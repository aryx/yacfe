#!/usr/bin/perl -w
use strict;
use vars qw($opt_a $opt_m $opt_s);
use Getopt::Std;

# Analyze comments in Java source code.

my %eol = (name => 'end-of-line comment');  # // ...
my %multi = (name => 'multi-line traditional comment');    # /* ...\n... */
my %single = (name => 'single-line traditional comment');  # /* ... */

my $comment_start = 0;
my $comment_partial = 0;

sub usage() {
    die <<EOF
Usage: $0 [options] [files]
Options:
    -a  print all comments
    -m  print "middle" comments
    -s  print comment delimiters found within strings
EOF
}

getopts("ams");
my $print_all = $opt_a;
my $print_middle = $opt_m;
my $print_string = $opt_s;

while (<>) {
    if (m%".*?(?://|/\*|\*/).*?"%) {
	print "$ARGV, line $.: comment in string: $_" if $print_string;
    } elsif (m%//%) {
	print if $print_all;
	$eol{m%\S.*//% ? 'right' : 'whole'}++;
    } elsif (m%/\*%) {
	print if $print_all;
	$comment_start = $.;
	$comment_partial = m%\S.*/\*%;
    } elsif (m%\*/%) {
	print if $print_all;
	my $table = ($. == $comment_start ? \%single : \%multi);
	my $kind =  (m%\*/.*\S% ? ($comment_partial ? 'middle' : 'left')
		     : ($comment_partial ? 'right' : 'whole'));
	$table->{$kind}++;
	if (!$print_all && $kind eq 'middle' && $print_middle) {
	    my $name = $table->{'name'};
	    print "$ARGV, line $.: middle $name: $_";
	}
	$comment_start = 0;
    } else {
	print if $print_all && $comment_start;
    }
} continue {
    close ARGV if eof;  # reset line number ($.) for each file
}

foreach my $table (\%eol, \%multi, \%single) {
    do_report($table);
}

sub plural($$) {
    my ($n, $str) = @_;
    return $n == 1 ? $str : $str . 's';
}

sub do_report($) {
    my $table = $_[0];
    my $name = $table->{'name'};
    my @keys = sort { $table->{$b} <=> $table->{$a} }
               grep { $_ ne 'name' && defined $table->{$_} }
               keys %$table;
    foreach my $kind (@keys) {
	my $count = $table->{$kind};
	printf "%6d %-6s %s\n", $count, $kind, plural($count, $name);
    }
}
