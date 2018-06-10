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

#ifndef _ZONAGE_H_
#define _ZONAGE_H_


#include "CommunScene.h"

#include "ContenuZonage.h"

//*******************************************************************************
/** Représente une le zonage. 
 *  Il est composé d'une formeFermée et d'un contenuZonage.
 *******************************************************************************/


class Zonage {

public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir d'une forme et d'un contenu.
  Zonage(FormeFermee * f,ContenuZonage * c): _formeFermee(f),_contenuZonage(c){} 

  /// Destructeur.
  virtual ~Zonage(){
    delete _formeFermee;
    delete _contenuZonage;
  }

  virtual Zonage* clone() const
    {
      return new Zonage(_formeFermee->clone(),_contenuZonage->clone());
    }

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

  FormeFermee* getFormeFermee() const
    {
      return _formeFermee;
    }

  ContenuZonage* getContenuZonage() const
    {
      return _contenuZonage;
    }

  void setContenuZonage(ContenuZonage * c)
    {
      _contenuZonage = c;
    }

  void afficheur() const
    {
      cerr << "Zonage\n" << endl;
      cerr << " Forme : ";
      _formeFermee->afficheur(); 
      cerr << " Contenu de la forme :\n";
      _contenuZonage->afficheur();
    }


  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<Zonage>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Zonage> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const Zonage &arg)
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

  /// Représente le type de la forme.
  FormeFermee * _formeFermee;

  /// Représente ce que contient le zonage courant.
  ContenuZonage * _contenuZonage;

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
inline Zonage::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

#endif

 
