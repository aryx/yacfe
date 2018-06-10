#include <stdio.h> 

#define XXX_ICH(i, a,b) for (i = a; i < b; i++) 

void main()
{
	int a = 1;
	int b = 10;
	int i;

	XXX_ICH(i, a,b) {
		printf("%d\n", i);
	}
	printf(XXX_STR "toto");

	XXX_DBG // work even if bad indentation
   int i;
}
