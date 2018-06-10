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

#include "GtkFigures.h"
#include <math.h>

GtkLine::GtkLine(Gdk::Color * c, gint x1, gint y1, gint x2, gint y2)
{
  _color = c;
  _x1 = x1;
  _y1 = y1;
  _x2 = x2;
  _y2 = y2;
}


GtkLine::GtkLine(Ligne * l, Gdk::Color * c) : Ligne::Ligne(*l)
{
  _color = c;
}

void GtkLine::modifyEnd(gint x, gint y)
{
  _x2 = x;
  _y2 = y;
}


bool GtkLine::isInvalid()
{
  if (((_x1 == _x2) && (_y1 == _y2)) || (_x1 < 0) || (_x2 < 0) || (_y1 < 0) || (_y2 < 0)) return true;
  return false;
}


void GtkLine::gimmeYourCoordinates(gint *x1, gint *y1, gint *x2, gint *y2)
{
  *x1 = _x1;
  *y1 = _y1;
  *x2 = _x2;
  *y2 = _y2;
}


void GtkLine::drawYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  if (isInvalid()) return;
  if (_selection)
    GtkForm::makeContextSelectionBorder(_color);
  else
  if (_preSelection)
    GtkForm::makeContextPreSelection();
  else
  if (_temporary)
    GtkForm::makeContextTemporary();
  else
    GtkForm::makeContextNormal(_color);
  pixmap->draw_line(GtkForm::getGcGlobal(), _x1, _y1, _x2, _y2);
}


void GtkLine::fillYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  cerr << "[GtkLine::fillYourself] I can't fill myself." << endl;
  g_assert(true);
}


bool GtkLine::isOn(gint x, gint y)
{
  if (((x<_x1-TOLERANCE_SELECTION) && (x<_x2-TOLERANCE_SELECTION)) ||
      ((x>_x1+TOLERANCE_SELECTION) && (x>_x2+TOLERANCE_SELECTION)) ||
      ((y<_y1-TOLERANCE_SELECTION) && (y<_y2-TOLERANCE_SELECTION)) ||
      ((y>_y1+TOLERANCE_SELECTION) && (y>_y2+TOLERANCE_SELECTION)))
    return false;

  if (_y2 == _y1)
    {
      if (ABS(y-_y1) <= TOLERANCE_SELECTION)
	return true;
      else
	return false;
    }

  if (_x2 == _x1)
    {
      if (ABS(x-_x1) <= TOLERANCE_SELECTION)
	return true;
      else
	return false;
    }


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


/** Description.
 *  Special method that computes without TOLERANCE, for the ellipse issue.
 */
bool GtkLine::isReallyOnIt(gint x, gint y)
{
  if (((x<_x1) && (x<_x2)) ||
      ((x>_x1) && (x>_x2)) ||
      ((y<_y1) && (y<_y2)) ||
      ((y>_y1) && (y>_y2)))
    return false;

  if (_y2 == _y1)
    {
      if (ABS(y-_y1) < 1)
	return true;
      else
	return false;
    }

  if (_x2 == _x1)
    {
      if (ABS(x-_x1) < 1)
	return true;
      else
	return false;
    }

  double coefficient_directeur_segment = ((double)(_y2-_y1))/(_x2-_x1);
  double origine_segment = _y1 - coefficient_directeur_segment*_x1;

  double coefficient_directeur_perpend = -1/coefficient_directeur_segment;
  double origine_perpend = y - coefficient_directeur_perpend*x;

  double x_plus_proche = (origine_perpend-origine_segment)/(coefficient_directeur_segment-coefficient_directeur_perpend);
  double y_plus_proche = coefficient_directeur_segment*x_plus_proche + origine_segment;

  if (hypot((x-x_plus_proche), (y-y_plus_proche)) < 1)
    return true;
  else
    return false;
}


bool GtkLine::isInside(gint x, gint y)
{
  cerr << "[GtkLine::isInside] I don't have `inside'." << endl;
  g_assert(true);
  return true;
}
