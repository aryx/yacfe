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

#ifndef _NEWBIEWINDOW_H
#define _NEWBIEWINDOW_H

#include "CommonInterface.h"

/** Self-documented class name.
 */
class NewbieWindow : public Gtk::Dialog
{
public:
  NewbieWindow(string);

private:
  virtual void on_button_close();

  Gtk::Frame _frameNewbie;
  Gtk::HBox _hboxNewbie;
  Gtk::Label _labelNewbie;
  Gtk::Button _buttonClose;
};



#endif

