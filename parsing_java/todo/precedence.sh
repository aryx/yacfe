#!/bin/sh

# check that precedence-based parenthesis-minimization is valid

canon=~/proj/joust/ppcanon
prec=~/proj/joust/pptest

[ -x $canon ] || (echo "$canon: not found"; exit 1)
[ -x $prec ] || (echo "$prec: not found"; exit 1)

TMP=/tmp/java-$$

for file in $* ; do
    echo $file
    if $canon $file > $TMP.canon && \
       $prec $file > $TMP.pass1 && \
       $canon $TMP.pass1 > $TMP.pass2
    then
	diff $TMP.canon $TMP.pass2
    fi
done

rm $TMP.{canon,pass{1,2}}
