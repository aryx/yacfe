/******************************************************************************
*******************************************************************************
** Matière                        :    BASES DE DONNEES
** Sujet                          :    B_ARBRES
** Unité de compilation           :      gestion
** Nom du module                  :    gestion.c
*******************************************************************************
** Description                    :
**
******************************************************************************/

#include <stdio.h> 
#include "barbtypes.h" 
/*******************************************************************************
*               gestion de memoire pour l'emulation de disque                  *
*******************************************************************************/
                                             /*  definitions                  */
                                             /*********************************/
   static t_secteur TMEM[tmax];              /* tableau pour emuler le disque */
   static int  DISPO;                        /* ind. de 1er secteur disponible*/
                                             /*********************************/


                                      /****************************************
                                      * Nom         :  initmem
                                      * Description :  initialisation de la
                                      *                memoire disponible
                                      *****************************************
                                      * Var. globales modifiees  : TMEM, DISPO
                                      * Proc. externes utilisees :
                                      ****************************************/
       initmem ()
               {
               int i;
               for (i=0; i<tmax; i++)
                    {
                     TMEM[i].suc = i+1;
                     TMEM[i].typ = -1;
                    }
               DISPO = 0;
               }

                                      /****************************************
                                      * Nom         :  allouer
                                      * Description :  allocation d'un secteur
                                      *                dans TMEM, retour de son
                                      *                indice
                                      *****************************************
                                      * Var. globales modifiees  : TMEM, DISPO
                                      * Proc. externes utilisees :
                                      ****************************************/
       allouer ()
               {
               int r;
               if (DISPO == tmax)
                     return -1;
               else   {
                      r = DISPO;
                      DISPO = TMEM[r].suc;
                      return r;
                      }
               }

                                      /****************************************
                                      * Nom         :  liberer
                                      * Description :  cette fonction rend le
                                      *                secteur reference par
                                      *                son argument a la gestion
                                      *****************************************
                                      * Var. globales modifiees  : TMEM, DISPO
                                      * Proc. externes utilisees :
                                      ****************************************/
       liberer (int r)
               {
               if ((r < 0) || (r > tmax-1))
                     return -1;
               else   {
                      TMEM[r].suc = DISPO;
                      TMEM[r].typ = -1;
                      DISPO = r;
                      return r;
                      }
               }

/*******************************************************************************
*                          emulation des E/S disques                           *
*******************************************************************************/
                                      /****************************************
                                      * Nom         :  ecrire
                                      * Description : ecriture d'un secteur
                                      *              (deuxieme argument), son 
                                      *              adresse est retournee dans
                                      *              adr
                                      *****************************************
                                      * Var. globales modifiees  : TMEM, DISPO
                                      * Proc. externes utilisees : allouer
                                      ****************************************/
       ecrire (int * adr, t_secteur * sect)
               {
               if (((* adr) = allouer()) == -1)
                     return -1;
               else   {
                      TMEM[(* adr)] = (* sect);
                      return 0;
                      }
               }

                                      /****************************************
                                      * Nom         :  lire
                                      * Description : lecture d'un secteur
                                      *              (deuxieme argument), son 
                                      *              adresse est donnee par
                                      *              adr
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : 
                                      ****************************************/
       lire (int adr, t_secteur * sect)
               {
               if ( (adr < 0) || (adr > tmax-1) || (TMEM[adr].typ == -1) )
                     return -1;
               else   {
                      (* sect) = TMEM[adr];
                      return 0;
                      }
               }

                                      /****************************************
                                      * Nom         :  modifier
                                      * Description : modification d'un secteur
                                      *              (deuxieme argument), son 
                                      *              adresse est donnee par
                                      *              adr
                                      *****************************************
                                      * Var. globales modifiees  : TMEM
                                      * Proc. externes utilisees : 
                                      ****************************************/
       modifier (int adr, t_secteur * sect)
               {
               if ( (adr < 0) || (adr > tmax-1) || (TMEM[adr].typ == -1) )
                     return -1;
               else   {
                      TMEM[adr] = (* sect);
                      return 0;
                      }
               }

                                      /****************************************
                                      * Nom         :  supprimer
                                      * Description : suppression d'un secteur
                                      *              qui est determine par
                                      *              adr
                                      *****************************************
                                      * Var. globales modifiees  : TMEM, DISPO
                                      * Proc. externes utilisees : liberer
                                      ****************************************/
       supprimer (int adr)
               {
               if ( (adr < 0) || (adr > tmax-1) || (TMEM[adr].typ == -1) )
                     return -1;
               else   {
                      liberer(adr);
                      return 0;
                      }
               }

/*******************************************************************************
*                                acces B-arbre                                 *
*******************************************************************************/
                                      /****************************************
                                      * Nom         :  initarbre
                                      * Description : initialisation de l'arbre
                                      *               B a vide
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : 
                                      ****************************************/
       initarbre (t_arbre * B)
               {
               B->racine = -1;
               B->sommet = -1;
               }

                                      /****************************************
                                      * Nom         :  arbrevide
                                      * Description : retourne vrai si l'arbre
                                      *               est vide
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : 
                                      ****************************************/
       arbrevide (t_arbre * B)
               {
               return (B->racine == -1);
               }

                                      /****************************************
                                      * Nom         :  horsarbre
                                      * Description : retourne vrai si l'on est
                                      *               hors arbre
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : 
                                      ****************************************/
       horsarbre (t_arbre * B)
               {
               return (B->sommet < 0);
               }

                                      /****************************************
                                      * Nom         :  racine
                                      * Description : retourne vrai si l'on est
                                      *               positionne a la racine
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : horsarbre
                                      ****************************************/
       racine (t_arbre * B)
               {
               if (horsarbre(B))    return 0;
               else                 return (B->sommet == 0);
               }

                                      /****************************************
                                      * Nom         :  feuille
                                      * Description : retourne vrai si l'on est 
                                      *               positionne sur une feuille
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : horsarbre, 
                                      *                            valec
                                      ****************************************/
       feuille (t_arbre * B)
               {
                t_secteur S;
               if (horsarbre(B))    return 0;
               else   {
                       valec (B, &S);
                       return (S.typ == 0);
                      }
               }

                                      /****************************************
                                      * Nom         :  valec
                                      * Description : rend le noeud courant de B
                                      *               dans S
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : lire,
                                      *                            horsarbre
                                      ****************************************/
       valec (t_arbre * B, t_secteur * S)
               {
               if (horsarbre(B))    return 0;
               else   {
                       lire (B->pile[B->sommet], S);
                       return 1;
                      }
               }

                                      /****************************************
                                      * Nom         :  positracine
                                      * Description : positionne sur la racine
                                      *               de B
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : arbrevide
                                      ****************************************/
       positracine (t_arbre * B)
               {
               if (arbrevide(B))    return -1;
               else   {
                      B->pile[0] = B->racine;
                      B->sommet = 0;
                      return 0;
                      }
               }

                                      /****************************************
                                      * Nom         :  positpere
                                      * Description : positionne sur le pere du
                                      *               noeud courant
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : horsarbre
                                      ****************************************/
       positpere (t_arbre * B)
               {
               if (horsarbre(B))    return -1;
               else   {
                      B->sommet --;
                      return 0;
                      }
               }

                                      /****************************************
                                      * Nom         :  positfils
                                      * Description : positionne sur le fils du
                                      *               noeud courant ou la cle c
                                      *               devrait se trouver
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : horsarbre,
                                      *                            feuille,
                                      *                            valec
                                      ****************************************/
       positfils (t_arbre * B, int c)
               {
                t_secteur S;
                int j, k;
               if (horsarbre(B))    return -1;
               if (feuille(B))    return 1;
               valec (B, &S);
               j = 1;
               while ((j<I-1) && (S.cont.ind.occup[j]) && (c>S.cont.ind.cle[j]))
                       j++;
               B->sommet ++;
               if (! S.cont.ind.occup[j])
                      B->pile[B->sommet] = S.cont.ind.in[j-1];
               else
                      if (c < S.cont.ind.cle[j])
                             B->pile[B->sommet] = S.cont.ind.in[j-1];
                      else   B->pile[B->sommet] = S.cont.ind.in[j];
               return 0;
               }

                                      /****************************************
                                      * Nom         :  imprimer
                                      * Description : impression de l'arbre
                                      *               (appel de l'impression
                                      *               recursive imp_rec)
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : arbrevide,
                                      *                            psitracine,
                                      *                            imp_rec
                                      ****************************************/
       imprimer (t_arbre * B)
               {

               if (arbrevide(B))
                      printf (" impression : arbre vide *** \n");
               else   {
                       positracine(B);
                       imp_rec(B);
                      printf (" \n + + + \n");
                      }
               }

                                      /****************************************
                                      * Nom         :  impr_rec
                                      * Description : impression recursive 
                                      *               postfixee du b-arbre
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : horsarbre,
                                      *                            valec, 
                                      *                            positfils,
                                      *                            feuille,
                                      *                            printf
                                      ****************************************/
       imp_rec (t_arbre * B)
               {
               t_secteur S;
               int j;
               if (horsarbre(B))
                      printf (" impression : hors arbre *** \n");
               else   {
                      valec (B, &S);
                      if (feuille(B))
                            {
                            printf("[ ");
                            for (j=0; j<G; j++)
                                if ( S.cont.don.occup[j])
                                     printf("%d ", S.cont.don.don[j].cle);
                                else
                                     printf(" - ");
                            printf("] ");
                            }
                       else {
                            printf("< ");
                            for (j=0; j<I; j++)
                                if ( S.cont.ind.occup[j])
                                     {
                                      if (j == 0)
                                     positfils(B, S.cont.ind.cle[1]-1);
                                     else
                                     positfils(B, S.cont.ind.cle[j]);
                                     imp_rec(B);
                                     positpere(B);
                                     }
                            printf("> \n");
                            printf("[ - ");
                            for (j=1; j<I; j++)
                                if ( S.cont.ind.occup[j])
                                     printf("%d ", S.cont.ind.cle[j]);
                                else
                                     printf(" - ");
                            printf("] ");
                            }
                      }
               }

                                      /****************************************
                                      * Nom         :  chercher
                                      * Description : positionne sur la feuille 
                                      *               qui devrait contenir c
                                      *****************************************
                                      * Var. globales modifiees  : 
                                      * Proc. externes utilisees : arbrevide,
                                      *                            valec, 
                                      *                            positracine,
                                      *                            positfils
                                      ****************************************/
       chercher (t_arbre * B, int c)
               {
                t_secteur S;
                int j;
               if (arbrevide(B))
                      {
                      printf (" chercher : arbre vide *** \n");
                      return 0;
                      }
               else   {
                      positracine(B);
                      while (! feuille(B))
                            positfils(B,c);
                      valec (B, &S);
                      j = 0;
                      while ((j<G-1) && (S.cont.don.occup[j]) && 
                             (S.cont.don.don[j].cle<c))           j++;
                      if ( ! S.cont.don.occup[j])
                            return 0;
                      if ( S.cont.don.don[j].cle == c)
                            return 1;
                      else
                            return 0;
                      }
               }

