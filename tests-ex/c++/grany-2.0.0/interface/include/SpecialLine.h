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

#ifndef _SPECIALLINE_H_
#define _SPECIALLINE_H_

#include <gtkmm.h>

/** A special Line for the Rules Editor.
 *
 */

class SpecialLine
{
public:
  SpecialLine(Glib::RefPtr<Gdk::GC>, gint x1, gint y1, gint x2, gint y2);


  void ModifyExtremity(gint x1, gint y1,gint x2, gint y2);
  void drawYourself(Glib::RefPtr<Gdk::Pixmap>);
  bool isOn(gint x, gint y);

private:
  gint _x1;
  gint _y1;
  gint _x2;
  gint _y2;
  Glib::RefPtr<Gdk::GC> _gc;
};


#endif
