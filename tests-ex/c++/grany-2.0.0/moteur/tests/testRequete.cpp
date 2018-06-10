/******************************************************************************* 
 * $Id: testRequete.cpp,v 1.4 1999/06/14 12:53:18 ypadiole Exp $
 * 
 *******************************************************************************/

#include "Requete.h"

#include "testCommun.h"

int main()
{
  int i;

  cout << "Starting testRequete" << endl;
  //******************************************************************************
  cin >> i;

  {
    testFeature("constructeur par defaut");

    Requete req;
    req.afficheur();
    cout << endl;
    
    valeurAttendue();
    cout << "RIEN" << endl;

  }
  //******************************************************************************
  cin >> i;

  {
    testFeature("Constructeur par EnumRequeteRequete");

    Requete req(SUD);
    req.afficheur();
    cout << endl;
    
    valeurAttendue();
    cout << "SUD" << endl;
  }
  //******************************************************************************
  cin >> i;

  {
    testFeature("Constructeur par entier");

    Requete req(2);
    req.afficheur();
    cout << endl;

    valeurAttendue();
    cout << "SE" << endl;
  }
  //******************************************************************************
  cin >> i;

  {
    testFeature("operateur de cast");

    Requete req(2);

    int i = req;
    cout << i <<endl;

    valeurAttendue();
    cout << 2 << endl;
  }
  //******************************************************************************
  cin >> i;

  {
    testFeature("operateur ==");
    
    Requete req1(2);
    Requete req2(2);
    Requete req3(3);
    cout << (req1 == req2) << endl;
    cout << (req1 == req3) << endl;
 
    valeurAttendue();
    
    cout << 1 << endl;
    cout << 0 << endl;
  }
  //******************************************************************************
  cin >> i;

  {
    testFeature("methode RequeteEnAccord");
    
    Requete req0(RIEN);
    Requete req1(NORD);
    Requete req2(NE);
    Requete req3(SE);
    Requete req4(SUD);
    Requete req5(SW);
    Requete req6(NW);

    req0.afficheur();
    cout << endl;

    req1.afficheur();
    cout << endl;

    req2.afficheur();
    cout << endl;

    req3.afficheur();
    cout << endl;

    req4.afficheur();
    cout << endl;

    req5.afficheur();
    cout << endl;

    req6.afficheur();
    cout << endl;

    cout << requeteEnAccord(req0,req1) << endl;
    cout << requeteEnAccord(req0,req3) << endl;
    cout << requeteEnAccord(req1,req1) << endl;
    cout << requeteEnAccord(req1,req4) << endl;
    cout << requeteEnAccord(req2,req2) << endl;
    cout << requeteEnAccord(req2,req5) << endl;
    cout << requeteEnAccord(req3,req3) << endl;
    cout << requeteEnAccord(req3,req6) << endl;
    cout << requeteEnAccord(req4,req4) << endl;
    cout << requeteEnAccord(req4,req1) << endl;
    cout << requeteEnAccord(req5,req5) << endl;
    cout << requeteEnAccord(req5,req2) << endl;
    cout << requeteEnAccord(req6,req6) << endl;
    cout << requeteEnAccord(req6,req3) << endl;


 
    valeurAttendue();
    
    cout << "RIEN" << endl;
    cout << "NORD" << endl;
    cout << "NE" << endl;
    cout << "SE" << endl;
    cout << "SUD" << endl;
    cout << "SW" << endl;
    cout << "NW" << endl;

    cout << 0 << endl;
    cout << 0 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    

  }
  //******************************************************************************
  cin >> i;

  {
    testFeature("methode RequeteAccorde");
    
    Requete req0(RIEN);
    Requete req1(NORD);
    Requete req2(NE);
    Requete req3(SE);
    Requete req4(SUD);
    Requete req5(SW);
    Requete req6(NW);

    req0.afficheur();
    cout << endl;

    req1.afficheur();
    cout << endl;

    req2.afficheur();
    cout << endl;

    req3.afficheur();
    cout << endl;

    req4.afficheur();
    cout << endl;

    req5.afficheur();
    cout << endl;

    req6.afficheur();
    cout << endl;

    (req0.requeteAccordee()).afficheur();
    cout << endl;

    (req1.requeteAccordee()).afficheur();
    cout << endl;

    (req2.requeteAccordee()).afficheur();
    cout << endl;

    (req3.requeteAccordee()).afficheur();
    cout << endl;

    (req4.requeteAccordee()).afficheur();
    cout << endl;

    (req5.requeteAccordee()).afficheur();
    cout << endl;

    (req6.requeteAccordee()).afficheur();
    cout << endl;
 
    valeurAttendue();
    
    cout << "RIEN" << endl;
    cout << "NORD" << endl;
    cout << "NE" << endl;
    cout << "SE" << endl;
    cout << "SUD" << endl;
    cout << "SW" << endl;
    cout << "NW" << endl;

    cout << "[ERREUR] on ne devrait pas avoir d'appel de requete accordee sur RIEN (aucune requete ne s'y accorde / cela ne genere pas de deplacement)" << endl;
    cout << "RIEN" << endl;
    cout << "SUD" << endl;
    cout << "SW" << endl;
    cout << "NW" << endl;
    cout << "NORD" << endl;
    cout << "NE" << endl;
    cout << "SE" << endl;

    

  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("pas d'exception sur RIEN");

    try {
      Requete req(RIEN);
      if (&req) {}
    }
    catch (Requete::Exception reqexception)
      {
	cout << "exception catche" << endl;
      }

    valeurAttendue();
  }
  //******************************************************************************
  cin >> i;

  {
    testFeature("exception sur 7");

    try {
      Requete req(7);
      if (&req) {}
    }
    catch (Requete::Exception reqexception)
      {
	cout << "exception catche" << endl;
      }

    valeurAttendue();
    cout << "[EXCEPTION]: valeur de Requete non compris dans le domaine requete " <<endl;
    cout << "exception catche" << endl;
  }

  
}
