#include <stdio.h> 

int array[5] = { 0 };

int * SNT sentinel = array + 5;
//int * nosentinel = (array + 5);

void main(void) {
	int *x;

	for (x = array; x < sentinel; x++) {
		//printf("%d", x); why not have gcc warning in addition to deputy ?
		printf("%d\n", *x);
	}
//	printf("%d\n", *sentinel); // error, not allowed reference
//	printf("%d\n", *nosentinel);

	   
}
