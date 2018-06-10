AUTOMAKE_OPTIONS=dejagnu


if GRANY_X11TEST
TESTBIN = testPlanHexX11
FLAGSSUP = $(X_CFLAGS)
LIBSUP = $(X_LIBS)  -lX11
# $(X_EXTRA_LIBS) $(X_PRE_LIBS)
else
TESTBIN = 
endif


noinst_PROGRAMS = $(TESTBIN)

testPlanHexX11_SOURCES = testPlanHexX11.cpp
#testRegleCompiler_SOURCES = testRegleCompiler.cpp
#testFrontiereCompiler_SOURCES = testFrontiereCompiler.cpp
#testSceneCompiler_SOURCES = testSceneCompiler.cpp
#testSimulCompiler_SOURCES = testSimulCompiler.cpp
#testEntreeSortie_SOURCES = testEntreeSortie.cpp

LIBS = $(LIBSUP)


INCLUDES = -I../include -I../../moteur/include  -I../../figures/include -I../../scene/include \
	-I../../fichiers/include   -I$(top_srcdir)/common $(FLAGSSUP)
LDADD =  ../../fichiers/src/libfichier.a  \
	../../scene/src/libscene.a ../../moteur/src/libmoteur.a ../../figures/src/libfigures.a 

RUNTESTFLAGS = --all



# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# les variables suivantes sont definies dans le configure.in
EXTRA_DIST = testCommun.h config/unix.exp  test.console/Console.exp  output.ok/Console-test-1 files/test1.simul \
	  $(CONSOLE_TEST_OUTPUTOK) $(CONSOLE_TEST_EXPECT) $(CONSOLE_TEST_FILES)

clean-local:
	  rm -f *.log *.sum site.exp site.bak





