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

#ifndef _FRONTIERE_H_
#define _FRONTIERE_H_

#include "CommunScene.h"


//****************************************************************************
/** Représente une frontiere de l'automate.
 *  Il est composé d'un ensemble de formes, et d'un type de paroi.
 ****************************************************************************/
 

class Frontiere {
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Symboles/Enum
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  enum TypeParoi {
    CLASSIQUE,   /**< Paroi classique.   */
    GENERATRICE  /**< Paroi génératrice. */
  };

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir d'une forme et d'un type de paroi.
  Frontiere(Forme * f,TypeParoi typ = CLASSIQUE): _forme(f), _type(typ) {}

  /// Destructeur.
  virtual ~Frontiere(){delete _forme;}


  virtual Frontiere* clone() const
    {
      return new Frontiere(_forme->clone(),_type);
    }

  Forme * getForme()  const { return _forme ; }

  
  void setParoi(TypeParoi typ) {_type = typ;}
  TypeParoi getTypeParoi()  const { return _type; }


  void afficheur() const
    {
      cerr << "Frontiere" << endl;
      cerr << "Forme:" << endl;
      _forme->afficheur();
      cerr << "type:" << endl;
      if (_type == CLASSIQUE) cerr << "CLASSIQUE" ;
      else cerr << "GENERATRICE" ;
      cerr << endl;

    }
private:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
  // Attributs privés
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Représente une formes constituante de la frontière.
  Forme * _forme;
  TypeParoi _type;

};

#endif

 
