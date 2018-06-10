import java.util.*;
import java.awt.*;


class Pointille extends Arc {

static private int Largeur_ext = 7;
static private int Largeur_int = 3;

static private Color c = Color.yellow;

public void dessine(Graphics g)
  {
    g.setColor(c);
    Polygon monpoly = new Polygon();
    double alpha = Math.atan((Extremite2().getY()-Extremite1().getY()) /
			     (Extremite2().getX()-Extremite1().getX()));
    monpoly.addPoint((int)Extremite1().getX()+(int)(Largeur_int*Math.sin(alpha)),
		     (int)Extremite1().getY()-(int)(Largeur_int*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite1().getX()-(int)(Largeur_int*Math.sin(alpha)),
		     (int)Extremite1().getY()+(int)(Largeur_int*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite2().getX()-(int)(Largeur_int*Math.sin(alpha)),
		     (int)Extremite2().getY()+(int)(Largeur_int*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite2().getX()+(int)(Largeur_int*Math.sin(alpha)),
		     (int)Extremite2().getY()-(int)(Largeur_int*Math.cos(alpha)));
    g.fillPolygon(monpoly);
  }


public Polygon polygon_englobant() 
  {
    Polygon monpoly = new Polygon();
    double alpha = Math.atan((Extremite2().getY()-Extremite1().getY()) /
			     (Extremite2().getX()-Extremite1().getX()));
    monpoly.addPoint((int)Extremite1().getX()+(int)(Largeur_ext*Math.sin(alpha)),
		     (int)Extremite1().getY()-(int)(Largeur_ext*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite1().getX()-(int)(Largeur_ext*Math.sin(alpha)),
		     (int)Extremite1().getY()+(int)(Largeur_ext*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite2().getX()-(int)(Largeur_ext*Math.sin(alpha)),
		     (int)Extremite2().getY()+(int)(Largeur_ext*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite2().getX()+(int)(Largeur_ext*Math.sin(alpha)),
		     (int)Extremite2().getY()-(int)(Largeur_ext*Math.cos(alpha)));
    return monpoly;
  }


}
