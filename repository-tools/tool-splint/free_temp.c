#include "splint.h"


//tofix: add __only
int f(int *x)
{
	free(x);
	return 1;
}
