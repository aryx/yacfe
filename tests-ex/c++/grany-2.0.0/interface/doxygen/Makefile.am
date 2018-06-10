EXTRA_DIST = Doxyfile

vpath %.cpp ../src
vpath %.h ../include
all-local: docsauto

docsauto:  html/index.html

if GRANY_GENDOCS_PS
html/index.html: $(INTERFACE_CPP) $(INTERFACE_H) Doxyfile
	@echo "*** Generating Documentation ***" ; \
	rm -rf html latex man ; \
	@DOXYGEN@ Doxyfile && cd latex && make ; \
	echo "*** Documentation generated ***"  ;
else
html/index.html: $(INTERFACE_CPP) $(INTERFACE_H) Doxyfile
	@echo "*** Generating Documentation ***" ; \
	rm -rf html latex man ; \
	@DOXYGEN@ Doxyfile ; \
	rm -rf latex ; \
	echo "*** Documentation generated ***"  ;
endif

clean-local:
	rm -rf html latex man
