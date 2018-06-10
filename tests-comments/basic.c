/* file/module comment */

#define X 1 /* macro constant after comment */

/* macro function comment */
#define X(a,b) a+b


/* ifdef comment */
#ifdef X
#endif

// include comment 
#include "toto.c"
#include "titi.c"

#include "basic_comments.h"

/* function comment */
void main(int i)
{
	int i; // decl comment
	return i; /* statement comment */
}


/* struct comment */
struct xx {
	int x; // field1 comment
	int y; // field2 comment
};


void foo(int i,  /* param1 comment */
		 int j)  /* param2 comment */
{

	int x; // local var

	// for comment
	for(x = 0; x < 10; x++) {
		x++;
	}
}
