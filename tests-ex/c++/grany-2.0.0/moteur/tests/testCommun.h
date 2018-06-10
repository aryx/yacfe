/******************************************************************************* 
 * $Id: testCommun.h,v 1.1 1999/04/21 22:37:39 pad Exp $
 * 
 *******************************************************************************/

#include <iostream>
#include <string>

inline void testFeature(string message)
{
  cout << "[TEST************] " << message <<" ************************" << "\n";
}

inline void valeurAttendue()
{
  cout << "---------Valeur attendue-------------\n";
}
