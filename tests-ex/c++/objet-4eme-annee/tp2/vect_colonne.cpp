#include "vect_colonne.h"

int & vect_colonne::operator[](unsigned int colonne)
{
  return (*(pt_tab_pt[0]))[colonne];
}

