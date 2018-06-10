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

#ifndef _ARROW_H_
#define _ARROW_H_

#include "SpecialLine.h"
#include <gtkmm.h>

/** Class implementing an Arrow, for the Rules editor.
 *
 */

class Arrow
{
public:
  Arrow(Glib::RefPtr<Gdk::GC>, gint x1, gint y1, gint x2, gint y2, gint rayon);

  void ModifyExtremity(gint x1, gint y1, gint x2, gint y2, gint rayon);

  void drawYourself(Glib::RefPtr<Gdk::Pixmap>);
  void allowedMove(bool passage);
  bool isAllowedMove();
  bool isOn(gint x, gint y);

private:
  SpecialLine * _extremity1;
  SpecialLine * _extremity2;
  SpecialLine * _body;
  SpecialLine * _stripe;
  bool _allowedMove;
  gint _x1;
  gint _y1;
  gint _x2;
  gint _y2;
  gint _l;
  gint _ray;
  gint _x;
  gint _y;
  gint _xf1;
  gint _yf1;
  gint _xf2;
  gint _yf2;
  gint _xc1;
  gint _yc1;
  gint _xc2;
  gint _yc2;
};


#endif
