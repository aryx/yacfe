


/*
 * %Module
 *   Nom            : gener
 *   Nom du fichier : gener.c
 *   Role du module : construit le graphe de dependance des procedures
 *			d'un programme dont la grammaire est lang.pad
 *			et affiche les commentaires extraits du programme
 *			source analyse
 *
 * prototype des fonctions definies dans le module
 * globales :
 *
 *	executer : execute le numero d'action fourni par l'analyseur
 *		prototype : void executer (int i)
 * locales :
 *	affiche : affiche l'identificateur correspondant a un sommet 		
 *		prototype : void affiche( int nosom)
 *
 *	numid_v_som : calcule le no de sommet correspondant au numid 
 *		      s'il y est deja
 *		      sinon range le numid dans la table tabnumid
 *		prototype : int numid_v_som (int numid) 
 *
 *	imprime_com : imprime les commentaires extraits d'un programme
 *		      a partir de la  matrice  representant le graphe de 
		      dependance
 *		prototype : void imprime_com(Graphema gma)	
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
 * % Prototype des fonctions externes appelées dans ce module
 *
 * definie dans lexico.p 
 *	    repid : delivre l'identificateur a partir de numid 
 *  		prototype : void repid(int numid, typid *idlu) 
 *
 * definies dans graphe.c
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
 *	     ajoute  	: ajoute un sommet au vecteur pointe par Succ
 *		prototype : void ajoute (Succ *pts , Sommet s)

 */

/* definition des types C correspondant aux types Pascal
 *  aux variables externes  definis par Padre 
 *  prototype de la procedure repid
 */

typedef struct {
 	 	int lg;
		char c[32];
                } typid ;
         
/* on ne peut faire un include de lexico.h qui est ecrit en Pascal
 * on definit donc le prototype en langage C de repid et l'attribut 
 * lexical numid
 */ 
extern void repid(int numid, typid *idlu);
extern int numid;


/*
 *  definition des variables globales et des constantes  du programme
 */
const nmax = 10;
static  Grapheds gds;  /* graphe sous forme de dictionnaire des successeurs */
static  Graphema gma ;  /* graphe sous forme de matrice */

static  int tabnumid[11] ;
			/* table pour ranger les numid des noms de procedures
			    l'indice ou il est range correspond au numero
 			     de sommet dans le graphe */
static int nb = 0 ; 	 /* nombre de numid presents dans la table */


/*
 * %Fonction locale
 * Nom : affiche 
 *
 * Definition :	affiche l'identificateur correspondant a un sommet du graphe
 *		il faut d'abord rechercher le numid correspondant  
 * Argument : 
 *      int nosom
 *
 * Variables globales utilisees :
 *      tabnumid
 *
 * Fonctions appelees :
 * Commentaires : une chaine C est un tableau de caracteres, le 0 est la marque
 *		   de fin de chaine => il faut donc le rajouter
 *
 * Creation              : 29 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
static void affiche(int nosom) {
  typid idlu;

  repid (tabnumid[nosom], &idlu);
  idlu.c[idlu.lg] = '\0';

  printf (" %s ", idlu.c);
}

 			    
 /* %Fonction locale
 * Nom : numid_v_som
 *
 * Definition :	calcule le no de sommet correspondant au numid  s'il y est deja
 *		sinon range le numid dans la table tabnumid
 * Argument : 
 *      int numid 
 *
 * Variables globales utilisees :
 *      tabnumid nb 
 * Erreur detectee : saturation de la table
 *
 * Commentaires : 
 *
 * Creation              : 29 avril 98
 * Auteur/Origine        : M.J. Pedrono
 */

static int numid_v_som (int numid) 
{
  int i,k ;
  
  if (nb == nmax +1) {
    printf("table numid saturee\n");
  }/*if*/

  tabnumid[nb] = numid ; /* on force la presence de numid en fin de tableau */
  i=0;
  while (tabnumid[i] != numid) i++ ;
  if (i==nb) nb++ ; /* on a rajoute le numid dans la table */

  return i;
}/* numid-v-som */


/*
 * %Fonction locale
 * Nom : imprime_com
 *
 * Definition :	imprime les commentaires extraits d'un programme a partir de la  
 * 		matrice  representant le graphe de dependance
 * Argument : 
 *      Graphema gma
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *       affiche
 * Commentaires : 
 *
 * Creation              : 29 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
static void imprime_com(Graphema gma)
{
  int j,k;

		/* on s'interesse a chaque procedure  */
  for (j=0 ; j <gma.nbsom-1 ; j++){     
    printf("\n\n\nprocedure ") ; affiche(j) ;     
    printf("\nprocedure appelees : ");

    for (k=0; k < gma.nbsom; k++){
      if (gma.pt2dim[j*gma.nbsom + k] == vrai) {
	affiche (k);
      }
    }

    printf("\nprocedure appelantes : ");

    for (k=0; k < gma.nbsom; k++){
      if (gma.pt2dim[j+k*gma.nbsom] == vrai){
	affiche (k);
      }
    }
  }/*for (j=0 ; ...*/

  j = gma.nbsom-1;
  printf("\n\n\nprogramme principal : ");
  affiche (j);
  printf("\nprocedure appelees : ");

  for (k=0; k < gma.nbsom; k++){
    if (gma.pt2dim[j*gma.nbsom + k] == vrai) {
      affiche (k);
    }
  }
	
}/* imprime_com */

       

/*
 * %Fonction  globale
 * Nom : execute
 *
 * Definition :	 c'est la procedure qui execute le code correspondant aux
 * 		points de generation mis dans la grammaire
 * 		
 * Argument : 
 *      int i
 *
 * Variables externes utilisees : numid (attribut lexical)
 *      neant
 *
 * Fonctions appelees :
 *
 * Erreur detectee : 
 * Creation              : 29 avril 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *                   
 */
 
void executer(int i){ 
  static int numprog;

  switch (i){
  case 1 :
    gds.nbsom = 0;
    gds.ptsucc = alloueptsucc (nmax);
		    /* Sauvegarde du numid du nom du programme */
    numprog = numid;
    break;
  case 2 :
    numid_v_som (numid);

		    /* Ajout d'un sommet correspondant a une procedure */
    gds.ptsucc[gds.nbsom].ptsom = alloueptsom(nmax);
    gds.nbsom++;
    break;
  case 3 :;
    ajoute (&(gds.ptsucc[gds.nbsom-1]), numid_v_som(numid));
    break;
  case 4 :
    gds.ptsucc[gds.nbsom-1].ptsom  = ajuste (&(gds.ptsucc[gds.nbsom-1]));
    break;
  case 5 : 
		   /* Ajout de la procedure principal */
    numid_v_som (numprog);
    gds.ptsucc[gds.nbsom].ptsom = alloueptsom(nmax);
    gds.nbsom++;
    break;
  case 6 :
    gma = ds_vers_ma (&gds);

    libere (&gds);
    
    imprime_com(gma);

    break;


  default : printf("point non prevu\n");
  }
}

/* Jeu d'essais
leffe[59] tp6
*nom du source sans suffixe: 
prog
*production de prog.lst?(o/n)
n



procedure  pa 
procedure appelees :  pa 
procedure appelantes :  pa  pb  pd 


procedure  pb 
procedure appelees :  pa 
procedure appelantes :  essai 


procedure  pc 
procedure appelees : 
procedure appelantes :  pd 


procedure  pd 
procedure appelees :  pa  pc  pd 
procedure appelantes :  pd  essai 


programme principal :  essai 
procedure appelees :  pb  pd
leffe[60] 
*/
