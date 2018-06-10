#include <stdio.h> 


struct foo { 
	int tag; 
	union { 
		int n WHEN(tag == 1); 
		int *p WHEN(tag == 2); 
	} u; 
};

void main(void) {
	struct foo x;
	x.tag = 1; // if do not put this then deputy say nothing at compile-time
	x.u.n = 1;
	printf("%d", *(x.u.p)); // detected statically after the x.tag = 1;
	
}
