
#include "PlanHexagonalX11.h"


//#include "Rectangle.h"
//#include "Ellipse.h"
//#include "Ligne.h"
//#include "ArcEllipse.h"
//#include <list>
//#include "Polygone.h"
//#include "Frontiere.h"
//#include <vector>
//#include <iostream.h>
//#include "Zonage.h"
//#include "Coloration.h"
//#include "Phase.h"
//#include "ContientHorsScene.h"
//#include "ContientPhase.h"
//
///*
//#include "Phase.h"
//#include "Zonage.h"
//#include "Coloration.h"
//*/
//
//#include "Couleur.h"



int main()
{

 
  list<Frontiere *> frt ;
  list<Zonage *> zon ;
  vector<PhasePourcent> pp ;
  list<Coloration *> col ;
  list<RegleExclusion*> lregle;
  list<Phase*> lphase;
  list<Couleur*> lcoul;

  Forme * form = new Rectangle(25,25,50,50);


  frt.push_back(new Frontiere(form,Frontiere::CLASSIQUE)) ;

  form = new ArcEllipse(10,10,6,6,5,5,16,16) ;
  frt.push_back(new Frontiere(form,Frontiere::CLASSIQUE)) ;

  Polygone * poly = new Polygone() ;
  poly->ajoutLigne(new Ligne(20,30,100,100)) ;
  poly->ajoutLigne(new Ligne(100,100,0,100)) ;
  poly->ajoutLigne(new Ligne(0,100,20,30)) ;

  frt.push_back(new Frontiere(poly,Frontiere::CLASSIQUE)) ;

  /*
    cout << "murf c pourri le c++" << endl;
  */
  //zon.push_back(new Zonage(new Rectangle(20,20,50,50),new ContientHorsScene())) ;


  /*
    Polygone * poly = new Polygone() ;
    poly->ajouteLignePolygone(Ligne(10,20,50,50)) ;
    poly->ajouteLignePolygone(Ligne(50,50,50,100)) ;
    poly->ajouteLignePolygone(Ligne(50,100,20,20)) ;

    zon.push_back(new Zonage(poly,new ContientHorsScene())) ;

    delete poly ;

  */


  int mes_vals[6] = {10,11,12,13,14,15};
  Ponderation ma_ponderation = Ponderation(mes_vals);

  
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


  RegleExclusion * regle1 = new RegleExclusion("Regle1 (Exclusion frontale)",
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


  RegleExclusion * regle2 = new RegleExclusion("Regle2 (Exclusion isophase)",
					       paires2);


  lregle.push_back(regle1);
  lregle.push_back(regle2);


  Phase* p = new Phase("eau",
		       0.666,
		       true,
		       7,
		       ma_ponderation);
  p->ajoutPaire(regle1, RegleExclusion::PRE);
  p->ajoutPaire(regle2, RegleExclusion::POST);


  Phase* p2 = new Phase("sable",
			0.666,
			true,
			7,
			ma_ponderation);

  p2->ajoutPaire(regle1, RegleExclusion::PRE);
  p2->ajoutPaire(regle2, RegleExclusion::POST);

  lphase.push_back(p);
  lphase.push_back(p2);


  PhasePourcent elpp;
  elpp.phase = p;
  elpp.pourcentage = 50;
  
  pp.push_back(elpp) ;

  elpp.phase = p2;
  elpp.pourcentage = 50;


  pp.push_back(elpp) ;
  zon.push_back(new Zonage(new Rectangle(0,0,300,300),new ContientPhase(pp))) ;

  Polygone * poly2 = new Polygone() ;
  poly2->ajoutLigne(new Ligne(20,30,100,100)) ;
  poly2->ajoutLigne(new Ligne(100,100,0,100)) ;
  poly2->ajoutLigne(new Ligne(0,100,20,30)) ;
 
  
  zon.push_back(new Zonage(poly2, new ContientPhase(pp)));
  //  zon.push_back(new Zonage(poly2, new ContientHorsScene()));

  //col.push_back(new Coloration(new Rectangle(50,50,100,100),123)) ;
  Scene sc(frt,lregle,lcoul,lphase,zon,col);

  //PlanHexagonal planHexagonal(50,minx,miny,maxx,maxy) ;

  cout << "AvantAvant\n";


  PlanHexagonalX11 plan(50,sc);
  
  cout << "Avant\n";

  plan.afficheEcran();

  cout << "Apres\n";


  /*
    int dim,minX,minY,maxX,maxY ;

    cout <<"Ajout regle a la scene \n";
    ptrScene->ajouteRegleExclusion(ma_deuxieme_regle);
    ptrScene->ajouteRegleExclusion(ma_premiere_regle);

    while(1)
    {
    cout << "dim : " ; cin >> dim ;
    cout << "minX : " ; cin >> minX ;
    cout << "minY : " ; cin >> minY ;
    cout << "maxX : " ; cin >> maxX ;
    cout << "maxY : " ; cin >> maxY ;
    
    
    PlanHexagonal planHexagonal(dim,minX,minY,maxX,maxY) ;
    

    int x,y ;
    
    int X,Y ;
    cout << "X : " ; cin >> X ;
    cout << "Y : " ; cin >> Y ;
    
    planHexagonal.coordonneeVectorielVersBitmap(X,Y,x,y) ;
    
    cout << x << " " << y << endl ;
    }
  */

}
