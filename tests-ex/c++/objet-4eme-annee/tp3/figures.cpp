//+++++++++++++++++++++++++++++   figures.c   +++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"


//autres methodes : 
figures::figures() 
{
  x = 0;
  y = 0;
  suivant = ListeFigures;
  ListeFigures = this;
}

figures::figures(int x1, int y1)
{
  x = x1;
  y = y1;
  suivant = ListeFigures;
  ListeFigures = this;
}  

void figures::deplacer(fenetre * f, int xx, int yy)    	
{
  effacer(f);
  x+=xx;
  y+=yy;
  dessiner(f);
}

figures* figures::ListeFigures;

