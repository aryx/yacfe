/*******************************************************************************
 *
 * Copyright (C) 1999-2000 by Y. Padioleau, G. Cottenceau, P. Garcia,
 *   G. LeGuelvouit, Y. Zemali, S. Crunchant, X. Michard.
 *
 * Please check out README.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 ******************************************************************************/

#include "RulesEditor.h"
#include "InterfaceUtils.h"
#include "AllPixmaps.h"
#include <math.h>

using namespace Gtk::Menu_Helpers;
using namespace Gtk::Toolbar_Helpers;


RulesEditor::RulesEditor()
  : BaseWindow() ,
    _imagePhiId(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapRed)),
    _imagePhiSup(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapBlue)),
    _imagePhiInf(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapGreen)),
    _imagePhiAny(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapGrey))
{
  set_title(_("Rules editor"));

  set_default_size(400, 400);

  Gtk::Menu * menu_edit = manage(new Gtk::Menu());
  MenuList& list_edit = menu_edit->items();

  Gtk::RadioMenuItem::Group my_gr_phis;
  list_edit.push_back(RadioMenuElem(my_gr_phis, _("Same Phi"), slot(*this, &RulesEditor::onActivateSamePhi)));
  _menuPhiId = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_phis, _("Lower than solid Phi"), slot(*this, &RulesEditor::onActivateUpperPhi)));
  _menuPhiSup = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_phis, _("Lower Phi"), slot(*this, &RulesEditor::onActivateLowerPhi)));
  _menuPhiInf = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_phis, _("Any Phi"), slot(*this, &RulesEditor::onActivateAnyPhi)));
  _menuPhiAny = &(list_edit.back());

  _menuBar.items().push_back(MenuElem(_("_Edit"), Gtk::Menu::AccelKey("<alt>e"), *menu_edit));
  


  makeHelpMenu();


  _imagePhiId.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imagePhiSup.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imagePhiInf.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imagePhiAny.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);


  _buttonPhiId.add(_imagePhiId);
  _buttonPhiSup.add(_imagePhiSup);
  _buttonPhiInf.add(_imagePhiInf);
  _buttonPhiAny.add(_imagePhiAny);



  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPhiId, _("Same Phi")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPhiSup, _("Lower than solid Phi")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPhiInf, _("Lower Phi")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPhiAny, _("Any Phi")));

  _buttonPhiId.signal_clicked().connect(slot(*this, &RulesEditor::onActivateSamePhi));
  _buttonPhiSup.signal_clicked().connect(slot(*this, &RulesEditor::onActivateUpperPhi));
  _buttonPhiInf.signal_clicked().connect(slot(*this, &RulesEditor::onActivateLowerPhi));
  _buttonPhiAny.signal_clicked().connect(slot(*this, &RulesEditor::onActivateAnyPhi));
  
  _statusBar.push(_("Configuration in progress..."));


  _noRecursivePlease = false;
  onActivateSamePhi();

  _myDrawingArea.signal_expose_event().connect(slot(*this, &RulesEditor::handleExposeDrawingArea));
  _myDrawingArea.signal_configure_event().connect(slot(*this, &RulesEditor::handleConfigureDrawingArea));
  _myDrawingArea.signal_button_press_event().connect(slot(*this, &RulesEditor::handleButtonPress));
  _myDrawingArea.signal_button_release_event().connect(slot(*this, &RulesEditor::handleButtonRelease));

  _myDrawingArea.set_events(Gdk::EXPOSURE_MASK
			    | Gdk::BUTTON_PRESS_MASK
			    | Gdk::BUTTON_RELEASE_MASK);

  initColors();

  _vbox.pack_start(_myDrawingArea);


  _buttonSave.set_sensitive(true);
  _menuSave->set_sensitive(true);
  _menuSaveAs->set_sensitive(true);

  _balls.reserve(_NB_BALLS);
  _arrows.reserve(_NB_BALLS);
  _allowed.reserve(_NB_BALLS);

  _selectedBall = -1;
  _filename = "";
  _correctedFilename = "";

  for (unsigned int i=0 ; i < _NB_BALLS; i++) 
    {
      _allowed[i] = RegleExclusion::CONTRAINTE_NULLE;
      _balls[i] = _grey;
    }

  _statusBar.pop();
  _statusBar.push(_("Ready"));

}

RulesEditor::~RulesEditor()
{
  for (unsigned int i=0 ; i<_NB_BALLS ; i++)
    delete _arrows[i];
  _arrows.clear();
  _balls.clear();
  delete _red;
  delete _blue;
  delete _green;
  delete _grey;
}

void RulesEditor::initColors()
{
  _red = InterfaceUtils::addColorDirect(65535, 0, 0);
  _blue = InterfaceUtils::addColorDirect(0, 0, 65535);
  _green = InterfaceUtils::addColorDirect(0, 65535, 0);
  _grey = InterfaceUtils::addColorDirect(40000, 40000, 40000);
}



bool RulesEditor::handleConfigureDrawingArea(GdkEventConfigure *event)
{
  if (!_myGc)
    {
      _myGc = Gdk::GC::create(get_window());
      _myGc->set_line_attributes(3, Gdk::LINE_SOLID, Gdk::CAP_NOT_LAST, Gdk::JOIN_MITER);

      for (unsigned int i=0 ; i<_NB_BALLS ; i++)
	_arrows[i] = new Arrow(_myGc, 0, 0, 2, 2, 2);
    }  

  int x, y, width, height, depth;
  _myDrawingArea.get_window()->get_geometry(x, y, width, height, depth);

  _pixmap = Gdk::Pixmap::create(_myDrawingArea.get_window(), width, height, -1);

  // centers of the balls
  if (width <= height)
    _ray = width/10; // we can put in equivalent, 5x5 balls in the drawing ares
  else 
    _ray = height/10;


  // processing of the centers
  int centreX = width / 2;
  int centreY = height / 2;

  _xBall[0] =  centreX - _ray;
  _yBall[0] =  centreY-4*_ray - _ray;
  _xBall[1] =  (gint) (centreX+sqrt(3.0)*2*_ray - _ray);
  _yBall[1] =  centreY-2*_ray - _ray;
  _xBall[2] =  (gint) (centreX+sqrt(3.0)*2*_ray - _ray);
  _yBall[2] =  centreY+2*_ray - _ray;
  _xBall[3] =  centreX - _ray;
  _yBall[3] =  centreY+4*_ray - _ray;
  _xBall[4] =  (gint) (centreX-sqrt(3.0)*2*_ray - _ray);
  _yBall[4] =  centreY+2*_ray - _ray;
  _xBall[5] =  (gint) (centreX-sqrt(3.0)*2*_ray - _ray);
  _yBall[5] =  centreY-2*_ray - _ray;
  
  _arrows[0]->ModifyExtremity(centreX, 
			      centreY - _ray,
			      centreX,
			      _yBall[0] + 2*_ray,
			      _ray);
  _arrows[1]->ModifyExtremity((int) (centreX + _ray*(sqrt(3.0)/2)), 
			      centreY - _ray/2,
			      (int) (_xBall[1] + _ray*(1-sqrt(3.0)/2)),
			      _yBall[1] + (_ray*3)/2,
			      _ray);
  _arrows[2]->ModifyExtremity((int) (centreX + _ray*(sqrt(3.0)/2)),
			      centreY + _ray/2,
			      (int) (_xBall[2] + _ray*(1-sqrt(3.0)/2)),
			      _yBall[2] + _ray/2,
			      _ray);
  _arrows[3]->ModifyExtremity(centreX, 
			      centreY + _ray,
			      centreX,
			      _yBall[3],
			      _ray);
  _arrows[4]->ModifyExtremity((int) (centreX - _ray*(sqrt(3.0)/2)),
			      centreY + _ray/2,
			      (int) (_xBall[4] + _ray*(1+sqrt(3.0)/2)),
			      _yBall[4] + _ray/2,
			      _ray);
  _arrows[5]->ModifyExtremity((int) (centreX - _ray*(sqrt(3.0)/2)),
			      centreY - _ray/2,
			      (int) (_xBall[5] + _ray*(1+sqrt(3.0)/2)),
			      _yBall[5] + (_ray*3)/2,
			      _ray);


  DEBUG_INTERFACE(
  for (unsigned int i=0 ; i < _NB_BALLS; i++) 
    {
      cout << "center ball number " << i << ":" << _xBall[i] << "," << _yBall[i] << endl;
    }
  cout << "drawing area size: " << width << height << endl;);
  
  drawBubble();
  return true;
}


bool RulesEditor::handleExposeDrawingArea(GdkEventExpose *event)
{
  g_assert(_myGc);

  _myDrawingArea.get_window()->draw_drawable(_myGc,
					     _pixmap,
					     event->area.x, event->area.y, event->area.x, event->area.y,
					     event->area.width, event->area.height);

  return false;
}


  
bool RulesEditor::handleButtonPress(GdkEventButton *event)
{
  // click
  int x,y; GdkModifierType state;
  
  gdk_window_get_pointer(event->window, &x, &y, &state);

  if (!((state & Gdk::BUTTON1_MASK) || (state & GDK_BUTTON2_MASK) || (state & GDK_BUTTON3_MASK)))
    return false;


  unsigned int i=0;
  bool trouve = false;
  gint xx = (gint)event->x;
  gint yy = (gint)event->y;
  _selectedBall = -1;
  _selectedArrow = -1;
  
  while ((i<_NB_BALLS) && (trouve==false))
    {
      if ( (xx < _xBall[i] + _ray*2) && 
	   (xx > _xBall[i]) &&
	   (yy < _yBall[i] + _ray*2) && 
	   (yy > _yBall[i]) )
	{
	  trouve = true;
	  _selectedBall=i;
	} 
      else
	i++;
    }
  if (trouve) return true;
  

  // else, we look if we did not click on an arrow
  i = 0;
  while ((i<_NB_BALLS) && (trouve==false))
    {
      if (_arrows[i]->isOn(xx, yy))
	{
	  trouve = true;
	  _selectedArrow=i;
	} 
      else
	i++;
    }
  

  return true;
}  



bool RulesEditor::handleButtonRelease(GdkEventButton *event)
{
  // release

  if ((event->x <= 0) || (event->y <= 0))
    return true;

  unsigned int i=0;
  bool trouve = false;
  gint xx = (gint)event->x;
  gint yy = (gint)event->y;
  int _boule_cliquee = -1;
  
  while((i<_NB_BALLS) && (trouve==false))
    {
      if ( (xx < _xBall[i] + _ray*2) && 
	   (xx > _xBall[i]) &&
	   (yy < _yBall[i] + _ray*2) && 
	   (yy > _yBall[i]) )
	{
	  trouve = true;
	  _boule_cliquee=i;
	} 
      else {i++;}
    }
  
  
  if ((_boule_cliquee == _selectedBall) && trouve)
    {
      switch(_selectionPhi)
	{
	case RegleExclusion::CONTRAINTE_MEMEPHI :
	  _balls[_selectedBall] = _red;   // _red = same phi's color
	  _allowed[_selectedBall] = RegleExclusion::CONTRAINTE_MEMEPHI;
	  _statusBar.pop();
	  _statusBar.push(_("Now, to enable the rule, that cell must be `same phi'"));
	  
	  break;
	case  RegleExclusion::CONTRAINTE_PHIINFSOLIDE :
	  _balls[_selectedBall] = _blue;   // _blue = phi sup's color
	  _allowed[_selectedBall] = RegleExclusion::CONTRAINTE_PHIINFSOLIDE;
	  _statusBar.pop();
	  _statusBar.push(_("Now, to enable the rule, that cell must be `phi inf solid'"));
	  break;
	  
	case  RegleExclusion::CONTRAINTE_PHIINFERIEUR :
	  _balls[_selectedBall] = _green;   // _green = phi inf's color
	  _allowed[_selectedBall] = RegleExclusion::CONTRAINTE_PHIINFERIEUR;
	  _statusBar.pop();
	  _statusBar.push(_("Now, to enable the rule, that cell must be `phi inf'"));
	  break;
	  
	case  RegleExclusion::CONTRAINTE_NULLE :
	  _balls[_selectedBall] = _grey;    // _grey = phi qq's color
	  _allowed[_selectedBall] = RegleExclusion::CONTRAINTE_NULLE;
	  _statusBar.pop();
	  _statusBar.push(_("Now, there is no constraint on this cell"));
	  break;
	  
	default:
	  cerr << "We must /never/ get there [3] ! " << endl;
	}  
      drawBubble();
      return true;
    }

  
  i = 0;
  trouve = false;
  int _fleche_cliquee = -1;

  while((i< _NB_BALLS) && (trouve==false))
    {
      if (_arrows[i]->isOn(xx, yy))
	{
	  trouve = true;
	  _fleche_cliquee = i;
	} 
      else {i++;}
    }
  
  
  if ((_fleche_cliquee == _selectedArrow) && trouve)
    {
      _arrows[_selectedArrow]->allowedMove(!_arrows[_selectedArrow]->isAllowedMove());
      if (_arrows[_selectedArrow]->isAllowedMove())
	_statusBar.push(_("Now, this movement is allowed"));
      else
	_statusBar.push(_("Now, this movement is forbidden"));
    }
  
  
  drawBubble();
  return true;
}


void RulesEditor::onOkFileOpen()
{
  RegleExclusion * regle;

  // Opening of a rule file (.regle)
  DEBUG_INTERFACE(cout << "[RulesEditor::onOkFileOpen] enter" << endl;);

  _filename = _winFileSelection->get_filename();
    
  DEBUG_INTERFACE(cout << "[RulesEditor::onOkFileOpen] trying to open: " << nom_fichier << endl;);

  // We read the file and put it in _regle
  std::ifstream filestream(const_cast<char*>(_filename.c_str()));

  if (!filestream)
    {
      popupErrorWindow(_("File not found !"));
      _filename = "";
      _correctedFilename = "";
      set_title(_("Rules editor : new file"));
      drawBubble();
      return;
    }
  else
    {
      regle = new (RegleExclusion);

      int results = StaticIOs::parseMaRegle(filestream, *regle);
	  
      if (results != 0)
	{
	  popupErrorWindow(_("Error while reading the file...\nAre you sure this was a rule file?"));
	  _filename = "";
	  _correctedFilename = "";
	  set_title(_("Rules editor : new file"));
	  drawBubble();
	}

      _correctedFilename = regle->getNom();

      for (unsigned int i=0 ; i < _NB_BALLS; i++) 
	{
	  _allowed[i] = regle->getContrainte(i);
	  _balls[i] = color(_allowed[i]);
	  _arrows[i]->allowedMove(moveThroughAllowed(regle->getDeplacement(i)));
	
	}
      delete regle;

      set_title(_("Rules editor : ")+_correctedFilename);
      drawBubble();
    }

  DEBUG_INTERFACE(DEBUG_INTERFACE(cout << "[RulesEditor::onOkFileOpen] leave" << endl;););

  onCloseFileSelection();
}


RegleExclusion * RulesEditor::convertsToRegleExclusion()
{
  // Converts the data structure.
  g_assert(_correctedFilename != "");

  RegleExclusion::Paire paar[_NB_BALLS];

  for (unsigned int i=0 ; i < _NB_BALLS; i++) 
    {
      paar[i].contrainte = _allowed[i];
      paar[i].deplacement = (_arrows[i]->isAllowedMove())?RegleExclusion::DEPLPOSSIBLE:RegleExclusion::DEPLIMPOSSIBLE;
    }

  return new RegleExclusion(_correctedFilename, paar);
}


void RulesEditor::onFileNew()
{
  _selectedBall = -1;
  _filename = "";
  _correctedFilename = "";

  for (unsigned int i=0 ; i < _NB_BALLS; i++) 
    {
      _allowed[i] = RegleExclusion::CONTRAINTE_NULLE;
      _balls[i] = _grey;
      _arrows[i]->allowedMove(true);
    }

  drawBubble();
}


void RulesEditor::onFileSave()
{
  if (_filename == "")
    onFileSaveAs();
  else
    {
      std::ofstream filestream(const_cast<char*>(_filename.c_str()));
      if (!filestream)
	{
	  popupErrorWindow(_("Error while writing the file..."));
	  _filename = "";
	  _correctedFilename = "";
	  set_title(_("Rules editor : new file"));
	}
      else
	{
	  RegleExclusion * regle = convertsToRegleExclusion();
	  filestream << * regle;
	  set_title(_("Rules editor : ")+_correctedFilename);
	  popupWarningWindow(_("You have erased the previous file named :\n")+_filename);
	}
    }
}


void RulesEditor::onOkFileSaveAs()
{
  DEBUG_INTERFACE(DEBUG_INTERFACE(cout << "[RulesEditor::onOkFileSaveAs] enter" << endl;););

  _filename = _winFileSelection->get_filename();

  // let's keep only the filename
  int j = _filename.find_last_of("/") + 1;
  _correctedFilename = string(_filename.begin()+j, _filename.end());

  // let's remove all after the . the extension if there is one.
  int k = _correctedFilename.find_last_of(".");

  if (k != -1)
    {
      // no point, so no extension.
      _correctedFilename = string(_correctedFilename.begin(), _correctedFilename.begin()+k);
    }
  // else: a point. an extension.

  for (unsigned int i=0 ; i< _correctedFilename.size() ; i++)
    {
      char char_to_test = _correctedFilename[i];
      if (!(((char_to_test >= 'a') && (char_to_test <= 'z')) ||
	    ((char_to_test >= 'A') && (char_to_test <= 'Z')) ||
	    ((char_to_test >= '0') && (char_to_test <= '9'))))
	{
	  bool ok_char = false;
	  for (unsigned int j=0 ; j< sizeof(allowedSpecialChars) ; j++)
	    if (char_to_test == allowedSpecialChars[j])
	      ok_char = true;
	  if (!ok_char)
	    {
	      popupErrorWindow(_("The value entered for `name' is not valid. It must not contain spaces nor special characters."));
	      return;
	    }
	}
    }



  DEBUG_INTERFACE(cout << "[RulesEditor::onOkFileSaveAs] Corrected file name used for the `name' of the rule: " << nom_fichier_corrige << endl;);


  RegleExclusion * regle = convertsToRegleExclusion();

  std::ofstream filestream(const_cast<char*>(_filename.c_str()));

  if (!filestream)
    {
      popupErrorWindow(_("Error while writing the file..."));
      _filename = "";
      set_title(_("Rules editor : new file"));
    }
  else
    {
      filestream << * regle;
      set_title(_("Rules editor : ")+_correctedFilename);
    }
  

  DEBUG_INTERFACE(DEBUG_INTERFACE(cout << "[RulesEditor::onOkFileSaveAs] leave" << endl;);)

  onCloseWritingFileSelection();
}


void RulesEditor::onNewbieHelp()
{
  popupNewbieHelp(_("This is the Rules Editor.\nHere you will design an exclusion rule applicable to the phases.\nTo setup your rule, you may:\n1. dictate conditions on the neighbourhood by the colors symbols.\n2. forbid some movements by clicking on the arrows."));
}


string RulesEditor::getSavedRuleFilename()
{
  return _filename;
}

string RulesEditor::getSavedRuleName()
{
  return _correctedFilename;
}


// Now two methods used to convert the data structures from the one used here to the one used in the engine.

Gdk::Color * RulesEditor::color(RegleExclusion::Contrainte constraint)
{
  if (constraint == RegleExclusion::CONTRAINTE_NULLE)
    return _grey;
  else
    if (constraint == RegleExclusion::CONTRAINTE_MEMEPHI) 
      return _red;
    else
      if (constraint == RegleExclusion::CONTRAINTE_PHIINFERIEUR)
	return _green;
      else
	if (constraint == RegleExclusion::CONTRAINTE_PHIINFSOLIDE)
	  return _blue;
  cerr << "[RulesEditor::color] d'better save your work QUICKLY" << endl;
  return NULL;
}


bool RulesEditor::moveThroughAllowed(RegleExclusion::Deplacement dep)
{
 return (dep == RegleExclusion::DEPLPOSSIBLE);
}


void RulesEditor::onActivateSamePhi()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _selectionPhi =  RegleExclusion::CONTRAINTE_MEMEPHI ;

  _buttonPhiId.set_active(true);
  _buttonPhiAny.set_active(false);
  _buttonPhiInf.set_active(false);
  _buttonPhiSup.set_active(false);

  _menuPhiId->activate();

  _noRecursivePlease = false;

  _statusBar.pop();
  _statusBar.push(_("Clic on a bubble to set it `same phi'"));
}


void RulesEditor::onActivateUpperPhi()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _selectionPhi =  RegleExclusion::CONTRAINTE_PHIINFSOLIDE ;

  _buttonPhiId.set_active(false);
  _buttonPhiAny.set_active(false);
  _buttonPhiInf.set_active(false);
  _buttonPhiSup.set_active(true);

  _menuPhiSup->activate();

  _noRecursivePlease = false;


  _statusBar.pop();
  _statusBar.push(_("Clic on a bubble to set it `lower than solid Phi'"));

}


void RulesEditor::onActivateLowerPhi()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _selectionPhi =  RegleExclusion::CONTRAINTE_PHIINFERIEUR ;

  _buttonPhiId.set_active(false);
  _buttonPhiAny.set_active(false);
  _buttonPhiInf.set_active(true);
  _buttonPhiSup.set_active(false);

  _menuPhiInf->activate();

  _noRecursivePlease = false;

  _statusBar.pop();
  _statusBar.push(_("Clic on a bubble to set it `lower phi'"));

}


void RulesEditor::onActivateAnyPhi()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _selectionPhi = RegleExclusion::CONTRAINTE_NULLE ;

  _buttonPhiId.set_active(false);
  _buttonPhiAny.set_active(true);
  _buttonPhiInf.set_active(false);
  _buttonPhiSup.set_active(false);

  _menuPhiAny->activate();

  _noRecursivePlease = false;

  _statusBar.pop();
  _statusBar.push(_("Clic on a bubble to set it `any phi'"));

}




void RulesEditor::drawBubble()
{
  DEBUG_INTERFACE(cout << "appel de drawbubble" << endl;);

  int x, y, width, height, depth;
  _myDrawingArea.get_window()->get_geometry(x, y, width, height, depth);
  
  _myGc->set_foreground(InterfaceUtils::getColorWhite());
  _pixmap->draw_rectangle(_myGc, true, 0, 0, width, height);

  // draw the balls
  for (unsigned int i = 0; i< _NB_BALLS; i++)
    {
      _myGc->set_foreground(*_balls[i]);
      _pixmap->draw_arc(_myGc, true, _xBall[i], _yBall[i], _ray*2, _ray*2, 0, 360*64); 
      
      _arrows[i]->drawYourself(_pixmap);
    }
  
  _myGc->set_foreground(*_red);
  _pixmap->draw_arc(_myGc, true, width/2 - _ray, height/2 - _ray, _ray*2, _ray*2, 0, 360*64); 
  
  _myGc->set_foreground(InterfaceUtils::getColorBlack());

  queue_draw();
}
