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

#include "FrontiereCompiler.h"


int FrontiereCompiler::yylex()
{
 yylloc.first_line=_scanner._ligne;
 yylloc.first_column=_scanner._colonne;

 int token=_scanner.yylex(&yylval,&yylloc);

 yylloc.last_line=_scanner._ligne;
 yylloc.last_column=_scanner._colonne;
 yylloc.text=(char *)_scanner.yytext;

 return token;
}

void FrontiereCompiler::yyerror(char *m)
{
  /* Quoted out for nicer output. (it's not nice to have that)

  cerr << (int)yylloc.first_line 
       <<": "
       << m
       <<" at token '"
       <<(char *)yylloc.text
       <<"'"
       <<endl;
  */

  /* Quoted out because the exceptions won't work because of gtkmm :-((
     Read gtkmm.faq.sgml if interested.

  throw Exception("Parse Error in FrontiereCompiler\n");
  */
}

list<Frontiere*>* FrontiereCompiler::parseStream(istream& is)
{
  _scanner.yyin = &is;
  yyparse();
  
  return _listFrontiere;
}

int FrontiereCompiler::parseStreamWithResults(istream& is, list<Frontiere*>** lis)
{
  _scanner.yyin = &is;

  int results = yyparse();

  *lis = _listFrontiere;

  return results;
}


list<Frontiere*>* FrontiereCompiler::parseFichier(string nom_fichier)
{
  std::ifstream filestream(nom_fichier.c_str());

  if (!filestream)
    {
	throw Exception("peut pas ouvrir le fichier\n");
    }
  
  _scanner.yyin = &filestream;
  return parseStream(filestream);

}


