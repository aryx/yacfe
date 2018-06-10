/*******************************************************************************
 *
 * Copyright (C) 1998-1999 by Y. Padioleau, G. Cottenceau, P. Garcia,
 *   G. LeGuelvouit, Y. Zemali, S. Crunchant, X. Michard.
 *
 * Please check out README.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 ******************************************************************************/

/* -------------- declaration section -------------- */
%name RegleParser

/* sinon il me fait chier */
%define LSP_NEEDED

%define ERROR_BODY =0
%define LEX_BODY =0
// gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
%define LTYPE yyltype2

%define MEMBERS \
   public: \
       RegleExclusion * _regle;
/* %define CONSTRUCTOR_CODE _regle = new RegleExclusion(); */


%header{
#include "CommunFichiers.h"

#include "RegleExclusion.h"

  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype2
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype2;


%}

/* -------------- union section -------------- */

%union {
  int                         entier;
  char*                       Nom;

  RegleExclusion::Contrainte  contr;
  RegleExclusion::Deplacement depl;
  RegleExclusion*             regle;
}

/* -------------- token section -------------- */

%token NOM ENTETEREGLE
%token CNULLE CMEMPHI CPHIINFERIEUR CPHIINFSOLIDE
%token REGLES Depl_IMPOSSIBLE Depl_POSSIBLE
%token TOK_BAD
/* -------------- type section -------------- */

%type <Nom> NOM

%type <contr> Contrainte
%type <depl>  Deplacement
%type <regle> Regle

/* -------------- rules section -------------- */
%%

file:    ENTETEREGLE Regle {_regle = $2;}
    |                Regle {_regle = $1;}
;


/* -------- pure parser ---------- */
Regle:   NOM '=' '(' '(' Contrainte ',' Deplacement ')' ','
                     '(' Contrainte ',' Deplacement ')' ','
                     '(' Contrainte ',' Deplacement ')' ','
                     '(' Contrainte ',' Deplacement ')' ','
                     '(' Contrainte ',' Deplacement ')' ','
                     '(' Contrainte ',' Deplacement ')'
	             ')' ';'
{ 
  RegleExclusion* _tmpRegle = new RegleExclusion();
 
  _tmpRegle->setNom($1);
  _tmpRegle->ajoutPaire($7,  $5);
  _tmpRegle->ajoutPaire($13, $11);
  _tmpRegle->ajoutPaire($19, $17);
  _tmpRegle->ajoutPaire($25, $23);
  _tmpRegle->ajoutPaire($31, $29);
  _tmpRegle->ajoutPaire($37, $35);
  $$ = _tmpRegle;
}
;

Contrainte: CPHIINFERIEUR { $$ = RegleExclusion::CONTRAINTE_PHIINFERIEUR; }
	  | CNULLE        { $$ = RegleExclusion::CONTRAINTE_NULLE; } 
	  | CPHIINFSOLIDE { $$ = RegleExclusion::CONTRAINTE_PHIINFSOLIDE; }
	  | CMEMPHI       { $$ = RegleExclusion::CONTRAINTE_MEMEPHI;       }
;
Deplacement: Depl_IMPOSSIBLE { $$ = RegleExclusion::DEPLIMPOSSIBLE; }
	   | Depl_POSSIBLE   { $$ = RegleExclusion::DEPLPOSSIBLE; } 

%%

/* -------------- body section -------------- */

