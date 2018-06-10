if GRANY_GENDOCS
GRANY_SUBDIRS = doxygen
else
GRANY_SUBDIRS =
endif


# il faut au moins un fichier dedans pour qu'il sache qu'il faut creer le repertoire include
# les variables suivantes sont definies dans le configure.in
EXTRA_DIST = include/MainWindow.h $(INTERFACE_H_INCLUDE)
SUBDIRS = src tests $(GRANY_SUBDIRS)

