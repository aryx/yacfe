										//SEQb
#ifndef _PAROI_H_								/*GENB*/
#define _PAROI_H_								/*GENB*/
										//GENB
										//1OIDB
										//GENB
#include "Immobile.h"								/*GENB*/
										//GENB
/*										//GENB
 * Class Header									//GENB
 */										//GENB
class Paroi: public Immobile {							//GENB
public:										//GENB
   Paroi();									//GENB
private:									//GENB
   int p_Vie;									//GENB
public:										//GENB
   int Vie ()									//GENB
   {										//GENB
      return p_Vie;								//GENB
   }										//GENB
   void set_Vie (int a_Vie)							//GENB
   {										//GENB
      p_Vie = a_Vie;								//GENB
   }										//GENB
};										//GENB
#endif										/*GENB*/
										//SEQe
