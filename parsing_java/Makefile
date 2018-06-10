# Joust: a Java lexer, parser, and pretty-printer written in OCaml
# Copyright (C) 2001  Eric C. Cooper <ecc@cmu.edu>
# Released under the GNU General Public License
#VERSION = 0.8
#MODULES = source syntax parser reserved lexer pretty
#PROGRAMS = lextest parsetest pptest comtest
#include ~/proj/ocaml/Makefile

##############################################################################
# Variables
##############################################################################
TARGET=parsing_java

SRC= flag_parsing_java.ml \
     ast_java.ml \
     visitor_java.ml lib_parsing_java.ml \
     lexer_helper.ml \
     parser_java.ml lexer_java.ml \
     token_helpers_java.ml \
     parse_java.ml \
     comment_java_annotater.ml \
     test_parsing_java.ml

#flag_parsing_cplusplus.ml \
# ast_cocci.ml \
#  \
# semantic_cplusplus.ml lexer_parser2.ml 
#  parsing_hacks2.ml  \
 
#control_flow_cplusplus.ml \
# visitor_cplusplus.ml \
# pretty_print_cplusplus.ml unparse_cplusplus.ml \
#lib_parsing_c.ml \
# ast_to_flow.ml \
# compare_c.ml type_annoter_c.ml  \
# place_c.ml statistics_c.ml  comment_annotater.ml  \

SYSLIBS= str.cma unix.cma 
LIBS=../commons/commons.cma ../pl_info/code_info.cma
INCLUDES= -I ../commons -I ../pl_info

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



lexer_java.ml: lexer_java.mll
	$(OCAMLLEX) $<
clean::
	rm -f lexer_java.ml
beforedepend:: lexer_java.ml


parser_java.ml parser_java.mli: parser_java.mly
	$(OCAMLYACC) $<
clean::
	rm -f parser_java.ml parser_java.mli parser_java.output
beforedepend:: parser_java.ml parser_java.mli


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
