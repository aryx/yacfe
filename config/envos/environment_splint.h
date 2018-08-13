// ---------------------------------------------------------------------------
//pad: copy from standard.h of splint distribution + some def from its unix.h
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// standard.h
// ---------------------------------------------------------------------------

/*
** standard.h --- ISO C99 Standard Library for Splint.
**
** Process with -DSTRICT to get strict library.
*/

/*@-nextlinemacros@*/
/*@+allimponly@*/
/*@+globsimpmodifiesnothing@*/

/*
** errno.h
*/

/*@constant int EDOM;@*/
/*@constant int ERANGE;@*/
#define ERANGE 2
/*@constant int EILSEQ;@*/

# ifdef STRICT
/*@checkedstrict@*/ int errno;
# else
///*@unchecked@*/ int errno;
# endif

/*
** stdbool.h
*/

/*@-likelybool@*/
//typedef _Bool bool;
/*@=likelybool@*/
/*@constant bool true@*/
/*@constant bool false@*/
/*@constant int __bool_true_false_are_defined = 1@*/

/*
** types
*/

//typedef /*@integraltype@*/ ptrdiff_t;
//typedef /*@unsignedintegraltype@*/ size_t;
//typedef /*@signedintegraltype@*/ ssize_t;
//typedef /*@integraltype@*/ wchar_t;

/*
** Added by Amendment 1 to ISO.
*/

//typedef /*@integraltype@*/ wint_t;
//typedef /*@abstract@*/ mbstate_t;

/*@constant null anytype NULL = 0;@*/

/*
** assert.h
*/

/*@constant _Bool NDEBUG;@*/

# ifdef STRICT
/*@falseexit@*/ void assert (/*@sef@*/ /*pad:_Bool*/ int e)
  /*@*/ ;
# else
///*@falseexit@*/ void assert (/*@sef@*/ _Bool /*@alt int@*/ e)
  /*@*/ ;
# endif


/*
** ctype.h
*/

# ifdef STRICT
//_Bool isalnum (int c) /*@*/ ;
//_Bool isalpha (int c) /*@*/ ;
//_Bool iscntrl (int c) /*@*/ ;
//_Bool isdigit (int c) /*@*/ ;
//_Bool isgraph (int c) /*@*/ ;
//_Bool islower (int c) /*@*/ ;
//_Bool isprint (int c) /*@*/ ;
//_Bool ispunct (int c) /*@*/ ;
//_Bool isspace (int c) /*@*/ ;
//_Bool isupper (int c) /*@*/ ;
//_Bool isxdigit (int c) /*@*/ ;
//char tolower (int c) /*@*/ ;
//char toupper (int c) /*@*/ ;
# else
/*
** evans 2002-01-03: added alt char (was alt unsigned char)
*/

_Bool /*@alt int@*/ isalnum (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ isalpha (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ iscntrl (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ isdigit (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ isgraph (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ islower (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ isprint (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ ispunct (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ isspace (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ isupper (int /*@alt char, unsigned char@*/ c) /*@*/ ;
_Bool /*@alt int@*/ isxdigit (int /*@alt char, unsigned char@*/ c) /*@*/ ;
char /*@alt int@*/ tolower (int /*@alt char, unsigned char@*/ c) /*@*/ ;
char /*@alt int@*/ toupper (int /*@alt char, unsigned char@*/ c) /*@*/ ;
# endif

/*
** locale.h
*/

struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
} ;

/*@constant int LC_ALL;@*/
/*@constant int LC_COLLATE;@*/
/*@constant int LC_CTYPE;@*/
/*@constant int LC_MONETARY;@*/
/*@constant int LC_NUMERIC;@*/
/*@constant int LC_TIME;@*/

/*@observer@*/ /*@null@*/ char *setlocale (int category, /*@null@*/ char *locale)
   /*@modifies internalState, errno@*/ ;

struct lconv *localeconv (void) /*@*/ ;

/*
** float.h
*/

/*
** Note, these are defined by macros, but NOT necessarily
** constants.  They may be used as lvalues.
*/

/*@unchecked@*/ int    DBL_DIG;
/*@unchecked@*/ double DBL_EPSILON;
/*@unchecked@*/ int    DBL_MANT_DIG;
/*@unchecked@*/ double DBL_MAX;
/*@unchecked@*/ int    DBL_MAX_10_EXP;
/*@unchecked@*/ int    DBL_MAX_EXP;
/*@unchecked@*/ double DBL_MIN;
/*@unchecked@*/ int    DBL_MIN_10_EXP;
/*@unchecked@*/ int    DBL_MIN_EXP;

/*@unchecked@*/ int   FLT_DIG;
/*@unchecked@*/ float FLT_EPSILON;
/*@unchecked@*/ int   FLT_MANT_DIG;
/*@unchecked@*/ float FLT_MAX;
/*@unchecked@*/ int   FLT_MAX_10_EXP;
/*@unchecked@*/ int   FLT_MAX_EXP;
/*@unchecked@*/ float FLT_MIN;
/*@unchecked@*/ int   FLT_MIN_10_EXP;
/*@unchecked@*/ int   FLT_MIN_EXP;
/*@constant            int   FLT_RADIX@*/
/*@unchecked@*/ int   FLT_ROUNDS;

/*@unchecked@*/ int         LDBL_DIG;
/*@unchecked@*/ long double LDBL_EPSILON;
/*@unchecked@*/ int         LDBL_MANT_DIG;
/*@unchecked@*/ long double LDBL_MAX;
/*@unchecked@*/ int         LDBL_MAX_10_EXP;
/*@unchecked@*/ int         LDBL_MAX_EXP;
/*@unchecked@*/ long double LDBL_MIN;
/*@unchecked@*/ int         LDBL_MIN_10_EXP;
/*@unchecked@*/ int         LDBL_MIN_EXP;

/*
** limits.h
*/

/*@constant int CHAR_BIT; @*/
/*@constant char CHAR_MAX; @*/
/*@constant char CHAR_MIN; @*/
/*@constant int INT_MAX; @*/
/*@constant int INT_MIN; @*/
#define INT_MAX 111
#define INT_MIN 111
/*@constant long int LONG_MAX; @*/
/*@constant long int LONG_MIN; @*/
/*@constant long int MB_LEN_MAX@*/
/*@constant signed char SCHAR_MAX; @*/
/*@constant signed char SCHAR_MIN; @*/
/*@constant short SHRT_MAX; @*/
/*@constant short SHRT_MIN; @*/
/*@constant unsigned char UCHAR_MAX; @*/
/*@constant unsigned char UCHAR_MIN; @*/
/*@constant unsigned int UINT_MAX; @*/
/*@constant unsigned long ULONG_MAX; @*/
/*@constant unsigned short USHRT_MAX; @*/

/*
** math.h
**
** evans 2002-07-03: updated from ISO C99 (http://www.vmunix.com/~gabor/c/draft.html)
*/

//typedef float float_t;
//typedef double double_t;

/*@constant double HUGE_VAL; @*/
/*@constant float HUGE_VALF; @*/
/*@constant long double HUGE_VALL; @*/

/*@constant float INFINITY; @*/

/*@constant float NAN; @*/
  /*:warn implementationoptional "NAN is defined if and only if the implementation supports quiet float type NaNs.":*/ ;

/*@constant int FP_INFINITE;@*/
/*@constant int FP_NAN;@*/
/*@constant int FP_NORMAL;@*/
/*@constant int FP_SUBNORMAL;@*/
/*@constant int FP_ZERO;@*/

/*@constant int FP_ILOGB0;@*/
/*@constant int FP_ILOGBNAN;@*/

/*@constant int DECIMAL_DIG;@*/

/* Defined for specs only - this type is any real type */
//typedef float /*@alt double, long double@*/ s_real_t;

int fpclassify (/*@sef@*/ s_real_t) /*@*/ ;
int signbit (/*@sef@*/ s_real_t) /*@*/ ;
int isfinite (/*@sef@*/ s_real_t) /*@*/ ;
int isnormal (/*@sef@*/ s_real_t) /*@*/ ;
int isnan (/*@sef@*/ s_real_t) /*@*/ ;
int isinf (/*@sef@*/ s_real_t) /*@*/ ;

/*
** math functions that may have a range error modify errno (implementation defined).
*/

double acos (double x) /*@modifies errno@*/ ;
double asin (double x) /*@modifies errno@*/ ;
double atan (double x) /*@*/ ;
double atan2 (double y, double x) /*@*/ ;

double cos (double x) /*@*/ ;
double sin (double x) /*@*/ ;
double tan (double x) /*@*/ ;

double cosh (double x) /*@modifies errno@*/ ;
double sinh (double x) /*@modifies errno@*/ ;
double tanh (double x) /*@*/ ;

double acosh (double x) /*@modifies errno@*/ ;
double asinh (double x) /*@modifies errno@*/ ;
double atanh (double x) /*@modifies errno@*/ ;

double exp (double x) /*@modifies errno@*/ ;
double frexp (double x, /*@out@*/ int *xp) /*@modifies *xp;@*/ ;
double ldexp (double x, int n) /*@modifies errno@*/ ;

double log (double x) /*@modifies errno@*/ ;
double log10 (double x) /*@modifies errno@*/ ;

double modf (double x, /*@out@*/ double *ip) /*@modifies *ip;@*/ ;

double exp2 (double x) /*@modifies errno@*/ ;
double expm1 (double x) /*@modifies errno@*/ ;
double log1p (double x) /*@modifies errno@*/ ;
double log2 (double x) /*@modifies errno@*/ ;
double logb (double x) /*@modifies errno@*/ ;

double scalbn (double x, int n) /*@modifies errno@*/ ;
double scalbln (double x, long int n) /*@modifies errno@*/ ;
long double scalblnl(long double x, long int n) /*@modifies errno@*/ ;

int ilogb (double x) /*@modifies errno@*/ ;
int ilogbf (float x) /*@modifies errno@*/ ;
int ilogbl (long double x) /*@modifies errno@*/ ;

double fabs (double x) /*@*/ ;
float fabsf (float x) /*@*/ ;
long double fabsl (long double x) /*@*/ ;

double pow (double x, double y) /*@modifies errno@*/ ;
float powf(float x, float y) /*@modifies errno@*/ ;
long double powl(long double x, long double y) /*@modifies errno@*/ ;

double sqrt (double x) /*@modifies errno@*/ ;
float sqrtf(float x) /*@modifies errno@*/ ;
long double sqrtl (long double x) /*@modifies errno@*/ ;

double cbrt (double x) /*@*/ ;
float cbrtf (float x) /*@*/ ;
long double cbrtl (long double x) /*@*/ ;

double hypot (double x, double y) /*@modifies errno@*/ ;
float hypotf (float x, float y) /*@modifies errno@*/ ;
long double hypotl (long double x, long double y) /*@modifies errno@*/ ;

double erf (double x) /*@*/ ;
double erfc (double x) /*@*/ ;
float erff (float x) /*@*/ ;
long double erfl (long double x) /*@*/ ;
float erfcf (float x) /*@*/ ;
long double erfcl (long double x) /*@*/ ;

double gamma (double x) /*@modifies errno@*/ ;
float gammaf(float x) /*@modifies errno@*/ ;
long double gammal (long double x) /*@modifies errno@*/ ;
double lgamma (double x) /*@modifies errno@*/ ;
float lgammaf (float x)  /*@modifies errno@*/ ;
long double lgammal (long double x)  /*@modifies errno@*/ ;

double ceil (double x) /*@*/ ;
float ceilf(float x) /*@*/ ;
long double ceill(long double x) /*@*/ ;

double floor (double x) /*@*/ ;
float floorf (float x) /*@*/ ;
long double floorl (long double x) /*@*/ ;

double nearbyint (double x) /*@*/ ;
float nearbyintf (float x) /*@*/ ;
long double nearbyintl (long double x) /*@*/ ;

double rint (double x) /*@*/;
float rintf (float x) /*@*/ ;
long double rintl (long double x) /*@*/ ;
long int lrint (double x) /*@modifies errno@*/ ;
long int lrintf (float x) /*@modifies errno@*/ ;
long int lrintl (long double x) /*@modifies errno@*/ ;
long long llrint (double x) /*@modifies errno@*/ ;
long long llrintf(float x)  /*@modifies errno@*/ ;
long long llrintl(long double x) /*@modifies errno@*/ ;

double round (double x) /*@*/ ;
long int lround (double x) /*@modifies errno@*/ ;
long long llround (double x) /*@modifies errno@*/ ;

double trunc (double x) /*@*/ ;
double fmod (double x, double y) /*@*/ ;
double remainder (double x, double y) /*@*/ ;
double remquo (double x, double y, /*@out@*/ int *quo) /*@modifies *quo@*/ ;
double copysign (double x, double y) /*@*/ ;
double nan (/*@nullterminated@*/ const char *tagp) /*@*/ ;
double nextafter (double x, double y) /*@*/ ;
double nextafterx (double x, long double y) /*@*/ ;

double fdim (double x, double y) /*@modifies errno@*/ ;
double fmax (double x, double y) /*@*/ ;
double fmin (double x, double y) /*@*/ ;
double fma (double x, double y, double z) /*@*/ ;

int isgreater (s_real_t x, s_real_t y) /*@*/ ;
int isgreaterequal (s_real_t x, s_real_t y) /*@*/ ;
int isless (s_real_t x, s_real_t y) /*@*/ ;
int islessequal (s_real_t x, s_real_t y) /*@*/ ;
int islessgreater (s_real_t x, s_real_t y) /*@*/ ;
int isunordered (s_real_t x, s_real_t y) /*@*/ ;

/*
** These functions are optional in iso C.  An implementation does not
** have to provide them.  They are included in comments here, but
** are not required to be part of the standard library.
*/

# ifdef OPTIONAL_MATH

//float acosf (float x) /*@modifies errno@*/ ;
//long double acosl (long double x) /*@modifies errno@*/ ;
//float asinf (float x)	/*@modifies errno@*/ ;
//long double asinl (long double x) /*@modifies errno@*/ ;
//float atanf (float x)	/*@*/ ;
//long double atanl (long double x) /*@*/ ;
//float atan2f (float y, float x) /*@*/ ;
//long double atan2l (long double y, long double x) /*@*/ ;
//float ceilf (float x)	/*@*/ ;
//long double ceill (long double x) /*@*/ ;
//float cosf (float x) /*@*/ ;
//long double cosl (long double x) /*@*/ ;
//float coshf (float x)	/*@modifies errno@*/ ;
//long double coshl (long double x) /*@modifies errno@*/ ;
//float expf (float x) /*@modifies errno@*/ ;
//long double expl (long double x) /*@modifies errno@*/;
//float fabsf (float x)	/*@*/ ;
//long double fabsl (long double x) /*@*/ ;
//float floorf (float x) /*@*/ ;
//long double floorl (long double x) /*@*/ ;
//float fmodf (float x, float y) /*@*/ ;
//long double fmodl (long double x, long double y)	/*@*/ ;
//float frexpf (float x, /*@out@*/ int *xp) /*@modifies *xp@*/;
//long double frexpl (long double x, /*@out@*/ int *xp) /*@modifies *xp@*/;
//float ldexpf (float x, int n) /*@modifies errno@*/ ;
//long double ldexpl (long double x, int n) /*@modifies errno@*/ ;
//float logf (float x) /*@modifies errno@*/ ;
//long double logl (long double x) /*@modifies errno@*/ ;
//float log10f (float x) /*@modifies errno@*/;
//long double log10l (long double x) /*@modifies errno@*/;
//float modff (float x, /*@out@*/ float *xp) /*@modifies *xp@*/ ;
//long double modfl (long double x, /*@out@*/ long double *xp) /*@modifies *xp@*/ ;
//float powf (float x, float y) /*@modifies errno@*/ ;
//long double powl (long double x, long double y) /*@modifies errno@*/ ;
//float sinf (float x) /*@*/ ;
//long double sinl (long double x)	/*@*/ ;
//float sinhf (float x) /*@*/ ;
//long double sinhl (long double x) /*@*/ ;
//float sqrtf (float x) /*@modifies errno@*/ ;
//long double sqrtl (long double x) /*@modifies errno@*/ ;
//float tanf (float x) /*@*/ ;
//long double tanl (long double x)	/*@*/ ;
//float tanhf (float x) /*@*/ ;
//long double tanhl (long double x) /*@*/ ;

# endif

/*
** setjmp.h
*/

typedef /*@abstract@*/ /*@mutable@*/ void *jmp_buf;

int setjmp (/*@out@*/ jmp_buf env) /*@modifies env;@*/ ;
/*@mayexit@*/ void longjmp (jmp_buf env, int val) /*@*/ ;

/*
** signal.h
*/

/*@constant int SIGABRT; @*/
/*@constant int SIGFPE; @*/
/*@constant int SIGILL; @*/
/*@constant int SIGINT; @*/
/*@constant int SIGSEGV; @*/
/*@constant int SIGTERM; @*/

//typedef /*@integraltype@*/ sig_atomic_t;

/*@constant void (*SIG_DFL)(int); @*/
/*@constant void (*SIG_ERR)(int); @*/
/*@constant void (*SIG_IGN)(int); @*/

/*
** signal takes an int, and a function takes int returns void, and
** returns the function (or NULL if unsuccessful).
*/

/*@null@*/ void (*signal (int sig, /*@null@*/ void (*func)(int))) (int)
   /*@modifies internalState, errno;@*/ ;

/*@mayexit@*/ int raise (int sig) ;

/*
** stdarg.h
*/

typedef /*@abstract@*/ /*@mutable@*/ void *va_list;

void va_start (/*@out@*/ va_list ap, ...) /*@modifies ap;@*/ ;
void va_end (va_list va) /*@modifies va;@*/ ;

void va_copy (/*@out@*/ va_list dest, va_list src) /*modifies dest;@*/ ;

/*
** va_arg is builtin
*/

/*
** stdio.h
*/

typedef /*@abstract@*/ /*@mutable@*/ void *FILE;
typedef /*@abstract@*/ /*@mutable@*/ void *fpos_t;

/*@constant size_t _IOFBF; @*/
/*@constant size_t _IOLBF; @*/
/*@constant size_t _IONBF; @*/

/*@constant size_t BUFSIZ; @*/ /* evans 2002-02-27 change suggested by Walter Briscoe */

/*@constant int EOF; @*/

/*@constant int FOPEN_MAX; @*/
/*@constant int FILENAME_MAX; @*/

/*@constant int L_tmpnam; @*/

/*@constant int SEEK_CUR; @*/
#define SEEK_CUR 0
/*@constant int SEEK_END; @*/
#define SEEK_END 0
/*@constant int SEEK_SET; @*/
#define SEEK_SET 0

/*@constant int TMP_MAX; @*/

# ifdef STRICT
/*@checked@*/ FILE *stderr;
/*@checked@*/ FILE *stdin;
/*@checked@*/ FILE *stdout;
# else
///*@unchecked@*/ FILE *stderr;
///*@unchecked@*/ FILE *stdin;
///*@unchecked@*/ FILE *stdout;
# endif

int remove (char *filename) /*@modifies fileSystem, errno@*/ ;
int rename (char *old, char *new) /*@modifies fileSystem, errno@*/ ;

/*@dependent@*/ /*@null@*/ FILE *tmpfile (void)
   /*@modifies fileSystem, errno@*/ ;

/*@observer@*/ char *
  tmpnam (/*@out@*/ /*@null@*/ /*@returned@*/ char *s)
  /*@modifies *s, internalState@*/ ;

int fclose (FILE *stream)
   /*@modifies *stream, errno, fileSystem;@*/ ;

int fflush (/*@null@*/ FILE *stream)
   /*@modifies *stream, errno, fileSystem;@*/ ;

/*@null@*/ /*@dependent@*/ FILE *fopen (char *filename, char *mode)
   /*@modifies fileSystem@*/ ;

/*@dependent@*/ /*@null@*/ FILE *freopen (char *filename, char *mode, FILE *stream)
  /*@modifies *stream, fileSystem, errno@*/ ;

void setbuf (FILE *stream, /*@null@*/ /*@exposed@*/ /*@out@*/ char *buf)
     /*@modifies fileSystem, *stream, *buf@*/
     /*:errorcode != 0*/ ;
     /*:requires maxSet(buf) >= (BUFSIZ - 1):*/ ;

int setvbuf (FILE *stream, /*@null@*/ /*@exposed@*/ /*@out@*/ char *buf,
	     int mode, size_t size)
      /*@modifies fileSystem, *stream, *buf@*/
     /*@requires maxSet(buf) >= (size - 1) @*/ ;

# ifdef STRICT
/*@printflike@*/
int fprintf (FILE *stream, char *format, ...)
   /*@modifies fileSystem, *stream@*/ ;
# else
///*@printflike@*/
//int /*@alt void@*/ fprintf (FILE *stream, char *format, ...)
//   /*@modifies fileSystem, *stream@*/ ;
# endif

/*@scanflike@*/
int fscanf (FILE *stream, char *format, ...)
   /*@modifies fileSystem, *stream, errno@*/ ;

# ifdef STRICT
/*@printflike@*/
int printf (char *format, ...)
   /*@globals stdout@*/
   /*@modifies fileSystem, *stdout@*/ ;
# else
///*@printflike@*/
//int /*@alt void@*/ printf (char *format, ...)
//   /*@globals stdout@*/
//   /*@modifies fileSystem, *stdout@*/ ;
# endif

/*@scanflike@*/
int scanf(char *format, ...)
   /*@globals stdin@*/
   /*@modifies fileSystem, *stdin, errno@*/ ;
   /*drl added errno 09-19-2001 */ ;

# ifdef STRICT
/*@printflike@*/
int sprintf (/*@out@*/ char *s, char *format, ...)
   /*@warn bufferoverflowhigh "Buffer overflow possible with sprintf.  Recommend using snprintf instead"@*/
   /*@modifies *s@*/ ;
# else
///*@printflike@*/
//int /*@alt void@*/ sprintf (/*@out@*/ char *s, char *format, ...)
//   /*@warn bufferoverflowhigh "Buffer overflow possible with sprintf.  Recommend using snprintf instead"@*/
//   /*@modifies *s@*/ ;
# endif

/* evans 2002-07-09: snprintf added to standard.h (from unix.h) */
/*@printflike@*/
int snprintf (/*@out@*/ char * /*pad:restrict*/ s, size_t n, const char * /*pad: restrict*/ format, ...)
   /*@modifies s@*/
   /*@requires maxSet(s) >= (n - 1)@*/ ;

/*@scanflike@*/
int sscanf (/*@out@*/ char *s, char *format, ...) /*@modifies errno@*/ ;
   /* modifies extra arguments */

int vprintf (const char *format, va_list arg)
   /*@globals stdout@*/
   /*@modifies fileSystem, *stdout@*/ ;

int vfprintf (FILE *stream, char *format, va_list arg)
   /*@modifies fileSystem, *stream, arg, errno@*/ ;

int vsprintf (/*@out@*/ char *str, const char *format, va_list ap)
     /*@warn bufferoverflowhigh "Use vsnprintf instead"@*/
     /*@modifies str@*/ ;

int vsnprintf (/*@out@*/ char *str, size_t size, const char *format, va_list ap)
     /*@requires maxSet(str) >= (size - 1)@*/ /* drl - this was size, size-1 in stdio.h */
     /*@modifies str@*/ ;

int fgetc (FILE *stream)
   /*@modifies fileSystem, *stream, errno@*/ ;

/*@null@*/ char *
  fgets (/*@returned@*/ /*@out@*/ char *s, int n, FILE *stream)
     /*@modifies fileSystem, *s, *stream, errno@*/
     /*@requires maxSet(s) >= (n -1); @*/
     /*@ensures maxRead(s) <= (n -1) /\ maxRead(s) >= 0; @*/
     ;

int fputc (int /*@alt char@*/ c, FILE *stream)
  /*:errorcode EOF:*/
  /*@modifies fileSystem, *stream, errno@*/ ;

int fputs (char *s, FILE *stream)
  /*@modifies fileSystem, *stream@*/ ;

/* note use of sef --- stream may be evaluated more than once */
int getc (/*@sef@*/ FILE *stream)
  /*@modifies fileSystem, *stream, errno@*/ ;

int getchar (void) /*@globals stdin@*/ /*@modifies fileSystem, *stdin, errno@*/ ;

/*@null@*/ char *gets (/*@out@*/ char *s)
   /*@warn bufferoverflowhigh
           "Use of gets leads to a buffer overflow vulnerability.  Use fgets instead"@*/
   /*@globals stdin@*/ /*@modifies fileSystem, *s, *stdin, errno@*/ ;

int putc (int /*@alt char@*/ c, /*@sef@*/ FILE *stream)
   /*:errorcode EOF:*/
   /*@modifies fileSystem, *stream, errno;@*/ ;

int putchar (int /*@alt char@*/ c)
   /*:errorcode EOF:*/
   /*@globals stdout@*/
   /*@modifies fileSystem, *stdout, errno@*/ ;

int puts (const char *s)
   /*:errorcode EOF:*/
   /*@globals stdout@*/
   /*@modifies fileSystem, *stdout, errno@*/ ;

int ungetc (int /*@alt char@*/ c, FILE *stream)
  /*@modifies fileSystem, *stream@*/ ;
      /*drl REMOVED errno 09-19-2001*/

size_t
  fread (/*@out@*/ void *ptr, size_t size, size_t nobj, FILE *stream)
  /*@modifies fileSystem, *ptr, *stream, errno@*/
  /*requires maxSet(ptr) >= (size - 1) @*/
  /*@ensures maxRead(ptr) == (size - 1) @*/ ;

size_t fwrite (void *ptr, size_t size, size_t nobj, FILE *stream)
  /*@modifies fileSystem, *stream, errno@*/
  /*@requires maxRead(ptr) >= size @*/ ;

int fgetpos (FILE *stream, /*@out@*/ fpos_t *pos)
   /*@modifies *pos, errno@*/
   /*@requires maxSet(pos) >= 0@*/
   /*@ensures maxRead(pos) >= 0 @*/;

int fseek (FILE *stream, long int offset, int whence)
   /*:errorcode -1:*/
   /*@modifies fileSystem, *stream, errno@*/ ;

int fsetpos (FILE *stream, fpos_t *pos)
   /*@modifies fileSystem, *stream, errno@*/ ;

long int ftell(FILE *stream)
   /*:errorcode -1:*/ /*@modifies errno*/ ;

void rewind (FILE *stream) /*@modifies *stream@*/ ;
void clearerr (FILE *stream) /*@modifies *stream@*/ ;

int feof (FILE *stream) /*@modifies errno@*/ ;

int ferror (FILE *stream) /*@modifies errno@*/ ;

void perror (/*@null@*/ char *s)
   /*@globals errno, stderr@*/ /*@modifies fileSystem, *stderr@*/ ;

/*
** stdlib.h
*/

double atof (char *s) /*@*/ ;
int atoi (char *s) /*@*/ ;
long int atol (char *s) /*@*/ ;

double strtod (char *s, /*@null@*/ /*@out@*/ char **endp)
  /*@modifies *endp, errno@*/ ;

long strtol (char *s, /*@null@*/ /*@out@*/ char **endp, int base)
  /*@modifies *endp, errno@*/ ;

unsigned long
  strtoul (char *s, /*@null@*/ /*@out@*/ char **endp, int base)
  /*@modifies *endp, errno@*/ ;

/*@constant int RAND_MAX; @*/
int rand (void) /*@modifies internalState@*/ ;
void srand (unsigned int seed) /*@modifies internalState@*/ ;

/*
  drl
  changed 12/29/2000
*/

/*@null@*/ /*@only@*/ void *calloc (size_t nobj, size_t size) /*@*/
     /*@ensures maxSet(result) == (nobj - 1); @*/ ;
/*@null@*/ /*@out@*/ /*@only@*/ void *malloc (size_t size) /*@*/
     /*@ensures maxSet(result) == (size - 1); @*/ ;

/*end drl changed */

/* 11 June 1997: removed out on return value */

/*
** LCLint annotations cannot fully describe realloc.  The semantics we
** want are:
**    realloc returns null: ownership of parameter is not changed
**    realloc returns non-null: ownership of parameter is transferred to return value
**
** Otherwise, storage is in the same state before and after the call.
*/

/*@null@*/ /*@only@*/ void *
   realloc (/*@null@*/ /*@only@*/ /*@out@*/ /*@returned@*/ void *p, size_t size)
     /*@modifies *p@*/ /*@ensures maxSet(result) >= (size - 1) @*/;

void free (/*@null@*/ /*@out@*/ /*@only@*/ void *p) /*@modifies p@*/ ;

/*@constant int EXIT_FAILURE; @*/
/*@constant int EXIT_SUCCESS; @*/

/*@exits@*/ void abort (void) /*@*/ ;
/*@exits@*/ void exit (int status) /*@*/ ;
int atexit (void (*func)(void)) /*@modifies internalState@*/ ;

/*@observer@*/ /*@null@*/ char *getenv (char *name) /*@*/ ;

int system (/*@null@*/ char *s) /*@modifies fileSystem@*/ ;

/*@null@*/ /*@dependent@*/ void *
  bsearch (void *key, void *base,
	   size_t n, size_t size,
	   int (*compar)(void *, void *)) /*@*/ ;

void qsort (void *base, size_t n, size_t size,
		   int (*compar)(void *, void *))
   /*@modifies *base, errno@*/ ;

int abs (int n) /*@*/ ;

typedef /*@concrete@*/ struct
{
  int quot;
  int rem;
} div_t ;

div_t div (int num, int denom) /*@*/ ;

long int labs (long int n) /*@*/ ;

typedef /*@concrete@*/ struct
{
  long int quot;
  long int rem;
} ldiv_t ;

ldiv_t ldiv (long num, long denom) /*@*/ ;

/*@constant size_t MB_CUR_MAX; @*/

/*
** wchar_t and wint_t functions added by Amendment 1 to ISO.
*/

/*@constant int WCHAR_MAX@*/
/*@constant int WCHAR_MIN@*/
/*@constant wint_t WEOF@*/

wint_t btowc (int c) /*@*/ ;

wint_t fgetwc (FILE *fp)	/*@modifies fileSystem, *fp*/ ;

/*@null@*/ wchar_t *fgetws (/*@returned@*/ wchar_t *s, int n, FILE *stream)
   /*@modifies fileSystem, *s, *stream@*/;

wint_t fputwc (wchar_t c, FILE *stream)
   /*@modifies fileSystem, *stream@*/;

int fputws (const wchar_t *s, FILE *stream)
   /*@modifies fileSystem, *stream@*/ ;

int fwide (FILE *stream, int mode) /*@*/ ;
   /* does not modify the stream */

/*@printflike@*/ int fwprintf (FILE *stream, const wchar_t *format, ...)
    /*@modifies *stream, fileSystem@*/ ;

/*@scanflike@*/ int fwscanf (FILE *stream, const wchar_t *format, ...)
	/*@modifies *stream, fileSystem@*/ ;

/* note use of sef --- stream may be evaluated more than once */
wint_t getwc (/*@sef@*/ FILE *stream) /*@modifies fileSystem, *stream@*/ ;

wint_t getwchar (void) /*@modifies fileSystem, *stdin@*/;

size_t mbrlen (const char *s, size_t n, /*@null@*/ mbstate_t *ps) /*@*/ ;

size_t mbrtowc (/*@null@*/ wchar_t *pwc, const char *s, size_t n,
		       /*@null@*/ mbstate_t *ps)
   /*@modifies *pwc@*/ ;

int mbsinit (/*@null@*/ const mbstate_t *ps) /*@*/ ;

size_t mbsrtowcs (/*@null@*/ wchar_t *dst, const char **src, size_t len,
			 /*@null@*/ mbstate_t *ps)
   /*@modifies *dst@*/ ;

/* note use of sef --- stream may be evaluated more than once */
wint_t putwc (wchar_t c, /*@sef@*/ FILE *stream)	/*@modifies fileSystem, *stream@*/ ;

wint_t putwchar (wchar_t c) /*@modifies fileSystem, *stdout@*/ ;

/*@printflike@*/ int swprintf (wchar_t *s, size_t n, const wchar_t *format, ...)
   /*@modifies *s@*/ ;

/*@scanflike@*/ int swscanf (const wchar_t *s, const wchar_t *format, ...)
   /*@modifies *stdin@*/ ;

wint_t ungetwc (wint_t c, FILE *stream) /*@modifies fileSystem, *stream@*/ ;

int vfwprintf (FILE *stream, const wchar_t *format, va_list arg)
   /*@modifies fileSystem, *stream@*/ ;

int vswprintf (wchar_t *s, size_t n, const wchar_t *format, va_list arg)
   /*@modifies *s@*/ ;

int vwprintf (const wchar_t *format, va_list arg)
   /*@modifies fileSystem, *stdout@*/ ;

size_t wcrtomb (/*@null@*/ /*@out@*/ char *s, wchar_t wc, /*@null@*/ mbstate_t *ps)
   /*@modifies *s@*/;

void /*@alt wchar_t *@*/
  wcscat (/*@unique@*/ /*@returned@*/ /*@out@*/ wchar_t *s1, const wchar_t *s2)
  /*@modifies *s1@*/ ;

/*@exposed@*/ /*@null@*/ wchar_t *
  wcschr (/*@returned@*/ const wchar_t *s, wchar_t c)
  /*@*/ ;

int wcscmp (const wchar_t *s1, const wchar_t *s2) /*@*/ ;

int wcscoll (const wchar_t *s1, const wchar_t *s2) /*@*/ ;

void /*@alt wchar_t *@*/
  wcscpy (/*@unique@*/ /*@out@*/ /*@returned@*/ wchar_t *s1, const wchar_t *s2)
  /*@modifies *s1@*/ ;

size_t wcscspn (const wchar_t *s1, const wchar_t *s2) /*@*/ ;

size_t wcsftime (/*@out@*/ wchar_t *s, size_t maxsize, const wchar_t *format,
			const struct tm *timeptr)
   /*@modifies *s@*/ ;

size_t wcslen (const wchar_t *s) /*@*/ ;

void /*@alt wchar_t *@*/
  wcsncat (/*@unique@*/ /*@returned@*/ /*@out@*/ wchar_t *s1, const wchar_t *s2,
	   size_t n)
  /*@modifies *s1@*/ ;

int wcsncmp (const wchar_t *s1, const wchar_t *s2, size_t n) /*@*/ ;

void /*@alt wchar_t *@*/
  wcsncpy (/*@unique@*/ /*@returned@*/ /*@out@*/ wchar_t *s1, const wchar_t *s2,
	   size_t n)
   /*@modifies *s1@*/ ;

/*@null@*/ wchar_t *
  wcspbrk (/*@returned@*/ const wchar_t *s1, const wchar_t *s2)
  /*@*/ ;

/*@null@*/ wchar_t *
  wcsrchr (/*@returned@*/ const wchar_t *s, wchar_t c)
  /*@*/ ;

size_t
  wcsrtombs (/*@null@*/ char *dst, const wchar_t **src, size_t len,
	     /*@null@*/ mbstate_t *ps)
  /*@modifies *src@*/ ;

size_t wcsspn (const wchar_t *s1, const wchar_t *s2) /*@*/ ;

/*@null@*/ wchar_t *wcsstr (const wchar_t *s1, const wchar_t *s2) /*@*/ ;

double wcstod (const wchar_t *nptr, /*@null@*/ wchar_t **endptr)
   /*@modifies *endptr@*/ ;

/*@null@*/ wchar_t *
  wcstok (/*@null@*/ wchar_t *s1, const wchar_t *s2, wchar_t **ptr)
  /*@modifies *ptr@*/;

long wcstol (const wchar_t *nptr, /*@null@*/ wchar_t **endptr, int base)
   /*@modifies *endptr@*/;

unsigned long
  wcstoul (const wchar_t *nptr, /*@null@*/ wchar_t **endptr, int base)
  /*@modifies *endptr@*/;

size_t
  wcsxfrm (/*@null@*/ wchar_t *s1, const wchar_t *s2, size_t n)
  /*@modifies *s1@*/;

int wctob (wint_t c) /*@*/;

/*@null@*/ wchar_t *wmemchr (const wchar_t *s, wchar_t c, size_t n) /*@*/ ;

int wmemcmp (const wchar_t *s1, const wchar_t *s2, size_t n) /*@*/ ;

wchar_t *wmemcpy (/*@returned@*/ wchar_t *s1, const wchar_t *s2, size_t n)
   /*@modifies *s1@*/;

wchar_t *wmemmove (/*@returned@*/ wchar_t *s1, const wchar_t *s2, size_t n)
   /*@modifies *s1@*/;

wchar_t *wmemset (/*@returned@*/ wchar_t *s, wchar_t c, size_t n)
   /*@modifies *s@*/;

/*@printflike@*/ int wprintf (const wchar_t *format, ...)
   /*@globals stdout@*/ /*@modifies errno, *stdout@*/;

/*@scanflike@*/ int
  wscanf (const wchar_t *format, ...)
  /*@globals stdin@*/ /*@modifies errno, *stdin@*/;

/*
** wctype.h (added by Amendment 1)
*/

/* Warning: not sure about these (maybe abstract?): */
//typedef /*@integraltype@*/ wctype_t;
//typedef /*@integraltype@*/ wctrans_t;

# ifdef STRICT
//_Bool iswalnum (wint_t c) /*@*/ ;
//_Bool iswalpha (wint_t c) /*@*/ ;
//_Bool iswcntrl (wint_t c) /*@*/ ;
//_Bool iswctype (wint_t c, wctype_t ctg) /*@*/ ;
//_Bool iswdigit (wint_t c) /*@*/ ;
//_Bool iswgraph (wint_t c) /*@*/ ;
//_Bool iswlower (wint_t c) /*@*/ ;
//_Bool iswprint (wint_t c) /*@*/ ;
//_Bool iswpunct (wint_t c) /*@*/ ;
//_Bool iswspace (wint_t c) /*@*/ ;
//_Bool iswupper (wint_t c) /*@*/ ;
//_Bool iswxdigit (wint_t c) /*@*/ ;
//
//wint_t towctrans (wint_t c, wctrans_t ctg) /*@*/ ;
//wint_t towlower (wint_t c) /*@*/ ;
//wint_t towupper (wint_t c) /*@*/ ;
# else
_Bool /*@alt int@*/ iswalnum (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswalpha (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswcntrl (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswctype (wint_t c, wctype_t ctg) /*@*/ ;
_Bool /*@alt int@*/ iswdigit (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswgraph (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswlower (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswprint (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswpunct (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswspace (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswupper (wint_t c) /*@*/ ;
_Bool /*@alt int@*/ iswxdigit (wint_t c) /*@*/ ;

wint_t /*@alt int@*/ towctrans (wint_t c, wctrans_t ctg)	/*@*/ ;
wint_t /*@alt int@*/ towlower (wint_t c)	/*@*/ ;
wint_t /*@alt int@*/ towupper (wint_t c)	/*@*/ ;
# endif

wctrans_t wctrans (const char *property)	/*@*/ ;
wctype_t wctype (const char *property) /*@*/ ;

int mblen (char *s, size_t n) /*@*/ ;
int mbtowc (/*@null@*/ wchar_t *pwc, /*@null@*/ char *s, size_t n)
   /*@modifies *pwc@*/ ;
int wctomb (/*@out@*/ /*@null@*/ char *s, wchar_t wchar)
   /*@modifies *s@*/ ;
size_t mbstowcs (/*@out@*/ wchar_t *pwcs, char *s, size_t n)
  /*@modifies *pwcs@*/ ;
size_t wcstombs (/*@out@*/ char *s, wchar_t *pwcs, size_t n)
  /*@modifies *s@*/ ;

/*
** string.h
*/

void /*@alt void * @*/
  memcpy (/*@unique@*/ /*@returned@*/ /*@out@*/ void *s1, void *s2, size_t n)
  /*@modifies *s1@*/
     /*@requires maxRead(s2) >= (n - 1) /\ maxSet(s1) >= (n - 1); @*/
     ;

void /*@alt void * @*/
  memmove (/*@returned@*/ /*@out@*/ void *s1, void *s2, size_t n)
  /*@modifies *s1@*/
  /*@requires maxRead(s2) >= (n - 1) /\ maxSet(s1) >= (n - 1); @*/
   ;


  /* drl
     modifed  12/29/2000
  */

void /*@alt char * @*/
  strcpy (/*@unique@*/ /*@out@*/ /*@returned@*/ char *s1, char *s2)
     /*@modifies *s1@*/
     /*@requires maxSet(s1) >= maxRead(s2) @*/
     /*@ensures maxRead(s1) == maxRead (s2) /\ maxRead(result) == maxRead(s2) /\ maxSet(result) == maxSet(s1); @*/;

void /*@alt char * @*/
  strncpy (/*@unique@*/ /*@out@*/ /*@returned@*/ char *s1, char *s2, size_t n)
     /*@modifies *s1@*/
     /*@requires maxSet(s1) >= ( n - 1 ); @*/
     /*@ensures maxRead (s2) >= maxRead(s1) /\ maxRead (s1) <= n; @*/ ;

void /*@alt char * @*/
  strcat (/*@unique@*/ /*@returned@*/ char *s1, char *s2)
     /*@modifies *s1@*/ /*@requires maxSet(s1) >= (maxRead(s1) + maxRead(s2) );@*/
     /*@ensures maxRead(result) == (maxRead(s1) + maxRead(s2) );@*/;

void /*@alt char * @*/
  strncat (/*@unique@*/ /*@returned@*/ char *s1, char *s2, size_t n)
     /*@modifies *s1@*/
     /*@requires maxSet(s1) >= ( maxRead(s1) + n); @*/
      /*@ensures maxRead(s1) >= (maxRead(s1) + n); @*/;

     /*drl end*/

int memcmp (void *s1, void *s2, size_t n) /*@*/ ;
int strcmp (char *s1, char *s2) /*@*/ ;
int strcoll (char *s1, char *s2) /*@*/ ;
int strncmp (char *s1, char *s2, size_t n) /*@*/ ;
size_t strxfrm (/*@out@*/ /*@null@*/ char *s1, char *s2, size_t n)
  /*@modifies *s1@*/ ;  /* s1 may be null only if n == 0 */

/*@null@*/ void *memchr (void *s, int c, size_t n) /*@*/ ;

# ifdef STRICT
/*@exposed@*/ /*@null@*/ char *
strchr (/*@returned@*/ char *s, char c) /*@*/ /*@ensures maxSet(result) >= 0 /\ maxSet(result) <= maxSet(s) /\ maxRead (result) <= maxRead(s) /\ maxRead(result) >= 0 @*/ ;
# else
///*@exposed@*/ /*@null@*/ char *
//  strchr (/*@returned@*/ char *s, int /*@alt char@*/ c) /*@*/ /*@ensures maxSet(result) >= 0 /\ maxSet(result) <= maxSet(s) /\ maxRead (result) <= maxRead(s) /\ maxRead(result) >= 0; @*/ ;
# endif

size_t strcspn (char *s1, char *s2) /*@*/ ;
/*@null@*/ /*@exposed@*/ char *
  strpbrk (/*@returned@*/ char *s, char *t) /*@*/ ;

# ifdef STRICT
/*@null@*/ /*@exposed@*/ char *
  strrchr (/*@returned@*/ char *s, char c) /*@*/  /*@ensures maxSet(result) >= 0 /\ maxSet(result) <= maxSet(s) /\ maxRead (result) <= maxRead(s) /\ maxRead(result) >= 0 @*/ ;
# else
///*@null@*/ /*@exposed@*/ char *
//  strrchr (/*@returned@*/ char *s, int /*@alt char@*/ c) /*@*/  /*@ensures maxSet(result) >= 0 /\ maxSet(result) <= maxSet(s) /\ maxRead (result) <= maxRead(s) /\ maxRead(result) >= 0 @*/ ;
# endif

size_t strspn (char *s, char *t) /*@*/ ;

/*@null@*/ /*@exposed@*/  char *
  strstr (/*@returned@*/ const char *s, const char *t) /*@*/
       /*@ensures maxSet(result) >= 0 /\ maxSet(result) <= maxSet(s) /\ maxRead (result) <= maxRead(s) /\ maxRead(result) >= 0 /\ maxRead(result) >= maxRead(t) /\ maxSet(result) >= maxRead(t)@*/ ;

/*@null@*/ /*@exposed@*/ char *
  strtok (/*@returned@*/ /*@null@*/ char *s, char *t)
  /*@modifies *s, internalState, errno@*/ ;

void /*@alt void *@*/ memset (/*@out@*/ /*@returned@*/ void *s,
				     int c, size_t n)
     /*@modifies *s@*/ /*@requires maxSet(s) >= (n - 1) @*/ /*@ensures maxRead(s) >= (n - 1) @*/ ;

/*@observer@*/ char *strerror (int errnum) /*@*/ ;

/*drl */
size_t strlen (char *s) /*@*/ /*@ensures result == maxRead(s); @*/;

/*
** time.h
*/

/*@constant int CLOCKS_PER_SEC;@*/

//typedef /*@integraltype@*/ clock_t;
//typedef /*@integraltype@*/ time_t;

struct tm
  {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  } ;

clock_t clock (void) /*@modifies internalState@*/ ;
double difftime (time_t time1, time_t time0) /*@*/ ;
time_t mktime (struct tm *timeptr) /*@*/ ;

time_t time (/*@null@*/ /*@out@*/ time_t *tp)
  /*@modifies *tp@*/ ;

/*@observer@*/ char *asctime (struct tm *timeptr)
  /*@modifies errno*/ /*@ensures maxSet(result) == 25 /\  maxRead(result) == 25; @*/ ;

/*@observer@*/ char *ctime (time_t *tp) /*@*/
     /*@ensures maxSet(result) == 25 /\  maxRead(result) == 25; @*/;

/* 2003-11-01: remove null annotation: gmtima and localtime cannot return null */
/*@observer@*/ struct tm *gmtime (time_t *tp) /*@*/ ;

/*@observer@*/ struct tm *localtime (time_t *tp)
  /*@modifies errno@*/ ;

size_t strftime (/*@out@*/ char *s, size_t smax,
			char *fmt, struct tm *timeptr)
  /*@modifies *s@*/ ;

/*
** ISO c99: 7.18 Integer types <stdint.h>
*/

/*
** These types are OPTIONAL.  Provide warnings on use.
*/

//typedef /*@integraltype@*/ int8_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider int_least8_t instead."@*/ ;

//typedef /*@integraltype@*/ int16_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider int_least16_t instead."@*/ ;

//typedef /*@integraltype@*/ int32_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider int_least32_t instead."@*/ ;

//typedef /*@integraltype@*/ int64_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider int_least64_t instead."@*/ ;

//typedef /*@unsignedintegraltype@*/ uint8_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider uint_least8_t instead."@*/ ;

//typedef /*@unsignedintegraltype@*/ uint16_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider uint_least16_t instead."@*/ ;

//typedef /*@unsignedintegraltype@*/ uint32_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider uint_least32_t instead."@*/ ;

//typedef /*@unsignedintegraltype@*/ uint64_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide. Consider uint_least64_t instead."@*/ ;

//typedef /*@integraltype@*/ int_least8_t;
//typedef /*@integraltype@*/ int_least16_t;
//typedef /*@integraltype@*/ int_least32_t;
//typedef /*@integraltype@*/ int_least64_t;

//typedef /*@unsignedintegraltype@*/ uint_least8_t;
//typedef /*@unsignedintegraltype@*/ uint_least16_t;
//typedef /*@unsignedintegraltype@*/ uint_least32_t;
//typedef /*@unsignedintegraltype@*/ uint_least64_t;

//typedef /*@integraltype@*/ int_fast8_t;
//typedef /*@integraltype@*/ int_fast16_t;
//typedef /*@integraltype@*/ int_fast32_t;
//typedef /*@integraltype@*/ int_fast64_t;

//typedef /*@unsignedintegraltype@*/ uint_fast8_t;
//typedef /*@unsignedintegraltype@*/ uint_fast16_t;
//typedef /*@unsignedintegraltype@*/ uint_fast32_t;
//typedef /*@unsignedintegraltype@*/ uint_fast64_t;

/* Corrections to intptr_t and uintptr_t decparations provided by David Sanderson */

//typedef /*@signedintegraltype@*/ intptr_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide."@*/ ;

//typedef /*@unsignedintegraltype@*/ uintptr_t
   /*@warn implementationoptional "ISO99 specifies as optional type, implementation need not provide."@*/ ;

//typedef /*@signedintegraltype@*/ intmax_t;
//typedef /*@unsignedintegraltype@*/ uintmax_t;

/*
** What should the types be here?
*/ /*#*/

/*@constant int INT8_MIN@*/
/*@constant int INT16_MIN@*/
/*@constant int INT32_MIN@*/
/*@constant int INT64_MIN@*/

/*@constant int INT8_MAX@*/
/*@constant int INT16_MAX@*/
/*@constant int INT32_MAX@*/
/*@constant int INT64_MAX@*/

/*@constant int UINT8_MIN@*/
/*@constant int UINT16_MIN@*/
/*@constant int UINT32_MIN@*/
/*@constant int UINT64_MIN@*/

/*@constant int INT_LEAST8_MIN@*/
/*@constant int INT_LEAST16_MIN@*/
/*@constant int INT_LEAST32_MIN@*/
/*@constant int INT_LEAST64_MIN@*/

/*@constant int INT_LEAST8_MAX@*/
/*@constant int INT_LEAST16_MAX@*/
/*@constant int INT_LEAST32_MAX@*/
/*@constant int INT_LEAST64_MAX@*/

/*@constant int UINT_LEAST8_MAX@*/
/*@constant int UINT_LEAST16_MAX@*/
/*@constant int UINT_LEAST32_MAX@*/
/*@constant int UINT_LEAST64_MAX@*/

/*@constant int INT_FAST8_MIN@*/
/*@constant int INT_FAST16_MIN@*/
/*@constant int INT_FAST32_MIN@*/
/*@constant int INT_FAST64_MIN@*/

/*@constant int INT_FAST8_MAX@*/
/*@constant int INT_FAST16_MAX@*/
/*@constant int INT_FAST32_MAX@*/
/*@constant int INT_FAST64_MAX@*/

/*@constant int UINT_FAST8_MAX@*/
/*@constant int UINT_FAST16_MAX@*/
/*@constant int UINT_FAST32_MAX@*/
/*@constant int UINT_FAST64_MAX@*/

/*@constant size_t INTPTR_MIN@*/
/*@constant size_t INTPTR_MAX@*/


// ---------------------------------------------------------------------------
// posix.h
// ---------------------------------------------------------------------------

/*
** posix.h
**
** This file should be processed with one of the standard libraries
** (standard.h or strict.h) to produce posix.lcd or posixstrict.lcd.
*/

/*@-nextlinemacros@*/
/*@+allimponly@*/
/*@+globsimpmodifiesnothing@*/

/*
 * LCLint ISO C + POSIX Library
 *
 * $Id: posix.h,v 1.19 2004/05/21 12:57:21 evans1629 Exp $
 */

/*
 * In 1988, IEEE Std 1003.1-1988, commonly known as "POSIX" or the
 * "IEEE Portable Operating System Interface for Computing Environments"
 * was published as an American National Standard. In 1990, IEEE Std
 * 1003.1-1990 was published as an International Standard. The two
 * standards differ slightly, and where they do, the 1990 International
 * standard was used for this lclint library. The differences are:
 *
 *  1988: cuserid()
 *  1990: -removed- (but still in this lclint library)
 *
 *  1988:     int read (int, void*, unsigned int)
 *  1990: ssize_t read (int, void*, size_t)
 *
 *  1988:     int write (int, const void*, unsigned int)
 *  1990: ssize_t write (int, const void*, size_t)
 *
 * The other differences are in the semantics of functions.
 */

/*
 * The reference for the ISO C part of this library was
 * Plauger, Brodie's "Standard C - A Reference", Prentice Hall.
 * The reference for the POSIX part of this library was
 * Donald Lewine's "POSIX Programmer's Guide", O'Reilly.
 * Transcription by Jens Schweikhardt <schweikhardt@rus.uni-stuttgart.de>
 */

/*
 * Note that Amendment 1 to ISO C was published in 1995 after POSIX was out.
 * Amendment 1 basically adds support for wide characters and iso 646
 * source character sets. In particular, there are three new headers:
 * <iso646.h>, <wchar.h>, and <wctype.h>
 */

/*
 * Each header has annotations in this order:
 *
 *    1) type definitions (if any)
 *    2) constant definitions (if any)
 *    3) structure definitions (if any)
 *    4) function prototypes and externals (if any)
 *
 *    5) type definitions augmented by POSIX (if any)
 *    6) constant definitions augmented by POSIX (if any)
 *    7) structure definitions augmented by POSIX (if any)
 *    8) function prototypes and externals augmented by POSIX (if any)
 *
 * Builtins are mentioned in the header where they appear according to ISO.
 */

/*
** sys/types.h
*/

//typedef /*@integraltype@*/ dev_t;
//typedef /*@integraltype@*/ gid_t;
//typedef /*@unsignedintegraltype@*/ ino_t; /*: is this definitely unsigned? */
//typedef /*@integraltype@*/ mode_t;
//typedef /*@integraltype@*/ nlink_t;
//typedef /*@integraltype@*/ off_t;
//typedef /*@integraltype@*/ pid_t;
//typedef /*@integraltype@*/ uid_t;

/*
** dirent.h
*/

typedef /*@abstract@*/ /*@mutable@*/ void *DIR;

//struct dirent {
//  char	d_name[];
//};

extern int closedir (DIR *dirp)
   /*@modifies errno@*/;

   /*drl 1/4/2001 added the dependent annotation as suggested by
     Ralf Wildenhues */

extern /*@null@*/ /*@dependent@*/ DIR *opendir (const char *dirname)
   /*@modifies errno, fileSystem@*/;

extern /*@dependent@*/ /*@null@*/ struct dirent *readdir (DIR *dirp)
   /*@modifies errno@*/;

extern void rewinddir (DIR *dirp)
   /*@*/;

/*
** errno.h
*/

/*@constant int E2BIG@*/
#define E2BIG 0
/*@constant int EACCES@*/
#define EACCES 0
/*@constant int EAGAIN@*/
#define EAGAIN 0
/*@constant int EBADF@*/
#define EBADF 0
/*@constant int EBUSY@*/
#define EBUSY 0
/*@constant int ECHILD@*/
#define ECHILD 0
/*@constant int EDEADLK@*/
#define EDEADLK 0
/*@constant int EEXIST@*/
#define EEXIST 0
/*@constant int EFAULT@*/
#define EFAULT 0
/*@constant int EFBIG@*/
#define EFBIG 0
/*@constant int EINTR@*/
#define EINTR 0
/*@constant int EINVAL@*/
#define EINVAL 0
/*@constant int EIO@*/
#define EIO 0
/*@constant int EISDIR@*/
#define EISDIR 0
/*@constant int EMFILE@*/
#define EMFILE 0
/*@constant int EMLINK@*/
#define EMLINK 0
/*@constant int ENAMETOOLONG@*/
#define ENAMETOOLONG 0
/*@constant int ENFILE@*/
#define ENFILE 0
/*@constant int ENODEV@*/
#define ENODEV 0
/*@constant int ENOENT@*/
#define ENOENT 0
/*@constant int ENOEXEC@*/
#define ENOEXEC 0
/*@constant int ENOLCK@*/
#define ENOLCK 0
/*@constant int ENOMEM@*/
#define ENOMEM 0
/*@constant int ENOSPC@*/
#define ENOSPC 0
/*@constant int ENOSYS@*/
#define ENOSYS 0
/*@constant int ENOTDIR@*/
#define ENOTDIR 0
/*@constant int ENOTEMPTY@*/
#define ENOTEMPTY 0
/*@constant int ENOTTY@*/
#define ENOTTY 0
/*@constant int ENXIO@*/
#define ENXIO 0
/*@constant int EPERM@*/
#define EPERM 0
/*@constant int EPIPE@*/
#define EPIPE 0
/*@constant int EROFS@*/
#define EROFS 0
/*@constant int ESPIPE@*/
#define ESPIPE 0
/*@constant int ESRCH@*/
#define ESRCH 0
/*@constant int EXDEV@*/
#define EXDEV 0

/*
** fcntl.h
*/

/*@constant int FD_CLOEXEC@*/
/*@constant int F_DUPFD@*/
/*@constant int F_GETFD@*/
/*@constant int F_GETFL@*/
/*@constant int F_GETLK@*/
/*@constant int F_RDLCK@*/
/*@constant int F_SETFD@*/
/*@constant int F_SETFL@*/
/*@constant int F_SETLK@*/
/*@constant int F_SETLKW@*/
/*@constant int F_UNLCK@*/
/*@constant int F_WRLCK@*/
/*@constant int O_ACCMODE@*/
/*@constant int O_APPEND@*/
#define O_APPEND 0
/*@constant int O_CREAT@*/
#define O_CREAT 0
/*@constant int O_EXCL@*/
/*@constant int O_NOCTTY@*/
/*@constant int O_NONBLOCK@*/

/*@constant int O_RDONLY@*/
#define O_RDONLY 2
/*@constant int O_RDWR@*/
#define O_RDWR 2
/*@constant int O_TRUNC@*/
#define O_TRUNC 2
/*@constant int O_WRONLY@*/
#define O_WRONLY 2

//pad: dup
/*@constant int SEEK_CUR@*/
/*@constant int SEEK_END@*/
/*@constant int SEEK_SET@*/

/*@constant mode_t S_IFMT@*/
/*@constant mode_t S_IFBLK@*/
/*@constant mode_t S_IFCHR@*/
/*@constant mode_t S_IFIFO@*/
/*@constant mode_t S_IFREG@*/
/*@constant mode_t S_IFDIR@*/
/*@constant mode_t S_IFLNK@*/

/*@constant mode_t S_IRWXU@*/
/*@constant mode_t S_IRUSR@*/

/*@constant mode_t S_IRGRP@*/
/*@constant mode_t S_IROTH@*/
/*@constant mode_t S_IUSR@*/
/*@constant mode_t S_IWXG@*/
/*@constant mode_t S_IWXO@*/
/*@constant mode_t S_IWXU@*/
/*@constant mode_t S_ISGID@*/
/*@constant mode_t S_ISUID@*/
/*@constant mode_t S_IWGRP@*/
/*@constant mode_t S_IWOTH@*/
/*@constant mode_t S_IWUSR@*/
/*@constant mode_t S_IXGRP@*/
/*@constant mode_t S_IXOTH@*/
/*@constant mode_t S_IXUSR@*/

struct flock {
  short l_type;
  short l_whence;
  off_t l_start;
  off_t l_len;
  pid_t l_pid;
};

extern int creat (const char *path, mode_t mode)
   /*@modifies errno@*/;

extern int fcntl (int fd, int cmd, ...)
   /*@modifies errno@*/;

extern int open (const char *path, int oflag, ...)
  /*:checkerror -1 - returns -1 on error */
     /* the ... is one mode_t param */
  /*@modifies errno@*/ ;

/*
** grp.h
*/

struct group {
  char *gr_name;
  gid_t gr_gid;
  char **gr_mem;
};

/* evans 2002-07-09: added observer annotation (reported by Enrico Scholz). */

/*@observer@*/ /*@null@*/ struct group * getgrgid (gid_t gid)
   /*@modifies errno@*/;

/*@observer@*/ /*@null@*/ struct group *getgrnam (const char *nm)
   /*@modifies errno@*/;

/*
** limits.h
*/

/* These are always defined: */

/*@constant int CHAR_BIT@*/
/*@constant char CHAR_MIN@*/
/*@constant char CHAR_MAX@*/
/*@constant int INT_MIN@*/
/*@constant int INT_MAX@*/
/*@constant long LONG_MIN@*/
/*@constant long LONG_MAX@*/
/*@constant int MB_LEN_MAX@*/
/*@constant signed char SCHAR_MIN@*/
/*@constant signed char SCHAR_MAX@*/
/*@constant short SHRT_MIN@*/
/*@constant short SHRT_MAX@*/
/*@constant unsigned char UCHAR_MAX@*/
/*@constant unsigned int UINT_MAX@*/
/*@constant unsigned long ULONG_MAX@*/
/*@constant unsigned short USHRT_MAX@*/

/* When _POSIX_SOURCE is defined */

/*@constant long ARG_MAX@*/
/*@constant long CHILD_MAX@*/
/*@constant long LINK_MAX@*/
/*@constant long MAX_CANON@*/
/*@constant size_t MAX_INPUT@*/ /* evans 2001-10-15 changed type to size_t from long */
/*@constant size_t NAME_MAX@*/ /* evans 2001-10-15 changed type to size_t from long */
/*@constant long NGROUPS_MAX@*/
/*@constant long OPEN_MAX@*/
/*@constant size_t PATH_MAX@*/ /* evans 2001-10-15 changed type to size_t from long */
/*@constant size_t PIPE_BUF@*/ /* evans 2001-10-15 changed type to size_t from long */
/*@constant long SSIZE_MAX@*/
/*@constant long STREAM_MAX@*/
/*@constant long TZNAME_MAX@*/
/*@constant long _POSIX_ARG_MAX@*/
/*@constant long _POSIX_CHILD_MAX@*/
/*@constant long _POSIX_LINK_MAX@*/
/*@constant long _POSIX_MAX_CANON@*/
/*@constant long _POSIX_MAX_INPUT@*/
/*@constant long _POSIX_NAME_MAX@*/
/*@constant long _POSIX_NGROUPS_MAX@*/
/*@constant long _POSIX_OPEN_MAX@*/
/*@constant long _POSIX_PATH_MAX@*/
/*@constant long _POSIX_PIPE_BUF@*/
/*@constant long _POSIX_SSIZE@*/
/*@constant long _POSIX_STREAM@*/
/*@constant long _POSIX_TZNAME_MAX@*/

/*
** pwd.h
*/

struct passwd {
  char *pw_name;
  uid_t pw_uid;
  gid_t pw_gid;
  char *pw_dir;
  char *pw_shell;
} ;

/*@observer@*/ /*@null@*/ struct passwd *getpwnam (const char *)
   /*@modifies errno@*/  /*@ensures maxRead(result) == 0 /\ maxSet(result) == 0 @*/;

/*@observer@*/ /*@null@*/ struct passwd *getpwuid (uid_t uid)
   /*@modifies errno@*/  /*@ensures maxRead(result) == 0 /\ maxSet(result) == 0 @*/;

/*
** setjmp.h
*/

typedef /*@abstract@*/ /*@mutable@*/ void *sigjmp_buf;

/*@mayexit@*/ void siglongjmp (sigjmp_buf env, int val)	/*@*/;

int sigsetjmp (/*@out@*/ sigjmp_buf env, int savemask) /*@modifies env@*/;

/*
** moved up from signal.h
*/

//typedef /*@abstract@*/ sigset_t;

typedef struct {
  void *ss_sp;
  size_t ss_size;
  int ss_flags;
} stack_t;

/*
** ucontext.h
*/

//typedef /*@abstract@*/ mcontext_t;

typedef struct s_ucontext_t {
  /*@null@*/ struct s_ucontext_t *uc_link;
  sigset_t uc_sigmask;
  stack_t uc_stack;
  mcontext_t uc_mcontext;
} ucontext_t;

int  getcontext(ucontext_t *);
int  setcontext(const ucontext_t *);
void makecontext(ucontext_t *, void (*)(void), int, ...);
int  swapcontext(ucontext_t *restrict, const ucontext_t *restrict);

/*
** signal.h
*/

/*@constant int SA_NOCLDSTOP@*/
/*@constant int SIG_BLOCK@*/
/*@constant int SIG_SETMASK@*/
/*@constant int SIG_UNBLOCK@*/

/*@constant int SIGALRM@*/
#define SIGALRM 0
/*@constant int SIGCHLD@*/
#define SIGCHLD 0
/*@constant int SIGCONT@*/
#define SIGCONT 0
/*@constant int SIGHUP@*/
#define SIGHUP 0
/*@constant int SIGKILL@*/
#define SIGKILL 0
/*@constant int SIGPIPE@*/
#define SIGPIPE 0
/*@constant int SIGQUIT@*/
#define SIGQUIT 0
/*@constant int SIGSTOP@*/
#define SIGSTOP 0
/*@constant int SIGTSTP@*/
#define SIGTSTP 0
/*@constant int SIGTTIN@*/
#define SIGTTIN 0
/*@constant int SIGTTOU@*/
#define SIGTTOU 0
/*@constant int SIGUSR1@*/
#define SIGUSR1 0
/*@constant int SIGUSR2@*/
#define SIGUSR2 0

struct sigstack {
  int ss_onstack;
  void *ss_sp;
} ;

typedef struct {
  int si_signo;
  int si_errno;
  int si_code;
  pid_t si_pid;
  uid_t si_uid;
  void *si_addr;
  int si_status;
  long si_band;
  union sigval si_value;
} siginfo_t;

typedef union {
  int    sival_int;
  void  *sival_ptr;
} sigval;

struct sigaction {
  void (*sa_handler)();
  sigset_t sa_mask;
  int sa_flags;
  void (*sa_sigaction)(int, siginfo_t *, void *); /* Added 2003-06-13: Noticed by Jerry James */
} ;

	extern /*@mayexit@*/ int
kill (pid_t pid, int sig)
	/*@modifies errno@*/;

	extern int
sigaction (int sig, const struct sigaction *act, /*@out@*/ /*@null@*/ struct sigaction *oact)
	/*@modifies *oact, errno, systemState@*/;

	extern int
sigaddset (sigset_t *set, int signo)
	/*@modifies *set, errno@*/;

	extern int
sigdelset (sigset_t *set, int signo)
	/*@modifies *set, errno@*/;

	extern int
sigemptyset (/*@out@*/ sigset_t *set)
	/*@modifies *set, errno@*/;

	extern int
sigfillset (/*@out@*/ sigset_t *set)
	/*@modifies *set, errno@*/;

	extern int
sigismember (const sigset_t *set, int signo)
	/*@modifies errno@*/;

	extern int
sigpending (/*@out@*/ sigset_t *set)
	/*@modifies *set, errno@*/;

	extern int
sigprocmask (int how, /*@null@*/ const sigset_t *set, /*@null@*/ /*@out@*/ sigset_t *oset)
	/*@modifies *oset, errno, systemState@*/;

	extern int
sigsuspend (const sigset_t *sigmask)
	/*@modifies errno, systemState@*/;

/*
** stdio.h
*/

/*@constant int L_ctermid@*/
/*@constant int L_cuserid@*/
/*@constant int STREAM_MAX@*/

extern /*@null@*/ /*@dependent@*/ FILE *fdopen (int fd, const char *type)
   /*@modifies errno, fileSystem@*/;

extern int fileno (FILE *fp) /*@modifies errno@*/;

/*
** sys/stat.h
*/

struct stat {
  mode_t st_mode;
  ino_t	st_ino;
  dev_t	st_dev;
  nlink_t st_nlink;
  uid_t	st_uid;
  gid_t	st_gid;
  off_t	st_size;
  time_t st_atime; /* evans 2001-08-23 - these were previously st_st_atime - POSIX spec says st_atime */
  time_t st_mtime; /* evans 2001-08-23 - these were previously st_st_mtime - POSIX spec says st_mtime */
  time_t st_ctime; /* evans 2001-08-23 - these were previously st_st_ctime - POSIX spec says st_ctime */
} ;
/*
** evans 2004-05-19: dependent annotations atted for time_t fields.  Could not find
** any clear documetation on this, but it seems to be correct.
*/

/*
** POSIX does not require that the S_I* be functions. They're
** macros virtually everywhere.
*/

# ifdef STRICT
/*@notfunction@*/
//# define SBOOLINT _Bool /*@alt int@*/
# else
/*@notfunction@*/
//# define SBOOLINT _Bool
# endif

//extern SBOOLINT S_ISBLK (/*@sef@*/ mode_t m) /*@*/ ;
//
//extern SBOOLINT S_ISCHR (/*@sef@*/ mode_t m) /*@*/ ;
//
//extern SBOOLINT S_ISDIR (/*@sef@*/ mode_t m) /*@*/ ;
//
//extern SBOOLINT S_ISFIFO (/*@sef@*/ mode_t m) /*@*/ ;
//
//extern SBOOLINT S_ISREG (/*@sef@*/ mode_t m) /*@*/ ;

int chmod (const char *path, mode_t mode)
     /*@modifies fileSystem, errno@*/ ;

int fstat (int fd, /*@out@*/ struct stat *buf)
     /*@modifies errno, *buf@*/ ;

int mkdir (const char *path, mode_t mode)
     /*@modifies fileSystem, errno@*/;

int mkfifo (const char *path, mode_t mode)
     /*@modifies fileSystem, errno@*/;

int stat (const char *path, /*@out@*/ struct stat *buf)
     /*:errorcode -1*/
     /*@modifies errno, *buf@*/;

int umask (mode_t cmask)
     /*@modifies systemState@*/;

/*
** sys/times.h
*/

struct tms {
  clock_t	tms_utime;
  clock_t	tms_stime;
  clock_t	tms_cutime;
  clock_t	tms_cstime;
};

	extern clock_t
times (/*@out@*/ struct tms *tp)
	/*@modifies *tp@*/;

/*
** sys/utsname.h
*/

struct utsname {
  char	sysname[];
  char	nodename[];
  char	release[];
  char	version[];
  char	machine[];
};

	extern int
uname (/*@out@*/ struct utsname *name)
     /*@modifies *name, errno@*/ ;

/*
** sys/wait.h
*/

extern int WEXITSTATUS (int status) /*@*/ ;
extern int WIFEXITED (int status) /*@*/ ;
extern int WIFSIGNALED (int status) /*@*/ ;
extern int WIFSTOPPED (int status) /*@*/ ;
extern int WSTOPSIG (int status) /*@*/ ;
extern int WTERMSIG (int status) /*@*/ ;

/*@constant int WUNTRACED@*/

/* These are in Unix spec, are they in POSIX? */
/*@constant int WCONTINUED@*/
/*@constant int WNOHANG@*/

pid_t wait (/*@out@*/ /*@null@*/ int *st)
   /*@modifies *st, errno, systemState@*/;

pid_t waitpid (pid_t pid, /*@out@*/ /*@null@*/ int *st, int opt)
   /*@modifies *st, errno, systemState@*/;

/*
** termios.h
*/

typedef unsigned char /*@alt unsigned short@*/ cc_t;
typedef unsigned long /*@alt long@*/ speed_t;
typedef unsigned long /*@alt long@*/ tcflag_t;

/*@constant int B0@*/
/*@constant int B50@*/
/*@constant int B75@*/
/*@constant int B110@*/
/*@constant int B134@*/
/*@constant int B150@*/
/*@constant int B200@*/
/*@constant int B300@*/
/*@constant int B600@*/
/*@constant int B1200@*/
/*@constant int B1800@*/
/*@constant int B2400@*/
/*@constant int B4800@*/
/*@constant int B9600@*/
/*@constant int B19200@*/
/*@constant int B38400@*/
/*@constant int BRKINT@*/
/*@constant int CLOCAL@*/
/*@constant int CREAD@*/
/*@constant int CS5@*/
/*@constant int CS6@*/
/*@constant int CS7@*/
/*@constant int CS8@*/
/*@constant int CSIZE@*/
/*@constant int CSTOPB@*/
/*@constant int ECHO@*/
/*@constant int ECHOE@*/
/*@constant int ECHOK@*/
/*@constant int ECHONL@*/
/*@constant int HUPCL@*/
/*@constant int ICANON@*/
/*@constant int ICRNL@*/
/*@constant int IEXTEN@*/
/*@constant int IGNBRK@*/
/*@constant int IGNCR@*/
/*@constant int IGNPAR@*/
/*@constant int IGNLCR@*/
/*@constant int INPCK@*/
/*@constant int ISIG@*/
/*@constant int ISTRIP@*/
/*@constant int IXOFF@*/
/*@constant int IXON@*/
/*@constant int NCCS@*/
/*@constant int NOFLSH@*/
/*@constant int OPOST@*/
/*@constant int PARENB@*/
/*@constant int PARMRK@*/
/*@constant int PARODD@*/
/*@constant int TCIFLUSH@*/
/*@constant int TCIOFF@*/
/*@constant int TCIOFLUSH@*/
/*@constant int TCION@*/
/*@constant int TCOFLUSH@*/
/*@constant int TCSADRAIN@*/
/*@constant int TCSAFLUSH@*/
/*@constant int TCSANOW@*/
/*@constant int TOSTOP@*/
/*@constant int VEOF@*/
/*@constant int VEOL@*/
/*@constant int VERASE@*/
/*@constant int VINTR@*/
/*@constant int VKILL@*/
/*@constant int VMIN@*/
/*@constant int VQUIT@*/
/*@constant int VSTART@*/
/*@constant int VSTOP@*/
/*@constant int VSUSP@*/
/*@constant int VTIME@*/

struct termios {
  tcflag_t	c_iflag;
  tcflag_t	c_oflag;
  tcflag_t	c_cflag;
  tcflag_t	c_lflag;
  cc_t		c_cc;
} ;

	extern speed_t
cfgetispeed (const struct termios *p)
	/*@*/;

	extern speed_t
cfgetospeed (const struct termios *p)
	/*@*/;

	extern int
cfsetispeed (struct termios *p)
	/*@modifies *p@*/;

	extern int
cfsetospeed (struct termios *p)
	/*@modifies *p@*/;

	extern int
tcdrain (int fd)
	/*@modifies errno@*/;

	extern int
tcflow (int fd, int action)
	/*@modifies errno@*/;

	extern int
tcflush (int fd, int qs)
	/*@modifies errno@*/;

	extern int
tcgetattr (int fd, /*@out@*/ struct termios *p)
	/*@modifies errno, *p@*/;

	extern int
tcsendbreak (int fd, int d)
	/*@modifies errno@*/;

	extern int
tcsetattr (int fd, int opt, const struct termios *p)
	/*@modifies errno@*/;

/*
** time.h
*/

/* Environ must be known before it can be used in `globals' clauses. */

/*@unchecked@*/ extern char **environ;

/*@constant int CLK_TCK@*/

	extern void
tzset (void)
	/*@globals environ@*/ /*@modifies systemState@*/;

/*
** unistd.h
*/

/*@constant int F_OK@*/
/*@constant int R_OK@*/
#define R_OK 0
/*@constant int W_OK@*/
/*@constant int X_OK@*/


/*@constant int SEEK_CUR@*/
/*@constant int SEEK_END@*/
/*@constant int SEEK_SET@*/
/*@constant int STDERR_FILENO@*/
/*@constant int STDIN_FILENO@*/
/*@constant int STDOUT_FILENO@*/
/*@constant int _PC_CHOWN_RESTRUCTED@*/
/*@constant int _PC_MAX_CANON@*/
/*@constant int _PC_MAX_INPUT@*/
/*@constant int _PC_NAME_MAX@*/
/*@constant int _PC_NO_TRUNC@*/
/*@constant int _PC_PATH_MAX@*/
/*@constant int _PC_PIPE_BUF@*/
/*@constant int _PC_VDISABLE@*/
/*@constant int _POSIX_CHOWN_RESTRICTED@*/
/*@constant int _POSIX_JOB_CONTROL@*/
/*@constant int _POSIX_NO_TRUNC@*/
/*@constant int _POSIX_SAVED_IDS@*/
/*@constant int _POSIX_VDISABLE@*/
/*@constant int _POSIX_VERSION@*/
/*@constant int _SC_ARG_MAX@*/
/*@constant int _SC_CHILD_MAX@*/
/*@constant int _SC_CLK_TCK@*/
/*@constant int _SC_JOB_CONTROL@*/
/*@constant int _SC_NGROUPS_MAX@*/
/*@constant int _SC_OPEN_MAX@*/
/*@constant int _SC_SAVED_IDS@*/
/*@constant int _SC_STREAM_MAX@*/
/*@constant int _SC_TZNAME_MAX@*/
/*@constant int _SC_VERSION@*/

extern /*@exits@*/ void _exit (int status) /*@*/;

extern int access (const char *path, int mode) /*@modifies errno@*/;

extern unsigned int alarm (unsigned int) /*@modifies systemState@*/;

extern int chdir (const char *path) /*@modifies errno@*/;

extern int chown (const char *path, uid_t owner, gid_t group)
     /*@modifies fileSystem, errno@*/;

	extern int
close (int fd)
	/*@modifies fileSystem, errno, systemState@*/;
	/* state: record locks are unlocked */

	extern char *
ctermid (/*@returned@*/ /*@out@*/ /*@null@*/ char *s)
	/*@modifies *s, systemState@*/;

	/* cuserid is in the 1988 version of POSIX but removed in 1990 */
	extern char *
cuserid (/*@null@*/ /*@out@*/ char *s)
	/*@modifies *s@*/;

	extern int
dup2 (int fd, int fd2)
	/*@modifies errno, fileSystem@*/;

	extern int
dup (int fd)
	/*@modifies errno, fileSystem@*/;

	extern /*@mayexit@*/ int
execl (const char *path, const char *arg, ...)
	/*@modifies errno@*/;

	extern /*@mayexit@*/ int
execle (const char *file, const char *arg, ...)
	/*@modifies errno@*/;

	extern /*@mayexit@*/ int
execlp (const char *file, const char *arg, ...)
	/*@modifies errno@*/;

	extern /*@mayexit@*/ int
execv (const char *path, char *const argv[])
	/*@modifies errno@*/;

	extern /*@mayexit@*/ int
execve (const char *path, char *const argv[], char *const *envp)
	/*@modifies errno@*/;

	extern /*@mayexit@*/ int
execvp (const char *file, char *const argv[])
	/*@modifies errno@*/;

	extern pid_t
fork (void)
	/*@modifies fileSystem, errno@*/;

	extern long
fpathconf (int fd, int name)
	/*@modifies errno@*/;

extern /*@null@*/ char *getcwd (/*@returned@*/ /*@out@*/ /*@notnull@*/ char *buf, size_t size)
     /*@requires maxSet(buf) >= (size - 1)@*/
     /*@ensures  maxRead(buf) <= (size - 1)@*/

     /*@modifies errno, *buf@*/ ;

	extern gid_t
getegid (void)
	/*@*/;

	extern uid_t
geteuid (void)
	/*@*/;

	extern gid_t
getgid (void)
	/*@*/;

	extern int
getgroups (int gs, /*@out@*/ gid_t gl[])
	/*@modifies errno, gl[]@*/;

	extern /*@observer@*/ char *
getlogin (void)
	/*@*/;

	extern pid_t
getpgrp (void)
	/*@*/;

	extern pid_t
getpid (void)
	/*@*/;

	extern pid_t
getppid (void)
	/*@*/;

	extern uid_t
getuid (void)
	/*@*/;

	extern int
isatty (int fd)
	/*@*/;

	extern int
link (const char *o, const char *n)
	/*@modifies errno, fileSystem@*/;

	extern off_t
lseek (int fd, off_t offset, int whence)
	/*@modifies errno@*/;

	extern long
pathconf (const char *path, int name)
	/*@modifies errno@*/;

	extern int
pause (void)
	/*@modifies errno@*/;

	extern int
pipe (/*@out@*/ int fd[]) /* Out parameter noticed by Marc Espie. */
	/*@modifies errno@*/;

extern ssize_t read (int fd, /*@out@*/ void *buf, size_t nbyte)
   /*@modifies errno, *buf@*/
   /*@requires maxSet(buf) >= (nbyte - 1) @*/
   /*@ensures maxRead(buf) >= nbyte @*/ ;

extern int rmdir (const char *path)
   /*@modifies fileSystem, errno@*/;

extern int setgid (gid_t gid)
   /*@modifies errno, systemState@*/;

extern int setpgid (pid_t pid, pid_t pgid)
   /*@modifies errno, systemState@*/;

extern pid_t setsid (void) /*@modifies systemState@*/;

extern int setuid (uid_t uid)
   /*@modifies errno, systemState@*/;

unsigned int sleep (unsigned int sec) /*@modifies systemState@*/ ;

extern long sysconf (int name)
   /*@modifies errno@*/;

extern pid_t tcgetpgrp (int fd)
   /*@modifies errno@*/;

extern int tcsetpgrp (int fd, pid_t pgrpid)
   /*@modifies errno, systemState@*/;

/* Q: observer ok? */
extern /*@null@*/ /*@observer@*/ char *ttyname (int fd)
   /*@modifies errno@*/;

extern int unlink (const char *path)
   /*@modifies fileSystem, errno@*/;

extern ssize_t write (int fd, const void *buf, size_t nbyte)
     /*@requires maxRead(buf) >= nbyte@*/
     /*@modifies errno@*/;

/*
** utime.h
*/

struct utimbuf {
  time_t	actime;
  time_t	modtime;
} ;

	extern int
utime (const char *path, /*@null@*/ const struct utimbuf *times)
	/*@modifies fileSystem, errno@*/;

/*
** regex.h
*/

typedef /*@abstract@*/ /*@mutable@*/ void *regex_t;
//typedef /*@integraltype@*/ regoff_t;

typedef struct
{
  regoff_t rm_so;
  regoff_t rm_eo;
} regmatch_t;

int regcomp (/*@out@*/ regex_t *preg, /*@nullterminated@*/ const char *regex, int cflags)
   /*:statusreturn@*/
   /*@modifies preg@*/ ;

int regexec (const regex_t *preg, /*@nullterminated@*/ const char *string, size_t nmatch, /*@out@*/ regmatch_t pmatch[], int eflags)
   /*@requires maxSet(pmatch) >= nmatch@*/
   /*@modifies pmatch@*/ ;

size_t regerror (int errcode, const regex_t *preg, /*@out@*/ char *errbuf, size_t errbuf_size)
   /*@requires maxSet(errbuf) >= errbuf_size@*/
   /*@modifies errbuf@*/ ;

void regfree (/*@only@*/ regex_t *preg) ;

/* regcomp flags */
/*@constant int	REG_BASIC@*/
/*@constant int	REG_EXTENDED@*/
/*@constant int	REG_ICASE@*/
/*@constant int	REG_NOSUB@*/
/*@constant int	REG_NEWLINE@*/
/*@constant int	REG_NOSPEC@*/
/*@constant int	REG_PEND@*/
/*@constant int	REG_DUMP@*/

/* regerror flags */
/*@constant int	REG_NOMATCH@*/
/*@constant int	REG_BADPAT@*/
/*@constant int	REG_ECOLLATE@*/
/*@constant int	REG_ECTYPE@*/
/*@constant int	REG_EESCAPE@*/
/*@constant int	REG_ESUBREG@*/
/*@constant int	REG_EBRACK@*/
/*@constant int	REG_EPAREN@*/
/*@constant int	REG_EBRACE@*/
/*@constant int	REG_BADBR@*/
/*@constant int	REG_ERANGE@*/
/*@constant int	REG_ESPACE@*/
/*@constant int	REG_BADRPT@*/
/*@constant int	REG_EMPTY@*/
/*@constant int	REG_ASSERT@*/
/*@constant int	REG_INVARG@*/
/*@constant int	REG_ATOI@*/ /* non standard */
/*@constant int	REG_ITOA@*/ /* non standard */

/* regexec flags */
/*@constant int	REG_NOTBOL@*/
/*@constant int	REG_NOTEOL@*/
/*@constant int	REG_STARTEND@*/
/*@constant int	REG_TRACE@*/
/*@constant int	REG_LARGE@*/
/*@constant int	REG_BACKR@*/





// ---------------------------------------------------------------------------
// unix.h
// ---------------------------------------------------------------------------

/*
** unix.h
*/

/*@-nextlinemacros@*/

/*
** sys/types.h
**
** evans - 2001-08-27: from http://www.opengroup.org/onlinepubs/007908799/xsh/systypes.h.html
*/

//typedef /*@integraltype@*/ blkcnt_t;
//typedef /*@integraltype@*/ blksize_t;
//
///*@-redef@*/ /* These are also defined by ansi.h: */
//typedef /*@integraltype@*/ clock_t;
//typedef /*@integraltype@*/ dev_t;
//typedef /*@integraltype@*/ gid_t;
//typedef /*@unsignedintegraltype@*/ ino_t;
//typedef /*@integraltype@*/ mode_t;
//typedef /*@integraltype@*/ nlink_t;
//typedef /*@integraltype@*/ off_t;
//typedef /*@integraltype@*/ pid_t;
//typedef /*@integraltype@*/ time_t;
//typedef /*@integraltype@*/ uid_t;
//
///*@=redef@*/
//
//typedef /*@integraltype@*/ clockid_t;
//typedef /*@unsignedintegraltype@*/ fsblkcnt_t;
//typedef /*@unsignedintegraltype@*/ fsfilcnt_t;
//typedef /*@integraltype@*/ id_t;
//
//typedef /*@integraltype@*/ key_t;
//typedef /*@integraltype@*/ pthread_attr_t;
//typedef /*@integraltype@*/ pthread_cond_t;
//typedef /*@integraltype@*/ pthread_condattr_t;
//typedef /*@integraltype@*/ pthread_key_t;
//typedef /*@integraltype@*/ pthread_mutex_t;
//typedef /*@integraltype@*/ pthread_mutexattr_t;
//typedef /*@integraltype@*/ pthread_once_t;
//typedef /*@integraltype@*/ pthread_rwlock_t;
//typedef /*@integraltype@*/ pthread_rwlockattr_t;
//typedef /*@integraltype@*/ pthread_t;
//typedef /*@signedintegraltype@*/ suseconds_t;
//typedef /*@integraltype@*/ timer_t;
//typedef /*@unsignedintegraltype@*/ useconds_t;

/*
** Extra stuff in some unixen, not in posix.
*/

extern /*@unchecked@*/ int signgam;

/*@-redef@*/ /* Defined by ansi: */
//typedef /*@integraltype@*/ clockid_t;
/*@=redef@*/

extern void bcopy (char *b1, /*@out@*/ char *b2, int length)
   /*@modifies *b2@*/ ;  /* Yes, the second parameter is the out param! */

extern int /*@alt _Bool@*/ bcmp (char *b1, char *b2, int length) /*@*/ ;
   /* Return value is NOT like strcmp! */

extern void bzero (/*@out@*/ char *b1, int length) /*@modifies *b1@*/ ;
extern int ffs (int i) /*@*/ ;
extern int symlink (char *name1, char *name2) /*@modifies fileSystem@*/ ;

extern int
  setvbuf_unlocked (FILE *stream, /*@null@*/ /*@exposed@*/ char *buf,
		    int mode, size_t size)
  /*@modifies internalState@*/ ;

extern void
  setbuffer (FILE *stream, /*@null@*/ /*@exposed@*/ char *buf, int size)
  /*@modifies internalState@*/ ;

extern void setlinebuf (FILE *stream) /*@modifies internalState@*/ ;

extern int strerror_r (int errnum, /*@out@*/ char *strerrbuf, int buflen)
  /*@modifies strerrbuf@*/ ;

extern size_t
  fread_unlocked (/*@out@*/ void *ptr, size_t size, size_t nitems,
		  FILE *stream)
  /*@modifies *stream, *ptr;@*/ ;

extern size_t
  fwrite_unlocked (void *pointer, size_t size, size_t num_items, FILE *stream)
  /*@modifies *stream;@*/ ;

extern void /*@alt void * @*/
  memccpy (/*@returned@*/ /*@out@*/ void *s1,
	   /*@unique@*/ void *s2, int c, size_t n)
  /*@modifies *s1@*/ ;

extern int strcasecmp (char *s1, char *s2) /*@*/ ;
extern int strncasecmp (char *s1, char *s2, int n) /*@*/ ;
extern /*@null@*/ /*@only@*/ char *strdup (char *s) /*@*/ ;

extern /*@null@*/ /*@dependent@*/ char *
  index (/*@returned@*/ char *s, char c) /*@*/ ;

extern /*@null@*/ /*@dependent@*/ char *
  rindex (/*@returned@*/ char *s, char c) /*@*/ ;

//# if 0
//These are in ISO C99.  Moved to standard.h:
//   extern double cbrt (double x) /*@modifies errno@*/ ;
//   extern double rint (double x) /*@*/ ;
//   extern double trunc (double x) /*@*/ ;
//# endif


/*@constant int ENOTBLK@*/
/*@constant int ETXTBSY@*/
/*@constant int EWOULDBLOCK@*/
/*@constant int EINPROGRESS@*/
/*@constant int EALREADY@*/
/*@constant int ENOTSOCK@*/
/*@constant int EDESTADDRREQ@*/
/*@constant int EMSGSIZE@*/
/*@constant int EPROTOTYPE@*/
/*@constant int ENOPROTOOPT@*/
/*@constant int EPROTONOSUPPORT@*/
/*@constant int ESOCKTNOSUPPORT@*/
/*@constant int EOPNOTSUPP@*/
/*@constant int EPFNOSUPPORT@*/
/*@constant int EAFNOSUPPORT@*/
/*@constant int EADDRINUSE@*/
/*@constant int EADDRNOTAVAIL@*/
/*@constant int ENETDOWN@*/
/*@constant int ENETUNREACH@*/
/*@constant int ENETRESET@*/
/*@constant int ECONNABORTED@*/
/*@constant int ECONNRESET@*/
/*@constant int ENOBUFS@*/
/*@constant int EISCONN@*/
/*@constant int ENOTCONN@*/
/*@constant int ESHUTDOWN@*/
/*@constant int ETOOMANYREFS@*/
/*@constant int ETIMEDOUT@*/
/*@constant int ECONNREFUSED@*/
/*@constant int ENAMETOOLONG@*/
/*@constant int EHOSTDOWN@*/
/*@constant int EHOSTUNREACH@*/
/*@constant int ENOTEMPTY@*/
/*@constant int EPROCLIM@*/
/*@constant int EUSERS@*/
/*@constant int EDQUOT@*/
/*@constant int ESTALE@*/
/*@constant int EREMOTE@*/
/*@constant int ENOMSG@*/
/*@constant int EIDRM@*/
/*@constant int EALIGN@*/
/*@constant int EDEADLK@*/
/*@constant int ENOLCK@*/
/*@constant int ENOSYS@*/
/*@constant int EACTIVE@*/
/*@constant int ENOACTIVE@*/
/*@constant int ENORESOURCES@*/
/*@constant int ENOSYSTEM@*/
/*@constant int ENODUST@*/
/*@constant int EDUPNOCONN@*/
/*@constant int EDUPNODISCONN@*/
/*@constant int EDUPNOTCNTD@*/
/*@constant int EDUPNOTIDLE@*/
/*@constant int EDUPNOTWAIT@*/
/*@constant int EDUPNOTRUN@*/
/*@constant int EDUPBADOPCODE@*/
/*@constant int EDUPINTRANSIT@*/
/*@constant int EDUPTOOMANYCPUS@*/
/*@constant int ELOOP@*/

/*@constant int LOCK_MAX@*/
/*@constant int FCHR_MAX@*/
/*@constant int USI_MAX@*/
/*@constant int WORD_BIT@*/
/*@constant int LONG_BIT@*/

/*@-incondefs@*/ /* some constant are also declared in posix.h*/

/*@constant long NAME_MAX@*/

/*@constant long NGROUPS_MAX@*/

/*@constant long MAX_CANON@*/
/*@constant int MAX_CHAR@*/
/*@constant long OPEN_MAX@*/
/*@constant int PASS_MAX@*/

/*@constant int PID_MAX@*/
/*@constant int SYSPID_MAX@*/
/*@constant long PIPE_BUF@*/
/*@=incondefs@*/
/*@constant int PIPE_MAX@*/
/*@constant int PROC_MAX@*/
/*@constant int STD_BLK@*/
/*@constant int SYS_NMLN@*/
/*@constant int SYS_OPEN@*/
/*@constant int NZERO@*/
/*@constant int UID_MAX@*/
/*@constant long MB_LEN_MAX@*/
/*@constant int NL_ARGMAX@*/
/*@constant int NL_MSGMAX@*/
/*@constant int NL_NMAX@*/
/*@constant int NL_SETMAX@*/
/*@constant int NL_TEXTMAX@*/
/*@constant int NL_LBLMAX@*/
/*@constant int NL_LANGMAX @*/

/*@constant double M_E@*/
/*@constant double M_LOG2E@*/
/*@constant double M_LOG10E@*/
/*@constant double M_LN2@*/
/*@constant double M_LN10@*/
/*@constant double M_PI@*/
/*@constant double M_PI_2@*/
/*@constant double M_PI_4@*/
/*@constant double M_1_PI@*/
/*@constant double M_2_PI@*/
/*@constant double M_2_SQRTPI@*/
/*@constant double M_SQRT2@*/
/*@constant double M_SQRT1_2@*/

/*@constant double MAXFLOAT@*/
/*@constant double HUGE@*/

/*@constant int DOMAIN@*/
/*@constant int SING@*/
/*@constant int OVERFLOW@*/
/*@constant int UNDERFLOW@*/
/*@constant int TLOSS@*/
/*@constant int PLOSS@*/

extern /*@unchecked@*/ int daylight;
extern /*@unchecked@*/ long timezone;
extern /*@unchecked@*/ char *tzname[];

/*@-incondefs@*/
//extern void tzset(void) /*@modifies daylight, timezone, tzname@*/ ;
/*@=incondefs@*/

/*@-redef@*/ /* Defined by ansi: */
//typedef /*@integraltype@*/ key_t;
/*@-incondefs@*/ typedef long timer_t; /*@=incondefs@*/
/*@=redef@*/

typedef	unsigned char uchar_t;
typedef	unsigned short ushort_t;
typedef	unsigned int uint_t;
typedef unsigned long ulong_t;
typedef	volatile unsigned char vuchar_t;
typedef	volatile unsigned short	vushort_t;
typedef	volatile unsigned int vuint_t;
typedef volatile unsigned long vulong_t;
typedef long label_t;
typedef int level_t;
//typedef	/*@integraltype@*/ daddr_t;
typedef	char *caddr_t;
typedef long *qaddr_t;
typedef char *addr_t;
typedef long physadr_t;
typedef short cnt_t;
typedef	int chan_t;
typedef	int paddr_t;
typedef	void *mid_t;
typedef char slab_t[12];
typedef ulong_t	shmatt_t;
typedef ulong_t	msgqnum_t;
typedef ulong_t	msglen_t;
typedef	uchar_t uchar;
typedef	ushort_t ushort;
typedef	uint_t uint;
typedef ulong_t	ulong;
typedef	uchar_t	u_char;
typedef	ushort_t u_short;
typedef	uint_t u_int;
typedef	ulong_t	u_long;
typedef	vuchar_t vu_char;
typedef	vushort_t vu_short;
typedef	vuint_t	vu_int;
typedef	vulong_t vu_long;
typedef	long swblk_t;
typedef u_long fixpt_t;
typedef long segsz_t;
//typedef /*@abstract@*/ fd_set;

int ioctl (int d, int /*@alt long@*/ request, /*@out@*/ void *arg)
   /*@modifies *arg, errno@*/ ;  /* depends on request! */

pid_t vfork (void) /*@modifies fileSystem@*/ ;

/*
** sys/uio.h
*/

struct iovec {
  /*@dependent@*/ void *iov_base;
  size_t iov_len; /*: maxSet(iov_base) = iov_len */
};

/* from limits.h */
/*@constant int UIO_MAXIOV@*/   /* BSD */
/*@constant int IOV_MAX@*/      /* supposedly SVR4 */

ssize_t readv (int fd, const struct iovec *iov, int iovcnt)
     /*@modifies iov->iov_base, fileSystem, errno@*/;

ssize_t writev (int fd, const struct iovec *iov, int iovcnt)
     /*@modifies errno@*/;

/*________________________________________________________________________
 * poll.h
 */

 struct poll {
	int fd;
	short events;
	short revents;
};

/*@constant short POLLIN@*/
/*@constant short POLLRDNORM@*/
/*@constant short POLLRDBAND@*/
/*@constant short POLLPRI@*/
/*@constant short POLLOUT@*/
/*@constant short POLLWRNORM@*/
/*@constant short POLLWRBAND@*/
/*@constant short POLLERR@*/
/*@constant short POLLHUP@*/
/*@constant short POLLNVAL@*/

extern int poll (struct poll pollfd[], unsigned long nfds, int timeout)
  /*@modifies pollfd[].revents, errno@*/ ;

/*
** free does not take null
*/

/*@-incondefs@*/
//extern void free (/*@notnull@*/ /*@out@*/ /*@only@*/ void *p) /*@modifies *p@*/ ;
/*@=incondefs@*/

/*________________________________________________________________________
 * sys/socket.h
 */




/*@constant int SOCK_RDM@*/







/*@constant int SO_USELOOPBACK@*/


/*@constant int SO_REUSEPORT@*/










/*@constant int AF_LOCAL@*/


/*@constant int AF_IMPLINK@*/
/*@constant int AF_PUP@*/
/*@constant int AF_CHAOS@*/
/*@constant int AF_NS@*/
/*@constant int AF_ISO@*/
/*@constant int AF_OSI@*/
/*@constant int AF_ECMA@*/
/*@constant int AF_DATAKIT@*/
/*@constant int AF_CCITT@*/
/*@constant int AF_SNA@*/
/*@constant int AF_DECnet@*/
/*@constant int AF_DLI@*/
/*@constant int AF_LAT@*/
/*@constant int AF_HYLINK@*/
/*@constant int AF_APPLETALK@*/
/*@constant int AF_ROUTE@*/
/*@constant int AF_LINK@*/
/*@constant int pseudo_AF_XTP@*/
/*@constant int AF_COIP@*/
/*@constant int AF_CNT@*/
/*@constant int pseudo_AF_RTIP@*/
/*@constant int AF_IPX@*/
/*@constant int AF_SIP@*/
/*@constant int pseudo_AF_PIP@*/
/*@constant int AF_ISDN@*/
/*@constant int AF_E164@*/
/*@constant int AF_MAX@*/






/*@constant int MSG_DONTWAIT@*/
/*@constant int MSG_EOF@*/
/*@constant int MSG_COMPAT@*/
/*@constant int PF_UNSPEC@*/
/*@constant int PF_LOCAL@*/
/*@constant int PF_UNIX@*/
#define PF_UNIX 0
/*@constant int PF_INET@*/
#define PF_INET 0
/*@constant int PF_IMPLINK@*/
/*@constant int PF_PUP@*/
/*@constant int PF_CHAOS@*/
/*@constant int PF_NS@*/
/*@constant int PF_ISO@*/
/*@constant int PF_OSI@*/
/*@constant int PF_ECMA@*/
/*@constant int PF_DATAKIT@*/
/*@constant int PF_CCITT@*/
/*@constant int PF_SNA@*/
/*@constant int PF_DECnet@*/
/*@constant int PF_DLI@*/
/*@constant int PF_LAT@*/
/*@constant int PF_HYLINK@*/
/*@constant int PF_APPLETALK@*/
/*@constant int PF_ROUTE@*/
/*@constant int PF_LINK@*/
/*@constant int PF_XTP@*/
/*@constant int PF_COIP@*/
/*@constant int PF_CNT@*/
/*@constant int PF_SIP@*/
/*@constant int PF_IPX@*/
/*@constant int PF_RTIP@*/
/*@constant int PF_PIP@*/
/*@constant int PF_ISDN@*/
/*@constant int PF_MAX@*/
/*@constant int NET_MAXID@*/
/*@constant int NET_RT_DUMP@*/
/*@constant int NET_RT_FLAGS@*/
/*@constant int NET_RT_IFLIST@*/
/*@constant int NET_RT_MAXID@*/

/*moved this to before socket.h to get splint to parse the header*/
//typedef /*@unsignedintegraltype@*/ sa_family_t;

/*
** sys/socket.h
** (updated 26 May 2002)
*/

//typedef /*@unsignedintegraltype@*/ __socklen_t; /* not in USB, but needed by linux */
//typedef /*@unsignedintegraltype@*/ socklen_t;

struct sockaddr {
  sa_family_t	sa_family;		/* address family */
  char          sa_data[];		/* variable length */
};

struct sockaddr_storage {
  sa_family_t ss_family;
} ;

struct msghdr {
  /*@dependent@*/ void *msg_name;
  socklen_t msg_namelen;	/*: maxSet (msg_name) >= msg_namelen */
  /*@dependent@*/ struct iovec *msg_iov;	/* scatter/gather array */
  int msg_iovlen;		/* # elements in msg_iov */ /*: maxSet (msg_iov) >= msg_iovlen */
  /*@dependent@*/ void *msg_control;		/* ancillary data, see below */
  socklen_t msg_controllen;     /*: maxSet (msg_control) >= msg_controllen */
  int msg_flags;		/* flags on received message */
} ;

struct cmsghdr {
  socklen_t cmsg_len;		/* data byte count, including hdr */
  int cmsg_level;		/* originating protocol */
  int cmsg_type;		/* protocol-specific type */
} ;

/*@constant int SCM_RIGHTS@*/

/*@exposed@*/ unsigned char *CMSG_DATA (/*@sef@*/ struct cmsghdr *) /*@*/ ;
/*@null@*/ /*@exposed@*/ struct cmsghdr *CMSG_NXTHDR (struct msghdr *, struct cmsghdr *) /*@*/ ;
/*@null@*/ /*@exposed@*/ struct cmsghdr *CMSG_FIRSTHDR (struct msghdr *) /*@*/ ;

struct linger {
  int l_onoff;
  int l_linger;
};

/*@constant int SOCK_DGRAM@*/
#define SOCK_DGRAM 0
/*@constant int SOCK_RAW@*/
/*@constant int SOCK_SEQPACKET@*/
/*@constant int SOCK_STREAM@*/

/*@constant int SOL_SOCKET@*/

/*@constant int SO_ACCEPTCONN@*/
/*@constant int SO_BROADCAST@*/
/*@constant int SO_DEBUG@*/
/*@constant int SO_DONTROUTE@*/
/*@constant int SO_ERROR@*/
/*@constant int SO_KEEPALIVE@*/
/*@constant int SO_LINGER@*/
/*@constant int SO_OOBINLINE@*/
/*@constant int SO_RCVBUF@*/
/*@constant int SO_RCVLOWAT@*/
/*@constant int SO_RCVTIMEO@*/
/*@constant int SO_REUSEADDR@*/
/*@constant int SO_SNDBUF@*/
/*@constant int SO_SNDLOWAT@*/
/*@constant int SO_SNDTIMEO@*/
/*@constant int SO_TYPE@*/

/*@constant int SOMAXCONN@*/

/*@constant int MSG_CTRUNC@*/
/*@constant int MSG_DONTROUTE@*/
/*@constant int MSG_EOR@*/
/*@constant int MSG_OOB@*/
/*@constant int MSG_PEEK@*/
/*@constant int MSG_TRUNC@*/
/*@constant int MSG_WAITALL@*/

/*@constant int AF_INET@*/
#define AF_INET 0
/*@constant int AF_INET6@*/
/*@constant int AF_UNIX@*/
#define AF_UNIX 0
/*@constant int AF_UNSPEC@*/

/*@constant int SHUT_RD@*/
/*@constant int SHUT_RDWR@*/
/*@constant int SHUT_WR@*/

# if 0
/*
** These were in the old unix.h spec, but are not in SUS6
*/

struct sockproto {
  u_short	sp_family;		/* address family */
  u_short	sp_protocol;		/* protocol */
};

# endif

int accept (int s, struct sockaddr *addr, int *addrlen)
  /*@modifies *addrlen, errno@*/;

int bind (int s, const struct sockaddr *name, int namelen)
  /*@modifies errno, fileSystem@*/;

int connect (int s, const struct sockaddr *name, int namelen)
  /*@modifies errno, internalState@*/;

int getpeername (int s, /*@out@*/ struct sockaddr */*restrict*/ name, socklen_t */*restrict*/ namelen)
  /*drl splint doesn't handle restrict yet*/
   /*@modifies *name, *namelen, errno@*/;

#ifdef STRICT

int getsockname (int s, /*@out@*/ struct sockaddr *address, socklen_t *address_len)
     /*@i556@*/  /*: can't do this? requires maxSet(address) >= (*address_len) @*/
  /*@modifies *address, *address_len, errno@*/;

#else
//int getsockname (int s, /*@out@*/ struct sockaddr *address, socklen_t  /*@alt size_t@*/ *address_len)
  /*@i556@*/  /*: can't do this? requires maxSet(address) >= (*address_len) @*/
  /*@modifies *address, *address_len, errno@*/;

#endif

int getsockopt (int s, int level, int optname, /*@out@*/ void *optval, size_t *optlen)
	/*@modifies *optval, *optlen, errno@*/;

	extern int
listen (int s, int backlog)
	/*@modifies errno, internalState@*/;

	extern ssize_t
recv (int s, /*@out@*/ void *buf, size_t len, int flags)
	/*@modifies *buf, errno@*/;

	extern ssize_t
recvfrom (int s, void *buf, size_t len, int flags, /*@null@*/ struct sockaddr *from, int *fromlen)
	/*@modifies *buf, *from, *fromlen, errno@*/;

	extern ssize_t
recvmsg (int s, struct msghdr *msg, int flags)
	/*@modifies msg->msg_iov->iov_base[], errno@*/;

	extern ssize_t
send (int s, const void *msg, size_t len, int flags)
	/*@modifies errno@*/;

	extern ssize_t
sendto (int s, const void *msg, size_t len, int flags, const struct sockaddr *to, int tolen)
	/*@modifies errno@*/;

	extern ssize_t
sendmsg (int s, const struct msghdr *msg, int flags)
	/*@modifies errno@*/;

	extern int
setsockopt (int s, int level, int optname, const void *optval, int optlen)
	/*@modifies internalState, errno@*/;

	extern int
shutdown (int s, int how)
	/*@modifies errno@*/;

	extern int
socket (int domain, int type, int protocol)
	/*@modifies errno@*/;

	extern int
socketpair (int d, int type, int protocol, /*@out@*/ int *sv)
	/*@modifies errno@*/;

/*@constant int BADSIG@*/
/*@constant int SA_ONSTACK@*/
/*@constant int SA_RESTART@*/
/*@constant int SA_DISABLE@*/
/*@constant int SIGBUS@*/
/*@constant int SIGEMT@*/
/*@constant int SIGINFO@*/
/*@constant int SIGIO@*/
/*@constant int SIGIOT@*/
/*@constant int SIGPOLL@*/
/*@constant int SIGPROF@*/
/*@constant int SIGPWR@*/
/*@constant int SIGSYS@*/
/*@constant int SIGTRAP@*/
/*@constant int SIGURG@*/
/*@constant int SIGVTALRM@*/
/*@constant int SIGWINCH@*/
/*@constant int SIGXCPU@*/
/*@constant int SIGXFSZ@*/

extern void psignal (int sig, const char *msg)
   /*@modifies fileSystem@*/;

	extern int
setenv (const char *name, const char *value, int overwrite)
	/*@globals environ@*/
	/*@modifies *environ, errno@*/;

	extern void
unsetenv (const char *name)
	/*@globals environ@*/
	/*@modifies *environ@*/;

/*________________________________________________________________________
 * sys/wait.h
 */

	extern int
WCOREDUMP (int x)
	/*@*/;

	extern int
W_EXITCODE (int ret, int sig)
	/*@*/;

	extern int
W_STOPCODE (int sig)
	/*@*/;

/*@constant int WAIT_ANY@*/
/*@constant int WAIT_MYPGRP@*/
/*@constant int WSTOPPED@*/

	extern pid_t
wait3 (int *statloc, int options, /*@null@*/ /*@out@*/ struct rusage *rusage)
	/*@modifies *statloc, *rusage, errno@*/;

	extern pid_t
wait4 (pid_t p, int *statloc, int opt, /*@null@*/ /*@out@*/ struct rusage *r)
	/*@modifies *statloc, *r, errno@*/;

struct timeval {
  long	tv_sec;
  long	tv_usec;
} ;

struct timespec {
  long	ts_sec;
  long	ts_nsec;
} ;

struct timezone {
  int	tz_minuteswest;
  int	tz_dsttime;
} ;

/*@constant int DST_NONE@*/
/*@constant int DST_USA@*/
/*@constant int DST_AUST@*/
/*@constant int DST_WET@*/
/*@constant int DST_MET@*/
/*@constant int DST_EET@*/
/*@constant int DST_CAN@*/

/*@constant int ITIMER_PROF@*/
/*@constant int ITIMER_REAL@*/
/*@constant int ITIMER_VIRTUAL@*/

 struct itimerval {
	struct	timeval it_interval;
	struct	timeval it_value;
};

 struct clockinfo {
	int	hz;
	int	tick;
	int	stathz;
	int	profhz;
};

	extern int
adjtime (const struct timeval *delta, /*@null@*/ /*@out@*/ struct timeval *olddelta)
	/*@modifies internalState, *olddelta, errno@*/;

	extern int
getitimer (int which, /*@out@*/ struct itimerval *value)
	/*@modifies errno, *value*/;

	extern int
gettimeofday (/*@null@*/ /*@out@*/ struct timeval *tp, /*@null@*/ /*@out@*/ struct timezone *tzp)
	/*@modifies *tp, *tzp, errno@*/;

	extern int
setitimer (int which, struct itimerval *val, /*@null@*/ /*@out@*/ struct itimerval *oval)
	/*@modifies *oval, errno, internalState*/;

	extern int
settimeofday (const struct timeval *t, const struct timezone *z)
	/*@modifies internalState, errno@*/;

	extern int
utimes (const char *file, /*@null@*/ const struct timeval *times)
	/*@modifies fileSystem, errno*/;

/*________________________________________________________________________
 * sys/mman.h
 */

//pad:
#define PROT_NONE 4

/*@constant int PROT_READ@*/
#define PROT_READ 1
/*@constant int PROT_WRITE@*/
#define PROT_WRITE 2
/*@constant int PROT_EXEC@*/
#define PROT_EXEC 3

/*@constant int MAP_SHARED@*/
#define MAP_SHARED 0
/*@constant int MAP_PRIVATE@*/
#define MAP_PRIVATE 0
/*@constant int MAP_COPY@*/
#define MAP_COPY 0
/*@constant int MAP_FIXED@*/
/*@constant int MAP_RENAME@*/
/*@constant int MAP_NORESERVE@*/
/*@constant int MAP_INHERIT@*/
/*@constant int MAP_NOEXTEND@*/
/*@constant int MAP_HASSEMAPHORE@*/
/*@constant int MS_ASYNC@*/
/*@constant int MS_INVALIDATE@*/
/*@constant int MAP_FILE@*/
/*@constant int MAP_ANON@*/
#define MAP_ANON 0
/*@constant int MADV_NORMAL@*/
/*@constant int MADV_RANDOM@*/
/*@constant int MADV_SEQUENTIAL@*/
/*@constant int MADV_WILLNEED@*/
/*@constant int MADV_DONTNEED@*/

#define MAP_FAILED 0
#define MAP_ANONYMOUS 0


	extern caddr_t
mmap (/*@null@*/ /*@returned@*/ caddr_t addr, size_t len, int prot, int flags, int fd, off_t offset)
	/*@modifies addr@*/;

	extern int
madvise (caddr_t addr, int len, int behav)
	/*@*/;

	extern int
mprotect (caddr_t addr, int len, int prot)
	/*@*/;

	extern int
	munmap (/*@only@*/ caddr_t addr, size_t len)
     /*@modifies fileSystem, *addr, errno @*/;

	extern int
msync (caddr_t addr, int len, int flags)
	/*@*/;

	extern int
mlock (caddr_t addr, size_t len)
	/*@*/;

	extern int
munlock (caddr_t addr, size_t len)
	/*@*/;


/*________________________________________________________________________
 * sys/ioctl.h
 */

 struct winsize {
	unsigned short	ws_row;
	unsigned short	ws_col;
	unsigned short	ws_xpixel;
	unsigned short	ws_ypixel;
};

/*@constant int TIOCMODG@*/
/*@constant int TIOCMODS@*/
/*@constant int TIOCM_LE@*/
/*@constant int TIOCM_DTR@*/
/*@constant int TIOCM_RTS@*/
/*@constant int TIOCM_ST@*/
/*@constant int TIOCM_SR@*/
/*@constant int TIOCM_CTS@*/
/*@constant int TIOCM_CAR@*/
/*@constant int TIOCM_CD@*/
/*@constant int TIOCM_RNG@*/
/*@constant int TIOCM_RI@*/
/*@constant int TIOCM_DSR@*/
/*@constant int TIOCEXCL@*/
/*@constant int TIOCNXCL@*/
/*@constant int TIOCFLUSH@*/
/*@constant int TIOCGETA@*/
/*@constant int TIOCSETA@*/
/*@constant int TIOCSETAW@*/
/*@constant int TIOCSETAF@*/
/*@constant int TIOCGETD@*/
/*@constant int TIOCSETD@*/
/*@constant int TIOCSBRK@*/
/*@constant int TIOCCBRK@*/
/*@constant int TIOCSDTR@*/
/*@constant int TIOCCDTR@*/
/*@constant int TIOCGPGRP@*/
/*@constant int TIOCSPGRP@*/
/*@constant int TIOCOUTQ@*/
/*@constant int TIOCSTI@*/
/*@constant int TIOCNOTTY@*/
/*@constant int TIOCPKT@*/
/*@constant int TIOCPKT_DATA@*/
/*@constant int TIOCPKT_FLUSHREAD@*/
/*@constant int TIOCPKT_FLUSHWRITE@*/
/*@constant int TIOCPKT_STOP@*/
/*@constant int TIOCPKT_START@*/
/*@constant int TIOCPKT_NOSTOP@*/
/*@constant int TIOCPKT_DOSTOP@*/
/*@constant int TIOCPKT_IOCTL@*/
/*@constant int TIOCSTOP@*/
/*@constant int TIOCSTART@*/
/*@constant int TIOCMSET@*/
/*@constant int TIOCMBIS@*/
/*@constant int TIOCMBIC@*/
/*@constant int TIOCMGET@*/
/*@constant int TIOCREMOTE@*/
/*@constant int TIOCGWINSZ@*/
/*@constant int TIOCSWINSZ@*/
/*@constant int TIOCUCNTL@*/
/*@constant int TIOCSTAT@*/
/*@constant int TIOCCONS@*/
/*@constant int TIOCSCTTY@*/
/*@constant int TIOCEXT@*/
/*@constant int TIOCSIG@*/
/*@constant int TIOCDRAIN@*/
/*@constant int TIOCMSDTRWAIT@*/
/*@constant int TIOCMGDTRWAIT@*/
/*@constant int TIOCTIMESTAMP@*/
/*@constant int TIOCSDRAINWAIT@*/
/*@constant int TIOCGDRAINWAIT@*/
/*@constant int TTYDISC@*/
/*@constant int TABLDISC@*/
/*@constant int SLIPDISC@*/
/*@constant int PPPDISC@*/

/*@constant int MAXHOSTNAMELEN@*/

extern void FD_CLR (/*@sef@*/ int n, /*@sef@*/ fd_set *p) /*@modifies *p@*/ ;
extern void FD_COPY (/*@sef@*/ fd_set *f, /*@out@*/ fd_set *t) /*@modifies *t@*/ ;
extern int /*@alt _Bool@*/ FD_ISSET (/*@sef@*/ int n, /*@sef@*/ fd_set *p) /*@*/ ;
extern void FD_SET (/*@sef@*/ int n, /*@sef@*/ fd_set *p) /*@modifies *p@*/ ;
extern void FD_ZERO (/*@sef@*/ fd_set /*@out@*/ *p) /*@modifies *p@*/;

extern int fchdir (int fd) /*@modifies internalState, errno@*/;
extern int fchown (int fd, uid_t owner, gid_t group) /*@modifies errno, fileSystem@*/;
extern int fsync (int fd) /*@modifies errno, fileSystem@*/;

extern int ftruncate (int fd, off_t length) /*@modifies errno, fileSystem@*/;

int gethostname (/*@out@*/ char *address, size_t address_len)
   /*:errorstatus@*/
   /*@modifies address@*/ ;

int initgroups (const char *name, int basegid)
   /*@modifies internalState@*/;

int lchown (const char *path, uid_t owner, gid_t group)
     /*@modifies errno, fileSystem@*/;

int select (int mfd, fd_set /*@null@*/ *r, fd_set /*@null@*/ *w,
	    fd_set /*@null@*/ *e, /*@null@*/ struct timeval *t)
  /*@modifies *r, *w, *e, *t, errno@*/;
  /* evans - 2002-05-26: added null for t, bug reported by Enrico Scholz */

int setegid (gid_t egid)
  /*@modifies errno, internalState@*/;

int seteuid (uid_t euid)
   /*@modifies errno, internalState@*/;

int setgroups (int ngroups, const gid_t *gidset)
   /*@modifies errno, internalState@*/;

int setregid (gid_t rgid, gid_t egid)
   /*@modifies errno, internalState@*/;

int setreuid (gid_t ruid, gid_t euid)
   /*@modifies errno, internalState@*/;

void sync (void)
   /*@modifies fileSystem@*/;

//int symlink (const char *path, const char *path2)
//   /*@modifies fileSystem@*/;

int truncate (const char *name, off_t length)
   /*@modifies errno, fileSystem@*/;

/*@constant int EBADRPC@*/
/*@constant int ERPCMISMATCH@*/
/*@constant int EPROGUNAVAIL@*/
/*@constant int EPROGMISMATCH@*/
/*@constant int EPROCUNAVAIL@*/
/*@constant int EFTYPE@*/
/*@constant int EAUTH@*/
/*@constant int ENEEDAUTH@*/
/*@constant int ELAST@*/

/*
** tar.h
*/

/*@unchecked@*/ extern char *TMAGIC;
/*@constant int TMAGLEN@*/
/*@unchecked@*/ extern char *TVERSION;
/*@constant int TVERSLEN@*/

/*@constant int REGTYPE@*/
/*@constant int AREGTYPE@*/
/*@constant int LNKTYPE@*/
/*@constant int SYMTYPE@*/
/*@constant int CHRTYPE@*/
/*@constant int BLKTYPE@*/
/*@constant int DIRTYPE@*/
/*@constant int FIFOTYPE@*/
/*@constant int CONTTYPE@*/

/*@constant int TSUID@*/
/*@constant int TSGID@*/
/*@constant int TSVTX@*/

/*@constant int TUREAD@*/
/*@constant int TUWRITE@*/
/*@constant int TUEXEC@*/
/*@constant int TGREAD@*/
/*@constant int TGWRITE@*/
/*@constant int TGEXEC@*/
/*@constant int TOREAD@*/
/*@constant int TOWRITE@*/
/*@constant int TOEXEC@*/

struct ipc_perm {
  uid_t	uid;	/* user id */
  gid_t	gid;	/* group id */
  uid_t	cuid;	/* creator user id */
  gid_t	cgid;	/* creator group id */
  mode_t	mode;	/* r/w permission */
  ulong	seq;	/* slot usage sequence number */
  key_t	key;	/* user specified msg/sem/shm key */
} ;

/*@constant int	IPC_R@*/
/*@constant int	IPC_W@*/
/*@constant int	IPC_M@*/
/*@constant int	IPC_CREAT@*/
/*@constant int	IPC_EXCL@*/
/*@constant int	IPC_NOWAIT@*/
/*@constant key_t IPC_PRIVATE@*/
/*@constant int IPC_RMID@*/
/*@constant int IPC_SET@*/
/*@constant int IPC_STAT@*/

/*
** sys/msg.h
*/

 struct msqid_ds {
	struct	ipc_perm msg_perm;	/* msg queue permission bits */
	struct	msg *msg_first;	/* first message in the queue */
	struct	msg *msg_last;	/* last message in the queue */
	u_long	msg_cbytes;	/* number of bytes in use on the queue */
	u_long	msg_qnum;	/* number of msgs in the queue */
	u_long	msg_qbytes;	/* max # of bytes on the queue */
	pid_t	msg_lspid;	/* pid of last msgsnd() */
	pid_t	msg_lrpid;	/* pid of last msgrcv() */
	time_t	msg_stime;	/* time of last msgsnd() */
	time_t	msg_rtime;	/* time of last msgrcv() */
	time_t	msg_ctime;	/* time of last msgctl() */
};

 struct mymesg {
	long	mtype;		/* message type (+ve integer) */
	char	mtext[];	/* message body */
};

/*@constant int MSG_NOERROR@*/
/*@constant int MSGMAX@*/
/*@constant int MSGMNB@*/
/*@constant int MSGMNI@*/
/*@constant int MSGTQL@*/

	extern int
msgctl (int id , int cmd, /*@out@*/ struct msqid_ds *buf)
	/*@modifies errno, *buf@*/;

	extern int
msgget (key_t key, int flag)
	/*@modifies errno@*/;

	extern int
msgrcv (int id, /*@out@*/ void *ptr, size_t nbytes, long type, int flags)
	/*@modifies errno, *ptr@*/;

	extern int
msgsnd (int id, const void *ptr, size_t nbytes, int flag)
	/*@modifies errno@*/;

/*
** sys/sem.h
*/

 struct semid_ds {
	struct ipc_perm sem_perm;
	struct sem     *sem_base;
	ushort          sem_nsems;
	time_t          sem_otime;
	time_t          sem_ctime;
};

 struct sem {
	ushort semval;
	pid_t  sempid;
	ushort semncnt;
	ushort semzcnt;
};

 union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
};

 struct sembuf {
	ushort sem_num;
	short sem_op;
	short sem_flg;
};

/*@constant int SEM_A@*/
/*@constant int SEMAEM@*/
/*@constant int SEMMNI@*/
/*@constant int SEMMNS@*/
/*@constant int SEMMNU@*/
/*@constant int SEMMSL@*/
/*@constant int SEMOPN@*/
/*@constant int SEM_R@*/
/*@constant int SEMUME@*/
/*@constant int SEM_UNDO@*/
/*@constant int SEMVMX@*/
/*@constant int GETVAL@*/
/*@constant int SETVAL@*/
/*@constant int GETPID@*/
/*@constant int GETNCNT@*/
/*@constant int GETZCNT@*/
/*@constant int GETALL@*/
/*@constant int SETALL@*/

/*@constant int ERMID@*/

	extern int
semctl (int id, int semnum, int cmd, union semun arg)
	/*@modifies errno@*/;

	extern int
semget (key_t key, int nsems, int flag)
	/*@modifies errno@*/;

	extern int
semop (int id, struct sembuf *semoparray, size_t nops)
	/*@modifies errno@*/;

/*
** sys/shm.h
*/

 struct shmid_ds {
	struct ipc_perm shm_perm;
	int shm_segsz;
	ushort shm_lkcnt;
	pid_t shm_lpid;
	pid_t shm_cpid;
	ulong shm_nattch;
	ulong shm_cnattch;
	time_t shm_atime;
	time_t shm_dtime;
	time_t shm_ctime;
};

/*@constant int SHMLBA@*/
/*@constant int SHM_LOCK@*/
/*@constant int SHMMAX@*/
/*@constant int SHMMIN@*/
/*@constant int SHMMNI@*/
/*@constant int SHM_R@*/
/*@constant int SHM_RDONLY@*/
/*@constant int SHM_RND@*/
/*@constant int SHMSEG@*/
/*@constant int SHM_W@*/
/*@constant int SHM_UNLOCK@*/

void * shmat (int id, /*@null@*/ void *addr, int flag)
     /*@modifies errno@*/ ;

extern int shmctl (int id, int cmd, /*@out@*/ struct shmid_ds *buf)
     /*@modifies errno, *buf@*/ ;

extern int shmdt (void *addr)
     /*@modifies errno@*/ ;

extern int shmget (key_t key, int size, int flag)
     /*@modifies errno@*/ ;


/*
** stdio.h - in separte file stdio.h
*/

/*
** syslog.h
*/

/*@constant int LOG_EMERG@*/
/*@constant int LOG_ALERT@*/
/*@constant int LOG_CRIT@*/
/*@constant int LOG_ERR@*/
/*@constant int LOG_WARNING@*/
/*@constant int LOG_NOTICE@*/
/*@constant int LOG_INFO@*/
/*@constant int LOG_DEBUG@*/

/*@constant int LOG_KERN@*/
/*@constant int LOG_USER@*/
/*@constant int LOG_MAIL@*/
/*@constant int LOG_DAEMON@*/
/*@constant int LOG_AUTH@*/
/*@constant int LOG_SYSLOG@*/
/*@constant int LOG_LPR@*/
/*@constant int LOG_NEWS@*/
/*@constant int LOG_UUCP@*/
/*@constant int LOG_CRON@*/
/*@constant int LOG_AUTHPRIV@*/
/*@constant int LOG_FTP@*/
/*@constant int LOG_LOCAL0@*/
/*@constant int LOG_LOCAL1@*/
/*@constant int LOG_LOCAL2@*/
/*@constant int LOG_LOCAL3@*/
/*@constant int LOG_LOCAL4@*/
/*@constant int LOG_LOCAL5@*/
/*@constant int LOG_LOCAL6@*/
/*@constant int LOG_LOCAL7@*/

/*@constant int LOG_PID@*/
/*@constant int LOG_CONS@*/
/*@constant int LOG_ODELAY@*/
/*@constant int LOG_NDELAY@*/
/*@constant int LOG_NOWAIT@*/
/*@constant int LOG_PERROR@*/

int LOG_MASK (int pri)
     /*@*/;

int LOG_UPTO (int pri)
     /*@*/;

void closelog (void)
     /*@modifies fileSystem@*/;

void openlog (const char *ident, int logopt, int facility)
     /*@modifies fileSystem@*/;

int setlogmask (int maskpri)
     /*@modifies internalState@*/;

void /*@printflike@*/ syslog (int priority, const char *message, ...)
     /*@modifies fileSystem@*/;

void vsyslog (int priority, const char *message, va_list args)
     /*@modifies fileSystem@*/;

/*________________________________________________________________________
 * pwd.h
 */

 extern void
endpwent (void)
	/*@modifies internalState@*/;

	extern /*@null@*/ struct passwd *
getpwent (void)
	/*@modifies internalState@*/;

	extern int
setpassent (int stayopen)
	/*@modifies internalState@*/;

	extern int
setpwent (void)
	/*@modifies internalState@*/;

/*
** grp.h
*/

void endgrent (void) /*@modifies internalState@*/;

/*@null@*/ /*@observer@*/ struct group *getgrent (void)
   /*@modifies internalState@*/;

int setgrent (void) /*@modifies internalState@*/;

void setgrfile (const char *name) /*@modifies internalState@*/;

int setgroupent (int stayopen) /*@modifies internalState@*/;

/*
** sys/stat.h
**
** evans 2001-08-26 - updated from http://www.opengroup.org/onlinepubs/007908799/xsh/sysstat.h.html
*/

/*
** struct stat replaces POSIX version - more required fields in Unix
*/

/*@-redef@*/ /*@-matchfields@*/
//struct stat {
//  dev_t     st_dev; /* ID of device containing file */
//  ino_t     st_ino; /* file serial number */
//  mode_t    st_mode; /* mode of file (see below) */
//  nlink_t   st_nlink; /* number of links to the file */
//  uid_t     st_uid; /* user ID of file */
//  gid_t     st_gid; /* group ID of file */
//  dev_t     st_rdev; /* device ID (if file is character or block special) */
//  off_t     st_size; /* file size in bytes (if file is a regular file) */
//  time_t    st_atime; /* time of last access */
//  time_t    st_mtime; /* time of last data modification */
//  time_t    st_ctime; /* time of last status change */
//  blksize_t st_blksize; /* a filesystem-specific preferred I/O block size for
//			   this object.  In some filesystem types, this may
//			   vary from file to file */
//  blkcnt_t  st_blocks; /*  number of blocks allocated for this object */
//} ;
/*@=redef@*/ /*@=matchfields@*/

/*@constant mode_t S_IWUSR@*/
/*@constant mode_t S_IXUSR@*/
/*@constant mode_t S_IRWXG@*/
/*@constant mode_t S_IRGRP@*/
/*@constant mode_t S_IWGRP@*/
/*@constant mode_t S_IXGRP@*/
/*@constant mode_t S_IRWXO@*/
/*@constant mode_t S_IROTH@*/
/*@constant mode_t S_IWOTH@*/
/*@constant mode_t S_IXOTH@*/
/*@constant mode_t S_ISUID@*/
/*@constant mode_t S_ISGID@*/
/*@constant mode_t S_ISVTX@*/

//# if 0
///*These are the old definitions - they don't appear to be in the Single UNIX Specification */
//
///*@constant int S_ISTXT@*/
///*@constant int S_IREAD@*/
///*@constant int S_IWRITE@*/
///*@constant int S_IEXEC@*/
///*@constant int S_IFMT@*/
///*@constant int S_IFIFO@*/
///*@constant int S_IFCHR@*/
///*@constant int S_IFDIR@*/
///*@constant int S_IFBLK@*/
///*@constant int S_IFREG@*/
///*@constant int S_IFLNK@*/
///*@constant int S_IFSOCK@*/
///*@constant int S_ISVTX@*/
///*@constant int S_ISVTX@*/
///*@constant int SF_SETTABLE@*/
///*@constant int SF_ARCHIVED@*/
///*@constant int ACCESSPERMS@*/
///*@constant int ALLPERMS@*/
///*@constant int DEFFILEMODE@*/
///*@constant int S_BLKSIZE@*/
///*@constant int SF_IMMUTABLE@*/
///*@constant int SF_APPEND@*/
///*@constant int UF_NODUMP@*/
///*@constant int UF_IMMUTABLE@*/
///*@constant int UF_APPEND@*/
//# endif

int /*@alt _Bool@*/ S_ISBLK (/*@sef@*/ __mode_t m) /*@*/;
int /*@alt _Bool@*/ S_ISCHR (/*@sef@*/ __mode_t m) /*@*/;
int /*@alt _Bool@*/ S_ISDIR (/*@sef@*/ __mode_t m) /*@*/;
int /*@alt _Bool@*/ S_ISFIFO (/*@sef@*/ __mode_t m) /*@*/;
int /*@alt _Bool@*/ S_ISREG (/*@sef@*/ __mode_t m) /*@*/;
int /*@alt _Bool@*/ S_ISLNK (/*@sef@*/ __mode_t m) /*@*/;

int /*@alt _Bool@*/ S_TYPEISMQ (/*@sef@*/ struct stat *buf) /*@*/ ;
int /*@alt _Bool@*/ S_TYPEISSEM (/*@sef@*/ struct stat *buf) /*@*/ ;
int /*@alt _Bool@*/ S_TYPEISSHM  (/*@sef@*/ struct stat *buf) /*@*/ ;

/* in POSIX: chmod, fstat, mkdir, mkfifo, stat, umask */

int lstat(const char *, /*@out@*/ struct stat *)
     /*:errorcode -1:*/
     /*@modifies errno@*/ ;

int mknod (const char *, mode_t, dev_t)
  /*@warn portability "The only portable use of mknod is to create FIFO-special file. If mode is not S_IFIFO or dev is not 0, the behaviour of mknod() is unspecified."@*/
  /*:errorcode -1:*/
  /*@modifies errno@*/ ;

int chflags (const char *path, u_long flags)
  /*@warn unixstandard "Not in Single UNIX Specification Version 2"@*/
  /*@modifies fileSystem, errno@*/;

int fchflags (int fd, u_long flags)
  /*@warn unixstandard "Not in Single UNIX Specification Version 2"@*/
  /*@modifies fileSystem, errno@*/;

/* evans 2002-03-17: this was missing, reported by Ralf Wildenhues */
int fchmod(int fildes, mode_t mode)
   /*@modifies fileSystem, errno@*/ ;

/*
** sys/statvfs.h
** from http://www.opengroup.org/onlinepubs/007908799/xsh/sysstatvfs.h.html
*/

struct statvfs {
   unsigned long f_bsize;
   unsigned long f_frsize;
   fsblkcnt_t    f_blocks;
   fsblkcnt_t    f_bfree;
   fsblkcnt_t    f_bavail;
   fsfilcnt_t    f_files;
   fsfilcnt_t    f_ffree;
   fsfilcnt_t    f_favail;
   unsigned long f_fsid;
   unsigned long f_flag;
   unsigned long f_namemax;
} ;

/*@constant unsigned long ST_RDONLY; @*/
/*@constant unsigned long ST_NOSUID; @*/

int fstatvfs (int fildes, /*@out@*/ struct statvfs *buf)
   /*@modifies buf@*/ ;

int statvfs (const char *path, /*@out@*/ struct statvfs *buf)
    /*@modifies buf@*/ ;


/*________________________________________________________________________
 * stropts.h
 */

/*@constant int FMNAMESZ@*/
/*@constant int MSG_BAND@*/
/*@constant int MSG_HIPRI@*/
/*@constant int RS_HIPRI@*/
/*@constant int S_INPUT@*/
/*@constant int S_RDNORM@*/
/*@constant int S_RDBAND@*/
/*@constant int S_BANDURG@*/
/*@constant int S_HIPRI@*/
/*@constant int S_OUTPUT@*/
/*@constant int S_WRNORM@*/
/*@constant int S_WRBAND@*/
/*@constant int S_MSG@*/
/*@constant int S_ERROR@*/
/*@constant int S_HANGUP@*/

 struct strbuf {
	int maxlen;
	int len;
	char *buf;
};

 struct str_mlist {
	char l_name[];
};

 struct str_list {
	int sl_nmods;
	struct str_mlist *sl_modlist;
};

	extern int
getmsg (int fd, /*@out@*/ struct strbuf *c, /*@out@*/ struct strbuf *d, int *f)
	/*@modifies *c, *d, errno@*/;

	extern int
getpmsg (int fd, /*@out@*/ struct strbuf *c, /*@out@*/ struct strbuf *d, int *b, int *f)
	/*@modifies *b, *c, *d, errno@*/;

	extern int
putmsg (int fd, const struct strbuf *c, const struct strbuf *d, int *f)
	/*@modifies internalState, errno@*/;

extern int putpmsg (int fd, const struct strbuf *c, const struct strbuf *d, int b, int *f)
   /*@modifies internalState, errno@*/;

/*
** sys/resource.h
**
** Update 2002-07-09 from
** http://www.opengroup.org/onlinepubs/007904975/basedefs/sys/resource.h.html
*/

/*@constant int PRIO_PROCESS@*/
/*@constant int PRIO_PGRP@*/
/*@constant int PRIO_USER@*/

//typedef /*@unsignedintegraltype@*/ rlim_t;

/*@constant rlim_t RLIM_INFINITY@*/
/*@constant rlim_t RLIM_SAVED_MAX@*/
/*@constant rlim_t RLIM_SAVED_CUR@*/

/*@constant int RUSAGE_SELF@*/
/*@constant int RUSAGE_CHILDREN@*/

struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
};

struct rusage {
  struct timeval ru_utime;        /* user time used */
  struct timeval ru_stime;        /* system time used */
  /* other members optional */
};

/*@constant int RLIMIT_CORE@*/
/*@constant int RLIMIT_CPU@*/
/*@constant int RLIMIT_DATA@*/
/*@constant int RLIMIT_FSIZE@*/
/*@constant int RLIMIT_NOFILE@*/
/*@constant int RLIMIT_STACK@*/
/*@constant int RLIMIT_AS@*/

int getpriority (int which, id_t who)
   /*@modifies errno@*/;

int getrlimit (int res, /*@out@*/ struct rlimit *rlp)
   /*@modifies *rlp, errno@*/;

int getrusage (int who, /*@out@*/ struct rusage *rusage)
   /*@modifies *rusage, errno@*/;

int setpriority (int which, id_t who, int prio)
   /*@modifies errno, internalState@*/;

int setrlimit (int resource, const struct rlimit *rlp)
   /*@modifies errno, internalState@*/;

/*
** in <netdb.h>
*/

struct servent
{
  /*@observer@*/ char *s_name;			/* Official service name.  */
  /*@observer@*/ char **s_aliases;		/* Alias list.  */
  int s_port;			                /* Port number.  */
  /*@observer@*/ char *s_proto;		        /* Protocol to use.  */
} ;

/*@observer@*/ /*@dependent@*/ /*@null@*/ struct servent *getservbyname (const char *name, /*@null@*/ const char *proto)
     /*@warn multithreaded "Unsafe in multithreaded applications, use getsrvbyname_r instead"@*/ ;

struct servent *getservbyname_r (const char *name, /*@null@*/ const char *proto, /*@out@*/ /*@returned@*/ struct servent *result, /*@out@*/ char *buffer, int buflen)
     /*@requires maxSet (buffer) >= buflen@*/ ;


/*@observer@*/ /*@dependent@*/ struct servent *getservbyport (int port, /*@null@*/ const char *proto)
     /*@warn multithreaded "Unsafe in multithreaded applications, use getservbyport_r instead"@*/ ;

struct servent *getservbyport_r (int port, /*@null@*/ const char *proto, /*@out@*/ /*@returned@*/ struct servent *result, /*@out@*/ char *buffer, int buflen)
     /*@requires maxSet (buffer) >= buflen@*/ ;

/*@null@*/ struct servent *getservent (void);

/*@null@*/ struct servent *getservent_r (struct servent *result, char *buffer, int buflen);

int setservent (int stayopen);
int endservent (void);

extern int h_errno;

/*@null@*/ /*@observer@*/ struct hostent *gethostbyname (/*@nullterminated@*/ /*@notnull@*/ const char *name)
     /*@warn multithreaded "Unsafe in multithreaded applications, use gethostbyname_r instead"@*/
     /*@modifies h_errno@*/ ;

struct hostent *gethostbyname_r (/*@nullterminated@*/ const char *name, /*@notnull@*/ /*@returned@*/ struct hostent *hent, /*@out@*/ /*@exposed@*/ char *buffer, int bufsize, /*@out@*/ int *h_errnop)
     /*@requires maxSet(buffer) >= bufsize@*/ ;

/*@null@*/ /*@observer@*/ struct hostent *gethostbyaddr (/*@notnull@*/ const void *addr, size_t addrlen, int type)
     /*@requires maxRead(addr) == addrlen@*/ /*:i534 ??? is this right? */
     /*@warn multithreaded "Unsafe in multithreaded applications, use gethostbyaddr_r instead"@*/
     /*@modifies h_errno@*/ ;

struct hostent *gethostbyaddr_r (/*@notnull@*/ const void *addr, size_t addrlen, int type,
				 /*@returned@*/ /*@out@*/ struct hostent *hent,
				 /*@exposed@*/ /*@out@*/ char *buffer, int bufsize, /*@out@*/ int *h_errnop)
     /*@requires maxRead(addr) == addrlen /\ maxSet(buffer) >= bufsize@*/
     /*:i534 ??? is this right? */ ;

/*@observer@*/ /*@null@*/ struct hostent *gethostent (void)
    /*@warn multithreaded "Unsafe in multithreaded applications, use gethostent_r instead"@*/ ;

struct hostent *gethostent_r (/*@out@*/ /*@returned@*/ struct hostent *hent, /*@exposed@*/ /*@out@*/ char *buffer, int bufsize)
     /*@requires maxSet(buffer) >= bufsize@*/ ;

/*:i534 need to annotate these: */

struct hostent *fgethostent(FILE *f);
struct hostent *fgethostent_r(FILE*f, struct hostent *hent, char buffer, int bufsize);
void sethostent(int stayopen);
void endhostent(void);
void herror(const char *string);
char *hstrerror(int err);

struct hostent {
  /*@observer@*/ /*@nullterminated@*/ char *h_name;   /* official name of host */
  /*@observer@*/ /*@nullterminated@*/ char * /*:observer@*/ /*:nullterminated@*/ *h_aliases;   /* alias list */
  int  h_addrtype;   /* host address type*/
  int  h_length;   /* length ofaddress*/
  /*@observer@*/ /*@nullterminated@*/ char * /*:observer@*/ /*:nullterminated@*/ *h_addr_list; /* list of addressesfrom name server */
  /*@observer@*/ /*@nullterminated@*/ char *h_addr; /* first address in list (backward compatibility) */
} ;

/*
** unistd.h
** from http://www.opengroup.org/onlinepubs/007908799/xsh/unistd.h.html
*/

/*@constant int _POSIX_VERSION@*/
/*@constant int _POSIX2_VERSION@*/
/*@constant int _POSIX2_C_VERSION@*/
/*@constant int _XOPEN_VERSION@*/
/*@constant int _XOPEN_XCU_VERSION@*/

/* for access: */

/*@constant int R_OK@*/
/*@constant int W_OK@*/
/*@constant int X_OK@*/
/*@constant int F_OK@*/

/* for confstr: */
/*@constant int _CS_PATH@*/
/*@constant int _CS_XBS5_ILP32_OFF32_CFLAGS@*/
/*@constant int _CS_XBS5_ILP32_OFF32_LDFLAGS@*/
/*@constant int _CS_XBS5_ILP32_OFF32_LIBS@*/
/*@constant int _CS_XBS5_ILP32_OFF32_LINTFLAGS@*/
/*@constant int _CS_XBS5_ILP32_OFFBIG_CFLAGS@*/
/*@constant int _CS_XBS5_ILP32_OFFBIG_LDFLAGS@*/
/*@constant int _CS_XBS5_ILP32_OFFBIG_LIBS@*/
/*@constant int _CS_XBS5_ILP32_OFFBIG_LINTFLAGS@*/
/*@constant int _CS_XBS5_LP64_OFF64_CFLAGS@*/
/*@constant int _CS_XBS5_LP64_OFF64_LDFLAGS@*/
/*@constant int _CS_XBS5_LP64_OFF64_LIBS@*/
/*@constant int _CS_XBS5_LP64_OFF64_LINTFLAGS@*/
/*@constant int _CS_XBS5_LPBIG_OFFBIG_CFLAGS@*/
/*@constant int _CS_XBS5_LPBIG_OFFBIG_LDFLAGS@*/
/*@constant int _CS_XBS5_LPBIG_OFFBIG_LIBS@*/
/*@constant int _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS@*/

/* name parameters to sysconf: */

/*@constant int _SC_2_C_BIND@*/
/*@constant int _SC_2_C_DEV@*/
/*@constant int _SC_2_C_VERSION@*/
/*@constant int _SC_2_FORT_DEV@*/
/*@constant int _SC_2_FORT_RUN@*/
/*@constant int _SC_2_LOCALEDEF@*/
/*@constant int _SC_2_SW_DEV@*/
/*@constant int _SC_2_UPE@*/
/*@constant int _SC_2_VERSION@*/
/*@constant int _SC_ARG_MAX@*/
/*@constant int _SC_AIO_LISTIO_MAX@*/
/*@constant int _SC_AIO_MAX@*/
/*@constant int _SC_AIO_PRIO_DELTA_MAX@*/
/*@constant int _SC_ASYNCHRONOUS_IO@*/
/*@constant int _SC_ATEXIT_MAX@*/
/*@constant int _SC_BC_BASE_MAX@*/
/*@constant int _SC_BC_DIM_MAX@*/
/*@constant int _SC_BC_SCALE_MAX@*/
/*@constant int _SC_BC_STRING_MAX@*/
/*@constant int _SC_CHILD_MAX@*/
/*@constant int _SC_CLK_TCK@*/
/*@constant int _SC_COLL_WEIGHTS_MAX@*/
/*@constant int _SC_DELAYTIMER_MAX@*/
/*@constant int _SC_EXPR_NEST_MAX@*/
/*@constant int _SC_FSYNC@*/
/*@constant int _SC_GETGR_R_SIZE_MAX@*/
/*@constant int _SC_GETPW_R_SIZE_MAX@*/
/*@constant int _SC_IOV_MAX@*/
/*@constant int _SC_JOB_CONTROL@*/
/*@constant int _SC_LINE_MAX@*/
/*@constant int _SC_LOGIN_NAME_MAX@*/
/*@constant int _SC_MAPPED_FILES@*/
/*@constant int _SC_MEMLOCK@*/
/*@constant int _SC_MEMLOCK_RANGE@*/
/*@constant int _SC_MEMORY_PROTECTION@*/
/*@constant int _SC_MESSAGE_PASSING@*/
/*@constant int _SC_MQ_OPEN_MAX@*/
/*@constant int _SC_MQ_PRIO_MAX@*/
/*@constant int _SC_NGROUPS_MAX@*/
/*@constant int _SC_OPEN_MAX@*/
/*@constant int _SC_PAGESIZE@*/
/*@constant int _SC_PAGE_SIZE@*/
/*@constant int _SC_PASS_MAX@*/
/*@constant int _SC_PRIORITIZED_IO@*/
/*@constant int _SC_PRIORITY_SCHEDULING@*/
/*@constant int _SC_RE_DUP_MAX@*/
/*@constant int _SC_REALTIME_SIGNALS@*/
/*@constant int _SC_RTSIG_MAX@*/
/*@constant int _SC_SAVED_IDS@*/
/*@constant int _SC_SEMAPHORES@*/
/*@constant int _SC_SEM_NSEMS_MAX@*/
/*@constant int _SC_SEM_VALUE_MAX@*/
/*@constant int _SC_SHARED_MEMORY_OBJECTS@*/
/*@constant int _SC_SIGQUEUE_MAX@*/
/*@constant int _SC_STREAM_MAX@*/
/*@constant int _SC_SYNCHRONIZED_IO@*/
/*@constant int _SC_THREADS@*/
/*@constant int _SC_THREAD_ATTR_STACKADDR@*/
/*@constant int _SC_THREAD_ATTR_STACKSIZE@*/
/*@constant int _SC_THREAD_DESTRUCTOR_ITERATIONS@*/
/*@constant int _SC_THREAD_KEYS_MAX@*/
/*@constant int _SC_THREAD_PRIORITY_SCHEDULING@*/
/*@constant int _SC_THREAD_PRIO_INHERIT@*/
/*@constant int _SC_THREAD_PRIO_PROTECT@*/
/*@constant int _SC_THREAD_PROCESS_SHARED@*/
/*@constant int _SC_THREAD_SAFE_FUNCTIONS@*/
/*@constant int _SC_THREAD_STACK_MIN@*/
/*@constant int _SC_THREAD_THREADS_MAX@*/
/*@constant int _SC_TIMERS@*/
/*@constant int _SC_TIMER_MAX@*/
/*@constant int _SC_TTY_NAME_MAX@*/
/*@constant int _SC_TZNAME_MAX@*/
/*@constant int _SC_VERSION@*/
/*@constant int _SC_XOPEN_VERSION@*/
/*@constant int _SC_XOPEN_CRYPT@*/
/*@constant int _SC_XOPEN_ENH_I18N@*/
/*@constant int _SC_XOPEN_SHM@*/
/*@constant int _SC_XOPEN_UNIX@*/
/*@constant int _SC_XOPEN_XCU_VERSION@*/
/*@constant int _SC_XOPEN_LEGACY@*/
/*@constant int _SC_XOPEN_REALTIME@*/
/*@constant int _SC_XOPEN_REALTIME_THREADS@*/
/*@constant int _SC_XBS5_ILP32_OFF32@*/
/*@constant int _SC_XBS5_ILP32_OFFBIG@*/
/*@constant int _SC_XBS5_LP64_OFF64@*/
/*@constant int _SC_XBS5_LPBIG_OFFBIG@*/


//int access(const char *, int) /*@modifies errno@*/ /*:errorcode -1:*/ ;
//unsigned int alarm (unsigned int) /*@modifies internalState@*/ ;

int brk(void *)
     /*@modifies errno@*/
     /*:errorcode -1:*/
     /*@warn legacy "brk is obsolete"@*/ ;

//int chdir (const char *)
//     /*@modifies internalState, errno@*/
//     /*:errorcode -1:*/ ;

//int chown (const char *, uid_t, gid_t)
//     /*@modifies internalState, errno@*/
//     /*:errorcode -1:*/ ;

//int close (int)
//     /*@modifies internalState, errno@*/
//     /*:errorcode -1:*/ ;

size_t confstr(int, /*@null@*/ char *, size_t)
     /*@globals internalState@*/
     /*@modifies errno@*/
     /*:errorcode 0:*/ ;

/*@dependent@*/ /*@null@*/ char *crypt(const char *, const char *)
     /*@modifies errno, internalState@*/ ;

///*@dependent@*/ /*@null@*/ char *ctermid(/*@returned@*/ /*@null@*/ /*@out@*/ char *s)
//     /*@modifies s@*/ ;

///*@null@*/ /*@dependent@*/ char *cuserid (/*@null@*/ /*@returned@*/ char *s)
//     /*@warn legacy "cuserid is obsolete"@*/
//     /*@modifies s@*/ ;

//int dup(int)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

//int dup2(int, int)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

void encrypt(char p_block[], int)
     /*@requires maxSet(p_block) == 63@*/
     /*@modifies p_block, errno@*/ ;

//extern char **environ;

//int execl (const char *, const char *, ...)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

//int execle(const char *, const char *, ...)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

//int execlp(const char *, const char *, ...)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

//int execv(const char *, char *const [])
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;
//
//int execve(const char *, char *const [], char *const [])
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;
//
//int execvp(const char *, char *const [])
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

///*@exits@*/ void _exit (int);
//
//int fchown (int, uid_t, gid_t)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
//int fchdir (int)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
//int fdatasync (int)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
//pid_t fork (void)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

//long int fpathconf(int, int)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;
//
//int fsync(int)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
//int ftruncate(int, off_t)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
///*@null@*/ char *getcwd (/*@returned@*/ char *buf, size_t size)
//     /*@requires maxSet(buf) >= size;@*/
//     /*@modifies errno@*/ ;
//
//int getdtablesize (void)
//     /*@warn legacy "getdtablesize is obsolete"@*/ ;

//gid_t getegid (void) /*@globals internalState*/ ;
//uid_t geteuid (void) /*@globals internalState*/ ;
//gid_t getgid (void) /*@globals internalState*/ ;
//
//int getgroups (int gidsetsize, gid_t grouplist[])
//     /*@requires maxSet(grouplist) >= gidsetsize@*/
//     /*@modifies errno@*/
//     /*:errorcode -1:*/ ;
//
//long gethostid (void) /*@globals internalState@*/ ;
//
///*@null@*/ /*@dependent@*/ char *getlogin (void)
//     /*@modifies errno@*/ ;
//
//int getlogin_r (char *name, size_t namesize)
//     /*@requires maxSet(name) >= namesize@*/
//     /*:errorcode !0:*/ ;

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;

int getopt(int, char * const [], const char *)
     /*@modifies optind, opterr, optopt, errno@*/
     /*:errorcode -1:*/ ;

int getpagesize(void)
     /*@warn legacy "getpagesize is obsolete"@*/ ;

/*@dependent@*/ /*@null@*/ char *getpass(/*@nullterminated@*/ const char *)
     /*@warn legacy "getpass is obsolete"@*/ ;

pid_t getpgid(pid_t)
     /*@modifies errno@*/
     /*@globals internalState@*/
     /*:errorcode (pid_t)-1:*/ ;

//pid_t getpgrp(void) /*@globals internalState*/ ;

//pid_t getpid(void) /*@globals internalState*/ ;
//pid_t getppid(void) /*@globals internalState*/ ;

//pid_t getsid(pid_t)
//     /*@modifies errno@*/
//     /*@globals internalState@*/
//     /*:errorcode (pid_t)-1:*/ ;
//
//uid_t getuid(void) /*@globals internalState@*/ ;

/*@null@*/ char *getwd (/*@returned@*/ char *path_name)
     /*@modifies path_name@*/ ;

//int isatty(int)
//     /*@globals internalState@*/
//     /*@modifies errno@*/
//     /*:errorcode 0:*/ ;

//int lchown(const char *, uid_t, gid_t)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
//int link(const char *, const char *)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
//int lockf(int, int, off_t)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;
//
//off_t lseek(int, off_t, int)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode (off_t)-1:*/ ;

int nice(int)
     /*@modifies errno, fileSystem@*/
     /*:errorcode -1:*/ ;

//long int pathconf(const char *, int)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;
//
//int pause(void)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;
//
//int pipe(int p[])
//     /*@requires maxRead(p) == 1@*/
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;

ssize_t pread(int, /*@out@*/ void *buf, size_t nbyte, off_t offset)
     /*@modifies errno, fileSystem@*/
     /*@requires maxSet(buf) >= (nbyte - 1) @*/
     /*@ensures maxRead(buf) >= nbyte @*/
     /*:errorcode -1:*/ ;

int pthread_atfork(void (*)(void), void (*)(void), void(*)(void))
     /*@modifies errno, fileSystem@*/
     /*:errorcode !0:*/ ;

ssize_t pwrite(int, const void *buf, size_t nbyte, off_t)
     /*@requires maxRead(buf) >= nbyte@*/
     /*@modifies errno, fileSystem@*/
     /*:errorcode -1:*/ ;

/*     ssize_t      read(int, void *, size_t); in posix.h */

int readlink(const char *, char *buf, size_t bufsize)
     /*@requires maxSet(buf) >= (bufsize - 1)@*/
     /*@modifies errno, fileSystem, *buf@*/
     /*:errorcode -1:*/ ;

/* int          rmdir(const char *); in posix.h */

void *sbrk(intptr_t)
     /*@modifies errno@*/
     /*:errorcode (void *)-1:*/
     /*@warn legacy "sbrk is obsolete"@*/ ;

     /*     int          setgid(gid_t);
	    int          setpgid(pid_t, pid_t);
     */

pid_t setpgrp(void) /*@modifies internalState@*/ ;

//int setregid(gid_t, gid_t)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;
//
//int setreuid(uid_t, uid_t)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;
//
//pid_t setsid(void)
//     /*@modifies errno, internalState@*/
//     /*:errorcode (pid_t) -1:*/ ;
//
//int setuid(uid_t)
//     /*@modifies errno, internalState@*/
//     /*:errorcode -1:*/ ;

//unsigned int sleep(unsigned int)
//     /*@modifies systemState@*/ ;

void swab(/*@unique@*/ const void *src, /*@unique@*/ void *dest, ssize_t nbytes)
     /*@requires maxSet(dest) >= (nbytes - 1)@*/ ;

//int symlink(const char *, const char *)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;

//void sync(void) /*@modifies systemState@*/ ;

//long int sysconf(int)
//     /*@modifies errno, systemState@*/
//     /*:errorcode -1:*/ ;
//
//pid_t tcgetpgrp(int)
//     /*@globals systemState@*/
//     /*@modifies errno@*/
//     /*:errorcode -1:*/ ;
//
//int tcsetpgrp(int, pid_t)
//     /*@modifies errno, systemState@*/
//     /*:errorcode -1:*/ ;
//
//int truncate(const char *, off_t)
//     /*@modifies errno, fileSystem@*/
//     /*:errorcode -1:*/ ;

///*@dependent@*/ /*@null@*/ char *ttyname(int)
//     /*@globals systemState@*/
//     /*@modifies errno@*/
//     /*:errorcode -1:*/ ;

int ttyname_r(int, char *name, size_t namesize)
     /*@requires maxSet(name) >= (namesize - 1)@*/ ;
     /*:errorcode !0:*/ ;

useconds_t ualarm(useconds_t, useconds_t)
     /*@modifies systemState@*/ ;

//int unlink(const char *)
//     /*@modifies fileSystem, errno@*/
//     /*:errorcode -1:*/ ;
//
//int usleep(useconds_t)
//     /*@modifies fileSystem, errno@*/
//     /*:errorcode -1:*/ ;
//
//pid_t vfork(void)
//     /*@modifies fileSystem, errno@*/
//     /*:errorcode -1:*/ ;
//
//     /* in posix.h ssize_t write(int, const void *, size_t); */
//
//
//int chroot (/*@notnull@*/ /*@nullterminated@*/ const char *path)
//     /*@modifies internalState, errno@*/
//     /*:errorcode -1:*/
//     /*@warn superuser "Only super-user processes may call chroot."@*/ ;
//
//int fchroot (int fildes)
//   /*:statusreturn@*/
//   /*@warn superuser "Only super-user processes may call fchroot."@*/ ;


/*
** ctype.h
**
** evans 2001-08-26 - added from http://www.opengroup.org/onlinepubs/007908799/xsh/ctype.h.html
*/

# ifdef STRICT
_Bool isascii(int) /*@*/ ;
_Bool toascii(int) /*@*/ ;
char _toupper(/*@sef@*/ int) /*@*/ ;
char  _tolower(/*@sef@*/ int) /*@*/ ;
# else
//_Bool /*@alt int@*/ isascii(int /*@alt unsigned char@*/) /*@*/ ;
//_Bool /*@alt int@*/ toascii(int /*@alt unsigned char@*/);
//char  /*@alt int@*/ _toupper(/*@sef@*/ int /*@alt unsigned char@*/);
//char /*@alt int@*/ _tolower(/*@sef@*/ int /*@alt unsigned char@*/);
# endif

/* other ctype.h functions in ansi.h */

/*
** stdlib.h
**
** evans 2001-08-27 - added from http://www.opengroup.org/onlinepubs/007908799/xsh/drand48.html
*/

double drand48 (void) /*@modifies internalState@*/ ;
double erand48 (unsigned short int /*@-fixedformalarray@*/ xsubi[3] /*@=fixedformalarray@*/ )
   /*@modifies internalState@*/ ;

void srand48 (long int seedval) /*@modifies internalState@*/ ;

/*
** netinet/in.h
**
** evans 2001-08-27 - added from http://www.opengroup.org/onlinepubs/007908799/xns/netinetin.h.html
*/

//typedef /*@unsignedintegraltype@*/ in_port_t; /* An unsigned integral type of exactly 16 bits. */
//typedef /*@unsignedintegraltype@*/ in_addr_t; /* An unsigned integral type of exactly 32 bits. */

/* sa_family_t moved earlier */

struct in_addr {
  in_addr_t      s_addr;
} ;

struct sockaddr_in {
  sa_family_t    sin_family;
  in_port_t      sin_port;
  struct in_addr sin_addr;
  unsigned char  sin_zero[8];
} ;


/* The <netinet/in.h> header defines the following macros for use as values of the level argument of
   getsockopt() and setsockopt():
 */

/*@constant int IPPROTO_IP@*/
/*@constant int IPPROTO_ICMP@*/
/*@constant int IPPROTO_TCP@*/
/*@constant int IPPROTO_UDP@*/

/* The <netinet/in.h> header defines the following macros for use as destination addresses for connect(), sendmsg() and sendto():
 */

/*@constant in_addr_t INADDR_ANY@*/
/*@constant in_addr_t INADDR_BROADCAST@*/

/*
** arpa/inet.h
*/

in_addr_t htonl (in_addr_t hostlong) /*@*/ ;
in_port_t htons (in_port_t hostshort) /*@*/ ;
in_addr_t ntohl (in_addr_t netlong) /*@*/ ;
in_port_t ntohs (in_port_t netshort) /*@*/ ;

/*
** dirent.h
**
** evans 2001-08-27 - added from http://www.opengroup.org/onlinepubs/007908799/xsh/dirent.h.html
*/

/*@-redef@*/ /*@-matchfields@*/ /* Has d_ino field, not in posix (?) */

struct dirent
{
  ino_t  d_ino;
  char   d_name[];
} ;

/*@=redef@*/ /*@=matchfields@*/

//typedef /*@abstract@*/ DIR;

/*:i32 need to check annotations on these */

//int closedir (DIR *) /*:errorcode -1*/ ;
///*@null@*/ /*@dependent@*/ DIR *opendir(const char *)  /*@modifies errno, fileSystem@*/ ;
//
///* in posix.h: struct dirent *readdir(DIR *); */
//
//int readdir_r (DIR *, struct dirent *, /*@out@*/ struct dirent **result)
//     /*@modifies *result@*/
//     /*:errorcode !0:*/ ;
//
//void rewinddir(DIR *);
//void seekdir(DIR *, long int);
//long int telldir(DIR *);

/*drl added these functions
  stpcpy and stpncpy are found on linux but
  don't seem to be present on other unixes

  thanks to Jeff Johnson for pointing out that
  these functions were in the unix library
*/

/* this function is like strcpy but it reutrns a pointer to the null terminated character in dest instead of the beginning of dest */

extern char * stpcpy(/*@out@*/ /*@returned@*/ char * dest, const char * src)
             /*@modifies *dest @*/
     /*@requires maxSet(dest) >= maxRead(src) @*/
     /*@ensures MaxRead(dest) == MaxRead (src) /\ MaxRead(result) == 0 /\ MaxSet(result) == ( maxSet(dest) - MaxRead(src) ); @*/;


extern char * stpncpy(/*@out@*/ /*@returned@*/ char * dest,
		      const char * src, size_t n)
           /*@modifies *dest @*/
   /*@requires MaxSet(dest) >= ( n - 1 ); @*/ /*@ensures MaxRead (src) >= MaxRead(dest) /\ MaxRead (dest) <= n; @*/
  ;

  /* drl added 09-25-001
     Alexander Ma pointed out these were missing
  */

int usleep (useconds_t useconds) /*@modifies systemState, errno@*/
     /*error -1 sucess 0 */
     /* warn opengroup unix specification recommends using setitimer(), timer_create(), timer_delete(), timer_getoverrun(), timer_gettime() or
     timer_settime() instead of this interface.
     */
     ;


     /* drl added 10-27-001 */
         /*not sure what the exact size of this is
       also can IPv6 use this function?
      */
     /*I'm going to assume that the address had the format:
       "###.###.###.###" which is 16 bytes*/

       /*@kept@*/ char *inet_ntoa(struct in_addr in)
     /*@ensures maxSet(result) <= 15 /\ maxRead(result) <= 15 @*/
     ;


//     extern  double hypot(double x, double y) /*@modifies errno@*/ /*error errno only*/;


     extern double j0(double x) /*@modifies errno @*/ /*error 0 or NaN */;
 extern      double j1(double x) /*@modifies errno @*/ /*error 0 or NaN */;
 extern      double jn(int n, double x) /*@modifies errno @*/ /*error 0 or NaN */;

     extern double y0(double x) /*@modifies errno @*/  /*error NaN -HUGE_VAL 0.0 */     ;
     extern      double y1 (double x) /*@modifies errno @*/  /*error NaN -HUGE_VAL 0.0 */;
     extern      double yn (int n, double x)  /*@modifies errno @*/  /*error NaN -HUGE_VAL 0.0 */;

//     extern       double acosh(double x)  /*@modifies errno @*/ /*error errno and implementation-dependent(NaN if present) */ /*error NaN and may errno*/;
//     extern       double asinh(double x) /*@modifies errno @*/  /*error NaN and may errno */;
//
//  extern        double atanh(double x) /*@modifies errno @*/ /*error errno and implementation-dependent(NaN if present) */ /*error NaN and may errno */ ;

//     extern         double lgamma(double x)  /*@modifies errno @*/  /*error NaN or HUGE_VAL may set errno */;
//
//     extern int signgam ;
//
//      extern      double erf(double x)  /*@modifies errno @*/  /*error NaN or 0 may set errno */;
//
//   extern      double erfc (double x) /*@modifies errno @*/  /*error NaN or 0
//					may set errno */;






