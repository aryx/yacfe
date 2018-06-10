#include "vect_ligne.h"


int & vect_ligne::operator[](unsigned int ligne)
{
  return (*(pt_tab_pt[ligne]))[0];
}


