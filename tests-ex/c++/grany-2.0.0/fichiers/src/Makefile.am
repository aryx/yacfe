################################################################################
## Variable de fichiers
################################################################################


INCLUDES = -I../include -I../../moteur/include -I../../figures/include \
	-I../../scene/include -I$(top_srcdir)/common
LIBS = @INTLLIBS@ ../../moteur/src/libmoteur.a @LIBS@

noinst_LIBRARIES = libfichier.a


FICHIERSRC = RegleParser.cpp RegleScanner.cpp RegleCompiler.cpp \
	FrontiereParser.cpp FrontiereScanner.cpp FrontiereCompiler.cpp \
	SceneParser.cpp SceneScanner.cpp SceneCompiler.cpp \
	SimulParser.cpp SimulScanner.cpp SimulCompiler.cpp EntreeSortie.cpp

libfichier_a_SOURCES = $(FICHIERSRC)

# arrive pas a faire des .y.cpp pour factoriser
RegleParser.cpp: RegleParser.y
	$(BISON) -d  -o $*.cpp -h../include/$*.h  $*.y
RegleScanner.cpp: RegleScanner.l
	$(FLEX)  -8  -h../include/$*.h -o$*.cpp $*.l

FrontiereParser.cpp: FrontiereParser.y
	$(BISON) -d  -o $*.cpp -h../include/$*.h  $*.y
FrontiereScanner.cpp: FrontiereScanner.l
	$(FLEX)  -8  -h../include/$*.h -o$*.cpp $*.l

SceneParser.cpp: SceneParser.y
	$(BISON) -d  -o $*.cpp -h../include/$*.h  $*.y
SceneScanner.cpp: SceneScanner.l
	$(FLEX)  -8  -h../include/$*.h -o$*.cpp $*.l

SimulParser.cpp: SimulParser.y
	$(BISON) -d  -o $*.cpp -h../include/$*.h  $*.y
SimulScanner.cpp: SimulScanner.l
	$(FLEX)  -8  -h../include/$*.h -o$*.cpp $*.l

EXTRA_DIST = RegleParser.y RegleScanner.l \
	     FrontiereScanner.l FrontiereParser.y \
	     SceneScanner.l SceneParser.y \
	     SimulScanner.l SimulParser.y 

clean-bison:
	rm -f RegleScanner.cpp ../include/RegleScanner.h RegleParser.cpp ../include/RegleParser.h
	rm -f FrontiereScanner.cpp ../include/FrontiereScanner.h FrontiereParser.cpp ../include/FrontiereParser.h
	rm -f SceneScanner.cpp ../include/SceneScanner.h SceneParser.cpp ../include/SceneParser.h
	rm -f SimulScanner.cpp ../include/SimulScanner.h SimulParser.cpp ../include/SimulParser.h

