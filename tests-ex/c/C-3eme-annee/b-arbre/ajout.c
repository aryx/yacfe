/******************************************************************************
*******************************************************************************
** Matiere                        :    BASES DE DONNEES
** Sujet                          :    B_ARBRES
** Unite de compilation           :    ajout
** Nom du module                  :    ajout.c
*******************************************************************************
** Description                    :
**
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "barbtypes.h"
#include "ajout.h"
                                      /****************************************
                                      * Nom         :  Dans
                                      * Description :  Renvoi vrai si l'article
                                      *                est present dans l'arbre
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :

                                      ****************************************/
Bool Dans (t_arbre *B, t_article a){
  int i;
  Bool trouve;
  t_secteur S;

  i = 0;
  trouve = FAUX;
  valec (B, &S);
  while (!trouve && i < G){
    if (S.cont.don.don[i].cle == a.cle){
      trouve = VRAI;
    } else {
      i++;
    }
  }
  return trouve;
} /* Dans */

                                      /****************************************
                                      * Nom         :  Libre
                                      * Description :  Renvoi vrai si on peut
                                      *                ajouter un article
				      *		       directement
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :
                                      ****************************************/
Bool Libre (t_arbre *B){
  t_secteur S;

  valec (B, &S);

  if (S.typ == 0){
    return (!(S.cont.don.occup[G-1]));
  } else if (S.typ == 1){
    return (!(S.cont.ind.occup[G-1]));
  }
} /* Libre */


                                      /****************************************
                                      * Nom         :  InsererArticle
                                      * Description :  Insereun article dans un
                                      *                bloc libre
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :
                                      ****************************************/
void InsererArticle (t_arbre *B, t_article a){
  t_secteur S;
  t_donnees D;
  int i;

  valec (B, &S);
  i = 0;
	/* Ajout des elements inferieurs a la cle */
  while ((S.cont.don.don[i].cle < a.cle)&&(S.cont.don.occup[i])){
    D.don[i] = S.cont.don.don[i];
    D.occup[i] = S.cont.don.occup[i];
    i++;
  }

	/* Ajout de l'article */
  D.don[i] = a;
  D.occup[i] = VRAI;
  i++;

	/* Ajout du reste des elements */
  while (i<G){
    D.don[i] = S.cont.don.don[i-1];
    D.occup[i] = S.cont.don.occup[i-1];
    i++;
  }

  S.cont.don = D;
  modifier(B->pile[B->sommet],&S); /* modifie l'element courant */
} /* InsererArticle */

                                      /****************************************
                                      * Nom         :  Partager
                                      * Description :  Partage un bloc en
                                      *                deux
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :
                                      ****************************************/
Couple Partager (t_arbre *B, t_article a) {
  Couple nouveau;

  t_secteur S,sect;
  t_article tab[G+1];
  int i;

  S.typ = 0; /* secteur de donnee */

  valec (B, &sect);
  for (i=0; i<G; i++){
	/* On recopie les elements dans le tableau temporaire */
    tab[i] = sect.cont.don.don[i];
  }
  
	/* On decale les articles dont la cle est superieure a a */
  i=G;
  while ((sect.cont.don.don[i-1].cle > a.cle) && (i>0)){
    tab[i] = tab[i-1];
    i--;
  }
  
	/* On insere l'element pour obtenir un tableau trie */
  tab[i] = a;

  for (i=0; i <(G+1)/2; i++){
    /* On insere les articles dans le premier secteur */
    sect.cont.don.don[i] = tab[i];
    sect.cont.don.occup[i] = VRAI;

    /* On insere les articles dans le nouveau secteur */
    S.cont.don.don[i] = tab[i+((G+1)/2)];
    S.cont.don.occup[i] = VRAI;
  }

  for (i=(G+1)/2; i<G; i++){
	/* On met a jour les booleens d'occupation */
    sect.cont.don.occup[i] = FAUX;
    S.cont.don.occup[i] = FAUX;
  }

  modifier(B->pile[B->sommet],&sect); /* modifie l'element courant */
  ecrire(&nouveau.addresse,&S); /* ecrit le secteur alloue */

  nouveau.cle=S.cont.don.don[0].cle;
  return nouveau;
}
                                      /****************************************
                                      * Nom         :  InsererIndex
                                      * Description :  Insere une cle dans une
                                      *                cellule libre d'un bloc
				      *                d'index
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :
                                      ****************************************/

void InsererIndex (t_arbre *B, Couple nouveau){
  t_secteur S;
  t_index In;
  int i;

  valec (B, &S);
  i=0;

  /* Ajout des elements inferieurs a la cle */
  while ((S.cont.ind.cle[i] < nouveau.cle)&&(S.cont.ind.occup[i])){
    In.cle[i] = S.cont.ind.cle[i];
    In.occup[i] = 1;
    In.in[i]=S.cont.ind.in[i];
    i++;
  }
  /* Ajout du nouvau */
  In.cle[i]=nouveau.cle;
  In.occup[i]=1;
  In.in[i]=nouveau.addresse;
  i++;

  /* Ajout reste des elemets */
  while (i<G) {
    In.cle[i] = S.cont.ind.cle[i-1];
    In.occup[i] = S.cont.ind.occup[i-1];
    In.in[i]=S.cont.ind.in[i-1];
    i++;
  }
  
  S.cont.ind=In;
  modifier(B->pile[B->sommet],&S); /* modifie l'element courant */
} /* InsererArticle */




                                      /****************************************
                                      * Nom         :  Partager_index
                                      * Description :  Partage un bloc d'index  en
                                      *                deux
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :
                                      ****************************************/

Couple Partager_index(t_arbre *B, Couple nouveau){
  Couple nouveau_index;

  t_secteur S,sect;
  int tab_cle[I+1];
  int tab_in[I+1];
  int i;

  S.typ = 1; /* secteur d'index */

  valec (B, &sect);
  for (i=0; i<I; i++){
	/* On recopie les elements dans le tableau temporaire */
    tab_cle[i] = sect.cont.ind.cle[i];
    tab_in[i] = sect.cont.ind.in[i];
  }
  
	/* On decale les articles dont la cle est superieure a nouveau.cle */
  i=I;
  while ((sect.cont.ind.cle[i-1] > nouveau.cle) && (i>0)){
    tab_cle[i] = tab_cle[i-1];
    tab_in[i] = tab_in[i-1];
    
    i--;
  }
  
	/* On insere l'element pour obtenir un tableau trie */
  tab_cle[i] = nouveau.cle;
  tab_in[i] = nouveau.addresse;

  for (i=0; i <(I+1)/2; i++){
    /* On insere les articles dans le premier secteur */
    sect.cont.ind.cle[i] = tab_cle[i];
    sect.cont.ind.in[i] = tab_in[i];

    sect.cont.ind.occup[i] = VRAI;

    /* On insere les articles dans le nouveau secteur */
    S.cont.ind.cle[i] = tab_cle[i+((G+1)/2)];
    S.cont.ind.in[i] = tab_in[i+((G+1)/2)];
    S.cont.ind.occup[i] = VRAI;
  }

  for (i=(I+1)/2; i<I; i++){
	/* On met a jour les booleens d'occupation */
    sect.cont.ind.occup[i] = FAUX;
    S.cont.ind.occup[i] = FAUX;
  }

  modifier(B->pile[B->sommet],&sect); /* modifie l'element courant */
  ecrire(&nouveau_index.addresse,&S); /* ecrit le secteur alloue */

  nouveau_index.cle=S.cont.ind.cle[0];
  return nouveau_index;
}




                                      /****************************************
                                      * Nom         :  ModifIndex
                                      * Description :  
                                      *               
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :
                                      ****************************************/
void ModifIndex (t_arbre *B, Couple nouveau) {
  Couple nouveau_index;
  int nouvelle_racine,i;
  t_secteur racine;

  if (horsarbre(B)) { /* on cree une nouvelle racine */ 
    racine.typ=1; /* index */
    racine.cont.ind.occup[0]=1;
    racine.cont.ind.occup[1]=1;

    for (i=2;i<I;i++) racine.cont.ind.occup[i]=0;
    racine.cont.ind.in[0]=B->racine;
    racine.cont.ind.in[1]=nouveau.addresse;
    racine.cont.ind.cle[1]=nouveau.cle;
    ecrire(&nouvelle_racine,&racine);
    B->racine=nouvelle_racine;

  }
  else {
    if (Libre(B)) {
      InsererIndex (B,nouveau);
    } else {
      nouveau_index = Partager_index(B,nouveau); /* on doit en creer un autre */
      positpere(B);
      ModifIndex(B,nouveau_index); /* appel recursif */
    }
  }
}


                                      /****************************************
                                      * Nom         :  ajouter
                                      * Description :  Ajoute un article dans
                                      *                une structure t_donnees
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees :
                                      ****************************************/






void ajouter (t_arbre *B, t_article a){
		 
  Couple nouveau; /* Pointeur sur un bloc de donnees alloue + la cle de son premier elememt*/
  int nouvelle_racine,i;
  t_secteur racine;
  if (arbrevide(B)) { /* on cree une nouvelle racine */ 
    racine.typ=0; /* donne */
    racine.cont.don.don[0]=a;
    racine.cont.don.occup[0]=1;
    for (i=1;i<G;i++) racine.cont.don.occup[i]=0;

    ecrire(&nouvelle_racine,&racine);
    B->racine=nouvelle_racine;

  }
  else {
    chercher (B, a.cle);
    
    if (Dans(B, a)){
      printf ("\nArticle deja present\n");
    } else {
      if (Libre(B)) { /* Il y a la place pour ajouter un article */
	InsererArticle (B, a);
      } else {
	nouveau = Partager (B, a);
	positpere (B);
	ModifIndex (B, nouveau);
      }
    }
  } /* fin du else */

} /* ajouter */


