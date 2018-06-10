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

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "CommonInterface.h"

#include "BaseWindow.h"

#include "RulesEditor.h"
#include "BordersEditor.h"
#include "SceneEditor.h"
#include "NewSimulationDialog.h"
#include "UpdatableParameters.h"
#include "ParamRecordDialog.h"

#include "Automate.h"

#include "EntreeSortie.h"
#include "PlanHexagonal.h"

class UpdatableParameters;


/** The first window to appear.
 *  Here we will see the running simulation, and we will call every editors and so on.
 */
class MainWindow : public BaseWindow
{
public:
  MainWindow();
  virtual ~MainWindow();

  /******** ripped from granyconsole made by Pad. gc. ********/

  /// This variable is created before execution (because static), so will put the pointer RegleExclusion::_io up-to-date pour make it point to him.
  static RegleIoManager ioRegleIoManager;

  /// Same - and so on.
  static LigneIoManager ioLigneIoManager;
  static RectangleIoManager ioRectangleIoManager;
  static PolygoneIoManager ioPolygoneIoManager;
  static EllipseIoManager ioEllipseIoManager;
  static ArcEllipseIoManager ioArcEllipseIoManager;

  static SceneIoManager ioSceneIoManager;
  static CouleurIoManager ioCouleurIoManager;
  static PhaseIoManager ioPhaseIoManager;
  static PonderationIoManager ioPonderationIoManager;
  static ZonageIoManager ioZonageIoManager;
  static ContientHorsSceneIoManager ioContientHorsSceneIoManager;
  static ContientPhaseIoManager ioContientPhaseIoManager;
  static ColorationIoManager ioColorationIoManager;

  static AutomateIoManager ioAutomateIoManager;
  static CelluleHorsSceneIoManager ioCelluleHorsSceneIoManager;
  static CelluleParoiIoManager ioCelluleParoiIoManager;
  static CelluleAvecParticuleIoManager ioCelluleAvecParticuleIoManager;
  static CelluleGeneratriceIoManager ioCelluleGeneratriceIoManager;

  /****** end ripp ********/

  void drawCells();

private:

  void onToolsSceneEditor();
  void onToolsBordersEditor();
  void onToolsRuleEditor();
  void onToolsUpdatableParameters();
  void onCloseToolsUpdatableParameters();


  void onControlStop();
  void onControlPlay();
  void onControlPause();
  void onControlRecord();

  void onApplyUpdatableParameters();


  void onCloseSceneEditor();
  void onCloseRuleEditor();
  void onCloseBordersEditor();
  
  virtual int delete_event_impl(GdkEventAny*);

  void onFileNew();
  void onOkNewSimulation();
  void onCloseNewSimulation();

  void onOkParamRecord();
  void onCloseParamRecord();

  void onOkFileOpen();
  void onFileSave();
  void onOkFileSaveAs();

  void onNewbieHelp();

  void handleRealize();

  bool handleConfigureDrawingArea(GdkEventConfigure *);
  bool handleExposeDrawingArea(GdkEventExpose *);

  void drawCell(gdouble x, gdouble y, Gdk::Color *, gint taille);
  void fitCells();

  void initColors();

  void registerNewAutomaton();
  void nextStepAutomaton();
  void drawCurrentStep();

  void updateStatusBar();

  Gtk::Widget *_menuUpdatableParameters, *_menuPlay, *_menuPause, *_menuStop, *_menuRecord;

  Gtk::Button     _buttonPlay,_buttonStop,_buttonPause,_buttonRecord;
  Gtk::Image     _imageStop,_imagePlay,_imagePause,_imageRecord;

  SceneEditor     *_winScene;
  BordersEditor *_winBorders;
  RulesEditor     *_winRule;

  UpdatableParameters *_winParamModif;

  NewSimulationDialog *_dialogNewSimulation;
  ParamRecordDialog *_dialogParamRecord;



  // For the automaton.
  Automate _automate, _automatonBeginning;
  string _sceneName;
  int _networkSize;
  int _numberSteps;
  int _seed;
  bool _active;


  // For the drawing area.
  Gtk::DrawingArea _myDrawingArea;
  Glib::RefPtr<Gdk::GC> _myGc;
  Glib::RefPtr<Gdk::Pixmap> _pixmap;

  gdouble _edgex, _edgey, _incr;


  int _displayFrequency;
  int _currentStep;
  bool _play;

  Gtk::ProgressBar _progressing;

  string _fileName;
};



#endif
