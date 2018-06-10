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

#ifndef _DIRECTION_H
#define _DIRECTION_H


#include "CommunMoteur.h"

#include <iostream>




//*******************************************************************************
/** Type pouvant prendre une valeur cardinale.
 *  La topologie de l'automate est hexavalente, ce qui implique que l'on manipule
 *  des directions pouvant prendre une valeur parmi l'ensemble :
 *  nord, sud, sud-ouest, sud-est, nord-ouest et nord-est.
 *  On dispose d'un enum ::EnumDirectionRequete qui peut prendre les valeurs 
 *  cardinales plus la valeur RIEN. Le probl�me vient de cette valeur RIEN en trop.
 *  En effet si on met comme argument d'une fonction un type EnumDirectionRequete
 *  et que la fonction n'accepte en fait que des valeurs cardinales, alors on sera
 *  oblig� de placer dans le code de la fonction un test pour savoir si l'argument
 *  est diff�rent de RIEN (si c'est le cas alors on l�vera une exception). 
 *  Il en sera de m�me pour toutes les fonctions voulant prendre en param�tre une
 *  direction ce qui induit une duplication de code importante. L'id�e retenue est
 *  de fournir un objet Direction ne pouvant prendre que des valeurs cardinales.
 *  Si l'utilisateur essaie de construire un objet Direction invalide (en passant
 *  par exemple au constructeur Direction(EnumDirectionRequete) la valeur RIEN)
 *  alors l'exception DirectionException sera lev�e. Ainsi si une fonction prend
 *  en param�tre un objet Direction, elle est assur�e que cet objet Direction a seulement
 *  une valeur cardinale.
 *******************************************************************************/

class Direction
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur par d�faut.
  Direction();
  /// Constructeur � partir d'un ::EnumDirectionRequete.
  Direction(EnumDirectionRequete);
  /// Constructeur � partir d'un entier.
  Direction(int i);

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Op�rateurs
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Op�rateur de cast vers int.
  operator int() const; 


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception lev�e lorsque l'on essaie de construire un objet Direction invalide.
   *  Par exemple, il n'est pas valide de construire un objet Direction ayant pour
   *  valeur RIEN.
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception();
  };

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Retourne vrai si la direction est pr�pond�rante.
  bool estPreponderante() const;

  /// Affiche les attributs priv�s de l'objet.
  void afficheur() const;


private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Valeur de la direction.
  EnumDirectionRequete _direction; // 

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
 *  La valeur construite par d�faut est la valeur NORD (il faut bien en choisir
 *  une).
 ******************************************************************************/
inline Direction::Direction()
{
  _direction = NORD;
}

//******************************************************************************
/** Description.
 *  \param dir si dir est le symbole RIEN alors une exception est lev�e.
 *  \exception Exception
 ******************************************************************************/
inline Direction::Direction(EnumDirectionRequete dir)
{
#ifdef DEBUG_EXCEPTION
  if (dir == RIEN)
    throw Exception();
  else 
#endif
    _direction = dir;
}

//******************************************************************************
/** Description.
 *  \param i si i >= VALENCE ou < 0 alors une 
 *  exception est lev�e.
 *  \exception Exception
 ******************************************************************************/
inline Direction::Direction(int i)
{
#ifdef DEBUG_EXCEPTION
  if ((i < 0) || (i >= VALENCE))
    throw Exception();
  else 
#endif
    _direction = EnumDirectionRequete(i);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Op�rateurs
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  Afin de pouvoir indexer un tableau � partir 
 *  d'un objet Direction, il est n�cessaire de pouvoir le convertir en un entier.
 ******************************************************************************/
inline Direction::operator int() const
{
  return (int) _direction;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exceptions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  Il affiche sur le canal d'erreur :
 *  \verbatim
 *  [EXCEPTION]: valeur de Direction non compris dans le domaine direction 
 *  \endverbatim
 *
 ******************************************************************************/
inline Direction::Exception::Exception()
{
  cerr << "[EXCEPTION]: valeur de Direction non compris dans le domaine direction " << endl;
}

#endif
