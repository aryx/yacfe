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

#ifndef _CONTIENTPHASE_H_
#define _CONTIENTPHASE_H_

#include "CommunScene.h"

#include "PhasePourcent.h"
#include "ContenuZonage.h"


//*******************************************************************************
/** Représente le fait que le contenu d'un zonage  est une liste de (phase, pourcentage).
 *******************************************************************************/
 
class ContientPhase : public ContenuZonage{

public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir d'une liste de PhasePourcent.
  ContientPhase(vector<PhasePourcent> tab_phase_pourcent)
  {
    _tab = tab_phase_pourcent ;
  }

  virtual ContientPhase* clone() const
    {
      return new ContientPhase(*this);
    }

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes : Fonctions d'acces aux membres 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Ajoute un objet PhasePourcent à la liste.
  void ajoutePhasePourcent(PhasePourcent p)
  {
    _tab.push_back(p) ;
  }
  /// Retourne la liste des (phase, pourcent).
  vector<PhasePourcent>* getPhasePourcent() {return &_tab ;}



  void afficheur() const
    { 
      cerr << "contient Phase: ";

      vector<PhasePourcent>::const_iterator it;

      for (it = _tab.begin(); it != _tab.end(); it++)
	{
	  it->phase->afficheur();
	  cerr << "Pourcentage :" << it->pourcentage << endl;
	}
      cerr << "\n" ;
    }

  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  // UGLY je sais pas si ca marche ca
  // ca doit pas je pense
  // faut que l'adresse des fonctions virtuelles 
  // soit les memes !!!!!!!!!!!!!
  virtual ioManager<ContenuZonage>* getIoManager() const
    {
      return (ioManager<ContenuZonage>*) _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<ContientPhase> *_io;

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

  ///  tableau de couple (phase,pourcentage de la phase).
  vector<PhasePourcent> _tab;

};

#endif

