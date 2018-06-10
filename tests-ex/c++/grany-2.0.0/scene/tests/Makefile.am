AUTOMAKE_OPTIONS=dejagnu


if GRANY_X11TEST
TESTBIN = testPlanHexagonal
FLAGSSUP = $(X_CFLAGS)
LIBSUP = $(X_LIBS)  -lX11
# $(X_EXTRA_LIBS) $(X_PRE_LIBS)
else
TESTBIN = 
endif




noinst_PROGRAMS = $(TESTBIN)

testPlanHexagonal_SOURCES = testPlanHexagonal.cpp
#testRequete_SOURCES = testRequete.cpp
#testPonderation_SOURCES = testPonderation.cpp
#testRegleExclusion_SOURCES = testRegleExclusion.cpp
#testPhase_SOURCES = testPhase.cpp
#testParticule_SOURCES = testParticule.cpp
#testAutomate_SOURCES = testAutomate.cpp
#testAutomate2_SOURCES = testAutomate2.cpp

LIBS = $(LIBSUP)
INCLUDES = -I../include -I$(top_srcdir)/common -I../../moteur/include \
	-I../../figures/include $(FLAGSSUP)
LDADD = ../src/libscene.a ../../figures/src/libfigures.a ../../moteur/src/libmoteur.a 

RUNTESTFLAGS = --all



# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# les variables suivantes sont definies dans le configure.in
EXTRA_DIST = testCommun.h config/unix.exp  test.scene/Scene.exp  output.ok/Scene-test-1 \
	$(SCENE_TEST_OUTPUTOK) $(SCENE_TEST_EXPECT)

clean-local:
	rm -f *.log *.sum site.exp site.bak






