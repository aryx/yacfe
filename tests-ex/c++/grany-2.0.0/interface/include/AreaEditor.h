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

#ifndef _AREAEDITOR_H
#define _AREAEDITOR_H

#include "CommonInterface.h"
#include "GtkFigures.h"
#include "GranyDrawingArea.h"
#include "ErrorWindow.h"
#include "BasicWindow.h"

/** Common mother class to ColorationEditor and EditeurWonageWindow. Abstract.
 *  Because lots of things are common to those two editors. 
 */

class AreaEditor : public BasicWindow
{
public:

  enum EnumActionType {
    SELECTION,   
    RECTANGLE,   
    ELLIPSE,     
    POLYGONE     
  };

  AreaEditor(list<Frontiere*>);
  ~AreaEditor();

protected:

  bool handleKeyPress(GdkEventKey *);
  virtual bool handleButtonPress(GdkEventButton *) = 0;
  virtual bool handleButtonRelease(GdkEventButton *) = 0;
  virtual bool handleMotionNotify(GdkEventMotion *) = 0;
  bool handleLeaveNotify(GdkEventCrossing *);

  void initColors();
  virtual void deleteSelectedArea() = 0;

  void onQuit();

  virtual void onActivateNew() = 0;
  void onActivateSelection();
  void onActivateDelete();
  void onActivateRectangle();
  void onActivateEllipse();
  void onActivatePolygon();
  void onActivateGrid();


  void createFormBorder(Forme *, Frontiere::TypeParoi);

  Gtk::HBox _hbox;
  Gtk::VBox _options;

  Gtk::Widget * _menuDelete;

  Gtk::Image _imageNew, _imageSelection, _imageDelete, _imageRectangle, _imageEllipse, _imagePolygon, _imageGrid;

  Gtk::ToggleButton _buttonSelection, _buttonRectangle, _buttonEllipse, _buttonPolygone;
  Gtk::Button _buttonNew, _buttonDelete;
  Gtk::ToggleButton _buttonGrid;

  EnumActionType _typeAction;

  Gtk::Widget *_menuSelect, *_menuRectangle, *_menuEllipse, *_menuPolygon, *_menuGrid;


  // For the drawing area
  GranyDrawingArea _drawingArea;
  Gdk::Color *_grey, *_colorClassicalBorder, *_colorGeneratingBorder;
  GtkForm * _selectedArea, * _preSelectedArea;

  bool _isGrid;
  bool _noRecursivePlease;

  list<Zonage*> _listZonage;

};



#endif
