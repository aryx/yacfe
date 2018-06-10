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

#include "SceneEditor.h"

SceneEditor::SceneEditor()

{
  // All this pointers because of `huge-objects' problem on Sparc. shit.
  _notebook = new Gtk::Notebook();

  _hboxFrontiere = new Gtk::HBox();
  _zonePrevisualisationFrontieres = new GranyDrawingArea();
  _vboxBoutonsFrontiere = new Gtk::VBox();
  _buttonNewFrontiere = new Gtk::Button(__("New"));
  _buttonOpenFrontiere = new Gtk::Button(__("Open"));
  _buttonModifyFrontiere = new Gtk::Button(__("Modify"));
  _labelTabFrontiere = new Gtk::Label(__("Borders"));
  _vboxPhase = new Gtk::VBox();
  _hboxPhase = new Gtk::HBox();
  _scrwinPhase = new Gtk::ScrolledWindow();
  _gtklistPhase_tv = new Gtk::TreeView();
  _vboxBoutonsPhase = new Gtk::VBox();
  _buttonNewPhase = new Gtk::Button(__("New"));
  _buttonProprietePhase = new Gtk::Button(__("Properties"));
  _buttonDeletePhase = new Gtk::Button(__("Delete"));
  _buttonPropagativePhase = new Gtk::ToggleButton(__("Propagative"));
  _buttonGenereePhase = new Gtk::ToggleButton(__("Generated"));
  _labelTabPhase = new Gtk::Label(__("Phases"));
  _labelNbPhases = new Gtk::Label(_("Number of phases : 0"));
  _hboxZonage = new Gtk::HBox();
  _zonePrevisualisationZonage = new GranyDrawingArea();
  _vboxBoutonsZonage = new Gtk::VBox();
  _buttonModifyZonage = new Gtk::Button(__("Modify"));
  _labelTabZonage = new Gtk::Label(__("Zoning"));
  _hboxColoration = new Gtk::HBox();
  _zonePrevisualisationColoration = new GranyDrawingArea();
  _vboxBoutonsColoration = new Gtk::VBox();
  _buttonModifyColoration = new Gtk::Button(__("Modify"));
  _labelTabColoration = new Gtk::Label(__("Coloration"));

  _winBorders = NULL;
  _dialogParamPhase = NULL;
  _winEditeurZonage = NULL;
  _winColorationEditor = NULL;
  _winFileSelectionInterne = NULL;


  set_title(_("Scene editor : new file"));

  set_default_size(600,450);
  
  _vbox.pack_start(*_notebook);


  // First page : "Borders"
  _notebook->append_page(*_hboxFrontiere,*_labelTabFrontiere);

  _hboxFrontiere->pack_start(*_zonePrevisualisationFrontieres);
  _hboxFrontiere->pack_start(*_vboxBoutonsFrontiere, false, false, 10);

  _vboxBoutonsFrontiere->pack_start(*_buttonNewFrontiere, false, false, 5);
  _vboxBoutonsFrontiere->pack_start(*_buttonOpenFrontiere, false, false, 5);
  _vboxBoutonsFrontiere->pack_start(*_buttonModifyFrontiere, false, false, 5);

  _buttonNewFrontiere->signal_clicked().connect(slot(*this, &SceneEditor::onNouveauFrontiere));
  _buttonOpenFrontiere->signal_clicked().connect(slot(*this, &SceneEditor::onOuvrirFrontiere));
  _buttonModifyFrontiere->signal_clicked().connect(slot(*this, &SceneEditor::onModifierFrontiere));

  _zonePrevisualisationFrontieres->signal_button_press_event().connect(slot(*this, &SceneEditor::handleButtonPressBorders));
  _zonePrevisualisationFrontieres->set_events(Gdk::BUTTON_PRESS_MASK);


  // Second page : "Phases"
  _notebook->append_page(*_vboxPhase,*_labelTabPhase);

  _vboxPhase->pack_start(*_labelNbPhases, false, false, 5);
  _vboxPhase->pack_start(*_hboxPhase);

  _hboxPhase->pack_start(*_scrwinPhase);
  _gtklistPhase_ls = Gtk::ListStore::create(_gtklistPhase_mc);
  _gtklistPhase_tv->set_model(_gtklistPhase_ls);
  _gtklistPhase_tv->append_column("dummy", _gtklistPhase_mc._name);
  _gtklistPhase_tv->set_headers_visible(false);
  _gtklistPhase_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);
  _scrwinPhase->add(*_gtklistPhase_tv);
  _scrwinPhase->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  _hboxPhase->pack_end(*_vboxBoutonsPhase, false, false, 5);

  _vboxBoutonsPhase->pack_start(*_buttonNewPhase, false, false, 5);
  _vboxBoutonsPhase->pack_start(*_buttonProprietePhase, false, false, 5);
  _vboxBoutonsPhase->pack_start(*_buttonDeletePhase, false, false, 5);
  _vboxBoutonsPhase->pack_start(*_buttonPropagativePhase, false, false, 5);
  _vboxBoutonsPhase->pack_start(*_buttonGenereePhase, false, false, 5);

  _buttonNewPhase->signal_clicked().connect(slot(*this, &SceneEditor::onNewPhase));
  _buttonProprietePhase->signal_clicked().connect(slot(*this, &SceneEditor::onPhaseProperties));
  _buttonDeletePhase->signal_clicked().connect(slot(*this, &SceneEditor::onDeletePhase));
  _buttonPropagativePhase->signal_clicked().connect(slot(*this, &SceneEditor::onPropagativePhase));
  _buttonGenereePhase->signal_clicked().connect(slot(*this, &SceneEditor::onGeneratedPhase));

  _numPropagative = -1; _numGeneree = -1;
  _phaseNouvelle = NULL; _phaseEditee = NULL;
  _numModifiedPhase = -1;
  _lastSelectedRow = -1;

  _buttonProprietePhase->set_sensitive(false);
  _buttonDeletePhase->set_sensitive(false);
  _buttonPropagativePhase->set_sensitive(false);
  _buttonGenereePhase->set_sensitive(false);

  _gtklistPhase_tv->signal_button_press_event().connect(slot(*this, &SceneEditor::handleButtonPressPhases), false);
  _gtklistPhase_tv->signal_key_press_event().connect(slot(*this, &SceneEditor::handleKeyPressPhases));
  _gtklistPhase_tv->get_selection()->signal_changed().connect(slot(*this, &SceneEditor::onSelectionChanged));
  _gtklistPhase_tv->add_events(Gdk::BUTTON_PRESS_MASK | Gdk::KEY_PRESS_MASK);


  // Third page : "Zoning"
  _notebook->append_page(*_hboxZonage,*_labelTabZonage);

  _hboxZonage->pack_start(*_zonePrevisualisationZonage);
  _hboxZonage->pack_end(*_vboxBoutonsZonage, false, false, 10);

  _vboxBoutonsZonage->pack_start(*_buttonModifyZonage, false, false, 5);

  _buttonModifyZonage->signal_clicked().connect(slot(*this, &SceneEditor::onModifyZoning));

  _zonePrevisualisationZonage->signal_button_press_event().connect(slot(*this, &SceneEditor::handleButtonPressZoning));
  _zonePrevisualisationZonage->set_events(Gdk::BUTTON_PRESS_MASK);


  // Fourth page : "Coloration"
  _notebook->append_page(*_hboxColoration,*_labelTabColoration);

  _hboxColoration->pack_start(*_zonePrevisualisationColoration);
  _hboxColoration->pack_end(*_vboxBoutonsColoration, false, false, 10);

  _vboxBoutonsColoration->pack_start(*_buttonModifyColoration, false, false, 5);

  _buttonModifyColoration->signal_clicked().connect(slot(*this, &SceneEditor::onModifyColoration));

  _zonePrevisualisationColoration->signal_button_press_event().connect(slot(*this, &SceneEditor::handleButtonPressColoration));
  _zonePrevisualisationColoration->set_events(Gdk::BUTTON_PRESS_MASK);



  _labelTabPhase->set_sensitive(false);
  _vboxPhase->set_sensitive(false);
  _labelTabZonage->set_sensitive(false);
  _hboxZonage->set_sensitive(false);
  _labelTabColoration->set_sensitive(false);
  _hboxColoration->set_sensitive(false);

  initColors();

  makeHelpMenu();

  _fileName = "";
  _noRecursiveCall = false;
}


SceneEditor::~SceneEditor()
{
  if (_dialogParamPhase != NULL)
    onCancelPhaseProperties();
  if (_winEditeurZonage != NULL)
    onCloseZoning();
  if (_winBorders != NULL)
    onCloseBordersEditor();

  delete _notebook;  delete _hboxFrontiere;  delete _zonePrevisualisationFrontieres;  delete _vboxBoutonsFrontiere;
  delete _buttonNewFrontiere;  delete _buttonOpenFrontiere;  delete _buttonModifyFrontiere;  delete _labelTabFrontiere;
  delete _vboxPhase;  delete _hboxPhase;  delete _scrwinPhase; 
  delete _gtklistPhase_tv;
  delete _vboxBoutonsPhase;  delete _buttonNewPhase;  delete _buttonProprietePhase;  delete _buttonDeletePhase;
  delete _buttonPropagativePhase;  delete _buttonGenereePhase;  delete _labelTabPhase;  delete _labelNbPhases;
  delete _hboxZonage;  delete _zonePrevisualisationZonage;  delete _vboxBoutonsZonage;  delete _buttonModifyZonage;
  delete _labelTabZonage;  delete _hboxColoration;  delete _zonePrevisualisationColoration;  delete _vboxBoutonsColoration;
  delete _buttonModifyColoration;  delete _labelTabColoration;
}


void SceneEditor::onFileNew()
{
  _fileName = "";
  set_title(_("Scene editor : new file"));

  //  _scene = Scene();     //<-- SIGSEV, therefore : (I want a new Scene object - I will set all the Scene objects to blank objects)
			   
  list<Frontiere*> frt;
  list<Phase*> ph;
  list<Zonage*> zon;
  list<Coloration*> colo;
  list<Couleur*> col;
  
  _scene.setTableauFrontiere(frt);
  _scene.setTableauPhase(ph);
  _scene.setTableauZonage(zon);
  _scene.setTableauColoration(colo);
  _scene.setTableauCouleur(col);
			   

  _zonePrevisualisationFrontieres->clearBorders();

  _gtklistPhase_ls->clear();
  _listePhases.clear(); 

  _vboxPhase->set_sensitive(false);
  _labelTabPhase->set_sensitive(false);
  numberOfPhasesChanged();

  _zonePrevisualisationZonage->clearBorders();
  _zonePrevisualisationZonage->clearZonings();


  _zonePrevisualisationColoration->clearBorders();
  _zonePrevisualisationColoration->clearZonings();
  _zonePrevisualisationColoration->clearColorations();

  InterfaceUtils::deleteColorsAuxiliary();

  _zonePrevisualisationFrontieres->drawFigures();
  _zonePrevisualisationZonage->drawFigures();
  _zonePrevisualisationColoration->drawFigures();

  _buttonSave.set_sensitive(false);
  _menuSave->set_sensitive(false);
  _menuSaveAs->set_sensitive(false);
}

void SceneEditor::onOkFileOpen()
{
  // Opening a scene file (.scene)
  _fileName = _winFileSelection->get_filename();
    
  DEBUG_INTERFACE(cout << "[SceneEditor::onOkFileOpen] tentative d'ouverture du fichier : " << _fileName << endl;);

  std::ifstream filestream(const_cast<char*>(_fileName.c_str()));

  if (!filestream)
    {
      DEBUG_INTERFACE(cout << "[SceneEditor::onOkFileOpen] Erreur dans l'instantiation du filestream -> fichier non trouvé" << endl;);
      popupErrorWindow(_("File not found !"));
      return;
    }
  else
    // OK, the file has been opened we will read it.
    {

      // Delete everything.
      string save_erased_filename = _fileName;
      onFileNew();
      _fileName = save_erased_filename;

      int results = StaticIOs::parseMaScene(filestream, _scene);
      
      if (results == 0)
	{
	  DEBUG_INTERFACE(cout << "[SceneEditor::onOkFileOpen] Pas d'exception pendant appel à >> de .scene sur _scene" << endl;);
	}
      else
	{
	  DEBUG_INTERFACE(cout << "[MainWindow::onOkFileOpen] Exception pendant appel à >> de .scene sur _scene" << endl;);
	  popupErrorWindow(_("Error while reading the file...\nAre you sur this was a .scene file?"));
	  _fileName = "";
	  return;
	}

      
      // We record the borders
      list<Frontiere*> frt = _scene.getTableauFrontiere();
      list<Frontiere*>::const_iterator itf;
      
      for (itf = frt.begin(); itf != frt.end(); itf++)
	createFormBorder((*itf)->getForme(), (*itf)->getTypeParoi());

      _zonePrevisualisationFrontieres->drawFigures();


      // We record the phases
      list<Phase *> ph = _scene.getTableauPhase();
      list<Phase *>::const_iterator itp;
      
      for (itp = ph.begin(); itp != ph.end(); itp++)
	{
	  // Adding in my phases vector
	  _listePhases.push_back(*itp);

	  // Adding in the Gtk::TreeView
	  Gtk::TreeModel::Row row = *(_gtklistPhase_ls->append());
	  row[_gtklistPhase_mc._name] = (*itp)->getNom();
	}

      // Setup our stuff for the propagative and generated phase
      _numPropagative = -1;
      _numGeneree = -1;
      for (unsigned int i=0; i<_listePhases.size() ; i++) {
	if (_listePhases[i] == _scene.getPhaseGeneratrice())
	  _numGeneree = i;
	
	if ((_listePhases[i]->getPropagatif()) && (_numPropagative == -1))
	  _numPropagative = i;
      }


      // Record the colormap
      list<Couleur *> colors_utilisees = _scene.getTableauCouleur();
      for (list<Couleur*>::iterator itcol = colors_utilisees.begin(); itcol != colors_utilisees.end(); itcol++)
	{
	  if ((*itcol)->getCouleur() == -1)
	    cerr << "GRANY_WARNING Color number -1, reserved for the gray borders, has been found in the colormap." << endl;
	  else
	    InterfaceUtils::addColorAuxiliary((*itcol)->getCouleur(), (*itcol)->getRed(), (*itcol)->getGreen(), (*itcol)->getBlue());
	}


      // We record the zonings
      list<Zonage*> zon = _scene.getTableauZonage();
      list<Zonage*>::const_iterator itz;
      
      for (itz = zon.begin(); itz != zon.end(); itz++)
	{
	  if (ContientPhase * cp = dynamic_cast<ContientPhase*>((*itz)->getContenuZonage()))
	    createFormZoning((*itz)->getFormeFermee(), cp);
	  else
	    cerr << "[SceneEditor::onOkFileOpen] Je ne veux pas remplir avec du hors-scène." << endl;
	}

      _zonePrevisualisationZonage->drawFigures();


      // We record the colorations
      list<Coloration*> col = _scene.getTableauColoration();
      list<Coloration*>::const_iterator itc;
      
      for (itc = col.begin(); itc != col.end(); itc++)
	createFormColoration((*itc)->getFormeFermee(), (*itc)->getCouleur());

      _zonePrevisualisationColoration->drawFigures();

      _vboxPhase->set_sensitive(true);
      _labelTabPhase->set_sensitive(true);
      numberOfPhasesChanged();
      set_title(_("Scene editor : ")+_fileName);
    }

  _buttonSave.set_sensitive(true);
  _menuSave->set_sensitive(true);
  _menuSaveAs->set_sensitive(true);
  onCloseFileSelection();
}



// This method does conversion of the data currently edited to a Scene object.
bool SceneEditor::convertsToScene()
{

  // Borders.
  // -> Ok because we maintain the list<Frontiere*> in the Scene object _scene
  if (_scene.getTableauFrontiere().size() == 0)
    {
      popupErrorWindow(_("You must define at least one border."));
      _notebook->set_current_page(0);
      return false;
    }


  // Phases.
  if (_listePhases.size() == 0)
    {
      popupErrorWindow(_("You must define at least one phase."));
      _notebook->set_current_page(1);
      return false;
    }


  // -> deal with the generated phase.
  if (_numGeneree == -1)
    {
      list<Frontiere*> frt = _scene.getTableauFrontiere();
      list<Frontiere*>::const_iterator itf;
      
      for (itf = frt.begin(); itf != frt.end(); itf++)
	if ((*itf)->getTypeParoi() == Frontiere::GENERATRICE)
	  {
	    popupErrorWindow(_("You must define a generated phase because you have a generating border."));
	    _notebook->set_current_page(1);
	    return false;
	  }
    }


  // -> Process the phi of the phases
  double phi_phases_solid = 0.01;
  double phi_phases_fluid = PHI_SOLIDE + 0.01;
  for (unsigned int i=0 ; i< _listePhases.size() ; i++)
    {
      // Solid ?
      if (_listePhases[i]->getPhi() == 0)
	{
	  _listePhases[i]->setPhi(phi_phases_solid);
	  phi_phases_solid += 0.01;
	}
      // Fluid ?
      if (_listePhases[i]->getPhi() == PHI_SOLIDE)
	{
	  _listePhases[i]->setPhi(phi_phases_fluid);
	  phi_phases_fluid += 0.01;
	}
    }

  // -> Convert from a vector to a list and setup the generated phase
  list<Phase*> ph;

  _scene.setPhaseGeneratrice(NULL);
  for (unsigned int i=0 ; i< _listePhases.size() ; i++)
    {
      if (_numGeneree == i)
	_scene.setPhaseGeneratrice(_listePhases[i]);
      ph.push_back(_listePhases[i]);
    }

  _scene.setTableauPhase(ph);


  list<RegleExclusion*> all_rules;

  // -> Record the used rules
  for (unsigned int i=0 ; i< _listePhases.size() ; i++)
    {
      const list<Phase::RegleEtMode> rules_and_modes = *(_listePhases[i]->getRegleEtModeExclusion());
      for (list<Phase::RegleEtMode>::const_iterator it = rules_and_modes.begin() ; it != rules_and_modes.end() ; it++)
	all_rules.push_back((*it).regle);
    }
  
  _scene.setTableauRegleExclusion(all_rules);


  // Colormap
  list<Couleur *> colors_utilisees;

  vector<InterfaceUtils::EntryTableColors> ma_colormap = InterfaceUtils::getAuxiliaryColormap();

  for (unsigned int i=0 ; i< ma_colormap.size() ; i++)
    {
      // I test because I record -1 as the color for classical borders (gray), and I don't want a color # -1 in the colormap!
      if (ma_colormap[i]._numero >= 0)
	colors_utilisees.push_back(new Couleur(ma_colormap[i]._numero, ma_colormap[i]._color.get_red(), ma_colormap[i]._color.get_green(), ma_colormap[i]._color.get_blue()));
      // TODO: reduce colormap to really used colors?
    }

  _scene.setTableauCouleur(colors_utilisees);


  // Zoning.
  // -> Ok because we maintain the list<Zonage*> in the Scene object _scene
  if (_scene.getTableauZonage().size() == 0)
    {
      popupErrorWindow(_("You must define at least one zoning."));
      _notebook->set_current_page(2);
      return false;
    }


  // Coloration.
  // -> Ok because we maintain the list<Coloration*> in the Scene object _scene

  return true;
}


void SceneEditor::onFileSave()
{
  DEBUG_INTERFACE(cout << "[SceneEditor::onFileSave] tentative d'écriture du fichier : " << _fileName << endl;);

  if (_fileName == "")
    onFileSaveAs();
  else
    {
      if (!convertsToScene()) return;

      std::ofstream filestream(const_cast<char*>(_fileName.c_str()));
      if (!filestream)
	{
	  DEBUG_INTERFACE(cout << "Problème à l'écriture" << endl;);
	  popupErrorWindow(_("Error while writing the file..."));
	  _fileName = "";
	  set_title(_("Scene editor"));
	}
      else
	{
	  filestream << _scene;
	  set_title(_("Scene editor : ")+_fileName);
	  popupWarningWindow(_("You have erased the previous file named :\n")+_fileName);
	}
    }
}

void SceneEditor::onOkFileSaveAs()
{
  _fileName = _winFileSelection->get_filename();

  if (!convertsToScene())
    {
      onCloseFileSelection();
      return;
    }

  std::ofstream filestream(const_cast<char*>(_fileName.c_str()));
  if (!filestream)
    {
      DEBUG_INTERFACE(cout << "Problème à l'écriture" << endl;);
      popupErrorWindow(_("Error while writing the file..."));
      _fileName = "";
      set_title(_("Scene editor"));
    }
  else
    {
      filestream << _scene;
      set_title(_("Scene editor : ")+_fileName);
    }

  onCloseWritingFileSelection();
}




void SceneEditor::onCloseFileSelectionInterne()
{
  InterfaceUtils::closingFileSelection(_winFileSelectionInterne);

  delete _winFileSelectionInterne;
  _winFileSelectionInterne = NULL;
}


void SceneEditor::initColors()
{
  // First set up the used colors.
  _colorClassicalBorder = InterfaceUtils::addColorDirect(R_CLASSICAL_BORDERS, G_CLASSICAL_BORDERS, B_CLASSICAL_BORDERS);
  _colorGeneratingBorder = InterfaceUtils::addColorDirect(R_GENERATING_BORDERS, G_GENERATING_BORDERS, B_GENERATING_BORDERS);
  _colorPhasePropagative = InterfaceUtils::addColorDirect(R_BUTTON_PROPAGATIVE, G_BUTTON_PROPAGATIVE, B_BUTTON_PROPAGATIVE);
  _colorPhaseGeneree = InterfaceUtils::addColorDirect(R_BUTTON_GENERATED, G_BUTTON_GENERATED, B_BUTTON_GENERATED);

  // Now set up the background colors for the buttons `Generated' and `Propagative'
  Glib::RefPtr<Gtk::Style> style = _buttonPropagativePhase->get_style()->copy();
  style->set_bg(Gtk::STATE_NORMAL, *_colorPhasePropagative);
  Gdk::Color prop_lighter = InterfaceUtils::lighter(*new Gdk::Color(*_colorPhasePropagative));
  style->set_bg(Gtk::STATE_ACTIVE, prop_lighter);
  style->set_bg(Gtk::STATE_PRELIGHT, prop_lighter);
  _buttonPropagativePhase->set_style(style);

  style = _buttonGenereePhase->get_style()->copy();
  style->set_bg(Gtk::STATE_NORMAL, *_colorPhaseGeneree);
  Gdk::Color gen_lighter = InterfaceUtils::lighter(*new Gdk::Color(*_colorPhaseGeneree));
  style->set_bg(Gtk::STATE_ACTIVE, gen_lighter);
  style->set_bg(Gtk::STATE_PRELIGHT, gen_lighter);
  _buttonGenereePhase->set_style(style);
}


void SceneEditor::onNewbieHelp()
{
  popupNewbieHelp(_(
		    "This is the Scene Editor.\n"
		    "Here you will design step-by-step a new scene (ie. a vectorial representation of the future simulation):\n"
		    "1. Design some borders either by opening a borders file or creating a new one from scratch.\n"
		    "2. Design some phases (abstraction for `type of matter') and setup their properties.\n"
		    "3. Design some zonings: they will be the initial positions of the phases.\n"
		    "4. Design some colorations: they will repaint some initial areas with local colors."));
}


// ********* Methods for the notebook page Borders **********

void SceneEditor::onNouveauFrontiere()
{
  _winBorders = new BordersEditor();

  _winBorders->signal_hide().connect(slot(*this, &SceneEditor::onCloseBordersEditor));
  _winBorders->set_modal(true);
  _winBorders->show_all();

}


void SceneEditor::onCloseBordersEditor()
{
  list<Frontiere*> frt = _winBorders->getListFrontiere();

  _scene.setTableauFrontiere(frt);

  _zonePrevisualisationFrontieres->clearBorders();
  _zonePrevisualisationZonage->clearBorders();
  _zonePrevisualisationColoration->clearBorders();

  list<Frontiere*>::const_iterator it;
      
  for (it = frt.begin(); it != frt.end(); it++)
    createFormBorder((*it)->getForme(), (*it)->getTypeParoi());

  _zonePrevisualisationFrontieres->drawFigures();
  _zonePrevisualisationZonage->drawFigures();
  _zonePrevisualisationColoration->drawFigures();

  if (frt.size() > 0)
    {
      _vboxPhase->set_sensitive(true);
      _labelTabPhase->set_sensitive(true);
    }
  else
    {
      _vboxPhase->set_sensitive(false);
      _labelTabPhase->set_sensitive(false);
      _buttonProprietePhase->set_sensitive(false);
      _buttonDeletePhase->set_sensitive(false);
      _buttonPropagativePhase->set_sensitive(false);
      _buttonGenereePhase->set_sensitive(false);
      _hboxZonage->set_sensitive(false);
      _labelTabZonage->set_sensitive(false);
      _hboxColoration->set_sensitive(false);
      _labelTabColoration->set_sensitive(false);
      _buttonSave.set_sensitive(false);
      _menuSave->set_sensitive(false);
      _menuSaveAs->set_sensitive(false);
    }

  DEBUG_INTERFACE(cout << "[SceneEditor] onCloseBordersEditor" << endl;)
  delete _winBorders;
  _winBorders = NULL;
}


void SceneEditor::onOuvrirFrontiere()
{
  _winFileSelectionInterne = new Gtk::FileSelection(_("Open a borders file..."));

  _winFileSelectionInterne->signal_hide().connect(slot(*this, &SceneEditor::onCloseFileSelectionInterne));
  _winFileSelectionInterne->set_modal(true);

  _winFileSelectionInterne->get_ok_button()->signal_clicked().connect(slot(*this, &SceneEditor::onOkOuvrirFrontiere));
  _winFileSelectionInterne->get_cancel_button()->signal_clicked().connect(slot(*this, &SceneEditor::onCloseFileSelectionInterne));

  InterfaceUtils::openingFileSelection(_winFileSelectionInterne);

  _winFileSelectionInterne->show(); 
}


void SceneEditor::onOkOuvrirFrontiere()
{
  string nom_fichier = _winFileSelectionInterne->get_filename();

  std::ifstream filestream(const_cast<char*>(nom_fichier.c_str()));

  if (!filestream)
    {
      DEBUG_INTERFACE(cout << "[SceneEditor::onOkFileOpen] Erreur dans l'instantiation du filestream -> fichier non trouvé" << endl;);
      popupErrorWindow(_("File not found !"));
      return;
    }
  else
    {
      _zonePrevisualisationFrontieres->clearBorders();
      _zonePrevisualisationZonage->clearBorders();
      _zonePrevisualisationColoration->clearBorders();

      list<Frontiere*> frt;

      int results = StaticIOs::parseMesFrontieres(filestream, frt);
      
      if (results == 0)
	{
	  DEBUG_INTERFACE(cout << "[BordersEditor::onOkFileOpen] Pas d'exception" << endl;);
	}
      else
	{
	  DEBUG_INTERFACE(cout << "[SceneEditor::onOkFileOpen] Exception pendant appel à >> de .frontiere" << endl;);
	  popupErrorWindow(_("Error while reading the file...\nAre you sure this was a borders file?"));
	  return;
	}
      
      _scene.setTableauFrontiere(frt);
      
      list<Frontiere*>::const_iterator it;
      
      for (it = frt.begin(); it != frt.end(); it++)
	createFormBorder((*it)->getForme(), (*it)->getTypeParoi());

      _zonePrevisualisationFrontieres->drawFigures();
      _zonePrevisualisationZonage->drawFigures();
      _zonePrevisualisationColoration->drawFigures();
      _vboxPhase->set_sensitive(true);
      _labelTabPhase->set_sensitive(true);
    }

  onCloseFileSelectionInterne();
}


void SceneEditor::onModifierFrontiere()
{
  _winBorders = new BordersEditor(_scene.getTableauFrontiere());

  _winBorders->signal_hide().connect(slot(*this, &SceneEditor::onCloseBordersEditor));
  _winBorders->set_modal(true);
  _winBorders->show_all();
}


bool SceneEditor::handleButtonPressBorders(GdkEventButton *event)
{
  // We want to intercept double-click to call the edition of the borders.

  if (event->type == GDK_2BUTTON_PRESS)
    onModifierFrontiere();

  return false;
}





// ********* Methods for the notebook page Phases **********

void SceneEditor::openParamPhase(Phase * phase)
{
  g_assert(phase != NULL);

  _phaseEditee = phase;

  _dialogParamPhase = new ParamPhaseDialog(phase, InterfaceUtils::getColorAuxiliary(phase->getCouleur()));
  
  _dialogParamPhase->signal_hide().connect(slot(*this, &SceneEditor::onCancelPhaseProperties));
  _dialogParamPhase->getButtonOk()->signal_clicked().connect(slot(*this, &SceneEditor::onOkPhaseProperties));

  _dialogParamPhase->show_all();

}


void SceneEditor::onPhaseProperties()
{
  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  if (iter) {
    _numModifiedPhase = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
    openParamPhase(_listePhases[_numModifiedPhase]);
  } else
    popupErrorWindow(_("No phase selected."));
}

void SceneEditor::onClosePhaseProperties()
{
  DEBUG_INTERFACE(cout << "[SceneEditor] onFermetureProprietesPhase" << endl;)
  delete _dialogParamPhase;
  _dialogParamPhase = NULL;
}


void SceneEditor::onCancelPhaseProperties()
{
  if (_phaseEditee == NULL)
    return;

  g_assert((_phaseNouvelle != NULL) || (_numModifiedPhase != -1));

  if (_phaseNouvelle != NULL)
    {
      InterfaceUtils::deleteColorAuxiliary(_phaseNouvelle->getCouleur());
      delete _phaseNouvelle;
      _phaseNouvelle = NULL;
    }
  if (_numModifiedPhase != -1)
    _numModifiedPhase = -1;

  _phaseEditee = NULL;

  onClosePhaseProperties();
}


// Here we will take dispositions because the number of phases changed.
void SceneEditor::numberOfPhasesChanged()
{
  // 1. We update the number of phases.
  _labelNbPhases->set_text(_("Number of phases : ")+InterfaceUtils::intToString(_listePhases.size()));
  
  // 2. Setup the sensitivity of the buttons.
  if (_listePhases.size() == 0)
    {
      _buttonProprietePhase->set_sensitive(false);
      _buttonDeletePhase->set_sensitive(false);
      _buttonPropagativePhase->set_sensitive(false);
      _buttonGenereePhase->set_sensitive(false);
      _hboxZonage->set_sensitive(false);
      _labelTabZonage->set_sensitive(false);
      _hboxColoration->set_sensitive(false);
      _labelTabColoration->set_sensitive(false);
    }
  else
    {
      _buttonProprietePhase->set_sensitive(true);
      _buttonDeletePhase->set_sensitive(true);
      _buttonPropagativePhase->set_sensitive(true);
      _buttonGenereePhase->set_sensitive(true);
      _hboxZonage->set_sensitive(true);
      _labelTabZonage->set_sensitive(true);
      _hboxColoration->set_sensitive(true);
      _labelTabColoration->set_sensitive(true);
    }
}


void SceneEditor::onOkPhaseProperties()
{
  DEBUG_INTERFACE(cout << "[SceneEditor::onOkProprietesPhase] enter" << endl;);

  g_assert(((_phaseNouvelle != NULL) || (_numModifiedPhase != -1)) && (_phaseEditee != NULL));

  Gdk::Color * new_color_for_phase = _dialogParamPhase->onOk(_listePhases);

  if (new_color_for_phase == NULL)
    return;

  InterfaceUtils::addColorAuxiliary(_phaseEditee->getCouleur(), new_color_for_phase->get_red(), new_color_for_phase->get_green(), new_color_for_phase->get_blue());


  if (_phaseNouvelle != NULL)
    {
      // We just edited a new phase -> we add it
      Gtk::TreeModel::Row row = *(_gtklistPhase_ls->append());
      row[_gtklistPhase_mc._name] = _phaseNouvelle->getNom();
      _listePhases.push_back(_phaseNouvelle);

      g_assert(_gtklistPhase_ls->iter_is_valid(_gtklistPhase_ls->get_iter(InterfaceUtils::intToString(_listePhases.size()-1)))
	       && !_gtklistPhase_ls->iter_is_valid(_gtklistPhase_ls->get_iter(InterfaceUtils::intToString(_listePhases.size()))));

      numberOfPhasesChanged();
      _phaseNouvelle = NULL;
    }
  else
    if (_numModifiedPhase != -1)
      {
	// We just modified an already existing phase.
	Gtk::TreeModel::Row row = *(_gtklistPhase_ls->get_iter(InterfaceUtils::intToString(_numModifiedPhase)));
	row[_gtklistPhase_mc._name] = _listePhases[_numModifiedPhase]->getNom();

	_numModifiedPhase = -1;

	// Let's re-create the zonings because we modified the phase's color
	_zonePrevisualisationZonage->clearZonings();
	_zonePrevisualisationColoration->clearZonings();
	
	list<Zonage*> zon = _scene.getTableauZonage();
	list<Zonage*>::const_iterator itz;
	for (itz = zon.begin(); itz != zon.end(); itz++)
	  {
	    if (ContientPhase * cp = dynamic_cast<ContientPhase*>((*itz)->getContenuZonage()))
	      createFormZoning((*itz)->getFormeFermee(), cp);
	    else
	      cerr << "[ParamPhaseDialog::onOkColorSelection] I don't want to fill with CelluleHorsScene." << endl;
	  }
	_zonePrevisualisationZonage->drawFigures();
	_zonePrevisualisationColoration->drawFigures();
	
      }

  
  _phaseEditee = NULL;

  onClosePhaseProperties();

}


void SceneEditor::onNewPhase()
{

  // Building a new phase.

  list<RegleExclusion*> pas_de_regles;
  list<RegleExclusion::ModeExclusion> pas_de_modes;

  _phaseNouvelle = new Phase(_("Newphase"));


  // We find a color number for our new phase.
  gint numero_color = InterfaceUtils::getNextFreeNumberAuxiliary();
  _phaseNouvelle->setCouleur(numero_color);


  // We will create a default color, random.
  InterfaceUtils::addColorAuxiliary(numero_color, 1+(gushort) (65535.0*rand()/(RAND_MAX+1.0)), 1+(gushort) (65535.0*rand()/(RAND_MAX+1.0)), 1+(gushort) (65535.0*rand()/(RAND_MAX+1.0)));

  openParamPhase(_phaseNouvelle);
}


void SceneEditor::onDeletePhase()
{
  // Auto-changing the specs -> `delete' button. It's better, no? g.c.

  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  if (iter) {
    int num_a_effacer = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
    string name = (*iter)[_gtklistPhase_mc._name];

    if (num_a_effacer == _numPropagative)
      _numPropagative = -1;
    if (num_a_effacer == _numGeneree)
      _numGeneree = -1;

    _gtklistPhase_ls->erase(iter);
    InterfaceUtils::deleteColorAuxiliary(_listePhases[num_a_effacer]->getCouleur());

    Phase * phase_to_delete = _listePhases[num_a_effacer];

    // Scan of the vector to find the occurence.
    int i = 0;
    for (vector<Phase*>::iterator it_phases = _listePhases.begin() ;
	 it_phases != _listePhases.end() ;
	 it_phases++)
      if ((*it_phases) == _listePhases[num_a_effacer]) {
	_listePhases.erase(it_phases);
	break;
      } else
	i++;

    if (i < _numPropagative)
      _numPropagative--;
    if (i < _numGeneree)
      _numGeneree--;

    // This makes the program gets a Segmentation fault:  TODO: why?
    //	delete phase_to_delete;
    if (phase_to_delete);   // silence compiler warning

    numberOfPhasesChanged();
    
    // We must delete the zoning informations, no longer pertinent
    list<Zonage*> zon;
    _scene.setTableauZonage(zon);
    _zonePrevisualisationZonage->clearZonings();
    _zonePrevisualisationZonage->drawFigures();
    _zonePrevisualisationColoration->clearZonings();
    _zonePrevisualisationColoration->drawFigures();
    
    _buttonSave.set_sensitive(false);
    _menuSave->set_sensitive(false);
    _menuSaveAs->set_sensitive(false);
    
    setToggledButtonsAccordingToSelectedPhase();
  } else
    popupErrorWindow(_("No phase selected."));
}

void SceneEditor::onPropagativePhase()
{
  if (_noRecursiveCall)
    return;

  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  if (iter) {
    int sel_num = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
    string name = (*iter)[_gtklistPhase_mc._name];
    if (_numPropagative != -1)
      _listePhases[_numPropagative]->setPropagatif(false);

    if (_numPropagative == sel_num)
      // We are on the propagative phase -> it's no more propagative
      _numPropagative = -1;
    else {
      // We are on another -> it becomes propagative
      _numPropagative = sel_num;
      _listePhases[_numPropagative]->setPropagatif(true);
    }
  }
  else
      popupErrorWindow(_("No phase selected."));

  setToggledButtonsAccordingToSelectedPhase();
}


void SceneEditor::onGeneratedPhase()
{
  if (_noRecursiveCall)
    return;

  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  if (iter) {
    int sel_num = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));

    if (_numGeneree == sel_num)
      // We are on the generated phase -> it's no more generated
      _numGeneree = -1;
    else
      // We are on another -> it becomes generated
      _numGeneree = sel_num;
  } else
    popupErrorWindow(_("No phase selected."));

  setToggledButtonsAccordingToSelectedPhase();
}


void SceneEditor::setToggledButtonsAccordingToSelectedPhase()
{
  _noRecursiveCall = true;

  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  if (iter) {
    int num_selected = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));

    if (num_selected == _numPropagative)
      _buttonPropagativePhase->set_active(true);
    if (num_selected == _numGeneree)
      _buttonGenereePhase->set_active(true);
    
    if (_numPropagative == -1)
      _buttonPropagativePhase->set_active(false);
    if (_numGeneree == -1)
      _buttonGenereePhase->set_active(false);
  } else {
    // No phase selected.
    _buttonGenereePhase->set_active(false);
    _buttonPropagativePhase->set_active(false);
  }
  
  _noRecursiveCall = false;
}


void SceneEditor::onSelectionChanged()
{
  _noRecursiveCall = true;

  _buttonPropagativePhase->set_active(false);
  _buttonGenereePhase->set_active(false);

  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  if (iter) {
    int n = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
    if (n == _numPropagative)
      _buttonPropagativePhase->set_active(true);
    if (n == _numGeneree)
      _buttonGenereePhase->set_active(true);
  }

  _noRecursiveCall = false;
}


bool SceneEditor::handleButtonPressPhases(GdkEventButton *event)
{
  Gtk::TreeModel::iterator iter = _gtklistPhase_tv->get_selection()->get_selected();

  // We want to intercept double-click to call the Property dialog.
  if (event->type == GDK_2BUTTON_PRESS) {

    if (iter) {
      _numModifiedPhase = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
      openParamPhase(_listePhases[_numModifiedPhase]);
    } else {
      // means no row is currently selected, but we want to edit the properties! make use of _lastSelectedRow
      if (_lastSelectedRow == -1)
	return false;
      _numModifiedPhase = _lastSelectedRow;
      openParamPhase(_listePhases[_numModifiedPhase]);
    }
  } else {
      // We store the last selected row because a double-click can lead to an unselected row properties invocation
      if (iter)
	_lastSelectedRow = InterfaceUtils::stringToInt(_gtklistPhase_ls->get_string(iter));
  }

  return false;
}


bool SceneEditor::handleKeyPressPhases(GdkEventKey *event)
{
  // `delete'
  if (event->keyval == 65535)
    onDeletePhase();

  return false;
}


// ********* Methods for the notebook page Zoning **********

/*
 *** Now talking in #linux-4-ever
 *** topic is "FUCK WINCRASH !!!!"
 <ELitEmAN> kkun a une url de warez pour linux ????
 <veNdeTA> bah euuh sous linux tout est gratuit nan ?
 <ELitEmAN> m'en fout file moi une url @#@$#!!!
*/

void SceneEditor::onCloseZoning()
{
  list<Zonage*> zon = _winEditeurZonage->getListZonage();

  _scene.setTableauZonage(zon);

  _zonePrevisualisationZonage->clearZonings();
  _zonePrevisualisationColoration->clearZonings();

  list<Zonage*>::const_iterator itz;
      
  for (itz = zon.begin(); itz != zon.end(); itz++)
    if (ContientPhase * cp = dynamic_cast<ContientPhase*>((*itz)->getContenuZonage()))
      createFormZoning((*itz)->getFormeFermee(), cp);
    else
      cerr << "[SceneEditor::onFermetureZonage] I don't want to fill with CelluleHorsScene, sorry." << endl;

  _zonePrevisualisationZonage->drawFigures();
  _zonePrevisualisationColoration->drawFigures();


  DEBUG_INTERFACE(cout << "[SceneEditor] onFermetureZonage" << endl;)
  delete _winEditeurZonage;
  _winEditeurZonage = NULL;


  if (zon.size() > 0)
    {
      _buttonSave.set_sensitive(true);
      _menuSave->set_sensitive(true);
      _menuSaveAs->set_sensitive(true);
    }
  else
    {
      _buttonSave.set_sensitive(false);
      _menuSave->set_sensitive(false);
      _menuSaveAs->set_sensitive(false);
    }
}

void SceneEditor::onModifyZoning()
{
  _winEditeurZonage = new ZoningEditor(_listePhases, _scene.getTableauFrontiere(), _scene.getTableauZonage());

  _winEditeurZonage->signal_hide().connect(slot(*this, &SceneEditor::onCloseZoning));
  _winEditeurZonage->set_modal(true);

  _winEditeurZonage->show_all();
}


bool SceneEditor::handleButtonPressZoning(GdkEventButton *event)
{
  // We want to intercept double-click to call the edition of the zoning.

  if (event->type == GDK_2BUTTON_PRESS)
    onModifyZoning();

  return false;
}




// ********* Methods for the notebook page Coloration **********

void SceneEditor::onCloseColoration()
{
  list<Coloration*> col = _winColorationEditor->getListColoration();

  _scene.setTableauColoration(col);

  _zonePrevisualisationColoration->clearColorations();

  list<Coloration*>::const_iterator itc;
      
  for (itc = col.begin(); itc != col.end(); itc++)
    createFormColoration((*itc)->getFormeFermee(), (*itc)->getCouleur());

  _zonePrevisualisationColoration->drawFigures();


  DEBUG_INTERFACE(cout << "[SceneEditor] onFermetureZonage" << endl;)
  delete _winColorationEditor;
  _winColorationEditor = NULL;
  
}

void SceneEditor::onModifyColoration()
{
  _winColorationEditor = new ColorationEditor(_scene.getTableauFrontiere(), _scene.getTableauZonage(), _scene.getTableauColoration());

  _winColorationEditor->signal_hide().connect(slot(*this, &SceneEditor::onCloseColoration));
  _winColorationEditor->set_modal(true);

  _winColorationEditor->show_all();
}


bool SceneEditor::handleButtonPressColoration(GdkEventButton *event)
{
  // We want to intercept double-click to call the edition of the zoning.

  if (event->type == GDK_2BUTTON_PRESS)
    onModifyColoration();

  return false;
}




// ********* Methods for creation of the forms **********

void SceneEditor::createFormBorder(Forme * f, Frontiere::TypeParoi tp)
{
  Gdk::Color * col;
  if (tp == Frontiere::CLASSIQUE)
    col = _colorClassicalBorder;
  else
    col = _colorGeneratingBorder;

  if (Ligne* arg = dynamic_cast<Ligne*>(f))
    {
      GtkLine * ds = new GtkLine(arg, col);
      _zonePrevisualisationFrontieres->addFigureBorder(ds);
      _zonePrevisualisationZonage->addFigureBorder(ds);
      _zonePrevisualisationColoration->addFigureBorder(ds);
      return;
    }
  else 
    if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
      {
	GtkRectangle * dr = new GtkRectangle(arg, col);
	_zonePrevisualisationFrontieres->addFigureBorder(dr);
	_zonePrevisualisationZonage->addFigureBorder(dr);
	_zonePrevisualisationColoration->addFigureBorder(dr);
	return;
      }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _zonePrevisualisationFrontieres->addFigureBorder(de);
	  _zonePrevisualisationZonage->addFigureBorder(de);
	  _zonePrevisualisationColoration->addFigureBorder(de);
	  return;
	}
      else
	if (ArcEllipse* arg = dynamic_cast<ArcEllipse*>(f))
	  {
	    GtkArcEllipse * dae = new GtkArcEllipse(arg, col);
	    _zonePrevisualisationFrontieres->addFigureBorder(dae);
	    _zonePrevisualisationZonage->addFigureBorder(dae);
	    _zonePrevisualisationColoration->addFigureBorder(dae);
	    return;
	  }
	else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _zonePrevisualisationFrontieres->addFigureBorder(dp);
	      _zonePrevisualisationZonage->addFigureBorder(dp);
	      _zonePrevisualisationColoration->addFigureBorder(dp);
	      return;
	    }
  
  cerr << "[SceneEditor::createFormBorder] There is a problem, I don't handle all the forms..." << endl;
}



void SceneEditor::createFormZoning(FormeFermee * f, ContientPhase * cp)
{
  Gdk::Color * col = InterfaceUtils::createColorFromMix(cp);
  
  if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
    {
      GtkRectangle * dr = new GtkRectangle(arg, col);
      _zonePrevisualisationZonage->addFigureZoning(dr);
      _zonePrevisualisationColoration->addFigureZoning(dr);
      return;
    }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _zonePrevisualisationZonage->addFigureZoning(de);
	  _zonePrevisualisationColoration->addFigureZoning(de);
	  return;
	}
      else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _zonePrevisualisationZonage->addFigureZoning(dp);
	      _zonePrevisualisationColoration->addFigureZoning(dp);
	      return;
	    }
  
  cerr << "[SceneEditor::createFormZoning] There is a problem, I don't handle all the forms..." << endl;
}



void SceneEditor::createFormColoration(FormeFermee * f, int color)
{
  Gdk::Color * col = InterfaceUtils::getColorAuxiliary(color);
  
  if (Rectangle* arg = dynamic_cast<Rectangle*>(f))
    {
      GtkRectangle * dr = new GtkRectangle(arg, col);
      _zonePrevisualisationColoration->addFigureColoration(dr);
      return;
    }
    else 
      if (Ellipse* arg = dynamic_cast<Ellipse*>(f))
	{
	  GtkEllipse * de = new GtkEllipse(arg, col);
	  _zonePrevisualisationColoration->addFigureColoration(de);
	  return;
	}
      else
	  if(Polygone* arg = dynamic_cast<Polygone*>(f))
	    {
	      GtkPolygon * dp = new GtkPolygon(arg, col);
	      _zonePrevisualisationColoration->addFigureColoration(dp);
	      return;
	    }
  
  cerr << "[SceneEditor::createFormColoration] There is a problem, I don't handle all the forms..." << endl;
}
