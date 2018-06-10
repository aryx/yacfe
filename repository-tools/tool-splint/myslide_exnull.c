#include "splint.h"

//0: splint says nothing :( 

//2: force to add __null
extern char __null *gname;

//1: add __null
void setName(char __null *pname)
{
	gname = pname;
}

void foo() 
{
    //3: force to add check
	if(gname != NULL)
		printf("%s", gname);
}
