/* % Gestion de configuration
 * Creation : 28 avril 95
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification
 *
 */
/*
 * %Module
 *   Nom            : service
 *   Nom du fichier : service.c
 *   Role du module : definir des fonctions de creation et affichage de listes
 *   Fonctions de ce module :
 * locales : 
 *
 * globales :
 *	creer_l: lecture d'une liste avec message d'invite
 *		prototype : void creer_l(Liste *l)	
 *	ecrire_l : ecriture d'une liste avec message au debut
 *		prototype : void ecrire_l(Liste *l)
 *	append :  concatene deux listes
 *		prototype : void append (Liste *l1,Liste *l2, Liste *l3)
 *      oter   : ote un element d'une liste
 *		prototype : void oter (Liste *l,Element e)
 *		 		  
 */
  
/* 
 * %Fichiers include systeme
 */


/* 
 * %Fichiers include de l'application
 */
#include "liste.h"
#include "service.h"

/*   Fonctions externes appelees dans ce module :
 *	initliste : initialise tete,ec,predec et l'element fictif
 * 	 	prototype :void initliste(Liste  *l)
 *	
 *	horsliste  : rend vrai si hors liste 	
 * 		prototype :Bool horsliste(Liste *l)
 *
 *	entete : positionne l'element courant en tete de liste
 * 	 	prototype :void entete(Liste  *l)
 *
 *	suc	   : positionne l'element courant sur le suivant	
 *		prototype :void suc (Liste *l)
 *		
 *	listevide  : rend vrai si la liste est vide 	
 * 		prototype :Bool listevide(Liste *l)
 *
 *	ajoutd	   : ajoute l'element e apres l'element courant
 *		prototype : void ajoutd(Liste *l,Element v)
 *
 *	supprime   : supprime l'element courant
 *		     libere l'emplacement correspondant
 *		prototype : void supprime(Liste *l)
 *
 *	valcour	   : delivre la valeur de l'element courant
 *		prototype : Element valcour(Liste *l)
 */
  	
/*
  * %Fonction globale
 * Nom : creer_l 
 * Definition : creation d'une liste par lecture
 * Argument : Liste *l   
 * Resultat :         
 * Fonctions appelantes : main (tp5_2/princ.c)
 * Fonctions appelées : printf,scanf - ajoutd,initliste(tp5_2/liste.c)
 * Erreur detectee : 
 * Commentaires :  
 * Creation              : 28 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
void creer_l(Liste *l)
{
  Bool fin=faux;
  Element vallu;

  initliste (l);
  printf("Donner une liste d'entiers terminee par -1\n");
  while (fin == faux){
    scanf("%d",&vallu);
    if (vallu==-1) {
      fin = vrai;
    } else {
      ajoutd (l, vallu);
    }
  }
} /* Fin CREER_L */

 	
/*
 * %Fonction globale
 * Nom : ecrire_l 
 * Definition : affichage d'une liste apres un message
 * Argument : Liste *l   
 * Resultat :  void       
 * Fonctions appelantes : main (tp5_2/princ.c)
 * Fonctions appelées : printf,scanf - entete,horsliste,valcour(tp5_2/liste.c)
 * Erreur detectee : 
 * Commentaires :  
 * Creation              : 28 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
void ecrire_l(Liste l)
{
  printf("Voici la liste d'entiers  : \n");
  entete (&l);
  while (!horsliste (&l)){
    printf (" %4d ", (int)valcour (&l));
    suc (&l);
  }
  printf ("\n");
} /* Fin ECRIRE_L */

/*
 * %Fonction globale
 * Nom : append 
 * Definition :  concatene deux listes 
 * Argument : Liste l1,Liste l2, Liste *l3
 * Resultat :     
 * Fonctions appelantes : main (tp5_2/princ.c)
 * Fonctions appelées :   initliste,entete,horsliste,ajoutd,valcour,
 * 			  suc(tp5_2/liste.c) 
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

void append (Liste l1,Liste l2, Liste *l3)
{  
  initliste (l3);

  entete (&l1);
  while (!horsliste(&l1)) {
    ajoutd (l3, valcour (&l1));
    suc (&l1);
  }

  entete (&l2);
  while (!horsliste (&l2)){
    ajoutd (l3, valcour (&l2));
    suc (&l2);
  }

} /* Fin APPEND*/

/*
 * %Fonction globale
 * Nom : oter 
 * Definition :  ote la premiere occurence de l'element e d'une liste l
 * Argument : Liste *l, Element e
 * Resultat :    
 * Fonctions appelantes : main (tp5_2/princ.c)
 * Fonctions appelées : horsliste,valcour,supprime(tp5_2/liste.c) 
 * Erreur detectee :   
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

void oter (Liste *l, Element e)
{
  entete (l);

  while (!horsliste(l)) {
    if (valcour(l) == e){
      supprime (l);
      return;
    } else{
      suc (l);
    }
  }
} /* Fin OTER */

