#############################################################################
# Configuration section
#############################################################################

-include Makefile.config

VERSION=$(shell cat globals/config.ml |grep version |perl -p -e 's/.*"(.*)".*/$$1/;')

##############################################################################
# Variables
##############################################################################
TOP=$(shell pwd)

SRC=test.ml main.ml 

TARGET=yacfe
PROGS=yacfe

OPTPROGS= $(PROGS:=.opt)

#------------------------------------------------------------------------------
SYSLIBS=str.cma bigarray.cma unix.cma
LIBS= commons/commons.cma \
      commons/commons_features.cma \
      globals/globals.cma \
      pl_info/code_info.cma \
      parsing_c/parsing_c.cma \
      pl_wrapper/code_wrapper.cma \
      src_repository/src_repository.cma

MAKESUBDIRS=commons \
  globals \
  pl_info \
  parsing_c \
  pl_wrapper \
  src_repository \
  demos 

INCLUDEDIRS=commons \
  globals \
  pl_info \
  parsing_c \
  pl_wrapper \
  src_repository


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

all: 
	$(MAKE) rec 
	$(MAKE) $(PROGS) 
opt: 
	$(MAKE) rec.opt 
	$(MAKE) $(OPTPROGS) 
all.opt: opt
top: $(EXEC).top

#note: old: was before all: rec $(EXEC) ... but can not do that cos make -j20
#could try to compile $(EXEC) before rec. So here force sequentiality.
rec:
	$(MAKE) -C commons 
	$(MAKE) features -C commons 
	set -e; for i in $(MAKESUBDIRS); do $(MAKE) -C $$i all || exit 1; done 
rec.opt:
	$(MAKE) all.opt -C commons 
	$(MAKE) features.opt -C commons 
	set -e; for i in $(MAKESUBDIRS); do $(MAKE) -C $$i all.opt || exit 1; done 

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
	rm -f $(EXEC).opt $(EXEC)
	$(MAKE) STATIC="-ccopt -static" $(EXEC).opt
	cp $(EXEC).opt $(EXEC)

purebytecode:
	rm -f $(EXEC).opt $(EXEC)
	$(MAKE) BYTECODE_STATIC="" $(EXEC)






##############################################################################
# Install
##############################################################################

# note: don't remove DESTDIR, it can be set by package build system like ebuild
install: all
	mkdir -p $(DESTDIR)$(SHAREDIR)
	cp -a config/ $(DESTDIR)$(SHAREDIR)
	@echo ""
	@echo "You can also install yacfe by copying the program yacfe"
	@echo "(available in this directory) anywhere you want and"
	@echo "give it the right options to find its configuration files."

uninstall:
	rm -rf $(DESTDIR)$(SHAREDIR)/config/

version:
	@echo $(VERSION)


##############################################################################
# Package rules
##############################################################################

PACKAGE=yacfe-light-$(VERSION)

BINSRC=yacfe env.sh env.csh \
       config/macros/*.h config/isos/*.iso config/envos/*.h \
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




distclean:: clean
	set -e; for i in $(MAKESUBDIRS); do $(MAKE) -C $$i $@; done
	rm -f .depend
	rm -f Makefile.config
	rm -f TAGS

#	find -name ".#*1.*" | xargs rm -f

##############################################################################
# Pad specific rules
##############################################################################


WEBSITE=/home/pad/mobile/homepage/software/project-yacfe

website:
	cp $(TMP)/$(PACKAGE).tgz                $(WEBSITE)

#TXT=$(wildcard *.txt)
syncwiki:
#	unison ~/public_html/wiki/wiki-LFS/data/pages/ docs/wiki/
#	set -e; for i in $(TXT); do unison $$i docs/wiki/$$i; done 


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
