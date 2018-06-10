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

#include "BordersEditor.h"
#include "AllPixmaps.h"
#include "EntreeSortie.h"

using namespace Gtk::Menu_Helpers;
using namespace Gtk::Toolbar_Helpers;

/* You like ugly programming ?
 * Enjoy !
 */

BordersEditor::BordersEditor(list<Frontiere*> frt)
  : BaseWindow(),
    _imageSelection(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapSelection)),
    _imageDelete(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapDelete)),
    _imageSpecialLine(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapLine)),
    _imageArcEllipse(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapArcEllipse)),
    _imageEllipse(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapEllipse)),
    _imagePolygon(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapPolygon)),
    _imageClassicalBorders(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapClassicalBorder)),
    _imageGeneratingBorders(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapGeneratingBorder)),
    _imageGrid(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapGrid))
{

  set_title(_("Borders editor : new file"));

  set_default_size(500, 400);

  Gtk::Menu * menu_edit = manage(new Gtk::Menu());
  MenuList& list_edit = menu_edit->items();

  Gtk::RadioMenuItem::Group my_gr_action;
  list_edit.push_back(RadioMenuElem(my_gr_action, _("Select"), slot(*this, &BordersEditor::onActivateSelection)));
  _menuSelect = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_action, _("New line"), slot(*this, &BordersEditor::onActivateLine)));
  _menuLine = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_action, _("New arc of ellipse"), slot(*this, &BordersEditor::onActivateArcEllipse)));
  _menuArcEllipse = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_action, _("New ellipse"), slot(*this, &BordersEditor::onActivateEllipse)));
  _menuEllipse = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_action, _("New polygon"), slot(*this, &BordersEditor::onActivatePolygon)));
  _menuPolygon = &(list_edit.back());
  list_edit.push_back(SeparatorElem());
  list_edit.push_back(MenuElem(_("Delete"), slot(*this, &BordersEditor::onActivateDelete)));
  _menuDelete = &(list_edit.back());
  list_edit.push_back(SeparatorElem());

  Gtk::RadioMenuItem::Group my_gr_type;
  list_edit.push_back(RadioMenuElem(my_gr_type, _("Create classical borders"), slot(*this, &BordersEditor::onActivateClassicalBorders)));
  _menuClassicalBorders = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_type, _("Create generating borders"), slot(*this, &BordersEditor::onActivateGeneratingBorders)));
  _menuGeneratingBorders = &(list_edit.back());
  list_edit.push_back(SeparatorElem());
  list_edit.push_back(CheckMenuElem(_("Grid"), slot(*this, &BordersEditor::onActivateGridMenu)));
  _menuGrid = &(list_edit.back());

  _menuBar.items().push_back(MenuElem(_("_Edit"), Gtk::Menu::AccelKey(_("<alt>e")), *menu_edit));


  makeHelpMenu();

  
  _imageSelection.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageDelete.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageSpecialLine.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageArcEllipse.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageEllipse.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imagePolygon.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageClassicalBorders.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageGeneratingBorders.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageGrid.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);

  _buttonSelection.add(_imageSelection);
  _buttonDelete.add(_imageDelete);
  _buttonLine.add(_imageSpecialLine);
  _buttonArcEllipse.add(_imageArcEllipse);
  _buttonEllipse.add(_imageEllipse);
  _buttonPolygone.add(_imagePolygon);
  _buttonClassicalBorder.add(_imageClassicalBorders);
  _buttonGeneratingBorder.add(_imageGeneratingBorders);
  _buttonGrid.add(_imageGrid);

  _buttonDelete.set_sensitive(false);
  _menuDelete->set_sensitive(false);


  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonSelection, _("Select")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonLine, _("New line")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonArcEllipse, _("New arc of ellipse")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonEllipse, _("New ellipse")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPolygone, _("New polygon")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonDelete, _("Delete")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonClassicalBorder, _("Create classical borders")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonGeneratingBorder, _("Create generating borders")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonGrid, _("Grid")));

  _buttonDelete.signal_clicked().connect(slot(*this, &BordersEditor::onActivateDelete));
  _buttonSelection.signal_clicked().connect(slot(*this, &BordersEditor::onActivateSelection));
  _buttonLine.signal_clicked().connect(slot(*this, &BordersEditor::onActivateLine));
  _buttonArcEllipse.signal_clicked().connect(slot(*this, &BordersEditor::onActivateArcEllipse));
  _buttonEllipse.signal_clicked().connect(slot(*this, &BordersEditor::onActivateEllipse));
  _buttonPolygone.signal_clicked().connect(slot(*this, &BordersEditor::onActivatePolygon));
  _buttonClassicalBorder.signal_clicked().connect(slot(*this, &BordersEditor::onActivateClassicalBorders));
  _buttonGeneratingBorder.signal_clicked().connect(slot(*this, &BordersEditor::onActivateGeneratingBorders));
  _buttonGrid.signal_clicked().connect(slot(*this, &BordersEditor::onActivateGridToolbar));

  _statusBar.push(_("Configuration in progress..."));


  
  _drawingArea.signal_motion_notify_event().connect(slot(*this, &BordersEditor::handleMotionNotify));
  _drawingArea.signal_button_press_event().connect(slot(*this, &BordersEditor::handleButtonPress));
  _drawingArea.signal_button_release_event().connect(slot(*this, &BordersEditor::handleButtonRelease));
  _drawingArea.signal_leave_notify_event().connect(slot(*this, &BordersEditor::handleLeaveNotify));


  _drawingArea.set_events(Gdk::EXPOSURE_MASK
			 | Gdk::BUTTON_PRESS_MASK
			 | Gdk::BUTTON_RELEASE_MASK
			 | Gdk::POINTER_MOTION_MASK
			 | Gdk::POINTER_MOTION_HINT_MASK
			 | Gdk::LEAVE_NOTIFY_MASK);


  signal_key_press_event().connect(slot(*this, &BordersEditor::handleKeyPress));

  set_events(Gdk::KEY_PRESS_MASK);

  _vbox.pack_start(_drawingArea);


  initColors();

  // We construct the figures given as parameters
  // (this allows to open the editor from the scene editor, with already
  // the figures previously defined)
  list<Frontiere*>::const_iterator itf;
  
  for (itf = frt.begin(); itf != frt.end(); itf++)
    createFormBorder((*itf)->getForme(), (*itf)->getTypeParoi());
  
  if (_listFrontiere.size() > 0)
    {
      _buttonSave.set_sensitive(true);
      _menuSave->set_sensitive(true);
      _menuSaveAs->set_sensitive(true);
    }
  

  _figureSelectionnee = NULL; _figurePreSelectionnee = NULL;
  _isGrid = false;
  _noRecursivePlease = false;

  onActivateLine();
  onActivateClassicalBorders();
  onActivateGridToolbar();

  _fileName = "";

  _statusBar.pop();
  _statusBar.push(_("Ready."));

}

void BordersEditor::onFileNew()
{
  // TODO "do you want to save your work, boulet ?" gc.
  
  // TODO free the memory!
  _listFrontiere.clear();
  _drawingArea.clearBorders();
  _drawingArea.drawFigures();

  DEBUG_INTERFACE(cout << "[BordersEditor::onFileNew]" << endl;);
  _fileName = "";

  _buttonSave.set_sensitive(false);
  _menuSave->set_sensitive(false);
  _menuSaveAs->set_sensitive(false);
}


void BordersEditor::onOkFileOpen()
{
  // Opening of a borders file (.frontiere)
  _fileName = _winFileSelection->get_filename();
    
  DEBUG_INTERFACE(cout << "[BordersEditor::onOkFileOpen] I try to open the file: " << _fileName << endl;);

  std::ifstream filestream(const_cast<char*>(_fileName.c_str()));

  if (!filestream)
    {
      DEBUG_INTERFACE(cout << "[BordersEditor::onOkFileOpen] Error while instantiating the filestream -> file not found" << endl;);
      popupErrorWindow(_("File not found !"));
      _fileName = "";
      set_title(_("Borders editor : new file"));
      _drawingArea.drawFigures();
      return;
    }
  else
    {
      _listFrontiere.clear();
      _drawingArea.clearBorders();

      list<Frontiere*> frt;

      int results = StaticIOs::parseMesFrontieres(filestream, frt);
      
      if (results == 0)
	{
	  DEBUG_INTERFACE(cout << "[BordersEditor::onOkFileOpen] Pas d'exception" << endl;);
	}
      else
	{
	  DEBUG_INTERFACE(cout << "[BordersEditor::onOkFileOpen] Exception pendant appel à >> de .frontiere sur _listFrontiere" << endl;);
	  popupErrorWindow(_("Error while reading the file...\nAre you sure this was a borders file?"));
	  _fileName = ""; // to not erase the failing filename in the next save
	  return;
	}
      
      list<Frontiere*>::const_iterator itf;
      
      for (itf = frt.begin(); itf != frt.end(); itf++)
	createFormBorder((*itf)->getForme(), (*itf)->getTypeParoi());

      set_title(_("Borders editor : ")+_fileName);
      _drawingArea.drawFigures();
    }

  _buttonSave.set_sensitive(true);
  _menuSave->set_sensitive(true);
  _menuSaveAs->set_sensitive(true);
  onCloseFileSelection();
}


void BordersEditor::onFileSave()
{
  DEBUG_INTERFACE(cout << "[BordersEditor::onFileSave] I try to write the file: " << _fileName << endl;);

  if (_fileName == "")
    onFileSaveAs();
  else
    {
      std::ofstream filestream(const_cast<char*>(_fileName.c_str()));
      if (!filestream)
	{
	  DEBUG_INTERFACE(cout << "[BordersEditor::onFileSave] Problem while writing." << endl;);
	  popupErrorWindow(_("Error while writing the file..."));
	  _fileName = "";
	  set_title(_("Borders editor : new file"));
	}
      else
	{
	  filestream << _listFrontiere;
	  set_title(_("Borders editor : ")+_fileName);
	  popupWarningWindow(_("You have erased the previous file named :\n")+_fileName);
	}
    }
}

void BordersEditor::onOkFileSaveAs()
{
  _fileName = _winFileSelection->get_filename();
  std::ofstream filestream(const_cast<char*>(_fileName.c_str()));
  if (!filestream)
    {
      popupErrorWindow(_("Error while writing the file..."));
      _fileName = "";
      set_title(_("Borders editor : new file"));
    }
  else
    {
      filestream << _listFrontiere;
      set_title(_("Borders editor : ")+_fileName);
    }

  onCloseWritingFileSelection();
}


void BordersEditor::onNewbieHelp()
{
  popupNewbieHelp(_("This is the Borders Editor.\nHere you will design the borders of a future simulation.\n\nYou can use several geometrical forms:\n1. A line: click-drag-drop.\n2. An arc of ellipse: click-drag-drop to setup the first and last points ; then move the pointer to setup the curve.\n3. An ellipse: click-drag-drop (holding shift you will create a circle).\n4. A polygon: click-drag-drop for the first line, then click for the next ones, then right-click to terminate.\n\nEach one of these borders may be:\n1. Classical borders. -- or,\n2. Generating borders (which means one phase will be able to go through this border)."));
}


bool BordersEditor::handleKeyPress(GdkEventKey *event)
{
  if (event->length <= 0)
    return false;

  // I pushed on `delete' on my RedHat GNU/Linux and I got 65535.
  // Then on some Sun Solaris 2.5 Workstations, same value. Cool. gc.
  if (event->keyval == 65535)
    {
      deleteSelectedFigure();
      return false;
    }

  // Here I got 65307 for `Escape'.
  if (event->keyval == 65307)
    {
      delete _drawingArea._lineInProgress; _drawingArea._lineInProgress = NULL;
      delete _drawingArea._line2InProgress; _drawingArea._line2InProgress = NULL;
      delete _drawingArea._arcEllipseInProgress; _drawingArea._arcEllipseInProgress = NULL;
      delete _drawingArea._ellipseBordersInProgress; _drawingArea._ellipseBordersInProgress = NULL;
      delete _drawingArea._polygonInProgress; _drawingArea._polygonInProgress = NULL;
      _drawingArea.drawFigures();
      return false;
    }

  return false; // for ctrl and alt
}


/** Description.
 * When we quit the drawing area, we have to stop the `in progress' things which suppose
 * the mouse button is pressed and holded, because when the user releases the button outside
 * the window, I don't get the buttonRelease signal.
 */
bool BordersEditor::handleLeaveNotify(GdkEventCrossing *event)
{
  switch (_typeBorder)
    {
    case SELECTION:
      break;
      
    case POLYGONE:
      if (_drawingArea._line2InProgress != NULL)
	{
	  delete _drawingArea._line2InProgress;
	  _drawingArea._line2InProgress = NULL;
	  delete _drawingArea._polygonInProgress;
	  _drawingArea._polygonInProgress = NULL;
	}

    case SPECIALLINE:
    case ARCELLIPSE:
      if (_drawingArea._lineInProgress != NULL)
	{
	  delete _drawingArea._lineInProgress;
	  _drawingArea._lineInProgress = NULL;
	  _drawingArea.drawFigures();
	}
      break;

    case ELLIPSE:
      if (_drawingArea._ellipseBordersInProgress != NULL)
	{
	  delete _drawingArea._ellipseBordersInProgress;
	  _drawingArea._ellipseBordersInProgress = NULL;
	  _drawingArea.drawFigures();
	}
      break;
      
    default:
      cerr << "We must never get here.. [4] ! " << endl;
    }

  return true;
}



bool BordersEditor::handleButtonPress(GdkEventButton *event)
{
  // click

  int x,y; GdkModifierType state;
  gdk_window_get_pointer(event->window, &x, &y, &state);
  if (!((state & GDK_BUTTON1_MASK) || (state & GDK_BUTTON2_MASK) || (state & GDK_BUTTON3_MASK)))
    return false;

  if (_figureSelectionnee != NULL)
    {
      _figureSelectionnee->setSelection(false);
      _figureSelectionnee = NULL;
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
      my_selection = _drawingArea.findSelectedBorder((gint)event->x, (gint)event->y);
      if (my_selection != NULL)
	{
	  _figureSelectionnee = my_selection;
	  _figureSelectionnee->setSelection(true);
	  deleteSelectedFigure();
	  _buttonDelete.set_sensitive(false);
	  _menuDelete->set_sensitive(false);
	}
    }
  
  // If this is a simple-click...
  else

  switch (_typeBorder)
    {
    case SELECTION:
      GtkForm * my_selection;
      my_selection = _drawingArea.findSelectedBorder((gint)event->x, (gint)event->y);
      if (my_selection != NULL)
	{
	  _figureSelectionnee = my_selection;
	  _figureSelectionnee->setSelection(true);
	  _statusBar.pop();
	  _statusBar.push(_("Element selected."));
	  _buttonDelete.set_sensitive(true);
	  _menuDelete->set_sensitive(true);
	}
      
      break;


    case SPECIALLINE:
      if (_drawingArea._lineInProgress != NULL)
	delete _drawingArea._lineInProgress;
      _drawingArea._lineInProgress = new GtkLine(_grey, rx, ry, rx, ry);
      _statusBar.pop();
      _statusBar.push(_("New line, origine : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+_("). Drag for the end."));
      break;
      
    case ARCELLIPSE:
      if (_drawingArea._arcEllipseInProgress != NULL)
	{
	  // We just clicked for terminating an arc of ellipse
	  if (_drawingArea._arcEllipseInProgress->isInvalid())
	    {
	      _statusBar.pop();
	      _statusBar.push(_("The arc of ellipse is not valid."));
	      delete _drawingArea._arcEllipseInProgress;
	      _drawingArea._arcEllipseInProgress = NULL;
	    }
	  else
	    {
	      Frontiere * front = new Frontiere(_drawingArea._arcEllipseInProgress, _typeParoi);
	      _listFrontiere.push_back(front);

	      if (_typeParoi == Frontiere::CLASSIQUE)
		{
		  _drawingArea._arcEllipseInProgress->setColor(_colorClassicalBorder);
		  _drawingArea.addFigureBorder(_drawingArea._arcEllipseInProgress);
		  _statusBar.pop();
		  _statusBar.push(_("Arc of ellipse with a classical border added."));
		}
	      else
		if (_typeParoi == Frontiere::GENERATRICE)
		  {
		    _drawingArea._arcEllipseInProgress->setColor(_colorGeneratingBorder);
		    _drawingArea.addFigureBorder(_drawingArea._arcEllipseInProgress);
		    _statusBar.pop();
		    _statusBar.push(_("Arc of ellipse with a generating border added."));
		  }
		else cerr << "We must never get there !?" << endl;
	      _buttonSave.set_sensitive(true);
	      _menuSave->set_sensitive(true);
	      _menuSaveAs->set_sensitive(true);
	    }
	  _drawingArea._arcEllipseInProgress = NULL;
	}
      else
	{
	  // We click for a new arc of ellipse
	  if (_drawingArea._lineInProgress != NULL)
	    delete _drawingArea._lineInProgress;
	  _drawingArea._lineInProgress = new GtkLine(_grey, rx, ry, rx, ry);
	  _drawingArea._lineInProgress->setTemporary(true);
	  _statusBar.pop();
	  _statusBar.push(_("New arc of ellipse, origine : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+_("). Drag for the end."));
	}
      break;
      
    case POLYGONE:
      if (_drawingArea._polygonInProgress != NULL)
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

	      if (_typeParoi == Frontiere::CLASSIQUE)
		_drawingArea._lineInProgress->setColor(_colorClassicalBorder);
	      else
		_drawingArea._lineInProgress->setColor(_colorGeneratingBorder);

	      _drawingArea._polygonInProgress->ajoutLigne(_drawingArea._lineInProgress);

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
		    if (_drawingArea._polygonInProgress->isInvalid())
		      {
			_statusBar.pop();
			_statusBar.push(_("The polygone is not valid."));
			delete _drawingArea._polygonInProgress;
		      }
		    else
		      {
			Frontiere * front = new Frontiere(_drawingArea._polygonInProgress, _typeParoi);
			_listFrontiere.push_back(front);
			
			if (_typeParoi == Frontiere::CLASSIQUE)
			  {
			    _drawingArea.addFigureBorder(_drawingArea._polygonInProgress);
			    _statusBar.pop();
			    _statusBar.push(_("Polygone with a classical border added."));
			  }
			else
			  if (_typeParoi == Frontiere::GENERATRICE)
			    {
			      _drawingArea.addFigureBorder(_drawingArea._polygonInProgress);
			      _statusBar.pop();
			      _statusBar.push(_("Polygone with a generating border added."));
			    }
			  else cerr << "We must never get there !? [2]" << endl;

			_buttonSave.set_sensitive(true);
			_menuSave->set_sensitive(true);
			_menuSaveAs->set_sensitive(true);
		      }
		    _drawingArea._polygonInProgress = NULL;
		    _drawingArea._lineInProgress = NULL;
		    delete _drawingArea._line2InProgress;
		    _drawingArea._line2InProgress = NULL;
		  }
	    }
	}
      else
	{
	  // We click for a new polygone
	  _drawingArea._lineInProgress = new GtkLine(_grey, rx, ry, rx, ry);
	  _drawingArea._line2InProgress = new GtkLine(_grey, rx, ry, rx, ry);
	  _drawingArea._line2InProgress->setTemporary(true);
	  _statusBar.pop();
	  _statusBar.push(_("New polygone, origine : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+_("). Drag."));
	}
      break;


    case ELLIPSE:
      if (_drawingArea._ellipseBordersInProgress != NULL)
	delete _drawingArea._ellipseBordersInProgress;
      _drawingArea._ellipseBordersInProgress = new GtkEllipse(_grey, rx, ry);
      _statusBar.pop();
      _statusBar.push(_("New ellipse, origine : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+_("). Drag for the end."));
      break;

      
    default:
      cerr << "We must never get here.. [1] ! " << endl;
    }

  _drawingArea.drawFigures();
  return true;
}


bool BordersEditor::handleMotionNotify(GdkEventMotion *event)
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

  if (_figurePreSelectionnee != NULL)
    _figurePreSelectionnee->setPreSelection(false);
  _figurePreSelectionnee = NULL;

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
      cerr << "??"; // i never got this to happen... i don't know what it is.
    }
    
  if (state & GDK_BUTTON1_MASK)
    {
      // mouse-drag (move of the mouse with button pressed and holded)

      if (_typeBorder == SELECTION)
	{
	}
      else
	{
	  if (_drawingArea._polygonInProgress != NULL) return true;

	  // all the rest, ie SPECIALLINE, ARCELLIPSE ou POLYGONE
	  if (_drawingArea._lineInProgress != NULL)
	    {
	      _drawingArea._lineInProgress->modifyEnd(rx, ry);
	      gint x1,y1,x2,y2;
	      _drawingArea._lineInProgress->gimmeYourCoordinates(&x1, &y1, &x2, &y2);
	      _statusBar.pop();
	      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(x1)+","+InterfaceUtils::intToString(y1)+";"+InterfaceUtils::intToString(x2)+","+InterfaceUtils::intToString(y2)+").");
	    }
	  if (_drawingArea._ellipseBordersInProgress != NULL)
	    {
	      _drawingArea._ellipseBordersInProgress->ModifyExtremity(rx, ry, state);
	      gint x, y, l, h;
	      _drawingArea._ellipseBordersInProgress->gimmeYourCoordinates(&x, &y, &l, &h);
	      _statusBar.pop();
	      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(x)+","+InterfaceUtils::intToString(y)+";l="+InterfaceUtils::intToString(l)+";h="+InterfaceUtils::intToString(h)+").");
	      _drawingArea.drawFigures();
	    }

	}	  
      
      _drawingArea.drawFigures();
    }
  else
    {
      // move of the mouse, no button pressed.


      _statusBar.pop();
      _statusBar.push(_("Current position : (")+InterfaceUtils::intToString(rx)+","+InterfaceUtils::intToString(ry)+").");
      
      switch (_typeBorder)
	{
	case SELECTION:

	  // The thing only usefull for the eyes: highlight of the figure under the mouse. :) gc.
	  GtkForm * my_selection;
	  my_selection = _drawingArea.findSelectedBorder((gint)event->x, (gint)event->y);
	  if (my_selection != NULL)
	    {
	      _figurePreSelectionnee = my_selection;
	      _figurePreSelectionnee->setPreSelection(true);
	    }
	  
	  _drawingArea.drawFigures();
	  break;
	  
	case SPECIALLINE:
	  break;
	  
	case ARCELLIPSE:
	  if (_drawingArea._arcEllipseInProgress != NULL)
	    {
	      /* We're creating an ellipse. Another point is wanted.
	       * Here there is no granularity and thus it's cuuuuuute.
	       */
	      _drawingArea._arcEllipseInProgress->modifyCenter((gint)event->x, (gint)event->y, state);
	      _drawingArea.drawFigures();
	    }
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
	  cerr << "We must never get here.. [2bis] ! " << endl;
	}
      
    }

  return true;
}


bool BordersEditor::handleButtonRelease(GdkEventButton *event)
{
  // release
  gint rx, ry;

  if ((event->x < 0) || (event->y < 0))
    return true;

  if (_isGrid)
    InterfaceUtils::granularity((gint)event->x, (gint)event->y, &rx, &ry);
  else
    { rx = (gint)event->x; ry = (gint)event->y; }

  switch (_typeBorder)
    {
    case SELECTION:
      break;

    case SPECIALLINE:
      if (_drawingArea._lineInProgress != NULL)
	{
	  if (_drawingArea._lineInProgress->isInvalid())
	    {
	      _statusBar.pop();
	      _statusBar.push(_("The line is not valid."));
	      delete _drawingArea._lineInProgress;
	      _drawingArea._lineInProgress = NULL;
	    }
	  else
	    {
	      if (_typeParoi == Frontiere::CLASSIQUE)
		{
		  _drawingArea._lineInProgress->setColor(_colorClassicalBorder);
		  
		  Frontiere * front = new Frontiere(_drawingArea._lineInProgress, _typeParoi);
		  _listFrontiere.push_back(front);
		  
		  _drawingArea.addFigureBorder(_drawingArea._lineInProgress);
		  
		  _statusBar.pop();
		  _statusBar.push(_("Line with classical border added."));
		}
	      else
		if (_typeParoi == Frontiere::GENERATRICE)
		  {
		    _drawingArea._lineInProgress->setColor(_colorGeneratingBorder);
		    
		    Frontiere * front = new Frontiere(_drawingArea._lineInProgress, _typeParoi);
		    _listFrontiere.push_back(front);

		    _drawingArea.addFigureBorder(_drawingArea._lineInProgress);
		    _statusBar.pop();
		    _statusBar.push(_("Line with generating border added."));
		  }
		else cerr << "We must never get there !?" << endl;
	      
	      _buttonSave.set_sensitive(true);
	      _menuSave->set_sensitive(true);
	      _menuSaveAs->set_sensitive(true);
	    }
	  _drawingArea._lineInProgress = NULL;
	}
      break;

    case ARCELLIPSE:
      if (_drawingArea._lineInProgress != NULL)
	{
	  gint x1,y1,x2,y2;
	  _drawingArea._lineInProgress->gimmeYourCoordinates(&x1, &y1, &x2, &y2);
	  if ((x1 == x2) && (y1 == y2))
	    {
	      _statusBar.pop();
	      _statusBar.push(_("Invalid arc of ellipse."));
	      delete _drawingArea._lineInProgress;
	      _drawingArea._lineInProgress = NULL;
	    }
	  else
	    {
	      _statusBar.pop();
	      _statusBar.push(_("Now decide for the centre of the ellipse."));
	      
	      _drawingArea._arcEllipseInProgress = new GtkArcEllipse(_grey, x1, y1, x2, y2);
	      _drawingArea._lineInProgress = NULL;
	    }
	}
      break;

    case POLYGONE:
      if ((_drawingArea._polygonInProgress == NULL) && (_drawingArea._lineInProgress != NULL))
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
	      _drawingArea._polygonInProgress = new GtkPolygon(_grey);

	      _statusBar.pop();
	      _statusBar.push(_("Left button for another line, right button to end."));

	      _drawingArea._lineInProgress->modifyEnd(rx,ry);
	      if (_typeParoi == Frontiere::CLASSIQUE)
		_drawingArea._lineInProgress->setColor(_colorClassicalBorder);
	      else
		_drawingArea._lineInProgress->setColor(_colorGeneratingBorder);
	      _drawingArea._line2InProgress->modifyEnd(rx,ry);
	      _drawingArea._polygonInProgress->ajoutLigne(_drawingArea._lineInProgress);
	      _drawingArea._lineInProgress = new GtkLine(_grey, rx, ry, rx, ry);
	    }
	}
      break;

    case ELLIPSE:
      if (_drawingArea._ellipseBordersInProgress != NULL)
	{
	  if (_drawingArea._ellipseBordersInProgress->isInvalid())
	    {
	      _statusBar.pop();
	      _statusBar.push(_("The ellipse is not valid."));
	      delete _drawingArea._ellipseBordersInProgress;
	      _drawingArea._ellipseBordersInProgress = NULL;
	    }
	  else
	    {
	      if (_typeParoi == Frontiere::CLASSIQUE)
		{
		  _drawingArea._ellipseBordersInProgress->setColor(_colorClassicalBorder);

		  Frontiere * front = new Frontiere(_drawingArea._ellipseBordersInProgress, _typeParoi);
		  _listFrontiere.push_back(front);
		  
		  _drawingArea.addFigureBorder(_drawingArea._ellipseBordersInProgress);
		  
		  _statusBar.pop();
		  _statusBar.push(_("Ellipse with classical border added."));
		}
	      else
		if (_typeParoi == Frontiere::GENERATRICE)
		  {
		    _drawingArea._ellipseBordersInProgress->setColor(_colorGeneratingBorder);
		    
		    Frontiere * front = new Frontiere(_drawingArea._ellipseBordersInProgress, _typeParoi);
		    _listFrontiere.push_back(front);
		    
		    _drawingArea.addFigureBorder(_drawingArea._ellipseBordersInProgress);
		    _statusBar.pop();
		    _statusBar.push(_("Ellipse with generating border added."));
		  }
		else cerr << "We must never get there !?" << endl;
	      
	      _buttonSave.set_sensitive(true);
	      _menuSave->set_sensitive(true);
	      _menuSaveAs->set_sensitive(true);
	    }
	  _drawingArea._ellipseBordersInProgress = NULL;
	}
      break;


    default:
      cerr << "We must never get here.. [3] ! " << endl;
    }

  _drawingArea.drawFigures();
  return true;
}





void BordersEditor::deleteSelectedFigure()
{
  // We delete the current selected object if there is one.

  if (_figureSelectionnee != NULL)
    {
      // Scan the list of borders looking for the occurence.
      for (list<Frontiere*>::iterator it = _listFrontiere.begin() ;
	   it != _listFrontiere.end() ;
	   it++)
	if (dynamic_cast<Forme*>(_figureSelectionnee) == (*it)->getForme())
	  it = _listFrontiere.erase(it);
      
      // Delete from the list of borders holded by the drawing area.
      _drawingArea.removeFigure(_figureSelectionnee);

      if (_figurePreSelectionnee == _figureSelectionnee)
	_figurePreSelectionnee = NULL;
      delete _figureSelectionnee;
      _figureSelectionnee = NULL;
      _drawingArea.drawFigures();
      _statusBar.pop();
      _statusBar.push(_("Element deleted."));

      _buttonDelete.set_sensitive(false);
      _menuDelete->set_sensitive(false);

      if (_listFrontiere.size() == 0)
	{
	  _buttonSave.set_sensitive(false);
	  _menuSave->set_sensitive(false);
	  _menuSaveAs->set_sensitive(false);
	}
    }
}


void BordersEditor::initColors()
{
  _grey = InterfaceUtils::addColorDirect(R_TEMPORARY, G_TEMPORARY, B_TEMPORARY);
  _colorClassicalBorder = InterfaceUtils::addColorDirect(R_CLASSICAL_BORDERS, G_CLASSICAL_BORDERS, B_CLASSICAL_BORDERS);
  _colorGeneratingBorder = InterfaceUtils::addColorDirect(R_GENERATING_BORDERS, G_GENERATING_BORDERS, B_GENERATING_BORDERS);

  GtkForm::setColorPreSelection(_grey);
}




/** Description.
 * Okay actually I make calls to set_active on some Gtk::ToggleButton.
 * Problem is this set_active generates a click signal (apparently), so infinite recursive call!
 * Apparently in the doc, it does not exist a method to only change the state of the Button, so
 * I use a boolean to remove the recursive problem.
 */

void BordersEditor::onActivateSelection()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeBorder = SELECTION;

  _buttonSelection.set_active(true);
  _buttonLine.set_active(false);
  _buttonArcEllipse.set_active(false);
  _buttonEllipse.set_active(false);
  _buttonPolygone.set_active(false);

  _menuSelect->activate();

  _noRecursivePlease = false;
}


void BordersEditor::onActivateDelete()
{
  deleteSelectedFigure();
  _statusBar.pop();
  _statusBar.push(_("You can also use the DEL key."));
}


void BordersEditor::onActivateLine()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeBorder = SPECIALLINE;
  _statusBar.pop();
  _statusBar.push(_("Add a new line by clicking for the origine, then dragging for the end."));

  _buttonSelection.set_active(false);
  _buttonLine.set_active(true);
  _buttonArcEllipse.set_active(false);
  _buttonEllipse.set_active(false);
  _buttonPolygone.set_active(false);

  _menuLine->activate();

  _noRecursivePlease = false;
}


void BordersEditor::onActivateArcEllipse()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeBorder = ARCELLIPSE;
  _statusBar.pop();
  _statusBar.push(_("Add a new arc of ellipse by clicking and dragging to determine the extreme coordinates."));

  _buttonSelection.set_active(false);
  _buttonLine.set_active(false);
  _buttonArcEllipse.set_active(true);
  _buttonEllipse.set_active(false);
  _buttonPolygone.set_active(false);

  _menuArcEllipse->activate();

  _noRecursivePlease = false;
}


void BordersEditor::onActivateEllipse()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeBorder = ELLIPSE;
  _statusBar.pop();
  _statusBar.push(_("Add a new ellipse by clicking and dragging to determine the extreme coordinates."));

  _buttonSelection.set_active(false);
  _buttonLine.set_active(false);
  _buttonArcEllipse.set_active(false);
  _buttonEllipse.set_active(true);
  _buttonPolygone.set_active(false);

  _menuEllipse->activate();

  _noRecursivePlease = false;
}


void BordersEditor::onActivatePolygon()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeBorder = POLYGONE;
  _statusBar.pop();
  _statusBar.push(_("Add a new polygone by clicking and dragging for the first line."));

  _buttonSelection.set_active(false);
  _buttonLine.set_active(false);
  _buttonArcEllipse.set_active(false);
  _buttonEllipse.set_active(false);
  _buttonPolygone.set_active(true);

  _menuPolygon->activate();

  _noRecursivePlease = false;
}



void BordersEditor::onActivateClassicalBorders()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeParoi = Frontiere::CLASSIQUE;
  _statusBar.pop();
  _statusBar.push(_("Added borders will be `classical'."));

  _buttonClassicalBorder.set_active(true);
  _buttonGeneratingBorder.set_active(false);

  _menuClassicalBorders->activate();

  _noRecursivePlease = false;
}


void BordersEditor::onActivateGeneratingBorders()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeParoi = Frontiere::GENERATRICE;
  _statusBar.pop();
  _statusBar.push(_("Added borders will be `generating'."));

  _buttonClassicalBorder.set_active(false);
  _buttonGeneratingBorder.set_active(true);

  _menuGeneratingBorders->activate();

  _noRecursivePlease = false;
}


void BordersEditor::onActivateGridMenu()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _statusBar.pop();
  if (_isGrid)
    {
      _isGrid = false;
      _buttonGrid.set_active(false);
      _statusBar.push(_("The grid is no longer displayed."));
    }
  else
    {
      _isGrid = true;
      _buttonGrid.set_active(true);
      _statusBar.push(_("The grid is being displayed."));
    }

  _drawingArea.setGrid(_isGrid);
  _drawingArea.drawFigures();

  _noRecursivePlease = false;
}


void BordersEditor::onActivateGridToolbar()
{
  if (_noRecursivePlease) return;
  _menuGrid->activate();
}



void BordersEditor::createFormBorder(Forme * f, Frontiere::TypeParoi tp)
{
  Gdk::Color * col;
  if (tp == Frontiere::CLASSIQUE)
    col = _colorClassicalBorder;
  else
    col = _colorGeneratingBorder;

  if (Ligne* arg = dynamic_cast<Ligne*>(f))
    {
      GtkLine * ds = new GtkLine(arg, col);
      _drawingArea.addFigureBorder(ds);
      _listFrontiere.push_back(new Frontiere(ds, tp));
      return;
    }
  else 
    if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
      {
	GtkRectangle * dr = new GtkRectangle(arg, col);
	_drawingArea.addFigureBorder(dr);
	_listFrontiere.push_back(new Frontiere(dr, tp));
	return;
      }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _drawingArea.addFigureBorder(de);
	  _listFrontiere.push_back(new Frontiere(de, tp));
	  return;
	}
      else
	if (ArcEllipse* arg = dynamic_cast<ArcEllipse*>(f))
	  {
	    GtkArcEllipse * dae = new GtkArcEllipse(arg, col);
	    _drawingArea.addFigureBorder(dae);
	    _listFrontiere.push_back(new Frontiere(dae, tp));
	    return;
	  }
	else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _drawingArea.addFigureBorder(dp);
	      _listFrontiere.push_back(new Frontiere(dp, tp));
	      return;
	    }
  
  cerr << "[BordersEditor::createFormBorder] There is a problem, I don't handle all the forms..." << endl;
}


list<Frontiere*> BordersEditor::getListFrontiere()
{
  return _listFrontiere;
}
