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
%name FrontiereParser

/* sinon il me fait chier */
%define LSP_NEEDED

%define ERROR_BODY =0
%define LEX_BODY =0
// gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
%define LTYPE yyltype1
%define MEMBERS \
   public: \
      list<Frontiere*> *_listFrontiere;

%header{
#include "CommunFichiers.h"

#include "Figures.h"

#include "Frontiere.h"

#include <list>
  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype1
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype1;

%}

/* -------------- union section -------------- */

%union {
  int                  entier;

  Frontiere::TypeParoi typ;
  Forme                *forme;
  list<Frontiere*>*  vecfront;
  Frontiere*           front;
  Ligne*               ligne;
  list<Ligne*>*      vecligne;
}

/* -------------- token section -------------- */
%token CLASSIQUE GENERATRICE ENTETEFRONTIERE
%token LIGNE RECTANGLE ELLIPSE ARCELLIPSE POLYGONE
%token NBR
%token TOK_BAD

/* -------------- type section -------------- */
%type <entier>   NBR

%type <typ>      Type
%type <forme>    Forme
%type <vecfront> Frontieres
%type <front>    Frontiere
%type <ligne>    Ligne
%type <vecligne> Lignes


/* -------------- rules section -------------- */
%%
file: ENTETEFRONTIERE Frontieres { _listFrontiere = $2 ;}



/* -------- pure parser ---------- */
/* TOEXPLAIN comment ca marche*/
Frontieres: Frontieres Frontiere { ($1)->push_back($2); $$ = $1; }
          | Frontiere { list<Frontiere*>* vectmp = new list<Frontiere*>; vectmp->push_back($1); $$ = vectmp; }
;

Frontiere: Forme ',' Type ';' { $$ = new Frontiere($1, $3) ;}
;

Forme: POLYGONE '(' Lignes ')' 
                      { $$ = new Polygone(*$3); delete $3 } 
     | LIGNE '(' NBR ',' NBR ',' NBR ',' NBR ')' 
                      { $$ = new Ligne($3,$5,$7,$9); }
     | RECTANGLE '(' NBR ',' NBR ',' NBR ',' NBR ')'
                      { $$ = new Rectangle($3,$5,$7,$9); }
     | ELLIPSE '(' NBR ',' NBR ',' NBR ',' NBR ')' 
                      { $$ = new Ellipse($3,$5,$7,$9); }
     | ARCELLIPSE '(' NBR ',' NBR ',' NBR ',' NBR ',' NBR ',' NBR ',' NBR ',' NBR ')' 
                      { $$ = new ArcEllipse($3,$5,$7,$9,$11,$13,$15,$17); }

;

Lignes: Lignes ',' Ligne { ($1)->push_back($3); $$ = $1; }
      | Ligne { list<Ligne*>* vectmp = new list<Ligne*>; vectmp->push_back($1); $$ = vectmp; }

;
Ligne: LIGNE '(' NBR ',' NBR ',' NBR ',' NBR ')' 
                  {$$ = new Ligne($3,$5,$7,$9);}
;

Type: CLASSIQUE   { $$ = Frontiere::CLASSIQUE; }
    | GENERATRICE { $$ = Frontiere::GENERATRICE; }

;

%%

/* -------------- body section -------------- */
