#include "chaine.h"
#include <iostream>
using std::cout;

int main()
{

  chaine ch1;
  chaine ch2;

  ch1 = "toto";
  ch1.afficher();

  ch2 = ch1;

  ch2.afficher();

  chaine ch3;

  ch2 = ch1 + "ere";
  ch3 = "tam" + ch1;

  ch2.afficher();
  ch3.afficher();

  char c = ch2[5];

  cout << c << '\n';

  ch2[5] = 'x';

  ch2.afficher();

  ch2 += "Tarlouze";

  ch2.afficher();

}
