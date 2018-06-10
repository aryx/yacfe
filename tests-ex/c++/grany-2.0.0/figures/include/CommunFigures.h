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

#ifndef _COMMUNFIGURES_H_
#define _COMMUNFIGURES_H_



//*******************************************************************************
/** \file CommunFigures.h
 *  Contient des symboles et constantes utilisés par tous les fichiers.
 *******************************************************************************/

class Rectangle;


#define max(A,B) ((A) > (B) ? (A) : (B))
#define min(A,B) ((A) < (B) ? (A) : (B))
// pour compiler sur solaris car ce con redefinit abs #define abs(A)   ((A) >= 0  ? (A) : (-A))



#define DEBUG_EXCEPTION

// #define DEBUG_FIG
#ifdef DEBUG_FIG
#define DEBUG_FIGURES(s) s
#else
#define DEBUG_FIGURES(s)
#endif


#include <list>

#include "ioManager.h"

#endif

