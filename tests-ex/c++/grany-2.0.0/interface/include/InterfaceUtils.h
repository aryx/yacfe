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

#ifndef _INTERFACE_UTILS_H_
#define _INTERFACE_UTILS_H_

#include "CommonInterface.h"

#include "EntreeSortie.h"
#include "PlanHexagonal.h"
#include "config.h"

#include "GtkFigures.h"

// #define DEBUG_INTERFACE_ENABLE

#ifdef DEBUG_INTERFACE_ENABLE
#define DEBUG_INTERFACE(s) s
#else
#define DEBUG_INTERFACE(s)
#endif

// These are the minimum dimensions for the pixmaps, in order to get all of them to the same size
#define WIDTH_PIXMAPS 16
#define HEIGHT_PIXMAPS 16


// General colors
#define R_BORDER_CELLS 40000
#define G_BORDER_CELLS 40000
#define B_BORDER_CELLS 40000


// Colors for the editors
#define R_TEMPORARY 40000
#define G_TEMPORARY 40000
#define B_TEMPORARY 40000


// Colors for the SceneEditor
#define R_BUTTON_PROPAGATIVE 65535
#define G_BUTTON_PROPAGATIVE 50000
#define B_BUTTON_PROPAGATIVE 40000

#define R_BUTTON_GENERATED 65535
#define G_BUTTON_GENERATED 32767
#define B_BUTTON_GENERATED 32767


// Colors for the BordersEditor
#define R_CLASSICAL_BORDERS 0
#define G_CLASSICAL_BORDERS 0
#define B_CLASSICAL_BORDERS 65535

#define R_GENERATING_BORDERS 65535
#define G_GENERATING_BORDERS 0
#define B_GENERATING_BORDERS 0


// Coefficient for making modifications to colors via InterfaceUtils::darker or lighter
#define DARKER_COEFFICIENT 0.9
#define LIGHTER_COEFFICIENT 1.15


// Allowed special characters for the name parsers
const char allowedSpecialChars[7] = { '-', '+', '#', '.', '_', '@', '!' };

//*******************************************************************************
/** Methods common to several classes of the application.
 *  Every methods here are static. We'll call them via InterfaceUtils::methodName(params).
 *  I had to use two colormaps (main one, auxiliary one) because when the user opens a
 *  simulation and simultaneously a scene in the scene editor, the colormaps may differ.
 *
 *  \warning gdk follows X so the values for the colors are between 0 and 65535.
 *******************************************************************************/

class InterfaceUtils
{

public:

  /******************************************************************
   * STL-obliged conversions
   *****************************************************************/
  
  /// Converts an int to a STL string.
  static string intToString(int);

  /// Converts a STL string to an int.
  static int stringToInt(string);

  /// Guess if the string is convertible to an int.
  static bool stringConvertible(string);


  /******************************************************************
   * GDK colors easy-handling
   *****************************************************************/

  /// Init the colormap and the base colors.
  static void initColors(Gtk::Widget *);

  /// Delete the recorded colors.
  static void deleteColors();

  /// Delete the recorded colors in the auxiliary colormap.
  static void deleteColorsAuxiliary();

  /// Returns the white color.
  static Gdk::Color & getColorWhite();

  /// Returns the black color.
  static Gdk::Color & getColorBlack();

  /// Adds a color in the colormap with a reference number.
  static void addColor(gint numero, gushort r, gushort g, gushort b);

  /// Adds a color in the auxiliary colormap with a reference number.
  static void addColorAuxiliary(gint numero, gushort r, gushort g, gushort b);

  /// Adds a random color.
  static void addRandomColorAuxiliary(gint);

  /// Returns the color previously defined by addColor.
  static Gdk::Color * getColor(gint numero);

  /// Returns the color previously defined by addColorAuxiliary.
  static Gdk::Color * getColorAuxiliary(gint numero);

  /// To get a free reference number for the auxiliary colormap.
  static gint getNextFreeNumberAuxiliary();

  /// To delete a color from the auxiliary colormap.
  static void deleteColorAuxiliary(gint numero_color);
  
  /// Adds a color directly, ie withoud recording it in the colormap registered entries. (but does add it in the GDK colormap ofcourse)
  static Gdk::Color * addColorDirect(gushort r, gushort g, gushort b);


  struct EntryTableColors
  {
    gint _numero;
    Gdk::Color _color;
  };

  /// Gives back the whole colormap.
  static vector<InterfaceUtils::EntryTableColors> getColormap();

  /// Gives back the whole auxiliary colormap.
  static vector<InterfaceUtils::EntryTableColors> getAuxiliaryColormap();


  /// To create a color from a mix of quantities of phases. Used in ZoningEditor and SceneEditor.
  static Gdk::Color * createColorFromMix(ContientPhase *);

  /// To make a Gdk::Color darker - used mainly for the colored buttons.
  static Gdk::Color & darker(Gdk::Color &);

  /// To make a GdkColor lighter - used mainly for the colored buttons.
  static Gdk::Color & lighter(Gdk::Color &);

  /// To make a color random - used by the Coloration Editor.
  static void randomizeColor(gint number);



  /******************************************************************
   * Misc
   *****************************************************************/

  /// To make the creation of regular forms easier, coordinates are granularized when the grid is displayed.
  static void granularity(gint, gint, gint *, gint *);


  /// To record the directory we were in.
  static void closingFileSelection(Gtk::FileSelection *);

  /// To setup the file selection to the last directory we were visiting.
  static void openingFileSelection(Gtk::FileSelection *);

  /// To record the directory we were in for save-as.
  static void closingWritingFileSelection(Gtk::FileSelection *);

  /// To setup the file selection to the last directory we were visiting for save-as.
  static void openingWritingFileSelection(Gtk::FileSelection *);


  /// Do a sensible gettext for gtk2
  static string gettext_(string);

};

#endif
