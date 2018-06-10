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

#ifndef _COULEUR_H_
#define _COULEUR_H_


//*******************************************************************************
/** Représente une couleur sous forme un numero de couleur suivit par les 3 composantes RGB de la couleur.
 *******************************************************************************/
#include "CommunMoteur.h"


class Couleur 
{
  
public:

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception.
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception(string message);
  };


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir d'un entier et de 3 longs.
  Couleur(int num=0, long r=0, long g=0, long b=0) : _num(num), _red(r), _green(g), _blue(b){};
  
  virtual Couleur* clone() const;


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes : Fonctions d'acces aux membres 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Retourne le numero de la couleur.
  int getCouleur() const {return _num;}

  /// Retourne la composante rouge de la couleur.
  int getRed() const {return _red;}

  /// Retourne la composante verte de la couleur.
  int getGreen() const {return _green;}

  /// Retourne la composante bleue de la couleur.
  int getBlue() const {return _blue;}




 void afficheur()
  {
    cerr << "Couleur Numero: " << _num;
    cerr << "  R= " << _red;
    cerr << "  G= " << _green;
    cerr << "  B= " << _blue; 
    cerr << "\n";
   }

  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<Couleur>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Couleur> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const Couleur &arg)
    {
      DEBUG_MOTEUR(cerr << "dans << de Couleur\n";)
      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");
      arg.getIoManager()->ecrire(arg,os);

      return os;
    }



private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Numero de la couleur.
  int _num;

  /// Composante rouge de la couleur.
  int _red;

  /// Composante verte de la couleur.
  int _green;

  /// Composante bleue de la couleur.
  int _blue;

};




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

inline Couleur* Couleur::clone() const
{
  return new Couleur(*this);
}


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
inline Couleur::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

#endif
