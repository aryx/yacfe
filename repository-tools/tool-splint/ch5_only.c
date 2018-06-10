#include "splint.h"

#include <stdio.h>

extern __only int *glob;

__only int * f(__only int *x, int *y, int *z) /*@globals glob;@*/
{
	int *m = (int *) malloc(sizeof(int));
	//glob = y; // memory leak cos only 
	free(x);
	// *m = *x; // use after free
	return z;

}
