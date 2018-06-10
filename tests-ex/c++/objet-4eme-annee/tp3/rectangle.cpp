//+++++++++++++++++++++++++++++ rectangle.c +++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"
#include "fenetre.h"
#include "rectangle.h"


  	
void rectangle::effacer(fenetre * f)
{
  f->vi_rectangle(BLANC,x,y,x+lg,y+ht);
}

void rectangle::dessiner(fenetre * f)
{
  f->vi_rectangle(NOIR,x,y,x+lg,y+ht);

}
	

