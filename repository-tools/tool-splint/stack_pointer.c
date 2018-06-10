#include "splint.h"

#include <stdio.h>


static int *glob;

void f() {
	int x = 0;
	glob = &x;
}


void g() {
	printf("%d", *glob);
}
