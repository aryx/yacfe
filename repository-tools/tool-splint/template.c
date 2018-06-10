#include "splint.h"

#include <stdio.h>


int *glob;

void f(int *x) {

	printf("%d", *x);

}
