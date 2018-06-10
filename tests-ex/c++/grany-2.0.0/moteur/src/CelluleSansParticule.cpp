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

#include "CelluleSansParticule.h"


//##############################################################################
// Public members
//##############################################################################




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  On ne fait rien car la cellule ne possédant pas de particule, elle ne peut
 *  formuler de requête.
 ******************************************************************************/
void CelluleSansParticule::calculerRequete()
{
  // on ne fait rien puisque ces Cellules n'ont pas de Particule
}


//******************************************************************************
/** Description.
 *  Ici on retourne la requête RIEN puisqu'aucune particule n'est présente au
 *  sein de la cellule.
 ******************************************************************************/
Requete CelluleSansParticule::getRequete() const
{
  return RIEN;
}


//******************************************************************************
/** Description.
 *  Ici on lève une exception car cette méthode ne doit jamais être
 *  appelée.
 ******************************************************************************/
Particule * CelluleSansParticule::echangeParticule(Particule * part)
{
  // fait pour enlever les warnings
  if (part);
  throw Exception("CelluleSansParticule::echangeParticule() : cette methode ne doit pas etre appelee");
}


//******************************************************************************
/** Description.
 *  On ne fait rien car on ne peut activer d'échange qu'entre particules.
 ******************************************************************************/
void CelluleSansParticule::activerEchange()
{
  // rien a faire
}
    


//******************************************************************************
/** Description.
 *  On ne fait rien car il n'y a pas de particule à activer.
 ******************************************************************************/
void CelluleSansParticule::activer()
{

}


//******************************************************************************
/** Description.
 *  On retourne faux car il n'y a pas d'activité au sein de la cellule.
 ******************************************************************************/
bool CelluleSansParticule::getActivite() const
{
  return false;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleSansParticule::afficheur() const
{
  cerr << "----- Cellule sans particule\n";

  Cellule::afficheur();

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleSansParticule::afficheurReduit() const
{
  cerr << "----- Cellule sans particule\n";

  Cellule::afficheurReduit();

}




