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

#ifndef _COMMUNFICHIERS_H_
#define _COMMUNFICHIERS_H_



//*******************************************************************************
/** \file CommunFichiers.h
 *  Contient des symboles et constantes utilisés par tous les fichiers.
 *******************************************************************************/

/// Permet de repérer une cellule qui ne fait pas partie de la scène.
#define HORSSCENE NULL

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class Rectangle;
// pascal class PhasePourcent;

template <class T> void granyDelete(T el)
{
  delete el;
}

#define DEBUG_EXCEPTION
//#define DEBUG_COMP // pour debugger les parsers et lexers

#ifdef DEBUG_COMP
#define DEBUG_COMPILER(s) s
#else
#define DEBUG_COMPILER(s)
#endif

#include "ioManager.h"

#endif

