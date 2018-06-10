// clone: yacfe(master), coccinelle, acomment, 

// ****************************************************************************
// Prelude, this file is used with -macro_file_builtins option of the C parser
// ****************************************************************************

/* This file contains:
 *   - macros found in <.h>
 *   - macros found in ".h" 
 *     but where we cant detect that it will be a "bad macro"
 *   - hints, cf below.
 * 
 * A "bad macro" is a macro using free variables or when expanded
 * that influence the control-flow of the code. In those cases it 
 * is preferable to expand the macro so that the coccinelle engine
 * has a more accurate representation of what is going on.
 * 
 *
 *
 *
 * old: this file was also containing what is below but now we 
 * try to expand on demand the macro found in the c file, so those cases
 * are not needed any more:
 *   - macros found in .c; macros that cannot be parsed.
 *     In the future should be autodetected
 *     (not so easy to do same for macros in .h cos require to access .h file)
 *   - macros found in .c; macros correctly parsed
 *     but where we cant detect that it will be a "bad macro"
 *
 * Some of those macros could be deleted and the C code rewritten because
 * they are "bad" macros.
 * 
 * todo? perhaps better if could enable/disable some of those expansions
 * as different software may use conflicting macros.
 *
 *
 * can maybe have a look in sparse/lib.c to see a list of default #define
 * handled builtin apparently by gcc.
 */

// ****************************************************************************
// Test macros
// ****************************************************************************

// #define FOO(a, OP, b) a OP b
// #define FOO(a,b) fn(a,b)
#define YACFE_TEST_MACRO(a) a

// this is defined by windows compiler, and so can not be found via a macro
// after a -extract_macros
#define __stdcall YACFE_ATTRIBUTE
#define __declspec(a) 

#define WINAPI
#define CALLBACK
// generate false positive in Linux 

// ****************************************************************************
// Generic macros
// ****************************************************************************


