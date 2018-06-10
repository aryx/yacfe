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

#ifndef _PARAMPHASEDIALOG_H
#define _PARAMPHASEDIALOG_H

#include "CommonInterface.h"
#include "ErrorWindow.h"
#include "WarningWindow.h"
#include "RulesEditor.h"

#include "Phase.h"

#define RULES_DIR "/files/rules/"

/** To edit all the properties of a given phase.
 *  Sad NB: before, there was lots of objects inside this objects, it was nice. Because
 *  of `huge-objects' problem mainly on sparc I had to move to pointers.
 */

class ParamPhaseDialog : public Gtk::Dialog
{
public:
  ParamPhaseDialog(Phase *, Gdk::Color *);
  ~ParamPhaseDialog();

  Gtk::Button *getButtonOk();

  Gdk::Color * onOk(const vector<Phase *> phases);


private:
  void onCancel();

  /// The Phase we edit through this window.
  Phase *_phase;
  
  Gtk::Notebook *_notebook;

  bool handleKeyPress(GdkEventKey *);


  // First page.
  
  Gtk::VBox     *_vboxGeneral, *_vboxOtherParametersGeneral;
  Gtk::HBox     *_hboxNameGeneral, *_hboxParametersGeneral, *_hboxColorGeneral, *_hboxInertia;

  Gtk::RadioButton *_radioSolidPhase, *_radioFluidPhase;

  Gtk::Label    *_labelTabGeneral;

  Gtk::Label    *_labelNameGeneral;
  Gtk::Entry    *_entryNameGeneral;
  Gtk::Label    *_labelInertia;
  Gtk::Entry    *_entryInertia;

  Gtk::Button   *_buttonColorGeneral;

  Gdk::Color * _phaseColor;

  void onOpenColorSelection();

  void updateColorButtonColor();

  // Second page.
  
  Gtk::HBox *_hboxRule, *_hboxPreRules, *_hboxPostRules;
  Gtk::VBox *_vboxUsableRule, *_vboxSelectedRules, *_vboxPreRules, *_vboxPostRules, *_buttonsPre, *_buttonsPost;

  Gtk::Label *_labelTabRule, *_labelUsableRule, *_labelPreRules, *_labelPostRules, *_labelVoidPre, *_labelVoidPost;

  Gtk::ScrolledWindow *_scrwinPreRules, *_scrwinPostRules, *_scrwinUsableRule;
  int _lastSelectedPreRule, _lastSelectedPostRule, _lastSelectedRowUsable;
  vector<string> _absolutePathUsableRules;

  Gtk::TreeView               *_listPreRules_tv;
  Glib::RefPtr<Gtk::ListStore> _listPreRules_ls;
  Gtk::TreeModelColumn<string> _listPreRules_col;
  class ModelColumns : public Gtk::TreeModel::ColumnRecord {
  public:
    Gtk::TreeModelColumn<string> _name;
    ModelColumns() { add(_name); }
  };
  ModelColumns                 _listPreRules_mc;

  Gtk::TreeView               *_listPostRules_tv;
  Glib::RefPtr<Gtk::ListStore> _listPostRules_ls;
  Gtk::TreeModelColumn<string> _listPostRules_col;
  ModelColumns                 _listPostRules_mc;

  Gtk::TreeView               *_listUsableRules_tv;
  Glib::RefPtr<Gtk::ListStore> _listUsableRules_ls;
  Gtk::TreeModelColumn<string> _listUsableRules_col;
  ModelColumns                 _listUsableRules_mc;

  list<Phase::RegleEtMode> _usedRules;

  Gtk::Button *_buttonNew, *_buttonAddPre, *_buttonAddPost, *_buttonRemovePre, *_buttonRemovePost;

  RulesEditor * _winRuleEditor;
  void onCloseRuleEditor();

  RegleExclusion * openRuleFile(string name);
  void onNewRule();
  void onAddPreRule();
  void onAddPostRule();
  void onRemovePreRule();
  void onRemovePostRule();

  void populateRules();
  int populateWithDir(string dir);

  bool handleButtonPressUsable(GdkEventButton *);
  bool handleButtonPressPreRule(GdkEventButton *);
  bool handleButtonPressPostRule(GdkEventButton *);



  // Third page.

  Gtk::Table *_tablePonderation;
  Gtk::Label *_labelTabPonderation, *_labelN, *_labelS, *_labelNE, *_labelNW, *_labelSE, *_labelSW;

  Gtk::VBox *_vboxN, *_vboxS, *_vboxNE, *_vboxNW, *_vboxSE, *_vboxSW;
  Gtk::Entry *_entryN, *_entryS, *_entryNE, *_entryNW, *_entrySE, *_entrySW;
  

  Gtk::Button *_buttonOK, *_buttonCancel;
  

  void popupErrorWindow(const string &s);
  
  void popupWarningWindowFromConstructor(const string &s);

  
};


#endif

