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
// Yacc macros
// ****************************************************************************

#define YY_PROTO(x) x
#define yyconst const


// ****************************************************************************
// GNU Hello macros
// ****************************************************************************

#define __getopt_argv_const const


// ****************************************************************************
// Gcc (as in the source of gcc code) macros
// ****************************************************************************


// ****************************************************************************
// Linux macros
// ****************************************************************************

// ----------------------------------------------------------------------------
// Attributes. could perhaps generalize via "__.*"
// ----------------------------------------------------------------------------
#define  __init
#define  __exit
#define  __user
#define  __iomem
#define  __initdata
#define  __exitdata
#define  __devinit
#define  __devexit
#define  __devinitdata
#define  __cpuinit
#define  __cpuinitdata
#define  __init_or_module
#define  __initdata_or_module
#define  __pminit
#define  __pminitdata

#define  __cacheline_aligned
#define  ____cacheline_aligned
#define  __cacheline_aligned_in_smp
#define  ____cacheline_aligned_in_smp
#define  ____cacheline_internodealigned_in_smp

#define  __ALIGNED__
#define  __3xp_aligned

#define  __pmac
#define  __force
#define  __nocast
#define  __read_mostly

#define  __must_check
// pb
#define  __unused
#define  __maybe_unused


#define  __attribute_used__
#define  __attribute_pure__
#define  __attribute_const__
// #define _attribute__const __attribute__((const))

#define  __always_inline

#define  __xipram

// in the other part of the kernel, in arch/, mm/, etc
#define  __sched
#define  __initmv
#define  __exception
#define  __cpuexit
#define  __kprobes
#define  __meminit
#define  __meminitdata
#define  __nosavedata
#define  __kernel
#define  __nomods_init
#define  __apicdebuginit
#define  __ipc_init
#define  __modinit
#define  __lockfunc
#define  __weak
#define  __tlb_handler_align
#define  __lock_aligned
#define  __force_data
#define  __nongprelbss
#define  __nongpreldata
#define  __noreturn

#define  __section_jiffies
#define  __vsyscall_fn
#define  __section_vgetcpu_mode
#define  __section_vsyscall_gtod_data

// in header files
#define  __bitwise
#define  __bitwise__
#define  __deprecated


// last found
#define __init_refok


// maybe only in old kernel
#define  __openfirmware


#define __extension__

#define __thread
#define __used
#define __pure

#define __ref
#define __refdata

#define __uses_jump_to_uncached

// ----------------------------------------------------------------------------
// String macros
// ----------------------------------------------------------------------------

/* string macro. normally handle quite well by mu lalr(k), but
 * sometimes not enough, if have for instance the XX YY case, could
 * be considered as a declaration with XX being a typedef, so would
 * Have ambiguity. So at least by adding this special case, we can
 * catch more correct string-macro, no more a XX YY but now a good
 * "XX" YY
 *
 * cf include/linux/kernel.h
 *
 * For stringification I need to have at least a witness, a string,
 * and sometimes have just printk(KERN_WARNING MYSTR) and it could
 * be transformed in a typedef later, so better to at least
 * transform in string already the string-macro we know.
 *
 * Perhaps better to apply also as soon as possible the
 * correct macro-annotation tagging (__init & co) to be able to
 * filter them as soon as possible so that they will not polluate
 * our pattern-matching that come later.
 */

#define  KERN_EMERG "KERN_EMERG"
#define  KERN_ALERT "KERN_ALERT"
#define  KERN_CRIT "KERN_CRIT"
#define  KERN_ERR "KERN_ERR"
#define  KERN_WARNING "KERN_WARNING"
#define  KERN_NOTICE "KERN_NOTICE"
#define  KERN_INFO "KERN_INFO"
#define  KERN_DEBUG "KERN_DEBUG"


/* EX_TABLE & co.
 *
 * Replaced by a string. We can't put everything as comment
 * because it can be part of an expression where we wait for
 * something, where we wait for a string. So at least we
 * must keep the EX_TABLE token and transform it as a string.
 *
 * normally not needed if have good stringification of macro
 * but those macros are sometimes used multiple times
 * as in EX_TABLE(0b) EX_TABLE(1b)  and we don't detect
 * it well yet.
 */

// TODO don't use x :(
#define EX_TABLE(x)  "TOTO"
#define ASM_EXCEPTIONTABLE_ENTRY(x)  "TOTO"
#define DCACHE_CLEAR(x) "TOTO"
#define PPC405_ERR77(x)  "TOTO"




// ----------------------------------------------------------------------------
// Alias keywords
// ----------------------------------------------------------------------------
// pb, false positive, can also be a #define cst and use as 'case CONST:'
//#define CONST const


#define STATIC static
#define _static static

#define  noinline

#define  __CS4231_INLINE__ inline
#define  CCIO_INLINE inline
#define  SBA_INLINE  inline

#define  STATIC_INLINE static inline
#define  __EXTERN_INLINE extern inline

#define  AGPEXTERN extern

#define  PNMI_STATIC static
#define  RLMT_STATIC static
#define  SISINITSTATIC static
#define  SCTP_STATIC static

#define  BUGLVL if
#define  IFDEBUG if

#define  TRACE_EXIT return


// ----------------------------------------------------------------------------
// linkage
// ----------------------------------------------------------------------------

#define  fastcall
#define  asmlinkage

#define  far
#define  SK_FAR

// pb
//#define  near


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

#define  INITSECTION

#define  NORET_TYPE

#define  compat_init_data

#define  DIVA_EXIT_FUNCTION
#define  DIVA_INIT_FUNCTION
#define  ACPI_SYSTEM_XFACE

#define  ASC_INITDATA
#define  in2000__INITDATA
#define  PACKED

#define  WPMINFO
#define  CPMINFO
#define  PMINFO

#define  ACPI_INTERNAL_VAR_XFACE

#define  SISIOMEMTYPE

#define  ACPI_STATE_COMMON
#define  ACPI_PARSE_COMMON
#define  ACPI_COMMON_DEBUG_MEM_HEADER


#define  nabi_no_regargs


#define  ATTRIB_NORET
#define  ATTRIBUTE_UNUSED
#define  BTEXT
#define  BTDATA
#define  PAGE_ALIGNED

#define  EARLY_INIT_SECTION_ATTR

// pb
//#define  INIT

#define  IDI_CALL_ENTITY_T
#define  IDI_CALL_LINK_T

/* cf gcc-linux.h
 * A trick to suppress uninitialized variable warning without generating any
 * code
 */
#define uninitialized_var(x) x = x
// as in u16 uninitialized_var(ioboard_type);	/* GCC be quiet */

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

#define __releases(x)
#define __acquires(x)
#define __declspec(x)
#define __page_aligned(x)
#define __vsyscall(x)

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


//conflict with a macro of firefox
//#define FASTCALL(x) x
#define PARAMS(x) x



// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// include/asm-arm/mach/arch.h
// #define MACHINE_START(x) struct foo { x }
#define MACHINE_START(_type,_name)			\
static const struct machine_desc __mach_desc_##_type	\
/* __used*/							\
 __attribute__((__section__(".arch.info.init"))) = {	\
	.nr		= MACH_TYPE_##_type,		\
	.name		= _name,

#define MACHINE_END				\
};

// include/asm-powerpc/machdep.h
#define define_machine(name)                                    \
         extern struct machdep_calls mach_##name;                \
         EXPORT_SYMBOL(mach_##name);                             \
         struct machdep_calls mach_##name /*__machine_desc*/ =


// ----------------------------------------------------------------------------
// Declare like macros (in structure def), or tricky Declare macros
// ----------------------------------------------------------------------------

// include/asm-i386/pci.h
// the DECLARE are detected by parsing_hack but not when they are
// inside a struct def.
#define DECLARE_PCI_UNMAP_ADDR(ADDR_NAME)
#define DECLARE_PCI_UNMAP_LEN(LEN_NAME)

// defined in drivers/infiniband/hw/mthca/mthca_doorbell.h
#define MTHCA_DECLARE_DOORBELL_LOCK(doorbell_lock)

// include/linux/types.h
//#define BITS_TO_LONGS(bits) \
//	(((bits)+BITS_PER_LONG-1)/BITS_PER_LONG)
#define DECLARE_BITMAP(name,bits) \
	/*unsigned*/ long name[BITS_TO_LONGS(bits)]


// include/asm-i386/percpu.h
// interesting macro where we see the need of __typeof__(type) with
// for example DECLARE_PER_CPU(char[256], iucv_dbf_txt_buf);
#define DEFINE_PER_CPU(type, name) \
    __attribute__((__section__(".data.percpu"))) __typeof__(type) per_cpu__##name
#define DECLARE_PER_CPU(type, name) extern __typeof__(type) per_cpu__##name



// include/linux/kobject.h
#define decl_subsys(_name,_type,_uevent_ops) \
struct subsystem _name##_subsys = { \
        .kset = { \
                .kobj = { .name = __stringify(_name) }, \
                .ktype = _type, \
                .uevent_ops =_uevent_ops, \
        } \
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// pb: if use this macro then we will not transform the argument of CS_CHECK
// in some rules.
//#define CS_CHECK(fn, ret) \
//  do { last_fn = (fn); if ((last_ret = (ret)) != 0) goto cs_failed; } while (0)


// bt2/hci_bcsp.c
#define BCSP_CRC_INIT(x) x = 0xffff


// sound/oss/cs46xx_wrapper-24.h
#define CS_OWNER .owner =
#define CS_THIS_MODULE THIS_MODULE,


// sound/sparc/dbri.c
// "bad macro", have a ',' at the end
#define CS4215_SINGLE(xname, entry, shift, mask, invert) \
{ .iface = SNDRV_CTL_ELEM_IFACE_MIXER, .name = xname, \
  .info = snd_cs4215_info_single, \
  .get = snd_cs4215_get_single, .put = snd_cs4215_put_single, \
  .private_value = entry | (shift << 8) | (mask << 16) | (invert << 24) },

// drivers/media/video/sn9c102/sn9c102_sensor.h
//#define sn9c102_write_const_regs(sn9c102_device, data...)                     \
//	({ const static u8 _valreg[][2] = {data};                             \
//	sn9c102_write_regs(sn9c102_device, _valreg, ARRAY_SIZE(_valreg)); })





// drivers/s390/cio/qdio.h
#define SYNC_MEMORY if (unlikely(q->siga_sync)) qdio_siga_sync_q(q)
#define SYNC_MEMORY_ALL if (unlikely(q->siga_sync)) \
	qdio_siga_sync(q,~0U,~0U)
#define SYNC_MEMORY_ALL_OUTB if (unlikely(q->siga_sync)) \
	qdio_siga_sync(q,~0U,0)

// drivers/scsi/g_NCR5380.c
#define ANDP ,


// drivers/scsi/ncr53c8xx.c
// generate lots of errors because error en cascade car dans l'initialiseur
// il y'a des '}' dans la premiere colonne
#define PREFETCH_FLUSH SCR_CALL, PADDRH (wait_dma),

// drivers/net/e100.c
// pbs false positive, defined in another manner in some files
//#define X(a,b)	a,b


// net/ipv4/netfilter/ip_conntrack_helper_h323_asn1.c
// also used in other.c that don't do any include :(
// but locally redefined in drivers/net/bnx2.c :( with a
// #define FNAME	0x8
#define FNAME(name) name,


// drivers/net/tulip/de4x5.c
#define DESC_ALIGN


// in .h
#define MPI_POINTER *

// mega4/soc.c mega4/socal.c
// cause false typedef inference if let soc_printk
#define soc_printk printk
#define socal_printk printk


// ----------------------------------------------------------------------------
// Initializer array macros
// ----------------------------------------------------------------------------

// drivers/net/wireless/bcm43xx/bcm43xx_wx.c
// defined in similar way multiple times, in the same file and in another one
#define WX(ioctl)  [(ioctl) - SIOCSIWCOMMIT]
// #define WX(x) [(x)-SIOCIWFIRST]

// drivers/net/wireless/ipw2200.c
#define IW_IOCTL(x) [(x)-SIOCSIWCOMMIT]

// drivers/net/wireless/zd1211rw/zd_netdev.c
#define PRIV_OFFSET(x) [(x)-SIOCIWFIRSTPRIV]

// drivers/net/wireless/zd1211rw/zd_rf.h
#define RF_CHANNEL(ch) [(ch)-1]

// drivers/net/wireless/zd1211rw/zd_rf_uw2453.c
#define RF_CHANPAIR(a,b) [CHAN_TO_PAIRIDX(a)]

// drivers/net/wireless/arlan-proc.c
// incomplete macro, the real macro is quite complex and use other macros
#define ARLAN_SYSCTL_TABLE_TOTAL(x)


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// drivers/net/cxgb3/t3_hw.c
#define VPD_ENTRY(name, len) \
	u8 name##_kword[2]; u8 name##_len; u8 name##_data[len]


// #define rtrc(i) {}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// drivers/video/nvidia/nv_type.h
// use:	SetBitField(h_blank_e, 5: 5, 7:7)
//#define BITMASK(t,b) (((unsigned)(1U << (((t)-(b)+1)))-1)  << (b))
//#define MASKEXPAND(mask) BITMASK(1?mask,0?mask)
//#define SetBF(mask,value) ((value) << (0?mask))
//#define GetBF(var,mask) (((unsigned)((var) & MASKEXPAND(mask))) >> (0?mask) )
//#define SetBitField(value,from,to) SetBF(to, GetBF(value,from))
//#define SetBit(n) (1<<(n))
//#define Set8Bits(value) ((value)&0xff)


// drivers/video/sis/init.c
// use: GETBITSTR((SiS_Pr->CVTotal     -2), 10:10, 0:0)
//#define BITMASK(h,l)    	(((unsigned)(1U << ((h)-(l)+1))-1)<<(l))
//#define GENMASK(mask)   	BITMASK(1?mask,0?mask)
//#define GETBITS(var,mask)   	(((var) & GENMASK(mask)) >> (0?mask))
//#define GETBITSTR(val,from,to)  ((GETBITS(val,from)) << (0?to))


// fs/afs/internal.h
#define ASSERTCMP(X, OP, Y)						\
do {									\
	if (unlikely(!((X) OP (Y)))) {					\
		printk(KERN_ERR "\n");					\
		printk(KERN_ERR "AFS: Assertion failed\n");		\
		printk(KERN_ERR "%lu " /*#OP*/ " %lu is false\n",		\
		       (unsigned long)(X), (unsigned long)(Y));		\
		printk(KERN_ERR "0x%lx " /*#OP*/ " 0x%lx is false\n",	\
		       (unsigned long)(X), (unsigned long)(Y));		\
		BUG();							\
	}								\
} while(0)

#define ASSERTIFCMP(C, X, OP, Y)					\
do {									\
	if (unlikely((C) && !((X) OP (Y)))) {				\
		printk(KERN_ERR "\n");					\
		printk(KERN_ERR "AFS: Assertion failed\n");		\
		printk(KERN_ERR "%lu " /*#OP*/ " %lu is false\n",		\
		       (unsigned long)(X), (unsigned long)(Y));		\
		printk(KERN_ERR "0x%lx " /*#OP*/ " 0x%lx is false\n",	\
		       (unsigned long)(X), (unsigned long)(Y));		\
		BUG();							\
	}								\
} while(0)


#define ASSERTRANGE(L, OP1, N, OP2, H)					\
do {									\
	if (unlikely(!((L) OP1 (N)) || !((N) OP2 (H)))) {		\
		printk(KERN_ERR "\n");					\
		printk(KERN_ERR "AFS: Assertion failed\n");		\
		printk(KERN_ERR "%lu "/*#OP1*/" %lu "/*#OP2*/" %lu is false\n",	\
		       (unsigned long)(L), (unsigned long)(N),		\
		       (unsigned long)(H));				\
		printk(KERN_ERR "0x%lx "/*#OP1*/" 0x%lx "/*#OP2*/" 0x%lx is false\n", \
		       (unsigned long)(L), (unsigned long)(N),		\
		       (unsigned long)(H));				\
		BUG();							\
	}								\
} while(0)




// loop, macro without ';', single macro. ex: DEBUG()

// TODO should find the definition because we don't use 'x' and so
// may lose code sites with coccinelle. If expand correctly, will
// still don't transform correctly but at least will detect the place.




// Cooperation with parsing_hack.ml: MACROSTATEMENT is a magic string.
// I can't just expand those macros into some 'whatever();' because I need
// to generate a TMacroStmt for solving some ambiguities in the grammar
// for the toplevel stuff I think.
#define ASSERT(x) MACROSTATEMENT
#define IRDA_ASSERT(x) MACROSTATEMENT

#define CHECK_NULL(x) MACROSTATEMENT

//#define DEBUG(x) MACROSTATEMENT
#define DEBUG0(x) MACROSTATEMENT
#define DEBUG1(x) MACROSTATEMENT
#define DEBUG2(x) MACROSTATEMENT
#define DEBUG3(x) MACROSTATEMENT


#define DBG(x) MACROSTATEMENT
#define DEB(x) MACROSTATEMENT
#define PARSEDEBUG(x) MACROSTATEMENT
#define DEBC(x) MACROSTATEMENT
#define DBG_TRC(x) MACROSTATEMENT
#define DBG_ERR(x) MACROSTATEMENT
#define DBG_FTL(x) MACROSTATEMENT

#define DBGINFO(x) MACROSTATEMENT
#define DFLOW(x) MACROSTATEMENT
#define DFLIP(x) MACROSTATEMENT
#define DLOG_INT_TRIG(x) MACROSTATEMENT

#define D3(x) MACROSTATEMENT
#define D1(x) MACROSTATEMENT
#define DB(x) MACROSTATEMENT
#define DCBDEBUG(x) MACROSTATEMENT
#define SCSI_LOG_MLQUEUE(x) MACROSTATEMENT

#define PLND(x) MACROSTATEMENT
#define FCALND(x) MACROSTATEMENT
#define FCALD(x) MACROSTATEMENT

#define DEBUGRECURSION(x) MACROSTATEMENT

#define DEBUGPIO(x) MACROSTATEMENT
#define VDEB(x) MACROSTATEMENT

#define READ_UNLOCK_IRQRESTORE(x) MACROSTATEMENT

#define TRACE_CATCH(x) MACROSTATEMENT

#define PDBGG(x) MACROSTATEMENT

#define IF_ABR(x) MACROSTATEMENT
#define IF_EVENT(x) MACROSTATEMENT
#define IF_ERR(x) MACROSTATEMENT
#define IF_CBR(x) MACROSTATEMENT
#define IF_INIT(x) MACROSTATEMENT
#define IF_RX(x) MACROSTATEMENT

#define SOD(x) MACROSTATEMENT

#define KDBG(x) MACROSTATEMENT

#define IRDA_ASSERT_LABEL(x) MACROSTATEMENT





// ----------------------------------------------------------------------------
// Difficult foreach
// ----------------------------------------------------------------------------

// include/linux/sched.h
#define while_each_thread(g, t) \
        while ((t = next_thread(t)) != g)



// net/decnet/dn_fib.c
#define for_fib_info() { struct dn_fib_info *fi;\
	for(fi = dn_fib_info_list; fi; fi = fi->fib_next)
#define endfor_fib_info() }

#define for_nexthops(fi) { int nhsel; const struct dn_fib_nh *nh;\
	for(nhsel = 0, nh = (fi)->fib_nh; nhsel < (fi)->fib_nhs; nh++, nhsel++)

#define change_nexthops(fi) { int nhsel; struct dn_fib_nh *nh;\
	for(nhsel = 0, nh = (struct dn_fib_nh *)((fi)->fib_nh); nhsel < (fi)->fib_nhs; nh++, nhsel++)

#define endfor_nexthops(fi) }


// ----------------------------------------------------------------------------
// Macros around function prototype
// ----------------------------------------------------------------------------


// net/sched/em_meta.c
#define META_COLLECTOR(FUNC) static void meta_##FUNC(struct sk_buff *skb, \
	struct tcf_pkt_info *info, struct meta_value *v, \
	struct meta_obj *dst, int *err)


#define GDTH_INITFUNC(x,y) x y
#define ASC_INITFUNC(x,y) x y


// ----------------------------------------------------------------------------
// If-like macros
// ----------------------------------------------------------------------------

// include/linux/lockd/debug.h
// include/linux/nfs_fs.h
// include/linux/nfsd/debug.h
// include/linux/sunrpc/debug.h
//#define ifdebug(flag)          if (unlikely(nlm_debug & NLMDBG_##flag))
#define ifdebug(flag)          if (0)



// ----------------------------------------------------------------------------
//#define __PROM_O32

// ----------------------------------------------------------------------------
// for tests-big/ macros, may be obsolete now cos fixed in latest kernel
// ----------------------------------------------------------------------------

// rule10
//#define	 ACPI_MODULE_NAME(x)




// ****************************************************************************
// Httpd (apache) macros
// ****************************************************************************

#define AP_DECLARE(x) x
#define PROXY_DECLARE(x) x
#define CACHE_DECLARE(x) x
#define DBD_DECLARE_NONSTD(x) x
#define DAV_DECLARE(x) x
#define APU_DECLARE(x) x
#define APU_DECLARE_NONSTD(x) x
#define APR_DECLARE(x) x
#define AP_CORE_DECLARE(x) x
#define AP_DECLARE_NONSTD(x) x
#define AP_CORE_DECLARE_NONSTD(x) x
#define APR_OPTIONAL_FN_TYPE(x) x
#define DAV_DECLARE_NONSTD(x) x
#define APR_DECLARE_NONSTD(x) x

#define APU_DECLARE_DATA
#define APR_THREAD_FUNC
#define AP_DECLARE_DATA
#define PROXY_DECLARE_DATA
#define AP_MODULE_DECLARE_DATA
#define APR_DECLARE_DATA



#define APR_INLINE inline
#define EXPORT static
#define REGISTER register

#define MODSSL_D2I_SSL_SESSION_CONST const
#define MODSSL_D2I_X509_CONST const
#define MODSSL_D2I_PrivateKey_CONST const
#define MODSSL_D2I_SSL_SESSION_CONST const

#define STACK_OF(X509_NAME) X509_NAME

#define MODSSL_PCHAR_CAST  (pchar)

#define WINAPI
//#define CALLBACK
// generate false positive in Linux
#define APIENTRY
#define __declspec(x)
#define __stdcall


//#define module struct xxx

#define APR_POOL_IMPLEMENT_ACCESSOR(shm)

#define ADD_SUITE(suite) suite;

// ****************************************************************************
// CISCO vpn client macros
// ****************************************************************************

// #define NOREGPARM
// #define IN
// #define OUT
// #define OPTIONAL



// ****************************************************************************
// minix3 macros
// ****************************************************************************

//#define PUBLIC
//#define PRIVATE
//#define EXTERN
//#define FORWARD
//#define _PROTOTYPE(a,b) a b
//#define _CONST

// ****************************************************************************
// Sparse macros
// ****************************************************************************

#define FORMAT_ATTR(pos)

// END_FOR_EACH_PTR_REVERSE

#define RECURSE_PTR_REVERSE(insn, dom) for(;;)
#define END_FOR_EACH_PTR_REVERSE(dom)

#define IDENT_RESERVED(a)
#define IDENT(a)

// ****************************************************************************
// git macros
// ****************************************************************************

// #define NORETURN __attribute__((noreturn))
#define NORETURN

// ****************************************************************************
// elsa macros
// ****************************************************************************



// ****************************************************************************
// Qemu macros
// ****************************************************************************

// OPPROTO
// always_inline
// IO_WRITE_PROTO

// QEMU_LIST_HEAD
// QEMU_LIST_ENTRY

// ****************************************************************************
// Xen macros
// ****************************************************************************

// STATUS_PARAM
// IO_WRITE_PROTO

// XEN_GUEST_HANDLE

// ****************************************************************************
// mysql macros
// ****************************************************************************

#define LINT_SET_PTR

#define TESTCASE(a,b) void test_foo()

#define TAOCRYPT_CDECL
#define TAOCRYPT_NAKED
#define TAOCRYPT_FASTCALL


#define UNIV_INLINE

//   STATIC_CONST( SignalLength = 2 );
#define STATIC_CONST(xassign) static const int xassign

#define ATTRIBUTE_FORMAT(a,b,c)


#define UT_LIST_BASE_NODE_T(a) a
#define UT_LIST_NODE_T(a) a

#define NEAR_F
#define STDCALL

// ****************************************************************************
// sqlite
// ****************************************************************************

// used in firefox



#define SQLITE_EXTERN extern

#define SQLITE_PRIVATE
#define SQLITE_API


#define  sqlite3ParserARG_SDECL                /* A place to hold %extra_argument */

// ****************************************************************************
// jpeg
// ****************************************************************************

// used in firefox

#define jpeg_common_fields

// conflict with minix
#define EXTERN(a) a
#define JPP(x) x


// ****************************************************************************
// firefox macros (for C code)
// ****************************************************************************

#define NSPR_BEGIN_EXTERN_C


#define EXTERN_C_WITHOUT_EXTERN

#define JMC_PUBLIC_API(a) a


#define afx_msg


#define __P(a) a

#define cairo_private static
#define cairo_public
#define cairo_private_no_warn

#define CG_EXTERN extern

#define XMLPARSEAPI

#define _Xconst const

/* linux also use FASTCALL but as a DefineFunc, not DefineVar, todo my
 * hash allow this ? */

#define FASTCALL

#define FAR
#define NEAR

#define PIXMAN_EXPORT

#define MODULE_PRIVATE static

#define METHODDEF(x) x
#define GLOBAL(x) x
#define LOCAL(x) x

//#define pascal
//#define local static


#define JNIEXPORT
#define JNICALL

#define JS_STATIC_DLL_CALLBACK(x) x

#define JS_DLL_CALLBACK



#define JSD_PUBLIC_API(x) x
#define JS_EXPORT_API(x) x

#define ZONE_INLINE

#define LCMSEXPORT
#define LCMSAPI

#define cdecl

#define PNGAPI
#define PNG_CONST const

#define VR_INTERFACE(x) x

#define ZEXPORT

#define PR_IMPLEMENT(x) x
#define PR_CALLBACK

#define GCPTR


#define JS_IMPORT_DATA(x) x

#define NS_EXTERNAL_VIS_(x) x

#define XPT_PUBLIC_API(x) x

#define NSS_EXTERN extern
#define NSS_IMPLEMENT

#define PR_EXTERN(x) x

//define local static
//#define vector

#define PL_DHASH_FASTCALL

#define PR_STATIC_CALLBACK static


#define LL_CMP(a,op,b) a op b

#define UNTIL(x) while(!(x))


#define CAIRO_PRINTF_FORMAT(a,b)

#define PREFIX(a) a


#define JMETHOD(a, b, c) a b c

#define _inline

#define JS_EXTERN_API(x) x

#define FARDATA

#define XMLCALL
#define PTRCALL
#define PTRFASTCALL

#define NSS_IMPLEMENT_DATA

// ****************************************************************************
// firefox macros (for C++ code)
// ****************************************************************************

#define G_BEGIN_DECLS
#define G_END_DECLS

#define __BEGIN_DECLS
#define __END_DECLS

#define CALLBACK

#define G_CONST_RETURN


//sure ?
#define NS_IMETHODIMP void

#define CPP_THROW_NEW

#define NS_LINEBREAK "toto"

#define PR_STATIC_CALLBACK(x) x


#define NS_IMETHODIMP_(x) x



#define NS_IMETHOD void
#define NS_IMETHOD_(a) a

#define NS_METHOD void

// cast function syntax
//#define PRUnichar(x) (char)(x)
//#define PRInt32(x) (char)(x)


#define NS_IF_ADDREF(e) e


#define DECL_DHASH_WRAPPER(a,b,c)


#define NS_STDCALL_FUNCPROTO(a,b,c,d,e) a b

#define NS_HTML_CONTENT_INTERFACE_MAP_BEGIN(a,b)
#define NS_HTML_CONTENT_INTERFACE_MAP_END

//#define MOZCE_SHUNT_API static
#define MOZCE_SHUNT_API


//but normally should be detected by the heuristic on macro noptvirg
#define MOZCE_PRECHECK

#define CONST const

#define LDAP_CALLBACK
#define LDAP_C


#define STDMETHODIMP_(x) x
#define STDMETHODIMP void

#define __RPC_FAR


#define EXTERN_C

#define CDECL


#define MORK_LIB_IMPL(a) a



#define PR_PUBLIC_API(x) x

#define PR_BEGIN_EXTERN_C
#define PR_END_EXTERN_C


#define JS_BEGIN_EXTERN_C
#define JS_END_EXTERN_C


#define JM_OJIAPITest(a) int a()
#define JNI_OJIAPITest(a) int a()
#define TM_OJIAPITest(a) int a()
#define LCM_OJIAPITest(a) int a()

#define NS_EXPORT
#define NP_EXPORT

#define NP_LOADDS
#define OSCALL
#define _System
#define EXPENTRY

#define LOAD_DS
#define LOADDS

#define NS_COM
#define NS_COM_OBSOLETE
#define NS_COM_GLUE


#define PASCAL


#define MOZILLA_NATIVE(a) a
#define GRE_NATIVE(a) a
#define XPCOM_NATIVE(a) a
#define JXM_NATIVE(a) a

#define JX_EXPORT

//pad: lots of xxx_EXPORT

#define PYXPCOM_EXPORT

//#define NS_STATIC_CAST(a,b) static_cast<a>(b)
#define NS_STATIC_CAST(a,b) (a) (b)

#define STDMETHODCALLTYPE
#define __cdecl

#define VFTCALL

#define TEST_OUT_PTR(x)

#define CWPLUGIN_ENTRY(a) void a

//FORWARD_TO_OUTER_VOID(ReallyCloseWindow, ());
#define FORWARD_TO_OUTER(a,b,c)
#define FORWARD_TO_OUTER_VOID(a,b)
#define FORWARD_TO_INNER(a,b,c)
#define FORWARD_TO_INNER_VOID(a,b,c)
#define FORWARD_IACCESSIBLEACTION(a)
#define FORWARD_IACCESSIBLETEXT(a)

#define ExportFunc

#define BEGIN_MESSAGE_MAP(a,b)
#define END_MESSAGE_MAP()

#define DECLARE_MESSAGE_MAP()

#define BEGIN_EVENT_TABLE(a,b)
#define END_EVENT_TABLE()

#define BEGIN_OBJECT_MAP(a)
#define END_OBJECT_MAP()

#define BEGIN_DISPATCH_MAP(a,b)
#define END_DISPATCH_MAP()

#define __pin

#define NS_STRINGAPI(a) a

#define XPTC_PUBLIC_API(a) a


#define NS_GFX_(a) a

#define WIDGET_SUPPORT_EXPORT(a) a

// but should be detected as a macro noptvirg ...
#define GET_TM_FOR_TEST
#define GET_LCM_FOR_TEST



#define NS_HIDDEN
#define NS_HIDDEN_(a) a

// BAD:!!!!!   if NS_SUCCEEDED(rv)
// but sometimes they define it as inline
//#define NS_SUCCEEDED(a) ((a))


#define MAPI_IMPLEMENT(a) a



// in initializer, pb cos miss some ','
#define REFERENCE_METHOD_FAMILY(CallObjectMethod)

#define TX_DOUBLE_COMPARE(a,b,c) (a b c)


#define LL_UCMP(a,op,b) a op b


#define GSS_MAKE_TYPEDEF
#define GSS_CALL_CONV
#define GSS_FUNC(a) a


// ****************************************************************************
// firefox macros (for headers, both C and C++ I guess)
// ****************************************************************************



#define NS_IMPLEMENT_FULLVISITRESULT


#define _MD_NEW_LOCK(a) a
#define _PR_MD_PRE_CLEANUP(a) a

#define NSPR_API(a) a

#define NSS_EXTERN_DATA
#define MPI_ASM_DECL


#define SEC_BEGIN_PROTOS
#define SEC_END_PROTOS

#define OF(a) a

#define SSL_IMPORT

#define LDAP_API(a) a

#define LDAP_CALL



#define PNG_EXPORT(a,b) a b
#define PNGARG(a) a


//#define NS_IMPL_CLASS_GETSET_STR(a, b) a b

#define NS_DEFINE_STATIC_IID_ACCESSOR(a)

#define MOZ_DECL_CTOR_COUNTER(a)

//#define ipcMessageCast static_cast


#define NS_DECL_ISUPPORTS
// now in parsing_hack2.ml
// grep "BAD:.*NS_IMPL" firefox_parse_h++_error2
// grep "BAD:.*NS_INTERFACE" firefox_parse_h++_error2
//#define TX_DECL_EVAL_CONTEXT




#define __gc


#define __try try
//TODO!!!!!!!!!
#define __except(a) catch(foo)



#define DECL_IUNKNOWN_INHERITED


// :) in windows code
#define __out
#define __in
#define __inout
#define __in_ecount(a)
#define __in_opt
#define __out_opt
#define __in_ecount_opt(a)
#define __out_ecount_opt(a)


#define NS_STACK_CLASS

#define NS_SPECIALIZE_TEMPLATE // template <>

#define NS_DOM_INTERFACE_MAP_ENTRY_CLASSINFO(a)


#define IMPL_ADD_LISTENER(a)
#define IMPL_REMOVE_LISTENER(a,b)


#define ATL_NO_VTABLE

#define DECLARE_DYNCREATE(a)

#define GTKMOZEMBED_API(a,b,c) a b c
#define DECLARE_EVENT_TABLE()

#define NS_EXPORT_STATIC_MEMBER_(a) a

#define CAIRO_BEGIN_DECLS
#define CAIRO_END_DECLS

#define __internal_linkage

#define THEBES_API

#define JS_PUBLIC_API(a) a
#define JS_FRIEND_API(a) a

#define VFTDELTA_DECL(a)


#define MY_UNKNOWN_IMP

#define CTOKEN_IMPL_SIZEOF

#define CALLBACK_API_C(a,b) a(b)

#define NS_DEFINE_STATIC_CID_ACCESSOR(a)



#define CK_PTR

#define JRI_PUBLIC_API(a) a

#define NS_DEFINE_CONSTRUCTOR_DATA(a,b)


#define NS_STID_FOR_INDEX(a) while(a)
#define NS_STID_FOR_ID(a) while(a)
#define NS_FOR_CSS_SIDES(a) while(a)

//hehe :)
#define NS_OUTPARAM


#define CIPtr(a) CI<a>


#define _stdcall

#define STDAPICALLTYPE
#define STDAPI_(x) x


#define NS_CONVERTER_REGISTRY_START
#define NS_CONVERTER_REGISTRY_END

#define NS_NEVER_INLINE

#define JS_DHASH_FASTCALL

#define JS_FRIEND_DATA(a) a

#define JS_INLINE inline

#define JS_STATIC_INTERPRET static


#define JSLL_CMP(a,b,c) (a b c)

#define NS_COM_MAP_BEGIN(a)
#define NS_COM_MAP_END

#define OBJECT_ENTRY(a,b)

// but mostly valid, should perhaps comment it, generates lots of passed:
// NS_ENSURE_TRUE(window, /**/);
#define NS_ENSURE_TRUE(a,b)

#define DECL_STYLE_RULE_INHERIT

#define NP_CALLBACK


#define UP_IMPL_NSISUPPORTS


#define MAKE_SAFE_VFT(a,b) a b =
#define VFTFIRST_VAL()
#define SAFE_VFT_ZEROS()


#define _JNI_IMPORT_OR_EXPORT_

#define NS_WIDGET

#define EXPORT_XPCOM_API(a) a
#define XPCOM_API(a) a

// ****************************************************************************
// diffutils
// ****************************************************************************

#define XTERN

