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

#ifndef _SCENEEDITOR_H
#define _SCENEEDITOR_H

#include "CommonInterface.h"

#include "BaseWindow.h"

#include "ParamPhaseDialog.h"
#include "ZoningEditor.h"
#include "BordersEditor.h"
#include "ColorationEditor.h"
#include "GranyDrawingArea.h"
#include "Phase.h"

/** The biggest editor, which can call all other ones, and permits creating a scene.
 *
 */
class SceneEditor : public BaseWindow
{
public:
  SceneEditor();
  ~SceneEditor();

private:
  Gtk::Notebook *_notebook;
  Gtk::FileSelection * _winFileSelectionInterne;
  Gdk::Color *_colorClassicalBorder, *_colorGeneratingBorder;

  void onCloseFileSelectionInterne();
  void onFileNew();
  void onOkFileOpen();
  bool convertsToScene();
  void onFileSave();
  void onOkFileSaveAs();

  string _fileName;
  Scene _scene;

  void initColors();
  void onNewbieHelp();

  // First notebook page : "Borders"
  Gtk::HBox *_hboxFrontiere;
  GranyDrawingArea *_zonePrevisualisationFrontieres;
  Gtk::VBox *_vboxBoutonsFrontiere;

  Gtk::Button *_buttonNewFrontiere, *_buttonOpenFrontiere, *_buttonModifyFrontiere;
  Gtk::Label *_labelTabFrontiere;

  BordersEditor * _winBorders;

  void numberOfPhasesChanged();

  void onNouveauFrontiere();
  void onOuvrirFrontiere();
  void onOkOuvrirFrontiere();
  void onModifierFrontiere();
  void onCloseBordersEditor();
    
  bool handleButtonPressBorders(GdkEventButton *);

  void createFormBorder(Forme *, Frontiere::TypeParoi);


  // Second notebook page : "Phases"
  Gtk::VBox *_vboxPhase;
  Gtk::HBox *_hboxPhase;
  Gtk::ScrolledWindow *_scrwinPhase;
  Gtk::VBox *_vboxBoutonsPhase;

  Gtk::TreeView               *_gtklistPhase_tv;
  Glib::RefPtr<Gtk::ListStore> _gtklistPhase_ls;
  Gtk::TreeModelColumn<string> _gtklistPhase_col;
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:
    Gtk::TreeModelColumn<string> _name;
    ModelColumns() { add(_name); }
  };
  ModelColumns                        _gtklistPhase_mc;

  Gtk::Button *_buttonNewPhase, *_buttonProprietePhase, *_buttonDeletePhase;
  Gtk::ToggleButton *_buttonPropagativePhase, *_buttonGenereePhase;
  Gtk::Label *_labelTabPhase;
  Gtk::Label *_labelNbPhases;

  vector<Phase*> _listePhases;
  Phase * _phaseNouvelle, * _phaseEditee;
  int _numModifiedPhase;
  int _lastSelectedRow;

  int _numPropagative, _numGeneree;
  Gdk::Color *_colorPhasePropagative, *_colorPhaseGeneree;

  // TODO it could be nice to edit properties of several phases at the same time.
  ParamPhaseDialog *_dialogParamPhase;

  void openParamPhase(Phase *);
  void onNewPhase();
  void onPhaseProperties();
  void onDeletePhase();

  void onClosePhaseProperties();
  void onCancelPhaseProperties();
  void onOkPhaseProperties();
  void onPropagativePhase();
  void onGeneratedPhase();

  bool handleButtonPressPhases(GdkEventButton *);
  bool handleKeyPressPhases(GdkEventKey *);

  void setToggledButtonsAccordingToSelectedPhase();

  void onSelectionChanged();

  bool _noRecursiveCall;


  // Third notebook page : "Zoning"
  Gtk::HBox *_hboxZonage;
  GranyDrawingArea *_zonePrevisualisationZonage;
  Gtk::VBox *_vboxBoutonsZonage;

  Gtk::Button *_buttonModifyZonage;
  Gtk::Label *_labelTabZonage;

  ZoningEditor *_winEditeurZonage;

  void onModifyZoning();
  void onCloseZoning();

  void createFormZoning(FormeFermee *, ContientPhase *);
  
  bool handleButtonPressZoning(GdkEventButton *);


  // Fourth notebook page : "Coloration"
  Gtk::HBox *_hboxColoration;
  GranyDrawingArea *_zonePrevisualisationColoration;
  Gtk::VBox *_vboxBoutonsColoration;

  Gtk::Button *_buttonModifyColoration;
  Gtk::Label *_labelTabColoration;

  ColorationEditor *_winColorationEditor;

  void onModifyColoration();
  void onCloseColoration();

  void createFormColoration(FormeFermee *, int);
  
  bool handleButtonPressColoration(GdkEventButton *);
  
};



#endif
