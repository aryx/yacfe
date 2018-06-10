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

#ifndef _IOMANAGER_H_
#define _IOMANAGER_H_

#include <string>
#include <iostream>
using namespace std;

template <class T> class ioManager {
public:

  // il va mettre a jour le pointeur.
  ioManager()
    {
      T::_io = this;
    }

  // il l'enleve.
  virtual ~ioManager() 
    {
      T::_io = NULL;
    }


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


  virtual T* lire(istream&) {throw Exception("Lecture non autorisé");}
  virtual void ecrire(const T&,ostream&) const {throw Exception("Ecriture non autorisé");}
  
  
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
template <class T>  ioManager<T>::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

#endif
