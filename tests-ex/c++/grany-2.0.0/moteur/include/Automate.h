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

#ifndef _AUTOMATE_H_
#define _AUTOMATE_H_

#include "CommunMoteur.h"

#include "Phase.h"
#include "RegleExclusion.h"
#include "Cellule.h"
#include "Couleur.h"
//#include "CelluleAvecParticule.h"    CelluleSansParticule veut pas compiler sinon
//#include "Particule.h"

#include <list>

//*******************************************************************************
/** Aggr�gat de cellules.
 * C'est la classe la plus ``haute'' dans le mod�le objet du moteur.
 * Elle est li�e plus au moins directement avec tous les autres objets
 * du moteur.
 *
 * D'un point de vue externe, c'est celle qui g�n�re les transitions 
 * de l'automate lorsqu'on appelle la m�thode genereTransition().
 * Elle met aussi � disposition toutes les
 * m�thodes n�cessaires � la construction de la sc�ne par ajout de nouvelles
 * r�gles, phases, particules et cellules � l'int�rieur de l'objet Automate(
 * qui joue ainsi le role de container).
 *******************************************************************************/

class Automate
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur � partir du germe du g�n�rateur al�atoire et de la dimension du r�seau.
  Automate(int germe = 0, int dim_reseau = 0);

  Automate(int germe, 
	   int dim_reseau,
	   int nbpas,
	   int freqaff,
	   list<RegleExclusion *> regle,
	   list<Couleur *> colormap,
	   list<Phase *> phase);

  /// Le constructeur par recopie.
  Automate(const Automate&);

  /// L'op�rateur =.
  Automate& operator=(const Automate&);


  /// Destructeur.
  virtual ~Automate();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception lanc�e lorsque l'on appelle par ex getRegleByNom et que l'on ne trouve pas
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception(string message);
  };


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres m�thodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Mise � jour du germe du g�n�rateur al�atoire.
  void setGerme(int germe);
  /// Obtention du germe du g�n�rateur al�atoire.
  int getGerme() const;

  void setNbrePas(int arg) {_nbPas = arg;}
  int getNbrePas() const {return _nbPas;}

  void setFreqAff(int arg) {_freqAff = arg;}
  int getFreqAff() const {return _freqAff;}

  
  /// Mise � jour de la dimension du r�seau. 
  void setDimReseau(int dim_reseau);
  /// Obtention de la dimension du r�seau.
  int getDimReseau() const;


  /// Obtention du tableau de r�f�rences de la totalit� des cellules utilis�es dans le r�seau.
  Cellule ** getTableauCellules() const;

  /// Ajout d'une phase dans une liste maintenue par l'automate.
  void ajoutPhase(Phase* phase);
  Phase* getPhaseByNom(string nom) const;

  /// Retourne le tableau des phases.
  list<Phase *> getTableauPhase()  const {return _phases;}


  /// Ajout d'une r�gle dans une liste maintenue par l'automate.
  void ajoutRegle(RegleExclusion* regle);
  RegleExclusion* getRegleByNom(string nom) const;

  /// Retourne le tableau des RegleExclusion.
  list<RegleExclusion *> getRegleExclusion()  const {return _regles;}


  void ajoutCouleur(Couleur* coul);
  /// Retourne le tableau des Couleurs.
  list<Couleur *> getCouleur()  const {return _tableauColormap;}

  /// Ajout d'une particule dans le r�seau utilis� par l'automate.
  void ajoutParticule(Particule* particule);

  Particule* getParticuleByNumber(int num) const;


  /// Suppression d'une particule dans le r�seau utilis� par l'automate.
  void suppressionParticule(Particule* particule);

  /// Ajout d'une cellule dans le r�seau utilis� par l'automate.
  void ajoutCellule(Cellule* cellule);

  /// Calcul effectif de la totalit� d'une transition de l'automate.
  void genereTransition() const;


  /// AJOUT
  void connecteCellules() const;
  

  /// Affiche les attributs priv�s de l'objet.
  void afficheur() const;
  /// M�thode de d�buggage r�duite � un identifiant.
  void afficheurReduit() const;
  /// M�thode de d�buggage affichant tout le r�seau sur la console.
  void afficheurReseau() const;

  /// Obtention d'un num�ro libre pour r�f�rencer une nouvelle particule.
  int getNumeroParticuleLibre();

  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<Automate>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Automate> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const Automate &arg)
    {
      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");
      arg.getIoManager()->ecrire(arg,os);

      return os;
    }

  // marche celui la pour l'heritage ?? de tout facon on s'en fout
  // car TOEXPLAIN on la lecture y 'a que un module qui s'en occupe
  friend istream& operator>>(istream& is, Automate &arg)
    {

      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");

      Automate* arg2 = arg.getIoManager()->lire(is);
      
      arg = *arg2;

      delete arg2;

      return is;
    }



private:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // M�thodes priv�es
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Retourne vrai s'il reste au moins une particule propagative active.
  bool ilExisteParticulePropagativeActive() const;
  /// Calcul effectif, pour toutes les cellules du r�seau, de la requ�te de la particule qu'elle contient �ventuellement.
  void calculRequeteToutesLesCellules() const;
  /// Proc�de � l'�change du contenu des cellules dont les requ�tes des particules qu'elles contiennent sont en accord deux-�-deux.
  void activerEchangeToutesLesCellules() const;
  /// Active les particules contenues dans chacune des cellules.
  void activerToutesLesCellules() const;
 
  /// M�thode utilise�e par afficheurReseau().
  void sQuiYAACetEndroit(int x, int y, int dim) const;

  void copy(const Automate&);

  void free();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // m�thodes statiques priv�es
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Retourne vrai si il existe au moins une particule propagative.
  bool modePropagatif() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs priv�s
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Valeur du germe du g�n�rateur al�atoire.
  int _germe;
  /// Valeur de la dimension du r�seau.
  int _dimReseau;

  /// Liste des r�gles d'exclusion utilis�es.
  list<RegleExclusion*> _regles;

  /// Liste des phases utilis�es.
  list<Phase*> _phases;

  /// Tableau r�f�ren�ant toutes les cellules du r�seau.
  Cellule **_tableauCellule;
  

  /// Compteur interne pour num�roter les cellules ajout�es.
  int _compteurCellule;



  // Rajout pour fichiers
  ///  Tableau de Couleurs.
  list<Couleur *> _tableauColormap;

  /// Valeur du nombre de pas.
  int _nbPas;

  /// Valeur de la fr�quence d'affichage.
  int _freqAff;



  /// Prochain num�ro libre r�f�ren�ant une particule.
  int _numeroParticuleLibre;

  /// Liste des particules propagatives pr�sentes au sein du r�seau.
  list<Particule*> _particulePropagatives;

  /// Liste de toutes les particules.
  list<Particule*> _particule;

  /// Bool�en interne pour d�terminer si l'automate fonctionne en mode propagatif ou non.
  bool _modePropagatif;

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
inline void Automate::setGerme(int germe)
{
  _germe=germe;
  srand(germe);
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Automate::getGerme() const
{
  return _germe;
}


//******************************************************************************
/** Description.
 *  De la fa�on dont nous g�rons l'ensemble des cellules et leur num�rotation,
 *  le total de cellules utilis�es est le carr� de la dimension du r�seau.
 *  La sc�ne peut alors �tre cr��e dans un losange de c�t� �gal � la dimension.
 ******************************************************************************/
inline void Automate::setDimReseau(int dim_reseau)
{
  // pour moi ca realloue tout TOSEE
  _dimReseau = dim_reseau;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline int Automate::getDimReseau() const
{
  return _dimReseau;
}


//******************************************************************************
/** Description.
 *  Il s'agit en fait de r�pertorier dans l'automate toutes les phases que
 *  l'on voudra utiliser par la suite, lors de la cr�ation des particules.
 ******************************************************************************/
inline void Automate::ajoutPhase(Phase* phase)
{
  _phases.push_back(phase);
}


//******************************************************************************
/** Description.
 *  Il s'agit en fait de r�pertorier dans l'automate toutes les r�gles
 *  d'exclusion que l'on voudra utiliser par la suite au sein des phases.
 ******************************************************************************/
inline void Automate::ajoutRegle(RegleExclusion* regle)
{
  _regles.push_back(regle);
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline void Automate::ajoutCouleur(Couleur* coul)
{
  _tableauColormap.push_back(coul);
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline Cellule ** Automate::getTableauCellules() const
{
  return _tableauCellule;
}
//##############################################################################
// Private members
//##############################################################################

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
inline bool Automate::modePropagatif() const
{
  return _modePropagatif;
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
inline Automate::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}


#endif
