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

#include "NewbieWindow.h"

NewbieWindow::NewbieWindow(string s)
  : Gtk::Dialog(),
    _frameNewbie(_("A newbie! has occured...")),
    _hboxNewbie(false,0),
    _labelNewbie(s),
    _buttonClose(__("Close"))
{
  set_title("[Grany-3] " + _("Newbie") + "!");
  set_resizable(false);

  _labelNewbie.set_justify(Gtk::JUSTIFY_LEFT);

  get_vbox()->set_border_width(2);
  get_vbox()->pack_start(_frameNewbie);
  
  _frameNewbie.add(_hboxNewbie);
  _frameNewbie.set_border_width(6);

  _hboxNewbie.set_border_width(15);

  _hboxNewbie.pack_end(_labelNewbie); //, false, false, 15);

  get_action_area()->pack_start(_buttonClose, false, false);

  _buttonClose.signal_clicked().connect(slot(*this, &NewbieWindow::on_button_close));
  show_all();
  run();
}

void NewbieWindow::on_button_close()
{
  hide();
}

