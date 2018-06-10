#include <stream.h>
#include "tableau.h"
#include "matrice.h"

#ifndef VECTCOLONNEH
#define VECTCOLONNEH

class vect_colonne :public matrice
{
  public :
  vect_colonne(int colonne) : matrice(1,colonne) {};
  int & vect_colonne::operator[](unsigned int colonne);
};
#endif
