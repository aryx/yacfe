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

#ifndef _COLORATION_H_
#define _COLORATION_H_

#include "CommunScene.h"




//*******************************************************************************
/** Représente la coloration d'une FormeFermee.
 *  Composé d'un ensemble de formes, et d'une couleur.
 *  On utilise FormeFermee car on ne peut remplir que des formes fermées.
 *******************************************************************************/
 
class Coloration {


public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir d'une FormeFermee et d'une Couleur.
  Coloration(FormeFermee  * f, int c): _formeFermee(f),_couleur(c) {}

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


  virtual ~Coloration()
    {
      delete _formeFermee ;
      //      delete _couleur;
    }


  virtual Coloration* clone() const
    {
      return new Coloration(_formeFermee->clone(),_couleur);
    }

  int getCouleur() const { return _couleur ; }

  FormeFermee* getFormeFermee() const {return _formeFermee;}

  void afficheur() const
    {
      cerr << "Coloration\n";
      cerr << "Forme Fermee :";
      _formeFermee->afficheur();
      cerr << "Couleur :" << _couleur << endl;
    }

  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<Coloration>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Coloration> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const Coloration &arg)
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

  /// Type de la forme.
  FormeFermee  * _formeFermee;

  /// Couleur de la forme précédement définie.
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
// Exceptions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  Il affiche sur la canal d'erreur la chaine [EXCEPTION] puis
 *  la chaine contenue dans la variable message.
 *
 ******************************************************************************/
inline Coloration::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}


#endif

 
