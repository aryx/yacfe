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

#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_


#include "CommunFigures.h"

#include "FormeFermee.h"
#include "Rectangle.h"


//*******************************************************************************
/** Représente une FormeFermee de type ellipse.
 *  Une ellipse est caractérisée par son centre et ses deux rayons.
 *******************************************************************************/
 

class Ellipse : public FormeFermee{

public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  //*******************************************************************************
  /** Constructeur à partir des coordonnées de l'ellipse.
   *  Les coordonnées sont x,y pour le centre, r1 et r2 pour les rayons de l'ellipse.
   *******************************************************************************/
  Ellipse(int x=0, int y=0, int r1=0, int r2=0) : _x(x), _y(y), _r1(r1), _r2(r2) {}

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

  Rectangle rectangleEnglobant()
  {
    return Rectangle(_x - _r1, _y - _r2, _x + _r1, _y + _r2) ;
  } 

  virtual Ellipse* clone() const 
    {
      return new Ellipse(*this);
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
  static ioManager<Ellipse> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut



  /// Affiche les attributs privés de l'objet.
  void afficheur()
  {
    cerr << "Ellipse(" << _x << ","  << _y << ",";
    cerr << _r1 << "," << _r2 << ")\n" ;
  }
  

  
protected:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Abscisse du centre.
  int _x;

  /// Ordonnée du centre.
  int _y;

  /// Premier rayon.
  int _r1;

  /// Deuxième rayon.
  int _r2;

};

#endif
