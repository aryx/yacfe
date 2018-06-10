//+++++++++++++++++++++++++++++   segment.c +++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <stream.h>
#include "segment.h"
#include "fenetre.h"

  	
void segment::effacer(fenetre * f)
{
  f->vi_vect(BLANC,x,y,x+lg,y+ht);
}

void segment::dessiner(fenetre * f)
{
  f->vi_vect(NOIR,x,y,x+lg,y+ht);
}
