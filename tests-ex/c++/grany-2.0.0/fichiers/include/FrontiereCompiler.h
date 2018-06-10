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

#ifndef _FRONTIERECOMPILER_H_
#define _FRONTIERECOMPILER_H_

#include "FrontiereScanner.h"
#include "FrontiereParser.h"

#include <iostream>
#include <fstream>


class FrontiereCompiler : public FrontiereParser
{
public:

  virtual ~FrontiereCompiler() {}; // sinon warning 
  int yylex();
  void yyerror(char *m);

  list<Frontiere*> * parseFichier(string nom_fichier);
  list<Frontiere*> * parseStream(istream& is);
  int parseStreamWithResults(istream&, list<Frontiere*>**);

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception levée lorsque l'on essaie de rotate de plus de 6 (ou moins de 0)
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception(string message);
  };


private:
  FrontiereScanner _scanner;
  
};


//##############################################################################
//##############################################################################
//##############################################################################
// METHODES INLINES
//##############################################################################
//##############################################################################
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exceptions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  Il affiche sur la canal d'erreur la chaine [EXCEPTION] puis
 *  la chaine contenue dans la variable message.
 *
 ******************************************************************************/
inline FrontiereCompiler::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

#endif
