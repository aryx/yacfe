
2008/7/6 Randy Dunlap <randy.dunlap@oracle.com>:
> Did you do these manually (by personal inspection) or by some tool?
> If a tool, what tool/where is it?  Thanks.

It is a simple script like this:

find . -name "*.h" -exec grep.sh {} \;
find . -name "*.c" -exec grep.sh {} \;

grep.sh:
#!/bin/sh
grep -H "^#include" $1|sed "s,/\*.\+,,"|grep -v ":$"|sort|uniq -c|grep
-v "^ \+1:"

