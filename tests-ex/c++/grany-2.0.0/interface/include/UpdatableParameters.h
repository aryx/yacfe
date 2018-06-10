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

#ifndef _UPDATABLEPARAMETERS_H
#define _UPDATABLEPARAMETERS_H

#include "CommonInterface.h"
#include "ErrorWindow.h"
#include "ParamPhaseDialog.h"
#include "BasicWindow.h"
#include "MainWindow.h"

class MainWindow;


/** To enter the during-simulation-updatable-parameters.
 *  This small panel is intended to be used together with the still active main window. Then the user will modify parameters `real-time'.
 */

class UpdatableParameters : public BasicWindow
{
public:
  /// Default constructor will allow calling without already specified values.
  UpdatableParameters(MainWindow *, string nbr_steps = "", string displ_freq = "", list<Phase*> phases = list<Phase*>());

  /// Used when the automaton is modified in the caller's window.
  void updateValues(string nbr_steps, string displ_freq, list<Phase*> used_phases);

  /// The caller will use this method for connecting an event to the button press.
  Gtk::Button* getApplyButton();

  /// The window calling UpdatableParameters will use this method to reclaim the number of steps entered.
  string getNumberSteps();

  /// The window calling UpdatableParameters will use this method to reclaim the display frequency entered.
  string getDisplayFrequency();

  /// The window calling UpdatableParameters will use this method to signify to UpdatableParameters the problem, asking it to alert the user by a way (selecting the failing region).
  void numberStepsInvalid();

  /// The window calling UpdatableParameters will use this method to signify to UpdatableParameters the problem, asking it to alert the user by a way (selecting the failing region).
  void displayFrequencyInvalid();


private:

  void modifyNumberedPhase();
  void onModifySelectedPhase();
  void onOkModifyPhase();
  void onCloseModifyPhase();
  void onDestroyModifyPhase();
  
  bool handleButtonPress(GdkEventButton *);
  bool handleKeyPress(GdkEventKey *event);

  Gtk::Frame _frameGeneral,_framePhase;
  
  Gtk::VBox _vboxGeneral;
  Gtk::HBox _hboxNumberSteps, _hboxDisplayFrequency, _hboxGeneralButtons;

  Gtk::Label _labelNumberSteps,_labelDisplayFrequency;
  Gtk::Entry _entryNumberSteps,_entryDisplayFrequency;

  Gtk::HBox  _hboxPhase;

  Gtk::ScrolledWindow _scrwinPhase;

  Gtk::VBox  _vboxButtons;
  
  Gtk::Button _buttonApply,_buttonModify;

  vector<Phase*> _phases;
  int _numModifiedPhase;
  int _lastSelectedRow;

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

  Phase * _modifiedPhase;
  ParamPhaseDialog * _dialogParamPhase;

  MainWindow * _caller;

};

#endif
