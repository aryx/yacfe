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
%name SimulScanner

%define LEX_PARAM YY_SimulParser_STYPE *val,YY_SimulParser_LTYPE *loc
%define IOSTREAM
%define MEMBERS \
   public: \
      int _ligne, _colonne; \
      void beginAction();

%define CONSTRUCTOR_INIT : _ligne(1), _colonne(1)

%header{ 
#include "SimulParser.h"

#define YY_USER_ACTION beginAction();
%}

alpha    [A-Za-z]
dig      [0-9]
entier   {dig}+
flottant {dig}+\.{dig}+
num1     [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2     [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number   {num1}|{num2}
name     {alpha}({alpha}|{dig}|([-+#._@!]))*


/* -------------- rules section -------------- */

%%
"\n"	                   { _ligne++; _colonne=1;}
[\t ]+                     { /* pour eliminer les blancs */ }
"#".*                      { }
"$PARAMETRES:"             { return SimulParser::ENTETEPARAMETRES; }
"$REGLES:"                 { return SimulParser::ENTETEREGLES; }
"$COLORMAP:"               { return SimulParser::ENTETECOLORMAP; }
"$PHASES:"                 { return SimulParser::ENTETEPHASES; }
"$LOCALISATION:"           { return SimulParser::ENTETELOCALISATION; }

"NBPAS"                    { return SimulParser::NBPAS; }
"FREQAFF"                  { return SimulParser::FREQAFF; }
"DIM"                      { return SimulParser::DIM; }
"GERME"                    { return SimulParser::GERME; }

"Contrainte_NULLE"         { return SimulParser::CNULLE; }
"Contrainte_MEMEPHI"       { return SimulParser::CMEMPHI; }
"Contrainte_PHIINFSOLIDE"  { return SimulParser::CPHIINFSOLIDE; }
"Contrainte_PHIINFERIEUR"  { return SimulParser::CPHIINFERIEUR; }
"Depl_POSSIBLE"            { return SimulParser::Depl_POSSIBLE; }
"Depl_IMPOSSIBLE"          { return SimulParser::Depl_IMPOSSIBLE; }

"NOM"                      { return SimulParser::STRINGNOM; }
"PHI"                      { return SimulParser::PHI; }
"POND"                     { return SimulParser::POND; }
"COUL"                     { return SimulParser::COUL; }
"INERTIE"                  { return SimulParser::INERTIE; }
"PROPAG"                   { return SimulParser::PROPAG; }
"PRE"                      { return SimulParser::PREEXCLUSION; }
"POST"                     { return SimulParser::POSTEXCLUSION; }
"VRAI"                     { return SimulParser::VRAI; }
"FAUX"                     { return SimulParser::FAUX; }
"REGLES"                   { return SimulParser::REGLES; }

"HS"                       { return SimulParser::HS; }
"CP"                       { return SimulParser::CP; }
"CG"                       { return SimulParser::CG; }
"C"                        { return SimulParser::C; }

"NC"                       { return SimulParser::CNC; }
"N"                        { return SimulParser::CN; }
"S"                        { return SimulParser::CS; }
"NE"                       { return SimulParser::CNE; }
"NO"                       { return SimulParser::CNO; }
"SE"                       { return SimulParser::CSE; }
"SO"                       { return SimulParser::CSO; }

{entier}                   { val->entier=atoi((const char*) yytext); return SimulParser::NBR; }
{flottant}                 { val->reel=atof((const char *)yytext);   return SimulParser::NBRREEL; }
{name}                     { val->Nom = strdup((const char*)yytext); return SimulParser::NOM; }
[;,()=]                    { return yytext[0]; }
.                          { return SimulParser::TOK_BAD ;}
%%


/* -------------- body section -------------- */
void SimulScanner::beginAction()
{
  _colonne += yyleng; 
  DEBUG_COMPILER(cerr << "Lexex:" << yytext << endl);
};
