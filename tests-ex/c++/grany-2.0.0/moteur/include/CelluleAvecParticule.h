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
#ifndef _CELLULEAVECPARTICULE_H_
#define _CELLULEAVECPARTICULE_H_


#include "CommunMoteur.h"

#include "Cellule.h"
#include "Particule.h"
#include "Requete.h"


//*******************************************************************************
/** Modélisation d'une cellule avec particule.
 *  Cette classe hérite de la classe Cellule. Elle permet de préciser le
 *  comportement des cellules contenant réellement une particule, c'est-à-dire
 *  les cellules ``classiques'' (on instanciera alors un objet CelluleAvecParticule)
 *  et les cellules "génératrices" (on utilisera la classe CelluleGeneratrice
 *  héritée de CelluleAvecParticule).
 *******************************************************************************/

class CelluleAvecParticule : public Cellule
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir de la particule que contiendra la cellule.
  CelluleAvecParticule(Particule* part);

  /// Destructeur virtuel.
  virtual ~CelluleAvecParticule();

  virtual CelluleAvecParticule* clone() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Mise à jour de la particule que contient la cellule.
  void setParticule(Particule* part);

  /// Obtention de la particule que contient la cellule.
  Particule* getParticule() const;

  /// Echange effectif de particules.
  virtual Particule* echangeParticule(Particule* part);

  

  /// Calcul de la requête associée.
  virtual void calculerRequete();

  /// Activation de l'échange de particules.
  virtual void activerEchange();

  /// Obtention de la requête précédemment calculée.
  virtual Requete getRequete() const;

  /// Obtention du phi de la particule contenue dans la cellule.
  virtual float getPhiParticule() const;

  /// Activation de la particule contenue dans la cellule.
  virtual void activer();

  /// Obtention de l'activité de la particule contenue dans la cellule.
  virtual bool getActivite() const;

  /// Méthode utilisée pour pouvoir debugger le code.
  virtual void afficheur() const;

  virtual void afficheurReduit() const;


  /// Méthode de débuggage qui demande à la cellule d'afficher son contenant sur un caractère, sur la sortie standard.
  void afficheToi() const;

  /** Méthode pour le GUI.
   */
  int donneTaCouleur() const;

  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  // UGLY je sais pas si ca marche ca
  // ca doit pas je pense
  // faut que l'adresse des fonctions virtuelles 
  // soit les memes !!!!!!!!!!!!!
  virtual ioManager<Cellule>* getIoManager() const
    {
      return (ioManager<Cellule>*) _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<CelluleAvecParticule> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut


private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Valeur de la requête calculée par la particule contenue dans la cellule.
  Requete _requete;

  /// Lien vers la particule contenue dans la cellule.
  Particule* _particule;
  
};
//##############################################################################
//##############################################################################
//##############################################################################
// METHODES INLINES
//##############################################################################
//##############################################################################
//##############################################################################

//##############################################################################
// Public members
//##############################################################################

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline CelluleAvecParticule* CelluleAvecParticule::clone() const
{
  return new CelluleAvecParticule(*this);
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline Particule * CelluleAvecParticule::getParticule() const
{
  return _particule;
}



#endif



