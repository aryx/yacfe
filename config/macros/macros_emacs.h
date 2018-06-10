// time: 
//  start 18h07 62%
//        18h35 84.42%
//               95% (fix old C decl typedef pb)
//        + 30min 96.1 
/* remaining main pbs: 
 *  'xxx' unicode character
 *  foo(void) { },    function with no return type and often old C decl style
 */



//bad: DEFUN ("make-abbrev-table", Fmake_abbrev_table, Smake_abbrev_table, 0, 0, 0,
//BAD:!!!!!        doc: /* Create a new, empty abbrev table object.  */)
//bad:      ()
//bad: {
//bad:   /* The value 59 is arbitrary chosen prime number.  */
//bad:   return Fmake_vector (make_number (59), make_number (0));
//bad: }
#define DEFUN(str, f1, f2, i1, i2, i3, doc) void f1


//  DEFVAR_LISP ("byte-code-meter", &Vbyte_code_meter,
//	       doc: /* A vector of vectors which holds a histogram of byte-code usage.
//\(aref (aref byte-code-meter 0) CODE) indicates how many times the byte
//opcode CODE has been executed.
//\(aref (aref byte-code-meter CODE1) CODE2), where CODE1 is not 0,
//indicates how many times the byte opcodes CODE1 and CODE2 have been
//executed in succession.  */);
#define DEFVAR_LISP(str, e1, str) defvar(str,e1)

//bad:   DEFVAR_KBOARD ("prefix-arg", Vprefix_arg,
//BAD:!!!!! 		 doc: /* The value of the prefix argument for the next editing command.

//bad:   DEFVAR_PER_BUFFER ("local-abbrev-table", &current_buffer->abbrev_table, Qnil,
//BAD:!!!!! 		     doc: /* Local (mode-specific) abbrev table of current buffer.  */);
#define DEFVAR_PER_BUFFER(str,e1, e2) defvar_buffer(str,e1,e2)


#define DEFVAR_KBOARD(str, e1, str) defvar(str,e1)

//bad:   DEFVAR_LISP_NOPRO ("default-mode-line-format",
//bad: 		     &buffer_defaults.mode_line_format,
//BAD:!!!!! 		     doc: /* Default value of `mode-line-format' for buffers that don't override it.
//bad: This is the same as (default-value 'mode-line-format).  */);
#define DEFVAR_LISP_NOPRO(str, e1, str) defvar(str,e1)



//bad:   DEFVAR_INT ("gc-cons-threshold", &gc_cons_threshold,
//BAD:!!!!! 	      doc: /* *Number of bytes of consing between garbage collections.
#define DEFVAR_INT(str, e1, str) defvar(str,e1)

#define DEFVAR_BOOL(str, e1, str) defvar(str,e1)



//BAD:!!!!! static POINTER_TYPE *lisp_malloc P_ ((size_t, enum mem_type));
#define P_(a) a

//BAD:!!!!! void *xmalloc _P ((size_t));
#define _P(a) a


//BAD:!!!!! static void unwind_to_catch P_ ((struct catchtag *, Lisp_Object)) NO_RETURN;
#define NO_RETURN

//bad: static void NO_INLINE
//BAD:!!!!! x_error_quitter (display, error)
#define NO_INLINE


//BAD:!!!!! extern __ptr_t _malloc_internal PP ((__malloc_size_t __size));
#define _malloc_internal

#define PP(a) a

//BAD:!!!!! static __ptr_t reallochook __P ((__ptr_t, __malloc_size_t));
#define __P(a) a



//BAD:!!!!! extern int pop_multi_first _ARGS((popserver server, char *command,
#define _ARGS(a) a

//BAD:!!!!! static void extract_number_and_incr _RE_ARGS ((int *destination,
#define _RE_ARGS(a) a

//BAD:!!!!! int _CRTAPI1 _getpid (void);
#define _CRTAPI1



//BAD:!!!!!   EMACS_INT i;
#define EMACS_INT int

//BAD:!!!!!       Lisp_Object obj = Qnil;
#define Lisp_Object int



//BAD:!!!!! int (PASCAL *pfn_shutdown) (SOCKET s, int how);
#define PASCAL

//BAD:!!!!! typedef void (_CALLBACK_ *signal_handler)(int);
#define _CALLBACK_

//bad: regexec (preg, string, nmatch, pmatch, eflags)
//BAD:!!!!!     const regex_t *__restrict preg;
//bad:     const char *__restrict string;
//bad:     size_t nmatch;
//bad:     regmatch_t pmatch[__restrict_arr];
//bad:     int eflags;
//bad: {

//BAD:!!!!! extern int regcomp _RE_ARGS ((regex_t *__restrict __preg,
//#define __restrict 

//BAD:!!!!! extern int getopt_long (int ___argc, char *__getopt_argv_const *___argv,
//bad: 			const char *__shortopts,
//bad: 		        const struct option *__longopts, int *__longind)
//bad:        __THROW;
#define __THROW;


#define WINAPI
#define CALLBACK
#define __stdcall
#define __cdecl

#define pascal


//BAD:!!!!! globalref char sdata[];
#define globalref

//BAD:!!!!! extern noshare char **environ;
#define noshare

//bad: static CHAR_T *memcpy_lowcase __P ((CHAR_T *dest, const CHAR_T *src,
//BAD:!!!!! 				    size_t len LOCALE_PARAM_PROTO));
//bad: static CHAR_T *memcpy_uppcase __P ((CHAR_T *dest, const CHAR_T *src,
//BAD:!!!!! 				    size_t len LOCALE_PARAM_PROTO));
#define LOCALE_PARAM_PROTO
//
//bad: static CHAR_T *
//bad: memcpy_lowcase (dest, src, len LOCALE_PARAM)
//bad:      CHAR_T *dest;
//bad:      const CHAR_T *src;
//bad:      size_t len;
//BAD:!!!!!      LOCALE_PARAM_DECL
#define LOCALE_PARAM_DECL

//BAD:!!!!! static mpr_static(ArrowCursorMpr, 16, 16, 1, ArrowCursorData);
#define mpr_static(s, i1, i2, i3, s2) int s

//BAD:!!!!! getopt_long (int argc, char *__getopt_argv_const *argv, const char *options,
#define __getopt_argv_const const

/*

//BAD:!!!!!   extern DIRENTRY * readdirver ();
//BAD:!!!!!   extern EMACS_TIME *input_available_clear_time;
//
//BAD:!!!!! std_$call void  unix_$main();
//
////pad: double recursive
//BAD:!!!!! extern int mcheck PP ((void (*__abortfunc) PP ((enum mcheck_status))));


//BAD:!!!!!       if (cipb.hFileInfo.ioFlFndrInfo.fdType == 'APPL')
//
//BAD:!!!!!   owner_name = (char **) GetResource ('STR ',-16096);
//
//BAD:!!!!! const OSType kEmacsSubprocessSend = 'ESND';
//
//bad: enum {
//BAD:!!!!!   typeUTF8Text			= 'utf8'
//bad: };
//
//
//
//pad: many pbs because no return type to function
//bad: x_destroy_window (f)
//BAD:!!!!!      struct frame *f;
//bad: {
//
//BAD:!!!!! init_glyph_string (s, OPTIONAL_HDC (hdc) char2b, w, row, area, start, hl)
//
//  LOOP_ON_INPUT_LINES (inf, lb, dummy)
//    continue;
//}
//

*/
