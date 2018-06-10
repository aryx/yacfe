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

#include "WarningWindow.h"
#include "AllPixmaps.h"


WarningWindow::WarningWindow(string s)
  : Gtk::Dialog(),
    _imageWarning(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapWarning)),
    _frameWarning(_("Warning message...")),
    _hboxWarning(false,0),
    _buttonOk(__("Ok")),
    _labelWarning(s)
{
  set_title("[Grany-3] "+_("Warning")+"!");
  set_resizable(false);
  
  get_vbox()->set_border_width(2);
  get_vbox()->pack_start(_frameWarning);
  
  _frameWarning.add(_hboxWarning);
  _frameWarning.set_border_width(6);

  _hboxWarning.pack_start(_imageWarning, true, false, 15);
  _hboxWarning.pack_end(_labelWarning, true, false, 15);

  get_action_area()->pack_start(_buttonOk, false, false);

  _buttonOk.set_size_request(60, 20);

  _buttonOk.signal_clicked().connect(slot(*this, &WarningWindow::on_button_ok));

  set_modal(true);
  show_all();
  run();
}

void WarningWindow::on_button_ok()
{
  hide();
}
