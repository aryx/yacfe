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

#include "BasicWindow.h"
#include "AllPixmaps.h"

using namespace Gtk::Menu_Helpers;
using namespace Gtk::Toolbar_Helpers;

BasicWindow::BasicWindow()
  : Gtk::Window(Gtk::WINDOW_TOPLEVEL),
    _imageHelp(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapHelp))

{
  _winApropos = NULL;
  _error = NULL;
  _warning = NULL;
  _newbie = NULL;

  add(_vbox);

  _imageHelp.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);

  _buttonHelp.add(_imageHelp);
  _buttonHelp.set_sensitive(false);

  _buttonHelp.signal_clicked().connect(slot(*this, &BasicWindow::onHelp));

}

BasicWindow::~BasicWindow()
{
}

void BasicWindow::makeHelpMenu()
{
  Gtk::Menu * menu_help = manage(new Gtk::Menu());
  MenuList& list_help = menu_help->items();

  list_help.push_back(MenuElem(_("About _Grany"), slot(*this, &BasicWindow::onHelpAbout)));
  list_help.push_back(SeparatorElem());
  list_help.push_back(MenuElem(_("Ne_wbie help!"), slot(*this, &BasicWindow::onNewbieHelp)));

  _menuBar.items().push_back(MenuElem(_("_Help"), Gtk::Menu::AccelKey(_("<alt>h")), *menu_help));
  _menuBar.items().back().set_right_justified();
}


void BasicWindow::onHelpAbout()
{
  AboutWindow a;
}

void BasicWindow::onNewbieHelp()
{
  popupNewbieHelp(_("Sorry, no newbie help available in this window."));
}

void BasicWindow::onHelpContents()
{
}

void BasicWindow::onHelpIndex()
{
}

void BasicWindow::onHelp()
{
}

// This is a cool thing for every window
void BasicWindow::popupErrorWindow(const string &s)
{
  ErrorWindow e(s);
}

static bool _warningEnabled = true;

// This is a cool thing for every window
void BasicWindow::popupWarningWindow(const string &s)
{
  if (_warningEnabled)
    WarningWindow w(s);
}

// static
void BasicWindow::setWarningMessages(bool yes_or_no)
{
  _warningEnabled = yes_or_no;
}

// This is a cool thing for every window
void BasicWindow::popupNewbieHelp(const string &s)
{
  NewbieWindow n(s);
}
