#include <stdlib.h>

#define FOO 1
#define BAR 1 \
 + 1

#define CSTNULL 0


int main()
{
	int *x;
	int y;

#ifdef YYY

	if(x == NULL) { // dont, or useless to redo
	}

#endif

	if(x == CSTNULL) { // dont
	}

	if(x == 0) { // do
	}

	if(y == 0) { // dont, not a pointer
	}


	return 0; // dont
}
