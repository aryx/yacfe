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

#include "CelluleGeneratrice.h"
#include "Particule.h"


//##############################################################################
// Public members
//##############################################################################



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  Comme on a pu le voir dans CelluleAvecParticule, ici se font les
 *  manipulations nécessaires à l'échange de particule, lorsqu'une cellule
 *  prend (dans activerEchange()) la décision de l'échange effectif.
 *  Cela est particulièrement utile ici car la cellule génératrice
 *  doit créer la nouvelle particule générée.
 ******************************************************************************/
Particule* CelluleGeneratrice::echangeParticule(Particule* part1)
{
//  Particule * tmp = getParticule();
//  tmp->tuBouges();
//
//  setParticule(part1);
//  creeNouvelleParticuleGeneree();
//  getParticule()->tuBouges(); // on peut en discuter
//  
//  return tmp;
  Particule* tmp = CelluleAvecParticule::echangeParticule(part1);
  creeNouvelleParticuleGeneree();
  getParticule()->tuBouges();
  return tmp;
}


//******************************************************************************
/** Description.
 *  Cette méthode effectue la même opération que celle de la classe mère,
 *  tout en prenant en compte la génération d'une nouvelle particule
 *  après l'échange effectif des particules.
 ******************************************************************************/
void CelluleGeneratrice::activerEchange()
{
  Requete my_req = getRequete();

  if ((my_req == Requete(RIEN)) ||
	  (! requeteEnAccord(my_req,getVoisin(Direction(my_req))->getRequete())))
    {
	  getParticule()->tuBougesPas();
    }
  else { 
	  /*
	    Directions NORD, SW, SE : on gere les methodes
	    liees au deplacement et l'echange
	    */
    if (Direction(my_req).estPreponderante()) {
	  
	  setParticule(getVoisin(Direction(my_req))->echangeParticule(getParticule()));
	  creeNouvelleParticuleGeneree();
	  getParticule()->tuBouges();
    }
  }
}





//##############################################################################
// Private members
//##############################################################################


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleGeneratrice::creeNouvelleParticuleGeneree()
{
  Particule * particule_generee;

  getAutomate()->suppressionParticule(getParticule());
  int i = getAutomate()->getNumeroParticuleLibre();
  DEBUG_MOTEUR(cout << "I = " << i << endl;);

  particule_generee = new Particule(i,
				    getPhaseGeneree(),
				    this,   // Cellule liee
				    RIEN,   // Provenance
				    true);  // Activite
  getAutomate()->ajoutParticule(particule_generee);
  setParticule(particule_generee);
}

//******************************************************************************
/** Description.
 *  Affiche les attributs privés de l'objet.
 ******************************************************************************/
void CelluleGeneratrice::afficheur() const
{
  CelluleAvecParticule::afficheur();
  cerr << "Genere Phase :"; _phaseGeneree->afficheur();

}


//##############################################################################
// Static members
//##############################################################################

ioManager<CelluleGeneratrice>* CelluleGeneratrice::_io;
