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

#ifndef __PLANHEXAGONAL_H__
#define __PLANHEXAGONAL_H__

#include "CommunScene.h"

#include "Matrice.h"
#include <stdio.h>
#include <string>
#include <vector>

#include "Scene.h"
#include "PhasePourcent.h"
#include "Frontiere.h"

#include "Automate.h"
#include "Cellule.h"
#include "Particule.h"

#include "ContientHorsScene.h"



#define max(A,B) ((A) > (B) ? (A) : (B))
#define min(A,B) ((A) < (B) ? (A) : (B))
#define abs(A)   ((A) >= 0  ? (A) : (-A))

class FormeScene;

enum TypeCellulePourPlanHexagonal { PAROI_CLASSIQUE, PAROI_GENERATRICE, HORS_SCENE, PHASE } ;


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class InfoCellule {

private:

  TypeCellulePourPlanHexagonal _type ;
  Cellule * _cellule ;

public:

  InfoCellule(TypeCellulePourPlanHexagonal type, Cellule * ceil) : _type(type), _cellule(ceil) {}

  TypeCellulePourPlanHexagonal getType() { return _type ; }

  Cellule * getCellule() { return _cellule ; }
  
  ~InfoCellule() { delete _cellule ; }

} ;
  


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class PourRemplirCellule {

private:

  TypeCellulePourPlanHexagonal _typeParoi ;

public:

  PourRemplirCellule(TypeCellulePourPlanHexagonal typeParoi) : _typeParoi(typeParoi) {}

  virtual Cellule * getCellule() = 0 ;
  
  TypeCellulePourPlanHexagonal getType() { return _typeParoi ; }

  virtual ~PourRemplirCellule() {}

} ;


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class PourRemplirCelluleParoiGeneratrice : public PourRemplirCellule {

private :

  Phase *_phase ;
  int   _couleur ;

public :

  PourRemplirCelluleParoiGeneratrice(Phase *p, int col) : PourRemplirCellule(PAROI_GENERATRICE), _phase(p), _couleur(col) {}

  Cellule * getCellule() ;

};


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class PourRemplirCelluleParoiClassique : public PourRemplirCellule {


public :

  PourRemplirCelluleParoiClassique() : PourRemplirCellule(PAROI_CLASSIQUE) {}

  Cellule * getCellule() ;

};


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class PourRemplirCelluleHorsScene : public PourRemplirCellule {


public :

  PourRemplirCelluleHorsScene() : PourRemplirCellule(HORS_SCENE) {}

  Cellule * getCellule() ;

};



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class PlanHexagonal {
public:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception levée lorsque l'on essaie de rotate de plus de 6 (ou moins de 0)
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception(string message);
  };


  PlanHexagonal(int dim, const Scene&);
  PlanHexagonal(const PlanHexagonal&) ;
  PlanHexagonal& operator = (const PlanHexagonal&) ;
  ~PlanHexagonal()
  {
    for(int i = 0; i < _dimension; i++)
      for(int j = 0; j < _dimension; j++)
	delete _ecran(i,j) ;
  }

  void numeroteCellule() ;

  friend ostream& operator << (ostream& os, const PlanHexagonal& p) ;


  void dessineLigne(const Ligne& ligne, PourRemplirCellule * ceil) ;
  void dessineLigne(const Ligne& ligne, int col) ;
  void dessineLigne(const Ligne& ligne, const vector<PhasePourcent>& tab_phase_pourcent) ;  
  void dessineArcEllipse(const ArcEllipse& arc_ellipse, PourRemplirCellule * ceil) ;
  void dessineEllipse(const Ellipse& ellipse, PourRemplirCellule * ceil) ;
  void dessineRectangle(const Rectangle& rectangle, PourRemplirCellule * ceil) ;
  void dessinePolygone(const Polygone& poly, PourRemplirCellule * ceil) ;

  void rempliEllipse(const Ellipse& ellipse, PourRemplirCellule * ceil) ;
  void rempliEllipse(const Ellipse& ellipse, int col) ;
  void rempliEllipse(const Ellipse& ellipse, const vector<PhasePourcent>& tab_phase_pourcent) ;
  void rempliRectangle(const Rectangle& rectangle, PourRemplirCellule * ceil) ;
  void rempliRectangle(const Rectangle& rectangle, int col) ;
  void rempliRectangle(const Rectangle& rectangle, const vector<PhasePourcent>& tab_phase_pourcent) ;
  void rempliPolygone(const Polygone& poly, PourRemplirCellule * ceil) ;
  void rempliPolygone(const Polygone& poly, int col) ;
  void rempliPolygone(const Polygone& poly, const vector<PhasePourcent>& tab_phase_pourcent) ;
  

  static void calculMinEtMax(const list<Frontiere *>& , int& minX, int& minY, int& maxX, int& maxY) ;

  Ligne* proportionneLigne(const Ligne*) ;
  ArcEllipse proportionneArcEllipse(const ArcEllipse&) ;
  Ellipse proportionneEllipse(const Ellipse&) ;
  Rectangle proportionneRectangle(const Rectangle&) ;
  Polygone proportionnePolygone(const Polygone&) ;


 Polygone mettreAJourPolygone(vector<Ligne> ancienPolygone, vector<Ligne> nouveauPolygone,
 						   const vector<Ligne>& ancienHorizontale, const vector<Ligne>& nouveauHorizontale);
 Polygone assembleHorizontaleEtVerticale(const Polygone& polygone);


  // tres mauvaise gestion de la memoire
  // cet automate est lie avec les elements de la scene -> si on
  // detruit la scene passe en parametre du constructeur
  // on detruit les elements pointes par l'automate (comme les phase, regle,etc...
  // mais bon c'est pas mon job de bien faire ca (moi je fais ce que
  // je peux)

  Automate* getAutomate() {return _automate;}
private:

  void dessineLigne(int x1, int y1, int x2, int y2, PourRemplirCellule * ceil) ;
  void dessineLigne(int x1, int y1, int x2, int y2, int col) ;
  void dessineLigne(int x1, int y1, int x2, int y2, const vector<PhasePourcent>& tab_phase_pourcent,
		    vector<float>& tab) ;
  void dessineEllipse(int x1, int y1, int r1, int r2, PourRemplirCellule * ceil) ;
  void dessineArcEllipse(int x, int y, int r1, int r2,
			 int x1, int y1, int x2, int y2, PourRemplirCellule * ceil) ;
  void rempliPolygone(const vector<Arete>&, PourRemplirCellule * ceil) ;
  void rempliPolygone(const vector<Arete>&, int col) ;
  void rempliPolygone(const vector<Arete>&, const vector<PhasePourcent>& tab_phase_pourcent,
		      vector<float>& tab) ;
  void rempliEllipse(int x1, int y1, int r1, int r2, PourRemplirCellule * ceil) ;
  void rempliEllipse(int x1, int y1, int r1, int r2, int col) ;
  void rempliEllipse(int x1, int y1, int r1, int r2, const vector<PhasePourcent>& tab_phase_pourcent,
		     vector<float>& tab) ;

 
  void translatePoint(int x, int y, double& x_res, double& y_res)
  {
    x_res = x ; y_res = (y + (x * _tangente30 * _normalisation)) ;
  }


  void coordonneeVectorielVersBitmap(int,int,double&,double&);

  vector<int> rechercheArreteSecante(int, const vector<Arete>&) ;
  void rechercheMinEtMax(const vector<Arete>& t, int& min_x, int& max_x, int& min_y, int& max_y) ;

  static int plusProcheEntier(double x) ;
  double calculEcart(double x, double y, double r1, double r2) ;
  int appartient(double,double,double,double,double,double) ;


  vector<float> enleve(vector<float>& tab) ;
  int reinitialise(const vector<float>& tab) ;
  float minimum(const vector<PhasePourcent>& tab_phase_pourcent) ;
  vector<float> additionne(const vector<float>& tab1, const vector<float>& tab2) ;
  vector<float> initTabPoids(const vector<PhasePourcent>& tab_phase_pourcent) ;
  float poids(const vector<float>& tab) ;
  vector<float> cumule(const vector<float>& tab) ;
  int indice(vector<float>& tab) ;

  vector<int> analyse(const vector<int>& tab) ;
  vector<int> tri(const vector<int>& tab) ;

  static FormeScene* transformeForme(Forme* f);
  
  void mettreHSExterieurFrontiere() ;
  void changeNULLEnHorsScene() ;
  void repandre(int x, int y) ;
  
protected:
  
  Matrice<InfoCellule *> _ecran ;
  int _minX, _minY, _maxX, _maxY ;
  int _dimension ;

  Automate* _automate;

  static double _pi ;
  static double _tangente30 ;
  static double _normalisation ;




} ;

//##############################################################################
//##############################################################################
//##############################################################################
// METHODES INLINES
//##############################################################################
//##############################################################################
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exceptions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  Il affiche sur la canal d'erreur la chaine [EXCEPTION] puis
 *  la chaine contenue dans la variable message.
 *
 ******************************************************************************/
inline PlanHexagonal::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}


#endif
  
