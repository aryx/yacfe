#include "splint.h"

#include <stdio.h>


//pad: why splint says nothing ? can have bugs here ? g assume
// glob is allocated

//can also put extern, but splint force you to add a storage qualifier.

static int *glob;

void g() {
	printf("%d", *glob);
}
