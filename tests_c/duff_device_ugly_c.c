
/*

from http://groups.google.com/group/net.lang.c/msg/66008138e07aa94c
famous usenet post according to google

Consider the following routine, abstracted from code which copies an
array of shorts into the Programmed IO data register of an Evans &
Sutherland Picture System II:

        send(to, from, count)
        register short *to, *from;
        register count;
        {
                do
                        *to = *from++;
                while(--count>0);
        }

(Obviously, this fails if the count is zero.)
The VAX C compiler compiles the loop into 2 instructions (a movw and
a sobleq, I think.)  As it turns out, this loop was the bottleneck in
a real time animation playback program which ran too slowly by about 50 pourcent.
The standard way to get more speed out of something like this is to unwind
the loop a few times, decreasing the number of sobleqs.  When you do that,
you wind up with a leftover partial loop.  I usually handle this in C with
a switch that indexes a list of copies of the original loop body.  Of
course, if I were writing assembly language code, I d just jump into the
middle of the unwound loop to deal with the leftovers.  Thinking about this
one day last October, the following implementation occurred to me:
*/

//send(to, from, count)
//     register short *to, *from;
//     register count;
void send(short *to, short *from, int count)
{
  register n=(count+7)/8;
  switch(count%8){
  case 0: do{     *to = *from++;
  case 7:         *to = *from++;
  case 6:         *to = *from++;
  case 5:         *to = *from++;
  case 4:         *to = *from++;
  case 3:         *to = *from++;
  case 2:         *to = *from++;
  case 1:         *to = *from++;
  }while(--n>0);
  }
}
 

/*
Disgusting, no?  But it compiles and runs just fine on all known C compilers.
Dennis Ritchie has endorsed it as legal C.
I feel a combination of pride and revulsion at this discovery;
I think I'll name it after myself -- ``Duff's Device'' has a nice ring to it.

It amazes me that after 10 years of writing C there are still little corners
that I haven't explored fully.  (Actually, I have another revolting way to
use switches to implement interrupt driven state machines but it's too
horrid to go into.)

Many people (even Brian Kernighan?) have said that the worst feature of C is that
switches don't break automatically before each case label.  This code forms
some sort of argument in that debate, but I'm not sure whether it's for or
against.

Tom Duff {ucbvax,decvax,ihnp4,...}!alice!td

Note:  Work reported herein was done while the author was an employee of
Lucasfilm Ltd., San Rafael, CA. 
*/
