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

#ifndef _RULESEDITOR_H
#define _RULESEDITOR_H

#define _NB_BALLS    6
#define _SQRT_2_ON_2      sqrt(2)/2

#include "CommonInterface.h"

#include "BaseWindow.h"
#include <vector>
#include "Arrow.h"

#include "RegleExclusion.h"

#include "EntreeSortie.h"

/** Another editor, to create a Rule.
 *
 */

class RulesEditor : public BaseWindow
{
public:

  RulesEditor();
  ~RulesEditor();

  string getSavedRuleFilename();
  string getSavedRuleName();

private:

  bool handleConfigureDrawingArea(GdkEventConfigure *) ;
  bool handleExposeDrawingArea(GdkEventExpose *) ;
  bool handleButtonPress(GdkEventButton *) ;
  bool handleButtonRelease(GdkEventButton *) ;

  void initColors() ;


  void onActivateSamePhi() ;
  void onActivateUpperPhi() ;
  void onActivateLowerPhi() ;
  void onActivateAnyPhi() ;
  void onActivateAllowedMove() ;
  void onActivateNotAllowedMove() ;

  void drawBubble() ;

  void onFileNew();
  void onFileSave();
  void onOkFileOpen();
  void onOkFileSaveAs();

  void onNewbieHelp();


  Gdk::Color * color(RegleExclusion::Contrainte) ;

  bool moveThroughAllowed(RegleExclusion::Deplacement) ;

  RegleExclusion * convertsToRegleExclusion();


  Gtk::Image _imagePhiId, _imagePhiSup, _imagePhiInf, _imagePhiAny;

  Gtk::ToggleButton _buttonPhiId, _buttonPhiSup, _buttonPhiInf, _buttonPhiAny;

  Gtk::Widget *_menuPhiId, *_menuPhiSup, *_menuPhiInf, *_menuPhiAny ;


  bool _noRecursivePlease;

  gint _xBall[_NB_BALLS];  // balls' coordinates
  gint _yBall[_NB_BALLS];


  Gtk::DrawingArea _myDrawingArea;
  Glib::RefPtr<Gdk::GC> _myGc;
  gint _width, _length ;
  Gdk::Color *_red, *_blue, *_green, *_grey;
  Glib::RefPtr<Gdk::Pixmap> _pixmap;


  // We always start from the upper ball and scan them clockwise
  vector<Gdk::Color*>   _balls ;
  vector<Arrow *>  _arrows ;

  vector<RegleExclusion::Contrainte> _allowed;

  RegleExclusion::Contrainte _selectionPhi ;

  gint _ray;
  int _selectedBall;
  int _selectedArrow;


  string _ruleName;  
  string _filename, _correctedFilename;

};





#endif
