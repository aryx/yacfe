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

#include "AreaEditor.h"
#include "AllPixmaps.h"

using namespace Gtk::Menu_Helpers;
using namespace Gtk::Toolbar_Helpers;


AreaEditor::AreaEditor(list<Frontiere*> frt)
  : BasicWindow(),
    _imageNew(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapNew)),
    _imageSelection(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapSelection)),
    _imageDelete(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapDelete)),
    _imageRectangle(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapFilledRectangle)),
    _imageEllipse(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapFilledEllipse)),
    _imagePolygon(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapFilledPolygon)),
    _imageGrid(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapGrid))
{

  set_default_size(600,400);

  Gtk::Menu * menu_file = manage(new Gtk::Menu());
  MenuList& list_file = menu_file->items();

  list_file.push_back(MenuElem(_("_New"), Gtk::Menu::AccelKey(_("<alt>n")), slot(*this, &AreaEditor::onActivateNew)));
  list_file.push_back(SeparatorElem());
  list_file.push_back(MenuElem(_("_Quit"), Gtk::Menu::AccelKey(_("<alt>q")), slot(*this, &AreaEditor::onQuit)));

  _menuBar.items().push_back(MenuElem(_("_File"), Gtk::Menu::AccelKey(_("<alt>f")), *menu_file));


  Gtk::Menu * menu_edit = manage(new Gtk::Menu());
  MenuList& list_edit = menu_edit->items();

  Gtk::RadioMenuItem::Group my_gr_action;
  list_edit.push_back(RadioMenuElem(my_gr_action, _("Select"), slot(*this, &AreaEditor::onActivateSelection)));
  _menuSelect = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_action, _("New rectangle"), slot(*this, &AreaEditor::onActivateRectangle)));
  _menuRectangle = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_action, _("New ellipse"), slot(*this, &AreaEditor::onActivateEllipse)));
  _menuEllipse = &(list_edit.back());
  list_edit.push_back(RadioMenuElem(my_gr_action, _("New polygon"), slot(*this, &AreaEditor::onActivatePolygon)));
  _menuPolygon = &(list_edit.back());
  list_edit.push_back(SeparatorElem());
  list_edit.push_back(MenuElem(_("Delete"), slot(*this, &AreaEditor::onActivateDelete)));
  _menuDelete = &(list_edit.back());
  list_edit.push_back(SeparatorElem());
  list_edit.push_back(CheckMenuElem(_("Grid"), slot(*this, &AreaEditor::onActivateGrid)));
  _menuGrid = &(list_edit.back());

  _menuBar.items().push_back(MenuElem(_("_Edit"), Gtk::Menu::AccelKey(_("<alt>e")), *menu_edit));

  makeHelpMenu();

  _imageNew.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageSelection.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageDelete.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageRectangle.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageEllipse.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imagePolygon.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageGrid.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);

  _buttonNew.add(_imageNew);
  _buttonSelection.add(_imageSelection);
  _buttonDelete.add(_imageDelete);
  _buttonRectangle.add(_imageRectangle);
  _buttonEllipse.add(_imageEllipse);
  _buttonPolygone.add(_imagePolygon);
  _buttonGrid.add(_imageGrid);

  _buttonDelete.set_sensitive(false);
  _menuDelete->set_sensitive(false);

  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonNew, _("New")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonHelp, _("Help")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonSelection, _("Select")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonRectangle, _("New rectangle")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonEllipse, _("New ellipse")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPolygone, _("New polygon")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonDelete, _("Delete")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonGrid, _("Grid")));

  _buttonNew.signal_clicked().connect(slot(*this, &AreaEditor::onActivateNew));
  _buttonDelete.signal_clicked().connect(slot(*this, &AreaEditor::onActivateDelete));
  _buttonSelection.signal_clicked().connect(slot(*this, &AreaEditor::onActivateSelection));
  _buttonRectangle.signal_clicked().connect(slot(*this, &AreaEditor::onActivateRectangle));
  _buttonEllipse.signal_clicked().connect(slot(*this, &AreaEditor::onActivateEllipse));
  _buttonPolygone.signal_clicked().connect(slot(*this, &AreaEditor::onActivatePolygon));
  _buttonGrid.signal_clicked().connect(slot(*this, &AreaEditor::onActivateGrid));

  _drawingArea.signal_leave_notify_event().connect(slot(*this, &AreaEditor::handleLeaveNotify));

  _drawingArea.set_events(Gdk::EXPOSURE_MASK
			 | Gdk::BUTTON_PRESS_MASK
			 | Gdk::BUTTON_RELEASE_MASK
			 | Gdk::POINTER_MOTION_MASK
			 | Gdk::POINTER_MOTION_HINT_MASK
			 | Gdk::LEAVE_NOTIFY_MASK);

  signal_key_press_event().connect(slot(*this, &AreaEditor::handleKeyPress));

  set_events(Gdk::KEY_PRESS_MASK);


  _selectedArea = NULL; _preSelectedArea = NULL;

  initColors();


  // We create the borders if there are some
  list<Frontiere*>::const_iterator itf;
  
  for (itf = frt.begin(); itf != frt.end(); itf++)
    createFormBorder((*itf)->getForme(), (*itf)->getTypeParoi());
  

  _vbox.pack_start(_menuBar, false, false);
  _vbox.pack_start(_toolBar, false, false);
  _vbox.pack_start(_hbox);
  _vbox.pack_end(_statusBar, false, false);

  _hbox.pack_start(_drawingArea);
  _hbox.pack_end(_options, false, false, 5);


  _isGrid = false;
  _noRecursivePlease = false;

  _statusBar.push(_("Configuration in progress..."));

  onActivateGrid();
  onActivateRectangle();
}


AreaEditor::~AreaEditor()
{
  // BIG TODO: lots of things to delete
}


void AreaEditor::onQuit()
{
  hide();
}


bool AreaEditor::handleKeyPress(GdkEventKey *event)
{
  if (event->length <= 0)
    return false;

  if (event->keyval == 65535)
    {
      deleteSelectedArea();
      return false;
    }

  return false;
}




bool AreaEditor::handleLeaveNotify(GdkEventCrossing *event)
{
  switch (_typeAction)
    {
    case SELECTION:
      break;
      
    case POLYGONE:
      if (_drawingArea._line2InProgress != NULL)
	{
	  delete _drawingArea._line2InProgress;
	  _drawingArea._line2InProgress = NULL;
	  delete _drawingArea._lineInProgress;
	  _drawingArea._lineInProgress = NULL;
	  delete _drawingArea._polygonAreaInProgress;
	  _drawingArea._polygonAreaInProgress = NULL;
	  _drawingArea.drawFigures();
	}
      break;

    case RECTANGLE:
      if (_drawingArea._rectangleInProgress != NULL)
	{
	  delete _drawingArea._rectangleInProgress;
	  _drawingArea._rectangleInProgress = NULL;
	  _drawingArea.drawFigures();
	}
      break;
	  
    case ELLIPSE:
      if (_drawingArea._ellipseInProgress != NULL)
	{
	  delete _drawingArea._ellipseInProgress;
	  _drawingArea._ellipseInProgress = NULL;
	  _drawingArea.drawFigures();
	}
      break;
      
    default:
      cerr << "OH NO! THEY KILLED GRANY! YOU BASTARDS! [4]!" << endl;
    }

  return true;
}


void AreaEditor::initColors()
{
  _grey = InterfaceUtils::addColorDirect(40000, 40000, 40000);
  _colorClassicalBorder = InterfaceUtils::addColorDirect(0, 0, 65535);
  _colorGeneratingBorder = InterfaceUtils::addColorDirect(65535, 0, 0);

  GtkForm::setColorPreSelection(_grey);
}




void AreaEditor::onActivateSelection()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeAction = SELECTION;

  _buttonSelection.set_active(true);
  _buttonRectangle.set_active(false);
  _buttonEllipse.set_active(false);
  _buttonPolygone.set_active(false);

  _menuSelect->activate();

  _noRecursivePlease = false;
}


void AreaEditor::onActivateDelete()
{
  if (_selectedArea != NULL)
    {
      deleteSelectedArea();
      _statusBar.pop();
      _statusBar.push(_("You can also use the DEL key."));
    }
  else
    popupErrorWindow(_("No area selected !"));
}


void AreaEditor::onActivateRectangle()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeAction = RECTANGLE;
  _statusBar.pop();
  _statusBar.push(_("Add a new rectangle by clicking for the origine, then dragging for the end."));

  _buttonSelection.set_active(false);
  _buttonRectangle.set_active(true);
  _buttonEllipse.set_active(false);
  _buttonPolygone.set_active(false);

  _menuRectangle->activate();

  _noRecursivePlease = false;
}


void AreaEditor::onActivateEllipse()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeAction = ELLIPSE;
  _statusBar.pop();
  _statusBar.push(_("Add a new ellipse by clicking and dragging."));

  _buttonSelection.set_active(false);
  _buttonRectangle.set_active(false);
  _buttonEllipse.set_active(true);
  _buttonPolygone.set_active(false);

  _menuEllipse->activate();

  _noRecursivePlease = false;
}


void AreaEditor::onActivatePolygon()
{
  if (_noRecursivePlease) return;
  _noRecursivePlease = true;

  _typeAction = POLYGONE;
  _statusBar.pop();
  _statusBar.push(_("Add a new polygone by clicking and dragging for the first line."));

  _buttonSelection.set_active(false);
  _buttonRectangle.set_active(false);
  _buttonEllipse.set_active(false);
  _buttonPolygone.set_active(true);

  _menuPolygon->activate();

  _noRecursivePlease = false;
}


void AreaEditor::onActivateGrid()
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

  _menuGrid->activate();

  _noRecursivePlease = false;
}



void AreaEditor::createFormBorder(Forme * f, Frontiere::TypeParoi tp)
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
      return;
    }
  else 
    if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
      {
	GtkRectangle * dr = new GtkRectangle(arg, col);
	_drawingArea.addFigureBorder(dr);
	return;
      }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _drawingArea.addFigureBorder(de);
	  return;
	}
      else
	if (ArcEllipse* arg = dynamic_cast<ArcEllipse*>(f))
	  {
	    GtkArcEllipse * dae = new GtkArcEllipse(arg, col);
	    _drawingArea.addFigureBorder(dae);
	    return;
	  }
	else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _drawingArea.addFigureBorder(dp);
	      return;
	    }
  
  cerr << "[AreaEditor::createFormBorder] There is a problem, I don't handle all the forms..." << endl;
}
