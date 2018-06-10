/*******************************************************************************
 * $Id: testPonderation.cpp,v 1.6 1999/06/14 12:53:16 ypadiole Exp $
 *
 *******************************************************************************/

#include "Ponderation.h"

#include "testCommun.h"

int  main()
{
  int i;

  cout << "Starting testPonderation" << endl;
  //******************************************************************************
  cin >> i;

  {
    testFeature("constructeur par defaut");

    Ponderation p;
    p.afficheur();
    
    valeurAttendue();
    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 0"  << endl;
    cout << "Valeur de la ponderation : NE = 0"    << endl;
    cout << "Valeur de la ponderation : SE = 0"    << endl;
    cout << "Valeur de la ponderation : SUD = 0"   << endl;
    cout << "Valeur de la ponderation : SW = 0"    << endl;
    cout << "Valeur de la ponderation : NW = 0"    << endl;


  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("constructeur a partir d'un tableau de probabilites");

    int tab[] = {1,2,3,4,5,6};
    Ponderation p(tab);
    p.afficheur();
    
    valeurAttendue();
    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 1"  << endl;
    cout << "Valeur de la ponderation : NE = 2"    << endl;
    cout << "Valeur de la ponderation : SE = 3"    << endl;
    cout << "Valeur de la ponderation : SUD = 4"   << endl;
    cout << "Valeur de la ponderation : SW = 5"    << endl;
    cout << "Valeur de la ponderation : NW = 6"    << endl;


  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("operateur +=");

    int tab[] = {1,2,3,4,5,6};
    Ponderation p(tab);
    p.afficheur();

    int tab2[] = {1,1,1,1,1,1};
    Ponderation p2(tab2);
    p2.afficheur();
    
    p+=p2;
    p.afficheur();
    

    
    valeurAttendue();
    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 1"  << endl;
    cout << "Valeur de la ponderation : NE = 2"    << endl;
    cout << "Valeur de la ponderation : SE = 3"    << endl;
    cout << "Valeur de la ponderation : SUD = 4"   << endl;
    cout << "Valeur de la ponderation : SW = 5"    << endl;
    cout << "Valeur de la ponderation : NW = 6"    << endl;

    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 1"  << endl;
    cout << "Valeur de la ponderation : NE = 1"    << endl;
    cout << "Valeur de la ponderation : SE = 1"    << endl;
    cout << "Valeur de la ponderation : SUD = 1"   << endl;
    cout << "Valeur de la ponderation : SW = 1"    << endl;
    cout << "Valeur de la ponderation : NW = 1"    << endl;

    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 2"  << endl;
    cout << "Valeur de la ponderation : NE = 3"    << endl;
    cout << "Valeur de la ponderation : SE = 4"    << endl;
    cout << "Valeur de la ponderation : SUD = 5"   << endl;
    cout << "Valeur de la ponderation : SW = 6"    << endl;
    cout << "Valeur de la ponderation : NW = 7"    << endl;


  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("operateur +");

    int tab[] = {1,2,3,4,5,6};
    Ponderation p(tab);
    p.afficheur();

    int tab2[] = {1,1,1,1,1,1};
    Ponderation p2(tab2);
    p2.afficheur();
    
    (p+p2).afficheur();
    

    
    valeurAttendue();
    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 1"  << endl;
    cout << "Valeur de la ponderation : NE = 2"    << endl;
    cout << "Valeur de la ponderation : SE = 3"    << endl;
    cout << "Valeur de la ponderation : SUD = 4"   << endl;
    cout << "Valeur de la ponderation : SW = 5"    << endl;
    cout << "Valeur de la ponderation : NW = 6"    << endl;

    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 1"  << endl;
    cout << "Valeur de la ponderation : NE = 1"    << endl;
    cout << "Valeur de la ponderation : SE = 1"    << endl;
    cout << "Valeur de la ponderation : SUD = 1"   << endl;
    cout << "Valeur de la ponderation : SW = 1"    << endl;
    cout << "Valeur de la ponderation : NW = 1"    << endl;

    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 2"  << endl;
    cout << "Valeur de la ponderation : NE = 3"    << endl;
    cout << "Valeur de la ponderation : SE = 4"    << endl;
    cout << "Valeur de la ponderation : SUD = 5"   << endl;
    cout << "Valeur de la ponderation : SW = 6"    << endl;
    cout << "Valeur de la ponderation : NW = 7"    << endl;


  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("methodes setPonderation");

    Ponderation p;
    p.afficheur();

    p.setPonderation(NORD,1);
    p.setPonderation(NE,2);
    p.setPonderation(SE,3);
    p.setPonderation(SUD,4);
    p.setPonderation(SW,5);
    p.setPonderation(NW,6);

    p.afficheur();
    
    valeurAttendue();

    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 0"  << endl;
    cout << "Valeur de la ponderation : NE = 0"    << endl;
    cout << "Valeur de la ponderation : SE = 0"    << endl;
    cout << "Valeur de la ponderation : SUD = 0"   << endl;
    cout << "Valeur de la ponderation : SW = 0"    << endl;
    cout << "Valeur de la ponderation : NW = 0"    << endl;

    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 1"  << endl;
    cout << "Valeur de la ponderation : NE = 2"    << endl;
    cout << "Valeur de la ponderation : SE = 3"    << endl;
    cout << "Valeur de la ponderation : SUD = 4"   << endl;
    cout << "Valeur de la ponderation : SW = 5"    << endl;
    cout << "Valeur de la ponderation : NW = 6"    << endl;


  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test exception sur setPonderation(7,2)");

    Ponderation p;

    try {
      p.setPonderation(7,1);
    }
    catch (Direction::Exception ex)
      {
	cout << "exception catche" << endl;
      }


  
    valeurAttendue();


    cout << "[EXCEPTION]: valeur de Direction non compris dans le domaine direction " <<endl;
    cout << "exception catche" << endl;

  }


  //******************************************************************************
  cin >> i;

  {
    testFeature("methodes getPonderation");

    Ponderation p;

    p.setPonderation(NORD,1);
    p.setPonderation(NE,2);
    p.setPonderation(SE,3);
    p.setPonderation(SUD,4);
    p.setPonderation(SW,5);
    p.setPonderation(NW,6);

    p.afficheur();

    cout << p.getPonderation(NORD) << endl;
    cout << p.getPonderation(NE) << endl;
    cout << p.getPonderation(SE) << endl;
    cout << p.getPonderation(SUD) << endl;
    cout << p.getPonderation(SW) << endl;
    cout << p.getPonderation(NW) << endl;
    
    valeurAttendue();

    cout << "----------- Ponderation --------------" << endl;
    cout << "Valeur de la ponderation : NORD = 1"  << endl;
    cout << "Valeur de la ponderation : NE = 2"    << endl;
    cout << "Valeur de la ponderation : SE = 3"    << endl;
    cout << "Valeur de la ponderation : SUD = 4"   << endl;
    cout << "Valeur de la ponderation : SW = 5"    << endl;
    cout << "Valeur de la ponderation : NW = 6"    << endl;

    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
    cout << "5" << endl;
    cout << "6" << endl;


  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test exception sur getPonderation(7,2)");

    Ponderation p;

    try {
      p.getPonderation(7);
    }
    catch (Direction::Exception ex)
      {
	cout << "exception catche" << endl;
      }


  
    valeurAttendue();


    cout << "[EXCEPTION]: valeur de Direction non compris dans le domaine direction " <<endl;
    cout << "exception catche" << endl;

  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("methode getModule");

    Ponderation p;

    p.setPonderation(NORD,1);
    p.setPonderation(NE,2);
    p.setPonderation(SE,3);
    p.setPonderation(SUD,4);
    p.setPonderation(SW,5);
    p.setPonderation(NW,6);

    cout << p.getModule() << endl;

  
    valeurAttendue();

    cout << "21" << endl;
    
  }


}
