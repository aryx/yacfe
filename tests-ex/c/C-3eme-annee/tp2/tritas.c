/* % Gestion de configuration
 * Creation : 4 avril 95
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification 26 mars 98
 *
 */
/*
 * %Module
 *   Nom            : tritas
 *   Nom du fichier : tritas.c
 *   Role du module : trier un tableau selon l'algorithme du tri en tas
 *                    
 *
 *   Fonctions de ce module :
 * locales :
 *      pere : indice du pere
 *              prototype : int pere (int i)
 * 	gauche : indice du fils gauche
 *		prototype : int gauche(int i)
 *	droit : indice du fils droit
 *		prototype : int droit(int i)
 *	entasser : fait descendre la valeur en A[i] de maniere que le 
 *		   sous-arbre enracine en i devienne un tas
 *		prototype : void entasser(int A[], int taille, int i)
 *	construire_tas : convertit un tableau en tas
 *		prototype : void construire_tas(int A[], int *taille, int longueur)
 *
 * globales :
 *
 *	tri_tas : realise le tri d'un tableau
 *		prototype : void tri_tas(int A[], int longueur)
 *		
 */
  
/* 
 * %Fichiers include systeme
 */

/* 
 * %Fichiers include de l'application
 */
#include "tritas.h"
#include "service.h"


/* 
 * % Prototype des fonctions externes appelees dans ce module
 * 
 *          void echanger(int *x, int *y)
 *               echange 2 variables
 */
 
/*
 * %Fonction locale
 * Nom : pere
 * Definition : indice du pere 
 * Argument : int      
 * Resultat : int      
 * Variables globales utilisees : neant
 * Fonctions appelées : neant
 * Fonctions appelantes : construire_tas
 */
int pere(int i){
  return (i/2);
} /* pere */

/*
 * %Fonction locale
 * Nom : gauche
 * Definition : indice du fils gauche 
 * Argument : int      
 * Resultat : int      
 * Variables globales utilisees : neant
 * Fonctions appelées : neant
 * Fonctions appelantes : entasser  
 */
int gauche(int i){
  return (2*i);
} /* gauche */

 
/*
 * %Fonction locale
 * Nom : droit
 * Definition : indice du fils droit 
 * Argument : int      
 * Resultat : int      
 * Variables globales utilisees : neant
 * Fonctions appelantes : entasser
 * Fonctions appelees : neant
 */
int droit(int i){
  return (2*i+1);
} /* droit */


/*
 * %Fonction locale
 * Nom :  entasser
 * Definition : fait descendre la valeur en A[i] de maniere que le 
 *		   sous-arbre enracine en i devienne un tas
 * 		taille est le nombre d'element du tableau
 * Argument : int A[], int taille, int i    
 * Resultat :  void 
 * Variables globales utilisees :  neant
 * Fonctions appelees : echanger(service.c)
 * Fonctions appelantes : construire_tas, tri_tas
 */
void entasser(int A[], int taille, int i){
  int l, r, max;

  l = gauche (i);
  r = droit (i);
  if ((l <= taille) && (A[l] > A[i])){
    max = l;
  } else {
    max = i;
  }

  if ((r <= taille) && (A[r] > A[max])) {
    max = r;
  }

  if (max != i) {
    echanger (&A[i], &A[max]);
    entasser (A, taille, max);
  }
} /* entasser */


/*
 * %Fonction locale
 * Nom :  construire_tas
 * Definition : convertit un tableau A de longueur "longueur" en tas
 * Argument : int A[], int *taille, int longueur    
 * Resultat :  void 
 * Variables globales utilisees :  neant
 * Fonctions appelees : entasser
 * Fonctions appelantes : tri_tas
 */
void construire_tas(int A[], int *taille, int longueur){
  int i;

  *taille = longueur;
  for (i= pere(longueur); i>=1; i--){
    entasser (A, *taille, i);
  }/* for */
} /* construire_tas */

/*
 * %Fonction globale
 * Nom :  tri_tas
 * Definition : trie en tas d'un tableau A de longueur "longueur" 
 * Argument : int A[], int *taille, int longueur    
 * Resultat :  void 
 * Variables globales utilisees :  neant
 * Fonctions appelees : echanger (service.c), entasser
 * Fonctions appelantes : main(princ.c)
 */
void tri_tas(int A[], int longueur){
  int i;
  int taille;

  construire_tas (A, &taille, longueur);
  for (i= longueur; i >=2; i--){
    echanger (&A[1], &A[i]);
    taille = taille - 1;
    entasser (A, taille, 1);
  } /* for */
} /* tri_tas */
