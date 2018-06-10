#include <stream.h>
#include "tableau.h"
#include "matrice.h"

#ifndef VECTLIGNEH
#define VECTLIGNEH

class vect_ligne :public matrice
{
  public :
  vect_ligne(int ligne) : matrice(ligne,1) {};
  int & vect_ligne::operator[](unsigned int ligne);

};

#endif
