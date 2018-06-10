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

#ifndef __ARETE_H__
#define __ARETE_H__


#include "CommunFigures.h"

#include "Ligne.h"

class Arete {

private:

  int _x1, _y1 ;
  int _x2, _y2 ;

public:

  Arete(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
  Arete(Ligne l);

  int getX1() const { return _x1 ; }
  int getY1() const { return _y1 ; }
  int getX2() const { return _x2 ; }
  int getY2() const { return _y2 ; }

  void setX1(int x) { _x1 = x ; }
  void setX2(int x) { _x2 = x ; }
  void setY1(int y) { _y1 = y ; }
  void setY2(int y) { _y2 = y ; }


  /*  void setY1(int y) 
  { 
    if (_y2 < y) 
      { 
	int tmp = _x1 ;
	_y1 = _y2 ; _x1 = _x2 ; _y2 = y ; _x2 = tmp ; 
      }
    else 
      {
	_y1 = y ;
      }
  }
  void setY2(int y) 
  {
   if (_y1 > y) 
      { 
	int tmp = _x2 ;
	_y2 = _y1 ; _x2 = _x1 ; _y1 = y ; _x1 = tmp ; 
      }
    else 
      {
	_y2 = y ;
      }
  } */

  void ordonne() 
  {
     if (_y1 > _y2) 
      { 
	int x2 = _x2, y2 = _y2 ;
	_y2 = _y1 ; _x2 = _x1 ; _y1 = y2 ; _x1 = x2 ; 
      }
  }

  int estHorizontale() const 
  {
    return _y1 == _y2 ; 
  }

  int coupeArete(int y) const
  {
    if (_y1 <= _y2) return y >= _y1 && y <= _y2 ; 
    else return y <= _y1 && y >= _y2 ; 
  }

  friend int operator > (const Arete&, const Arete&) ;

  double intersection (int droite_y) const ;

} ; 

ostream& operator << (ostream&, const Arete&) ;

#endif
