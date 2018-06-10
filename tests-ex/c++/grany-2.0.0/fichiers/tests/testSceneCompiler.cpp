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

#include "SceneCompiler.h"


int main(int argc,char **argv)
{

  int i;

  cout << "Starting testSceneCompiler" << endl;


  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.scene");

    SceneCompiler aCompiler;

    Scene *scene;


    scene = aCompiler.parseFichier("files/test1.scene");

    scene->afficheur();

    Scene sc(*scene);


    delete scene;

    sc.afficheur();
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur test1.scene");

    SceneCompiler aCompiler;

    Scene *scene;

    scene = aCompiler.parseFichier("files/test1.scene");

    scene->afficheur();
    delete scene;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur phasegen.scene");

    SceneCompiler aCompiler;

    Scene *scene;

    scene = aCompiler.parseFichier("files/phasegen.scene");

    scene->afficheur();
    delete scene;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur nocoloration.scene");

    SceneCompiler aCompiler;

    Scene *scene;

    scene = aCompiler.parseFichier("files/nocoloration.scene");

    scene->afficheur();
    delete scene;
  }

  //******************************************************************************
  cin >> i;

  {
    testFeature("test sur noregle.scene");

    SceneCompiler aCompiler;

    Scene *scene;

    scene = aCompiler.parseFichier("files/noregle.scene");

    scene->afficheur();
    delete scene;
  }







  return 0;
};
