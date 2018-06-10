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
%name SimulParser

/* sinon il me fait chier */
%define LSP_NEEDED

%define ERROR_BODY =0
%define LTYPE yyltype4

%define LEX_BODY =0
//%define CONSTRUCTOR_CODE cerr << "toto\n";
%define MEMBERS \
   public: \
     Automate* _automate; \
     private: \
     RegleExclusion* recherchePtrRegle(string nom); \
     Phase * recherchePtrPhase(string nomPhase); \
     list<RegleExclusion*>* listregles; \
     list<Phase*>* listphases;


%header{
#include "CommunFichiers.h"

#include "RegleExclusion.h"
#include "Automate.h"
#include "Phase.h"
#include "Particule.h"

#include "Cellule.h"
#include "CelluleAvecParticule.h"
#include "CelluleGeneratrice.h"
#include "CelluleHorsScene.h"
#include "CelluleParoi.h"
#include "CelluleSansParticule.h"

#include "Couleur.h"

  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype4
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype4;

%}

/* -------------- union section -------------- */

%union {
  int entier;
  float reel;
  char * Nom;
  bool Bool;

  /* From Scene without Change */ 
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

  Cellule*               cellule;
  Particule*             particule;
  EnumDirectionRequete   dirreq;

}

/* -------------- token section -------------- */

%token ENTETEPARAMETRES ENTETEREGLES ENTETECOLORMAP ENTETEPHASES ENTETELOCALISATION

%token  NBPAS FREQAFF DIM GERME

/* Regles */
%token CNULLE CMEMPHI CPHIINFERIEUR CPHIINFSOLIDE
%token Depl_IMPOSSIBLE Depl_POSSIBLE

%token STRINGNOM PHI POND COUL REGLES INERTIE
%token PROPAG PREEXCLUSION POSTEXCLUSION VRAI FAUX

%token NOM NBRREEL NBR

%token CP CG HS C
%token CNC CN CS CNE CNO CSE CSO

%token TOK_BAD

/* -------------- type section -------------- */

%type <entier> NBR ;
%type <reel> NBRREEL ;
%type <Nom> NOM;
%type <Bool> Booleen; 

/* Regle */
%type <contr> Contrainte
%type <depl>  Deplacement
%type <regle> Regle

/* Rajout */

%type <vecregle> Regles RegleSection

%type <couleur> Couleur
%type <veccoul> ColorMapSection Couleurs

%type <phase>   Phase
%type <vecphase> PhaseSection Phases 

%type <regleEtMode> NomRegle
%type <vecRegleEtMode> NomRegles

%type <modeExclusion> PrePost

%type <entier> NumCouleur ;
%type <cellule> Cellule;
%type <particule> ContenuCellule;
%type <dirreq> Provenance;

/* -------------- rules section -------------- */
%%

Simul: SimulDebut LocalisationSection 
            { 
	      _automate->connecteCellules(); 
	      delete listphases; ; delete listregles; // plus besoin
	      DEBUG_COMPILER(cerr << "Parser:" << "Fin Simul\n";)
            }

SimulDebut:  ENTETEPARAMETRES
                    NBPAS '=' NBR ';'
                    FREQAFF '=' NBR ';'
                    DIM '=' NBR ';'
                    GERME '=' NBR ';'
            RegleSection ColorMapSection PhaseSection 
          {
	    _automate = new Automate($16,$12,$4,$8,*$18,*$19,*$20);
	    delete $19; // delete colormap 
	  }
;

/* -------- semi pure global parser ---------- */

/* From SceneParser.y without change */
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


/************** Section des localisation *********************************************/

LocalisationSection: ENTETELOCALISATION '(' Cellules ')' ';' 
               { DEBUG_COMPILER(cerr << "Parser:" << "Fin Localisation\n";)}
;

Cellules: Cellules ',' Cellule  { _automate->ajoutCellule($3); DEBUG_COMPILER(cerr << "Parser:" << "Ajout Cellule2\n";)}
	| Cellule { _automate->ajoutCellule($1); DEBUG_COMPILER(cerr << "Parser:" << "Ajout Cellule1\n";)}
;

Cellule: HS { $$ = new CelluleHorsScene(); DEBUG_COMPILER(cerr << "Parser:" << "Hs\n";)}
       | CP { $$ = new CelluleParoi(); DEBUG_COMPILER(cerr << "Parser:" << "Cp\n";)}
       | CG ContenuCellule ',' NOM ')' 
            { 
	      Phase* phase = recherchePtrPhase($4);
	      CelluleGeneratrice* cell;
	      cell = new CelluleGeneratrice($2,phase);
	      cell->setAutomate(_automate);
	      $$ = cell;

	    }
       | ContenuCellule ')' { $$ = new CelluleAvecParticule($1); DEBUG_COMPILER(cerr << "Parser:" << "Norm\n";)}
;


ContenuCellule: '(' NBR ',' Provenance ','  NOM ',' NumCouleur
                {
		  DEBUG_COMPILER(cerr << "Parser:" << "Nom =" << $6 << "\n";)
		  Phase * phase = recherchePtrPhase($6);
		  
		  $$ = new Particule($2, phase, NULL, Requete($4), false, $8);
		  _automate->ajoutParticule($$);

		  DEBUG_COMPILER(cerr << "Parser:" << "Fin Contenu\n";)
		    }
;

Provenance: CNC { $$ = RIEN; DEBUG_COMPILER(cerr << "Parser:" << "Provenance NC\n";) } 
	  | CN  { $$ = NORD; DEBUG_COMPILER(cerr << "Parser:" << "Provenance N\n";) }  
	  | CS  { $$ = SUD;  DEBUG_COMPILER(cerr << "Parser:" << "Provenance S\n";) } 
	  | CNE { $$ = NE;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance NE\n";) } 
	  | CNO { $$ = NW;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance NO\n";) } 
	  | CSE { $$ = SE;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance SE\n";) } 
	  | CSO { $$ = SW;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance SO\n";) } 
;

NumCouleur: NBR { $$ = $1; }
;

%%

RegleExclusion * SimulParser::recherchePtrRegle(string nomRegle)
{
    list<RegleExclusion*>::iterator it_regles;
    
    for (it_regles = listregles->begin(); it_regles != listregles->end(); it_regles++)
      if ((*it_regles)->getNom() == nomRegle) return (*it_regles) ;

    cerr << "recherchePtrRegle: Regle non connue" << endl;
    return NULL;
}

Phase * SimulParser::recherchePtrPhase(string nomPhase)
{
    DEBUG_COMPILER(cerr << "recherchePtrPhase:" << "Nom =" << nomPhase << "\n";)
    
    list<Phase*>::iterator it_phases ;

    for (it_phases = listphases->begin(); it_phases != listphases->end(); it_phases++)
      if ((*it_phases)->getNom() == nomPhase) return (*it_phases) ;

    cerr << "recherchePtrPhase: Phase non connue" << endl;
    return NULL;
}



