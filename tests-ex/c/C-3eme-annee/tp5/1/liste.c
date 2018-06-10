/* % Gestion de configuration
 * Creation : 28 avril 95
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification
 *
 */
/*
 * %Module
 *   Nom            : liste
 *   Nom du fichier : liste.c
 *   Role du module : definir des acces listes et les constructeurs
 *         	      a la facon de Lisp ou Scheme (liste d'Element)
 * 		      le type Element etant a definir
 *   Fonctions de ce module :
 * locales :
 * globales :
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
 * 		prototype :Bool null(Liste l)  
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
 * %Fonction globale
 * Nom : car 
 * Definition : delivre le premier element d'une liste
 * Argument : Liste l    
 * Resultat : Element      
 * Fonctions appelantes : oter,append,ecrire_l(tp5_1/service.c)
 * Fonctions appelées :  
 * Erreur detectee : la liste est vide 
 * Commentaires :  
 * Creation              : 28 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Element  car(Liste  l)
{ 
  if (!null(l)) {
    return l->val;
  }
  return 0;
 } /* Fin CAR */

/*
 * %Fonction globale
 * Nom : cdr 
 * Definition :  delivre une liste amputee de son premier element
 * Argument : Liste l    
 * Resultat : Liste      
 * Fonctions appelantes :  oter,ecrire_l,append(tp5_1/service.c)
 * Fonctions appelées : 
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Liste cdr(Liste l)
{
  if (!null(l)) {
    return l->succ;
  }
  return listevide;
} /* Fin CDR */


/*
 * %Fonction globale
 * Nom : cons 
 * Definition : delivre une liste ou on a ajoute un element en tete de liste 
 * Argument : Element e,Liste l    
 * Resultat : Liste      
 * Fonctions appelantes : append,oter,lire_l(tp5_1/service.c) 
 * Fonctions appelées : malloc 
 * Erreur detectee : resultat incorrect pour malloc 
 * Commentaires :  
 * Creation              : 28 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Liste cons(Element e,Liste  l)
{ 
  Liste local;
  
  if ((local=malloc(sizeof(Cellule)))==NULL) {
    printf("erreur d allocation dans cons\n");
    return l;
  }
  local->val=e;
  local->succ=l;
  return local;
  
} /* Fin CONS */


/*
 * %Fonction globale
 * Nom :  null
 * Definition : rend vrai si la liste est vide 
 * Argument : Liste l    
 * Resultat : Bool       
 * Fonctions appelantes : car(liste.c),append,oter,ecrire_l(tp5_1/service.c) 
 * Fonctions appelées :  
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

Bool null(Liste l)
{ 
  return ((l==listevide)? vrai : faux);
} /* Fin NULL */


/* definition de la constante listevide */

const Liste listevide = NULL;


