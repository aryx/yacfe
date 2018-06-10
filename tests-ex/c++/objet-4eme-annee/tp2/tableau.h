#include <stream.h>

#ifndef TABLEAUH
#define TABLEAUH

class tableau
{
  
  unsigned taille;
  int * pt_elements;
  
  public :
  tableau(int t);
  ~tableau(); 	
  tableau(const tableau& tab);
  int & operator[](unsigned indice);

};

#endif
