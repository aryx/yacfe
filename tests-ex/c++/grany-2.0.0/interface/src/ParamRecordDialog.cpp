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

#include "ParamRecordDialog.h"

ParamRecordDialog::ParamRecordDialog()
  : Gtk::Dialog(),
    _frameFileName(_("Name of output file")),
    _frameParameters(_("Parameters")),
    _hboxFileName(true,5),
    _hboxDisplayFrequency(true,5),
    _vboxFileName(true,5),
    _vboxParameters(true,5),

    _buttonOk(_("Ok")),
    _buttonCancel(_("Cancel")),
    _buttonBrowse(_("Browse...")),
   
    _labelRecordFrequency(_("Network size"))
   
{
  set_title(_("Recording parameters"));

  set_default_size(350,180);
  get_vbox()->set_border_width(2);


  Gtk::Label * my_lab = new Gtk::Label(_("Sorry, not implemented."));

  get_vbox()->pack_start(*my_lab);
  /*
  get_vbox()->pack_start(_frameFileName);
  get_vbox()->pack_start(_frameParameters);
  
  _frameFileName.add(_vboxFileName);
  _frameFileName.set_border_width(6);

  _vboxFileName.pack_start(_hboxFileName,true,false);

  
  _hboxFileName.pack_start(_entryFileName);
  _hboxFileName.pack_end(_buttonBrowse);

  _frameParameters.add(_vboxParameters);
  _frameParameters.set_border_width(6);

  _vboxParameters.pack_start(_hboxDisplayFrequency);


  _hboxDisplayFrequency.pack_start(_labelRecordFrequency);
  _hboxDisplayFrequency.pack_end(_entryRecordFrequency);
  */
  get_action_area()->pack_start(_buttonOk);
  //  get_action_area()->pack_end(_buttonCancel);
  
}



Gtk::Button* ParamRecordDialog::get_ok_button()
{
  return &_buttonOk;
}





