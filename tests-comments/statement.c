#include <xxx.h>

/*
 * gzip declarations
 */

#define OF(args)  args

#ifndef memzero
#define memzero(s, n)     memset ((s), 0, (n))
#endif

int main(int i)
{

    int mode = 0;

	/* logical assign */
	loops_per_jiffy >>= 1;

	if (get_option(&str, &minor) != 2) {	/* MD Number */
		printk(KERN_WARNING "md: Too few arguments supplied to md=.\n");
		return 0;
	} else { /* else */
		return 1;
	}

	if (get_option(&str, &factor) != 2 ||	/* Chunk Size */
		get_option(&str, &fault) != 2) {
		printk(KERN_WARNING "md: Too few arguments supplied to md=.\n");
		return 0;
	}


    mode |= 0700 & (perm >> 2); /* User  is off-by-2 bits */
    mode |= 0070 & (perm >> 1); /* Group is off-by-1 bit */
    mode |= 0007 & (perm);      /* World maps 1 for 1 */
    return mode;

}
