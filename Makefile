#############################################################################
# Configuration section
#############################################################################

-include Makefile.config

VERSION=$(shell cat globals/config.ml |grep version |perl -p -e 's/.*"(.*)".*/$$1/;')

##############################################################################
# Variables
##############################################################################
TARGET=yacfe

SRC=test.ml features.ml software_src.ml cc09.ml main.ml 


ifeq ($(FEATURE_MPI),1)
MPICMA=ocamlmpi/mpi.cma commons/commons_mpi.cma
MPIDIR=ocamlmpi
MPICMD=    $(MAKE) all -C ocamlmpi; $(MAKE) distribution -C commons
MPICMDOPT= $(MAKE) all.opt -C ocamlmpi; $(MAKE) distribution.opt -C commons
#MPILIB=dllpycaml_stubs.so
# the following is essential for yacfe to compile under gentoo (wierd) ???
#OPTLIBFLAGS=-cclib dllpycaml_stubs.so
else
MPICMD=echo "no mpi"
MPICMDOPT=echo "no mpi"
endif

ifeq ($(FEATURE_GUI),1)
GUIDIR=gui
GUICMD= $(MAKE) backtrace -C commons; \
        $(MAKE) gui       -C commons; \
GUICMDOPT= $(MAKE) backtrace.opt -C commons; \
           $(MAKE) gui.opt       -C commons;
GUIEXEC=yacfe_browser
GUIEXECOPT=yacfe_browser.opt
GUIINCLUDE= +lablgtk2 +lablgtksourceview
else
GUICMD=echo "no gui"
GUICMDOPT=echo "no gui"
endif

#ifeq ($(FEATURES_GDBM), 1)
GDBMCMD= $(MAKE) gdbm -C commons
GDBMCMDOPT= $(MAKE) gdbm.opt -C commons
GDBMCMA=commons/commons_gdbm.cma
GDBMSYSCMA=dbm.cma
#else
#endif


SYSLIBS=str.cma unix.cma $(GDBMSYSCMA)
LIBS= commons/commons.cma \
      globals/globals.cma \
      $(MPICMA) \
      $(GDBMCMA) \
      code_info/code_info.cma \
      parsing_c/parsing_c.cma \
      parsing_c++/parsing_cplusplus.cma \
      parsing_java/parsing_java.cma \
      matcher_c/matcher.cma \
      analyze_c/analyze_c.cma \
      code_wrapper/code_wrapper.cma

MAKESUBDIRS=commons globals $(MPIDIR) code_info \
  parsing_c parsing_c++ parsing_java matcher_c analyze_c code_wrapper \
  $(GUIDIR) demos
INCLUDEDIRS=commons globals $(MPIDIR) code_info \
  parsing_c parsing_c++ parsing_java matcher_c analyze_c code_wrapper \
  $(GUIDIR) $(GUIINCLUDE)


##############################################################################
# Generic variables
##############################################################################

INCLUDES=$(INCLUDEDIRS:%=-I %)

OBJS=    $(SRC:.ml=.cmo)
OPTOBJS= $(SRC:.ml=.cmx)

EXEC=$(TARGET)

##############################################################################
# Generic ocaml variables
##############################################################################

#dont use -custom, it makes the bytecode unportable.
OCAMLCFLAGS=-g -dtypes # -w A

# This flag is also used in subdirectories so don't change its name here.
OPTFLAGS=


OCAMLC=ocamlc$(OPTBIN) $(OCAMLCFLAGS)  $(INCLUDES) -thread
OCAMLOPT=ocamlopt$(OPTBIN) $(OPTFLAGS) $(INCLUDES) -thread
OCAMLLEX=ocamllex #-ml # -ml for debugging lexer, but slightly slower
OCAMLYACC=ocamlyacc -v
OCAMLDEP=ocamldep $(INCLUDES)
OCAMLMKTOP=ocamlmktop -g -custom $(INCLUDES) -thread

# can also be set via 'make static'
STATIC= #-ccopt -static

# can also be unset via 'make purebytecode'
BYTECODE_STATIC=-custom


##############################################################################
# Top rules
##############################################################################

all: rec $(EXEC) $(GUIEXEC)
opt: rec.opt $(EXEC).opt $(GUIEXECOPT)
all.opt: opt
top: $(EXEC).top

rec:
	$(MAKE) -C commons 
	$(MPICMD)
	$(GDBMCMD)
	$(GUICMD)
	set -e; for i in $(MAKESUBDIRS); do $(MAKE) -C $$i all; done 
rec.opt:
	$(MAKE) all.opt -C commons 
	$(MPICMDOPT)
	$(GDBMCMDOPT)
	set -e; for i in $(MAKESUBDIRS); do $(MAKE) -C $$i all.opt; done 
	$(GUICMDOPT)

$(EXEC): $(LIBS) $(OBJS)
	$(OCAMLC) $(BYTECODE_STATIC) -o $@ $(SYSLIBS) $^

$(EXEC).opt: $(LIBS:.cma=.cmxa) $(OPTOBJS) 
	$(OCAMLOPT) $(STATIC) -o $@ $(SYSLIBS:.cma=.cmxa) $^


$(EXEC).top: $(LIBS) $(OBJS) 
	$(OCAMLMKTOP) -o $@ $(SYSLIBS) $^

clean::
	rm -f $(EXEC) $(EXEC).opt $(EXEC).top

clean::
	set -e; for i in $(MAKESUBDIRS); do $(MAKE) -C $$i clean; done 

depend::
	set -e; for i in $(MAKESUBDIRS); do $(MAKE) -C $$i depend; done



static:
	rm -f spatch.opt spatch
	$(MAKE) STATIC="-ccopt -static" spatch.opt
	cp spatch.opt spatch

purebytecode:
	rm -f spatch.opt spatch
	$(MAKE) BYTECODE_STATIC="" spatch




features.ml: features.ml.cpp Makefile.config
	cpp -DFEATURE_MPI=$(FEATURE_MPI) \
	    -DFEATURE_GUI=$(FEATURE_GUI) \
	   features.ml.cpp > features.ml

clean::
	rm -f features.ml

beforedepend:: features.ml




SYSLIBS2=lablgtk.cma lablgtksourceview.cma
LIBS2=commons/commons_gui.cma gui/gui.cma
OBJS2=

yacfe_browser: $(LIBS) $(LIBS2) $(OBJS2) main_gui.cmo 
	$(OCAMLC) -o $@ $(SYSLIBS) $(SYSLIBS2)  $^ 

yacfe_browser.opt: $(LIBS:.cma=.cmxa) $(LIBS2:.cma=.cmxa) $(OBJS2:.cmo=.cmx) main_gui.cmx
	$(OCAMLOPT) $(STATIC) -o $@ $(SYSLIBS:.cma=.cmxa) $(SYSLIBS2:.cma=.cmxa)  $^ 

clean::
	rm -f yacfe_browser yacfe_browser.opt

clean::
	set -e; for i in gui; do $(MAKE) -C $$i clean; done 

##############################################################################
# Install
##############################################################################

# don't remove DESTDIR, it can be set by package build system like ebuild
install: all
	mkdir -p $(DESTDIR)$(SHAREDIR)
	cp data/*.h $(DESTDIR)$(SHAREDIR)
	@echo ""
	@echo "You can also install yacfe by copying the program yacfe"
	@echo "(available in this directory) anywhere you want and"
	@echo "give it the right options to find its configuration files."

uninstall:
	rm -f $(DESTDIR)$(SHAREDIR)/*.h

version:
	@echo $(VERSION)


##############################################################################
# Package rules
##############################################################################

PACKAGE=yacfe-$(VERSION)

BINSRC=yacfe env.sh env.csh data/*.h \
       *.txt docs/* \
       demos/foo.* demos/*.ml
BINSRC2=$(BINSRC:%=$(PACKAGE)/%)

TMP=/tmp
OCAMLVERSION=$(shell ocaml -version |perl -p -e 's/.*version (.*)/$$1/;')

# Procedure to do first time:
#  cd ~/release
#  darcs get ~/c-yacfe yacfe
#  cd yacfe
#  make get_darcs
#  remember to comment the -g -dtypes in this Makefile

# Procedure to do each time:
#  make update_darcs
#  ./configure --without-gui --without-mpi
#  make package
#  make website

# To test you can try compile and run yacfe from different instances 
# like my ~/c-yacfe, ~/release/yacfe, and the /tmp/yacfe-0.X 
# downloaded from the website. 

# For 'make srctar' it must done from a clean
# repo such as ~/release/yacfe. 
# For the 'make bintar' I can do it from my original repo.


package: 
	make srctar 
#	make bintar 
#	make staticbintar 
#	make bytecodetar

srctar:
	make clean
	cp -a .  $(TMP)/$(PACKAGE)
	cd $(TMP); tar cvfz $(PACKAGE).tgz  --exclude=CVS --exclude=_darcs  $(PACKAGE)
	rm -rf  $(TMP)/$(PACKAGE)


bintar: all
	rm -f $(TMP)/$(PACKAGE)
	ln -s `pwd` $(TMP)/$(PACKAGE)
	cd $(TMP); tar cvfz $(PACKAGE)-bin-x86.tgz $(BINSRC2)
	rm -f $(TMP)/$(PACKAGE)

staticbintar: all.opt
	rm -f $(TMP)/$(PACKAGE)
	ln -s `pwd` $(TMP)/$(PACKAGE)
	make static
	cd $(TMP); tar cvfz $(PACKAGE)-bin-x86-static.tgz $(BINSRC2)
	rm -f $(TMP)/$(PACKAGE)

# add ocaml version in name ?
bytecodetar: all
	rm -f $(TMP)/$(PACKAGE)
	ln -s `pwd` $(TMP)/$(PACKAGE)
	make purebytecode
	cd $(TMP); tar cvfz $(PACKAGE)-bin-bytecode-$(OCAMLVERSION).tgz $(BINSRC2)
	rm -f $(TMP)/$(PACKAGE)

clean::
	rm -f $(PACKAGE) 
	rm -f $(PACKAGE)-bin-x86.tgz 
	rm -f $(PACKAGE)-bin-x86-static.tgz 
	rm -f $(PACKAGE)-bin-bytecode-$(OCAMLVERSION).tgz

ocamlversion:
	@echo $(OCAMLVERSION)

##############################################################################
# Pad specific rules
##############################################################################

DARCSFORESTS=commons \
 parsing_c parsing_c++ parsing_java \
 matcher_c analyze_c \
 code_info code_wrapper \
 data

update_darcs:
	darcs pull
	set -e; for i in $(DARCSFORESTS); do cd $$i; darcs pull; cd ..; done 

diff_darcs:
	darcs diff -u
	set -e; for i in $(DARCSFORESTS); do cd $$i; darcs diff -u; cd ..; done 



# first time
get_darcs:
	set -e; for i in $(DARCSFORESTS); do darcs get ~/c-yacfe/$$i; done 


WEBSITE=/home/pad/mobile/homepage/software/project-yacfe

website:
	cp $(TMP)/$(PACKAGE).tgz                $(WEBSITE)

#TXT=$(wildcard *.txt)
syncwiki:
#	unison ~/public_html/wiki/wiki-LFS/data/pages/ docs/wiki/
#	set -e; for i in $(TXT); do unison $$i docs/wiki/$$i; done 

darcsweb:
#	@echo pull from ~/public_html/darcs/c-coccinelle and c-commons and lib-xxx


##############################################################################
# Developer rules
##############################################################################

tags:
	otags -no-mli-tags -r  .

clean::
	rm -f TAGS


##############################################################################
# Pad's rules bis
##############################################################################

test:
# -parse_c big-files/
# -parse_c pb_parsing/ 
# -parse_c pb_parsing_ecoop/

PARSECMD=./spatch.opt -D standard.h -filter_define_error -filter_classic_passed \
	  -dir

testparsing2: 
	$(PARSECMD) -parse_c ~/kernels/git/linux-2.6/sound/ > /tmp/parse_sound_filter 2>&1 
	$(PARSECMD) -parse_c ~/kernels/git/linux-2.6/drivers/  > /tmp/parse_drivers_filter 2>&1 
	$(PARSECMD) -parse_c ~/kernels/git/linux-2.6/  > /tmp/parse_c_filter 2>&1 
	$(PARSECMD) -parse_h ~/kernels/git/linux-2.6/  > /tmp/parse_h_filter 2>&1 
	$(PARSECMD) -parse_ch ~/kernels/git/linux-2.6/ > /tmp/parse_ch_filter 2>&1

testparsing3:
	./spatch.opt -D standard.h -parse_ch -dir ~/kernels/git/linux-2.6/ > /tmp/parse_ch_all 2>&1

testparsing4:
	./spatch.opt -D standard.h -parse_c -dir tests-big/ > /tmp/parse_big_c 2>&1


#	./$(TARGET) -D standard.h -parse_c -dir parsing_c/tests



cp_4mpi:
	echo no copy needed yet

test_mpi: opt yacfe.opt cp_4mpi 
	time mpirun -p4pg env-machines-onlyme.pg ./yacfe.opt -parse_all /home/pad/software-src/devel/sparse-git

##############################################################################
# Generic ocaml rules
##############################################################################

.SUFFIXES: .ml .mli .cmo .cmi .cmx

.ml.cmo:
	$(OCAMLC)  -c $<
.mli.cmi:
	$(OCAMLC)  -c $<
.ml.cmx:
	$(OCAMLOPT)  -c $<

.ml.mldepend: 
	$(OCAMLC) -i $<

clean::
	rm -f *.cm[iox] *.o *.annot
clean::
	rm -f *~ .*~ *.exe #*#

beforedepend::

depend:: beforedepend
	$(OCAMLDEP) *.mli *.ml > .depend

-include .depend
