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

#ifndef _PARTICULE_H_
#define _PARTICULE_H_


#include "CommunMoteur.h"
#include "CelluleAvecParticule.h"
#include "Phase.h"
#include "RegleExclusion.h"
#include "Ponderation.h"
#include "Requete.h"


//*******************************************************************************
/** Caractérise l'état d'une cellule.
 *  Une particule est composée de :
 *  <UL>
 *     <LI> un numéro (il ne doit pas y avoir deux particules dans le réseau ayant
 *          même numéro),
 *     <LI> une phase (Le type de la particule est caractérisé par un lien vers sa phase),
 *     <LI> un lien vers une cellule (de type CelluleAvecParticule),
 *     <LI> une requête courante (qui enregistre la direction qu'avait pris la particule
 *          lors de la transition précedente si cette particule s'était déplacée, et RIEN sinon),
 *     <LI> un booléen indiquant si la particule est active ou non.
 *  </UL>
 *  La méthode la plus importante de cette classe est calculerRequete() qui comme
 *  son nom l'indique calcule la requête de la particule.
 *  L'attribut activité est utilisé pour le mode propagatif.
 *  Il existe deux types de particules : les particules normales et les particules
 *  propagatives. Elles different uniquement dans leur comportement
 *  au moment où elles bougent. La première devient inactive lorsqu'elle
 *  bouge, tandis que la deuxième devient inactive lorsqu'elle s'arrête.
 *
 *  La couleur n'est pas un paramètre du constructeur, mais elle est modifiable
 *  à l'aide de la méthode setCouleur(). Cette facon de faire peut sembler bizarre
 *  mais cela marque notre intention de séparer ce qui définit vraiment ce qu'est
 *  une particule (comme par exemple sa phase, etc...) de ce qui est du rajout
 *  lié en parti à l'interface graphique.
 *
 * \sa ParticulePropagative, Phase, Cellule
 *******************************************************************************/

class Particule {
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur.
  Particule(int num, 
	    Phase* phase, 
	    CelluleAvecParticule* cell, 
	    Requete req_cour, 
	    bool acti);

  Particule(int num, 
	    Phase* phase, 
	    CelluleAvecParticule* cell, 
	    Requete req_cour, 
	    bool acti, 
	    int couleur);


  Particule* clone() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /** Exception levée lorsque l'on essaie de récuperer un pointeur
   *  qui a la valeur NULL. Par exemple dans la méthode getCellule()
   *  si le pointeur vers la cellule est NULL (ce qui veut dire
   *  que la particule n'est liée à aucune cellule) alors on lève
   *  une exception.
   */
  class Exception {
  public:
    /// Constructeur.
    Exception(string message);
  };

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Mise à jour du numéro de la particule.
  void setNumero(int num);
  /// Obtention du numéro de la particule.
  int  getNumero() const;

  /// Mise à jour de la phase de la particule.
  void setPhase(Phase* phase);
  /// Obtention de la phase de la particule.
  Phase* getPhase() const;

  /// Mise à jour du lien vers la cellule contenant la particule.
  void setCellule(CelluleAvecParticule* cellule);
  /// Obtention de la cellule contenant la particule.
  CelluleAvecParticule* getCellule() const;

  /// Mise à jour de la requête courante.
  void setRequeteCourante(Requete req);
  /// Obtention de la requête courante.
  Requete getRequeteCourante() const;

  /// Calcul la requête.
  Requete calculerRequete();


  /// Mise à jour de l'activite de la particule.
  void setActivite(bool activite);
  /// Obtention de l'activite de la particule.
  bool getActivite() const;


  /// Informe la particule qu'elle vient de bouger.
  void tuBouges();
  /// Informe la particule qu'elle ne vient pas de bouger.
  void tuBougesPas();


 

  /// Mise à jour de la couleur de la particule.
  void setCouleur(int couleur);
  /// Obtention de la couleur de la particule.
  int getCouleur() const;

  /// Affiche les attributs privés de l'objet.
  void afficheur() const;
  /// Méthode de débuggage réduite à un identifiant.
  void afficheurReduit() const;



private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Méthodes privées
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Applique le critère inertiel.
  void appliquerCritereInertiel(Ponderation * p) const;
  /// Applique des règles d'exclusion.
  void appliquerExclusions(Ponderation * ponderation, list<RegleExclusion*> *regles_exclusion) const;
  /// Tire au hasard une requête.
  void elireRequete(Ponderation * ponderation) const;

  bool verifieExclusion(RegleExclusion* regle) const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /// Numéro de la particule.
  int _numero;
  /// Phase de la particule.
  Phase* _phase;


  /** 
   * Lien vers la cellule qui la contient.
   * \warning
   * Ce lien doit être mis à jour par des procédures extérieures. En aucun cas
   * l'objet Particule n'assure que le lien _cellule est cohérent (il est possible
   * que ce lien pointe vers une cellule qui en fait ne la contient pas).
   */
  CelluleAvecParticule* _cellule;

  /**
   * Utilisé pour prendre en compte l'inertie.
   * Lors du calcul de sa requête, la particule aura tendance à se déplacer
   * dans la même direction qu'à l'étape précédente. Cet attribut sert
   * à stocker cette direction précédente.
   * \warning
   * Cet attribut doit être mis à jour par des procédures extérieures.
   * En effet la particule ne fait que calculer une requête (qui sera ou ne sera pas prise
   * en compte, si une autre particule veut bien s'echanger avec elle).
   * Il sera donc modifié par la méthode qui s'occupe de valider les échanges,
   * CelluleAvecParticule::echangeParticule.
   */
  Requete _requeteCourante;

  /// La particule est-elle active ?
  bool _activite;


  /// Couleur de la particule.
  int _couleur;


};

//##############################################################################
//##############################################################################
//##############################################################################
// METHODES INLINES
//##############################################################################
//##############################################################################
//##############################################################################

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline Particule* Particule::clone() const
{
  return new Particule(*this);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exceptions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  Il affiche sur la canal d'erreur la chaine [EXCEPTION] puis
 *  la chaine contenue dans la variable message.
 *
 ******************************************************************************/
inline Particule::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  \warning
 *  Cette méthode n'assure en aucune
 *  facon que ce numéro n'est pas utilisé par une autre particule.
 *  
 ******************************************************************************/

inline void Particule::setNumero(int num)
{
  _numero=num;
}
//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline int Particule::getNumero() const
{
  return _numero;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline void Particule::setPhase(Phase* phase)
{
  _phase=phase;
}

//******************************************************************************
/** Description.
 *  \exception Exception si le pointeur vers phase est NULL.
 ******************************************************************************/
inline Phase* Particule::getPhase() const
{
#ifdef DEBUG_EXCEPTION
  if (_phase == NULL) throw Exception("Particule::getPhase() : _phase == NULL");
#endif
  return _phase;

}


//******************************************************************************
/** Description.
 *  \warning
 *  Cette méthode ne met pas à jour le pointeur vers particule de l'objet
 *  cellule (c'est pour empecher les appels récusifs à l'infini).
 ******************************************************************************/
inline void Particule::setCellule(CelluleAvecParticule* cellule)
{
  _cellule=cellule;
}


//******************************************************************************
/** Description.
 *  \exception Exception si le pointeur vers cellule est NULL
 ******************************************************************************/
inline CelluleAvecParticule* Particule::getCellule() const
{
#ifdef DEBUG_EXCEPTION
  if (_cellule == NULL) throw Exception("Particule::getCellule() : _cellule == NULL");
#endif
  return _cellule;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Particule::setRequeteCourante(Requete req_cour)
{
  _requeteCourante=req_cour;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline Requete Particule::getRequeteCourante() const
{
  return _requeteCourante;
}


  
//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Particule::setActivite(bool activite)
{
  _activite=activite;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline bool Particule::getActivite() const
{
  return _activite;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Particule::setCouleur(int couleur)
{
  _couleur = couleur;
}



//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Particule::getCouleur() const
{
  return _couleur;
}



#endif

