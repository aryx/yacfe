AUTOMAKE_OPTIONS=dejagnu


TESTBIN = 

noinst_PROGRAMS = $(TESTBIN)

#testDirection_SOURCES = testDirection.cpp
#testRequete_SOURCES = testRequete.cpp
#testPonderation_SOURCES = testPonderation.cpp
#testRegleExclusion_SOURCES = testRegleExclusion.cpp
#testPhase_SOURCES = testPhase.cpp
#testParticule_SOURCES = testParticule.cpp
#testAutomate_SOURCES = testAutomate.cpp
#testAutomate2_SOURCES = testAutomate2.cpp


INCLUDES = -I../include -I$(top_srcdir)/common
LDADD = ../src/libfigures.a

RUNTESTFLAGS = --all



# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# les variables suivantes sont definies dans le configure.in
EXTRA_DIST = testCommun.h config/unix.exp  test.figures/Ligne.exp  output.ok/Ligne-test-1 \
	$(FIGURES_TEST_OUTPUTOK) $(FIGURES_TEST_EXPECT)

clean-local:
	rm -f *.log *.sum site.exp site.bak






