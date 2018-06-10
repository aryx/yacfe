/******************************************************************************
*******************************************************************************
** Matière                        :    BASES DE DONNEES
** Sujet                          :    B_ARBRES
** Unité de compilation           :       
** Nom du module                  :    test.c
*******************************************************************************
** Description                    : initialisation et creation d'un B-arbre
**
******************************************************************************/

#include <stdio.h> 
#include "barbtypes.h" 
/*******************************************************************************
*                      jeux d'essai, programme principal                       *
*******************************************************************************/
                                      /****************************************
                                      * Nom         :  main
                                      * Description : jeux d'essai 
                                      *               creation d'un B-arbre
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : initmem,
                                      *                            initarbre,
                                      *                            ajouter,
                                      *                            imprimer
                                      ****************************************/
main()
{
  t_arbre A;
  t_article a;
  int in, j;

  printf ( "debut \n");
  initmem();

  initarbre (&A);
  imprimer (&A);

  a.cle = 3;
  for (j = 1; j<taille; j++)
    a.c[j] = 'c';
  ajouter(&A, a);
  imprimer (&A);


  a.cle = 4;
  for (j = 1; j<taille; j++)
    a.c[j] = 'd';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 2;
  for (j = 1; j<taille; j++)
    a.c[j] = 'b';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 1;
  for (j = 1; j<taille; j++)
    a.c[j] = 'b';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 5;
  for (j = 1; j<taille; j++)
    a.c[j] = 'e';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 6;
  for (j = 1; j<taille; j++)
    a.c[j] = 'f';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 7;
  for (j = 1; j<taille; j++)
    a.c[j] = 'g';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 8;
  for (j = 1; j<taille; j++)
    a.c[j] = 'h';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 9;
  for (j = 1; j<taille; j++)
    a.c[j] = 'i';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 10;
  for (j = 1; j<taille; j++)
    a.c[j] = 'j';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 11;
  for (j = 1; j<taille; j++)
    a.c[j] = 'k';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 12;
  for (j = 1; j<taille; j++)
    a.c[j] = 'l';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 6;
  for (j = 1; j<taille; j++)
    a.c[j] = 'f';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 7;
  for (j = 1; j<taille; j++)
    a.c[j] = 'g';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 13;
  for (j = 1; j<taille; j++)
    a.c[j] = 'm';
  ajouter(&A, a);
  imprimer (&A);

  a.cle = 1;
  for (j = 1; j<taille; j++)
    a.c[j] = 'a';
  ajouter(&A, a);
  imprimer (&A);



  a.cle = 14;
  for (j = 1; j<taille; j++)
    a.c[j] = 'n';
  ajouter(&A, a);
  imprimer (&A);



  a.cle = 15;
  for (j = 1; j<taille; j++)
    a.c[j] = 'o';
  ajouter(&A, a);
  imprimer (&A);



  a.cle = 16;
  for (j = 1; j<taille; j++)
    a.c[j] = 'p';
  ajouter(&A, a);
  imprimer (&A);


}
