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

#include "Cellule.h"


//##############################################################################
// Public members
//##############################################################################


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Cellule::afficheur() const
{
  cerr << "----------- Cellule --------------" << endl;

  cerr << "Numero : " << _numero << endl;
  cerr << "X : " << _x << endl;
  cerr << "Y : " << _y << endl;

  cerr << "Liees a " << VALENCE << " Cellules " << endl;

  for (int i=0 ; i<VALENCE ; i++)
    if (getVoisin(Direction(i)) == NULL)
      cerr << "Cellule::afficheur WARNING: pointeur null a la place d'un pointeur vers une Cellule " << endl ;
    else getVoisin(Direction(i))->afficheurReduit();

}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Cellule::afficheurReduit() const
{
  cerr << "----- Cellule" << " Numero : " << _numero << endl;
}



