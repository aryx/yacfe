// time start 
//      01h10  77.3% 
//      01h40  84%
//      - +10 min
//      17h02 86%
//      -     87%
//      18h07 87%
//      19h13 90% (also added restrict C99 in lexer and grammar)
//      20h23 92% (also added ifdef cplusplus handling in lexer)

/* main pbs: 
*    done: restrict typedef inference 
*    complex extension
*/   

//bad: char *
//BAD:!!!!! internal_function
//bad: _dl_next_ld_env_entry (char ***position)
//bad: {
#define internal_function

//BAD:!!!!! extern char **__environ attribute_hidden;
#define attribute_hidden

//BAD:!!!!! int __stack_prot attribute_hidden attribute_relro
#define attribute_relro


//BAD:!!!!! static __thread struct A local1 = { 28, 29, 30 };
#define __thread

//BAD:!!!!! extern void weak_function free (void *ptr);
#define weak_function


//BAD:!!!!! determine_info (const ElfW(Addr) addr, struct link_map *match, Dl_info *info,
#define ElfW(a) a


//bad: internal_function __attribute_noinline__
#define __attribute_noinline__

//BAD:!!!!! extern int eventfd (int __count, int __flags) __THROW;
#define __THROW

//bad: __BEGIN_DECLS
#define __BEGIN_DECLS
#define __END_DECLS



//BAD:!!!!!     __SOCKADDR_COMMON (spkt_);
#define __SOCKADDR_COMMON(a) int a

//bad: __extern_inline vm_size_t
//BAD:!!!!! __mig_strncpy (char *__dst, const char *__src, vm_size_t __len)
#define __extern_inline

//BAD:!!!!! _EXTERN_INLINE void
//bad: __spin_lock (__spin_lock_t *__lock)
#define _EXTERN_INLINE

//BAD:!!!!! extern int sigemptyset (sigset_t *__set) __THROW __nonnull ((1));
#define __nonnull(a)


//bad: DL_FIXUP_VALUE_TYPE
//bad: __attribute ((noinline)) ARCH_FIXUP_ATTRIBUTE
//BAD:!!!!! _dl_profile_fixup (
//bad: #ifdef ELF_MACHINE_RUNTIME_FIXUP_ARGS
//bad: 		   ELF_MACHINE_RUNTIME_FIXUP_ARGS,
//bad: #endif
//bad: 		   struct link_map *l, ElfW(Word) reloc_offset,
//bad: 		   ElfW(Addr) retaddr, void *regs, long int *framesizep)
//bad: {
#define ARCH_FIXUP_ATTRIBUTE





//BAD:!!!!! extern int siggetmask (void) __THROW __attribute_deprecated__;
#define __attribute_deprecated__

//BAD:!!!!! extern int sigprocmask (int __how, __const sigset_t *__restrict __set,
//#define __restrict

//bad:      __attribute_pure__;
#define __attribute_pure__

//BAD:!!!!! extern void *__dlsym (void *handle, const char *name DL_CALLER_DECL)
#define DL_CALLER_DECL

//BAD:!!!!! extern void *__dlsym (void *handle, const char *name DL_CALLER_DECL)

//BAD:!!!!! CTYPE_EXTERN_INLINE const int32_t ** __attribute__ ((const))
#define CTYPE_EXTERN_INLINE

//BAD:!!!!!      __attribute_format_arg__ (1);
#define __attribute_format_arg__(a)


//BAD:!!!!! __extension__ __extern_inline unsigned long long int
//bad: __NTH (gnu_dev_makedev (unsigned int __major, unsigned int __minor))
//bad: {
//bad: __extern_always_inline __wur char *
//bad: __NTH (realpath (__const char *__restrict __name, char *__restrict __resolved))
//bad: {
#define __NTH(a) a

#define __extern_always_inline
#define __extension__


#define __wur

//bad: extern char *__REDIRECT_NTH (__realpath_chk_warn,
//BAD:!!!!! 			     (__const char *__restrict __name,
//bad: 			      char *__restrict __resolved,
//bad: 			      size_t __resolvedlen), __realpath_chk) __wur
//bad:      __warnattr ("second argument of realpath must be either NULL or at "
//bad: 		 "least PATH_MAX bytes long buffer");
#define __REDIRECT_NTH(a,b,c) a b


//bad: attribute_compat_text_section
#define attribute_compat_text_section

//BAD:!!!!! typedef __gmp_const __mpz_struct *mpz_srcptr;
#define __gmp_const const




//BAD:!!!!! void mpz_add_ui _PROTO ((mpz_ptr, mpz_srcptr, unsigned long int));
#define _PROTO(a) a


//BAD:!!!!!      __THROW __attribute_format_strfmon__ (4, 5);
#define __attribute_format_strfmon__(a,b)



//only 1:
////bad: _MCOUNT_DECL(frompc, selfpc)
////BAD:!!!!! {
#define _MCOUNT_DECL(a,b) int a(void)

//BAD:!!!!!   extern const char INTUSE(_itoa_lower_digits)[] attribute_hidden;
#define INTUSE(a) a

//bad: __BEGIN_NAMESPACE_STD
//BAD:!!!!! typedef __sig_atomic_t sig_atomic_t;
//bad: __END_NAMESPACE_STD
#define __BEGIN_NAMESPACE_STD
#define __END_NAMESPACE_STD

//BAD:!!!!! __libc_lock_define (extern, __libc_utmp_lock attribute_hidden)
#define __libc_utmp_lock(a, b) int foo;

//BAD:!!!!! __libc_lock_define_initialized (static, lock)
//BAD:!!!!! __libc_lock_define_initialized (static, lock)
#define __libc_lock_define_initialized(a,b) int foo;

//BAD:!!!!! __libc_lock_define_initialized_recursive (static, lock);
#define __libc_lock_define_initialized_recursive(a,b) int foo;

//BAD:!!!!!     __libc_lock_define (, lock) 
#define __libc_lock_define (a,b) int foo;


//BAD:!!!!! libc_freeres_ptr (static char *buffer);
#define libc_freeres_ptr(a) a



//bad: static bool __libc_freeres_fn_section
//BAD:!!!!! free_slotinfo (struct dtv_slotinfo_list **elemp)
//bad: {
//bad: static bool __libc_freeres_fn_section
//BAD:!!!!! free_slotinfo (struct dtv_slotinfo_list **elemp)
#define __libc_freeres_fn_section 

//BAD:!!!!!   static __thread void *data attribute_tls_model_ie;
//bad: void ** __attribute__ ((const))
//bad: __libc_dl_error_tsd (void)
//bad: {
//BAD:!!!!!   static __thread void *data attribute_tls_model_ie;
//bad:   return &data;
#define attribute_tls_model_ie


//BAD:!!!!!   char name __flexarr;
#define __flexarr 
//
//BAD:!!!!!   void *__unbounded result;
#define __unbounded

//bad: static ElfW(Addr) __attribute_used__ internal_function
//BAD:!!!!! _dl_start (void *arg)
#define __attribute_used__


//LINE_PARSER
//("#",
// STRING_FIELD (result->p_name, isspace, 1);
// INT_FIELD (result->p_proto, isspace, 1, 10,);
// )
//
//enum nss_status
//_nss_hesiod_setprotoent (int stayopen)
//{
#define LINE_PARSER(a, b)

#define STATIC static

//bad: extern char *__strdup (__const char *__string)
//BAD:!!!!!      __attribute_malloc__;
#define __attribute_malloc__


//libc_hidden_proto (__wcstol_l)
#define libc_hidden_proto(a)

//bad: libc_hidden_def (__libc_dlclose)
#define libc_hidden_def(a) 


//BAD:!!!!! LINKAGE int
//bad: ADJTIME (const struct TIMEVAL *itv, struct TIMEVAL *otv)
//bad: {
#define LINKAGE

//bad: static __always_inline bool
//BAD:!!!!! _dl_ppc64_addr_sym_match (const struct link_map *l, const ElfW(Sym) *sym,
#define __always_inline


//bad: double _Complex
//bad: attribute_hidden
//BAD:!!!!! casinl (double _Complex x)
//bad: {
#define _Complex


//BAD:!!!!! __libc_once_define (static, once);
//BAD:!!!!!       __libc_once_define (static, once);
//BAD:!!!!!   __libc_once_define (static, once);
//bad:   __libc_once (once, init);
#define __libc_once_define(a,b) int foo;
#define __libc_once(a,b) int foo;

//BAD:!!!!!     __ST_TIME(a);
#define __ST_TIME(a) int a

//bad: static void
//bad: start1 (ARG_DUMMIES argc, argp)
//BAD:!!!!!      DECL_DUMMIES
#define DECL_DUMMIES

//BAD:!!!!!   QP_HANDLE_EXCEPTIONS(__asm (
//bad: "	fdtoq %1, %%f60\n"
//bad: "	std %%f60, [%0]\n"
//bad: "	std %%f62, [%0+8]\n"
//bad: "	" : : "r" (c), "e" (a) : QP_CLOBBER));
//bad: }
#define QP_HANDLE_EXCEPTIONS(a) a

//BAD:!!!!! __MATH_INLINE float __NTH (fdimf (float __x, float __y));
//BAD:!!!!! __MATH_INLINE int
#define __MATH_INLINE 

//
//BAD:!!!!! symbol_version (__novmx_longjmp,_longjmp,GLIBC_2.3);
#define symbol_version(a,b,c) int foo

//BAD:!!!!! __STRING_INLINE void *
//bad: memchr (__const void *__str, int __c, size_t __n)
#define __STRING_INLINE

//BAD:!!!!!   EXTERN int _dl_debug_mask;
#define EXTERN extern

//
//BAD:!!!!! extern struct rtld_global _rtld_global __rtld_global_attribute__;
//BAD:!!!!! extern struct rtld_global _rtld_local __rtld_local_attribute__;
#define __rtld_local_attribute__
#define __rtld_global_attribute__

//bad: STATIC const char double_neg_zero[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80};
//bad: ALIGNIT
//BAD:!!!!! STATIC const char long_double_inf[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00};
//bad: ALIGNIT
#define ALIGNIT

//
//bad: float
//BAD:!!!!! __c2_cabsf (c2_cfloat_decl (z))
//bad: {
#define c2_cfloat_decl(a) float a

//bad: c1_cfloat_rettype
//BAD:!!!!! __c1_ccoshf (c1_cfloat_decl (x))
#define c1_cfloat_decl(a) float a

//BAD:!!!!! DEFINE_HOOK (_hurd_fork_prepare_hook, (void));
//BAD:!!!!! DEFINE_HOOK (_hurd_preinit_hook, (void));
#define DEFINE_HOOK(a,b) int foo
//
//BAD:!!!!!   RUN_HOOK (_hurd_preinit_hook, ());
#define RUN_HOOK(a,b) int a

//BAD:!!!!! _HURD_THREADVAR_H_EXTERN_INLINE unsigned long int *
//bad: __hurd_threadvar_location (enum __hurd_threadvar_index __index)
#define _HURD_THREADVAR_H_EXTERN_INLINE 

//BAD:!!!!! _HURD_SIGNAL_H_EXTERN_INLINE void
//bad: _hurd_critical_section_unlock (void *our_lock)
#define _HURD_SIGNAL_H_EXTERN_INLINE 

//BAD:!!!!! _HURD_FD_H_EXTERN_INLINE int
//bad: _hurd_fd_error_signal (error_t err)
#define _HURD_FD_H_EXTERN_INLINE 
//
//BAD:!!!!! _HURD_H_EXTERN_INLINE int
//bad: __hurd_fail (error_t err)
#define _HURD_H_EXTERN_INLINE

//BAD:!!!!!   __malloc_ptr_t (*hook) __MALLOC_PMT ((size_t, size_t,
//bad: 					__const __malloc_ptr_t)) =
#define __MALLOC_PMT(a) a 

//BAD:!!!!! static Void_t* memalign_hook_ini __MALLOC_P ((size_t alignment, size_t sz,
//bad: 					      const __malloc_ptr_t caller));
#define __MALLOC_P(a) a

//BAD:!!!!! void weak_variable (*__free_hook) (__malloc_ptr_t __ptr,
//bad: 				   const __malloc_ptr_t) = NULL;
#define weak_variable 


//
//BAD:!!!!! __complex__ double
//bad: __clog10 (__complex__ double x)
#define __complex__ 

//bad: int
//bad: __strcasecmp (s1, s2 LOCALE_PARAM)
//bad:      const char *s1;
//bad:      const char *s2;
//BAD:!!!!!      LOCALE_PARAM_DECL
#define LOCALE_PARAM_DECL
#define LOCALE_PARAM



bad: int *
bad: #if ! USE___THREAD
bad: weak_const_function
bad: #endif
BAD:!!!!! __errno_location (void)
bad: {
bad:   return &errno;
bad: }



//BAD:!!!!! DEFINE_HOOK (_hurd_fork_prepare_hook, (void));
//BAD:!!!!! DEFINE_HOOK (_hurd_preinit_hook, (void));
#define DEFINE_HOOK(a,b) int foo
//
//BAD:!!!!!   RUN_HOOK (_hurd_preinit_hook, ());
#define RUN_HOOK(a,b) int a

//BAD:!!!!! _HURD_THREADVAR_H_EXTERN_INLINE unsigned long int *
//bad: __hurd_threadvar_location (enum __hurd_threadvar_index __index)
#define _HURD_THREADVAR_H_EXTERN_INLINE 

//BAD:!!!!! _HURD_SIGNAL_H_EXTERN_INLINE void
//bad: _hurd_critical_section_unlock (void *our_lock)
#define _HURD_SIGNAL_H_EXTERN_INLINE 

//BAD:!!!!! _HURD_FD_H_EXTERN_INLINE int
//bad: _hurd_fd_error_signal (error_t err)
#define _HURD_FD_H_EXTERN_INLINE 
//
//BAD:!!!!! _HURD_H_EXTERN_INLINE int
//bad: __hurd_fail (error_t err)
#define _HURD_H_EXTERN_INLINE

//BAD:!!!!!   __malloc_ptr_t (*hook) __MALLOC_PMT ((size_t, size_t,
//bad: 					__const __malloc_ptr_t)) =
#define __MALLOC_PMT(a) a 

//BAD:!!!!! static Void_t* memalign_hook_ini __MALLOC_P ((size_t alignment, size_t sz,
//bad: 					      const __malloc_ptr_t caller));
#define __MALLOC_P(a) a

//BAD:!!!!! void weak_variable (*__free_hook) (__malloc_ptr_t __ptr,
//bad: 				   const __malloc_ptr_t) = NULL;
#define weak_variable 


//
//BAD:!!!!! __complex__ double
//bad: __clog10 (__complex__ double x)
#define __complex__ 

//bad: int
//bad: __strcasecmp (s1, s2 LOCALE_PARAM)
//bad:      const char *s1;
//bad:      const char *s2;
//BAD:!!!!!      LOCALE_PARAM_DECL
#define LOCALE_PARAM_DECL
#define LOCALE_PARAM

//bad: int *
//bad: #if ! USE___THREAD
//bad: weak_const_function
//bad: #endif
//BAD:!!!!! __errno_location (void)
//bad: {
//bad:   return &errno;
//bad: }
#define weak_const_function 


//BAD:!!!!!   float two23 = copysignf (0x1.0p23, x);
#define copysignf(a, b) foocopy(b)

//BAD:!!!!! __libc_tsd_define (static, MALLOC)
#define __libc_tsd_define(a,b) int foo;
//
//BAD:!!!!!       if (timercmp (&val.it_value, &elapsed, <))
#define timercmp(a,b,op) a op b

//BAD:!!!!! _HURD_PORT_H_EXTERN_INLINE void
#define _HURD_PORT_H_EXTERN_INLINE 

//BAD:!!!!! _HURD_USERLINK_H_EXTERN_INLINE int
#define _HURD_USERLINK_H_EXTERN_INLINE

//bad: weak_alias (__posix_memalign, posix_memalign)
//bad: 
//BAD:!!!!! strong_alias (__libc_calloc, __calloc) weak_alias (__libc_calloc, calloc)
#define weak_alias(a,b) 
#define strong_alias(a,b)
//
//BAD:!!!!!        __attribute_warn_unused_result__;
#define __attribute_warn_unused_result__

//
//bad:       __real__ res = INFINITY;
//bad:       __imag__ res = __copysign (0.0, __imag__ x);
#define __real__ 
#define __imag__


//bad: complex TYPE
//BAD:!!!!! (F(cproj)) (complex TYPE x)
//bad: {
//bad:   ++ccount;
//bad:   P ();
//bad:   return x;
//bad: }
#define F(a) a 
#define TYPE double

//BAD:!!!!! complex float fz;
//
//BAD:!!!!! __MATHCALL (cacos, (_Mdouble_complex_ __z));
#define __MATHCALL(a, b)
//
//BAD:!!!!! 		 size_t *irreversible EXTRA_LOOP_DECLS)
#define EXTRA_LOOP_DECLS

//
//BAD:!!!!!       if ((void *) current INNER_THAN top_stack

//
//BAD:!!!!! extern mqd_t __REDIRECT (__mq_open_alias, (__const char *__name, int __oflag, ...),
//bad: 			 mq_open) __nonnull ((1));
//BAD:!!!!! extern ssize_t __REDIRECT (pwrite, (int __fd, __const void *__buf,
//bad: 				    size_t __nbytes, __off64_t __offset),
//bad: 			   pwrite64) __wur;
#define __REDIRECT(a, args, b)  a args

//bad:   TRY (RTLD_DI_LINKMAP, &l)
//BAD:!!!!!     {


//bad: rettype
//bad: memmove (a1, a2, len)
//BAD:!!!!!      a1const void *a1;
//bad:      a2const void *a2;
//bad:      size_t len;
//bad: {
#define a1const const
#define a2const const 

//
//BAD:!!!!!      __nonnull ((1)) __wur __warnattr ("getdomainname called with bigger "
//bad: 				       "buflen than size of destination "
//bad: 				       "buffer");
#define __warnattr(a) 
//
//BAD:!!!!!       status = DL_CALL_FCT (setgrent_fct, ());
#define DL_CALL_FCT(a,b) a
//
//bad:   TST_DECL_VARS (wctype_t);
//bad:   char *class;
//bad: 
//bad:   TST_DO_TEST (wctype)
//BAD:!!!!!   {
//bad:     TST_HEAD_LOCALE (wctype, S_WCTYPE);
//bad:     TST_DO_REC (wctype)
//bad:     {
//bad:     TST_HEAD_LOCALE (strxfrm, S_STRXFRM);
#define TST_DO_TEST(a) if(a)
//
//BAD:!!!!! TST_ISW_LOC (CNTRL, cntrl) = {
#define TST_ISW_LOC(a,b) int b 

//bad:       TST_DO_SEQ (MBSRTOWCS_SEQNUM)
#define TST_DO_SEQ(a) if(a)

//bad:     TST_DO_REC (wcsncpy)
//BAD:!!!!!     {
#define TST_DO_REC(a) if(a) 
//BAD:!!!!! TST_TOW_LOC (UPPER, upper) = {
#define TST_TOW_LOC(a,b) int b 


//bad:       TST_IF_RETURN (S_WCTRANS)
//BAD:!!!!!       {
#define TST_IF_RETURN(a) if(a)

//bad: extern int __REDIRECT_NTH_LDBL (__swprintf_alias,
//BAD:!!!!! 				(wchar_t *__restrict __s, size_t __n,
//bad: 				 __const wchar_t *__restrict __fmt, ...),
//bad: 				swprintf);
#define __REDIRECT_NTH_LDBL(a, b,c) a b


//bad:   LOCK_FILE (file_fd, F_RDLCK)
//BAD:!!!!!     {
//bad:       nbytes = 0;
//bad:       LOCKING_FAILED ();
//bad:     }
#define LOCK_FILE(a,b) if(a)

//BAD:!!!!! extern INT __strtol_l PARAMS ((const STRING_TYPE *nptr, STRING_TYPE **endptr,
//bad: 			       int base));
#define PARAMS(a) a 


//bad: __BEGIN_NAMESPACE_C99
//bad: __END_NAMESPACE_C99
#define __BEGIN_NAMESPACE_C99
#define __END_NAMESPACE_C99




//BAD:!!!!! libc_locked_map_ptr (extern, __gr_map_handle) attribute_hidden;
#define libc_locked_map_ptr(a,b) int b 

//BAD:!!!!! static const char compilation[21] = __DATE__ " " __TIME__;
#define __DATE__ "foo"
#define __TIME__ "bar" 

//pad: ???
//BAD:!!!!! static const struct timeval tottimeout = {KEY_TIMEOUT *KEY_NRETRY, 0};

//pad: false positif
//BAD:!!!!! int inlineflag = INLINE;	


//BAD:!!!!! 	void *buffer, size_t buflen, int *errnop H_ERRNO_PROTO EXTRA_ARGS_DECL)
//bad: extern int parse_line (char *line, struct STRUCTURE *result,
//BAD:!!!!! 		       struct parser_data *data, size_t datalen, int *errnop
//bad: 		       EXTRA_ARGS_DECL);
#define EXTRA_ARGS_DECL
//
//BAD:!!!!! 			       size_t buflen, int *errnop H_ERRNO_PROTO)
#define H_ERRNO_PROTO 

//
//bad: int
//bad: INTERNAL (REENTRANT_GETNAME) (LOOKUP_TYPE *resbuf, char *buffer, size_t buflen,
//BAD:!!!!! 			      LOOKUP_TYPE **result H_ERRNO_PARM)
#define H_ERRNO_PARM



//bad: 	 && (INTERNAL (REENTRANT_NAME) (ADD_VARIABLES, &resbuf, buffer,
//BAD:!!!!! 					buffer_size, &result H_ERRNO_VAR)
#define H_ERRNO_VAR

//
//bad: int
//bad: attribute_compat_text_section
//bad: OLD (REENTRANT_GETNAME) (LOOKUP_TYPE *resbuf, char *buffer, size_t buflen,
//BAD:!!!!! 			 LOOKUP_TYPE **result H_ERRNO_PARM)
//bad: {


//BAD:!!!!! __libc_lock_define_recursive (typedef, _IO_lock_t)
#define __libc_lock_define_recursive(a,b) int foo;

//BAD:!!!!! __STD_TYPE __SWORD_TYPE __intptr_t;
#define __STD_TYPE

//BAD:!!!!! extern int	getopt P((int argc, char * const argv[],
//bad: 			const char * options));
//but conflict :( 
#define P(a) a

//BAD:!!!!! __STDIO_INLINE int
#define __STDIO_INLINE


//
//bad: extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
//BAD:!!!!!      __cleanup_fct_attribute;
//
//bad: void
//bad: __cleanup_fct_attribute __attribute ((noreturn))
//BAD:!!!!! __pthread_unwind (__pthread_unwind_buf_t *buf)
//bad: {
#define __cleanup_fct_attribute


//BAD:!!!!! FORWARD (pthread_attr_destroy, (pthread_attr_t *attr), (attr), 0)
#define FORWARD(a, b, c, d) int foo;


//bad: ARGP_FS_EI size_t
//BAD:!!!!! __argp_fmtstream_write (argp_fmtstream_t __fs,
#define ARGP_FS_EI 

//BAD:!!!!! ARGP_EI int
//bad: __NTH (__option_is_short (__const struct argp_option *__opt))
#define ARGP_EI

//
//BAD:!!!!! const STRUCT_CTYPE_CLASS(1, 0) _nl_C_LC_CTYPE_class_space attribute_hidden =
#define STRUCT_CTYPE_CLASS(a,b) 
//
//BAD:!!!!!   __libc_rwlock_define (, conversions_lock);
#define __libc_rwlock_define(a,b) int foo;
//
//BAD:!!!!!   __libc_rwlock_define_initialized (static, lock);
#define __libc_rwlock_define_initialized(a,b) int foo; 
//bad:   __libc_rwlock_rdlock (tree_lock);

//BAD:!!!!! 			       size_t len LOCALE_PARAM_PROTO) __THROW;
#define LOCALE_PARAM_PROTO


//bad:       bool tzset_called;
//BAD:!!!!!       ut_argument_spec
//bad:       LOCALE_PARAM_DECL
//

//
//bad:   struct
//bad:   {
//BAD:!!!!!     TMD_ERRET (size_t);
#define TMD_ERRET(a) a foo

//
//BAD:!!!!!       mp_limb_t base PACK;
//bad: #if UDIV_TIME > 2 * UMUL_TIME
//bad:       mp_limb_t base_ninv PACK;
#define PACK 

//
//BAD:!!!!!   TEST (creal (1.0 + 1.0i), sizeof (double));
//
//BAD:!!!!! __MATHDECL (_Mdouble_,cabs, (_Mdouble_complex_ __z));
#define __MATHDECL(a,b,c) a b c





/*
//BAD:!!!!!   GLRO(dl_mcount) ((ElfW(Addr)) RETURN_ADDRESS (0), (ElfW(Addr)) selfpc);
//BAD:!!!!!     GLRO(dl_mcount) ((ElfW(Addr)) RETURN_ADDRESS (0), (ElfW(Addr)) selfpc);
//
//bad: static int
//bad: AB(handle_file) (const char *fname, int fd)
//bad: {
//BAD:!!!!!   E(Ehdr) ehdr;
//bad: 
//
//bad: 
//bad: 
//bad: libc_freeres_fn (free_mem)
//BAD:!!!!! {
//bad:   struct link_map *l;
//
//	DL_DST_REQ_STATIC (l)						      \
//	if ((l)->l_origin == NULL)					      \
//	  {								      \

//BAD:!!!!! #include_next <siglist.h>






*/

