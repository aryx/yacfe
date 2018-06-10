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

#include "RegleExclusion.h"

#include <iostream>
#include <string>

//##############################################################################
// Public members
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructeurs/Destructeur
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  \param nom nom de la règle.
 *  \param elements tableau des déplacements et des contraintes.
 ******************************************************************************/
RegleExclusion::RegleExclusion(string nom,
			       Paire elements[6])
{
  int i;

  _nom = nom;

  for (i=0 ; i<VALENCE-1 ; i++)
    {
      _tabDepl[i] = elements[i].deplacement;
      _tabDepl[i+VALENCE] = elements[i].deplacement;
    }
  _tabDepl[VALENCE-1] = elements[VALENCE-1].deplacement;
  

  for (i=0 ; i<VALENCE-1 ; i++)
    {
      _tabContr[i] = elements[i].contrainte;
      _tabContr[i+VALENCE] = elements[i].contrainte;
    }
  _tabContr[VALENCE-1] = elements[VALENCE-1].contrainte;

  _decalageRotation = 0;
  _compteur = 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void RegleExclusion::ajoutPaire(Deplacement depl, Contrainte contr)
{
  if (_compteur >= VALENCE )
    {
      cerr << "Nombre d'appels à ajoute trop nombreux" << endl;
    }
  else {
    setDeplacement(Direction(_compteur), depl);
    setContrainte(Direction(_compteur), contr);
    _compteur++;
  }
  
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void RegleExclusion::ajoutPaire(Paire paire)
{
  if (_compteur >= VALENCE )
    {
      cerr << "Nombre d'appels à ajoute trop nombreux" << endl;
    }
  else {
    setDeplacement(Direction(_compteur), paire.deplacement);
    setContrainte(Direction(_compteur), paire.contrainte);
    _compteur++;
  }
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

ostream& operator<<(ostream& os,RegleExclusion::Deplacement dep)
{
  switch(dep) {
  case RegleExclusion::DEPLPOSSIBLE:   os << "Deplacement possible"  ;break;
  case RegleExclusion::DEPLIMPOSSIBLE: os << "Deplacement impossible";break;
  }
  return os;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

ostream& operator<<(ostream& os,RegleExclusion::Contrainte con)
{
  switch(con) {
  case RegleExclusion::CONTRAINTE_NULLE:  os << "Contrainte nulle" ; break;
  case RegleExclusion::CONTRAINTE_MEMEPHI: os << "Contrainte meme phi"; break;
  case RegleExclusion::CONTRAINTE_PHIINFERIEUR: os << "Contrainte phi inferieur" ; break;
  case RegleExclusion::CONTRAINTE_PHIINFSOLIDE: os << "Contrainte phi inferieur phi solide" ; break;
  }
  return os;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

ostream& operator<<(ostream& os,RegleExclusion::ModeExclusion mode)
{
  switch(mode) {
  case RegleExclusion::POST: os << "Post exclusion" ; break;
  case RegleExclusion::PRE: os << "Pre exclusion" ; break;
  }
  return os;
}


//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code.
 ******************************************************************************/
void RegleExclusion::afficheur() const
{
  cerr << "----------- Regle d'exclusion  --------------" << endl;

  cerr << "Nom : " << _nom << endl;

  for (int i=0 ; i<VALENCE ; i++)
    {
      cerr << "Valeur de la contrainte ";

      Direction(i).afficheur();
      cerr << " = ";
         
      
      switch(_tabContr[i+_decalageRotation]) {
      case RegleExclusion::CONTRAINTE_NULLE:  cerr << "Contrainte nulle" ; break;
      case RegleExclusion::CONTRAINTE_MEMEPHI: cerr << "Contrainte meme phi"; break;
      case RegleExclusion::CONTRAINTE_PHIINFERIEUR: cerr << "Contrainte phi inferieur" ; break;
      case RegleExclusion::CONTRAINTE_PHIINFSOLIDE: cerr << "Contrainte phi inferieur phi solide" ; break;
      }
      
      cerr << " ; deplacement = ";

      switch(_tabDepl[i+_decalageRotation]) {
      case RegleExclusion::DEPLPOSSIBLE:   cerr << "Deplacement possible"  ;break;
      case RegleExclusion::DEPLIMPOSSIBLE: cerr << "Deplacement impossible";break;
      }
      cerr << endl;
    }

}

//##############################################################################
// static members
//##############################################################################


RegleExclusion::Paire RegleExclusion::_paireDefaut[6] = {{DEPLIMPOSSIBLE, CONTRAINTE_NULLE},
							 {DEPLIMPOSSIBLE, CONTRAINTE_NULLE},
							 {DEPLIMPOSSIBLE, CONTRAINTE_NULLE},
							 {DEPLIMPOSSIBLE, CONTRAINTE_NULLE},
							 {DEPLIMPOSSIBLE, CONTRAINTE_NULLE},
							 {DEPLIMPOSSIBLE, CONTRAINTE_NULLE}};


ioManager<RegleExclusion>* RegleExclusion::_io = NULL;
