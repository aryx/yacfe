#!/usr/bin/perl -w
#
# An automated kernel janitor.
# (c) 2001, Dave Jones. <davej@suse.de>, with invaluable
# perl assistance from Rob Andrews <nine@impure.org.uk>
# Various code also inspired from hundreds of other perl scripts.
#
# Additional functionality added by The kerneljanitors.org team :)
#
# Licensed under the terms of the GNU GPL License version 2
#
#
# TODO:
#	  Should reduce some false positives.
#	- Spinlock balancing routine needs to check all return paths
#	  of current subroutine
#	- Spinlock balancing routine can be made more generic to a
#	  "Check that all return paths call $1"

use strict;

my @lines;

foreach my $file (@ARGV) {
	process ($file)
			or warn "Couldn't check file $file: $!";
}


sub check_pci_enable_device {
	my $used = shift;
	my $filename = shift;
	my $currentlinenr;
	foreach my $current (@lines) {
		$currentlinenr++;
		if ($current=~/pci_enable_device/) {
			if ($currentlinenr < $used) {
				print "Should be ok, called on line $currentlinenr\n";
				print "$filename:$currentlinenr:$current\n";
			}
		}
	}
}


sub check_spinlock {
	my $lock = shift;
	my $filename = shift;
	my $locklinenr = shift;
	my $foundunlock = 0;
	my $currentlinenr;

# TODO: Start at $locklinenr

	foreach my $current (@lines) {
		$currentlinenr++;
		if ($current=~/spin_unlock\($lock\)/) {
#			print ("Lock closed on line $currentlinenr\n");
			$foundunlock = 1;
		}
	}

	return $foundunlock;
}


sub process {
	my $filename=shift;

	return undef unless $filename;

	open INPUT, $filename
		or return undef;

	while(!eof INPUT) {
			my $input=<INPUT>;
			chomp $input;
			push @lines, $input;
	}
	close INPUT;		

#	s!/\*(.*?)\*/!"\n" x (@lines =~ tr/\n//)!esg;

my $spinlockwarn=0;
my $lookspci=0;
my $linenr=0;

	foreach my $line (@lines) {

		$linenr++;

# For later, we may need to preprocess include files.
# read as: Include them into the array before the current file.
#		if ($line=~/^#include [<"].*?[>"]/i) {

		if ($line=~/static const char.*__initdata/) {
			print "const & __initdata in string def. Remove const.\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/\(struct netdev_private \*\)/) {
			print "Unnecessary cast.\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/netif_rx/) {
			print "Net drivers should set dev->last_rx immediately after netif_rx\n";
			print "Also make sure the skb isn't referenced after giving it to netif_rx\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/MOD_(INC|DEC)_USE_COUNT/) {
			print "MOD_{INC,DEC}_USE_COUNT are deprecated for 2.6: see the module-init-tools FAQ\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/SET_MODULE_OWNER/) {
			print "SET_MODULE_OWNER is useless for 2.6: see the module-init-tools FAQ\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/sleep_on/) {
			print "Using sleep_on derivative, is racy. consider using wait_event instead\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/check_region/) {
			print "Using check_region, is racy, use just request_region and check for its return.\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/check_mem_region/) {
			print "Using check_mem_region, is racy, use just request_mem_region and check for its return.\n";
			print "$filename:$linenr:$line\n\n";
		}
				
		if ($line=~/pdev-\>irq/) {
			print "Make sure pci_enable_device before reading irq\n";
			check_pci_enable_device($linenr, $filename);
			print "$filename:$linenr:$line\n\n";
		}

		if (($lookspci==0) and ($line=~/pci_/)) {
			$lookspci=1;
			print "Looks like a PCI driver. Make sure it uses pci_enable_device.\n";
			check_pci_enable_device($linenr, $filename);
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/pdev-\>resource/) {
			print "Make sure pci_enable_device --before-- reading resource\n";
			check_pci_enable_device($linenr, $filename);
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/pcibios_/) {
			print "Uses obsolete pcibios_xxx functions.\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/save_flags_cli/) {
			print "Use local_irq_save instead.\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/isa_{read,write}{b,w,l}/) {
			print "Use ioremap instead of isa_read/write functions.\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/current-\>state/) {
			print "Bad. Should use set_current_state.\n";
			print "$filename:$linenr:$line\n\n";
		}


		if ($line=~/loops_per_sec/) {
			print "Warning: loops_per_sec may change..\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/if.*dev-\>mem_start/) {
			if (($line!~/0xffffffff/) or ($line!~/-1/)) {
				print "Should check for 0xffffffff too.\n";
				print "$filename:$linenr:$line\n\n";
			}
		}

		if (($spinlockwarn==0) and
			(($line=~/cli\(\)/) or
			 ($line=~/sti\(\)/) or
			 ($line=~/lock_kernel/))){
			$spinlockwarn=1;
			print "Consider using spinlocks.\n";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/return E/) {
			print "Should be return -E ?";
			print "$filename:$linenr:$line\n\n";
		}

		if ($line=~/spin_lock\((.*)\)/) {
			if (check_spinlock($1, $filename, $line) == 0) {
				print ("Obtained spinlock on line $linenr, but never unlocked.\n\n");
			}
		}
	}
	return 1;
}
