// time: ? 
//   10min + 20min + 10min: 96.72%

// ****************************************************************************
// Gcc (as in the source of gcc code) macros 
// ****************************************************************************
//BAD:!!!!! java_gimplify_self_mod_expr (tree *expr_p, gimple_seq *pre_p ATTRIBUTE_UNUSED, 
#define ATTRIBUTE_UNUSED

//BAD:!!!!! static void help (void) ATTRIBUTE_NORETURN;
#define ATTRIBUTE_NORETURN


//bad: static void ATTRIBUTE_PRINTF_1
//BAD:!!!!! debug_print (const char *fmt ATTRIBUTE_UNUSED, ...)
#define ATTRIBUTE_PRINTF_1

//BAD:!!!!! static GTY(()) tree base_decl_map;
#define GTY(a)

//BAD:!!!!!   VEC(int, heap) *map = (VEC(int, heap) *) arg;
#define VEC(a,b) a

//BAD:!!!!! static inline VEC(edge,gc) *
//bad: ei_container (edge_iterator i)



//BAD:!!!!! static void mark_reference_fields (tree, unsigned HOST_WIDE_INT *,
#define HOST_WIDE_INT int

//BAD:!!!!!   unsigned HOST_WIDEST_INT retval;
#define HOST_WIDEST_INT int

//BAD:!!!!! typedef unsigned HOST_WIDEST_FAST_INT HARD_REG_ELT_TYPE;
#define HOST_WIDEST_FAST_INT int


//BAD:!!!!!   ENUM_BITFIELD(languages) language : 4;
//BAD:!!!!!     ENUM_BITFIELD (scope_kind) kind : 4;
#define ENUM_BITFIELD(a) int

//BAD:!!!!!   void (*p_msg) (const char *, ...) ATTRIBUTE_GCC_CXXDIAG(1,2);
//BAD:!!!!! typedef void (*diagnostic_fn_t) (const char *, ...) ATTRIBUTE_GCC_CXXDIAG(1,2);
//BAD:!!!!!   void (*p_msg) (const char *, ...) ATTRIBUTE_GCC_CXXDIAG(1,2);
#define ATTRIBUTE_GCC_CXXDIAG(a,b) 

//BAD:!!!!!      ATTRIBUTE_GCC_PPDIAG(2,3);
#define ATTRIBUTE_GCC_PPDIAG(a,b) 

//BAD:!!!!! extern void error (const char *, ...) ATTRIBUTE_GCC_DIAG(1,2);
#define ATTRIBUTE_GCC_DIAG(a,b) 

//BAD:!!!!! extern void pedwarn_c99 (int opt, const char *, ...) ATTRIBUTE_GCC_CDIAG(2,3);
#define ATTRIBUTE_GCC_CDIAG(a,b)

//bad: typedef struct gfc_symtree
//bad: {
//BAD:!!!!!   BBT_HEADER (gfc_symtree);
#define BBT_HEADER(a) 


//BAD:!!!!! HAIFA_INLINE static rtx
//bad: ready_element (struct ready_list *ready, int index)
#define HAIFA_INLINE




//bad: extern _Unwind_Reason_Code LIBGCC2_UNWIND_ATTRIBUTE
//BAD:!!!!! _Unwind_RaiseException (struct _Unwind_Exception *);
#define LIBGCC2_UNWIND_ATTRIBUTE


//BAD:!!!!! void gfc_warning (const char *, ...) ATTRIBUTE_GCC_GFC(1,2);
//BAD:!!!!! void gfc_error (const char *, ...) ATTRIBUTE_GCC_GFC(1,2);
#define ATTRIBUTE_GCC_GFC(a,b) 

//bad: 	  EXECUTE_IF_SET_IN_BITMAP (gimple_call_clobbered_vars (cfun), 0, i, bi)
//bad:     {
//bad: 	      tree var = referenced_var (i);
//bad: 	      add_stmt_operand (&var, stmt, opf_def | opf_implicit);
//bad: 	    }
#define EXECUTE_IF_SET_IN_BITMAP(a,b,c,d) if(1)

#define EXECUTE_IF_SET_IN_SBITMAP(a,b,c,d) if(1)

//bad:   EXECUTE_IF_AND_COMPL_IN_BITMAP (refs, sm_executed, 0, i, bi)
#define EXECUTE_IF_AND_COMPL_IN_BITMAP(a,b,c,d) if(1)

#define EXECUTE_IF_SET_IN_SPARSESET(a,b) if(1)

//bad: 	      EXECUTE_IF_IN_NONNULL_BITMAP (graph->succs[i], 0, j, bi)
#define EXECUTE_IF_IN_NONNULL_BITMAP(a,b,c,d) if(1)

//bad:   EXECUTE_IF_SET_IN_REG_SET (&spilled_pseudos, FIRST_PSEUDO_REGISTER, i, rsi)
#define EXECUTE_IF_SET_IN_REG_SET(a,b,c,d) if(1)


//BAD:!!!!! extern void error (const char *, ...) ATTRIBUTE_PRINTF_1 ATTRIBUTE_COLD;
#define ATTRIBUTE_COLD

//bad: static void ATTRIBUTE_PRINTF_2
//BAD:!!!!! db (int db_code, char * msg_format, ...)
//bad: {
#define ATTRIBUTE_PRINTF_1
#define ATTRIBUTE_PRINTF_2
#define ATTRIBUTE_PRINTF_3
#define ATTRIBUTE_PRINTF_4

#define ATTRIBUTE_NULL_PRINTF_1
#define ATTRIBUTE_NULL_PRINTF_2
#define ATTRIBUTE_NULL_PRINTF_3
#define ATTRIBUTE_NULL_PRINTF_4


//bad: static FRV_INLINE bool
//BAD:!!!!! frv_small_data_reloc_p (rtx symbol, int reloc)
#define FRV_INLINE


//bad: extern void *__deregister_frame_info (const void *)
//BAD:!!!!! 				      TARGET_ATTRIBUTE_WEAK;
#define TARGET_ATTRIBUTE_WEAK


//BAD:!!!!! extern int __gcov_execl (const char *, const char *, ...) ATTRIBUTE_HIDDEN;
#define ATTRIBUTE_HIDDEN

//bad: static inline int
//BAD:!!!!! __gthread_objc_mutex_unlock (objc_mutex_t mutex UNUSED)
#define UNUSED

//BAD:!!!!! static EH_FRAME_SECTION_CONST char __EH_FRAME_BEGIN__[]
#define EH_FRAME_SECTION_CONST

//BAD:!!!!!   return __extension__ (__m64)(__v2sf){ __A, 0.0f };
#define __extension__


//bad: GCOV_LINKAGE gcov_unsigned_t
//BAD:!!!!! gcov_read_unsigned (void)
#define GCOV_LINKAGE



//BAD:!!!!! typedef unsigned _Fract UDAtype __attribute__ ((mode (UDA)));
#define _Fract 

//BAD:!!!!! typedef _Complex float XCtype	__attribute__ ((mode (XC)));
#define _Complex




//BAD:!!!!! 	    ((NONCONST def_dec_info *) prev)->next_in_file = def_dec_p;
#define NONCONST



//bad: tree
//BAD:!!!!! copy_node_stat (tree node MEM_STAT_DECL)
#define MEM_STAT_DECL

//BAD:!!!!! STATIC void
#define STATIC static

//PB false positif: 
//BAD:!!!!! char __gnat_shared_libgnat_default = STATIC;
//ERROR-RECOV: found sync col 0 at line 108


//BAD:!!!!! 	CASE_FLT_FN (BUILT_IN_LLCEIL):
#define CASE_FLT_FN(a) case a

//BAD:!!!!!     CASE_INT_FN (BUILT_IN_FFS):
#define CASE_INT_FN(a) case a


//BAD:!!!!! #include_next <limits.h>		/* recurse down to the real one */

/*
//BAD:!!!!! extern int CMA$_EXIT_THREAD;
//
//BAD:!!!!! TXT("------------------------------------------------------------------------------")
//bad: TXT("--                                                                          --")

BAD:!!!!! extern vector unsigned int __mfc_tag_table;
BAD:!!!!!   vector unsigned int table_copy, tmp, tmp1;

BAD:!!!!!   vec_st((vec_uchar16)(a), si_to_uint(b) & ~0xF, (vector unsigned char *)(imm));


BAD:!!!!! extern CONST_MODE_SIZE unsigned char mode_size[NUM_MACHINE_MODES];
BAD:!!!!! extern CONST_MODE_IBIT unsigned char mode_ibit[NUM_MACHINE_MODES];


pad: why pb ?
 = File "/home/pad/software-src/devel/gcc-svn/gcc/hard-reg-set.h", line 432, column 0,  charpos = 14162
    around = '', whole content = 
ERROR-RECOV: found sync end of #define 431
badcount: 6
bad:        *scan_tp_++ |= *scan_fp_++; } while (0)
bad: 
bad: #define IOR_COMPL_HARD_REG_SET(TO, FROM)  \
bad: do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\
bad:      int i;							\
bad:      for (i = 0; i < HARD_REG_SET_LONGS; i++)			\
BAD:!!!!!        *scan_tp_++ |= ~ *scan_fp_++; } while (0)

*/
