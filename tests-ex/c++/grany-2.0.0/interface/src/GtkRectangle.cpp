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

GtkRectangle::GtkRectangle(Gdk::Color * c, gint x1, gint y1, gint x2, gint y2)
{
  _color = c;
  _x1 = x1;
  _y1 = y1;
  _x2 = x2;
  _y2 = y2;
}


GtkRectangle::GtkRectangle(Rectangle * r, Gdk::Color * c) : Rectangle::Rectangle(*r)
{
  _color = c;
}


void GtkRectangle::modifyEnd(gint x, gint y)
{
  _x2 = x;
  _y2 = y;
}


bool GtkRectangle::isInvalid()
{
  if (((_x1 == _x2) && (_y1 == _y2)) || (_x1 < 0) || (_x2 < 0) || (_y1 < 0) || (_y2 < 0)) return true;
  return false;
}


void GtkRectangle::gimmeYourCoordinates(gint *x1, gint *y1, gint *x2, gint *y2)
{
  *x1 = _x1;
  *y1 = _y1;
  *x2 = _x2;
  *y2 = _y2;
}



void GtkRectangle::drawYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
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

  pixmap->draw_rectangle(GtkForm::getGcGlobal(), false, MIN(_x1,_x2), MIN(_y1,_y2), ABS(_x2-_x1), ABS(_y2-_y1));
}


void GtkRectangle::fillYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  if (isInvalid()) return;
  if (_selection)
    GtkForm::makeContextSelectionZoning(_color);
  else
  if (_preSelection)
    GtkForm::makeContextPreSelection();
  else
  if (_temporary)
    GtkForm::makeContextTemporary();
  else
    GtkForm::makeContextNormal(_color);

  pixmap->draw_rectangle(GtkForm::getGcGlobal(), true, MIN(_x1,_x2), MIN(_y1,_y2), ABS(_x2-_x1), ABS(_y2-_y1));
}



bool GtkRectangle::isOn(gint x, gint y)
{
  cerr << "[GtkRectangle::isOn] Not implemented. Rectangle should be always filled, and you called a non-filled designed method." << endl;
  g_assert(true);
  return true;
}


bool GtkRectangle::isInside(gint x, gint y)
{
  gint x1, y1, x2, y2;
  
  x1 = MIN(_x1,_x2);
  x2 = MAX(_x1,_x2);
  y1 = MIN(_y1,_y2);
  y2 = MAX(_y1,_y2);

  if ((x>x1-TOLERANCE_SELECTION) && (y>y1-TOLERANCE_SELECTION) &&
      (x<x2+TOLERANCE_SELECTION) && (y<y2+TOLERANCE_SELECTION))
    return true;
  else
    return false;
}
