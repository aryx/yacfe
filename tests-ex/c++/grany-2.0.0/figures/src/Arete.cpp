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

#include "Arete.h"

//##############################################################################
// Public members
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructeurs/Destructeur
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Arete::Arete(int x1, int y1, int x2, int y2)
{
  if (y1 <= y2) { _y1 = y1 ; _x1 = x1 ; _y2 = y2 ; _x2 = x2 ; }
  else { _y1 = y2 ; _x1 = x2 ; _y2 = y1 ; _x2 = x1 ;}
}

Arete::Arete(Ligne l) 
{
  int x1 = l.getX1();
  int y1 = l.getY1();
  int x2 = l.getX2();
  int y2 = l.getY2();

  if (y1 <= y2) { _y1 = y1 ; _x1 = x1 ; _y2 = y2 ; _x2 = x2 ; }
  else { _y1 = y2 ; _x1 = x2 ; _y2 = y1 ; _x2 = x1 ;}


}
// SALEEEE EEEEEEEEEEEEEEEEEE BUGGGGGGGGGGGGGGGGGGGG DE MERRRRRRRRRRRDDDDDDDDDDDEEEEEEEE

/* voila ce qui y a vait avant
Arete::Arete(Ligne l)
{
  Arete(l.getX1(),l.getY1(),l.getX2(),l.getY2())
}
Hors ca ca cree un objet temporaire et c'est tout
*/


int operator > (const Arete& a1, const Arete& a2)
{
  return a1._y2 > a2._y2 ;
}

double Arete::intersection (int droite_y) const
{
  
  if ( _x2 - _x1 == 0) 
    {
      return _x1 ;
    }
  else
    {
       
      double pente = double(_y2 - _y1) / double(_x2 - _x1) ; 
      double b     = _y1 - pente * _x1 ;

      return (droite_y - b) / pente ;
    }
} 
      
// pascal ostream& operator << (ostream& os, const Arete& ar) 
// pascal {
// pascal   os << "< (" << ar.getX1() << "," << ar.getY1() << ") ; (" ;
// pascal   os << ar.getX2() << "," << ar.getY2() << ") >" ;
// pascal   return os ;
// pascal }

//##############################################################################
// static members
//##############################################################################


