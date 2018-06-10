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
/** Mod�lisation d'une cellule avec particule.
 *  Cette classe h�rite de la classe Cellule. Elle permet de pr�ciser le
 *  comportement des cellules contenant r�ellement une particule, c'est-�-dire
 *  les cellules ``classiques'' (on instanciera alors un objet CelluleAvecParticule)
 *  et les cellules "g�n�ratrices" (on utilisera la classe CelluleGeneratrice
 *  h�rit�e de CelluleAvecParticule).
 *******************************************************************************/

class CelluleAvecParticule : public Cellule
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur � partir de la particule que contiendra la cellule.
  CelluleAvecParticule(Particule* part);

  /// Destructeur virtuel.
  virtual ~CelluleAvecParticule();

  virtual CelluleAvecParticule* clone() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Mise � jour de la particule que contient la cellule.
  void setParticule(Particule* part);

  /// Obtention de la particule que contient la cellule.
  Particule* getParticule() const;

  /// Echange effectif de particules.
  virtual Particule* echangeParticule(Particule* part);

  

  /// Calcul de la requ�te associ�e.
  virtual void calculerRequete();

  /// Activation de l'�change de particules.
  virtual void activerEchange();

  /// Obtention de la requ�te pr�c�demment calcul�e.
  virtual Requete getRequete() const;

  /// Obtention du phi de la particule contenue dans la cellule.
  virtual float getPhiParticule() const;

  /// Activation de la particule contenue dans la cellule.
  virtual void activer();

  /// Obtention de l'activit� de la particule contenue dans la cellule.
  virtual bool getActivite() const;

  /// M�thode utilis�e pour pouvoir debugger le code.
  virtual void afficheur() const;

  virtual void afficheurReduit() const;


  /// M�thode de d�buggage qui demande � la cellule d'afficher son contenant sur un caract�re, sur la sortie standard.
  void afficheToi() const;

  /** M�thode pour le GUI.
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
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Valeur de la requ�te calcul�e par la particule contenue dans la cellule.
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
// Autres m�thodes
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



