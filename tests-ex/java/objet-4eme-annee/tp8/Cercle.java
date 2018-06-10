import java.util.*;
import java.awt.*;


class Cercle extends Noeud {


static private int Rayon = 5;
static private Color c = Color.orange;

public void dessine(Graphics g)
  {
    g.setColor(c);
    g.fillRect((int)centre().getX()-Rayon,
	       (int)centre().getY()-Rayon,
	       2*Rayon,
	       2*Rayon);
  }


public Polygon polygon_englobant() 
  {
    Polygon monpoly = new Polygon();
    monpoly.addPoint((int)centre().getX()-3*Rayon,
		     (int)centre().getY()-3*Rayon);
    monpoly.addPoint((int)centre().getX()+3*Rayon,
		     (int)centre().getY()-3*Rayon);
    monpoly.addPoint((int)centre().getX()+3*Rayon,
		     (int)centre().getY()+3*Rayon);
    monpoly.addPoint((int)centre().getX()-3*Rayon,
		     (int)centre().getY()+3*Rayon);
    return monpoly;
  }


}
