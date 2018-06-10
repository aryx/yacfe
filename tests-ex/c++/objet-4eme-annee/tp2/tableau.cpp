#include <stream.h>
#include "tableau.h"


tableau::tableau(int t)
{
  taille = t;
  pt_elements = new int[taille];
}
 
tableau::~tableau()
{
  delete[] pt_elements;
}

tableau::tableau(const tableau& tab)
{
  taille = tab.taille;
  pt_elements = new int[taille];
  for (int i = 0; i < taille; i++)
    pt_elements[i]=tab.pt_elements[i];
}


int & tableau::operator[](unsigned indice)
{
  if (indice >= taille) {
    cout << "erreur lors de l'acces a l'indice du tableau\n";
    exit(0);
  }

  return pt_elements[indice];
}

