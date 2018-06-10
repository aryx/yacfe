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

#ifndef _POLYGONE_H_
#define _POLYGONE_H_


#include "CommunFigures.h"

#include "FormeFermee.h"

#include "Ligne.h"


//*******************************************************************************
/** Représente une FormeFermee de type polygone.
 *  Il est compose d'une liste de lignes.
 *******************************************************************************/

class Polygone : public FormeFermee {

public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur.
  Polygone() {}
    //_elemPolygone = new list<Ligne*>; };

  /// Constructeur.
  Polygone(const list<Ligne*> &liste) {_elemPolygone = liste; };

  /// Destructeur.
  virtual ~Polygone() 
    { 
      free();
    };

    /// Le constructeur par recopie.
  Polygone(const Polygone& arg)
    {
      copy(arg);
    }

  /// L'opérateur =.
  Polygone& operator=(const Polygone& arg)
    {
      if (this != &arg)
      {
	free();
	copy(arg);
      }
      return *this;
    }

  virtual Polygone* clone() const 
    {
      return new Polygone(*this);
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
  static ioManager<Polygone> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes : Fonctions d'acces aux membres 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
  /// Retourne la liste de lignes associée au polygone.
  list<Ligne*> getLignes() const {return _elemPolygone;}

  /// Ajoute une ligne au polygone.
  void ajoutLigne(Ligne *ligne) { _elemPolygone.push_back(ligne); }

  
  Rectangle rectangleEnglobant()
  {
    int minX, minY, maxX, maxY ;

    list<Ligne*>::iterator it_lignes ;

    
    minX = (*(_elemPolygone.begin()))->getX1();
    maxX = (*(_elemPolygone.begin()))->getX1();
    minY = (*(_elemPolygone.begin()))->getY1();
    maxY = (*(_elemPolygone.begin()))->getY1();

    for (it_lignes = _elemPolygone.begin() ; it_lignes != _elemPolygone.end(); it_lignes++)
      {
	if ((*it_lignes)->getX1() < minX) minX = (*it_lignes)->getX1() ;
	if ((*it_lignes)->getX2() < minX) minX = (*it_lignes)->getX2() ;
	if ((*it_lignes)->getX1() > maxX) maxX = (*it_lignes)->getX1() ;
	if ((*it_lignes)->getX1() > maxX) maxX = (*it_lignes)->getX2() ;	

	if ((*it_lignes)->getY1() < minY) minY = (*it_lignes)->getY1() ;
	if ((*it_lignes)->getY2() < minY) minY = (*it_lignes)->getY2() ;
	if ((*it_lignes)->getY1() > maxY) maxY = (*it_lignes)->getY1() ;
	if ((*it_lignes)->getY1() > maxY) maxY = (*it_lignes)->getY2() ;	

      }
    
    return Rectangle(minX,minY,maxX,maxY) ;

  }


  void afficheur()
  {
    cerr << "Polygone(" << endl ;

    list<Ligne*>::iterator it_lignes ;


    for (it_lignes = _elemPolygone.begin(); it_lignes != _elemPolygone.end(); it_lignes++)
      {
	(*it_lignes)->afficheur();
      }

    cerr << ")\n" ;
    
  }




private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  void copy(const Polygone& polyg)
    {
      list<Ligne*>::const_iterator it;
      for (it = polyg._elemPolygone.begin(); it != polyg._elemPolygone.end(); it++)
	{
	  ajoutLigne((*it)->clone());
	}
      
    }


  void free()
    {
      list<Ligne*>::iterator it_lignes ;
      for (it_lignes = _elemPolygone.begin(); it_lignes != _elemPolygone.end(); it_lignes++)
	{
	  delete (*it_lignes);
	}
    }


protected:
  /// Liste de toutes les lignes composant le polygone.
  list<Ligne*> _elemPolygone;

};

#endif
