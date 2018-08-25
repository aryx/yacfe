Yacfe
=====

Summary
-------

Yacfe (Yet Another C Front-End) is mainly an OCaml API to write
style-preserving source-to-source transformations such as refactorings
on C source code.

The goal of Yacfe is to parse the code as-is, and to represent it
internally as-is. We thus maintain in the Abstract Syntax Tree (AST)
as much information as possible so that one can transform this AST and
unparse it in a new file while preserving the coding style of the
original file. Yacfe preserves the whitespaces, newlines, indentation,
and comments from the original file, as well as the C preprocessor
(cpp) macros and cpp directives.

Other source-to-source transformation tools such as
[CIL](http://manju.cs.berkeley.edu/cil/) do not preserve this coding style
as they first call 'cpp' on the original file and perform the
transformation on the preprocessed file. The AST of Yacfe on the
opposite contains explicit constructions representing cpp directives,
macro definitions, or cpp idioms such as macro iterators as in
`list_for_each(i, x) { printf("%d", x); }`. "What You See In The Yacfe
AST Is What Was Written". The Yacfe abstract syntax tree is thus in
fact more a concrete syntax tree (c.f. `parsing_c/ast_c.ml`).

Compilation
-----------

To install Yacfe from its source, see the instructions in INSTALL.md.
If OCaml is installed, this should consist of doing:

```
    $ ./configure
    $ make depend
    $ make
```

If you want to embed the C parsing library in your own application,
you should normally have just to copy the `parsing_c/` directory and the
`commons/` directory (and the `matcher_c/` and `analyze_c/` directories
only if you want the other services) in your project directory and add a
recursive make that goes in those directories.

Example
-------

You can then test Yacfe with:

```
    $ cd demos/
    $ ocamlc -I ../commons/ -I ../parsing_c/ unix.cma str.cma bigarray.cma ../commons/commons.cma ../parsing_c/parsing_c.cma simple_zero_to_null.ml -o zero_to_null
    $ ./zero_to_null foo.c
    $ cat /tmp/modified.c
```

You should then see in the file `/tmp/modified.c` the result of
converting some `0` into `NULL` on the original file `foo.c`
according to the program transformation encoded in `simple_zero_to_null.ml`.
You should also see that the style of the original file (whitespaces,
indentation, comments, cpp directives) has been maintained in
`/tmp/modified.c`.

The compilation process, in addition to building the parsing_c.cma library,
also builds a binary program called 'yacfe' that can let you evaluate
how good the Yacfe parser is. To test the parser for instance on the
source code of the git version control system, just do:

```
    $ cd /tmp
    $ wget http://kernel.org/pub/software/scm/git/git-1.6.2.4.tar.bz2
    $ tar xvfj git-1.6.2.4.tar.bz2
    $ cd <yacfe_installation_dir>
    $ ./yacfe -parse /tmp/git-1.6.2.4/
```

The yacfe program should then iterate over all C source code files
(`.c` and `.h` files), and run the parser on each of those files. At the
end yacfe will output some statistics showing what yacfe was not
able to handle. On the git source code the message is:

```
    NB total files = 327; perfect = 316; pbs = 11; timeout = 0; =========> 96%
    nb good = 111789,  nb passed = 448 =========> 0.400755% passed
    nb good = 111789,  nb bad = 2201 =========> 98.069129% good
```

meaning yacfe was able to parse 98% of the code, but had in those 98%
to pass a few tokens (0.4%) (quite often code inside `#if 0` that the
parser just ignores).

Configuration
-------------

The Yacfe parser relies on the fact that in most C programs,
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

```c
    #define change_hops YACFE__MACRO__ITERATOR
    #define DBG         YACFE__MACRO__STATEMENT
    #define KERN_EMERG  YACFE__MACRO__STRING
    #define DESC_ALIGN  YACFE__MACRO__DECL
```

This file can also be used as a last resort as a way
to partially call cpp for difficult macros, such as

```c
    __P(int, foo, (int x, int y))
    {
      printf("%d,%d", x y);
    }
```

by adding for instance this definition in the configuration file:

```c
    #define __P(returnt, name, params) returnt name params
```

In these cases, the resulting expansion is marked specially in the AST
so that even if a tool using Yacfe can match over such expansion, such
tool will be warned if it wants to transform those expansions.

For more information on Yacfe see the files in the `docs/` directory.
The `config/macros/` directory also contains examples of configuration
files for different popular open-source software.

Organization
------------

Here are roughly the services provided by Yacfe and their corresponding
source files:

 * C parser which is also cpp-aware and program-transformation-friendly:
     * AST    (`ast_c.ml`)
     * lexer  (`lexer_c.mll`)
     * grammar (`parser_c.mly`)
     * hacks   (`parsing_hacks.ml`, `lexer_parser.ml`)
     * "driver", error recovery (`parse_c.ml`)
 * Visitor (`visitor_c.ml`)
 * Control flow graph (`control_flow_c.ml`, `ast_to_flow.ml`)
 * Unparsing (`unparse_c.ml`, `unparse_cocci.ml`) (style preserving)
 * Pretty printing (`pretty_print_c.ml`)        (not style preserving)
 * Type annotater (`type_annotater_c.ml`)
 * cpp expander on ast (`cpp_ast_c.ml`)
 * Statistics (`parsing_stat.ml`, `statistics_c.ml`)
 * Comment annotater (`comment_annotater.ml`)
