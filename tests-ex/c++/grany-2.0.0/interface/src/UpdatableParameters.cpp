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

#include "UpdatableParameters.h"

UpdatableParameters::UpdatableParameters(MainWindow * caller, string nbr_steps, string displ_freq, list<Phase*> phases)
  : BasicWindow(),
    _frameGeneral(_("General")),
    _framePhase(_("Phases")),
    _vboxGeneral(true,5),
    _hboxNumberSteps(true,5),
    _hboxDisplayFrequency(true,5),
    _hboxGeneralButtons(true,5),
    _labelNumberSteps(_("Number of steps")),
    _labelDisplayFrequency(_("Display frequency")),
    _hboxPhase(true,5),
    _vboxButtons(true,5),
    _buttonApply(__("Apply changes")),
    _buttonModify(__("Modify"))
{
  _dialogParamPhase = NULL;

  set_title(_("Updatable parameters"));

  _vbox.set_border_width(2);

  _vbox.pack_start(_frameGeneral);
  _vbox.pack_start(_framePhase);

  _frameGeneral.add(_vboxGeneral);
  _frameGeneral.set_border_width(6);


  _vboxGeneral.pack_start(_hboxNumberSteps, false, false, 10);
  _vboxGeneral.pack_start(_hboxDisplayFrequency, false, false, 10);
  _vboxGeneral.pack_end(_hboxGeneralButtons, false, false, 10);

  _hboxNumberSteps.pack_start(_labelNumberSteps, false, false, 10);
  _hboxNumberSteps.pack_end(_entryNumberSteps, false, false, 10);

  _hboxDisplayFrequency.pack_start(_labelDisplayFrequency, false, false, 10);
  _hboxDisplayFrequency.pack_end(_entryDisplayFrequency, false, false, 10);

  _hboxGeneralButtons.pack_start(_buttonApply, false, false, 10);
  
  _framePhase.add(_hboxPhase);
  _framePhase.set_border_width(6);


  _hboxPhase.pack_start(_scrwinPhase);

  _gtklistPhase_tv = new Gtk::TreeView();
  _gtklistPhase_ls = Gtk::ListStore::create(_gtklistPhase_mc);
  _gtklistPhase_tv->set_model(_gtklistPhase_ls);
  _gtklistPhase_tv->append_column("dummy", _gtklistPhase_mc._name);
  _gtklistPhase_tv->set_headers_visible(false);
  _gtklistPhase_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);
  _scrwinPhase.add(*_gtklistPhase_tv);
  _scrwinPhase.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  _hboxPhase.pack_end(_vboxButtons, false, false, 10);

  _vboxButtons.pack_start(_buttonModify, false, false, 10);

  _buttonModify.signal_clicked().connect(slot(*this, &UpdatableParameters::onModifySelectedPhase));
  _modifiedPhase = NULL; _numModifiedPhase = -1; _lastSelectedRow = -1;

  _gtklistPhase_tv->signal_button_press_event().connect(slot(*this, &UpdatableParameters::handleButtonPress), false);
  _gtklistPhase_tv->set_events(Gdk::BUTTON_PRESS_MASK);

  updateValues(nbr_steps, displ_freq, phases);

  _caller = caller;

  signal_key_press_event().connect(slot(*this, &UpdatableParameters::handleKeyPress));
  set_events(Gdk::KEY_PRESS_MASK);

  _entryNumberSteps.grab_focus();
}


void UpdatableParameters::updateValues(string nbr_steps, string displ_freq, list<Phase*> used_phases)
{
  _entryNumberSteps.set_text(nbr_steps);
  _entryDisplayFrequency.set_text(displ_freq);

  _phases.clear();
  _gtklistPhase_ls->clear();

  for (list<Phase*>::iterator it = used_phases.begin() ; it != used_phases.end() ; it++) {
    _phases.push_back(*it);
    Gtk::TreeModel::Row row = *(_gtklistPhase_ls->append());
    row[_gtklistPhase_mc._name] = (*it)->getNom();
  }
}


Gtk::Button* UpdatableParameters::getApplyButton()
{
  return &_buttonApply;
}


string UpdatableParameters::getNumberSteps()
{
  return _entryNumberSteps.get_text();
}


string UpdatableParameters::getDisplayFrequency()
{
  return _entryDisplayFrequency.get_text();
}


void UpdatableParameters::numberStepsInvalid()
{
  _entryNumberSteps.select_region(0, _entryNumberSteps.get_text_length());
  _entryNumberSteps.grab_focus();
}


void UpdatableParameters::displayFrequencyInvalid()
{
  _entryDisplayFrequency.select_region(0, _entryDisplayFrequency.get_text_length());
  _entryDisplayFrequency.grab_focus();
}


void UpdatableParameters::modifyNumberedPhase()
{
  for (unsigned int i=0 ; i<_phases.size() ; i++)
    if ((int)i == _numModifiedPhase)
      _modifiedPhase = _phases[i];

  g_assert(_modifiedPhase != NULL);
  
  _dialogParamPhase = new ParamPhaseDialog(_modifiedPhase, InterfaceUtils::getColor(_modifiedPhase->getCouleur()));
  
  _dialogParamPhase->signal_hide().connect(slot(*this, &UpdatableParameters::onCloseModifyPhase));
  _dialogParamPhase->getButtonOk()->signal_clicked().connect(slot(*this, &UpdatableParameters::onOkModifyPhase));
  
  _dialogParamPhase->show_all();
}


void UpdatableParameters::onModifySelectedPhase()
{
  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  if (iter) {
    _numModifiedPhase = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
    modifyNumberedPhase();
  } else
    popupErrorWindow(_("No phase selected."));
}

void UpdatableParameters::onDestroyModifyPhase()
{
  g_assert(_modifiedPhase != NULL);
  _modifiedPhase = NULL;
}

void UpdatableParameters::onCloseModifyPhase()
{
  delete _dialogParamPhase;
  _dialogParamPhase = NULL;
}


void UpdatableParameters::onOkModifyPhase()
{
  DEBUG_INTERFACE(cout << "[UpdatableParameters::onOkModifyPhase] enter" << endl;);

  g_assert(_modifiedPhase != NULL);

  Gdk::Color * new_color_for_phase = _dialogParamPhase->onOk(_phases);

  if (new_color_for_phase == NULL)
    return;

  InterfaceUtils::addColor(_modifiedPhase->getCouleur(), new_color_for_phase->get_red(), new_color_for_phase->get_green(), new_color_for_phase->get_blue());

  Gtk::TreeModel::Row row = *(_gtklistPhase_ls->get_iter(InterfaceUtils::intToString(_numModifiedPhase)));
  row[_gtklistPhase_mc._name] = _modifiedPhase->getNom();

  _modifiedPhase = NULL;
  _numModifiedPhase = -1;

  onCloseModifyPhase();

  // -> Process the phi of the phases
  double phi_phases_solid = 0.01;
  double phi_phases_fluid = PHI_SOLIDE + 0.01;
  for (unsigned int i=0 ; i< _phases.size() ; i++)
    {
      // Solid ?
      if (_phases[i]->getPhi() < PHI_SOLIDE)
	{
	  _phases[i]->setPhi(phi_phases_solid);
	  phi_phases_solid += 0.01;
	}
      // Fluid ?
      if (_phases[i]->getPhi() >= PHI_SOLIDE)
	{
	  _phases[i]->setPhi(phi_phases_fluid);
	  phi_phases_fluid += 0.01;
	}
    }

  // Redraw is requested because the color of the phase may have changed.
  _caller->drawCells();
}



bool UpdatableParameters::handleButtonPress(GdkEventButton *event)
{
  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  // We want to intercept double-click to call the Property dialog.
  if (event->type == GDK_2BUTTON_PRESS) {
    if (iter) {
      _numModifiedPhase = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
      modifyNumberedPhase();
    } else {
      // means no row is currently selected, but we want to edit the properties! make use of _lastSelectedRow
      if (_lastSelectedRow == -1)
	return false;
      _numModifiedPhase = _lastSelectedRow;
      
      modifyNumberedPhase();
    }
  } else
    // We store the last selected row because a double-click can lead to an unselected row properties invocation
    if (iter)
      _lastSelectedRow = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));

  return false;
}


bool UpdatableParameters::handleKeyPress(GdkEventKey *event)
{
  // This is `enter' and `numeric keypad enter'
  if ((event->keyval == 65293) || (event->keyval == 65421))
    _buttonApply.activate();

  // This is `escape'.
  if (event->keyval == 65307)
    hide();

  return false; // for gtk to edit the entries!!
}
