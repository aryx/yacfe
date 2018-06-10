/*
 * %Module
 *   Nom            : joindre
 *   Nom du fichier : joindre.c
 *   Auteurs: Sebastien Gringoire
 *	      Yoann Padioleau
 *   Role du module : Effectue la jointure de deux fichiers
 *
 */

/* 
 * %Fichiers include systeme
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
 * %Fichiers include de l'application
 */
#include "joindre.h"


/*
 * %Fonction locale
 * Nom : InitListeEntree
 *
 * Definition : Initialise une liste d'elements d'entree
 *
 * Argument : 
 *     t_liste_i *L
 *
 *                   
 */
t_liste_i *InitListeEntree (){
  t_liste_i* L;

  if ((L = (t_liste_i*) malloc (sizeof(t_liste_i))) == NULL) {
    printf ("***Erreur d'allocation memoire - InitListeEntree.\n");
    exit (3);
  }

  L->tete = L->ec = NULL;

  return L;
}  /* InitListeEntree */


/*
 * %Fonction locale
 * Nom : InsereEntree
 *
 * Definition : Insertion d'une entree d'index en fin de liste
 *
 * Argument : 
 *     t_liste_i *L, FOURNISSEUR f
 *
 *
 */
void InsereEntree (t_liste_i *L, ENTREE ent){
  t_elem_i *nv;

  if ((nv = (t_elem_i*) malloc (sizeof (t_elem_i))) == NULL) {
    printf ("***Erreur d'allocation - InsereEntree.\n");
    exit (3);
  }

  nv->ent = ent;
  nv->succ = NULL;

  if (L->tete == NULL){
	/* On insere le premier element */
    L->tete = nv;
  } else {
    L->ec->succ = nv;
  }
  L->ec = nv;

} /* InsereEntree */

/*
 * %Fonction locale
 * Nom : LectureIndex
 *
 * Definition : Lit l'index du fichier binaire de la relation FOURNISSEUR et le met
 *		dans la liste L
 *
 * Argument : 
 *     FILE *fic, t_liste_i *L
 *
 *                   
 */
void LectureIndex (FILE *fic, t_liste_i *L){
  int nbelem;	/* Nombre d'elements du fichier des fournisseurs */
  int i;
  ENTREE ent;

	/* On se place au debut du fichier */
  fseek (fic, 0, SEEK_SET);

	/* Lecture du nombre d'elements */
  fread (&nbelem, sizeof(nbelem), 1, fic);

  for (i=0; i<nbelem; i++){
	/* On lit l'entree */
    fread (&ent, sizeof(ent), 1, fic);
	/* On la place dans la liste */
    InsereEntree (L, ent);
  }

} /* LectureIndex */

/*
 * %Fonction locale
 * Nom : Aff
 *
 * Definition : Fait une jointure a partir de deux n-uplets
 *		Renvoi faux si le fournisseur n'est pas trouve
 *
 * Argument : 
 *    FILE *fic, int num, FOURNISSEUR *four, t_liste_i *L
 *
 *                   
 */
Bool ChercheFour (FILE *fic, int num, FOURNISSEUR *four, t_liste_i *L){
  Bool trouve;
  long dep;		/* offset de l'element */

  L->ec = L->tete;
  trouve = FAUX;

  while (!trouve && (L->ec != NULL)) {
    if (L->ec->ent.nf == num){
      dep = L->ec->ent.adoctet;
      trouve = VRAI;
		/* On se positionne au niveau de l'element */
      fseek (fic, dep, SEEK_SET);
		/* On le lit */
      fread (four, sizeof(FOURNISSEUR), 1, fic);
    } else {
      L->ec = L->ec->succ;
    }
  }

  return trouve;
} /* ChercheFour */


/*
 * %Fonction locale
 * Nom : Aff
 *
 * Definition : Fait une jointure a partir de deux n-uplets
 *
 * Argument : 
 *    FOURNISSEUR four, MAFOURNITURE mafo, JOINTURE *joint
 *
 *                   
 */
void Aff (FOURNISSEUR four, MAFOURNITURE mafo, JOINTURE *joint){
  joint->nf = four.nf;
  joint->np = mafo.np;
  joint->qte = mafo.qte;
  strcpy (joint->nom, four.nom);
  joint->remise = four.remise;
  strcpy (joint->ville, four.ville);
}	/* Aff */

/*
 * %Fonction principale
 * Nom : main
 *
 * Definition : Fait la jointure entre deux table: FOURNISSEUR et MAFOURNITURE
 *
 * Argument : 
 *     int argc, char *argv[]
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires : en retour: 1 -> erreur d'utilisation de la commande
 *			     2 -> erreur d'ouverture du fichier
 *			     3 -> erreur d'allocation
 *
 *                   
 */
int main (int argc, char *argv[]){
  FILE *ficfour, *ficmafo, *ficjoin;
  t_liste_i Liste;
  MAFOURNITURE mafo;
  JOINTURE joint;
  FOURNISSEUR four;


  if (argc != 4){
	/* Verification du nombre de parametres */
    printf ("\nUsage: %s <srcef> <srcemf> <dest>.\n", argv[0]);
    printf ("\t<srcef> est le nom du fichier binaire contenant la relation FOURNISSEUR.\n");
    printf ("\t<srcemf> est le nom du fichier binaire contenant la relation MAFOURNITURE.\n");
    printf ("\t<dest> est le nom du fichier destine a recevoir la jointure entre ces deux relations dans le format binaire.\n");
    return (1);
  }

  if ((ficfour = fopen (argv [1], "r")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [1]);
    return (2);
  }

  if ((ficmafo = fopen (argv [2], "r")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [2]);
    return (2);
  }

  if ((ficjoin = fopen (argv [3], "w")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [3]);
    return (2);
  }

  InitListeEntree (&Liste);

  LectureIndex (ficfour, &Liste);

	/* On se positionne en debut de fichier */
  fseek (ficmafo, 0, SEEK_SET);
  fseek (ficfour, 0, SEEK_SET);

	/* Ecriture des jointure dans le fichier */
  while (!feof(ficmafo)){
    if (fread (&mafo, sizeof(mafo), 1, ficmafo) != 0){
      if (!ChercheFour (ficfour, mafo.nf, &four, &Liste)) {
	printf ("***Le fournisseur de code %d n'est pas present dans la table.\n", mafo.nf);
      } else {
	Aff (four, mafo, &joint);
	fwrite (&joint, sizeof(joint), 1, ficjoin);
      }
    }
  }	/* while */

  fclose (ficmafo);
  fclose (ficfour);
  fclose (ficjoin);

  return (0);
} /* main -> joindre */
