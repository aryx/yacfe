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

#include "GtkFigures.h"


GtkForm::GtkForm()
{
  _selection = false;
  _preSelection = false;
  _temporary = false;
}

GtkForm::~GtkForm()
{
}


void GtkForm::setColor(Gdk::Color * color)
{
  _color = color;
}


void GtkForm::setSelection(bool sel)
{
  _selection = sel;
}


void GtkForm::setPreSelection(bool sel)
{
  _preSelection = sel;
}


void GtkForm::setTemporary(bool sel)
{
  _temporary = sel;
}





/*************** ALL THE REST IS STATIC **************/

static Glib::RefPtr<Gdk::GC> _gcGlobal;
static Gdk::Color *_colorPreSelection;


void GtkForm::setColorPreSelection(Gdk::Color * color)
{
  _colorPreSelection = color;
}

void GtkForm::setGcGlobal(Glib::RefPtr<Gdk::GC> gc)
{
  _gcGlobal = gc;
}

Glib::RefPtr<Gdk::GC> GtkForm::getGcGlobal()
{
  return _gcGlobal;
}


Glib::RefPtr<Gdk::Pixmap> _pixmapTile;

void GtkForm::setTile(Glib::RefPtr<Gdk::Window> win)
{
  if (!_pixmapTile)
    _pixmapTile = Gdk::Pixmap::create(win, 10, 10, -1);
  // TODO: free this memory?

  _gcGlobal->set_tile(_pixmapTile);
}


void GtkForm::makeContextSelectionBorder(Gdk::Color * color)
{
  _gcGlobal->set_foreground(*color);
  _gcGlobal->set_line_attributes(1, Gdk::LINE_ON_OFF_DASH, Gdk::CAP_NOT_LAST, Gdk::JOIN_MITER);
  _gcGlobal->set_fill(Gdk::SOLID);
}


void GtkForm::makeContextSelectionZoning(Gdk::Color * color)
{
  g_assert(_pixmapTile);

  // We draw the tile.
  _gcGlobal->set_foreground(*color);
  _gcGlobal->set_fill(Gdk::SOLID);
  _pixmapTile->draw_rectangle(_gcGlobal, true, 0, 0, 5, 5);
  _pixmapTile->draw_rectangle(_gcGlobal, true, 5, 5, 5, 5);
  _gcGlobal->set_foreground(*_colorPreSelection);
  _pixmapTile->draw_rectangle(_gcGlobal, true, 5, 0, 5, 5);
  _pixmapTile->draw_rectangle(_gcGlobal, true, 0, 5, 5, 5);

  _gcGlobal->set_fill(Gdk::TILED);
}


void GtkForm::makeContextPreSelection()
{
  _gcGlobal->set_foreground(*_colorPreSelection);
  _gcGlobal->set_line_attributes(1, Gdk::LINE_SOLID, Gdk::CAP_NOT_LAST, Gdk::JOIN_MITER);
  _gcGlobal->set_fill(Gdk::SOLID);
}

void GtkForm::makeContextTemporary()
{
  _gcGlobal->set_foreground(*_colorPreSelection);
  _gcGlobal->set_line_attributes(1, Gdk::LINE_ON_OFF_DASH, Gdk::CAP_NOT_LAST, Gdk::JOIN_MITER);
  _gcGlobal->set_fill(Gdk::SOLID);
}

void GtkForm::makeContextNormal(Gdk::Color * color)
{
  _gcGlobal->set_foreground(*color);
  _gcGlobal->set_line_attributes(1, Gdk::LINE_SOLID, Gdk::CAP_NOT_LAST, Gdk::JOIN_MITER);
  _gcGlobal->set_fill(Gdk::SOLID);
}

