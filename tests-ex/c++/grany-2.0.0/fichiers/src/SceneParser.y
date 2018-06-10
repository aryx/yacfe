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
%name SceneParser

/* sinon il me fait chier */
%define LSP_NEEDED

%define ERROR_BODY =0

%define LTYPE yyltype3

%define LEX_BODY =0
//%define CONSTRUCTOR_CODE cerr << "toto\n";
%define MEMBERS \
   public: \
	 Scene * _scene; \
     private: \
     RegleExclusion* recherchePtrRegle(string nom); \
     Phase * recherchePtrPhase(string nomPhase); \
     list<RegleExclusion*>* listregles; \
     list<Phase*>* listphases;


%header{
#include "CommunFichiers.h"

#include "Figures.h"

#include "Couleur.h"
#include "Frontiere.h"
#include "RegleExclusion.h"
#include "Phase.h"

#include "Zonage.h"
#include "ContenuZonage.h"
#include "ContientPhase.h"
#include "ContientHorsScene.h"
#include "PhasePourcent.h"

#include "Coloration.h"

#include "Scene.h"

  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype3
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype3;

%}

/* -------------- union section -------------- */

%union {
  int    entier;
  float  reel;
  char*  Nom;
  bool   Bool;

  /* Frontiere */
  Frontiere::TypeParoi typ;
  Forme*               forme;
  list<Frontiere*>*    vecfront;
  Frontiere*           front;
  Ligne*               ligne;
  list<Ligne*>*        vecligne;

  /* Regle */
  RegleExclusion::Contrainte  contr;
  RegleExclusion::Deplacement depl;
  RegleExclusion*             regle;


  /* Rajout */
  list<RegleExclusion*>* vecregle;

  Couleur*               couleur;
  list<Couleur*>*        veccoul;

  Phase*                 phase;
  list<Phase*>*          vecphase;

  Phase::RegleEtMode     regleEtMode;
  list<Phase::RegleEtMode>* vecRegleEtMode;

  RegleExclusion::ModeExclusion modeExclusion;

  Zonage*                zonage;
  list<Zonage*>*         veczonage;
  FormeFermee*           formefermee;
  ContenuZonage*         contenuZonage;
  
  PhasePourcent          phasePourcent;
  vector<PhasePourcent>*   vecPhasePourcent;

  Coloration*            coloration;
  list<Coloration*>*     vecColoration;
  
}

/* -------------- token section -------------- */

%token ENTETEFRONTIERE ENTETEREGLES ENTETECOLORMAP ENTETEPHASES ENTETEZONAGE ENTETECOLORATION

/* Frontiere */
%token POLYGONE LIGNE RECTANGLE ELLIPSE ARCELLIPSE
%token CLASSIQUE GENERATRICE

/* Regles */
%token CNULLE CMEMPHI CPHIINFERIEUR CPHIINFSOLIDE
%token Depl_IMPOSSIBLE Depl_POSSIBLE

%token STRINGNOM PHI POND COUL INERTIE REGLES
%token PROPAG PREEXCLUSION POSTEXCLUSION VRAI FAUX HS 

%token NOM NBRREEL NBR 
%token TOK_BAD

%token TYPEGENERATRICE
/* -------------- type section -------------- */

%type <entier> NBR ;
%type <reel> NBRREEL ;
%type <Nom> NOM;
%type <Bool> Booleen; 

/* Frontiere */
%type <typ>      Type
%type <forme>    Forme
%type <vecfront> Frontieres
%type <front>    Frontiere
%type <ligne>    Ligne
%type <vecligne> Lignes 

/* Regle */
%type <contr> Contrainte
%type <depl>  Deplacement
%type <regle> Regle

/* Rajout */
%type <vecfront> FrontiereSection
%type <vecregle> Regles RegleSection

%type <couleur> Couleur
%type <veccoul> ColorMapSection Couleurs

%type <phase>   Phase
%type <vecphase> PhaseSection Phases 

%type <regleEtMode> NomRegle
%type <vecRegleEtMode> NomRegles

%type <modeExclusion> PrePost

%type <zonage>   Zone
%type <veczonage> ZonageSection Zones 
%type <formefermee> FormeFermee
%type <contenuZonage> TypeZone

%type <phasePourcent> NomPhase
%type <vecPhasePourcent> NomPhases

%type <coloration> Color
%type <vecColoration> Colors ColorationSection

%type <phase> TypeGeneratriceSection

/* -------------- rules section -------------- */
%%


Scene: FrontiereSection 
       RegleSection 
       ColorMapSection 
       PhaseSection 
       ZonageSection 
       ColorationSection 
       TypeGeneratriceSection
        { 
	  _scene = new Scene(*$1, *$2, *$3, *$4, *$5, *$6, $7); 
	  delete $1; delete $2; delete $3; delete $4; delete $5; delete $6; }
;


/* -------- semi pure global parser ---------- */

/************** Section de la frontiere *********************************************/
FrontiereSection: ENTETEFRONTIERE Frontieres { $$ = $2; }
;

/* From FrontiereParser.y without change */
/* -------- pure parser ---------- */
Frontieres: Frontieres Frontiere { ($1)->push_back($2); $$ = $1;}
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


/************** Section des regles *********************************************/
RegleSection: ENTETEREGLES Regles { $$ = $2; /* side effect */ listregles = $2;}
            | ENTETEREGLES        { $$ = new list<RegleExclusion*>; listregles = $$;}
Regles: Regles Regle { ($1)->push_back($2); $$ = $1; }
	| Regle { list<RegleExclusion*>* vectmp = new list<RegleExclusion*>; vectmp->push_back($1); $$ = vectmp; }

/* From RegleParser.y without change */
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

Contrainte: CPHIINFERIEUR   { $$ = RegleExclusion::CONTRAINTE_PHIINFERIEUR; }
	    | CNULLE        { $$ = RegleExclusion::CONTRAINTE_NULLE; } 
	    | CPHIINFSOLIDE { $$ = RegleExclusion::CONTRAINTE_PHIINFSOLIDE; }
	    | CMEMPHI       { $$ = RegleExclusion::CONTRAINTE_MEMEPHI;       }
;
Deplacement: Depl_IMPOSSIBLE { $$ = RegleExclusion::DEPLIMPOSSIBLE; }
	     | Depl_POSSIBLE { $$ = RegleExclusion::DEPLPOSSIBLE; } 
;

/************** Section des colormap *********************************************/


ColorMapSection: ENTETECOLORMAP '(' Couleurs ')' ';' { $$ = $3; }
;

Couleurs: Couleurs ',' Couleur { ($1)->push_back($3); $$ = $1; }
        | Couleur { list<Couleur*>* vectmp = new list<Couleur*>; vectmp->push_back($1); $$ = vectmp; }

Couleur: '(' NBR ',' NBR ',' NBR ',' NBR ')'
        { $$ = new Couleur($2, $4, $6, $8); }

;

/************** Section des phases *********************************************/

PhaseSection: ENTETEPHASES Phases { $$ = $2; /* side effect */ listphases = $2;}
;

Phases: Phases Phase { ($1)->push_back($2); $$ = $1; }
      | Phase { list<Phase*>* vectmp = new list<Phase*>; vectmp->push_back($1); $$ = vectmp; }
;
Phase: STRINGNOM '=' NOM ','
       PHI       '=' NBRREEL ',' 
       POND      '=' '(' NBR ',' NBR ',' NBR ',' NBR ',' NBR ',' NBR ')' ','
       COUL      '=' NBR ','
       REGLES    '=' '(' NomRegles ')' ',' 
       INERTIE   '=' NBR ','
       PROPAG    '=' Booleen ';' 
	  { 
	    int tabPond[6] = {$12,$14,$16,$18,$20,$22};
	    $$ = new Phase($3, $7, $41, $37, Ponderation(tabPond) ,*($32));
	    $$->setCouleur($27);
	    delete $32; // plus besoin
			   
	  } 
;

NomRegles: NomRegles ',' NomRegle { ($1)->push_back($3); $$ = $1; }
         | NomRegle { list<Phase::RegleEtMode>* vectmp = new list<Phase::RegleEtMode>; vectmp->push_back($1); $$ = vectmp; }
         | /* vide */ { list<Phase::RegleEtMode>* vectmp = new list<Phase::RegleEtMode>; $$ = vectmp; }
NomRegle: '(' NOM ',' PrePost ')' 
           { 
	     RegleExclusion* tmpRegle = recherchePtrRegle($2);
	     $$.mode = $4;
	     $$.regle = tmpRegle;
	   }
;

PrePost: PREEXCLUSION  { $$ = RegleExclusion::PRE  ;}
       | POSTEXCLUSION { $$ = RegleExclusion::POST ;}
;

Booleen: VRAI { $$ = true; }
       | FAUX { $$ = false; }
;

/************** Section du Zonage *********************************************/

ZonageSection: ENTETEZONAGE Zones { $$ = $2; }
;

Zones: Zones Zone { ($1)->push_back($2); $$ = $1; }
     | Zone { list<Zonage*>* vectmp = new list<Zonage*>; vectmp->push_back($1); $$ = vectmp; }
;

Zone: FormeFermee ',' TypeZone ';' { $$ = new Zonage($1, $3); }
;

FormeFermee: POLYGONE '(' Lignes ')' 
                      { $$ = new Polygone(*$3); delete $3} 
     | RECTANGLE '(' NBR ',' NBR ',' NBR ',' NBR ')'
                      { $$ = new Rectangle($3,$5,$7,$9); }
     | ELLIPSE '(' NBR ',' NBR ',' NBR ',' NBR ')' 
                      { $$ = new Ellipse($3,$5,$7,$9); }

;

TypeZone: HS { $$ = new ContientHorsScene(); }
        | '(' NomPhases ')'  { $$ = new ContientPhase(*($2)); delete $2; /* plus besoin */ }
;

NomPhases: NomPhases ',' NomPhase { ($1)->push_back($3); $$ = $1; }
         | NomPhase { vector<PhasePourcent>* vectmp = new vector<PhasePourcent>; vectmp->push_back($1); $$ = vectmp; }
;

NomPhase: '(' NOM ',' NBRREEL ')'
           { 
	     Phase* phase = recherchePtrPhase($2);
	     $$.phase = phase;
	     $$.pourcentage = $4;
	   }
        | '(' NOM ',' NBR ')'
           { 
	     Phase* phase = recherchePtrPhase($2);
	     $$.phase = phase;
	     $$.pourcentage = $4;
	   }

;

/************** Section de la coloration *********************************************/

ColorationSection: ENTETECOLORATION Colors { $$ = $2; }
                 | ENTETECOLORATION /* vide */ { $$ = new list<Coloration*>;}
;
Colors: Colors Color { ($1)->push_back($2); $$ = $1; }
      | Color { list<Coloration*>* vectmp = new list<Coloration*>; vectmp->push_back($1); $$ = vectmp; }
;


Color: FormeFermee ',' NBR ';' { $$ = new Coloration($1, $3); }
;


/************** Section du type de la phase de la generatrice ****************************/

TypeGeneratriceSection: TYPEGENERATRICE NOM { $$ = recherchePtrPhase($2);}
                      | /* vide */          { $$ = NULL; }

%%

RegleExclusion * SceneParser::recherchePtrRegle(string nomRegle)
{
    list<RegleExclusion*>::iterator it_regles;
    
    for (it_regles = listregles->begin(); it_regles != listregles->end(); it_regles++)
      if ((*it_regles)->getNom() == nomRegle) return (*it_regles) ;

    cerr << "recherchePtrRegle: Regle non connue" << endl;
    return NULL;
}

Phase * SceneParser::recherchePtrPhase(string nomPhase)
{

    list<Phase*>::iterator it_phases ;

    for (it_phases = listphases->begin(); it_phases != listphases->end(); it_phases++)
      if ((*it_phases)->getNom() == nomPhase) return (*it_phases) ;

    cerr << "recherchePtrPhase: Phase non connue" << endl;
    return NULL;
}

