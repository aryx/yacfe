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

#include "SpecialLine.h"
#include "InterfaceUtils.h"
#include <math.h>

SpecialLine::SpecialLine(Glib::RefPtr<Gdk::GC> gc, gint x1, gint y1, gint x2, gint y2)
{
  _x1 = x1;
  _y1 = y1;
  _x2 = x2;
  _y2 = y2;
  _gc = gc;
}


void SpecialLine::ModifyExtremity(gint x1, gint y1,gint x2, gint y2)
{
  _x1 = x1;
  _y1 = y1;
  _x2 = x2;
  _y2 = y2;
}

void SpecialLine::drawYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  _gc->set_foreground(InterfaceUtils::getColorBlack());
  pixmap->draw_line(_gc, _x1, _y1, _x2, _y2);
}

bool SpecialLine::isOn(gint x, gint y)
{
  // First step: excluding coordinates outside of the rectangle created by the line.
  if (((x<_x1-TOLERANCE_SELECTION) && (x<_x2-TOLERANCE_SELECTION)) ||
      ((x>_x1+TOLERANCE_SELECTION) && (x>_x2+TOLERANCE_SELECTION)) ||
      ((y<_y1-TOLERANCE_SELECTION) && (y<_y2-TOLERANCE_SELECTION)) ||
      ((y>_y1+TOLERANCE_SELECTION) && (y>_y2+TOLERANCE_SELECTION)))
    return false;

  // Two special cases where we won't be able to process the coeff.
  if (_y2 == _y1)
    {
      if (abs(y-_y1) <= TOLERANCE_SELECTION)
	return true;
      else
	return false;
    }

  if (_x2 == _x1)
    {
      if (abs(x-_x1) <= TOLERANCE_SELECTION)
	return true;
      else
	return false;
    }

  // Then we try to estimate the proximity of the point to the segment, processing the closest point.
  double coefficient_directeur_segment = ((double)(_y2-_y1))/(_x2-_x1);
  double origine_segment = _y1 - coefficient_directeur_segment*_x1;

  double coefficient_directeur_perpend = -1/coefficient_directeur_segment;
  double origine_perpend = y - coefficient_directeur_perpend*x;

  double x_plus_proche = (origine_perpend-origine_segment)/(coefficient_directeur_segment-coefficient_directeur_perpend);
  double y_plus_proche = coefficient_directeur_segment*x_plus_proche + origine_segment;

  if (hypot((x-x_plus_proche), (y-y_plus_proche)) <= TOLERANCE_SELECTION)
    return true;
  else
    return false;
}
