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

#ifndef _ABOUTWINDOW_H
#define _ABOUTWINDOW_H

#include "CommonInterface.h"

/** Class for displaying the `About' common to all applications.
 *
 */

class AboutWindow : public Gtk::Dialog
{
public:
  AboutWindow();


private:
  virtual void on_button_close();

  Gtk::Button _buttonClose;
  Gtk::HBox _hbox;
  Gtk::Frame _frameAbout;
  Gtk::Label _labelAbout;
  Gtk::Image _granyApple;
};

#endif
