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


GtkEllipse::GtkEllipse(Gdk::Color * c, gint x, gint y)
{
  _color = c;

  _x1 = x;
  _y1 = y;
  
  _r1 = 0; // to be invalid
}

GtkEllipse::GtkEllipse(Ellipse * e, Gdk::Color * c) : Ellipse::Ellipse(*e)
{
  _color = c;
}


void GtkEllipse::ModifyExtremity(gint x, gint y, GdkModifierType state)
{
  _r1 = ABS(x - _x1)/2;
  _r2 = ABS(y - _y1)/2;
  
  // Gimp-way to handle `shift' key
  if (state & GDK_SHIFT_MASK)
    _r1 = _r2 = (int) ((_r1 + _r2)/2);


  // Origine of the arc for Gdk is the top-left corner...
  if ((x - _x1) >= 0)
    {
      _x = _x1 + _r1;
      _y = _y1;
    }
  else
    {
      _x = _x1 - _r1;
      _y = _y1;
    }

}


bool GtkEllipse::isInvalid()
{
  if ((_r1 == 0) || (_r2 == 0)) return true;
  return false;
}


void GtkEllipse::gimmeYourCoordinates(gint *x, gint *y, gint *l, gint *h)
{
  *x = _x;
  *y = _y;
  *l = _r1*2;
  *h = _r2*2;
}

void GtkEllipse::drawYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  if (isInvalid()) return;
  if (_selection)
    GtkForm::makeContextSelectionBorder(_color);
  else
  if (_preSelection)
    GtkForm::makeContextPreSelection();
  else
    GtkForm::makeContextNormal(_color);
  pixmap->draw_arc(GtkForm::getGcGlobal(), false, _x-_r1, _y-_r2, _r1*2, _r2*2, 0, 360*64);
}

void GtkEllipse::fillYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  if (isInvalid()) return;
  if (_selection)
    GtkForm::makeContextSelectionZoning(_color);
  else
  if (_preSelection)
    GtkForm::makeContextPreSelection();
  else
    GtkForm::makeContextNormal(_color);
  pixmap->draw_arc(GtkForm::getGcGlobal(), true, _x-_r1, _y-_r2, _r1*2, _r2*2, 0, 360*64);
}


bool GtkEllipse::isOn(gint x, gint y)
{
  gint xc, yc;

  xc = _x;
  yc = _y;

  if ((hypot(gdouble(xc-x)*2/(_r1*2+TOLERANCE_SELECTION), gdouble(yc-y)*2/(_r2*2+TOLERANCE_SELECTION)) <= 1) &&
      (hypot(gdouble(xc-x)*2/(_r1*2-TOLERANCE_SELECTION), gdouble(yc-y)*2/(_r2*2-TOLERANCE_SELECTION)) >= 1))
    return true;
  else
    return false;
}


bool GtkEllipse::isInside(gint x, gint y)
{
  gint xc, yc;

  xc = _x;
  yc = _y;

  if (hypot(gdouble(xc-x)*2/(_r1*2+TOLERANCE_SELECTION), gdouble(yc-y)*2/(_r2*2+TOLERANCE_SELECTION)) <= 1)
    return true;
  else
    return false;
}
