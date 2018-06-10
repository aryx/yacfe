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

#ifndef _BASEWINDOW_H
#define _BASEWINDOW_H

#include "BasicWindow.h"

/** One of our top-level classes.
 *  This is a sub-class of BasicWindow intended for windows with a little bit
 *  more stuff, as some new/save/save-as pixmaps etc.
 */

class BaseWindow : public BasicWindow
{
public:
  BaseWindow();
  virtual ~BaseWindow();


protected:
  virtual void onFileNew();
  void onFileOpen();
  virtual void onFileSave();
  void onFileSaveAs();
  virtual void onFileQuit();


  virtual void onOkFileOpen();
  virtual void onCancelFileOpen();
  virtual void onOkFileSaveAs();
  void onCloseFileSelection();
  void onCloseWritingFileSelection();

  void makeFileMenu();


protected:

  Gtk::FileSelection *_winFileSelection;

  //  Gtk::ObjectHandle<Gtk_MenuItem> _handleMenuItem;

  Gtk::Toolbar _toolbar;
  Gtk::Button _buttonNew, _buttonOpen, _buttonSave;
  Gtk::Image _imageNew, _imageOpen, _imageSave;

  Gtk::Widget * _menuSave, * _menuSaveAs;

};



#endif

