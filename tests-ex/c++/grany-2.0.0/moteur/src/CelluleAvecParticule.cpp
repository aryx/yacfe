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

#include "CelluleAvecParticule.h"

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
CelluleAvecParticule::CelluleAvecParticule(Particule * part)
{
  _particule = part;
  part->setCellule(this);
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
//Détruit la particule qu'elle contient.
CelluleAvecParticule::~CelluleAvecParticule()
{
  //delete _particule; // la particule n'est plus accessible par personne
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleAvecParticule::setParticule(Particule * part)
{
  _particule = part;
  part->setCellule(this);
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleAvecParticule::calculerRequete()
{
  _requete = getParticule()->calculerRequete();
}



//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
Requete CelluleAvecParticule::getRequete() const
{
  return _requete;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
float CelluleAvecParticule::getPhiParticule() const
{
  return getParticule()->getPhase()->getPhi();
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleAvecParticule::activer()
{
  getParticule()->setActivite(true);
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
bool CelluleAvecParticule::getActivite() const
{
  return getParticule()->getActivite();
}



//******************************************************************************
/** Description.
 *  Cette méthode est appelée sur le voisin de la cellule prenant la
 *  décision de l'échange effectif (par activerEchange()). Elle effectue
 *  alors, de son côté, les manipulations nécessaires à l'accueil d'une
 *  nouvelle particule en échange du départ de l'ancienne. Cela sera
 *  particulièrement utile dans la redéfinition d'echangeParticule() dans la
 *  classe CelluleGeneratrice.
 ******************************************************************************/
Particule* CelluleAvecParticule::echangeParticule(Particule* part1)
{
    // Particule qui va venir dans la Cellule
  part1->tuBouges();
  part1->setRequeteCourante(getRequete().requeteAccordee());

    // Particule actuellement contenue dans la Cellule
  Particule * tmp = getParticule(); 
  tmp->tuBouges();
  tmp->setRequeteCourante(getRequete());

  setParticule(part1);
  return tmp;
}


//******************************************************************************
/** Description.
 *  Cette méthode prend la décision de l'échange effectif de particules entre deux
 *  cellules adjacentes, selon l'algorithme utilisé dans les précédents Grany :
 *  \code
 *     si la requete de ma particule est Nord, Sud-Ouest, ou Sud-Est
 *       si la requete de mon voisin correspondant est en accord
 *         j'echange ma particule avec celle de mon voisin
 *  \endcode
 ******************************************************************************/
void CelluleAvecParticule::activerEchange()
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
    if (Direction(my_req).estPreponderante())
	setParticule(getVoisin(Direction(my_req))->echangeParticule(getParticule()));
  }
}
    



//******************************************************************************
/** Description.
 *  Affiche les attributs privés de l'objet.
 ******************************************************************************/
void CelluleAvecParticule::afficheur() const
{
  Cellule::afficheur();

  cerr << "Requete : ";

  _requete.afficheur();
  cerr << endl;

  cerr << "Liee a Particule :"; _particule->afficheurReduit();

}
//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleAvecParticule::afficheurReduit() const
{
  cerr << "----- Cellule avec particule\n";

  Cellule::afficheurReduit();
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void CelluleAvecParticule::afficheToi() const
{
  cerr << getParticule()->getNumero();
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
int CelluleAvecParticule::donneTaCouleur() const
{
  return getParticule()->getCouleur();
}



//##############################################################################
// Static members
//##############################################################################

ioManager<CelluleAvecParticule>* CelluleAvecParticule::_io;
