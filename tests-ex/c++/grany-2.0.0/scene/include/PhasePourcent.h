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

#ifndef _PHASEPOURCENT_H_
#define _PHASEPOURCENT_H_

#include "CommunScene.h"

//*******************************************************************************
/** Repr�sente une phase associ�e � un pourcentage.
 *******************************************************************************/

struct PhasePourcent {
  Phase* phase;
  float pourcentage;
};


#endif

 
