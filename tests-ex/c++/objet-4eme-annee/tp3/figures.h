//+++++++++++++++++++++++++++++   figures.h   +++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "fenetre.h"

#ifndef FIGURESH
#define FIGURESH



class figures
{
  protected :
               // attributs d'une figure
  static figures *ListeFigures;
  
  int x,y;
  figures *suivant;
  
  public :
  figures();			// attributs initialises par defaults
  figures(int x1, int y1);     // attributs initialisees

  int pos_x() {return x;}			//pour recuperer la position x 
  int pos_y() {return y;}			//pour recuperer la position y 
  
//autres methodes : 
  
  virtual void effacer(fenetre *) = 0;  
  virtual void dessiner(fenetre *) = 0;  
  
  void deplacer(fenetre * f, int xx, int yy);
  static void init() {ListeFigures = NULL;}
  static figures* le_premier() {return ListeFigures;}
  figures* le_suivant() {return suivant;}
  
};

#endif
  	
  	
