/*******************************************************************************
 * $Id: testParticule.cpp,v 1.6 1999/06/14 12:53:13 ypadiole Exp $
 *
 *******************************************************************************/
#include "Particule.h"
#include "Phase.h"
#include "CelluleAvecParticule.h"

#include <iostream>

int main()
{

//  cout << "[TEST*******] Constructeur avec phase et cellule a NULL\n";
//
//
//  Particule part1 = Particule(5, NULL, NULL, RIEN, false);
//  
//  part1.afficheur();
//
//
//
//  cout << "\n[TEST******] Constructeur avec une phase et une cellule\n";
//
//
//  // ------ construction de la phase ; repris de testPhase.cpp --------
//
//    // construction de l'objet Ponderation
//  int mes_vals[6] = {10,11,12,13,14,15};
//  Ponderation ma_ponderation = Ponderation(mes_vals);
//
//  // construction de l'objet list<RegleEtMode>
//  list<Phase::RegleEtMode> mes_regles_et_modes;
//
//  RegleExclusion::Paire paires[VALENCE];
//  paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//  paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//  paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
//  paires[3].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//  paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
//  paires[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//  
//  
//  paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires[2].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
//  paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;
//
//  
//    
//  RegleExclusion * ma_premiere_regle = new RegleExclusion("Ma premiere regle",
//							    paires);
//
//  
//
//  RegleExclusion::Contrainte tab_contr2[VALENCE] =
//  { 
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_NULLE,
//    RegleExclusion::CONTRAINTE_NULLE
//  };
//  RegleExclusion::Deplacement tab_depl2[VALENCE] =
//  {
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//  };
//
//  RegleExclusion * ma_deuxieme_regle = new RegleExclusion("Ma deuxieme regle",
//							    tab_depl2, 
//							    tab_contr2);
//
//  mes_regles.push_back(ma_premiere_regle);
//  mes_regles.push_back(ma_deuxieme_regle);
//
//
//    // construction de l'objet list<RegleExclusion::ModeExclusion>
//  list<RegleExclusion::ModeExclusion> mes_modes;
//  
//  mes_modes.push_back(RegleExclusion::PRE);
//  mes_modes.push_back(RegleExclusion::POST);
//
//
//    // appel du constructeur de la phase
//  Phase * ma_phase = new Phase("Premiere phase",
//				 0.666,
//				 true,
//				 7,
//				 ma_ponderation,
//				 mes_regles,
//				 mes_modes);
//
//
//    // construction d'une CelluleAvecParticule
//  CelluleAvecParticule * ma_cellule = new CelluleAvecParticule(NULL);
//  ma_cellule->setNumero(17);
//
//  Particule part2 = Particule(7, ma_phase, ma_cellule, RIEN, true);
//
//  part2.afficheur();
//
//
//
//  cout << "\n[TEST************] Operateur = \n";
//
//  Particule part3 = part2;
//
//  part3.afficheur();
//
//
//
//  cout << "\n[TEST************] getChose() \n";
//
//  cout << "Numero = " << part3.getNumero();
//  cout << "\nPhase = "; part3.getPhase()->afficheurReduit();
//  cout << "CelluleAvecParticule = "; part3.getCellule()->afficheurReduit();
//  cout << "Requete = "; part3.getRequeteCourante().afficheur();
//  cout << "\nActivite = " << part3.getActivite();
//  cout << "\nCouleur (ajout) = " << part3.getCouleur();
//
//
//
//  cout << "\n\n[TEST************] setChose() \n";
//
//
//  Particule part4 = Particule(0, NULL, NULL, RIEN, false);
//  
//  part4.setNumero(1);
//  part4.setPhase(ma_phase);
//  part4.setCellule(ma_cellule);
//  part4.setRequeteCourante(NORD);
//  part4.setActivite(true);
//  // part4.setCouleur(7);   bon la il faut mettre une couleur c'est chiant
//
//  part4.afficheur();
//
//
//  cout << "\n[TEST************] calculerRequete() \n";
//
//  cout << "on ne peut tester que si on a un voisinage... cf. testAutomate\n";
//
//
//  cout << "\n[TEST************] ParticuleException() \n";
//
//  // gc: On ne peut pas tester ces deux-la a la fois puisque ca fait vautrer le prog... ;)
//  part1.getCellule()->afficheurReduit();
//  part1.getPhase()->afficheurReduit();
//
//
//  return 0;
}
