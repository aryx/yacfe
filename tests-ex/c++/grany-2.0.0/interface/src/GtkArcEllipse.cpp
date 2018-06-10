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


/** Constructor.
 * Important things here are the last 4 args.
 * They describe the 2 points that will everytime be the first and last point of the arc.
 */
GtkArcEllipse::GtkArcEllipse(Gdk::Color * c, gint x1, gint y1, gint x2, gint y2)
{
  _color = c;
  _x1 = x1;
  _y1 = y1;
  _x2 = x2;
  _y2 = y2;
  
  _r1 = 0; // I want not be able to draw this arc because it's incomplete. Setting _r1 to 0 makes it invalid, ok.  
}


GtkArcEllipse::GtkArcEllipse(ArcEllipse * ae, Gdk::Color * c ) : ArcEllipse::ArcEllipse(*ae)
{
  _color = c;
  
  gint mx1 = _x1 - _x;
  gint my1 = _y1 - _y;
  gint mx2 = _x2 - _x;
  gint my2 = _y2 - _y;
  _angle1 = (gint) (360*64/(2*M_PI)*atan2((double)-my2*_r1*2,(double)mx2*_r2*2));
  _angle2 = (gint) (360*64/(2*M_PI)*atan2((double)-my1*_r1*2,(double)mx1*_r2*2)) - _angle1;
  if (_angle2 < 0)
    _angle2 += 360*64;

  // To be compliant with the arcs of the `PlanHexagonal' of Pascal
  _angle2 -= 360*64;
  
}


/** Description.
 * We must find the coordinates of the new ellipse from the data we have.
 * We know the two stable points, first and last point of the arc.
 * User moves the mouse pointer and modifies that way the center of the ellipse.
 */
void GtkArcEllipse::modifyCenter(gint x, gint y, GdkModifierType state)
{


  // #1 : the two stable points are the same -> we don't want it, we stop the program.
  g_assert((_x1 != _x2) || (_y1 != _y2));


  gint mx1, my1, mx2, my2;

  // #2 : the two stable points are not horizontally aligned, nor vertically.
  if ((_x1 != _x2) && (_y1 != _y2))
    {
      // We want the points to have coordinates relative to the center.
      mx1 = _x1 - x;
      my1 = _y1 - y;
      mx2 = _x2 - x;
      my2 = _y2 - y;
      
      /* Then, process with the mathematical equation of the ellipse.
       * I had a pain in my ass, although it's easy. Consequence of not studying maths anymore! :) gc.
       */
      long diviseur1, diviseur2;
      diviseur1 = mx1*mx1-mx2*mx2;
      diviseur2 = my1*my1-my2*my2;

      if ((diviseur1 == 0) || (diviseur2 == 0))
	{ 
	  // Ellipse is invalid.
	  _r1 = 0;
	  _r2 = 0;
	}
      else
	{
	  _r1 = (int) sqrt((double)((my1*my1*mx2*mx2-my2*my2*mx1*mx1)/diviseur2));
	  _r2 = (int) sqrt((double)((mx1*mx1*my2*my2-mx2*mx2*my1*my1)/diviseur1));
	}
      
    }
  else


  // #3 : the two stable points form an horizontal line.
  if (_y1 == _y2)
    {
      /* We have the x coordinate of the center: it's the mean of the x coordinates of the stable points.
       * We'll use the x given by the user to fix a priori the height, and process the consequence width.
       */
      _r2 = (ABS(x - _x1))/2;
      if (_r2 == 0)
	{
	  // Ellipse is invalid.
	  _r1 = 0;
	  _r2 = 0;
	  return;
	}

      x = (int) ((_x1+_x2)/2);
      mx1 = _x1 - x;
      my1 = _y1 - y;
      mx2 = _x2 - x;
      my2 = _y2 - y;
      gdouble diviseur = 1 - (gdouble(my1*my1)/(_r2*_r2));
      if (diviseur <= 0)
	{ 
	  // Ellipse is invalid.
	  _r1 = 0;
	  _r2 = 0;
	}
      else
	{
	  _r1 = (int) sqrt((mx1*mx1)/diviseur);
	}

    }
  else


  // #4 : the two stable points form an vertical line.
    {
      g_assert(_x1 == _x2);
      /* We have the y coordinate of the center: it's the mean of the y coordinates of the stable points.
       * We'll use the y given by the user to fix a priori the width, and process the consequence height.
       */
      _r1 = (ABS(y - _y1))/2;
      if (_r1 == 0)
	{
	  // Ellipse is invalid.
	  _r1 = 0;
	  _r2 = 0;
	  return;
	}

      y = (int) ((_y1+_y2)/2);
      mx1 = _x1 - x;
      my1 = _y1 - y;
      mx2 = _x2 - x;
      my2 = _y2 - y;
      gdouble diviseur = 1 - (gdouble(mx1*mx1)/(_r1*_r1));
      if (diviseur <= 0)
	{ 
	  // Ellipse is invalid.
	  _r1 = 0;
	  _r2 = 0;
	}
      else
	{
	  _r2 = (int) sqrt((my1*my1)/diviseur);
	}

    }

  
  // We process the angles now.
  if ((_r1 <= 0) || (_r2 <=0))
    { _r2 = 0; _r1 = 0; } // Invalid.
      
  _angle1 = (gint) (360*64/(2*M_PI)*atan2((double)-my2*_r1*2,(double)mx2*_r2*2));
  _angle2 = (gint) (360*64/(2*M_PI)*atan2((double)-my1*_r1*2,(double)mx1*_r2*2)) - _angle1;

  // Angle given is not correct for the moment:
  if (_angle2 < 0)
    _angle2 += 360*64;
  
  // To  be compliant with the arcs of the `PlanHexagonal' of Pascal
  _angle2 -= 360*64;
  

  // Then we can finally record the centers necessary for the draws of Gdk.
  _x = x;
  _y = y;

}


bool GtkArcEllipse::isInvalid()
{
  if ((_r1 == 0) || (_r2 == 0)) return true;
  return false;
}


void GtkArcEllipse::gimmeYourCoordinates(gint *x, gint *y, gint *l, gint *h, gint *a1, gint *a2)
{
  *x = _x;
  *y = _y;
  *l = _r1*2;
  *h = _r2*2;  
  *a1 = _angle1;
  *a2 = _angle2;
}


void GtkArcEllipse::drawYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  if (isInvalid()) return;
  if (_selection)
    GtkForm::makeContextSelectionBorder(_color);
  else
  if (_preSelection)
    GtkForm::makeContextPreSelection();
  else
    GtkForm::makeContextNormal(_color);
  pixmap->draw_arc(GtkForm::getGcGlobal(), false, _x-_r1 , _y-_r2, _r1*2, _r2*2, _angle1, _angle2);
}


void GtkArcEllipse::fillYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  cerr << "[GtkArcEllipse::fillYourself] I can't fill myself." << endl;
  g_assert(true);
}


gint xc, yc, a, b;

// This function goes to 0 for the expression of the distance from the given point and the closest point of the ellipse.
gdouble fct(gdouble arg)
{
  return arg*arg*arg*arg +
    arg*arg*arg*(2*a + 2*b) +
    arg*arg*(a*a + b*b + 4*a*b - yc*yc - xc*xc) +
    arg*(2*a*b*b + 2*b*a*a - 2*a*yc*yc - 2*b*xc*xc) +
    a*a*b*b - a*a*yc*yc - b*b*xc*xc;
} 


/** Description.
 * We'll process the approaching ellipse, ie the ellipse that forms a `surface' with
 * the this-ellipse, and passes by (x,y)
 * This approaching ellipse has the same center than this-ellipse, and
 * we got (_largeur = this->_largeur + x) et (_hauteur = this->_hauteur + x)
 */    
bool GtkArcEllipse::isOn(gint x, gint y)
{
  // Coordinates x and y relative to the center of the two ellipses.
  xc = x - _x;
  yc = y - _y;

  a = _r1;
  b = _r2;

  /* Here I've got big problem. An equation of the 4th degree.
   * Solution ?
   * Brutal: dichotomy in [-TOLERANCE_SELECTION, +TOLERANCE_SELECTION].
   * Better: -> if a change in sign, maths tell us there is a root inside. :)
   */

  if (((fct(-TOLERANCE_SELECTION) <= 0) && (fct(TOLERANCE_SELECTION) >= 0)) ||
      ((fct(TOLERANCE_SELECTION) <= 0) && (fct(-TOLERANCE_SELECTION) >= 0)))
    {
      /* Then we'll look if the point is `inside' the arc of ellipse. We approximate
       * the approaching ellipse by the this-ellipse (very small error), and we process
       * the needed angle to place the point the user gives. Then we only have to test
       * if the angle is inside the opening angle of our arc.
       */
      gint angle = (gint) (360*64/(2*M_PI)*atan2((double)-yc*_r1*2,(double)xc*_r2*2));
      
      gint m_angle2 = _angle1+_angle2-360*64;

      if (((_angle2-360*64 <= 0) && (angle <= _angle1) && (angle >= m_angle2)) ||
	  ((_angle2-360*64 >= 0) && (angle >= _angle1) && (angle <= m_angle2)) ||
	  ((_angle2-360*64 <= 0) && (m_angle2 >= 360*64/2) && (angle+360*64 <= _angle1) && (angle+360*64 >= m_angle2)) ||
	  ((_angle2-360*64 >= 0) && (m_angle2 >= 360*64/2) && (angle+360*64 >= _angle1) && (angle+360*64 <= m_angle2)) ||
	  ((_angle2-360*64 <= 0) && (m_angle2 <= -360*64/2) && (angle-360*64 <= _angle1) && (angle-360*64 >= m_angle2)) ||
	  ((_angle2-360*64 >= 0) && (m_angle2 <= -360*64/2) && (angle-360*64 >= _angle1) && (angle-360*64 <= m_angle2)))
	return true;
      else
	return false;
    }
  
  else
    return false;
  
}

bool GtkArcEllipse::isInside(gint x, gint y)
{
  cerr << "[GtkArcEllipse::isInside] I don't have `inside'." << endl;
  g_assert(true);
  return true;
}
