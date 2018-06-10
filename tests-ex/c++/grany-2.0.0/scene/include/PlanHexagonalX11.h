/*******************************************************************************
 *
 * Copyright (C) 1999-2000 by Y. Padioleau, G. Cottenceau, P. Garcia,
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

#ifndef _PLANHEXAGONALX11_H_
#define _PLANHEXAGONALX11_H_

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "CommunScene.h"

#include "PlanHexagonal.h"

#define XORIGINE 40
#define YORIGINE 100
#define DISTANCE 4


class PlanHexagonalX11 : public PlanHexagonal
{
public:
  PlanHexagonalX11(int dim, const Scene& sc);

  void dessinePlanHexagonal(Display *, Window, GC, XColor, XColor, XColor, XColor) ;
  void afficheEcran() ;

  void transf(int i, int j, int& x, int& y)
    {
      x = XORIGINE + (3 * DISTANCE * i) / 2 ;
      y = YORIGINE + 2 * DISTANCE * j - DISTANCE * i ;
    }
  
};


//##############################################################################
//##############################################################################
//##############################################################################
// METHODES INLINES
//##############################################################################
//##############################################################################
//##############################################################################

PlanHexagonalX11::PlanHexagonalX11(int dim, const Scene& sc)
  :PlanHexagonal(dim,sc) 
{
}


// machin X
void PlanHexagonalX11::afficheEcran() 
{

  Display * display ;
  Window    fenetre ;
  GC        cont_graph ;
  XEvent    evenement ;
  KeySym    touche ;
  Colormap  cmap_def ;
  XColor    couleurRouge ;
  XColor    couleurBleu ;
  XColor    couleurJaune ;
  XColor    couleurNoir ;
  Status    existe ;
  //int       x,y ;

  XSizeHints indic ;
  int ecran ;
  unsigned long avant_plan,arr_plan ;
  int encore ;
  int i ;
  char caractere[11] ;

  display = XOpenDisplay(NULL) ;


  if (display == NULL)
    {
      fprintf(stderr,"Impossible d'ouvrir le display.\n") ;
      exit(1) ;
    }

  ecran = DefaultScreen(display) ;
  arr_plan = WhitePixel(display,ecran) ;
  avant_plan = BlackPixel(display,ecran) ;

  indic.x = 0 ; indic.y = 0;
  indic.width = 700; indic.height = 590 ;
  indic.flags = PPosition | PSize ;

  fenetre = XCreateSimpleWindow(display,
				DefaultRootWindow(display),
				indic.x,indic.y,indic.width,indic.height,
				5,avant_plan,arr_plan) ;

  XSetStandardProperties(display,fenetre,"Affichage plan hexagonal","Affichage plan hexagonal",
			 None,NULL,0,&indic) ;

  cont_graph = XCreateGC(display,fenetre,0,NULL) ;

  cmap_def = DefaultColormap(display,ecran) ;
  existe = XParseColor(display,cmap_def,"red",&couleurRouge) ;

  if (!existe)
    {
      fprintf(stderr,"La couleur rouge n'est pas dans la database\n") ;
      exit(0) ;
    }

  if (!XAllocColor(display,cmap_def,&couleurRouge))
    {
      printf("couleur non allouee\n") ;
      exit(0) ;
    }    
  
  existe = XParseColor(display,cmap_def,"darkgreen",&couleurBleu) ;

  if (!existe)
    {
      fprintf(stderr,"La couleur bleue n'est pas dans la database\n") ;
      exit(0) ;
    }

  if (!XAllocColor(display,cmap_def,&couleurBleu))
    {
      printf("couleur non allouee\n") ;
      exit(0) ;
    }    

  existe = XParseColor(display,cmap_def,"yellow",&couleurJaune) ;

  if (!existe)
    {
      fprintf(stderr,"La couleur jaune n'est pas dans la database\n") ;
      exit(0) ;
    }

  if (!XAllocColor(display,cmap_def,&couleurJaune))
    {
      printf("couleur non allouee\n") ;
      exit(0) ;
    }    

  existe = XParseColor(display,cmap_def,"black",&couleurNoir) ;


  if (!existe)
    {
      fprintf(stderr,"La couleur noire n'est pas dans la database\n") ;
      exit(0) ;
    }

  if (!XAllocColor(display,cmap_def,&couleurNoir))
    {
      printf("couleur non allouee\n") ;
      exit(0) ;
    }    

  XSetBackground(display,cont_graph,arr_plan) ;

  XSetForeground(display,cont_graph,avant_plan) ;

  XSetWindowBackground(display,fenetre,couleurNoir.pixel) ;

  XMapRaised(display,fenetre) ;
  
  XSelectInput(display,fenetre, KeyPressMask | ExposureMask);

  dessinePlanHexagonal(display, fenetre, cont_graph, couleurNoir, couleurBleu, couleurJaune, couleurRouge) ;

  encore = 1 ;

  while(encore)
    {
      XNextEvent(display,&evenement) ;
  
      switch(evenement.type)
	{
	case Expose :
	  if (evenement.xexpose.count == 0)
	    {
	      dessinePlanHexagonal(display, fenetre, cont_graph, couleurNoir, couleurBleu, couleurJaune, couleurRouge) ;
	    }
	  break ;
      
	case MappingNotify :
	  XRefreshKeyboardMapping(&(evenement.xmapping)) ;
	  break ;
      
	case KeyPress :
	  i = XLookupString(&(evenement.xkey),caractere,10,&touche,0) ;
	  if ((i==1) && (caractere[0] == 'q')) encore = 0 ;
	}
    }

  XFreeGC(display,cont_graph) ;
  XDestroyWindow(display,fenetre) ;
  XCloseDisplay(display) ;

}

void PlanHexagonalX11::dessinePlanHexagonal(Display * display, Window fenetre, GC cont_graph, 
					    XColor couleurNoir, XColor couleurBleu, XColor couleurJaune, XColor couleurRouge)
{
  unsigned int largeur,hauteur,largeur_bord,profondeur ;
  Window racine ;
  int x,y ;
  XPoint points[7] ;
  int d_sur_deux = DISTANCE / 2 ;
  //  int trois_demi_d = (3 * DISTANCE) / 2 ; 
  
  XGetGeometry(display,fenetre,&racine,&x,&y,&largeur,&hauteur,&largeur_bord,&profondeur) ; 
  
  
  XSetForeground(display,cont_graph,couleurBleu.pixel) ;
  XFillRectangle(display,fenetre,cont_graph,0,0,largeur,hauteur) ;
  

  for (int i = 0; i < _ecran.NbLigne(); i++)
    for (int j = 0; j < _ecran.NbColonne(); j++)
      {    
	transf(i,j,x,y) ;
	points[0].x = x - d_sur_deux ; points[0].y = y - DISTANCE ; 
	points[1].x = x - DISTANCE   ; points[1].y = y ;
	points[2].x = x - d_sur_deux ; points[2].y = y + DISTANCE ;
	points[3].x = x + d_sur_deux ; points[3].y = y + DISTANCE ;
	points[4].x = x + DISTANCE   ; points[4].y = y ;
	points[5].x = x + d_sur_deux ; points[5].y = y - DISTANCE ;
	points[6].x = x - d_sur_deux ; points[6].y = y - DISTANCE ;

	if (_ecran(i,j)->getType() != HORS_SCENE) 
	  {
	    
	    if (_ecran(i,j)->getType() == PAROI_GENERATRICE || _ecran(i,j)->getType() == PAROI_CLASSIQUE)
	      {
		XSetForeground(display,cont_graph,couleurNoir.pixel) ;
		XFillPolygon(display,fenetre,cont_graph,points,7,Convex,CoordModeOrigin) ;
	      }
	    else
	      {
  
	    
		if (_ecran(i,j)->getCellule()->getParticule()->getPhase()->getNom() == "sable") 
		  {
		    
		    XSetForeground(display,cont_graph,couleurJaune.pixel) ;
		    XFillPolygon(display,fenetre,cont_graph,points,7,Convex,CoordModeOrigin) ;
		  }
		else
		  {
		    if (_ecran(i,j)->getCellule()->getParticule()->getPhase()->getNom() == "eau") 
		      {
			
			XSetForeground(display,cont_graph,couleurRouge.pixel) ;
			XFillPolygon(display,fenetre,cont_graph,points,7,Convex,CoordModeOrigin) ;
		      }
		  }
	      }
	  }
	else
	  {
	    XSetForeground(display,cont_graph,couleurNoir.pixel) ;
	    XDrawLines(display,fenetre,cont_graph,points,7,CoordModeOrigin) ;
	  }
      }
}




#endif

