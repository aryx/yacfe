#! /usr/bin/perl
#
# Detect cycles in the header file dependency graph
# Vegard Nossum <vegardno@ifi.uio.no>
#

use strict;
use warnings;

my @I = ('include');
my %deps = ();

my @headers = grep { strip($_) } @ARGV;

parse_all(@headers);

detect_cycles(@headers);
#graph();
exit;


# Get a file name that is relative to our include paths
sub strip {
	my $filename = shift;

	for my $i (@I) {
		my $stripped = $filename;
		$stripped =~ s/^$i\///;

		return $stripped if $stripped ne $filename;
	}

	return $filename;
}

# Search for the file name in the list of include paths
sub search {
	my $filename = shift;
	return $filename if -f $filename;

	for my $i (@I) {
		my $path = sprintf "%s/%s", $i, $filename;
		return $path if -f $path;
	}

	return undef;
}

sub parse_all {
	# Parse all the headers.
	my @queue = @_;
	while(@queue) {
		my $header = pop @queue;
		next if exists $deps{$header};

		$deps{$header} = [] unless exists $deps{$header};

		my $path = search($header);
		next unless $path;

		open(my $file, '<', $path) or die($!);
		chomp(my @lines = <$file>);
		close($file);

		for my $line (@lines) {
			if(my($dep) = ($line =~ m/^#\s*include <([^>]+)>/)) {
				push @queue, $dep;
				push @{$deps{$header}}, $dep;
			}
		}
	}
}

sub print_cycle {
	my $cycle = shift;

	my $first = shift @$cycle;
	my $last = pop @$cycle;

	my $msg = "In file included";
	printf "%s from %s,\n", $msg, $last if defined $last;

	for my $header (reverse @$cycle) {
		printf "%*.s from %s\n", length $msg, '', $header;
	}

	printf "%s: warning: recursive header inclusion\n", $first;
}

# Find and print the smallest cycle starting in the specified node.
sub detect_cycles {
	my @queue = map { [$_] } @_;
	while(@queue) {
		my $top = pop @queue;
		my $name = $top->[-1];

		for my $dep (@{$deps{$name}}) {
			my $chain = [@$top, $dep];

			if(grep { $_ eq $dep } @$top) {
				print_cycle($chain);
				return;
			}

			push @queue, $chain;
		}
	}
}

sub mangle {
	$_ = shift;
	s/\//__/g;
	s/\./_/g;
	s/-/_/g;
	$_;
}

sub escape {
	$_ = shift;
}

# Output dependency graph in GraphViz language.
sub graph {
	printf "digraph {\n";

	printf "\t/* vertices */\n";
	for my $header (keys %deps) {
		printf "\t%s [label=\"%s\"];\n",
			mangle($header), escape($header);
	}

	printf "\n";

	printf "\t/* edges */\n";
	for my $header (keys %deps) {
		for my $dep (@{$deps{$header}}) {
			printf "\t%s -> %s;\n",
				mangle($header), mangle($dep);
		}
	}

	printf "}\n";
}
