#include <stdio.h> 

int global = 0;

int * SAFE x;
int *y; // apparently considered SAFE by default too as it also generates 
        // a runtime error. indeed, cf section 5.1 of deputy manual
int * SAFE NONNULL z = &global;
/*
safe.c:6: Warning: Undischarged check for global initializer:
CNonNull(0, "0 != 0", __LOCATION__);
safe.c:6: Error: non-null check will always fail.
*/

void main(void)
{
	int arr[3] = { 1, 2, 3 };

	z = arr; // not enough

//	printf("%d %d\n", *z, *y);

/*
	printf("%d %d\n", *x, *y);
==>
safe.c:11: main: Assertion failed in non-null check:
  x != 0
*/

	x = arr;
	x = arr + 1; // allowed to.
/*
	printf("%d\n", x[1]);
==> 
safe.c:19: Error: Assertion will always fail in pointer access check:
  ((arr + 1) + 1) + 1 <= (arr + 1) + 1
*/
	printf("%d\n", x[0]);
	y = arr+2;


	printf("%d %d\n", *x, *y);
}


