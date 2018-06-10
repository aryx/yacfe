#include <stdio.h> 
#include <stdlib.h> 

// so it can be compiled by gcc too
// but does not work well then when run via
// deputy :(
//#include "deputy_gcc.h"

/*
cryptic type error message ...
argc_argv.c:20: Error: Type mismatch in coercion:
  from: char * SAFE  * BND(...) NT  
    to: char * COUNT(0) NT  * BND(...) NT  
   exp: argv___0
pad: that was when I forgot to add annotation on myargv too.


after that, get this runtime cryptic error:
argc_argv.c:34: main: Assertion failed in nullterm upper bound check:
  tmp0 + (12U + 3) / 4 <= tmp0 + (3U - 1) + len(tmp0 + (3U - 1)) (with no overflow)
Where:
  tmp0 = malloc(sizeof(char * SAFE  ) * 3U)

*/

void foo(int argc, char * NTS * NT COUNT(argc) argv) {
	printf("%s\n", argv[0]);

	for(int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
}


void main(int argc, char * NTS * NT COUNT(argc) argv) {

//argc_argv.c:28: Warning: Type "char *" in local "myargv" should be annotated NT.
//but wrong line :(

	char * NTS * NT myargv; // required
	myargv = malloc(sizeof(char *) * 4); // argh, already complained at runtime
	for(int i = 0; i < 3; i++) {
		myargv[i] = "test";
	}
	myargv[3] = NULL;

	foo(2, myargv);
		
}
