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

#ifndef _COMMUNMOTEUR_H_
#define _COMMUNMOTEUR_H_



//*******************************************************************************
/** \file Commun.h
 *  Contient des symboles et constantes utilisés par tous les fichiers.
 *  Par exemple l'enum EnumDirectionRequete permet à tous les fichiers
 *  de pouvoir utiliser les symboles NORD, SUD, etc...
 *******************************************************************************/


/** 
 * Définit des symboles cardinaux plus un symbole RIEN.
 * Il permet de spécifier des directions ou requêtes, simplement en tapant un 
 * symbole, et non un entier. Il est plus pratique de taper NORD que 0.
 * L'ordre dans lequel les symboles cardinaux sont définis représente
 * le sens horaire (ou anti-trigonométrique (on est pas des charlots)).
 * \sa Direction, Requete
 */

enum EnumDirectionRequete { 
  NORD = 0,   /**< Nord.       */
  NE,         /**< Nord est.   */
  SE,         /**< Sud est.    */
  SUD,        /**< Sud.        */
  SW,         /**< Sud ouest.  */
  NW,         /**< Nord ouest. */
  RIEN        /**< Rien n'est pas une direction mais il est utilisé pour contruire un objet Requete. */
};

/** 
 * On a une toplogie hexavalente -> VALENCE = 6.
 * Cette constante est utilisée pour définir la dimension de nos tableaux
 * ou bien les bornes de nos boucles for.
 */
const int   VALENCE = 6;

/** 
 * Constante en dur permettant de séparer les phases solides des non-solides.
 * En effet dans les règles d'exclusion, on range les particules en différentes
 * catégories, et un des critères de séparation est son appartenance à l'ensemble
 * des phases solides.
 * \sa RegleExclusion
 */
const float PHI_SOLIDE = 0.5;


// On définit ces classes dans ce fichier afin de contourner le problème d'inclusion
// récursive.
class Cellule;
class CelluleAvecParticule;
class Automate;
class Particule;
class ParticulePropagative;


// Au cas ou qu'on veut les messages de debug, ben y'a qu'a rajouter ici
// gc: TOSEE: peut-etre des "niveaux de debug" ou des debugs specifiques aux classes ?
// #ifndef _DEBUG_
// #define _DEBUG_
// #endif
//#define DEBUG_EXCEPTION

//#define DEBUG_MOT

#ifdef DEBUG_MOT
#define DEBUG_MOTEUR(s) s
#else
#define DEBUG_MOTEUR(s)
#endif

#include "ioManager.h"

#endif

