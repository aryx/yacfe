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

#include "Phase.h"
#include <iostream>

//##############################################################################
// Public members
//##############################################################################

//******************************************************************************
/** Description.
 *  \param nom nom de la phase.
 *  \param phi indice phi.
 *  \param propagatif la phase est-elle de type propagative ?
 *  \param inertie facteur inertiel.
 *  \param ponderation objet Ponderation.
 *  \param regles_et_modes liste des règles d'exclusion et modes
 ******************************************************************************/

Phase::Phase(string nom, 
	     float phi, 
	     bool propagatif, 
	     int inertie, 
	     Ponderation ponderation,
	     list<RegleEtMode> regles_et_modes)


{
  _nom         = nom;
  _phi         = phi;
  _propagatif  = propagatif;
  _inertie     = inertie;
  _ponderation = ponderation;
  _reglesEtModes= regles_et_modes;


  miseAjourCache();
}

//******************************************************************************
/** Description.
 *  Ne détruit pas les règles. c'est l'automate qui s'en chargera.
 ******************************************************************************/
Phase::~Phase()
{
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Phase::miseAjourCache()
{
  _reglesPre.clear();
  _reglesPost.clear();


  list<RegleEtMode>::iterator it_regles;

  for(it_regles=_reglesEtModes.begin(); it_regles!=_reglesEtModes.end(); it_regles++)
    if (it_regles->mode==RegleExclusion::PRE) 
      _reglesPre.push_back(it_regles->regle);
    else
      _reglesPost.push_back(it_regles->regle);
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Phase::ajoutPaire(RegleExclusion* regle, RegleExclusion::ModeExclusion mode)
{
  RegleEtMode re;
  
  re.mode  = mode;
  re.regle = regle;

  _reglesEtModes.push_back(re);

  if(mode==RegleExclusion::PRE)
    _reglesPre.push_back(regle);
  else
    _reglesPost.push_back(regle);
}

//******************************************************************************
/** Description.
 *  
 ******************************************************************************/
void Phase::ajoutPaire(RegleEtMode regle_et_mode)
{
  _reglesEtModes.push_back(regle_et_mode);

  if(regle_et_mode.mode==RegleExclusion::PRE)
    _reglesPre.push_back(regle_et_mode.regle);
  else
    _reglesPost.push_back(regle_et_mode.regle);
}


//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code.
 ******************************************************************************/
void Phase::afficheur() const
{
  cerr << "----------- Phase --------------" << endl;

  cerr << "Nom : " << _nom << endl;
  
  cerr << "Phi : " << _phi << endl;

  cerr << "Propagatif : " << _propagatif << endl;

  cerr << "Inertie : " << _inertie << endl;

  cerr << "Couleur (ajout) : " << _couleur << endl;
  
  cerr << "Ponderations : " << endl;

  _ponderation.afficheur();
  
  cerr << endl;

  list<RegleEtMode>::const_iterator it_regles;

  for(it_regles=_reglesEtModes.begin(); it_regles!=_reglesEtModes.end(); it_regles++)
    {

      cerr << "Regle d'exclusion utilisee en ";
      if (it_regles->mode == RegleExclusion::PRE) cerr << "PREexclusion :" << endl;
      else
	if (it_regles->mode == RegleExclusion::POST) cerr << "POSTexclusion :" << endl;
	else
	  cerr << "<erreur dans le mode d'exclusion (ni PRE ni POST)> :" << endl;

      if (it_regles->regle == NULL) {
	cerr << "WARNING: pointeur null a la place d'un pointeur vers une regle d'exclusion " << endl;
      } else {
	it_regles->regle->afficheur();
      }
    }
}


//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code (version réduite à un identifiant).
 ******************************************************************************/
void Phase::afficheurReduit() const
{
  cerr << "----------- Phase --------------" << endl;

  cerr << "Nom : " << _nom << endl;
}  

//##############################################################################
// static members
//##############################################################################
list<Phase::RegleEtMode> Phase::_reglesEtModesDefaut;
Ponderation Phase::_ponderationDefaut;

ioManager<Phase> * Phase::_io;
