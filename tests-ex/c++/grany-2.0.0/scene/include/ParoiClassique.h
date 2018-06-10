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

#ifndef _PAROICLASSIQUE_H_
#define _PAROICLASSIQUE_H_


#include <stdio.h>
#include "Frontiere.h"
#include "Cellule.h"
#include "PlanHexagonal.h"
#include "CelluleParoi.h"

//*******************************************************************************
/** Représente une paroi simple à la différence d'une paroi génératrice.
 *******************************************************************************/

class ParoiClassique : public Frontiere {
public:

  ParoiClassique(Forme * f) : Frontiere(f) {}

  virtual void representeToiDansPlanHexagonal(PlanHexagonal& p)
  {
    cerr << "paroi classiquekkkkk" << endl ; 
    Cellule * ceil = new CelluleParoi() ;
    getForme()->dessineToiDansPlanHexagonal(p,ceil) ;
  }
 
  void afficheFrontiere() 
  { 
    cerr << " Paroi classique : ";
    getForme()->afficheToi(); 
  }     

  virtual string donneTaChaine() 
  {
    string res;
    res+=getForme()->donneTaChaine();
    res+=", CLASSIQUE;";
    return res;
  }

};

#endif
