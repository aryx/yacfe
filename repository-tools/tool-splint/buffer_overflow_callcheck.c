#include <stdlib.h>


void FillString(char* buf, size_t cchBuf, char ch) {
	
	size_t i;
	for (i = 0; i < cchBuf; i++)   {
		buf[i] = ch;
	}

}

int main(int argc, char * argv[]) {

	int len = atoi((const char *)argv[1]);
	char *b = (char*)malloc(200*sizeof(char));
	//FillString(b,210,'x');
	FillString(b, 210,'x');
	/*if (b)
	  FillString(b,len,'x');*/
	return 0;
	
}
