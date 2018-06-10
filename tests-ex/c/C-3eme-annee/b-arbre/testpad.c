#include "barbtypes.h"
#include "ajout.h"


void main(void)
{
  t_arbre A;
  t_article a;
  int j;
  initmem();

  initarbre(&A);
  imprimer(&A);

  a.cle=3;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);

  a.cle=2;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);

  a.cle=5;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);

  a.cle=1;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);

  a.cle=4;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);

  a.cle=12;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);

  a.cle=13;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);

  a.cle=14;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);


}



