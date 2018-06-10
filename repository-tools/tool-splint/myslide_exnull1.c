#include "splint.h"

//0: splint says nothing :( 
// because pname is @temp@ and yes it creates an alias
// but gname is by default (?) not-only, so the alias is
// allowed. if add __only to gname then splint shout
/*
myslide_exnull1.c:13:2: Implicitly temp storage pname assigned to only:
                           gname = pname
  Temp storage (associated with a formal parameter) is transferred to a
  non-temporary reference. The storage may be released or new aliases created.
  (Use -temptrans to inhibit warning)

pad: shout because new alias created :)
*/


extern char __only *gname;

void setName(char *pname)
/*@globals undef  gname @*/
{
	gname = pname;
}

void foo() 
{
	printf("%s", gname);
}
