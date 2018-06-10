/*
 * %Module
 *   Nom            : chargf
 *   Nom du fichier : chargf.c
 *   Auteurs: Sebastien Gringoire
 *	      Yoann Padioleau
 *   Role du module : A partir d'un fichier de donnees, construit un
 *	fichier de donnees avec un index
 *
 */

/* 
 * %Fichiers include systeme
 */
#include <stdio.h>
#include <string.h>

/* 
 * %Fichiers include de l'application
 */
#include "schema.h"

/*
 * %Fonction locale
 * Nom : AfficheEntete
 *
 * Definition : Affiche l'entete pour le formatage
 *
 * Argument : 
 *     
 *
 * Variables globales utilisees :
 *
 *                   
 */
void AfficheEntete (void){
	/* Format: 6 | 6 | 6| 12 | 6 | 12 */
  printf ("\t  nf  |  np  | qte  |   nom      |remise|  ville\n");
} /* AfficheEntete */


/*
 * %Fonction locale
 * Nom : AfficheJoint
 *
 * Definition : Affiche un n-uplet JOINTURE
 *
 * Argument : 
 *     JOINTURE j
 *
 * Variables globales utilisees :
 *
 *                   
 */
void AfficheJoint (JOINTURE j){
  printf ("\t%3d   |%3d   |%3d   |%12s|%3d   |%12s\n", j.nf, j.np, j.qte, j.nom, j.remise, j.ville);

} /* AfficheJoint */

/*
 * %Fonction principale
 * Nom : main
 *
 * Definition : Lecture du fichier contenant la jointure des deux tables
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
 *                   
 */
int main (int argc, char *argv[]){
  FILE *fic;
  JOINTURE joint;

  if (argc != 2){
	/* Verification du nombre de parametres */
    printf ("\nUsage: %s <ficjoint>.\n", argv[0]);
    printf ("\t<ficjoint> est le nom du fichier binaire contenant la jointure entre ces deux relations dans le format binaire.\n");
    return (1);
  }

  if ((fic = fopen (argv [1], "r")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [1]);
    return (2);
  }

  AfficheEntete();
  while (!feof (fic)){
    if (fread (&joint, sizeof(joint), 1, fic) != 0)
      AfficheJoint (joint);
  } /* while */

  fclose (fic);

  return (0);
} /* main -> voirjoint */
