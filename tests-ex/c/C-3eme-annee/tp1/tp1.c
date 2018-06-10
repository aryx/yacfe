/*  
 *                                  Le premier programme 
 *
 * Objectifs techniques:
 *   decouverte des pieges syntaxiques,
 *   structure d'un programme C en un seul fichier,
 *   les types de base en C,
 *   les e/s simples,
 *   les différentes expressions,
 *   les instructions,
 *   
 * Objectifs 'qualite':
 *   adoption d'une norme 
 *    pour les commentaires,
 *    pour la présentation des instructions
 *   
 * Objectifs algorithmiques:
 *   faut pas rever dans un premier TP de decouverte
 *
 * CE COMMENTAIRE EST EVIDEMMENT HORS DE LA NORME !   
 */
 
/*
 * %Module
 *   Nom            : tp1
 *   Nom du fichier : tp1
 *   Role du module : je me demande bien
 *
 *   Fonctions de ce module :
 *         factrec : calcul recursif de factorielle
 *               prototype : int factrec (int n)
 *
 *         factiter : calcul iteratif de factorielle
 *               prototype : int factiter (int n)
 *
 *         factiterfor : calcul iteratif de factorielle
 *               prototype : int factiterfor (int n)
 *
 *         arr : calcul de nombre d'arrangements
 *               prototype : int arr (int n,int p)
 *
 *         comb : calcul de nombre de combinaisons
 *               prototype : int comb (int n,int p)
 *
 *         moy : calcul d'une moyenne
 *               prototype : float moy (void)
 *
 *         cumul : calcul d'un cumul 
 *                prototype : float cumul (void) 
 */
 
#define TRUE 1
#define FALSE 0
/* 
 * %Fichiers include systeme
 */
#include <stdio.h>

/* 
 * %Fichiers include de l'application
 */
 
 
/* 
 * %Variables globales externes
 *    neant
 */
 

/* 
 * %Fonctions externes appelees dans ce module
 *    neant
 */
 
 
/*
 * %Fonction 
 * Nom : factrec
 *
 * Definition : calcul de la factorielle d'un entier donne.
 *
 * Argument : Entier n 
 *
 * Variables globales utilisees :
 *      néant
 *
 * Fonctions appelees :
 *      néant
 *
 * Erreurs detectee : le parametre est negatif -> message + retour 0
 *
 * Commentaires : cette premiere version de factorielle utilise la recursivite
 *                la conditionnelle, le retour de valeur 
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */
int factrec (int n)
{
  if (n<0) {printf ("erreur factrec,n negatif\n");return 0;}
  if (n==0) return 1;
  else return factrec(n-1)*n;
	     
}
/*???????????????????????????????????????????????????????*/
 
 
/*
 * %Fonction 
 * Nom : factiter
 *
 * Definition : calcul de la factorielle d'un entier donne.
 *
 * Argument : Entier n 
 *
 * Variables globales utilisees :
 *      néant
 *
 * Fonctions appelées :
 *      néant
 *
 * Erreurs detectee : le parametre est negatif -> message + retour 0
 *
 * Commentaires : cette seconde version de factorielle utilise l'iteration while
 *                et necessite au moins une variable locale
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */
int factiter (int n)
{
  int i,acc;
  if (n<0) {printf ("erreur factiter,n negatif\n");return 0;}
  acc=1;
  i=0;
  while (i!=n) {
    i++;
    acc*=i;
  }
  return acc;
} 
/*???????????????????????????????????????????????????????*/
 


/*
 * %Fonction 
 * Nom : factiterfor
 *
 * Definition : calcul de la factorielle d'un entier donne.
 *
 * Argument : 
 *      Entier n 
 *
 * Variables globales utilisees :
 *      néant
 *
 * Fonctions appelees :
 *      néant
 *
 * Erreurs detectee : le parametre est negatif -> message + retour 0
 *
 * Commentaires : cette troisieme version de factorielle utilise l'iteration for
 *                et necessite elle aussi au moins une variable locale	
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *	     
 */
int factiterfor(int n)
{
  int i,acc;
  if (n<0) {printf ("erreur factiterfor,n negatif\n");return 0;}
  acc=1;
  for (i=1;i<=n;i++) acc*=i;
  return acc;
}
/*???????????????????????????????????????????????????????*/



/*
 * %Fonction 
 * Nom : arr
 *
 * Definition : calcul du nombre d'arrangement de p parmi n.
 *
 * Argument : 
 *      Entier n
 *      Entier p 
 *
 * Variables globales utilisees :
 *      néant
 *
 * Fonctions appelees :
 *      factiterfor (tp1/tp1)
 *
 * Erreurs detectee : p>n -> message + return 0
 *
 * Commentaires :  A(n,p) = n! / (n-p)!
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                		     
 */
int arr(int n,int p)
{
  if (n<p) {printf ("erreur arr,n inferieur a p\n");return 0;}
  return factiterfor(n)/factiterfor(n-p);
}

/*???????????????????????????????????????????????????????*/

      
/*
 * %Fonction 
 * Nom : comb
 *
 * Definition : calcul du nombre de combinaison de p parmi n.
 *
 * Argument : 
 *      Entier n
 *      Entier p 
 *
 * Variables globales utilisees :
 *      néant
 *
 * Fonctions appelees :
 *      factiterfor (tp1/tp1)
 *
 * Erreurs detectee : p>n -> message + return 0
 *
 * Commentaires : C(n,p) = n! / (p! * (n-p)!)
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                		     
 */
int comb(int n,int p)
{
  if (n<p) {printf ("erreur comb,n inferieur a p\n");return 0;}
  return factiterfor(n)/(factiterfor(n-p)*factiterfor(p));
}
  
/*???????????????????????????????????????????????????????*/


/*
 * %Fonction 
 * Nom : moy
 *
 * Definition : calcul de la moyenne de nombres entiers entres au clavier.
 *
 * Argument : 
 *      neant
 *
 * Variables globales utilisees :
 *      néant
 *
 * Fonctions appelees :
 *      néant
 *
 * Erreurs detectee :  division par zero -> message + return 0
 *
 * Commentaires :  on termine l'entree par la frappe de -1
 *                 utilisation d'un forceur
 *                 pour lire il faut fournir l'adresse d'une variable
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                		     
 */
float moy (void)
{
  int carlu,nbelem=0;
  int somme=0;
  printf("\ntaper une valeur ou -1 pour arreter\n");
  scanf("%d",&carlu);
  while (carlu!=-1) {
    nbelem++;
    somme+=carlu;
    printf("encore un \n");
    scanf("%d",&carlu);
  }
  if (nbelem==0) {printf("div par zero dans moy\n");return 0;}
  return (float)somme/(float)nbelem;
}
 

/*???????????????????????????????????????????????????????*/


/*
 * %Fonction 
 * Nom : cumul
 *
 * Definition : "cumul" de nombres entiers entres au clavier.
 *              Le cumul depend d'une opération fournie avant la saisie des entiers
 *                +  ->  Somme generalisee classique
 *                -  ->  Difference (le prenier moins la somme des autres)
 *                *  ->  Produit generalise classique
 *                /  ->  Quotient (le premier sur le produit des autres
 *
 * Argument : 
 *      néant
 *
 * Variables globales utilisees :
 *      néant
 *
 * Fonctions appelees :
 *      neant
 *
 * Erreurs detectee :  operation non prevue -> re-invite
 *                     division par zero -> message + finexec 0
 *
 * Commentaires :  on termine l'entree par la frappe de -1
 *                   exemple :
 *
 *                  |Entrer le symbole +, -, * ou /
 *                  | -
 *                  |Entrer les entiers, terminer par -1
 *                  |5
 *                  |5
 *                  |4
 *                  |8
 *                  |-1
 *                    la fonction rend alors -12 en flottant
 *
 *                 lecture de caractere
 *                 utilisation de switch
 *                 utilisation d'un forceur
 *                 pour lire il faut fournir l'adresse d'une variable
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *                		     
 */
float cumul(void)
{
  char c;
  float somme;
  int ok,carlu,val1;

  somme=0;
  ok=FALSE;
  fflush(stdin);
  while (!ok) {
    printf("Entrer le symbole +, -, * ou / \n");
    scanf("%c",&c);
    ok=TRUE;
    switch (c) {
    case '+':
      printf("\ntaper une valeur ou -1 pour arreter\n");
      scanf("%d",&carlu);
      while (carlu!=-1){
	somme+=carlu;
	scanf("%d",&carlu);
      }
    
      break;
    case '-':
      printf("\ntaper une valeur ou -1 pour arreter\n");
      scanf("%d",&carlu);
      val1=carlu;
      scanf("%d",&carlu);
      while (carlu!=-1) {
	somme+=carlu;
	scanf("%d",&carlu);
      }
      somme=val1-somme;
      break;
    case '*':
      printf("\ntaper une valeur ou -1 pour arreter\n");
      scanf("%d",&carlu);
      somme=1;
      while (carlu!=-1){
	somme*=carlu;
	scanf("%d",&carlu);
      }
      break;
    case '/':
      printf("\ntaper une valeur ou -1 pour arreter\n");
      scanf("%d",&carlu);
      val1=carlu;
      scanf("%d",&carlu);
      while (carlu!=-1) {
	somme+=carlu;
	scanf("%d",&carlu);
      }
      if (val1==0) {printf("div par zero dans cumul\n");return 0;}
      somme=(float)val1/(float)somme;
      break;
    default:ok=FALSE;
    }
  }
  return somme;
} 
/*???????????????????????????????????????????????????????*/
  
/*
 * %Fonction 
 * Nom : main
 *
 * Definition : l'inevitable fonction "principale" en C
 *
 * Argument : 
 *      neant
 *
 * Variables globales utilisees :
 *      neant
 *
 * Fonctions appelées :
 *      factrec (tp1/tp1)
 *      factiter (tp1/tp1)
 *      factiterfor (tp1/tp1)
 *      arr (tp1/tp1)
 *      comb (tp1/tp1)
 *      moy (tp1/tp1)
 *      cumul (tp1/tp1)
 *
 * Erreurs detectee :  neant
 *
 * Commentaires :  
 *     appel pour test de chacune des fonctions
 *                		     
 */      

int main(void)

 { 
/*
 * Declaration des variables locales
 */ 
   int i;      /* variable de test                       */
   int j;      /* variable de test                       */
   
   i = 8;
   j = 5;
   
   printf("fact(%d)=%d\n",i,factrec(i));
   
   printf("fact(%d)=%d\n",i,factiter(i));
   
   printf("fact(%d)=%d\n",i,factiterfor(i));
   
   printf("A(%d,%d)=%d\n",i,j,arr(i,j));
   
   printf("C(%d,%d)=%d\n",i,j,comb(i,j));
   
   printf(" calcul de moyenne%f \n",moy());
   
   printf(" operation : %f \n", cumul());

 } /* main */
 





