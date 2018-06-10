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

#include "Particule.h"

//##############################################################################
// Public members
//##############################################################################

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructeurs/Destructeur
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 * \param num le numéro de particule. 
 *      \warning
 *      Le constructeur de la particule n'assure en aucune
 *      facon que ce numéro n'est pas utilisé par une autre particule.
 * \param phase la phase de la particule.
 * \param cell la cellule avec laquelle la particule sera liée (pour appliquer les
 *    règles d'exclusion, la particule a besoin de connaitre ses voisines, ce qui implique
 *    qu'elle doit appeler la méthode Cellule::getVoisin() de la cellule qui la contient).
 * \param req_cour la requête précédente de la particule (souvent RIEN).
 * \param acti l'activité de la particule (souvent VRAI pour active).
 * \param couleur l'indice d'une colormap
 ******************************************************************************/
Particule::Particule(int num, Phase* phase, CelluleAvecParticule* cell, Requete req_cour, bool acti, int couleur)
{
  _numero = num;
  _phase = phase;
  _cellule = cell;
  _requeteCourante = req_cour;
  _activite = acti;
  _couleur = couleur;
}

//******************************************************************************
/** Description.
 * \param num le numéro de particule. 
 *      \warning
 *      Le constructeur de la particule n'assure en aucune
 *      facon que ce numéro n'est pas utilisé par une autre particule.
 * \param phase la phase de la particule.
 * \param cell la cellule avec laquelle la particule sera liée (pour appliquer les
 *    règles d'exclusion, la particule a besoin de connaitre ses voisines, ce qui implique
 *    qu'elle doit appeler la méthode Cellule::getVoisin() de la cellule qui la contient).
 * \param req_cour la requête précédente de la particule (souvent RIEN).
 * \param acti l'activité de la particule (souvent VRAI pour active).
 ******************************************************************************/
Particule::Particule(int num, Phase* phase, CelluleAvecParticule* cell, Requete req_cour, bool acti)
{
  _numero = num;
  _phase = phase;
  _cellule = cell;
  _requeteCourante = req_cour;
  _activite = acti;

  if (phase != NULL)
    _couleur = phase->getCouleur();
  else _couleur = 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Autres méthodes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 * Voici l'algorithme :
 * \code
 *   Si la particule est inactive alors retourner RIEN
 *   Sinon
 *       récuperer les pondérations de la particule (définit dans sa phase)
 *       appliquer le critère inertiel
 *       appliquer les règles de pré-exclusion (définit dans sa phase)
 *       elire une requête au hasard
 *       appliquer les règles de post exclusion sur cette requête (définit dans sa phase)
 *       retourner la requête.
 * \endcode
 *  
 ******************************************************************************/
Requete Particule::calculerRequete()
{
  Requete req;
  if (getActivite() == false) {
    req = RIEN;
  }
  else {
    Ponderation * p = new Ponderation(getPhase()->getPonderation());
    appliquerCritereInertiel(p);
    appliquerExclusions(p, getPhase()->getRegleExclusion(RegleExclusion::PRE));
    elireRequete(p);
    appliquerExclusions(p, getPhase()->getRegleExclusion(RegleExclusion::POST));

    if (p->getModule() == 0 ) req = RIEN;
    else 
      {
	for (int i = 0; i <VALENCE; i++) 
	  if (p->getPonderation(Direction(i)) != 0)
	    req = Requete(i);
      }

    delete(p);

    /* gc: Maintenant que le critere inertiel a ete pris en compte, on peut annuler
     * son effet pour la suite de la sous-transition, et la prochaine transition.
     * Si la particule se deplace vraiment, RequeteCourante sera mis a jour
     * selon ce deplacement grace a CelluleAvecParticule::activerEchange()
     */
    setRequeteCourante(RIEN);
  }
  return req;
}
 

//******************************************************************************
/** Description.
 *  Si la particule n'est pas propagative, on place l'activité à faux 
 *  (la particule devient inactive), sinon on fait rien
 *  En effet on veut autoriser les vides à pouvoir s'échanger plusieurs
 *  fois au cour d'une même transition afin que des grains de sable puissent
 *  dégringoler.

 ******************************************************************************/
void Particule::tuBouges()
{
  if (getPhase()->getPropagatif() == false )
    setActivite(false);
  
}

//******************************************************************************
/** Description.
 *  Si la particule n'est pas propagative, on ne fait rien.
 *  En effet on veut autoriser les grains de sable à pouvoir dégringoler, ce qui
 *  veut dire que l'on ne doit pas rendre inactif le grain de sable qui est tout
 *  en haut.
 *  Si la particule est propagative alors il faut l'arreter.
 *  En effet il faut bien que la transition se termine.
 ******************************************************************************/
void Particule::tuBougesPas()
{
  if (getPhase()->getPropagatif() == true )
    setActivite(false);


}

  



//******************************************************************************
/** Description.
 *  Méthode utilisée pour pouvoir debugger le code.
 ******************************************************************************/
void Particule::afficheur() const
{
  cerr << "----------- Particule --------------" << endl;

  cerr << "Numero : " << _numero << endl ;

  cerr << "Direction Courante : ";
  
  _requeteCourante.afficheur();

  cerr << endl;
  

  cerr << "Activite : " << _activite << endl;


  cerr << "Liee a Phase : " << endl; 
  if (_phase == NULL) 
    cerr << "WARNING: pointeur null a la place d'un pointeur vers une Phase " << endl ;
  else _phase->afficheurReduit();

  cerr << "Liee a Cellule : " << endl; 
  if (_cellule == NULL) 
    cerr << "WARNING: pointeur null a la place d'un pointeur vers une Cellule " << endl;
  else _cellule->afficheurReduit();

  
  cerr << "Couleur (ajout) : " << _couleur << endl;


}
//******************************************************************************
/** Description.
 *  
 ******************************************************************************/

void Particule::afficheurReduit() const
{
  cerr << "----------- Particule --------------" << endl;

  cerr << "Numero : " << _numero << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Méthodes privées
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//******************************************************************************
/** Description.
 *  L'algorithme est simple : on favorise simplement
 *  la direction que la particule avait à l'étape précédente
 *  en multipliant le module de l'objet p par le facteur inertiel de la phase
 *  de la particule et en ajoutant cette valeur à l'ancienne probabilité
 *  pour la direction considérée.
 *  \param  p la pondération de départ.
 ******************************************************************************/
void Particule::appliquerCritereInertiel(Ponderation * p) const
{
  if (getRequeteCourante() != Requete(RIEN))
    {
      int inertie = getPhase()->getInertie();
      if (inertie != 0)
	{
	  Ponderation np;
	  np.setPonderation(Direction(getRequeteCourante()), inertie * p->getModule());
	  *p += np;
	}
    }
}

//******************************************************************************
/** Description.
 *  Voici l'algorithme :
 *  pour chaque règle de la liste
 *     pour chaque rotation de la règle (6 rotations)
 *       si la règle peut s'appliquer à la situation
 *             alors pour chaque direction impossible de la règle
 *                     mettre à zéro la probabilité de déplacement pour
 *                     la direction considérée dans l'objet pondération.
 *  retourner la pondération modifiée.
 *
 *  \param ponderation la pondération de départ.
 *  \param regles_exclusion une liste de règles d'exclusion.
 *  \return l'objet pondération modifié.
 *
 *  \sa RegleExclusion
 ******************************************************************************/


// Algo modifie par gc, a VALIDER
void Particule::appliquerExclusions(Ponderation * ponderation, list<RegleExclusion*> *regles_exclusion) const
{
  RegleExclusion* regle;

  // pour chaque regle d'exclusion
  for (list<RegleExclusion*>::iterator it = regles_exclusion->begin() ; it != regles_exclusion->end(); it++)
    {
      regle = *it;
	    
      // pour chaque rotation de la regle
      for (int j = 0; j<VALENCE; j++)
	{
	  regle->rotation(j);
	
	  if (verifieExclusion(regle))
	    
	    // pour chaque direction impossible
	    for (int i = 0; i<VALENCE; i++)
	    {
	      if (regle->getDeplacement(Direction(i)) == RegleExclusion::DEPLIMPOSSIBLE)
		ponderation->setPonderation(Direction(i),0); // on a un deplacement impossible
	    }
	}
    }
}

//******************************************************************************
/** Description.
 *  Vérifie si le motif correspond à la situation. Par exemple si la règle
 *  contient une contrainte PHIINFSOLIDE pour la direction NORD
 *  et si la particule au nord est de type fluide alors on retourne
 *  faux.
 *  \sa RegleExclusion
 ******************************************************************************/


bool Particule::verifieExclusion(RegleExclusion* regle) const
{
  Cellule* voisin;
  bool condition_respecte = true;

  for (int i=0; i< VALENCE; i++)
    {
      voisin = getCellule()->getVoisin(Direction(i));
      
      switch(regle->getContrainte(Direction(i)))
	{
	case RegleExclusion::CONTRAINTE_NULLE:
	  break;
	case RegleExclusion::CONTRAINTE_MEMEPHI:
	  if (getPhase()->getPhi() != voisin->getPhiParticule())
	    condition_respecte = false;
	  break;
	case RegleExclusion::CONTRAINTE_PHIINFERIEUR:
	  if (voisin->getPhiParticule() > getPhase()->getPhi())
	    condition_respecte = false;
	  break;
	case RegleExclusion::CONTRAINTE_PHIINFSOLIDE:
	  if (voisin->getPhiParticule() > PHI_SOLIDE) 
	    condition_respecte = false;
	  break;
	default:
	  break;
	}
      
    }
  return condition_respecte;
}

//******************************************************************************
/** Description.
 *
 *  > Now talking in #linux-4ever
 *  <eLe3t> QQ'un a pas une @ de warez pour Linux ??
 *  <Ph3aR> Hey je croyais que tout etait gratuit sous Linux ?
 *  <eLe3t> M'en fous moi file moi une url #@$#$@# !
 ******************************************************************************/

void Particule::elireRequete(Ponderation * ponderation) const
{
  int temp;
  double res_random;
  int somme = 0;

  temp = ponderation->getModule();

  if (temp == 0)
    // on a tout a zero on renvoie une ponderation avec tout a zero
    {
      for (int i = 0; i < VALENCE; i++)
	ponderation->setPonderation(Direction(i),0);
      //      
      //      ca pouvait faire de serieux effets bizarres ca
      //      car le pointeur nous est passe dans la pile (par valeur)
      //      -> recopie -> en sortie c'est plus le meme
      //      il se trouve que ca marche kan meme car on fait
      //      un delete puis un new qui realloue au meme endroit
      //      delete(ponderation);
      //      ponderation = new Ponderation();
      return;
    }                        


  res_random = (double(rand())*temp)/RAND_MAX;

  for (int i = 0; i< VALENCE; i++)
    {
      if ((res_random >= somme) &&
          (res_random <= (somme + ponderation->getPonderation(Direction(i)))))
	             // gc: remplace < par <= parce que sinon on atteint l'exception quelquefois
	{
	  for (int j = 0; j < VALENCE; j++)
	    ponderation->setPonderation(Direction(j),0);

	  ponderation->setPonderation(Direction(i),1);
	  return;
      }
      somme += ponderation->getPonderation(Direction(i));
    }
  // yp: si j'atteint cette ligne c'est que y'a une erreur TODO TOSEE
  // gc: normalement avec la modif on l'atteint plus jamais
  throw Exception("Particule::elireRequete() : probleme de generation aleatoire");
}

