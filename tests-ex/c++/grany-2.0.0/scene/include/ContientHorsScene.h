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

#ifndef _CONTIENTHORSSCENE_H_
#define _CONTIENTHORSSCENE_H_

#include "CommunScene.h"

#include "ContenuZonage.h"
#include "CelluleHorsScene.h"

//*******************************************************************************
/** Représente que le contenu d'un zonage est une cellule hors-scène.
 *******************************************************************************/
 
class ContientHorsScene : public ContenuZonage {

public:

  void afficheur()  const
  { 
    cerr << "Contient de type Hors scene "  << endl;
  }     

  virtual ContientHorsScene* clone() const
    {
      return new ContientHorsScene(*this);
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
  static ioManager<ContientHorsScene> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

    

};

#endif

