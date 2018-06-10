/*******************************************************************************
 * $Id: testRegleExclusion.cpp,v 1.9 1999/06/14 12:53:16 ypadiole Exp $
 *
 ******************************************************************************/

#include "RegleExclusion.h"

#include "testCommun.h"


int main()
{

  int i;

  cout << "Starting testRegleExclusion" << endl;


  //******************************************************************************
  cin >> i;

  {
    testFeature("constructeur avec arguments");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);
    
    re.afficheur();

    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;


  }

  //******************************************************************************
  cin >> i;

  {

    testFeature("methode setNom");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);

    re.setNom("Ma vrai premiere regle");
    
    re.afficheur();

    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma vrai premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;




  }


  //******************************************************************************
  cin >> i;

  {

    testFeature("methode getNom");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);

    re.setNom("Ma vrai premiere regle");
    
    re.afficheur();

    cout << re.getNom() << endl;

    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma vrai premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;

    cout << "Ma vrai premiere regle" << endl;


  }



  //******************************************************************************
  cin >> i;

  {

    testFeature("methode setContrainte");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);

    re.setContrainte(NORD,RegleExclusion::CONTRAINTE_PHIINFSOLIDE);
    re.setContrainte(NE,RegleExclusion::CONTRAINTE_PHIINFSOLIDE);


    
    re.afficheur();

    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;




  }

  //******************************************************************************
  cin >> i;

  {

    testFeature("methode setDeplacement");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);

    re.setDeplacement(NORD,RegleExclusion::DEPLIMPOSSIBLE);
    re.setDeplacement(NE,RegleExclusion::DEPLIMPOSSIBLE);


    
    re.afficheur();

    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement impossible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement impossible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;




  }




  //******************************************************************************
  cin >> i;

  {
    testFeature("methode getDeplacement");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);

    
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;


    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;

    cout << "Deplacement possible" << endl;
    cout << "Deplacement impossible" << endl;



  }


  //******************************************************************************
  cin >> i;

  {
    testFeature("methode getContrainte");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);
    
    re.afficheur();
    cout << re.getContrainte(NORD) << endl;
    cout << re.getContrainte(SUD) << endl;


    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;

    cout << "Contrainte nulle" << endl;
    cout << "Contrainte meme phi" << endl;



  }
  

  //******************************************************************************
  cin >> i;

  {
    testFeature("la rotation");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);
    
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    re.rotation(0);
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;


    re.rotation(1);
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    re.rotation(2);
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    re.rotation(3);
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    re.rotation(4);
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    re.rotation(5);
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    try {
      re.rotation(6);
      re.afficheur();
      cout << re.getDeplacement(NORD) << endl;
      cout << re.getContrainte(NORD) << endl;
      cout << re.getDeplacement(SUD) << endl;
      cout << re.getContrainte(SUD) << endl;
    }
    catch (RegleExclusion::Exception re)
      {
	cout << "exception catche" << endl;
      }

    try {
      re.rotation(-1);
      re.afficheur();
    }
    catch (RegleExclusion::Exception re)
      {
	cout << "exception catche" << endl;
      }


    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;

    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;
    cout << "Deplacement impossible" << endl;
    cout << "Contrainte meme phi" << endl;

    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;

    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;
    cout << "Deplacement impossible" << endl;
    cout << "Contrainte meme phi" << endl;


    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte NE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SE = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;
    cout << "Valeur de la contrainte NW = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;

    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;
    cout << "Deplacement possible" << endl;
    cout << "Contrainte phi inferieur" << endl;


    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte NE = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;
    cout << "Valeur de la contrainte SW = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NW = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	

    cout << "Deplacement impossible" << endl;
    cout << "Contrainte phi inferieur" << endl;
    cout << "Deplacement possible" << endl;
    cout << "Contrainte phi inferieur phi solide" << endl;

    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte NE = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;
    cout << "Valeur de la contrainte SUD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte SW = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;

    cout << "Deplacement impossible" << endl;
    cout << "Contrainte meme phi" << endl;
    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;

    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NE = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;
    cout << "Valeur de la contrainte SE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;

    cout << "Deplacement possible" << endl;
    cout << "Contrainte phi inferieur" << endl;
    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;

    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte SE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SUD = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;

    cout << "Deplacement possible" << endl;
    cout << "Contrainte phi inferieur phi solide" << endl;
    cout << "Deplacement impossible" << endl;
    cout << "Contrainte phi inferieur" << endl;

    cout <<"[EXCEPTION] mauvaise utilisation de rotation" << endl;
    cout << "exception catche" << endl;

    cout <<"[EXCEPTION] mauvaise utilisation de rotation" << endl;
    cout << "exception catche" << endl;




  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("la rotation + setContrainte et setDeplacement");

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI;
    paires[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    paires[5].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[2].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;

    RegleExclusion re = RegleExclusion("Ma premiere regle",
				       paires);
    
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    re.rotation(3);
    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;


    re.setDeplacement(NORD,RegleExclusion::DEPLIMPOSSIBLE);
    re.setDeplacement(NE,RegleExclusion::DEPLIMPOSSIBLE);
    re.setContrainte(NORD,RegleExclusion::CONTRAINTE_PHIINFSOLIDE);
    re.setContrainte(NE,RegleExclusion::CONTRAINTE_PHIINFSOLIDE);

    re.afficheur();
    cout << re.getDeplacement(NORD) << endl;
    cout << re.getContrainte(NORD) << endl;
    cout << re.getDeplacement(SUD) << endl;
    cout << re.getContrainte(SUD) << endl;

    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;

    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;
    cout << "Deplacement impossible" << endl;
    cout << "Contrainte meme phi" << endl;


    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte meme phi ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte NE = Contrainte phi inferieur ; deplacement = Deplacement possible"		 << endl;
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;
    cout << "Valeur de la contrainte SUD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte SW = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;

    cout << "Deplacement impossible" << endl;
    cout << "Contrainte meme phi" << endl;
    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;

    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur phi solide ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte NE = Contrainte phi inferieur phi solide ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible"  << endl;
    cout << "Valeur de la contrainte SUD = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;
    cout << "Valeur de la contrainte SW = Contrainte nulle ; deplacement = Deplacement possible"			 << endl;	
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur ; deplacement = Deplacement impossible"		 << endl;

    cout << "Deplacement impossible" << endl;
    cout << "Contrainte phi inferieur phi solide" << endl;
    cout << "Deplacement possible" << endl;
    cout << "Contrainte nulle" << endl;




  }

  //******************************************************************************
  cin >> i;

  {

    testFeature("methode ajoutePaire avec deux arguments");

    RegleExclusion re = RegleExclusion("Ma premiere regle");

    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_PHIINFERIEUR);
    re.ajoutPaire(RegleExclusion::DEPLIMPOSSIBLE, RegleExclusion::CONTRAINTE_NULLE);
    re.ajoutPaire(RegleExclusion::DEPLIMPOSSIBLE, RegleExclusion::CONTRAINTE_PHIINFERIEUR);
    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_MEMEPHI);
    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_PHIINFERIEUR);
    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_PHIINFSOLIDE);
    
    re.afficheur();

    valeurAttendue();

    cout <<"----------- Regle d'exclusion  --------------"                                                << endl;
    cout << "Nom : Ma premiere regle"                                                                     << endl; 
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur ; deplacement = Deplacement possible" << endl; 
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement impossible"         << endl; 
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible" << endl; 
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement possible"       << endl;   
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"   << endl;   
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible" << endl;
   


  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("constructeur sans arguments");


    RegleExclusion re = RegleExclusion("Ma premiere regle");
    
    re.afficheur();

    valeurAttendue();

    
    cout << "----------- Regle d'exclusion  --------------"                                                          << endl;
    cout << "Nom : Ma premiere regle"										 << endl;
    cout << "Valeur de la contrainte NORD = Contrainte nulle ; deplacement = Deplacement impossible"			 << endl;
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement impossible"			 << endl;	
    cout << "Valeur de la contrainte SE = Contrainte nulle ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SUD = Contrainte nulle ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte SW = Contrainte nulle ; deplacement = Deplacement impossible"		 << endl;
    cout << "Valeur de la contrainte NW = Contrainte nulle ; deplacement = Deplacement impossible"  << endl;




  }
  //******************************************************************************
  cin >> i;

  {

    testFeature("test d'acces interdit (vieux bug)");

    RegleExclusion re = RegleExclusion("Ma premiere regle");

    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_PHIINFERIEUR);
    re.ajoutPaire(RegleExclusion::DEPLIMPOSSIBLE, RegleExclusion::CONTRAINTE_NULLE);
    re.ajoutPaire(RegleExclusion::DEPLIMPOSSIBLE, RegleExclusion::CONTRAINTE_PHIINFERIEUR);
    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_MEMEPHI);
    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_PHIINFERIEUR);
    re.ajoutPaire(RegleExclusion::DEPLPOSSIBLE,   RegleExclusion::CONTRAINTE_PHIINFSOLIDE);

    // ce test est la car j'avais un bug avant qui faisant que
    // le setDeplacement faisait un acces au dela de ces bornes, dans le tableau de contrainte
    re.setContrainte(Direction(5),RegleExclusion::CONTRAINTE_MEMEPHI);
    re.setDeplacement(Direction(5),RegleExclusion::DEPLIMPOSSIBLE);
    re.afficheur();


    valeurAttendue();

    cout <<"----------- Regle d'exclusion  --------------"                                                << endl;
    cout << "Nom : Ma premiere regle"                                                                     << endl; 
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur ; deplacement = Deplacement possible" << endl; 
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement impossible"         << endl; 
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible" << endl; 
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement possible"       << endl;   
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"   << endl;   
    cout << "Valeur de la contrainte NW = Contrainte meme phi ; deplacement = Deplacement impossible" << endl;
   


  }

  //******************************************************************************
  cin >> i;

  {

    testFeature("methode ajoutePaire avec un argument");

    RegleExclusion re = RegleExclusion("Ma premiere regle");
    RegleExclusion::Paire paire;
    
    paire.deplacement = RegleExclusion::DEPLPOSSIBLE;
    paire.contrainte  = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    re.ajoutPaire(paire);

    paire.deplacement = RegleExclusion::DEPLPOSSIBLE;
    paire.contrainte  = RegleExclusion::CONTRAINTE_NULLE;
    re.ajoutPaire(paire);

    paire.deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paire.contrainte  = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    re.ajoutPaire(paire);

    paire.deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paire.contrainte  = RegleExclusion::CONTRAINTE_MEMEPHI;
    re.ajoutPaire(paire);

    paire.deplacement = RegleExclusion::DEPLPOSSIBLE;
    paire.contrainte  = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
    re.ajoutPaire(paire);

    paire.deplacement = RegleExclusion::DEPLPOSSIBLE;
    paire.contrainte  = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
    re.ajoutPaire(paire);
    
    re.afficheur();

    valeurAttendue();

    cout <<"----------- Regle d'exclusion  --------------"                                                << endl;
    cout << "Nom : Ma premiere regle"                                                                     << endl; 
    cout << "Valeur de la contrainte NORD = Contrainte phi inferieur ; deplacement = Deplacement possible" << endl; 
    cout << "Valeur de la contrainte NE = Contrainte nulle ; deplacement = Deplacement impossible"         << endl; 
    cout << "Valeur de la contrainte SE = Contrainte phi inferieur ; deplacement = Deplacement impossible" << endl; 
    cout << "Valeur de la contrainte SUD = Contrainte meme phi ; deplacement = Deplacement possible"       << endl;   
    cout << "Valeur de la contrainte SW = Contrainte phi inferieur ; deplacement = Deplacement possible"   << endl;   
    cout << "Valeur de la contrainte NW = Contrainte phi inferieur phi solide ; deplacement = Deplacement possible" << endl;
   


  }


}
