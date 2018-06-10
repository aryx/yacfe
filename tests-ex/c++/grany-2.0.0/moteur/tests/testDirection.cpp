/******************************************************************************* 
 * $Id: testDirection.cpp,v 1.4 1999/06/14 12:53:12 ypadiole Exp $
 * 
 *******************************************************************************/

#include "Direction.h"

#include "testCommun.h"

int main()
{
  int i;

  cout << "Starting testDirection" << endl;
  
  //******************************************************************************
  cin >> i;

  {
    testFeature("constructeur par defaut");

    Direction dir;
    dir.afficheur();
    cout << endl;
    
    valeurAttendue();
    cout << "NORD" << endl;

  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("Constructeur par EnumDirectionRequete");

    Direction dir(SUD);
    dir.afficheur();
    cout << endl;
    
    valeurAttendue();
    cout << "SUD" << endl;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("Constructeur par entier");

    Direction dir(2);
    dir.afficheur();
    cout << endl;

    valeurAttendue();
    cout << "SE" << endl;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("operateur de cast");

    Direction dir(2);

    int i = dir;
    cout << i <<endl;

    valeurAttendue();
    cout << 2 << endl;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("methode estPreponderante");
    
    Direction dir0(0);
    Direction dir1(1);
    Direction dir2(2);
    Direction dir3(3);
    Direction dir4(4);
    Direction dir5(5);

    dir0.afficheur();
    cout << dir0.estPreponderante() <<endl;
    dir1.afficheur();
    cout << dir1.estPreponderante() <<endl;
    dir2.afficheur();
    cout << dir2.estPreponderante() <<endl;
    dir3.afficheur();
    cout << dir3.estPreponderante() <<endl;
    dir4.afficheur();
    cout << dir4.estPreponderante() <<endl;
    dir5.afficheur();
    cout << dir5.estPreponderante() <<endl;
  
    valeurAttendue();
    cout 
      << "NORD" << "1" << endl
      << "NE" << "0" << endl
      << "SE" << "1" << endl
      << "SUD" << "0" << endl
      << "SW" << "1" << endl
      << "NW" << "0" <<endl;

    
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("exception sur RIEN");

    try {
      Direction dir(RIEN);
      if (&dir) {}
    }
    catch (Direction::Exception direxception)
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
    testFeature("exception sur 7");

    try {
      Direction dir(7);
      if (&dir) {}
    }
    catch (Direction::Exception direxception)
      {
	cout << "exception catche" << endl;
      }

    valeurAttendue();
    cout << "[EXCEPTION]: valeur de Direction non compris dans le domaine direction " <<endl;
    cout << "exception catche" << endl;
  }
  
}
