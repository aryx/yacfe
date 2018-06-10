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

#ifndef _ALLPIXMAPS_H
#define _ALLPIXMAPS_H


/**
 * This is a special file which holds all the pixmaps. It will be more convenient to have them here than
 * to read them from several files. (because of the path of installation, etc.)
 *
 * And anyway if you want external pixmaps it's ultra easy to modify as the init of the pixmaps are systematically
 * put in the header of the constructor of each class.
 */


class AllPixmaps
{
  
public:
  // for BaseWindow
  static char * _dataPixmapNew[];
  static char * _dataPixmapOpen[];
  static char * _dataPixmapSave[];
  static char * _dataPixmapHelp[];

  // for MainWindow
  static char * _dataPixmapStop[];
  static char * _dataPixmapPlay[];
  static char * _dataPixmapPause[];
  static char * _dataPixmapRecord[];

  // for BordersEditor
  static char * _dataPixmapSelection[];
  static char * _dataPixmapDelete[];
  static char * _dataPixmapLine[];
  static char * _dataPixmapArcEllipse[];
  static char * _dataPixmapEllipse[];
  static char * _dataPixmapPolygon[];
  static char * _dataPixmapClassicalBorder[];
  static char * _dataPixmapGeneratingBorder[];
  static char * _dataPixmapGrid[];

  // for ZoningEditor
  static char * _dataPixmapFilledRectangle[];
  static char * _dataPixmapFilledEllipse[];
  static char * _dataPixmapFilledPolygon[];

  // for RulesEditor
  static char * _dataPixmapRed[];
  static char * _dataPixmapBlue[];
  static char * _dataPixmapGreen[];
  static char * _dataPixmapGrey[];

  // for WarningWindow
  static char * _dataPixmapWarning[];

  // for ErrorWindow
  static char * _dataPixmapError[];

  // for AboutWindow
  static char * _dataPixmapAbout[];

};

#endif
