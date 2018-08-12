##############################################################################
# Variables
##############################################################################
TARGET=code_info

# ast_cocci.ml and unparse_cocci2.ml should be deleted in the futur
# to make parsing_c really independent of coccinelle.
# control_flow_c have also coccinelle dependencies.
SRC= programming_language.ml ast_generic.ml place_code.ml parse_info.ml \
     statistics_code.ml statistics_parsing.ml

SYSLIBS= str.cma unix.cma
LIBS=../commons/commons.cma
INCLUDES= -I ../commons

##############################################################################
# Generic variables
##############################################################################

#for warning:  -w A
#for profiling:  -p -inline 0   with OCAMLOPT
OCAMLC=ocamlc$(OPTBIN) -g -dtypes   $(INCLUDES)
OCAMLOPT=ocamlopt$(OPTBIN)   $(INCLUDES) $(OPTFLAGS)
OCAMLLEX=ocamllex$(OPTBIN) #-ml
OCAMLYACC=ocamlyacc -v
OCAMLDEP=ocamldep$(OPTBIN)  $(INCLUDES)
OCAMLMKTOP=ocamlmktop -g -custom $(INCLUDES)


OBJS = $(SRC:.ml=.cmo)
OPTOBJS = $(SRC:.ml=.cmx)


##############################################################################
# Top rules
##############################################################################
all: $(TARGET).cma
all.opt: $(TARGET).cmxa

$(TARGET).cma: $(OBJS)
	$(OCAMLC) -a -o $(TARGET).cma $(OBJS)

$(TARGET).cmxa: $(OPTOBJS) $(LIBS:.cma=.cmxa)
	$(OCAMLOPT) -a -o $(TARGET).cmxa $(OPTOBJS)

$(TARGET).top: $(OBJS) $(LIBS)
	$(OCAMLMKTOP) -o $(TARGET).top $(SYSLIBS) $(LIBS) $(OBJS)

clean::
	rm -f $(TARGET).top


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

distclean::
	rm -f .depend

beforedepend::

depend:: beforedepend
	$(OCAMLDEP) *.mli *.ml    > .depend


-include .depend
