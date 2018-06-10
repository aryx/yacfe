#include "chaine.h"
#include <iostream>
using std::cout;

#include <string.h>


// Fonction generale servant a tester si les retours de fct ou retours
// d'allocation sont reussis

void testnull(const void *arg)
{
  if (arg == NULL) {
    cout << "Erreur d'allocation (too many semaphors)";
    exit(-1);
  }
}



chaine::chaine(const char *notre_chaine)
{
  int longueur = strlen(notre_chaine);

  pt = new char[longueur];
  testnull(pt);
  
  testnull(strcpy(pt,notre_chaine));

  lg = longueur;

}



chaine::chaine(const chaine &notre_chaine)
{
  int longueur = notre_chaine.lg;

  pt = new char[longueur];
  testnull(pt);
  
  testnull(strcpy(pt,notre_chaine.pt));

  lg = longueur;

}



chaine::~chaine()
{
  delete[] pt;
  lg = 0;

}


void chaine::afficher(void) const
{

  cout << pt << "\n";

}


chaine & chaine::operator=(const chaine &chaine_source)
{

  if (this != &chaine_source) {
    
    // On libere d'abord l'objet destination
    delete[] pt;


    int longueur = chaine_source.lg;

    pt = new char[longueur];
    testnull(pt);
  
    testnull(strcpy(pt,chaine_source.pt));

    lg = longueur;

  
  }
}


int chaine_strcmp(const chaine &c1,const chaine &c2)
{
  return(strcmp(c1.pt,c2.pt));
}


bool operator<(const chaine &c1,const chaine &c2)
{
  return(chaine_strcmp(c1,c2)<0);
}


bool operator>(const chaine &c1,const chaine &c2)
{
  return(chaine_strcmp(c1,c2)<0);
}


bool operator==(const chaine &c1,const chaine &c2)
{
  return(chaine_strcmp(c1,c2)==0);
}



chaine operator+(const chaine &c1,const chaine &c2)
{
  int longueur = c1.lg + c2.lg;
  chaine chaine_finale;
  
  chaine_finale.pt = new char[longueur];
  testnull(chaine_finale.pt);
  
  strcpy(chaine_finale.pt,c1.pt);
  strcat(chaine_finale.pt,c2.pt);

  chaine_finale.lg = longueur;

  return chaine_finale;

}



chaine operator-(const chaine &c1,const chaine &c2)
{
  char *ch_final = strstr(c1.pt,c2.pt);

  testnull(ch_final);

  int longueur = strlen(ch_final) - strlen(c1.pt);

  chaine chaine_finale;
  chaine_finale.pt = new char[longueur];

  strncpy(chaine_finale.pt,c1.pt,longueur);

  chaine_finale.lg = longueur;

  return chaine_finale;

}



chaine & chaine::operator+=(const chaine &c1)
{
  chaine chaine_tmp = *this + c1;
  *this = chaine_tmp;

  return *this;

}

chaine & chaine::operator-=(const chaine &c1)
{
  chaine chaine_tmp = *this - c1;
  *this = chaine_tmp;

  return *this;

}

char & chaine::operator[](int position)
{
  return pt[position];

}

