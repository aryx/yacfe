/* Copyleft (c) Guillaume Cottenceau Jan 1999
 *
 */

import java.util.*;
import java.awt.*;


class IconCanvas extends Canvas {


private Vector _Objs;


public IconCanvas()
  {
    setSize(50,200); // A verifier
  }

int placeur_objs;

public void init_collection_obj()
  {
    _Objs = new Vector();
    placeur_objs = 0;
  }

public void ajoute_obj(Object obj)
  {
    _Objs.addElement(obj);

    placeur_objs += 20;
    if (obj instanceof Noeud)
      {
	((Noeud) obj).deplace(new Point(25,placeur_objs));
      } else
    if (obj instanceof Arc)
      {
	((Arc) obj).reference_extr1(new Point(10,placeur_objs-5));
	((Arc) obj).reference_extr2(new Point(40,placeur_objs+5));
      } else
	System.out.println("Erreur[IconCanvas]: l'objet fourni m'est inconnu");
  }


  // Cette methode va permettre d'initialiser, au debut du
  // programme, le Noeud et l'Arc "courants", c'est-a-dire
  // les objets sur lesquels le prog va se baser pour
  // le clonage, si l'utilisateur cree de nouveaux objets.
public void initialise_objs_courants()
  {
    Enumeration mon_enum = _Objs.elements();
    int n = 0;  // Flag pour Noeud
    int a = 0;  // Flag pour Arc
    while (mon_enum.hasMoreElements() && ((n == 0) || (a == 0))) {
      Object obj_a_examiner = mon_enum.nextElement();
      if (n == 0)
	{
	  if (obj_a_examiner instanceof Noeud)
	    {
	      ((GraphEditeur) getParent()).Modifie_Noeud_Courant((Noeud)obj_a_examiner);
	      n = -1;
	    }
	}
      if (a == 0)
	{
	  if (obj_a_examiner instanceof Arc)
	    {
	      ((GraphEditeur) getParent()).Modifie_Arc_Courant((Arc)obj_a_examiner);
	      a = -1;
	    }
	}
    }
  }

public void paint(Graphics g)
  {
    Enumeration mon_enum = _Objs.elements();
    while (mon_enum.hasMoreElements()) {
      Object obj_a_examiner = mon_enum.nextElement();
      if (obj_a_examiner instanceof Noeud)
	{
	  ((Noeud) obj_a_examiner).dessine(g);
	} else
	  if (obj_a_examiner instanceof Arc)
	    {
	      ((Arc) obj_a_examiner).dessine(g);
	    } else
	      {
		System.out.println("Impossible de dessiner l'objet suivant :");
		System.out.println(obj_a_examiner);
	      }
    }
  }


public boolean mouseDown(Event evt,int x, int y)
  {
    Enumeration mon_enum = _Objs.elements();
    while (mon_enum.hasMoreElements()) {
      Object obj_a_examiner = mon_enum.nextElement();
      if (obj_a_examiner instanceof Noeud)
	{
	  if (((Noeud)obj_a_examiner).est_dans(new Point(x,y)))
	      {
		((GraphEditeur) getParent()).Modifie_Noeud_Courant((Noeud)obj_a_examiner);
	      }
	}
      if (obj_a_examiner instanceof Arc)
	{
	  if (((Arc)obj_a_examiner).est_dans(new Point(x,y)))
	      {
		((GraphEditeur) getParent()).Modifie_Arc_Courant((Arc)obj_a_examiner);
	      }
	}
    }
    return true;
  }


}
