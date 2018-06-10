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


#include "Arrow.h"
#include <math.h>

Arrow::Arrow(Glib::RefPtr<Gdk::GC> gc, gint x1, gint y1, gint x2, gint y2, gint rayon)
{
  _allowedMove = true;
  _ray = rayon;
  _x1 = x1;
  _y1 = y1;
  _x2 = x2;
  _y2 = y2;

  _x = x2 - x1;
  _y = y2 - y1;

  _l = (gint) sqrt(_x * _x + _y * _y);

  if (_l == 0) 
    _l++;

  _xf1 = _x2 - _x / 8 - (_y / _l) * _ray / 4;    
  _yf1 = _y2 - _y / 8 + (_x / _l) * _ray / 4;
  _xf2 = _x2 - _x / 8 + (_y / _l) * _ray / 4;    
  _yf2 = _y2 - _y / 8 - (_x / _l) * _ray / 4;    

  _xc1 = _x1 + _x / 2 - (_y / _l) * _ray / 2;    
  _yc1 = _y1 + _y / 2 + (_x / _l) * _ray / 2;
  _xc2 = _x1 + _x / 2 + (_y / _l) * _ray / 2;    
  _yc2 = _y1 + _y / 2 - (_x / _l) * _ray / 2;    

  _extremity1 = new SpecialLine(gc, x2, y2, _xf1, _yf1);
  _extremity2 = new SpecialLine(gc, x2, y2, _xf2, _yf2);
  _body = new SpecialLine(gc, x1, y1, x2, y2);
  _stripe = new SpecialLine(gc, _xc1, _yc1, _xc2, _yc2);
}


void Arrow::ModifyExtremity(gint x1, gint y1, gint x2, gint y2, gint rayon)
{
  _ray = rayon;
  _x1 = x1;
  _y1 = y1;
  _x2 = x2;
  _y2 = y2;

  _x = x2 - x1;
  _y = y2 - y1;

  _l = (gint) sqrt(_x * _x + _y * _y);

  if (_l == 0) { _l++;}

  _xf1 = _x2 - _x / 8 - _y * _ray / 4 / _l;    
  _yf1 = _y2 - _y / 8 + _x * _ray / 4 / _l;
  _xf2 = _x2 - _x / 8 + _y * _ray / 4 / _l;    
  _yf2 = _y2 - _y / 8 - _x * _ray / 4 / _l;    

  _xc1 = _x1 + _x / 2 - _y * _ray / 2 / _l;    
  _yc1 = _y1 + _y / 2 + _x * _ray / 2 / _l;
  _xc2 = _x1 + _x / 2 + _y * _ray / 2 / _l;    
  _yc2 = _y1 + _y / 2 - _x * _ray / 2 / _l;    

  _extremity1->ModifyExtremity(_x2, _y2, _xf1, _yf1);
  _extremity2->ModifyExtremity(_x2, _y2, _xf2, _yf2);
  _body->ModifyExtremity(_x1, _y1, _x2, _y2);
  _stripe->ModifyExtremity(_xc1, _yc1, _xc2, _yc2);
}


void Arrow::drawYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
 _extremity1->drawYourself(pixmap);
 _extremity2->drawYourself(pixmap);
 _body->drawYourself(pixmap);
 if (!_allowedMove) 
   _stripe->drawYourself(pixmap);
}

void Arrow::allowedMove(bool passage)
{
  _allowedMove = passage;
}

bool Arrow::isAllowedMove()
{
  return _allowedMove;
}



bool Arrow::isOn(gint x, gint y)
{
  return (_extremity1->isOn(x, y) || _extremity2->isOn(x, y) || _body->isOn(x, y) || ((!isAllowedMove()) && _stripe->isOn(x, y)));
}
