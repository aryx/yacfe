/*******************************************************************************
 *  $Id: testAutomate2.cpp,v 1.2 1999/06/14 12:53:11 ypadiole Exp $
 *
 *******************************************************************************/

#include "Automate.h"
#include "CelluleAvecParticule.h"
#include "CelluleGeneratrice.h"
#include "CelluleParoi.h"
#include "CelluleHorsScene.h"

#include <time.h>
// #include <iostream.h>


///* Bon c'est pas beau mais c'est pour tester */
//
//Phase * phase1;
//Phase * phase2;
//
//RegleExclusion * regle1;
//RegleExclusion * regle2;
//RegleExclusion * regle3;
//RegleExclusion * regle4;
//
//
//void construitRegles()
//{
//
//  RegleExclusion::Contrainte tab_contr1[VALENCE] =
//  { 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_PHIINFSOLIDE,
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_NULLE
//  };
//
//  RegleExclusion::Deplacement tab_depl1[VALENCE] =
//  {
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE
//  };
//
//  regle1 = new RegleExclusion("Regle1 (Exclusion frontale)",
//				tab_depl1, 
//				tab_contr1);
//
//
//  RegleExclusion::Contrainte tab_contr2[VALENCE] =
//  { 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_MEMEPHI,
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_NULLE
//  };
//
//  RegleExclusion::Deplacement tab_depl2[VALENCE] =
//  {
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE
//  };
//
//  regle2 = new RegleExclusion("Regle2 (Exclusion isophase)",
//				tab_depl2, 
//				tab_contr2);
//
//  
//  RegleExclusion::Contrainte tab_contr3[VALENCE] =
//  { 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_NULLE
//  };
//
//  RegleExclusion::Deplacement tab_depl3[VALENCE] =
//  {
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE
//  };
//
//  regle3 = new RegleExclusion("Regle3 (Exclusion intersticielle)",
//				tab_depl3, 
//				tab_contr3);
//
//
//  RegleExclusion::Contrainte tab_contr4[VALENCE] =
//  { 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_NULLE, 
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_NULLE
//  };
//
//  RegleExclusion::Deplacement tab_depl4[VALENCE] =
//  {
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE
//  };
//
//  regle4 = new RegleExclusion("Regle4 (Exclusion constrictive)",
//				tab_depl4, 
//				tab_contr4);
//
//
//}
//
//
//
//void construitPhases()
//{
//
//  // ** Premiere phase : genre grain de sable
//
//    // construction de l'objet Ponderation
//  int mes_vals[6] = {0,0,1,3,1,0};
//  Ponderation ma_ponderation = Ponderation(mes_vals);
//
//    // construction de l'objet list<RegleExclusion*>
//  list<RegleExclusion*> mes_regles;
//
//  mes_regles.push_back(regle1);
//  mes_regles.push_back(regle2);
//  mes_regles.push_back(regle3);
//
//
//    // construction de l'objet list<RegleExclusion::ModeExclusion>
//  list<RegleExclusion::ModeExclusion> mes_modes;
//  
//  mes_modes.push_back(RegleExclusion::PRE);
//  mes_modes.push_back(RegleExclusion::PRE);
//  mes_modes.push_back(RegleExclusion::POST);
//
//
//    // appel du constructeur
//  phase1 = new Phase("Premiere phase (genre sable)",
//		       0.2,
//		       false,
//		       1,
//		       ma_ponderation,
//		       mes_regles,
//		       mes_modes);
//
//
//
//  // ** Deuxieme phase : genre vide
//
//    // construction de l'objet Ponderation
//  int mes_vals2[6] = {2,1,0,0,0,1};
//  Ponderation ma_ponderation2 = Ponderation(mes_vals2);
//
//    // construction de l'objet list<RegleExclusion*>
//  list<RegleExclusion*> mes_regles2;
//
//    // construction de l'objet list<RegleExclusion::ModeExclusion>
//  list<RegleExclusion::ModeExclusion> mes_modes2;
//  
//  // NB : Pas de regles d'exclusion sur le vide
//
//    // appel du constructeur
//  phase2 = new Phase("Deuxieme phase (genre vide)",
//		       0.7,
//		       true,
//		       //		     false,
//		       0,
//		       ma_ponderation2,
//		       mes_regles2,
//		       mes_modes2);
//
//
//}
//
//
//
//
//
//  CelluleAvecParticule * ma_cellule_particule;
//  CelluleParoi * ma_cellule_paroi;
//  Particule * ma_particule;
//  ParticulePropagative * ma_particule_propag;
//
//
//void creeCelluleParoi(Automate * mon_automate)
//{
//  ma_cellule_paroi = new CelluleParoi();
//  mon_automate->ajoutCellule(ma_cellule_paroi);
//}
//
//void creeCellulePhase1(Automate * mon_automate, int i)
//{
//  ma_particule = new Particule(i,
//				 phase1,
//				 NULL, // on n'a pas encore cree la cellule
//				 RIEN,
//				 false);
//  
//  ma_cellule_particule = new CelluleAvecParticule(ma_particule);
//  
//  ma_particule->setCellule(ma_cellule_particule);
//  
//  mon_automate->ajoutCellule(ma_cellule_particule);
//  mon_automate->ajoutParticule(ma_particule);
//}
//
//void creeCellulePhase2(Automate * mon_automate, int i)
//{
////  ma_particule_propag = new ParticulePropagative(i,
////						   phase2,
////						   NULL, // on n'a pas encore cree la cellule
////						   RIEN,
////						   false);
////  
//
//  ma_particule_propag = new ParticulePropagative(i,
//						     phase2,
//						     NULL, // on n'a pas encore cree la cellule
//						     RIEN,
//						     false);
//  
//  ma_cellule_particule = new CelluleAvecParticule(ma_particule_propag);
//
//  ma_particule_propag->setCellule(ma_cellule_particule);
//
//  mon_automate->ajoutCellule(ma_cellule_particule);
//  mon_automate->ajoutParticulePropagative(ma_particule_propag);
//  // mon_automate->ajoutParticule(ma_particule_propag);
//}
//
//void timing(Automate * automate)
//{
//  for (int i=0 ; i<9000 ; i++)
//    automate->genereTransition();
//}


int main()
{
//  Automate* _automate;
//
//  construitRegles();
//  construitPhases();
//
//  int v = 1; // indice que j'utilise pour generer les numeros des particules
//
//  int d = 6; // cote de mon reseau
//
//  _automate = new Automate(time(NULL), d); // germe : system-time
//
//
//  _automate->ajoutPhase(phase1);
//  _automate->ajoutPhase(phase2);
//
//
//  for (int i = 0 ; i<d ; i++)
//    creeCelluleParoi(_automate);
//
//  for (int j = 1 ; j<(d/2) ; j++)
//    {
//	creeCelluleParoi(_automate);
//	cout << "ligne paroi ";
//	for (int i = 1 ; i<(d-1) ; i++)
//	  {
//	    creeCellulePhase1(_automate,v);
//	    cout << " phase1 ";
//	    v++;
//	  }
//	cout << " fin ligne paroi" << endl;
//	creeCelluleParoi(_automate);
//    }
//
//  for (int j = (d/2) ; j<(d-1) ; j++)
//    {
//	creeCelluleParoi(_automate);
//	cout << "ligne paroi ";
//	for (int i = 1 ; i<(d-1) ; i++)
//	  {
//	    creeCellulePhase2(_automate,v);
//	    cout << " phase2 ";
//	    v++;
//	  }
//	cout << " fin ligne paroi" << endl;
//	creeCelluleParoi(_automate);
//    }
//
//  for (int i = 0 ; i<d ; i++)
//    creeCelluleParoi(_automate);
//
//  _automate->connecteCellules();
//
//
//  for (;;)
//    {
//	string j;
//
//	_automate->afficheurReseau();
//
//	_automate->genereTransition();
//
//	cin >> j;
//    }

  return 0;
}
