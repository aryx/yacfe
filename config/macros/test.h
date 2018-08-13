// Cooperation with parsing_hack.ml: YACFE_XXX are magic strings.
// In the case of YACFE_STATEMENT, I could not just expand those macros
// into some 'whatever();' because I needed
// to generate a TMacroStmt for solving some ambiguities in the grammar
// for the toplevel stuff I think.

// todo? add parameters ?

// ex:
#define XXX_ICH(a,b,c) YACFE_ITERATOR

// ex:
#define XXX_STR YACFE_STRING

// ex:
#define XXX_DEC YACFE_DECLARATOR

// ex:
#define XXX_STM YACFE_STATEMENT

// ex:
#define __xxx  YACFE_ATTRIBUTE

// backward compatibility
#define XXX_DBG MACROSTATEMENT



// ex: int foo __P((int a, int b));
#define __P(a) a
