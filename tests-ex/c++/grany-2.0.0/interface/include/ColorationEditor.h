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

#ifndef _COLORATIONEDITOR_H
#define _COLORATIONEDITOR_H

#include "AreaEditor.h"

/** Class for our coloration editor.
 *  Inherits from AreaEditor, like ZoningEditor, coz it has lots of things
 *  in common.
 */
class ColorationEditor : public AreaEditor
{
public:

  ColorationEditor(list<Frontiere*>, list<Zonage*>, list<Coloration*>);
  ~ColorationEditor();

  list<Coloration*> getListColoration();


private:

  int findColorOfSelectedArea();
  void updateColorButton(int color);
  void updateColorButtonAccordingToSelectedArea();

  virtual bool handleButtonPress(GdkEventButton *);
  virtual bool handleButtonRelease(GdkEventButton *);
  virtual bool handleMotionNotify(GdkEventMotion *);

  virtual void deleteSelectedArea();

  virtual void onActivateNew();
  void onNewbieHelp();

  void onActivateColor();
  void onActivateRandomize();

  void createFormZoning(FormeFermee *, ContientPhase *);
  void createFormColoration(FormeFermee *, int);

  Gtk::Button _buttonColor, _buttonRandomize;
  int _currentColor;

  list<Coloration*> _listColoration;
};



#endif
