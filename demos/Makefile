##############################################################################
# Variables
##############################################################################
SYSLIBS=str.cma bigarray.cma unix.cma

LIBS= ../commons/commons.cma ../pl_info/code_info.cma \
      ../parsing_c/parsing_c.cma ../parsing_cplusplus/parsing_cplusplus.cma \

#      ../analyze_c/analyze_c.cma

INCLUDEDIRS=../commons ../pl_info ../parsing_c ../parsing_cplusplus \

# ../analyze_c

##############################################################################
# Generic variables
##############################################################################

INCLUDES=$(INCLUDEDIRS:%=-I %)

OBJS=    $(SRC:.ml=.cmo)
OPTOBJS= $(SRC:.ml=.cmx)

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

##############################################################################
# Top rules
##############################################################################

PROGS=simple_zero_to_null.byte
#c_transducer.byte 

all: $(PROGS)
opt: $(PROGS:.byte=.opt)
all.opt: opt


.SUFFIXES: .byte .opt

%.byte: %.cmo 
	$(OCAMLC) -o $@ $(SYSLIBS) $(LIBS)  $^

%.opt: %.cmx
	$(OCAMLOPT) -o $@ $(SYSLIBS:.cma=.cmxa) $(LIBS:.cma=.cmxa)  $^


clean::
	rm -f *.opt *.byte

##############################################################################
# Developer rules
##############################################################################

tags:
	otags -no-mli-tags -r  .

clean::
	rm -f TAGS

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

distclean::
	rm -f .depend

beforedepend::

depend:: beforedepend
	$(OCAMLDEP) *.mli *.ml > .depend

-include .depend
