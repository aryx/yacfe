Yacfe (Yet Another C/C++ Front-End) is mainly an OCaml API to write
style-preserving source-to-source transformations such as refactorings
on C or C++ source code.

The goal of Yacfe is to parse the code as-is, and to represent it
internally as-is. We thus maintain in the Abstract Syntax Tree (AST)
as much information as possible so that one can transform this AST and
unparse it in a new file while preserving the coding style of the
original file. Yacfe preserves the whitespaces, newlines, indentation,
and comments from the original file, as well as the C preprocessor
(cpp) macros and cpp directives. 

Other source-to-source transformation tools such as CIL [1] do not
preserve this coding style as they first call cpp on the original file
and perform the transformation on the preprocessed file. The AST of
Yacfe on the opposite contains explicit constructions representing cpp
directives, macro definitions, or cpp idioms such as macro iterators
as in 'list_for_each(i, x) { printf("%d", x); }'. "What You See In The
Yacfe AST Is What Was Written". The Yacfe abstract syntax tree is thus
in fact more a concrete syntax tree (cf parsing_c/ast_c.ml).

To install Yacfe from its source, see the instructions in install.txt.
It should mainly consists in doing:

   $ ./configure
   $ make depend
   $ make

You can then test Yacfe with:

   $ cd demos/
   $ ocamlc -I ../commons/ -I ../parsing_c/ unix.cma str.cma ../commons/commons.cma ../parsing_c/parsing_c.cma simple_zero_to_null.ml -o zero_to_null 
   $ ./zero_to_null foo.c
   $ cat /tmp/modified.c

You should then see in the file /tmp/modified.c the result of
converting some '0' into NULL on the original file foo.c
according to the program transformation encoded in simple_zero_to_null.ml.
You should also see that the style of the original file (whitespaces,
indentation, comments, cpp directives) has been maintained in
/tmp/modified.c.




The Yacfe parser relies on the fact that in most C and C++ software,
programmers follow a limited number of conventions on the use of cpp
which makes it possible to represent most of the cpp idioms
in the AST. It also makes it possible for the parser to disambiguate
different situations by just looking at the context, names, or
indentation of cpp constructs. Nevertheless using Yacfe on new
projects may require adapting some of our heuristics. To offer an easy
way to partially extend Yacfe, the user can write a configuration file
where he can manually specify the class of specific but recurring
macros that cause the above heuristics to originally fail. We have
reused the syntax of cpp for the format of this file but Yacfe
recognizes special keywords used in the body of macros as hints.
Here is an excerpt of the configuration file for the Linux kernel: 

   #define change_hops YACFE__MACRO__ITERATOR 
   #define DBG         YACFE__MACRO__STATEMENT
   #define KERN_EMERG  YACFE__MACRO__STRING
   #define DESC_ALIGN  YACFE__MACRO__DECL

This file can also be used as a last resort as a way
to partially call cpp for difficult macros, such as

   __P(int, foo, (int x, int y)) 
   {
     printf("%d,%d", x y);
   }
   
by adding for instance this definition in the configuration file:

   #define __P(returnt, name, params) returnt name params

In these cases, the resulting expansion is marked specially in the AST
so that even if a tool using Yacfe can match over such expansion, such
tool will be warned if it wants to transform those expansions.


For more information on Yacfe see the files in the docs/ directory.

Here are roughly the services provided by Yacfe and their corresponding
source files:
 - C parser which is also cpp-aware: 
     - AST    (ast_c.ml)
     - lexer  (lexer_c.mll)
     - grammar (parser_c.mly)
     - hacks   (parsing_hacks.ml, lexer_parser.ml)
     - "driver", error recovery (parse_c.ml)
 - Visitor (visitor_c.ml)
 - Control flow graph (control_flow_c.ml, ast_to_flow.ml)
 - Unparsing (unparse_c.ml, unparse_cocci.ml)
 - Pretty printing (pretty_print_c.ml)
 - Statistics (parsing_stat.ml statistics_c.ml)
 - Type annotater (type_annotater_c.ml)
 - cpp expander on ast (cpp_ast_c.ml)
 - Comment annotater (comment_annotater.ml)
 - Database (database_c.ml)
 - Call graph (relation_c.ml)
 - Pattern matcher (c_vs_c.ml, cocci_vs_c.ml, pattern.ml, transformation.ml)
 

The parsing_c++/ and parsing_java/ contain some of those services
for the C++ and Java language.


[1] http://manju.cs.berkeley.edu/cil/
