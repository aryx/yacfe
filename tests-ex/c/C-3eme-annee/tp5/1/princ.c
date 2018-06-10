/* % Gestion de configuration
 * Creation : 28 avril 95                    TP no 5-1
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification
 *
 */

/*
 * %Module
 *   Nom            : princ
 *   Nom du fichier : princ.c
 *   Role du module : Tests des acces et constructeurs liste de liste.c                                    *   Fonctions de ce module :
 *               main : 
 */ 

/* 
 * %Fichiers include de l'application
 */
#include "liste.h"
#include "service.h"

/*   Fonctions externes appelees dans ce module :
 * 	creer_l: lecture d'une liste avec message d'invite
 *		prototype : Liste creer_l(void)	
 *	ecrire_l : ecriture d'une liste avec message au debut
 *		prototype : void ecrire_l(Liste l)
 *	append :  concatene deux listes
 *		prototype : Liste append (Liste l1,Liste l2)
 *      oter   : ote un element d'une liste
 *		prototype : Liste oter (Liste l,Element e)
 *
 *		 		  	
 */
 
/*
 * %Fonction globale
 * Nom : main
 * Definition :  
 * Argument :  void   
 * Resultat :  void     
 * Fonctions appelantes : 
 * Fonctions appelées :	creer_l,ecrire_l(tp5_1/service.c),
 *			append,oter(tp5_1/service.c)		
 * Erreur detectee :  
 * Commentaires : Tests des acces et constructeurs liste 
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
main()
{  Liste l1,l2,l3,l4; 			/* listes manipulees */
   int entlu;				/* entier lu */
   l1 = creer_l();
   l2 = creer_l();

   l3 = append(l1,l2);

   l4 = l3;

   printf("Donner le nombre a supprimer \n");
   scanf("%d",&entlu);
   l3 = oter(l3,entlu);

   ecrire_l(l2);
   ecrire_l(l3);
   ecrire_l(l4);
 }/* Fin du main*/
