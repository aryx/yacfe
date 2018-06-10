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

#ifndef _PONDERATION_H_
#define _PONDERATION_H_



#include "CommunMoteur.h"
#include "Direction.h"

//*******************************************************************************
/** Stocke des probabilités de déplacement pour chacune des six directions.
 *  Par exemple si on a un objet Ponderation ayant pour valeur
 *  NORD = 0, NE = 0, NW = 0, SUD = 2, SE = 1, SW = 1 alors 
 *  cette objet favorise le déplacement vers le sud
 *  (1 chance sur deux d'aller vers le sud, 1 chance sur 4 d'aller au sud-est,
 *  1 chance sur 4 d'aller au sud-ouest et aucune chance d'aller vers le nord).
 *******************************************************************************/

class Ponderation
{
public:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur par défaut.
  Ponderation();
  /// Constructeur à partir d'un tableau de probabilités.
  Ponderation(int tab_val[VALENCE]);

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception levée.
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception(string message);
  };


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Opérateurs
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Opérateur d'addition et d'affectation.
  Ponderation & operator+=(const Ponderation &po);
  /// Opérateur d'addition.
  friend Ponderation operator+(const Ponderation &po1,const Ponderation &po2);


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Mise à jour d'une probabilité.
  void setPonderation(Direction dir, int valeur);
  /// Obtention d'une probabilité.
  int getPonderation(Direction dir) const;

  /// Obtention du module de l'objet.
  int getModule() const;


  /// Affiche les attributs privés de l'objet.
  void afficheur() const;


  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<Ponderation>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Ponderation> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const Ponderation &arg)
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


  /** 
   * Tableau des probabilités.
   * L'ordre est celui définit par l'enum ::EnumDirectionRequete.
   * Ainsi par exemple, si on veut avoir 
   * NORD = 0, NE = 0, NW = 0, SUD = 2, SE = 1, SW = 1 alors _tabValeur contiendra
   * {0,0,1,2,1,0}
  */
  int _tabValeur[VALENCE];

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
inline Ponderation::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  \param valeur la nouvelle valeur de la probabilité pour la direction dir.
 ******************************************************************************/
inline void Ponderation::setPonderation(Direction dir, int valeur)
{
  _tabValeur[dir] = valeur;
}
      
//******************************************************************************
/** Description.
 *  \return la probabilité pour la direction dir.
 ******************************************************************************/

inline int Ponderation::getPonderation(Direction dir) const
{
  return _tabValeur[dir];
}

#endif
