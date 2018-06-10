/* Copyleft (c) Guillaume Cottenceau Jan 1999
 *
 */

import java.util.*;
import java.applet.*;


public class MonEditeur extends GraphEditeur {


public void init()
  {
    super.init();
    String[] types = 
      {"Cercle","CercleP","Droite","Pointille"};
    super.set_types(types);
  }

}
