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
# $Id: kj-devel.pl,v 1.5 2005/03/23 13:45:07 domen Exp $
#
# 1.0 Initial version.
# 1.1 Spinlock balancing checker improved.
#	Vicente Feito			Added options posibility
#	<vicente.feito@gmail.com>	New loader function to fix multiple files load
#					Changed the storage structure, from array to hashes
# 					include files processing (local and tree referred)
# 					Added more checks based on DO's and DONT's
#					Skip comments on source files(C and C++ Style)
#					Some trivial fixes and cleanup
#					spinlock code rewrite
#					Fixed line numbers
#					Fixed panic() checks on files that are not drivers
#					ioremap()/iounmap() balance check

use strict;
use Getopt::Long;

my @lines = ();
my $linesinfile=0;
my $module;		#flag, mantains the module_init/_exit
my $comment = 0;

my ($includes, $nospinlocks, $nomodules, $pathinclude);
my $linenr;
my %filenames = ();
my @archs = @ARGV;
my $include;
chomp($pathinclude = `uname -r`);


die "$0 <--includes> <--nospinlocks> <--nomodules> <file1 file2 file...> 
	--includes		Checks inside the #include files
	--nospinlocks		Don't Check spinlocks, default is yes
	--nomodules		In case you're not building a module
	file1 file2 ...		The files you want to check\n" unless @ARGV > 0;

GetOptions("includes"	=> \$includes,
	"nospinlocks"	=> \$nospinlocks,
	"nomodules"	=> \$nomodules);

if ($includes) {
	shift @archs;
}
if ($nospinlocks) {
	shift @archs;
}
if ($nomodules) {
	shift @archs;
}

#Here's where everything starts
loader();

sub loader {
	foreach my $filename (@archs) {
		open(FILE, "<$filename") or "Unable to open $filename $!" and next;
		while(<FILE>) {
			#Add the includes files if the --includes option is given
			if ($includes and $_ =~ /#include[ |\t]?([<|"])([^(>|")]*)/) {
				if ($1 eq "\"") {
					$include = giveLocal($filename, $2);

				} else {
					$include = "/lib/modules/$pathinclude/build/include/$2";
				}
				#Check if the file isn't already there, if it's not, push it
				if (not exists($filenames{$include})) {
					push @archs, $include;
				}
			}
	
			#Push the lines of each file inside the array of that file in the hash
			push @{$filenames{$filename}}, $_;
		}
		close(FILE);
	}
	process();
}

sub check_pci_enable_device {
	my ($used, $filename) = @_;
	my $currentlinenr;
	foreach my $current (@lines) {
		if ($current=~/pci_enable_device/) {
			if ($currentlinenr < $used) {
				print "Should be ok, called on line $currentlinenr\n";
				print "$filename:$currentlinenr:$current\n";
				return;
			}
		}
		$currentlinenr++;
	}
}

sub process {
	my (%locks, %locks_irq, %locks_bh, %ioremap);	
	my $comment = 0;
	my $spinlockwarn=0;
	my $lookspci=0;
	my $drvdata; 	#this allow to check MODULE_ macros

	foreach my $filename (@archs) {
		$linenr = 1;
		$linesinfile = $#{$filenames{$filename}}+1;

		#This is dirty, but just in order to keep check_* working
		#until I clean those too.
		@lines = @{$filenames{$filename}};

		print "\n" . "x"x15 . "  $filename  " . "x"x15 ."\n\n";
		foreach my $line (@{$filenames{$filename}}) {
			$drvdata = 4;
	
			#This code skips comments.
			if ($line=~/^\/\//) {
				$linenr++;
				next;
			}
			$comment = 1 if ($line=~/(^|\s+)\/\*/);
			if ($comment) {
				$comment = 0 if ($line=~/\*\//);
				$linenr++;
				next;
			}
			chomp($line);
	
	
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
	
			if ($line=~/(GET|MOD_(INC|DEC))_USE_COUNT/) {
				print "MOD_{INC,DEC}_USE_COUNT and GET_USE_COUNT are deprecated for 2.6: see the module-init-tools FAQ\n";
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
	
			if ($line=~/return( |\t)*E[^(]*$/) {
				print "Should be return -E ?";
				print "$filename:$linenr:$line\n\n";
			}

			if (not $nospinlocks and $line=~/(^|[^_])spin_lock\(&?(.*)\);/) {
				#add that one
				push @{$locks{$2}}, $linenr; 
			}
			if (not $nospinlocks and $line=~/(^|[^_])spin_unlock\(&?(.*)\);/) {
				
				if (not exists($locks{$2}) or 
					(exists($locks{$2}) and @{$locks{$2}} == 0)) {
					print "Unlocking a lock that hasn't been acquired ".
						"yet (could be a false positive) - Line:$linenr\n\n";
				} else {
					#get rid of the last one
					pop @{$locks{$2}};
				}
			}

			if (not $nospinlocks and $line=~/(^|[^_])spin_lock_irqsave\(&?(.*)\);/) {
				push @{$locks_irq{$2}}, $linenr; 
			}
			if (not $nospinlocks and 
				$line=~/(^|[^_])spin_unlock_irqrestore\(&?(.*)\);/) {

				if (not exists($locks_irq{$2}) or 
					(exists($locks_irq{$2}) and @{$locks_irq{$2}} == 0)) {
					print "Unlocking a lock that hasn't been acquired ".
						"yet (could be a false positive) - Line:$linenr\n\n";
				} else {
					pop @{$locks_irq{$2}};
				}
			}

			if (not $nospinlocks and $line=~/(^|[^_])spin_lock_bh\(&?(.*)\);/) {
				push @{$locks_bh{$2}}, $linenr; 
			}
			if (not $nospinlocks and 
				$line=~/(^|[^_])spin_unlock_bh\(&?(.*)\);/) {

				if (not exists($locks_bh{$2}) or 
					(exists($locks_bh{$2}) and @{$locks_bh{$2}} == 0)) {
					print "Unlocking a lock that hasn't been acquired ".
						"yet (could be a false positive) - Line:$linenr\n\n";
				} else {
					pop @{$locks_bh{$2}};
				}
			}

			# ioremap() / iounmap()
			if ($line=~/(^|[^_])ioremap\((.*),.*\);/) {
				push @{$ioremap{$2}}, $linenr;
			}
			if ($line=~/(^|[^_])iounmap\((.*)\)/) {
				if (not exists($ioremap{$2}) or 
					(exists($ioremap{$2}) and @{$ioremap{$2}} == 0)) {
					print "Unmapping a region that hasn't been mapped ".
						"yet (could be a false positive) - Line:$linenr\n\n";
				} else {
					pop @{$ioremap{$2}};
				}
			}

			#we make sure it's a driver to check for panic
			if (not $nomodules and $line=~/panic\((.*)\)/ and $line!~/^NORET_TYPE/) {
				print "Device Drivers as a general rule should not call panic().\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/save_flags(_cli)?\(\)/ or $line=~/restore_flags\(\)/) {
				print "save_flags_* and restore flags should not be used.\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/module_init\((.*)\)/ or $line=~/module_exit\((.*)\)/) {
				$module = 1;
			}
			if ($line=~/MODULE_AUTHOR\(.*\)/ or
				$line=~/MODULE_LICENSE\(.*\)/ or
				$line=~/SUPPORTED_DEVICE\(.*\)/ or
				$line=~/MODULE_DESCRIPTION\(.*\)/) {
				$drvdata--;
			}
			if ($line=~/MODULE_PARM\(.*\)/) {
				print "MODULE_PARM() has been replaced by module_param(name, type, perm).\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/^#.*__SMP__/) {
				print "__SMP__ is no longer used and it's going to dissapear soon.\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/strtok\(.*\)/) {
				print "strtok() is racy on smp, use strsep() instead.\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/int 0x80/) {
				print "Device Drivers should never use syscalls.\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/\bproc_register\(.*\)/) {
				print "proc_register() should be replaced with create_proc_entry().\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/(const )?char ?\* ?\w+ ?= ?\".*\"/) {
				print "Using foo[] is recommended over *foo: saves memory references & code\n";
				print "$filename:$linenr:$line\n\n";
			}
			if ($line=~/memset\((.*),( *sizeof.*),( *\d+)\)/) {
				print "Your memset parameters appears to be backwards\n";
				print "$filename:$linenr:$line\n\n";
			}
			$linenr++;
		}
		#now we show the not unlocked ones
		show_balance_results(0,%locks);
		show_balance_results(0,%locks_bh);
		show_balance_results(0,%locks_irq);
		show_balance_results(1,%ioremap);
	
		if (!$nomodules and !defined($module)) {
			print "If you're building a module, note that you must use the". 
				" init mechanism, module_init() and module_exit().\n";
		}
		if (!$nomodules and $drvdata) {
			print "MODULE_AUTHOR/MODULE_LICENSE/SUPPORTED_DEVICE/MODULE_DESCRIPTION". 
				" are now required.\n";
		}
	}
	return 1;
}

#Returns the name of a local file given from an #include ""
#1st parm:the actual file being processed
#2nd parm:The file being included by include ""
sub giveLocal {
	my ($include, $local) = @_;
	$include = reverse($include);
	my ($name, $path) = split(/\//, $include, 2);
	return reverse($path)."/$local";
}

#This shows the function calls not balanced
sub show_balance_results {
	my $flag = shift;
	my %checks = @_;

	foreach my $check (sort keys %checks) {
	 	if (@{$checks{$check}}) {
			if ($flag) {
				print "ioremap($check) used and iounmap missing in line(s)".
					"(maybe iounmapped before?) - Line:@{$checks{$check}}\n\n";
			} else {
				print "Lock ($check) obtained and not unlocked in line(s)".
					"(maybe unlocked before?) - Line:@{$checks{$check}}\n\n";
			}

		}
	}
}
