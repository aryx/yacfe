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

#include "FrontiereCompiler.h"

void affiche(list<Frontiere*> *vec)
{
  cout << "Liste des frontieres" << endl << endl;

  list<Frontiere*>::iterator it_vec;
  for (it_vec = vec->begin(); it_vec != vec->end(); it_vec++)
    {
      (*it_vec)->afficheur();
      cout << endl;
    }

}

void libere(list<Frontiere*> *vec)
{
  list<Frontiere*>::iterator it_vec;
  for (it_vec = vec->begin(); it_vec != vec->end(); it_vec++)
    {
      delete (*it_vec);
    }
  delete vec;
}


int main(int argc,char **argv)
{

  int i;

  cout << "Starting testFrontiereCompiler" << endl;


  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.frontiere");

    list<Frontiere*>* list_frontiere;
    FrontiereCompiler aCompiler;
    
    list_frontiere = aCompiler.parseFichier("files/test1.frontiere");

    affiche(list_frontiere);

    libere(list_frontiere);
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur sablier.frontiere");

    list<Frontiere*>* list_frontiere;
    FrontiereCompiler aCompiler;
    
    list_frontiere = aCompiler.parseFichier("files/sablier.frontiere");

    affiche(list_frontiere);

    libere(list_frontiere);
  }



  return 0;
};
