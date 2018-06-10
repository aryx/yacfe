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

#ifndef _SCENE_H_
#define _SCENE_H_

#include "CommunScene.h"

#include "Frontiere.h"

#include "Zonage.h"
#include "Coloration.h"

#include "ContientPhase.h"
//*******************************************************************************
/** Représente le contenu d'un ficher .scene.
 *******************************************************************************/

class Scene{

public:
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Constructeurs/Destructeur
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Constructeur par défaut.
  Scene(){}; 

  /// Constructeur.
  Scene(list<Frontiere *> frontiere,
	list<RegleExclusion *> regle,
	list<Couleur *> colormap,
	list<Phase *> phase, 
	list<Zonage *> zonage, 
	list<Coloration *> coloration,
	Phase* phase_de_cell_gen = NULL) 
    {
      _tableauFrontiere=frontiere;
      _tableauRegleExclusion=regle;
      _tableauColormap=colormap;
      _tableauPhase=phase;
      _tableauZonage=zonage;
      _tableauColoration=coloration;

      _phaseGeneratrice = phase_de_cell_gen;
    }

  /// Le constructeur par recopie.
  Scene(const Scene& scene)
    {
      copy(scene);
    }

  /// L'opérateur =.
  Scene& operator=(const Scene& scene)
    {
      if (this != &scene)
      {
	free();
	copy(scene);
      }
      return *this;
    }

  /// Destructeur.
  virtual ~Scene()
    {
      free(); 
    }

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


  // ---- cut
  // les choses a declarer dans les fils : le getIoManager
  // et le static _io (different pour chaque sous class si
  // representation differente
  virtual ioManager<Scene>* getIoManager() const
    {
      return _io;
    }

  // ne pas oublier de le mettre dans le cpp aussi
  static ioManager<Scene> *_io;

  // quand la personne voudra afficher une regle, il y aura appel
  // a la methode virtuelle getIoManager (redefinit
  // dans chacune des sous classes) qui a son tour
  // appelera son ioManager
  //
  // ---- end cut

  friend ostream& operator<<(ostream& os,const Scene &arg)
    {
      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");
      arg.getIoManager()->ecrire(arg,os);

      return os;
    }

  // marche celui la pour l'heritage ?? de tout facon on s'en fout
  // car TOEXPLAIN on la lecture y 'a que un module qui s'en occupe
  friend istream& operator>>(istream& is, Scene &arg)
    {

      if (arg.getIoManager() == NULL)
	throw Exception("il n'y a pas de ioManager");

      Scene* arg2 = arg.getIoManager()->lire(is);
      
      arg = *arg2;

      delete arg2;

      return is;
    }


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Autres méthodes : Fonctions d'acces aux membres 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /// Ajoute un objet Frontiere au tableau des frontieres.
  void ajouteFrontiere(Frontiere *frontiere) 
    {
      _tableauFrontiere.push_back(frontiere);
    }

  /// Retourne le tableau des frontieres.
  list<Frontiere *> getTableauFrontiere() const {return _tableauFrontiere;}

  /// Place le tableau des frontieres.
  void setTableauFrontiere(list<Frontiere *> f) {_tableauFrontiere = f;}

  /// Ajoute un objet RegleExclusion au tableau des regles.
  void ajouteRegleExclusion(RegleExclusion *regle)
    {
      _tableauRegleExclusion.push_back(regle);
    }

  /// Retourne le tableau des RegleExclusion.
  list<RegleExclusion *> getTableauRegleExclusion()  const {return _tableauRegleExclusion;}

  /// Place le tableau des RegleExclusion.
  void setTableauRegleExclusion(list<RegleExclusion*> &re) {_tableauRegleExclusion = re;}

  /// Ajoute un objet Couleur au tableau des Couleurs.
  void ajouteCouleur(Couleur  * couleur)
    {
      _tableauColormap.push_back(couleur);
    }

  /// Retourne le tableau des Couleurs.
  list<Couleur *> getTableauCouleur()  const {return _tableauColormap;}

  /// Retourne le tableau des Couleurs.
  void setTableauCouleur(list<Couleur*> lc) {_tableauColormap = lc;}

  /// Ajoute un objet Phase au tableau des phases.
  void ajoutePhase(Phase *phase)
    {
      _tableauPhase.push_back(phase);
    }

  /// Retourne le tableau des phases.
  list<Phase *> getTableauPhase()  const {return _tableauPhase;}

  /// Place le tableau des phases.
  void setTableauPhase(list<Phase*> lp) { _tableauPhase = lp;}

  /// Ajoute un objet Zonage au tableau des zonages.
  void ajouteZonage(Zonage *zonage)
    {
      _tableauZonage.push_back(zonage);
    }

  /// Retourne le tableau des zonages.
  list<Zonage *> getTableauZonage() const {return _tableauZonage;}

  /// Place le tableau des zonages.
  void setTableauZonage(list<Zonage*> lz) { _tableauZonage = lz;}

  /// Retourne le type de la Phase generatrice.
  Phase* getPhaseGeneratrice()  const {return _phaseGeneratrice;}

  /// Place la phase generatrice.
  void setPhaseGeneratrice(Phase * p) { _phaseGeneratrice = p;}

  /// Ajoute un objet Coloration au tableau des colorations.
  void ajouteColoration(Coloration *coloration)
    {
      _tableauColoration.push_back(coloration);
    }

  /// Retourne le tableau des colorations.
  list<Coloration *> getTableauColoration()  const {return _tableauColoration;}

  void setTableauColoration(list<Coloration*> lc) { _tableauColoration = lc; }


  void afficheur() const
    {
      cerr << "********************************************** \n" ;
      cerr << "** Affichage des attributs de l'objet scene ** \n" ;
      cerr << "********************************************** \n" ;

      {
	/// Les Frontieres
	cerr << "Frontieres\n" ; 
	list<Frontiere*>::const_iterator it;
	
	for (it = _tableauFrontiere.begin(); it != _tableauFrontiere.end(); it++)
	  {
	    (*it)->afficheur() ;
	    cerr << "\n" ;
	  }
	cerr << "\n" ;
      }

      {
	// Les Regles
	cerr << "Regles\n" ; 
	list<RegleExclusion*>::const_iterator it;
	
	for (it = _tableauRegleExclusion.begin(); it != _tableauRegleExclusion.end(); it++)
	  {
	    (*it)->afficheur() ;
	    cerr << "\n" ;
	  }
	cerr << "\n" ;
      }


      {
	// La colorMap
	//	for_each(_tableauColormap.begin(),_tableauColormap.end(),mem_fun(&Couleur::afficheur));

	cerr << "ColorMap\n" ; 
	list<Couleur*>::const_iterator it;
	
	for (it = _tableauColormap.begin(); it != _tableauColormap.end(); it++)
	  {
	    (*it)->afficheur() ;
	    cerr << "\n" ;
	  }
	cerr << "\n" ;
      }

      {
	// Les Phases
	cerr << "Phases\n" ; 
	list<Phase*>::const_iterator it;
	
	for (it = _tableauPhase.begin(); it != _tableauPhase.end(); it++)
	  {
	    (*it)->afficheur() ;
	    cerr << "\n" ;
	  }
	cerr << "\n" ;
      }
      

      
	{
	  // Le Zonage
	  cerr << "Zonages\n" ; 
	  list<Zonage*>::const_iterator it;
	  
	  for (it = _tableauZonage.begin(); it != _tableauZonage.end(); it++)
	    {
	      (*it)->afficheur() ;
	      cerr << "\n" ;
	    }
	  cerr << "\n" ;
	}

      {
	// Les colorations
	cerr << "Colorations\n" ; 
	list<Coloration*>::const_iterator it;
	
	for (it = _tableauColoration.begin(); it != _tableauColoration.end(); it++)
	  {
	    (*it)->afficheur() ;
	    cerr << "\n" ;
	  }
	cerr << "\n" ;
      }

      {
	// La Phase gene
	cerr << "Phase Generatrice\n" ; 

	if (_phaseGeneratrice != NULL)
	  _phaseGeneratrice->afficheur();
	else cerr << "Pas de Phase Generatrice";
	cerr << "\n" ;
      }

    }
RegleExclusion* getRegleByNom(string nom) const
{

  list<RegleExclusion*>::const_iterator it_liste_regles;
  
  for(it_liste_regles=_tableauRegleExclusion.begin();it_liste_regles!=_tableauRegleExclusion.end();it_liste_regles++)
    if ((*it_liste_regles)->getNom()==nom) 
      return *(it_liste_regles);

  throw Exception("getRegleByNom: Pas de regle trouvée");

}

Phase* getPhaseByNom(string nom) const
{
  list<Phase*>::const_iterator it_liste_phases;
  
  for(it_liste_phases=_tableauPhase.begin();it_liste_phases!=_tableauPhase.end();it_liste_phases++)
    if ((*it_liste_phases)->getNom()==nom) 
      return *(it_liste_phases);

  throw Exception("getPhaseByNom: Pas de phase trouvée");

  
}


private:


  void copy(const Scene& scene)
    {
      // copy member
      list<Frontiere*>::const_iterator it_front;
      for (it_front = scene._tableauFrontiere.begin(); it_front != scene._tableauFrontiere.end(); it_front++)
	ajouteFrontiere((*it_front)->clone());

      list<Couleur*>::const_iterator it;
      for (it = scene._tableauColormap.begin(); it != scene._tableauColormap.end(); it++)
	ajouteCouleur((*it)->clone());

      list<RegleExclusion*>::const_iterator it_regle;
      for (it_regle = scene._tableauRegleExclusion.begin(); it_regle != scene._tableauRegleExclusion.end(); it_regle++)
	ajouteRegleExclusion((*it_regle)->clone());

      list<Phase*>::const_iterator it_phase;
      for (it_phase = scene._tableauPhase.begin(); it_phase != scene._tableauPhase.end(); it_phase++)
	ajoutePhase((*it_phase)->clone());

      list<Coloration*>::const_iterator it_col;
      for (it_col = scene._tableauColoration.begin(); it_col != scene._tableauColoration.end(); it_col++)
	ajouteColoration((*it_col)->clone());

      list<Zonage*>::const_iterator it_zon;
      for (it_zon = scene._tableauZonage.begin(); it_zon != scene._tableauZonage.end(); it_zon++)
	ajouteZonage((*it_zon)->clone());
      

      // mise a jour des pointeurs
      // Effacement de la liste de regle de la phase (pointeur non valide)
      for (it_phase = _tableauPhase.begin(); it_phase != _tableauPhase.end(); it_phase++)
	(*it_phase)->clearListeRegleExclusion();

      list<Phase*>::const_iterator it_phase2;
      // mise a jour des pointeurs dans les objets
      for (it_phase = scene._tableauPhase.begin(),
	     it_phase2 = _tableauPhase.begin();
	   it_phase != scene._tableauPhase.end(),
	     it_phase2 != _tableauPhase.end();
	   it_phase++,it_phase2++)
	{
	  list<RegleExclusion*>::const_iterator it_reg;
	  list<RegleExclusion*>* regle;
	  Phase::RegleEtMode regmode;

	  // les regles en PRE
	  regmode.mode = RegleExclusion::PRE;
	  regle = (*it_phase)->getRegleExclusion(RegleExclusion::PRE);
	  
	  for (it_reg = regle->begin(); it_reg != regle->end(); it_reg++)
	    {
	      regmode.regle = getRegleByNom((*it_reg)->getNom());
	      (*it_phase2)->ajoutPaire(regmode);
	    }

	  // les regles en POST
	  regmode.mode = RegleExclusion::POST;
	  regle = (*it_phase)->getRegleExclusion(RegleExclusion::POST);
	  for (it_reg = regle->begin(); it_reg != regle->end(); it_reg++)
	    {
	      regmode.regle = getRegleByNom((*it_reg)->getNom());
	      (*it_phase2)->ajoutPaire(regmode);
	    }
	}

      // Mise a jour des pointeurs des ContenuZonage
      list<Zonage*>::const_iterator it_zon2;


      for (it_zon = scene._tableauZonage.begin(),
	     it_zon2 = _tableauZonage.begin();
	   it_zon != scene._tableauZonage.end(),
	     it_zon2 != _tableauZonage.end();
	   it_zon++,it_zon2++)
	{
	  
	  if (ContientPhase* co = dynamic_cast<ContientPhase*>((*it_zon)->getContenuZonage()))
	    {
	      if (ContientPhase* co2 = dynamic_cast<ContientPhase*>((*it_zon2)->getContenuZonage()))
		{
		  vector<PhasePourcent>::iterator it,it2;
		  for (it = co->getPhasePourcent()->begin(),
		  	   it2 = co2->getPhasePourcent()->begin();
		  	 it != co->getPhasePourcent()->end(),
		  	   it2 != co2->getPhasePourcent()->end();
		  	 it++,it2++)
		    {
		  	// mettre a jour
		  	(*it2).phase = getPhaseByNom((*it).phase->getNom());
		    }

		}
	      else throw Exception("les ContenuZonage ne sont pas les memes");
	    }
	}
      // Mise a jour de la phase Generatrice
      
      Phase* phase_gen = scene.getPhaseGeneratrice();
      if ( phase_gen == NULL)
	_phaseGeneratrice = NULL;
      else 
	{
	  _phaseGeneratrice = getPhaseByNom(phase_gen->getNom());
	}

    }
  
  void free()
    {
      // La colorMap
      list<Couleur*>::const_iterator it;
      for (it = _tableauColormap.begin(); it != _tableauColormap.end(); it++)
	delete (*it);

      list<RegleExclusion*>::const_iterator it_regle;
      for (it_regle = _tableauRegleExclusion.begin(); it_regle != _tableauRegleExclusion.end(); it_regle++)
	delete (*it_regle);


      list<Phase*>::const_iterator it_phase;
      for (it_phase = _tableauPhase.begin(); it_phase != _tableauPhase.end(); it_phase++)
	delete (*it_phase);

      list<Coloration*>::const_iterator it_col;
      for (it_col = _tableauColoration.begin(); it_col != _tableauColoration.end(); it_col++)
	delete (*it_col);

      list<Frontiere*>::const_iterator it_front;
      for (it_front = _tableauFrontiere.begin(); it_front != _tableauFrontiere.end(); it_front++)
	delete (*it_front);

      list<Zonage*>::const_iterator it_zon;
      for (it_zon = _tableauZonage.begin(); it_zon != _tableauZonage.end(); it_zon++)
	delete (*it_zon);


      _tableauColormap.clear();
      _tableauRegleExclusion.clear();
      _tableauPhase.clear();          
      _tableauColoration.clear();     
      _tableauFrontiere.clear();      
      _tableauZonage.clear();         
      
    }



  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Attributs privés
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  ///  Tableau de RegleExclusion.
  list<RegleExclusion *> _tableauRegleExclusion;

  ///  Tableau de Couleurs.
  list<Couleur *> _tableauColormap;

  ///  Tableau de Phases.
  list<Phase *> _tableauPhase;

  ///  Tableau de zonages.
  list<Zonage *> _tableauZonage;

  ///  Tableau de frontieres.
  list<Frontiere *> _tableauFrontiere;

  ///  Tableau de coloration.
  list<Coloration *> _tableauColoration;



  ///
  Phase* _phaseGeneratrice;

};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exceptions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//******************************************************************************
/** Description.
 *  Il affiche sur la canal d'erreur la chaine [EXCEPTION] puis
 *  la chaine contenue dans la variable message.
 *
 ******************************************************************************/
inline Scene::Exception::Exception(string message)
{
  cerr << "[EXCEPTION] " << message << endl;

}

#endif


