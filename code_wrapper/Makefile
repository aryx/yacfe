##############################################################################
# Variables
##############################################################################
TARGET=code_wrapper

SRC= language_helper.ml


LIBS=../commons/commons.cma \
     ../code_info/code_info.cma \
     ../parsing_c/parsing_c.cma \
     ../parsing_c++/parsing_cplusplus.cma \
     ../parsing_java/parsing_java.cma

INCLUDEDIRS=../commons ../code_info \
 ../parsing_c ../parsing_c++ ../parsing_java

##############################################################################
# Generic variables
##############################################################################

INCLUDES=$(INCLUDEDIRS:%=-I %)


OCAMLCFLAGS=-g -dtypes
OCAMLLEXFLAGS= #-ml

OCAMLC=ocamlc$(OPTBIN) $(OCAMLCFLAGS)   $(INCLUDES) 
OCAMLOPT=ocamlopt$(OPTBIN)   $(INCLUDES) $(OPTFLAGS)
OCAMLLEX=ocamllex$(OPTBIN) $(OCAMLLEXFLAGS)
OCAMLYACC=ocamlyacc -v
OCAMLDEP=ocamldep$(OPTBIN)  $(INCLUDES)
OCAMLMKTOP=ocamlmktop -g -custom $(INCLUDES)

OBJS= $(SRC:.ml=.cmo)
OPTOBJS= $(SRC:.ml=.cmx)


##############################################################################
# Top rules
##############################################################################
all: $(TARGET).cma
all.opt: $(TARGET).cmxa
opt: all.opt


$(TARGET).cma: $(OBJS) $(LIBS)
	$(OCAMLC) -a -o $@ $(OBJS)

$(TARGET).cmxa: $(OPTOBJS) $(LIBS:.cma=.cmxa)
	$(OCAMLOPT) -a -o $@ $(OPTOBJS)


##############################################################################
# Generic rules
##############################################################################
.SUFFIXES: .ml .mli .cmo .cmi .cmx

.ml.cmo:
	$(OCAMLC) -c $<
.mli.cmi:
	$(OCAMLC) -c $<
.ml.cmx:
	$(OCAMLOPT) -c $<

.ml.mldepend: 
	$(OCAMLC) -i $<

clean::
	rm -f *.cm[ioxa] *.o *.a *.cmxa *.annot

clean::
	rm -f *~ .*~ gmon.out #*#

beforedepend::

depend:: beforedepend
	$(OCAMLDEP) *.mli *.ml    > .depend

-include .depend
