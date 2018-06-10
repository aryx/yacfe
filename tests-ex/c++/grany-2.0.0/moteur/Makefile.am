if GRANY_GENDOCS
GRANY_SUBDIRS = doxygen
else
GRANY_SUBDIRS =
endif

if GRANY_TESTSUITE
GRANY_SUBDIR2 = tests
else
GRANY_SUBDIR2 = 
endif

# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# MOTEUR_H_INCLUDE est definie dans le configure.in
EXTRA_DIST = include/CommunMoteur.h $(MOTEUR_H_INCLUDE)




SUBDIRS = src $(GRANY_SUBDIRS) $(GRANY_SUBDIR2)

