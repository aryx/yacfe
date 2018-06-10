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

#ifndef _PHASE_H_
#define _PHASE_H_


#include "CommunMoteur.h"

#include <list>
#include <string>

#include "Direction.h"
#include "Ponderation.h"
#include "RegleExclusion.h"



//*******************************************************************************
/** Contient des informations caract�risant le type d'une particule.
 *  On y trouve : 
 *  <UL>
 *    <LI> son nom,
 *    <LI> un indice phi (qui permet de differencier les phases
 *         solides et non-solides), 
 *    <LI> un bool�en indiquant si la phase est de type propagative,
 *    <LI> un facteur inertiel,
 *    <LI> des pond�rations pour les six directions,
 *    <LI> une liste de r�gles d'exclusion (ainsi que son mode d'exclusion : en post ou pr�
 *         exclusion)
 *    <LI> une couleur.
 *  </UL>  
 *  La couleur n'est pas un param�tre du constructeur, mais elle est modifiable
 *  � l'aide de la m�thode setCouleur(). Cette facon de faire peut sembler bizarre
 *  mais cela marque notre intention de s�parer ce qui d�finit vraiment ce qu'est
 *  une phase (comme par exemple son indice phi, etc...) de ce qui est du rajout
 *  li� en parti � l'interface graphique.
 *  \sa Particule, RegleExclusion
 *******************************************************************************/


class Phase
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Symboles/Enum
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Paire RegleExclusion et ModeExclusion
  struct RegleEtMode {
    RegleExclusion *regle;
    RegleExclusion::ModeExclusion mode;
    
  };

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception lev�e lorsque l'on essaie de construire une phase par recopie.
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception(string message);
  };
  

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Valeur par d�faut du constructeur
  static list<RegleEtMode> _reglesEtModesDefaut;

  /// Valeur par d�faut du constructeur
  static Ponderation _ponderationDefaut;

  /// Constructeur par defaut.
  Phase(string nom          = "NONE", 
	float phi           = PHI_SOLIDE , 
	bool propagatif     = false, 
	int inertie         = 1, 
	Ponderation ponderation = _ponderationDefaut,
	list<RegleEtMode> regles_et_modes = _reglesEtModesDefaut);

  /// Destructeur.
  virtual ~Phase();

  virtual Phase* clone() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Mise � jour du nom de la phase.
  void setNom(string nom);
  /// Obtention du nom de la phase.
  string getNom() const;

  /// Mise � jour de l'indice phi.
  void setPhi(float phi);
  /// Obtention de l'indice phi.
  float getPhi() const;


  /// Mise � jour du bool�en indiquant si la phase est propagative.
  void setPropagatif(bool quelmode);
  /// Obtention du bool�en indiquant si la phase est propagative.
  bool getPropagatif() const;

  /// Mise � jour du facteur inertiel.
  void setInertie(int valeur);
  /// Obtention du facteur inertiel.
  int getInertie() const;

  /// Mise � jour des ponderations.
  void setPonderation(const Ponderation &ponderation);
  /// Obtention des ponderations.
  Ponderation getPonderation() const;


  /// Ajoute une r�gle (et son mode) � la liste des r�gles d'exclusion.
  void ajoutPaire(RegleExclusion* regle, RegleExclusion::ModeExclusion mode);

  /// Ajoute une r�gle (et son mode) � la liste des r�gles d'exclusion.
  void ajoutPaire(RegleEtMode regle_et_mode);


  /// Obtention de la liste des r�gles d'exclusion qui sont soumises au mode d'exclusion mode.
  list<RegleExclusion*>* getRegleExclusion(RegleExclusion::ModeExclusion mode);

  const list<RegleEtMode>* getRegleEtModeExclusion() const;

  void setRegleEtModeExclusion(list<RegleEtMode>&);

  void clearListeRegleExclusion();

  /// Mise � jour de la couleur.
  void setCouleur(int couleur);
  /// Obtention de la couleur.
  int getCouleur() const;

  /// Affiche les attributs priv�s de l'objet.
  void afficheur() const;

  /// M�thode de d�buggage r�duite � un identifiant.
  void afficheurReduit() const;


  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<Phase>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Phase> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const Phase &arg)
    {
      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");
      arg.getIoManager()->ecrire(arg,os);

      return os;
    }



private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Methodes priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  void miseAjourCache();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Nom de la phase.
  string _nom;
  /// L'indice phi.
  float _phi;
  /// La phase est-elle de type propagative ?
  bool _propagatif;
  /// Facteur inertiel.
  int _inertie;
  /// Pond�rations.
  Ponderation _ponderation;

  /// Liste des r�gles d'exclusion et de son mode.
  list<RegleEtMode> _reglesEtModes;

  /// Liste des r�gles d'exclusion en pre (cache). 
  list<RegleExclusion*> _reglesPre;

  /// Liste des r�gles d'exclusion en post (cache). 
  list<RegleExclusion*> _reglesPost;

  /// Couleur de la phase. 
  int _couleur;


};
//##############################################################################
//##############################################################################
//##############################################################################
// METHODES INLINES
//##############################################################################
//##############################################################################
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres m�thodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::clearListeRegleExclusion()
{
  _reglesEtModes.clear();
  _reglesPost.clear();
  _reglesPre.clear();
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline Phase* Phase::clone() const
{
  return new Phase(*this);
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::setNom(string nom)
{
  _nom=nom;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline string Phase::getNom() const
{
  return _nom;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::setPhi(float phi)
{
  _phi=phi;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline float Phase::getPhi() const
{
  return _phi;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::setPropagatif(bool quelmode)
{
  _propagatif=quelmode;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline bool Phase::getPropagatif() const
{
  return _propagatif;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::setInertie(int valeur)
{
  _inertie=valeur;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Phase::getInertie() const
{
  return _inertie;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::setPonderation(const Ponderation &ponderation)
{
  _ponderation=ponderation;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline Ponderation Phase::getPonderation() const
{
  return _ponderation;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::setCouleur(int couleur)
{
  _couleur=couleur;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Phase::getCouleur() const
{
  return _couleur;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline list<RegleExclusion*>* Phase::getRegleExclusion(RegleExclusion::ModeExclusion mode)
{
  if (mode == RegleExclusion::PRE)
    return &_reglesPre;
  else 
    return &_reglesPost;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline const list<Phase::RegleEtMode>* Phase::getRegleEtModeExclusion() const
{
  return &_reglesEtModes;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Phase::setRegleEtModeExclusion(list<Phase::RegleEtMode> &rem)
{
  _reglesEtModes = rem;
  miseAjourCache();
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
inline Phase::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

#endif
