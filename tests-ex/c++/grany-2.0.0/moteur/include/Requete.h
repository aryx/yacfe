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

#ifndef _REQUETE_H
#define _REQUETE_H

#include "CommunMoteur.h"
#include <string>

//*******************************************************************************
/** Type pouvant prendre une valeur cardinale plus la valeur RIEN.
 *  Pour les mêmes raisons qui nous ont poussées à créer un objet Direction,
 *  on crée un objet Requete. En effet plusieurs fonctions prennent en paramètres
 *  des requêtes et s'attendent à recevoir un objet Requete valide.
 *
 *******************************************************************************/

class Requete
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur par défaut.
  Requete();
  /// Constructeur à partir d'un ::EnumDirectionRequete.
  Requete(EnumDirectionRequete req);
  /// Constructeur à partir d'un entier.
  Requete(int i);

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Opérateurs
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Opérateur de cast vers int.
  operator int() const; 

  /// Opérateur de comparaison égale.
  friend bool operator==(const Requete &req1, const Requete &req2);
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception levée lorsque l'on essaie de construire un objet Requete invalide.
   *  Il n'est pas valide de construire un objet Requete ayant pour 
   *  valeur autre chose que RIEN ou une valeur cardinale.
   */
  class Exception{
  public:
    /// Le constructeur
    Exception();
  };

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Retourne vrai si les requêtes ont des directions opposées.
  friend bool requeteEnAccord(const Requete &req1,const Requete &req2);

  /// Retourne la requete en accord
  Requete requeteAccordee() const;

  /// Affiche les attributs privés de l'objet.
  void afficheur() const;

private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /// Valeur de la requête.
  EnumDirectionRequete _requete; 

};

//##############################################################################
//##############################################################################
//##############################################################################
// METHODES INLINES
//##############################################################################
//##############################################################################
//##############################################################################

//##############################################################################
// Public members
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructeurs/Destructeur
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  La valeur construite par défaut est la valeur RIEN.
 ******************************************************************************/
inline Requete::Requete()
{
  _requete = RIEN;
}

//******************************************************************************
/** Description.
 *  \param req contrairement à Direction::Direction(EnumDirectionRequete dir) tout symbole
 *  de EnumDirectionRequete est valide.
 ******************************************************************************/
inline Requete::Requete(EnumDirectionRequete req)
{
  _requete = req;
}

//******************************************************************************
/** Description.
 *  \param i si i > VALENCE ou < 0 alors une 
 *  exception est levée.
 *  \exception Exception
 ******************************************************************************/
inline Requete::Requete(int i)
{
#ifdef DEBUG_EXCEPTION
  if ((i < 0) || (i > VALENCE))
    throw Exception();
  else 
#endif
    _requete = EnumDirectionRequete(i);
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Opérateurs
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline bool operator==(const Requete &req1, const Requete &req2)
{
  return req1._requete == req2._requete;
}



//******************************************************************************
/** Description.
 *  Il permet de transformer facilement un objet Requete en un objet Direction et 
 *  vice-versa.
 *  En effet en écrivant :
 *  \code
 *  dir = Direction(requete);
 *  \endcode
 *  l'objet requête est transformé en int puis passé en paramètre au constructeur
 *  Direction::Direction(int) (qui éventuellement lèvera une exception si requete = RIEN)
 *  puis affecté à l'objet dir.
 ******************************************************************************/
inline Requete::operator int() const
{
  return (int) _requete;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exceptions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  Il affiche sur le canal d'erreur :
 *  \verbatim
 *  [EXCEPTION]: valeur de Requete non compris dans le domaine requete 
 *  \endverbatim
 *
 *
 ******************************************************************************/
inline Requete::Exception::Exception()
{
  cerr << "[EXCEPTION]: valeur de Requete non compris dans le domaine requete " << endl;
}

#endif
