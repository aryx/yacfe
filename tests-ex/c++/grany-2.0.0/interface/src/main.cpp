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
#include "WarningWindow.h"
#include <time.h>


string getNomProg()
{
  return string(PACKAGE);
}

string coolHeader()
{
  return "["+getNomProg()+"] ";
}


void printAuthors()
{
  cerr << getNomProg() << ", " << gettext("version") << " " << VERSION << ", authors:" << endl << endl;

  cerr << "Yoann Padioleau, <ypadiole@ens.insa-rennes.fr> \t\t\t" << gettext("engine, file handling, tools (autoconf...)") << endl;
  cerr << "Guillaume Cottenceau, <gcottenc at altern dot org> \t\t\t" << gettext("graphical interface") << endl;
  cerr << "Pascal Garcia, <pgarcia@ens.insa-rennes.fr> \t\t\t" << gettext("hexagonal algorithms") << endl;
  cerr << "Gaetan Le Guelvouit, <gaetan@mail.dotcom.com> \t\t\t" << gettext("design") << endl;
  cerr << "Yacine Zemali, <yzemali@ens.insa-rennes.fr> \t\t\t" << gettext("contribution to the graphical interface") << endl;
  cerr << "Sebastien Crunchant, <scruncha@ens.insa-rennes.fr> \t\t" << gettext("contribution to file handling") << endl;
  cerr << "Xavier Michard, <xmichard@ens.insa-rennes.fr> \t\t\t" << gettext("contribution to file handling") << endl;

  cerr << endl;

  cerr << "This piece of software has been developped as part of our degree of engineer at Insa Rennes, <http://www.insa-rennes.fr>." << endl;

  cerr << endl;

  cerr << "page: http://guillaume.cottenceau.free.fr/html/grany.html" << endl;
  cerr << "online-french-help: http://www.multimania.com/granyrules" << endl << endl;

  exit(0);
  
}

void printVersion()
{
  cerr << getNomProg() << ", " << gettext("version") << " " << VERSION << endl << endl;

  exit(0);
}

void printUsage()
{
  cerr << gettext("Usage") << ": " << getNomProg() << " [--help] [--version] [--authors] [OPTIONS]" << endl;
  cerr << gettext("Launch the graphical interface of Grany-3") << endl;
  cerr << gettext("Options") << ":" << endl;
  cerr << " --expert\t\t\t" << gettext("disable the (few) warning messages") << endl;
  
  cerr << endl;
  
  cerr << " --help\t\t\t\t\t" << gettext("prints a summary of the options") << endl;
  cerr << " --version\t\t\t\t" << gettext("prints the version number") << endl;
  cerr << " --authors\t\t\t\t" << gettext("prints the authors") << endl << endl;
  
  exit(0);

}




int main(int argc, char *argv[])
{
  DEBUG_INTERFACE(cout << "[main] Debut application" << endl;);

  cout << coolHeader() << "Init..." << endl << endl;

#ifdef ENABLE_NLS
  cout << coolHeader() << "Binding the text domain for `" << string(PACKAGE) << "'..." << endl;
  textdomain(PACKAGE);
  setlocale(LC_MESSAGES, "");
  bindtextdomain(PACKAGE, LOCALEDIR);
  cout << coolHeader() << gettext("Now I can talk like this. Your application will be in english.") << endl;
#endif 
#ifndef ENABLE_NLS
  cout << coolHeader() << "Your system does not support localization, so I can only speak english. Install GNU gettext, it's free and cool." << endl;
#endif

  cout << endl;

  vector<string> args(argc);
  
  for (int i = 0; i < argc; i++)
    args[i] = string(argv[i]);
		     
  bool expert = false;

  for (int i = 1; i < argc; i++)
    {
      if (args[i] == "--help")
	printUsage();
      else
	if (args[i] == "--version")
	  printVersion();
	else
	  if (args[i] == "--authors")
	    printAuthors();
	  else
	    if (args[i] == "--expert")
	      {
		cout << coolHeader() << gettext("Expert mode engaged.") << endl;
		expert = true;
	      }
	    else
	      cerr << gettext("[Warning!] Unrecognized option on command-line: ") << args[i] << endl;
    }


  BaseWindow::setWarningMessages(!expert);


  cout << coolHeader() << gettext("Asking gtk to wake up...") << endl;

  Gtk::Main grany_app(argc, argv);


  string user_granyrc = string(g_get_home_dir()) + "/.grany/granyrc";
  // Let's verify we will execute the script by opening a filestream on it.
  std::ifstream filestream(const_cast<char*>(user_granyrc.c_str()));

  if (!filestream)
    {
      cout << coolHeader() << gettext("No ~/.grany/granyrc, so using common `granyrc'.") << endl;
      //      GtkRC(PKGDATADIR "granyrc");
    }
  if (filestream)
    {
      cout << coolHeader() << gettext("Found ~/.grany/granyrc, using it.") << endl;
      //      GtkRC(user_granyrc.c_str());  // I first tried string(user_granyrc), allright except for GCC-2.95. I need `c_str()' to shut up even GCC-2.95
    }

  MainWindow grany_main_window;
  
  grany_main_window.show_all();

  cout << coolHeader() << gettext("Ok. Running now...") << endl;

  Gtk::Main::run(grany_main_window);

  cout << coolHeader() << gettext("Exiting...") << endl;

  grany_main_window.hide();
  //  grany_main_window->hide();
  //  delete grany_main_window;

  DEBUG_INTERFACE(cout << "[main] Fin application" << endl;)

  return 0;
  
}
