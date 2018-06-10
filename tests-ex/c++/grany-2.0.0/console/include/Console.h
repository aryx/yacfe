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

#ifndef _CONSOLE_H_
#define _CONSOLE_H_



#include "EntreeSortie.h"
#include "PlanHexagonal.h"


#include <libintl.h>
#include <locale.h>

#define _(x) (string)gettext(x)
#define gettext_noop(x) (x)


#define DEBUG_EXCEPTION

#define DEBUG_CONS

#ifdef DEBUG_CONS
#define DEBUG_CONSOLE(s) s
#else
#define DEBUG_CONSOLE(s)
#endif



class Console {
public:


  Console(int argc,char **argv);
  ~Console();


  // cette variable est creer avant l'execution du main (car static)
  // et va mettre le pointeur RegleExclusion::_io a jour pour
  // le faire pointer vers lui (c'est pas beau ca !)
  static RegleIoManager ioRegleIoManager;

  // idem
  static LigneIoManager ioLigneIoManager;
  static RectangleIoManager ioRectangleIoManager;
  static PolygoneIoManager ioPolygoneIoManager;
  static EllipseIoManager ioEllipseIoManager;
  static ArcEllipseIoManager ioArcEllipseIoManager;

  static SceneIoManager ioSceneIoManager;
  static CouleurIoManager ioCouleurIoManager;
  static PhaseIoManager ioPhaseIoManager;
  static PonderationIoManager ioPonderationIoManager;
  static ZonageIoManager ioZonageIoManager;
  static ContientHorsSceneIoManager ioContientHorsSceneIoManager;
  static ContientPhaseIoManager ioContientPhaseIoManager;
  static ColorationIoManager ioColorationIoManager;

  static AutomateIoManager ioAutomateIoManager;
  static CelluleHorsSceneIoManager ioCelluleHorsSceneIoManager;
  static CelluleParoiIoManager ioCelluleParoiIoManager;
  static CelluleAvecParticuleIoManager ioCelluleAvecParticuleIoManager;

  void i18nPrintings();
  void printUsage();
  void printHelp();
  void printVersion();
  void printAuthors();
  string getNomProg();
  string coolHeader();


};




#endif
