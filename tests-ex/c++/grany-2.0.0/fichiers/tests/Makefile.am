AUTOMAKE_OPTIONS=dejagnu


if GRANY_X11TEST
TESTBIN2 = testIntegrationPlanHex
FLAGSSUP = $(X_CFLAGS)
LIBSUP = $(X_LIBS)  -lX11
# $(X_EXTRA_LIBS) $(X_PRE_LIBS)
else
TESTBIN2 = 
endif


TESTBIN = testRegleCompiler testFrontiereCompiler testSceneCompiler testSimulCompiler \
	testEntreeSortie $(TESTBIN2) 

noinst_PROGRAMS = $(TESTBIN)

testRegleCompiler_SOURCES = testRegleCompiler.cpp
testFrontiereCompiler_SOURCES = testFrontiereCompiler.cpp
testSceneCompiler_SOURCES = testSceneCompiler.cpp
testSimulCompiler_SOURCES = testSimulCompiler.cpp
testEntreeSortie_SOURCES = testEntreeSortie.cpp
testIntegrationPlanHex_SOURCES = testIntegrationPlanHex.cpp


LIBS = $(LIBSUP)

INCLUDES = -I../include -I../../moteur/include  -I../../figures/include \
	-I../../scene/include -I$(top_srcdir)/common $(FLAGSSUP)
LDADD = ../src/libfichier.a  \
	../../scene/src/libscene.a ../../moteur/src/libmoteur.a ../../figures/src/libfigures.a 

RUNTESTFLAGS = --all



# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# les variables suivantes sont definies dans le configure.in
EXTRA_DIST = testCommun.h config/unix.exp  test.fichiers/RegleCompiler.exp  output.ok/RegleCompiler-test-1 files/test1.regle \
	  $(FICHIER_TEST_OUTPUTOK) $(FICHIER_TEST_EXPECT) $(FICHIER_TEST_FILES)

clean-local:
	  rm -f *.log *.sum site.exp site.bak





