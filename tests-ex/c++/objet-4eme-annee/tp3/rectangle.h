//+++++++++++++++++++++++++++++ rectangle.h +++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"
#include "fenetre.h"

#ifndef RECTANGLEH
#define RECTANGLEH

class rectangle : public figures
{
  protected :
  int ht, lg;
  
  public :
  rectangle() {ht = 0; lg = 0;};	// donnees initilisees par defaults
  rectangle(int xx1, int yy1, int longueur, int hauteur) : figures(xx1,yy1)
  {
    lg = longueur; ht = hauteur;	// rectangle initilise 
  }
  void effacer(fenetre * f);
  void dessiner(fenetre * f);
  	

};

#endif
  
