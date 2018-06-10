/*  
 *                                  Le troisième programme 
 *
 * Objectifs techniques:
 *   decouverte des pièges syntaxiques,
 *   articulation de 2 modules,
 *   les définitions de type
 *         union
 *         struct
 *         enum,
 *   les objets composés 
 *         en parametre, 
 *         en resultat,
 *   le Makefile
 *   l'utilisation de la bibliotheque mathematique
 *   
 *
 * Objectifs 'qualité':
 *   creation d'un environnement de developpement 
 *     le Makefile
 *     les includes
 *   
 * Objectifs algorithmiques:
 *    mise en oeuvre d'un module de calcul sur les nombres complexes
 *   
 */
 
/*
 * %Module

 *   Nom            : comp
 *   Nom du fichier : comp.c
 *   Role du module : implanter les operations courantes sur le domaine des 
 *                    nombres complexes, ainsi que la saisie et l'affichage
 *
 *   Fonctions de ce module :
 *         partreelle : partie reelle d'un nombre complexe
 *              prototype : float partreelle (Complexe z)
 *
 *         partimag : partie imaginaire d'un nombre complexe
 *              prototype : float partimag (Complexe z)
 *
 *         partmodule : partie module d'un nombre complexe
 *              prototype : float partmodule (Complexe z)
 *
 *         partargument : partie argument d'un nombre complexe
 *              prototype : float partargument (Complexe z)
 *
 *         addc : somme de 2 nombres complexes
 *              prototype : Complexe addc(Complexe z1, Complexe z2)
 *
 *         mulc : produit de 2 nombres complexes
 *              prototype : Complexe mulc(Complexe z1, Complexe z2)
 *
 *         sousc : difference de 2 nombres complexes
 *              prototype : Complexe sousc(Complexe z1, Complexe z2)
 *
 *         divc : quotient de 2 nombres complexes
 *              prototype : Complexe divc(Complexe z1, Complexe z2)
 * 
 *         lirec : lecture d'un nombre complexe
 *		prototype : Complexe lirec (void);
 *
 *         ecrirec : ecriture d'un nombre complexe
 *              prototype : void ecrirec (Complexe z);
 *
 *         initcrect : initialisation d'un nombre complexe rectang.
 *              prototype : Complexe initcrect (float pr, float pi);
 *
 *         initcpol : initialisation d'un nombre complexe polaire
 *              prototype : Complexe initcpol (float md, float ar);
 *
 *
 */
 

/* 
 * %Fichiers include systeme
 */
#include <stdio.h>
#include <math.h>


/* 
 * %Fichiers include de l'application
 */
#include "comp.h" 
 
/* 
 * %Variables globales externes
 *    neant
 */
 

/* 
 * %Fonctions externes appelées dans ce module
 *    neant
 */
 
/*
 * %Fonction locale
 * Nom : EstRect
 *
 * Definition : Renvoi Vrai si le complexe est sous forme Rectangulaire
 *
 * Argument : 
 *      Complexe z
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelées :
 *      neant
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */
Bool EstRect (Complexe z){
  return ((z.indicrep == rect)?vrai:faux);
} /* EstRect */

/*
 * %Fonction globale
 * Nom : partreelle
 *
 * Definition : isole la partie reelle d'un complexe
 *
 * Argument : 
 *      Complexe z
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelées :
 *      cos de la librairie mathematique
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

float partreelle (Complexe z){
  if ( EstRect (z) ){
    return z.valeur.rep1.preel;
  } else {
    return (z.valeur.rep2.module*(cos(z.valeur.rep2.argument)));
  }
} /* partreelle */


/*
 * %Fonction globale
 * Nom : partimag
 *
 * Definition : isole la partie imaginaire d'un complexe
 *
 * Argument : 
 *      Complexe z
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelées :
 *      sin de la librairie mathematique
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

float partimag (Complexe z){
  if ( EstRect (z) ){
    return z.valeur.rep1.pimag;
  } else {
    return (z.valeur.rep2.module*(sin(z.valeur.rep2.argument)));
  }
} /* partimag */


/*
 * %Fonction globale
 * Nom : partmodule
 *
 * Definition : isole le module d'un complexe
 *
 * Argument : 
 *      Complexe z
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelées :
 *      sqrt et pow de la librairie mathematique
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

float partmodule (Complexe z){
  if (EstRect (z) ) {
    return (sqrt(pow(z.valeur.rep1.preel, 2) + pow(z.valeur.rep1.pimag,2)));
  } else {
    return (z.valeur.rep2.module);
  }
} /* partmodule */


/*
 * %Fonction globale
 * Nom : partargument
 *
 * Definition : isole l'argument d'un complexe
 *
 * Argument : 
 *      Complexe z
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelées :
 *      atan2 de la librairie mathematique
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

float partargument (Complexe z){
  if (EstRect (z) ) {
    return (atan2(z.valeur.rep1.pimag, z.valeur.rep1.preel));
  } else {
    return (z.valeur.rep2.argument);
  }
} /* partargument */

/*
 * %Fonction globale
 * Nom : addc
 *
 * Definition : calcule la somme de 2 complexes
 *
 * Argument : 
 *      Complexe z1
 *      Complexe z2
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      partreelle (tp2 / comp.c)
 *      partimag   (tp2 / comp.c)
 *      initcrect  (tp2 / comp.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe addc(Complexe z1, Complexe z2){
  float f1, f2;

  f1 = partreelle (z1) + partreelle (z2);
  f2 = partimag (z1) + partimag (z2);

  return (initcrect (f1, f2));
;
}
 


/*
 * %Fonction globale
 * Nom : sousc
 *
 * Definition : calcule la difference de 2 complexes
 *
 * Argument : 
 *      Complexe z1
 *      Complexe z2
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      partreelle (tp2 / comp.c)
 *      partimag   (tp2 / comp.c)
 *      initcrect  (tp2 / comp.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe sousc(Complexe z1, Complexe z2){
  float f1, f2;

  f1 = partreelle (z1) - partreelle (z2);
  f2 = partimag (z1) - partimag (z2);

  return (initcrect (f1, f2));
}
 


/*
 * %Fonction globale
 * Nom : mulc
 *
 * Definition : calcule le produit de 2 complexes
 *
 * Argument : 
 *      Complexe z1
 *      Complexe z2
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      partmodule     (tp2 / comp.c)
 *      partargument   (tp2 / comp.c)
 *      initcpol       (tp2 / comp.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe mulc(Complexe z1, Complexe z2){
  float f1, f2;

  f2 = partargument (z1) + partargument (z2);
  f1 = partmodule (z1) * partmodule (z2);

  return (initcpol (f1, f2));
}
 
   

/*
 * %Fonction globale
 * Nom : divc
 *
 * Definition : calcule le quotient de 2 complexes
 *
 * Argument : 
 *      Complexe z1
 *      Complexe z2
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      partmodule     (tp2 / comp.c)
 *      partargument   (tp2 / comp.c)
 *      initcpol       (tp2 / comp.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *
 * Creation              : 28 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe divc(Complexe z1, Complexe z2){
  float f1, f2;

  f2 = partargument (z1) - partargument (z2);
  f1 = partmodule (z1) / partmodule (z2);

  return (initcpol (f1, f2));
}
 


/*
 * %Fonction globale
 * Nom : lirec
 *
 * Definition : lecture d'un complexe au clavier
 *
 * Argument : 
 *      neant
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      partmodule   (tp2 / comp.c)
 *      partargument (tp2 / comp.c)
 *      partreelle   (tp2 / comp.c)
 *      partimag     (tp2 / comp.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :  l'utilisateur est tout d'abord invite a indiquer la
 *                 representation du complexe saisi.
 *                 On ne le lache pas avant qu'il ait repondu 
 *                     r pour rectangulaire ou 
 *                     p pour polaire
 *
 * Creation              : 29 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe lirec(void){
  Bool ok;
  char carlu;
  float f1, f2;
  Complexe res;

  ok = faux;
  while (!ok) {
    printf ("\n\tDans quelle representation?(r=rectangulaire; p=polaire): ");
    scanf ("%c", &carlu);
    if (carlu == 'r' || carlu == 'p'){
      ok = vrai;
    }
  }
  if (carlu == 'p'){
    printf ("\n\tModule?: ");
    scanf ("%f", &f1);

    printf ("\n\tArgument?: ");
    scanf ("%f", &f2);

    res = initcpol (f1, f2);
  } else {
    printf ("\n\tPartie reelle?: ");
    scanf ("%f", &f1);

    printf ("\n\tPartie imaginaire?: ");
    scanf ("%f", &f2);

    res = initcrect (f1, f2);
  }

  return res;
}
 



/*
 * %Fonction globale
 * Nom : ecrirec
 *
 * Definition : affichage d'un complexe dans sa representation courante
 *
 * Argument : 
 *      neant
 *
 * Variables glogales utilisées :
 *      néant
 *
 * Fonctions appelées :
 *      partmodule   (tp2 / comp.c)
 *      partargument (tp2 / comp.c)
 *      partreelle   (tp2 / comp.c)
 *      partimag     (tp2 / comp.c)
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *                   
 *
 * Creation              : 29 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

void ecrirec (Complexe z){
  if (EstRect(z)) {
    printf (" %0.0f + %0.0fi ", partreelle(z), partimag(z));
  } else {
    printf (" %0fe(%0fi) ", partmodule(z), partargument(z));
  }
}

 
 
/*
 * %Fonction globale
 * Nom : initcrect
 *
 * Definition : initialisation d'un complexe dans la representation 
 *               rectangulaire
 *
 * Argument : 
 *      float pr    (la partie reelle)
 *      float pi    (la partie imaginaire)
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      neant
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *                   
 *
 * Creation              : 29 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe initcrect (float pr, float pi){
  Complexe res;

  res.indicrep = rect;
  res.valeur.rep1.preel = pr;
  res.valeur.rep1.pimag = pi;

  return res;
}



/*
 * %Fonction globale
 * Nom : initcpol
 *
 * Definition : initialisation d'un complexe dans la representation 
 *               polaire
 *
 * Argument : 
 *      float md    (le module)
 *      float ar    (l'argument)
 *
 * Variables glogales utilisees :
 *      neant
 *
 * Fonctions appelees :
 *      neant
 *
 * Erreur detectee : 
 *
 * Commentaires :  
 *                   
 *
 * Creation              : 29 mars 1995
 * Auteur/Origine        : E. Monnier
 * Modifications         :
 * Derniere modification :
 *		     
 */

Complexe initcpol (float md, float ar){
  Complexe res;

  res.indicrep = pol;
  res.valeur.rep2.module = md;
  res.valeur.rep2.argument = ar;

  return res;
}


/* definition du complexe C_i = i */
const Complexe C_i = {rect, {0,1}};

