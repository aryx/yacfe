/* % Gestion de configuration
 * Creation : 27 avril 95
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification
 *
 */
/*
 * %Module
 *   Nom            : liste
 *   Nom du fichier : liste.c
 *   Role du module : definir des acces listes
 *         	      la simple est une liste a simple chainage           
 *		      et element fictif en tete
 * 		      un triplet(tete,ec,predec) permet de gerer la liste
 *   Fonctions de ce module :
 * locales :
 * globales :
 *	initliste : initialise tete,ec,predec et l'element fictif
 * 	 	prototype :void initliste(Liste  *l)
 *	
 *	horsliste  : rend vrai si hors liste 	
 * 		prototype :Bool horsliste(Liste *l)

 *	entete : positionne l'element courant en tete de liste
 * 	 	prototype :void entete(Liste  *l)
 *
 *	suc	   : positionne l'element courant sur le suivant	
 *		prototype :void suc (Liste *l)
 *		
 *	listevide  : rend vrai si la liste est vide 	
 * 		prototype :Bool listevide(Liste *l)
 *
 *	ajoutd	   : ajoute l'element e apres l'element t
 *		prototype : void ajoutd(Liste *l, Elem Element v)
 *
 *	supprime   : supprime l'element courant
 *		     libere l'emplacement correspondant
 *		prototype : void supprime(Liste *l)
 *
 *	valcour	   : delivre la valeur de l'element courant
 *		prototype : Element valcour(Liste *l)
 */
  
/* 
 * %Fichiers include systeme
 */
#include "stddef.h"
#include "stdlib.h"

/* 
 * %Fichiers include de l'application
 */
#include "liste.h"
/*
 * %Fonction locale
 * Nom : Die
 * Definition : Gestion d'une erreur
 * Argument : char *err   
 * Resultat : void      
 * Fonctions appelantes : initlist
 * Fonctions appelées : printf 
 * Auteur/Origine        : M.J. Pedrono
 * Modifications      
 * Erreur detectee : 
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
void Die (char *err){
  printf (err);
  exit (0);
}



/*
 * %Fonction globale
 * Nom : initliste 
 * Definition : initialise tete,ec,predec et l'element fictif
 * Argument : Liste *l    
 * Resultat : void      
 * Fonctions appelantes : creer_l,append (tp5_2/service.c)
 * Fonctions appelées : malloc Die
 * Auteur/Origine        : M.J. Pedrono
 * Modifications      
 * Erreur detectee : mauvais resultat de malloc 
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

void initliste(Liste *l)
{
  if (l->tete =(Cellule *)malloc(sizeof(Cellule))) {
    l->tete->succ = NULL;
    l->ec = l->tete->succ;
    l->predec = l->tete;
  } else {
    Die ("\nProbleme malloc- initliste\n");
  }
} /* Fin INITLISTE */

/*
 * %Fonction globale
 * Nom : horsliste 
 * Definition : rend vrai si hors liste  
 * Argument : Liste *l    
 * Resultat : Bool      
 * Fonctions appelantes : ecrire_l,append,oter (tp5_2/service.c)
 *			  supprime,valcour suc
 * Fonctions appelées : 
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Bool horsliste(Liste *l)
{
  return (l->ec == NULL);
} /* Fin HORSLISTE */


/*
 * %Fonction globale
 * Nom : entete 
 * Definition : positionne l'element courant en tete de liste
 * Argument : Liste *l    
 * Resultat : void      
 * Fonctions appelantes : ecrire_l,append,oter (tp5_2/service.c)
 * Fonctions appelées :  
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

void entete(Liste  *l)
{
  l->ec = (l->tete)->succ;
  l->predec = l->tete ;
} /* Fin ENTETE */


/*
 * %Fonction globale
 * Nom : suc 
 * Definition :  positionne l'element courant sur le suivant 
 * Argument : Liste  *l     
 * Resultat : void     
 * Fonctions appelantes : ecrire_l,append,oter (tp5_2/service.c)
 * Fonctions appelées : horsliste(tp5_2/liste .c) 
 * Erreur detectee :  hors liste 
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

void suc (Liste *l)
{
  if (!horsliste (l)) {
    l->predec = l->ec;
    l->ec = l->ec->succ;
  } else {
    Die ("\nHorliste - suc\n");
  }
} /* Fin SUC */

/*
 * %Fonction globale
 * Nom :  listevide
 * Definition : rend vrai si la liste est vide 
 * Argument : Liste *l    
 * Resultat : Bool       
 * Fonctions appelantes : ajoutd (tp5_2/liste.c)
 * Fonctions appelées :  
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Bool listevide(Liste *l)
{
  if (l->tete->succ == NULL) {
    return vrai;
  }else {
    return faux;
  }
} /* Fin LISTEVIDE */


/*
 * %Fonction globale
 * Nom : ajoutd 
 * Definition : ajoute l'element v apres l'element courant
 * Argument : Liste *l,Element v    
 * Resultat : void     
 * Fonctions appelantes : main (tp5_2/princ.c)
 * Fonctions appelées : malloc - listevide(tp5_2/liste.c)  
 * Erreur detectee : mauvais resultat de malloc 
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

void ajoutd(Liste *l,Element v)
{
  Cellule *elemv;

  if (listevide (l)){
    if (elemv=(Cellule*)malloc(sizeof(Cellule))) {
      elemv->val = v;
      elemv->succ = NULL;
      l->predec = l->tete;
      l->ec = elemv;
      l->tete->succ = l->ec;
    } else {
      Die ("\nErreur d'allocation (malloc) - ajoutd\n");
    }
  } else {
    if (!horsliste (l)){
      if (elemv=(Cellule*)malloc(sizeof(Cellule))) {
	elemv->val = v;
	elemv->succ = l->ec->succ;
	l->ec->succ = elemv;
	l->predec = l->ec;
	l->ec = elemv;
      }else{
	Die ("\nErreur d'allocation (malloc) - ajoutd\n");
      }
    } else {
      Die ("\nHorsliste - ajoutd\n");
    }
  }
}/* Fin AJOUTD*/

/*
 * %Fonction globale
 * Nom : supprime 
 * Definition : supprime l'element courant
 *		libere l'emplacement correspondant
 * Argument :  Liste *l   
 * Resultat :  void     
 * Fonctions appelantes : main (tp5_2/princ.c)
 * Fonctions appelées : horsliste(tp5_2/liste.c) _ free 
 * Erreur detectee :horsliste  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

void supprime(Liste *l)
{
  Cellule* supp;

  if (!horsliste (l)){
    supp = l->ec;
    l->predec->succ = l->ec->succ;
    free (l->ec);
    l->ec = l->predec->succ;
  } else {
    Die ("\nHorsliste - supprime\n");
  }
}/* Fin SUPPRIME*/

/*
 * %Fonction globale
 * Nom : valcour 
 * Definition : delivre la valeur de l'element courant
 * Argument : Liste *l    
 * Resultat : Element     
 * Fonctions appelantes : main (tp5_2/princ.c)
 * Fonctions appelées : horsliste 
 * Erreur detectee : horsliste 
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
Element valcour(Liste *l)
{
  if (!horsliste (l)){
    return l->ec->val;
  } else {
    Die ("\nHorsliste - valcour\n");
  }
} /* Fin VALCOUR */
