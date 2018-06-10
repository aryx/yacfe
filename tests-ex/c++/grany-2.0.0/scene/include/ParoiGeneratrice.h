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

#ifndef _PAROIGENERATRICE_H_
#define _PAROIGENERATRICE_H_


#include <stdio.h>
#include "Phase.h"
#include "Frontiere.h"
#include "Particule.h"
#include "CelluleGeneratrice.h"

//*******************************************************************************
/** Représente une paroi génératrice d'une phase.
 *  Cet objet possède une couleur propre.
 *******************************************************************************/
 
class ParoiGeneratrice : public Frontiere{

public:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur par défaut.
  ParoiGeneratrice(Forme * f) : Frontiere(f) {}

  /// Constructeur à partir d'une Phase et d'une couleur.
  ParoiGeneratrice(Forme * f, Phase p, int c ): Frontiere(f),_phase(p),_couleur(c){}

  /// Destructeur.
  ~ParoiGeneratrice() {}

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes : Fonctions d'acces aux membres 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Retourne la phase associée à l'objet.
  Phase  getPhase(){return _phase;}

  /// Retourne la couleur associée à l'objet.
  int getCouleur(){return  _couleur;}

  virtual void representeToiDansPlanHexagonal(PlanHexagonal& p)
  {
    Particule * part = new Particule(0, &_phase, NULL, RIEN, false) ;
    Cellule * ceil = new CelluleGeneratrice(part, &_phase) ;
    part->setCellule(ceil) ;
    part->setCouleur(_couleur) ;
    getForme()->dessineToiDansPlanHexagonal(p,ceil) ;
  }
     
private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Phase que la paroi génère.
  Phase  _phase;

  /// Couleur de la paroi.
  int  _couleur;


};

#endif

