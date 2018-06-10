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

GtkPolygon::GtkPolygon(Gdk::Color * color)
{
  _color = color;
}


GtkPolygon::GtkPolygon(Polygone * pol, Gdk::Color * color)
{
  _color = color;

  // Then let's construct a collection of GdkPoint for the drawing issue with Gdk
  list<Ligne*>::const_iterator it;
  list<Ligne*> arg;

  arg = pol->getLignes();

  int number = 0;
  for (it = arg.begin() ; it != arg.end() ; it++)
    {
      _points.push_back(Gdk::Point((*it)->getX1(), (*it)->getY1()));
      _elemPolygone.push_back(new GtkLine(*it, _color));
    }
}


void GtkPolygon::close()
{
  list<Ligne*>::const_iterator it;
  list<Ligne*> arg;
  arg = _elemPolygone;

  it = arg.end(); it--;

  if (((*it)->getY2() != (*arg.begin())->getY1()) ||
      ((*it)->getX2() != (*arg.begin())->getX1()))
    {
      _points.push_back(Gdk::Point((*it)->getX2(), (*it)->getY2()));
      _elemPolygone.push_back(new GtkLine(_color, (*it)->getX2(), (*it)->getY2(), (*arg.begin())->getX1(), (*arg.begin())->getY1()));
    }
}


GtkPolygon::~GtkPolygon()
{
  _elemPolygone.clear();
}

bool GtkPolygon::isInvalid()
{
  return false;
}


void GtkPolygon::drawYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
  for (list<Ligne*>::iterator it = _elemPolygone.begin() ;
       it != _elemPolygone.end() ;
       it++)
    {
      if (GtkLine * ds = dynamic_cast<GtkLine*>(*it))
	{
	  ds->setSelection(_selection);
	  ds->setPreSelection(_preSelection);
	  ds->drawYourself(pixmap);
	}
      else
	cerr << "[GtkPolygon::drawYourself] In my list of Line* there is something not a GtkLine* ??" << endl;
    }
}


void GtkPolygon::fillYourself(Glib::RefPtr<Gdk::Pixmap> pixmap)
{
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

  pixmap->draw_polygon(GtkForm::getGcGlobal(), true, _points);
}


bool GtkPolygon::isOn(gint x, gint y)
{
  for (list<Ligne*>::iterator it = _elemPolygone.begin() ;
       it != _elemPolygone.end() ;
       it++)
    {
      GtkLine * ds = dynamic_cast<GtkLine*>(*it);
      if (ds->isOn(x,y))
	return true;
    }
  return false;
}

unsigned int GtkPolygon::getMaxX() const
{
  unsigned int temp_max_x = 0;

  for (list<Ligne*>::const_iterator it = _elemPolygone.begin() ;
       it != _elemPolygone.end() ;
       it++)
    {
      GtkLine * ds = dynamic_cast<GtkLine*>(*it);
      temp_max_x = MAX(temp_max_x, ds->getMaxX());
    }
  return temp_max_x;
}

unsigned int GtkPolygon::getMaxY() const
{
  unsigned int temp_max_y = 0;

  for (list<Ligne*>::const_iterator it = _elemPolygone.begin() ;
       it != _elemPolygone.end() ;
       it++)
    {
      GtkLine * ds = dynamic_cast<GtkLine*>(*it);
      temp_max_y = MAX(temp_max_y, ds->getMaxY());
    }
  return temp_max_y;
}

/** Selection for a filled Polygon.
 *  Yes, we're not using Java, so we must write down the rough code.
 *  Okay at the beginning I was too lazy to make a correct algorithm.
 *  At the end, I was lazy, too, so I wrote a correct algorithm, but `porky'.
 *  (I don't know if porky means something in english, but we use it in french
 *  when we do something badly.)
 *  But it works ok. (or send me a bugreport)
 */
bool GtkPolygon::isInside(gint x, gint y)
{
  // First, eliminate easy parts.
  bool xleft = true; bool xright = true; bool yleft = true; bool yright = true;
  for (list<Ligne*>::iterator it = _elemPolygone.begin() ;
       it != _elemPolygone.end() ;
       it++)
    {
      int xl = (*it)->getX1();
      if (x>xl)
	xleft = false;
      if (x<xl)
	xright = false;

      xl = (*it)->getX2();
      if (x>xl)
	xleft = false;
      if (x<xl)
	xright = false;

      int yl = (*it)->getY1();
      if (y>yl)
	yleft = false;
      if (y<yl)
	yright = false;

      yl = (*it)->getY2();
      if (y>yl)
	yleft = false;
      if (y<yl)
	yright = false;
    }

  if ((xleft) || (xright) || (yleft) || (yright))
    return false;

  // Second, if I'm near the lines of the polygons. Because the next algorithm gives bad results near to borders of the polygons, due to the tolerance.
  if (isOn(x,y))
    return true;


  // To know if I'm inside the polygone, I will scan the y-scanline from x=0 and count how many borders I cross.
  vector<Ligne*> already_crossed;
  already_crossed.reserve(_elemPolygone.size());
  
  for (gint x_scan = 0 ; x_scan <= x ; x_scan ++)
    {
      for (list<Ligne*>::iterator it = _elemPolygone.begin() ;
	   it != _elemPolygone.end() ;
	   it++)
	{
	  bool not_already_crossed = true;
	  for (unsigned int i=0 ; i<already_crossed.size() ; i++)
	    if (already_crossed[i] == *it)
	      not_already_crossed = false;
	  
	  if (not_already_crossed)
	    {
	      GtkLine * ds = dynamic_cast<GtkLine*>(*it);
	      if (ds->isReallyOnIt(x_scan,y))
		already_crossed.push_back(*it);
	    }
	}

      // if we just entered or just escaped the polygon by exactly one of its points we have to adjust value.
      for (unsigned int number = 0 ; number<_elemPolygone.size() ; number++)
	if ((_points[number].get_x() == x_scan) &&
	    (_points[number].get_y() == y))
	  {
	    int ytest_inf;
	    if (number == 0)
	      ytest_inf = _points[_elemPolygone.size()-1].get_y();
	    else
	      ytest_inf = _points[number-1].get_y();
	    int ytest_sup;
	    if (number == _elemPolygone.size()-1)
	      ytest_sup = _points[0].get_y();
	    else
	      ytest_sup = _points[number+1].get_y();
	    if (((ytest_inf < y) && (ytest_sup > y)) ||
		((ytest_inf > y) && (ytest_sup < y)))
	      already_crossed.push_back(NULL);
	    break;
	  }
    }
  return (already_crossed.size() % 2);
}
