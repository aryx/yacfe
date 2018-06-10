/*********************************************************************************
**********************************************************************************
** Matière                        :    BASES DE DONNEES
** Sujet                          :    B_ARBRES
** Unité de compilation           :      gestion des b-arbres
** Nom du module                  :    barbtypes.h
** *******************************************************************************
** Description                    :    ce fichier contient les types de base
**                                     et les constantes
*******************************************************************************
*/

#define I 3 
                           /* facteur de groupage pour les index   */
#define G 3
                           /* facteur de groupage pour les donnees */
#define taille 50
                           /* taille d'un article                  */
#define tmax 500
                           /* nombre maximal d'articles             */

 typedef struct a {         /* type pour les articles               */
                    int cle;
                    char c[taille];
                  } t_article;

 typedef struct d {         /* type pour un bloc de donnees         */
                    int occup[G];
                    t_article don[G];
                  } t_donnees;

 typedef struct b {         /* type pour un bloc d'index            */
                    int occup[I];
                    int cle[I];
                    int in[I];
                  } t_index;

 typedef struct g {         /* type pour emuler un secteur          */
                    int typ;          /* type : 0 - donnes          */
                                      /*        1 - index           */
                                      /*       -1 - pas alloue      */
                    union {
                           t_donnees don;
                           t_index ind;
                          } cont;
                    int suc;          /* successeur pour le chainage*/
                  } t_secteur;

 typedef struct t {         /* type pour le descripteur des b-arbres*/
                    int racine;
                    int pile[9];
                    int sommet;
                  } t_arbre;

 
