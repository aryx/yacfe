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



#include "Ponderation.h"

//##############################################################################
// Public members
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructeurs/Destructeur
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  Il place toutes les probabilités à zéro.
 ******************************************************************************/
Ponderation::Ponderation()
{
  int i;

  for (i=0 ; i<VALENCE ; i++)
    _tabValeur[i] = 0;
}

//******************************************************************************
/** Description.
 *  \param tab_val tableau de 6 valeurs représentant des probabilités. L'ordre
 *  est celui définit par l'enum ::EnumDirectionRequete (tab_val[0] représente la
 *  probabilité pour la direction NORD).
 ******************************************************************************/
// TOSEE bug du au fait que le C++ verifie pas la taille des tableaux passe en param
Ponderation::Ponderation(int tab_val[VALENCE])
{
  int i;

  for (i=0 ; i<VALENCE ; i++)
    _tabValeur[i] = tab_val[i];
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Opérateurs
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
Ponderation & Ponderation::operator+=(const Ponderation &po)
{
  Ponderation Ponderation_tmp = *this + po;
  *this = Ponderation_tmp;

  return *this;
}

//******************************************************************************
/** Description.
 *  Il effectue simplement une addition des probabilités pour chaque direction.
 ******************************************************************************/
Ponderation operator+(const Ponderation &po1,const Ponderation &po2)
{
  int i;
  Ponderation ponderation_finale = po1;

  for (i=0 ; i<VALENCE ; i++)
    ponderation_finale._tabValeur[i] += po2._tabValeur[i];

  return ponderation_finale;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
//******************************************************************************
/** Description.
 *  \return Une sommation de toutes les probabilités.
 ******************************************************************************/
int Ponderation::getModule() const
{
  int i,module;

  module = 0;

  for (i=0; i<VALENCE ; i++)
    module += getPonderation(Direction(i));

  return module;
}

//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code.
 ******************************************************************************/
void Ponderation::afficheur() const
{
  cerr << "----------- Ponderation --------------" << endl;

  for (int i=0 ; i<VALENCE ; i++)
    {
      cerr << "Valeur de la ponderation : ";

      Direction(i).afficheur();

      cerr << " = " << _tabValeur[i] << endl;
    }
}
//##############################################################################
// Static members
//##############################################################################

ioManager<Ponderation>* Ponderation::_io;
