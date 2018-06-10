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

#ifndef _CELLULEGENERATRICE_H_
#define _CELLULEGENERATRICE_H_


#include "CommunMoteur.h"
#include "CelluleAvecParticule.h"

//*******************************************************************************
/** Modélisation d'une cellule génératrice.
 *  Cette classe hérite de la classe CelluleAvecParticule. Elle permet
 *  de redéfinir le comportement de certaines méthodes afin de prendre en
 *  compte la possibilité de générer une nouvelle particule à l'intérieur
 *  de la cellule considérée, en remplacement d'une particule qu'elle
 *  accueille.
 *******************************************************************************/

class CelluleGeneratrice : public CelluleAvecParticule
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir de la particule que contiendra la cellule, et de la phase utilisée pour générer de nouvelles particules.
  CelluleGeneratrice(Particule* part, Phase* phase);


  virtual CelluleGeneratrice* clone() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  /// Activation de l'échange de particules.
  void activerEchange();

  /// Echange effectif de particules.
  Particule* echangeParticule(Particule* part1);

  /// Obtention de la phase générée.
  Phase * getPhaseGeneree() const;

  /// Obtention de la phase générée.
  void setPhaseGeneree(Phase* phase)
    {
      _phaseGeneree = phase;
    }

  /// Mise à jour du pointeur vers automate.
  void setAutomate(Automate* aut);

  Automate* getAutomate() const ;

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
  static ioManager<CelluleGeneratrice> *_io;

  /// Méthode utilisée pour pouvoir debugger le code.
  virtual void afficheur() const;


private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Méthodes privées
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Crée la nouvelle particule générée.
  void creeNouvelleParticuleGeneree();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Lien vers la phase générée.
  Phase* _phaseGeneree;

  /// Pointeur vers l'automate.
  Automate *_automate;
  
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
 *  
 ******************************************************************************/
inline CelluleGeneratrice::CelluleGeneratrice(Particule * part,Phase * phase) :

  CelluleAvecParticule(part)
{
  _phaseGeneree = phase;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline Phase * CelluleGeneratrice::getPhaseGeneree() const
{
  return _phaseGeneree;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void CelluleGeneratrice::setAutomate(Automate* aut)
{
  _automate = aut;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline Automate* CelluleGeneratrice::getAutomate() const
{
  return _automate;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline CelluleGeneratrice* CelluleGeneratrice::clone() const
{
  return new CelluleGeneratrice(*this);
}

#endif



