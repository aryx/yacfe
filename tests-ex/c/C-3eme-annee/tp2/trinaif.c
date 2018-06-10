/* % Gestion de configuration
 * Creation : 25 mars 98
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification : 
 *
 */

/*
 * %Module
 *   Nom            : trinaif
 *   Nom du fichier : trinaif.c
 *                  
 *
 *   Fonctions de ce module :
 *  		void tri_naif (int t[], int n)
 *		     trie le tableau d'entiers t[1..n]   
 */ 
 
/* 
 * %Fichiers include systeme
 */
#include "stdio.h"

/* 
 * %Fichiers include de l'application
*/
#include "service.h" 
#include "trinaif.h"

/*
 * %Fonction globale
 * Nom : tri_naif
 * Definition : trie le tableau d'entiers t[1..n]
 * Argument : int t[],int n  ; le tableau t est modifie
 * Resultat : void
 * Variables globales utilisees 
 * Fonctions appelees : echanger 
 * Fonctions appelantes : main(princ.c)
 * Erreur detectee : 
 * Commentaires :  on ne trie pas l'element 0 (compatibilite tri en tas)
 * Creation              : 25 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *		     
 */
 

void tri_naif(int t[], int n)
{ int i,j,jmax ;  

   for (i = n ; i>1 ; i--)
    {
     for (j =i, jmax=i ; j >= 1 ; j--) 
       { if (t[j]>t[jmax]) jmax = j ;
       }/* fin  for (j =1, jmin=1 ; j <= i ; j++) */

      echanger(&t[jmax],&t[i]);
    }/* fin  for (i = n; i>1 ; i--) */
}/* tri_naif */

 
