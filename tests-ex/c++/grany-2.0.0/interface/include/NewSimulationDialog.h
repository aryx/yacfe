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

#ifndef _NEWSIMULATIONDIALOG_H
#define _NEWSIMULATIONDIALOG_H

#include "CommonInterface.h"

/** Inherited from Gtk::Dialog for the options of a new simulation given s scene.
 *
 */

class NewSimulationDialog : public Gtk::Dialog
{
public:
  NewSimulationDialog(string nom_scene = "", string dim_reseau = "", string nbre_pas = "", string germe = "");

  Gtk::Button* getButtonOk();
  Gtk::Button* getCancelButton();
  Gtk::Button* getBrowseButton();

  string getSceneName();
  string getNetworkSize();
  string getNumberSteps();
  string getSeed();

  void sceneNameInvalod();
  void networkSizeInvalid();
  void numberStepsInvalid();
  void seedInvalid();

  bool handleKeyPress(GdkEventKey *);

private:
  Gtk::Frame  _frameSceneName,_frameParameters;
  Gtk::HBox   _hboxSceneName,_hboxNetworkSize,_hboxNumberSteps,_hboxSeed;
  Gtk::VBox   _vboxScene;
  Gtk::VBox   _vboxParameters;

  Gtk::Button _buttonOk,_buttonCancel,_buttonBrowse;
  
  Gtk::Entry  _entrySceneName,_entryNetworkSize,_entryNumberSteps,_entrySeed;
  Gtk::Label  _labelNetworkSize,_labelNumberSteps,_labelSeed;


  void onBrowse();
  
};



#endif
