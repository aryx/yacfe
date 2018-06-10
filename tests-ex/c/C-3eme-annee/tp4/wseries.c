/* % Gestion de configuration
 * Creation : 28 mars  98
 * Auteur : Sebastien Gringoire
 *          Yoann Padioleau
 * Modifications : 
 * Derniere modification
 *
 */
/*
 * %Module
 *   Nom            : wordseries
 *   Nom du fichier : worlseries.c
 *   Role du module : comparer les temps de calcul d'une fonction purement
 *                     recursive et de la meme fonction tabulee par une 
                       methode de programmation dynamique
 *   Fonctions de ce module :
 * locales  :
 *       p_recurs     : calcul de fonction purement recursive
 * 			prototype : real p_recurs(int i, int j)
 *       p_recurs_tab : calcul de fonction  en programmation dynamique
 * 			prototype : real p_recurs_tab(int i, int j)
 *       p_tab        : calcul de fonction par tables
 * 			prototype : real p_tab(int i, int j) 
 *       p_tab_pt     : calcul par tables : parcours de la table par
 *  			pointeurs                
 * globales :
 
/* 
 * %Fichiers include systeme
 */
#include "stdio.h"
#include <math.h>

/* definitions globales 
 */
const int m =  15;	/* taille maximum de la table */

int nb1;		/* variables globales pour compter */
int nb2;		/* le nombre appels recursifs      */

/*
 * %Fonction locale
 * Nom : p_recurs 
 * Definition : calcul de fonction purement recursive
 * Argument : int i, int j    
 * Resultat : real      
 * Fonctions appelantes : main 
 * Fonctions appelées :p_recurs 
 * Erreur detectee :
 * Commentaires :  
 * Creation              : 5 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

float p_recurs(int i, int j) {
  float res;

  nb1++;    /* On calcul le nombre d'appels recursifs */

  if ((i==0) && (j>0)) {
    res = 1;
  } else if ((i>0) && (j==0)) {
    res = 0;
  } else {
    res = (p_recurs (i-1, j) +  p_recurs (i, j-1))/2;
  } /* if */

  return res;
} /*p_recurs */

/*
 * %Fonction locale
 * Nom : p_recurs_tab 
 * Definition : calcul de fonction recursive avec tabulation
 * Argument : int i, int j    
 * Resultat : real      
 * Fonctions appelantes : main 
 * Fonctions appelées : p_recurs_loc (fonction locale recursive) 
 * Erreur detectee :
 * Commentaires : le tableau est local a la procedure 
 * Creation              : 5 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

float p_recurs_tab(int i, int j) {
 float  tab [m][m];	/* tableau local */
 int k, l;
 
 float p_recurs_loc (int c, int d){
   float res;

   nb2++;    /* On calcule le nombre d'appels recursifs */

   if ((c==0) && (d>0)) {
     res = 1;
   } else if ((c>0) && (d==0)) {
     res = 0;
   } else {
     if (tab [c-1][d] == -1) {
       tab[c-1][d] = p_recurs_loc (c-1, d);
     }
     if (tab [c][d-1] == -1) {
       tab [c][d-1] = p_recurs_loc (c, d-1);
     }
     res = (tab[c-1][d] +  tab [c][d-1])/2;
   } /* if */  
   return res;
 } /* p_recurs_loc */

 for (k=0; k<m; k++){   /* Initialisation du tableau */
   for (l=0; l<m; l++){
     tab [k][l] = -1;
   }
 }

 return (p_recurs_loc (i, j));
} /* p_recurs_tab */ 

/*
 * %Fonction locale
 * Nom : p_tab 
 * Definition : calcul de fonction purement tabulee
 * Argument : int i, int j    
 * Resultat : real      
 * Fonctions appelantes : main 
 * Fonctions appelées :  
 * Erreur detectee :
 * Commentaires :  le tableau est local a la procedure
 * Creation              : 5 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

float p_tab(int i, int j) {
 float  tab [m][m];	/* tableau local */
 int k, l;

 for (k=0; k<m; k++){   /* Initialisation du tableau */
   tab [0][k] = 1;
   tab [k][0] = 0;
 }
 for (k=1; k<m; k++){
   for (l=1; l<m; l++){
     tab [k][l] = (tab [k-1][l] + tab [k][l-1])/2;
   }
 }

 return tab[i][j] ;
} /*p_tab*/


/*
 * %Fonction locale
 * Nom : p_tab_pt 
 * Definition : calcul de fonction purement tabulee avec pointeurs
 * 		elle joue exactement le meme role que la precedente
 * Argument : int i, int j    
 * Resultat : real      
 * Fonctions appelantes : main 
 * Fonctions appelées :  
 * Erreur detectee :
 * Commentaires : on s'interdit la notation tab[i][j],on accede
 *		  aux elements par pointeurs
 * Creation              : 5 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

float p_tab_pt(int i, int j) {
 float  tab [m][m];	/* tableau local */
 float *ptr_tab;
 float *ptr_fin;
 int k, l;

 ptr_tab = (float *)tab;
 ptr_fin = (float *)(tab + m*m);

 for (k=0; k<m; k++){
   *(ptr_tab + k) = 1;
   *(ptr_tab + m*k) = 0;
 }

 for (; ptr_tab < ptr_fin; ptr_tab++){
   /* Initialisation du tableau */
   *ptr_tab = (*(ptr_tab - m) + *(ptr_tab - 1))/2;
 }

 return tab[i][j] ;
} /*p_tab_pt*/


/*
 * %Fonction locale
 * Nom : f 
 * Definition : calcul de fonction de la  complexite theorique
 * Argument : int i    
 * Resultat : float      
 * Fonctions appelantes : main 
 * Fonctions appelées : pow, sqrt (Librairie math) 
 * Erreur detectee :
 * Commentaires :  
 * Creation              : 5 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */

float f(int i) { return pow(4,i)/sqrt(2*i);}

/*
 * %Fonction globale
 * Nom : main 
 * Definition : comparaisons de methodes en temps de calcul
 *              pour les 3 fonctions
 * Argument :     
 * Resultat : void      
 * Fonctions appelantes : 
 * Fonctions appelées : p_recurs, p_recurs_tab, p_tab, p_tab_pt
 *  			clock   
 * Erreur detectee :
 * Commentaires :  
 * Creation              : 5 mars 98
 * Auteur/Origine        : M.J. Pedrono
 * Modifications         :
 * Derniere modification :		     
 */
int  main() {
  int i;
  long tps1, tps2;
  float res;

  nb1 = 0;
  nb2 = 0;

  /*
  printf ("\n\tCalcul du nombre d'appels recursifs pour i de 1 a 15:\n");
  for (i=1; i<=15; i++){
    p_recurs (i, i);
    p_recurs_tab (i, i);

    printf ("i= %9d, nb1= %9d, nb2= %9d\n", i, nb1, nb2);
  }
  */

  printf ("\n\tCalcul des temps pour les 3 fonctions:\n");
  for (i=1; i<=15; i++){
    tps1 = clock();
    p_recurs (i, i);
    tps2 = clock();
    printf ("***i= %9d\n\t t_rec= %9d,", i, tps2-tps1);
    res = (tps2-tps1)/f(i);

    tps1 = clock ();
    p_recurs_tab (i, i);
    tps2 = clock();
    printf ("t_rec_tab= %9d,", tps2-tps1);

    tps1 = clock();
    p_tab (i, i);
    tps2 = clock();
    printf ("t_tab= %9d,", tps2-tps1);

    tps1 = clock();
    p_tab_pt (i, i);
    tps2 = clock();
    printf ("t_tab_pt= %9d,", tps2-tps1);

    printf ("f(i)= %f, t_rec/f(i)= %9f\n\n", f (i), res);
 
  }
}/*main*/


/* Resultats:
	Calcul du nombre d'appels recursifs pour i de 1 a 15:
i=         1, nb1=         3, nb2=         3
i=         2, nb1=        14, nb2=        11
i=         3, nb1=        53, nb2=        26
i=         4, nb1=       192, nb2=        50
i=         5, nb1=       695, nb2=        85
i=         6, nb1=      2542, nb2=       133
i=         7, nb1=      9405, nb2=       196
i=         8, nb1=     35144, nb2=       276
i=         9, nb1=    132383, nb2=       375
i=        10, nb1=    501894, nb2=       495
i=        11, nb1=   1912757, nb2=       638
i=        12, nb1=   7321068, nb2=       806
i=        13, nb1=  28122267, nb2=       807
i=        14, nb1= 108355466, nb2=       808
i=        15, nb1= 418590505, nb2=       809

	Calcul des temps pour les 3 fonctions:
***i=         1
	 t_rec=         0,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 2.828427, t_rec/f(i)=  0.000000

***i=         2
	 t_rec=         0,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 8.000000, t_rec/f(i)=  0.000000

***i=         3
	 t_rec=         0,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 26.127892, t_rec/f(i)=  0.000000

***i=         4
	 t_rec=         0,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 90.509666, t_rec/f(i)=  0.000000

***i=         5
	 t_rec=         0,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 323.817230, t_rec/f(i)=  0.000000

***i=         6
	 t_rec=         0,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 1182.413330, t_rec/f(i)=  0.000000

***i=         7
	 t_rec=     10000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 4378.808105, t_rec/f(i)=  2.283726

***i=         8
	 t_rec=     30000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 16384.000000, t_rec/f(i)=  1.831055

***i=         9
	 t_rec=    110000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 61787.933594, t_rec/f(i)=  1.780283

***i=        10
	 t_rec=    370000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 234468.718750, t_rec/f(i)=  1.578036

***i=        11
	 t_rec=   1410000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 894228.625000, t_rec/f(i)=  1.576778

***i=        12
	 t_rec=   5380000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 3424635.000000, t_rec/f(i)=  1.570970

***i=        13
	 t_rec=  20700000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 13161131.000000, t_rec/f(i)=  1.572813

***i=        14
	 t_rec=  80090000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 50729532.000000, t_rec/f(i)=  1.578765

***i=        15
	 t_rec= 310680000,t_rec_tab=         0,t_tab=         0,t_tab_pt=         0,f(i)= 196037536.000000, t_rec/f(i)=  1.584799

*/
