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

#ifndef _ZONINGEDITOR_H
#define _ZONINGEDITOR_H

#include "AreaEditor.h"
#include "Phase.h"

/** Class for our zoning editor.
 *  Inherits from AreaEditor, like ColorationEditor, coz it has lots of things
 *  in common.
 */

class ZoningEditor : public AreaEditor
{
public:

  /// The constructor will permit having the lists of borders, phases, and initial zonings.
  ZoningEditor(vector<Phase*>, list<Frontiere*>, list<Zonage*>);
  ~ZoningEditor();

  list<Zonage*> getListZonage();


private:

  Gdk::Color * createColorFromSliders();

  vector<PhasePourcent> percentageCurrentPhases();
  vector<PhasePourcent> * findPhasePercentage(GtkForm *);
  void modifySlidersPositions(vector<PhasePourcent> *);

  /// Do we have at least a little bit of one phase ?
  bool slidersAtLeastOne();

  virtual bool handleButtonPress(GdkEventButton *);
  virtual bool handleButtonRelease(GdkEventButton *);
  virtual bool handleMotionNotify(GdkEventMotion *);

  virtual void deleteSelectedArea();

  virtual void onActivateNew();
  void onNewbieHelp();

  void onActivateApplyMix();

  void createFormZoning(FormeFermee *, ContientPhase *);

  vector<Gtk::Adjustment*> _slidersPhases;

  Gtk::Label _labelMix;
  Gtk::Button _buttonApplyMelange;

  vector<Phase*> _phases;
  list<Zonage*> _listZonage;
};



#endif
