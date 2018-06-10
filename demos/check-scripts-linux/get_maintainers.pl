#!/usr/bin/perl -w
# (c) 2007, Joe Perches <joe@perches.com>
#           created from checkpatch.pl
#
# Print the contact information for the maintainers
# of the files modified in a patch
#
# usage: perl scripts/get_maintainers.pl <patch>
#
# Licensed under the terms of the GNU GPL License version 2

use strict;

my $P = $0;
$P =~ s@.*/@@g;

my $V = '0.06';

use Getopt::Long qw(:config no_auto_abbrev);

my $tree = "./";
my $email_maintainer = 1;
my $email_usename = 1;
my $email_list = 1;
my $email_subscriber_list = 0;
my $email_separator = ", ";
my $email_git = 1;
my $email_git_chief_penguins = 0;
my $email_multiline = 0;
my %saw;

my $chief_penguins = "(Linus Torvalds|Andrew Morton)";

GetOptions(
	   'tree=s' => \$tree,
	   'git!' => $email_git,
	   'git-chief-penguins' => \$email_git_chief_penguins,
	   'm!' => \$email_maintainer,
	   'n!' => \$email_usename,
	   'l!' => \$email_list,
	   's!' => \$email_subscriber_list,
	   'multiline!' => \$email_multiline,
	   'separator=s' => \$email_separator,
	   ) or exit;

my $exit = 0;

if ($#ARGV < 0 ||
    ($email_maintainer == 0
     && $email_list == 0
     && $email_subscriber_list == 0
     && $email_git == 0)) {
    print "usage: $P [options] patchfile\n";
    print "version: $V\n";
    print "  --tree [path] => linux kernel source path\n";
    print "  --git => include recent git \*-by: signers\n";
    print "  --git_chief_penguins => include ${chief_penguins}\n";
    print "  --m => include maintainer(s) if any\n";
    print "  --n => include name 'Full Name <addr\@domain.tld>'\n";
    print "  --l => include list(s) if any\n";
    print "  --s => include subscriber only list(s) if any\n";
    print "  --separator [, ] => separator for multiple addresses on 1 line\n";
    print "  --multiline => print 1 address per line\n";
    print "Default: [--g --m --l --separator \", \"]\n";
    print "Be sure to select something...\n";
    exit(1);
}

if ($tree && !top_of_kernel_tree($tree)) {
    if (${tree} ne "") {
	print "'${tree}' ";
    } else {
	print "The current directory ";
    }
    print "doesn't appear to be a linux kernel source tree\n";
    exit(2);
}

## Read MAINTAINERS for type/value pairs

my @typevalue = ();
open(MAINT, "<${tree}MAINTAINERS") || die "$P: Can't open ${tree}MAINTAINERS\n";
while (<MAINT>) {
    if (m/^(\C):\s*(.*)/) {
	my $type = $1;
	my $value = $2;

	##Filename pattern matching
	if ($type eq "F" || $type eq "X") {
	    $value =~ s@\.@\\\.@g;       ##Convert . to \.
	    $value =~ s/\*/\.\*/g;       ##Convert * to .*
	}
	push(@typevalue, "$type:$value");
    } elsif (!/^(\s)*$/) {
	push(@typevalue, $_);
    }
}
close(MAINT);

## Find the patched filenames

my @patchedfiles = ();
open(PATCH, "<$ARGV[0]") or die "Can't open $ARGV[0]\n";
while (<PATCH>) {
    if (m/^\+\+\+\s+(\S+)/) {
	my $file = $1;
	$file =~ s@^[^/]*/@@;
	$file =~ s@\n@@;
	push(@patchedfiles, $file);
    }
}
close(PATCH);

# Sort and uniq patchedfiles

undef %saw;
@patchedfiles = sort @patchedfiles;
@patchedfiles = grep(!$saw{$_}++, @patchedfiles);

# Find responsible parties

my @email_to = ();
foreach (@patchedfiles) {
    my $patchedfile = $_;
    my $exclude = 0;

#Git

    recent_git_signoffs($patchedfile);

#Do not match excluded file patterns

    foreach (@typevalue) {
	if (m/^(\C):(.*)/) {
	    my $type = $1;
	    my $value = $2;
	    if ($type eq 'X') {
		if (file_match_pattern($patchedfile, $value)) {
		    $exclude = 1;
		}
	    }
	}
    }

    if ($exclude == 0) {
	my $tvi = 0;
	foreach (@typevalue) {
	    if (m/^(\C):(.*)/) {
		my $type = $1;
		my $value = $2;
		if ($type eq 'F') {
		    if (file_match_pattern($patchedfile, $value)) {
			add_emails($tvi);
		    }
		}
	    }
	    $tvi++;
	}
    }
}

## sort and uniq email_to

@email_to = sort @email_to;
undef %saw;
@email_to = grep(!$saw{$_}++, @email_to);

## add lk if no one is interested...

my $address_cnt = @email_to;
if ($address_cnt == 0 && $email_list > 0) {
    push(@email_to, "linux-kernel\@vger.kernel.org");
}
if ($email_multiline != 0) {
    foreach (@email_to) {
	print("$_\n");
    }
} else {
    print(join($email_separator, @email_to));
    print("\n");
}

exit($exit);

sub file_match_pattern {
    my ($file, $pattern) = @_;
    if (substr($pattern, -1) eq "/") {
	if ($file =~ m@^$pattern@) {
	    return 1;
	}
    } else {
	if ($file =~ m@^$pattern@) {
	    my $s1 = ($file =~ tr@/@@);
	    my $s2 = ($pattern =~ tr@/@@);
	    if ($s1 == $s2) {
		return 1;
	    }
	}
    }
    return 0;
}

sub top_of_kernel_tree {
	my ($tree) = @_;

	if ($tree ne "" && substr($tree,length($tree)-1,1) ne "/") {
	    $tree = $tree . "/";
	}
	if (   (-f "${tree}COPYING")
	    && (-f "${tree}CREDITS")
	    && (-f "${tree}Kbuild")
	    && (-f "${tree}MAINTAINERS")
	    && (-f "${tree}Makefile")
	    && (-f "${tree}README")
	    && (-d "${tree}Documentation")
	    && (-d "${tree}arch")
	    && (-d "${tree}include")
	    && (-d "${tree}drivers")
	    && (-d "${tree}fs")
	    && (-d "${tree}init")
	    && (-d "${tree}ipc")
	    && (-d "${tree}kernel")
	    && (-d "${tree}lib")
	    && (-d "${tree}scripts")) {
		return 1;
	}
	return 0;
}

sub format_email {
    my ($name, $email) = @_;
    my $formatted_email = $name;

    if ($name =~ /[^a-z0-9 \.\-]/i) {    ##has "must quote" chars
	$name =~ s/(?<!\\)"/\\"/g;       ##escape quotes
	$formatted_email = "\"${name}\"\ \<${email}\>";
    } else {
	$formatted_email = "${name} \<${email}\>";
    }
    return $formatted_email;
}

sub add_emails {
    my ($index) = @_;

    $index = $index - 1;
    while ($index >= 0) {
	my $tv = $typevalue[$index];
	if ($tv =~ m/^(\C):(.*)/) {
	    my $ptype = $1;
	    my $pvalue = $2;
	    if ($ptype eq "L") {
		my $subscr = $pvalue;
		if ($subscr =~ m/\s*\(subscribers-only\)/) {
		    if ($email_subscriber_list > 0) {
			$subscr =~ s/\s*\(subscribers-only\)//g;
			push(@email_to, $subscr);
		    }
		} else {
		    if ($email_list > 0) {
			push(@email_to, $pvalue);
		    }
		}
	    } elsif ($ptype eq "M") {
		if ($email_maintainer > 0) {
		    if ($index >= 0) {
			my $tv = $typevalue[$index - 1];
			if ($tv =~ m/^(\C):(.*)/) {
			    if ($1 eq "P" && $email_usename > 0) {
				push(@email_to, format_email($2, $pvalue));
			    } else {
				push(@email_to, $pvalue);
			    }
			}
		    } else {
			push(@email_to, $pvalue);
		    }
		}
	    }
	    $index--;
	} else {
	    $index = -1;
	}
    }
}

sub which {
    my ($bin) = @_;

    my $path;

    foreach $path (split /:/, $ENV{PATH}) {
	if (-e "$path/$bin") {
	    return "$path/$bin";
	}
    }
    
    return "";
}

sub recent_git_signoffs {
    my ($file) = @_;

    my $sign_offs = "";
    my $cmd = "";
    my $output = "";

    my @lines = ();

    if (which("git") eq "") {
	die("Git not found\n");
    }

# Search the git logs for "by:" lines per file
# sort in reverse order by occurance
# add at most 5

    $cmd = "git log --since=6.months.ago -- ${file} ";
    $cmd = $cmd . " | grep -i '^    [-a-z]*by:.*\\\@' ";
    if ($email_git_chief_penguins == 0) {
	$cmd = $cmd . " | grep -E -v '${chief_penguins}'";
    }
    $cmd = $cmd . " | sort | uniq -c | sort -r -n | head -n 5";
    $cmd = $cmd . " | cut -f 2 -d ':' -s ";

    $output = `${cmd}`;

    $output =~ s/^\s*//gm;

    @lines = split("\n", $output);
    foreach (@lines) {
	my $line = $_;
	if ($line =~ m/(.*) <(.*)>/) {
	    my $git_name = $1;
	    my $git_addr = $2;
	    $git_name =~ tr/^\"//;
	    $git_name =~ tr/\"$//;
	    if ($email_usename > 0) {
		push(@email_to, format_email($git_name, $git_addr));
	    } else {
		push(@email_to, $git_addr);
	    }
	} elsif ($line =~ m/<(.*)>/) {
	    my $git_addr = $1;
	    push(@email_to, $git_addr);
	} else {
	    push(@email_to, $line);
	}
    }
    return $output;
}
