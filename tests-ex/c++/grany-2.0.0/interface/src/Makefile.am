################################################################################
## Variable de fichiers
################################################################################
datadir = $(prefix)/@DATADIRNAME@
localedir = $(datadir)/locale

# maitenant je le mets plus car il est dans le config.h

DEFS = -DPKGDATADIR=\"$(pkgdatadir)/\" -DLOCALEDIR=\"$(localedir)\"  @DEFS@
INCLUDES = -I$(top_srcdir) -I../include -I../../moteur/include -I../../figures/include \
	-I../../fichiers/include -I../../scene/include -I../../common $(GRANY_GTKMM_CFLAGS) 

# LIBS = @INTLLIBS@ ../../fichiers/src/libfichier.a ../../scene/src/libscene.a ../../moteur/src/libmoteur.a ../../figures/src/libfigures.a $(GTKMM_LIBS) @LIBS@
## grany_LDADD = LIBS
LDADD = @INTLLIBS@ ../../fichiers/src/libfichier.a ../../scene/src/libscene.a ../../moteur/src/libmoteur.a ../../figures/src/libfigures.a $(GRANY_GTKMM_LIBS) @LIBS@

bin_PROGRAMS = grany

INTERFACESRC = InterfaceUtils.cpp AllPixmaps.cpp \
	GtkForm.cpp GtkLine.cpp GtkRectangle.cpp GtkPolygon.cpp \
	GtkArcEllipse.cpp GtkEllipse.cpp GranyDrawingArea.cpp \
	SpecialLine.cpp AboutWindow.cpp WarningWindow.cpp ErrorWindow.cpp NewbieWindow.cpp \
	ParamRecordDialog.cpp NewSimulationDialog.cpp ParamPhaseDialog.cpp \
	BasicWindow.cpp BaseWindow.cpp UpdatableParameters.cpp  \
	Arrow.cpp RulesEditor.cpp BordersEditor.cpp AreaEditor.cpp ZoningEditor.cpp \
	ColorationEditor.cpp SceneEditor.cpp MainWindow.cpp main.cpp

grany_SOURCES = $(INTERFACESRC)

pkgdata_DATA = granyrc
pkgdata_SCRIPTS = user_install

# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# les variables suivantes sont definies dans le configure.in
EXTRA_DIST = files/borders/sand-glass.frontiere files/rules/neutral.regle files/scenes/silo.scene \
	files/simulations/sand-water.simul user_install $(INTERFACEFILES)

# on peut faire aussi un truc du genre, mais je varie un peu les plaisirs
#     htmldir = $(prefix)/html
#     html_DATA = automake.html 

install-data-local:
	@echo "*** now installing example files..."
	$(mkinstalldirs) $(pkgdatadir)/files/borders
	@echo installing the borders...
	@for file in files/borders/*; do\
	  $(INSTALL_DATA) $$file $(pkgdatadir)/$$file; \
	done
	$(mkinstalldirs) $(pkgdatadir)/files/rules
	@echo installing the rules...
	@for file in files/rules/*; do\
	  $(INSTALL_DATA) $$file $(pkgdatadir)/$$file; \
	done
	$(mkinstalldirs) $(pkgdatadir)/files/scenes
	@echo installing the scenes...
	@for file in files/scenes/*; do\
	  $(INSTALL_DATA) $$file $(pkgdatadir)/$$file; \
	done
	$(mkinstalldirs) $(pkgdatadir)/files/simulations
	@echo installing the simulations...
	@for file in files/simulations/*; do\
	  $(INSTALL_DATA) $$file $(pkgdatadir)/$$file; \
	done

uninstall-local:
	 @echo erasing grany files
	 rm -rf $(pkgdatadir)


# EXTRA_DIST = pixmaps/help.xpm $(PIXMAPS_FILES)

#install-data-local:
## 	$(mkinstalldirs) $(pkgdatadir)/pixmaps
## 	@echo installing the pixmaps
## 	@for file in pixmaps/*.xpm; do\
## 	  $(INSTALL_DATA) $$file $(pkgdatadir)/$$file; \
## 	done
#	 @echo installing granyrc
#	 $(INSTALL_DATA) granyrc $(pkgdatadir)
#uninstall-local:
#	 @echo erasing the pixmaps and granyrc
#	 rm -rf $(pkgdatadir)




all-local:
	@echo ""
	@echo "*** grany completed ***"
	@echo ""
