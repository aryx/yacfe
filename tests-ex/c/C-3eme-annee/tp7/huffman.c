

/*
 * %Module
 *   Nom            : huffman
 *   Nom du fichier : huffman.c
 *   Auteurs: Sebastien Gringoire
 *	      Yoann Padioleau
 *   Role du module : Application a l'algorithme de Huffman
 *
 * prototype des fonctions definies dans le module
 * globales :
 *
 *	ExtraireMin : Retire le noeud de frequence minimal d'une file
 *		prototype : t_noeudfeuille (t_file* F)
 * locales :
 *	AllouerNoeud : Alloue un noeud de type t_noeudfeuille		
 *		prototype : void affiche( int nosom)
 *
 *	Inserer: Insere un noeud dans la file 
 *		      s'il y est deja
 *		      sinon range le numid dans la table tabnumid
 *		prototype : int numid_v_som (int numid) 
 *
 */

/* 
 * %Fichiers include systeme
 */
#include <malloc.h>
#include <stdlib.h>
#include <stddef.h>


/* 
 * %Fichiers include de l'application
 */
#include "huffman.h"

/* 
 * % Prototype des fonctions externes appelées dans ce module
 *
	void *malloc(size_t size);
	void free(void *ptr);
	printf format [ argument...  ]
 */




/*
 * %Fonction globale
 * Nom : SupprimeFile
 *
 * Definition : Supprime l'element pointe par ptr de la file F
 *
 * Argument : 
 *      t_file* F, t_elemfile* ptr
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
void SupprimeFile (t_file* F, t_elemfile* ptr){
  Bool trouve;
  t_elemfile* predec;

  trouve = FAUX;

	/* On regarde si c'est le premier */
  if (ptr == F->tete){
    trouve = VRAI;
	/* Changement du chainage dans la file */
    F->tete = F->tete->succ;
	/* Liberation de l'espace memoire */
    free (ptr);
  }

  predec = F->tete;
  while (!trouve && (predec != NULL)){
    if (predec->succ == ptr) {
      trouve = VRAI;
      predec->succ = ptr->succ;
      free (ptr);
    } else {
      predec = predec->succ;
    }
  }
} /* SupprimeFile */

/*
 * %Fonction locale
 * Nom : ExtraireMin
 *
 * Definition :
 *
 * Argument : 
 *      t_file F
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
t_noeudfeuille* ExtraireMin (t_file* F){
  t_noeudfeuille* ptrmin;
  t_elemfile* ptrelem;
  int pdmin, poids;

	/* On part du premier element de la file */
  if (F->tete == NULL){
	/* On renvoit NULL si la file est vide */
    ptrmin = (t_noeudfeuille*) NULL;
  } else {
    ptrmin = F->tete->val;
    ptrelem = F->tete;

    F->ec = F->tete->succ;

    if (ptrmin->type == FEUILLE){
      pdmin = ptrmin->un.feuille.freq;
    } else {
      pdmin = ptrmin->un.noeud.spoids;
    }

	/* Tant qu'il reste des elements */
    while (F->ec != NULL){
	/* On sauvegarde le poids */
      if (F->ec->val->type == FEUILLE){
	poids = F->ec->val->un.feuille.freq;
      } else {
	poids = F->ec->val->un.noeud.spoids;
      }

      if (pdmin > poids) {
	/* On a trouve un nouveau element */
	ptrmin = F->ec->val;
	ptrelem = F->ec;
	pdmin = poids;
      }
      F->ec = F->ec->succ;
    }
    SupprimeFile (F, ptrelem);
  }
  return ptrmin;
} /* ExtraireMin */


/*
 * %Fonction locale
 * Nom : affichefile
 *
 * Definition : affiche la file de priorite
 *
 * Argument : 
 *      t_file F
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
void affichefile ( t_file *F){
  t_feuille f;
  t_noeud n;

  printf ("\n\tAffichage de la file de priorite:");

  F->ec = F->tete;

  printf ("\n");
  while (F->ec != NULL) {
    if (F->ec->val->type == FEUILLE) {
      f =  F->ec->val->un.feuille;
      printf ("(%c, %d)\n", f.car, f.freq);
    } else {
      n = F->ec->val->un.noeud;
      printf ("(%d)\n", n.spoids);
    }
    F->ec = F->ec->succ;
  }

} /* affichefile */


/*
 * %Fonction locale
 * Nom : TransAF
 *
 * Definition :  Transforme un alphabet en file
 *
 * Argument : 
 *      t_alphabet C
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
t_file* TransAF (t_alphabet C){
  t_file *F;
  int i;
  t_elemfile *ptr;

  if ((F = (t_file*) malloc (sizeof(t_file))) == NULL){
    printf ("\nErreur d'allocation - TransAF\n");
    exit (1);
  }
  F->tete = NULL;
  F->ec = NULL;

  		/* pour chaque lettre de l'alphabet */
  for (i=0; i<C.nb; i++){
    if ((ptr = (t_elemfile*) malloc (sizeof(t_elemfile))) == NULL){
      printf ("\nErreur d'allocation (ptr) - Huffman\n");
      exit (1);
    }
    
    ptr->succ = F->tete;
    if ((ptr->val = (t_noeudfeuille*)malloc(sizeof(t_noeudfeuille))) == NULL) {
      printf ("\nErreur d'allocation (ptr->val) - Huffman\n");
      exit (1);
    }
    ptr->val->type = FEUILLE;
    ptr->val->un.feuille = C.alph[i];

    F->tete = ptr;
  }
  return F;
} /* TransAF */

/*
 * %Fonction locale
 * Nom : Poids
 *
 * Definition : Renvoi le poids d'un noeud
 *
 * Argument : 
 *      t_noeudfeuille x
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
int Poids (t_noeudfeuille x){
  if (x.type == FEUILLE) {
    return (x.un.feuille.freq);
  } else {
    return (x.un.noeud.spoids);
  }
}


/*
 * %Fonction locale
 * Nom : AllouerNoeud
 *
 * Definition :Allocation d'un noeud de l'arbre de Huffman
 *		Renvoi le pointeur sur ce noeud
 *
 * Argument : 
 *     neant
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
t_noeudfeuille* AllouerNoeud(void){
  t_noeudfeuille* ptr;

  if ((ptr = (t_noeudfeuille*)malloc(sizeof(t_noeudfeuille))) == NULL){
    printf ("\nErreur: Allocation impossible - AllouerNoeud\n");
    exit (1);
  } else {
    return ptr;
  }
} /* AllouerNoeud */

/*
 * %Fonction locale
 * Nom : Inserer
 *
 * Definition : Insertion d'un noeud, ou d'un arbre dans la file F
 *
 * Argument : t_file F, t_noeudfeuille* x
 *
 *     neant
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
void Inserer (t_file* F, t_noeudfeuille* x){
  t_elemfile* elem;

  if ((elem= (t_elemfile*)malloc(sizeof(t_elemfile))) == NULL){
    printf ("\nErreur: allocation impossible - Inserer\n");
    exit(1);
  }
  elem->val = x;
  elem->succ = F->tete;
  F->tete = elem;
} /* Inserer */

/*
 * %Fonction globale
 * Nom : Huffman
 *
 * Definition : algo de Huffman
 *
 * Argument : 
 *      t_file F
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
t_noeudfeuille* Huffman (t_alphabet C){
  int n, i;
  t_file *F;
  t_noeudfeuille *z, *x, *y;
  
		/* n contient le nombre de lettres dans l'alphabet */
  n = C.nb;
  F = TransAF (C);
  affichefile(F);

  for (i=1; i <= n-1; i++){
    z = AllouerNoeud();
    z->type = NOEUD;

    x = ExtraireMin (F);
    z->un.noeud.filsg = x;

    y = ExtraireMin (F);
    z->un.noeud.filsd = y;

    z->un.noeud.spoids = Poids (*x) + Poids (*y);

    Inserer (F, z);
    affichefile (F);
  }

  return ExtraireMin (F);
}	/* Huffman() */

/*
 * %Fonction globale
 * Nom : AfficheHuffman
 *
 * Definition : affiche l'arbre de Huffman
 *
 * Argument : 
 *      t_noeudfeuille A, int prof
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
void AfficheHuffman (t_noeudfeuille A, int prof){
  /* prof indique la profondeur dans l'arbre */
  char espace[2];

  strcpy(espace, " ");
	/* Parcours PostFixe */

  if (A.type == FEUILLE){
	/* Affichage de la feuille */
    printf ("\n%*s%c:%2d ", prof*5, espace, A.un.feuille.car, A.un.feuille.freq);
  } else if (A.type == NOEUD) {
    if (A.un.noeud.filsd != NULL){
	/* Parcours du sous-arbre droit */
      AfficheHuffman (*A.un.noeud.filsd, prof+1);
    } else {
      printf ("\nErreur: fils droit inexistant\n");
    }

	/* Affichage de la valeur du noeud */
    printf ("\n%*s%2d", prof*5, espace, A.un.noeud.spoids);

    if (A.un.noeud.filsg != NULL) {
	/* Parcours du sous-arbre gauche */
      AfficheHuffman (*A.un.noeud.filsg, prof+1);
    } else {
      printf ("\nErreur: fils gauche inexistant\n");
    }
  } else {
    /* Pour verifier la coherence de la programmation */
    printf ("\nErreur de programmation: aucun type pour ce noeud\n");
  }
} /* AfficheHuffman */

/*
 * %Fonction globale
 * Nom : main
 *
 * Definition :programme principal pour l'algo de Huffman
 *
 * Argument : 
 *      t_file F
 *
 * Variables globales utilisees :
 *
 * Fonctions appelees :
 * Commentaires :
 *
 * Creation              : 
 * Auteur/Origine        :
 * Modifications         :
 * Derniere modification :
 *                   
 */
void main (void){
  t_alphabet C;
  t_noeudfeuille* res;

  C.nb = 6;
  C.alph = malloc ((C.nb)*sizeof(t_feuille));
  C.alph[0].car = 'f';
  C.alph[0].freq = 5;
  C.alph[1].car = 'e';
  C.alph[1].freq = 9;
  C.alph[2].car = 'c';
  C.alph[2].freq = 12;
  C.alph[3].car = 'b';
  C.alph[3].freq = 13;
  C.alph[4].car = 'd';
  C.alph[4].freq = 16;
  C.alph[5].car = 'a';
  C.alph[5].freq = 45;

  printf("\n\tCalcul de l'arbre de Huffman.");
  res = Huffman (C);
  printf ("\n\tAffichage de l'arbre de Huffman:\n");
  AfficheHuffman (*res, 2);
  printf ("\n");
}

/* Jeu d'essais:
	Calcul de l'arbre de Huffman.
	Affichage de la file de priorite:
(a, 45)
(d, 16)
(b, 13)
(c, 12)
(e, 9)
(f, 5)

	Affichage de la file de priorite:
(14)
(a, 45)
(d, 16)
(b, 13)
(c, 12)

	Affichage de la file de priorite:
(25)
(14)
(a, 45)
(d, 16)

	Affichage de la file de priorite:
(30)
(25)
(a, 45)

	Affichage de la file de priorite:
(55)
(a, 45)

	Affichage de la file de priorite:
(100)

	Affichage de l'arbre de Huffman:

                         d:16 
                    30
                              e: 9 
                         14
                              f: 5 
               55
                         b:13 
                    25
                         c:12 
          100
               a:45 
*/
