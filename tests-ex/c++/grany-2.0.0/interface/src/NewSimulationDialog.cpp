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

#include "NewSimulationDialog.h"
#include "InterfaceUtils.h"


NewSimulationDialog::NewSimulationDialog(string nom_scene, string dim_reseau, string nbre_pas, string germe)
  : Gtk::Dialog(),
    _frameSceneName(_("Scene name")),
    _frameParameters(_("Parameters")),
    _hboxSceneName(true,5),
    _hboxNetworkSize(true,5),
    _hboxNumberSteps(true,5),
    _hboxSeed(true,5),
    _vboxScene(true,5),
    _vboxParameters(true,5),
    
    _buttonOk(_("Ok")),
    _buttonCancel(_("Cancel")),
    _buttonBrowse(_("Browse...")),
   
    _labelNetworkSize(_("Network size")),
    _labelNumberSteps(_("Number of steps")),
    
    _labelSeed(_("Seed"))

{
  DEBUG_INTERFACE(cout << "[NewSimulationDialog::NewSimulationDialog()]" << endl;);

  set_title(_("New simulation"));
  set_resizable(false);

  get_vbox()->set_border_width(2);

  get_vbox()->pack_start(_frameSceneName, false, false, 5);
  get_vbox()->pack_start(_frameParameters, false, false, 5);
  
  _frameSceneName.add(_vboxScene);
  _vboxScene.pack_start(_hboxSceneName, false, false, 5);
  _frameSceneName.set_border_width(6);
  
  _hboxSceneName.pack_start(_entrySceneName, false, false, 5);
  _hboxSceneName.pack_end(_buttonBrowse, true, true, 5);

  _frameParameters.add(_vboxParameters);
  _frameParameters.set_border_width(6);

  _vboxParameters.pack_start(_hboxNetworkSize, false, false, 5);
  _vboxParameters.pack_start(_hboxNumberSteps, false, false, 5);
  _vboxParameters.pack_end(_hboxSeed, false, false, 5);


  _hboxNetworkSize.pack_start(_labelNetworkSize, false, false, 5);
  _hboxNetworkSize.pack_end(_entryNetworkSize, false, false, 5);
  
  _hboxNumberSteps.pack_start(_labelNumberSteps, false, false, 5);
  _hboxNumberSteps.pack_end(_entryNumberSteps, false, false, 5);
  
  _hboxSeed.pack_start(_labelSeed, false, false, 5);
  _hboxSeed.pack_end(_entrySeed, false, false, 5);
  

  get_action_area()->pack_start(_buttonOk, true, true, 5);
  get_action_area()->pack_end(_buttonCancel, true, true, 5);

  _buttonBrowse.signal_clicked().connect(slot(*this, &NewSimulationDialog::onBrowse));

  _entrySceneName.set_text (nom_scene);
  _entryNetworkSize.set_text(dim_reseau);
  _entryNumberSteps.set_text  (nbre_pas);
  _entrySeed.set_text    (germe);

  signal_key_press_event().connect(slot(*this, &NewSimulationDialog::handleKeyPress));
  set_events(Gdk::KEY_PRESS_MASK);

  _entrySceneName.grab_focus(); // cursor will appear here, nice

}

Gtk::Button* NewSimulationDialog::getButtonOk()
{
  return &_buttonOk;
}

Gtk::Button* NewSimulationDialog::getCancelButton()
{
  return &_buttonCancel;
}

Gtk::Button* NewSimulationDialog::getBrowseButton()
{
  return &_buttonBrowse;
}

string NewSimulationDialog::getSceneName()
{
  return _entrySceneName.get_text();
}

string NewSimulationDialog::getNetworkSize()
{
  return _entryNetworkSize.get_text();
}

string NewSimulationDialog::getNumberSteps()
{
  return _entryNumberSteps.get_text();
}

string NewSimulationDialog::getSeed()
{
  return _entrySeed.get_text();
}

void NewSimulationDialog::sceneNameInvalod()
{
  _entrySceneName.select_region(0,_entrySceneName.get_text_length());
  _entrySceneName.grab_focus();
}

void NewSimulationDialog::networkSizeInvalid()
{
  _entryNetworkSize.select_region(0,_entryNetworkSize.get_text_length());
  _entryNetworkSize.grab_focus();
}

void NewSimulationDialog::numberStepsInvalid()
{
  _entryNumberSteps.select_region(0,_entryNumberSteps.get_text_length());
  _entryNumberSteps.grab_focus();
}

void NewSimulationDialog::seedInvalid()
{
  _entrySeed.select_region(0,_entrySeed.get_text_length());
  _entrySeed.grab_focus(); // cool staff that allows to edit directly here in the correct location
}

void NewSimulationDialog::onBrowse()
{
  Gtk::FileSelection fs(_("Open a scene file..."));

  fs.set_modal(true);

  InterfaceUtils::openingFileSelection(&fs);

  fs.show(); 

  if (fs.run() == Gtk::RESPONSE_OK)
    _entrySceneName.set_text(fs.get_filename());

  InterfaceUtils::closingFileSelection(&fs);
}

bool NewSimulationDialog::handleKeyPress(GdkEventKey *event)
{
  if (event->length <= 0)
    return false;

  // This is `enter' and `numeric keypad enter'
  if ((event->keyval == 65293) || (event->keyval == 65421))
    _buttonOk.activate();

  // This is `escape'.
  if (event->keyval == 65307)
    _buttonCancel.activate();

  return false; // for gtk to edit the entries!!
}
