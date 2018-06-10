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

#ifndef _CELLULESANSPARTICULE_H_
#define _CELLULESANSPARTICULE_H_



#include "CommunMoteur.h"
#include "Cellule.h"

//*******************************************************************************
/** Mod�lisation d'une cellule sans particule.
 *  Cette classe h�rite de la classe Cellule. Elle permet
 *  de pr�ciser le comportement commun des cellules sans particules,
 *  mais n'est pas instanciable. On fera h�riter de CelluleSansParticule, les
 *  classes CelluleParoi et CelluleHorsScene.
 *
 *  Il existe des m�thodes dans cette classe qui sont cens�es porter sur
 *  des cellules avec particules. Leur d�finition a �t� remont�e dans la
 *  classe Cellule, et leur impl�mentation dans la classe
 *  CelluleSansParticule soit n'effectuera aucune op�ration, soit l�vera
 *  une exception ; ceci afin de pouvoir appeller ces m�thodes directement
 *  sur les �l�ments d'une liste de Cellule, sans se soucier de quelle
 *  Cellule il s'agit.
 *******************************************************************************/

class CelluleSansParticule : public Cellule {

public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  class Exception {
  public:
    /** Exception lev�e lorsque l'on essaie d'ex�cuter une m�thode portant exclusivement
     *  sur les cellules avec particules.
     */
    Exception(string message);
  };


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Calcul de la requ�te associ�e.
  void calculerRequete();

  /// Activation de l'�change de particules.
  void activerEchange();

  /// Obtention de la requ�te pr�c�demment calcul�e.
  Requete getRequete() const;

  /// Activation de la particule th�oriquementcontenue dans la cellule.
  void activer();

  /// Obtention de l'activit� de la particule contenue dans la cellule.
  bool getActivite() const;

  /// Th�oriquement, correspond � l'�change de particules.
  Particule * echangeParticule(Particule * part);

  virtual Particule * getParticule() const;

  /// Obtention du \latexonly $\phi$ \endlatexonly de la particule cens�e se trouver dans la cellule.
  virtual float getPhiParticule() const = 0;

  /// Affiche les attributs priv�s de l'objet.
  void afficheur() const;

  /// Affiche un attribut identifiant l'objet.
  void afficheurReduit() const;

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
 *  
 ******************************************************************************/
inline CelluleSansParticule::Exception::Exception(string message)
{
  DEBUG_MOTEUR(cerr << "[Exception] " << message << endl;)
}

inline Particule* CelluleSansParticule::getParticule() const
{
  throw CelluleSansParticule::Exception("cellule sans particule"); 
}

#endif

