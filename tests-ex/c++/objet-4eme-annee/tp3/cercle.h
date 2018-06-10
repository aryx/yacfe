//+++++++++++++++++++++++++++++    cercle.h   +++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"
#include "fenetre.h"

#ifndef CERCLEH
#define CERCLEH

class cercle : public figures
{
  protected :
  int rayon;
  

  
  public :
  cercle() {rayon = 0;}			// donnees initilisees par defaults
  cercle(int xx,int yy,int rayon_param) : figures(xx,yy) {rayon = rayon_param;}// cercle initilise 
  	
  void effacer(fenetre * f);
  void dessiner(fenetre * f);
  	
};

#endif
  
