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
/** Caract�rise l'�tat d'une cellule.
 *  Une particule est compos�e de :
 *  <UL>
 *     <LI> un num�ro (il ne doit pas y avoir deux particules dans le r�seau ayant
 *          m�me num�ro),
 *     <LI> une phase (Le type de la particule est caract�ris� par un lien vers sa phase),
 *     <LI> un lien vers une cellule (de type CelluleAvecParticule),
 *     <LI> une requ�te courante (qui enregistre la direction qu'avait pris la particule
 *          lors de la transition pr�cedente si cette particule s'�tait d�plac�e, et RIEN sinon),
 *     <LI> un bool�en indiquant si la particule est active ou non.
 *  </UL>
 *  La m�thode la plus importante de cette classe est calculerRequete() qui comme
 *  son nom l'indique calcule la requ�te de la particule.
 *  L'attribut activit� est utilis� pour le mode propagatif.
 *  Il existe deux types de particules : les particules normales et les particules
 *  propagatives. Elles different uniquement dans leur comportement
 *  au moment o� elles bougent. La premi�re devient inactive lorsqu'elle
 *  bouge, tandis que la deuxi�me devient inactive lorsqu'elle s'arr�te.
 *
 *  La couleur n'est pas un param�tre du constructeur, mais elle est modifiable
 *  � l'aide de la m�thode setCouleur(). Cette facon de faire peut sembler bizarre
 *  mais cela marque notre intention de s�parer ce qui d�finit vraiment ce qu'est
 *  une particule (comme par exemple sa phase, etc...) de ce qui est du rajout
 *  li� en parti � l'interface graphique.
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
  
  /** Exception lev�e lorsque l'on essaie de r�cuperer un pointeur
   *  qui a la valeur NULL. Par exemple dans la m�thode getCellule()
   *  si le pointeur vers la cellule est NULL (ce qui veut dire
   *  que la particule n'est li�e � aucune cellule) alors on l�ve
   *  une exception.
   */
  class Exception {
  public:
    /// Constructeur.
    Exception(string message);
  };

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Mise � jour du num�ro de la particule.
  void setNumero(int num);
  /// Obtention du num�ro de la particule.
  int  getNumero() const;

  /// Mise � jour de la phase de la particule.
  void setPhase(Phase* phase);
  /// Obtention de la phase de la particule.
  Phase* getPhase() const;

  /// Mise � jour du lien vers la cellule contenant la particule.
  void setCellule(CelluleAvecParticule* cellule);
  /// Obtention de la cellule contenant la particule.
  CelluleAvecParticule* getCellule() const;

  /// Mise � jour de la requ�te courante.
  void setRequeteCourante(Requete req);
  /// Obtention de la requ�te courante.
  Requete getRequeteCourante() const;

  /// Calcul la requ�te.
  Requete calculerRequete();


  /// Mise � jour de l'activite de la particule.
  void setActivite(bool activite);
  /// Obtention de l'activite de la particule.
  bool getActivite() const;


  /// Informe la particule qu'elle vient de bouger.
  void tuBouges();
  /// Informe la particule qu'elle ne vient pas de bouger.
  void tuBougesPas();


 

  /// Mise � jour de la couleur de la particule.
  void setCouleur(int couleur);
  /// Obtention de la couleur de la particule.
  int getCouleur() const;

  /// Affiche les attributs priv�s de l'objet.
  void afficheur() const;
  /// M�thode de d�buggage r�duite � un identifiant.
  void afficheurReduit() const;



private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // M�thodes priv�es
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Applique le crit�re inertiel.
  void appliquerCritereInertiel(Ponderation * p) const;
  /// Applique des r�gles d'exclusion.
  void appliquerExclusions(Ponderation * ponderation, list<RegleExclusion*> *regles_exclusion) const;
  /// Tire au hasard une requ�te.
  void elireRequete(Ponderation * ponderation) const;

  bool verifieExclusion(RegleExclusion* regle) const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /// Num�ro de la particule.
  int _numero;
  /// Phase de la particule.
  Phase* _phase;


  /** 
   * Lien vers la cellule qui la contient.
   * \warning
   * Ce lien doit �tre mis � jour par des proc�dures ext�rieures. En aucun cas
   * l'objet Particule n'assure que le lien _cellule est coh�rent (il est possible
   * que ce lien pointe vers une cellule qui en fait ne la contient pas).
   */
  CelluleAvecParticule* _cellule;

  /**
   * Utilis� pour prendre en compte l'inertie.
   * Lors du calcul de sa requ�te, la particule aura tendance � se d�placer
   * dans la m�me direction qu'� l'�tape pr�c�dente. Cet attribut sert
   * � stocker cette direction pr�c�dente.
   * \warning
   * Cet attribut doit �tre mis � jour par des proc�dures ext�rieures.
   * En effet la particule ne fait que calculer une requ�te (qui sera ou ne sera pas prise
   * en compte, si une autre particule veut bien s'echanger avec elle).
   * Il sera donc modifi� par la m�thode qui s'occupe de valider les �changes,
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
// Autres m�thodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  \warning
 *  Cette m�thode n'assure en aucune
 *  facon que ce num�ro n'est pas utilis� par une autre particule.
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
 *  Cette m�thode ne met pas � jour le pointeur vers particule de l'objet
 *  cellule (c'est pour empecher les appels r�cusifs � l'infini).
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

