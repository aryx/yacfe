/* % Gestion de configuration
 * Creation : 26 mars 98
 * Auteur : M.J. Pedrono
 * Modifications : 
 * Derniere modification
 *
 */

/*
 * %Module
 *   Nom            : princ
 *   Nom du fichier : princ.c
 *   Role du module : Initialiser un tableau et le trier                     
 *   Fonctions de ce module :
 *               main : 
 */ 
 
/* 
 * %Fichiers include systeme
 */
#include <stdio.h>
#include <math.h>
/* 
 * %Fichiers include de l'application
 */

#include "service.h" 
#include "tritas.h"
#include "trirapide.h"
#include "trinaif.h"


/* 
 * % Prototype des fonctions externes appelees dans ce module
 *		void ecrire(int t[], int longueur)
 *		     affiche le tableau d'entiers t[1..longueur]
 *		void lire(int t[], int longueur)
 *		     lit le tableau d'entiers t[1..longueur]
 *		void tri_tas(int t[], int longueur)
 *		     trie le tableau d'entiers t[1..longueur]		
 * 		     en suivant l'algoritme du tri en tas
 *		void tri_rap(int t[], int longueur)
 *		     trie le tableau d'entiers t[1..longueur]		
 * 		     en suivant l'algoritme du tri rapide
 *		void tri_naif(int t[], int longueur)
 *		     trie le tableau d'entiers t[1..longueur]		
 * 		     en suivant l'algoritme du tri naif
 *
 */

/*
 * %Fonction 
 * Nom :main
 * Definition : comparaison de methodes de tri d'un tableau 
 * Argument :       
 * Resultat : int      
 * Variables globales utilisees : néant
 * Fonctions appelees : lire(service.c), ecrire(service.c)
 *			tri_tas(tritas.c),tri_rap(trirap.c),
 *			tri_naif(trinaif.c) 
 * Fonctions appelantes : 
 * Erreur detectee :  
 * Commentaires :  
 * Creation              : 26 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :
 *		     
 */

/*---------------------------------------------------------------
 *
 *
 *  ce module permet de tester chaque procedure de tri 
 *  avant les calculs de complexite ou seuls les temps de calculs
 *  nous interessent => il faut donc modifier ce module par la suite
 *
 *------------------------------------------------------------------
 */

const int LONGUEUR = 524288;	/* nombre d'elements du tableau*/


void main(void)
{
  int tab[LONGUEUR+1] ;
  int tabtmp[LONGUEUR+1];
  int i,j;
  int longueur;

  long tps1, tps2;

		/* tableau tab[1..longueur] : l'element 0 (-1) est inutilise*/
		/* ce choix est dicte par l'algorithme de tri en tas */
  for (j=10; j<=19;j++){
    longueur = pow (2, j);
    printf (" \n Tes: longueur= %d.\n", longueur);

	remplitab (tab,longueur);
	for (i=1;i<=longueur;i++){
	  tabtmp[i] = tab[i];
	}
	/* printf ("\nTableau d'origine:\n");
	ecrire (tabtmp, longueur); */

        printf("tri en tas:\n");
	tps1 = clock ();
	tri_tas(tabtmp,longueur);
	tps2 = clock ();
	printf ("Temps d'execution: %d ms.\n", tps2-tps1);
	printf ("Constante n = %f\n", (tps2-tps1)/(longueur*log(longueur)/log(2)));

	/*       	ecrire(tabtmp,longueur);*/

	for (i=1;i<=longueur;i++){
	  tabtmp[i] = tab[i];
	}
        printf("tri rapide:\n");
	tps1 = clock();
	tri_rap(tabtmp,longueur);
	tps2 = clock ();
	printf ("Temps d'execution: %d ms.\n", tps2-tps1);
	printf ("Constante n = %f\n", (tps2-tps1)/(longueur*log(longueur)/log(2)));
	/*       	ecrire(tabtmp,longueur); */

	/*	for (i=1;i<=longueur;i++){
	  tabtmp[i] = tab[i];
	}
        printf("tri naif:\n");
	tps1 = clock();
	tri_naif(tabtmp,longueur);
	tps2 = clock ();
	printf ("Temps d'execution: %d ms.\n", tps2-tps1); 
	ecrire(tabtmp,longueur);*/

  } /*for */
}/*main*/



Longueur        Tri en tas         Constante    Tri rapide       Constante
1024            30000 ms           2.929688     10000 ms         0.976562
2048            80000 ms           3.551136     20000 ms         0.887784
4096            170000 ms          3.458659     40000 ms         0.813802
8192            390000 ms          3.662109     70000 ms         0.657302
16384           890000 ms          3.880092     160000 ms        0.697545
32768           1990000 ms         4.048665     340000 ms        0.691732
65536           4380000 ms         4.177094     680000 ms        0.648499
131072          9560000 ms         4.399618     1480000 ms       0.664206
262144          20760000 ms        4.399618     3020000 ms       0.640021
524288          44870000 ms        4.504354     6260000 ms       0.628421
