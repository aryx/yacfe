/*
 * %Module
 *   Nom            : chargmf
 *   Nom du fichier : chargmf.c
 *   Auteurs: Sebastien Gringoire
 *	      Yoann Padioleau
 *   Role du module : A partir d'un fichier de donnees texte, construit un
 *	fichier de donnees binaire
 *
 */

/* 
 * %Fichiers include systeme
 */
#include <stdio.h>


/* 
 * %Fichiers include de l'application
 */
#include "schema.h"


/*
 * %Fonction principale
 * Nom : main
 *
 * Definition : Construit un fichier donnees + index
 *
 * Argument : 
 *     int argc, char *argv[]
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires : en retour: 1 -> erreur d'utilisation de la commande
 *			     2 -> erreur d'ouverture du fichier
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
int main (int argc, char *argv[]){
  FILE *fictxt, *ficbin;	/* Descripteurs des fichiers */
  MAFOURNITURE mf;		/* Contient un n-uplet lu */

  if (argc != 3){
	/* Verification du nombre de parametres */
    printf ("\nUsage: %s <srce> <dest>.\n", argv[0]);
    printf ("\t<srce> est le nom du fichier texte contenet la relation MAFOURNITURE.\n");
    printf ("\t<dest> est le nom du fichier destine a recevoir cette relation dans le format binaire.\n");
    return (1);
  }

  if ((fictxt = fopen (argv [1], "r")) == NULL){
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [1]);
    return (2);
  }
  if ((ficbin = fopen (argv [2], "w")) == NULL){
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [2]);
    return (2);
  }

	/* Tant qu'on n'est pas en fin de fichier */
  while ( !feof(fictxt) ) {
	/* Lecture d'un n-uplet dans la table MaFourniture */
    if(fscanf (fictxt, "%d %d %d", &(mf.nf), &(mf.np), &(mf.qte)) != EOF)
      fwrite (&mf, sizeof(MAFOURNITURE), 1, ficbin);
  }

  fclose (fictxt);
  fclose (ficbin);
  return (0);	/* Tout s'est bien deroule */
} /* main -> chargmf */
