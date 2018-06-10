/* % Gestion de configuration
 * Creation : 28 avril 95                    TP no 5-2
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification
 *
 */

/*
 * %Module
 *   Nom            : princ
 *   Nom du fichier : princ.c
 *   Role du module : Tests des acces et constructeurs liste de liste.c                                *   Fonctions de ce module :
 *               main : 
 */ 

/* 
 * %Fichiers include de l'application
 */
#include "liste.h"
#include "service.h"

/*   Fonctions externes appelees dans ce module :
 * 	creer_l: lecture d'une liste avec message d'invite
 *		prototype : void creer_l(Liste *l)	
 *	ecrire_l : ecriture d'une liste avec message au debut
 *		prototype : void ecrire_l(Liste l)
 *	append :  concatene deux listes
 *		prototype : void append (Liste l1,Liste l2, Liste *l3)
 *      oter   : ote un element d'une liste
 *		prototype : void oter (Liste *l,Element e)
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
 * Fonctions appelées :	creer_l,ecrire_l,oter,append(tp5_2/service.c)	
 * Erreur detectee :  
 * Commentaires : Tests des acces et constructeurs liste 
 * Creation              : 27 avril 95
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
main()
{  
   Liste l1,l2,l3,l4; 			/* listes manipulees */
   int entlu;				/* entier lu */
   creer_l(&l1);
   creer_l(&l2);

   append(l1,l2,&l3);

   l4 = l3;

   printf("Donner le nombre a supprimer \n");
   scanf("%d",&entlu);
   oter(&l3,entlu);

   ecrire_l(l2);
   ecrire_l(l3);
   ecrire_l(l4);
 }/* Fin du main*/
/*
vichy[75] princ
Donner une liste d'entiers terminee par -1
1
2
3
-1
Donner une liste d'entiers terminee par -1
4
5
6
-1
Donner le nombre a supprimer 
4
Voici la liste d'entiers  : 
    4     5     6 
Voici la liste d'entiers  : 
    1     2     3     5     6 
Voici la liste d'entiers  : 
    1     2     3     5     6 
vichy[76] 
*/
