/*******************************************************************************
 *
 * Copyright (C) 1998-1999 by Y. Padioleau, G. Cottenceau, P. Garcia,
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

#include "testCommun.h"

#include "EntreeSortie.h"

#include "FrontiereCompiler.h"
#include "RegleCompiler.h"
#include "SimulCompiler.h"
#include "SceneCompiler.h"

#include <sstream>
// cet variable est creer avant l'execution du main (car static)
// et va mettre le pointeur RegleExclusion::_io a jour pour
// le faire pointer vers lui (c'est pas beau ca !)
static RegleIoManager ioRegleIoManager;
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
static CelluleGeneratriceIoManager ioCelluleGeneratriceIoManager;



int main(int argc,char **argv)
{

  int i;

  cout << "Starting testEntreeSortie" << endl;


  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.regle");

    RegleCompiler aCompiler;

    RegleExclusion arg;

    std::ifstream filestream("files/test1.regle");

    filestream >> arg;

    // test si on peut lire ce que l'on a ecrit
    stringstream io;
    io << arg;
    io >> arg;





    cout << arg;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.frontiere");


    list<Frontiere*> arg;
    std::ifstream filestream("files/test1.frontiere");



    filestream >> arg;

    // test si on peut lire ce que l'on a ecrit
    std::stringstream io;
    io << arg;
    io >> arg;



    cout << arg;

  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.scene");

    Scene arg;
    std::ifstream filestream("files/phasegen.scene");

    filestream >> arg;

    // test si on peut lire ce que l'on a ecrit
    std::stringstream io;
    io << arg;
    io >> arg;

    cout << arg;

  }


  //******************************************************************************
  cin >> i;
  
  {
    testFeature("test sur test1.simul");

    Automate arg;
    std::ifstream filestream("files/testgen.simul");


    filestream >> arg;

    // test si on peut lire ce que l'on a ecrit
    std::stringstream io;
    io << arg;
    io >> arg;

    cout << arg;

  }




  return 0;
};
