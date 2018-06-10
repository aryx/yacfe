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
#include <stdlib.h>

/* 
 * %Fichiers include de l'application
 */
#include "chargf.h"


/*
 * %Fonction locale
 * Nom : InitListe
 *
 * Definition : Initialise une liste d'elements de fournisseurs
 *
 * Argument : 
 *     t_liste_f *L
 *
 *                   
 */
t_liste_f *InitListe (){
  t_liste_f* L;

  if ((L = (t_liste_f*) malloc (sizeof(t_liste_f))) == NULL) {
    printf ("***Erreur d'allocation memoire - InitListe.\n");
    exit (3);
  }

  L->tete = L->ec = L->predec = NULL;

  return L;
}  /* InitListe */

/*
 * %Fonction locale
 * Nom : Insere
 *
 * Definition : Insertion d'un element fournisseur dans une liste
 *
 * Argument : 
 *     t_liste_f *L, FOURNISSEUR f
 *
 *                   
 */
void Insere ( t_liste_f *L, FOURNISSEUR f, int r){
  t_elem_f *nv;
  Bool Introduit;

  if ((nv = (t_elem_f*) malloc (sizeof (t_elem_f))) == NULL) {
    printf ("***Erreur d'allocation - Insere.\n");
    exit (3);
  }
  nv->nf = f.nf;
  nv->rang = r;
  nv->succ = NULL;

  if (L->tete == NULL){
	/* C'est le premier element */
    L->tete = nv;
  } else {
    Introduit = FAUX;
    L->ec = L->tete;
    L->predec = NULL;

		/* Introduction de l'element dans la liste triee */
    while (!Introduit) {

      if (L->ec == NULL) {
		/* On est arrive au bout de la liste, on l'insere en fin de liste */
	Introduit = VRAI;
	L->predec->succ = nv;
      } else if (L->ec->nf > f.nf) {
		/* On l'insere ici */
	Introduit = VRAI;
	nv->succ = L->ec;
	if (L->ec == L->tete){
	  L->tete = nv;
	} else {
	  L->predec->succ = nv;
	}
      } else {
		/* On passe a l'element suivant */
	L->predec = L->ec;
	L->ec = L->ec->succ;
      } /* if pour le tri de la liste */
    }  /* While (!Introduit) */
  }
} /* Insere */

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
 *			     3 -> erreur d'allocation
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
int main (int argc, char *argv[]){
  FILE *fictxt, *ficbin, *ficbintmp;	/* Descripteurs des fichiers */
  char nomtmp[100];
  FOURNISSEUR four;
  t_liste_f *L;			/* Liste triee contenant les elements du fichier */
  int j, rang;			/* rang du n-uplet dans le fichier */
  ENTREE ent;
  size_t taille_entete_fic;

  if (argc != 3){
	/* Verification du nombre de parametres */
    printf ("\nUsage: %s <srce> <dest>.\n", argv[0]);
    printf ("\t<srce> est le nom du fichier texte contenant la relation FOURNISSEUR.\n");
    printf ("\t<dest> est le nom du fichier destine a recevoir cette relation dans le format binaire.\n");
    return (1);
  }

  if ((fictxt = fopen (argv [1], "r")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [1]);
    return (2);
  }

  if ((ficbin = fopen (argv [2], "w")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", argv [2]);
    return (2);
  }

  strcpy (nomtmp, argv[2]);
  strcat (nomtmp, "**tmp");

	/* Ouverture en Lecture/Ecriture */
  if ((ficbintmp = fopen (nomtmp, "w+")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier %s.\n", nomtmp);
    return (2);
  }

  L = InitListe();

  	/* Tant qu'on n'est pas en fin de fichier */
	/* On place dans un fichier temporaire les donnees en binaire */
  rang = 0; /* i cotient le rang du nuplet dans le fichier */
  while ( !feof(fictxt) ) {
	/* Lecture d'un n-uplet dans la table FOURNISSEUR */
    if(fscanf (fictxt, "%d %s %d %s", &(four.nf), &(four.nom), &(four.remise) ,&(four.ville)) != EOF){
	/* Insertion dans la liste triee du numero du fournisseur */
      Insere (L, four, rang);
	/* Insertion du n-uplet dans le fichier temporaire */
      fwrite (&four, sizeof(FOURNISSEUR), 1, ficbintmp);
      rang++;
    }
  }

	/* On calcule la taille de l'entete du fichier comprenant:
		- le nombre d'elements;
		- la liste des entrees. */
  taille_entete_fic = sizeof (rang) + sizeof(ENTREE)*rang;
	/* On ecrit le nombre d'elements que contient le fichier */
  fwrite (&rang, sizeof(rang), 1, ficbin);
	/* Il faut fabriquer l'index */
	/* Pour chaque element contenu dans le fichier, on ajoute son entete ENTREE */
  L->ec = L->tete;
  while (L->ec != NULL) {
    ent.nf = L->ec->nf;
    ent.adoctet = taille_entete_fic + (L->ec->rang)*sizeof(FOURNISSEUR);
    fwrite (&ent, sizeof(ent), 1, ficbin);
    L->ec = L->ec->succ;
  }

	/* Copie des donnees */
	/* On positionne le curseur en debut de fichier */
  fseek (ficbintmp, 0, SEEK_SET);

  for (j=0; j<rang; j++){
	/* Lecture dans le fichier temporaire */
    if (fread (&four, sizeof(FOURNISSEUR), 1, ficbintmp) != 0){
	/* Ecriture de la donnee dans le fichier destination */
      if (!(fwrite (&four, sizeof(FOURNISSEUR), 1, ficbin) < sizeof(FOURNISSEUR))){
	printf ("&&&Erreur dans le recopiage de l'element %d vers relf\n", j);
      }
    }
  }

	/* On efface le fichier temporaire */
  if (remove (nomtmp)) {
    printf ("***Erreur: impossible d'effacer le fichier %s.\n", nomtmp);
    exit (4);
  }

  fclose (ficbintmp);
  fclose (ficbin);
  fclose (fictxt);

  return (0);	/* Tout s'est bien deroule */
} /* main -> chargf */

/*
  Structure du fichier de sortie:
  int : entier donnant le nombre d'elements
  t_elem_index : les couples des index (nf, @)
  donnees binaires
*/
