//+++++++++++++++++++++++++++++   point.h   +++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"
#include "fenetre.h"

#ifndef POINTH
#define POINTH

class point : public figures
{
  protected :
	
  public :
  point() {} 			// x et y initilisees a 0
  point(int xx,int yy) : figures(xx,yy) {}	// x et y initilisees 
  	
  void effacer(fenetre * f);
  void dessiner(fenetre * f);

};

#endif
  
