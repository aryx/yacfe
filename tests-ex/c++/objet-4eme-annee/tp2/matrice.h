#include <stream.h>
#include "tableau.h"

#ifndef MATRICEH
#define MATRICEH

class matrice
{
  protected :
  int taille_ligne;
  int taille_colonne;
  
  tableau** pt_tab_pt;
   
	
  public :
  matrice(unsigned int nn,unsigned int mm);
  ~matrice();
  matrice(const matrice&);

  matrice & matrice::operator=(const matrice& m);

  tableau & matrice::operator[](unsigned int);
  tableau matrice::operator[](unsigned int ligne) const;
  
  friend ostream & operator<<(ostream &,const matrice &);

  friend matrice operator+(const matrice &mat1,const matrice &mat2);
   	
};

#endif
