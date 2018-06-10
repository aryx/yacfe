#!/usr/bin/perl -w

use strict;
my $VERSION = "003";
my @lines;
my $linesinfile = 0;
my ($opt_verbose, $opt_allsource, $opt_pedantic, $opt_style);

if (scalar(@ARGV) == 0) {
	usage();
}

get_options();

foreach my $file (@ARGV) {
	process ($file)
		or warn "Couldn't check file $file: $!";
}

sub usage {
	print STDERR "usage: findbugs.pl [-options] file(s)\n";
	print STDERR "  -allsource : check entire source file, not just '+' patch lines\n";
	print STDERR "  -pedantic : check for pedantic booboos\n";
	print STDERR "  -style : check for out of style\n";
	print STDERR "  -v, --verbose : verbose\n";
	print STDERR "  -h, --help : this help text\n";
	print STDERR "Version: $VERSION\n";
	exit 1;
}

sub get_options {
	while ($ARGV[0] =~ m/^-(.*)/) {
		my $cmd = shift @ARGV;

		if ($cmd eq "-allsource") {
			$opt_allsource = 1;
		}
		elsif ($cmd eq "-pedantic") {
			$opt_pedantic = 1;
		}
		elsif ($cmd eq "-style") {
			$opt_style = 1;
		}
		elsif (($cmd eq "-v") || ($cmd eq "--verbose")) {
			$opt_verbose = 1;
		}
		elsif (($cmd eq "-h") || ($cmd eq "--help")) {
			usage();
		}
		else {
			print STDERR "unknown option: '$cmd'\n";
			usage();
		}
	}
}

sub search {
	my $regexp = shift;
	my $text = shift;
	my $hits = 0;
	my $linenr = 0;

	foreach my $line (@lines) {
		$linenr++;
		if (($line =~ /^\+/) || $opt_allsource) {
			if ($line =~ $regexp) {
				$hits++;
				if ($hits == 1) {
					print $text
				}
				print "$linenr:$line\n";
			}
		}
	}
	if ($hits != 0) {
	    print ("\n");
	}

	return $hits;
}

sub process {
	my $filename = shift;
	my $linenr = 0;
	my $warnings = 0;
	my $signoff = 0;

	return undef unless $filename;

	open INPUT, $filename
		or return undef;
	@lines = ();

	while (!eof INPUT) {
		my $input=<INPUT>;
		chomp $input;
		if ($input =~ /^[[:space:]]*Signed-off-by/i) {
			$signoff++;
		}
		push @lines, $input;
		$linesinfile++;
	}
	close INPUT;

	print "Checking $filename:  signoffs = $signoff\n";
	if ($signoff == 0) {
		$warnings++;
		print "Missing Signed-off-by line(s)\n";
	}

	$warnings += search(qr/memset.*\,(\ |)(0x|)0(\ |0|)\);/,
			"Found memset with swapped arguments.\n");
	$warnings += search(qr/memset.*\,(\ |)1(\ |)\);/,
			"Found suspicious single byte memset.\n");
	$warnings += search(qr/![a-zA-Z0-9_ ]+(\|[^|]|\&[^&])|([^|]\||[^&]\&) *!/,
			"Possible boolean logic bug.\n");
	$warnings += search(qr/if(\ |)\(.*\)(\ |)(\|\&)\ /,
			"Found an if with suspect looking boolean logic\n");
	$warnings += search(qr/sizeof\((.*)\)\ ?\/\ ?sizeof\(\1\[0\]\)/,
			"Could use ARRAY_SIZE()\n");
	$warnings += search(qr/current\-\>state\ \=/,
		"Should use __set_current_state() instead of setting ->state directly.\n");
	$warnings += search(qr/\)kmalloc/, "kmalloc return shouldn't be cast.\n");
	$warnings += search(qr/__inline__/, "Use 'inline' instead of '__inline__'\n");
	$warnings += search(qr/check_region/,
		"Using check_region is racy, use just request_region and check its return value.\n");
	$warnings += search(qr/check_mem_region/,
		"Using check_mem_region is racy, use just request_mem_region and check its return value.\n");
	$warnings += search(qr/isa_(read|write){b,w,l}/,
		"Use ioremap instead of isa_read/write functions.\n");
	$warnings += search(qr/return E(INVAL|NODEV)/, "Return value should be negative.\n");
	$warnings += search(qr/kernel_thread\(/,
		"Use kthread abstraction instead of kernel_thread()\n");
	$warnings += search(qr/typedef/, "Do not add new typedefs.\n");
	$warnings += search(qr/[[:space:]]*extern[[:space:]]*\w.*\w/,
			"Put externs in header files only.\n");

	# pedantic: Noisy regexps that aren't really fatal.
	if ($opt_pedantic) {
		#search(qr/memset.*0\,\ PAGE_SIZE/,
			#"Use clear_page() if alignment permits (Or GFP_ZERO if this was kmalloc'd).\n");
		$warnings += search(qr/tmp(,|;)/,
			"Bad variable name: tmp. Please use something more descriptive.\n");
		$warnings += search(qr/temp(,|;)/,
			"Bad variable name: temp. Please use something more descriptive.\n");
		$warnings += search(qr/uint8_t/,
			"Incorrect type usage for kernel code. Use __u8/u8\n");
		$warnings += search(qr/uint16_t/,
			"Incorrect type usage for kernel code. Use __u16/u16\n");
		$warnings += search(qr/uint32_t/,
			"Incorrect type usage for kernel code. Use __u32/u32\n");
		$warnings += search(qr/uint64_t/,
			"Incorrect type usage for kernel code. Use __u64/u64\n");
		$warnings += search(qr/int8_t/,
			"Incorrect type usage for kernel code. Use __s8/s8\n");
		$warnings += search(qr/int16_t/,
			"Incorrect type usage for kernel code. Use __s16/s16\n");
		$warnings += search(qr/int32_t/,
			"Incorrect type usage for kernel code. Use __s32/s32\n");
		$warnings += search(qr/int64_t/,
			"Incorrect type usage for kernel code. Use __s64/s64\n");
		$warnings += search(qr/\b(BUG|BUG_ON)\b/,
			"Try to use WARN_ON & Recovery code rather than BUG() or BUG_ON()\n");
		$warnings += search(qr/__FUNCTION__/,
			"Should use C99 __func__ instead of GNU __FUNCTION__\n");
	}

	# Crazy types.
	$warnings += search(qr/CHAR/, "Incorrect type usage for kernel code. Use s8.\n");
	$warnings += search(qr/SHORT/, "Incorrect type usage for kernel code. Use s16.\n");
	$warnings += search(qr/WORD/, "Incorrect type usage for kernel code. Use s32.\n");
	$warnings += search(qr/LONG/, "Incorrect type usage for kernel code. Use s64.\n");
	$warnings += search(qr/UCHAR/, "Incorrect type usage for kernel code. Use u8.\n");
	$warnings += search(qr/USHORT/, "Incorrect type usage for kernel code. Use u16.\n");
	$warnings += search(qr/UWORD/, "Incorrect type usage for kernel code. Use u32.\n");
	$warnings += search(qr/ULONG/, "Incorrect type usage for kernel code. Use u64.\n");

	# coding style:
	if ($opt_style) {
		$warnings += search(qr/,[^[:space:]]/, "Need space after comma:\n");
		$warnings += search(qr/\([[:space:]]/, "Don't use space after '(':\n");
		$warnings += search(qr/[[:space:]]\)/, "Don't use space before ')':\n");
		$warnings += search(qr/ \t/, "Don't use space before tab:\n");
		$warnings += search(qr/[[:space:]]$/, "Don't use trailing white space:\n");
		$warnings += search(qr/if\(|for\(|while\(|switch\(/,
				"Need space after if/for/while/switch:\n");
		$warnings += search(qr/sizeof[[:space:]]/,
				"Don't use space after sizeof:\n");
		$warnings += search(qr|//|, "Don't use C99 // comments:\n");
		$warnings += search(qr/return\s*\(.*\)\s*;/,
				"Do not use parentheses on returns.\n");
	}

	$warnings += search(qr/\bstatic\b.*=[[:space:]]*\b(0|NULL)\b/,
			"Don't init statics to 0/NULL:\n");
	$warnings += search(qr/\b(float|double)\b.*;/,
			"Don't use floating point in kernel:\n");

	# email damage. (wordwrap, MIME etc)
	$warnings += search(qr/=3D/, "Patch is MIME damaged. Resend as plaintext inline.\n");

	print "$warnings warnings\n\n";
	return 1;
}
