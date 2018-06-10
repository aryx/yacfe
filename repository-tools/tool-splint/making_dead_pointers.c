#include "splint.h"

#include <stdio.h>


int *x;
int *y;


void f() {

	x = malloc(sizeof(int));
	y = x;

	free(x);
	

}
