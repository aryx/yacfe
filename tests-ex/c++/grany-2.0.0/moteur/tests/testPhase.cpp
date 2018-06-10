/******************************************************************************* 
 * $Id: testPhase.cpp,v 1.7 1999/06/14 12:53:14 ypadiole Exp $
 * 
 *******************************************************************************/

#include "Phase.h"

#include <iostream>


int main()
{

  cout << "[TEST************] Constructeur \n";

  // construction de l'objet Ponderation
  int mes_vals[6] = {10,11,12,13,14,15};
  Ponderation ma_ponderation = Ponderation(mes_vals);

  
  // construction de l'objet list<RegleEtMode>
  list<Phase::RegleEtMode> mes_regles_et_modes;

  RegleExclusion::Paire paires[VALENCE];
  paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
  paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
  paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
  paires[3].contrainte = RegleExclusion::CONTRAINTE_NULLE;
  paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
  paires[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;
  
  
  paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
  paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
  paires[2].deplacement = RegleExclusion::DEPLPOSSIBLE;
  paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
  paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
  paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

  
    
  RegleExclusion * ma_premiere_regle = new RegleExclusion("Ma premiere regle",
							  paires);




  RegleExclusion::Paire paires2[VALENCE];
  paires2[0].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
  paires2[1].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
  paires2[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
  paires2[3].contrainte = RegleExclusion::CONTRAINTE_NULLE;
  paires2[4].contrainte = RegleExclusion::CONTRAINTE_NULLE;
  paires2[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;
  
  
  paires2[0].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
  paires2[1].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
  paires2[2].deplacement = RegleExclusion::DEPLPOSSIBLE;
  paires2[3].deplacement = RegleExclusion::DEPLPOSSIBLE;
  paires2[4].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
  paires2[5].deplacement = RegleExclusion::DEPLIMPOSSIBLE;

  RegleExclusion * ma_deuxieme_regle = new RegleExclusion("Ma deuxieme regle",
							  paires2);


  Phase::RegleEtMode remode;

  remode.regle = ma_premiere_regle;
  remode.mode  = RegleExclusion::PRE;
  
  mes_regles_et_modes.push_back(remode);

  remode.regle = ma_deuxieme_regle;
  remode.mode  = RegleExclusion::POST;

  mes_regles_et_modes.push_back(remode);

  // appel du constructeur
  Phase p("Premiere phase",
	  0.666,
	  true,
	  7,
	  ma_ponderation,
	  mes_regles_et_modes);

  p.afficheur();



//  cout << "\n[TEST************] Operateur = \n";
//
//  Phase p2 = p;
//
//  p2.afficheur();
//
//
//
//  cout << "\n[TEST************] getChose() \n";
//
//  cout << "Nom = " << p.getNom();
//  cout << "\nPhi = " << p.getPhi();
//  cout << "\nPropagatif = " << p.getPropagatif();
//  cout << "\nCouleur (ajout) = " << p.getCouleur();
//  cout << "\nInertie = " << p.getInertie();
//
//  cout << "\nPonderation : \n"; p.getPonderation().afficheur();
//
//  cout << "\nRegles en PREexclusion : \n";
//
//  mes_regles = *(p.getRegleExclusion(RegleExclusion::PRE));
//  list<RegleExclusion*>::iterator it_liste_regles;
//
//  for(it_liste_regles=mes_regles.begin() ; it_liste_regles!=mes_regles.end() ; it_liste_regles++)
//    (*it_liste_regles)->afficheur();
//
//  cout << "\nRegles en POSTexclusion : \n";
//
//  mes_regles = *(p.getRegleExclusion(RegleExclusion::POST));
//
//  for(it_liste_regles=mes_regles.begin() ; it_liste_regles!=mes_regles.end() ; it_liste_regles++)
//    (*it_liste_regles)->afficheur();
//
//
//
//  cout << "\n[TEST************] setChose() \n";
//
//  p.setNom("Nouveau nom");
//  p.setPhi(6.7);
//  p.setPropagatif(false);
//  p.setInertie(12);
//  p.setCouleur(3);
//
//    // test de Phase::setPonderation
//  int mes_nouvelles_vals[6] = {110,111,112,113,114,115};
//  Ponderation ma_nouvelle_ponderation = Ponderation(mes_nouvelles_vals);
//  p.setPonderation(ma_nouvelle_ponderation);
//
//    // test de Phase::setRegleExclusion
//  list<RegleExclusion*> mes_nouvelles_regles;
//
//
//
//  RegleExclusion::Paire paires3[VALENCE];
//  paires3[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//  paires3[1].contrainte = RegleExclusion::CONTRAINTE_NULLE; 
//  paires3[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
//  paires3[3].contrainte = RegleExclusion::CONTRAINTE_NULLE; 
//  paires3[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
//  paires3[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//
//
//  paires3[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires3[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires3[2].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires3[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
//  paires3[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires3[5].deplacement = RegleExclusion::DEPLPOSSIBLE;
//
//  
//  RegleExclusion * ma_nouvelle_premiere_regle = 
//    new RegleExclusion("Ma nouvelle premiere regle",
//			 paires3);
//
//  RegleExclusion::Paire paires4[VALENCE];
//  paires4[0].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
//  paires4[1].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
//  paires4[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
//  paires4[3].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//  paires4[4].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//  paires4[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;
//
//
//  paires4[0].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
//  paires4[1].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
//  paires4[2].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires4[3].deplacement = RegleExclusion::DEPLPOSSIBLE;
//  paires4[4].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
//  paires4[5].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
//
//  RegleExclusion * ma_nouvelle_deuxieme_regle = 
//    new RegleExclusion("Ma nouvelle deuxieme regle",paire4);
//
//
//
//  remode.regle = ma_nouvelle_premiere_regle;
//  remode.mode  = RegleEtMode::PRE;
//  
//  mes_regles_et_modes.push_back(remode);
//
//  remode.regle = ma_deuxieme_regle;
//  remode.mode  = RegleEtMode::PRE;
//
//  mes_nouvelles_regles.push_back();
//  mes_nouvelles_regles.push_back(ma_nouvelle_deuxieme_regle);
//
//
//  p.setRegleExclusion(mes_nouvelles_regles, mes_nouveaux_modes);
//
//
//    // Phase::ajoutRegle
//  RegleExclusion::Contrainte tab_contr_nouv[VALENCE] =
//  { 
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_PHIINFERIEUR,
//    RegleExclusion::CONTRAINTE_NULLE, 
//  };
//  RegleExclusion::Deplacement tab_depl_nouv[VALENCE] =
//  {
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//    RegleExclusion::DEPLIMPOSSIBLE,
//  };
//
//  RegleExclusion * ma_nouvelle_regle = new RegleExclusion("Ma nouvelle regle",
//							    tab_depl_nouv,
//							    tab_contr_nouv);
//  p.ajoutRegle(ma_nouvelle_regle, RegleExclusion::POST);
//
//
//  p.afficheur();

  return 0;
}
