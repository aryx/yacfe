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

#ifndef _LIGNE_H_
#define _LIGNE_H_


#include "CommunFigures.h"

#include "Rectangle.h"
#include "FormeOuverte.h"


//*******************************************************************************
/** Repr�sente une FormesOuverte de type ligne.
 *  Il est compos� de deux points. Cet objet est aussi utilis� pour la d�finition
 *  d'un objet Polygone.
 *******************************************************************************/

class Ligne : public FormeOuverte 
{
  
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur � partir des coordonn�es de la ligne.
  Ligne(int x1=0, int y1=0, int x2=0, int y2=0) : _x1(x1), _y1(y1), _x2(x2), _y2(y2) {}
  

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes : Fonctions d'acces aux membres 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Retourne l'abscisse du premier point.
  int getX1() const {return _x1;}

  /// Retourne l'ordonn�e du premier point.
  int getY1() const {return _y1;}

  /// Retourne l'abscisse du second point.
  int getX2() const {return _x2;}

  /// Retourne l'ordonn�e du second point.
  int getY2() const {return _y2;}

  Rectangle rectangleEnglobant()
  {
    return Rectangle(min(_x1,_x2),min(_y1,_y2),max(_x1,_x2),max(_y1,_y2)) ;
  }

  virtual Ligne* clone() const 
    {
      return new Ligne(*this);
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
      DEBUG_FIGURES(cerr << "ioManager de Ligne\n");
      return (ioManager<Forme>*) _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Ligne> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut



  /// Affiche les attributs priv�s de l'objet.
  void afficheur()
    {
      cerr << "Ligne(" << _x1 << "," << _y1 << "," ;
      cerr << _x2 << "," << _y2 << ")" << "\n"; 
    }

protected:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Abscisse du premier point.
  int _x1;

  /// Ordonn�e du premier point.
  int _y1;

  /// Abscisse du deuxi�me point.
  int _x2;

  /// Ordonn�e du deuxi�me point.
  int _y2;

};


#endif
