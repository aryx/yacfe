EXTRA_DIST = Doxyfile

all-local: docsauto

docsauto:  html/index.html

if GRANY_GENDOCS_PS
html/index.html: Doxyfile
	@echo "*** Generating developper Documentation for the whole code of Grany ***" ; \
	rm -rf html latex man ; \
	@DOXYGEN@ Doxyfile && cd latex && make ; \
	echo "*** Documentation generated ***"  ;
else
html/index.html: Doxyfile
	echo "*** Generating developper Documentation for the whole code of Grany ***" ; \
	rm -rf html latex man ; \
	@DOXYGEN@ Doxyfile ; \
	rm -rf latex ; \
	echo "*** Documentation generated ***"  ;
endif

clean-local:
	rm -rf html latex man
