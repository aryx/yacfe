//+++++++++++++++++++++++++++++   segment.h   +++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "figures.h"
#include "fenetre.h"

#ifndef SEGMENTH
#define SEGMENTH

class segment : public figures
{
  int lg,ht;
  public :
  segment() {lg = 0; ht = 0;}	// donnees initilisees par defaults
  segment(int xx,int yy,int longueur, int hauteur) : figures(xx,yy) {lg = longueur; ht = hauteur;}// initialisation 
  	
  void effacer(fenetre * f);
  void dessiner(fenetre * f);
  
};

#endif
  
