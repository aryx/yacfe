/* Copyleft (c) Guillaume Cottenceau Jan 1999
 *
 */

import java.util.*;
import java.applet.*;
import java.awt.*;


abstract class GraphEditeur extends Applet {

GraphCanvas Zone_Dessin;
IconCanvas Zone_Icones;

Panel Mes_Boutons;
Button Insertion;
Button Suppression;
Button Deplacement;

public String _mode_action;
public String _mode_objet;


public void init()
  {
    setLayout(new BorderLayout());

    Zone_Dessin = new GraphCanvas();
    add("Center",Zone_Dessin);

    Zone_Icones = new IconCanvas();
    add("West",Zone_Icones);

    Insertion = new Button("Inserer");
    Suppression = new Button("Supprimer");
    Deplacement = new Button("Deplacer");

    Mes_Boutons = new Panel();
    Mes_Boutons.add(Insertion);
    Mes_Boutons.add(Suppression);
    Mes_Boutons.add(Deplacement);
    add("South",Mes_Boutons);

    _mode_action = "insertion";
    _mode_objet = "noeud";
    
  }

  
void set_types(String[] typenames)
  {
    Zone_Icones.init_collection_obj();
    for (int i = 0 ; i < typenames.length ; i++)
      {
	try 
	  {
	    Class cls = Class.forName(typenames[i]);
	    Object obj = cls.newInstance();
	    Zone_Icones.ajoute_obj(obj);
	  } catch (ClassNotFoundException c)
	    {
	      System.out.println("[Kernel Panic] ClassNotFoundException");
	    }
	  catch (InstantiationException in)
	    {
	      System.out.println("[Kernel Panic] InstantiationException");
	    }
	  catch (IllegalAccessException il)
	    {
	      System.out.println("[Kernel Panic] IllegalAccessException");
	    } 
      }
    Zone_Icones.initialise_objs_courants();
  }


private Noeud _Noeud_Courant;

  // Sera appele par IconCanvas pour mettre a jour
  // l'objet Noeud selectionne.
  // On aura ainsi une instance correcte de
  // la sous-classe heritee de Noeud qu'il
  // faudra cloner a la creation d'un nouveau Noeud.
public void Modifie_Noeud_Courant(Noeud n)
  {
    _Noeud_Courant = n;
    _mode_objet = "noeud";
  }

  // Retourne dans GraphCanvas une instance correcte
  // du Noeud a creer.
public Noeud Noeud_Courant()
  {
    return _Noeud_Courant;
  }


private Arc _Arc_Courant;

  // Sera appele par IconCanvas pour mettre a jour
  // l'objet Arc selectionne.
  // On aura ainsi une instance correcte de
  // la sous-classe heritee de Arc qu'il
  // faudra cloner a la creation d'un nouvel Arc.
public void Modifie_Arc_Courant(Arc a)
  {
    _Arc_Courant = a;
    _mode_objet = "arc";
  }

  // Retourne dans GraphCanvas une instance correcte
  // de l'arc a creer.
public Arc Arc_Courant()
  {
    return _Arc_Courant;
  }



public String mode_action()
  {
    return _mode_action;
  }

public String mode_objet()
  {
    return _mode_objet;
  }


public boolean handleEvent(Event evt)
  {

  if (evt.id == Event.ACTION_EVENT)
    {

      // On ne peut pas faire de switch, c'est pourri
      if (evt.target == Insertion)
	{
	  _mode_action = "insertion";
	  return true;
	}
      if (evt.target == Suppression)
	{
	  _mode_action = "suppression";
	  return true;
	}
      if (evt.target == Deplacement)
	{
	  _mode_action = "deplacement";
	  _mode_objet = "noeud";
	  return true;
	}
      
      return true;

    } else return super.handleEvent(evt);
  
  }
    
  
}
