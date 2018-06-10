										//SEQb
#ifndef _MOBILE_H_								/*GENB*/
#define _MOBILE_H_								/*GENB*/
										//GENB
										//1OIDB
										//GENB
#include "Objet_Graphique.h"							/*GENB*/
										//GENB
/*										//GENB
 * Class Header									//GENB
 */										//GENB
class Mobile: public Objet_Graphique {						//GENB
public:										//GENB
   void Deplacer();								//GENB
   Mobile();									//GENB
private:									//GENB
   Objet_Graphique* p_Liste_Objet_Mobiles;					//GENB
public:										//GENB
   Objet_Graphique* Liste_Objet_Mobiles ()					//GENB
   {										//GENB
      return p_Liste_Objet_Mobiles;						//GENB
   }										//GENB
   void set_Liste_Objet_Mobiles (Objet_Graphique* a_Liste_Objet_Mobiles)	//GENB
   {										//GENB
      p_Liste_Objet_Mobiles = a_Liste_Objet_Mobiles;				//GENB
   }										//GENB
private:									//GENB
   int p_Deplacement_y;								//GENB
public:										//GENB
   int Deplacement_y ()								//GENB
   {										//GENB
      return p_Deplacement_y;							//GENB
   }										//GENB
   void set_Deplacement_y (int a_Deplacement_y)					//GENB
   {										//GENB
      p_Deplacement_y = a_Deplacement_y;					//GENB
   }										//GENB
private:									//GENB
   int p_Deplacement_x;								//GENB
public:										//GENB
   int Deplacement_x ()								//GENB
   {										//GENB
      return p_Deplacement_x;							//GENB
   }										//GENB
   void set_Deplacement_x (int a_Deplacement_x)					//GENB
   {										//GENB
      p_Deplacement_x = a_Deplacement_x;					//GENB
   }										//GENB
};										//GENB
#endif										/*GENB*/
										//SEQe
