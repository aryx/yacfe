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

#ifndef _PARAMRECORDDIALOG_H
#define _PARAMRECORDDIALOG_H

#include "CommonInterface.h"

/** This to enter parameters of the record of a simulation.
 *
 */
class ParamRecordDialog : public Gtk::Dialog
{
public:
  ParamRecordDialog();

  Gtk::Button* get_ok_button();
  

private:
  Gtk::Frame  _frameFileName,_frameParameters;
  Gtk::HBox   _hboxFileName,_hboxDisplayFrequency;
  Gtk::VBox   _vboxFileName;
  Gtk::VBox   _vboxParameters;

  Gtk::Button _buttonOk,_buttonCancel,_buttonBrowse;
  
  Gtk::Entry  _entryFileName,_entryRecordFrequency;
  Gtk::Label  _labelRecordFrequency;

  
};



#endif
