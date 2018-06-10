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
/** Aggrégat de cellules.
 * C'est la classe la plus ``haute'' dans le modèle objet du moteur.
 * Elle est liée plus au moins directement avec tous les autres objets
 * du moteur.
 *
 * D'un point de vue externe, c'est celle qui génère les transitions 
 * de l'automate lorsqu'on appelle la méthode genereTransition().
 * Elle met aussi à disposition toutes les
 * méthodes nécessaires à la construction de la scène par ajout de nouvelles
 * règles, phases, particules et cellules à l'intérieur de l'objet Automate(
 * qui joue ainsi le role de container).
 *******************************************************************************/

class Automate
{
public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur à partir du germe du générateur aléatoire et de la dimension du réseau.
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

  /// L'opérateur =.
  Automate& operator=(const Automate&);


  /// Destructeur.
  virtual ~Automate();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Exceptions
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /** Exception lancée lorsque l'on appelle par ex getRegleByNom et que l'on ne trouve pas
   */
  class Exception{
  public:
    /// Le constructeur.
    Exception(string message);
  };


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Mise à jour du germe du générateur aléatoire.
  void setGerme(int germe);
  /// Obtention du germe du générateur aléatoire.
  int getGerme() const;

  void setNbrePas(int arg) {_nbPas = arg;}
  int getNbrePas() const {return _nbPas;}

  void setFreqAff(int arg) {_freqAff = arg;}
  int getFreqAff() const {return _freqAff;}

  
  /// Mise à jour de la dimension du réseau. 
  void setDimReseau(int dim_reseau);
  /// Obtention de la dimension du réseau.
  int getDimReseau() const;


  /// Obtention du tableau de références de la totalité des cellules utilisées dans le réseau.
  Cellule ** getTableauCellules() const;

  /// Ajout d'une phase dans une liste maintenue par l'automate.
  void ajoutPhase(Phase* phase);
  Phase* getPhaseByNom(string nom) const;

  /// Retourne le tableau des phases.
  list<Phase *> getTableauPhase()  const {return _phases;}


  /// Ajout d'une règle dans une liste maintenue par l'automate.
  void ajoutRegle(RegleExclusion* regle);
  RegleExclusion* getRegleByNom(string nom) const;

  /// Retourne le tableau des RegleExclusion.
  list<RegleExclusion *> getRegleExclusion()  const {return _regles;}


  void ajoutCouleur(Couleur* coul);
  /// Retourne le tableau des Couleurs.
  list<Couleur *> getCouleur()  const {return _tableauColormap;}

  /// Ajout d'une particule dans le réseau utilisé par l'automate.
  void ajoutParticule(Particule* particule);

  Particule* getParticuleByNumber(int num) const;


  /// Suppression d'une particule dans le réseau utilisé par l'automate.
  void suppressionParticule(Particule* particule);

  /// Ajout d'une cellule dans le réseau utilisé par l'automate.
  void ajoutCellule(Cellule* cellule);

  /// Calcul effectif de la totalité d'une transition de l'automate.
  void genereTransition() const;


  /// AJOUT
  void connecteCellules() const;
  

  /// Affiche les attributs privés de l'objet.
  void afficheur() const;
  /// Méthode de débuggage réduite à un identifiant.
  void afficheurReduit() const;
  /// Méthode de débuggage affichant tout le réseau sur la console.
  void afficheurReseau() const;

  /// Obtention d'un numéro libre pour référencer une nouvelle particule.
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
  // Méthodes privées
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Retourne vrai s'il reste au moins une particule propagative active.
  bool ilExisteParticulePropagativeActive() const;
  /// Calcul effectif, pour toutes les cellules du réseau, de la requête de la particule qu'elle contient éventuellement.
  void calculRequeteToutesLesCellules() const;
  /// Procède à l'échange du contenu des cellules dont les requêtes des particules qu'elles contiennent sont en accord deux-à-deux.
  void activerEchangeToutesLesCellules() const;
  /// Active les particules contenues dans chacune des cellules.
  void activerToutesLesCellules() const;
 
  /// Méthode utiliseée par afficheurReseau().
  void sQuiYAACetEndroit(int x, int y, int dim) const;

  void copy(const Automate&);

  void free();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // méthodes statiques privées
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  /// Retourne vrai si il existe au moins une particule propagative.
  bool modePropagatif() const;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Valeur du germe du générateur aléatoire.
  int _germe;
  /// Valeur de la dimension du réseau.
  int _dimReseau;

  /// Liste des règles d'exclusion utilisées.
  list<RegleExclusion*> _regles;

  /// Liste des phases utilisées.
  list<Phase*> _phases;

  /// Tableau référençant toutes les cellules du réseau.
  Cellule **_tableauCellule;
  

  /// Compteur interne pour numéroter les cellules ajoutées.
  int _compteurCellule;



  // Rajout pour fichiers
  ///  Tableau de Couleurs.
  list<Couleur *> _tableauColormap;

  /// Valeur du nombre de pas.
  int _nbPas;

  /// Valeur de la fréquence d'affichage.
  int _freqAff;



  /// Prochain numéro libre référençant une particule.
  int _numeroParticuleLibre;

  /// Liste des particules propagatives présentes au sein du réseau.
  list<Particule*> _particulePropagatives;

  /// Liste de toutes les particules.
  list<Particule*> _particule;

  /// Booléen interne pour déterminer si l'automate fonctionne en mode propagatif ou non.
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
// Autres méthodes
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
 *  De la façon dont nous gérons l'ensemble des cellules et leur numérotation,
 *  le total de cellules utilisées est le carré de la dimension du réseau.
 *  La scène peut alors être créée dans un losange de côté égal à la dimension.
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
 *  Il s'agit en fait de répertorier dans l'automate toutes les phases que
 *  l'on voudra utiliser par la suite, lors de la création des particules.
 ******************************************************************************/
inline void Automate::ajoutPhase(Phase* phase)
{
  _phases.push_back(phase);
}


//******************************************************************************
/** Description.
 *  Il s'agit en fait de répertorier dans l'automate toutes les règles
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
