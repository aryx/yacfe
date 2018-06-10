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
%name SceneScanner

%define LEX_PARAM YY_SceneParser_STYPE *val,YY_SceneParser_LTYPE *loc
%define IOSTREAM
%define MEMBERS \
   public: \
      int _ligne, _colonne; \
      void beginAction();

%define CONSTRUCTOR_INIT : _ligne(1), _colonne(1)

%header{ 
#include "SceneParser.h"

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
"$FRONTIERE:"              { return SceneParser::ENTETEFRONTIERE;  }
"$REGLES:"                 { return SceneParser::ENTETEREGLES; }
"$COLORMAP:"               { return SceneParser::ENTETECOLORMAP; }
"$PHASES:"                 { return SceneParser::ENTETEPHASES; }
"$ZONAGE:"                 { return SceneParser::ENTETEZONAGE; }
"$COLORATION:"             { return SceneParser::ENTETECOLORATION; }

"POLYGONE"                 { return SceneParser::POLYGONE; }
"LIGNE"                    { return SceneParser::LIGNE; }
"RECTANGLE"                { return SceneParser::RECTANGLE; }
"ELLIPSE"                  { return SceneParser::ELLIPSE; }
"ARCELLIPSE"               { return SceneParser::ARCELLIPSE; }

"CLASSIQUE"                { return SceneParser::CLASSIQUE; }
"GENERATRICE"              { return SceneParser::GENERATRICE; }

"Contrainte_NULLE"         { return SceneParser::CNULLE; }
"Contrainte_MEMEPHI"       { return SceneParser::CMEMPHI; }
"Contrainte_PHIINFSOLIDE"  { return SceneParser::CPHIINFSOLIDE; }
"Contrainte_PHIINFERIEUR"  { return SceneParser::CPHIINFERIEUR; }
"Depl_POSSIBLE"            { return SceneParser::Depl_POSSIBLE; }
"Depl_IMPOSSIBLE"          { return SceneParser::Depl_IMPOSSIBLE; }

"NOM"                      { return SceneParser::STRINGNOM; }
"PHI"                      { return SceneParser::PHI; }
"POND"                     { return SceneParser::POND; }
"COUL"                     { return SceneParser::COUL; }
"INERTIE"                  { return SceneParser::INERTIE; }
"PROPAG"                   { return SceneParser::PROPAG; }
"PRE"                      { return SceneParser::PREEXCLUSION; }
"POST"                     { return SceneParser::POSTEXCLUSION; }
"VRAI"                     { return SceneParser::VRAI; }
"FAUX"                     { return SceneParser::FAUX; }
"HS"                       { return SceneParser::HS; }
"REGLES"                   { return SceneParser::REGLES; }

"$TYPEGENERATRICE:"         { return SceneParser::TYPEGENERATRICE; }
{entier}                   { val->entier=atoi((const char*) yytext); return SceneParser::NBR; }
{flottant}                 { val->reel=atof((const char *)yytext);   return SceneParser::NBRREEL; }
{name}                     { val->Nom = strdup((const char*)yytext); return SceneParser::NOM; }
[;,()=]                    { return yytext[0]; }
.                          { return SceneParser::TOK_BAD ;}
%%


/* -------------- body section -------------- */
void SceneScanner::beginAction()
{
  _colonne += yyleng;
  DEBUG_COMPILER(cerr << "Lexex:" << yytext << endl);
};
