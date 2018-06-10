/* % Gestion de configuration
 * Creation : 4 avril 95
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification 26 mars 98
 *
 */
/*
 * %Module
 *   Nom            : trirapide
 *   Nom du fichier : trirapide.c
 *   Role du module : trier un tableau selon l'algorithme du tri rapide
 *                    
 *
 *   Fonctions de ce module :
 * locales : 
 *      partitionner :  int partitionner (int p , int r )
 *              prototype : int partitionner (int A[], int p, int r)
 *	tri_rapide : realise le tri d'un tableau
 *		prototype : void tri_rapide(int A[], int p, int q)
 *
 * globales :
 *  	prototype : void tri_rap (int t[], int n)
 *		     trie le tableau d'entiers t[1..n]
 *                   selon la methode du tri rapide
 *		
 */
  
/* 
 * %Fichiers include systeme
 */

/* 
 * %Fichiers include de l'application
 */
#include "trirapide.h"
#include "service.h"


/* 
 * % Prototype des fonctions externes appelees dans ce module
 * 
 *          void echanger(int *x, int *y)
 *               echange 2 variables
 */
 
/*
 * %Fonction locale
 * Nom : partitionner
 * Definition : partitionne un tableau et retourne l'indice du pivot
 * Argument : int a[], int p, int r     
 * Resultat : int      
 * Variables globales utilisees : neant
 * Fonctions appelées : echanger
 * Fonctions appelantes : tri_rapide
 */
int partitionner (int A[], int p, int r){
  int x, i, j;

  x = A[p];
  i = p-1;
  j = r+1;

  for (;;) {
    do {
      j = j-1;
    } while ( A[j] > x);
    do {
      i++;
    } while (A[i] < x);
    if (i<j) {
      echanger (&A[i], &A[j]);
    } else {
      return j;
    } /* if */
  }
  
} /* partitionner */

/*
 * %Fonction locale
 * Nom : tri_rapide
 * Definition : realise le tri d'un tableau
 * Argument : int A[], int p, int q     
 * Resultat : void
 * Variables globales utilisees : neant
 * Fonctions appelées : partitionner
 * Fonctions appelantes : main
 */
void tri_rapide (int A[], int p, int r){
  int q;

  if (p < r) {
    q = partitionner (A, p, r);
    tri_rapide (A, p, q);
    tri_rapide (A, q+1, r);
  } /* if */
} /* tri_rapide */

/*
 * %Fonction globale
 * Nom : tri_rap
 * Definition : realise le tri d'un tableau
 * Argument : int A[], int q     
 * Resultat : void
 * Variables globales utilisees : neant
 * Fonctions appelées : partitionner
 * Fonctions appelantes : main
 */
void tri_rap( int t[], int n){
  tri_rapide (t, 1, n);
} /* tri_rap */
