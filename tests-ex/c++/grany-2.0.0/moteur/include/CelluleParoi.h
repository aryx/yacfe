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

#ifndef _CELLULEPAROI_H_
#define _CELLULEPAROI_H_




#include "CommunMoteur.h"
#include "CelluleSansParticule.h"

//*******************************************************************************
/** Mod�lisation d'une cellule g�n�ratrice.
 *  Cette classe h�rite de la classe CelluleSansParticule. Elle permet
 *  de pr�ciser le comportement d'une cellule mod�lisant une portion
 *  de paroi ; en fait elle simule la pr�sence en son sein d'une particule
 *  totalement immobile, de \latexonly $\phi$ \endlatexonly nul.
 *******************************************************************************/

class CelluleParoi : public CelluleSansParticule {


public:

  virtual CelluleParoi* clone() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Obtention du phi de la particule cens�e se trouver dans la cellule.
  float getPhiParticule() const;

  /// Affiche les attributs priv�s de l'objet.
  void afficheur() const;

  /// Affiche un attribut identifiant l'objet.
  void afficheurReduit() const;

  /// Affiche un caract�re repr�sentant le contenu de la cellule.
  void afficheToi() const;

  /** M�thode pour le GUI.
   */
  int donneTaCouleur() const;

  /// Mise � jour de la couleur commune des cellules Paroi.
  friend void setCouleurParoi(int);

  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  // UGLY je sais pas si ca marche ca
  // ca doit pas je pense
  // faut que l'adresse des fonctions virtuelles 
  // soit les memes !!!!!!!!!!!!!
  virtual ioManager<Cellule>* getIoManager() const
    {
      return (ioManager<Cellule>*) _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<CelluleParoi> *_io;

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

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline CelluleParoi* CelluleParoi::clone() const
{
  return new CelluleParoi(*this);
}

#endif

