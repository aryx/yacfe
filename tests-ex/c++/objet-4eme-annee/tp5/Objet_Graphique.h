										//SEQb
#ifndef _OBJET_GRAPHIQUE_H_							/*GENB*/
#define _OBJET_GRAPHIQUE_H_							/*GENB*/
										//GENB
										//1OIDB
										//GENB
										//GENB
/*										//GENB
 * Class Header									//GENB
 */										//GENB
class Objet_Graphique {								//GENB
public:										//GENB
   void Afficher();								//GENB
   void Effacer();								//GENB
   Objet_Graphique* SuisjeTouche();						//GENB
   virtual Identite_Objet_Graphique Identite() = 0;				//GENB
   virtual void ResolutionChoc() = 0;						//GENB
   virtual void Mort() = 0;							//GENB
   Objet_Graphique();								//GENB
private:									//GENB
   Objet_Graphique* p_Prochain_Objet_Graphique;					//GENB
public:										//GENB
   Objet_Graphique* Prochain_Objet_Graphique ()					//GENB
   {										//GENB
      return p_Prochain_Objet_Graphique;					//GENB
   }										//GENB
   void set_Prochain_Objet_Graphique (Objet_Graphique* a_Prochain_Objet_Graphique)		    //GENB
   {										//GENB
      p_Prochain_Objet_Graphique = a_Prochain_Objet_Graphique;			//GENB
   }										//GENB
private:									//GENB
   Objet_Graphique* p_Liste_Objets_Graphiques;					//GENB
public:										//GENB
   Objet_Graphique* Liste_Objets_Graphiques ()					//GENB
   {										//GENB
      return p_Liste_Objets_Graphiques;						//GENB
   }										//GENB
   void set_Liste_Objets_Graphiques (Objet_Graphique* a_Liste_Objets_Graphiques)		    //GENB
   {										//GENB
      p_Liste_Objets_Graphiques = a_Liste_Objets_Graphiques;			//GENB
   }										//GENB
private:									//GENB
   Figures* p_ListeFigures;							//GENB
public:										//GENB
   Figures* ListeFigures ()							//GENB
   {										//GENB
      return p_ListeFigures;							//GENB
   }										//GENB
   void set_ListeFigures (Figures* a_ListeFigures)				//GENB
   {										//GENB
      p_ListeFigures = a_ListeFigures;						//GENB
   }										//GENB
private:									//GENB
   int p_NbFigures;								//GENB
public:										//GENB
   int NbFigures ()								//GENB
   {										//GENB
      return p_NbFigures;							//GENB
   }										//GENB
   void set_NbFigures (int a_NbFigures)						//GENB
   {										//GENB
      p_NbFigures = a_NbFigures;						//GENB
   }										//GENB
};										//GENB
#endif										/*GENB*/
										//SEQe
