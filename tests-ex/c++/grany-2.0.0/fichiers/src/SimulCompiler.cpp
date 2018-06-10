/*******************************************************************************
 *
 * Copyright (C) 1999-2000 by Y. Padioleau, G. Cottenceau, P. Garcia,
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

#include "SimulCompiler.h"


int SimulCompiler::yylex()
{
 yylloc.first_line=_scanner._ligne;
 yylloc.first_column=_scanner._colonne;

 int token=_scanner.yylex(&yylval,&yylloc);

 yylloc.last_line=_scanner._ligne;
 yylloc.last_column=_scanner._colonne;
 yylloc.text=(char *)_scanner.yytext;

 return token;
}

void SimulCompiler::yyerror(char *m)
{ 
  /*  cerr << (int)yylloc.first_line 
       <<": "
       << m
       <<" at token '"
       <<(char *)yylloc.text
       <<"'"
       <<endl;
  throw Exception("Parse Error\n");
  */
}

Automate* SimulCompiler::parseStream(istream& is)
{
  _scanner.yyin = &is;
  yyparse();
  
  return _automate;
  
}

int SimulCompiler::parseStreamWithResults(istream& is, Automate** autom)
{
  _scanner.yyin = &is;

  int results = yyparse();

  *autom = _automate;
  
  return results;
}


Automate * SimulCompiler::parseFichier(string nom_fichier)
{
  std::ifstream filestream(nom_fichier.c_str());

  if (!filestream)
    {
	throw Exception("peut pas ouvir le fichier\n");
    }

  return parseStream(filestream);
}


