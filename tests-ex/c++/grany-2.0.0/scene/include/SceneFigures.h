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

#include "Figures.h"
#include "PlanHexagonal.h"

// Fake interface de java

class FormeScene
{
public:
  virtual void dessineToiDansPlanHexagonal(PlanHexagonal&, PourRemplirCellule *) = 0;
};



class FormeFermeeScene : public FormeScene
{
public:
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal&, const vector<PhasePourcent>&) = 0 ;
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal&, int) = 0 ;
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal&, PourRemplirCellule *) = 0 ;

};

// si tu mets class FormeOuverteScene : public FormeOuverte, public FormeScene
// alors ca veut pas compiler

class FormeOuverteScene : public FormeScene
{
};



class LigneScene : public Ligne, public FormeOuverteScene
{
public:
  LigneScene(Ligne *el);
  virtual void dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
};

class ArcEllipseScene : public ArcEllipse, public FormeOuverteScene
{
public:  
  ArcEllipseScene(ArcEllipse *el);

  virtual void dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
};



class RectangleScene : public Rectangle, public FormeFermeeScene
{
public:  
  RectangleScene(Rectangle *el);

  virtual void dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, const vector<PhasePourcent>& liste);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, int col);
}; 

class EllipseScene : public Ellipse, public FormeFermeeScene
{
public:
  EllipseScene(Ellipse *el);

  virtual void dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, const vector<PhasePourcent>& liste);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, int col);
  

};


class PolygoneScene : public Polygone, public FormeFermeeScene
{
public:
  PolygoneScene(Polygone *el);
  virtual void dessineToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, PourRemplirCellule * ceil);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, const vector<PhasePourcent>& liste);
  virtual void rempliToiDansPlanHexagonal(PlanHexagonal& p, int col);


};

