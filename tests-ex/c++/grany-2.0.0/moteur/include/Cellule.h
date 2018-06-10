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
/** Modélisation d'une cellule.
 * Notons qu'on ne peut directement instancier un élément de la classe
 * Cellule puisque certaines méthodes sont virtuelles pures. Elle permet ainsi
 * de définir le comportement commun de toutes les cellules, l'héritage
 * permettant ensuite de spécialiser les CelluleAvecParticule et les
 * CelluleSansParticule.
 *******************************************************************************/

class Cellule
{
public:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /** Exception levée lorsque l'on essaie de récuperer un pointeur
   *  qui a la valeur NULL. Par exemple dans la méthode getCellule()
   *  si le pointeur vers la cellule est NULL (ce qui veut dire
   *  que la particule n'est liée à aucune cellule) alors on lève
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
  // car il n'y a pas de constructeur public (car le constructeur par recopie est privé)
  Cellule(){};

  virtual Cellule* clone() const = 0;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Obtention du voisin de la cellule dans une direction donnée.
  Cellule* getVoisin(Direction dir) const;

  /// Mise à jour du voisin de la cellule dans une direction donnée.
  void setVoisin(Direction dir,Cellule* cell);

  /* sert plus TOENLEVE */
  /// Mise à jour des coordonnées.
  void setXY(int x, int y);
  /// Obtention de l'abscisse.
  int getX() const;
  /// Obtention de l'ordonnée.
  int getY() const;

  /// Mise à jour du numéro de la cellule.
  void setNumero(int num);

  /// Obtention du numéro de la cellule.
  int getNumero() const;

  /// Méthode utilisée pour pouvoir debugger le code.
  virtual void afficheur() const;

  /// Méthode de débuggage réduite à un identifiant
  virtual void afficheurReduit() const;


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Méthodes virtuelles pures
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Calcul de la requête associée.
  virtual void calculerRequete() = 0;

  /// Activation de l'échange de particules.
  virtual void activerEchange() = 0;

  /// Obtention de la requête précédemment calculée.
  virtual Requete getRequete() const = 0 ;

  /// Activation de ce que contient éventuellement la cellule.
  virtual void activer() = 0;

  /// Rend vrai si ce que contient la cellule est actif.
  virtual bool getActivite() const = 0 ;

  // utilise pas pascal
  virtual Particule * getParticule() const = 0;


  /** Echange effectif de particules.
   * Ici on inclue cette méthode sur particule qu'on aurait pu
   * ne mettre que dans CelluleAvecParticule.
   * On implémentera ces méthodes dans CelluleSansParticule en déclenchant
   * une exception, cela permettra de ne pas ``caster'' la Cellule dans les
   * appels aux voisins.
   */
  virtual Particule* echangeParticule(Particule* part) = 0;

  /** Obtention du phi de la particule présente éventuellement dans la cellule.
   *  Dans le cas contraire, on rend une constante représentant l'absence
   *  totale de possibilité de mouvement.
   */
  virtual float getPhiParticule() const = 0;

  /** Méthode de débuggage qui demande à la cellule d'afficher son contenant
   *  sur un caractère, sur la sortie standard.
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
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /* sert plus TOENLEVE */
  /// Numéro référençant la position de la cellule dans le tableau contenant le réseau.
  int _numero;

  /* sert plus TOENLEVE */
  /// Abscisse.
  int _x;
  /// Ordonnée.
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
// Autres méthodes
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
 *    Cette méthode est complètement dépendante du choix de numérotation des
 *    cellules. Elle récupère le tableau de cellules de l'automate et l'utilise
 *    directement pour déterminer le voisin voulu.
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
 *  Notons que ces coordonnées ne sont pas
 *  utilisées dans le moteur et sont donc prévues pour faciliter le travail
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
