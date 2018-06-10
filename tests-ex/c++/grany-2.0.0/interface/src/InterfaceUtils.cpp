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

#include "InterfaceUtils.h"

#include <langinfo.h>
#include <iconv.h>
#include <stdio.h>
#include <math.h>


/********************************************************************************
 * Some tools for converting a STL string <-> int
 * (mainly used in the various Gtk::Entry)
 *
 *******************************************************************************/

/** Description.
 *  This is no good version, because of backward-compatibility problem. In the good stdio,
 *  like the one with every GNU/linux distrib, there's `snprintf' which prevents from
 *  overflowing the maximum capacity of the char[] given. But on shitty Sun workstations
 *  it lacks, although it's part of the ANSI C3.159-1989 standard. So I kept this, but did
 *  not want to make any more efforts to write a clean algo only with sprintf just because
 *  of shitty sun.
 */
string InterfaceUtils::intToString(int i)
{
  char chaine_temp[80];
  sprintf(chaine_temp, "%d", i);
  string a_rendre = chaine_temp;
  return a_rendre;
}


int InterfaceUtils::stringToInt(string s)
{ 
  return atoi(const_cast<char*>(s.c_str()));
}


bool InterfaceUtils::stringConvertible(string s)
{
  if ((InterfaceUtils::stringToInt(s) == 0) &&    // atoi gives 0 when failure
      (s != "0"))
    return false;
  else
    return true;
}





/********************************************************************************
 * Some tools for colors.
 * Used mainly in GranyDrawingArea (which inherits from Gtk::DrawingArea).
 *
 *******************************************************************************/

// A bool to ensure the calls are done correctly (ie, after a call to initColors).
static bool _initialise = false;

static Glib::RefPtr<Gdk::Colormap> _colormap;
static Gdk::Color _blanc("white"), _black("black");



// We'll store associations `number <-> Gdk::Color'

static vector<InterfaceUtils::EntryTableColors> _tabColors;
static vector<InterfaceUtils::EntryTableColors> _tabColorsAuxiliary;



/** Description.
 * We must make this call one time, the parameter will be the caller Gtk::Window.
 */
void InterfaceUtils::initColors(Gtk::Widget * widg)
{
  g_assert(!_initialise);

  _colormap = widg->get_default_colormap();
  _colormap->alloc_color(_blanc);
  _colormap->alloc_color(_black);

  _initialise = true;
}


void InterfaceUtils::deleteColors()
{
  g_assert(_initialise);

  vector<InterfaceUtils::EntryTableColors> nouveau_tableau;

  for (unsigned int i = 0; i<_tabColors.size() ; i++)
    if (_tabColors[i]._numero < 0)
      nouveau_tableau.push_back(_tabColors[i]);

  _tabColors = nouveau_tableau;
}


void InterfaceUtils::deleteColorsAuxiliary()
{
  g_assert(_initialise);

  vector<InterfaceUtils::EntryTableColors> nouveau_tableau;

  for (unsigned int i = 0; i<_tabColorsAuxiliary.size() ; i++)
    if (_tabColorsAuxiliary[i]._numero < 0)
      nouveau_tableau.push_back(_tabColorsAuxiliary[i]);

  _tabColorsAuxiliary = nouveau_tableau;
}


Gdk::Color & InterfaceUtils::getColorWhite()
{
  g_assert(_initialise);
  return _blanc;
}


Gdk::Color & InterfaceUtils::getColorBlack()
{
  g_assert(_initialise);
  return _black;
}


/** Description.
 *  \warning In my choice, if the number was already stored, we store another color value. (replacing)
 */
  
void InterfaceUtils::addColor(gint numero, gushort r, gushort g, gushort b)
{
  g_assert(_initialise);

  // Scan of the list to get the maybe occurence.
  for (unsigned int i=0 ; i< _tabColors.size() ; i++)
    if (_tabColors[i]._numero == numero)
      {
	DEBUG_INTERFACE(cout << "[InterfaceUtils::addColor] found. replacing by new color." << endl;)
	_tabColors[i]._color.set_rgb(r, g, b);
	_colormap->alloc_color(_tabColors[i]._color);
	return;
      }


  // Else... :

  // Creation and allocation of the new color.
  Gdk::Color nouvelle_color;
  nouvelle_color.set_rgb(r, g, b);

  _colormap->alloc_color(nouvelle_color);


  // Adding in the list.
  InterfaceUtils::EntryTableColors nouvelle_entree;
  nouvelle_entree._numero = numero;
  nouvelle_entree._color = nouvelle_color;

  _tabColors.push_back(nouvelle_entree);
}



/** Description.
 *  \warning In my choice, if the number was already stored, we store another color value. (replacing)
 */
  
void InterfaceUtils::addColorAuxiliary(gint numero, gushort r, gushort g, gushort b)
{
  g_assert(_initialise);

  // Scan of the list to get the maybe occurence.
  for (unsigned int i=0 ; i< _tabColorsAuxiliary.size() ; i++)
    if (_tabColorsAuxiliary[i]._numero == numero)
      {
	DEBUG_INTERFACE(cout << "[InterfaceUtils::addColorAuxiliary] found. replacing by new color." << endl;)
	_tabColorsAuxiliary[i]._color.set_rgb(r, g, b);
	_colormap->alloc_color(_tabColorsAuxiliary[i]._color);
	return;
      }


  // Else... :

  // Creation and allocation of the new color.
  Gdk::Color nouvelle_color;
  nouvelle_color.set_rgb(r, g, b);

  _colormap->alloc_color(nouvelle_color);


  // Adding in the list.
  InterfaceUtils::EntryTableColors nouvelle_entree;
  nouvelle_entree._numero = numero;
  nouvelle_entree._color = nouvelle_color;

  _tabColorsAuxiliary.push_back(nouvelle_entree);
}

static int rand_(double val) { return 1+(int) (val*rand()/(RAND_MAX+1.0)); }
static void randomize_col(Gdk::Color * col)
{
  col->set_red(rand_(65535));
  col->set_green(rand_(65535));
  col->set_blue(rand_(65535));
}

void InterfaceUtils::addRandomColorAuxiliary(gint number)
{
  g_assert(_initialise);

  // Scan of the list to get the maybe occurence.
  for (unsigned int i=0 ; i< _tabColorsAuxiliary.size() ; i++)
    if (_tabColorsAuxiliary[i]._numero == number)
      {
	DEBUG_INTERFACE(cout << "[InterfaceUtils::randomizeColorAuxiliary] found. randomizing." << endl;)
	randomize_col(&(_tabColorsAuxiliary[i]._color));
	_colormap->alloc_color(_tabColorsAuxiliary[i]._color);
	return;
      }


  // Else... :

  // Creation and allocation of the new color.
  Gdk::Color nouvelle_color;
  randomize_col(&nouvelle_color);

  _colormap->alloc_color(nouvelle_color);

  // Adding in the list.
  InterfaceUtils::EntryTableColors nouvelle_entree;
  nouvelle_entree._numero = number;
  nouvelle_entree._color = nouvelle_color;

  _tabColorsAuxiliary.push_back(nouvelle_entree);
}


Gdk::Color * InterfaceUtils::getColor(gint numero)
{
  g_assert(_initialise);

  for (unsigned int i=0 ; i< _tabColors.size() ; i++)
    if (_tabColors[i]._numero == numero)
      return &(_tabColors[i]._color);
  
  // If the color does not exist, we give back some black.
  cerr << "GRANY_WARNING [InterfaceUtils::getColor] Warning! A non-allocated color has been asked: " << numero << ". I give you black, Jack!" << endl;
  return &_black;
}


Gdk::Color * InterfaceUtils::getColorAuxiliary(gint numero)
{
  g_assert(_initialise);

  for (unsigned int i=0 ; i< _tabColorsAuxiliary.size() ; i++)
    if (_tabColorsAuxiliary[i]._numero == numero)
      return &(_tabColorsAuxiliary[i]._color);
  
  // If the color does not exist, we give back some black.
  cerr << "GRANY_WARNING [InterfaceUtils::getColorAuxiliary] Warning! A non-allocated color has been asked: " << numero << ". I give you black, Jack!" << endl;
  return &_black;
}



gint InterfaceUtils::getNextFreeNumberAuxiliary()
{
  gint numero_libre = 1;
  bool trouve = false;
  
  while (trouve == false)
    {
      trouve = true;
      for (unsigned int i=0 ; i< _tabColorsAuxiliary.size() ; i++)
	if (_tabColorsAuxiliary[i]._numero == numero_libre)
	  {
	    numero_libre++;
	    trouve = false;
	    break;
	  }
    }

  DEBUG_INTERFACE(cout << "[InterfaceUtils::getNextFreeNumberAuxiliary] I give the number: " << numero_libre << endl;)

  return numero_libre;
}



void InterfaceUtils::deleteColorAuxiliary(gint numero_color)
{
  for (vector<InterfaceUtils::EntryTableColors>::iterator it_colors = _tabColorsAuxiliary.begin() ;
       it_colors != _tabColorsAuxiliary.end() ;
       it_colors++)
    if ((*it_colors)._numero == numero_color)
      {
	it_colors = _tabColorsAuxiliary.erase(it_colors);
	return;
      }
  cerr << "[InterfaceUtils::deleteColorAuxiliary] Trial to delete a non-allocated color number... (" << numero_color << ")" << endl;
}

/** Description.
 * When we want to add a color in the colormap but no matter an index. For example for the simulation viewer.
 */
Gdk::Color * InterfaceUtils::addColorDirect(gushort r, gushort g, gushort b)
{
  g_assert(_initialise);

  Gdk::Color * nouvelle_color = new Gdk::Color();
  nouvelle_color->set_rgb(r, g, b);

  _colormap->alloc_color(*nouvelle_color);

  return nouvelle_color;
}


vector<InterfaceUtils::EntryTableColors> InterfaceUtils::getColormap()
{
  g_assert(_initialise);

  return _tabColors;
}


vector<InterfaceUtils::EntryTableColors> InterfaceUtils::getAuxiliaryColormap()
{
  g_assert(_initialise);

  return _tabColorsAuxiliary;
}


/** Description.
 * This will create and allocate a new color, a mix of the colors of the phases with counting their respective percentages.
 */
Gdk::Color * InterfaceUtils::createColorFromMix(ContientPhase * cp)
{
  gdouble r, g, b;
  r = g = b = 0;

  gdouble intensities = 0, values = 0;

  vector<PhasePourcent> * pp = cp->getPhasePourcent();
  
  for (unsigned int i=0; i<pp->size() ; i++)
    {
      gdouble value = (*pp)[i].pourcentage;
      Gdk::Color * coul = InterfaceUtils::getColorAuxiliary((*pp)[i].phase->getCouleur());
      r += value*coul->get_red();
      g += value*coul->get_green();
      b += value*coul->get_blue();
      intensities += value*MAX(MAX(coul->get_red(), coul->get_green()), coul->get_blue());
      values += value;
    }

  gdouble max;
  if ((r>=g) && (r>=b)) max = r;
  else
    if ((g>=r) && (g>=b)) max = g;
    else
      max = b;

  max /= intensities/values;

  return InterfaceUtils::addColorDirect((gushort)(r/max), (gushort)(g/max), (gushort)(b/max));
}


Gdk::Color & InterfaceUtils::darker(Gdk::Color &c)
{
  c.set_red((gushort) (c.get_red() * DARKER_COEFFICIENT));
  c.set_green((gushort) (c.get_green() * DARKER_COEFFICIENT));
  c.set_blue((gushort) (c.get_blue() * DARKER_COEFFICIENT));
  return c;
}

Gdk::Color & InterfaceUtils::lighter(Gdk::Color &c)
{
  gushort intensity = MAX(MAX(c.get_red(), c.get_green()), c.get_blue());
  gushort adding = (gushort) (intensity * LIGHTER_COEFFICIENT) - intensity;
  c.set_red((gushort) MIN((c.get_red() + adding),65535));
  c.set_green((gushort) MIN((c.get_green() + adding),65535));
  c.set_blue((gushort) MIN((c.get_blue() + adding),65535));
  return c;
}


void InterfaceUtils::randomizeColor(gint number)
{
  g_assert(_initialise);

  // Scan of the list to get the maybe occurence.
  for (unsigned int i=0 ; i< _tabColors.size() ; i++)
    if (_tabColors[i]._numero == number)
      {
	DEBUG_INTERFACE(cout << "[InterfaceUtils::randomizeColor] found. randomizing." << endl;)
	randomize_col(&(_tabColors[i]._color));
	_colormap->alloc_color(_tabColors[i]._color);
	return;
      }
}





/********************************************************************************
 * Misc tools.
 *
 *******************************************************************************/


void InterfaceUtils::granularity(gint x, gint y, gint *rx, gint *ry)
{
  // Allows a `centering' around the granularity.
  x += GRANULARITY/2;
  y += GRANULARITY/2;
  
  // Makes the granularity.
  *rx = x - (x % GRANULARITY);
  *ry = y - (y % GRANULARITY);
}


static string _currentFileSelection = string(g_get_home_dir()) + "/.grany/files";

void InterfaceUtils::closingFileSelection(Gtk::FileSelection * fs)
{
  string file_name = fs->get_filename();

  int last_slash = file_name.find_last_of("/");
  if (last_slash == -1)
    _currentFileSelection = PKGDATADIR "files";
  else
    _currentFileSelection = string(file_name.begin(), file_name.begin()+last_slash);
}


void InterfaceUtils::openingFileSelection(Gtk::FileSelection * fs)
{
  fs->complete(_currentFileSelection);

  // Last char of the current filename: if it's a '/' it means we're in the directory (success), if not it means no success.
  string test_string = fs->get_filename();
  if (test_string.find_last_of("/") != test_string.length()-1)
    {
      _currentFileSelection = PKGDATADIR "files";
      fs->complete(_currentFileSelection);
      string test_string2 = fs->get_filename();
      if (test_string2.find_last_of("/") != test_string2.length()-1)
	{
	  _currentFileSelection = string(g_get_home_dir());
	  fs->complete(_currentFileSelection);
	}
    }
}


static string _currentWritingFileSelection = string(g_get_home_dir()) + "/.grany/files";

void InterfaceUtils::closingWritingFileSelection(Gtk::FileSelection * fs)
{
  string file_name = fs->get_filename();

  int last_slash = file_name.find_last_of("/");
  if (last_slash == -1)
    _currentWritingFileSelection = PKGDATADIR "files";
  else
    _currentWritingFileSelection = string(file_name.begin(), file_name.begin()+last_slash);
}


void InterfaceUtils::openingWritingFileSelection(Gtk::FileSelection * fs)
{
  fs->complete(_currentWritingFileSelection);

  // Last char of the current filename: if it's a '/' it means we're in the directory (success), if not it means no success.
  string test_string = fs->get_filename();
  if (test_string.find_last_of("/") != test_string.length()-1)
    {
      _currentWritingFileSelection = string(g_get_home_dir());
      fs->complete(_currentWritingFileSelection);
    }
}


static string std_to_utf8(string s)
{
  char * s_ = const_cast<char*>(s.c_str());
  iconv_t cd = iconv_open("UTF-8", nl_langinfo(CODESET));
  char* retval = s_;
  if (cd != (iconv_t) (-1)) {
      size_t s_len = strlen(retval);
      /* the maximum expansion when converting happens when converting
	 tscii to utf-8; each tscii char can become up to 4 unicode chars
	 and each one of those unicode chars can be 3 bytes long */
      char *buf = (char *) alloca(4 * 3 * s_len);
      {
	  char *ptr = buf;
	  size_t ptr_len = 4 * 3 * s_len;
	  if ((iconv(cd, &s_, &s_len, &ptr, &ptr_len)) != (size_t) (-1)) {
	      *ptr = 0;
	      retval = buf;
	  }
      }
      iconv_close(cd);
  }
  return retval;
}

string InterfaceUtils::gettext_(string s)
{
  return std_to_utf8(gettext(const_cast<char*>(s.c_str())));
}
