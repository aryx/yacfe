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

#include "MainWindow.h"
#include "config.h"
#include "AllPixmaps.h"
#include <dirent.h>
#include <sys/stat.h>    // for struct stat filestat

using namespace Gtk::Menu_Helpers;
using namespace Gtk::Toolbar_Helpers;


MainWindow::MainWindow()
  : BaseWindow(),
    _imageStop(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapStop)),
    _imagePlay(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapPlay)),
    _imagePause(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapPause)),
    _imageRecord(Gdk::Pixbuf::create_from_xpm_data(AllPixmaps::_dataPixmapRecord))
    
{

  _winRule = NULL;
  _winScene = NULL;
  _winBorders = NULL;
  _dialogNewSimulation = NULL;
  _dialogParamRecord = NULL;
  _winParamModif = NULL;

  set_title("Grany-3");
  set_default_size(600,600);


  Gtk::Menu * menu_tools = manage(new Gtk::Menu());
  MenuList& list_tools = menu_tools->items();

  list_tools.push_back(MenuElem(_("_Scene editor"), Gtk::Menu::AccelKey(_("<alt>s")), slot(*this, &MainWindow::onToolsSceneEditor)));
  list_tools.push_back(MenuElem(_("_Borders editor"), Gtk::Menu::AccelKey(_("<alt>b")), slot(*this, &MainWindow::onToolsBordersEditor)));
  list_tools.push_back(MenuElem(_("_Rules editor"), Gtk::Menu::AccelKey(_("<alt>r")), slot(*this, &MainWindow::onToolsRuleEditor)));
  list_tools.push_back(SeparatorElem());
  list_tools.push_back(CheckMenuElem(_("_Updatable parameters"), Gtk::Menu::AccelKey(_("<alt>u")), slot(*this, &MainWindow::onToolsUpdatableParameters)));
  _menuUpdatableParameters = &(list_tools.back());

  _menuBar.items().push_back(MenuElem(_("_Tools"), Gtk::Menu::AccelKey(_("<alt>t")), *menu_tools));


  Gtk::Menu * menu_control = manage(new Gtk::Menu());
  MenuList& list_control = menu_control->items();

  list_control.push_back(MenuElem(_("St_op"), Gtk::Menu::AccelKey(_("<alt>o")), slot(*this, &MainWindow::onControlStop)));
  _menuStop = &(list_control.back());
  list_control.push_back(MenuElem(_("_Play"), Gtk::Menu::AccelKey(_("<alt>p")), slot(*this, &MainWindow::onControlPlay)));
  _menuPlay = &(list_control.back());
  list_control.push_back(MenuElem(_("P_ause"), Gtk::Menu::AccelKey(_("<alt>a")), slot(*this, &MainWindow::onControlPause)));
  _menuPause = &(list_control.back());
  list_control.push_back(SeparatorElem());
  list_control.push_back(MenuElem(_("Recor_d"), Gtk::Menu::AccelKey(_("<alt>d")), slot(*this, &MainWindow::onControlRecord)));
  _menuRecord = &(list_control.back());

  _menuBar.items().push_back(MenuElem(_("_Control"), Gtk::Menu::AccelKey(_("<alt>c")), *menu_control));


  // then I call the maker of the help menu (it's in BasicWindow)

  makeHelpMenu();

  _imageStop.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imagePlay.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imagePause.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);
  _imageRecord.set_size_request(WIDTH_PIXMAPS, HEIGHT_PIXMAPS);

  _buttonStop.add(_imageStop);
  _buttonPlay.add(_imagePlay);
  _buttonPause.add(_imagePause);
  _buttonRecord.add(_imageRecord);

  // At the beginning buttons are insensitive because we don't have automaton yet.
  _buttonStop.set_sensitive(false);
  _buttonPlay.set_sensitive(false);
  _buttonPause.set_sensitive(false);
  _buttonRecord.set_sensitive(false);

  _menuUpdatableParameters->set_sensitive(false);
  _menuStop->set_sensitive(false);
  _menuPlay->set_sensitive(false);
  _menuPause->set_sensitive(false);
  _menuRecord->set_sensitive(false);

  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonStop, _("Stop")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPlay, _("Play")));
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonPause, _("Pause")));
  _toolBar.tools().push_back(Space());
  _toolBar.tools().push_back(Gtk::Toolbar_Helpers::Element(_buttonRecord, _("Record")));

  _buttonStop.signal_clicked().connect(slot(*this, &MainWindow::onControlStop));
  _buttonPlay.signal_clicked().connect(slot(*this, &MainWindow::onControlPlay));
  _buttonPause.signal_clicked().connect(slot(*this, &MainWindow::onControlPause));
  _buttonRecord.signal_clicked().connect(slot(*this, &MainWindow::onControlRecord));

  signal_realize().connect(slot(*this, &MainWindow::handleRealize));

  // gives a minimum size the user won't be able to shrink more
  _myDrawingArea.set_size_request(300, 300);
  _myDrawingArea.signal_expose_event().connect(slot(*this, &MainWindow::handleExposeDrawingArea));
  _myDrawingArea.signal_configure_event().connect(slot(*this, &MainWindow::handleConfigureDrawingArea));

  _pixmap = NULL;

  _vbox.pack_start(_myDrawingArea);

  initColors();

  _sceneName = "";
  _networkSize = 60;
  _numberSteps = 100;
  _seed = 0;
  _active = false;
 
  _play = false;
  _displayFrequency = 1;

  // I would have liked to reduce the size of the progress bar ; but we can only set the minimum size with usize. So I should
  // set the minimum size of the text area ? Ok. But how to get the text area from a statusbar ? There is no method for that !... gc.
  _statusBar.pack_end(_progressing);
  
  _fileName = "";
  
  _statusBar.push(_("Ready."));
}


MainWindow::~MainWindow()
{
}


void MainWindow::initColors()
{
  InterfaceUtils::initColors(this);

  // I choose -1 because the colors chosen for the phases, etc, are >= 0.
  InterfaceUtils::addColor(-1, R_BORDER_CELLS, G_BORDER_CELLS, B_BORDER_CELLS);
  setCouleurParoi(-1);
}


// Interface-specific actions after the init of a new automaton.
void MainWindow::registerNewAutomaton()
{
  // We register the colormap

  list<Couleur *> colors_utilisees = _automate.getCouleur();
  
  for (list<Couleur*>::iterator it = colors_utilisees.begin(); it != colors_utilisees.end(); it++)
    {
      if ((*it)->getCouleur() == -1)
	cerr << "[MainWindow::registerNewAutomaton] GRANY_WARNING Color number -1, reserved for the gray borders, has been found in the colormap." << endl;
      else
	InterfaceUtils::addColor((*it)->getCouleur(), (*it)->getRed(), (*it)->getGreen(), (*it)->getBlue());
    }


  // We save the beginning automaton for being able to come back instantly to the initial state

  DEBUG_INTERFACE(cout << "[MainWindow::registerNewAutomaton] Call to copy automaton." << endl;);
  _automatonBeginning = _automate;
  DEBUG_INTERFACE(cout << "[MainWindow::registerNewAutomaton] End of copy of automaton." << endl;);


  // We read the general information and set the current step to  0

  _currentStep = 0;

  
  // We activate the (maybe) inactive buttons 
  _buttonStop.set_sensitive(true);
  _buttonPlay.set_sensitive(true);
  _buttonPause.set_sensitive(true);
  _menuUpdatableParameters->set_sensitive(true);
  _menuStop->set_sensitive(true);
  _menuPlay->set_sensitive(true);
  _menuPause->set_sensitive(true);

  _active = true;

}



/* Draw a Cellule from its position, size and color ; we use a circle (why not a hexagon?) gc. */
void MainWindow::drawCell(gdouble x, gdouble y, Gdk::Color * c, gint taille)
{
  _myGc->set_foreground(*c);
  _pixmap->draw_arc(_myGc, true, (gint) (x - taille/2), (gint) (y - taille/2), taille, taille, 0, 360*64);
}



/* Change dimensions of the Cellule to occupy the maximum space */
void MainWindow::fitCells()
{

  // Dimensions of the graphical window
  int x, y, width, height, depth;
  _myDrawingArea.get_window()->get_geometry(x, y, width, height, depth);

  int dim = _automate.getDimReseau();

  if (dim > 0)
    {
      
      if ((double(height)/width) > double(3)/2)
	{
	  // the screen is more high than wide -> we fit on the width
	  _incr = width/dim;
	  _edgex = _incr/2;
	  _edgey = (height - (width*3)/2) /2;
	}
      else
	{
	  // the screen is more wide than high -> we fit on the height
	  _incr = ((height*2)/3)/dim;
	  _edgex = (width - (height*2)/3 ) /2 + _incr/2; // hmmm not cute
	  _edgey = _incr/4; // hmmm same
	}
      
      gdouble minx, maxx, miny, maxy;
      
      minx = width;
      miny = height;
      maxx = 0;
      maxy = 0;
      
      // Scan of all Cellule to optimize the space occupied.
      for (int j=0 ; j < dim ; j++)
	{
	  gdouble x = _edgex;
	  gdouble y = _edgey + (j+dim/2)*_incr;
	  for (int i=0 ; i < dim ; i++)
	    {
	      if (dynamic_cast<CelluleHorsScene*>(_automate.getTableauCellules()[i+j*dim]))
		{
		  // The dynamic_cast succeded, we have a CelluleHorsScene. We don't count it.
		}
	      else
		{
		  if (x<minx) minx = x;
		  if (x>maxx) maxx = x;
		  if (y<miny) miny = y;
		  if (y>maxy) maxy = y;
		}
	      x += _incr;
	      y -= _incr/2;
	    }
	}

      gint taille = (int) ((_incr*3)/4);
      
      gdouble correction_incrx = (maxx-minx+taille*2)/width;
      gdouble correction_incry = (maxy-miny+taille*2)/height;
      
      gdouble correction_incr = MAX(correction_incrx, correction_incry);
      
      _incr /= correction_incr;
      
      
      gint nouv_taille = (int) ((_incr*3)/4);
      
      _edgex = -(minx-_edgex)/correction_incr + nouv_taille;
      _edgey = -(miny-_edgey)/correction_incr + nouv_taille;
      
      
      // Now our graphic has correct size (maximum) but is at the top-left corner.
      
      
      if (correction_incrx > correction_incry)
	// We center in translating the starting y
	_edgey += (height-(maxy-miny+taille*2)/correction_incr)/2;
      
      if (correction_incrx < correction_incry)
	// We center in translating the starting x
	_edgex += (width-(maxx-minx+taille*2)/correction_incr)/2;
      
    }
}




/* Draw all Cellule of the automaton */
void MainWindow::drawCells()
{
  // We `erase' by drawing a big white rectangle.
  _myGc->set_foreground(InterfaceUtils::getColorWhite());
  int x, y, width, height, depth;
  _myDrawingArea.get_window()->get_geometry(x, y, width, height, depth);
  _pixmap->draw_rectangle(_myGc, true, 0, 0, width, height);

  gint taille = (int) ((_incr*3)/4); // Cellule size

  if (taille > 1)
    {
      int dim = _automate.getDimReseau();
      
      for (int j=0 ; j < dim ; j++)
	{
	  gdouble x = _edgex;
	  gdouble y = _edgey + (j+dim/2)*_incr;
	  for (int i=0 ; i < dim ; i++)
	    {
	      if (dynamic_cast<CelluleHorsScene*>(_automate.getTableauCellules()[i+j*dim]))
		{
		  // The dynamic_cast succeded, we have a CelluleHorsScene. We don't draw it!!
		}
	      else
		drawCell(x, y, InterfaceUtils::getColor(_automate.getTableauCellules()[i+j*dim]->donneTaCouleur()), taille);
	      x += _incr;
	      y -= _incr/2;
	    }
	}
    }


  // we put back the default color to black, because gtk will draw awful colors in borders of pixmaps and menus
  _myGc->set_foreground(InterfaceUtils::getColorBlack());

  _myDrawingArea.queue_draw();
}


// This method is called when the X server realizes our window. We then can create our graphical context.
void MainWindow::handleRealize()
{
  _myGc = Gdk::GC::create(get_window());
  GtkForm::setGcGlobal(_myGc);
  GtkForm::setTile(get_window());

  // Then let's verify there is a ~/.grany directory.
  
  struct stat filestat;
  string my_dir = string(g_get_home_dir()) + "/.grany";
  int err = stat(const_cast<char*>(my_dir.c_str()), &filestat);

  if (!err && S_ISDIR(filestat.st_mode))
    {
      // Ok the directory is there. Let's suppose the user did not mess up inside.
    }
  else
    {
      // Taken from Gimp, app/install.c - modified with stl.

      string script_to_run = string(PKGDATADIR "user_install");
      // Let's verify we will execute the script by opening a filestream on it.
      std::ifstream filestream(const_cast<char*>(script_to_run.c_str()));

      if (!filestream)
	{
	  popupErrorWindow(_("I detected you don't have `~/.grany' directory,\nbut I can't find my installing script...\nI tried: ")
			   +script_to_run);
	}
      else
	{
	  script_to_run = script_to_run + " " + string(PKGDATADIR) + " " + my_dir;

	  FILE *pfp;
	  if ((pfp = popen(const_cast<char*>(script_to_run.c_str()), "r")) != NULL)
	    {
	      cerr << endl << _("No `~/.grany' directory. Welcome to Grany, new user! Let's make your very own grany directory...") << endl;
	      cerr << _("Invoking my install script: ") << script_to_run << endl;
	      char buffer[2048];
	      while (fgets(buffer, 2048, pfp))
		cerr << buffer;
	      pclose(pfp);

	      cerr << _("Installation successful. Enjoy!") << endl << endl;
	      popupWarningWindow(_("A directory `~/.grany' and some subdirs have been created.\nPlease put your creations in its subdirectories.\nNB: through each window you can access Help / Newbie help which will help you begin with Grany."));
	    }
	  else
	    popupErrorWindow(_("I detected you don't have `~/.grany' directory,\nbut I failed while invoking my script...\nI tried: ")+script_to_run);
	}
    }
}


bool MainWindow::handleConfigureDrawingArea(GdkEventConfigure *event)
{            
  int x, y, width, height, depth;
  _myDrawingArea.get_window()->get_geometry(x, y, width, height, depth);
  _pixmap = Gdk::Pixmap::create(_myDrawingArea.get_window(), width, height, -1);
  
  // then we redraw the network if it has been initialised
  fitCells();
  drawCells();
  
  return true;
}



bool MainWindow::handleExposeDrawingArea(GdkEventExpose *event)
{
 _myDrawingArea.get_window()->draw_drawable(_myGc,
					    _pixmap,
					    event->area.x, event->area.y,
					    event->area.x, event->area.y,
					    event->area.width, event->area.height);
  return false;
}




// If I don't have this function the program will not terminate!
gint MainWindow::delete_event_impl(GdkEventAny*)
{ 
  DEBUG_INTERFACE(cout << "[MainWindow] delete_event_impl " << endl;);

  // If I don't have this line, in case of `play' mode, the application doesn't stop and I have looots of assertion `Gtk::IS_LABEL (label)' failed.
  _play = false;

  //  Gtk::Main::quit(); 

  return false; 
}


void MainWindow::onNewbieHelp()
{
  popupNewbieHelp(_("This is the main window.\nHere you will watch a simulation progressing over the time.\nPlease consider opening a .simulation file, -- or defining a new simulation\nby opening a .scene file and setting up some parameters through the dialogs.\nThen you will use the stop-play-pause buttons to control the simulation."));
}


void MainWindow::onCloseSceneEditor()
{
  DEBUG_INTERFACE(cout << "[MainWindow] onCloseSceneEditor" << endl;)
  delete _winScene;
  _winScene = NULL;
}


void MainWindow::onCloseRuleEditor()
{
  DEBUG_INTERFACE(cout << "[MainWindow] onCloseRuleEditor" << endl;)
  delete _winRule;
  _winRule = NULL;
}


void MainWindow::onCloseBordersEditor()
{
  DEBUG_INTERFACE(cout << "[MainWindow] onCloseBordersEditor" << endl;)
  delete _winBorders;
  _winBorders = NULL;
}


void MainWindow::onToolsSceneEditor()
{
  if (!_winScene) {
      _winScene = new SceneEditor();
      _winScene->signal_hide().connect(slot(*this, &MainWindow::onCloseSceneEditor));
      _winScene->show_all();
    }
}


void MainWindow::onToolsBordersEditor()
{
  if (!_winBorders) {
    _winBorders = new BordersEditor();
    _winBorders->signal_hide().connect(slot(*this, &MainWindow::onCloseBordersEditor));
    _winBorders->show_all();
  }
}


void MainWindow::onToolsRuleEditor()
{
  if (!_winRule) {
    _winRule = new RulesEditor();
    _winRule->signal_hide().connect(slot(*this, &MainWindow::onCloseRuleEditor));
    _winRule->show_all();
  }
}

int no_recurse_please;

void MainWindow::onCloseToolsUpdatableParameters()
{
  if (no_recurse_please) return;
  _menuUpdatableParameters->activate();
}

void MainWindow::onToolsUpdatableParameters()
{
  if (no_recurse_please) return;
  no_recurse_please = true;
  if (_winParamModif) {
    DEBUG_INTERFACE(cout << "[MainWindow] onFermetureParametreModifiable" << endl;)
    delete _winParamModif;
    _winParamModif = NULL;
  } else {
      _winParamModif = new UpdatableParameters(this, InterfaceUtils::intToString(_numberSteps), InterfaceUtils::intToString(_displayFrequency), _automate.getTableauPhase());
      
      _winParamModif->signal_hide().connect(slot(*this, &MainWindow::onCloseToolsUpdatableParameters));
      _winParamModif->getApplyButton()->signal_clicked().connect(slot(*this, &MainWindow::onApplyUpdatableParameters));
      _winParamModif->show_all();
    }
  no_recurse_please = false;
}


void MainWindow::onApplyUpdatableParameters()
{
  // Verification of validity of entered parameters
  if (!InterfaceUtils::stringConvertible(_winParamModif->getNumberSteps()))
    {
      // TODO more constraints
      _winParamModif->numberStepsInvalid(); // we call the window to act for signaling the non-validity
      popupErrorWindow(_("The value entered for `number of steps' is not valid."));
      return;
    }

  if (!InterfaceUtils::stringConvertible(_winParamModif->getDisplayFrequency()))
    {
      // TODO more constraints
      _winParamModif->displayFrequencyInvalid(); // we call the window to act for signaling the non-validity
      popupErrorWindow(_("The value entered for `display frequency' is not valid."));
      return;
    }


  _numberSteps = InterfaceUtils::stringToInt(_winParamModif->getNumberSteps());
  _displayFrequency = InterfaceUtils::stringToInt(_winParamModif->getDisplayFrequency());
  updateStatusBar();
  drawCells();
}



void MainWindow::onOkFileOpen()
{
  // Opening of a simulation file (.simul)
  _fileName = _winFileSelection->get_filename();
    
  DEBUG_INTERFACE(cout << "[MainWindow::onOkFileOpen] trying to open file : " << _fileName << endl;);


  std::ifstream filestream(const_cast<char*>(_fileName.c_str()));

  if (!filestream)
    {
      DEBUG_INTERFACE(cout << "[MainWindow::onOkFileOpen] Error when setting up the filestream -> file not found" << endl;);
      popupErrorWindow(_("File not found !"));
      return;
    }
  else
    {
      // OK, file is open, we read it.
      _statusBar.pop();
      _statusBar.push(_("Computing..."));
      while (gtk_events_pending())
	gtk_main_iteration();

      int results = StaticIOs::parseMaSimul(filestream, _automate);
      
      if (results != 0)
	{
	  //      try
	  //	{
	  //	  filestream >> _automate;
	  //	  
	  //	  DEBUG_INTERFACE(cout << "[MainWindow::onOkFileOpen] No exception while calling >> from the file .simul to the automaton" << endl;);
	  //	}  
	  //      catch (SimulCompiler::Exception e)
	  //	{
	  DEBUG_INTERFACE(cout << "[MainWindow::onOkFileOpen] Exception while calling >> from the file .simul to the automaton!" << endl;);
	  popupErrorWindow(_("Error while reading the file...\nAre you sure this is a .simul file?"));
	  _fileName = "";  // to avoid saving on a failing filename later on
	  _statusBar.pop();
	  _statusBar.push(_("Fileread failed."));
	  return;
	}
    }

  DEBUG_INTERFACE(cout << "[MainWindow::onOkFileOpen] copying the automaton in a saving automaton..." << endl;);


  registerNewAutomaton();

  _numberSteps = _automate.getNbrePas();
  _displayFrequency = _automate.getFreqAff();
  _seed = _automate.getGerme();
  _networkSize = _automate.getDimReseau();

  set_title(_("Grany-3 : ")+_fileName);

  fitCells();
  drawCells();

  _buttonSave.set_sensitive(true);
  _menuSave->set_sensitive(true);
  _menuSaveAs->set_sensitive(true);
  onCloseFileSelection();


  // If `updatable parameters' is open, we update the values which are no longer pertinent.
  if (_winParamModif != NULL)
    _winParamModif->updateValues(InterfaceUtils::intToString(_numberSteps), InterfaceUtils::intToString(_displayFrequency), _automate.getTableauPhase());

  updateStatusBar();
  _statusBar.pop();
  _statusBar.push(_("Ready."));
}



void MainWindow::onFileSave()
{
  DEBUG_INTERFACE(cout << "[MainWindow::onFileSave] trying to save file : " << _fileName << endl;);

  if (_fileName == "")
    onFileSaveAs();
  else
    {
      std::ofstream filestream(const_cast<char*>(_fileName.c_str()));
      if (!filestream)
	{
	  DEBUG_INTERFACE(cout << "[MainWindow::onFileSave] Problem while writing" << endl;);
	  popupErrorWindow(_("Error while writing the file...\nDo you have write permission?"));
	  _fileName = "";
	  set_title(_("Grany-3 : new file"));
	}
      else
	{
	  _automate.setNbrePas(_numberSteps);
	  _automate.setFreqAff(_displayFrequency);
	  filestream << _automate;
	  set_title(_("Grany-3 : ")+_fileName);
	  popupWarningWindow(_("You have erased the previous file named :\n")+_fileName);
	}
    }
}

void MainWindow::onOkFileSaveAs()
{
  _fileName = _winFileSelection->get_filename();
  std::ofstream filestream(const_cast<char*>(_fileName.c_str()));
  if (!filestream)
    {
      popupErrorWindow(_("Error while writing the file...\nDo you have write permission?"));
      _fileName = "";
      set_title(_("Grany-3 : new file"));
    }
  else
    {
      _automate.setNbrePas(_numberSteps);
      _automate.setFreqAff(_displayFrequency);
      filestream << _automate;
      set_title(_("Grany-3 : ")+_fileName);
    }

  onCloseWritingFileSelection();
}



void MainWindow::updateStatusBar()
{
  _statusBar.pop();
  _statusBar.push(_("Step of the automata : ")+InterfaceUtils::intToString(_currentStep));

  // CLAMP : cf. glib.h
  if (_numberSteps != 0)
    _progressing.set_fraction(CLAMP(((gfloat) _currentStep)/_numberSteps, 0, 1));
  else
    _progressing.set_fraction(0);
}


void MainWindow::drawCurrentStep()
{
  drawCells();
  updateStatusBar();
}


void MainWindow::nextStepAutomaton()
{
  _automate.genereTransition();
  _currentStep++;
}


void MainWindow::onControlStop()
{
  if (!_active)
    return;

  _play = false;

  _currentStep = 0;
  _automate = _automatonBeginning;


  // If `updatable parameters' is open, we update the values which are no longer pertinent.
  if (_winParamModif != NULL)
    _winParamModif->updateValues(InterfaceUtils::intToString(_numberSteps), InterfaceUtils::intToString(_displayFrequency), _automate.getTableauPhase());


  // The `copy' does not performs a srand to init the seed. I must call `setGerme' to have srand performed. (I think this is better than to call srand by myself, here)
  _automate.setGerme(_automate.getGerme());


  // we rewind to initial colors in case some phases' colors have been modified
  list<Couleur *> used_colors = _automate.getCouleur();
  for (list<Couleur*>::iterator it = used_colors.begin(); it != used_colors.end(); it++)
    {
      if ((*it)->getCouleur() == -1)
	cerr << "[MainWindow::onControlStop] GRANY_WARNING Color number -1, reserved for the gray borders, has been found in the colormap." << endl;
      else
	InterfaceUtils::addColor((*it)->getCouleur(), (*it)->getRed(), (*it)->getGreen(), (*it)->getBlue());
    }


  drawCells(); // to generate the drawing of the automaton

  updateStatusBar();
  _statusBar.pop();
  _statusBar.push(_("Ready."));
}


void MainWindow::onControlPlay()
{
  if (!_active)
    return;

  _play = true;

  while (_currentStep < _numberSteps)
    {
      // to allow stop/pause 
      if (_play == false)
	return;

      for (int i=0 ; i<_displayFrequency ; i++)
	nextStepAutomaton();

      drawCurrentStep();

      /* (this is taken from the Gtk+ FAQ)
       * -> to allow the status bar and the progress bar to be displayed although there are
       *    still CPU-intensive automaton calculations pending.
       * (and btw to allow stop and pause!)
       */
      while (gtk_events_pending())
	gtk_main_iteration();
    }

  _play = false;
}


// New specification : pause will produce a new step. gc.
void MainWindow::onControlPause()
{
  if (!_active)
    return;

  // We were in playing mode -> we move to pause
  if (_play == true)
    {
      _play = false;
      return;
    }
  else
    {
      nextStepAutomaton();
      drawCurrentStep();
    }
}


void MainWindow::onControlRecord()
{
  if (!_active)
    return;

  _dialogParamRecord = new ParamRecordDialog();

  _dialogParamRecord->signal_hide().connect(slot(*this, &MainWindow::onCloseParamRecord));
  _dialogParamRecord->set_modal(true);

  _dialogParamRecord->get_ok_button()->signal_clicked().connect(slot(*this, &MainWindow::onOkParamRecord));

  _dialogParamRecord->show_all();
}


void MainWindow::onOkParamRecord()
{
  onCloseParamRecord();
}

void MainWindow::onCloseParamRecord()
{
  _dialogParamRecord->hide();
  _dialogParamRecord->set_modal(false);
  delete _dialogParamRecord;
  _dialogParamRecord = NULL;
}



void MainWindow::onFileNew()
{
  _dialogNewSimulation = new NewSimulationDialog(_sceneName, InterfaceUtils::intToString(_networkSize), InterfaceUtils::intToString(_numberSteps), InterfaceUtils::intToString(_seed));
 
  _dialogNewSimulation->set_modal(true);

  _dialogNewSimulation->signal_hide().connect(slot(*this, &MainWindow::onCloseNewSimulation));
  _dialogNewSimulation->getButtonOk()->signal_clicked().connect(slot(*this, &MainWindow::onOkNewSimulation));
  _dialogNewSimulation->getCancelButton()->signal_clicked().connect(slot(*this, &MainWindow::onCloseNewSimulation));

  _dialogNewSimulation->show_all();
}

void MainWindow::onOkNewSimulation()
{
  // Verification of validity for: network size.
  if (!InterfaceUtils::stringConvertible(_dialogNewSimulation->getNetworkSize()))
    {
      _dialogNewSimulation->networkSizeInvalid(); // we call the window to act for signaling the non-validity
      popupErrorWindow(_("The value entered for `network size' is not valid. It must be a number."));
      return;
    }

  _networkSize = InterfaceUtils::stringToInt(_dialogNewSimulation->getNetworkSize());
  if (_networkSize <= 0)
    {
      _dialogNewSimulation->networkSizeInvalid(); // we call the window to act for signaling the non-validity
      popupErrorWindow(_("The value entered for `network size' is not valid.\nIt must be greater than 0. (and should be smaller than 100 to be viewable)"));
      return;
    }

  if (_networkSize >= 160)
    popupWarningWindow(_("The -actual- number of cells generated is `network size'^2.\nThe cells in the window can therefore be too small to be viewable."));


  // Verification of validity for: number of steps.
  if (!InterfaceUtils::stringConvertible(_dialogNewSimulation->getNumberSteps()))
    {
      _dialogNewSimulation->numberStepsInvalid(); // we call the window to act for signaling the non-validity
      popupErrorWindow(_("The value entered for `number of steps' is not valid. It must be a number."));
      return;
    }

  _numberSteps = InterfaceUtils::stringToInt(_dialogNewSimulation->getNumberSteps());
  if (_numberSteps <= 0)
    {
      _dialogNewSimulation->numberStepsInvalid(); // we call the window to act for signaling the non-validity
      popupErrorWindow(_("The value entered for `number of steps' is not valid. It must be greater than 0."));
    }


  // Verification of validity for: seed.
  if (!InterfaceUtils::stringConvertible(_dialogNewSimulation->getSeed()))
    {
      _dialogNewSimulation->seedInvalid(); // we call the window to act for signaling the non-validity
      popupErrorWindow(_("The value entered for `seed' is not valid."));
      return;
    }

  _seed = InterfaceUtils::stringToInt(_dialogNewSimulation->getSeed());


  // Verification of validity for: file name.
  _sceneName = _dialogNewSimulation->getSceneName();
  std::ifstream filestream(const_cast<char*>(_sceneName.c_str()));

  if (!filestream)
    {
      _dialogNewSimulation->sceneNameInvalod();  // we call the window to act for signaling the non-validity
      popupErrorWindow(_("File not found !"));
      return;
    }


  // Ok let's create the simulation. But before flush any pending gtk action.
  _statusBar.pop();
  _statusBar.push(_("Computing..."));

  Scene scene;

  // We create the new automaton.
  int results = StaticIOs::parseMaScene(filestream, scene);
      
  if (results == 0)
    {
      PlanHexagonal plan(_networkSize, scene);
      _automate = *plan.getAutomate();
    }
  else
    {
      DEBUG_INTERFACE(cout << "[MainWindow::onOkNewSimulation] Exception while calling >> from .scene to scene object!" << endl;);
      popupErrorWindow(_("Error while reading the file...\nAre you sure you gave me a .scene file?"));
      _statusBar.pop();
      _statusBar.push(_("Fileread failed."));
      return;
    }


  _automate.setGerme(_seed);

  registerNewAutomaton();

  fitCells();
  drawCells();

  set_title(_("Grany-3 : new file"));
  _fileName = "";

  // If `updatable parameters' is open, we update the values which are no longer pertinent.
  if (_winParamModif != NULL)
    _winParamModif->updateValues(InterfaceUtils::intToString(_numberSteps), InterfaceUtils::intToString(_displayFrequency), _automate.getTableauPhase());

  updateStatusBar();
  _statusBar.pop();
  _statusBar.push(_("Ready."));

  _buttonSave.set_sensitive(true);
  _menuSave->set_sensitive(true);
  _menuSaveAs->set_sensitive(true);
  onCloseNewSimulation();
}

void MainWindow::onCloseNewSimulation()
{
  delete _dialogNewSimulation;
  _dialogNewSimulation = NULL;
}






//##############################################################################
// static members
//##############################################################################

static RegleIoManager ioRegleIoManager;
static LigneIoManager ioLigneIoManager;
static RectangleIoManager ioRectangleIoManager;
static PolygoneIoManager ioPolygoneIoManager;
static EllipseIoManager ioEllipseIoManager;
static ArcEllipseIoManager ioArcEllipseIoManager;

static SceneIoManager ioSceneIoManager;
static CouleurIoManager ioCouleurIoManager;
static PhaseIoManager ioPhaseIoManager;
static PonderationIoManager ioPonderationIoManager;
static ZonageIoManager ioZonageIoManager;
static ContientHorsSceneIoManager ioContientHorsSceneIoManager;
static ContientPhaseIoManager ioContientPhaseIoManager;
static ColorationIoManager ioColorationIoManager;

static AutomateIoManager ioAutomateIoManager;
static CelluleHorsSceneIoManager ioCelluleHorsSceneIoManager;
static CelluleParoiIoManager ioCelluleParoiIoManager;
static CelluleAvecParticuleIoManager ioCelluleAvecParticuleIoManager;
static CelluleGeneratriceIoManager ioCelluleGeneratriceIoManager;
