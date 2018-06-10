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

#ifndef _GRANYDRAWINGAREA_H
#define _GRANYDRAWINGAREA_H

#include "CommonInterface.h"

#include "GtkFigures.h"

/** This is the generic class for the areas with drawn borders, zonings, colorations.
 *
 */

class GranyDrawingArea : public Gtk::DrawingArea
{

public:
  GranyDrawingArea();
  ~GranyDrawingArea();

  void addFigureBorder(GtkForm *);
  void addFigureZoning(GtkForm *);
  void addFigureColoration(GtkForm *);

  void removeFigure(GtkForm *);

  void clearBorders();
  void clearZonings();
  void clearColorations();

  void drawFigures();

  GtkForm * findSelectedBorder(gint x, gint y);
  GtkForm * findSelectedZoning(gint x, gint y);
  GtkForm * findSelectedColoration(gint x, gint y);

  void setGrid(bool);


  // These are temporary figures for the Borders editor
  GtkLine * _lineInProgress, * _line2InProgress;
  GtkArcEllipse * _arcEllipseInProgress;
  GtkPolygon * _polygonInProgress;
  GtkEllipse * _ellipseBordersInProgress;

  // These are temporary figures for the Zoning editor
  GtkRectangle * _rectangleInProgress;
  GtkEllipse * _ellipseInProgress;
  GtkPolygon * _polygonAreaInProgress;

private:

  bool handleConfigureDrawingArea(GdkEventConfigure *);
  bool handleExposeDrawingArea(GdkEventExpose *);


  Glib::RefPtr<Gdk::GC> _myGc;
  Glib::RefPtr<Gdk::Pixmap> _pixmap;
  Gdk::Color * _colorGrid, * _colorClassicalBorder, * _colorGeneratingBorder;
			 
  bool _isGrid;


  list<GtkForm*> _gtkBorderFigures;
  list<GtkForm*> _gtkZoningFigures;
  list<GtkForm*> _gtkColorationFigures;

};



#endif
