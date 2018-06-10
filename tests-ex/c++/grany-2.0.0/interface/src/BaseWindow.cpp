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

#include "BaseWindow.h"
#include "AllPixmaps.h"

using namespace Gtk::Menu_Helpers;
using namespace Gtk::Toolbar_Helpers;


BaseWindow::BaseWindow()
  : BasicWindow(),
    _imageNew(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapNew)),
    _imageOpen(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapOpen)),
    _imageSave(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapSave))
{
  makeFileMenu();

  _imageNew.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageOpen.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageSave.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);

  _buttonNew.add(_imageNew);
  _buttonOpen.add(_imageOpen);
  _buttonSave.add(_imageSave);

  _buttonSave.set_sensitive(false);

  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonNew, _("New")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonOpen, _("Open")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonSave, _("Save")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonHelp, _("Help")));

  _buttonNew.signal_clicked().connect(slot(*this, &BaseWindow::onFileNew));
  _buttonOpen.signal_clicked().connect(slot(*this, &BaseWindow::onFileOpen));
  _buttonSave.signal_clicked().connect(slot(*this, &BaseWindow::onFileSave));

  _vbox.pack_start(_menuBar, false, false);
  _vbox.pack_start(_toolBar, false, false);
  _vbox.pack_end(_statusBar, false, false);

}


BaseWindow::~BaseWindow()
{
  DEBUG_INTERFACE(cout << "[BaseWindow::~BaseWindow] enter" << endl;)
}


void BaseWindow::makeFileMenu()
{

  Gtk::Menu * menu_file = manage(new Gtk::Menu());
  MenuList& list_file = menu_file->items();

  list_file.push_back(MenuElem(_("_New"), Gtk::Menu::AccelKey(_("<alt>n")), slot(*this, &BaseWindow::onFileNew)));
  list_file.push_back(MenuElem(_("_Open"), Gtk::Menu::AccelKey(_("<alt>o")), slot(*this, &BaseWindow::onFileOpen)));
  list_file.push_back(MenuElem(_("_Save"), Gtk::Menu::AccelKey(_("<alt>s")), slot(*this, &BaseWindow::onFileSave))); _menuSave = &(list_file.back());
  list_file.push_back(MenuElem(_("Save as..."), slot(*this, &BaseWindow::onFileSaveAs))); _menuSaveAs = &(list_file.back());
  list_file.push_back(SeparatorElem());
  list_file.push_back(MenuElem(_("_Quit"), Gtk::Menu::AccelKey(_("<alt>q")), slot(*this, &BaseWindow::onFileQuit)));

  _menuBar.items().push_front(MenuElem(_("_File"), Gtk::Menu::AccelKey(_("<alt>f")), *menu_file));

  _menuSave->set_sensitive(false);
  _menuSaveAs->set_sensitive(false);

}

void BaseWindow::onFileNew()
{
  cout << "BaseWindow::onFileNew()" << endl;
}

void BaseWindow::onOkFileOpen()
{
  DEBUG_INTERFACE(cout << "[BaseWindow::onOkFileOpen] enter" << endl;)
  onCloseFileSelection();
}

void BaseWindow::onCancelFileOpen()
{
  DEBUG_INTERFACE(cout << "[BaseWindow::onCancelFileOpen] enter" << endl;)
  delete _winFileSelection;
}

void BaseWindow::onCloseFileSelection()
{
  DEBUG_INTERFACE(cout << "[BaseWindow::onCloseFileSelection]" << endl;)
  InterfaceUtils::closingFileSelection(_winFileSelection);
  delete _winFileSelection;
}


void BaseWindow::onCloseWritingFileSelection()
{
  DEBUG_INTERFACE(cout << "[BaseWindow::onCloseWritingFileSelection]" << endl;)
  InterfaceUtils::closingWritingFileSelection(_winFileSelection);
  delete _winFileSelection;
}


void BaseWindow::onFileOpen()
{
  _winFileSelection = new Gtk::FileSelection(_("Open a file..."));
  _winFileSelection->set_modal(true);
  _winFileSelection->get_ok_button()->signal_clicked().connect(slot(*this, &BaseWindow::onOkFileOpen));
  _winFileSelection->get_cancel_button()->signal_clicked().connect(slot(*this, &BaseWindow::onCancelFileOpen));
  InterfaceUtils::openingFileSelection(_winFileSelection);
  _winFileSelection->show(); 
}


void BaseWindow::onFileSave()
{
}


void BaseWindow::onOkFileSaveAs()
{
  onCloseWritingFileSelection();
}

void BaseWindow::onFileSaveAs()
{
  _winFileSelection = new Gtk::FileSelection(_("Write to a file..."));
  _winFileSelection->set_modal(true);
  _winFileSelection->get_ok_button()->signal_clicked().connect(slot(*this, &BaseWindow::onOkFileSaveAs));
  _winFileSelection->get_cancel_button()->signal_clicked().connect(slot(*this, &BaseWindow::onCancelFileOpen));
  InterfaceUtils::openingWritingFileSelection(_winFileSelection);
  _winFileSelection->show(); 
}


void BaseWindow::onFileQuit()
{
  hide();
}
