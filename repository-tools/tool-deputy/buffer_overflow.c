#include <stdlib.h>

//TODO: how say that after this func buf will be completely defined ???


static void FillString(char* COUNT(n) buf, size_t n, char ch)
 {
	
	size_t i;
	//bug '<='
	for (i = 0; i <= n; i++)   {
		// not detected :( I guess they don't handle loops
		buf[i] = ch;
	}
	
	//this one is detected
	buf[n] = '\0';

}

int main(int argc, char * argv[]) {

	size_t len = (size_t) atoi((const char *)argv[1]);
	char *b = (char*)malloc(200*sizeof(char));
	
	char c[200];

	if (b) {
		FillString(b,len,'x'); // not detected
		FillString(b,210,'x');
		FillString(c,210,'x');
		FillString(b,200,'x');
		FillString(c,200,'x');

	  free(b);
	}
	return 0;
	
}
