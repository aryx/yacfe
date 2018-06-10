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

#include "Requete.h"

#include <iostream>


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
bool requeteEnAccord(const Requete &req1,const Requete &req2)
{
  bool result = true;

  switch (req1._requete)
    {
    case RIEN : 
      result = false; break;

    case SUD :
      if (req2._requete != NORD)
      result = false; break;

    case NW :
      if (req2._requete != SE)
      result = false; break;

    case NE :
      if (req2._requete != SW)
      result = false; break;

    case NORD :
      if (req2._requete != SUD)
	result = false; break;

    case SW :
      if (req2._requete != NE)
	result = false; break;

    case SE :
      if (req2._requete != NW)
	result = false; break;


    default :
      //TODO exception
      break;

    }
  return result;

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
Requete Requete::requeteAccordee() const
{
  switch (_requete)
    {
    case RIEN : 
      cerr << "[ERREUR] on ne devrait pas avoir d'appel de requete accordee sur RIEN (aucune requete ne s'y accorde / cela ne genere pas de deplacement)" << endl;
      return RIEN;
      break;

    case SUD :
      return NORD;

    case NORD :
      return SUD;

    case NW :
      return SE;

    case NE :
      return SW;

    case SE :
      return NW;

    case SW :
      return NE;

    default :
      // TODO exception
      return RIEN;
      break;

    }
}



//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code.
 ******************************************************************************/
void Requete::afficheur() const
{
  switch (_requete)
    {
    case NORD : cerr << "NORD"; break;
    case NE   : cerr << "NE"; break;
    case SE   : cerr << "SE"; break;
    case SUD  : cerr << "SUD"; break;
    case SW   : cerr << "SW"; break;
    case NW   : cerr << "NW"; break;
    case RIEN : cerr << "RIEN" ; break;
    default: cerr << "<Erreur dans la requete (aucune des 7)>"; // jamais atteint
    }

}



