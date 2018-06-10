import java.util.*;
import java.awt.*;


abstract class Noeud implements Cloneable {


private Point _centre;


public Noeud()
  {
    _centre = new Point();
  }


public abstract void dessine(Graphics g);

public abstract Polygon polygon_englobant();


public Object clone()
  {
    try {
      Object objet_clone = super.clone();
      ((Noeud) objet_clone)._centre = new Point(this._centre);
      return objet_clone;
    } catch (CloneNotSupportedException e)
      { 
	System.out.println("[Kernel Panic] Exception clone non supporte dans Noeud");
	return null;
      }
  }


public boolean est_dans(Point p)
  { return polygon_englobant().contains(p); }

public Point centre()
  { return _centre; }

public void deplace(Point p)
  {
    _centre.setLocation(p.getX(),p.getY());
  }
  
}
