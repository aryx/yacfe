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

#include "PlanHexagonal.h"


#include <math.h>
#include <list>
#include <vector>
#include <stdlib.h>

#include "Figures.h"

#include "Scene.h"

#include "Cellule.h"
#include "CelluleAvecParticule.h"
#include "CelluleHorsScene.h"
#include "CelluleSansParticule.h"
#include "CelluleParoi.h"
#include "CelluleGeneratrice.h"
#include "Coloration.h"
#include "Couleur.h"
#include "Zonage.h"

#include <iomanip>
#include <typeinfo>

#include "SceneFigures.h"

#include "ContientPhase.h"
#include "ContientHorsScene.h"


double PlanHexagonal::_pi = 3.1415926535897932384626433832795028841972;
double PlanHexagonal::_tangente30 = 0.57735026919 ;
double PlanHexagonal::_normalisation = sqrt(3.0)/2 ;


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Cellule * PourRemplirCelluleParoiGeneratrice::getCellule()
{

  Particule * part = new Particule(0, _phase, NULL, RIEN, false) ;
  if (part == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
  CelluleGeneratrice * ceil = new CelluleGeneratrice(part, _phase) ;
  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
  part->setCellule(ceil) ;
  part->setCouleur(_couleur) ;

  return ceil ;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


Cellule * PourRemplirCelluleParoiClassique::getCellule()
{
  Cellule * ceil = new CelluleParoi() ;
  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
  return ceil ;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


Cellule * PourRemplirCelluleHorsScene::getCellule()
{
  Cellule * ceil = new CelluleHorsScene() ;
  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
  return ceil ;
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void PlanHexagonal::calculMinEtMax(const list<Frontiere *>& frt, int& minX, int& minY, 
				   int& maxX, int& maxY)
{


  if (frt.size() == 0)
    {
      minX = maxX = minY = maxY = 0 ;
      return ;
    }

  list<Frontiere*>::const_iterator it = frt.begin();
  

  minX = (*it)->getForme()->rectangleEnglobant().getX1() ;
  minY = plusProcheEntier((*it)->getForme()->rectangleEnglobant().getY1() + (minX * PlanHexagonal::_tangente30 * PlanHexagonal::_normalisation)) ;
  maxX = minX ;
  maxY = minY ;

  
  for(it = frt.begin(); it != frt.end(); it++)
  {
      Rectangle r = (*it)->getForme()->rectangleEnglobant() ;
      
      int X1 = r.getX1() ; 
      int Y1 = plusProcheEntier(r.getY1() + (X1 * PlanHexagonal::_tangente30 * PlanHexagonal::_normalisation)) ;
      int X2 = r.getX2() ; 
      int Y2 = plusProcheEntier(r.getY2() + (X2 * PlanHexagonal::_tangente30 * PlanHexagonal::_normalisation)) ;

      if (X1 < minX) 
	minX = X1 ;

      if (Y1 < minY) 
	minY = Y1 ;

      if (X2 > maxX) 
	maxX = X2 ;

      if (Y2 > maxY) 
	maxY = Y2 ;
  }

  
}



PlanHexagonal::PlanHexagonal(int dim, const Scene& scene) : _ecran(dim, dim)
{

  DEBUG_SCENE(cerr << "entree" << endl;)
 
  int minx,miny,maxx,maxy ;
  PlanHexagonal::calculMinEtMax(scene.getTableauFrontiere(),minx,miny,maxx,maxy) ;

  Cellule * ceil ;
  for (int i = 0 ; i < dim ; i++)
    for(int j = 0 ; j < dim ; j++)
      {
	ceil = new CelluleHorsScene() ;
	if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	_ecran(i,j) = new InfoCellule(HORS_SCENE, ceil) ;
	if (_ecran(i,j) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
      }
    
  _maxX = maxx;
  _maxY = maxy;

  _minX = minx;
  _minY = miny;

  _dimension = dim;

  //                       germe dim nbpas freqaff
  _automate = new Automate(1, _dimension, 2, 2, 
			   scene.getTableauRegleExclusion(),
			   scene.getTableauCouleur(),
			   scene.getTableauPhase());

  // il reste plus qu'a ajouter les particules et les Cellules
 
   {
     //   for(unsigned int i = 0; i < frt.size(); i++)
     //     {
     //	  frt[i]->representeToiDansPlanHexagonal(p) ;
     //     }
     // Frontieres
     list<Frontiere*> frt = scene.getTableauFrontiere();
     list<Frontiere*>::const_iterator it;
   
     for (it = frt.begin(); it != frt.end(); it++)
       {
	 if ((*it)->getTypeParoi() == Frontiere::CLASSIQUE)
	   {
	     PourRemplirCelluleParoiClassique * ceil = new PourRemplirCelluleParoiClassique() ;
	     
	     FormeScene* f = transformeForme((*it)->getForme());
	     f->dessineToiDansPlanHexagonal(*this,ceil) ;
	     delete ceil ;

	   }
	 else  //GENERATRICE
	   {


	     PourRemplirCelluleParoiGeneratrice * ceil = 
	       new PourRemplirCelluleParoiGeneratrice(scene.getPhaseGeneratrice(),scene.getPhaseGeneratrice()->getCouleur());
	     
	     FormeScene* f = transformeForme((*it)->getForme());
	     f->dessineToiDansPlanHexagonal(*this,ceil) ;
	     delete ceil ;

 
	     // TOADD SPEC FICHIER COULEUR pour paroi
	   }
       }
   }
   
   {
     // Zonage
     list<Zonage*> arg = scene.getTableauZonage();
     list<Zonage*>::const_iterator it;
   
     for (it = arg.begin(); it != arg.end(); it++)
       {


	 // UGLY faudrait faire une deuxieme fonction transformFormeFermee
	 FormeFermeeScene* f = (FormeFermeeScene*) transformeForme((*it)->getFormeFermee());
	     
	 if (dynamic_cast<ContientHorsScene*>((*it)->getContenuZonage()))
	   {
	     
	     PourRemplirCelluleHorsScene *ceil = new PourRemplirCelluleHorsScene();
	     f->rempliToiDansPlanHexagonal(*this,ceil);
	     
	     
	   }
	 else  //ContientPhase
	   if (ContientPhase* p = dynamic_cast<ContientPhase*>((*it)->getContenuZonage()))
	     {
	       
	       f->rempliToiDansPlanHexagonal(*this,*(p->getPhasePourcent()));
	     }
       }


   }
   
   {
     // Coloration
     list<Coloration*> arg = scene.getTableauColoration();
     list<Coloration*>::const_iterator it;
   
     for (it = arg.begin(); it != arg.end(); it++)
       {

	 FormeFermeeScene* f = (FormeFermeeScene*) transformeForme((*it)->getFormeFermee());
	 f->rempliToiDansPlanHexagonal(*this,(*it)->getCouleur());


       }
   }
   

   
 
   
   DEBUG_SCENE(cerr << "col" << endl ;)

   numeroteCellule() ;

   DEBUG_SCENE(cerr << "PASSE" << endl ;)
 
   
 
   
 
   mettreHSExterieurFrontiere() ;
   

   // finalisation de l'automate

   for (int j = 0; j < _ecran.NbLigne(); j++)
     for (int i = 0; i < _ecran.NbColonne(); i++)
      {    
	if (_ecran(i,j)->getType() == HORS_SCENE || _ecran(i,j)->getType() == PAROI_CLASSIQUE )
	  _automate->ajoutCellule(_ecran(i,j)->getCellule());
	else
	  {
	    _automate->ajoutParticule(_ecran(i,j)->getCellule()->getParticule());
	    _automate->ajoutCellule(_ecran(i,j)->getCellule());
	  }
      }

   _automate->connecteCellules();

 

}

FormeScene* PlanHexagonal::transformeForme(Forme* f)
{
  if ( Ligne* arg = dynamic_cast<Ligne*>(f))
    return new LigneScene(arg);
  else 
    if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
      return new RectangleScene(arg);
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	return new EllipseScene(arg);
      else
	if (ArcEllipse* arg = dynamic_cast<ArcEllipse*>(f))
	  return new ArcEllipseScene(arg);
	else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    return new PolygoneScene(arg);

  throw Exception("C'est pas normal, je ne gere pas toutes les formes");
}



void PlanHexagonal::mettreHSExterieurFrontiere()
{
  for (int i = 0; i < _dimension; i++)
    {
      repandre(0,i) ;
      repandre(i,0) ;
    }
  
  changeNULLEnHorsScene() ;

}

void PlanHexagonal::repandre(int x, int y)
{
  
  if ( x >= 0 && x < _dimension && y >= 0 && y < _dimension && 
       _ecran(x,y) != NULL && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE)
    {
      delete _ecran(x,y) ;
      _ecran(x,y) = NULL ;
      
      repandre(x,y-1) ;
      repandre(x-1,y-1) ;
      repandre(x-1,y) ;
      repandre(x,y+1) ;
      repandre(x+1,y+1) ;
      repandre(x+1,y) ;
    }

}

void PlanHexagonal::changeNULLEnHorsScene()
{

  for(int i = 0; i < _dimension; i++)
    for(int j = 0; j < _dimension; j++)
      {
	if (_ecran(i,j) == NULL) _ecran(i,j) = new InfoCellule(HORS_SCENE, new CelluleHorsScene()) ;	
      }
} 


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void PlanHexagonal::numeroteCellule()
{

  int numero = 0 ;

  for(int i = 0; i < _dimension; i++)
    for(int j = 0; j < _dimension; j++)
      {

	try
	  {
	    _ecran(i,j)->getCellule()->getParticule()->setNumero(numero) ;
	    // avant y 'avait ca :
	    // _ecran(i,j)->getCellule()->getParticule()->setNumero(numero++) ;
	    // et le numero++ est execute avant
	    // et en plus y'a des trucs bizarres qui se passent
	    numero++;
	  }
	catch(CelluleSansParticule::Exception e)
	  { }
      }

}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------



  
ostream& operator << (ostream& os, const PlanHexagonal& p)
{
    for(int i = 0; i < p._dimension; i++)
      {
	for(int j = 0; j < p._dimension; j++)
	  { 
	  }
	os << endl ;
      }

    return os ;
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void PlanHexagonal::coordonneeVectorielVersBitmap(int x1, int y1, double& x_res, double& y_res)
{
  double x,y;
  if ( _maxY - _minY >= _maxX - _minX)
    {
      
      translatePoint(x1 /*- _minX*/, y1 /*- _minY*/, x, y) ;
      x -= _minX ;
      y -= _minY ;

      double coef = double(_dimension-1) / double(_maxY - _minY) ;
      int marge   = plusProcheEntier( ((_dimension-1) - ((_maxX - _minX) * coef)) / 2 ) ;

      x_res = (marge + x * coef) ; //if (x_res >= _dimension) x_res = _dimension - 1 ;
      y_res = (y * coef) ;         //if (y_res >= _dimension) y_res = _dimension - 1 ;

      //translatePoint(marge + (x1 - _minX) * coef, (y1 - _minY) * coef, x_res, y_res) ; 
     
    }
  else
    {

      translatePoint(x1 /*- _minX*/, y1 /*- _minY*/, x, y) ;
      x -= _minX ;
      y -= _minY ;

      
      double coef = double(_dimension-1) / double(_maxX - _minX) ;
      int marge   = plusProcheEntier( ((_dimension-1) - ((_maxY - _minY) * coef)) / 2 ) ;

      x_res = (x * coef) ; //if (x_res >= _dimension) x_res = _dimension - 1 ;
      y_res = (marge + y * coef) ; //if (y_res >= _dimension) y_res = _dimension - 1 ;

      //translatePoint((x1 - _minX) * coef, marge + (y1 - _minY) * coef, x_res, y_res) ;

    }
}



int PlanHexagonal::reinitialise(const vector<float>& tab)
{

  for(unsigned int i = 0; i < tab.size(); i++)
    {
      if (tab[i] >= 1) return 0 ;
    }

  return 1 ;

} 

float PlanHexagonal::minimum(const vector<PhasePourcent>& tab)
{
  float min = tab.begin()->pourcentage ;
  vector<PhasePourcent>::const_iterator it;
  for (it = tab.begin(); it != tab.end(); it++)
    {
      if (it->pourcentage < min) min = it->pourcentage ;

    }

  return min ;
}

vector<float> PlanHexagonal::enleve(vector<float>& tab)
{

  vector<float> res(tab.size()) ;
  
  for(unsigned int i = 0; i < tab.size(); i++)
    {
      if (tab[i] < 1) res[i] = 0 ;
      else res[i] = tab[i] ;
    }
 
  return res ;

}
  
int PlanHexagonal::indice(vector<float>& tab)
{
  
  vector<float> tmp = enleve(tab) ;

  int poid = (int) poids(tmp) ;
  vector<float> cum = cumule(tmp) ;

  int alea = rand() % poid + 1 ;
  
  for(unsigned int i = 0; i < tab.size(); i++)
    {

      if (alea <= cum[i]) 
	{
	  tab[i]-- ;
	  return i ;
	}
      
    }  
  DEBUG_SCENE(cerr << "BALACK !!!" << endl ;     )
  exit(1) ;
}


vector<float> PlanHexagonal::initTabPoids(const vector<PhasePourcent>& tab_phase_pourcent)
{
  vector<float> res(tab_phase_pourcent.size()) ;

  float min = minimum(tab_phase_pourcent) ;

  for(unsigned int i = 0; i  < tab_phase_pourcent.size(); i++)
    {
      res[i] = float(tab_phase_pourcent[i].pourcentage / min) ;
    }

  return res ;
}


float PlanHexagonal::poids(const vector<float>& tab)
{
  float res = 0 ;

  for(unsigned int i = 0; i < tab.size(); i++)
    {
      res += tab[i] ;
    }

  return res ;
}

vector<float> PlanHexagonal::cumule(const vector<float>& tab)
{
  vector<float> res(tab.size()) ;
  float cum = 0 ;

  for(unsigned int i = 0; i < tab.size(); i++)
    {
      cum += tab[i] ;
      res[i] = cum ;
    }

  return res ;
} 


vector<float> PlanHexagonal::additionne(const vector<float>& tab1, const vector<float>& tab2)
{
  vector<float> res = tab1 ;

  for(unsigned int i = 0; i < tab2.size(); i++)
    {
      res[i] += tab2[i] ;
    }

  return res ;

} 


int PlanHexagonal::plusProcheEntier(double x)
{
  if ((x - ((int) x)) <= 0.5 ) return (int) x ;
  else return ((int) x + 1) ; 
}


double PlanHexagonal::calculEcart(double x, double y, double r1, double r2)
{
  return (1 - (x*x)/(r1*r1) - (y*y)/(r2*r2)) ;
}

int PlanHexagonal::appartient(double x, double y, double x1, double y1, double x2, double y2)
{

  if (x1 == x2 && y1 == y2) return true ;

  if (y1 >= 0 && y2 >= 0 && x1 >= x2 && x1 >= 0 && x2 <= 0)
    {
      return x >= x2 && x <= x1 && (y >= y2 && x <= 0  || y >= y1 && x >= 0) ;
    }

  if (y1 >= 0 && y2 >= 0 && x1 >= x2 && x1 >= 0 && x2 >= 0)
    {
      return x >= x2 && x <= x1 && y >= y1 && y <= y2 ;
    }

  if (y1 >= 0 && y2 >= 0 && x1 >= x2 && x1 <= 0 && x2 <= 0)
    {
      return x >= x2 && x <= x1 && y >= y2 && y <= y1; 
    }

  /////////////////////////

  if (y1 >= 0 && y2 >= 0 && x1 < x2 && x1 <= 0 && x2 >= 0)
    {
      return x >= x2 && y <= y2 || x <= x1 && y <= y1 || y <= 0 ;
    }

 if (y1 >= 0 && y2 >= 0 && x1 < x2 && x1 <= 0 && x2 <= 0)
    {
      return x >= x2 && y >= y2 || x >= 0 || x <= x1 && y <= y1 || y <= 0 ;
    }

 if (y1 >= 0 && y2 >= 0 && x1 < x2 && x1 >= 0 && x2 >= 0)
    {
      return x >= x2 && y <= y2 || x <= x1 && y >= y1 || x <= 0 || y <= 0 ;
    }

 /////////

  if (y1 <= 0 && y2 <= 0 && x1 <= x2 && x1 <= 0 && x2 >= 0)
    {
      return x >= x1 && x <= x2 && (y <= y1 && x <= 0 || y <= y2 && x >= 0) ;
    }

 if (y1 <= 0 && y2 <= 0 && x1 <= x2 && x1 <= 0 && x2 <= 0)
    {
      return x >= x1 && x <= x2 && y <= y1 && y >= y2 ;
    }

 if (y1 <= 0 && y2 <= 0 && x1 <= x2 && x1 >= 0 && x2 >= 0)
    {
      return x >= x1 && x <= x2 && y >= y1 && y <= y2 ;
    }

 ///////////

  if (y1 <= 0 && y2 <= 0 && x1 > x2 && x1 >= 0 && x2 <= 0)
    {
      return x >= x1 && y >= y1 || x <= x2 && y >= y2 || y >= 0 ;
    }

  if (y1 <= 0 && y2 <= 0 && x1 > x2 && x1 >= 0 && x2 >= 0)
    {
      return x >= x1 && y >= y1 || x <= x2 && y <= y2 || y >= 0 || x <= 0 ;
    }

  if (y1 <= 0 && y2 <= 0 && x1 > x2 && x1 <= 0 && x2 <= 0)
    {
      return x >= x1 && y <= y1 || x >= 0 || x <= x2 && y >= y2 || y >= 0 ;
    }

  ///////////


  if (y1 >= 0 && y2 <= 0 && x1 >= 0 && x2 >= 0)
    {
      return y >= y1 && x <= x1 || x <= 0 || y <= y2 && x <= x2 ;
    }

  if (y1 >= 0 && y2 <= 0 && x1 <= 0 && x2 <= 0)
    {
      return y <= y1 && x <= x1 && y >= 0 || y >= y2 && x <= x2 && y <= 0 ;
    }

  if (y1 >= 0 && y2 <= 0 && x1 >= 0 && x2 <= 0)
    {
      return y >= y1 && x <= x1 && x >= 0 || x <= 0 && y >= 0 || y >= y2 && x <= x2 ;
    }

  if (y1 >= 0 && y2 <= 0 && x1 <= 0 && x2 >= 0)
    {
      return y <= y1 && x <= x1 || x <= 0 && y <= 0 || y <= y2 && x <= x2 && x >= 0 ;
    }

  if (y1 <= 0 && y2 >= 0 && x1 >= 0 && x2 >= 0)
    {
      return y >= y1 && x >= x1 && y <= 0  || y <= y2 && x >= x2 && y >= 0 ;
    }

  if (y1 <= 0 && y2 >= 0 && x1 <= 0 && x2 <= 0)
    {
      return y <= y1 && x >= x1 && x <= 0 || x >= 0 || y >= y2 && x >= x2 && x <= 0 ;
    }

  if (y1 <= 0 && y2 >= 0 && x1 >= 0 && x2 <= 0)
    {
      return y >= y1 && x >= x1 && x >= 0 || x >= 0 && y >= 0 || y >= y2 && x >= x2 ;
    }

  if (y1 <= 0 && y2 >= 0 && x1 <= 0 && x2 >= 0)
    {
      return y <= y1 && x >= x1 || x >= 0 && y <= 0 || y <= y2 && x >= x2 && x >= 0 ;
    }


  DEBUG_SCENE(cerr << "[PlanHexagonal] erreur dans int appartient(double x, double y, int x1, int y1, int x2, int y2)" << endl ;)
  exit (0) ;

}

void PlanHexagonal::rechercheMinEtMax(const vector<Arete>& t, int& min_x, int& max_x, int& min_y, int& max_y)
{
  min_x = t[0].getX1() ; max_x = t[0].getX1() ; min_y = t[0].getY1() ; max_y = t[0].getY1() ;
 
  for (unsigned int i = 0; i < t.size(); i++)
    {
      if (t[i].getX1() < min_x) min_x = t[i].getX1() ;
      if (t[i].getX1() > max_x) max_x = t[i].getX1() ;
      if (t[i].getX2() < min_x) min_x = t[i].getX2() ;
      if (t[i].getX2() > max_x) max_x = t[i].getX2() ;

      if (t[i].getY1() < min_y) min_y = t[i].getY1() ;
      if (t[i].getY1() > max_y) max_y = t[i].getY1() ;
      if (t[i].getY2() < min_y) min_y = t[i].getY2() ;
      if (t[i].getY2() > max_y) max_y = t[i].getY2() ;
    }
}


vector<int> PlanHexagonal::tri(const vector<int>& tab)
{

  vector<int> res = tab ;
  int j ;
  int v ;

  for (unsigned int i = 1; i < res.size(); i++)
    {
      v = res[i] ;
      j = i ;
      while ( (j > 0) && res[j-1] > v) { res[j] = res[j-1] ; j-- ; }
      res[j] = v ;
    }

  return res ;

}

vector<int> PlanHexagonal::analyse(const vector<int>& tab)
{

  if (tab.size() == 2) return tab ;

  vector<int> res ;

  int v = tab[0] ;
  res.push_back(v) ;

  for (unsigned int i = 1; i < tab.size(); i++)
    {
      if (tab[i] != v) 
	{
	  v = tab[i] ;
	  res.push_back(v) ;
	}
    }

  return res ;

}

vector<int> PlanHexagonal::rechercheArreteSecante(int y, const vector<Arete>& tab)
{

  vector<int> res ;

  for(unsigned int i = 0; i < tab.size(); i++)
    {
      if (tab[i].coupeArete(y)) res.push_back(plusProcheEntier(tab[i].intersection(y))) ;
    }

  return analyse(tri(res)) ;

}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void PlanHexagonal::dessineLigne(const Ligne& ligne, PourRemplirCellule * ceil) 
{
  dessineLigne(ligne.getX1(), ligne.getY1(), ligne.getX2(), ligne.getY2(), ceil) ;
}

void PlanHexagonal::dessineLigne(const Ligne& ligne, int col)
{
  dessineLigne(ligne.getX1(), ligne.getY1(), ligne.getX2(), ligne.getY2(), col) ;
}

void PlanHexagonal::dessineLigne(const Ligne& ligne, const vector<PhasePourcent>& tab_phase_pourcent)
{
  vector<float> tab = initTabPoids(tab_phase_pourcent) ;
  dessineLigne(ligne.getX1(), ligne.getY1(), ligne.getX2(), ligne.getY2(), tab_phase_pourcent, tab) ;
}

void PlanHexagonal::dessineLigne(int a, int b, int c, int d, PourRemplirCellule * ceil)
{

  int x1,y1,x2,y2 ;
  int x ;
  int y ;
  int delta_x ;
  int delta_y ;

  int cpt ;


  DEBUG_SCENE(cerr << "dessine ligne" << endl ;)

  if (a <= c) { x1 = a ; y1 = b ; x2 = c ; y2 = d ; }
  else        { x1 = c ; y1 = d ; x2 = a ; y2 = b ; }

  x = x1 ;
  y = y1 ;

  DEBUG_SCENE(cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl ;)
  
  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE )
      { 
	delete _ecran(x,y) ; 
        _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
	if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
      }

  if (y2 <= y1)
    {
      delta_x = x2 - x1 ;
      delta_y = y1 - y2 ;

      if (delta_x >= delta_y)
	{
	  cpt = delta_x / 2 ;

	    for (int i = 0; i < delta_x; i++)
	    {
	      x++ ; 
	      cpt += delta_y ;
	      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE) 
		{ 
		  delete _ecran(x,y) ;
		  _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		}

	      if (cpt >= delta_x) 
		{ 
		  y-- ; cpt -= delta_x ; 

		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ; 
		      _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }
		}
	      
	    }
	}
      else
	{
	  cpt = delta_y / 2 ;

	    for (int i = 0; i < delta_y; i++)
	    {
	      y-- ;
	      
	      cpt += delta_x ;
	      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		{ 
		  delete _ecran(x,y) ;
		  _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		}

	      if (cpt >= delta_y) 
		{ 
		  x++ ; cpt -= delta_y ;

		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    } 
		}

	
	    }
	}
    }
  else
    {
      if (y2 - y1 <= x2 - x1)
	{
	  delta_x = y2 - y1 ;
	  delta_y = x2 - x1 - (y2 - y1);
	  if (delta_x >= delta_y)
	    {
	      cpt = delta_x / 2 ;

		for (int i = 0; i < delta_x; i++)
		{
		  x++ ; y++ ;

		  cpt += delta_y ;
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }

		  if (cpt >= delta_x) 
		    { 
		      x++ ; cpt -= delta_x ; 

		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
		}
	    }
	  else
	    {
	      cpt = delta_y / 2 ; 

		for (int i = 0; i < delta_y; i++)
		{
		  x++ ; 

		  cpt += delta_x ;
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }

		  if (cpt >= delta_y) 
		    { 
		      x++ ; y++ ; cpt -= delta_y ;

		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
		  
		}
	    }
	  
	}
      else
	{
	  delta_x = y2 - y1 - (x2 - x1) ;
	  delta_y = x2 - x1 ;
	  if (delta_x >= delta_y)
	    {
	      cpt = delta_x / 2 ;

		for (int i = 0; i < delta_x; i++)
		{
		  y++ ; 

		  cpt += delta_y ;
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }

		  if (cpt >= delta_x) 
		    { 
		      x++ ; y++ ; cpt -= delta_x ;
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
	       
		}
	    }
	  else
	    {
	      cpt = delta_y / 2 ;

		for (int i = 0; i < delta_y; i++)
		{
		  x++ ; y++ ;
		  cpt += delta_x ;
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }

		  if (cpt >= delta_y) 
		    { 
		      y++ ; cpt -= delta_y ; 

		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  _ecran(x,y) = new InfoCellule(ceil->getType(), ceil->getCellule()) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
		}
	    }
	    
	}
    }

}

void PlanHexagonal::dessineLigne(int a, int b, int c, int d, int col)
{

  int x1,y1,x2,y2 ;
  int x ;
  int y ;
  int delta_x ;
  int delta_y ;

  int cpt ;


  if (a <= c) { x1 = a ; y1 = b ; x2 = c ; y2 = d ; }
  else        { x1 = c ; y1 = d ; x2 = a ; y2 = b ; }

  x = x1 ;
  y = y1 ;
  
  try
    {
      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
	_ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;

    }
  catch(CelluleSansParticule::Exception e)
    { }

  if (y2 <= y1)
    {
      delta_x = x2 - x1 ;
      delta_y = y1 - y2 ;

      if (delta_x >= delta_y)
	{
	  cpt = delta_x / 2 ;

	    for (int i = 0; i < delta_x; i++)
	    {
	      x++ ; 
	      cpt += delta_y ;
	      try
		{
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
		    
		    _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		}
	      catch(CelluleSansParticule::Exception e)
		{ }

	      if (cpt >= delta_x) 
		{ 
		  y-- ; cpt -= delta_x ; 
		  
		  
		  try
		    {
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			
			  _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		    }
		  catch(CelluleSansParticule::Exception e)
		    { }
		}
	      
	    }
	}
      else
	{
	  cpt = delta_y / 2 ;

	  for (int i = 0; i < delta_y; i++)
	    {
	      y-- ;
	      
	      cpt += delta_x ;

	      try
		{
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
		    
		      _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		}
	      catch(CelluleSansParticule::Exception e)
		{ }
	      
	      if (cpt >= delta_y) 
		{ 
		  x++ ; cpt -= delta_y ;
		  
		  
		  try
		    {
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			
			  _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		    }
		  catch(CelluleSansParticule::Exception e)
		    { }
		}
	      
	      
	    }
	}
    }
  else
    {
      if (y2 - y1 <= x2 - x1)
	{
	  delta_x = y2 - y1 ;
	  delta_y = x2 - x1 - (y2 - y1);
	  if (delta_x >= delta_y)
	    {
	      cpt = delta_x / 2 ;
	      
	      for (int i = 0; i < delta_x; i++)
		{
		  x++ ; y++ ;
		  
		  
		  cpt += delta_y ;
		  
		  try
		    {
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			
			  _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		    }
		  catch(CelluleSansParticule::Exception e)
		    { }
		  
		  if (cpt >= delta_x) 
		    { 
		      x++ ; cpt -= delta_x ; 
		      
		      
		      try
			{
			  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			    
			      _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
			}
		      catch(CelluleSansParticule::Exception e)
			{ }
		    }
		}
	    }
	  else
	    {
	      cpt = delta_y / 2 ; 
	      
	      for (int i = 0; i < delta_y; i++)
		{
		  x++ ; 
		  
		  cpt += delta_x ;

		  try
		    {
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			
			  _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		    }
		  catch(CelluleSansParticule::Exception e)
		    { }
		  
		  if (cpt >= delta_y) 
		    { 
		      x++ ; y++ ; cpt -= delta_y ;
		      
		      
		      try
			{
			  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			    
			      _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
			}
		      catch(CelluleSansParticule::Exception e)
			{ }
		    }
		  
		}
	    }
	  
	}
      else
	{
	  delta_x = y2 - y1 - (x2 - x1) ;
	  delta_y = x2 - x1 ;
	  if (delta_x >= delta_y)
	    {
	      cpt = delta_x / 2 ;
	      
		for (int i = 0; i < delta_x; i++)
		  {
		    y++ ; 
		    
		    cpt += delta_y ;
		    
		    try
		      {
			if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			  
			    _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		      }
		    catch(CelluleSansParticule::Exception e)
		      { }
		    
		    if (cpt >= delta_x) 
		      { 
			x++ ; y++ ; cpt -= delta_x ;
						
			
			try
			  {
			    if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			      
				_ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
			  }
			catch(CelluleSansParticule::Exception e)
			  { }
		      }
		    
		  }
	    }
	  else
	    {
	      cpt = delta_y / 2 ;
	      
	      for (int i = 0; i < delta_y; i++)
		{
		  x++ ; y++ ;
		  
		  
		  cpt += delta_x ;
		  
		  try
		    {
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			
			  _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
		    }
		  catch(CelluleSansParticule::Exception e)
		    { }
		  
		  if (cpt >= delta_y) 
		    { 
		      y++ ; cpt -= delta_y ; 
		      
		      
		      try
			{
			  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y) != NULL) 
			    
			      _ecran(x,y)->getCellule()->getParticule()->setCouleur(col) ;
			}
		      catch(CelluleSansParticule::Exception e)
			{ }
		    }
		}
	    }
	    
	}
    }
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*int PlanHexagonal::indice(vector<int>& tab)
{

  int poid = poids(tab) ;
  vector<int> cum = cumule(tab) ;

  int alea = rand() % poid + 1 ;

  for(unsigned int i = 0; i < tab.size(); i++)
    {
      
      if (alea <= cum[i]) 
	{
	  tab[i]-- ;
	  return i ;
	}
    }

  cerr << "[PlanHexagonal] erreur dans indice(vector<int>& tab)" << endl ;
  exit (1) ;

}*/


void PlanHexagonal::dessineLigne(int a, int b, int c, int d, const vector<PhasePourcent>& tab_phase_pourcent,
				 vector<float>& tab)
{

  int x1,y1,x2,y2 ;
  int x ;
  int y ;
  int delta_x ;
  int delta_y ;
  
  int cpt ;

  int iindice ;
  Particule * particule ;
  CelluleAvecParticule * ceil ;
  
  if (a <= c) { x1 = a ; y1 = b ; x2 = c ; y2 = d ; }
  else        { x1 = c ; y1 = d ; x2 = a ; y2 = b ; }
  
  x = x1 ;
  y = y1 ;
  
  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
    { 
      
      //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;

      delete _ecran(x,y) ;

      if (reinitialise(tab)) 
	{
	  tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
	}

      iindice = indice(tab) ;
      particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
      if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
      ceil = new CelluleAvecParticule(particule) ;
      if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
      particule->setCellule(ceil) ;
      _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }
  
  if (y2 <= y1)
    {
      delta_x = x2 - x1 ;
      delta_y = y1 - y2 ;
      
      if (delta_x >= delta_y)
	{
	  cpt = delta_x / 2 ;
	  
	  for (int i = 0; i < delta_x; i++)
	    {
	      x++ ; 
	      cpt += delta_y ;
	
	      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		{ 
		  delete _ecran(x,y) ;
		  //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		  if (reinitialise(tab)) 
		    {
		      tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
		    }

		  iindice = indice(tab) ;
		  particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		  if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		  ceil = new CelluleAvecParticule(particule) ;
		  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		  particule->setCellule(ceil) ;
		  _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		}      

	      if (cpt >= delta_x) 
		{ 
		  y-- ; cpt -= delta_x ; 
		  
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		      if (reinitialise(tab)) 
			{
			  tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			}

		      iindice = indice(tab) ;
		      particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		      if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      ceil = new CelluleAvecParticule(particule) ;
		      if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      particule->setCellule(ceil) ;
		      _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }
		}
	      
	    }
	}
      else
	{
	  cpt = delta_y / 2 ;
	  
	  for (int i = 0; i < delta_y; i++)
	    {
	      y-- ;
	      
	      cpt += delta_x ;
	      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		{ 
		  delete _ecran(x,y) ;
		  //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		  
		  if (reinitialise(tab)) 
		    {
		      tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
		    }

		  iindice = indice(tab) ;
		  particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		  if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		  ceil = new CelluleAvecParticule(particule) ;
		  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		  particule->setCellule(ceil) ;
		  _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		}

	      if (cpt >= delta_y) 
		{ 
		  x++ ; cpt -= delta_y ;
		  
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		      if (reinitialise(tab)) 
			{
			  tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			}

		      iindice = indice(tab) ;
		      particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		      if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      ceil = new CelluleAvecParticule(particule) ;
		      if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      particule->setCellule(ceil) ;
		      _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    } 
		}
	      
	      
	    }
	}
    }
  else
    {
      if (y2 - y1 <= x2 - x1)
	{
	  delta_x = y2 - y1 ;
	  delta_y = x2 - x1 - (y2 - y1);
	  if (delta_x >= delta_y)
	    {
	      cpt = delta_x / 2 ;
	      
	      for (int i = 0; i < delta_x; i++)
		{
		  x++ ; y++ ;
		  
		  
		  cpt += delta_y ;

		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		      if (reinitialise(tab)) 
			{
			  tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			}

		      iindice = indice(tab) ;
		      particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		      if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      ceil = new CelluleAvecParticule(particule) ;
		      if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      particule->setCellule(ceil) ;
		      _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }
		  if (cpt >= delta_x) 
		    { 
		      x++ ; cpt -= delta_x ; 
		      
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
			  if (reinitialise(tab)) 
			    {
			      tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			    }

			  iindice = indice(tab) ;
			  particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
			  if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  ceil = new CelluleAvecParticule(particule) ;
			  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  particule->setCellule(ceil) ;
			  _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
		}
	    }
	  else
	    {
	      cpt = delta_y / 2 ; 
	      
	      for (int i = 0; i < delta_y; i++)
		{
		  x++ ; 
		  
		  cpt += delta_x ;
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		      if (reinitialise(tab)) 
			{
			  tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			}

		      iindice = indice(tab) ;
		      particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		      if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      ceil = new CelluleAvecParticule(particule) ;
		      if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      particule->setCellule(ceil) ;
		      _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }
		  if (cpt >= delta_y) 
		    { 
		      x++ ; y++ ; cpt -= delta_y ;
		      
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
			  if (reinitialise(tab)) 
			    {
			      tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			    }

			  iindice = indice(tab) ;
			  particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
			  if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  ceil = new CelluleAvecParticule(particule) ;
			  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  particule->setCellule(ceil) ;
			  _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
		  
		}
	    }
	  
	}
      else
	{
	  delta_x = y2 - y1 - (x2 - x1) ;
	  delta_y = x2 - x1 ;
	  if (delta_x >= delta_y)
	    {
	      cpt = delta_x / 2 ;
	      
	      for (int i = 0; i < delta_x; i++)
		{
		  y++ ; 
		  
		  cpt += delta_y ;
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		      if (reinitialise(tab)) 
			{
			  tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			}

		      iindice = indice(tab) ;
		      particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		      if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      ceil = new CelluleAvecParticule(particule) ;
		      if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      particule->setCellule(ceil) ;
		      _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }

		  if (cpt >= delta_x) 
		    { 
		      x++ ; y++ ; cpt -= delta_x ;
		      
		      
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
			  if (reinitialise(tab)) 
			    {
			      tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			    }

			  iindice = indice(tab) ;
			  particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
			  if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  ceil = new CelluleAvecParticule(particule) ;
			  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  particule->setCellule(ceil) ;
			  _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
		  
		}
	    }
	  else
	    {
	      cpt = delta_y / 2 ;
	      
	      for (int i = 0; i < delta_y; i++)
		{
		  x++ ; y++ ;
		  
		  
		  cpt += delta_x ;
		  if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
		    { 
		      delete _ecran(x,y) ;
		      //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
		      if (reinitialise(tab)) 
			{
			  tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			}

		      iindice = indice(tab) ;
		      particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
		      if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      ceil = new CelluleAvecParticule(particule) ;
		      if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		      particule->setCellule(ceil) ;
		      _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
		      if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
		    }
		  if (cpt >= delta_y)
		    { 
		      y++ ; cpt -= delta_y ;
		      
		      if (x >= 0 && x < _ecran.NbLigne() && y >= 0 && y < _ecran.NbColonne() && _ecran(x,y)->getType() != PAROI_CLASSIQUE && _ecran(x,y)->getType() != PAROI_GENERATRICE ) 
			{ 
			  delete _ecran(x,y) ;
			  //if (poids(tab) == 0) tab = initTabPoids(tab_phase_pourcent) ;
			  if (reinitialise(tab)) 
			    {
			      tab = additionne(tab,initTabPoids(tab_phase_pourcent)) ;
			    }

			  iindice = indice(tab) ;
			  particule = new Particule(0,tab_phase_pourcent[iindice].phase,NULL,Requete(),false) ;
			  if (particule == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  ceil = new CelluleAvecParticule(particule) ;
			  if (ceil == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			  particule->setCellule(ceil) ;
			  _ecran(x,y) = new InfoCellule(PHASE,ceil) ; 
			  if (_ecran(x,y) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
			}
		    }
		}
	    }
	  
	}
    }
}


void PlanHexagonal::dessineArcEllipse(const ArcEllipse& arc_ellipse, PourRemplirCellule * ceil) 
{
  dessineArcEllipse(arc_ellipse.getX(), arc_ellipse.getY(), arc_ellipse.getR1(), arc_ellipse.getR2(),
		    arc_ellipse.getX1(), arc_ellipse.getY1(), arc_ellipse.getX2(), arc_ellipse.getY2(),ceil) ;
}



void PlanHexagonal::dessineArcEllipse(int centre_x, int centre_y, int r1, int r2,
				      int xa, int ya, int xb, int yb, PourRemplirCellule * ceil) 
{


  double X1, Y1, X2, Y2, X3, Y3, X4, Y4 ;
  int x1, y1, x2, y2, x3, y3, x4, y4 ;
  double ecartA1, ecartA2, ecartA3, ecartB1, ecartB2, ecartB3 ;
  double ecartC1, ecartC2, ecartC3, ecartD1, ecartD2, ecartD3 ;
  double R1,R2 ;

  double xA = xa ;
  double yA = ya ;
  double xB = xb ;
  double yB = yb ;

  x2 = x1 = centre_x ;
  y2 = y1 = centre_y - plusProcheEntier(r2 * _normalisation) ;
  R1 = r1 ; R2 = r2 ;
  X2 = X1 = 0 ; Y2 = Y1 = R2 ;

  x4 = x3 = centre_x ;
  y4 = y3 = centre_y + plusProcheEntier(r2 * _normalisation) ;
  X4 = X3 = 0 ; Y4 = Y3 = -R2 ;

  if ((x1 >= 0 && x1 < _ecran.NbLigne() && y1 >= 0 && y1 < _ecran.NbColonne()) 
      && _ecran(x1,y1)->getType() != PAROI_CLASSIQUE && _ecran(x1,y1)->getType() != PAROI_GENERATRICE && appartient(X1,Y1,xA,yA,xB,yB)) 
    {
      delete _ecran(x1,y1) ;
      _ecran(x1,y1) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x1,y1) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }

  if ((x2 >= 0 && x2 < _ecran.NbLigne() && y2 >= 0 && y2 < _ecran.NbColonne()) 
      && _ecran(x2,y2)->getType() != PAROI_CLASSIQUE && _ecran(x2,y2)->getType() != PAROI_GENERATRICE && appartient(X2,Y2,xA,yA,xB,yB))
    {
      delete _ecran(x2,y2) ;
      _ecran(x2,y2) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x2,y2) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }

  if ((x3 >= 0 && x3 < _ecran.NbLigne() && y3 >= 0 && y3 < _ecran.NbColonne()) 
      && _ecran(x3,y3)->getType() != PAROI_CLASSIQUE && _ecran(x3,y3)->getType() != PAROI_GENERATRICE && appartient(X3,Y3,xA,yA,xB,yB))
    {
      delete _ecran(x3,y3) ;
      _ecran(x3,y3) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x3,y3) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }
  
  if ((x4 >= 0 && x4 < _ecran.NbLigne() && y4 >= 0 && y4 < _ecran.NbColonne()) 
      && _ecran(x4,y4)->getType() != PAROI_CLASSIQUE && _ecran(x4,y4)->getType() != PAROI_GENERATRICE && appartient(X4,Y4,xA,yA,xB,yB))
    {
      delete _ecran(x4,y4) ;
      _ecran(x4,y4) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x4,y4) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }
      
  

  while (Y1 >= 0)
    {
      ecartA1 = fabs(calculEcart(X1+1,Y1+(1/(2*_normalisation)),R1,R2)) ;
      ecartA2 = fabs(calculEcart(X1+1,Y1-(1/(2*_normalisation)),R1,R2)) ;
      ecartA3 = fabs(calculEcart(X1,Y1-1/_normalisation,R1,R2)) ;

      if (ecartA1 < ecartA2 && ecartA1 < ecartA3)
	{
	  x1++ ;
	  X1 = X1 + 1 ; Y1 = Y1+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartA2 <= ecartA1 && ecartA2 <= ecartA3)
	    {
	      x1++ ; y1++ ;
	      X1 = X1 + 1 ; Y1 = Y1 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y1++ ;
	      Y1 = Y1 - 1/_normalisation ;
	    }
	}

      ecartB1 = fabs(calculEcart(X2-1,Y2+(1/(2*_normalisation)),R1,R2)) ;
      ecartB2 = fabs(calculEcart(X2-1,Y2-(1/(2*_normalisation)),R1,R2)) ;
      ecartB3 = fabs(calculEcart(X2,Y2-1/_normalisation,R1,R2)) ;

      if (ecartB1 < ecartB2 && ecartB1 <ecartB3)
	{
	  x2-- ; y2-- ;
	  X2 = X2 - 1 ; Y2 = Y2+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartB2 <= ecartB1 && ecartB2 <= ecartB3)
	    {
	      x2-- ;
	      X2 = X2 - 1 ; Y2 = Y2 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y2++ ;
	      Y2 = Y2 - 1/_normalisation ;
	    }
	}

      ecartC1 = fabs(calculEcart(X3+1,Y3-(1/(2*_normalisation)),R1,R2)) ;
      ecartC2 = fabs(calculEcart(X3+1,Y3+(1/(2*_normalisation)),R1,R2)) ;
      ecartC3 = fabs(calculEcart(X3,Y3+1/_normalisation,R1,R2)) ;

      if (ecartC1 < ecartC2 && ecartC1 < ecartC3)
	{
	  x3++ ; y3++ ;
	  X3 = X3 + 1 ; Y3 = Y3-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartC2 <= ecartC1 && ecartC2 <= ecartC3)
	    {
	      x3++ ;
	      X3 = X3 + 1 ; Y3 = Y3 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y3-- ;
	      Y3 = Y3 + 1/_normalisation ;
	    }
	}

      ecartD1 = fabs(calculEcart(X4-1,Y4-(1/(2*_normalisation)),R1,R2)) ;
      ecartD2 = fabs(calculEcart(X4-1,Y4+(1/(2*_normalisation)),R1,R2)) ;
      ecartD3 = fabs(calculEcart(X4,Y4+1/_normalisation,R1,R2)) ;

      if (ecartD1 < ecartD2 && ecartD1 < ecartD3)
	{
	  x4-- ;
	  X4 = X4 - 1 ; Y4 = Y4-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartD2 <= ecartD1 && ecartD2 <= ecartD3)
	    {
	      x4-- ; y4-- ; 
	      X4 = X4 - 1 ; Y4 = Y4 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y4-- ;
	      Y4 = Y4 + 1/_normalisation ;
	    }
	}

      
      if ((x1 >= 0 && x1 < _ecran.NbLigne() && y1 >= 0 && y1 < _ecran.NbColonne()) 
	  && _ecran(x1,y1)->getType() != PAROI_CLASSIQUE && _ecran(x1,y1)->getType() != PAROI_GENERATRICE && appartient(X1,Y1,xA,yA,xB,yB)) 
	{
	  delete _ecran(x1,y1) ;
	  _ecran(x1,y1) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x1,y1) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      if ((x2 >= 0 && x2 < _ecran.NbLigne() && y2 >= 0 && y2 < _ecran.NbColonne()) 
	  && _ecran(x2,y2)->getType() != PAROI_CLASSIQUE && _ecran(x2,y2)->getType() != PAROI_GENERATRICE && appartient(X2,Y2,xA,yA,xB,yB))
	{
	  delete _ecran(x2,y2) ;
	  _ecran(x2,y2) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x2,y2) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      if ((x3 >= 0 && x3 < _ecran.NbLigne() && y3 >= 0 && y3 < _ecran.NbColonne()) 
	  && _ecran(x3,y3)->getType() != PAROI_CLASSIQUE && _ecran(x3,y3)->getType() != PAROI_GENERATRICE && appartient(X3,Y3,xA,yA,xB,yB))
	{
	  delete _ecran(x3,y3) ;
	  _ecran(x3,y3) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x3,y3) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      if ((x4 >= 0 && x4 < _ecran.NbLigne() && y4 >= 0 && y4 < _ecran.NbColonne()) 
	  && _ecran(x4,y4)->getType() != PAROI_CLASSIQUE && _ecran(x4,y4)->getType() != PAROI_GENERATRICE && appartient(X4,Y4,xA,yA,xB,yB))
	{
	  delete _ecran(x4,y4) ;
	  _ecran(x4,y4) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x4,y4) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      
    }

}


void PlanHexagonal::dessineEllipse(const Ellipse& ellipse, PourRemplirCellule * ceil)
{

  dessineEllipse(ellipse.getX(),ellipse.getY(),ellipse.getR1(),ellipse.getR2(),ceil) ;

}

void PlanHexagonal::dessineEllipse(int centre_x, int centre_y, int r1, int r2, PourRemplirCellule * ceil) 
{


  double X1, Y1, X2, Y2, X3, Y3, X4, Y4 ;
  int x1, y1, x2, y2, x3, y3, x4, y4 ;
  double ecartA1, ecartA2, ecartA3, ecartB1, ecartB2, ecartB3 ;
  double ecartC1, ecartC2, ecartC3, ecartD1, ecartD2, ecartD3 ;
  double R1,R2 ;


  x2 = x1 = centre_x ;
  y2 = y1 = centre_y - plusProcheEntier(r2 * _normalisation) ;
  R1 = r1 ; R2 = r2 ;
  X2 = X1 = 0 ; Y2 = Y1 = R2 ;

  x4 = x3 = centre_x ;
  y4 = y3 = centre_y + plusProcheEntier(r2 * _normalisation) ;
  X4 = X3 = 0 ; Y4 = Y3 = -R2 ;

  if ((x1 >= 0 && x1 < _ecran.NbLigne() && y1 >= 0 && y1 < _ecran.NbColonne()) 
      && _ecran(x1,y1)->getType() != PAROI_CLASSIQUE && _ecran(x1,y1)->getType() != PAROI_GENERATRICE) 
    {
      delete _ecran(x1,y1) ;
      _ecran(x1,y1) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x1,y1) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }

  if ((x2 >= 0 && x2 < _ecran.NbLigne() && y2 >= 0 && y2 < _ecran.NbColonne()) 
      && _ecran(x2,y2)->getType() != PAROI_CLASSIQUE && _ecran(x2,y2)->getType() != PAROI_GENERATRICE)
    {
      delete _ecran(x2,y2) ;
      _ecran(x2,y2) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x2,y2) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }

  if ((x3 >= 0 && x3 < _ecran.NbLigne() && y3 >= 0 && y3 < _ecran.NbColonne()) 
      && _ecran(x3,y3)->getType() != PAROI_CLASSIQUE && _ecran(x3,y3)->getType() != PAROI_GENERATRICE)
    {
      delete _ecran(x3,y3) ;
      _ecran(x3,y3) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x3,y3) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }
  
  if ((x4 >= 0 && x4 < _ecran.NbLigne() && y4 >= 0 && y4 < _ecran.NbColonne()) 
      && _ecran(x4,y4)->getType() != PAROI_CLASSIQUE && _ecran(x4,y4)->getType() != PAROI_GENERATRICE)
    {
      delete _ecran(x4,y4) ;
      _ecran(x4,y4) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
      if (_ecran(x4,y4) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
    }
      
  while (Y1 >= 0)
    {
      ecartA1 = fabs(calculEcart(X1+1,Y1+(1/(2*_normalisation)),R1,R2)) ;
      ecartA2 = fabs(calculEcart(X1+1,Y1-(1/(2*_normalisation)),R1,R2)) ;
      ecartA3 = fabs(calculEcart(X1,Y1-1/_normalisation,R1,R2)) ;

      if (ecartA1 < ecartA2 && ecartA1 < ecartA3)
	{
	  x1++ ;
	  X1 = X1 + 1 ; Y1 = Y1+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartA2 <= ecartA1 && ecartA2 <= ecartA3)
	    {
	      x1++ ; y1++ ;
	      X1 = X1 + 1 ; Y1 = Y1 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y1++ ;
	      Y1 = Y1 - 1/_normalisation ;
	    }
	}

      ecartB1 = fabs(calculEcart(X2-1,Y2+(1/(2*_normalisation)),R1,R2)) ;
      ecartB2 = fabs(calculEcart(X2-1,Y2-(1/(2*_normalisation)),R1,R2)) ;
      ecartB3 = fabs(calculEcart(X2,Y2-1/_normalisation,R1,R2)) ;

      if (ecartB1 < ecartB2 && ecartB1 <ecartB3)
	{
	  x2-- ; y2-- ;
	  X2 = X2 - 1 ; Y2 = Y2+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartB2 <= ecartB1 && ecartB2 <= ecartB3)
	    {
	      x2-- ;
	      X2 = X2 - 1 ; Y2 = Y2 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y2++ ;
	      Y2 = Y2 - 1/_normalisation ;
	    }
	}

      ecartC1 = fabs(calculEcart(X3+1,Y3-(1/(2*_normalisation)),R1,R2)) ;
      ecartC2 = fabs(calculEcart(X3+1,Y3+(1/(2*_normalisation)),R1,R2)) ;
      ecartC3 = fabs(calculEcart(X3,Y3+1/_normalisation,R1,R2)) ;

      if (ecartC1 < ecartC2 && ecartC1 < ecartC3)
	{
	  x3++ ; y3++ ;
	  X3 = X3 + 1 ; Y3 = Y3-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartC2 <= ecartC1 && ecartC2 <= ecartC3)
	    {
	      x3++ ;
	      X3 = X3 + 1 ; Y3 = Y3 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y3-- ;
	      Y3 = Y3 + 1/_normalisation ;
	    }
	}

      ecartD1 = fabs(calculEcart(X4-1,Y4-(1/(2*_normalisation)),R1,R2)) ;
      ecartD2 = fabs(calculEcart(X4-1,Y4+(1/(2*_normalisation)),R1,R2)) ;
      ecartD3 = fabs(calculEcart(X4,Y4+1/_normalisation,R1,R2)) ;

      if (ecartD1 < ecartD2 && ecartD1 < ecartD3)
	{
	  x4-- ;
	  X4 = X4 - 1 ; Y4 = Y4-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartD2 <= ecartD1 && ecartD2 <= ecartD3)
	    {
	      x4-- ; y4-- ; 
	      X4 = X4 - 1 ; Y4 = Y4 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y4-- ;
	      Y4 = Y4 + 1/_normalisation ;
	    }
	}

      
      if ((x1 >= 0 && x1 < _ecran.NbLigne() && y1 >= 0 && y1 < _ecran.NbColonne()) 
	  && _ecran(x1,y1)->getType() != PAROI_CLASSIQUE && _ecran(x1,y1)->getType() != PAROI_GENERATRICE) 
	{
	  delete _ecran(x1,y1) ;
	  _ecran(x1,y1) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x1,y1) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      if ((x2 >= 0 && x2 < _ecran.NbLigne() && y2 >= 0 && y2 < _ecran.NbColonne()) 
	  && _ecran(x2,y2)->getType() != PAROI_CLASSIQUE && _ecran(x2,y2)->getType() != PAROI_GENERATRICE)
	{
	  delete _ecran(x2,y2) ;
	  _ecran(x2,y2) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x2,y2) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      if ((x3 >= 0 && x3 < _ecran.NbLigne() && y3 >= 0 && y3 < _ecran.NbColonne()) 
	  && _ecran(x3,y3)->getType() != PAROI_CLASSIQUE && _ecran(x3,y3)->getType() != PAROI_GENERATRICE)
	{
	  delete _ecran(x3,y3) ;
	  _ecran(x3,y3) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x3,y3) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      if ((x4 >= 0 && x4 < _ecran.NbLigne() && y4 >= 0 && y4 < _ecran.NbColonne()) 
	  && _ecran(x4,y4)->getType() != PAROI_CLASSIQUE && _ecran(x4,y4)->getType() != PAROI_GENERATRICE)
	{
	  delete _ecran(x4,y4) ;
	  _ecran(x4,y4) = new InfoCellule(ceil->getType(), ceil->getCellule()) ;
	  if (_ecran(x4,y4) == NULL) { cerr << "[Not enought memory]" << endl ; exit(1) ; }
	}
      
      
    }
  
}

void PlanHexagonal::dessineRectangle(const Rectangle& rectangle, PourRemplirCellule * ceil) 
{
  DEBUG_SCENE(cerr << "dessine rectangle" << endl ;)


  int x1 = rectangle.getX1(), y1, x2, y2, x3 = rectangle.getX2(), y3 = rectangle.getY2(), x4, y4 ;

  if ((x3 - x1) % 2 != 0)
    {
      x3 += 1 ;
    }

  y1 = rectangle.getY1() ;
  x2 = x3 ;
  y2 = y1 + (x3 - x1) / 2 ;
  x4 = x1 ;
  y4 = y3 - (x3 - x1) / 2 ;
  
  dessineLigne(x1,y1,x2,y2,ceil) ;
  dessineLigne(x2,y2,x3,y3,ceil) ;
  dessineLigne(x3,y3,x4,y4,ceil) ;
  dessineLigne(x4,y4,x1,y1,ceil) ;

}

void PlanHexagonal::dessinePolygone(const Polygone& poly, PourRemplirCellule * ceil) 
{
  list<Ligne*> lignes = poly.getLignes() ;
  list<Ligne*>::iterator it_lignes ;
  
  for (it_lignes = lignes.begin(); it_lignes != lignes.end(); it_lignes++)
    {
      dessineLigne(*(*it_lignes), ceil) ;
    }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PlanHexagonal::rempliEllipse(const Ellipse& ellipse, PourRemplirCellule * ceil) 
{
  rempliEllipse(ellipse.getX(),ellipse.getY(),ellipse.getR1(),ellipse.getR2(),ceil) ;
}

void PlanHexagonal::rempliEllipse(const Ellipse& ellipse, int col) 
{
  rempliEllipse(ellipse.getX(),ellipse.getY(),ellipse.getR1(),ellipse.getR2(),col) ;
}


void PlanHexagonal::rempliEllipse(const Ellipse& ellipse, const vector<PhasePourcent>& tab_phase_pourcent)
{
  vector<float> tab = initTabPoids(tab_phase_pourcent) ;
  rempliEllipse(ellipse.getX(),ellipse.getY(),ellipse.getR1(),ellipse.getR2(),tab_phase_pourcent,tab) ;
}


void PlanHexagonal::rempliEllipse(int centre_x, int centre_y, int r1, int r2, PourRemplirCellule * ceil) 
{
  
  double X1, Y1, X2, Y2, X3, Y3, X4, Y4 ;
  int x1, y1, x2, y2, x3, y3, x4, y4 ;
  double ecartA1, ecartA2, ecartA3, ecartB1, ecartB2, ecartB3 ;
  double ecartC1, ecartC2, ecartC3, ecartD1, ecartD2, ecartD3 ;
  double R1,R2 ;


  x2 = x1 = centre_x ;
  y2 = y1 = centre_y - plusProcheEntier(r2 * _normalisation) ;
  R1 = r1 ; R2 = r2 ;
  X2 = X1 = 0 ; Y2 = Y1 = R2 ;

  x4 = x3 = centre_x ;
  y4 = y3 = centre_y + plusProcheEntier(r2 * _normalisation) ;
  X4 = X3 = 0 ; Y4 = Y3 = -R2 ;

  dessineLigne(x1,y1,x3,y3,ceil) ;
  dessineLigne(x2,y2,x4,y4,ceil) ;



  while (Y1 >= 0)
    {
      ecartA1 = fabs(calculEcart(X1+1,Y1+(1/(2*_normalisation)),R1,R2)) ;
      ecartA2 = fabs(calculEcart(X1+1,Y1-(1/(2*_normalisation)),R1,R2)) ;
      ecartA3 = fabs(calculEcart(X1,Y1-1/_normalisation,R1,R2)) ;

      if (ecartA1 < ecartA2 && ecartA1 < ecartA3)
	{
	  x1++ ;
	  X1 = X1 + 1 ; Y1 = Y1+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartA2 <= ecartA1 && ecartA2 <= ecartA3)
	    {
	      x1++ ; y1++ ;
	      X1 = X1 + 1 ; Y1 = Y1 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y1++ ;
	      Y1 = Y1 - 1/_normalisation ;
	    }
	}

      ecartB1 = fabs(calculEcart(X2-1,Y2+(1/(2*_normalisation)),R1,R2)) ;
      ecartB2 = fabs(calculEcart(X2-1,Y2-(1/(2*_normalisation)),R1,R2)) ;
      ecartB3 = fabs(calculEcart(X2,Y2-1/_normalisation,R1,R2)) ;

      if (ecartB1 < ecartB2 && ecartB1 <ecartB3)
	{
	  x2-- ; y2-- ;
	  X2 = X2 - 1 ; Y2 = Y2+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartB2 <= ecartB1 && ecartB2 <= ecartB3)
	    {
	      x2-- ;
	      X2 = X2 - 1 ; Y2 = Y2 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y2++ ;
	      Y2 = Y2 - 1/_normalisation ;
	    }
	}

      ecartC1 = fabs(calculEcart(X3+1,Y3-(1/(2*_normalisation)),R1,R2)) ;
      ecartC2 = fabs(calculEcart(X3+1,Y3+(1/(2*_normalisation)),R1,R2)) ;
      ecartC3 = fabs(calculEcart(X3,Y3+1/_normalisation,R1,R2)) ;

      if (ecartC1 < ecartC2 && ecartC1 < ecartC3)
	{
	  x3++ ; y3++ ;
	  X3 = X3 + 1 ; Y3 = Y3-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartC2 <= ecartC1 && ecartC2 <= ecartC3)
	    {
	      x3++ ;
	      X3 = X3 + 1 ; Y3 = Y3 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y3-- ;
	      Y3 = Y3 + 1/_normalisation ;
	    }
	}

      ecartD1 = fabs(calculEcart(X4-1,Y4-(1/(2*_normalisation)),R1,R2)) ;
      ecartD2 = fabs(calculEcart(X4-1,Y4+(1/(2*_normalisation)),R1,R2)) ;
      ecartD3 = fabs(calculEcart(X4,Y4+1/_normalisation,R1,R2)) ;

      if (ecartD1 < ecartD2 && ecartD1 < ecartD3)
	{
	  x4-- ;
	  X4 = X4 - 1 ; Y4 = Y4-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartD2 <= ecartD1 && ecartD2 <= ecartD3)
	    {
	      x4-- ; y4-- ; 
	      X4 = X4 - 1 ; Y4 = Y4 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y4-- ;
	      Y4 = Y4 + 1/_normalisation ;
	    }
	}

      dessineLigne(x1,y1,x3,y3,ceil) ;
      dessineLigne(x2,y2,x4,y4,ceil) ;

    }

}


void PlanHexagonal::rempliEllipse(int centre_x, int centre_y, int r1, int r2, int col) 
{
  
  double X1, Y1, X2, Y2, X3, Y3, X4, Y4 ;
  int x1, y1, x2, y2, x3, y3, x4, y4 ;
  double ecartA1, ecartA2, ecartA3, ecartB1, ecartB2, ecartB3 ;
  double ecartC1, ecartC2, ecartC3, ecartD1, ecartD2, ecartD3 ;
  double R1,R2 ;


  x2 = x1 = centre_x ;
  y2 = y1 = centre_y - plusProcheEntier(r2 * _normalisation) ;
  R1 = r1 ; R2 = r2 ;
  X2 = X1 = 0 ; Y2 = Y1 = R2 ;

  x4 = x3 = centre_x ;
  y4 = y3 = centre_y + plusProcheEntier(r2 * _normalisation) ;
  X4 = X3 = 0 ; Y4 = Y3 = -R2 ;

  dessineLigne(x1,y1,x3,y3,col) ;
  dessineLigne(x2,y2,x4,y4,col) ;



  while (Y1 >= 0)
    {
      ecartA1 = fabs(calculEcart(X1+1,Y1+(1/(2*_normalisation)),R1,R2)) ;
      ecartA2 = fabs(calculEcart(X1+1,Y1-(1/(2*_normalisation)),R1,R2)) ;
      ecartA3 = fabs(calculEcart(X1,Y1-1/_normalisation,R1,R2)) ;

      if (ecartA1 < ecartA2 && ecartA1 < ecartA3)
	{
	  x1++ ;
	  X1 = X1 + 1 ; Y1 = Y1+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartA2 <= ecartA1 && ecartA2 <= ecartA3)
	    {
	      x1++ ; y1++ ;
	      X1 = X1 + 1 ; Y1 = Y1 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y1++ ;
	      Y1 = Y1 - 1/_normalisation ;
	    }
	}

      ecartB1 = fabs(calculEcart(X2-1,Y2+(1/(2*_normalisation)),R1,R2)) ;
      ecartB2 = fabs(calculEcart(X2-1,Y2-(1/(2*_normalisation)),R1,R2)) ;
      ecartB3 = fabs(calculEcart(X2,Y2-1/_normalisation,R1,R2)) ;

      if (ecartB1 < ecartB2 && ecartB1 <ecartB3)
	{
	  x2-- ; y2-- ;
	  X2 = X2 - 1 ; Y2 = Y2+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartB2 <= ecartB1 && ecartB2 <= ecartB3)
	    {
	      x2-- ;
	      X2 = X2 - 1 ; Y2 = Y2 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y2++ ;
	      Y2 = Y2 - 1/_normalisation ;
	    }
	}

      ecartC1 = fabs(calculEcart(X3+1,Y3-(1/(2*_normalisation)),R1,R2)) ;
      ecartC2 = fabs(calculEcart(X3+1,Y3+(1/(2*_normalisation)),R1,R2)) ;
      ecartC3 = fabs(calculEcart(X3,Y3+1/_normalisation,R1,R2)) ;

      if (ecartC1 < ecartC2 && ecartC1 < ecartC3)
	{
	  x3++ ; y3++ ;
	  X3 = X3 + 1 ; Y3 = Y3-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartC2 <= ecartC1 && ecartC2 <= ecartC3)
	    {
	      x3++ ;
	      X3 = X3 + 1 ; Y3 = Y3 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y3-- ;
	      Y3 = Y3 + 1/_normalisation ;
	    }
	}

      ecartD1 = fabs(calculEcart(X4-1,Y4-(1/(2*_normalisation)),R1,R2)) ;
      ecartD2 = fabs(calculEcart(X4-1,Y4+(1/(2*_normalisation)),R1,R2)) ;
      ecartD3 = fabs(calculEcart(X4,Y4+1/_normalisation,R1,R2)) ;

      if (ecartD1 < ecartD2 && ecartD1 < ecartD3)
	{
	  x4-- ;
	  X4 = X4 - 1 ; Y4 = Y4-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartD2 <= ecartD1 && ecartD2 <= ecartD3)
	    {
	      x4-- ; y4-- ; 
	      X4 = X4 - 1 ; Y4 = Y4 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y4-- ;
	      Y4 = Y4 + 1/_normalisation ;
	    }
	}

      dessineLigne(x1,y1,x3,y3,col) ;
      dessineLigne(x2,y2,x4,y4,col) ;

    }

}


void PlanHexagonal::rempliEllipse(int centre_x, int centre_y, int r1, int r2, 
				  const vector<PhasePourcent>& tab_phase_pourcent, vector<float>& tab) 
{
  
  double X1, Y1, X2, Y2, X3, Y3, X4, Y4 ;
  int x1, y1, x2, y2, x3, y3, x4, y4 ;
  double ecartA1, ecartA2, ecartA3, ecartB1, ecartB2, ecartB3 ;
  double ecartC1, ecartC2, ecartC3, ecartD1, ecartD2, ecartD3 ;
  double R1,R2 ;


  x2 = x1 = centre_x ;
  y2 = y1 = centre_y - plusProcheEntier(r2 * _normalisation) ;
  R1 = r1 ; R2 = r2 ;
  X2 = X1 = 0 ; Y2 = Y1 = R2 ;

  x4 = x3 = centre_x ;
  y4 = y3 = centre_y + plusProcheEntier(r2 * _normalisation) ;
  X4 = X3 = 0 ; Y4 = Y3 = -R2 ;

  dessineLigne(x1,y1,x3,y3,tab_phase_pourcent,tab) ;
  dessineLigne(x2,y2,x4,y4,tab_phase_pourcent,tab) ;



  while (Y1 >= 0)
    {
      ecartA1 = fabs(calculEcart(X1+1,Y1+(1/(2*_normalisation)),R1,R2)) ;
      ecartA2 = fabs(calculEcart(X1+1,Y1-(1/(2*_normalisation)),R1,R2)) ;
      ecartA3 = fabs(calculEcart(X1,Y1-1/_normalisation,R1,R2)) ;

      if (ecartA1 < ecartA2 && ecartA1 < ecartA3)
	{
	  x1++ ;
	  X1 = X1 + 1 ; Y1 = Y1+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartA2 <= ecartA1 && ecartA2 <= ecartA3)
	    {
	      x1++ ; y1++ ;
	      X1 = X1 + 1 ; Y1 = Y1 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y1++ ;
	      Y1 = Y1 - 1/_normalisation ;
	    }
	}

      ecartB1 = fabs(calculEcart(X2-1,Y2+(1/(2*_normalisation)),R1,R2)) ;
      ecartB2 = fabs(calculEcart(X2-1,Y2-(1/(2*_normalisation)),R1,R2)) ;
      ecartB3 = fabs(calculEcart(X2,Y2-1/_normalisation,R1,R2)) ;

      if (ecartB1 < ecartB2 && ecartB1 <ecartB3)
	{
	  x2-- ; y2-- ;
	  X2 = X2 - 1 ; Y2 = Y2+(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartB2 <= ecartB1 && ecartB2 <= ecartB3)
	    {
	      x2-- ;
	      X2 = X2 - 1 ; Y2 = Y2 - (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y2++ ;
	      Y2 = Y2 - 1/_normalisation ;
	    }
	}

      ecartC1 = fabs(calculEcart(X3+1,Y3-(1/(2*_normalisation)),R1,R2)) ;
      ecartC2 = fabs(calculEcart(X3+1,Y3+(1/(2*_normalisation)),R1,R2)) ;
      ecartC3 = fabs(calculEcart(X3,Y3+1/_normalisation,R1,R2)) ;

      if (ecartC1 < ecartC2 && ecartC1 < ecartC3)
	{
	  x3++ ; y3++ ;
	  X3 = X3 + 1 ; Y3 = Y3-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartC2 <= ecartC1 && ecartC2 <= ecartC3)
	    {
	      x3++ ;
	      X3 = X3 + 1 ; Y3 = Y3 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y3-- ;
	      Y3 = Y3 + 1/_normalisation ;
	    }
	}

      ecartD1 = fabs(calculEcart(X4-1,Y4-(1/(2*_normalisation)),R1,R2)) ;
      ecartD2 = fabs(calculEcart(X4-1,Y4+(1/(2*_normalisation)),R1,R2)) ;
      ecartD3 = fabs(calculEcart(X4,Y4+1/_normalisation,R1,R2)) ;

      if (ecartD1 < ecartD2 && ecartD1 < ecartD3)
	{
	  x4-- ;
	  X4 = X4 - 1 ; Y4 = Y4-(1/(2*_normalisation)) ;
	}
      else
	{
	  if (ecartD2 <= ecartD1 && ecartD2 <= ecartD3)
	    {
	      x4-- ; y4-- ; 
	      X4 = X4 - 1 ; Y4 = Y4 + (1/(2*_normalisation)) ;
	    }
	  else
	    {
	      y4-- ;
	      Y4 = Y4 + 1/_normalisation ;
	    }
	}

      dessineLigne(x1,y1,x3,y3,tab_phase_pourcent,tab) ;
      dessineLigne(x2,y2,x4,y4,tab_phase_pourcent,tab) ;

    }

}

void PlanHexagonal::rempliPolygone(const Polygone& poly, PourRemplirCellule * ceil) 
{

  list<Ligne*> lignes = poly.getLignes() ;
  list<Ligne*>::iterator it_lignes ;
  vector<Arete> tab ;
  for (it_lignes = lignes.begin(); it_lignes != lignes.end(); it_lignes++)
    {
      tab.push_back(Arete(*(*it_lignes))) ;
    }
  DEBUG_SCENE(cerr << "rempli" << endl ;)
  rempliPolygone(tab,ceil) ;

}

void PlanHexagonal::rempliPolygone(const Polygone& poly, int col)
{

  list<Ligne*> lignes = poly.getLignes() ;
  list<Ligne*>::iterator it_lignes ;
  vector<Arete> tab ;
  for (it_lignes = lignes.begin(); it_lignes != lignes.end(); it_lignes++)
    {
      tab.push_back(Arete(*(*it_lignes))) ;
    }

  rempliPolygone(tab,col) ;

}


void PlanHexagonal::rempliPolygone(const Polygone& poly, const vector<PhasePourcent>& tab_phase_pourcent)
{
  
  list<Ligne*> lignes = poly.getLignes() ;
  list<Ligne*>::iterator it_lignes ;
  vector<Arete> tab ;
  for (it_lignes = lignes.begin(); it_lignes != lignes.end(); it_lignes++)
    {
      tab.push_back(Arete(*(*it_lignes))) ;
    }


  DEBUG_SCENE(cerr << "rempli" << endl ;)
  vector<float> tab_poids = initTabPoids(tab_phase_pourcent) ;
  rempliPolygone(tab,tab_phase_pourcent,tab_poids) ;
  DEBUG_SCENE(cerr << "fin" << endl ;)
}




void PlanHexagonal::rempliPolygone(const vector<Arete>& t, PourRemplirCellule * ceil)
{
  vector<Arete> tab ;
  int min_x, max_x, min_y, max_y ;

  rechercheMinEtMax(t,min_x,max_x,min_y,max_y) ;

  for (unsigned int i = 0; i < t.size(); i++)
    {
      if (!t[i].estHorizontale()) tab.push_back(t[i]) ;
      else dessineLigne(t[i].getX1(),t[i].getY1(),t[i].getX2(),t[i].getY2(),ceil) ;
    }
  
  for (int i = min_y ; i <= max_y; i++)
    {
    
      vector<int> tab_x = rechercheArreteSecante(i,tab) ;
      
      for(unsigned int k = 0; k < tab_x.size(); k+=2)
	{
	  if (k+1 >= tab_x.size()) break ;
	  dessineLigne(tab_x[k],i,tab_x[k+1],i,ceil) ;
	}
    }
}

void PlanHexagonal::rempliPolygone(const vector<Arete>& t, int col)
{
  vector<Arete> tab ;
  int min_x, max_x, min_y, max_y ;

  rechercheMinEtMax(t,min_x,max_x,min_y,max_y) ;

  for (unsigned int i = 0; i < t.size(); i++)
    {
      if (!t[i].estHorizontale()) tab.push_back(t[i]) ;
      else dessineLigne(t[i].getX1(),t[i].getY1(),t[i].getX2(),t[i].getY2(),col) ;
    }
  
  for (int i = min_y ; i <= max_y; i++)
    {

      vector<int> tab_x = rechercheArreteSecante(i,tab) ;
      
      for(unsigned int k = 0; k < tab_x.size(); k+=2)
	{
	  if (k+1 >= tab_x.size()) break ;
	  dessineLigne(tab_x[k],i,tab_x[k+1],i,col) ;
	}
    }
}

void PlanHexagonal::rempliPolygone(const vector<Arete>& t, const vector<PhasePourcent>& tab_phase_pourcent,
				   vector<float>& tab)
{
  vector<Arete> tab_arete ;
  int min_x, max_x, min_y, max_y ;

  rechercheMinEtMax(t,min_x,max_x,min_y,max_y) ;

  for (unsigned int i = 0; i < t.size(); i++)
    {
      if (!t[i].estHorizontale()) tab_arete.push_back(t[i]) ;
      else dessineLigne(t[i].getX1(),t[i].getY1(),t[i].getX2(),t[i].getY2(),tab_phase_pourcent,tab) ;
    }

  //  afficheEcran() ;
  
  for (int i = min_y ; i <= max_y; i++)
    {

      vector<int> tab_x = rechercheArreteSecante(i,tab_arete) ;
      
      for(unsigned int k = 0; k < tab_x.size(); k+=2)
	{
	  if (k+1 >= tab_x.size()) break ;
	  dessineLigne(tab_x[k],i,tab_x[k+1],i,tab_phase_pourcent,tab) ;
	}
    }
}


void PlanHexagonal::rempliRectangle(const Rectangle& rectangle, PourRemplirCellule * ceil)
{
  vector<Arete> tab ;

  int x1 = rectangle.getX1(), y1, x2, y2, x3 = rectangle.getX2(), y3 = rectangle.getY2(), x4, y4 ;

  if ((x3 - x1) % 2 != 0)
    {
      x3 += 1 ;
    }

  y1 = rectangle.getY1() ;
  x2 = x3 ;
  y2 = y1 + (x3 - x1) / 2 ;
  x4 = x1 ;
  y4 = y3 - (x3 - x1) / 2 ;
  
  tab.push_back(Arete(x1,y1,x2,y2)) ;
  tab.push_back(Arete(x2,y2,x3,y3)) ;
  tab.push_back(Arete(x3,y3,x4,y4)) ;
  tab.push_back(Arete(x4,y4,x1,y1)) ;

  
  rempliPolygone(tab,ceil) ;

}

void PlanHexagonal::rempliRectangle(const Rectangle& rectangle, int col)
{
  vector<Arete> tab ;
  
  int x1 = rectangle.getX1(), y1, x2, y2, x3 = rectangle.getX2(), y3 = rectangle.getY2(), x4, y4 ;

  if ((x3 - x1) % 2 != 0)
    {
      x3 += 1 ;
    }

  y1 = rectangle.getY1() ;
  x2 = x3 ;
  y2 = y1 + (x3 - x1) / 2 ;
  x4 = x1 ;
  y4 = y3 - (x3 - x1) / 2 ;
  
  tab.push_back(Arete(x1,y1,x2,y2)) ;
  tab.push_back(Arete(x2,y2,x3,y3)) ;
  tab.push_back(Arete(x3,y3,x4,y4)) ;
  tab.push_back(Arete(x4,y4,x1,y1)) ;

  rempliPolygone(tab,col) ;

}

void PlanHexagonal::rempliRectangle(const Rectangle& rectangle, const vector<PhasePourcent>& tab_phase_pourcent)
{
  vector<Arete> tab ;
  
  int x1 = rectangle.getX1(), y1, x2, y2, x3 = rectangle.getX2(), y3 = rectangle.getY2(), x4, y4 ;

  if ((x3 - x1) % 2 != 0)
    {
      x3 += 1 ;
    }

  y1 = rectangle.getY1() ;
  x2 = x3 ;
  y2 = y1 + (x3 - x1) / 2 ;
  x4 = x1 ;
  y4 = y3 - (x3 - x1) / 2 ;
  
  tab.push_back(Arete(x1,y1,x2,y2)) ;
  tab.push_back(Arete(x2,y2,x3,y3)) ;
  tab.push_back(Arete(x3,y3,x4,y4)) ;
  tab.push_back(Arete(x4,y4,x1,y1)) ;

  vector<float> poids = initTabPoids(tab_phase_pourcent) ;

  rempliPolygone(tab,tab_phase_pourcent,poids) ;

}


  
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


Ligne* PlanHexagonal::proportionneLigne(const Ligne *ligne)
{
 
  int x1, y1, x2, y2 ;
  double X1,Y1,X2,Y2 ;
  //translateLigne(ligne,ligneTranslate) ;

  coordonneeVectorielVersBitmap(ligne->getX1(), ligne->getY1(), X1, Y1) ; 
  coordonneeVectorielVersBitmap(ligne->getX2(), ligne->getY2(), X2, Y2) ;

  x1 = plusProcheEntier(X1) ;
  y1 = plusProcheEntier(Y1) ;
  x2 = plusProcheEntier(X2) ;
  y2 = plusProcheEntier(Y2) ;

  if (ligne->getY1() == ligne->getY2())
    {
      int x_min = min(x1,x2) ;
      int x_max = max(x1,x2) ;

      if ((x_max - x_min) % 2 != 0)
	{
	  x_max += 1 ;
	}
 
      if (x1 != x_min)
	{
	  x1 = x2 ;
	  y1 = y2 ;
	}

      x2 = x_max ;
      y2 = y1 + (x_max - x_min) / 2 ;
    }

  return new Ligne(x1,y1,x2,y2);

}

ArcEllipse PlanHexagonal::proportionneArcEllipse(const ArcEllipse& arc_ellipse)
{

  int x, y, r1, r2, x1, y1, x2, y2 ;
  double X,Y,R1,R2,X1,Y1,X2,Y2 ;

  coordonneeVectorielVersBitmap(arc_ellipse.getX(), arc_ellipse.getY(), X, Y) ; 
  coordonneeVectorielVersBitmap(arc_ellipse.getX1(), arc_ellipse.getY1(), X1, Y1) ;
  coordonneeVectorielVersBitmap(arc_ellipse.getX2(), arc_ellipse.getY2(), X2, Y2) ;

  
  double tmp_x, tmp_y ;
  coordonneeVectorielVersBitmap(arc_ellipse.getX()+arc_ellipse.getR1(),arc_ellipse.getY(),tmp_x,tmp_y) ;
  R1 = tmp_x - X ;

  coordonneeVectorielVersBitmap(arc_ellipse.getX(),arc_ellipse.getY()-arc_ellipse.getR2(),tmp_x,tmp_y) ;
  R2 = Y - tmp_y ;
  
  X1 = (double(arc_ellipse.getX1() - arc_ellipse.getX()) / double(arc_ellipse.getR1())) * R1 ;

  X2 = (double(arc_ellipse.getX2() - arc_ellipse.getX()) / double(arc_ellipse.getR1())) * R1 ;

  Y1 = (double(arc_ellipse.getY() - arc_ellipse.getY1()) / double(arc_ellipse.getR2())) * R2 ;

  Y2 = (double(arc_ellipse.getY() - arc_ellipse.getY2()) / double(arc_ellipse.getR2())) * R2 ;

  x = plusProcheEntier(X) ;
  y = plusProcheEntier(Y) ;

  r1 = plusProcheEntier(R1) ;
  r2 = plusProcheEntier(R2 / _normalisation) ;

  x1 = plusProcheEntier(X1) ;
  y1 = plusProcheEntier(Y1 / _normalisation) ;

  x2 = plusProcheEntier(X2) ;
  y2 = plusProcheEntier(Y2 / _normalisation) ;

  return ArcEllipse(x,y,r1,r2,x1,y1,x2,y2) ;

}

Ellipse PlanHexagonal::proportionneEllipse(const Ellipse& ellipse)
{
  
  int x, y, r1, r2 ;
  double X,Y,R1,R2 ;
  coordonneeVectorielVersBitmap(ellipse.getX(), ellipse.getY(), X, Y) ; 


  double tmp_x, tmp_y ;
  coordonneeVectorielVersBitmap(ellipse.getX()+ellipse.getR1(),ellipse.getY(),tmp_x,tmp_y) ;
  R1 = tmp_x - X ;

  coordonneeVectorielVersBitmap(ellipse.getX(),ellipse.getY()-ellipse.getR2(),tmp_x,tmp_y) ;
  R2 = Y - tmp_y ;

  x = plusProcheEntier(X) ;
  y = plusProcheEntier(Y) ;

  r1 = plusProcheEntier(R1) ;
  r2 = plusProcheEntier(R2 / _normalisation) ;

  return Ellipse(x,y,r1,r2) ;

}

/*
Rectangle PlanHexagonal::translateRectangle(Rectangle r)
{
  return Rectangle(r.getX1(),r.getY1(),r.getX2(),r.getY2() + (r.getX2() - r.getX1()) * _tangente30 * _normalisation) ;
}
*/

Rectangle PlanHexagonal::proportionneRectangle(const Rectangle& rectangle)
{

  int x1, y1, x2, y2 ;
  double X1,Y1,X2,Y2 ;

  //Rectangle rectangleTranslate = translateRectangle(rectangle) ;

  coordonneeVectorielVersBitmap(rectangle.getX1(),rectangle.getY1(),X1,Y1) ;
  coordonneeVectorielVersBitmap(rectangle.getX2(),rectangle.getY2(),X2,Y2) ;

  x1 = plusProcheEntier(X1) ;
  y1 = plusProcheEntier(Y1) ;

  x2 = plusProcheEntier(X2) ;
  y2 = plusProcheEntier(Y2) ;

  return Rectangle(x1,y1,x2,y2) ;

}
/*
Polygone PlanHexagonal::translatePolygone(Polygone p)
{

  Polygone res ;
  Ligne tmp1, tmp2 ;

  list<Ligne> lignes = p.getLignes() ;
  list<Ligne>::iterator it_lignes ;

  it_lignes = lignes.begin() ;
  tmp1 = tmp2 = proportionneLigne(*it_lignes) ;
  it_lignes++ ;

  for (; it_lignes != lignes.end(); it_lignes++)
    {
      tmp1 = proportionneLigne(*it_lignes) ;
      
      res.ajouteLignePolygone(proportionneLigne(*it_lignes)) ;
    }

  return res ;

}
*/


 Polygone PlanHexagonal::mettreAJourPolygone(vector<Ligne> ancienPolygone, vector<Ligne> nouveauPolygone,
 						   const vector<Ligne>& ancienHorizontale, const vector<Ligne>& nouveauHorizontale)
 {
 
 	 Polygone res ;
 
 	 int ancienX, ancienY, nouveauX, nouveauY ;
 	 bool point1_deja_change ;
 	 bool point2_deja_change ;
 	     
 	 for (unsigned int i = 0; i < ancienPolygone.size(); i++)
 	   {
 	       point1_deja_change = false ;
 	       point2_deja_change = false ;
 
 
 	     for (unsigned int j = 0; j < nouveauHorizontale.size(); j++)
 	       {
 
 
 
 		 if (ancienHorizontale[j].getX2() >= ancienHorizontale[j].getX1())
 		   {
 		     ancienX = ancienHorizontale[j].getX2() ;
 		     ancienY = ancienHorizontale[j].getY2() ;
 		 
 		     nouveauX = nouveauHorizontale[j].getX2() ;
 		     nouveauY = nouveauHorizontale[j].getY2() ;
 		   }
 		 else
 		   {
 		     ancienX = ancienHorizontale[j].getX1() ;
 		     ancienY = ancienHorizontale[j].getY1() ;
 		 
 		     nouveauX = nouveauHorizontale[j].getX2() ;
 		     nouveauY = nouveauHorizontale[j].getY2() ;
 
 		   }
 		 
 		 if (!point1_deja_change && ancienPolygone[i].getX1() == ancienX && ancienPolygone[i].getY1() == ancienY)
 		   {
 		     nouveauPolygone[i] = Ligne(nouveauX,nouveauY,nouveauPolygone[i].getX2(),nouveauPolygone[i].getY2()) ;
 
 		     point1_deja_change = true ;
 		   }
 
 		 if (!point2_deja_change && ancienPolygone[i].getX2() == ancienX && ancienPolygone[i].getY2() == ancienY)
 		   {	      
 		     nouveauPolygone[i] = Ligne(nouveauPolygone[i].getX1(),nouveauPolygone[i].getY1(),nouveauX,nouveauY) ;
 
 		     point2_deja_change = true ;  
 		   }
 	     
 		 
 	       }
 
 	   }
 
 	 
 	 for (unsigned int i = 0; i < nouveauHorizontale.size(); i++)
 	   {
 	     res.ajoutLigne(nouveauHorizontale[i].clone()) ;
 	   }
 
 	 for (unsigned int i = 0; i < nouveauPolygone.size(); i++)
 	   {
 	     res.ajoutLigne(nouveauPolygone[i].clone()) ;
 	   }
 	 
 	 return res ;
 
 }
 
 Polygone PlanHexagonal::assembleHorizontaleEtVerticale(const Polygone& polygone)
 {
 
 	 Polygone res ;
 
 	 list<Ligne*> lignes = polygone.getLignes() ;
 	 list<Ligne*>::iterator it_lignes ;
 
 	 vector<Ligne> horizontale ;
 	 vector<Ligne> verticale ;
 
 	 for (it_lignes = lignes.begin(); it_lignes != lignes.end(); it_lignes++)
 	   {
 	     if ((*it_lignes)->getY1() == (*it_lignes)->getY2()) 
 	       {
 		 horizontale.push_back(*(*it_lignes)) ;
 	       }
 	     else
 	       {
 		 if ((*it_lignes)->getX1() == (*it_lignes)->getX2())
 		   {
 		     verticale.push_back(*(*it_lignes)) ;
 		   }
 		 else
 		   {
 		     res.ajoutLigne(*it_lignes) ;
 		   }
 	       }
 
 	   }
 
 
 	 bool trouve = false ;
 
 	 for (unsigned int i = 0; i < horizontale.size(); i++)
 	   {
 	     Ligne tmp = horizontale[i] ;
 
 	     for (unsigned int j = i+1; j < horizontale.size(); j++)
 	       {
 		 if (tmp.getY1() == horizontale[j].getY1() && ((tmp.getX1() == horizontale[j].getX1())
							       || (tmp.getX1() == horizontale[j].getX2())
							       || (tmp.getX2() == horizontale[j].getX1())
							       || (tmp.getX2() == horizontale[j].getX2())))
 		   {
		     
 		     horizontale[j] = Ligne(min(min(tmp.getX2(),horizontale[j].getX2()),min(tmp.getX1(),horizontale[j].getX1())),
 					    tmp.getY1(),
 					    max(max(tmp.getX2(),horizontale[j].getX2()),max(tmp.getX1(),horizontale[j].getX1())),
 					    tmp.getY1()) ;
 		     trouve = true ;
 		     break ;
 		   }
 	       }
 		 if (trouve == false) res.ajoutLigne(tmp.clone()) ;
 		 trouve = false ;
 	   }
 
 
 	 trouve = false ;
 
 	 for (unsigned int i = 0; i < verticale.size(); i++)
 	   {
 	     Ligne tmp = verticale[i] ;
 	     
 	     for (unsigned int j = i+1; j < verticale.size(); j++)
 	       {
 		 if (tmp.getX1() == verticale[j].getX1() && ((tmp.getY1() == verticale[j].getY1())
							       || (tmp.getY1() == verticale[j].getY2())
							       || (tmp.getY2() == verticale[j].getY1())
							       || (tmp.getY2() == verticale[j].getY2())))
 		   {
 		     verticale[j] = Ligne(tmp.getX1(),
 					  min(min(tmp.getY2(),verticale[j].getY2()),min(tmp.getY1(),verticale[j].getY1())),
 					  tmp.getX1(),
 					  max(max(tmp.getY2(),verticale[j].getY2()),max(tmp.getY1(),verticale[j].getY1()))) ;
 					  
 		     trouve = true ;
 		     break ;
 		   }
 	       }
 	     if (trouve == false) res.ajoutLigne(tmp.clone()) ;
 	     trouve = false ;
 	   }
 	 
 	 return res ;
 	 
 }
 
 
// Polygone PlanHexagonal::proportionnePolygone(const Polygone& polygone)
// {
// 
//	   vector<Ligne> ancien ;
//	   vector<Ligne> nouveau ;
// 
//	   Polygone poly = assembleHorizontaleEtVerticale(polygone) ;
// 
//	   //Polygone polygoneTranslate = translatePolygone(polygone) ;
//	   
//	   vector<Ligne> ancien_horizontale ;
//	   vector<Ligne> nouveau_horizontale ;
// 
//	   list<Ligne*> lignes = poly.getLignes() ;
//	   list<Ligne*>::iterator it_lignes ;
// 
//	   
//	   for (it_lignes = lignes.begin(); it_lignes != lignes.end(); it_lignes++)
//	     {
//	       if ((*it_lignes)->getY1() == (*it_lignes)->getY2()) 
//		 {
//		   ancien_horizontale.push_back(*(*it_lignes)) ;
//		   nouveau_horizontale.push_back(*(proportionneLigne(*it_lignes))) ;
//		 }
//	       else
//		 {
//		   ancien.push_back(*(*it_lignes)) ;
//		   nouveau.push_back(*(proportionneLigne(*it_lignes))) ;
//		 }
// 
//	     }
// 
//	   return mettreAJourPolygone(ancien, nouveau, ancien_horizontale, nouveau_horizontale) ;
// 
// }



Polygone PlanHexagonal::proportionnePolygone(const Polygone& polygone)
{

	   Polygone res ;

	   //Polygone polygoneTranslate = translatePolygone(polygone) ;

	   Polygone poly = assembleHorizontaleEtVerticale(polygone) ;

	   list<Ligne*> lignes = poly.getLignes() ;
	   list<Ligne*>::iterator it_lignes ;

	   for (it_lignes = lignes.begin(); it_lignes != lignes.end(); it_lignes++)
	     {
	       res.ajoutLigne(proportionneLigne(*it_lignes)) ;
	     }

	   return res ;

}
 
