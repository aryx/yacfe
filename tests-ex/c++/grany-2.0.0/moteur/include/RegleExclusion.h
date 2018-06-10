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

#ifndef _REGLEEXCLUSION_H_
#define _REGLEEXCLUSION_H_


#include "CommunMoteur.h"
#include <string>

#include "Direction.h"

//*******************************************************************************
/** Structure de données représentant les règles d'exclusion.
 *  On peut assimiler cet objet à un motif qui sera superposé sur une situation
 *  du réseau. Ce motif est composé :
 *  <UL>
 *     <LI> d'un ensemble de six contraintes de déplacement
 *          (l'enum Deplacement), représentant le droit ou non de se déplacer dans une
 *          des six directions, 
 *     <LI> de six contraintes sur le type de la particule pour chacune des six 
 *          directions. Le type de la particule est représenté par l'indice phi
 *          de sa phase, et on peut le contraindre de 4 manières différentes
 *          (l'enum Contrainte).
 *  </UL>
 *  Lorsque une particule effectue son calcul de requête (voir Particule::calculeRequete())
 *  elle applique à sa situation (qui est caractérisé par le contenu des cellules voisines)
 *  des règles d'exclusion (qui sont définies dans sa phase) 
 *  afin d'interdire certain déplacement. Par exemple comment modélisé la règle iso-phase
 *  qui dit que une particule ne peut s'échanger avec une autre particule de même
 *  phase. Il suffit de mettre une contrainte de déplacement impossible 
 *  (avec la contrainte DEPLIMPOSSIBLE) dans la direction où il y a une particule 
 *  de même phase (avec la contrainte CONTRAINTE_MEMEPHI).
 *  Soit sur un schéma :
 *  \code
 *
 *    CN  CN   CN
 *     \   |   /
 *      \  |  /
 *       \ | /
 *         o
 *        /|\
 *       / * \
 *      /  |  \
 *     CN CMP  CN
 *  \endcode
 *  
 *  ou CN veut dire CONTRAINTE_NULLE, CMP = CONTRAINTE_MEMEPHI, l'étoile représente
 *  DEPLIMPOSSIBLE et l'absence d'étoile DEPLPOSSIBLE.
 *  On peut penser que ca ne suffit pas à modéliser toutes les situations. En effet
 *  que se passe t-il si la particule de même phase est au nord ? Faut il définir
 *  une autre règle ou la contrainte CMP et DEPLIMPOSSIBLE sont au nord ?
 *  En fait la classe possède aussi une méthode rotation(int i) qui retourne
 *  une règle que l'on a fait tourner de i pas. Ainsi la méthode 
 *  Particule::calculerRequete() effectue six rotations pour chaque règle d'exclusion.
 *  
 *  De plus on peut appliquer une règle en post-exclusion ou en pré-exclusion,
 *  d'où la création de l'enum ModeExclusion.
 *
 *  \sa Particule::calculerRequete()
 *******************************************************************************/

class RegleExclusion
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Symboles/Enum
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /// Contrainte sur la possiblité de déplacement pour une direction.
  enum Deplacement {
    DEPLPOSSIBLE,   /**< Déplacement possible.   */
    DEPLIMPOSSIBLE  /**< Déplacement impossible. */
  };
  /** Contrainte sur le type de la particule contenue dans une cellule voisine.
   *  On peut modéliser 4 types de contrainte sur le phi des particules voisines.
   */
  enum  Contrainte {
    CONTRAINTE_NULLE,        /**< Pas de contrainte. */
    CONTRAINTE_MEMEPHI,      /**< On contraint les phis à être identiques. */ 
    CONTRAINTE_PHIINFERIEUR, /**< On contraint le phi de la particule voisine 
			          à être inférieur au phi de la particule du centre. */
    CONTRAINTE_PHIINFSOLIDE  /**< On contraint le phi de la particule voisine à être de type solide.   */
  };

  /// Couple contrainte, deplacement.
  struct Paire{
    Deplacement deplacement;
    Contrainte  contrainte;
  };

  /** A quel moment applique t-on la règle d'exclusion ?.
   *  Lors du calcul de sa requête, la particule peut décider
   *  d'appliquer des règle d'exclusion avant (pré-exclusion ou exclusion en mode requête)
   *  ou après (post-exclusion ou exclusion en mode déplacement) le tirage
   *  au sort.
   * \sa Phase, Particule::calculerRequete()
   */
  //TODO sur le commentaire peut etre
 enum ModeExclusion {
   POST, /**< Post-exclusion */
   PRE   /**< Pré-exclusion  */
 };





  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Valeur par defaut du constructeur.
  static Paire _paireDefaut[6];

  /// Constructeur.
  RegleExclusion(string nom = "NONE", Paire elements[6] = _paireDefaut);

  virtual RegleExclusion* clone() const; 
  virtual ~RegleExclusion(){};

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

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Mise à jour du nom de la règle.
  void setNom(string nom);
  /// Obtention du nom de la règle.
  string getNom() const;

  /// Mise à jour d'un déplacement.
  void setDeplacement(Direction dir, Deplacement depl);
  /// Obtention d'un déplacement.
  Deplacement getDeplacement(Direction dir) const;

  /// Mise à jour d'une contrainte.
  void setContrainte(Direction dir, Contrainte contr);
  /// Obtention d'une contrainte.
  Contrainte getContrainte(Direction dir) const;

  /// Ajoute une paire (contrainte deplacement).
  void ajoutPaire(Deplacement depl, Contrainte contr);

  /// Ajoute une paire (contrainte deplacement).
  void ajoutPaire(Paire paire);

  /// Rotation de i pas.
  void rotation(int i);

  /// Affichage d'un déplacement.
  friend ostream& operator<<(ostream& os,RegleExclusion::Deplacement dep);
  /// Affichage d'une contrainte.
  friend ostream& operator<<(ostream& os,RegleExclusion::Contrainte con);
  /// Affichage d'un mode d'exclusion.
  friend ostream& operator<<(ostream& os,RegleExclusion::ModeExclusion mode);

  /// Affiche les attributs privés de l'objet.
  void afficheur() const;


  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<RegleExclusion>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<RegleExclusion> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const RegleExclusion &arg)
    {
      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");
      arg.getIoManager()->ecrire(arg,os);

      return os;
    }

  // marche celui la pour l'heritage ?? de tout facon on s'en fout
  // car TOEXPLAIN on la lecture y 'a que un module qui s'en occupe
  friend istream& operator>>(istream& is, RegleExclusion &arg)
    {

      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");

      RegleExclusion* arg2 = arg.getIoManager()->lire(is);
      
      arg = *arg2;

      delete arg2;

      return is;
    }

  
private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Nom de la règle.
  string _nom;
  
  int _decalageRotation;

  /// Pour compter le nombre d'appels à la méthode ajoute
  int _compteur;

  /// Tableau des déplacements.
  Deplacement _tabDepl[VALENCE+VALENCE-1];
  /// Tableau des contraintes.
  Contrainte  _tabContr[VALENCE+VALENCE-1];



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
inline RegleExclusion::Exception::Exception(string message)
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

inline RegleExclusion* RegleExclusion::clone() const
{
  return new RegleExclusion(*this);
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void RegleExclusion::setNom(string nom)
{
  _nom=nom;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline string RegleExclusion::getNom() const
{
  return _nom;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void RegleExclusion::setDeplacement(Direction dir, Deplacement depl)
{
      _tabDepl[dir+_decalageRotation] = depl;

      //  0 1 2 3 4  5  6 7 8 9 10
      // [ , , , , ,[ ], , , , ,  ]

      // je suis entre 6 et 10
      if ((_decalageRotation+dir) > (VALENCE-1))
	_tabDepl[dir+_decalageRotation-VALENCE] = depl;
      else { 
	// je suis sur 5
	if ((_decalageRotation+dir) == (VALENCE-1))
	  _tabDepl[dir+_decalageRotation] = depl;
	else
	// je suis au dessous de 5
	  _tabDepl[dir+_decalageRotation+VALENCE] = depl;
      }
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline RegleExclusion::Deplacement RegleExclusion::getDeplacement(Direction dir) const
{
      return _tabDepl[dir+_decalageRotation];
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void RegleExclusion::setContrainte(Direction dir, Contrainte contr)
{
      _tabContr[dir+_decalageRotation] = contr;
      if ((_decalageRotation+dir) > (VALENCE-1))
	_tabContr[dir+_decalageRotation-VALENCE] = contr;
      else { 
	if ((_decalageRotation+dir) == (VALENCE-1))
	  _tabContr[dir+_decalageRotation] = contr;
	else
	  _tabContr[dir+_decalageRotation+VALENCE] = contr;
      }
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline RegleExclusion::Contrainte RegleExclusion::getContrainte(Direction dir) const
{
      return _tabContr[dir+_decalageRotation];

}

//******************************************************************************
/** Description.
 * Cette méthode est appelée par l'objet Particule afin d'appliquer les règles
 * d'exclusion.
 ******************************************************************************/
inline void RegleExclusion::rotation(int i)
{
#ifdef DEBUG_EXCEPTION
  if ((i < 0) || (i >= VALENCE)) throw Exception("mauvaise utilisation de rotation");
#endif
  _decalageRotation = i;
}

#endif
