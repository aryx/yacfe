#include "splint.h"


// bug cos mean previous 'only' annotation are not try any more

static int *glob;

int f(int *x)
{
	glob = x;
	return 1;
}
