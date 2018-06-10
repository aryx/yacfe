import java.util.*;
import java.awt.*;


class CercleP extends Noeud {


static private int Rayon = 5;
static private Color c = Color.pink;

public void dessine(Graphics g)
  {
    g.setColor(c);
    g.fillOval((int)centre().getX()-Rayon,
	       (int)centre().getY()-Rayon,
	       2*Rayon,
	       2*Rayon);
  }


public Polygon polygon_englobant() 
  {
    Polygon monpoly = new Polygon();
    monpoly.addPoint((int)centre().getX()-2*Rayon,
		     (int)centre().getY()-2*Rayon);
    monpoly.addPoint((int)centre().getX()+2*Rayon,
		     (int)centre().getY()-2*Rayon);
    monpoly.addPoint((int)centre().getX()+2*Rayon,
		     (int)centre().getY()+2*Rayon);
    monpoly.addPoint((int)centre().getX()-2*Rayon,
		     (int)centre().getY()+2*Rayon);
    return monpoly;
  }

}
