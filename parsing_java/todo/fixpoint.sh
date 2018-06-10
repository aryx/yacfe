#!/bin/sh

# check that parsing and pretty-printing a syntactically correct Java program
# reaches a fixpoint after two passes

check=~/proj/joust/pptest

[ -x $check ] || (echo "$check: not found"; exit 1)

TMP=/tmp/java-$$

for file in $* ; do
    echo $file
    if $check $file > $TMP.pass1 && $check $TMP.pass1 > $TMP.pass2; then
	diff $TMP.pass1 $TMP.pass2
    fi
done

rm $TMP.pass{1,2}
