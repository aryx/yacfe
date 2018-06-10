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

#ifndef _CELLULE_H_
#define _CELLULE_H_


#include "CommunMoteur.h"

// pour notre topologie
#include "Automate.h"
#include "Requete.h"

//*******************************************************************************
/** Mod�lisation d'une cellule.
 * Notons qu'on ne peut directement instancier un �l�ment de la classe
 * Cellule puisque certaines m�thodes sont virtuelles pures. Elle permet ainsi
 * de d�finir le comportement commun de toutes les cellules, l'h�ritage
 * permettant ensuite de sp�cialiser les CelluleAvecParticule et les
 * CelluleSansParticule.
 *******************************************************************************/

class Cellule
{
public:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /** Exception lev�e lorsque l'on essaie de r�cuperer un pointeur
   *  qui a la valeur NULL. Par exemple dans la m�thode getCellule()
   *  si le pointeur vers la cellule est NULL (ce qui veut dire
   *  que la particule n'est li�e � aucune cellule) alors on l�ve
   *  une exception.
   */
  class Exception{
  public:
    /// Constructeur.
    Exception(string message);
  };


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Constructeur.
  // En fait il est la car sinon le programme ne veut pas compiler
  // car il n'y a pas de constructeur public (car le constructeur par recopie est priv�)
  Cellule(){};

  virtual Cellule* clone() const = 0;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Obtention du voisin de la cellule dans une direction donn�e.
  Cellule* getVoisin(Direction dir) const;

  /// Mise � jour du voisin de la cellule dans une direction donn�e.
  void setVoisin(Direction dir,Cellule* cell);

  /* sert plus TOENLEVE */
  /// Mise � jour des coordonn�es.
  void setXY(int x, int y);
  /// Obtention de l'abscisse.
  int getX() const;
  /// Obtention de l'ordonn�e.
  int getY() const;

  /// Mise � jour du num�ro de la cellule.
  void setNumero(int num);

  /// Obtention du num�ro de la cellule.
  int getNumero() const;

  /// M�thode utilis�e pour pouvoir debugger le code.
  virtual void afficheur() const;

  /// M�thode de d�buggage r�duite � un identifiant
  virtual void afficheurReduit() const;


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // M�thodes virtuelles pures
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Calcul de la requ�te associ�e.
  virtual void calculerRequete() = 0;

  /// Activation de l'�change de particules.
  virtual void activerEchange() = 0;

  /// Obtention de la requ�te pr�c�demment calcul�e.
  virtual Requete getRequete() const = 0 ;

  /// Activation de ce que contient �ventuellement la cellule.
  virtual void activer() = 0;

  /// Rend vrai si ce que contient la cellule est actif.
  virtual bool getActivite() const = 0 ;

  // utilise pas pascal
  virtual Particule * getParticule() const = 0;


  /** Echange effectif de particules.
   * Ici on inclue cette m�thode sur particule qu'on aurait pu
   * ne mettre que dans CelluleAvecParticule.
   * On impl�mentera ces m�thodes dans CelluleSansParticule en d�clenchant
   * une exception, cela permettra de ne pas ``caster'' la Cellule dans les
   * appels aux voisins.
   */
  virtual Particule* echangeParticule(Particule* part) = 0;

  /** Obtention du phi de la particule pr�sente �ventuellement dans la cellule.
   *  Dans le cas contraire, on rend une constante repr�sentant l'absence
   *  totale de possibilit� de mouvement.
   */
  virtual float getPhiParticule() const = 0;

  /** M�thode de d�buggage qui demande � la cellule d'afficher son contenant
   *  sur un caract�re, sur la sortie standard.
   */
  virtual void afficheToi() const = 0;


  virtual int donneTaCouleur() const = 0;

  virtual ioManager<Cellule>* getIoManager() const = 0;


  friend ostream& operator<<(ostream& os,const Cellule &arg)
    {
      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");
      arg.getIoManager()->ecrire(arg,os);

      return os;
    }



private:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /* sert plus TOENLEVE */
  /// Num�ro r�f�ren�ant la position de la cellule dans le tableau contenant le r�seau.
  int _numero;

  /* sert plus TOENLEVE */
  /// Abscisse.
  int _x;
  /// Ordonn�e.
  int _y;

  /// Contient les voisines.
  Cellule* _tabCellule[VALENCE];

    
};
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
inline Cellule::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres m�thodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Cellule::setNumero(int num)
{
  _numero=num;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Cellule::getNumero() const
{
  return _numero;
}


/*
  Voici le getVoisin super dependant de la topologie choisie
  Ex. avec dim_reseau == 4 :
  
            3
         2  
      1     7
   0     6
      5     B
   4     A
      9     F
   8     E
      D
   C

 */

//******************************************************************************
/** Description.
 *  \warning
 *    Cette m�thode est compl�tement d�pendante du choix de num�rotation des
 *    cellules. Elle r�cup�re le tableau de cellules de l'automate et l'utilise
 *    directement pour d�terminer le voisin voulu.
 ******************************************************************************/
inline Cellule * Cellule::getVoisin(Direction dir) const
{
  return _tabCellule[dir];
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Cellule::setVoisin(Direction dir,Cellule* cell)
{
  _tabCellule[dir]=cell;
}

//******************************************************************************
/** Description.
 *  Notons que ces coordonn�es ne sont pas
 *  utilis�es dans le moteur et sont donc pr�vues pour faciliter le travail
 *  de l'interface graphique.
 ******************************************************************************/
inline void Cellule::setXY(int x, int y)
{
  _x = x;
  _y = y;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Cellule::getX() const
{
  return _x;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Cellule::getY() const
{
  return _y;
}



#endif
