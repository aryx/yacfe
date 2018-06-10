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

#ifndef _BORDERSEDITOR_H
#define _BORDERSEDITOR_H

#include "CommonInterface.h"

#include "BaseWindow.h"

#include "GranyDrawingArea.h"
#include "GtkFigures.h"

/** Our borders editor.
 *  Maybe the class I'm the most proud of, although it's full of no-good code.
 *  Perhaps because it was my first real experiment with gtk--, and the result
 *  is not so bad, to me.
 */
class BordersEditor : public BaseWindow
{
  /// Current working mode.
  enum EnumTypeBorders {
    SELECTION,   /**< Select. */
    SPECIALLINE, /**< Line. */
    ARCELLIPSE,  /**< Arc of ellipse. */
    ELLIPSE,     /**< Ellipse. */
    POLYGONE     /**< Polygon. */
  };


public:
  BordersEditor(list<Frontiere*> = list<Frontiere*>());

  list<Frontiere*> getListFrontiere();

private:

  void onFileNew();
  void onOkFileOpen();
  void onFileSave();
  void onOkFileSaveAs();
  
  void onNewbieHelp();

  bool handleKeyPress(GdkEventKey *);
  bool handleLeaveNotify(GdkEventCrossing *);
  bool handleButtonPress(GdkEventButton *);
  bool handleButtonRelease(GdkEventButton *);
  bool handleMotionNotify(GdkEventMotion *);

  void initColors();
  void deleteSelectedFigure();

  void onActivateSelection();
  void onActivateDelete();
  void onActivateLine();
  void onActivateArcEllipse();
  void onActivateEllipse();
  void onActivatePolygon();
  void onActivateClassicalBorders();
  void onActivateGeneratingBorders();
  void onActivateGridMenu();
  void onActivateGridToolbar();

  void createFormBorder(Forme *, Frontiere::TypeParoi);

  Gtk::Widget *_menuSelect, *_menuLine, *_menuArcEllipse, *_menuEllipse, *_menuPolygon,
    *_menuDelete, *_menuClassicalBorders, *_menuGeneratingBorders, *_menuGrid;

  Gtk::Image _imageSelection, _imageDelete, _imageSpecialLine, _imageArcEllipse, _imageEllipse,
             _imagePolygon, _imageClassicalBorders, _imageGeneratingBorders, _imageGrid;

  Gtk::ToggleButton _buttonSelection, _buttonLine, _buttonArcEllipse, _buttonEllipse,
                   _buttonPolygone, _buttonClassicalBorder, _buttonGeneratingBorder;
  Gtk::Button _buttonDelete;
  Gtk::ToggleButton _buttonGrid;

  EnumTypeBorders _typeBorder;
  Frontiere::TypeParoi _typeParoi;

  GranyDrawingArea _drawingArea;
  Gdk::Color *_grey, *_colorClassicalBorder, *_colorGeneratingBorder;
  GtkForm * _figureSelectionnee, * _figurePreSelectionnee;
  bool _isGrid;

  bool _noRecursivePlease;

  list<Frontiere*> _listFrontiere;

  string _fileName;

};



#endif
