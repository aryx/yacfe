
/*
 * %Module
 *   Nom            : princ
 *   Nom du fichier : princ.c
 *   Role du module : saisie de graphe et conversion de representation 
 *                    
 *
 *   Fonctions de ce module :
 *             
 *
 *                 main : no comment
 *
 */
 
 
/* 
 * %Fichiers include systeme
 */
#include <stdio.h>


/* 
 * %Fichiers include de l'application
 */
 
#include "graphe.h" 


/* 
 * % Prototype des fonctions externes appelées dans ce module
 *
 *
 *          saisiegraphe_ds : saisie d'un graphe sous forme du dico des succ
 *              prototype :  Grapheds saisiegraphe_ds(void)
 *
 *          ds_vers_ma  : dico des successeurs vers matrice des arcs
 *              prototype :  Graphema ds_vers_ma(Grapheds g)
 * 
 *          ecrigraphe_ma   : affichage de la matrice des arcs
 *              prototype :  void ecrigraphe_ma(Graphema g)
 *
 *
 */    






int main ()
 {
/* 
 * Declaration des variables locales 
 */
  Grapheds gds;		 /*  le graphe "dico des successeurs"  */
   
  Graphema gma;          /*    le graphe "matrice des ars"     */
  
  /* test de la fonction de saisie   */
  gds  = saisiegraphe_ds(); 

  /* test de la conversion  */ 
  gma   = ds_vers_ma(&gds);
  
  /* test de l'affichage             */
  printf("Le graphe lu sous forme de matrice des arcs : \n");
  ecrigraphe_ma(gma);
  
 }
