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

#ifndef _FORMEFERMEE_H_
#define _FORMEFERMEE_H_

#include "CommunFigures.h"

#include "Forme.h"


//*******************************************************************************
/** Représente l'ensemble des formes fermees.
 *******************************************************************************/

class FormeFermee : public Forme {

public:
  // je sais pas pkoi TOSEE je suis oblige de le mettre (sinon ca compile pas)
  // car il veut pas prendre l'appel FormeFermee* clone
  virtual FormeFermee* clone() const = 0;
} ;


#endif
