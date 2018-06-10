#include <stdio.h> 

int * COUNT(5) p;

/* but only at runtime
0
0
0
0
0
count.c:12: main: Assertion failed in pointer access check:
  (arr + i) + 1 <= arr + 5
Execution aborted.
*/


int total;
int * COUNT(total) p2;


void main(void)
{
	int arr[6] = { 0 };
	p = arr;

	
	for (int i = 0; i < total; i++) {
		printf("here\n");
		p2[i+1] = 1; // not detected, neither static or runtime ...
	}

//	p[5] = 1; // detected at compile time

	for(int i = 0; i < 5 /* 6 generate error */; i++) {
		printf("%d\n", p[i]);
	}
}
