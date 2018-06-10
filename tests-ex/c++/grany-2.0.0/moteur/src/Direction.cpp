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

#include "Direction.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  Une direction est prépondérante si elle vaut NORD ou SE ou SW.
 *  \sa CelluleAvecParticule::activerEchange()
 ******************************************************************************/

bool Direction::estPreponderante() const
{
  switch (_direction)
    {
    case NORD:
    case SE:
    case SW: return true; break;
    default: return false;
    }
}

//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code.
 ******************************************************************************/


void Direction::afficheur() const
{
  switch (_direction)
    {
    case NORD : cerr << "NORD"; break;
    case NE   : cerr << "NE"; break;
    case SE   : cerr << "SE"; break;
    case SUD  : cerr << "SUD"; break;
    case SW   : cerr << "SW"; break;
    case NW   : cerr << "NW"; break;
    default: cerr << "<Erreur dans la direction (aucune des 6)>"; // jamais atteint
    }

}


//##############################################################################
// Private members
//##############################################################################


