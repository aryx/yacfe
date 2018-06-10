#include <stdio.h> 
#include <stdlib.h> 

int x = 0, y = 1, z = 2;
int * (NT COUNT(3) array)[4] = { &x, &y, &z, NULL};
// dont forget the parens, dont do
//int * NT COUNT(3) array[4] = { &x, &y, &z, NULL};

/*
null_terminated.c:5: Error: Assertion will always fail in upper bound coercion:
  & x == 0 || & x + 3 <= & x + 1
*/


int main(void) {
	for (int i = 0; i < 3; i++) {
		printf("%d\n", *(array[i]));
	}
	return 0;
	
}
