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
/** Mod�lisation d'une cellule g�n�ratrice.
 *  Cette classe h�rite de la classe CelluleAvecParticule. Elle permet
 *  de red�finir le comportement de certaines m�thodes afin de prendre en
 *  compte la possibilit� de g�n�rer une nouvelle particule � l'int�rieur
 *  de la cellule consid�r�e, en remplacement d'une particule qu'elle
 *  accueille.
 *******************************************************************************/

class CelluleGeneratrice : public CelluleAvecParticule
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur � partir de la particule que contiendra la cellule, et de la phase utilis�e pour g�n�rer de nouvelles particules.
  CelluleGeneratrice(Particule* part, Phase* phase);


  virtual CelluleGeneratrice* clone() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  /// Activation de l'�change de particules.
  void activerEchange();

  /// Echange effectif de particules.
  Particule* echangeParticule(Particule* part1);

  /// Obtention de la phase g�n�r�e.
  Phase * getPhaseGeneree() const;

  /// Obtention de la phase g�n�r�e.
  void setPhaseGeneree(Phase* phase)
    {
      _phaseGeneree = phase;
    }

  /// Mise � jour du pointeur vers automate.
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

  /// M�thode utilis�e pour pouvoir debugger le code.
  virtual void afficheur() const;


private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // M�thodes priv�es
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Cr�e la nouvelle particule g�n�r�e.
  void creeNouvelleParticuleGeneree();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Lien vers la phase g�n�r�e.
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
// Autres m�thodes
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



