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

#include "AboutWindow.h"
#include "AllPixmaps.h"

AboutWindow::AboutWindow()
  : Gtk::Dialog(),
    _buttonClose(__("Close")),
    _hbox(false,0),
#ifdef VERSION
    _frameAbout("Grany-3, "+_("version ")+(string)VERSION),
#endif
#ifndef VERSION
    _frameAbout("Grany-3, "+_("version ")+"??"),
#endif
    /* Ok the first to drop a critic I'll kick his ass!
     * We also can produce free software! :)
     */
    _labelAbout("\n \
 Grany "+_("is a simulator of cellular automata for the granular environments")+" \n \
 \n \
 "+_("Authors")+" : G. Cottenceau, S. Crunchant, P. Garcia, G. Le Guelvouit, X. Michard, Y. Padioleau, Y. Zemali \n \
 Departement Informatique - INSA Rennes \n \
 \n \
 "+_("This program is ")+"`open-source software'. "+_("For further information, consult")+" \"http://www.gnu.org/copyleft/gpl.html\". \n  "),
    _granyApple(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapAbout))

{
  set_title(_("About Grany-3..."));
  set_resizable(false);

  get_vbox()->set_border_width(2);
  get_vbox()->pack_start(_frameAbout);

  _labelAbout.set_justify(Gtk::JUSTIFY_LEFT);

  _frameAbout.add(_hbox);
  _frameAbout.set_border_width(6);

  _hbox.pack_start(_granyApple, true, false, 15);
  _hbox.pack_end(_labelAbout, true, false, 15);

  get_action_area()->pack_start(_buttonClose, false, false);

  _buttonClose.signal_clicked().connect(slot(*this, &AboutWindow::on_button_close));
  show_all();
  run();
}

void AboutWindow::on_button_close()
{
  hide();
}
