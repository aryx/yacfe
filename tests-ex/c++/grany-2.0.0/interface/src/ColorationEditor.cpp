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

#include "ColorationEditor.h"
#include "AllPixmaps.h"


ColorationEditor::ColorationEditor(list<Frontiere*> frt, list<Zonage*> zon, list<Coloration*> col)
  : AreaEditor(frt),
    _buttonColor(__("Choose color")),
    _buttonRandomize(__("Automatic random color"))
{

  set_title(_("Coloration editor"));

  _drawingArea.signal_motion_notify_event().connect(slot(*this,&ColorationEditor::handleMotionNotify));
  _drawingArea.signal_button_press_event().connect(slot(*this,&ColorationEditor::handleButtonPress));
  _drawingArea.signal_button_release_event().connect(slot(*this,&ColorationEditor::handleButtonRelease));

  // We create the zonings if there are some
  list<Zonage*>::const_iterator itz;
      
  for (itz = zon.begin(); itz != zon.end(); itz++)
    if (ContientPhase * cp = dynamic_cast<ContientPhase*>((*itz)->getContenuZonage()))
      createFormZoning((*itz)->getFormeFermee(), cp);
    else
      cerr << "[ZoningEditor::ZoningEditor] I won't fill with CelluleHorsScene, sorry." << endl;

  _options.pack_start(_buttonColor, false, false, 5);
  _options.pack_start(_buttonRandomize, false, false, 5);

  _buttonColor.signal_clicked().connect(slot(*this, &ColorationEditor::onActivateColor));
  _buttonRandomize.signal_clicked().connect(slot(*this, &ColorationEditor::onActivateRandomize));
  
  
  // We create the colorations if there are some
  list<Coloration*>::const_iterator itc;
      
  for (itc = col.begin(); itc != col.end(); itc++)
    createFormColoration((*itc)->getFormeFermee(), (*itc)->getCouleur());

  updateColorButton(1);

  _statusBar.pop();
  _statusBar.push(_("Ready."));
}


ColorationEditor::~ColorationEditor()
{
  // BIG TODO: lots of things to delete?
}


void ColorationEditor::onActivateNew()
{
  // TODO "do you want to save your work, boulet ?" gc.

  // TODO free
  _listColoration.clear();
  _drawingArea.clearColorations();
  _drawingArea.drawFigures();
}


void ColorationEditor::onNewbieHelp()
{
  popupNewbieHelp(_("This is the Coloration Editor.\nHere you will setup color paintings on some areas:\n1. Setup the desired color.\n2. Create your geometrical filled form:\n\ta. A rectangle or an ellipse by click-drag-drop.\n\tb. A polygon by click-drag-drop, then clicks, then right-click."));
}


void ColorationEditor::onActivateColor()
{
  Gtk::ColorSelectionDialog cs(_("Please choose a color..."));
  cs.set_modal(true);

  cs.get_colorsel()->set_current_color(*InterfaceUtils::getColorAuxiliary(_currentColor));

  if (cs.run() == Gtk::RESPONSE_OK) {
    if (_selectedArea == NULL)
      _currentColor = InterfaceUtils::getNextFreeNumberAuxiliary();

    Gdk::Color cc = cs.get_colorsel()->get_current_color();
    InterfaceUtils::addColorAuxiliary(_currentColor, cc.get_red(), cc.get_green(), cc.get_blue());
    updateColorButton(_currentColor);
  
    if (_selectedArea != NULL)
      _drawingArea.drawFigures();
  }
}

void ColorationEditor::onActivateRandomize()
{
  _currentColor = InterfaceUtils::getNextFreeNumberAuxiliary();
  InterfaceUtils::addRandomColorAuxiliary(_currentColor);
  updateColorButton(_currentColor);
}


int ColorationEditor::findColorOfSelectedArea()
{
  for (list<Coloration*>::iterator it = _listColoration.begin() ;
	   it != _listColoration.end() ;
	   it++)
    if (dynamic_cast<Forme*>(_selectedArea) == (*it)->getFormeFermee())
      return (*it)->getCouleur();

  return -1;
}


void ColorationEditor::updateColorButton(int color)
{
  _currentColor = color;

  Gdk::Color * col = InterfaceUtils::getColorAuxiliary(color);

  Glib::RefPtr<Gtk::Style> style = _buttonColor.get_style()->copy();
  style->set_bg(Gtk::STATE_NORMAL, *col);
  style->set_bg(Gtk::STATE_ACTIVE, *col);
  style->set_bg(Gtk::STATE_PRELIGHT, InterfaceUtils::lighter(*new Gdk::Color(*col)));
  _buttonColor.set_style(style);
}


void ColorationEditor::updateColorButtonAccordingToSelectedArea()
{
  updateColorButton(findColorOfSelectedArea());
}


bool ColorationEditor::handleButtonPress(GdkEventButton *event)
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
      my_selection = _drawingArea.findSelectedColoration((gint)event->x, (gint)event->y);
      if (my_selection != NULL)
	{
	  _selectedArea = my_selection;
	  deleteSelectedArea();
	  _buttonDelete.set_sensitive(false);
	  _menuDelete->set_sensitive(false);
	}
    }
  
  // If this is a simple-click...
  else

  switch (_typeAction)
    {
    case SELECTION:
      GtkForm * my_selection;
      my_selection = _drawingArea.findSelectedColoration((gint)event->x, (gint)event->y);
      if (my_selection != NULL)
	{
	  _selectedArea = my_selection;
	  _selectedArea->setSelection(true);

	  updateColorButtonAccordingToSelectedArea();

	  _statusBar.pop();
	  _statusBar.push(_("Element selected."));
	  _buttonDelete.set_sensitive(true);
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
		    GtkPolygon * dp = new GtkPolygon(_drawingArea._polygonAreaInProgress, InterfaceUtils::getColorAuxiliary(_currentColor));
		    dp->close();
		    _drawingArea.addFigureColoration(dp);

		    Coloration * col = new Coloration(dp, _currentColor);
		    _listColoration.push_back(col);

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
      cerr << "BIG PB [1] ! " << endl;
    }

  _drawingArea.drawFigures();
  return true;
}


bool ColorationEditor::handleMotionNotify(GdkEventMotion *event)
{
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
      cerr << "??" << endl;
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
      _statusBar.pop();
      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+").");
      
      switch (_typeAction)
	{
	case SELECTION:

	  GtkForm * my_selection;
	  my_selection = _drawingArea.findSelectedColoration((gint)event->x, (gint)event->y);
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
	  cerr << "BIG PB [2bis] ! " << endl;
	}
      
    }

  return true;
}


bool ColorationEditor::handleButtonRelease(GdkEventButton *event)
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
	      _drawingArea._rectangleInProgress->setColor(InterfaceUtils::getColorAuxiliary(_currentColor));
	      
	      _drawingArea.addFigureColoration(_drawingArea._rectangleInProgress);
	      
	      Coloration * col = new Coloration(_drawingArea._rectangleInProgress, _currentColor);
	      _listColoration.push_back(col);
	      
	      _statusBar.pop();
	      _statusBar.push(_("Rectangle added."));
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
	      _drawingArea._ellipseInProgress->setColor(InterfaceUtils::getColorAuxiliary(_currentColor));
	      
	      _drawingArea.addFigureColoration(_drawingArea._ellipseInProgress);
	      
	      Coloration * col = new Coloration(_drawingArea._ellipseInProgress, _currentColor);
	      _listColoration.push_back(col);
	      
	      _statusBar.pop();
	      _statusBar.push(_("Rectangle added."));
	    }
	  _drawingArea._ellipseInProgress = NULL;
	}
      break;


    case POLYGONE:
      if ((_drawingArea._polygonAreaInProgress == NULL) && (_drawingArea._lineInProgress != NULL))
	{
	  // Releach of the button -> first line.
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
      cerr << "BIG PB [3] ! " << endl;
    }

  _drawingArea.drawFigures();
  return true;
}



void ColorationEditor::deleteSelectedArea()
{
  if (_selectedArea != NULL)
    {
      for (list<Coloration*>::iterator it = _listColoration.begin() ;
	   it != _listColoration.end() ;
	   it++)
	if (dynamic_cast<Forme*>(_selectedArea) == (*it)->getFormeFermee())
	  {
	    _listColoration.erase(it);
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


void ColorationEditor::createFormZoning(FormeFermee * f, ContientPhase * cp)
{
  Gdk::Color * col = InterfaceUtils::createColorFromMix(cp);
  
  if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
    {
      GtkRectangle * dr = new GtkRectangle(arg, col);
      _drawingArea.addFigureZoning(dr);
      return;
    }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _drawingArea.addFigureZoning(de);
	  return;
	}
      else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _drawingArea.addFigureZoning(dp);
	      return;
	    }
  
  cerr << "[ColorationEditor::createFormZoning] There is a problem, I don't handle all the forms..." << endl;
}


void ColorationEditor::createFormColoration(FormeFermee * f, int color)
{
  Gdk::Color * col = InterfaceUtils::getColorAuxiliary(color);
  
  if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
    {
      GtkRectangle * dr = new GtkRectangle(arg, col);
      _drawingArea.addFigureColoration(dr);
      _listColoration.push_back(new Coloration(dr, color));
      return;
    }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _drawingArea.addFigureColoration(de);
	  _listColoration.push_back(new Coloration(de, color));
	  return;
	}
      else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _drawingArea.addFigureColoration(dp);
	      _listColoration.push_back(new Coloration(dp, color));
	      return;
	    }
  
  cerr << "[ColorationEditor::createFormColoration] There is a problem, I don't handle all the forms..." << endl;
}


list<Coloration*> ColorationEditor::getListColoration()
{
  return _listColoration;
}
