

/*
 * %Module
 *   Nom            : princ
 *   Nom du fichier : princ.c
 *   Role du module : etudier une suite de nombres complexes. Ce module est un
 *                    pretexte pour utiliser certainss services offerts par le
 *                    module comp
 *                    
 *
 *   Fonctions de ce module :
 *             proj : projection d'un complexe sur un autre
 *                 prototype : Complexe proj(Complexe z0, Complexe z1)
 *
 *             suite : calcule le terme de rang n d'une suite complexe
 *                 prototype : Complexe suite(int n)
 *
 *             main : no comment
 *
 */
 
 
/* 
 * %Fichiers include systeme
 */
#include <stdio.h>
#include <math.h>


/* 
 * %Fichiers include de l'application
 */
#include "comp.h" 


/* 
 * % Prototype des fonctions externes appelées dans ce module
 *    
 *
 *   a completer selon ce que vous utilisez du module comp
 *
 */
 

/*
 * %Fonction locale
 * Nom : proj
 *
 * Definition : calcule la projection d'un complexe sur un autre
 *
 * Argument : 
 *      Complexe z0
 *      Complexe z1
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      module    (tp2 / comp.c)
 *      argument  (tp2 / comp.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :  le complexe zp calcule est defini par :
 *        module de zp   = module de z0 * cos(argument de z1 - argument de z0)
 *        argument de zp = argument de z1
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

static Complexe proj(Complexe z0, Complexe z1){
  float f1, f2;
  
  f1 = partmodule (z0) * cos(partargument(z1)-partargument(z0));
  f2 = partargument(z1);

  return initcpol(f1, f2);
}
 



/*
 * %Fonction 
 * Nom : suite
 *
 * Definition : calcule le terme de rang i d'une suite complexe decrite dans
 *              le commentaire
 *
 * Argument : 
 *       Entier i
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      proj    (tp2 / princ.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :   Z0 = 10
 *                  Z1 = 20 e i pi/4
 *                  Zi = projection de Zi-1 sur Zi-2
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe suite(int n){
  Complexe res;
  float pi;

  pi = 3.14;

  if (n==0){
    res = initcrect (10, 0);
  } else if (n==1) {
    res = initcpol (20, pi/4);
  } else {
    res = proj(suite(n-1), suite(n-2));

  }

  return res;
}

  
  
  
int main (void)
  {
/*
 * Declaration des variables locales
 */
    int x;                   /* rang du terme a calculer */
    
    Complexe c2;

    printf(" Entrer le rang de l'element a calculer :");
    scanf(" %d",&x);
    c2  = suite (x);
    ecrirec(c2);
    printf ("\n");
    ecrirec(C_i);
    printf ("\n");
  }
/*** Jeux d'essais
  volvic[62] comp
  Entrer le rang de l'element a calculer :0
  10 + 0i 
  0 + 1i 
  volvic[63] comp
  Entrer le rang de l'element a calculer :1
  20.000000e(0.785000i) 
  0 + 1i 
  volvic[64] comp
  Entrer le rang de l'element a calculer :2
  14.147765e(0.000000i) 
  0 + 1i 
  volvic[65] comp
  Entrer le rang de l'element a calculer :3
  10.007963e(0.785000i) 
  0 + 1i 
  volvic[66]
  */
