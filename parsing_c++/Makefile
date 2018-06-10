##############################################################################
# Variables
##############################################################################
TARGET=parsing_cplusplus

# ast_cocci.ml and should be deleted in the futur
# to make parsing_c really independent of coccinelle. 
# control_flow_c have also coccinelle dependencies.
SRC= flag_parsing_cplusplus.ml parsing_stat2.ml \
 ast_cocci_cplusplus.ml \
 ast_cplusplus.ml control_flow_cplusplus.ml \
 semantic_cplusplus.ml lexer_parser2.ml parser_cplusplus.ml lexer_cplusplus.ml \
 token_helpers2.ml parsing_hacks2.ml parse_cplusplus.ml \
 visitor_cplusplus.ml lib_parsing_cplusplus.ml \
 statistics_cplusplus.ml  comment_cplusplus_annotater.ml  \
 test_parsing_cplusplus.ml

# pretty_print_cplusplus.ml unparse_cplusplus.ml \

# 
# ast_to_flow.ml \
# compare_c.ml type_annoter_c.ml  \
# 


SYSLIBS= str.cma unix.cma 
LIBS=../commons/commons.cma ../code_info/code_info.cma
INCLUDES= -I ../commons -I ../code_info

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



lexer_cplusplus.ml: lexer_cplusplus.mll
	$(OCAMLLEX) $<
clean::
	rm -f lexer_cplusplus.ml
beforedepend:: lexer_cplusplus.ml


parser_cplusplus.ml parser_cplusplus.mli: parser_cplusplus.mly
	$(OCAMLYACC) $<
clean::
	rm -f parser_cplusplus.ml parser_cplusplus.mli parser_cplusplus.output
beforedepend:: parser_cplusplus.ml parser_cplusplus.mli


##############################################################################
# Pad's rules
##############################################################################
# pretty_print_cplusplus.ml unparse_cplusplus.ml \
# ast_to_flow.ml \
# compare_c.ml type_annoter_c.ml  
# visitor_cplusplus.ml lib_parsing_cplusplus.ml \
# statistics_cplusplus.ml  comment_cplusplus_annotater.ml  \
# test_parsing_cplusplus.ml
COREPARSING= flag_parsing_cplusplus.ml parsing_stat2.ml \
 ast_cocci.ml \
 ast_cplusplus.ml control_flow_cplusplus.ml \
 semantic_cplusplus.ml lexer_parser2.ml parser_cplusplus.mly lexer_cplusplus.mll \
 token_helpers2.ml parsing_hacks2.ml parse_cplusplus.ml 

locparsing:
	wc -l $(COREPARSING)


purge: clean
	rm -f parser_cplusplus.automaton

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
