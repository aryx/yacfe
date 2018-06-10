##############################################################################
# Variables
##############################################################################
TARGET=gui

SRC=model.ml controller.ml view.ml 

SYSLIBS=str.cma unix.cma dbm.cma threads.cma  lablgtk.cma lablgtksourceview.cma

LIBS=../commons/commons.cma ../commons/commons_gui.cma \
     ../globals/globals.cma \
     ../parsing_c/parsing_c.cma

INCLUDEDIRS=../commons ../globals \
	../parsing_c 

SYSINCLUDES=-I +lablgtk2 -I +lablgtksourceview -I ../ocamlgtk/src

##############################################################################
# Generic variables
##############################################################################
INCLUDES=$(INCLUDEDIRS:%=-I %)

OCAMLCFLAGS=-g -dtypes -w s # -w A

OCAMLC=ocamlc$(OPTBIN) $(OCAMLCFLAGS)   $(INCLUDES) $(SYSINCLUDES) -thread
OCAMLOPT=ocamlopt$(OPTBIN) $(OPTFLAGS)  $(INCLUDES) $(SYSINCLUDES) -thread
#OCAMLLEX=ocamllex$(OPTBIN) -ml
OCAMLLEX=ocamllex$(OPTBIN)
OCAMLYACC=ocamlyacc -v
OCAMLDEP=ocamldep$(OPTBIN) $(INCLUDES)
OCAMLMKTOP=ocamlmktop -g -custom $(INCLUDES) $(SYSINCLUDES) 

OBJS= $(SRC:.ml=.cmo)
OPTOBJS= $(SRC:.ml=.cmx)


##############################################################################
# Top rules
##############################################################################
all: $(TARGET).cma 
all.opt: $(TARGET).cmxa
opt: all.opt


$(TARGET).cma: $(OBJS) $(LIBS)
	$(OCAMLC) -a -o $(TARGET).cma $(OBJS)

$(TARGET).cmxa: $(OPTOBJS) $(LIBS:.cma=.cmxa)
	$(OCAMLOPT) -a -o $(TARGET).cmxa $(OPTOBJS)


##############################################################################
# developer rules
##############################################################################

mli: 
	ocamlc -i -g -dtypes -w s    -I ../commons -I ../globals -I ../parsing_c -I ../lfs_code/ocamlbdb -I ../lfs_code/lfs_core -I ../lfs_code/lfs_real -I ../nlp -I ../comments -I ../database  -I +lablgtk2 -I +lablgtksourceview -c gCommon.ml

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
