#include "splint.h"

#include <stdio.h>
#include <stdlib.h>

//4:
static char __only *gname;

//3: add __only
//x: add globals
static void setName(char __only *pname)
/*@globals undef  gname @*/
{
	gname = pname;
}

//x: add static
static void foo()
{
	char *pname = malloc(10 * sizeof(char));

	//1:
	if(pname != NULL) {

		//2: need define it
		pname[0] = '1';
		pname[1] = '\0';

		setName(pname);

		//9: bug
		//printf("%s", pname);
		
	} 
	//6:
	else { exit(0); }
}

//x: add int
int main() {
	foo();

	printf("%s", gname);

	//7:
	free(gname);
	//10:
    //return 0;
	exit(0);
}
