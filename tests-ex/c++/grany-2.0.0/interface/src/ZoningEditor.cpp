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

#include "ZoningEditor.h"
#include "AllPixmaps.h"


ZoningEditor::ZoningEditor(vector<Phase*> phases, list<Frontiere*> frt, list<Zonage*> zon)
  : AreaEditor(frt),
    _labelMix(_("Relative mix of phases:")),
    _buttonApplyMelange(__("Apply mix to selected area"))
{

  set_title(_("Zoning editor"));

  _buttonApplyMelange.set_sensitive(false);

  _drawingArea.signal_motion_notify_event().connect(slot(*this, &ZoningEditor::handleMotionNotify));
  _drawingArea.signal_button_press_event().connect(slot(*this, &ZoningEditor::handleButtonPress));
  _drawingArea.signal_button_release_event().connect(slot(*this, &ZoningEditor::handleButtonRelease));

  _buttonApplyMelange.signal_clicked().connect(slot(*this, &ZoningEditor::onActivateApplyMix));

  // We create the zonings if there are some
  list<Zonage*>::const_iterator itz;
      
  for (itz = zon.begin(); itz != zon.end(); itz++)
    {
      if (ContientPhase * cp = dynamic_cast<ContientPhase*>((*itz)->getContenuZonage()))
	createFormZoning((*itz)->getFormeFermee(), cp);
      else
	cerr << "[ZoningEditor::ZoningEditor] I won't fill with CelluleHorsScene, sorry." << endl;
    }


  _options.pack_start(_labelMix, false, false, 5);

  _phases = phases;

  // We fill up _slidersPhases by some sliders (Gtk::Adjustment), one for each phase. With the color of the phase, waaoooo cutie cutie.
  for (unsigned int i=0 ; i<_phases.size() ; i++)
    {
      // TODO : these things are never freed. gc.

      Gtk::Adjustment *slider = new Gtk::Adjustment(100, 0, 100); 
      _slidersPhases.push_back(slider);

      Gtk::HBox *box = new Gtk::HBox(true);

      Gtk::Label *lbl = new Gtk::Label(_phases[i]->getNom());
      Gtk::HScale *hs = new Gtk::HScale(*slider);

      Glib::RefPtr<Gtk::Style> style = hs->get_style()->copy();
      style->set_bg(Gtk::STATE_NORMAL, *InterfaceUtils::getColorAuxiliary(_phases[i]->getCouleur()));
      style->set_bg(Gtk::STATE_PRELIGHT, InterfaceUtils::lighter(*new Gdk::Color(*InterfaceUtils::getColorAuxiliary(_phases[i]->getCouleur()))));
      hs->set_style(style);

      box->pack_start(*lbl, true, true, 5);
      box->pack_end(*hs, true, true, 5);

      _options.pack_start(*box, false, false, 5);
    }

  _options.pack_end(_buttonApplyMelange, false, false, 5);
  
  _statusBar.pop();
  _statusBar.push(_("Ready."));
}


ZoningEditor::~ZoningEditor()
{
  // BIG TODO: lots of things to delete
}


void ZoningEditor::onActivateNew()
{
  // TODO "do you want to save your work, boulet ?" gc.

  // TODO free
  _listZonage.clear();
  _drawingArea.clearZonings();
  _drawingArea.drawFigures();
}


void ZoningEditor::onNewbieHelp()
{
  popupNewbieHelp(_("This is the Zoning Editor.\n"
		    "Here you will setup the initial positions of the phases:\n"
		    "1. Setup the desired phases mix with the sliders on the right.\n"
		    "2. Create your geometrical filled form:\n"
		    "\ta. A rectangle or an ellipse by click-drag-drop.\n"
		    "\tb. A polygon by click-drag-drop, then clicks, then right-click."));
}


/** Description.
 *
 * Okay here is (in other locations of Grany too) my initial multiple inheritance problem.
 *
 * 1. Have a look at GtkFigures.h for the way we use multiple inheritance.
 *
 * 2. When I create a zoning I store it as a drawing in the GranyDrawingArea, but I also
 *    create on-the-fly the list<Zonage*> wanted for the creation of the Scene.
 *    Problem is: the list of drawings is a list of GtkForm*
 *                the list of Zonage* handles a list of Forme*
 *
 * 3. So, as here we have multiple inheritance from Forme and GtkForm, when we
 *    look at an object as a Forme* it has the same address as the original object
 *    because this is the first declared mother class.
 *    But if we look at it as a GtkForm*, we just /lost/ some information because
 *    this is the second mother class. And this lost of info is reflected as the
 *    address of the pointer because the address of the object as the info about the
 *    Forme* but this info has been lost so the pointer is /translated/ of the value
 *    of the size of Forme.
 *
 * 4. Now when we want to find an object in the list<Zonage*> we must find a way
 *    to get the pointer comparison working.
 *    Several ideas has been brought. The best, to my mind, (I found it! :-)), is
 *    to perform a dynamic_cast<GtkForm*> on our Forme*
 *
 * Hope you understood. (but not sure as I know my qualities for explaining...)
 *
 * <gcottenc at altern dot org>
 *
 * PS: a friend of mine, `master of c++', found the factorization to cast the
 *  constant-over-the-for-statement GtkForm* into a Forme
 */

vector<PhasePourcent> * ZoningEditor::findPhasePercentage(GtkForm * dforme)
{
  for (list<Zonage*>::iterator it = _listZonage.begin() ;
	   it != _listZonage.end() ;
	   it++)
    if (dynamic_cast<Forme*>(dforme) == (*it)->getFormeFermee())
      if (ContientPhase * cp = dynamic_cast<ContientPhase*>((*it)->getContenuZonage()))
	return cp->getPhasePourcent();
      else
	cerr << "[ZoningEditor::findPhasePercentage] Il y a un ContenuZonage qui n'est pas un ContientPhase dans la liste des zonages" << endl;
  return NULL;
}



bool ZoningEditor::handleButtonPress(GdkEventButton *event)
{
  // click
  
  int x,y; GdkModifierType state;
  gdk_window_get_pointer(event->window, &x, &y, &state);
  if (!((state & GDK_BUTTON1_MASK) || (state & GDK_BUTTON2_MASK) || (state & GDK_BUTTON3_MASK)))
    return false;

  if (_selectedArea != NULL)
    {
      _selectedArea->setSelection(false);
      _selectedArea = NULL;
      _buttonDelete.set_sensitive(false);
      _buttonApplyMelange.set_sensitive(false);
      _menuDelete->set_sensitive(false);
    }

  gint rx, ry;
  if (_isGrid)
    InterfaceUtils::granularity((gint)event->x, (gint)event->y, &rx, &ry);
  else
    { rx = (gint)event->x; ry = (gint)event->y; }
  

  // Special case if this is a double-click : we'll delete the pointed object
  if (event->type == GDK_2BUTTON_PRESS)
    {
      GtkForm * my_selection;
      my_selection = _drawingArea.findSelectedZoning((gint)event->x, (gint)event->y);
      if (my_selection != NULL)
	{
	  _selectedArea = my_selection;
	  deleteSelectedArea();
	  _buttonDelete.set_sensitive(false);
	  _buttonApplyMelange.set_sensitive(false);
	  _menuDelete->set_sensitive(false);
	}
    }
  
  // If this is a simple-click...
  else

  switch (_typeAction)
    {
    case SELECTION:
      GtkForm * my_selection;
      my_selection = _drawingArea.findSelectedZoning((gint)event->x, (gint)event->y);
      if (my_selection != NULL)
	{
	  _selectedArea = my_selection;
	  _selectedArea->setSelection(true);
	  modifySlidersPositions(findPhasePercentage(_selectedArea));
	  _statusBar.pop();
	  _statusBar.push(_("Element selected."));
	  _buttonDelete.set_sensitive(true);
	  _buttonApplyMelange.set_sensitive(true);
	  _menuDelete->set_sensitive(true);
	}
      break;


    case RECTANGLE:
      if (_drawingArea._rectangleInProgress != NULL)
	delete _drawingArea._rectangleInProgress;
      _drawingArea._rectangleInProgress = new GtkRectangle(_grey, rx, ry, rx, ry);

      _statusBar.pop();
      _statusBar.push(_("New rectangle, origine : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+_("). Drag for the end."));
      break;


    case POLYGONE:
      if (_drawingArea._polygonAreaInProgress != NULL)
	{
	  // We clicked for adding a line or terminating the polygon
	  if (_drawingArea._lineInProgress->isInvalid())
	    {
	      _statusBar.pop();
	      _statusBar.push(_("The line is not valid."));
	    }
	  else
	    {
	      _drawingArea._lineInProgress->modifyEnd(rx,ry);
	      _drawingArea._line2InProgress->modifyEnd(rx,ry);

	      _drawingArea._polygonAreaInProgress->ajoutLigne(_drawingArea._lineInProgress);

	      if (state & GDK_BUTTON1_MASK)
		{
		  // Button 1 -> adding a line
		  _statusBar.pop();
		  _statusBar.push(_("Left button for another line, right button to end."));

		  _drawingArea._lineInProgress = new GtkLine(_grey, rx, ry, rx, ry);
		}
	      else
		if ((state & GDK_BUTTON2_MASK) || (state & GDK_BUTTON3_MASK))
		  {
		    // Button 2 -> last line, terminating polygon
		    GtkPolygon * dp = new GtkPolygon(_drawingArea._polygonAreaInProgress, createColorFromSliders());
		    dp->close();
		    _drawingArea.addFigureZoning(dp);
		    Zonage * zon = new Zonage(dp, new ContientPhase(percentageCurrentPhases()));
		    _listZonage.push_back(zon);

		    _drawingArea._polygonAreaInProgress = NULL;
		    _drawingArea._lineInProgress = NULL;
		    delete _drawingArea._line2InProgress;
		    _drawingArea._line2InProgress = NULL;
		  }
	    }
	}
      else
	{
	  // We click for a new polygon
	  _drawingArea._lineInProgress = new GtkLine(_grey, rx, ry, rx, ry);
	  _drawingArea._line2InProgress = new GtkLine(_grey, rx, ry, rx, ry);
	  _drawingArea._line2InProgress->setTemporary(true);
	  _statusBar.pop();
	  _statusBar.push(_("New polygone, origine : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+_("). Drag."));
	}
      break;


    case ELLIPSE:
      if (_drawingArea._ellipseInProgress != NULL)
	delete _drawingArea._ellipseInProgress;
      _drawingArea._ellipseInProgress = new GtkEllipse(_grey, rx, ry);
      _statusBar.pop();
      _statusBar.push(_("New ellipse, origine : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+_("). Drag for the end."));
      break;
      
      
    default:
      cerr << "On ne doit jamais arriver là [1] ! " << endl;
    }

  _drawingArea.drawFigures();
  return true;
}


bool ZoningEditor::handleMotionNotify(GdkEventMotion *event)
{
  /* I did not understand the gdk_window_get_pointer.

     Apparently it's used to init correctly the GdkModifierType which contains then the information
     in relation to the mouse buttons.

     I looked for an equivalent in gdk-- but I did not find some. (the Gtk::Widget::get_pointer does not have GdkModifierType or equivalent!)
     (The only location where there is GdkModifierType is the class Gtk::AccelGroup but this is documented like shit.)

     (therefore, copied from the Gtk+ Tutorial and terraform)
     
     gc.
  */
  int x, y;
  GdkModifierType state;

  gint rx, ry;

  if ((event->x < 0) || (event->y < 0))
    return true;

  if (_preSelectedArea != NULL)
    _preSelectedArea->setPreSelection(false);
  _preSelectedArea = NULL;

  if (_isGrid)
    InterfaceUtils::granularity((gint)event->x, (gint)event->y, &rx, &ry);
  else
    { rx = (gint)event->x; ry = (gint)event->y; }

  if (event->is_hint)
    gdk_window_get_pointer(event->window, &x, &y, &state);
  else
    {  
      x = (int)event->x;
      y = (int)event->y;
      state = (GdkModifierType) event->state;
      cerr << "??" << endl; // je l'ai jamais eu ce truc. je sais pas ce que c'est.
    }
    
  if (state & GDK_BUTTON1_MASK)
    {
      // drag

      if (_typeAction != SELECTION)
	{

	  if (_drawingArea._polygonAreaInProgress != NULL) return true;

	  if (_drawingArea._lineInProgress != NULL)
	    {
	      _drawingArea._lineInProgress->modifyEnd(rx, ry);
	      gint x1,y1,x2,y2;
	      _drawingArea._lineInProgress->gimmeYourCoordinates(&x1, &y1, &x2, &y2);
	      _statusBar.pop();
	      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(x1)+","+InterfaceUtils::intToString(y1)+";"+InterfaceUtils::intToString(x2)+","+InterfaceUtils::intToString(y2)+").");
	      _drawingArea.drawFigures();
	    }

	  if (_drawingArea._rectangleInProgress != NULL)
	    {
	      _drawingArea._rectangleInProgress->modifyEnd(rx, ry);
	      gint x1, y1, x2, y2;
	      _drawingArea._rectangleInProgress->gimmeYourCoordinates(&x1, &y1, &x2, &y2);
	      _statusBar.pop();
	      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(x1)+","+InterfaceUtils::intToString(y1)+";"+InterfaceUtils::intToString(x2)+","+InterfaceUtils::intToString(y2)+").");
	      _drawingArea.drawFigures();
	    }

	  if (_drawingArea._ellipseInProgress != NULL)
	    {
	      _drawingArea._ellipseInProgress->ModifyExtremity(rx, ry, state);
	      gint x, y, l, h;
	      _drawingArea._ellipseInProgress->gimmeYourCoordinates(&x, &y, &l, &h);
	      _statusBar.pop();
	      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(x)+","+InterfaceUtils::intToString(y)+";l="+InterfaceUtils::intToString(l)+";h="+InterfaceUtils::intToString(h)+").");
	      _drawingArea.drawFigures();
	    }
	}	  
      
    }
  else
    {
      // button is not kept clicked. free move.

      _statusBar.pop();
      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+").");
      
      switch (_typeAction)
	{
	case SELECTION:

	  // highlight. :) gc.
	  GtkForm * my_selection;
	  my_selection = _drawingArea.findSelectedZoning((gint)event->x, (gint)event->y);
	  if (my_selection != NULL)
	    {
	      _preSelectedArea = my_selection;
	      _preSelectedArea->setPreSelection(true);
	    }
	  
	  _drawingArea.drawFigures();
	  break;

	  
	case RECTANGLE:
	  break;


	case POLYGONE:
	  if (_drawingArea._lineInProgress != NULL)
	    {
	      g_assert((_drawingArea._lineInProgress != NULL) && (_drawingArea._line2InProgress != NULL));

	      _drawingArea._lineInProgress->modifyEnd(rx, ry);
	      _drawingArea._line2InProgress->modifyEnd(rx, ry);
	      gint x1,y1,x2,y2;
	      _drawingArea._lineInProgress->gimmeYourCoordinates(&x1, &y1, &x2, &y2);
	      _statusBar.pop();
	      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(x1)+","+InterfaceUtils::intToString(y1)+";"+InterfaceUtils::intToString(x2)+","+InterfaceUtils::intToString(y2)+").");
	      _drawingArea.drawFigures();
	    }
	  break;
	  
	case ELLIPSE:
	  break;
	  
	default:
	  cerr << "On ne doit jamais arriver là [2bis] ! " << endl;
	}
      
    }

  return true;
}


// Will create the color and send it back, from the position of the slider for each phase.
Gdk::Color * ZoningEditor::createColorFromSliders()
{
  gdouble r, g, b;
  r = g = b = 0;

  gdouble intensities = 0, values = 0;

  for (unsigned int i=0; i<_slidersPhases.size() ; i++)
    {
      gdouble value = _slidersPhases[i]->get_value();
      Gdk::Color * coul = InterfaceUtils::getColorAuxiliary(_phases[i]->getCouleur());
      r += value*coul->get_red();
      g += value*coul->get_green();
      b += value*coul->get_blue();
      intensities += value*MAX(MAX(coul->get_red(), coul->get_green()), coul->get_blue());
      values += value;
    }

  gdouble max;
  if ((r>=g) && (r>=b)) max = r;
  else
    if ((g>=r) && (g>=b)) max = g;
    else
      max = b;

  max /= intensities/values;

  return InterfaceUtils::addColorDirect((gushort)(r/max), (gushort)(g/max), (gushort)(b/max));
}


// Will create the vector<PhasePourcent> associated with the position of each one of the sliders.
vector<PhasePourcent> ZoningEditor::percentageCurrentPhases()
{
  vector<PhasePourcent> vect;

  for (unsigned int i=0; i<_slidersPhases.size() ; i++)
    {
      gdouble value = _slidersPhases[i]->get_value();
      if (value != 0)
	{
	  PhasePourcent nouvelle_entree;
	  nouvelle_entree.phase = _phases[i];
	  nouvelle_entree.pourcentage = value;
	  vect.push_back(nouvelle_entree);
	}
    }

  return vect;
}


// Will update the position of the sliders according to the vector<PhasePourcent>.
void ZoningEditor::modifySlidersPositions(vector<PhasePourcent> * vect)
{
  if (vect == NULL) return;

  for (unsigned int j=0; j<_slidersPhases.size() ; j++)
    _slidersPhases[j]->set_value(0);

  // scan of the PhasePourcent vector
  for (unsigned int i=0; i<vect->size() ; i++)
    // looking, in the sliders, for the number of the phase
      for (unsigned int j=0; j<_slidersPhases.size() ; j++)
	if ((*vect)[i].phase == _phases[j])
	  _slidersPhases[j]->set_value((*vect)[i].pourcentage);
}



bool ZoningEditor::slidersAtLeastOne()
{
  for (unsigned int i=0; i<_slidersPhases.size() ; i++)
      if (_slidersPhases[i]->get_value() > 0) return true;

  popupErrorWindow(_("You must have at least a little bit of one phase !"));
  return false;
}


bool ZoningEditor::handleButtonRelease(GdkEventButton *event)
{

  // release
  gint rx, ry;

  if ((event->x < 0) || (event->y < 0))
    return true;

  if (_isGrid)
    InterfaceUtils::granularity((gint)event->x, (gint)event->y, &rx, &ry);
  else
    { rx = (gint)event->x; ry = (gint)event->y; }

  switch (_typeAction)
    {
    case SELECTION:
      break;

    case RECTANGLE:
      if (_drawingArea._rectangleInProgress != NULL)
	{
	  if (_drawingArea._rectangleInProgress->isInvalid())
	    {
	      _statusBar.pop();
	      _statusBar.push(_("The rectangle is not valid."));
	      delete _drawingArea._rectangleInProgress;
	    }
	  else
	    {
	      if (slidersAtLeastOne())
		{
		  _drawingArea._rectangleInProgress->setColor(createColorFromSliders());

		  Zonage * zon = new Zonage(_drawingArea._rectangleInProgress, new ContientPhase(percentageCurrentPhases()));
		  _listZonage.push_back(zon);

		  _drawingArea.addFigureZoning(_drawingArea._rectangleInProgress);

		  _statusBar.pop();
		  _statusBar.push(_("Rectangle added."));
		}
	    }
	  _drawingArea._rectangleInProgress = NULL;
	}
      break;


    case ELLIPSE:
      if (_drawingArea._ellipseInProgress != NULL)
	{
	  if (_drawingArea._ellipseInProgress->isInvalid())
	    {
	      _statusBar.pop();
	      _statusBar.push(_("The ellipse is not valid."));
	      delete _drawingArea._ellipseInProgress;
	    }
	  else
	    {
	      if (slidersAtLeastOne())
		{
		  _drawingArea._ellipseInProgress->setColor(createColorFromSliders());

		  Zonage * zon = new Zonage(_drawingArea._ellipseInProgress, new ContientPhase(percentageCurrentPhases()));
		  _listZonage.push_back(zon);

		  _drawingArea.addFigureZoning(_drawingArea._ellipseInProgress);
		  _statusBar.pop();
		  _statusBar.push(_("Rectangle added."));
		}
	    }
	  _drawingArea._ellipseInProgress = NULL;
	}
      break;


    case POLYGONE:
      if ((_drawingArea._polygonAreaInProgress == NULL) && (_drawingArea._lineInProgress != NULL))
	{
	  // Release of the button -> first line.
	  if (_drawingArea._lineInProgress->isInvalid())
	    {
	      _statusBar.pop();
	      _statusBar.push(_("The line is not valid. Please give the first line again."));
	      delete _drawingArea._lineInProgress;
	      delete _drawingArea._line2InProgress;
	      _drawingArea._lineInProgress = NULL;
	      _drawingArea._line2InProgress = NULL;
	    }
	  else
	    {
	      _drawingArea._polygonAreaInProgress = new GtkPolygon(_grey);

	      _statusBar.pop();
	      _statusBar.push(_("Left button for another line, right button to end."));

	      _drawingArea._lineInProgress->modifyEnd(rx,ry);
	      _drawingArea._line2InProgress->modifyEnd(rx,ry);
	      _drawingArea._polygonAreaInProgress->ajoutLigne(_drawingArea._lineInProgress);
	      _drawingArea._lineInProgress = new GtkLine(_grey, rx, ry, rx, ry);
	    }
	}
      break;

      
    default:
      cerr << "On ne doit jamais arriver là [3] ! " << endl;
    }

  _drawingArea.drawFigures();
  return true;
}



void ZoningEditor::onActivateApplyMix()
{
  // We have to apply the mix to the selected zoning
  if (!slidersAtLeastOne()) return;
    
  // In case my insensitivity does not work, let's test if a zoning is selected...
  if (_selectedArea != NULL)
    {
      _selectedArea->setColor(createColorFromSliders());

      for (list<Zonage*>::iterator it = _listZonage.begin() ;
	   it != _listZonage.end() ;
	   it++)
	if (dynamic_cast<Forme*>(_selectedArea) == (*it)->getFormeFermee())
	    (*it)->setContenuZonage(new ContientPhase(percentageCurrentPhases()));

      _drawingArea.drawFigures();
    }
  else
    popupErrorWindow(_("No area selected !"));
}


void ZoningEditor::deleteSelectedArea()
{
  if (_selectedArea != NULL)
    {
      for (list<Zonage*>::iterator it = _listZonage.begin() ;
	   it != _listZonage.end() ;
	   it++)
	if (dynamic_cast<Forme*>(_selectedArea) == (*it)->getFormeFermee())
	  {
	    _listZonage.erase(it);
	    break;
	  }
      
      _drawingArea.removeFigure(_selectedArea);
      if (_preSelectedArea == _selectedArea)
	_preSelectedArea = NULL;
      delete _selectedArea;
      _selectedArea = NULL;
      _drawingArea.drawFigures();
      _statusBar.pop();
      _statusBar.push(_("Element deleted."));
    }
}


void ZoningEditor::createFormZoning(FormeFermee * f, ContientPhase * cp)
{
  Gdk::Color * col = InterfaceUtils::createColorFromMix(cp);
  
  if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
    {
      GtkRectangle * dr = new GtkRectangle(arg, col);
      _drawingArea.addFigureZoning(dr);
      _listZonage.push_back(new Zonage(dr, cp));
      return;
    }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _drawingArea.addFigureZoning(de);
	  _listZonage.push_back(new Zonage(de, cp));
	  return;
	}
      else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _drawingArea.addFigureZoning(dp);
	      _listZonage.push_back(new Zonage(dp, cp));
	      return;
	    }
  
  cerr << "[ZoningEditor::createFormZoning] There is a problem, I don't handle all the forms..." << endl;
}


list<Zonage*> ZoningEditor::getListZonage()
{
  return _listZonage;
}
