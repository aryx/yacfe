#include <stdio.h>

// ex from manual but generates lots of warning

void apply(void (*fn)(TV(t) data), TV(t) data) {
	fn(data);
}

void callback_int(int data) {
	printf("int\n");
	return;
}
// generate warning, wierd, and if add TRUSTED then dont typecheck anymore
void callback_ptr(int * data) {
	printf("int star\n");
	return;
}

int i = 1;

void main(void) {
	apply(callback_int, i); // TV(t) == int 
	apply(callback_ptr, &i); // TV(t) == int 


	//apply(callback_ptr, i); // error


}
