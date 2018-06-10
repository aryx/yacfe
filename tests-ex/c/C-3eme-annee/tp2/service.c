/* % Gestion de configuration
 * Creation : 4 avril 95
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification
 *
 */

/*
 * %Module
 *   Nom            : service
 *   Nom du fichier : service.c
 *                  
 *   Fonctions de ce module :
 *  		void ecrire(int t[], int longueur)
 *		     affiche le tableau d'entiers t[1..longueur]
 * 
 *		void lire(int t[], int longueur)
 *		     lit le tableau d'entiers t[1..longueur] 
 *
 *              void echanger(int *x, int *y)
 *                    echange le contenu des 2 variables en parametres
          
 */ 
 
/* 
 * %Fichiers include systeme
 */
#include <stdio.h>
#include <stdlib.h>

/* 
 * %Fichiers include de l'application
*/
#include "service.h" 

/*
 * %Fonction globale
 * Nom : lire
 * Definition : lit le tableau d'entiers t[1..longueur]
 * Argument : int t[],int longueur  ; le tableau t est modifie
 * Resultat : void
 * Variables globales utilisees 
 * Fonctions appelees : scanf,printf
 * Fonctions appelantes : main(princ.c)
 * Erreur detectee : 
 * Commentaires :  on ne lit pas l'element 0 non significatif	     
 */
void lire(int t[], int longueur){
  int i, ok;

  for (i=1; i<=longueur; i++){
    ok = 0;
    while (!ok) {
      printf ("\n\tDonnez un entier(0 non pris): ");
      scanf ("%d", &t[i]);
      if (t[i] != 0){
	ok = 1;
      } /* if */
    } /* while */
  } /* for */
} /* lit */
/*
 * %Fonction globale
 * Nom : remplitab
 * Definition : rempli le tableau d'entiers t[1..longueur]
 * Argument : int t[],int longueur  ; le tableau t est modifie
 * Resultat : void
 * Variables globales utilisees 
 * Fonctions appelees : scanf,printf
 * Fonctions appelantes : main(princ.c)
 * Erreur detectee : 
 * Commentaires :  on ne lit pas l'element 0 non significatif	     
 */
void remplitab(int t[], int longueur){
  int i;

  for (i=1; i<=longueur; i++){
    t[i] = rand ();
  } /* for */
} /* lit */
	
/*
 * %Fonction globale
 * Nom : ecrire 
 * Definition : affiche le tableau d'entiers t[1..longueur]
 * Argument : int t[],int longueur
 * Resultat : void
 * Variables globales utilisees 
 * Fonctions appelees : printf
 * Fonctions appelantes : main(princ.c)
 * Erreur detectee : 
 * Commentaires :  on n'affiche pas l'element 0 non significatif	    
 */
void ecrire(int t[], int longueur){
  int i;

  printf ("\n");
  for (i=1; i<=longueur; i++){
    printf ("%d  ", t[i]);
  } /* for */
  printf ("\n");
} /* ecrire */

/*
 * %Fonction globale
 * Nom : echanger 
 * Definition : permute le contenu des 2 variables
 * Argument : int *x ,int *y
 * Resultat : void
 * Variables globales utilisees 
 * Fonctions appelees : 
 * Fonctions appelantes :  tri_tas(tritas.c)
 * Erreur detectee : 
 * Commentaires : 
 * Creation              : 25 mars 1998
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *		     
 */
 
void echanger(int *x, int *y){
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}
