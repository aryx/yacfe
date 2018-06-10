#include <stdio.h> 

/*
deputy manual-sum.c 
=> 
manual-sum.c:1: Warning: Type "int *" in formal "data" of sum needs a bound annotation.

./a.out
=> 
manual-sum.c:7: sum: Assertion failed in upper bound check:
  data + i + 1 <= data + 1 (with no overflow)
Execution aborted.
*/


int sum(int *data, int length) { 
	int i, sum = 0; 
	for (i = 0; i <= length; i++) { 
		sum += data[i]; 
	} 
	return sum; 
}



int main() {
	int buf[5] = { 1, 2, 3, 4, 5 }; 

    // cool, runtime error
	//printf("%d\n", sum(buf, 5));  

    // not cool, runtime error too :)
    // int *data is assumed by default to be a pointer, not array, 
	// so everything is forbidden except sum(buf, 0)
	//printf("%d\n", sum(buf, 2)); 

	printf("%d\n", sum(buf, 0)); 
	return 0; 
}
