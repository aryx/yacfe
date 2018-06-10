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
 *	lirec : lecture d'une liste
 *		prototype : Liste lirec(void)	
 *	ecrirec : ecriture d'une liste
 *		prototype : void ecrirec(Liste l)	
 * globales :
 *	creer_l: lecture d'une liste avec message d'invite
 *		prototype : Liste creer_l(void)	
 *	ecrire_l : ecriture d'une liste avec message au debut
 *		prototype : void ecrire_l(Liste l)
 *	append :  concatene deux listes
 *		prototype : Liste append (Liste l1,Liste l2)
 *      oter   : ote un element d'une liste
 *		prototype : Liste oter (Liste l,Element e)
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
 *	car : delivre le premier element d'une liste
 * 	 	prototype :Element  car(Liste  l)
 *	
 *	cdr  : delivre une liste amputee de son premier element 	
 * 		prototype :Liste cdr(Liste l)
 *
 *	cons : delivre une liste ou on a ajoute un element en tete de liste
 * 	 	prototype :Liste cons(Element e,Liste  l)
  *		
 *	null  : rend vrai si la liste est vide 	
 * 		prototype : Bool null(Liste l)
 *
 */

 /*
  * %Fonction locale 
 * Nom : lirec 
 * Definition : creation d'une liste par lecture
 * Argument : void   
 * Resultat :  Liste l       
 * Fonctions appelantes : creer_l 
 * Fonctions appelées : scanf,cons - lirec (recursive)
 * Erreur detectee : 
 * Commentaires :  
 * Creation              : 28 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

 static Liste lirec(void)
{
  Element vallu;
  scanf("%d",&vallu);
  if (vallu==-1) return listevide;
  return cons(vallu,lirec());
   
} /* Fin LIREC */

 	
/*
  * %Fonction globale
 * Nom : creer_l 
 * Definition : creation d'une liste par lecture
 * Argument : void   
 * Resultat :  Liste l       
 * Fonctions appelantes : main (tp5_1/princ.c)
 * Fonctions appelées : printf,scanf
 * Erreur detectee : 
 * Commentaires :  
 * Creation              : 28 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
Liste creer_l(void)
{
  printf("Donner une liste d'entiers terminee par -1\n");
  return lirec();
} /* Fin CREER_L */

 /*
  * %Fonction locale 
 * Nom : ecrirec 
 * Definition : affichage d'une liste 
 * Argument : Liste l  
 * Resultat :  void       
 * Fonctions appelantes : ecrire_l ,ecrirec
 * Fonctions appelées : printf,cdr,car(tp5_1/liste.c) _ ecrirec(recursive)
 * Erreur detectee : 
 * Commentaires :  
 * Creation              : 28 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

 static void ecrirec(Liste l) 
{
  if (!null(l)) {
    printf("%d ",car(l));
    ecrirec(cdr(l));
  }
} /* Fin ECRIREC */

 	
/*
  * %Fonction globale
 * Nom : ecrire_l 
 * Definition : affichage d'une liste apres un message
 * Argument : Liste l   
 * Resultat :  void       
 * Fonctions appelantes : main (tp5_1/princ.c)
 * Fonctions appelées : printf,scanf
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
  ecrirec(l);
  printf("\n");
}

/*
 * %Fonction locale
 * Nom : copie
 * Definition :  copie d une liste
 * Argument : Liste l
 * Resultat : Liste    
 * Fonctions appelantes : on s en sert pas en fait
 * Fonctions appelées : null,car,cdr,copie (recursive)
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
Liste copie(Liste l)
{
  if (null(l)) return listevide;
  return (cons(car(l),copie(cdr(l))));
}



/*
 * %Fonction globale
 * Nom : append 
 * Definition :  concatene deux listes 
 * Argument : Liste l1,Liste l2
 * Resultat : Liste    
 * Fonctions appelantes : main (tp5_1/princ.c)
 * Fonctions appelées : null,car,cdr,cons(liste .c) et append(recursive)
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Liste append (Liste l1,Liste l2)
{
  /* on est pas oblige de copier l2 car le chainage de l2 ne sera pas modifie
     et donc ca n aura pas de repercusion sur la liste appendee */
  if(null(l1)) return l2; 
  return cons(car(l1),append(cdr(l1),l2));
  
  
} /* Fin APPEND*/

/*
 * %Fonction globale
 * Nom : oter 
 * Definition :  ote la premiere occurence d'un element d'une liste 
 * Argument : Liste l, Element e
 * Resultat : Liste    
 * Fonctions appelantes : main (tp5_1/princ.c)
 * Fonctions appelées : null,car,cdr,cons(tp5_1/liste .c) et oter(recursive)
 * Erreur detectee :   
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Liste oter (Liste l, Element e)
{
  if(null(l)) return listevide;

  if (e==l->val) return cdr(l);
  return cons(car(l),oter(cdr(l),e));
} /* Fin OTER */







