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
%name FrontiereScanner

%define LEX_PARAM YY_FrontiereParser_STYPE *val,YY_FrontiereParser_LTYPE *loc
%define IOSTREAM
%define MEMBERS \
   public: \
      int _ligne, _colonne; \
      void beginAction();

%define CONSTRUCTOR_INIT : _ligne(1), _colonne(1)

%header{ 
#include "FrontiereParser.h"

#define YY_USER_ACTION beginAction();
%}

alpha    [A-Za-z]
dig      [0-9]
entier   {dig}+
flottant {dig}+\.{dig}+
num1     [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2     [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number   {num1}|{num2}
name     {alpha}({alpha}|{dig}|([_@]))*
/* -------------- rules section -------------- */

%%
"\n"	      {_ligne++; _colonne=1;}
[\t ]+ ;      /* pour eliminer les blancs */
"#".*         { }
"$FRONTIERE:"  { return FrontiereParser::ENTETEFRONTIERE; }
"POLYGONE"    { return FrontiereParser::POLYGONE; }
"LIGNE"       { return FrontiereParser::LIGNE; }
"RECTANGLE"   { return FrontiereParser::RECTANGLE; }
"ELLIPSE"     { return FrontiereParser::ELLIPSE; }
"ARCELLIPSE"  { return FrontiereParser::ARCELLIPSE; }
"CLASSIQUE"   { return FrontiereParser::CLASSIQUE; }
"GENERATRICE" { return FrontiereParser::GENERATRICE; }
{entier}      { val->entier=atoi((const char*) yytext); return FrontiereParser::NBR; }
{name}        { cerr << "non reconnu\n" << yytext; }
[;,()]        { return yytext[0]; }
.             { return FrontiereParser::TOK_BAD ;}
%%

/* -------------- body section -------------- */
void FrontiereScanner::beginAction()
{
  _colonne += yyleng;
  DEBUG_COMPILER(cerr << "Lexex:" << yytext << endl);
};
