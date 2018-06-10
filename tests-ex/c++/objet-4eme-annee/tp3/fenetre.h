//+++++++++++++++++++++++++++++   fenetre.h   +++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef	FENETRE_H
#define	FENETRE_H

//
// fenetre.h -  definition de la classe transfert : fenetre.
//

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include "can_ui.h"

const int BLANC = 0;
const int NOIR = 1;



class fenetre {

Display  *DpyCan;        /* Pointeur sur la connection du serveur X Canvas*/
int       ScrNum ;       /* Specifie l'ecran du serveur */
Window    Win ;          /* Fenetre Graphique (canvas) */
GC        Gc;            /* Contexte Graphique général */
Xv_window Fen ;          /* Canvas */


public:
//constructeur :
		fenetre (can_window1_objects &);
//methodes :
	void 	vi_vect(int couleur, int x1, int y1, int x2, int y2);
	void 	vi_rectangle(int couleur, int x1, int y1, int x2, int y2);
	void 	vi_point(int couleur, int x, int y);
	void 	vi_texte(int couleur, int x, int y, char * chaine);
	void 	vi_cercle(int couleur, int x, int y, int rayon);
	void 	move(int *x0, int *y0, int *x1, int *y1, int m, int c);
	void 	vi_efface_fenetre();


};
#endif
