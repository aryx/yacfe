import java.util.*;
import java.awt.*;


class Droite extends Arc {

static private double Largeur = 5;
static private Color c = Color.blue;

public void dessine(Graphics g)
  {
    g.setColor(c);
    g.drawLine((int)Extremite1().getX(),
	       (int)Extremite1().getY(),
	       (int)Extremite2().getX(),
	       (int)Extremite2().getY());
  }


public Polygon polygon_englobant() 
  {
    Polygon monpoly = new Polygon();

      // Allez, on va lui faire un joli shape !
    double alpha = Math.atan((Extremite2().getY()-Extremite1().getY()) /
			     (Extremite2().getX()-Extremite1().getX()));
    monpoly.addPoint((int)Extremite1().getX()+(int)(Largeur*Math.sin(alpha)),
		     (int)Extremite1().getY()-(int)(Largeur*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite1().getX()-(int)(Largeur*Math.sin(alpha)),
		     (int)Extremite1().getY()+(int)(Largeur*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite2().getX()-(int)(Largeur*Math.sin(alpha)),
		     (int)Extremite2().getY()+(int)(Largeur*Math.cos(alpha)));
    monpoly.addPoint((int)Extremite2().getX()+(int)(Largeur*Math.sin(alpha)),
		     (int)Extremite2().getY()-(int)(Largeur*Math.cos(alpha)));
    return monpoly;
  }


}
