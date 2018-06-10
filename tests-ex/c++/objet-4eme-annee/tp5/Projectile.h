										//SEQb
#ifndef _PROJECTILE_H_								/*GENB*/
#define _PROJECTILE_H_								/*GENB*/
										//GENB
										//1OIDB
										//GENB
#include "Mobile.h"								/*GENB*/
										//GENB
/*										//GENB
 * Class Header									//GENB
 */										//GENB
class Projectile: public Mobile {						//GENB
public:										//GENB
   Projectile();								//GENB
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
