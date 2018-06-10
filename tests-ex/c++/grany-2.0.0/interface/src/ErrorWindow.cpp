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

#include "ErrorWindow.h"
#include "AllPixmaps.h"

ErrorWindow::ErrorWindow(string s)
  : Gtk::Dialog(),
    _imageError(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapError)),
    _frameError(_("An error has occured...")),
    _hboxError(false,0),
    _buttonOk(__("Ok")),
    _labelError(s)
{
  set_title("[Grany-3] "+_("Error")+"!");
  set_resizable(false);
  
  get_vbox()->set_border_width(2);
  get_vbox()->pack_start(_frameError);
  
  _frameError.add(_hboxError);
  _frameError.set_border_width(6);

  _hboxError.pack_start(_imageError, true, false, 15);
  _hboxError.pack_end(_labelError, true, false, 15);

  get_action_area()->pack_start(_buttonOk, false, false);

  _buttonOk.signal_clicked().connect(slot(*this, &ErrorWindow::on_button_ok));
  set_modal(true);
  show_all();
  run();
}

void ErrorWindow::on_button_ok()
{
  hide();
}
