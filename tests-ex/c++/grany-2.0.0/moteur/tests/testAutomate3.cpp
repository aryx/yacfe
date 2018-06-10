/*******************************************************************************
 *  $Id: testAutomate.cpp,v 1.18 1999/06/14 12:53:10 ypadiole Exp $
 *
 *******************************************************************************/

#include "Automate.h"
#include "CelluleAvecParticule.h"
#include "CelluleGeneratrice.h"
#include "CelluleParoi.h"
#include "CelluleHorsScene.h"

#include <time.h>
// #include <iostream.h>


/* Bon c'est pas beau mais c'est pour tester */

Phase * phase1;
Phase * phase2;

RegleExclusion * regle1;
RegleExclusion * regle2;
RegleExclusion * regle3;
RegleExclusion * regle4;


void construitRegles()
{

    RegleExclusion::Paire paires[VALENCE];
    paires[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;        
    paires[2].contrainte = RegleExclusion::CONTRAINTE_NULLE;        
    paires[3].contrainte = RegleExclusion::CONTRAINTE_PHIINFSOLIDE; 
    paires[4].contrainte = RegleExclusion::CONTRAINTE_NULLE; 
    paires[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    

    paires[0].deplacement = RegleExclusion::DEPLPOSSIBLE; 
    paires[1].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires[2].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires[4].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires[5].deplacement = RegleExclusion::DEPLPOSSIBLE;   


      regle1 = new RegleExclusion("Regle1 (Exclusion frontale)",
				  paires);

    RegleExclusion::Paire paires2[VALENCE];
    paires2[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires2[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;        
    paires2[2].contrainte = RegleExclusion::CONTRAINTE_NULLE;        
    paires2[3].contrainte = RegleExclusion::CONTRAINTE_MEMEPHI; 
    paires2[4].contrainte = RegleExclusion::CONTRAINTE_NULLE; 
    paires2[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;


    paires2[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires2[1].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires2[2].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires2[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires2[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires2[5].deplacement = RegleExclusion::DEPLPOSSIBLE;  


    regle2 = new RegleExclusion("Regle2 (Exclusion isophase)",
				paires2);

    RegleExclusion::Paire paires3[VALENCE];
    paires3[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires3[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;        
    paires3[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;        
    paires3[3].contrainte = RegleExclusion::CONTRAINTE_NULLE; 
    paires3[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR; 
    paires3[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;


    paires3[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires3[1].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires3[2].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires3[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires3[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires3[5].deplacement = RegleExclusion::DEPLPOSSIBLE;  


    regle3 = new RegleExclusion("Regle3 (Exclusion intersticielle)",
				paires);


    RegleExclusion::Paire paires4[VALENCE];
    paires4[0].contrainte = RegleExclusion::CONTRAINTE_NULLE;
    paires4[1].contrainte = RegleExclusion::CONTRAINTE_NULLE;        
    paires4[2].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR;        
    paires4[3].contrainte = RegleExclusion::CONTRAINTE_NULLE; 
    paires4[4].contrainte = RegleExclusion::CONTRAINTE_PHIINFERIEUR; 
    paires4[5].contrainte = RegleExclusion::CONTRAINTE_NULLE;


    paires4[0].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires4[1].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires4[2].deplacement = RegleExclusion::DEPLPOSSIBLE;  
    paires4[3].deplacement = RegleExclusion::DEPLIMPOSSIBLE;
    paires4[4].deplacement = RegleExclusion::DEPLPOSSIBLE;
    paires4[5].deplacement = RegleExclusion::DEPLPOSSIBLE;  


    regle4 = new RegleExclusion("Regle4 (Exclusion constrictive)",
				paires4);


}



void construitPhases()
{

  // ** Premiere phase : genre grain de sable

    // construction de l'objet Ponderation
  int mes_vals[6] = {0,0,1,3,1,0};
  Ponderation ma_ponderation = Ponderation(mes_vals);


    // appel du constructeur
  phase1 = new Phase("Premiere phase (genre sable)",
		       0.2,
		       false,
		       1,
		       ma_ponderation);

  phase1->ajoutPaire(regle1, RegleExclusion::PRE);
  phase1->ajoutPaire(regle2, RegleExclusion::PRE);
  phase1->ajoutPaire(regle3, RegleExclusion::POST);



  // ** Deuxieme phase : genre vide

    // construction de l'objet Ponderation
  int mes_vals2[6] = {2,1,0,0,0,1};
  Ponderation ma_ponderation2 = Ponderation(mes_vals2);

  // NB : Pas de regles d'exclusion sur le vide

    // appel du constructeur
  phase2 = new Phase("Deuxieme phase (genre vide)",
		       0.7,
		       true,
		       0,
		       ma_ponderation2);
  

}





  CelluleAvecParticule * ma_cellule_particule;
  CelluleParoi * ma_cellule_paroi;
  Particule * ma_particule;
  Particule * ma_particule_propag;


void creeCelluleParoi(Automate * mon_automate)
{
  ma_cellule_paroi = new CelluleParoi();
  mon_automate->ajoutCellule(ma_cellule_paroi);
}

void creeCellulePhase1(Automate * mon_automate, int i)
{
  ma_particule = new Particule(i,
				 phase1,
				 NULL, // on n'a pas encore cree la cellule
				 RIEN,
				 false);
  
  ma_cellule_particule = new CelluleAvecParticule(ma_particule);
  
  ma_particule->setCellule(ma_cellule_particule);
  
  mon_automate->ajoutCellule(ma_cellule_particule);
  mon_automate->ajoutParticule(ma_particule);
}

void creeCellulePhase2(Automate * mon_automate, int i)
{
//  ma_particule_propag = new ParticulePropagative(i,
//						   phase2,
//						   NULL, // on n'a pas encore cree la cellule
//						   RIEN,
//						   false);
//  

  ma_particule_propag = new Particule(i,
						     phase2,
						     NULL, // on n'a pas encore cree la cellule
						     RIEN,
						     false);
  
  ma_cellule_particule = new CelluleAvecParticule(ma_particule_propag);

  ma_particule_propag->setCellule(ma_cellule_particule);

  mon_automate->ajoutCellule(ma_cellule_particule);
  mon_automate->ajoutParticule(ma_particule_propag);
  // mon_automate->ajoutParticule(ma_particule_propag);
}

void creeCelluleGen(Automate * mon_automate, int i)
{

  ma_particule_propag = new Particule(i,
						     phase2,
						     NULL, // on n'a pas encore cree la cellule
						     RIEN,
						     false);
  
  ma_cellule_particule = new CelluleGeneratrice(ma_particule_propag,phase1);

  ma_particule_propag->setCellule(ma_cellule_particule);

  mon_automate->ajoutCellule(ma_cellule_particule);
  mon_automate->ajoutParticule(ma_particule_propag);
  // mon_automate->ajoutParticule(ma_particule_propag);
}


void timing(Automate * automate)
{
  for (int i=0 ; i<90 ; i++)
    automate->genereTransition();
}


int main()
{

  construitRegles();
  construitPhases();

  int mon_germe;

  // cin >> mon_germe;
  mon_germe = time(NULL);

  cout << "Germe utilise : " << mon_germe << endl;

  Automate* mon_automate = new Automate(mon_germe,6);

  mon_automate->ajoutRegle(regle1);
  mon_automate->ajoutRegle(regle2);
  mon_automate->ajoutRegle(regle3);
  mon_automate->ajoutRegle(regle4);
  /* On va faire

   P)aroi
   S)able
   V)ide
		    P
		 P
	      P     P
	   P     S
	P     S     P
   P     S     S  
	S     S     P
   P     S     V  
	S     V     P
   P     V     V
	V     V     P
   P     V     P
	V     P
   P     P
	P
   P 

   */

  mon_automate->ajoutPhase(phase1);
  mon_automate->ajoutPhase(phase2);



  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);

  creeCelluleParoi(mon_automate);
  creeCellulePhase1(mon_automate,1);
  creeCellulePhase1(mon_automate,2);
  creeCelluleGen(mon_automate,3);
  creeCellulePhase1(mon_automate,4);
  creeCelluleParoi(mon_automate);

  creeCelluleParoi(mon_automate);
  creeCellulePhase1(mon_automate,5);
  creeCellulePhase1(mon_automate,6);
  creeCellulePhase1(mon_automate,7);
  creeCellulePhase1(mon_automate,8);
  creeCelluleParoi(mon_automate);

  creeCelluleParoi(mon_automate);
  creeCellulePhase2(mon_automate,9);
  creeCellulePhase2(mon_automate,10);
  creeCellulePhase2(mon_automate,11);
  creeCellulePhase2(mon_automate,12);
  creeCelluleParoi(mon_automate);

  creeCelluleParoi(mon_automate);
  creeCellulePhase2(mon_automate,13);
  creeCellulePhase2(mon_automate,14);
  creeCellulePhase2(mon_automate,15);
  creeCelluleGen(mon_automate,16);
  creeCelluleParoi(mon_automate);

  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);
  creeCelluleParoi(mon_automate);

  mon_automate->connecteCellules();

  mon_automate->afficheurReseau();
  timing(mon_automate); 
  mon_automate->afficheurReseau();


  delete mon_automate;

  return 0;

}
