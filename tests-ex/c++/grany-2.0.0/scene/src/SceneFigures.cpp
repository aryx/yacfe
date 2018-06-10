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

#include "SceneFigures.h"

//##############################################################################
// Public members
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructeurs/Destructeur
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LigneScene::LigneScene(Ligne *el) : Ligne::Ligne(*el)
{

}

void LigneScene::dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
{
  Ligne* ligne = p.proportionneLigne(this) ;
  p.dessineLigne(*ligne,ceil) ;

}


ArcEllipseScene::ArcEllipseScene(ArcEllipse *el) : ArcEllipse::ArcEllipse(*el) {}


void ArcEllipseScene::dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
  {
    ArcEllipse arc_ellipse = p.proportionneArcEllipse(*this) ;
    p.dessineArcEllipse(arc_ellipse,ceil) ;
  }



RectangleScene::RectangleScene(Rectangle *el) : Rectangle::Rectangle(*el) {}

void RectangleScene::dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
  {
    DEBUG_SCENE(cerr << "rectangle" << endl ;)
    Rectangle rectangle = p.proportionneRectangle(*this) ;

    DEBUG_SCENE(cerr << "proportionneRectangle" << endl ;)

    p.dessineRectangle(rectangle,ceil) ;
    
    DEBUG_SCENE(cerr << "dessineRectangle" << endl;)
  }
  
void RectangleScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
  {
    Rectangle rectangle = p.proportionneRectangle(*this) ;
    p.rempliRectangle(rectangle,ceil) ;
  }
  
void RectangleScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, const vector<PhasePourcent>& liste)
  {
    Rectangle rectangle = p.proportionneRectangle(*this) ;
    p.rempliRectangle(rectangle,liste) ;
  }
  
void RectangleScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, int col)
  {
    Rectangle rectangle = p.proportionneRectangle(*this) ;
    p.rempliRectangle(rectangle,col) ;
  }



EllipseScene::EllipseScene(Ellipse *el) : Ellipse::Ellipse(*el) {};

void EllipseScene::dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
  {
    Ellipse ellipse = p.proportionneEllipse(*this) ;
    p.dessineEllipse(ellipse,ceil) ;
  }

void EllipseScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
  {
    Ellipse ellipse = p.proportionneEllipse(*this) ;
    p.rempliEllipse(ellipse,ceil) ;
  }
  
void EllipseScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, const vector<PhasePourcent>& liste)
  {
    Ellipse ellipse = p.proportionneEllipse(*this) ;
    p.rempliEllipse(ellipse,liste) ;
  }
  
void EllipseScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, int col)
  {
    Ellipse ellipse = p.proportionneEllipse(*this) ;
    p.rempliEllipse(ellipse,col) ;
  }


PolygoneScene::PolygoneScene(Polygone *el)
    {
      list<Ligne*>::const_iterator it;
      list<Ligne*> arg;

      arg = el->getLignes();
      for (it = arg.begin(); it != arg.end(); it++)
	{
	  // accepte car un LigneScene * = Ligne* (c'est beau ca hein ??
	  _elemPolygone.push_back(new LigneScene((*it)));
	}

    };

void PolygoneScene::dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
  {
    Polygone polygone = p.proportionnePolygone(*this) ;
    p.dessinePolygone(polygone,ceil) ;
  }
 
void PolygoneScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil)
  {
    DEBUG_SCENE(cerr << "rempl" << endl ;)

    Polygone polygone = p.proportionnePolygone(*this) ;

    DEBUG_SCENE(cerr << "sorti" << endl ;)

    p.rempliPolygone(polygone,ceil) ;
  }

void PolygoneScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, const vector<PhasePourcent>& liste)
  {
    Polygone polygone = p.proportionnePolygone(*this) ;
    p.rempliPolygone(polygone,liste) ;
  }

void PolygoneScene::rempliToiDansPlanHexagonal(PlanHexagonal& p, int col)
  {
    Polygone polygone = p.proportionnePolygone(*this) ;
    p.rempliPolygone(polygone,col) ;
  }

  



//##############################################################################
// static members
//##############################################################################
