import java.util.*;
import java.awt.*;


abstract class Arc implements Cloneable {


private Point _Extremite1;
private Point _Extremite2;


public Arc()
  {
    _Extremite1 = new Point();
    _Extremite2 = new Point();
  }

public abstract void dessine(Graphics g);


public Object clone()
  {
    try {
      Object objet_clone = super.clone();
      ((Arc) objet_clone)._Extremite1 = new Point(this._Extremite1);
      ((Arc) objet_clone)._Extremite2 = new Point(this._Extremite2);
      // TODO : verifier clone valide
      return objet_clone;
    } catch (CloneNotSupportedException e)
      { 
	System.out.println("[Kernel Panic] Exception clone non supporte dans Arc");
	return null;
      }
  }


public abstract Polygon polygon_englobant();

public boolean est_dans(Point p)
  { return polygon_englobant().contains(p); }

public Point Extremite1()
  { return _Extremite1; }


  // Referencement : super utile ensuite !
  // -> permet aux Arcs de se deplacer tout seuls par la
  // suite, lorsqu'on deplace les Noeuds des extremites ! :)
public void reference_extr1(Point p)
  {
    _Extremite1 = p;
  }

public Point Extremite2()
  { return _Extremite2; }

public void reference_extr2(Point p)
  {
    _Extremite2 = p;
  }


}
