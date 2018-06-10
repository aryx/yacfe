#include <stdlib.h> 

// it's used in git for instance via the NORETURN macro

// pad: gcc says nothing :( it does not detect the dead code

/* from gcc manual:
     The `noreturn' keyword tells the compiler to assume that `fatal'
     cannot return.  It can then optimize without regard to what would
     happen if `fatal' ever did return.  This makes slightly better
     code.  More importantly, it helps avoid spurious warnings of
     uninitialized variables.
pad: really ?

*/

// when on proto they put the macro after:
//extern void usage(const char *err) NORETURN;


void __attribute__ ((noreturn)) fatal() {
	/* ... */ /* Print error message. */ /* ... */
	exit (1);
}


int foo() {
	int x = 1;
	fatal();

	if(x) {
		return 1;
	} else {
		return 2;
	}
}
