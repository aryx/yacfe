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

#include "PlanHexagonalX11.h"


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


int main(int argc,char **argv)
{

  int i;

  cout << "Starting testIntegrationPlanHex" << endl;


  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur planhex.scene");

    //    Scene arg;
    //    std::ifstream filestream("files/planhex2.scene");

    Scene arg;
    string nom;

    cout << "Nom fichier scene\n";
    
    cin >> nom;

    std::ifstream filestream(nom.c_str());

    filestream >> arg;
    
    //cout << "avant\n";
    cout << "Dimension ?";
    int dim;
    cin >> dim;

    PlanHexagonalX11 plan(dim,arg);
    plan.afficheEcran();

    plan.getAutomate()->afficheurReseau();
    plan.getAutomate()->genereTransition();
    plan.getAutomate()->afficheurReseau();

    cout << *plan.getAutomate();

    //    cin >> dim;
    //cout << "apres\n";
    // peut pas faire ca car l'automate creer est dependant de la scene
    //    delete plan.getAutomate();

    //cout << "encoreapres\n";
    
    cout << arg;

  }




  return 0;
};
