//+++++++++++++++++++++++++++++    cercle.c   +++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"
#include "fenetre.h"
#include "cercle.h"

void cercle::effacer(fenetre * f)
{
  f->vi_cercle(BLANC,x,y,rayon);
}

void cercle::dessiner(fenetre * f)
{
 f->vi_cercle(NOIR,x,y,rayon);
} 


