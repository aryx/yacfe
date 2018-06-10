#include "splint.h"
#include <stdlib.h>

//TODO: how say that after this func buf will be completely defined ???

//5: add static


static void FillString(__out char* buf, size_t n, char ch)
/* @requires maxSet(buf) == (n - 1) */
 {
	
	size_t i;
	//bug '<='
	for (i = 0; i <= n; i++)   {
		buf[i] = ch;
	}

	//this one is not detected either :(
	buf[n] = '\0';

}

//4: add unused
int main(__unused int argc, char * argv[]) {

	//1: change int->size_t, add cast
	size_t len = (size_t) atoi((const char *)argv[1]);
	char *b = (char*)malloc(200*sizeof(char));
	char c[200];

	//2: force add guard
	if (b) {
	  FillString(b,len,'x');
	  FillString(b,210,'x');
	  FillString(c,210,'x');

	  //3:
	  free(b);
	}
	return 0;
	
}
