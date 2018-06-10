//+++++++++++++++++++++++++++++   point.c   +++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"
#include "fenetre.h"
#include "point.h"

  	
void point::effacer(fenetre *  f)
{
  f->vi_point(BLANC,x,y);
}

 void point::dessiner(fenetre *  f)
{
  f->vi_point(NOIR,x,y);

}

