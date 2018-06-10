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

#ifndef _GTKFIGURES_H_
#define _GTKFIGURES_H_

#include "CommonInterface.h"
#include "Figures.h"

#define TOLERANCE_SELECTION 5


/* All the figures for Gtk. Multiple inheritance provided by Pad. All to do in 1 day 1/2. Fuckit. gC.
 *
 */


/** Figures for Gtk, mother-class.
 *  We specify all the things we want to make drawings possible, together with moves, etc.
 */

class GtkForm
{
public:
  GtkForm();
  virtual ~GtkForm();

  /// Basically, that's: `is the form good enough ?'  
  virtual bool isInvalid() = 0;

  /// Set the drawing color of the form.
  void setColor(Gdk::Color *);

  /// Set the `selection' state of the form.
  void setSelection(bool);

  /// Set the `preselection' state of the form.
  void setPreSelection(bool);

  /// Set the `temporary' state of the form.
  void setTemporary(bool);

  /// Get the max x of the form.
  virtual unsigned int getMaxX() const = 0;

  /// Get the max y of the form.
  virtual unsigned int getMaxY() const = 0;

  /// Is this point on your shape, ms. form ?
  virtual bool isOn(gint x, gint y) = 0;

  /// Is this point inside your shape, ms. form ?
  virtual bool isInside(gint x, gint y) = 0;

  /// Please draw your shape, ms. form.
  virtual void drawYourself(Glib::RefPtr<Gdk::Pixmap>) = 0;

  /// Please fill your shape, ms. form.
  virtual void fillYourself(Glib::RefPtr<Gdk::Pixmap>) = 0;

  /// Set the color for every selected form.
  static void setColorPreSelection(Gdk::Color *);

  /// Set the Gdk Graphical Context.
  static void setGcGlobal(Glib::RefPtr<Gdk::GC>);

  /// Get the Gdk Graphical Context.
  static Glib::RefPtr<Gdk::GC> getGcGlobal();

  /// Setup which Gtk::Window is base for the Tile I use for the selection of a filled form.
  static void setTile(Glib::RefPtr<Gdk::Window>);

  /// Set the global context to `selection of a border'.
  static void makeContextSelectionBorder(Gdk::Color *);

  /// Set the global context to `selection of a zoning'.
  static void makeContextSelectionZoning(Gdk::Color *);

  /// Set the global context to `preselection'.
  static void makeContextPreSelection();

  /// Set the global context to `temporary'.
  static void makeContextTemporary();

  /// Restore basic context.
  static void makeContextNormal(Gdk::Color *);

protected:
  Glib::RefPtr<Gdk::GC> _gc;
  Gdk::Color * _color;
  bool _selection;
  bool _preSelection;
  bool _temporary;
};



// Figures for Gtk, instantiables classes.


/** My Line.
 *
 */

class GtkLine : public Ligne, public GtkForm
{
public:
  GtkLine(Gdk::Color *, gint x1, gint y1, gint x2, gint y2);
  GtkLine(Ligne *, Gdk::Color *);

  virtual void drawYourself(Glib::RefPtr<Gdk::Pixmap>);
  virtual void fillYourself(Glib::RefPtr<Gdk::Pixmap>);

  unsigned int getMaxX() const { return MAX(_x1,_x2); };
  unsigned int getMaxY() const { return MAX(_y1,_y2); };

  void modifyEnd(gint x, gint y);

  bool isInvalid();

  void gimmeYourCoordinates(gint *x1, gint *y1, gint *x2, gint *y2);

  virtual bool isOn(gint x, gint y);
  bool isReallyOnIt(gint x, gint y);
  virtual bool isInside(gint x, gint y);
};




/** My cool Arc of Ellipse.
 * Aie!
 * This wonderful GtkArcEllipse is copyright (c) Guillaume Cottenceau 04/1999. Especially dedicated to the workin' part of the GranyTeam (you know
 * who you are).
 * All ze secret iz inside modifyCenter.
 *
 * All portions of code free software.
 *
 * Enjoy ! gc.
 */

class GtkArcEllipse : public ArcEllipse, public GtkForm
{
public:
  GtkArcEllipse(Gdk::Color *, gint x1, gint y1, gint x2, gint y2);
  GtkArcEllipse(ArcEllipse *, Gdk::Color *);

  unsigned int getMaxX() const { return MAX(_x1,_x2); };
  unsigned int getMaxY() const { return MAX(_y1,_y2); };

  virtual void drawYourself(Glib::RefPtr<Gdk::Pixmap>);
  virtual void fillYourself(Glib::RefPtr<Gdk::Pixmap>);

  /// This is the very special method which will compute the real arc of ellipse, given the center.
  void modifyCenter(gint x, gint y, GdkModifierType);

  bool isInvalid();

  void gimmeYourCoordinates(gint *x, gint *y, gint *l, gint *h, gint *a1, gint *a2);

  virtual bool isOn(gint x, gint y);
  virtual bool isInside(gint x, gint y);

private:
  /// The corresponding angles because the gdk method draw_arc uses angles.
  gint _angle1, _angle2;
};


/** My Rectangle
 */

class GtkRectangle : public Rectangle, public GtkForm
{
public:
  GtkRectangle(Gdk::Color *, gint x1, gint y1, gint x2, gint y2);
  GtkRectangle(Rectangle *, Gdk::Color *);

  unsigned int getMaxX() const { return MAX(_x1,_x2); };
  unsigned int getMaxY() const { return MAX(_y1,_y2); };

  void modifyEnd(gint x, gint y);

  bool isInvalid();

  void gimmeYourCoordinates(gint *x1, gint *y1, gint *x2, gint *y2);

  virtual void drawYourself(Glib::RefPtr<Gdk::Pixmap>);
  virtual void fillYourself(Glib::RefPtr<Gdk::Pixmap>);

  virtual bool isOn(gint x, gint y);
  virtual bool isInside(gint x, gint y);
};


/** My Ellipse
 */

class GtkEllipse : public Ellipse, public GtkForm
{
public:
  GtkEllipse(Gdk::Color *, gint x, gint y);
  GtkEllipse(Ellipse *, Gdk::Color *);

  unsigned int getMaxX() const { return _x+_r1; };
  unsigned int getMaxY() const { return _y+_r2; };

  void ModifyExtremity(gint x, gint y, GdkModifierType state);

  bool isInvalid();

  void gimmeYourCoordinates(gint *x, gint *y, gint *l, gint *h);

  virtual void drawYourself(Glib::RefPtr<Gdk::Pixmap>);
  virtual void fillYourself(Glib::RefPtr<Gdk::Pixmap>);

  virtual bool isOn(gint x, gint y);
  virtual bool isInside(gint x, gint y);

private:
  /// This point is "left-top corner of the englobing rectangle"
  gint _x1, _y1;
};


/** My Polygon
 */

class GtkPolygon : public Polygone, public GtkForm
{
public:
  GtkPolygon(Gdk::Color *);
  GtkPolygon(Polygone *, Gdk::Color *);
  ~GtkPolygon();

  unsigned int getMaxX() const;
  unsigned int getMaxY() const;

  void close();

  bool isInvalid();

  virtual void drawYourself(Glib::RefPtr<Gdk::Pixmap>);
  virtual void fillYourself(Glib::RefPtr<Gdk::Pixmap>);

  virtual bool isOn(gint x, gint y);
  virtual bool isInside(gint x, gint y);

private:
  std::vector<Gdk::Point> _points;

};

#endif
