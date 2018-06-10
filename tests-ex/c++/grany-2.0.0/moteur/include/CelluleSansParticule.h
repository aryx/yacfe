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
/** Modélisation d'une cellule sans particule.
 *  Cette classe hérite de la classe Cellule. Elle permet
 *  de préciser le comportement commun des cellules sans particules,
 *  mais n'est pas instanciable. On fera hériter de CelluleSansParticule, les
 *  classes CelluleParoi et CelluleHorsScene.
 *
 *  Il existe des méthodes dans cette classe qui sont censées porter sur
 *  des cellules avec particules. Leur définition a été remontée dans la
 *  classe Cellule, et leur implémentation dans la classe
 *  CelluleSansParticule soit n'effectuera aucune opération, soit lèvera
 *  une exception ; ceci afin de pouvoir appeller ces méthodes directement
 *  sur les éléments d'une liste de Cellule, sans se soucier de quelle
 *  Cellule il s'agit.
 *******************************************************************************/

class CelluleSansParticule : public Cellule {

public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  class Exception {
  public:
    /** Exception levée lorsque l'on essaie d'exécuter une méthode portant exclusivement
     *  sur les cellules avec particules.
     */
    Exception(string message);
  };


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Calcul de la requête associée.
  void calculerRequete();

  /// Activation de l'échange de particules.
  void activerEchange();

  /// Obtention de la requête précédemment calculée.
  Requete getRequete() const;

  /// Activation de la particule théoriquementcontenue dans la cellule.
  void activer();

  /// Obtention de l'activité de la particule contenue dans la cellule.
  bool getActivite() const;

  /// Théoriquement, correspond à l'échange de particules.
  Particule * echangeParticule(Particule * part);

  virtual Particule * getParticule() const;

  /// Obtention du \latexonly $\phi$ \endlatexonly de la particule censée se trouver dans la cellule.
  virtual float getPhiParticule() const = 0;

  /// Affiche les attributs privés de l'objet.
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

