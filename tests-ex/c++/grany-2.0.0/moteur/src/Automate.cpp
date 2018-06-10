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

#include "Automate.h"
#include "Particule.h"


#include "CelluleGeneratrice.h"

//##############################################################################
// Public members
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructeurs/Destructeur
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
Automate::Automate(int germe, int dim_reseau)
{
  _germe = germe;

  // > Kikounet has joined #ado-amitie
  srand(germe); 
 

  _dimReseau = dim_reseau;
  _tableauCellule = new (Cellule*)[dim_reseau*dim_reseau];
  for (int i = 0 ; i < dim_reseau*dim_reseau; i++)
    _tableauCellule[i] = NULL;

  // rajout topologie
  _compteurCellule = 0;
  _numeroParticuleLibre = 0;
  _modePropagatif = false;
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
Automate::Automate(int germe, 
	 int dim_reseau,
	 int nbpas,
	 int freqaff,
	 list<RegleExclusion *> regle,
	 list<Couleur *> colormap,
	 list<Phase *> phase)
{
  _germe = germe;
  // > Kikounet has joined #ado-amitie
  srand(germe); 
  
  _dimReseau = dim_reseau;
  _tableauCellule = new (Cellule*)[dim_reseau*dim_reseau];
  for (int i = 0 ; i < dim_reseau*dim_reseau; i++)
    _tableauCellule[i] = NULL;

  // rajout topologie
  _compteurCellule = 0;

  _numeroParticuleLibre = 0;
  _modePropagatif = false;

  _regles = regle;
  _phases = phase;

  _tableauColormap = colormap;
  _nbPas = nbpas;
  _freqAff = freqaff;

}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
int Automate::getNumeroParticuleLibre()
{
  return _numeroParticuleLibre++;
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

void Automate::copy(const Automate& autom)
{

  // recopie membre a membre


  _germe=autom._germe;
  _dimReseau=autom._dimReseau;

  // TODO clone if heritage sur RegleExclusion
  list<RegleExclusion*>::const_iterator it_regle;
  for (it_regle = autom._regles.begin(); it_regle != autom._regles.end(); it_regle++)
    ajoutRegle((*it_regle)->clone());

  // La colorMap
  list<Couleur*>::const_iterator it;
  for (it = autom._tableauColormap.begin(); it != autom._tableauColormap.end(); it++)
    ajoutCouleur((*it)->clone());

  list<Phase*>::const_iterator it_phase;
  for (it_phase = autom._phases.begin(); it_phase != autom._phases.end(); it_phase++)
    ajoutPhase((*it_phase)->clone());

  _tableauCellule = new (Cellule*)[autom._dimReseau*autom._dimReseau];

  

  _compteurCellule = 0;

  _nbPas = autom._nbPas;
  _freqAff = autom._freqAff;

  _numeroParticuleLibre = autom._numeroParticuleLibre;

  list<Particule*>::const_iterator it_part;
  for (it_part = autom._particule.begin(); it_part != autom._particule.end(); it_part++)
    ajoutParticule((*it_part)->clone());

  /// Booléen interne pour déterminer si l'automate fonctionne en mode propagatif ou non.
  _modePropagatif = autom._modePropagatif;


  // Effacement de la liste de regle de la phase (pointeur non valide)
  for (it_phase = _phases.begin(); it_phase != _phases.end(); it_phase++)
    (*it_phase)->clearListeRegleExclusion();
  
  list<Phase*>::const_iterator it_phase2;
  // mise a jour des pointeurs dans les objets
  for (it_phase = autom._phases.begin(),
	 it_phase2 = _phases.begin();
       it_phase != autom._phases.end(),
	 it_phase2 != _phases.end();
       it_phase++,it_phase2++)
    {
      list<RegleExclusion*>::const_iterator it_reg;
      list<RegleExclusion*>* regle;
      Phase::RegleEtMode regmode;

      // les regles en PRE
      regmode.mode = RegleExclusion::PRE;
      regle = (*it_phase)->getRegleExclusion(RegleExclusion::PRE);

      // regle = regle de l'autres
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

  // Mise a jour des pointeurs de phase pour les particules
  list<Particule*>::const_iterator it_part2;
  // mise a jour des pointeurs dans les objets
  for (it_part = autom._particule.begin(),
	 it_part2 = _particule.begin();
       it_part != autom._particule.end(),
	 it_part2 != _particule.end();
       it_part++,it_part2++)
    {
      (*it_part2)->setPhase(getPhaseByNom((*it_part)->getPhase()->getNom()));
    }

  
  for (int i = 0 ; i < _dimReseau*_dimReseau; i++)
    {
      ajoutCellule(autom._tableauCellule[i]->clone());
      if (CelluleAvecParticule* cell = dynamic_cast<CelluleAvecParticule*>(autom._tableauCellule[i]))
	{
	  if (CelluleAvecParticule* cell2 = dynamic_cast<CelluleAvecParticule*>(_tableauCellule[i]))
	    {
	      cell2->setParticule(getParticuleByNumber(cell->getParticule()->getNumero()));
	    }
	  else throw Exception("Les cellules ne sont pas les memes");
	}
      
      if (CelluleGeneratrice* cell = dynamic_cast<CelluleGeneratrice*>(autom._tableauCellule[i]))
	{
	  if (CelluleGeneratrice* cell2 = dynamic_cast<CelluleGeneratrice*>(_tableauCellule[i]))
	    {
	      cell2->setPhaseGeneree(getPhaseByNom(cell->getPhaseGeneree()->getNom()));
	      cell2->setAutomate(this);
	    }
	  else throw Exception("Les cellules ne sont pas les memes");
	}
      

    }

  connecteCellules();
  
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::free()
{
  // La colorMap
  list<Couleur*>::const_iterator it;
  for (it = _tableauColormap.begin(); it != _tableauColormap.end(); it++)
    delete (*it);

  list<RegleExclusion*>::const_iterator it_regle;
  for (it_regle = _regles.begin(); it_regle != _regles.end(); it_regle++)
    delete (*it_regle);


  list<Phase*>::const_iterator it_phase;
  for (it_phase = _phases.begin(); it_phase != _phases.end(); it_phase++)
    delete (*it_phase);

  list<Particule*>::const_iterator it_part;
  for (it_part = _particule.begin(); it_part != _particule.end(); it_part++)
    delete (*it_part);

  for (int i = 0 ; i< _dimReseau*_dimReseau; i++)
    if (_tableauCellule[i] == NULL) 
      cerr << "WARNING: pointeur null a la place d'un pointeur vers une Cellule " << endl ;
    else delete _tableauCellule[i];

  _tableauColormap.clear();
  _regles.clear();
  _phases.clear();
  _particule.clear();
  _particulePropagatives.clear();



  delete _tableauCellule;
  
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
Automate::Automate(const Automate& autom)
{
  copy(autom);
  
}

//******************************************************************************
/** Description.
 *  Le constructeur par recopie, le destructeur et l'opérateur d'affectation
 *  ont des parties de code identiques.
 *  En effet l'opérateur d'affectation effectue une
 *  libération de l'objet puis une recopie, le destructeur effectue simplement
 *  une libération et le constructeur par recopie effectue une recopie.
 *  L'idée retenue pour éviter cette duplication de code est de créer deux
 *  méthodes copie() et libere() qui seront appelées par les autres méthodes.
 *  Par exemple, l'opérateur d'affectation aura comme code :
 *  \code
 * Automate & Automate::operator=(const Automate &dir)
 * {
 *   if (this != &dir) {
 *     free();
 *     copy(dir);
 *   }
 *   return *this;
 * }
 *  \endcode
 ******************************************************************************/
Automate& Automate::operator=(const Automate& autom)
{
  if (this != &autom)
  {
    free();
    copy(autom);
  }
  return *this;

}



//******************************************************************************
/** Description.
 *  Detruit tout ce qu'il contient, règles, phase, colormap, cellules.
 ******************************************************************************/
Automate::~Automate()
{
  free();
}




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
Phase* Automate::getPhaseByNom(string nom) const
{
  list<Phase*>::const_iterator it_liste_phases;
  
  for(it_liste_phases=_phases.begin();it_liste_phases!=_phases.end();it_liste_phases++)
    if ((*it_liste_phases)->getNom()==nom) 
      return *(it_liste_phases);

  throw Exception("getPhaseByNom: Pas de phase trouvée");

  
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

Particule* Automate::getParticuleByNumber(int num) const
{
  list<Particule*>::const_iterator it_liste_part;
  
  for(it_liste_part=_particule.begin();it_liste_part!=_particule.end();it_liste_part++)
    if ((*it_liste_part)->getNumero()==num) 
      return *it_liste_part;

  // Here I've got a warning at line 353 with some compilers. If someone knows why I would be
  // glad to learn from you, <gcottenc at altern dot org>.

  throw Exception("getParticuleByNumber: Pas de particule trouvée");
}
  
//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
RegleExclusion* Automate::getRegleByNom(string nom) const
{
  DEBUG_MOTEUR(cerr << "Nom de la regle a trouver" << endl;)

  list<RegleExclusion*>::const_iterator it_liste_regles;
  
  for(it_liste_regles=_regles.begin();it_liste_regles!=_regles.end();it_liste_regles++)
    if ((*it_liste_regles)->getNom()==nom) 
      return *(it_liste_regles);

  throw Exception("getRegleByNom: Pas de regle trouvée");

}

//******************************************************************************
/** Description.
 *  \warning
 *  Attention, cet appel doit se faire impérativement en séquence à partir
 *  de la première cellule jusqu'à la dernière, et cela correspondant
 *  à la numérotation choisie (losange).
 ******************************************************************************/
void Automate::ajoutCellule(Cellule* cellule)
{
  cellule->setNumero(_compteurCellule);
  _tableauCellule[_compteurCellule++] = cellule;

  if (CelluleGeneratrice* cell = dynamic_cast<CelluleGeneratrice*>(cellule))
    {
      cell->setAutomate(this);
    }
}


//******************************************************************************
/** Description.
 *  \warning
 *  Attention, cet appel est impératif pour toutes les cellules contenant
 *  des particules. Il permet entre autres de maintenir un générateur
 *  de références internes uniques pour chaque particule utilisée.
 *  L'appel de cette méthode déclenche en plus la prise en compte du mode
 *  propagatif par le générateur de transition, et permet de construire une
 *  liste des particules propagatives pour la détection de la fin de transition.
 ******************************************************************************/
void Automate::ajoutParticule(Particule* particule)
{
  // mise a jour de _numeroParticuleLibre
  if (particule->getNumero() >= _numeroParticuleLibre) {
      _numeroParticuleLibre = particule->getNumero() +1;
    }
  if (particule->getPhase()->getPropagatif())
    {
      _modePropagatif = true;
      _particulePropagatives.push_back(particule);
    }
  _particule.push_back(particule);

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::suppressionParticule(Particule* particule)
{
  if (particule->getPhase()->getPropagatif())
    {
      list<Particule*>::iterator it_part;
 
      for (it_part = _particulePropagatives.begin(); it_part != _particulePropagatives.end(); it_part++)
	{
	  if (*it_part == particule)
	    {
	      _particulePropagatives.erase(it_part);
	      break;
	    }
	}
      
    }
  
  list<Particule*>::iterator it_part;
 
  for (it_part = _particule.begin(); it_part != _particule.end(); it_part++)
    {
      if (*it_part == particule)
	{
	  delete (*it_part);
	  _particulePropagatives.erase(it_part);
	  break;
	}
    }
  
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::connecteCellules() const
{
  int dim_reseau = getDimReseau();
  int nb_elem = dim_reseau*dim_reseau;
  if (nb_elem != _compteurCellule) 
    cerr << "conecteCellules:WARNING: le tableau de cellule n'est pas complet " << endl ;

  for (int i=0; i <dim_reseau*dim_reseau; i++)
    {
      if (_tableauCellule[i] == NULL) 
	cerr << "conecteCellules:WARNING: pointeur null a la place d'un pointeur vers une Cellule " << endl ;
      else {
	_tableauCellule[i]->setVoisin(NORD,_tableauCellule[abs((i-dim_reseau)%nb_elem)]);
	_tableauCellule[i]->setVoisin(SUD,_tableauCellule[(abs(i+dim_reseau)%nb_elem)]);
	_tableauCellule[i]->setVoisin(SW,_tableauCellule[abs((i-1)%nb_elem)]);
	_tableauCellule[i]->setVoisin(NE,_tableauCellule[abs((i+1)%nb_elem)]);
	_tableauCellule[i]->setVoisin(NW,_tableauCellule[abs((i-dim_reseau-1)%nb_elem)]);
	_tableauCellule[i]->setVoisin(SE,_tableauCellule[abs((i+dim_reseau+1)%nb_elem)]);
      }
    }
}



//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::genereTransition() const
{
  activerToutesLesCellules();
  if (modePropagatif())
    {
      while (ilExisteParticulePropagativeActive()) {
	calculRequeteToutesLesCellules();
	activerEchangeToutesLesCellules();
      }
    }
  else 
    {
    calculRequeteToutesLesCellules();
    activerEchangeToutesLesCellules();
    }
}





//##############################################################################
// Private members
//##############################################################################


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
bool Automate::ilExisteParticulePropagativeActive() const
{

  list<Particule*>::const_iterator it_part;

  for (it_part = _particulePropagatives.begin(); it_part != _particulePropagatives.end(); it_part++)
    {
      if ((*it_part)->getActivite()) return  true;
    }
  return false;

}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::calculRequeteToutesLesCellules() const
{
  for (int i = 0; i< getDimReseau()*getDimReseau(); i++)
    _tableauCellule[i]->calculerRequete();
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::activerEchangeToutesLesCellules() const
{
  for (int i = 0; i< getDimReseau()*getDimReseau(); i++)
    _tableauCellule[i]->activerEchange();
}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::activerToutesLesCellules() const
{
  for (int i = 0; i< getDimReseau()*getDimReseau(); i++)
    _tableauCellule[i]->activer();
  
}


//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code.
 ******************************************************************************/
void Automate::afficheur() const
{
  cerr << "----------- Automate --------------" << endl;

  cerr << "Germe : " << _germe << endl;
  
  cerr << "Dimension du reseau : " << _dimReseau << endl;

  cerr << "Mode Propagatif : " << _modePropagatif << endl;
  
  // La colorMap
  cerr << "ColorMap\n" ; 
  list<Couleur*>::const_iterator it;
  
  for (it = _tableauColormap.begin(); it != _tableauColormap.end(); it++)
    {
      (*it)->afficheur() ;
      cerr << "\n" ;
    }
  cerr << "\n" ;

  cerr << "Nombre de pas : " << _nbPas << endl;
  cerr << "frequence d'affichage : " << _freqAff << endl;


  list<RegleExclusion*>::const_iterator it_regle;
  for (it_regle = _regles.begin(); it_regle != _regles.end(); it_regle++)
    {
      (*it_regle)->afficheur();
    }


  list<Phase*>::const_iterator it_phase;
  for (it_phase = _phases.begin(); it_phase != _phases.end(); it_phase++)
    {
      (*it_phase)->afficheur();
    }

  cerr << "Numero particule libre : " << _numeroParticuleLibre << endl;
  
  cerr << "Compteur de cellule : " << _compteurCellule << endl;
  
  for (int i = 0 ; i< _dimReseau*_dimReseau; i++)
    {
  	if (_tableauCellule[i] == NULL) 
  	  cerr << "WARNING: pointeur null a la place d'un pointeur vers une Cellule " << endl ;
  	else _tableauCellule[i]->afficheur();
    }
  
  
  list<Particule*>::const_iterator it_part;
  for (it_part = _particulePropagatives.begin(); it_part != _particulePropagatives.end(); it_part++)
    {
  	(*it_part)->afficheur();
    }


}


//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Automate::afficheurReduit() const
{
  cerr << "Dimension du reseau : " << _dimReseau << endl;
}



/* Methodes pour l'afficheurTraviole() */

int getx(int num,int dim)
{
  return 2+((num % dim)*4);
}

int gety(int num,int dim)
{
  return (dim-1)*2+(((int)(num / dim))*4)-(num % dim)*2;
}

bool isMoins(int x, int y, int dim)
{
  if (((y+3)*2 + x) < dim*4) return false;
  if (((y-dim*4)*2 + x) > dim*4) return false;
  if ((((x-2) % 8) == 0) && ((y % 4) == 0)) return true;
  if ((((x-6) % 8) == 0) && (((y-2) % 4) == 0)) return true;

  return false;
}

bool isSlash(int x, int y, int dim)
{
  if (((y+3)*2 + x) < dim*4) return false;
  if (((y-dim*4)*2 + x) > dim*4) return false;
  if ((((y-1) % 4) == 0) && ((x % 8) == 0)) return true;
  if ((((y-3) % 4) == 0) && (((x-4) % 8) == 0)) return true;
  return false;
}

bool isAntiSlash(int x, int y, int dim)
{
  if (((y+3)*2 + x) < dim*4) return false;
  if (((y+2-dim*4)*2 + x) > dim*4) return false;
  if ((((y-1) % 4) == 0) && (((x-4) % 8) == 0)) return true;
  if ((((y-3) % 4) == 0) && ((x % 8) == 0)) return true;
  return false;
}

void Automate::sQuiYAACetEndroit(int x, int y, int dim) const
{
  for (int i = 0 ; i < dim*dim ; i++)
    {
      if ((getx(i,dim) == x) && (gety(i,dim) == y))
	{
	  getTableauCellules()[i]->afficheToi();
	  return;
	}
    }
  if (isMoins(x,y,dim))
    {
      cerr << '-';
      return;
    }
  if (isSlash(x,y,dim))
    {
      cerr << '/';
      return;
    }
  if (isAntiSlash(x,y,dim))
    {
      cerr << '\\';
      return;
    }
  cerr << ' ';
}

void Automate::afficheurReseau() const
{
  // bourrin
  int dim = getDimReseau();

  cerr << "--- Affichage du reseau ---\n";
  for (int y = -2 ; y <= dim*4+(dim-1)*2-2 ; y++)
    {
      for (int x = 0 ; x <= dim*4 ; x++)
	sQuiYAACetEndroit(x,y,dim);
      cerr << endl;
    }
}
//##############################################################################
// static members
//##############################################################################


ioManager<Automate> * Automate::_io;
