/*******************************************************************************
 *
 * Copyright (C) 1998-1999 by Y. Padioleau, G. Cottenceau, P. Garcia,
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

#include "testCommun.h"

#include "RegleCompiler.h"

int main(int argc,char **argv)
{

  int i;

  cout << "Starting testRegleCompiler" << endl;


  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.regle");

    RegleExclusion * regle;
    RegleCompiler aCompiler;
    
    regle = aCompiler.parseFichier("files/test1.regle");

    regle->afficheur();

    delete regle;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur exclusion constrictive");

    RegleExclusion * regle;
    RegleCompiler aCompiler;
    
    regle = aCompiler.parseFichier("files/exclusion_constrictive.regle");

    regle->afficheur();

    delete regle;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur exclusion frontale");

    RegleExclusion * regle;
    RegleCompiler aCompiler;
    
    regle = aCompiler.parseFichier("files/exclusion_frontale.regle");

    regle->afficheur();

    delete regle;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur exclusion intersticielle");

    RegleExclusion * regle;
    RegleCompiler aCompiler;
    
    regle = aCompiler.parseFichier("files/exclusion_interstitielle.regle");

    regle->afficheur();

    delete regle;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur exclusion isophase");

    RegleExclusion * regle;
    RegleCompiler aCompiler;
    
    regle = aCompiler.parseFichier("files/exclusion_isophase.regle");

    regle->afficheur();

    delete regle;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur exclusion neutre");

    RegleExclusion * regle;
    RegleCompiler aCompiler;
    
    regle = aCompiler.parseFichier("files/neutre.regle");

    regle->afficheur();

    delete regle;
  }


  return 0;
};
