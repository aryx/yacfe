## Process this file with automake to produce Makefile.in
if GRANY_GENDOCS
GRANY_SUBDIRS = docs
else
GRANY_SUBDIRS =
endif

if GRANY_INTERFACE
GRANY_SUBDIRS_INTERFACE = interface 
else
GRANY_SUBDIRS_INTERFACE =
endif


SUBDIRS = moteur figures scene fichiers intl console $(GRANY_SUBDIRS) $(GRANY_SUBDIRS_INTERFACE) po 

EXTRA_DIST = README.i18n README.dptinfo FAQ BUGS LISEZMOI VERSION \
	config.sub config.guess m4/lcmessage.m4 m4/progtest.m4 \
	common/ioManager.h common/Matrice.h \
	scripts/rotationPonderation scripts/turning_scene scripts/simple-pondforte-prop.simul scripts/README \
	icons/grany-icon-16x16.xpm icons/grany-icon-32x32.xpm icons/grany-icon-48x48.xpm



all-local:
	@echo ""
	@echo "*** everything completed ***"
	@echo ""

install-data-local:
	@echo ""
	@echo "*** everything installed in $(prefix). Enjoy! ***"
	@echo ""
