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

#include "CelluleParoi.h"


//##############################################################################
// Public members
//##############################################################################


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  On simule ici le comportement d'une paroi, à savoir la présence d'une
 *  particule qui ne peut pas se déplacer, par le retour d'un \latexonly $\phi$
 *  \endlatexonly nul.
 ******************************************************************************/
float CelluleParoi::getPhiParticule() const
{
  return 0;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleParoi::afficheur() const
{
  cerr << "----- Cellule paroi\n";

  CelluleSansParticule::afficheur();

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleParoi::afficheurReduit() const
{
  cerr << "----- Cellule paroi\n";

  CelluleSansParticule::afficheurReduit();

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleParoi::afficheToi() const
{
  cerr << 'P';
}


static int _couleurParoi;

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
int CelluleParoi::donneTaCouleur() const
{
  return _couleurParoi;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void setCouleurParoi(int c)
{
  _couleurParoi = c;
}


//##############################################################################
// Static members
//##############################################################################

ioManager<CelluleParoi>* CelluleParoi::_io;
