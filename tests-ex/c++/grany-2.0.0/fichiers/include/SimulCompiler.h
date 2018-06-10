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

#ifndef _SIMULCOMPILER_H_
#define _SIMULCOMPILER_H_

#include "SimulScanner.h"
#include "SimulParser.h"

#include <iostream>
#include <fstream>


class SimulCompiler : public SimulParser
{
public:

  virtual ~SimulCompiler() {}; // sinon warning 
  int yylex();
  void yyerror(char *m);

  Automate* parseFichier(string nom_fichier);
  Automate* parseStream(istream& is);
  int parseStreamWithResults(istream& is, Automate**);

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
  SimulScanner _scanner;
  
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
inline SimulCompiler::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

#endif
