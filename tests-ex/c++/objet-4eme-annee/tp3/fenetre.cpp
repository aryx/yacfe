extern "C" {
#include <stdio.h>
}

#include "fenetre.h"


// MODULE  : outils pour dessiner des segments, des points, cercle, rectangle

//VERSION : Novembre 95



/* ----------------- constructeur------------------------ */
fenetre::fenetre(can_window1_objects & C)
{
        //
       C.objects_initialize(NULL);
 
    DpyCan = (Display *)xv_get(C.canvas1, XV_DISPLAY) ;
    ScrNum = DefaultScreen(DpyCan) ;
    Gc  = DefaultGC(DpyCan, ScrNum) ;
    Fen = canvas_paint_window(C.canvas1) ;
    Win = (XID)xv_get(Fen, XV_XID) ;
 

}


/* --------------------- vi_vect ----------- */
void fenetre::vi_vect(int coul, int x1, int y1, int x2, int y2)
{
//	pw_vector(pwc,x1,y1,x2,y2,PIX_SRC ,coul);

	if(coul == NOIR)
    		XSetForeground(DpyCan,Gc,BlackPixel(DpyCan,ScrNum));
	else
    		XSetForeground(DpyCan,Gc,WhitePixel(DpyCan,ScrNum));

    XDrawLine(DpyCan, Win, Gc, (short)x1, (short)y1, (short)x2, (short)y2 );
 

}

/* ----------------------- vi_point ------------ */
void fenetre::vi_point(int coul, int x, int y)
{
//	pw_put(pwc,x,y,coul);
	vi_vect( coul, x, y, x+1, y+1);
}

/* ---------------------- vi_texte -----------*/
void fenetre::vi_texte(int coul, int x, int y, char * chaine)
{
//	pw_text(pwc,x,y, PIX_SRC|PIX_DST, fonte, chaine);
}

/* ----------------- vi_efface_ecran -----------------*/
void fenetre::vi_efface_fenetre()
{
//	pw_writebackground(pwc,0,0,Enbcol,Enblig,PIX_SRC);
}


/* ----------------- vi_cercle -----------------*/
void fenetre::vi_cercle(int coul, int x, int y, int r)
{
int m3, m2, m1, delta, pdelta, x1, y1, X, Y, x0, y0;

	m3 = 1;
	x1 = -r + x;
	y1 = y ;
//	pw_put(pwc,x1, y1,coul);
	x0 = x1;
	y0 = y1;
	do
	{
		X = 1;
		Y = r + r - 1;
		delta = Y - 1;
		m1 = m3;
		m2 = m1 + 1;
		m3 = m2 + 1;
		if (m3 == 9)
			m3 = 1;
		while (Y>= 0)
		{
			pdelta = delta + delta;
			if (pdelta < 0)
			{
				pdelta = pdelta + X;
				if (pdelta < 0)
				{
					Y = Y -2;
					delta = delta + Y;
					move(&x0,&y0,&x1,&y1,m3, coul);
				}
				else
				{
					X = X + 2;
					Y = Y - 2;
					delta = delta +Y -X;
					move(&x0,&y0,&x1,&y1,m2, coul);
				}
				
			}
			else
			{
				pdelta = pdelta - Y;
				if (pdelta >= 0)
				{
					X = X +2;
					delta = delta - X;
					move(&x0,&y0,&x1,&y1,m1, coul);
				}
				else
				{
					X = X + 2;
					Y = Y - 2;
					delta = delta +Y -X;
					move(&x0,&y0,&x1,&y1,m2, coul);
				}
				
			}
		x0 = x1;
		y0 = y1;
		}
	}
	while (m3 != 1);
}

/* ----------------- move -----------------*/	
void fenetre::move(int *x0, int *y0, int *x1, int *y1, int m, int coul)
{
	switch (m)
	{
		case 1 :
				(*y1)++;
				break;
		case 2 :
				(*x1)++;
				(*y1)++;
				break;
		case 3 :
				(*x1)++;
				break;
		case 4 :
				(*x1)++;
				(*y1)--;
				break;
		case 5 :
				(*y1)--;
				break;
		case 6 :
				(*x1)--;
				(*y1)--;
				break;
		case 7 :
				(*x1)--;
				break;
		case 8 :
				(*x1)--;
				(*y1)++;
				break;
	}
//	pw_put(pwc,*x1, *y1,coul);
	vi_vect(coul, (*x0), (*y0), (*x1), (*y1) );

	(*x0) = (*x1);
	(*y0) = (*y1);
}				

void fenetre::vi_rectangle(int couleur, int x1, int y1, int x2, int y2)
{
	vi_vect(couleur, x1, y1, x1, y2);
	vi_vect(couleur, x1, y2, x2, y2);
	vi_vect(couleur, x2, y2, x2, y1);
	vi_vect(couleur, x2, y1, x1, y1);
}
	


