//+++++++++++++++++++++++++++++   carre.h   +++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "fenetre.h"
#include "rectangle.h"

#ifndef CARREH
#define CARREH

class carre : public rectangle
{
  public :
  carre() {}	//donnees initilisees par defaults
  carre(int xx1,int yy1,int cote) : rectangle(xx1, yy1, cote,cote) {}	//  initialisation
  	
};

#endif
  
