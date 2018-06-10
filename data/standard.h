// clone: yacfe(master), coccinelle, acomment, 

// ****************************************************************************
// Prelude, this file is to be used with the -macro_file option of the C parser
// ****************************************************************************

/* This file contains:
 *   - macros found in <.h>
 *   - macros found in .c; macros that cannot be parsed.
 *     In the future should be autodetected
 *     (not so easy to do same for macros in .h cos require to access .h file)
 *   - macros found in ".h" 
 *     but where we cant detect that it will be a "bad macro"
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

// ****************************************************************************
// Generic macros
// ****************************************************************************


// ****************************************************************************
// CISCO vpn client macros 
// ****************************************************************************

// #define NOREGPARM 
// #define IN
// #define OUT
// #define OPTIONAL

