/*
 * %Module
 *   Nom            : graphe
 *   Nom du fichier : graphe.c
 *   Role du module : fournir les operations de saisie, d'ecriture et de 
 *                    conversion de representation d'un graphe
 *		      fournit aussi des fonctions pour allouer des tableaux
 *		      de Succ ou Sommet et desallouer un Grapheds
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
 *	    alloueptsucc : alloue un vecteur de nb Succ
 *		prototype : Succ * alloueptsuc(int nb)
 *
 *	    alloueptsom : alloue un vecteur de nb Sommet
 *		prototype : Sommet * alloueptsom(int nb)
 *	    
 *	    libere	: libere les elements d'un Grapheds
 *		prototype : void libere( Grapheds gds)
 * 
 *	    ajuste      : ajuste la place alloue au vecteur de sommets
 *		prototype : Sommet * ajuste(Succ *pts)
 *	    
 *	    ajoute  	: ajoute un sommet au vecteur pointe par Succ
 *		prototype : void ajoute (Succ *pts , Sommet s)
 *
 */
 

/* 
 * %Fichiers include systeme
 */
#include <malloc.h>
#include <stdlib.h>
#include <stddef.h>


/* 
 * %Fichiers include de l'application
 */
#include "graphe.h"


/*
 * %Fonction locale
 * Nom : existearc_ds
 *
 * Definition : teste la presence d'un arc dans un graphe represente par un
 *                 dico de successeurs
 *
 * Argument : 
 *      Grapheds g
 *      Sommet   x
 *      Sommet   y
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *
 * Erreur detectee : 
 *
 * Commentaires : 
 *       on recupere d'emblee les successeurs de x, puis on cherche y
 *       dans les successeurs de x
 *       
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                   
 */
 
static Bool existearc_ds(Sommet x, Sommet y, Grapheds g){
  Succ succx;
  Sommet i=0;
  Bool trouve = faux;

  succx = *(g.ptsucc+x);    /* succx contient la structure succ pointant sur les
			       successeurs de x */
  while (!trouve && (succx.ptsom < (succx.ptsom+succx.nbsucc))){
			    /* On recherche y parmi les successeurs de x */
    if (*(succx.ptsom) == y){
      trouve = vrai;
    }else{
      succx.ptsom++;
    }
  }
  
} /* existearc_ds */


 
/*
 * %Fonction 
 * Nom : ds_vers_ma
 *
 * Definition : alloue et initialise un graphe par conversion de dico
 *               des successeurs vers matrice des arcs
 *
 * Argument : 
 *      Grapheds g
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      calloc libere
 *
 * Erreur detectee : 
 *      allocation impossible (calloc retourne NULL)
 *
 * Commentaires : 
 *       le graphe g sous forme de dico des successeurs est converti en
 *       une representation par matrice des arcs 
 *       l'espace alloue a g est rendu au systeme
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                   
 */

Graphema ds_vers_ma(Grapheds *g){
  Graphema mat;
  Bool *tabmat;
  int i, j;

		  /* Initialisation de la matrice */
  mat.nbsom = g->nbsom;
  mat.pt2dim = (Bool*)calloc ((g->nbsom)*(g->nbsom), sizeof(Bool));

  if (mat.pt2dim == NULL){
    printf ("\nErreur: allocation impossible mat.pt2dim - ds_vers_ma\n");
    exit (1);
  }
	          /* Initialisation du tableua de successeurs */
  tabmat = mat.pt2dim;
  for (i=0; i < ((g->nbsom)*(g->nbsom)); i++){
    tabmat[i] = faux;
  }


		  /* Parcours des successeurs */
  for (i = 0; i < g->nbsom; i++){
	          /* Parcours des sommets */
    for (j = 0; j < g->ptsucc[i].nbsucc; j++){
      tabmat[(i*g->nbsom) + (g->ptsucc[i].ptsom[j])] = vrai;
    }	/* Fin du parcours des sommets */
  }	/* Fin du parcours des successeurs */

		  /* Liberation de la representation par dico */
  libere (g);

  return mat;
} /* ds_vers_ma */
 


/*
 * %Fonction 
 * Nom : ecrigraphe_ma
 *
 * Definition : affiche le graphe sous forme d'une matrice d'existence
 *              des arcs.
 *
 * Argument : 
 *      Graphema g
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      neant
 *
 * Erreur detectee : 
 *
 * Commentaires : 
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                   
 */
 
void ecrigraphe_ma(Graphema g){
   Sommet i, j;

   printf("\n\t   0   1   2   3");
   for (i = 0; i < g.nbsom; i++){
     printf ("\n\t%1d |", i);
     for (j = 0; j < g.nbsom; j++){
       if (g.pt2dim [(i*g.nbsom)+j]) {
			/* Le successeur existe */
	 printf (" v ");
       } else {
	 printf (" f ");
       }
     }	/* fin for j */
   }	/* fin for i */
   printf ("\n\n");
} /* ecrigraphe_ma */




 
/*
 * %Fonction 
 * Nom : alloueptsucc
 *
 * Definition : alloue un tableau de nb SUCC et delivre son adresse
 *
 * Argument : 
 *      nb nombre de sommets
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      calloc
 *
 * Erreur detectee : 
 *      allocation impossible (calloc retourne NULL)
 *
 *
 * Commentaires :  
 *
 * Creation              : 30 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
Succ * alloueptsucc(int nb){
  Succ* pttab;

  if ((pttab = (Succ*)calloc(nb, sizeof(Succ))) == NULL) {
    printf ("\nErreur: Allocation impossible - alloueptsucc\n");
    exit (1);
  } else {
    pttab->nbsucc = 0;
    return pttab;
  }

} /*alloueptsucc*/

        
/*
 * %Fonction 
 * Nom : alloueptsom
 *
 * Definition : alloue un tableau de nb Sommet et delivre son adresse
 *
 * Argument : 
 *      nb nombre de sommets
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      calloc
 *
 * Erreur detectee : 
 *      allocation impossible (calloc retourne NULL)
 *
 *
 * Commentaires :  
 *
 * Creation              : 30 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
Sommet * alloueptsom(int nb){
  Sommet* pttab;

  if ((pttab = (Sommet*)calloc(nb, sizeof(Sommet)))==NULL) {
    printf ("\nErreur: Allocation impossible - alloueptsom\n");
    exit (1);
  }else{
    return pttab;
  }
  
} /*initptsom*/

  
        
/*
 * %Fonction 
 * Nom : libere
 *
 * Definition : libere la place allouee a un Grapheds
 *
 * Argument : 
 *      Grapheds *gds
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      free
 *
 * Erreur detectee : 
 *      retour de free
 * Commentaires :  
 *
 * Creation              : 30 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
void libere (Grapheds *gds){
  Succ *sucfin, *suc;

  sucfin = (gds->ptsucc + gds->nbsom);

		/* Liberation des Sommets */
  for (suc = gds->ptsucc; suc < sucfin; suc++){
    free (suc->ptsom);
  }
		/* Liberation des Succ */
  free (gds->ptsucc);
  gds->ptsucc = NULL;
  gds->nbsom = 0;
} /* libere */


        
/*
 * %Fonction 
 * Nom : ajuste
 *
 * Definition : ajuste la place alloue pour un vecteur de sommets en 
 *		fonction du nombre de successeurs effectivement presents
 * 		
 *
 * Argument : Succ *pts
 *		
 *      
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      realloc
 *
 * Erreur detectee : 
 *      retour de realloc
 * Commentaires :  peut ne pas servir pour le TP6_1 depend de votre lecture
 * 		   de graphe 
 *
 * Creation              : 30 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
Sommet * ajuste (Succ * pts ){
  Sommet *pt;

  if ((pt = (Sommet*)realloc ((Sommet*)pts->ptsom, (pts->nbsucc)*sizeof(Sommet))) == NULL) {
    printf ("\nErreur: allocation impossible - ajuste\n");
    exit (1);
  }
  return pt;
}/* ajuste*/ 

        
/*
 * %Fonction 
 * Nom : ajoute
 *
 * Definition : ajoute un sommet au vecteur pointe par Succ
 * 		s'il n'y est pas deja
 *
 * Argument : Succ *pts
 *	      Sommet s 
 *      
 *      
 * Commentaires :  
 *
 * Creation              : 30 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
void ajoute (Succ *pts , Sommet s){
  Sommet i;
  Bool trouve = faux;

  i = 0;
  while ((i < pts->nbsucc) && !trouve){
    if (*(pts->ptsom + i) == s){
      trouve = vrai;
    } else {
      i++;
    }
  }

  if (!trouve) {
		/* On rajoute le sommet */
    *(pts->ptsom + pts->nbsucc) = s;
    pts->nbsucc++;
  }
}/*ajoute*/


/*
 * %Fonction 
 * Nom : saisiegraphe_ds
 *
 * Definition : alloue et initialise un graphe par lecture
 *
 * Argument : 
 *      neant
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      alloueptsucc  alloueptsom  ajoute scanf
 *
 * Erreur detectee : 
 *      lecture avortee (scanf rend le nbre de valeurs effectivement lues)
 *
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                   
 */

Grapheds saisiegraphe_ds(void){
  Grapheds gds;
  Succ *pts;
  Sommet carlu;
  int nb, nbsuc;	/* Nombre de sommets et de successeurs */
  int i, j;

  printf ("\n\tCombien de sommets?  ");
  scanf ("%d", &nb);

  gds.nbsom = nb;
  gds.ptsucc = alloueptsucc (nb);
  
			/* Lecture des successeurs des sommets i */
  for (i = 0; i < nb; i++){
    printf ("\nCombien de successeurs possede le sommet %1d?", i);
    scanf ("%d", &nbsuc);
    
    pts = &(gds.ptsucc[i]);
    pts->ptsom = alloueptsom (nbsuc);

    for (j=0; j < nbsuc; j++){
      printf ("\nSuccesseur du sommet %1d?", i);
      scanf ("%d", &carlu);
      ajoute (pts, carlu);
    }
  }
  return gds;
} /* saisiegraphe_ds */
