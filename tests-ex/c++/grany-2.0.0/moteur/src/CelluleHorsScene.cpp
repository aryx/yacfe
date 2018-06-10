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

#include "CelluleHorsScene.h"


//##############################################################################
// Public members
//##############################################################################


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  On simule ici le comportement d'une cellule hors scene, à savoir l'absence
 *  de \latexonly $\phi$ \endlatexonly. On declenche une exception. 
 ******************************************************************************/
float CelluleHorsScene::getPhiParticule() const
{
  // TODO declencher exception
  return -1;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleHorsScene::afficheur() const
{
  cerr << "----- Cellule hors scene\n";

  CelluleSansParticule::afficheur();

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleHorsScene::afficheurReduit() const
{
  cerr << "----- Cellule hors scene\n";

  CelluleSansParticule::afficheurReduit();

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleHorsScene::afficheToi() const
{
  cerr << 'H';
}


static int _couleurHorsScene = -1;

//******************************************************************************
/** Description.
 *  Ici on rend une couleur "convention", on n'affichera pas la cellule.
 *  La convention est placée par défaut à -1 mais elle peut être changée.
 ******************************************************************************/
int CelluleHorsScene::donneTaCouleur() const
{
  return _couleurHorsScene;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void setCouleurHorsScene(int c)
{
  _couleurHorsScene = c;
}




//##############################################################################
// Private members
//##############################################################################

//##############################################################################
// Static members
//##############################################################################

ioManager<CelluleHorsScene>* CelluleHorsScene::_io;



