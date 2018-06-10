#include <stdio.h> 

/* runtime error only :( not statically checked :(

manual-sum2.c:6: sum: Assertion failed in pointer access check:
  (data + i) + 1 <= data + length
Execution aborted.
*/

int sum(int * COUNT(length) data, int length) { 
	int i, sum = 0; 
	for (i = 0; i <= /* bug must be < */ length; i++) { 
		sum += data[i]; 
	} 
	return sum; 
}



int main() {
	int buf[5] = { 1, 2, 3, 4, 5 }; 

	printf("%d\n", sum(buf, 5)); 
	return 0; 
}
