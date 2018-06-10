################################################################################
## Variable de fichiers
################################################################################

localedir = $(datadir)/locale

DEFS = -DLOCALEDIR=\"$(localedir)\"  @DEFS@
INCLUDES = -I$(top_srcdir) -I../include -I../../moteur/include  -I../../figures/include -I../../fichiers/include \
	-I../../scene/include -I$(top_srcdir)/common
LDADD = @INTLLIBS@ ../../fichiers/src/libfichier.a  \
	../../scene/src/libscene.a ../../moteur/src/libmoteur.a ../../figures/src/libfigures.a 


bin_PROGRAMS = granyconsole



CONSOLESCR = Console.cpp main.cpp

granyconsole_SOURCES = $(CONSOLESCR)



all-local:
	@echo ""
	@echo "*** granyconsole completed ***"
	@echo ""
