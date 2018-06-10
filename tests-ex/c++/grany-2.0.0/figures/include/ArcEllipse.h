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

#ifndef _ARCELIPSE_H_
#define _ARCELIPSE_H_

#include "CommunFigures.h"

#include "FormeOuverte.h"
#include "Rectangle.h"


//*******************************************************************************
/** Représente une partie d'une ellipse.
 *  Caractérisé par un centre, deux rayons, et deux points appartenant 
 *  à l'arc elliptique qui délimitent l'arc. 
 *******************************************************************************/
 

class ArcEllipse : public FormeOuverte{
  
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur.
  ArcEllipse(int x=0, int y=0, int r1=0, int r2=0,int x1=0,int y1=0, int x2=0, int y2=0) : _x(x), _y(y), _r1(r1), _r2(r2), _x1(x1), _y1(y1), _x2(x2), _y2(y2) {}

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes : Fonctions d'acces aux membres 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  /// Retourne l'abscisse du centre.
  int getX() const {return _x;}

  /// Retourne l'ordonnée du centre.
  int getY() const {return _y;}

  /// Retourne le premier rayon.
  int getR1() const {return _r1;}

  /// Retourne le deuxième rayon.
  int getR2() const {return _r2;}

  /// Retourne l'abscisse du premier point.
  int getX1() const {return _x1;}
  /// Retourne l'ordonnée du premier point.
  int getY1() const {return _y1;}
  /// Retourne l'abscisse du second point.
  int getX2() const {return _x2;}
  /// Retourne l'ordonnée du second point.
  int getY2() const {return _y2;}

  
  Rectangle rectangleEnglobant()
  {
    return Rectangle(min(_x - _r1,min(_x2,_x1)),min(_y - _r2,min(_y1,_y2)),
		     max(_x + _r1,max(_x2,_x1)),max(_y + _r2,max(_y1,_y2))) ;
  }

  virtual ArcEllipse* clone() const 
    {
      return new ArcEllipse(*this);
    }


  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  // UGLY je sais pas si ca marche ca
  // ca doit pas je pense
  // faut que l'adresse des fonctions virtuelles 
  // soit les memes !!!!!!!!!!!!!
  virtual ioManager<Forme>* getIoManager() const
    {
      return (ioManager<Forme>*) _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<ArcEllipse> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut



  /// Affiche les attributs privés de l'objet.
  void afficheur()
  {
    cerr << "ArcEllipse(" << _x << ","  << _y << ",";
    cerr << _r1 << "," << _r2 << "," << _x1 << "," << _y1 << "," << _x2 << "," << _y2 << ")\n" ;
  }


protected:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Abscisse du centre de l'arc elliptique.
  int _x;

  /// Ordonnée du centre de l'arc elliptique.
  int _y;

  /// Premier rayon de l'arc elliptique.
  int _r1;

  /// Premier rayon de l'arc elliptique.
  int _r2;

  /// Abscisse du premier point de l'arc elliptique.
  int _x1;

  /// Ordonnée du premier point de l'arc elliptique.
  int _y1;

  /// Abscisse du deuxième point de l'arc elliptique.
  int _x2;

  /// Ordonnée du deuxième point de l'arc elliptique.
  int _y2;

};

#endif
