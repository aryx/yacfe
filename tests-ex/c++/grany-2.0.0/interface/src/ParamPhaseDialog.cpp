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

#include "ParamPhaseDialog.h"
#include "RegleExclusion.h"
#include <dirent.h>


ParamPhaseDialog::ParamPhaseDialog(Phase * phase, Gdk::Color * phase_color)
{
  // Pointers to override the huge-objects problem on shitty sun. Quite a few objects.
  _notebook = new Gtk::Notebook();

  _vboxGeneral = new Gtk::VBox();
  _vboxOtherParametersGeneral = new Gtk::VBox();
  _hboxNameGeneral = new Gtk::HBox();
  _hboxParametersGeneral = new Gtk::HBox();
  _hboxColorGeneral = new Gtk::HBox();
  _hboxInertia = new Gtk::HBox();

  _radioSolidPhase = new Gtk::RadioButton(_("The phase is solid"));
  _radioFluidPhase = new Gtk::RadioButton(_("The phase is fluid"));
  Gtk::RadioButton::Group dummy = _radioSolidPhase->get_group();
  _radioFluidPhase->set_group(dummy);

  _labelTabGeneral = new Gtk::Label(_("General"));
  _labelNameGeneral = new Gtk::Label(_("Name :"));
  _labelInertia = new Gtk::Label(_("Inertia :"));
  _entryNameGeneral = new Gtk::Entry();
  _entryInertia = new Gtk::Entry();
  _buttonColorGeneral = new Gtk::Button(__("Color"));

  _hboxRule = new Gtk::HBox(false);
  _hboxPreRules = new Gtk::HBox(false);
  _hboxPostRules = new Gtk::HBox(false);
  _vboxUsableRule = new Gtk::VBox(false,10);
  _vboxSelectedRules = new Gtk::VBox(false);
  _vboxPreRules = new Gtk::VBox(false);
  _vboxPostRules = new Gtk::VBox(false);
  _buttonsPre = new Gtk::VBox(false,10);
  _buttonsPost = new Gtk::VBox(false,10);
  _scrwinPreRules = new Gtk::ScrolledWindow();
  _scrwinPostRules= new Gtk::ScrolledWindow();
  _scrwinUsableRule = new Gtk::ScrolledWindow();
  _listPostRules_tv = new Gtk::TreeView();
  _listPreRules_tv = new Gtk::TreeView();
  _listUsableRules_tv = new Gtk::TreeView();

  _labelTabRule = new Gtk::Label(_("Rules"));
  _labelUsableRule = new Gtk::Label(_("Usable rules"));
  _labelPreRules = new Gtk::Label(_("Pre-exclusion rules"));
  _labelPostRules = new Gtk::Label(_("Post-exclusion rules"));
  _labelVoidPre = new Gtk::Label("");
  _labelVoidPost = new Gtk::Label("");
  _buttonNew = new Gtk::Button(__("Design new rule"));
  _buttonAddPre = new Gtk::Button(__("Add in pre ")+"-->  ");
  _buttonAddPost = new Gtk::Button(__("Add in post")+"-->  ");
  _buttonRemovePre = new Gtk::Button(string("  <--")+__("Remove from pre "));
  _buttonRemovePost = new Gtk::Button(string("  <--")+__("Remove from post"));
  
  _tablePonderation = new Gtk::Table(4, 3, true);
  _labelTabPonderation = new Gtk::Label(_("Ponderations"));
  _labelN = new Gtk::Label(_("North"));
  _labelS = new Gtk::Label(_("South"));
  _labelNE = new Gtk::Label(_("North-east"));
  _labelNW = new Gtk::Label(_("North-west"));
  _labelSE = new Gtk::Label(_("South-east"));
  _labelSW = new Gtk::Label(_("South-west"));
  _vboxN = new Gtk::VBox();
  _vboxS = new Gtk::VBox();
  _vboxNE = new Gtk::VBox();
  _vboxNW = new Gtk::VBox();
  _vboxSE = new Gtk::VBox();
  _vboxSW = new Gtk::VBox();
  _entryN = new Gtk::Entry();
  _entryS = new Gtk::Entry();
  _entryNE = new Gtk::Entry();
  _entryNW = new Gtk::Entry();
  _entrySE = new Gtk::Entry();
  _entrySW = new Gtk::Entry();
  
  _buttonOK = new Gtk::Button(__("Ok"));
  _buttonCancel = new Gtk::Button(__("Cancel"));


  set_title(_("Phases parameters"));

  get_vbox()->set_border_width(2);

  set_default_size(600,300);

  get_vbox()->pack_start(*_notebook);

  signal_key_press_event().connect(slot(*this, &ParamPhaseDialog::handleKeyPress));
  set_events(Gdk::KEY_PRESS_MASK);


  // First notebook page
  _notebook->append_page(*_vboxGeneral, *_labelTabGeneral);

  _vboxGeneral->pack_start(*_hboxNameGeneral, false, false, 10);
  _vboxGeneral->pack_start(*_hboxParametersGeneral, false, false, 10);
  _hboxColorGeneral->pack_start(*_buttonColorGeneral, false, false, 10);
  _vboxGeneral->pack_start(*_hboxColorGeneral, false, false, 10);

  _phaseColor = phase_color;

  _hboxNameGeneral->pack_start(*_labelNameGeneral, false, false, 10);
  _hboxNameGeneral->pack_start(*_entryNameGeneral, false, false, 10);

  _hboxParametersGeneral->pack_start(*_vboxOtherParametersGeneral);
  
  _vboxOtherParametersGeneral->pack_start(*_radioSolidPhase);
  _vboxOtherParametersGeneral->pack_start(*_radioFluidPhase);
  _vboxOtherParametersGeneral->pack_start(*_hboxInertia, false, false, 10);

  _hboxInertia->pack_start(*_labelInertia, false, false, 10);
  _hboxInertia->pack_start(*_entryInertia, false, false, 10);


  _buttonColorGeneral->signal_clicked().connect(slot(*this, &ParamPhaseDialog::onOpenColorSelection));

  // Second page

  _winRuleEditor = NULL;
  _lastSelectedPreRule = -1; _lastSelectedPostRule = -1; _lastSelectedRowUsable = -1;



  _hboxPreRules->pack_start(*_buttonsPre, false, false, 25);
  _hboxPreRules->pack_end(*_vboxPreRules);
  _hboxPostRules->pack_start(*_buttonsPost, false, false, 25);
  _hboxPostRules->pack_end(*_vboxPostRules);

  _vboxUsableRule->pack_start(*_labelUsableRule, false, false);
  _vboxUsableRule->pack_start(*_scrwinUsableRule);
  _vboxUsableRule->pack_end(*_buttonNew, false, false, 10);

  _listUsableRules_ls = Gtk::ListStore::create(_listUsableRules_mc);
  _listUsableRules_tv->set_model(_listUsableRules_ls);
  _listUsableRules_tv->append_column("dummy", _listUsableRules_mc._name);
  _listUsableRules_tv->set_headers_visible(false);
  _listUsableRules_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);
  _scrwinUsableRule->add(*_listUsableRules_tv);
  _scrwinUsableRule->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  _vboxPreRules->pack_start(*_labelPreRules, false, false);
  _vboxPreRules->pack_end(*_scrwinPreRules);
  _listPreRules_ls = Gtk::ListStore::create(_listPreRules_mc);
  _listPreRules_tv->set_model(_listPreRules_ls);
  _listPreRules_tv->append_column("dummy", _listPreRules_mc._name);
  _listPreRules_tv->set_headers_visible(false);
  _listPreRules_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);
  _scrwinPreRules->add(*_listPreRules_tv);
  _scrwinPreRules->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  _vboxPostRules->pack_start(*_labelPostRules, false, false);
  _vboxPostRules->pack_end(*_scrwinPostRules);
  _listPostRules_ls = Gtk::ListStore::create(_listPostRules_mc);
  _listPostRules_tv->set_model(_listPostRules_ls);
  _listPostRules_tv->append_column("dummy", _listPostRules_mc._name);
  _listPostRules_tv->set_headers_visible(false);
  _listPostRules_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);
  _scrwinPostRules->add(*_listPostRules_tv);
  _scrwinPostRules->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  _buttonsPre->pack_start(*_labelVoidPre, false, false);
  _buttonsPre->pack_start(*_buttonAddPre, false, false);
  _buttonsPre->pack_start(*_buttonRemovePre, false, false);
  _buttonsPost->pack_start(*_labelVoidPost, false, false);
  _buttonsPost->pack_start(*_buttonAddPost, false, false);
  _buttonsPost->pack_start(*_buttonRemovePost, false, false);

  _listUsableRules_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);
  _listPreRules_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);
  _listPostRules_tv->get_selection()->set_mode(Gtk::SELECTION_SINGLE);

  _listUsableRules_tv->signal_button_press_event().connect(slot(*this, &ParamPhaseDialog::handleButtonPressUsable), false);
  _listPreRules_tv->signal_button_press_event().connect(slot(*this, &ParamPhaseDialog::handleButtonPressPreRule), false);
  _listPostRules_tv->signal_button_press_event().connect(slot(*this, &ParamPhaseDialog::handleButtonPressPostRule), false);
  
  populateRules();

  _buttonNew->signal_clicked().connect(slot(*this, &ParamPhaseDialog::onNewRule));
  _buttonAddPre->signal_clicked().connect(slot(*this, &ParamPhaseDialog::onAddPreRule));
  _buttonAddPost->signal_clicked().connect(slot(*this, &ParamPhaseDialog::onAddPostRule));
  _buttonRemovePre->signal_clicked().connect(slot(*this, &ParamPhaseDialog::onRemovePreRule));
  _buttonRemovePost->signal_clicked().connect(slot(*this, &ParamPhaseDialog::onRemovePostRule));

  _vboxSelectedRules->pack_start(*_hboxPreRules);
  _vboxSelectedRules->pack_end(*_hboxPostRules);

  _hboxRule->pack_start(*_vboxUsableRule);
  _hboxRule->pack_end(*_vboxSelectedRules);

  _notebook->append_page(*_hboxRule,*_labelTabRule);
  

  // Third page
  _notebook->append_page(*_tablePonderation,*_labelTabPonderation);

  _tablePonderation->attach(*_vboxN,  1, 2, 0, 1, Gtk::FILL, Gtk::FILL);
  _tablePonderation->attach(*_vboxS,  1, 2, 3, 4, Gtk::EXPAND, Gtk::EXPAND);
  _tablePonderation->attach(*_vboxNE, 2, 3, 1, 2, Gtk::EXPAND, Gtk::EXPAND);
  _tablePonderation->attach(*_vboxNW, 0, 1, 1, 2, Gtk::EXPAND, Gtk::EXPAND);
  _tablePonderation->attach(*_vboxSE, 2, 3, 2, 3, Gtk::EXPAND, Gtk::EXPAND);
  _tablePonderation->attach(*_vboxSW, 0, 1, 2, 3, Gtk::EXPAND, Gtk::EXPAND);


  _vboxN->pack_start(*_labelN);
  _vboxN->pack_end(*_entryN);

  _vboxS->pack_start(*_labelS);
  _vboxS->pack_end(*_entryS);
  
  _vboxNE->pack_start(*_labelNE);
  _vboxNE->pack_end(*_entryNE);
  
  _vboxNW->pack_start(*_labelNW);
  _vboxNW->pack_end(*_entryNW);

  _vboxSE->pack_start(*_labelSE);
  _vboxSE->pack_start(*_entrySE);

  _vboxSW->pack_start(*_labelSW);
  _vboxSW->pack_end(*_entrySW);
  

  get_action_area()->pack_start(*_buttonOK, true, true, 10);
  get_action_area()->pack_end(*_buttonCancel, true, true, 10);


  _buttonCancel->signal_clicked().connect(slot(*this, &ParamPhaseDialog::onCancel));



  // We update the entries according to the edited phase
  _phase = phase;

  _entryNameGeneral->set_text(_phase->getNom());

  updateColorButtonColor();

  // NB : phi is not value user can set directly ; however the phi is determined by the `solid' of `fluid' state of the phase
  if (_phase->getPhi() >= PHI_SOLIDE)
    _radioFluidPhase->set_active(true);
  else
    _radioSolidPhase->set_active(true);

  // Let's produce a private copy of the used rules. (because of the `cancel' button possibility!)
  const list<Phase::RegleEtMode> phase_rules = *(_phase->getRegleEtModeExclusion());

  for (list<Phase::RegleEtMode>::const_iterator it = phase_rules.begin() ; it != phase_rules.end() ; it++)
    {
      Phase::RegleEtMode new_r_and_m;
      new_r_and_m.regle = (*it).regle;
      new_r_and_m.mode = (*it).mode;
      _usedRules.push_back(new_r_and_m);

      if (new_r_and_m.mode == RegleExclusion::PRE) {
	  Gtk::TreeModel::Row row = *(_listPreRules_ls->append());
	  row[_listPreRules_mc._name] = new_r_and_m.regle->getNom();
      } else {
	  Gtk::TreeModel::Row row = *(_listPostRules_ls->append());
	  row[_listPostRules_mc._name] = new_r_and_m.regle->getNom();
      }
    }

  // NB : the propagative property is not editable `phase-wise'. Nor the generated property.
  _entryInertia->set_text(InterfaceUtils::intToString(_phase->getInertie()));
  _entryN->set_text(InterfaceUtils::intToString(_phase->getPonderation().getPonderation(NORD)));
  _entryNE->set_text(InterfaceUtils::intToString(_phase->getPonderation().getPonderation(NE)));
  _entrySE->set_text(InterfaceUtils::intToString(_phase->getPonderation().getPonderation(SE)));
  _entryS->set_text(InterfaceUtils::intToString(_phase->getPonderation().getPonderation(SUD)));
  _entrySW->set_text(InterfaceUtils::intToString(_phase->getPonderation().getPonderation(SW)));
  _entryNW->set_text(InterfaceUtils::intToString(_phase->getPonderation().getPonderation(NW)));
}

ParamPhaseDialog::~ParamPhaseDialog()
{
  if (_winRuleEditor)
    delete _winRuleEditor;

  delete _notebook;  delete _vboxGeneral;  delete _vboxOtherParametersGeneral;  delete _hboxNameGeneral;
  delete _hboxParametersGeneral;  delete _hboxColorGeneral;  delete _hboxInertia;  delete _radioSolidPhase;
  delete _radioFluidPhase;  delete _labelTabGeneral;  delete _labelNameGeneral;  delete _labelInertia;
  delete _entryNameGeneral;  delete _entryInertia;  delete _buttonColorGeneral;  delete _hboxRule;
  delete _hboxPreRules;  delete _hboxPostRules;  delete _vboxUsableRule;  delete _vboxSelectedRules;
  delete _vboxPreRules;  delete _vboxPostRules;  delete _buttonsPre;  delete _buttonsPost;
  delete _scrwinPreRules;  delete _scrwinPostRules;  delete _scrwinUsableRule; 
  delete _listPostRules_tv; delete _listPreRules_tv;  delete _listUsableRules_tv; 
  delete _labelTabRule;  delete _labelUsableRule;
  delete _labelPreRules;  delete _labelPostRules;  delete _buttonNew;  delete _buttonAddPre;
  delete _buttonAddPost;  delete _buttonRemovePre;  delete _buttonRemovePost;  delete _tablePonderation;
  delete _labelTabPonderation;  delete _labelN;  delete _labelS;  delete _labelNE;
  delete _labelNW;  delete _labelSE;  delete _labelSW;  delete _vboxN;
  delete _vboxS;  delete _vboxNE;  delete _vboxNW;  delete _vboxSE;
  delete _vboxSW;  delete _entryN;  delete _entryS;  delete _entryNE;
  delete _entryNW;  delete _entrySE;  delete _entrySW;  delete _buttonOK;
  delete _buttonCancel;
}

void ParamPhaseDialog::onCancel()
{
  hide();
}

Gtk::Button* ParamPhaseDialog::getButtonOk()
{
  return _buttonOK;
}


void ParamPhaseDialog::updateColorButtonColor()
{
  Glib::RefPtr<Gtk::Style> style = _buttonColorGeneral->get_style()->copy();
  Gdk::Color temp_color;
  
  style->set_bg(Gtk::STATE_NORMAL, *_phaseColor);
  temp_color = InterfaceUtils::darker(*new Gdk::Color(*_phaseColor));
  style->set_bg(Gtk::STATE_ACTIVE, temp_color);
  temp_color = InterfaceUtils::lighter(*new Gdk::Color(*_phaseColor));
  style->set_bg(Gtk::STATE_PRELIGHT, temp_color);

  _buttonColorGeneral->set_style(style);
}


void ParamPhaseDialog::onOpenColorSelection()
{
  Gtk::ColorSelectionDialog cs(_("Please choose a color..."));
  cs.set_modal(true);

  cs.get_colorsel()->set_current_color(*_phaseColor);

  if (cs.run() == Gtk::RESPONSE_OK) {
    _phaseColor = new Gdk::Color(cs.get_colorsel()->get_current_color());
    
    updateColorButtonColor();
  }
}


void ParamPhaseDialog::onCloseRuleEditor()
{
  DEBUG_INTERFACE(cout << "[ParamPhaseDialog::onCloseRuleEditor]" << endl;)

  string new_filename = _winRuleEditor->getSavedRuleFilename();
  string new_name = _winRuleEditor->getSavedRuleName();

  _winRuleEditor->hide();

  _winRuleEditor->set_modal(false);
  delete _winRuleEditor;
  _winRuleEditor = NULL;


  if (new_filename == "")
    popupErrorWindow(_("Please save the rule in the rules editor"));
  else

    {
      // Adding in my string vector of absolute paths
      _absolutePathUsableRules.push_back(new_filename);

      // Adding in the list
      Gtk::TreeModel::Row row = *(_listUsableRules_ls->append());
      row[_listUsableRules_mc._name] = new_name;
    }
}


RegleExclusion * ParamPhaseDialog::openRuleFile(string name)
{
  std::ifstream filestream(const_cast<char*>(name.c_str()));

  if (!filestream)
    {
      popupErrorWindow(_("Error while reading the rule file. Reinstall Microsoft Windows.\n(seriously, you're in trouble)"));
      return NULL;
    }

  RegleExclusion * rule = new (RegleExclusion);

  try
    {
      filestream >> *rule;
    }
  catch (RegleCompiler::Exception e)
    {
      popupErrorWindow(_("Error while reading the rule file. Reinstall Microsoft Windows.\n(seriously, you're in trouble)"));
      return NULL;
    }

  return rule;
}

void ParamPhaseDialog::onNewRule()
{
  DEBUG_INTERFACE(cout << "[ParamPhaseDialog::onNewRule]" << endl;)

  _winRuleEditor = new RulesEditor();

  _winRuleEditor->signal_hide().connect(slot(*this, &ParamPhaseDialog::onCloseRuleEditor));
  _winRuleEditor->set_modal(true);
  _winRuleEditor->show_all();
}



void ParamPhaseDialog::onAddPreRule()
{
  DEBUG_INTERFACE(cout << "[ParamPhaseDialog::onAddPreRule]" << endl;);
  
  if (_absolutePathUsableRules.size() > 0)
   g_assert(
    _listUsableRules_ls->iter_is_valid(_listUsableRules_ls->get_iter(InterfaceUtils::intToString(_absolutePathUsableRules.size()-1)))
    && !_listUsableRules_ls->iter_is_valid(_listUsableRules_ls->get_iter(InterfaceUtils::intToString(_absolutePathUsableRules.size()))));

  Gtk::TreeModel::iterator iter = _listUsableRules_tv->get_selection()->get_selected();

  if (iter) {
    int num_selected = InterfaceUtils::stringToInt(_listUsableRules_ls->get_string(iter));
    RegleExclusion * new_rule = openRuleFile(_absolutePathUsableRules[num_selected]);

    if (new_rule == NULL)
      return;

    // Ok now we have our rule.
	  
    // Adding to the list
    Gtk::TreeModel::Row row = *(_listPreRules_ls->append());
    string name = (*iter)[_listUsableRules_mc._name];
    row[_listUsableRules_mc._name] = name;

    // Adding in the _usedRules
    Phase::RegleEtMode new_r_and_m;
    new_r_and_m.regle = new_rule;
    new_r_and_m.mode = RegleExclusion::PRE;
    _usedRules.push_back(new_r_and_m);
  }
  else
    popupErrorWindow(_("No rule selected."));
}


void ParamPhaseDialog::onRemovePreRule()
{
  DEBUG_INTERFACE(cout << "[ParamPhaseDialog::onRemoveRule]" << endl;);

  Gtk::TreeModel::iterator iter = _listPreRules_tv->get_selection()->get_selected();

  if (iter) {
    int num_selected = InterfaceUtils::stringToInt(_listPreRules_ls->get_string(iter));
    string name = (*iter)[_listPreRules_mc._name];
	  
    // Remove from the list
    _listPreRules_ls->erase(iter);
      
    // Remove from _usedRules
    for (list<Phase::RegleEtMode>::iterator it = _usedRules.begin() ; it != _usedRules.end() ; it++)
      if ((it->regle->getNom() == name) && (it->mode == RegleExclusion::PRE)) {
	_usedRules.erase(it);
	break;
      }
  }
  else
    popupErrorWindow(_("No rule selected."));
}


void ParamPhaseDialog::onAddPostRule()
{
  DEBUG_INTERFACE(cout << "[ParamPhaseDialog::onAddPostRule]" << endl;);
  
  if (_absolutePathUsableRules.size() > 0)
   g_assert(
    _listUsableRules_ls->iter_is_valid(_listUsableRules_ls->get_iter(InterfaceUtils::intToString(_absolutePathUsableRules.size()-1)))
    && !_listUsableRules_ls->iter_is_valid(_listUsableRules_ls->get_iter(InterfaceUtils::intToString(_absolutePathUsableRules.size()))));

  Gtk::TreeModel::iterator iter = _listUsableRules_tv->get_selection()->get_selected();

  if (iter) {
    int num_selected = InterfaceUtils::stringToInt(_listUsableRules_ls->get_string(iter));
    RegleExclusion * new_rule = openRuleFile(_absolutePathUsableRules[num_selected]);

    if (new_rule == NULL)
      return;

    // Ok now we have our rule.
	  
    // Adding to the list
    Gtk::TreeModel::Row row = *(_listPostRules_ls->append());
    string name = (*iter)[_listUsableRules_mc._name];
    row[_listUsableRules_mc._name] = name;

    // Adding in the _usedRules
    Phase::RegleEtMode new_r_and_m;
    new_r_and_m.regle = new_rule;
    new_r_and_m.mode = RegleExclusion::PRE;
    _usedRules.push_back(new_r_and_m);
  }
  else
    popupErrorWindow(_("No rule selected."));
}


void ParamPhaseDialog::onRemovePostRule()
{
  DEBUG_INTERFACE(cout << "[ParamPhaseDialog::onRemovePostRule]" << endl;);

  Gtk::TreeModel::iterator iter = _listPostRules_tv->get_selection()->get_selected();

  if (iter) {
    int num_selected = InterfaceUtils::stringToInt(_listPostRules_ls->get_string(iter));
    string name = (*iter)[_listPostRules_mc._name];
	  
    // Remove from the list
    _listPostRules_ls->erase(iter);
      
    // Remove from _usedRules
    for (list<Phase::RegleEtMode>::iterator it = _usedRules.begin() ; it != _usedRules.end() ; it++)
      if ((it->regle->getNom() == name) && (it->mode == RegleExclusion::POST)) {
	_usedRules.erase(it);
	break;
      }
  }
  else
    popupErrorWindow(_("No rule selected."));
}


/// This is code taken from gtk+/gtkfilesel.c ; so it's not c++, sorry.
int ParamPhaseDialog::populateWithDir(string dir)
{
  DIR* directory;

  struct dirent *dirent_ptr;

  directory = opendir(const_cast<char*>(dir.c_str()));

  if(!directory)
    return 0;

  else
    {
      int i = 0;
      while((dirent_ptr = readdir(directory)) != NULL)
	{
	  string filename = dirent_ptr->d_name;

	  if ((filename != ".") && (filename != ".."))
	    {
	      i++;
	      // Adding in my string vector of absolute paths
	      _absolutePathUsableRules.push_back(dir + filename);

	      RegleExclusion * rule = openRuleFile(dir + filename);
	      if (rule == NULL)
		return -1;

	      // Adding in the list
	      Gtk::TreeModel::Row row = *(_listUsableRules_ls->append());
	      row[_listUsableRules_mc._name] = rule->getNom();

	      delete rule;
	    }
	}
      closedir(directory);
      return i;
    }
}

/// This method will populate the list of rules, reading in home directory, ~/.grany/files/rules
void ParamPhaseDialog::populateRules()
{
  // First let's open the user directory
  int res1 = populateWithDir(string(g_get_home_dir()) + "/.grany" + string(RULES_DIR));

  // Then let's open the grany installation directory
  //  int res2 = populateWithDir(string(PKGDATADIR) + string(RULES_DIR));

  // I don't do it anymore because now I copy all example files in user directory - easier if
  // he wants to modify files, etc...
  
  //  if (res1 == -1)
  //    popupWarningWindowFromConstructor("Problem while reading the rules...");
  // already a popupError in the openRule() method

  if (res1 == 0)
    popupWarningWindowFromConstructor("Rules finder: no rule could be found in directory :\n"+string(g_get_home_dir()) + "/.grany" + string(RULES_DIR));
}


Gdk::Color * ParamPhaseDialog::onOk(const vector<Phase *> phases)
{
  DEBUG_INTERFACE(cout << "[ParamPhaseDialog::onOk] enter" << endl;);

  // We verify the entries
  
  string name = _entryNameGeneral->get_text();

  for (unsigned int i=0 ; i< name.size() ; i++)
    {
      char char_to_test = name[i];
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
	      _notebook->set_current_page(0);
	      _entryNameGeneral->select_region(0,_entryNameGeneral->get_text_length());
	      return NULL;
	    }
	}
    }

  if (name == "")
    {
      popupErrorWindow(_("The value entered for `name' is not valid. It must not be void."));
      _notebook->set_current_page(0);
      _entryNameGeneral->select_region(0,_entryNameGeneral->get_text_length());
      return NULL;
    }

  for (unsigned int i=0; i<phases.size() ; i++)
    if ((_entryNameGeneral->get_text() == phases[i]->getNom()) && (phases[i] != _phase))
      {
	popupErrorWindow(_("The value entered for `name' is not valid. It must be different from the other phases names."));
	_notebook->set_current_page(0);
	_entryNameGeneral->select_region(0,_entryNameGeneral->get_text_length());
	return NULL;
      }

  if (!InterfaceUtils::stringConvertible(_entryInertia->get_text()))
    {
      popupErrorWindow(_("The value entered for `inertie' is not valid. It must be a number."));
      _notebook->set_current_page(0);
      _entryInertia->select_region(0,_entryInertia->get_text_length());
      return NULL;
    }

  if (!InterfaceUtils::stringConvertible(_entryN->get_text()))
    {
      popupErrorWindow(_("The value entered for `North' is not valid. It must be a number."));
      _notebook->set_current_page(2);
      _entryN->select_region(0,_entryN->get_text_length());
      return NULL;
    }

  if (!InterfaceUtils::stringConvertible(_entryNE->get_text()))
    {
      popupErrorWindow(_("The value entered for `North east' is not valid. It must be a number."));
      _notebook->set_current_page(2);
      _entryNE->select_region(0,_entryNE->get_text_length());
      return NULL;
    }

  if (!InterfaceUtils::stringConvertible(_entryNW->get_text()))
    {
      popupErrorWindow(_("The value entered for `North west' is not valid. It must be a number."));
      _notebook->set_current_page(2);
      _entryNW->select_region(0,_entryNW->get_text_length());
      return NULL;
    }

  if (!InterfaceUtils::stringConvertible(_entryS->get_text()))
    {
      popupErrorWindow(_("The value entered for `South' is not valid. It must be a number."));
      _notebook->set_current_page(2);
      _entryS->select_region(0,_entryS->get_text_length());
      return NULL;
    }

  if (!InterfaceUtils::stringConvertible(_entrySE->get_text()))
    {
      popupErrorWindow(_("The value entered for `South east' is not valid. It must be a number."));
      _notebook->set_current_page(2);
      _entrySE->select_region(0,_entrySE->get_text_length());
      return NULL;
    }

  if (!InterfaceUtils::stringConvertible(_entrySW->get_text()))
    {
      popupErrorWindow(_("The value entered for `South west' is not valid. It must be a number."));
      _notebook->set_current_page(2);
      _entrySW->select_region(0,_entrySW->get_text_length());
      return NULL;
    }


  // We will update all the properties of the phase according to the values in the entries
  _phase->setNom(_entryNameGeneral->get_text());
  _phase->setInertie(InterfaceUtils::stringToInt(_entryInertia->get_text()));

  _phase->setRegleEtModeExclusion(_usedRules);

  int tab_ponds[6] = { InterfaceUtils::stringToInt(_entryN->get_text()),
		       InterfaceUtils::stringToInt(_entryNE->get_text()),
		       InterfaceUtils::stringToInt(_entrySE->get_text()),
		       InterfaceUtils::stringToInt(_entryS->get_text()),
		       InterfaceUtils::stringToInt(_entrySW->get_text()),
		       InterfaceUtils::stringToInt(_entryNW->get_text()) };
  _phase->setPonderation(Ponderation(tab_ponds));


  /*
   * Problem: phi must be setup according to other phases and their state fluid or solid.
   *
   * I adopt this convention: I setup as phi the floor value for its category. Then externaly the callers of this class will
   * setup the definitive value for phi.
   */

  if (_radioFluidPhase->get_active() == true)
    _phase->setPhi(PHI_SOLIDE);
  else
    _phase->setPhi(0);


  // Then we return the color, the caller will update it in the right colormap
  return _phaseColor;
}


// Yes we don't inherit from BasicWindow. Ok it's not good.
void ParamPhaseDialog::popupErrorWindow(const string &s)
{
  ErrorWindow e(s);
}


// This is special method because of the `modality' property.
void ParamPhaseDialog::popupWarningWindowFromConstructor(const string &s)
{
  WarningWindow w(s);
}


bool ParamPhaseDialog::handleButtonPressUsable(GdkEventButton *event)
{
  if (event->type == GDK_2BUTTON_PRESS)
    onAddPreRule();
  return false;
}

bool ParamPhaseDialog::handleButtonPressPreRule(GdkEventButton *event)
{
  if (event->type == GDK_2BUTTON_PRESS)
    onRemovePreRule();
  return false;
}

bool ParamPhaseDialog::handleButtonPressPostRule(GdkEventButton *event)
{
  if (event->type == GDK_2BUTTON_PRESS)
    onRemovePostRule();
  return false;
}


bool ParamPhaseDialog::handleKeyPress(GdkEventKey *event)
{
  // This is `enter' and `numeric keypad enter'
  if ((event->keyval == 65293) || (event->keyval == 65421))
    _buttonOK->activate();

  // This is `escape'.
  if (event->keyval == 65307)
    hide();

  return false; // for gtk to edit the entries!!
}
