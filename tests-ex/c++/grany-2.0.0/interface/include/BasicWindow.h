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

#ifndef _BASICWINDOW_H
#define _BASICWINDOW_H

#include "CommonInterface.h"

#include "AboutWindow.h"
#include "ErrorWindow.h"
#include "WarningWindow.h"
#include "NewbieWindow.h"


/** Top-level class inheriting from Gtk::Window.
 *  It has stuff common to all windows except the Gtk::Dialog ones: help system,
 *  warning/error messages, toolbar, statusbar.
 */

class BasicWindow : public Gtk::Window
{
public:
  BasicWindow();
  virtual ~BasicWindow();

  static void setWarningMessages(bool);

protected:
  void onHelpAbout();
  virtual void onNewbieHelp();  // redefined in the window classes providing newbie help!
  void onHelpContents();
  void onHelpIndex();
  void onHelp();

  void onCloseAbout();

  void makeHelpMenu();

  void popupErrorWindow(const string &);

  void popupWarningWindow(const string &);

  void onCloseNewbieHelp();
  void popupNewbieHelp(const string &);


protected:
  Gtk::VBox        _vbox;
  Gtk::Statusbar   _statusBar;
  guint           _contexteStatusBar;

  Gtk::MenuBar _menuBar;

  Gtk::Toolbar   _toolBar;


  AboutWindow *_winApropos; 


  Gtk::Button _buttonHelp;
  Gtk::Image _imageHelp;


  ErrorWindow * _error;
  WarningWindow * _warning;
  NewbieWindow * _newbie;
};



#endif

