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

#include "GranyDrawingArea.h"
#include "InterfaceUtils.h"


GranyDrawingArea::GranyDrawingArea()
{
  _lineInProgress = NULL; _line2InProgress = NULL; _arcEllipseInProgress = NULL; _polygonInProgress = NULL; 
  _rectangleInProgress = NULL; _ellipseInProgress = NULL; _ellipseBordersInProgress = NULL; _polygonAreaInProgress = NULL;

  _isGrid = false;

  signal_expose_event().connect(slot(*this, &GranyDrawingArea::handleExposeDrawingArea));
  signal_configure_event().connect(slot(*this, &GranyDrawingArea::handleConfigureDrawingArea));

  _colorGrid = InterfaceUtils::addColorDirect(65535, 58000, 55000);
}


GranyDrawingArea::~GranyDrawingArea()
{
  clearBorders();
  clearZonings();

  delete _lineInProgress;
  delete _line2InProgress;
  delete _arcEllipseInProgress;
  delete _polygonInProgress;
  delete _ellipseBordersInProgress;
  delete _colorGrid;
}


// Creates my new pixmap. I will draw all in it. (sort of buffered write)
bool GranyDrawingArea::handleConfigureDrawingArea(GdkEventConfigure *event)
{
  if (!_myGc)
    {
      _myGc = Gdk::GC::create(get_window());
      GtkForm::setGcGlobal(_myGc);
      GtkForm::setTile(get_window());
    }

  int x, y, width, height, depth;
  get_window()->get_geometry(x, y, width, height, depth);
  _pixmap = Gdk::Pixmap::create(get_window(), width, height, -1);
  
  drawFigures();

  return true;
}



bool GranyDrawingArea::handleExposeDrawingArea(GdkEventExpose *event)
{
  get_window()->draw_drawable(_myGc,
			      _pixmap,
			      event->area.x, event->area.y,
			      event->area.x, event->area.y,
			      event->area.width, event->area.height);

  return false; // ? stolen from gtk-- examples
}


// This method draws all the objects 
void GranyDrawingArea::drawFigures()
{
  // It's possible I be called with no connected GC, ie I'm not realized yet, I only exit in such case.
  if (!_myGc)
    return;

  _myGc->set_foreground(InterfaceUtils::getColorWhite());
  int x, y, width, height, depth;
  get_window()->get_geometry(x, y, width, height, depth);
  _pixmap->draw_rectangle(_myGc, true, 0, 0, width-1, height-1);


  if (_isGrid)
    {
      _myGc->set_foreground(*_colorGrid);

      for (int i=0 ; i<width ; i+=GRANULARITY)
	_pixmap->draw_line(_myGc, i, 0, i, height);
      for (int j=0 ; j<height ; j+=GRANULARITY)
	_pixmap->draw_line(_myGc, 0, j, width, j);
    }


  // `Normal' zonings

  for (list<GtkForm*>::iterator it_figures = _gtkZoningFigures.begin() ;
       it_figures != _gtkZoningFigures.end() ;
       it_figures++)
    (*it_figures)->fillYourself(_pixmap);


  // `Normal' colorations

  for (list<GtkForm*>::iterator it_figures = _gtkColorationFigures.begin() ;
       it_figures != _gtkColorationFigures.end() ;
       it_figures++)
    (*it_figures)->fillYourself(_pixmap);


  // `Normal' borders

  for (list<GtkForm*>::iterator it_figures = _gtkBorderFigures.begin() ;
       it_figures != _gtkBorderFigures.end() ;
       it_figures++)
    (*it_figures)->drawYourself(_pixmap);


  // Then objects in progress

  if (_lineInProgress != NULL)
    _lineInProgress->drawYourself(_pixmap);

  if (_line2InProgress != NULL)
    _line2InProgress->drawYourself(_pixmap);

  if (_arcEllipseInProgress != NULL)
    _arcEllipseInProgress->drawYourself(_pixmap);

  if (_polygonInProgress != NULL)
    _polygonInProgress->drawYourself(_pixmap);

  if (_ellipseBordersInProgress != NULL)
    _ellipseBordersInProgress->drawYourself(_pixmap);


  if (_rectangleInProgress != NULL)
    _rectangleInProgress->fillYourself(_pixmap);

  if (_ellipseInProgress != NULL)
    _ellipseInProgress->fillYourself(_pixmap);

  if (_polygonAreaInProgress != NULL)
    _polygonAreaInProgress->drawYourself(_pixmap);


  _myGc->set_line_attributes(1, Gdk::LINE_SOLID, Gdk::CAP_NOT_LAST, Gdk::JOIN_MITER);
  _myGc->set_fill(Gdk::SOLID);

  _myGc->set_foreground(InterfaceUtils::getColorBlack());
  _pixmap->draw_rectangle(_myGc, false, 0, 0, width-1, height-1);


  _myGc->set_foreground(InterfaceUtils::getColorBlack());


//  GdkRectangle update_rect;
//
//  update_rect.x = 0;
//  update_rect.y = 0;
//  update_rect.width = width;
//  update_rect.height = height;
//
//  draw(&update_rect);
  
  queue_draw();
}


void GranyDrawingArea::setGrid(bool gr)
{
  _isGrid = gr;
}


void GranyDrawingArea::addFigureBorder(GtkForm * fig)
{
  _gtkBorderFigures.push_back(fig);
}


void GranyDrawingArea::addFigureZoning(GtkForm * fig)
{
  _gtkZoningFigures.push_back(fig);
}


void GranyDrawingArea::addFigureColoration(GtkForm * fig)
{
  _gtkColorationFigures.push_back(fig);
}

void GranyDrawingArea::removeFigure(GtkForm * fig)
{
  for (list<GtkForm*>::iterator it_figures_f = _gtkBorderFigures.begin() ;
       it_figures_f != _gtkBorderFigures.end() ;
       it_figures_f++)
    if ((*it_figures_f) == fig)
      {
	_gtkBorderFigures.erase(it_figures_f);
	return;
      }

  for (list<GtkForm*>::iterator it_figures_z = _gtkZoningFigures.begin() ;
       it_figures_z != _gtkZoningFigures.end() ;
       it_figures_z++)
    if ((*it_figures_z) == fig)
      {
	_gtkZoningFigures.erase(it_figures_z);
	return;
      }

  for (list<GtkForm*>::iterator it_figures_c = _gtkColorationFigures.begin() ;
       it_figures_c != _gtkColorationFigures.end() ;
       it_figures_c++)
    if ((*it_figures_c) == fig)
      {
	_gtkColorationFigures.erase(it_figures_c);
	return;
      }
}


GtkForm * GranyDrawingArea::findSelectedBorder(gint x, gint y)
{
  // We want to return the /last/ selected figure.
  GtkForm * selection = NULL;
  for (list<GtkForm*>::iterator it_figures = _gtkBorderFigures.begin() ;
       it_figures != _gtkBorderFigures.end() ;
       it_figures++)
    if ((*it_figures)->isOn(x, y))
      selection = *it_figures;

  return selection;
}


GtkForm * GranyDrawingArea::findSelectedZoning(gint x, gint y)
{
  // We want to return the /last/ selected figure.
  GtkForm * selection = NULL;
  for (list<GtkForm*>::iterator it_figures = _gtkZoningFigures.begin() ;
	   it_figures != _gtkZoningFigures.end() ;
	   it_figures++)
    if ((*it_figures)->isInside(x, y))
	selection = *it_figures;

  return selection;
}


GtkForm * GranyDrawingArea::findSelectedColoration(gint x, gint y)
{
  // We want to return the /last/ selected figure.
  GtkForm * selection = NULL;
  for (list<GtkForm*>::iterator it_figures = _gtkColorationFigures.begin() ;
	   it_figures != _gtkColorationFigures.end() ;
	   it_figures++)
    if ((*it_figures)->isInside(x, y))
	selection = *it_figures;

  return selection;
}


void GranyDrawingArea::clearBorders()
{
  // Ouch. Had problems with these frees. Because some figures are shared, etc.

  /*
  // Parcours de la liste des figures pour les effacer toutes.
  for (list<GtkForm*>::iterator it_figures = _gtkBorderFigures.begin() ;
       it_figures != _gtkBorderFigures.end() ;
       it_figures++)
    delete (*it_figures);
 */
  _gtkBorderFigures.clear();
}



void GranyDrawingArea::clearZonings()
{
  /*
  for (list<GtkForm*>::iterator it_figures = _gtkZoningFigures.begin() ;
       it_figures != _gtkZoningFigures.end() ;
       it_figures++)
    delete (*it_figures);
  */
  _gtkZoningFigures.clear();
}


void GranyDrawingArea::clearColorations()
{
  /*
  for (list<GtkForm*>::iterator it_figures = _gtkZoningFigures.begin() ;
       it_figures != _gtkZoningFigures.end() ;
       it_figures++)
    delete (*it_figures);
  */
  _gtkColorationFigures.clear();
}
