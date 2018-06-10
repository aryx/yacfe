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

#include "SimulCompiler.h"


int main(int argc,char **argv)
{

  int i;

  cout << "Starting testSimulCompiler" << endl;


  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.simul");

    SimulCompiler aCompiler;

    Automate *automate;

    automate = aCompiler.parseFichier("files/test1.simul");

    automate->afficheur();
    delete automate;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test2 sur test1.simul");

    SimulCompiler aCompiler;

    Automate *automate;

    automate = aCompiler.parseFichier("files/test1.simul");

    automate->afficheur();
    delete automate;
  }





  return 0;
};
