AUTOMAKE_OPTIONS=dejagnu


TESTBIN = testDirection testRequete testPonderation \
	testRegleExclusion testPhase testParticule \
	testAutomate testAutomate2 testAutomate3

noinst_PROGRAMS = $(TESTBIN)

testDirection_SOURCES = testDirection.cpp
testRequete_SOURCES = testRequete.cpp
testPonderation_SOURCES = testPonderation.cpp
testRegleExclusion_SOURCES = testRegleExclusion.cpp
testPhase_SOURCES = testPhase.cpp
testParticule_SOURCES = testParticule.cpp
testAutomate_SOURCES = testAutomate.cpp
testAutomate2_SOURCES = testAutomate2.cpp
testAutomate3_SOURCES = testAutomate3.cpp


INCLUDES = -I../include -I$(top_srcdir)/common
LDADD = ../src/libmoteur.a

RUNTESTFLAGS = --all



# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# les variables suivantes sont definies dans le configure.in
EXTRA_DIST = testCommun.h config/unix.exp  test.moteur/Direction.exp  output.ok/Direction-test-1 \
	$(MOTEUR_TEST_OUTPUTOK) $(MOTEUR_TEST_EXPECT)

clean-local:
	rm -f *.log *.sum site.exp site.bak






