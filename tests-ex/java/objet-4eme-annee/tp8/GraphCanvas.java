/* Copyleft (c) Guillaume Cottenceau Jan 1999
 *
 */

import java.util.*;
import java.awt.*;


class GraphCanvas extends Canvas {


private Vector _Noeuds;
private Vector _Arcs;


public GraphCanvas()
  {
    _Noeuds = new Vector();
    _Arcs = new Vector();

  }

public Noeud Cherche_Noeud(Point endroit)
  {
    Enumeration mon_enum = _Noeuds.elements();
    while (mon_enum.hasMoreElements()) {
      Noeud noeud_a_examiner = (Noeud) mon_enum.nextElement();
      if (noeud_a_examiner.est_dans(endroit)) return noeud_a_examiner;
    }
    return null;
  }


public Arc Cherche_Arc(Point endroit)
  {
    Enumeration mon_enum = _Arcs.elements();
    while (mon_enum.hasMoreElements()) {
      Arc arc_a_examiner = (Arc) mon_enum.nextElement();
      if (arc_a_examiner.est_dans(endroit)) return arc_a_examiner;
    }
    return null;
  }


void Supprime_Arcs_Attaches(Noeud n)
  {
    int re_enum = 1;
    while (re_enum == 1)
      {
	re_enum = 0;
	Enumeration mon_enum = _Arcs.elements();
	while (mon_enum.hasMoreElements()) {
	  Arc arc_a_examiner = (Arc) mon_enum.nextElement();
	  if (arc_a_examiner.Extremite1().equals(n.centre()) ||
	      arc_a_examiner.Extremite2().equals(n.centre()))
	    {
	      re_enum = 1;
	      _Arcs.removeElement(arc_a_examiner);
	    }
	}
      }
  }


Noeud Noeud_En_Deplacement;

Noeud Noeud_Origine_Arc;


public boolean mouseDown(Event evt, int x, int y)
  {
    String mode_action = ((GraphEditeur) getParent()).mode_action();
    String mode_objet = ((GraphEditeur) getParent()).mode_objet();

    if (mode_objet.compareTo("noeud") == 0)
      {
	Point Pos_Souris = new Point(x,y);
	Noeud n = Cherche_Noeud(Pos_Souris);

	if ((mode_action.compareTo("insertion") == 0) && (n == null))
	  {
	    Noeud t = ((GraphEditeur) getParent()).Noeud_Courant();
	    Noeud i = (Noeud) t.clone();
	    i.deplace(Pos_Souris);
	    _Noeuds.addElement(i);
	  }
	
	if ((mode_action.compareTo("deplacement") == 0) && (n != null))
	  {
	    Noeud_En_Deplacement = n;
	  }

	if ((mode_action.compareTo("suppression") == 0) && (n != null))
	  {
	    Supprime_Arcs_Attaches(n);
	    _Noeuds.removeElement(n);
	  }
      }


    if (mode_objet.compareTo("arc") == 0)
      {
	Point Pos_Souris = new Point(x,y);
	Noeud n = Cherche_Noeud(Pos_Souris);
	Arc a = Cherche_Arc(Pos_Souris);

	if ((mode_action.compareTo("insertion") == 0) && (n != null))
	  {
	    Noeud_Origine_Arc = n;
	  }
	
	if ((mode_action.compareTo("suppression") == 0) && (a != null))
	  {
	    _Arcs.removeElement(a);
	  }
      }

    repaint();
    return true;

  }


Arc fake_line_for_drawing;

public boolean mouseDrag(Event evt, int x, int y)
  {
    String mode_action = ((GraphEditeur) getParent()).mode_action();
    String mode_objet = ((GraphEditeur) getParent()).mode_objet();

    if (mode_objet.compareTo("noeud") == 0)
      {
	Point Pos_Souris = new Point(x,y);

	if (mode_action.compareTo("deplacement") == 0)
	  {
	    if (Noeud_En_Deplacement != null)
	      {
		// Pas besoin de deplacer les arcs !!
		// Les extremites etant des points referencant les
		// centres des Noeuds de leurs extremites... :)
		Noeud_En_Deplacement.deplace(Pos_Souris);
	      }
	  }
      }


    if (mode_objet.compareTo("arc") == 0)
      {
	Point Pos_Souris = new Point(x,y);

	if ((mode_action.compareTo("insertion") == 0) && (Noeud_Origine_Arc != null))
	  {
	    if (fake_line_for_drawing == null)
	      {
		Arc a = ((GraphEditeur) getParent()).Arc_Courant();
		fake_line_for_drawing = (Arc) a.clone();
		fake_line_for_drawing.reference_extr1(Noeud_Origine_Arc.centre());
		fake_line_for_drawing.reference_extr2(Pos_Souris);
	      }
	    else
	      {
		fake_line_for_drawing.reference_extr2(Pos_Souris);
	      }
	  }
      }

    repaint();
    return true;

  }


public boolean mouseUp(Event evt, int x, int y)
  {
    String mode_action = ((GraphEditeur) getParent()).mode_action();
    String mode_objet = ((GraphEditeur) getParent()).mode_objet();

    if (mode_objet.compareTo("noeud") == 0)
      {
	Point Pos_Souris = new Point(x,y);
	Noeud n = Cherche_Noeud(Pos_Souris);

	if ((mode_action.compareTo("deplacement") == 0) && (n != null))
	  {
	    Noeud_En_Deplacement = null;
	  }
      }

    if (mode_objet.compareTo("arc") == 0)
      {
	Point Pos_Souris = new Point(x,y);
	Noeud n = Cherche_Noeud(Pos_Souris);

	if ((mode_action.compareTo("insertion") == 0) && (n != null) && (Noeud_Origine_Arc != null) && (!(Noeud_Origine_Arc.equals(n))))
	  {
	    Arc a = ((GraphEditeur) getParent()).Arc_Courant();
	    Arc i = (Arc) a.clone();
	    i.reference_extr1(Noeud_Origine_Arc.centre());
	    i.reference_extr2(n.centre());
	    _Arcs.addElement(i);
	  }

	fake_line_for_drawing = null;
	Noeud_Origine_Arc = null;

      }

    repaint();
    return true;

  }




public void paint(Graphics g)
  {
    Dimension d = size();
    g.setColor(Color.white);
    g.drawRect(0,0,d.width-1,d.height-1);

    for (int i=0 ; i<_Noeuds.size() ; i++)
      {
	Noeud n = (Noeud) _Noeuds.elementAt(i);
	n.dessine(g);
      }

    for (int i=0 ; i<_Arcs.size() ; i++)
      {
	Arc n = (Arc) _Arcs.elementAt(i);
	n.dessine(g);
      }

    if (fake_line_for_drawing != null)
      {
	fake_line_for_drawing.dessine(g);
      }

  }


}
