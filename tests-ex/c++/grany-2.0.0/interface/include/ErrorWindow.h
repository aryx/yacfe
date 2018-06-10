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

#ifndef _ERRORWINDOW_H
#define _ERRORWINDOW_H

#include "CommonInterface.h"

/** Like WarningWindow, but for an error ;).
 */
class ErrorWindow : public Gtk::Dialog
{
public:
  ErrorWindow(string);

private:
  virtual void on_button_ok();

  Gtk::Image _imageError;
  Gtk::Frame _frameError;
  Gtk::HBox _hboxError;
  Gtk::Button _buttonOk;
  Gtk::Label _labelError;

};



#endif

