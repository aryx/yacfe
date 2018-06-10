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

#include "Console.h"

#include <config.h>




Console::Console(int argc,char **argv)
{
  
//  DEBUG_CONSOLE(cerr << argc << endl; )
//  DEBUG_CONSOLE(cerr << cin.eof() << endl; )
//  DEBUG_CONSOLE(cerr << cin.bad() << endl; )
//  DEBUG_CONSOLE(cerr << cin.fail() << endl; )
//  DEBUG_CONSOLE(cerr << cin.good() << endl; )


  vector<string> args(argc);
  
  for (int i = 0; i < argc; i++)
    args[i] = string(argv[i]);
		     

  if ( argc == 2 && args[1] == "--help")
    printUsage();

  if ( argc == 2 && args[1] == "--version")
    printVersion();

  if ( argc == 2 && args[1] == "--authors")
    printAuthors();


  bool dim_modifie    = false;
  bool germe_modifie  = false;
  bool nbpas_modifie  = false;
  bool nomfichier_simul_modifie = false;
  bool nomfichier_scene_modifie = false;


  int dim_reseau = -1;
  int germe = -1;
  int nbpas = -1;
  string nomfichier_scene;
  string nomfichier_simul;


  for (int i = 1; i < argc; i++)
    {
      unsigned int j;
      string str;
      
      str = "--network-size=";
      j = args[i].find(str);
      if (!(j < 0 || j > args[i].size()))
	{
	  string substring(args[i].begin()+str.size(), args[i].end());
	  DEBUG_CONSOLE(cerr << substring << endl;)

	  dim_reseau = atoi(substring.c_str());
	  dim_modifie = true;
	  
	}

      str = "--seed=";
      j = args[i].find(str);
      if (!(j < 0 || j > args[i].size()))
	{
	  string substring(args[i].begin()+str.size(), args[i].end());
	  DEBUG_CONSOLE(cerr << substring << endl;)

	  germe = atoi(substring.c_str());
	  germe_modifie = true;
	  
	}

      str = "--number-of-steps=";
      j = args[i].find(str);
      if (!(j < 0 || j > args[i].size()))
	{
	  string substring(args[i].begin()+str.size(), args[i].end());
	  DEBUG_CONSOLE(cerr << substring << endl;)

	  nbpas = atoi(substring.c_str());
	  nbpas_modifie = true;
	  
	}

      // pour les fichiers 
      str = ".scene";
      j = args[i].find(str);
      if (!(j < 0 || j > args[i].size()))
	{
	  
	  nomfichier_scene = args[i];
	  nomfichier_scene_modifie = true;
	  DEBUG_CONSOLE(cerr << nomfichier_scene << endl;)
	  
	}

      str = ".simul";
      j = args[i].find(str);
      if (!(j < 0 || j > args[i].size()))
	{
	  
	  nomfichier_simul = args[i];
	  nomfichier_simul_modifie = true;
	  DEBUG_CONSOLE(cerr << nomfichier_simul << endl;)
	  
	}
    }

  if (nomfichier_scene_modifie && !dim_modifie)
    {
      cerr << _("You did not specify the network size.") << endl;
      exit(0);
    }

  // l'objet
  Automate automate;
    

  // lecture de l'automate (a partir de cin ou nom de fichier)

  
  if (dim_modifie) // c'est une scene
    {
      Scene sc;

      if(nomfichier_scene_modifie)
	{
	  std::ifstream filestream(nomfichier_scene.c_str());
	  filestream >> sc;
	}
      else cin >> sc;

      PlanHexagonal plan(dim_reseau,sc);
      automate = *plan.getAutomate();

    }
  else // c'est une simul
    if (nomfichier_simul_modifie)
      {
	std::ifstream filestream(nomfichier_simul.c_str());
	filestream >> automate;
      }
    else cin >> automate;


  if (germe_modifie)
    automate.setGerme(germe);

  if (nbpas_modifie)
    automate.setNbrePas(nbpas);


  //  DEBUG_CONSOLE(automate.afficheurReseau();)
  for (int i = 0; i < automate.getNbrePas(); i++)
    {
      automate.genereTransition();
    }

  DEBUG_CONSOLE(automate.afficheurReseau();)
  
  cout << automate;
}

Console::~Console() 
{
  
}
string Console::getNomProg()
{
  return  string(PACKAGE) + _("console");
}

string Console::coolHeader()
{
  return "["+getNomProg()+"] ";
}

void Console::printHelp()
{
  cerr << _("This is") << " " << getNomProg() << ", " << _("the celullar automaton simulator.") << endl;

}
void Console::printVersion()
{
  i18nPrintings();

  cerr << getNomProg() << ", " << _("version") << " " << VERSION << endl;

  exit(0);
  
}

#define DECALAGE "\t\t\t"

void Console::printUsage()
{
  i18nPrintings();

  cerr << _("Usage") << ": " << getNomProg() << " [--help] [--version] [--authors] [OPTION] [foo(.scene)|(.simul)]" << endl;
  cerr << _("Launch the simulation or the scene from FILE or standard input") << endl;
  cerr << _("Options") << ":" << endl;
  cerr << " --seed=NBR" << DECALAGE<< "\t" << _("seed of the simulation") << endl;
  cerr << " --number-of-steps=NBR" << DECALAGE << _("number of steps of the simulation") << endl;
  cerr << " --network-size=NBR" << DECALAGE << _("if the argument is a scene, gives the dimension of the network") << endl;
  
  cerr << endl;
  
  cerr << " --help" << DECALAGE <<  "\t\t" << _("prints a summary of the options") << endl;
  cerr << " --version" << DECALAGE << "\t" << _("prints the version number") << endl;
  cerr << " --authors" << DECALAGE << "\t" << _("prints the authors") << endl;
  

  exit(0);

}


void Console::printAuthors()
{
  i18nPrintings();

  cerr << getNomProg() << ", " << _("version") << " " << VERSION << ", authors:" << endl << endl;

  cerr << "Yoann Padioleau, <ypadiole@ens.insa-rennes.fr> \t\t\t" << _("file handling, engine, tools (configure...)") << endl;
  cerr << "Guillaume Cottenceau, <gcottenc at altern dot org> \t\t\t" << _("graphical interface") << endl;
  cerr << "Pascal Garcia, <pgarcia@ens.insa-rennes.fr> \t\t\t" << _("hexagonal algorithms") << endl;
  cerr << "Gaetan Le Guelvouit, <gaetan@mail.dotcom.com> \t\t\t" << _("design") << endl;
  cerr << "Yacine Zemali, <yzemali@ens.insa-rennes.fr> \t\t\t" << _("contribution to the graphical interface") << endl;
  cerr << "Sebastien Crunchant, <scruncha@ens.insa-rennes.fr> \t\t" << _("contribution to file handling") << endl;
  cerr << "Xavier Michard, <xmichard@ens.insa-rennes.fr> \t\t\t" << _("contribution to file handling") << endl;

  cerr << endl;

  cerr << "This piece of software has been developped as part of our degree of engineer at Insa Rennes, <http://www.insa-rennes.fr>." << endl;

  cerr << endl;

  cerr << "page: http://guillaume.cottenceau.free.fr/html/grany.html" << endl;
  cerr << "online-french-help: http://www.multimania.com/granyrules" << endl;

  exit(0);
  
}


void Console::i18nPrintings()
{
#ifdef ENABLE_NLS
  textdomain(PACKAGE);
  setlocale (LC_MESSAGES, "");
  bindtextdomain(PACKAGE, LOCALEDIR);
#endif 
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
