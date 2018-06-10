
#include "splint.h"

#include <stdio.h>


void f(int __only *x) {
	free(x);
	printf("%d", *x);

}
