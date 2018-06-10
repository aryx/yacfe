# 1 "drivers/block/floppy.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "./include/linux/autoconf.h" 1
# 1 "<command line>" 2
# 1 "drivers/block/floppy.c"
# 155 "drivers/block/floppy.c"
static int print_unex = 1;
# 1 "include/linux/module.h" 1
# 9 "include/linux/module.h"
# 1 "include/linux/spinlock.h" 1
# 49 "include/linux/spinlock.h"
# 1 "include/linux/preempt.h" 1
# 9 "include/linux/preempt.h"
# 1 "include/linux/thread_info.h" 1
# 13 "include/linux/thread_info.h"
struct restart_block {
 long (*fn)(struct restart_block *);
 unsigned long arg0, arg1, arg2, arg3;
};

extern long do_no_restart_syscall(struct restart_block *parm);

# 1 "include/linux/bitops.h" 1


# 1 "include/asm/types.h" 1





typedef unsigned short umode_t;






typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;


typedef __signed__ long long __s64;
typedef unsigned long long __u64;
# 39 "include/asm/types.h"
typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;

typedef signed int s32;
typedef unsigned int u32;

typedef signed long long s64;
typedef unsigned long long u64;






typedef u32 dma_addr_t;

typedef u64 dma64_addr_t;
# 4 "include/linux/bitops.h" 2





# 1 "include/asm/bitops.h" 1







# 1 "include/linux/compiler.h" 1
# 40 "include/linux/compiler.h"
# 1 "include/linux/compiler-gcc4.h" 1



# 1 "include/linux/compiler-gcc.h" 1
# 5 "include/linux/compiler-gcc4.h" 2
# 41 "include/linux/compiler.h" 2
# 9 "include/asm/bitops.h" 2
# 1 "include/asm/alternative.h" 1




# 1 "include/linux/stddef.h" 1
# 15 "include/linux/stddef.h"
enum {
 false = 0,
 true = 1
};
# 6 "include/asm/alternative.h" 2
# 1 "include/linux/types.h" 1
# 14 "include/linux/types.h"
# 1 "include/linux/posix_types.h" 1
# 36 "include/linux/posix_types.h"
typedef struct {
 unsigned long fds_bits [(1024/(8 * sizeof(unsigned long)))];
} __kernel_fd_set;


typedef void (*__kernel_sighandler_t)(int);


typedef int __kernel_key_t;
typedef int __kernel_mqd_t;

# 1 "include/asm/posix_types.h" 1
# 10 "include/asm/posix_types.h"
typedef unsigned long __kernel_ino_t;
typedef unsigned short __kernel_mode_t;
typedef unsigned short __kernel_nlink_t;
typedef long __kernel_off_t;
typedef int __kernel_pid_t;
typedef unsigned short __kernel_ipc_pid_t;
typedef unsigned short __kernel_uid_t;
typedef unsigned short __kernel_gid_t;
typedef unsigned int __kernel_size_t;
typedef int __kernel_ssize_t;
typedef int __kernel_ptrdiff_t;
typedef long __kernel_time_t;
typedef long __kernel_suseconds_t;
typedef long __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef int __kernel_daddr_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;

typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned short __kernel_old_dev_t;


typedef long long __kernel_loff_t;


typedef struct {

 int val[2];



} __kernel_fsid_t;
# 48 "include/linux/posix_types.h" 2
# 15 "include/linux/types.h" 2




typedef __u32 __kernel_dev_t;

typedef __kernel_fd_set fd_set;
typedef __kernel_dev_t dev_t;
typedef __kernel_ino_t ino_t;
typedef __kernel_mode_t mode_t;
typedef __kernel_nlink_t nlink_t;
typedef __kernel_off_t off_t;
typedef __kernel_pid_t pid_t;
typedef __kernel_daddr_t daddr_t;
typedef __kernel_key_t key_t;
typedef __kernel_suseconds_t suseconds_t;
typedef __kernel_timer_t timer_t;
typedef __kernel_clockid_t clockid_t;
typedef __kernel_mqd_t mqd_t;


typedef _Bool bool;

typedef __kernel_uid32_t uid_t;
typedef __kernel_gid32_t gid_t;
typedef __kernel_uid16_t uid16_t;
typedef __kernel_gid16_t gid16_t;



typedef __kernel_old_uid_t old_uid_t;
typedef __kernel_old_gid_t old_gid_t;
# 58 "include/linux/types.h"
typedef __kernel_loff_t loff_t;
# 67 "include/linux/types.h"
typedef __kernel_size_t size_t;




typedef __kernel_ssize_t ssize_t;




typedef __kernel_ptrdiff_t ptrdiff_t;




typedef __kernel_time_t time_t;




typedef __kernel_clock_t clock_t;




typedef __kernel_caddr_t caddr_t;



typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;


typedef unsigned char unchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;




typedef __u8 u_int8_t;
typedef __s8 int8_t;
typedef __u16 u_int16_t;
typedef __s16 int16_t;
typedef __u32 u_int32_t;
typedef __s32 int32_t;



typedef __u8 uint8_t;
typedef __u16 uint16_t;
typedef __u32 uint32_t;


typedef __u64 uint64_t;
typedef __u64 u_int64_t;
typedef __s64 int64_t;
# 141 "include/linux/types.h"
typedef u64 sector_t;
# 150 "include/linux/types.h"
typedef u64 blkcnt_t;
# 181 "include/linux/types.h"
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;

typedef __u64 __le64;
typedef __u64 __be64;

typedef __u16 __sum16;
typedef __u32 __wsum;


typedef unsigned gfp_t;


typedef u64 resource_size_t;






struct ustat {
 __kernel_daddr_t f_tfree;
 __kernel_ino_t f_tinode;
 char f_fname[6];
 char f_fpack[6];
};
# 7 "include/asm/alternative.h" 2

struct alt_instr {
 u8 *instr;
 u8 *replacement;
 u8 cpuid;
 u8 instrlen;
 u8 replacementlen;
 u8 pad;
};

extern void alternative_instructions(void);
extern void apply_alternatives(struct alt_instr *start, struct alt_instr *end);

struct module;

extern void alternatives_smp_module_add(struct module *mod, char *name,
     void *locks, void *locks_end,
     void *text, void *text_end);
extern void alternatives_smp_module_del(struct module *mod);
extern void alternatives_smp_switch(int smp);
# 139 "include/asm/alternative.h"
struct paravirt_patch_site;

void apply_paravirt(struct paravirt_patch_site *start,
      struct paravirt_patch_site *end);
# 10 "include/asm/bitops.h" 2
# 36 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void set_bit(int nr, volatile unsigned long * addr)
{
 __asm__ __volatile__( ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; "
  "btsl %1,%0"
  :"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
}
# 53 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void __set_bit(int nr, volatile unsigned long * addr)
{
 __asm__(
  "btsl %1,%0"
  :"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
}
# 71 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void clear_bit(int nr, volatile unsigned long * addr)
{
 __asm__ __volatile__( ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; "
  "btrl %1,%0"
  :"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
}

static inline __attribute__((always_inline)) void __clear_bit(int nr, volatile unsigned long * addr)
{
 __asm__ __volatile__(
  "btrl %1,%0"
  :"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
}
# 98 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void __change_bit(int nr, volatile unsigned long * addr)
{
 __asm__ __volatile__(
  "btcl %1,%0"
  :"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
}
# 116 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void change_bit(int nr, volatile unsigned long * addr)
{
 __asm__ __volatile__( ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; "
  "btcl %1,%0"
  :"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
}
# 133 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int test_and_set_bit(int nr, volatile unsigned long * addr)
{
 int oldbit;

 __asm__ __volatile__( ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; "
  "btsl %2,%1\n\tsbbl %0,%0"
  :"=r" (oldbit),"+m" ((*(volatile long *) addr))
  :"Ir" (nr) : "memory");
 return oldbit;
}
# 153 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int __test_and_set_bit(int nr, volatile unsigned long * addr)
{
 int oldbit;

 __asm__(
  "btsl %2,%1\n\tsbbl %0,%0"
  :"=r" (oldbit),"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
 return oldbit;
}
# 173 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int test_and_clear_bit(int nr, volatile unsigned long * addr)
{
 int oldbit;

 __asm__ __volatile__( ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; "
  "btrl %2,%1\n\tsbbl %0,%0"
  :"=r" (oldbit),"+m" ((*(volatile long *) addr))
  :"Ir" (nr) : "memory");
 return oldbit;
}
# 193 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int __test_and_clear_bit(int nr, volatile unsigned long *addr)
{
 int oldbit;

 __asm__(
  "btrl %2,%1\n\tsbbl %0,%0"
  :"=r" (oldbit),"+m" ((*(volatile long *) addr))
  :"Ir" (nr));
 return oldbit;
}


static inline __attribute__((always_inline)) int __test_and_change_bit(int nr, volatile unsigned long *addr)
{
 int oldbit;

 __asm__ __volatile__(
  "btcl %2,%1\n\tsbbl %0,%0"
  :"=r" (oldbit),"+m" ((*(volatile long *) addr))
  :"Ir" (nr) : "memory");
 return oldbit;
}
# 224 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int test_and_change_bit(int nr, volatile unsigned long* addr)
{
 int oldbit;

 __asm__ __volatile__( ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; "
  "btcl %2,%1\n\tsbbl %0,%0"
  :"=r" (oldbit),"+m" ((*(volatile long *) addr))
  :"Ir" (nr) : "memory");
 return oldbit;
}
# 244 "include/asm/bitops.h"
static inline __attribute__((always_inline)) __attribute__((always_inline)) int constant_test_bit(int nr, const volatile unsigned long *addr)
{
 return ((1UL << (nr & 31)) & (addr[nr >> 5])) != 0;
}

static inline __attribute__((always_inline)) int variable_test_bit(int nr, const volatile unsigned long * addr)
{
 int oldbit;

 __asm__ __volatile__(
  "btl %2,%1\n\tsbbl %0,%0"
  :"=r" (oldbit)
  :"m" ((*(volatile long *) addr)),"Ir" (nr));
 return oldbit;
}
# 275 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int find_first_zero_bit(const unsigned long *addr, unsigned size)
{
 int d0, d1, d2;
 int res;

 if (!size)
  return 0;

 __asm__ __volatile__(
  "movl $-1,%%eax\n\t"
  "xorl %%edx,%%edx\n\t"
  "repe; scasl\n\t"
  "je 1f\n\t"
  "xorl -4(%%edi),%%eax\n\t"
  "subl $4,%%edi\n\t"
  "bsfl %%eax,%%edx\n"
  "1:\tsubl %%ebx,%%edi\n\t"
  "shll $3,%%edi\n\t"
  "addl %%edi,%%edx"
  :"=d" (res), "=&c" (d0), "=&D" (d1), "=&a" (d2)
  :"1" ((size + 31) >> 5), "2" (addr), "b" (addr) : "memory");
 return res;
}







int find_next_zero_bit(const unsigned long *addr, int size, int offset);







static inline __attribute__((always_inline)) unsigned long __ffs(unsigned long word)
{
 __asm__("bsfl %1,%0"
  :"=r" (word)
  :"rm" (word));
 return word;
}
# 329 "include/asm/bitops.h"
static inline __attribute__((always_inline)) unsigned find_first_bit(const unsigned long *addr, unsigned size)
{
 unsigned x = 0;

 while (x < size) {
  unsigned long val = *addr++;
  if (val)
   return __ffs(val) + x;
  x += (sizeof(*addr)<<3);
 }
 return x;
}







int find_next_bit(const unsigned long *addr, int size, int offset);







static inline __attribute__((always_inline)) unsigned long ffz(unsigned long word)
{
 __asm__("bsfl %1,%0"
  :"=r" (word)
  :"r" (~word));
 return word;
}



# 1 "include/asm-generic/bitops/sched.h" 1
# 12 "include/asm-generic/bitops/sched.h"
static inline __attribute__((always_inline)) int sched_find_first_bit(const unsigned long *b)
{





 if (b[0])
  return __ffs(b[0]);
 if (b[1])
  return __ffs(b[1]) + 32;
 if (b[2])
  return __ffs(b[2]) + 64;
 return __ffs(b[3]) + 96;



}
# 367 "include/asm/bitops.h" 2
# 376 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int ffs(int x)
{
 int r;

 __asm__("bsfl %1,%0\n\t"
  "jnz 1f\n\t"
  "movl $-1,%0\n"
  "1:" : "=r" (r) : "rm" (x));
 return r+1;
}







static inline __attribute__((always_inline)) int fls(int x)
{
 int r;

 __asm__("bsrl %1,%0\n\t"
  "jnz 1f\n\t"
  "movl $-1,%0\n"
  "1:" : "=r" (r) : "rm" (x));
 return r+1;
}

# 1 "include/asm-generic/bitops/hweight.h" 1





extern unsigned int hweight32(unsigned int w);
extern unsigned int hweight16(unsigned int w);
extern unsigned int hweight8(unsigned int w);
extern unsigned long hweight64(__u64 w);
# 405 "include/asm/bitops.h" 2



# 1 "include/asm-generic/bitops/fls64.h" 1





static inline __attribute__((always_inline)) int fls64(__u64 x)
{
 __u32 h = x >> 32;
 if (h)
  return fls(h) + 32;
 return fls(x);
}
# 409 "include/asm/bitops.h" 2



# 1 "include/asm-generic/bitops/ext2-non-atomic.h" 1



# 1 "include/asm-generic/bitops/le.h" 1




# 1 "include/asm/byteorder.h" 1
# 13 "include/asm/byteorder.h"
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u32 ___arch__swab32(__u32 x)
{

 __asm__("bswap %0" : "=r" (x) : "0" (x));







 return x;
}

static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u64 ___arch__swab64(__u64 val)
{
 union {
  struct { __u32 a,b; } s;
  __u64 u;
 } v;
 v.u = val;

 asm("bswapl %0 ; bswapl %1 ; xchgl %0,%1"
     : "=r" (v.s.a), "=r" (v.s.b)
     : "0" (v.s.a), "1" (v.s.b));





 return v.u;
}
# 56 "include/asm/byteorder.h"
# 1 "include/linux/byteorder/little_endian.h" 1
# 12 "include/linux/byteorder/little_endian.h"
# 1 "include/linux/byteorder/swab.h" 1
# 64 "include/linux/byteorder/swab.h"
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u16 ___swab16(__u16 x)
{
 return x<<8 | x>>8;
}
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u32 ___swab32(__u32 x)
{
 return x<<24 | x>>24 |
  (x & (__u32)0x0000ff00UL)<<8 |
  (x & (__u32)0x00ff0000UL)>>8;
}
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u64 ___swab64(__u64 x)
{
 return x<<56 | x>>56 |
  (x & (__u64)0x000000000000ff00ULL)<<40 |
  (x & (__u64)0x0000000000ff0000ULL)<<24 |
  (x & (__u64)0x00000000ff000000ULL)<< 8 |
         (x & (__u64)0x000000ff00000000ULL)>> 8 |
  (x & (__u64)0x0000ff0000000000ULL)>>24 |
  (x & (__u64)0x00ff000000000000ULL)>>40;
}
# 163 "include/linux/byteorder/swab.h"
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u16 __fswab16(__u16 x)
{
 return ___swab16(x);
}
static __inline__ __attribute__((always_inline)) __u16 __swab16p(const __u16 *x)
{
 return ___swab16(*(x));
}
static __inline__ __attribute__((always_inline)) void __swab16s(__u16 *addr)
{
 ((void)(*(addr) = ___swab16(*(addr))));
}

static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u32 __fswab32(__u32 x)
{
 return ___arch__swab32(x);
}
static __inline__ __attribute__((always_inline)) __u32 __swab32p(const __u32 *x)
{
 return ___arch__swab32(*(x));
}
static __inline__ __attribute__((always_inline)) void __swab32s(__u32 *addr)
{
 ((void)(*(addr) = ___arch__swab32(*(addr))));
}


static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u64 __fswab64(__u64 x)
{





 return ___arch__swab64(x);

}
static __inline__ __attribute__((always_inline)) __u64 __swab64p(const __u64 *x)
{
 return ___arch__swab64(*(x));
}
static __inline__ __attribute__((always_inline)) void __swab64s(__u64 *addr)
{
 ((void)(*(addr) = ___arch__swab64(*(addr))));
}
# 13 "include/linux/byteorder/little_endian.h" 2
# 43 "include/linux/byteorder/little_endian.h"
static inline __attribute__((always_inline)) __le64 __cpu_to_le64p(const __u64 *p)
{
 return ( __le64)*p;
}
static inline __attribute__((always_inline)) __u64 __le64_to_cpup(const __le64 *p)
{
 return ( __u64)*p;
}
static inline __attribute__((always_inline)) __le32 __cpu_to_le32p(const __u32 *p)
{
 return ( __le32)*p;
}
static inline __attribute__((always_inline)) __u32 __le32_to_cpup(const __le32 *p)
{
 return ( __u32)*p;
}
static inline __attribute__((always_inline)) __le16 __cpu_to_le16p(const __u16 *p)
{
 return ( __le16)*p;
}
static inline __attribute__((always_inline)) __u16 __le16_to_cpup(const __le16 *p)
{
 return ( __u16)*p;
}
static inline __attribute__((always_inline)) __be64 __cpu_to_be64p(const __u64 *p)
{
 return ( __be64)__swab64p(p);
}
static inline __attribute__((always_inline)) __u64 __be64_to_cpup(const __be64 *p)
{
 return __swab64p((__u64 *)p);
}
static inline __attribute__((always_inline)) __be32 __cpu_to_be32p(const __u32 *p)
{
 return ( __be32)__swab32p(p);
}
static inline __attribute__((always_inline)) __u32 __be32_to_cpup(const __be32 *p)
{
 return __swab32p((__u32 *)p);
}
static inline __attribute__((always_inline)) __be16 __cpu_to_be16p(const __u16 *p)
{
 return ( __be16)__swab16p(p);
}
static inline __attribute__((always_inline)) __u16 __be16_to_cpup(const __be16 *p)
{
 return __swab16p((__u16 *)p);
}
# 104 "include/linux/byteorder/little_endian.h"
# 1 "include/linux/byteorder/generic.h" 1
# 105 "include/linux/byteorder/little_endian.h" 2
# 57 "include/asm/byteorder.h" 2
# 6 "include/asm-generic/bitops/le.h" 2
# 5 "include/asm-generic/bitops/ext2-non-atomic.h" 2
# 413 "include/asm/bitops.h" 2






# 1 "include/asm-generic/bitops/minix.h" 1
# 420 "include/asm/bitops.h" 2
# 10 "include/linux/bitops.h" 2

static __inline__ __attribute__((always_inline)) int get_bitmask_order(unsigned int count)
{
 int order;

 order = fls(count);
 return order;
}

static __inline__ __attribute__((always_inline)) int get_count_order(unsigned int count)
{
 int order;

 order = fls(count) - 1;
 if (count & (count - 1))
  order++;
 return order;
}

static inline __attribute__((always_inline)) unsigned long hweight_long(unsigned long w)
{
 return sizeof(w) == 4 ? hweight32(w) : hweight64(w);
}






static inline __attribute__((always_inline)) __u32 rol32(__u32 word, unsigned int shift)
{
 return (word << shift) | (word >> (32 - shift));
}






static inline __attribute__((always_inline)) __u32 ror32(__u32 word, unsigned int shift)
{
 return (word >> shift) | (word << (32 - shift));
}

static inline __attribute__((always_inline)) unsigned fls_long(unsigned long l)
{
 if (sizeof(l) == 4)
  return fls(l);
 return fls64(l);
}
# 21 "include/linux/thread_info.h" 2
# 1 "include/asm/thread_info.h" 1
# 13 "include/asm/thread_info.h"
# 1 "include/asm/page.h" 1
# 43 "include/asm/page.h"
extern int nx_enabled;
# 90 "include/asm/page.h"
typedef struct { unsigned long pte_low; } pte_t;
typedef struct { unsigned long pgd; } pgd_t;
typedef struct { unsigned long pgprot; } pgprot_t;


static inline __attribute__((always_inline)) unsigned long native_pgd_val(pgd_t pgd)
{
 return pgd.pgd;
}

static inline __attribute__((always_inline)) unsigned long native_pte_val(pte_t pte)
{
 return pte.pte_low;
}

static inline __attribute__((always_inline)) pgd_t native_make_pgd(unsigned long val)
{
 return (pgd_t) { val };
}

static inline __attribute__((always_inline)) pte_t native_make_pte(unsigned long val)
{
 return (pte_t) { .pte_low = val };
}


# 1 "include/asm-generic/pgtable-nopmd.h" 1





# 1 "include/asm-generic/pgtable-nopud.h" 1
# 13 "include/asm-generic/pgtable-nopud.h"
typedef struct { pgd_t pgd; } pud_t;
# 25 "include/asm-generic/pgtable-nopud.h"
static inline __attribute__((always_inline)) int pgd_none(pgd_t pgd) { return 0; }
static inline __attribute__((always_inline)) int pgd_bad(pgd_t pgd) { return 0; }
static inline __attribute__((always_inline)) int pgd_present(pgd_t pgd) { return 1; }
static inline __attribute__((always_inline)) void pgd_clear(pgd_t *pgd) { }
# 38 "include/asm-generic/pgtable-nopud.h"
static inline __attribute__((always_inline)) pud_t * pud_offset(pgd_t * pgd, unsigned long address)
{
 return (pud_t *)pgd;
}
# 7 "include/asm-generic/pgtable-nopmd.h" 2
# 15 "include/asm-generic/pgtable-nopmd.h"
typedef struct { pud_t pud; } pmd_t;
# 27 "include/asm-generic/pgtable-nopmd.h"
static inline __attribute__((always_inline)) int pud_none(pud_t pud) { return 0; }
static inline __attribute__((always_inline)) int pud_bad(pud_t pud) { return 0; }
static inline __attribute__((always_inline)) int pud_present(pud_t pud) { return 1; }
static inline __attribute__((always_inline)) void pud_clear(pud_t *pud) { }
# 41 "include/asm-generic/pgtable-nopmd.h"
static inline __attribute__((always_inline)) pmd_t * pmd_offset(pud_t * pud, unsigned long address)
{
 return (pmd_t *)pud;
}
# 117 "include/asm/page.h" 2
# 158 "include/asm/page.h"
struct vm_area_struct;





extern unsigned int __VMALLOC_RESERVE;

extern int sysctl_legacy_va_layout;

extern int page_is_ram(unsigned long pagenr);
# 200 "include/asm/page.h"
# 1 "include/asm-generic/memory_model.h" 1
# 201 "include/asm/page.h" 2
# 1 "include/asm-generic/page.h" 1
# 10 "include/asm-generic/page.h"
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) int get_order(unsigned long size)
{
 int order;

 size = (size - 1) >> (12 - 1);
 order = -1;
 do {
  size >>= 1;
  order++;
 } while (size);
 return order;
}
# 202 "include/asm/page.h" 2
# 14 "include/asm/thread_info.h" 2


# 1 "include/asm/processor.h" 1
# 10 "include/asm/processor.h"
# 1 "include/asm/vm86.h" 1
# 72 "include/asm/vm86.h"
struct vm86_regs {



 long ebx;
 long ecx;
 long edx;
 long esi;
 long edi;
 long ebp;
 long eax;
 long __null_ds;
 long __null_es;
 long __null_fs;
 long __null_gs;
 long orig_eax;
 long eip;
 unsigned short cs, __csh;
 long eflags;
 long esp;
 unsigned short ss, __ssh;



 unsigned short es, __esh;
 unsigned short ds, __dsh;
 unsigned short fs, __fsh;
 unsigned short gs, __gsh;
};

struct revectored_struct {
 unsigned long __map[8];
};

struct vm86_struct {
 struct vm86_regs regs;
 unsigned long flags;
 unsigned long screen_bitmap;
 unsigned long cpu_type;
 struct revectored_struct int_revectored;
 struct revectored_struct int21_revectored;
};






struct vm86plus_info_struct {
 unsigned long force_return_for_pic:1;
 unsigned long vm86dbg_active:1;
 unsigned long vm86dbg_TFpendig:1;
 unsigned long unused:28;
 unsigned long is_vm86pus:1;
 unsigned char vm86dbg_intxxtab[32];
};

struct vm86plus_struct {
 struct vm86_regs regs;
 unsigned long flags;
 unsigned long screen_bitmap;
 unsigned long cpu_type;
 struct revectored_struct int_revectored;
 struct revectored_struct int21_revectored;
 struct vm86plus_info_struct vm86plus;
};
# 148 "include/asm/vm86.h"
# 1 "include/asm/ptrace.h" 1



# 1 "include/asm/ptrace-abi.h" 1
# 5 "include/asm/ptrace.h" 2




struct pt_regs {
 long ebx;
 long ecx;
 long edx;
 long esi;
 long edi;
 long ebp;
 long eax;
 int xds;
 int xes;
 int xfs;

 long orig_eax;
 long eip;
 int xcs;
 long eflags;
 long esp;
 int xss;
};



# 1 "include/asm/vm86.h" 1
# 32 "include/asm/ptrace.h" 2
# 1 "include/asm/segment.h" 1
# 33 "include/asm/ptrace.h" 2

struct task_struct;
extern void send_sigtrap(struct task_struct *tsk, struct pt_regs *regs, int error_code);
# 44 "include/asm/ptrace.h"
static inline __attribute__((always_inline)) int user_mode(struct pt_regs *regs)
{
 return (regs->xcs & 0x3) == 0x3;
}
static inline __attribute__((always_inline)) int user_mode_vm(struct pt_regs *regs)
{
 return ((regs->xcs & 0x3) | (regs->eflags & 0x00020000)) >= 0x3;
}
static inline __attribute__((always_inline)) int v8086_mode(struct pt_regs *regs)
{
 return (regs->eflags & 0x00020000);
}




extern unsigned long profile_pc(struct pt_regs *regs);
# 149 "include/asm/vm86.h" 2

struct kernel_vm86_regs {



 struct pt_regs pt;



 unsigned short es, __esh;
 unsigned short ds, __dsh;
 unsigned short fs, __fsh;
 unsigned short gs, __gsh;
};

struct kernel_vm86_struct {
 struct kernel_vm86_regs regs;
# 175 "include/asm/vm86.h"
 unsigned long flags;
 unsigned long screen_bitmap;
 unsigned long cpu_type;
 struct revectored_struct int_revectored;
 struct revectored_struct int21_revectored;
 struct vm86plus_info_struct vm86plus;
 struct pt_regs *regs32;
# 192 "include/asm/vm86.h"
};



void handle_vm86_fault(struct kernel_vm86_regs *, long);
int handle_vm86_trap(struct kernel_vm86_regs *, long, int);

struct task_struct;
void release_vm86_irqs(struct task_struct *);
# 11 "include/asm/processor.h" 2
# 1 "include/asm/math_emu.h" 1



# 1 "include/asm/sigcontext.h" 1
# 20 "include/asm/sigcontext.h"
struct _fpreg {
 unsigned short significand[4];
 unsigned short exponent;
};

struct _fpxreg {
 unsigned short significand[4];
 unsigned short exponent;
 unsigned short padding[3];
};

struct _xmmreg {
 unsigned long element[4];
};

struct _fpstate {

 unsigned long cw;
 unsigned long sw;
 unsigned long tag;
 unsigned long ipoff;
 unsigned long cssel;
 unsigned long dataoff;
 unsigned long datasel;
 struct _fpreg _st[8];
 unsigned short status;
 unsigned short magic;


 unsigned long _fxsr_env[6];
 unsigned long mxcsr;
 unsigned long reserved;
 struct _fpxreg _fxsr_st[8];
 struct _xmmreg _xmm[8];
 unsigned long padding[56];
};



struct sigcontext {
 unsigned short gs, __gsh;
 unsigned short fs, __fsh;
 unsigned short es, __esh;
 unsigned short ds, __dsh;
 unsigned long edi;
 unsigned long esi;
 unsigned long ebp;
 unsigned long esp;
 unsigned long ebx;
 unsigned long edx;
 unsigned long ecx;
 unsigned long eax;
 unsigned long trapno;
 unsigned long err;
 unsigned long eip;
 unsigned short cs, __csh;
 unsigned long eflags;
 unsigned long esp_at_signal;
 unsigned short ss, __ssh;
 struct _fpstate * fpstate;
 unsigned long oldmask;
 unsigned long cr2;
};
# 5 "include/asm/math_emu.h" 2

int restore_i387_soft(void *s387, struct _fpstate *buf);
int save_i387_soft(void *s387, struct _fpstate *buf);





struct info {
 long ___orig_eip;
 long ___ebx;
 long ___ecx;
 long ___edx;
 long ___esi;
 long ___edi;
 long ___ebp;
 long ___eax;
 long ___ds;
 long ___es;
 long ___fs;
 long ___orig_eax;
 long ___eip;
 long ___cs;
 long ___eflags;
 long ___esp;
 long ___ss;
 long ___vm86_es;
 long ___vm86_ds;
 long ___vm86_fs;
 long ___vm86_gs;
};
# 12 "include/asm/processor.h" 2




# 1 "include/asm/cpufeature.h" 1
# 13 "include/asm/cpufeature.h"
# 1 "include/asm/required-features.h" 1
# 14 "include/asm/cpufeature.h" 2
# 17 "include/asm/processor.h" 2
# 1 "include/asm/msr.h" 1



# 1 "include/asm/msr-index.h" 1
# 5 "include/asm/msr.h" 2




# 1 "include/asm/errno.h" 1



# 1 "include/asm-generic/errno.h" 1



# 1 "include/asm-generic/errno-base.h" 1
# 5 "include/asm-generic/errno.h" 2
# 5 "include/asm/errno.h" 2
# 10 "include/asm/msr.h" 2

static inline __attribute__((always_inline)) unsigned long long native_read_msr(unsigned int msr)
{
 unsigned long long val;

 asm volatile("rdmsr" : "=A" (val) : "c" (msr));
 return val;
}

static inline __attribute__((always_inline)) unsigned long long native_read_msr_safe(unsigned int msr,
            int *err)
{
 unsigned long long val;

 asm volatile("2: rdmsr ; xorl %0,%0\n"
       "1:\n\t"
       ".section .fixup,\"ax\"\n\t"
       "3:  movl %3,%0 ; jmp 1b\n\t"
       ".previous\n\t"
        ".section __ex_table,\"a\"\n"
       "   .align 4\n\t"
       "   .long 	2b,3b\n\t"
       ".previous"
       : "=r" (*err), "=A" (val)
       : "c" (msr), "i" (-14));

 return val;
}

static inline __attribute__((always_inline)) void native_write_msr(unsigned int msr, unsigned long long val)
{
 asm volatile("wrmsr" : : "c" (msr), "A"(val));
}

static inline __attribute__((always_inline)) int native_write_msr_safe(unsigned int msr,
     unsigned long long val)
{
 int err;
 asm volatile("2: wrmsr ; xorl %0,%0\n"
       "1:\n\t"
       ".section .fixup,\"ax\"\n\t"
       "3:  movl %4,%0 ; jmp 1b\n\t"
       ".previous\n\t"
        ".section __ex_table,\"a\"\n"
       "   .align 4\n\t"
       "   .long 	2b,3b\n\t"
       ".previous"
       : "=a" (err)
       : "c" (msr), "0" ((u32)val), "d" ((u32)(val>>32)),
         "i" (-14));
 return err;
}

static inline __attribute__((always_inline)) unsigned long long native_read_tsc(void)
{
 unsigned long long val;
 asm volatile("rdtsc" : "=A" (val));
 return val;
}

static inline __attribute__((always_inline)) unsigned long long native_read_pmc(void)
{
 unsigned long long val;
 asm volatile("rdpmc" : "=A" (val));
 return val;
}


# 1 "include/asm/paravirt.h" 1
# 18 "include/asm/paravirt.h"
# 1 "include/linux/cpumask.h" 1
# 84 "include/linux/cpumask.h"
# 1 "include/linux/kernel.h" 1
# 10 "include/linux/kernel.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h" 1 3 4
# 43 "/usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 105 "/usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 11 "include/linux/kernel.h" 2
# 1 "include/linux/linkage.h" 1



# 1 "include/asm/linkage.h" 1
# 5 "include/linux/linkage.h" 2
# 12 "include/linux/kernel.h" 2




# 1 "include/linux/log2.h" 1
# 21 "include/linux/log2.h"
extern __attribute__((const, noreturn))
int ____ilog2_NaN(void);
# 31 "include/linux/log2.h"
static inline __attribute__((always_inline)) __attribute__((const))
int __ilog2_u32(u32 n)
{
 return fls(n) - 1;
}



static inline __attribute__((always_inline)) __attribute__((const))
int __ilog2_u64(u64 n)
{
 return fls64(n) - 1;
}







static inline __attribute__((always_inline)) __attribute__((const))
bool is_power_of_2(unsigned long n)
{
 return (n != 0 && ((n & (n - 1)) == 0));
}




static inline __attribute__((always_inline)) __attribute__((const))
unsigned long __roundup_pow_of_two(unsigned long n)
{
 return 1UL << fls_long(n - 1);
}
# 17 "include/linux/kernel.h" 2

# 1 "include/asm/bug.h" 1
# 36 "include/asm/bug.h"
# 1 "include/asm-generic/bug.h" 1
# 10 "include/asm-generic/bug.h"
struct bug_entry {
 unsigned long bug_addr;

 const char *file;
 unsigned short line;

 unsigned short flags;
};
# 37 "include/asm/bug.h" 2
# 19 "include/linux/kernel.h" 2

extern const char linux_banner[];
extern const char linux_proc_banner[];
# 63 "include/linux/kernel.h"
extern int console_printk[];






struct completion;
struct pt_regs;
struct user;
# 92 "include/linux/kernel.h"
  void __might_sleep(char *file, int line);
# 106 "include/linux/kernel.h"
extern struct atomic_notifier_head panic_notifier_list;
extern long (*panic_blink)(long time);
 void panic(const char * fmt, ...)
 __attribute__ ((noreturn, format (printf, 1, 2)));
extern void oops_enter(void);
extern void oops_exit(void);
extern int oops_may_print(void);
__attribute__((regparm(3))) void do_exit(long error_code)
 __attribute__((noreturn));
 void complete_and_exit(struct completion *, long)
 __attribute__((noreturn));
extern unsigned long simple_strtoul(const char *,char **,unsigned int);
extern long simple_strtol(const char *,char **,unsigned int);
extern unsigned long long simple_strtoull(const char *,char **,unsigned int);
extern long long simple_strtoll(const char *,char **,unsigned int);
extern int sprintf(char * buf, const char * fmt, ...)
 __attribute__ ((format (printf, 2, 3)));
extern int vsprintf(char *buf, const char *, va_list)
 __attribute__ ((format (printf, 2, 0)));
extern int snprintf(char * buf, size_t size, const char * fmt, ...)
 __attribute__ ((format (printf, 3, 4)));
extern int vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
 __attribute__ ((format (printf, 3, 0)));
extern int scnprintf(char * buf, size_t size, const char * fmt, ...)
 __attribute__ ((format (printf, 3, 4)));
extern int vscnprintf(char *buf, size_t size, const char *fmt, va_list args)
 __attribute__ ((format (printf, 3, 0)));
extern char *kasprintf(gfp_t gfp, const char *fmt, ...)
 __attribute__ ((format (printf, 2, 3)));
extern char *kvasprintf(gfp_t gfp, const char *fmt, va_list args);

extern int sscanf(const char *, const char *, ...)
 __attribute__ ((format (scanf, 2, 3)));
extern int vsscanf(const char *, const char *, va_list)
 __attribute__ ((format (scanf, 2, 0)));

extern int get_option(char **str, int *pint);
extern char *get_options(const char *str, int nints, int *ints);
extern unsigned long long memparse(char *ptr, char **retptr);

extern int core_kernel_text(unsigned long addr);
extern int __kernel_text_address(unsigned long addr);
extern int kernel_text_address(unsigned long addr);
struct pid;
extern struct pid *session_of_pgrp(struct pid *pgrp);

extern void dump_thread(struct pt_regs *regs, struct user *dump);


 __attribute__((regparm(0))) int vprintk(const char *fmt, va_list args)
 __attribute__ ((format (printf, 1, 0)));
 __attribute__((regparm(0))) int printk(const char * fmt, ...)
 __attribute__ ((format (printf, 1, 2)));
# 168 "include/linux/kernel.h"
unsigned long int_sqrt(unsigned long);

extern int printk_ratelimit(void);
extern int __printk_ratelimit(int ratelimit_jiffies, int ratelimit_burst);
extern bool printk_timed_ratelimit(unsigned long *caller_jiffies,
    unsigned int interval_msec);

static inline __attribute__((always_inline)) void console_silent(void)
{
 (console_printk[0]) = 0;
}

static inline __attribute__((always_inline)) void console_verbose(void)
{
 if ((console_printk[0]))
  (console_printk[0]) = 15;
}

extern void bust_spinlocks(int yes);
extern void wake_up_klogd(void);
extern int oops_in_progress;
extern int panic_timeout;
extern int panic_on_oops;
extern int panic_on_unrecovered_nmi;
extern int tainted;
extern const char *print_tainted(void);
extern void add_taint(unsigned);


extern enum system_states {
 SYSTEM_BOOTING,
 SYSTEM_RUNNING,
 SYSTEM_HALT,
 SYSTEM_POWER_OFF,
 SYSTEM_RESTART,
 SYSTEM_SUSPEND_DISK,
} system_state;
# 214 "include/linux/kernel.h"
extern void dump_stack(void);

enum {
 DUMP_PREFIX_NONE,
 DUMP_PREFIX_ADDRESS,
 DUMP_PREFIX_OFFSET
};
extern void hex_dump_to_buffer(const void *buf, size_t len,
    int rowsize, int groupsize,
    char *linebuf, size_t linebuflen, bool ascii);
extern void print_hex_dump(const char *level, const char *prefix_str,
    int prefix_type, int rowsize, int groupsize,
    void *buf, size_t len, bool ascii);
extern void print_hex_dump_bytes(const char *prefix_str, int prefix_type,
   void *buf, size_t len);







static inline __attribute__((always_inline)) int __attribute__ ((format (printf, 1, 2))) pr_debug(const char * fmt, ...)
{
 return 0;
}
# 340 "include/linux/kernel.h"
struct sysinfo;
extern int do_sysinfo(struct sysinfo *info);




struct sysinfo {
 long uptime;
 unsigned long loads[3];
 unsigned long totalram;
 unsigned long freeram;
 unsigned long sharedram;
 unsigned long bufferram;
 unsigned long totalswap;
 unsigned long freeswap;
 unsigned short procs;
 unsigned short pad;
 unsigned long totalhigh;
 unsigned long freehigh;
 unsigned int mem_unit;
 char _f[20-2*sizeof(long)-sizeof(int)];
};
# 85 "include/linux/cpumask.h" 2
# 1 "include/linux/threads.h" 1
# 86 "include/linux/cpumask.h" 2
# 1 "include/linux/bitmap.h" 1







# 1 "include/linux/string.h" 1
# 16 "include/linux/string.h"
extern char *strndup_user(const char *, long);




# 1 "include/asm/string.h" 1
# 29 "include/asm/string.h"
static inline __attribute__((always_inline)) char * strcpy(char * dest,const char *src)
{
int d0, d1, d2;
__asm__ __volatile__(
 "1:\tlodsb\n\t"
 "stosb\n\t"
 "testb %%al,%%al\n\t"
 "jne 1b"
 : "=&S" (d0), "=&D" (d1), "=&a" (d2)
 :"0" (src),"1" (dest) : "memory");
return dest;
}


static inline __attribute__((always_inline)) char * strncpy(char * dest,const char *src,size_t count)
{
int d0, d1, d2, d3;
__asm__ __volatile__(
 "1:\tdecl %2\n\t"
 "js 2f\n\t"
 "lodsb\n\t"
 "stosb\n\t"
 "testb %%al,%%al\n\t"
 "jne 1b\n\t"
 "rep\n\t"
 "stosb\n"
 "2:"
 : "=&S" (d0), "=&D" (d1), "=&c" (d2), "=&a" (d3)
 :"0" (src),"1" (dest),"2" (count) : "memory");
return dest;
}


static inline __attribute__((always_inline)) char * strcat(char * dest,const char * src)
{
int d0, d1, d2, d3;
__asm__ __volatile__(
 "repne\n\t"
 "scasb\n\t"
 "decl %1\n"
 "1:\tlodsb\n\t"
 "stosb\n\t"
 "testb %%al,%%al\n\t"
 "jne 1b"
 : "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
 : "0" (src), "1" (dest), "2" (0), "3" (0xffffffffu):"memory");
return dest;
}


static inline __attribute__((always_inline)) char * strncat(char * dest,const char * src,size_t count)
{
int d0, d1, d2, d3;
__asm__ __volatile__(
 "repne\n\t"
 "scasb\n\t"
 "decl %1\n\t"
 "movl %8,%3\n"
 "1:\tdecl %3\n\t"
 "js 2f\n\t"
 "lodsb\n\t"
 "stosb\n\t"
 "testb %%al,%%al\n\t"
 "jne 1b\n"
 "2:\txorl %2,%2\n\t"
 "stosb"
 : "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
 : "0" (src),"1" (dest),"2" (0),"3" (0xffffffffu), "g" (count)
 : "memory");
return dest;
}


static inline __attribute__((always_inline)) int strcmp(const char * cs,const char * ct)
{
int d0, d1;
register int __res;
__asm__ __volatile__(
 "1:\tlodsb\n\t"
 "scasb\n\t"
 "jne 2f\n\t"
 "testb %%al,%%al\n\t"
 "jne 1b\n\t"
 "xorl %%eax,%%eax\n\t"
 "jmp 3f\n"
 "2:\tsbbl %%eax,%%eax\n\t"
 "orb $1,%%al\n"
 "3:"
 :"=a" (__res), "=&S" (d0), "=&D" (d1)
 :"1" (cs),"2" (ct)
 :"memory");
return __res;
}


static inline __attribute__((always_inline)) int strncmp(const char * cs,const char * ct,size_t count)
{
register int __res;
int d0, d1, d2;
__asm__ __volatile__(
 "1:\tdecl %3\n\t"
 "js 2f\n\t"
 "lodsb\n\t"
 "scasb\n\t"
 "jne 3f\n\t"
 "testb %%al,%%al\n\t"
 "jne 1b\n"
 "2:\txorl %%eax,%%eax\n\t"
 "jmp 4f\n"
 "3:\tsbbl %%eax,%%eax\n\t"
 "orb $1,%%al\n"
 "4:"
 :"=a" (__res), "=&S" (d0), "=&D" (d1), "=&c" (d2)
 :"1" (cs),"2" (ct),"3" (count)
 :"memory");
return __res;
}


static inline __attribute__((always_inline)) char * strchr(const char * s, int c)
{
int d0;
register char * __res;
__asm__ __volatile__(
 "movb %%al,%%ah\n"
 "1:\tlodsb\n\t"
 "cmpb %%ah,%%al\n\t"
 "je 2f\n\t"
 "testb %%al,%%al\n\t"
 "jne 1b\n\t"
 "movl $1,%1\n"
 "2:\tmovl %1,%0\n\t"
 "decl %0"
 :"=a" (__res), "=&S" (d0)
 :"1" (s),"0" (c)
 :"memory");
return __res;
}


static inline __attribute__((always_inline)) char * strrchr(const char * s, int c)
{
int d0, d1;
register char * __res;
__asm__ __volatile__(
 "movb %%al,%%ah\n"
 "1:\tlodsb\n\t"
 "cmpb %%ah,%%al\n\t"
 "jne 2f\n\t"
 "leal -1(%%esi),%0\n"
 "2:\ttestb %%al,%%al\n\t"
 "jne 1b"
 :"=g" (__res), "=&S" (d0), "=&a" (d1)
 :"0" (0),"1" (s),"2" (c)
 :"memory");
return __res;
}


static inline __attribute__((always_inline)) size_t strlen(const char * s)
{
int d0;
register int __res;
__asm__ __volatile__(
 "repne\n\t"
 "scasb\n\t"
 "notl %0\n\t"
 "decl %0"
 :"=c" (__res), "=&D" (d0)
 :"1" (s),"a" (0), "0" (0xffffffffu)
 :"memory");
return __res;
}

static inline __attribute__((always_inline)) __attribute__((always_inline)) void * __memcpy(void * to, const void * from, size_t n)
{
int d0, d1, d2;
__asm__ __volatile__(
 "rep ; movsl\n\t"
 "movl %4,%%ecx\n\t"
 "andl $3,%%ecx\n\t"

 "jz 1f\n\t"

 "rep ; movsb\n\t"
 "1:"
 : "=&c" (d0), "=&D" (d1), "=&S" (d2)
 : "0" (n/4), "g" (n), "1" ((long) to), "2" ((long) from)
 : "memory");
return (to);
}





static inline __attribute__((always_inline)) __attribute__((always_inline)) void * __constant_memcpy(void * to, const void * from, size_t n)
{
 long esi, edi;
 if (!n) return to;

 switch (n) {
  case 1: *(char*)to = *(char*)from; return to;
  case 2: *(short*)to = *(short*)from; return to;
  case 4: *(int*)to = *(int*)from; return to;

  case 3: *(short*)to = *(short*)from;
   *((char*)to+2) = *((char*)from+2); return to;
  case 5: *(int*)to = *(int*)from;
   *((char*)to+4) = *((char*)from+4); return to;
  case 6: *(int*)to = *(int*)from;
   *((short*)to+2) = *((short*)from+2); return to;
  case 8: *(int*)to = *(int*)from;
   *((int*)to+1) = *((int*)from+1); return to;

 }

 esi = (long) from;
 edi = (long) to;
 if (n >= 5*4) {

  int ecx;
  __asm__ __volatile__(
   "rep ; movsl"
   : "=&c" (ecx), "=&D" (edi), "=&S" (esi)
   : "0" (n/4), "1" (edi),"2" (esi)
   : "memory"
  );
 } else {

  if (n >= 4*4) __asm__ __volatile__("movsl"
   :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
  if (n >= 3*4) __asm__ __volatile__("movsl"
   :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
  if (n >= 2*4) __asm__ __volatile__("movsl"
   :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
  if (n >= 1*4) __asm__ __volatile__("movsl"
   :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
 }
 switch (n % 4) {

  case 0: return to;
  case 1: __asm__ __volatile__("movsb"
   :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
   return to;
  case 2: __asm__ __volatile__("movsw"
   :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
   return to;
  default: __asm__ __volatile__("movsw\n\tmovsb"
   :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
   return to;
 }
}
# 326 "include/asm/string.h"
void *memmove(void * dest,const void * src, size_t n);




static inline __attribute__((always_inline)) void * memchr(const void * cs,int c,size_t count)
{
int d0;
register void * __res;
if (!count)
 return ((void *)0);
__asm__ __volatile__(
 "repne\n\t"
 "scasb\n\t"
 "je 1f\n\t"
 "movl $1,%0\n"
 "1:\tdecl %0"
 :"=D" (__res), "=&c" (d0)
 :"a" (c),"0" (cs),"1" (count)
 :"memory");
return __res;
}

static inline __attribute__((always_inline)) void * __memset_generic(void * s, char c,size_t count)
{
int d0, d1;
__asm__ __volatile__(
 "rep\n\t"
 "stosb"
 : "=&c" (d0), "=&D" (d1)
 :"a" (c),"1" (s),"0" (count)
 :"memory");
return s;
}
# 369 "include/asm/string.h"
static inline __attribute__((always_inline)) __attribute__((always_inline)) void * __constant_c_memset(void * s, unsigned long c, size_t count)
{
int d0, d1;
__asm__ __volatile__(
 "rep ; stosl\n\t"
 "testb $2,%b3\n\t"
 "je 1f\n\t"
 "stosw\n"
 "1:\ttestb $1,%b3\n\t"
 "je 2f\n\t"
 "stosb\n"
 "2:"
 :"=&c" (d0), "=&D" (d1)
 :"a" (c), "q" (count), "0" (count/4), "1" ((long) s)
 :"memory");
return (s);
}



static inline __attribute__((always_inline)) size_t strnlen(const char * s, size_t count)
{
int d0;
register int __res;
__asm__ __volatile__(
 "movl %2,%0\n\t"
 "jmp 2f\n"
 "1:\tcmpb $0,(%0)\n\t"
 "je 3f\n\t"
 "incl %0\n"
 "2:\tdecl %1\n\t"
 "cmpl $-1,%1\n\t"
 "jne 1b\n"
 "3:\tsubl %2,%0"
 :"=a" (__res), "=&d" (d0)
 :"c" (s),"1" (count)
 :"memory");
return __res;
}




extern char *strstr(const char *cs, const char *ct);





static inline __attribute__((always_inline)) __attribute__((always_inline)) void * __constant_c_and_count_memset(void * s, unsigned long pattern, size_t count)
{
 switch (count) {
  case 0:
   return s;
  case 1:
   *(unsigned char *)s = pattern;
   return s;
  case 2:
   *(unsigned short *)s = pattern;
   return s;
  case 3:
   *(unsigned short *)s = pattern;
   *(2+(unsigned char *)s) = pattern;
   return s;
  case 4:
   *(unsigned long *)s = pattern;
   return s;
 }







{
 int d0, d1;
 switch (count % 4) {
  case 0: __asm__ __volatile__( "rep ; stosl" "" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
  case 1: __asm__ __volatile__( "rep ; stosl" "\n\tstosb" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
  case 2: __asm__ __volatile__( "rep ; stosl" "\n\tstosw" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
  default: __asm__ __volatile__( "rep ; stosl" "\n\tstosw\n\tstosb" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
 }
}


}
# 477 "include/asm/string.h"
static inline __attribute__((always_inline)) void * memscan(void * addr, int c, size_t size)
{
 if (!size)
  return addr;
 __asm__("repnz; scasb\n\t"
  "jnz 1f\n\t"
  "dec %%edi\n"
  "1:"
  : "=D" (addr), "=c" (size)
  : "0" (addr), "1" (size), "a" (c)
  : "memory");
 return addr;
}
# 22 "include/linux/string.h" 2
# 30 "include/linux/string.h"
size_t strlcpy(char *, const char *, size_t);
# 39 "include/linux/string.h"
extern size_t strlcat(char *, const char *, __kernel_size_t);
# 48 "include/linux/string.h"
extern int strnicmp(const char *, const char *, __kernel_size_t);


extern int strcasecmp(const char *s1, const char *s2);


extern int strncasecmp(const char *s1, const char *s2, size_t n);





extern char * strnchr(const char *, size_t, int);




extern char * strstrip(char *);
# 76 "include/linux/string.h"
extern char * strpbrk(const char *,const char *);


extern char * strsep(char **,const char *);


extern __kernel_size_t strspn(const char *,const char *);


extern __kernel_size_t strcspn(const char *,const char *);
# 101 "include/linux/string.h"
extern int __builtin_memcmp(const void *,const void *,__kernel_size_t);





extern char *kstrdup(const char *s, gfp_t gfp);
extern void *kmemdup(const void *src, size_t len, gfp_t gfp);
# 9 "include/linux/bitmap.h" 2
# 84 "include/linux/bitmap.h"
extern int __bitmap_empty(const unsigned long *bitmap, int bits);
extern int __bitmap_full(const unsigned long *bitmap, int bits);
extern int __bitmap_equal(const unsigned long *bitmap1,
                 const unsigned long *bitmap2, int bits);
extern void __bitmap_complement(unsigned long *dst, const unsigned long *src,
   int bits);
extern void __bitmap_shift_right(unsigned long *dst,
                        const unsigned long *src, int shift, int bits);
extern void __bitmap_shift_left(unsigned long *dst,
                        const unsigned long *src, int shift, int bits);
extern void __bitmap_and(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern void __bitmap_or(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern void __bitmap_xor(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern void __bitmap_andnot(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern int __bitmap_intersects(const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern int __bitmap_subset(const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern int __bitmap_weight(const unsigned long *bitmap, int bits);

extern int bitmap_scnprintf(char *buf, unsigned int len,
   const unsigned long *src, int nbits);
extern int __bitmap_parse(const char *buf, unsigned int buflen, int is_user,
   unsigned long *dst, int nbits);
extern int bitmap_parse_user(const char *ubuf, unsigned int ulen,
   unsigned long *dst, int nbits);
extern int bitmap_scnlistprintf(char *buf, unsigned int len,
   const unsigned long *src, int nbits);
extern int bitmap_parselist(const char *buf, unsigned long *maskp,
   int nmaskbits);
extern void bitmap_remap(unsigned long *dst, const unsigned long *src,
  const unsigned long *old, const unsigned long *new, int bits);
extern int bitmap_bitremap(int oldbit,
  const unsigned long *old, const unsigned long *new, int bits);
extern int bitmap_find_free_region(unsigned long *bitmap, int bits, int order);
extern void bitmap_release_region(unsigned long *bitmap, int pos, int order);
extern int bitmap_allocate_region(unsigned long *bitmap, int pos, int order);







static inline __attribute__((always_inline)) void bitmap_zero(unsigned long *dst, int nbits)
{
 if (nbits <= 32)
  *dst = 0UL;
 else {
  int len = (((nbits)+32 -1)/32) * sizeof(unsigned long);
  (__builtin_constant_p(0) ? (__builtin_constant_p((len)) ? __constant_c_and_count_memset(((dst)),((0x01010101UL*(unsigned char)(0))),((len))) : __constant_c_memset(((dst)),((0x01010101UL*(unsigned char)(0))),((len)))) : (__builtin_constant_p((len)) ? __memset_generic((((dst))),(((0))),(((len)))) : __memset_generic(((dst)),((0)),((len)))));
 }
}

static inline __attribute__((always_inline)) void bitmap_fill(unsigned long *dst, int nbits)
{
 size_t nlongs = (((nbits)+32 -1)/32);
 if (nlongs > 1) {
  int len = (nlongs - 1) * sizeof(unsigned long);
  (__builtin_constant_p(0xff) ? (__builtin_constant_p((len)) ? __constant_c_and_count_memset(((dst)),((0x01010101UL*(unsigned char)(0xff))),((len))) : __constant_c_memset(((dst)),((0x01010101UL*(unsigned char)(0xff))),((len)))) : (__builtin_constant_p((len)) ? __memset_generic((((dst))),(((0xff))),(((len)))) : __memset_generic(((dst)),((0xff)),((len)))));
 }
 dst[nlongs - 1] = ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL );
}

static inline __attribute__((always_inline)) void bitmap_copy(unsigned long *dst, const unsigned long *src,
   int nbits)
{
 if (nbits <= 32)
  *dst = *src;
 else {
  int len = (((nbits)+32 -1)/32) * sizeof(unsigned long);
  (__builtin_constant_p(len) ? __constant_memcpy((dst),(src),(len)) : __memcpy((dst),(src),(len)));
 }
}

static inline __attribute__((always_inline)) void bitmap_and(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 if (nbits <= 32)
  *dst = *src1 & *src2;
 else
  __bitmap_and(dst, src1, src2, nbits);
}

static inline __attribute__((always_inline)) void bitmap_or(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 if (nbits <= 32)
  *dst = *src1 | *src2;
 else
  __bitmap_or(dst, src1, src2, nbits);
}

static inline __attribute__((always_inline)) void bitmap_xor(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 if (nbits <= 32)
  *dst = *src1 ^ *src2;
 else
  __bitmap_xor(dst, src1, src2, nbits);
}

static inline __attribute__((always_inline)) void bitmap_andnot(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 if (nbits <= 32)
  *dst = *src1 & ~(*src2);
 else
  __bitmap_andnot(dst, src1, src2, nbits);
}

static inline __attribute__((always_inline)) void bitmap_complement(unsigned long *dst, const unsigned long *src,
   int nbits)
{
 if (nbits <= 32)
  *dst = ~(*src) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL );
 else
  __bitmap_complement(dst, src, nbits);
}

static inline __attribute__((always_inline)) int bitmap_equal(const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 if (nbits <= 32)
  return ! ((*src1 ^ *src2) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
 else
  return __bitmap_equal(src1, src2, nbits);
}

static inline __attribute__((always_inline)) int bitmap_intersects(const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 if (nbits <= 32)
  return ((*src1 & *src2) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL )) != 0;
 else
  return __bitmap_intersects(src1, src2, nbits);
}

static inline __attribute__((always_inline)) int bitmap_subset(const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 if (nbits <= 32)
  return ! ((*src1 & ~(*src2)) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
 else
  return __bitmap_subset(src1, src2, nbits);
}

static inline __attribute__((always_inline)) int bitmap_empty(const unsigned long *src, int nbits)
{
 if (nbits <= 32)
  return ! (*src & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
 else
  return __bitmap_empty(src, nbits);
}

static inline __attribute__((always_inline)) int bitmap_full(const unsigned long *src, int nbits)
{
 if (nbits <= 32)
  return ! (~(*src) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
 else
  return __bitmap_full(src, nbits);
}

static inline __attribute__((always_inline)) int bitmap_weight(const unsigned long *src, int nbits)
{
 if (nbits <= 32)
  return hweight_long(*src & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
 return __bitmap_weight(src, nbits);
}

static inline __attribute__((always_inline)) void bitmap_shift_right(unsigned long *dst,
   const unsigned long *src, int n, int nbits)
{
 if (nbits <= 32)
  *dst = *src >> n;
 else
  __bitmap_shift_right(dst, src, n, nbits);
}

static inline __attribute__((always_inline)) void bitmap_shift_left(unsigned long *dst,
   const unsigned long *src, int n, int nbits)
{
 if (nbits <= 32)
  *dst = (*src << n) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL );
 else
  __bitmap_shift_left(dst, src, n, nbits);
}

static inline __attribute__((always_inline)) int bitmap_parse(const char *buf, unsigned int buflen,
   unsigned long *maskp, int nmaskbits)
{
 return __bitmap_parse(buf, buflen, 0, maskp, nmaskbits);
}
# 87 "include/linux/cpumask.h" 2

typedef struct { unsigned long bits[(((8)+32 -1)/32)]; } cpumask_t;
extern cpumask_t _unused_cpumask_arg_;


static inline __attribute__((always_inline)) void __cpu_set(int cpu, volatile cpumask_t *dstp)
{
 set_bit(cpu, dstp->bits);
}


static inline __attribute__((always_inline)) void __cpu_clear(int cpu, volatile cpumask_t *dstp)
{
 clear_bit(cpu, dstp->bits);
}


static inline __attribute__((always_inline)) void __cpus_setall(cpumask_t *dstp, int nbits)
{
 bitmap_fill(dstp->bits, nbits);
}


static inline __attribute__((always_inline)) void __cpus_clear(cpumask_t *dstp, int nbits)
{
 bitmap_zero(dstp->bits, nbits);
}





static inline __attribute__((always_inline)) int __cpu_test_and_set(int cpu, cpumask_t *addr)
{
 return test_and_set_bit(cpu, addr->bits);
}


static inline __attribute__((always_inline)) void __cpus_and(cpumask_t *dstp, const cpumask_t *src1p,
     const cpumask_t *src2p, int nbits)
{
 bitmap_and(dstp->bits, src1p->bits, src2p->bits, nbits);
}


static inline __attribute__((always_inline)) void __cpus_or(cpumask_t *dstp, const cpumask_t *src1p,
     const cpumask_t *src2p, int nbits)
{
 bitmap_or(dstp->bits, src1p->bits, src2p->bits, nbits);
}


static inline __attribute__((always_inline)) void __cpus_xor(cpumask_t *dstp, const cpumask_t *src1p,
     const cpumask_t *src2p, int nbits)
{
 bitmap_xor(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static inline __attribute__((always_inline)) void __cpus_andnot(cpumask_t *dstp, const cpumask_t *src1p,
     const cpumask_t *src2p, int nbits)
{
 bitmap_andnot(dstp->bits, src1p->bits, src2p->bits, nbits);
}


static inline __attribute__((always_inline)) void __cpus_complement(cpumask_t *dstp,
     const cpumask_t *srcp, int nbits)
{
 bitmap_complement(dstp->bits, srcp->bits, nbits);
}


static inline __attribute__((always_inline)) int __cpus_equal(const cpumask_t *src1p,
     const cpumask_t *src2p, int nbits)
{
 return bitmap_equal(src1p->bits, src2p->bits, nbits);
}


static inline __attribute__((always_inline)) int __cpus_intersects(const cpumask_t *src1p,
     const cpumask_t *src2p, int nbits)
{
 return bitmap_intersects(src1p->bits, src2p->bits, nbits);
}


static inline __attribute__((always_inline)) int __cpus_subset(const cpumask_t *src1p,
     const cpumask_t *src2p, int nbits)
{
 return bitmap_subset(src1p->bits, src2p->bits, nbits);
}


static inline __attribute__((always_inline)) int __cpus_empty(const cpumask_t *srcp, int nbits)
{
 return bitmap_empty(srcp->bits, nbits);
}


static inline __attribute__((always_inline)) int __cpus_full(const cpumask_t *srcp, int nbits)
{
 return bitmap_full(srcp->bits, nbits);
}


static inline __attribute__((always_inline)) int __cpus_weight(const cpumask_t *srcp, int nbits)
{
 return bitmap_weight(srcp->bits, nbits);
}



static inline __attribute__((always_inline)) void __cpus_shift_right(cpumask_t *dstp,
     const cpumask_t *srcp, int n, int nbits)
{
 bitmap_shift_right(dstp->bits, srcp->bits, n, nbits);
}



static inline __attribute__((always_inline)) void __cpus_shift_left(cpumask_t *dstp,
     const cpumask_t *srcp, int n, int nbits)
{
 bitmap_shift_left(dstp->bits, srcp->bits, n, nbits);
}


int __first_cpu(const cpumask_t *srcp);

int __next_cpu(int n, const cpumask_t *srcp);
# 270 "include/linux/cpumask.h"
static inline __attribute__((always_inline)) int __cpumask_scnprintf(char *buf, int len,
     const cpumask_t *srcp, int nbits)
{
 return bitmap_scnprintf(buf, len, srcp->bits, nbits);
}



static inline __attribute__((always_inline)) int __cpumask_parse_user(const char *buf, int len,
     cpumask_t *dstp, int nbits)
{
 return bitmap_parse_user(buf, len, dstp->bits, nbits);
}



static inline __attribute__((always_inline)) int __cpulist_scnprintf(char *buf, int len,
     const cpumask_t *srcp, int nbits)
{
 return bitmap_scnlistprintf(buf, len, srcp->bits, nbits);
}


static inline __attribute__((always_inline)) int __cpulist_parse(const char *buf, cpumask_t *dstp, int nbits)
{
 return bitmap_parselist(buf, dstp->bits, nbits);
}



static inline __attribute__((always_inline)) int __cpu_remap(int oldbit,
  const cpumask_t *oldp, const cpumask_t *newp, int nbits)
{
 return bitmap_bitremap(oldbit, oldp->bits, newp->bits, nbits);
}



static inline __attribute__((always_inline)) void __cpus_remap(cpumask_t *dstp, const cpumask_t *srcp,
  const cpumask_t *oldp, const cpumask_t *newp, int nbits)
{
 bitmap_remap(dstp->bits, srcp->bits, oldp->bits, newp->bits, nbits);
}
# 380 "include/linux/cpumask.h"
extern cpumask_t cpu_possible_map;
extern cpumask_t cpu_online_map;
extern cpumask_t cpu_present_map;
# 401 "include/linux/cpumask.h"
extern int nr_cpu_ids;

int __any_online_cpu(const cpumask_t *mask);
# 19 "include/asm/paravirt.h" 2
# 1 "include/asm/kmap_types.h" 1
# 11 "include/asm/kmap_types.h"
enum km_type {
__KM_FENCE_0 , KM_BOUNCE_READ,
__KM_FENCE_1 , KM_SKB_SUNRPC_DATA,
__KM_FENCE_2 , KM_SKB_DATA_SOFTIRQ,
__KM_FENCE_3 , KM_USER0,
__KM_FENCE_4 , KM_USER1,
__KM_FENCE_5 , KM_BIO_SRC_IRQ,
__KM_FENCE_6 , KM_BIO_DST_IRQ,
__KM_FENCE_7 , KM_PTE0,
__KM_FENCE_8 , KM_PTE1,
__KM_FENCE_9 , KM_IRQ0,
__KM_FENCE_10 , KM_IRQ1,
__KM_FENCE_11 , KM_SOFTIRQ0,
__KM_FENCE_12 , KM_SOFTIRQ1,
__KM_FENCE_13 , KM_TYPE_NR
};
# 20 "include/asm/paravirt.h" 2

struct page;
struct thread_struct;
struct Xgt_desc_struct;
struct tss_struct;
struct mm_struct;
struct desc_struct;


enum paravirt_lazy_mode {
 PARAVIRT_LAZY_NONE = 0,
 PARAVIRT_LAZY_MMU = 1,
 PARAVIRT_LAZY_CPU = 2,
 PARAVIRT_LAZY_FLUSH = 3,
};

struct paravirt_ops
{
 unsigned int kernel_rpl;
 int shared_kernel_pmd;
  int paravirt_enabled;
 const char *name;
# 50 "include/asm/paravirt.h"
 unsigned (*patch)(u8 type, u16 clobber, void *firstinsn, unsigned len);


 void (*arch_setup)(void);
 char *(*memory_setup)(void);
 void (*init_IRQ)(void);
 void (*time_init)(void);







 void (*pagetable_setup_start)(pgd_t *pgd_base);
 void (*pagetable_setup_done)(pgd_t *pgd_base);


 void (*banner)(void);


 unsigned long (*get_wallclock)(void);
 int (*set_wallclock)(unsigned long);


 void (*cpuid)(unsigned int *eax, unsigned int *ebx,
        unsigned int *ecx, unsigned int *edx);


 unsigned long (*get_debugreg)(int regno);
 void (*set_debugreg)(int regno, unsigned long value);

 void (*clts)(void);

 unsigned long (*read_cr0)(void);
 void (*write_cr0)(unsigned long);

 unsigned long (*read_cr2)(void);
 void (*write_cr2)(unsigned long);

 unsigned long (*read_cr3)(void);
 void (*write_cr3)(unsigned long);

 unsigned long (*read_cr4_safe)(void);
 unsigned long (*read_cr4)(void);
 void (*write_cr4)(unsigned long);







 unsigned long (*save_fl)(void);
 void (*restore_fl)(unsigned long);
 void (*irq_disable)(void);
 void (*irq_enable)(void);
 void (*safe_halt)(void);
 void (*halt)(void);

 void (*wbinvd)(void);



 u64 (*read_msr)(unsigned int msr, int *err);
 int (*write_msr)(unsigned int msr, u64 val);

 u64 (*read_tsc)(void);
 u64 (*read_pmc)(void);
  u64 (*get_scheduled_cycles)(void);
 unsigned long (*get_cpu_khz)(void);


 void (*load_tr_desc)(void);
 void (*load_gdt)(const struct Xgt_desc_struct *);
 void (*load_idt)(const struct Xgt_desc_struct *);
 void (*store_gdt)(struct Xgt_desc_struct *);
 void (*store_idt)(struct Xgt_desc_struct *);
 void (*set_ldt)(const void *desc, unsigned entries);
 unsigned long (*store_tr)(void);
 void (*load_tls)(struct thread_struct *t, unsigned int cpu);
 void (*write_ldt_entry)(struct desc_struct *,
    int entrynum, u32 low, u32 high);
 void (*write_gdt_entry)(struct desc_struct *,
    int entrynum, u32 low, u32 high);
 void (*write_idt_entry)(struct desc_struct *,
    int entrynum, u32 low, u32 high);
 void (*load_esp0)(struct tss_struct *tss, struct thread_struct *t);

 void (*set_iopl_mask)(unsigned mask);
 void (*io_delay)(void);





 void (*activate_mm)(struct mm_struct *prev,
       struct mm_struct *next);
 void (*dup_mmap)(struct mm_struct *oldmm,
    struct mm_struct *mm);
 void (*exit_mmap)(struct mm_struct *mm);






 void (*apic_write)(unsigned long reg, unsigned long v);
 void (*apic_write_atomic)(unsigned long reg, unsigned long v);
 unsigned long (*apic_read)(unsigned long reg);
 void (*setup_boot_clock)(void);
 void (*setup_secondary_clock)(void);

 void (*startup_ipi_hook)(int phys_apicid,
     unsigned long start_eip,
     unsigned long start_esp);



 void (*flush_tlb_user)(void);
 void (*flush_tlb_kernel)(void);
 void (*flush_tlb_single)(unsigned long addr);
 void (*flush_tlb_others)(const cpumask_t *cpus, struct mm_struct *mm,
     unsigned long va);


 void (*alloc_pt)(u32 pfn);
 void (*alloc_pd)(u32 pfn);
 void (*alloc_pd_clone)(u32 pfn, u32 clonepfn, u32 start, u32 count);
 void (*release_pt)(u32 pfn);
 void (*release_pd)(u32 pfn);


 void (*set_pte)(pte_t *ptep, pte_t pteval);
 void (*set_pte_at)(struct mm_struct *mm, unsigned long addr,
      pte_t *ptep, pte_t pteval);
 void (*set_pmd)(pmd_t *pmdp, pmd_t pmdval);
 void (*pte_update)(struct mm_struct *mm, unsigned long addr, pte_t *ptep);
 void (*pte_update_defer)(struct mm_struct *mm,
     unsigned long addr, pte_t *ptep);


 void *(*kmap_atomic_pte)(struct page *page, enum km_type type);
# 210 "include/asm/paravirt.h"
 unsigned long (*pte_val)(pte_t);
 unsigned long (*pgd_val)(pgd_t);

 pte_t (*make_pte)(unsigned long pte);
 pgd_t (*make_pgd)(unsigned long pgd);



 void (*set_lazy_mode)(enum paravirt_lazy_mode mode);


 void (*irq_enable_sysexit)(void);
 void (*iret)(void);
};

extern struct paravirt_ops paravirt_ops;
# 252 "include/asm/paravirt.h"
unsigned paravirt_patch_nop(void);
unsigned paravirt_patch_ignore(unsigned len);
unsigned paravirt_patch_call(void *target, u16 tgt_clobbers,
        void *site, u16 site_clobbers,
        unsigned len);
unsigned paravirt_patch_jmp(void *target, void *site, unsigned len);
unsigned paravirt_patch_default(u8 type, u16 clobbers, void *site, unsigned len);

unsigned paravirt_patch_insns(void *site, unsigned len,
         const char *start, const char *end);
# 403 "include/asm/paravirt.h"
static inline __attribute__((always_inline)) int paravirt_enabled(void)
{
 return paravirt_ops.paravirt_enabled;
}

static inline __attribute__((always_inline)) void load_esp0(struct tss_struct *tss,
        struct thread_struct *thread)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,load_esp0) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(tss)), "1" ((u32)(thread)) : "memory", "cc"); });
}


static inline __attribute__((always_inline)) unsigned long get_wallclock(void)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,get_wallclock) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,get_wallclock) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) int set_wallclock(unsigned long nowtime)
{
 return ({ int __ret; unsigned long __eax, __edx, __ecx; if (sizeof(int) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_wallclock) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(nowtime)) : "memory", "cc"); __ret = (int)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_wallclock) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(nowtime)) : "memory", "cc"); __ret = (int)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void (*choose_time_init(void))(void)
{
 return paravirt_ops.time_init;
}


static inline __attribute__((always_inline)) void __cpuid(unsigned int *eax, unsigned int *ebx,
      unsigned int *ecx, unsigned int *edx)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("push %[_arg4];" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "lea 4(%%esp),%%esp;" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,cpuid) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(eax)), "1" ((u32)(ebx)), "2" ((u32)(ecx)), [_arg4] "mr" ((u32)(edx)) : "memory", "cc"); });
}




static inline __attribute__((always_inline)) unsigned long paravirt_get_debugreg(int reg)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,get_debugreg) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(reg)) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,get_debugreg) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(reg)) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void set_debugreg(unsigned long val, int reg)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_debugreg) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(reg)), "1" ((u32)(val)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void clts(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,clts) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) unsigned long read_cr0(void)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr0) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr0) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void write_cr0(unsigned long x)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_cr0) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) unsigned long read_cr2(void)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr2) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr2) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void write_cr2(unsigned long x)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_cr2) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) unsigned long read_cr3(void)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr3) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr3) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void write_cr3(unsigned long x)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_cr3) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) unsigned long read_cr4(void)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr4) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr4) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}
static inline __attribute__((always_inline)) unsigned long read_cr4_safe(void)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr4_safe) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_cr4_safe) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void write_cr4(unsigned long x)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_cr4) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void raw_safe_halt(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,safe_halt) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void halt(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,safe_halt) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void wbinvd(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,wbinvd) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}



static inline __attribute__((always_inline)) u64 paravirt_read_msr(unsigned msr, int *err)
{
 return ({ u64 __ret; unsigned long __eax, __edx, __ecx; if (sizeof(u64) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_msr) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(msr)), "1" ((u32)(err)) : "memory", "cc"); __ret = (u64)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_msr) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(msr)), "1" ((u32)(err)) : "memory", "cc"); __ret = (u64)__eax; } __ret; });
}
static inline __attribute__((always_inline)) int paravirt_write_msr(unsigned msr, unsigned low, unsigned high)
{
 return ({ int __ret; unsigned long __eax, __edx, __ecx; if (sizeof(int) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_msr) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(msr)), "1"((u32)(low)), "2"((u32)(high)) : "memory", "cc"); __ret = (int)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_msr) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(msr)), "1"((u32)(low)), "2"((u32)(high)) : "memory", "cc"); __ret = (int)__eax; } __ret; });
}
# 554 "include/asm/paravirt.h"
static inline __attribute__((always_inline)) u64 paravirt_read_tsc(void)
{
 return ({ u64 __ret; unsigned long __eax, __edx, __ecx; if (sizeof(u64) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_tsc) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (u64)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_tsc) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (u64)__eax; } __ret; });
}
# 571 "include/asm/paravirt.h"
static inline __attribute__((always_inline)) unsigned long long paravirt_read_pmc(int counter)
{
 return ({ u64 __ret; unsigned long __eax, __edx, __ecx; if (sizeof(u64) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_pmc) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(counter)) : "memory", "cc"); __ret = (u64)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,read_pmc) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(counter)) : "memory", "cc"); __ret = (u64)__eax; } __ret; });
}







static inline __attribute__((always_inline)) void load_TR_desc(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,load_tr_desc) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void load_gdt(const struct Xgt_desc_struct *dtr)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,load_gdt) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(dtr)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void load_idt(const struct Xgt_desc_struct *dtr)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,load_idt) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(dtr)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void set_ldt(const void *addr, unsigned entries)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_ldt) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(addr)), "1" ((u32)(entries)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void store_gdt(struct Xgt_desc_struct *dtr)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,store_gdt) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(dtr)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void store_idt(struct Xgt_desc_struct *dtr)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,store_idt) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(dtr)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) unsigned long paravirt_store_tr(void)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,store_tr) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,store_tr) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void load_TLS(struct thread_struct *t, unsigned cpu)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,load_tls) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(t)), "1" ((u32)(cpu)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void write_ldt_entry(void *dt, int entry, u32 low, u32 high)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("push %[_arg4];" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "lea 4(%%esp),%%esp;" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_ldt_entry) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(dt)), "1" ((u32)(entry)), "2" ((u32)(low)), [_arg4] "mr" ((u32)(high)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void write_gdt_entry(void *dt, int entry, u32 low, u32 high)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("push %[_arg4];" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "lea 4(%%esp),%%esp;" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_gdt_entry) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(dt)), "1" ((u32)(entry)), "2" ((u32)(low)), [_arg4] "mr" ((u32)(high)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void write_idt_entry(void *dt, int entry, u32 low, u32 high)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("push %[_arg4];" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "lea 4(%%esp),%%esp;" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,write_idt_entry) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(dt)), "1" ((u32)(entry)), "2" ((u32)(low)), [_arg4] "mr" ((u32)(high)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void set_iopl_mask(unsigned mask)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_iopl_mask) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(mask)) : "memory", "cc"); });
}


static inline __attribute__((always_inline)) void slow_down_io(void) {
 paravirt_ops.io_delay();

 paravirt_ops.io_delay();
 paravirt_ops.io_delay();
 paravirt_ops.io_delay();

}





static inline __attribute__((always_inline)) void apic_write(unsigned long reg, unsigned long v)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,apic_write) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(reg)), "1" ((u32)(v)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void apic_write_atomic(unsigned long reg, unsigned long v)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,apic_write_atomic) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(reg)), "1" ((u32)(v)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) unsigned long apic_read(unsigned long reg)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,apic_read) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(reg)) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,apic_read) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(reg)) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void setup_boot_clock(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,setup_boot_clock) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void setup_secondary_clock(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,setup_secondary_clock) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}


static inline __attribute__((always_inline)) void paravirt_pagetable_setup_start(pgd_t *base)
{
 if (paravirt_ops.pagetable_setup_start)
  (*paravirt_ops.pagetable_setup_start)(base);
}

static inline __attribute__((always_inline)) void paravirt_pagetable_setup_done(pgd_t *base)
{
 if (paravirt_ops.pagetable_setup_done)
  (*paravirt_ops.pagetable_setup_done)(base);
}


static inline __attribute__((always_inline)) void startup_ipi_hook(int phys_apicid, unsigned long start_eip,
        unsigned long start_esp)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,startup_ipi_hook) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(phys_apicid)), "1"((u32)(start_eip)), "2"((u32)(start_esp)) : "memory", "cc"); });
}


static inline __attribute__((always_inline)) void paravirt_activate_mm(struct mm_struct *prev,
     struct mm_struct *next)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,activate_mm) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(prev)), "1" ((u32)(next)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void arch_dup_mmap(struct mm_struct *oldmm,
     struct mm_struct *mm)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,dup_mmap) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(oldmm)), "1" ((u32)(mm)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void arch_exit_mmap(struct mm_struct *mm)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,exit_mmap) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(mm)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void __flush_tlb(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,flush_tlb_user) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void __flush_tlb_global(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,flush_tlb_kernel) / sizeof(void *))), [paravirt_clobber] "i" (0x7) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void __flush_tlb_single(unsigned long addr)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,flush_tlb_single) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(addr)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void flush_tlb_others(cpumask_t cpumask, struct mm_struct *mm,
        unsigned long va)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,flush_tlb_others) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(&cpumask)), "1"((u32)(mm)), "2"((u32)(va)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void paravirt_alloc_pt(unsigned pfn)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,alloc_pt) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(pfn)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void paravirt_release_pt(unsigned pfn)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,release_pt) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(pfn)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void paravirt_alloc_pd(unsigned pfn)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,alloc_pd) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(pfn)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void paravirt_alloc_pd_clone(unsigned pfn, unsigned clonepfn,
        unsigned start, unsigned count)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("push %[_arg4];" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "lea 4(%%esp),%%esp;" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,alloc_pd_clone) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(pfn)), "1" ((u32)(clonepfn)), "2" ((u32)(start)), [_arg4] "mr" ((u32)(count)) : "memory", "cc"); });
}
static inline __attribute__((always_inline)) void paravirt_release_pd(unsigned pfn)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,release_pd) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(pfn)) : "memory", "cc"); });
}


static inline __attribute__((always_inline)) void *kmap_atomic_pte(struct page *page, enum km_type type)
{
 unsigned long ret;
 ret = ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,kmap_atomic_pte) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(page)), "1" ((u32)(type)) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,kmap_atomic_pte) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(page)), "1" ((u32)(type)) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
 return (void *)ret;
}


static inline __attribute__((always_inline)) void pte_update(struct mm_struct *mm, unsigned long addr,
         pte_t *ptep)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,pte_update) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(mm)), "1"((u32)(addr)), "2"((u32)(ptep)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void pte_update_defer(struct mm_struct *mm, unsigned long addr,
        pte_t *ptep)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,pte_update_defer) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(mm)), "1"((u32)(addr)), "2"((u32)(ptep)) : "memory", "cc"); });
}
# 852 "include/asm/paravirt.h"
static inline __attribute__((always_inline)) pte_t __pte(unsigned long val)
{
 return (pte_t) { ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,make_pte) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(val)) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,make_pte) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(val)) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; }) };
}

static inline __attribute__((always_inline)) pgd_t __pgd(unsigned long val)
{
 return (pgd_t) { ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,make_pgd) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(val)) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,make_pgd) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(val)) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; }) };
}

static inline __attribute__((always_inline)) unsigned long pte_val(pte_t x)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,pte_val) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x.pte_low)) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,pte_val) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x.pte_low)) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) unsigned long pgd_val(pgd_t x)
{
 return ({ unsigned long __ret; unsigned long __eax, __edx, __ecx; if (sizeof(unsigned long) > sizeof(unsigned long)) { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,pgd_val) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x.pgd)) : "memory", "cc"); __ret = (unsigned long)((((u64)__edx) << 32) | __eax); } else { asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,pgd_val) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(x.pgd)) : "memory", "cc"); __ret = (unsigned long)__eax; } __ret; });
}

static inline __attribute__((always_inline)) void set_pte(pte_t *ptep, pte_t pteval)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_pte) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(ptep)), "1" ((u32)(pteval.pte_low)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void set_pte_at(struct mm_struct *mm, unsigned long addr,
         pte_t *ptep, pte_t pteval)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("push %[_arg4];" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "lea 4(%%esp),%%esp;" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_pte_at) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(mm)), "1" ((u32)(addr)), "2" ((u32)(ptep)), [_arg4] "mr" ((u32)(pteval.pte_low)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void set_pmd(pmd_t *pmdp, pmd_t pmdval)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_pmd) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(pmdp)), "1" ((u32)(pmdval.pud.pgd.pgd)) : "memory", "cc"); });
}



static inline __attribute__((always_inline)) void arch_enter_lazy_cpu_mode(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_lazy_mode) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(PARAVIRT_LAZY_CPU)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void arch_leave_lazy_cpu_mode(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_lazy_mode) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(PARAVIRT_LAZY_NONE)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void arch_flush_lazy_cpu_mode(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_lazy_mode) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(PARAVIRT_LAZY_FLUSH)) : "memory", "cc"); });
}



static inline __attribute__((always_inline)) void arch_enter_lazy_mmu_mode(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_lazy_mode) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(PARAVIRT_LAZY_MMU)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void arch_leave_lazy_mmu_mode(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_lazy_mode) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(PARAVIRT_LAZY_NONE)) : "memory", "cc"); });
}

static inline __attribute__((always_inline)) void arch_flush_lazy_mmu_mode(void)
{
 ({ unsigned long __eax, __edx, __ecx; asm volatile("" "771:\n\t" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n" "" : "=a" (__eax), "=d" (__edx), "=c" (__ecx) : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,set_lazy_mode) / sizeof(void *))), [paravirt_clobber] "i" (0x7), "0" ((u32)(PARAVIRT_LAZY_FLUSH)) : "memory", "cc"); });
}

void _paravirt_nop(void);



struct paravirt_patch_site {
 u8 *instr;
 u8 instrtype;
 u8 len;
 u16 clobbers;
};

extern struct paravirt_patch_site __parainstructions[],
 __parainstructions_end[];

static inline __attribute__((always_inline)) unsigned long __raw_local_save_flags(void)
{
 unsigned long f;

 asm volatile("771:\n\t" "pushl %%ecx; pushl %%edx;" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "popl %%edx; popl %%ecx" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n"


       : "=a"(f)
       : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,save_fl) / sizeof(void *))),
         [paravirt_clobber] "i" (0x1)
       : "memory", "cc");
 return f;
}

static inline __attribute__((always_inline)) void raw_local_irq_restore(unsigned long f)
{
 asm volatile("771:\n\t" "pushl %%ecx; pushl %%edx;" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "popl %%edx; popl %%ecx" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n"


       : "=a"(f)
       : "0"(f),
         [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,restore_fl) / sizeof(void *))),
         [paravirt_clobber] "i" (0x1)
       : "memory", "cc");
}

static inline __attribute__((always_inline)) void raw_local_irq_disable(void)
{
 asm volatile("771:\n\t" "pushl %%ecx; pushl %%edx;" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "popl %%edx; popl %%ecx" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n"


       :
       : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,irq_disable) / sizeof(void *))),
         [paravirt_clobber] "i" (0x1)
       : "memory", "eax", "cc");
}

static inline __attribute__((always_inline)) void raw_local_irq_enable(void)
{
 asm volatile("771:\n\t" "pushl %%ecx; pushl %%edx;" "call *(paravirt_ops+%c[paravirt_typenum]*4);" "popl %%edx; popl %%ecx" "\n" "772:\n" ".pushsection .parainstructions,\"a\"\n" "  .long 771b\n" "  .byte " "%c[paravirt_typenum]" "\n" "  .byte 772b-771b\n" "  .short " "%c[paravirt_clobber]" "\n" ".popsection\n"


       :
       : [paravirt_typenum] "i" ((__builtin_offsetof(struct paravirt_ops,irq_enable) / sizeof(void *))),
         [paravirt_clobber] "i" (0x1)
       : "memory", "eax", "cc");
}

static inline __attribute__((always_inline)) unsigned long __raw_local_irq_save(void)
{
 unsigned long f;

 f = __raw_local_save_flags();
 raw_local_irq_disable();
 return f;
}
# 79 "include/asm/msr.h" 2
# 137 "include/asm/msr.h"
void rdmsr_on_cpu(unsigned int cpu, u32 msr_no, u32 *l, u32 *h);
void wrmsr_on_cpu(unsigned int cpu, u32 msr_no, u32 l, u32 h);
int rdmsr_safe_on_cpu(unsigned int cpu, u32 msr_no, u32 *l, u32 *h);
int wrmsr_safe_on_cpu(unsigned int cpu, u32 msr_no, u32 l, u32 h);
# 18 "include/asm/processor.h" 2
# 1 "include/asm/system.h" 1






# 1 "include/asm/cmpxchg.h" 1







struct __xchg_dummy { unsigned long a[100]; };
# 75 "include/asm/cmpxchg.h"
static inline __attribute__((always_inline)) unsigned long __xchg(unsigned long x, volatile void * ptr, int size)
{
 switch (size) {
  case 1:
   __asm__ __volatile__("xchgb %b0,%1"
    :"=q" (x)
    :"m" (*((struct __xchg_dummy *)(ptr))), "0" (x)
    :"memory");
   break;
  case 2:
   __asm__ __volatile__("xchgw %w0,%1"
    :"=r" (x)
    :"m" (*((struct __xchg_dummy *)(ptr))), "0" (x)
    :"memory");
   break;
  case 4:
   __asm__ __volatile__("xchgl %0,%1"
    :"=r" (x)
    :"m" (*((struct __xchg_dummy *)(ptr))), "0" (x)
    :"memory");
   break;
 }
 return x;
}
# 119 "include/asm/cmpxchg.h"
static inline __attribute__((always_inline)) unsigned long __cmpxchg(volatile void *ptr, unsigned long old,
          unsigned long new, int size)
{
 unsigned long prev;
 switch (size) {
 case 1:
  __asm__ __volatile__(".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "cmpxchgb %b1,%2"
         : "=a"(prev)
         : "q"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 case 2:
  __asm__ __volatile__(".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "cmpxchgw %w1,%2"
         : "=a"(prev)
         : "r"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 case 4:
  __asm__ __volatile__(".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "cmpxchgl %1,%2"
         : "=a"(prev)
         : "r"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 }
 return old;
}






static inline __attribute__((always_inline)) unsigned long __sync_cmpxchg(volatile void *ptr,
         unsigned long old,
         unsigned long new, int size)
{
 unsigned long prev;
 switch (size) {
 case 1:
  __asm__ __volatile__("lock; cmpxchgb %b1,%2"
         : "=a"(prev)
         : "q"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 case 2:
  __asm__ __volatile__("lock; cmpxchgw %w1,%2"
         : "=a"(prev)
         : "r"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 case 4:
  __asm__ __volatile__("lock; cmpxchgl %1,%2"
         : "=a"(prev)
         : "r"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 }
 return old;
}

static inline __attribute__((always_inline)) unsigned long __cmpxchg_local(volatile void *ptr,
   unsigned long old, unsigned long new, int size)
{
 unsigned long prev;
 switch (size) {
 case 1:
  __asm__ __volatile__("cmpxchgb %b1,%2"
         : "=a"(prev)
         : "q"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 case 2:
  __asm__ __volatile__("cmpxchgw %w1,%2"
         : "=a"(prev)
         : "r"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 case 4:
  __asm__ __volatile__("cmpxchgl %1,%2"
         : "=a"(prev)
         : "r"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
         : "memory");
  return prev;
 }
 return old;
}
# 8 "include/asm/system.h" 2



struct task_struct;
extern struct task_struct * __switch_to(struct task_struct *prev, struct task_struct *next) __attribute__((regparm(3)));
# 92 "include/asm/system.h"
static inline __attribute__((always_inline)) void native_clts(void)
{
 asm volatile ("clts");
}

static inline __attribute__((always_inline)) unsigned long native_read_cr0(void)
{
 unsigned long val;
 asm volatile("movl %%cr0,%0\n\t" :"=r" (val));
 return val;
}

static inline __attribute__((always_inline)) void native_write_cr0(unsigned long val)
{
 asm volatile("movl %0,%%cr0": :"r" (val));
}

static inline __attribute__((always_inline)) unsigned long native_read_cr2(void)
{
 unsigned long val;
 asm volatile("movl %%cr2,%0\n\t" :"=r" (val));
 return val;
}

static inline __attribute__((always_inline)) void native_write_cr2(unsigned long val)
{
 asm volatile("movl %0,%%cr2": :"r" (val));
}

static inline __attribute__((always_inline)) unsigned long native_read_cr3(void)
{
 unsigned long val;
 asm volatile("movl %%cr3,%0\n\t" :"=r" (val));
 return val;
}

static inline __attribute__((always_inline)) void native_write_cr3(unsigned long val)
{
 asm volatile("movl %0,%%cr3": :"r" (val));
}

static inline __attribute__((always_inline)) unsigned long native_read_cr4(void)
{
 unsigned long val;
 asm volatile("movl %%cr4,%0\n\t" :"=r" (val));
 return val;
}

static inline __attribute__((always_inline)) unsigned long native_read_cr4_safe(void)
{
 unsigned long val;

 asm("1: movl %%cr4, %0		\n"
  "2:				\n"
  ".section __ex_table,\"a\"	\n"
  ".long 1b,2b			\n"
  ".previous			\n"
  : "=r" (val): "0" (0));
 return val;
}

static inline __attribute__((always_inline)) void native_write_cr4(unsigned long val)
{
 asm volatile("movl %0,%%cr4": :"r" (val));
}

static inline __attribute__((always_inline)) void native_wbinvd(void)
{
 asm volatile("wbinvd": : :"memory");
}
# 188 "include/asm/system.h"
static inline __attribute__((always_inline)) unsigned long get_limit(unsigned long segment)
{
 unsigned long __limit;
 __asm__("lsll %1,%0"
  :"=r" (__limit):"r" (segment));
 return __limit+1;
}
# 301 "include/asm/system.h"
# 1 "include/linux/irqflags.h" 1
# 15 "include/linux/irqflags.h"
  extern void trace_hardirqs_on(void);
  extern void trace_hardirqs_off(void);
  extern void trace_softirqs_on(unsigned long ip);
  extern void trace_softirqs_off(unsigned long ip);
# 46 "include/linux/irqflags.h"
# 1 "include/asm/irqflags.h" 1
# 12 "include/asm/irqflags.h"
# 1 "include/asm/processor-flags.h" 1
# 13 "include/asm/irqflags.h" 2


static inline __attribute__((always_inline)) unsigned long native_save_fl(void)
{
 unsigned long f;
 asm volatile("pushfl ; popl %0":"=g" (f): );
 return f;
}

static inline __attribute__((always_inline)) void native_restore_fl(unsigned long f)
{
 asm volatile("pushl %0 ; popfl":
        :"g" (f)
        :"memory", "cc");
}

static inline __attribute__((always_inline)) void native_irq_disable(void)
{
 asm volatile("cli": : :"memory");
}

static inline __attribute__((always_inline)) void native_irq_enable(void)
{
 asm volatile("sti": : :"memory");
}

static inline __attribute__((always_inline)) void native_safe_halt(void)
{
 asm volatile("sti; hlt": : :"memory");
}

static inline __attribute__((always_inline)) void native_halt(void)
{
 asm volatile("hlt": : :"memory");
}
# 121 "include/asm/irqflags.h"
static inline __attribute__((always_inline)) int raw_irqs_disabled_flags(unsigned long flags)
{
 return !(flags & 0x00000200);
}

static inline __attribute__((always_inline)) int raw_irqs_disabled(void)
{
 unsigned long flags = __raw_local_save_flags();

 return raw_irqs_disabled_flags(flags);
}
# 47 "include/linux/irqflags.h" 2
# 302 "include/asm/system.h" 2





void disable_hlt(void);
void enable_hlt(void);

extern int es7000_plat;
void cpu_idle_wait(void);





static inline __attribute__((always_inline)) void sched_cacheflush(void)
{
 wbinvd();
}

extern unsigned long arch_align_stack(unsigned long sp);
extern void free_init_pages(char *what, unsigned long begin, unsigned long end);

void default_idle(void);
# 19 "include/asm/processor.h" 2
# 1 "include/linux/cache.h" 1




# 1 "include/asm/cache.h" 1
# 6 "include/linux/cache.h" 2
# 20 "include/asm/processor.h" 2

# 1 "include/asm/percpu.h" 1
# 48 "include/asm/percpu.h"
extern unsigned long __per_cpu_offset[];
# 58 "include/asm/percpu.h"
extern __typeof__(unsigned long) per_cpu__this_cpu_off;
# 93 "include/asm/percpu.h"
extern void __bad_percpu_size(void);
# 22 "include/asm/processor.h" 2

# 1 "include/linux/init.h" 1
# 76 "include/linux/init.h"
typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);

extern initcall_t __con_initcall_start[], __con_initcall_end[];
extern initcall_t __security_initcall_start[], __security_initcall_end[];


extern char __attribute__ ((__section__ (".init.data"))) boot_command_line[];
extern char *saved_command_line;
extern unsigned int reset_devices;


void setup_arch(char **);
void prepare_namespace(void);
# 24 "include/asm/processor.h" 2



extern int tsc_disable;

struct desc_struct {
 unsigned long a,b;
};
# 50 "include/asm/processor.h"
struct cpuinfo_x86 {
 __u8 x86;
 __u8 x86_vendor;
 __u8 x86_model;
 __u8 x86_mask;
 char wp_works_ok;
 char hlt_works_ok;
 char hard_math;
 char rfu;
        int cpuid_level;
 unsigned long x86_capability[8];
 char x86_vendor_id[16];
 char x86_model_id[64];
 int x86_cache_size;

 int x86_cache_alignment;
 char fdiv_bug;
 char f00f_bug;
 char coma_bug;
 char pad0;
 int x86_power;
 unsigned long loops_per_jiffy;

 cpumask_t llc_shared_map;

 unsigned char x86_max_cores;
 unsigned char apicid;
 unsigned short x86_clflush_size;

 unsigned char booted_cores;
 __u8 phys_proc_id;
 __u8 cpu_core_id;

} __attribute__((__aligned__((1 << (7)))));
# 101 "include/asm/processor.h"
extern struct cpuinfo_x86 boot_cpu_data;
extern struct cpuinfo_x86 new_cpu_data;
extern struct tss_struct doublefault_tss;
extern __typeof__(struct tss_struct) per_cpu__init_tss;


extern struct cpuinfo_x86 cpu_data[];






extern int cpu_llc_id[8];
extern char ignore_fpu_irq;

void __attribute__ ((__section__ (".init.text"))) cpu_detect(struct cpuinfo_x86 *c);

extern void identify_boot_cpu(void);
extern void identify_secondary_cpu(struct cpuinfo_x86 *);
extern void print_cpu_info(struct cpuinfo_x86 *);
extern void init_scattered_cpuid_features(struct cpuinfo_x86 *c);
extern unsigned int init_intel_cacheinfo(struct cpuinfo_x86 *c);
extern unsigned short num_cache_leaves;


extern void detect_ht(struct cpuinfo_x86 *c);




static inline __attribute__((always_inline)) void native_cpuid(unsigned int *eax, unsigned int *ebx,
      unsigned int *ecx, unsigned int *edx)
{

 __asm__("cpuid"
  : "=a" (*eax),
    "=b" (*ebx),
    "=c" (*ecx),
    "=d" (*edx)
  : "0" (*eax), "2" (*ecx));
}
# 152 "include/asm/processor.h"
extern unsigned long mmu_cr4_features;

static inline __attribute__((always_inline)) void set_in_cr4 (unsigned long mask)
{
 unsigned cr4;
 mmu_cr4_features |= mask;
 cr4 = read_cr4();
 cr4 |= mask;
 write_cr4(cr4);
}

static inline __attribute__((always_inline)) void clear_in_cr4 (unsigned long mask)
{
 unsigned cr4;
 mmu_cr4_features &= ~mask;
 cr4 = read_cr4();
 cr4 &= ~mask;
 write_cr4(cr4);
}
# 184 "include/asm/processor.h"
static inline __attribute__((always_inline)) void sync_core(void)
{
 int tmp;
 asm volatile("cpuid" : "=a" (tmp) : "0" (1) : "ebx","ecx","edx","memory");
}

static inline __attribute__((always_inline)) void __monitor(const void *eax, unsigned long ecx,
  unsigned long edx)
{

 asm volatile(
  ".byte 0x0f,0x01,0xc8;"
  : :"a" (eax), "c" (ecx), "d"(edx));
}

static inline __attribute__((always_inline)) void __mwait(unsigned long eax, unsigned long ecx)
{

 asm volatile(
  ".byte 0x0f,0x01,0xc9;"
  : :"a" (eax), "c" (ecx));
}

extern void mwait_idle_with_hints(unsigned long eax, unsigned long ecx);



extern unsigned int machine_id;
extern unsigned int machine_submodel_id;
extern unsigned int BIOS_revision;
extern unsigned int mca_pentium_flag;


extern int bootloader_type;
# 241 "include/asm/processor.h"
struct i387_fsave_struct {
 long cwd;
 long swd;
 long twd;
 long fip;
 long fcs;
 long foo;
 long fos;
 long st_space[20];
 long status;
};

struct i387_fxsave_struct {
 unsigned short cwd;
 unsigned short swd;
 unsigned short twd;
 unsigned short fop;
 long fip;
 long fcs;
 long foo;
 long fos;
 long mxcsr;
 long mxcsr_mask;
 long st_space[32];
 long xmm_space[32];
 long padding[56];
} __attribute__ ((aligned (16)));

struct i387_soft_struct {
 long cwd;
 long swd;
 long twd;
 long fip;
 long fcs;
 long foo;
 long fos;
 long st_space[20];
 unsigned char ftop, changed, lookahead, no_update, rm, alimit;
 struct info *info;
 unsigned long entry_eip;
};

union i387_union {
 struct i387_fsave_struct fsave;
 struct i387_fxsave_struct fxsave;
 struct i387_soft_struct soft;
};

typedef struct {
 unsigned long seg;
} mm_segment_t;

struct thread_struct;


struct i386_hw_tss {
 unsigned short back_link,__blh;
 unsigned long esp0;
 unsigned short ss0,__ss0h;
 unsigned long esp1;
 unsigned short ss1,__ss1h;
 unsigned long esp2;
 unsigned short ss2,__ss2h;
 unsigned long __cr3;
 unsigned long eip;
 unsigned long eflags;
 unsigned long eax,ecx,edx,ebx;
 unsigned long esp;
 unsigned long ebp;
 unsigned long esi;
 unsigned long edi;
 unsigned short es, __esh;
 unsigned short cs, __csh;
 unsigned short ss, __ssh;
 unsigned short ds, __dsh;
 unsigned short fs, __fsh;
 unsigned short gs, __gsh;
 unsigned short ldt, __ldth;
 unsigned short trace, io_bitmap_base;
} __attribute__((packed));

struct tss_struct {
 struct i386_hw_tss x86_tss;







 unsigned long io_bitmap[((65536/8)/sizeof(long)) + 1];



 unsigned long io_bitmap_max;
 struct thread_struct *io_bitmap_owner;



 unsigned long __cacheline_filler[35];



 unsigned long stack[64];
} __attribute__((packed));



struct thread_struct {

 struct desc_struct tls_array[3];
 unsigned long esp0;
 unsigned long sysenter_cs;
 unsigned long eip;
 unsigned long esp;
 unsigned long fs;
 unsigned long gs;

 unsigned long debugreg[8];

 unsigned long cr2, trap_no, error_code;

 union i387_union i387;

 struct vm86_struct * vm86_info;
 unsigned long screen_bitmap;
 unsigned long v86flags, v86mask, saved_esp0;
 unsigned int saved_fs, saved_gs;

 unsigned long *io_bitmap_ptr;
  unsigned long iopl;

 unsigned long io_bitmap_max;
};
# 413 "include/asm/processor.h"
struct task_struct;
struct mm_struct;


extern void release_thread(struct task_struct *);


extern void prepare_to_copy(struct task_struct *tsk);




extern int kernel_thread(int (*fn)(void *), void * arg, unsigned long flags);

extern unsigned long thread_saved_pc(struct task_struct *tsk);
void show_trace(struct task_struct *task, struct pt_regs *regs, unsigned long *stack);

unsigned long get_wchan(struct task_struct *p);
# 460 "include/asm/processor.h"
struct microcode_header {
 unsigned int hdrver;
 unsigned int rev;
 unsigned int date;
 unsigned int sig;
 unsigned int cksum;
 unsigned int ldrver;
 unsigned int pf;
 unsigned int datasize;
 unsigned int totalsize;
 unsigned int reserved[3];
};

struct microcode {
 struct microcode_header hdr;
 unsigned int bits[0];
};

typedef struct microcode microcode_t;
typedef struct microcode_header microcode_header_t;


struct extended_signature {
 unsigned int sig;
 unsigned int pf;
 unsigned int cksum;
};

struct extended_sigtable {
 unsigned int count;
 unsigned int cksum;
 unsigned int reserved[3];
 struct extended_signature sigs[0];
};


static inline __attribute__((always_inline)) void rep_nop(void)
{
 __asm__ __volatile__("rep;nop": : :"memory");
}



static inline __attribute__((always_inline)) void native_load_esp0(struct tss_struct *tss, struct thread_struct *thread)
{
 tss->x86_tss.esp0 = thread->esp0;

 if (__builtin_expect(!!(tss->x86_tss.ss1 != thread->sysenter_cs), 0)) {
  tss->x86_tss.ss1 = thread->sysenter_cs;
  do { paravirt_write_msr(0x00000174, thread->sysenter_cs, 0); } while(0);
 }
}


static inline __attribute__((always_inline)) unsigned long native_get_debugreg(int regno)
{
 unsigned long val = 0;

 switch (regno) {
 case 0:
  asm("movl %%db0, %0" :"=r" (val)); break;
 case 1:
  asm("movl %%db1, %0" :"=r" (val)); break;
 case 2:
  asm("movl %%db2, %0" :"=r" (val)); break;
 case 3:
  asm("movl %%db3, %0" :"=r" (val)); break;
 case 6:
  asm("movl %%db6, %0" :"=r" (val)); break;
 case 7:
  asm("movl %%db7, %0" :"=r" (val)); break;
 default:
  do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/asm/processor.h"), "i" (532), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0);
 }
 return val;
}

static inline __attribute__((always_inline)) void native_set_debugreg(int regno, unsigned long value)
{
 switch (regno) {
 case 0:
  asm("movl %0,%%db0" : :"r" (value));
  break;
 case 1:
  asm("movl %0,%%db1" : :"r" (value));
  break;
 case 2:
  asm("movl %0,%%db2" : :"r" (value));
  break;
 case 3:
  asm("movl %0,%%db3" : :"r" (value));
  break;
 case 6:
  asm("movl %0,%%db6" : :"r" (value));
  break;
 case 7:
  asm("movl %0,%%db7" : :"r" (value));
  break;
 default:
  do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/asm/processor.h"), "i" (559), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0);
 }
}




static inline __attribute__((always_inline)) void native_set_iopl_mask(unsigned mask)
{
 unsigned int reg;
 __asm__ __volatile__ ("pushfl;"
         "popl %0;"
         "andl %1, %0;"
         "orl %2, %0;"
         "pushl %0;"
         "popfl"
    : "=&r" (reg)
    : "i" (~0x00003000), "r" (mask));
}
# 606 "include/asm/processor.h"
static inline __attribute__((always_inline)) void cpuid(unsigned int op, unsigned int *eax, unsigned int *ebx, unsigned int *ecx, unsigned int *edx)
{
 *eax = op;
 *ecx = 0;
 __cpuid(eax, ebx, ecx, edx);
}


static inline __attribute__((always_inline)) void cpuid_count(int op, int count, int *eax, int *ebx, int *ecx,
          int *edx)
{
 *eax = op;
 *ecx = count;
 __cpuid(eax, ebx, ecx, edx);
}




static inline __attribute__((always_inline)) unsigned int cpuid_eax(unsigned int op)
{
 unsigned int eax, ebx, ecx, edx;

 cpuid(op, &eax, &ebx, &ecx, &edx);
 return eax;
}
static inline __attribute__((always_inline)) unsigned int cpuid_ebx(unsigned int op)
{
 unsigned int eax, ebx, ecx, edx;

 cpuid(op, &eax, &ebx, &ecx, &edx);
 return ebx;
}
static inline __attribute__((always_inline)) unsigned int cpuid_ecx(unsigned int op)
{
 unsigned int eax, ebx, ecx, edx;

 cpuid(op, &eax, &ebx, &ecx, &edx);
 return ecx;
}
static inline __attribute__((always_inline)) unsigned int cpuid_edx(unsigned int op)
{
 unsigned int eax, ebx, ecx, edx;

 cpuid(op, &eax, &ebx, &ecx, &edx);
 return edx;
}
# 722 "include/asm/processor.h"
static inline __attribute__((always_inline)) void prefetch(const void *x)
{
 asm volatile ("661:\n\t" ".byte 0x8d,0x74,0x26,0x00\n" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "prefetchnta (%1)" "\n664:\n" ".previous" :: "i" ((0*32+25)), "r" (x));



}







static inline __attribute__((always_inline)) void prefetchw(const void *x)
{
 asm volatile ("661:\n\t" ".byte 0x8d,0x74,0x26,0x00\n" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "prefetchw (%1)" "\n664:\n" ".previous" :: "i" ((1*32+31)), "r" (x));



}


extern void select_idle_routine(const struct cpuinfo_x86 *c);



extern unsigned long boot_option_idle_override;
extern void enable_sep_cpu(void);
extern int sysenter_setup(void);


extern struct Xgt_desc_struct early_gdt_descr;

extern void cpu_set_gdt(int);
extern void switch_to_new_gdt(void);
extern void cpu_init(void);
extern void init_gdt(int cpu);

extern int force_mwait;
# 17 "include/asm/thread_info.h" 2
# 27 "include/asm/thread_info.h"
struct thread_info {
 struct task_struct *task;
 struct exec_domain *exec_domain;
 unsigned long flags;
 unsigned long status;
 __u32 cpu;
 int preempt_count;


 mm_segment_t addr_limit;



 void *sysenter_return;
 struct restart_block restart_block;

 unsigned long previous_esp;


 __u8 supervisor_stack[0];
};
# 88 "include/asm/thread_info.h"
register unsigned long current_stack_pointer asm("esp") __attribute__((__used__));


static inline __attribute__((always_inline)) struct thread_info *current_thread_info(void)
{
 return (struct thread_info *)(current_stack_pointer & ~((4096) - 1));
}
# 22 "include/linux/thread_info.h" 2
# 30 "include/linux/thread_info.h"
static inline __attribute__((always_inline)) void set_ti_thread_flag(struct thread_info *ti, int flag)
{
 set_bit(flag,&ti->flags);
}

static inline __attribute__((always_inline)) void clear_ti_thread_flag(struct thread_info *ti, int flag)
{
 clear_bit(flag,&ti->flags);
}

static inline __attribute__((always_inline)) int test_and_set_ti_thread_flag(struct thread_info *ti, int flag)
{
 return test_and_set_bit(flag,&ti->flags);
}

static inline __attribute__((always_inline)) int test_and_clear_ti_thread_flag(struct thread_info *ti, int flag)
{
 return test_and_clear_bit(flag,&ti->flags);
}

static inline __attribute__((always_inline)) int test_ti_thread_flag(struct thread_info *ti, int flag)
{
 return (__builtin_constant_p(flag) ? constant_test_bit((flag),(&ti->flags)) : variable_test_bit((flag),(&ti->flags)));
}
# 10 "include/linux/preempt.h" 2
# 50 "include/linux/spinlock.h" 2




# 1 "include/linux/stringify.h" 1
# 55 "include/linux/spinlock.h" 2
# 1 "include/linux/bottom_half.h" 1



extern void local_bh_disable(void);
extern void __local_bh_enable(void);
extern void _local_bh_enable(void);
extern void local_bh_enable(void);
extern void local_bh_enable_ip(unsigned long ip);
# 56 "include/linux/spinlock.h" 2
# 79 "include/linux/spinlock.h"
# 1 "include/linux/spinlock_types.h" 1
# 12 "include/linux/spinlock_types.h"
# 1 "include/linux/lockdep.h" 1
# 11 "include/linux/lockdep.h"
struct task_struct;




# 1 "include/linux/list.h" 1






# 1 "include/linux/poison.h" 1
# 8 "include/linux/list.h" 2
# 1 "include/linux/prefetch.h" 1
# 58 "include/linux/prefetch.h"
static inline __attribute__((always_inline)) void prefetch_range(void *addr, size_t len)
{

 char *cp;
 char *end = addr + len;

 for (cp = addr; cp < end; cp += (4*(1 << (7))))
  prefetch(cp);

}
# 9 "include/linux/list.h" 2
# 21 "include/linux/list.h"
struct list_head {
 struct list_head *next, *prev;
};






static inline __attribute__((always_inline)) void INIT_LIST_HEAD(struct list_head *list)
{
 list->next = list;
 list->prev = list;
}
# 53 "include/linux/list.h"
extern void __list_add(struct list_head *new,
         struct list_head *prev,
         struct list_head *next);
# 72 "include/linux/list.h"
extern void list_add(struct list_head *new, struct list_head *head);
# 84 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_add_tail(struct list_head *new, struct list_head *head)
{
 __list_add(new, head->prev, head);
}







static inline __attribute__((always_inline)) void __list_add_rcu(struct list_head * new,
  struct list_head * prev, struct list_head * next)
{
 new->next = next;
 new->prev = prev;
 __asm__ __volatile__ ("": : :"memory");
 next->prev = new;
 prev->next = new;
}
# 121 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_add_rcu(struct list_head *new, struct list_head *head)
{
 __list_add_rcu(new, head, head->next);
}
# 142 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_add_tail_rcu(struct list_head *new,
     struct list_head *head)
{
 __list_add_rcu(new, head->prev, head);
}
# 155 "include/linux/list.h"
static inline __attribute__((always_inline)) void __list_del(struct list_head * prev, struct list_head * next)
{
 next->prev = prev;
 prev->next = next;
}
# 175 "include/linux/list.h"
extern void list_del(struct list_head *entry);
# 202 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_del_rcu(struct list_head *entry)
{
 __list_del(entry->prev, entry->next);
 entry->prev = ((void *) 0x00200200);
}
# 215 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_replace(struct list_head *old,
    struct list_head *new)
{
 new->next = old->next;
 new->next->prev = new;
 new->prev = old->prev;
 new->prev->next = new;
}

static inline __attribute__((always_inline)) void list_replace_init(struct list_head *old,
     struct list_head *new)
{
 list_replace(old, new);
 INIT_LIST_HEAD(old);
}
# 239 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_replace_rcu(struct list_head *old,
    struct list_head *new)
{
 new->next = old->next;
 new->prev = old->prev;
 __asm__ __volatile__ ("": : :"memory");
 new->next->prev = new;
 new->prev->next = new;
 old->prev = ((void *) 0x00200200);
}





static inline __attribute__((always_inline)) void list_del_init(struct list_head *entry)
{
 __list_del(entry->prev, entry->next);
 INIT_LIST_HEAD(entry);
}






static inline __attribute__((always_inline)) void list_move(struct list_head *list, struct list_head *head)
{
 __list_del(list->prev, list->next);
 list_add(list, head);
}






static inline __attribute__((always_inline)) void list_move_tail(struct list_head *list,
      struct list_head *head)
{
 __list_del(list->prev, list->next);
 list_add_tail(list, head);
}






static inline __attribute__((always_inline)) int list_is_last(const struct list_head *list,
    const struct list_head *head)
{
 return list->next == head;
}





static inline __attribute__((always_inline)) int list_empty(const struct list_head *head)
{
 return head->next == head;
}
# 316 "include/linux/list.h"
static inline __attribute__((always_inline)) int list_empty_careful(const struct list_head *head)
{
 struct list_head *next = head->next;
 return (next == head) && (next == head->prev);
}

static inline __attribute__((always_inline)) void __list_splice(struct list_head *list,
     struct list_head *head)
{
 struct list_head *first = list->next;
 struct list_head *last = list->prev;
 struct list_head *at = head->next;

 first->prev = head;
 head->next = first;

 last->next = at;
 at->prev = last;
}






static inline __attribute__((always_inline)) void list_splice(struct list_head *list, struct list_head *head)
{
 if (!list_empty(list))
  __list_splice(list, head);
}
# 354 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_splice_init(struct list_head *list,
        struct list_head *head)
{
 if (!list_empty(list)) {
  __list_splice(list, head);
  INIT_LIST_HEAD(list);
 }
}
# 380 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_splice_init_rcu(struct list_head *list,
     struct list_head *head,
     void (*sync)(void))
{
 struct list_head *first = list->next;
 struct list_head *last = list->prev;
 struct list_head *at = head->next;

 if (list_empty(head))
  return;



 INIT_LIST_HEAD(list);
# 402 "include/linux/list.h"
 sync();
# 412 "include/linux/list.h"
 last->next = at;
 __asm__ __volatile__ ("": : :"memory");
 head->next = first;
 first->prev = head;
 at->prev = last;
}
# 675 "include/linux/list.h"
struct hlist_head {
 struct hlist_node *first;
};

struct hlist_node {
 struct hlist_node *next, **pprev;
};




static inline __attribute__((always_inline)) void INIT_HLIST_NODE(struct hlist_node *h)
{
 h->next = ((void *)0);
 h->pprev = ((void *)0);
}

static inline __attribute__((always_inline)) int hlist_unhashed(const struct hlist_node *h)
{
 return !h->pprev;
}

static inline __attribute__((always_inline)) int hlist_empty(const struct hlist_head *h)
{
 return !h->first;
}

static inline __attribute__((always_inline)) void __hlist_del(struct hlist_node *n)
{
 struct hlist_node *next = n->next;
 struct hlist_node **pprev = n->pprev;
 *pprev = next;
 if (next)
  next->pprev = pprev;
}

static inline __attribute__((always_inline)) void hlist_del(struct hlist_node *n)
{
 __hlist_del(n);
 n->next = ((void *) 0x00100100);
 n->pprev = ((void *) 0x00200200);
}
# 737 "include/linux/list.h"
static inline __attribute__((always_inline)) void hlist_del_rcu(struct hlist_node *n)
{
 __hlist_del(n);
 n->pprev = ((void *) 0x00200200);
}

static inline __attribute__((always_inline)) void hlist_del_init(struct hlist_node *n)
{
 if (!hlist_unhashed(n)) {
  __hlist_del(n);
  INIT_HLIST_NODE(n);
 }
}
# 758 "include/linux/list.h"
static inline __attribute__((always_inline)) void hlist_replace_rcu(struct hlist_node *old,
     struct hlist_node *new)
{
 struct hlist_node *next = old->next;

 new->next = next;
 new->pprev = old->pprev;
 __asm__ __volatile__ ("": : :"memory");
 if (next)
  new->next->pprev = &new->next;
 *new->pprev = new;
 old->pprev = ((void *) 0x00200200);
}

static inline __attribute__((always_inline)) void hlist_add_head(struct hlist_node *n, struct hlist_head *h)
{
 struct hlist_node *first = h->first;
 n->next = first;
 if (first)
  first->pprev = &n->next;
 h->first = n;
 n->pprev = &h->first;
}
# 802 "include/linux/list.h"
static inline __attribute__((always_inline)) void hlist_add_head_rcu(struct hlist_node *n,
     struct hlist_head *h)
{
 struct hlist_node *first = h->first;
 n->next = first;
 n->pprev = &h->first;
 __asm__ __volatile__ ("": : :"memory");
 if (first)
  first->pprev = &n->next;
 h->first = n;
}


static inline __attribute__((always_inline)) void hlist_add_before(struct hlist_node *n,
     struct hlist_node *next)
{
 n->pprev = next->pprev;
 n->next = next;
 next->pprev = &n->next;
 *(n->pprev) = n;
}

static inline __attribute__((always_inline)) void hlist_add_after(struct hlist_node *n,
     struct hlist_node *next)
{
 next->next = n->next;
 n->next = next;
 next->pprev = &n->next;

 if(next->next)
  next->next->pprev = &next->next;
}
# 853 "include/linux/list.h"
static inline __attribute__((always_inline)) void hlist_add_before_rcu(struct hlist_node *n,
     struct hlist_node *next)
{
 n->pprev = next->pprev;
 n->next = next;
 __asm__ __volatile__ ("": : :"memory");
 next->pprev = &n->next;
 *(n->pprev) = n;
}
# 881 "include/linux/list.h"
static inline __attribute__((always_inline)) void hlist_add_after_rcu(struct hlist_node *prev,
           struct hlist_node *n)
{
 n->next = prev->next;
 n->pprev = &prev->next;
 __asm__ __volatile__ ("": : :"memory");
 prev->next = n;
 if (n->next)
  n->next->pprev = &n->next;
}
# 17 "include/linux/lockdep.h" 2
# 1 "include/linux/debug_locks.h" 1



struct task_struct;

extern int debug_locks;
extern int debug_locks_silent;




extern int debug_locks_off(void);
# 41 "include/linux/debug_locks.h"
  extern void locking_selftest(void);




struct task_struct;


extern void debug_show_all_locks(void);
extern void debug_show_held_locks(struct task_struct *task);
extern void debug_check_no_locks_freed(const void *from, unsigned long len);
extern void debug_check_no_locks_held(struct task_struct *task);
# 18 "include/linux/lockdep.h" 2
# 1 "include/linux/stacktrace.h" 1




struct stack_trace {
 unsigned int nr_entries, max_entries;
 unsigned long *entries;
 int skip;
};

extern void save_stack_trace(struct stack_trace *trace);

extern void print_stack_trace(struct stack_trace *trace, int spaces);
# 19 "include/linux/lockdep.h" 2




enum lock_usage_bit
{
 LOCK_USED = 0,
 LOCK_USED_IN_HARDIRQ,
 LOCK_USED_IN_SOFTIRQ,
 LOCK_ENABLED_SOFTIRQS,
 LOCK_ENABLED_HARDIRQS,
 LOCK_USED_IN_HARDIRQ_READ,
 LOCK_USED_IN_SOFTIRQ_READ,
 LOCK_ENABLED_SOFTIRQS_READ,
 LOCK_ENABLED_HARDIRQS_READ,
 LOCK_USAGE_STATES
};
# 66 "include/linux/lockdep.h"
struct lockdep_subclass_key {
 char __one_byte;
} __attribute__ ((__packed__));

struct lock_class_key {
 struct lockdep_subclass_key subkeys[8UL];
};




struct lock_class {



 struct list_head hash_entry;




 struct list_head lock_entry;

 struct lockdep_subclass_key *key;
 unsigned int subclass;




 unsigned long usage_mask;
 struct stack_trace usage_traces[LOCK_USAGE_STATES];






 struct list_head locks_after, locks_before;





 unsigned int version;




 unsigned long ops;

 const char *name;
 int name_version;
};





struct lockdep_map {
 struct lock_class_key *key;
 struct lock_class *class_cache;
 const char *name;
};





struct lock_list {
 struct list_head entry;
 struct lock_class *class;
 struct stack_trace trace;
 int distance;
};




struct lock_chain {
 struct list_head entry;
 u64 chain_key;
};

struct held_lock {
# 163 "include/linux/lockdep.h"
 u64 prev_chain_key;
 struct lock_class *class;
 unsigned long acquire_ip;
 struct lockdep_map *instance;
# 181 "include/linux/lockdep.h"
 int irq_context;
 int trylock;
 int read;
 int check;
 int hardirqs_off;
};




extern void lockdep_init(void);
extern void lockdep_info(void);
extern void lockdep_reset(void);
extern void lockdep_reset_lock(struct lockdep_map *lock);
extern void lockdep_free_key_range(void *start, unsigned long size);

extern void lockdep_off(void);
extern void lockdep_on(void);







extern void lockdep_init_map(struct lockdep_map *lock, const char *name,
        struct lock_class_key *key, int subclass);
# 240 "include/linux/lockdep.h"
extern void lock_acquire(struct lockdep_map *lock, unsigned int subclass,
    int trylock, int read, int check, unsigned long ip);

extern void lock_release(struct lockdep_map *lock, int nested,
    unsigned long ip);
# 285 "include/linux/lockdep.h"
extern void early_init_irq_lock_class(void);







extern void early_boot_irqs_off(void);
extern void early_boot_irqs_on(void);
extern void print_irqtrace_events(struct task_struct *curr);
# 13 "include/linux/spinlock_types.h" 2


# 1 "include/asm/spinlock_types.h" 1







typedef struct {
 unsigned int slock;
} raw_spinlock_t;



typedef struct {
 unsigned int lock;
} raw_rwlock_t;
# 16 "include/linux/spinlock_types.h" 2




typedef struct {
 raw_spinlock_t raw_lock;




 unsigned int magic, owner_cpu;
 void *owner;


 struct lockdep_map dep_map;

} spinlock_t;



typedef struct {
 raw_rwlock_t raw_lock;




 unsigned int magic, owner_cpu;
 void *owner;


 struct lockdep_map dep_map;

} rwlock_t;
# 80 "include/linux/spinlock.h" 2

extern int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) generic__raw_read_trylock(raw_rwlock_t *lock);





# 1 "include/asm/spinlock.h" 1



# 1 "include/asm/atomic.h" 1
# 18 "include/asm/atomic.h"
typedef struct { int counter; } atomic_t;
# 46 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) void atomic_add(int i, atomic_t *v)
{
 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "addl %1,%0"
  :"+m" (v->counter)
  :"ir" (i));
}
# 61 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) void atomic_sub(int i, atomic_t *v)
{
 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "subl %1,%0"
  :"+m" (v->counter)
  :"ir" (i));
}
# 78 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_sub_and_test(int i, atomic_t *v)
{
 unsigned char c;

 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "subl %2,%0; sete %1"
  :"+m" (v->counter), "=qm" (c)
  :"ir" (i) : "memory");
 return c;
}







static __inline__ __attribute__((always_inline)) void atomic_inc(atomic_t *v)
{
 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "incl %0"
  :"+m" (v->counter));
}







static __inline__ __attribute__((always_inline)) void atomic_dec(atomic_t *v)
{
 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "decl %0"
  :"+m" (v->counter));
}
# 123 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_dec_and_test(atomic_t *v)
{
 unsigned char c;

 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "decl %0; sete %1"
  :"+m" (v->counter), "=qm" (c)
  : : "memory");
 return c != 0;
}
# 142 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_inc_and_test(atomic_t *v)
{
 unsigned char c;

 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "incl %0; sete %1"
  :"+m" (v->counter), "=qm" (c)
  : : "memory");
 return c != 0;
}
# 162 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_add_negative(int i, atomic_t *v)
{
 unsigned char c;

 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "addl %2,%0; sets %1"
  :"+m" (v->counter), "=qm" (c)
  :"ir" (i) : "memory");
 return c;
}
# 180 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_add_return(int i, atomic_t *v)
{
 int __i;






 __i = i;
 __asm__ __volatile__(
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "xaddl %0, %1"
  :"+r" (i), "+m" (v->counter)
  : : "memory");
 return i + __i;
# 204 "include/asm/atomic.h"
}
# 213 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_sub_return(int i, atomic_t *v)
{
 return atomic_add_return(-i,v);
}
# 230 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_add_unless(atomic_t *v, int a, int u)
{
 int c, old;
 c = ((v)->counter);
 for (;;) {
  if (__builtin_expect(!!(c == (u)), 0))
   break;
  old = (((__typeof__(*(&(((v))->counter))))__cmpxchg((&(((v))->counter)),(unsigned long)((c)), (unsigned long)((c + (a))),sizeof(*(&(((v))->counter))))));
  if (__builtin_expect(!!(old == c), 1))
   break;
  c = old;
 }
 return c != (u);
}
# 265 "include/asm/atomic.h"
# 1 "include/asm-generic/atomic.h" 1
# 141 "include/asm-generic/atomic.h"
typedef atomic_t atomic_long_t;


static inline __attribute__((always_inline)) long atomic_long_read(atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return (long)((v)->counter);
}

static inline __attribute__((always_inline)) void atomic_long_set(atomic_long_t *l, long i)
{
 atomic_t *v = (atomic_t *)l;

 (((v)->counter) = (i));
}

static inline __attribute__((always_inline)) void atomic_long_inc(atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 atomic_inc(v);
}

static inline __attribute__((always_inline)) void atomic_long_dec(atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 atomic_dec(v);
}

static inline __attribute__((always_inline)) void atomic_long_add(long i, atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 atomic_add(i, v);
}

static inline __attribute__((always_inline)) void atomic_long_sub(long i, atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 atomic_sub(i, v);
}

static inline __attribute__((always_inline)) int atomic_long_sub_and_test(long i, atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return atomic_sub_and_test(i, v);
}

static inline __attribute__((always_inline)) int atomic_long_dec_and_test(atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return atomic_dec_and_test(v);
}

static inline __attribute__((always_inline)) int atomic_long_inc_and_test(atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return atomic_inc_and_test(v);
}

static inline __attribute__((always_inline)) int atomic_long_add_negative(long i, atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return atomic_add_negative(i, v);
}

static inline __attribute__((always_inline)) long atomic_long_add_return(long i, atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return (long)atomic_add_return(i, v);
}

static inline __attribute__((always_inline)) long atomic_long_sub_return(long i, atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return (long)atomic_sub_return(i, v);
}

static inline __attribute__((always_inline)) long atomic_long_inc_return(atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return (long)(atomic_add_return(1,v));
}

static inline __attribute__((always_inline)) long atomic_long_dec_return(atomic_long_t *l)
{
 atomic_t *v = (atomic_t *)l;

 return (long)(atomic_sub_return(1,v));
}

static inline __attribute__((always_inline)) long atomic_long_add_unless(atomic_long_t *l, long a, long u)
{
 atomic_t *v = (atomic_t *)l;

 return (long)atomic_add_unless(v, a, u);
}
# 266 "include/asm/atomic.h" 2
# 5 "include/asm/spinlock.h" 2
# 1 "include/asm/rwlock.h" 1
# 6 "include/asm/spinlock.h" 2
# 30 "include/asm/spinlock.h"
static inline __attribute__((always_inline)) int __raw_spin_is_locked(raw_spinlock_t *x)
{
 return *(volatile signed char *)(&(x)->slock) <= 0;
}

static inline __attribute__((always_inline)) void __raw_spin_lock(raw_spinlock_t *lock)
{
 asm volatile("\n1:\t"
       ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " " ; decb %0\n\t"
       "jns 3f\n"
       "2:\t"
       "rep;nop\n\t"
       "cmpb $0,%0\n\t"
       "jle 2b\n\t"
       "jmp 1b\n"
       "3:\n\t"
       : "+m" (lock->slock) : : "memory");
}
# 87 "include/asm/spinlock.h"
static inline __attribute__((always_inline)) int __raw_spin_trylock(raw_spinlock_t *lock)
{
 char oldval;
 asm volatile(
  "xchgb %b0,%1"
  :"=q" (oldval), "+m" (lock->slock)
  :"0" (0) : "memory");
 return oldval > 0;
}
# 113 "include/asm/spinlock.h"
static inline __attribute__((always_inline)) void __raw_spin_unlock(raw_spinlock_t *lock)
{
 char oldval = 1;

 asm volatile("xchgb %b0, %1"
       : "=q" (oldval), "+m" (lock->slock)
       : "0" (oldval) : "memory");
}



static inline __attribute__((always_inline)) void __raw_spin_unlock_wait(raw_spinlock_t *lock)
{
 while (__raw_spin_is_locked(lock))
  rep_nop();
}
# 155 "include/asm/spinlock.h"
static inline __attribute__((always_inline)) int __raw_read_can_lock(raw_rwlock_t *x)
{
 return (int)(x)->lock > 0;
}





static inline __attribute__((always_inline)) int __raw_write_can_lock(raw_rwlock_t *x)
{
 return (x)->lock == 0x01000000;
}

static inline __attribute__((always_inline)) void __raw_read_lock(raw_rwlock_t *rw)
{
 asm volatile(".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " " subl $1,(%0)\n\t"
       "jns 1f\n"
       "call __read_lock_failed\n\t"
       "1:\n"
       ::"a" (rw) : "memory");
}

static inline __attribute__((always_inline)) void __raw_write_lock(raw_rwlock_t *rw)
{
 asm volatile(".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " " subl $" "0x01000000" ",(%0)\n\t"
       "jz 1f\n"
       "call __write_lock_failed\n\t"
       "1:\n"
       ::"a" (rw) : "memory");
}

static inline __attribute__((always_inline)) int __raw_read_trylock(raw_rwlock_t *lock)
{
 atomic_t *count = (atomic_t *)lock;
 atomic_dec(count);
 if (((count)->counter) >= 0)
  return 1;
 atomic_inc(count);
 return 0;
}

static inline __attribute__((always_inline)) int __raw_write_trylock(raw_rwlock_t *lock)
{
 atomic_t *count = (atomic_t *)lock;
 if (atomic_sub_and_test(0x01000000, count))
  return 1;
 atomic_add(0x01000000, count);
 return 0;
}

static inline __attribute__((always_inline)) void __raw_read_unlock(raw_rwlock_t *rw)
{
 asm volatile(".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "incl %0" :"+m" (rw->lock) : : "memory");
}

static inline __attribute__((always_inline)) void __raw_write_unlock(raw_rwlock_t *rw)
{
 asm volatile(".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "addl $" "0x01000000" ", %0"
     : "+m" (rw->lock) : : "memory");
}
# 88 "include/linux/spinlock.h" 2





  extern void __spin_lock_init(spinlock_t *lock, const char *name,
          struct lock_class_key *key);
# 108 "include/linux/spinlock.h"
  extern void __rwlock_init(rwlock_t *lock, const char *name,
       struct lock_class_key *key);
# 133 "include/linux/spinlock.h"
# 1 "include/linux/spinlock_api_smp.h" 1
# 18 "include/linux/spinlock_api_smp.h"
int in_lock_functions(unsigned long addr);



void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_nested(spinlock_t *lock, int subclass)
       ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_bh(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_irq(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock_irq(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock_irq(rwlock_t *lock) ;
unsigned long __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_irqsave(spinlock_t *lock)
       ;
unsigned long __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_irqsave_nested(spinlock_t *lock, int subclass)
       ;
unsigned long __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock_irqsave(rwlock_t *lock)
       ;
unsigned long __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock_irqsave(rwlock_t *lock)
       ;
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_trylock(spinlock_t *lock);
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_trylock(rwlock_t *lock);
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_trylock(rwlock_t *lock);
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_trylock_bh(spinlock_t *lock);
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock_bh(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock_irq(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock_irq(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock_irq(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags)
       ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
       ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
       ;
# 134 "include/linux/spinlock.h" 2





 extern void _raw_spin_lock(spinlock_t *lock);

 extern int _raw_spin_trylock(spinlock_t *lock);
 extern void _raw_spin_unlock(spinlock_t *lock);
 extern void _raw_read_lock(rwlock_t *lock);
 extern int _raw_read_trylock(rwlock_t *lock);
 extern void _raw_read_unlock(rwlock_t *lock);
 extern void _raw_write_lock(rwlock_t *lock);
 extern int _raw_write_trylock(rwlock_t *lock);
 extern void _raw_write_unlock(rwlock_t *lock);
# 289 "include/linux/spinlock.h"
static inline __attribute__((always_inline)) void double_spin_lock(spinlock_t *l1, spinlock_t *l2,
        bool l1_first)


{
 if (l1_first) {
  _spin_lock(l1);
  _spin_lock(l2);
 } else {
  _spin_lock(l2);
  _spin_lock(l1);
 }
}






static inline __attribute__((always_inline)) void double_spin_unlock(spinlock_t *l1, spinlock_t *l2,
          bool l1_taken_first)


{
 if (l1_taken_first) {
  _spin_unlock(l2);
  _spin_unlock(l1);
 } else {
  _spin_unlock(l1);
  _spin_unlock(l2);
 }
}
# 332 "include/linux/spinlock.h"
extern int _atomic_dec_and_lock(atomic_t *atomic, spinlock_t *lock);
# 10 "include/linux/module.h" 2

# 1 "include/linux/stat.h" 1





# 1 "include/asm/stat.h" 1



struct __old_kernel_stat {
 unsigned short st_dev;
 unsigned short st_ino;
 unsigned short st_mode;
 unsigned short st_nlink;
 unsigned short st_uid;
 unsigned short st_gid;
 unsigned short st_rdev;
 unsigned long st_size;
 unsigned long st_atime;
 unsigned long st_mtime;
 unsigned long st_ctime;
};

struct stat {
 unsigned long st_dev;
 unsigned long st_ino;
 unsigned short st_mode;
 unsigned short st_nlink;
 unsigned short st_uid;
 unsigned short st_gid;
 unsigned long st_rdev;
 unsigned long st_size;
 unsigned long st_blksize;
 unsigned long st_blocks;
 unsigned long st_atime;
 unsigned long st_atime_nsec;
 unsigned long st_mtime;
 unsigned long st_mtime_nsec;
 unsigned long st_ctime;
 unsigned long st_ctime_nsec;
 unsigned long __unused4;
 unsigned long __unused5;
};




struct stat64 {
 unsigned long long st_dev;
 unsigned char __pad0[4];


 unsigned long __st_ino;

 unsigned int st_mode;
 unsigned int st_nlink;

 unsigned long st_uid;
 unsigned long st_gid;

 unsigned long long st_rdev;
 unsigned char __pad3[4];

 long long st_size;
 unsigned long st_blksize;

 unsigned long long st_blocks;

 unsigned long st_atime;
 unsigned long st_atime_nsec;

 unsigned long st_mtime;
 unsigned int st_mtime_nsec;

 unsigned long st_ctime;
 unsigned long st_ctime_nsec;

 unsigned long long st_ino;
};
# 7 "include/linux/stat.h" 2
# 60 "include/linux/stat.h"
# 1 "include/linux/time.h" 1






# 1 "include/linux/seqlock.h" 1
# 32 "include/linux/seqlock.h"
typedef struct {
 unsigned sequence;
 spinlock_t lock;
} seqlock_t;
# 60 "include/linux/seqlock.h"
static inline __attribute__((always_inline)) void write_seqlock(seqlock_t *sl)
{
 _spin_lock(&sl->lock);
 ++sl->sequence;
 __asm__ __volatile__ ("": : :"memory");
}

static inline __attribute__((always_inline)) void write_sequnlock(seqlock_t *sl)
{
 __asm__ __volatile__ ("": : :"memory");
 sl->sequence++;
 _spin_unlock(&sl->lock);
}

static inline __attribute__((always_inline)) int write_tryseqlock(seqlock_t *sl)
{
 int ret = (_spin_trylock(&sl->lock));

 if (ret) {
  ++sl->sequence;
  __asm__ __volatile__ ("": : :"memory");
 }
 return ret;
}


static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned read_seqbegin(const seqlock_t *sl)
{
 unsigned ret = sl->sequence;
 asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
 return ret;
}
# 101 "include/linux/seqlock.h"
static inline __attribute__((always_inline)) __attribute__((always_inline)) int read_seqretry(const seqlock_t *sl, unsigned iv)
{
 asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
 return (iv & 1) | (sl->sequence ^ iv);
}
# 115 "include/linux/seqlock.h"
typedef struct seqcount {
 unsigned sequence;
} seqcount_t;





static inline __attribute__((always_inline)) unsigned read_seqcount_begin(const seqcount_t *s)
{
 unsigned ret = s->sequence;
 asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
 return ret;
}






static inline __attribute__((always_inline)) int read_seqcount_retry(const seqcount_t *s, unsigned iv)
{
 asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
 return (iv & 1) | (s->sequence ^ iv);
}






static inline __attribute__((always_inline)) void write_seqcount_begin(seqcount_t *s)
{
 s->sequence++;
 __asm__ __volatile__ ("": : :"memory");
}

static inline __attribute__((always_inline)) void write_seqcount_end(seqcount_t *s)
{
 __asm__ __volatile__ ("": : :"memory");
 s->sequence++;
}
# 8 "include/linux/time.h" 2




struct timespec {
 time_t tv_sec;
 long tv_nsec;
};


struct timeval {
 time_t tv_sec;
 suseconds_t tv_usec;
};

struct timezone {
 int tz_minuteswest;
 int tz_dsttime;
};
# 39 "include/linux/time.h"
static inline __attribute__((always_inline)) int timespec_equal(struct timespec *a, struct timespec *b)
{
 return (a->tv_sec == b->tv_sec) && (a->tv_nsec == b->tv_nsec);
}






static inline __attribute__((always_inline)) int timespec_compare(const struct timespec *lhs, const struct timespec *rhs)
{
 if (lhs->tv_sec < rhs->tv_sec)
  return -1;
 if (lhs->tv_sec > rhs->tv_sec)
  return 1;
 return lhs->tv_nsec - rhs->tv_nsec;
}

static inline __attribute__((always_inline)) int timeval_compare(const struct timeval *lhs, const struct timeval *rhs)
{
 if (lhs->tv_sec < rhs->tv_sec)
  return -1;
 if (lhs->tv_sec > rhs->tv_sec)
  return 1;
 return lhs->tv_usec - rhs->tv_usec;
}

extern unsigned long mktime(const unsigned int year, const unsigned int mon,
       const unsigned int day, const unsigned int hour,
       const unsigned int min, const unsigned int sec);

extern void set_normalized_timespec(struct timespec *ts, time_t sec, long nsec);




static inline __attribute__((always_inline)) struct timespec timespec_sub(struct timespec lhs,
      struct timespec rhs)
{
 struct timespec ts_delta;
 set_normalized_timespec(&ts_delta, lhs.tv_sec - rhs.tv_sec,
    lhs.tv_nsec - rhs.tv_nsec);
 return ts_delta;
}







extern struct timespec xtime;
extern struct timespec wall_to_monotonic;
extern seqlock_t xtime_lock __attribute__((weak));

extern unsigned long read_persistent_clock(void);
void timekeeping_init(void);

static inline __attribute__((always_inline)) unsigned long get_seconds(void)
{
 return xtime.tv_sec;
}

struct timespec current_kernel_time(void);




extern void do_gettimeofday(struct timeval *tv);
extern int do_settimeofday(struct timespec *tv);
extern int do_sys_settimeofday(struct timespec *tv, struct timezone *tz);

extern long do_utimes(int dfd, char *filename, struct timespec *times, int flags);
struct itimerval;
extern int do_setitimer(int which, struct itimerval *value,
   struct itimerval *ovalue);
extern unsigned int alarm_setitimer(unsigned int seconds);
extern int do_getitimer(int which, struct itimerval *value);
extern void getnstimeofday(struct timespec *tv);

extern struct timespec timespec_trunc(struct timespec t, unsigned gran);
extern int timekeeping_is_continuous(void);
extern void update_wall_time(void);
# 131 "include/linux/time.h"
static inline __attribute__((always_inline)) s64 timespec_to_ns(const struct timespec *ts)
{
 return ((s64) ts->tv_sec * 1000000000L) + ts->tv_nsec;
}
# 143 "include/linux/time.h"
static inline __attribute__((always_inline)) s64 timeval_to_ns(const struct timeval *tv)
{
 return ((s64) tv->tv_sec * 1000000000L) +
  tv->tv_usec * 1000L;
}







extern struct timespec ns_to_timespec(const s64 nsec);







extern struct timeval ns_to_timeval(const s64 nsec);






static inline __attribute__((always_inline)) void timespec_add_ns(struct timespec *a, u64 ns)
{
 ns += a->tv_nsec;
 while(__builtin_expect(!!(ns >= 1000000000L), 0)) {
  ns -= 1000000000L;
  a->tv_sec++;
 }
 a->tv_nsec = ns;
}
# 197 "include/linux/time.h"
struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};

struct itimerval {
 struct timeval it_interval;
 struct timeval it_value;
};
# 61 "include/linux/stat.h" 2

struct kstat {
 u64 ino;
 dev_t dev;
 umode_t mode;
 unsigned int nlink;
 uid_t uid;
 gid_t gid;
 dev_t rdev;
 loff_t size;
 struct timespec atime;
 struct timespec mtime;
 struct timespec ctime;
 unsigned long blksize;
 unsigned long long blocks;
};
# 12 "include/linux/module.h" 2


# 1 "include/linux/kmod.h" 1
# 23 "include/linux/kmod.h"
# 1 "include/linux/errno.h" 1
# 24 "include/linux/kmod.h" 2







extern int request_module(const char * name, ...) __attribute__ ((format (printf, 1, 2)));






struct key;
extern int call_usermodehelper_keys(char *path, char *argv[], char *envp[],
        struct key *session_keyring, int wait);

static inline __attribute__((always_inline)) int
call_usermodehelper(char *path, char **argv, char **envp, int wait)
{
 return call_usermodehelper_keys(path, argv, envp, ((void *)0), wait);
}

extern void usermodehelper_init(void);

struct file;
extern int call_usermodehelper_pipe(char *path, char *argv[], char *envp[],
        struct file **filp);
# 15 "include/linux/module.h" 2
# 1 "include/linux/elf.h" 1




# 1 "include/linux/auxvec.h" 1



# 1 "include/asm/auxvec.h" 1
# 5 "include/linux/auxvec.h" 2
# 6 "include/linux/elf.h" 2
# 1 "include/linux/elf-em.h" 1
# 7 "include/linux/elf.h" 2
# 1 "include/asm/elf.h" 1
# 9 "include/asm/elf.h"
# 1 "include/asm/user.h" 1
# 44 "include/asm/user.h"
struct user_i387_struct {
 long cwd;
 long swd;
 long twd;
 long fip;
 long fcs;
 long foo;
 long fos;
 long st_space[20];
};

struct user_fxsr_struct {
 unsigned short cwd;
 unsigned short swd;
 unsigned short twd;
 unsigned short fop;
 long fip;
 long fcs;
 long foo;
 long fos;
 long mxcsr;
 long reserved;
 long st_space[32];
 long xmm_space[32];
 long padding[56];
};







struct user_regs_struct {
 long ebx, ecx, edx, esi, edi, ebp, eax;
 unsigned short ds, __ds, es, __es;
 unsigned short fs, __fs, gs, __gs;
 long orig_eax, eip;
 unsigned short cs, __cs;
 long eflags, esp;
 unsigned short ss, __ss;
};




struct user{


  struct user_regs_struct regs;

  int u_fpvalid;

  struct user_i387_struct i387;

  unsigned long int u_tsize;
  unsigned long int u_dsize;
  unsigned long int u_ssize;
  unsigned long start_code;
  unsigned long start_stack;



  long int signal;
  int reserved;
  struct user_pt_regs * u_ar0;

  struct user_i387_struct* u_fpstate;
  unsigned long magic;
  char u_comm[32];
  int u_debugreg[8];
};
# 10 "include/asm/elf.h" 2
# 25 "include/asm/elf.h"
typedef unsigned long elf_greg_t;


typedef elf_greg_t elf_gregset_t[(sizeof (struct user_regs_struct) / sizeof(elf_greg_t))];

typedef struct user_i387_struct elf_fpregset_t;
typedef struct user_fxsr_struct elf_fpxregset_t;
# 50 "include/asm/elf.h"
# 1 "include/asm/desc.h" 1



# 1 "include/asm/ldt.h" 1
# 15 "include/asm/ldt.h"
struct user_desc {
 unsigned int entry_number;
 unsigned long base_addr;
 unsigned int limit;
 unsigned int seg_32bit:1;
 unsigned int contents:2;
 unsigned int read_exec_only:1;
 unsigned int limit_in_pages:1;
 unsigned int seg_not_present:1;
 unsigned int useable:1;
};
# 5 "include/asm/desc.h" 2





# 1 "include/linux/smp.h" 1
# 11 "include/linux/smp.h"
extern void cpu_idle(void);







# 1 "include/asm/smp.h" 1
# 15 "include/asm/smp.h"
# 1 "include/asm/mpspec.h" 1




# 1 "include/asm/mpspec_def.h" 1
# 19 "include/asm/mpspec_def.h"
struct intel_mp_floating
{
 char mpf_signature[4];
 unsigned long mpf_physptr;
 unsigned char mpf_length;
 unsigned char mpf_specification;
 unsigned char mpf_checksum;
 unsigned char mpf_feature1;
 unsigned char mpf_feature2;
 unsigned char mpf_feature3;
 unsigned char mpf_feature4;
 unsigned char mpf_feature5;
};

struct mp_config_table
{
 char mpc_signature[4];

 unsigned short mpc_length;
 char mpc_spec;
 char mpc_checksum;
 char mpc_oem[8];
 char mpc_productid[12];
 unsigned long mpc_oemptr;
 unsigned short mpc_oemsize;
 unsigned short mpc_oemcount;
 unsigned long mpc_lapic;
 unsigned long reserved;
};
# 58 "include/asm/mpspec_def.h"
struct mpc_config_processor
{
 unsigned char mpc_type;
 unsigned char mpc_apicid;
 unsigned char mpc_apicver;
 unsigned char mpc_cpuflag;


 unsigned long mpc_cpufeature;



 unsigned long mpc_featureflag;
 unsigned long mpc_reserved[2];
};

struct mpc_config_bus
{
 unsigned char mpc_type;
 unsigned char mpc_busid;
 unsigned char mpc_bustype[6];
};
# 101 "include/asm/mpspec_def.h"
struct mpc_config_ioapic
{
 unsigned char mpc_type;
 unsigned char mpc_apicid;
 unsigned char mpc_apicver;
 unsigned char mpc_flags;

 unsigned long mpc_apicaddr;
};

struct mpc_config_intsrc
{
 unsigned char mpc_type;
 unsigned char mpc_irqtype;
 unsigned short mpc_irqflag;
 unsigned char mpc_srcbus;
 unsigned char mpc_srcbusirq;
 unsigned char mpc_dstapic;
 unsigned char mpc_dstirq;
};

enum mp_irq_source_types {
 mp_INT = 0,
 mp_NMI = 1,
 mp_SMI = 2,
 mp_ExtINT = 3
};






struct mpc_config_lintsrc
{
 unsigned char mpc_type;
 unsigned char mpc_irqtype;
 unsigned short mpc_irqflag;
 unsigned char mpc_srcbusid;
 unsigned char mpc_srcbusirq;
 unsigned char mpc_destapic;

 unsigned char mpc_destapiclint;
};

struct mp_config_oemtable
{
 char oem_signature[4];

 unsigned short oem_length;
 char oem_rev;
 char oem_checksum;
 char mpc_oem[8];
};

struct mpc_config_translation
{
        unsigned char mpc_type;
        unsigned char trans_len;
        unsigned char trans_type;
        unsigned char trans_quad;
        unsigned char trans_global;
        unsigned char trans_local;
        unsigned short trans_reserved;
};
# 179 "include/asm/mpspec_def.h"
enum mp_bustype {
 MP_BUS_ISA = 1,
 MP_BUS_EISA,
 MP_BUS_PCI,
 MP_BUS_MCA,
};
# 6 "include/asm/mpspec.h" 2
# 1 "include/asm-i386/mach-default/mach_mpspec.h" 1
# 7 "include/asm/mpspec.h" 2

extern int mp_bus_id_to_type [256];
extern int mp_bus_id_to_node [256];
extern int mp_bus_id_to_local [256];
extern int quad_local_to_mp_bus_id [8/4][4];
extern int mp_bus_id_to_pci_bus [256];

extern unsigned int def_to_bigsmp;
extern unsigned int boot_cpu_physical_apicid;
extern int smp_found_config;
extern void find_smp_config (void);
extern void get_smp_config (void);
extern int nr_ioapics;
extern int apic_version [256];
extern int mp_irq_entries;
extern struct mpc_config_intsrc mp_irqs [256];
extern int mpc_default_type;
extern unsigned long mp_lapic_addr;
extern int pic_mode;


extern void mp_register_lapic (u8 id, u8 enabled);
extern void mp_register_lapic_address (u64 address);
extern void mp_register_ioapic (u8 id, u32 address, u32 gsi_base);
extern void mp_override_legacy_irq (u8 bus_irq, u8 polarity, u8 trigger, u32 gsi);
extern void mp_config_acpi_legacy_irqs (void);
extern int mp_register_gsi (u32 gsi, int edge_level, int active_high_low);




struct physid_mask
{
 unsigned long mask[(((256)+32 -1)/32)];
};

typedef struct physid_mask physid_mask_t;
# 78 "include/asm/mpspec.h"
extern physid_mask_t phys_cpu_present_map;
# 16 "include/asm/smp.h" 2
# 1 "include/asm/apic.h" 1



# 1 "include/linux/pm.h" 1
# 34 "include/linux/pm.h"
typedef int pm_request_t;
# 43 "include/linux/pm.h"
typedef int pm_dev_t;
# 56 "include/linux/pm.h"
enum
{
 PM_SYS_UNKNOWN = 0x00000000,
 PM_SYS_KBC = 0x41d00303,
 PM_SYS_COM = 0x41d00500,
 PM_SYS_IRDA = 0x41d00510,
 PM_SYS_FDC = 0x41d00700,
 PM_SYS_VGA = 0x41d00900,
 PM_SYS_PCMCIA = 0x41d00e00,
};
# 75 "include/linux/pm.h"
struct pm_dev;

typedef int (*pm_callback)(struct pm_dev *dev, pm_request_t rqst, void *data);




struct pm_dev
{
 pm_dev_t type;
 unsigned long id;
 pm_callback callback;
 void *data;

 unsigned long flags;
 unsigned long state;
 unsigned long prev_state;

 struct list_head entry;
};







extern void (*pm_idle)(void);
extern void (*pm_power_off)(void);

typedef int suspend_state_t;
# 159 "include/linux/pm.h"
struct pm_ops {
 int (*valid)(suspend_state_t state);
 int (*set_target)(suspend_state_t state);
 int (*prepare)(suspend_state_t state);
 int (*enter)(suspend_state_t state);
 int (*finish)(suspend_state_t state);
};

extern struct pm_ops *pm_ops;





extern void pm_set_ops(struct pm_ops *pm_ops);
extern int pm_valid_only_mem(suspend_state_t state);
# 183 "include/linux/pm.h"
extern void arch_suspend_disable_irqs(void);
# 192 "include/linux/pm.h"
extern void arch_suspend_enable_irqs(void);

extern int pm_suspend(suspend_state_t state);





struct device;

typedef struct pm_message {
 int event;
} pm_message_t;
# 265 "include/linux/pm.h"
struct dev_pm_info {
 pm_message_t power_state;
 unsigned can_wakeup:1;

 unsigned should_wakeup:1;
 struct list_head entry;

};

extern int device_power_down(pm_message_t state);
extern void device_power_up(void);
extern void device_resume(void);


extern int device_suspend(pm_message_t state);
extern int device_prepare_suspend(pm_message_t state);






extern int dpm_runtime_suspend(struct device *, pm_message_t);
extern void dpm_runtime_resume(struct device *);
extern void __suspend_report_result(const char *function, void *fn, int ret);
# 301 "include/linux/pm.h"
extern int (*platform_enable_wakeup)(struct device *dev, int is_on);

static inline __attribute__((always_inline)) int call_platform_enable_wakeup(struct device *dev, int is_on)
{
 if (platform_enable_wakeup)
  return (*platform_enable_wakeup)(dev, is_on);
 return 0;
}
# 5 "include/asm/apic.h" 2
# 1 "include/linux/delay.h" 1
# 10 "include/linux/delay.h"
extern unsigned long loops_per_jiffy;

# 1 "include/asm/delay.h" 1
# 11 "include/asm/delay.h"
extern void __bad_udelay(void);
extern void __bad_ndelay(void);

extern void __udelay(unsigned long usecs);
extern void __ndelay(unsigned long nsecs);
extern void __const_udelay(unsigned long usecs);
extern void __delay(unsigned long loops);
# 29 "include/asm/delay.h"
void use_tsc_delay(void);
# 13 "include/linux/delay.h" 2
# 38 "include/linux/delay.h"
void calibrate_delay(void);
void msleep(unsigned int msecs);
unsigned long msleep_interruptible(unsigned int msecs);

static inline __attribute__((always_inline)) void ssleep(unsigned int seconds)
{
 msleep(seconds * 1000);
}
# 6 "include/asm/apic.h" 2
# 1 "include/asm/fixmap.h" 1
# 22 "include/asm/fixmap.h"
extern unsigned long __FIXADDR_TOP;





# 1 "include/asm/acpi.h" 1
# 31 "include/asm/acpi.h"
# 1 "include/acpi/pdc_intel.h" 1
# 32 "include/asm/acpi.h" 2
# 59 "include/asm/acpi.h"
int __acpi_acquire_global_lock(unsigned int *lock);
int __acpi_release_global_lock(unsigned int *lock);
# 85 "include/asm/acpi.h"
extern void check_acpi_pci(void);





extern int acpi_lapic;
extern int acpi_ioapic;
extern int acpi_noirq;
extern int acpi_strict;
extern int acpi_disabled;
extern int acpi_ht;
extern int acpi_pci_disabled;
static inline __attribute__((always_inline)) void disable_acpi(void)
{
 acpi_disabled = 1;
 acpi_ht = 0;
 acpi_pci_disabled = 1;
 acpi_noirq = 1;
}




extern int acpi_gsi_to_irq(u32 gsi, unsigned int *irq);


extern int acpi_skip_timer_override;
extern int acpi_use_timer_override;


static inline __attribute__((always_inline)) void acpi_noirq_set(void) { acpi_noirq = 1; }
static inline __attribute__((always_inline)) void acpi_disable_pci(void)
{
 acpi_pci_disabled = 1;
 acpi_noirq_set();
}
extern int acpi_irq_balance_set(char *str);
# 138 "include/asm/acpi.h"
extern int acpi_save_state_mem(void);
extern void acpi_restore_state_mem(void);

extern unsigned long acpi_wakeup_address;


extern void acpi_reserve_bootmem(void);
# 29 "include/asm/fixmap.h" 2
# 1 "include/asm/apicdef.h" 1
# 125 "include/asm/apicdef.h"
struct local_apic {

        struct { unsigned int __reserved[4]; } __reserved_01;

        struct { unsigned int __reserved[4]; } __reserved_02;

        struct {
  unsigned int __reserved_1 : 24,
   phys_apic_id : 4,
   __reserved_2 : 4;
  unsigned int __reserved[3];
 } id;

        const
 struct {
  unsigned int version : 8,
   __reserved_1 : 8,
   max_lvt : 8,
   __reserved_2 : 8;
  unsigned int __reserved[3];
 } version;

        struct { unsigned int __reserved[4]; } __reserved_03;

        struct { unsigned int __reserved[4]; } __reserved_04;

        struct { unsigned int __reserved[4]; } __reserved_05;

        struct { unsigned int __reserved[4]; } __reserved_06;

        struct {
  unsigned int priority : 8,
   __reserved_1 : 24;
  unsigned int __reserved_2[3];
 } tpr;

        const
 struct {
  unsigned int priority : 8,
   __reserved_1 : 24;
  unsigned int __reserved_2[3];
 } apr;

        const
 struct {
  unsigned int priority : 8,
   __reserved_1 : 24;
  unsigned int __reserved_2[3];
 } ppr;

        struct {
  unsigned int eoi;
  unsigned int __reserved[3];
 } eoi;

        struct { unsigned int __reserved[4]; } __reserved_07;

        struct {
  unsigned int __reserved_1 : 24,
   logical_dest : 8;
  unsigned int __reserved_2[3];
 } ldr;

        struct {
  unsigned int __reserved_1 : 28,
   model : 4;
  unsigned int __reserved_2[3];
 } dfr;

        struct {
  unsigned int spurious_vector : 8,
   apic_enabled : 1,
   focus_cpu : 1,
   __reserved_2 : 22;
  unsigned int __reserved_3[3];
 } svr;

        struct {
         unsigned int bitfield;
  unsigned int __reserved[3];
 } isr [8];

        struct {
         unsigned int bitfield;
  unsigned int __reserved[3];
 } tmr [8];

        struct {
         unsigned int bitfield;
  unsigned int __reserved[3];
 } irr [8];

        union {
  struct {
   unsigned int send_cs_error : 1,
    receive_cs_error : 1,
    send_accept_error : 1,
    receive_accept_error : 1,
    __reserved_1 : 1,
    send_illegal_vector : 1,
    receive_illegal_vector : 1,
    illegal_register_address : 1,
    __reserved_2 : 24;
   unsigned int __reserved_3[3];
  } error_bits;
  struct {
   unsigned int errors;
   unsigned int __reserved_3[3];
  } all_errors;
 } esr;

        struct { unsigned int __reserved[4]; } __reserved_08;

        struct { unsigned int __reserved[4]; } __reserved_09;

        struct { unsigned int __reserved[4]; } __reserved_10;

        struct { unsigned int __reserved[4]; } __reserved_11;

        struct { unsigned int __reserved[4]; } __reserved_12;

        struct { unsigned int __reserved[4]; } __reserved_13;

        struct { unsigned int __reserved[4]; } __reserved_14;

        struct {
  unsigned int vector : 8,
   delivery_mode : 3,
   destination_mode : 1,
   delivery_status : 1,
   __reserved_1 : 1,
   level : 1,
   trigger : 1,
   __reserved_2 : 2,
   shorthand : 2,
   __reserved_3 : 12;
  unsigned int __reserved_4[3];
 } icr1;

        struct {
  union {
   unsigned int __reserved_1 : 24,
    phys_dest : 4,
    __reserved_2 : 4;
   unsigned int __reserved_3 : 24,
    logical_dest : 8;
  } dest;
  unsigned int __reserved_4[3];
 } icr2;

        struct {
  unsigned int vector : 8,
   __reserved_1 : 4,
   delivery_status : 1,
   __reserved_2 : 3,
   mask : 1,
   timer_mode : 1,
   __reserved_3 : 14;
  unsigned int __reserved_4[3];
 } lvt_timer;

        struct {
  unsigned int vector : 8,
   delivery_mode : 3,
   __reserved_1 : 1,
   delivery_status : 1,
   __reserved_2 : 3,
   mask : 1,
   __reserved_3 : 15;
  unsigned int __reserved_4[3];
 } lvt_thermal;

        struct {
  unsigned int vector : 8,
   delivery_mode : 3,
   __reserved_1 : 1,
   delivery_status : 1,
   __reserved_2 : 3,
   mask : 1,
   __reserved_3 : 15;
  unsigned int __reserved_4[3];
 } lvt_pc;

        struct {
  unsigned int vector : 8,
   delivery_mode : 3,
   __reserved_1 : 1,
   delivery_status : 1,
   polarity : 1,
   remote_irr : 1,
   trigger : 1,
   mask : 1,
   __reserved_2 : 15;
  unsigned int __reserved_3[3];
 } lvt_lint0;

        struct {
  unsigned int vector : 8,
   delivery_mode : 3,
   __reserved_1 : 1,
   delivery_status : 1,
   polarity : 1,
   remote_irr : 1,
   trigger : 1,
   mask : 1,
   __reserved_2 : 15;
  unsigned int __reserved_3[3];
 } lvt_lint1;

        struct {
  unsigned int vector : 8,
   __reserved_1 : 4,
   delivery_status : 1,
   __reserved_2 : 3,
   mask : 1,
   __reserved_3 : 15;
  unsigned int __reserved_4[3];
 } lvt_error;

        struct {
  unsigned int initial_count;
  unsigned int __reserved_2[3];
 } timer_icr;

        const
 struct {
  unsigned int curr_count;
  unsigned int __reserved_2[3];
 } timer_ccr;

        struct { unsigned int __reserved[4]; } __reserved_16;

        struct { unsigned int __reserved[4]; } __reserved_17;

        struct { unsigned int __reserved[4]; } __reserved_18;

        struct { unsigned int __reserved[4]; } __reserved_19;

        struct {
  unsigned int divisor : 4,
   __reserved_1 : 28;
  unsigned int __reserved_2[3];
 } timer_dcr;

        struct { unsigned int __reserved[4]; } __reserved_20;

} __attribute__ ((packed));
# 30 "include/asm/fixmap.h" 2
# 54 "include/asm/fixmap.h"
enum fixed_addresses {
 FIX_HOLE,
 FIX_VDSO,

 FIX_APIC_BASE,


 FIX_IO_APIC_BASE_0,
 FIX_IO_APIC_BASE_END = FIX_IO_APIC_BASE_0 + 64 -1,
# 77 "include/asm/fixmap.h"
 FIX_KMAP_BEGIN,
 FIX_KMAP_END = FIX_KMAP_BEGIN+(KM_TYPE_NR*8)-1,


 FIX_ACPI_BEGIN,
 FIX_ACPI_END = FIX_ACPI_BEGIN + 4 - 1,


 FIX_PCIE_MCFG,


 FIX_PARAVIRT_BOOTMAP,

 __end_of_permanent_fixed_addresses,


 FIX_BTMAP_END = __end_of_permanent_fixed_addresses,
 FIX_BTMAP_BEGIN = FIX_BTMAP_END + 16 - 1,
 FIX_WP_TEST,
 __end_of_fixed_addresses
};

extern void __set_fixmap (enum fixed_addresses idx,
     unsigned long phys, pgprot_t flags);
extern void reserve_top_address(unsigned long reserve);
# 124 "include/asm/fixmap.h"
extern void __this_fixmap_does_not_exist(void);






static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long fix_to_virt(const unsigned int idx)
{
# 142 "include/asm/fixmap.h"
 if (idx >= __end_of_fixed_addresses)
  __this_fixmap_does_not_exist();

        return (((unsigned long)__FIXADDR_TOP) - ((idx) << 12));
}

static inline __attribute__((always_inline)) unsigned long virt_to_fix(const unsigned long vaddr)
{
 do { if (__builtin_expect(!!((vaddr >= ((unsigned long)__FIXADDR_TOP) || vaddr < (((unsigned long)__FIXADDR_TOP) - (__end_of_permanent_fixed_addresses << 12)))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/asm/fixmap.h"), "i" (150), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
 return ((((unsigned long)__FIXADDR_TOP) - ((vaddr)&(~((1UL << 12)-1)))) >> 12);
}
# 7 "include/asm/apic.h" 2
# 20 "include/asm/apic.h"
extern int apic_verbosity;
# 34 "include/asm/apic.h"
extern void generic_apic_probe(void);
# 51 "include/asm/apic.h"
static __inline __attribute__((always_inline)) __attribute__((regparm(3))) void native_apic_write(unsigned long reg,
      unsigned long v)
{
 *((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg)) = v;
}

static __inline __attribute__((always_inline)) __attribute__((regparm(3))) void native_apic_write_atomic(unsigned long reg,
             unsigned long v)
{
 ((__typeof__(*((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg))))__xchg((unsigned long)(v),((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg)),sizeof(*((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg)))));
}

static __inline __attribute__((always_inline)) __attribute__((regparm(3))) unsigned long native_apic_read(unsigned long reg)
{
 return *((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg));
}

void apic_wait_icr_idle(void);
unsigned long safe_apic_wait_icr_idle(void);
int get_physical_broadcast(void);
# 82 "include/asm/apic.h"
static inline __attribute__((always_inline)) void ack_APIC_irq(void)
{
# 92 "include/asm/apic.h"
 apic_write((0xB0),(0));
}

extern int lapic_get_maxlvt(void);
extern void clear_local_APIC(void);
extern void connect_bsp_APIC (void);
extern void disconnect_bsp_APIC (int virt_wire_setup);
extern void disable_local_APIC (void);
extern void lapic_shutdown (void);
extern int verify_local_APIC (void);
extern void cache_APIC_registers (void);
extern void sync_Arb_IDs (void);
extern void init_bsp_APIC (void);
extern void setup_local_APIC (void);
extern void init_apic_mappings (void);
extern void smp_local_timer_interrupt (void);
extern void setup_boot_APIC_clock (void);
extern void setup_secondary_APIC_clock (void);
extern int APIC_init_uniprocessor (void);

extern void enable_NMI_through_LVT0 (void * dummy);



extern int timer_over_8254;
extern int local_apic_timer_c2_ok;
# 17 "include/asm/smp.h" 2

# 1 "include/asm/io_apic.h" 1
# 19 "include/asm/io_apic.h"
union IO_APIC_reg_00 {
 u32 raw;
 struct {
  u32 __reserved_2 : 14,
   LTS : 1,
   delivery_type : 1,
   __reserved_1 : 8,
   ID : 8;
 } __attribute__ ((packed)) bits;
};

union IO_APIC_reg_01 {
 u32 raw;
 struct {
  u32 version : 8,
   __reserved_2 : 7,
   PRQ : 1,
   entries : 8,
   __reserved_1 : 8;
 } __attribute__ ((packed)) bits;
};

union IO_APIC_reg_02 {
 u32 raw;
 struct {
  u32 __reserved_2 : 24,
   arbitration : 4,
   __reserved_1 : 4;
 } __attribute__ ((packed)) bits;
};

union IO_APIC_reg_03 {
 u32 raw;
 struct {
  u32 boot_DT : 1,
   __reserved_1 : 31;
 } __attribute__ ((packed)) bits;
};




extern int nr_ioapics;
extern int nr_ioapic_registers[64];

enum ioapic_irq_destination_types {
 dest_Fixed = 0,
 dest_LowestPrio = 1,
 dest_SMI = 2,
 dest__reserved_1 = 3,
 dest_NMI = 4,
 dest_INIT = 5,
 dest__reserved_2 = 6,
 dest_ExtINT = 7
};

struct IO_APIC_route_entry {
 __u32 vector : 8,
  delivery_mode : 3,



  dest_mode : 1,
  delivery_status : 1,
  polarity : 1,
  irr : 1,
  trigger : 1,
  mask : 1,
  __reserved_2 : 15;

 union { struct { __u32
     __reserved_1 : 24,
     physical_dest : 4,
     __reserved_2 : 4;
   } physical;

   struct { __u32
     __reserved_1 : 24,
     logical_dest : 8;
   } logical;
 } dest;

} __attribute__ ((packed));






extern struct mpc_config_ioapic mp_ioapics[64];


extern int mp_irq_entries;


extern struct mpc_config_intsrc mp_irqs[256];


extern int mpc_default_type;


extern int sis_apic_bug;


extern int skip_ioapic_setup;

static inline __attribute__((always_inline)) void disable_ioapic_setup(void)
{
 skip_ioapic_setup = 1;
}

static inline __attribute__((always_inline)) int ioapic_setup_disabled(void)
{
 return skip_ioapic_setup;
}
# 142 "include/asm/io_apic.h"
extern int io_apic_get_unique_id (int ioapic, int apic_id);
extern int io_apic_get_version (int ioapic);
extern int io_apic_get_redir_entries (int ioapic);
extern int io_apic_set_pci_routing (int ioapic, int pin, int irq, int edge_level, int active_high_low);
extern int timer_uses_ioapic_pin_0;


extern int (*ioapic_renumber_irq)(int ioapic, int irq);
# 19 "include/asm/smp.h" 2
# 30 "include/asm/smp.h"
extern void smp_alloc_memory(void);
extern int pic_mode;
extern int smp_num_siblings;
extern cpumask_t cpu_sibling_map[];
extern cpumask_t cpu_core_map[];

extern void (*mtrr_hook) (void);
extern void zap_low_mappings (void);
extern void lock_ipi_call_lock(void);
extern void unlock_ipi_call_lock(void);


extern u8 x86_cpu_to_apicid[];




extern void cpu_exit_clear(void);
extern void cpu_uninit(void);


struct smp_ops
{
 void (*smp_prepare_boot_cpu)(void);
 void (*smp_prepare_cpus)(unsigned max_cpus);
 int (*cpu_up)(unsigned cpu);
 void (*smp_cpus_done)(unsigned max_cpus);

 void (*smp_send_stop)(void);
 void (*smp_send_reschedule)(int cpu);
 int (*smp_call_function_mask)(cpumask_t mask,
          void (*func)(void *info), void *info,
          int wait);
};

extern struct smp_ops smp_ops;

static inline __attribute__((always_inline)) void smp_prepare_boot_cpu(void)
{
 smp_ops.smp_prepare_boot_cpu();
}
static inline __attribute__((always_inline)) void smp_prepare_cpus(unsigned int max_cpus)
{
 smp_ops.smp_prepare_cpus(max_cpus);
}
static inline __attribute__((always_inline)) int __cpu_up(unsigned int cpu)
{
 return smp_ops.cpu_up(cpu);
}
static inline __attribute__((always_inline)) void smp_cpus_done(unsigned int max_cpus)
{
 smp_ops.smp_cpus_done(max_cpus);
}

static inline __attribute__((always_inline)) void smp_send_stop(void)
{
 smp_ops.smp_send_stop();
}
static inline __attribute__((always_inline)) void smp_send_reschedule(int cpu)
{
 smp_ops.smp_send_reschedule(cpu);
}
static inline __attribute__((always_inline)) int smp_call_function_mask(cpumask_t mask,
      void (*func) (void *info), void *info,
      int wait)
{
 return smp_ops.smp_call_function_mask(mask, func, info, wait);
}

void native_smp_prepare_boot_cpu(void);
void native_smp_prepare_cpus(unsigned int max_cpus);
int native_cpu_up(unsigned int cpunum);
void native_smp_cpus_done(unsigned int max_cpus);
# 114 "include/asm/smp.h"
extern __typeof__(int) per_cpu__cpu_number;


extern cpumask_t cpu_callout_map;
extern cpumask_t cpu_callin_map;
extern cpumask_t cpu_possible_map;


static inline __attribute__((always_inline)) int num_booting_cpus(void)
{
 return __cpus_weight(&(cpu_callout_map), 8);
}

extern int safe_smp_processor_id(void);
extern int __cpu_disable(void);
extern void __cpu_die(unsigned int cpu);
extern unsigned int num_processors;
# 150 "include/asm/smp.h"
# 1 "include/asm-i386/mach-default/mach_apicdef.h" 1





static inline __attribute__((always_inline)) unsigned get_apic_id(unsigned long x)
{
 return (((x)>>24)&0xF);
}
# 151 "include/asm/smp.h" 2
static inline __attribute__((always_inline)) int hard_smp_processor_id(void)
{

 return get_apic_id(*(unsigned long *)((fix_to_virt(FIX_APIC_BASE))+0x20));
}
# 166 "include/asm/smp.h"
extern u8 apicid_2_node[];


static __inline __attribute__((always_inline)) int logical_smp_processor_id(void)
{

 return (((*(unsigned long *)((fix_to_virt(FIX_APIC_BASE))+0xD0))>>24)&0xFF);
}
# 20 "include/linux/smp.h" 2
# 29 "include/linux/smp.h"
extern void smp_send_stop(void);




extern void smp_send_reschedule(int cpu);





extern void smp_prepare_cpus(unsigned int max_cpus);




extern int __cpu_up(unsigned int cpunum);




extern void smp_cpus_done(unsigned int max_cpus);




int smp_call_function(void(*func)(void *info), void *info, int retry, int wait);

int smp_call_function_single(int cpuid, void (*func) (void *info), void *info,
    int retry, int wait);




int on_each_cpu(void (*func) (void *info), void *info, int retry, int wait);
# 79 "include/linux/smp.h"
void smp_prepare_boot_cpu(void);
# 136 "include/linux/smp.h"
void smp_setup_processor_id(void);
# 11 "include/asm/desc.h" 2
# 1 "include/linux/percpu.h" 1




# 1 "include/linux/slab.h" 1
# 14 "include/linux/slab.h"
# 1 "include/linux/gfp.h" 1



# 1 "include/linux/mmzone.h" 1
# 9 "include/linux/mmzone.h"
# 1 "include/linux/wait.h" 1
# 26 "include/linux/wait.h"
# 1 "include/asm/current.h" 1






struct task_struct;

extern __typeof__(struct task_struct *) per_cpu__current_task;
static inline __attribute__((always_inline)) __attribute__((always_inline)) struct task_struct *get_current(void)
{
 return ({ typeof(per_cpu__current_task) ret__; switch (sizeof(per_cpu__current_task)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__current_task)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__current_task)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__current_task)); break; default: __bad_percpu_size(); } ret__; });
}
# 27 "include/linux/wait.h" 2

typedef struct __wait_queue wait_queue_t;
typedef int (*wait_queue_func_t)(wait_queue_t *wait, unsigned mode, int sync, void *key);
int default_wake_function(wait_queue_t *wait, unsigned mode, int sync, void *key);

struct __wait_queue {
 unsigned int flags;

 void *private;
 wait_queue_func_t func;
 struct list_head task_list;
};

struct wait_bit_key {
 void *flags;
 int bit_nr;
};

struct wait_bit_queue {
 struct wait_bit_key key;
 wait_queue_t wait;
};

struct __wait_queue_head {
 spinlock_t lock;
 struct list_head task_list;
};
typedef struct __wait_queue_head wait_queue_head_t;

struct task_struct;
# 80 "include/linux/wait.h"
extern void init_waitqueue_head(wait_queue_head_t *q);
# 91 "include/linux/wait.h"
static inline __attribute__((always_inline)) void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
{
 q->flags = 0;
 q->private = p;
 q->func = default_wake_function;
}

static inline __attribute__((always_inline)) void init_waitqueue_func_entry(wait_queue_t *q,
     wait_queue_func_t func)
{
 q->flags = 0;
 q->private = ((void *)0);
 q->func = func;
}

static inline __attribute__((always_inline)) int waitqueue_active(wait_queue_head_t *q)
{
 return !list_empty(&q->task_list);
}
# 120 "include/linux/wait.h"
extern void add_wait_queue(wait_queue_head_t *q, wait_queue_t * wait) __attribute__((regparm(3)));
extern void add_wait_queue_exclusive(wait_queue_head_t *q, wait_queue_t * wait) __attribute__((regparm(3)));
extern void remove_wait_queue(wait_queue_head_t *q, wait_queue_t * wait) __attribute__((regparm(3)));

static inline __attribute__((always_inline)) void __add_wait_queue(wait_queue_head_t *head, wait_queue_t *new)
{
 list_add(&new->task_list, &head->task_list);
}




static inline __attribute__((always_inline)) void __add_wait_queue_tail(wait_queue_head_t *head,
      wait_queue_t *new)
{
 list_add_tail(&new->task_list, &head->task_list);
}

static inline __attribute__((always_inline)) void __remove_wait_queue(wait_queue_head_t *head,
       wait_queue_t *old)
{
 list_del(&old->task_list);
}

void __wake_up(wait_queue_head_t *q, unsigned int mode, int nr, void *key) __attribute__((regparm(3)));
extern void __wake_up_locked(wait_queue_head_t *q, unsigned int mode) __attribute__((regparm(3)));
extern void __wake_up_sync(wait_queue_head_t *q, unsigned int mode, int nr) __attribute__((regparm(3)));
void __wake_up_bit(wait_queue_head_t *, void *, int) __attribute__((regparm(3)));
int __wait_on_bit(wait_queue_head_t *, struct wait_bit_queue *, int (*)(void *), unsigned) __attribute__((regparm(3)));
int __wait_on_bit_lock(wait_queue_head_t *, struct wait_bit_queue *, int (*)(void *), unsigned) __attribute__((regparm(3)));
void wake_up_bit(void *, int) __attribute__((regparm(3)));
int out_of_line_wait_on_bit(void *, int, int (*)(void *), unsigned) __attribute__((regparm(3)));
int out_of_line_wait_on_bit_lock(void *, int, int (*)(void *), unsigned) __attribute__((regparm(3)));
wait_queue_head_t *bit_waitqueue(void *, int) __attribute__((regparm(3)));
# 351 "include/linux/wait.h"
static inline __attribute__((always_inline)) void add_wait_queue_exclusive_locked(wait_queue_head_t *q,
         wait_queue_t * wait)
{
 wait->flags |= 0x01;
 __add_wait_queue_tail(q, wait);
}




static inline __attribute__((always_inline)) void remove_wait_queue_locked(wait_queue_head_t *q,
         wait_queue_t * wait)
{
 __remove_wait_queue(q, wait);
}






extern void sleep_on(wait_queue_head_t *q);
extern long sleep_on_timeout(wait_queue_head_t *q,
          signed long timeout);
extern void interruptible_sleep_on(wait_queue_head_t *q);
extern long interruptible_sleep_on_timeout(wait_queue_head_t *q,
        signed long timeout);




void prepare_to_wait(wait_queue_head_t *q, wait_queue_t *wait, int state) __attribute__((regparm(3)));

void prepare_to_wait_exclusive(wait_queue_head_t *q, wait_queue_t *wait, int state) __attribute__((regparm(3)));

void finish_wait(wait_queue_head_t *q, wait_queue_t *wait) __attribute__((regparm(3)));
int autoremove_wake_function(wait_queue_t *wait, unsigned mode, int sync, void *key);
int wake_bit_function(wait_queue_t *wait, unsigned mode, int sync, void *key);
# 429 "include/linux/wait.h"
static inline __attribute__((always_inline)) int wait_on_bit(void *word, int bit,
    int (*action)(void *), unsigned mode)
{
 if (!(__builtin_constant_p(bit) ? constant_test_bit((bit),(word)) : variable_test_bit((bit),(word))))
  return 0;
 return out_of_line_wait_on_bit(word, bit, action, mode);
}
# 453 "include/linux/wait.h"
static inline __attribute__((always_inline)) int wait_on_bit_lock(void *word, int bit,
    int (*action)(void *), unsigned mode)
{
 if (!test_and_set_bit(bit, word))
  return 0;
 return out_of_line_wait_on_bit_lock(word, bit, action, mode);
}
# 10 "include/linux/mmzone.h" 2


# 1 "include/linux/numa.h" 1
# 13 "include/linux/mmzone.h" 2


# 1 "include/linux/nodemask.h" 1
# 88 "include/linux/nodemask.h"
typedef struct { unsigned long bits[((((1 << 0))+32 -1)/32)]; } nodemask_t;
extern nodemask_t _unused_nodemask_arg_;


static inline __attribute__((always_inline)) void __node_set(int node, volatile nodemask_t *dstp)
{
 set_bit(node, dstp->bits);
}


static inline __attribute__((always_inline)) void __node_clear(int node, volatile nodemask_t *dstp)
{
 clear_bit(node, dstp->bits);
}


static inline __attribute__((always_inline)) void __nodes_setall(nodemask_t *dstp, int nbits)
{
 bitmap_fill(dstp->bits, nbits);
}


static inline __attribute__((always_inline)) void __nodes_clear(nodemask_t *dstp, int nbits)
{
 bitmap_zero(dstp->bits, nbits);
}






static inline __attribute__((always_inline)) int __node_test_and_set(int node, nodemask_t *addr)
{
 return test_and_set_bit(node, addr->bits);
}



static inline __attribute__((always_inline)) void __nodes_and(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_and(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static inline __attribute__((always_inline)) void __nodes_or(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_or(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static inline __attribute__((always_inline)) void __nodes_xor(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_xor(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static inline __attribute__((always_inline)) void __nodes_andnot(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_andnot(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static inline __attribute__((always_inline)) void __nodes_complement(nodemask_t *dstp,
     const nodemask_t *srcp, int nbits)
{
 bitmap_complement(dstp->bits, srcp->bits, nbits);
}



static inline __attribute__((always_inline)) int __nodes_equal(const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 return bitmap_equal(src1p->bits, src2p->bits, nbits);
}



static inline __attribute__((always_inline)) int __nodes_intersects(const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 return bitmap_intersects(src1p->bits, src2p->bits, nbits);
}



static inline __attribute__((always_inline)) int __nodes_subset(const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 return bitmap_subset(src1p->bits, src2p->bits, nbits);
}


static inline __attribute__((always_inline)) int __nodes_empty(const nodemask_t *srcp, int nbits)
{
 return bitmap_empty(srcp->bits, nbits);
}


static inline __attribute__((always_inline)) int __nodes_full(const nodemask_t *srcp, int nbits)
{
 return bitmap_full(srcp->bits, nbits);
}


static inline __attribute__((always_inline)) int __nodes_weight(const nodemask_t *srcp, int nbits)
{
 return bitmap_weight(srcp->bits, nbits);
}



static inline __attribute__((always_inline)) void __nodes_shift_right(nodemask_t *dstp,
     const nodemask_t *srcp, int n, int nbits)
{
 bitmap_shift_right(dstp->bits, srcp->bits, n, nbits);
}



static inline __attribute__((always_inline)) void __nodes_shift_left(nodemask_t *dstp,
     const nodemask_t *srcp, int n, int nbits)
{
 bitmap_shift_left(dstp->bits, srcp->bits, n, nbits);
}





static inline __attribute__((always_inline)) int __first_node(const nodemask_t *srcp)
{
 return ({ int __x = ((1 << 0)); int __y = (find_first_bit(srcp->bits, (1 << 0))); __x < __y ? __x: __y; });
}


static inline __attribute__((always_inline)) int __next_node(int n, const nodemask_t *srcp)
{
 return ({ int __x = ((1 << 0)); int __y = (find_next_bit(srcp->bits, (1 << 0), n+1)); __x < __y ? __x: __y; });
}
# 251 "include/linux/nodemask.h"
static inline __attribute__((always_inline)) int __first_unset_node(const nodemask_t *maskp)
{
 return ({ int __x = ((1 << 0)); int __y = (find_first_zero_bit(maskp->bits, (1 << 0))); __x < __y ? __x: __y; });

}
# 285 "include/linux/nodemask.h"
static inline __attribute__((always_inline)) int __nodemask_scnprintf(char *buf, int len,
     const nodemask_t *srcp, int nbits)
{
 return bitmap_scnprintf(buf, len, srcp->bits, nbits);
}



static inline __attribute__((always_inline)) int __nodemask_parse_user(const char *buf, int len,
     nodemask_t *dstp, int nbits)
{
 return bitmap_parse_user(buf, len, dstp->bits, nbits);
}



static inline __attribute__((always_inline)) int __nodelist_scnprintf(char *buf, int len,
     const nodemask_t *srcp, int nbits)
{
 return bitmap_scnlistprintf(buf, len, srcp->bits, nbits);
}


static inline __attribute__((always_inline)) int __nodelist_parse(const char *buf, nodemask_t *dstp, int nbits)
{
 return bitmap_parselist(buf, dstp->bits, nbits);
}



static inline __attribute__((always_inline)) int __node_remap(int oldbit,
  const nodemask_t *oldp, const nodemask_t *newp, int nbits)
{
 return bitmap_bitremap(oldbit, oldp->bits, newp->bits, nbits);
}



static inline __attribute__((always_inline)) void __nodes_remap(nodemask_t *dstp, const nodemask_t *srcp,
  const nodemask_t *oldp, const nodemask_t *newp, int nbits)
{
 bitmap_remap(dstp->bits, srcp->bits, oldp->bits, newp->bits, nbits);
}
# 345 "include/linux/nodemask.h"
extern nodemask_t node_online_map;
extern nodemask_t node_possible_map;
# 16 "include/linux/mmzone.h" 2
# 27 "include/linux/mmzone.h"
struct free_area {
 struct list_head free_list;
 unsigned long nr_free;
};

struct pglist_data;
# 41 "include/linux/mmzone.h"
struct zone_padding {
 char x[0];
} __attribute__((__aligned__(1 << ((7)))));





enum zone_stat_item {

 NR_FREE_PAGES,
 NR_INACTIVE,
 NR_ACTIVE,
 NR_ANON_PAGES,
 NR_FILE_MAPPED,

 NR_FILE_PAGES,
 NR_FILE_DIRTY,
 NR_WRITEBACK,

 NR_SLAB_RECLAIMABLE,
 NR_SLAB_UNRECLAIMABLE,
 NR_PAGETABLE,
 NR_UNSTABLE_NFS,
 NR_BOUNCE,
 NR_VMSCAN_WRITE,
# 75 "include/linux/mmzone.h"
 NR_VM_ZONE_STAT_ITEMS };

struct per_cpu_pages {
 int count;
 int high;
 int batch;
 struct list_head list;
};

struct per_cpu_pageset {
 struct per_cpu_pages pcp[2];




 s8 stat_threshold;
 s8 vm_stat_diff[NR_VM_ZONE_STAT_ITEMS];

} __attribute__((__aligned__((1 << (7)))));







enum zone_type {
# 122 "include/linux/mmzone.h"
 ZONE_DMA,
# 137 "include/linux/mmzone.h"
 ZONE_NORMAL,
# 147 "include/linux/mmzone.h"
 ZONE_HIGHMEM,

 MAX_NR_ZONES
};
# 182 "include/linux/mmzone.h"
struct zone {

 unsigned long pages_min, pages_low, pages_high;
# 193 "include/linux/mmzone.h"
 unsigned long lowmem_reserve[MAX_NR_ZONES];
# 204 "include/linux/mmzone.h"
 struct per_cpu_pageset pageset[8];




 spinlock_t lock;




 struct free_area free_area[11];


 struct zone_padding _pad1_;


 spinlock_t lru_lock;
 struct list_head active_list;
 struct list_head inactive_list;
 unsigned long nr_scan_active;
 unsigned long nr_scan_inactive;
 unsigned long pages_scanned;
 int all_unreclaimable;


 atomic_t reclaim_in_progress;


 atomic_long_t vm_stat[NR_VM_ZONE_STAT_ITEMS];
# 247 "include/linux/mmzone.h"
 int prev_priority;


 struct zone_padding _pad2_;
# 277 "include/linux/mmzone.h"
 wait_queue_head_t * wait_table;
 unsigned long wait_table_hash_nr_entries;
 unsigned long wait_table_bits;




 struct pglist_data *zone_pgdat;

 unsigned long zone_start_pfn;
# 298 "include/linux/mmzone.h"
 unsigned long spanned_pages;
 unsigned long present_pages;




 const char *name;
} __attribute__((__aligned__(1 << ((7)))));
# 383 "include/linux/mmzone.h"
struct zonelist_cache;
# 396 "include/linux/mmzone.h"
struct zonelist {
 struct zonelist_cache *zlcache_ptr;
 struct zone *zones[((1 << 0) * MAX_NR_ZONES) + 1];



};


struct node_active_region {
 unsigned long start_pfn;
 unsigned long end_pfn;
 int nid;
};




extern struct page *mem_map;
# 428 "include/linux/mmzone.h"
struct bootmem_data;
typedef struct pglist_data {
 struct zone node_zones[MAX_NR_ZONES];
 struct zonelist node_zonelists[MAX_NR_ZONES];
 int nr_zones;

 struct page *node_mem_map;

 struct bootmem_data *bdata;
# 447 "include/linux/mmzone.h"
 unsigned long node_start_pfn;
 unsigned long node_present_pages;
 unsigned long node_spanned_pages;

 int node_id;
 wait_queue_head_t kswapd_wait;
 struct task_struct *kswapd;
 int kswapd_max_order;
} pg_data_t;
# 466 "include/linux/mmzone.h"
# 1 "include/linux/memory_hotplug.h" 1



# 1 "include/linux/mmzone.h" 1
# 5 "include/linux/memory_hotplug.h" 2


# 1 "include/linux/notifier.h" 1
# 13 "include/linux/notifier.h"
# 1 "include/linux/mutex.h" 1
# 47 "include/linux/mutex.h"
struct mutex {

 atomic_t count;
 spinlock_t wait_lock;
 struct list_head wait_list;

 struct thread_info *owner;
 const char *name;
 void *magic;


 struct lockdep_map dep_map;

};





struct mutex_waiter {
 struct list_head list;
 struct task_struct *task;

 struct mutex *lock;
 void *magic;

};


# 1 "include/linux/mutex-debug.h" 1
# 21 "include/linux/mutex-debug.h"
extern void mutex_destroy(struct mutex *lock) __attribute__((regparm(3)));
# 77 "include/linux/mutex.h" 2
# 105 "include/linux/mutex.h"
extern void __mutex_init(struct mutex *lock, const char *name,
    struct lock_class_key *key);







static inline __attribute__((always_inline)) int __attribute__((regparm(3))) mutex_is_locked(struct mutex *lock)
{
 return ((&lock->count)->counter) != 1;
}





extern void __attribute__((regparm(3))) mutex_lock(struct mutex *lock);
extern int __attribute__((warn_unused_result)) __attribute__((regparm(3))) mutex_lock_interruptible(struct mutex *lock);


extern void mutex_lock_nested(struct mutex *lock, unsigned int subclass);
extern int __attribute__((warn_unused_result)) mutex_lock_interruptible_nested(struct mutex *lock,
     unsigned int subclass);
# 139 "include/linux/mutex.h"
extern int __attribute__((regparm(3))) mutex_trylock(struct mutex *lock);
extern void __attribute__((regparm(3))) mutex_unlock(struct mutex *lock);
# 14 "include/linux/notifier.h" 2
# 1 "include/linux/rwsem.h" 1
# 19 "include/linux/rwsem.h"
struct rw_semaphore;




# 1 "include/asm/rwsem.h" 1
# 45 "include/asm/rwsem.h"
struct rwsem_waiter;

extern struct rw_semaphore *rwsem_down_read_failed(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern struct rw_semaphore *rwsem_down_write_failed(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern struct rw_semaphore *rwsem_wake(struct rw_semaphore *) __attribute__((regparm(3)));
extern struct rw_semaphore *rwsem_downgrade_wake(struct rw_semaphore *sem) __attribute__((regparm(3)));




struct rw_semaphore {
 signed long count;






 spinlock_t wait_lock;
 struct list_head wait_list;

 struct lockdep_map dep_map;

};
# 84 "include/asm/rwsem.h"
extern void __init_rwsem(struct rw_semaphore *sem, const char *name,
    struct lock_class_key *key);
# 97 "include/asm/rwsem.h"
static inline __attribute__((always_inline)) void __down_read(struct rw_semaphore *sem)
{
 __asm__ __volatile__(
  "# beginning down_read\n\t"
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "  incl      (%%eax)\n\t"
  "  jns        1f\n"
  "  call call_rwsem_down_read_failed\n"
  "1:\n\t"
  "# ending down_read\n\t"
  : "+m" (sem->count)
  : "a" (sem)
  : "memory", "cc");
}




static inline __attribute__((always_inline)) int __down_read_trylock(struct rw_semaphore *sem)
{
 __s32 result, tmp;
 __asm__ __volatile__(
  "# beginning __down_read_trylock\n\t"
  "  movl      %0,%1\n\t"
  "1:\n\t"
  "  movl	     %1,%2\n\t"
  "  addl      %3,%2\n\t"
  "  jle	     2f\n\t"
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "  cmpxchgl  %2,%0\n\t"
  "  jnz	     1b\n\t"
  "2:\n\t"
  "# ending __down_read_trylock\n\t"
  : "+m" (sem->count), "=&a" (result), "=&r" (tmp)
  : "i" (0x00000001)
  : "memory", "cc");
 return result>=0 ? 1 : 0;
}




static inline __attribute__((always_inline)) void __down_write_nested(struct rw_semaphore *sem, int subclass)
{
 int tmp;

 tmp = ((-0x00010000) + 0x00000001);
 __asm__ __volatile__(
  "# beginning down_write\n\t"
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "  xadd      %%edx,(%%eax)\n\t"
  "  testl     %%edx,%%edx\n\t"
  "  jz        1f\n"
  "  call call_rwsem_down_write_failed\n"
  "1:\n"
  "# ending down_write"
  : "+m" (sem->count), "=d" (tmp)
  : "a" (sem), "1" (tmp)
  : "memory", "cc");
}

static inline __attribute__((always_inline)) void __down_write(struct rw_semaphore *sem)
{
 __down_write_nested(sem, 0);
}




static inline __attribute__((always_inline)) int __down_write_trylock(struct rw_semaphore *sem)
{
 signed long ret = ((__typeof__(*(&sem->count)))__cmpxchg((&sem->count),(unsigned long)(0x00000000), (unsigned long)(((-0x00010000) + 0x00000001)),sizeof(*(&sem->count))));


 if (ret == 0x00000000)
  return 1;
 return 0;
}




static inline __attribute__((always_inline)) void __up_read(struct rw_semaphore *sem)
{
 __s32 tmp = -0x00000001;
 __asm__ __volatile__(
  "# beginning __up_read\n\t"
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "  xadd      %%edx,(%%eax)\n\t"
  "  jns        1f\n\t"
  "  call call_rwsem_wake\n"
  "1:\n"
  "# ending __up_read\n"
  : "+m" (sem->count), "=d" (tmp)
  : "a" (sem), "1" (tmp)
  : "memory", "cc");
}




static inline __attribute__((always_inline)) void __up_write(struct rw_semaphore *sem)
{
 __asm__ __volatile__(
  "# beginning __up_write\n\t"
  "  movl      %2,%%edx\n\t"
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "  xaddl     %%edx,(%%eax)\n\t"
  "  jz       1f\n"
  "  call call_rwsem_wake\n"
  "1:\n\t"
  "# ending __up_write\n"
  : "+m" (sem->count)
  : "a" (sem), "i" (-((-0x00010000) + 0x00000001))
  : "memory", "cc", "edx");
}




static inline __attribute__((always_inline)) void __downgrade_write(struct rw_semaphore *sem)
{
 __asm__ __volatile__(
  "# beginning __downgrade_write\n\t"
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "  addl      %2,(%%eax)\n\t"
  "  jns       1f\n\t"
  "  call call_rwsem_downgrade_wake\n"
  "1:\n\t"
  "# ending __downgrade_write\n"
  : "+m" (sem->count)
  : "a" (sem), "i" (-(-0x00010000))
  : "memory", "cc");
}




static inline __attribute__((always_inline)) void rwsem_atomic_add(int delta, struct rw_semaphore *sem)
{
 __asm__ __volatile__(
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "addl %1,%0"
  : "+m" (sem->count)
  : "ir" (delta));
}




static inline __attribute__((always_inline)) int rwsem_atomic_update(int delta, struct rw_semaphore *sem)
{
 int tmp = delta;

 __asm__ __volatile__(
".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "xadd %0,%1"
  : "+r" (tmp), "+m" (sem->count)
  : : "memory");

 return tmp+delta;
}

static inline __attribute__((always_inline)) int rwsem_is_locked(struct rw_semaphore *sem)
{
 return (sem->count != 0);
}
# 25 "include/linux/rwsem.h" 2





extern void down_read(struct rw_semaphore *sem);




extern int down_read_trylock(struct rw_semaphore *sem);




extern void down_write(struct rw_semaphore *sem);




extern int down_write_trylock(struct rw_semaphore *sem);




extern void up_read(struct rw_semaphore *sem);




extern void up_write(struct rw_semaphore *sem);




extern void downgrade_write(struct rw_semaphore *sem);
# 76 "include/linux/rwsem.h"
extern void down_read_nested(struct rw_semaphore *sem, int subclass);
extern void down_write_nested(struct rw_semaphore *sem, int subclass);






extern void down_read_non_owner(struct rw_semaphore *sem);
extern void up_read_non_owner(struct rw_semaphore *sem);
# 15 "include/linux/notifier.h" 2
# 1 "include/linux/srcu.h" 1
# 30 "include/linux/srcu.h"
struct srcu_struct_array {
 int c[2];
};

struct srcu_struct {
 int completed;
 struct srcu_struct_array *per_cpu_ref;
 struct mutex mutex;
};







int init_srcu_struct(struct srcu_struct *sp);
void cleanup_srcu_struct(struct srcu_struct *sp);
int srcu_read_lock(struct srcu_struct *sp) ;
void srcu_read_unlock(struct srcu_struct *sp, int idx) ;
void synchronize_srcu(struct srcu_struct *sp);
long srcu_batches_completed(struct srcu_struct *sp);
# 16 "include/linux/notifier.h" 2
# 50 "include/linux/notifier.h"
struct notifier_block {
 int (*notifier_call)(struct notifier_block *, unsigned long, void *);
 struct notifier_block *next;
 int priority;
};

struct atomic_notifier_head {
 spinlock_t lock;
 struct notifier_block *head;
};

struct blocking_notifier_head {
 struct rw_semaphore rwsem;
 struct notifier_block *head;
};

struct raw_notifier_head {
 struct notifier_block *head;
};

struct srcu_notifier_head {
 struct mutex mutex;
 struct srcu_struct srcu;
 struct notifier_block *head;
};
# 89 "include/linux/notifier.h"
extern void srcu_init_notifier_head(struct srcu_notifier_head *nh);
# 115 "include/linux/notifier.h"
extern int atomic_notifier_chain_register(struct atomic_notifier_head *nh,
  struct notifier_block *nb);
extern int blocking_notifier_chain_register(struct blocking_notifier_head *nh,
  struct notifier_block *nb);
extern int raw_notifier_chain_register(struct raw_notifier_head *nh,
  struct notifier_block *nb);
extern int srcu_notifier_chain_register(struct srcu_notifier_head *nh,
  struct notifier_block *nb);

extern int atomic_notifier_chain_unregister(struct atomic_notifier_head *nh,
  struct notifier_block *nb);
extern int blocking_notifier_chain_unregister(struct blocking_notifier_head *nh,
  struct notifier_block *nb);
extern int raw_notifier_chain_unregister(struct raw_notifier_head *nh,
  struct notifier_block *nb);
extern int srcu_notifier_chain_unregister(struct srcu_notifier_head *nh,
  struct notifier_block *nb);

extern int atomic_notifier_call_chain(struct atomic_notifier_head *nh,
  unsigned long val, void *v);
extern int __atomic_notifier_call_chain(struct atomic_notifier_head *nh,
 unsigned long val, void *v, int nr_to_call, int *nr_calls);
extern int blocking_notifier_call_chain(struct blocking_notifier_head *nh,
  unsigned long val, void *v);
extern int __blocking_notifier_call_chain(struct blocking_notifier_head *nh,
 unsigned long val, void *v, int nr_to_call, int *nr_calls);
extern int raw_notifier_call_chain(struct raw_notifier_head *nh,
  unsigned long val, void *v);
extern int __raw_notifier_call_chain(struct raw_notifier_head *nh,
 unsigned long val, void *v, int nr_to_call, int *nr_calls);
extern int srcu_notifier_call_chain(struct srcu_notifier_head *nh,
  unsigned long val, void *v);
extern int __srcu_notifier_call_chain(struct srcu_notifier_head *nh,
 unsigned long val, void *v, int nr_to_call, int *nr_calls);
# 8 "include/linux/memory_hotplug.h" 2

struct page;
struct zone;
struct pglist_data;
# 140 "include/linux/memory_hotplug.h"
static inline __attribute__((always_inline)) void pgdat_resize_lock(struct pglist_data *p, unsigned long *f) {}
static inline __attribute__((always_inline)) void pgdat_resize_unlock(struct pglist_data *p, unsigned long *f) {}
static inline __attribute__((always_inline)) void pgdat_resize_init(struct pglist_data *pgdat) {}

static inline __attribute__((always_inline)) unsigned zone_span_seqbegin(struct zone *zone)
{
 return 0;
}
static inline __attribute__((always_inline)) int zone_span_seqretry(struct zone *zone, unsigned iv)
{
 return 0;
}
static inline __attribute__((always_inline)) void zone_span_writelock(struct zone *zone) {}
static inline __attribute__((always_inline)) void zone_span_writeunlock(struct zone *zone) {}
static inline __attribute__((always_inline)) void zone_seqlock_init(struct zone *zone) {}

static inline __attribute__((always_inline)) int mhp_notimplemented(const char *func)
{
 printk("<4>" "%s() called, with CONFIG_MEMORY_HOTPLUG disabled\n", func);
 dump_stack();
 return -38;
}


static inline __attribute__((always_inline)) int __remove_pages(struct zone *zone, unsigned long start_pfn,
 unsigned long nr_pages)
{
 printk("<4>" "%s() called, not yet supported\n", (__func__));
 dump_stack();
 return -38;
}

extern int add_memory(int nid, u64 start, u64 size);
extern int arch_add_memory(int nid, u64 start, u64 size);
extern int remove_memory(u64 start, u64 size);
extern int sparse_add_one_section(struct zone *zone, unsigned long start_pfn,
        int nr_pages);
# 467 "include/linux/mmzone.h" 2

void get_zone_counts(unsigned long *active, unsigned long *inactive,
   unsigned long *free);
void build_all_zonelists(void);
void wakeup_kswapd(struct zone *zone, int order);
int zone_watermark_ok(struct zone *z, int order, unsigned long mark,
  int classzone_idx, int alloc_flags);
enum memmap_context {
 MEMMAP_EARLY,
 MEMMAP_HOTPLUG,
};
extern int init_currently_empty_zone(struct zone *zone, unsigned long start_pfn,
         unsigned long size,
         enum memmap_context context);




static inline __attribute__((always_inline)) void memory_present(int nid, unsigned long start, unsigned long end) {}
# 497 "include/linux/mmzone.h"
static inline __attribute__((always_inline)) int populated_zone(struct zone *zone)
{
 return (!!zone->present_pages);
}

static inline __attribute__((always_inline)) int is_highmem_idx(enum zone_type idx)
{

 return (idx == ZONE_HIGHMEM);



}

static inline __attribute__((always_inline)) int is_normal_idx(enum zone_type idx)
{
 return (idx == ZONE_NORMAL);
}







static inline __attribute__((always_inline)) int is_highmem(struct zone *zone)
{

 return zone == zone->zone_pgdat->node_zones + ZONE_HIGHMEM;



}

static inline __attribute__((always_inline)) int is_normal(struct zone *zone)
{
 return zone == zone->zone_pgdat->node_zones + ZONE_NORMAL;
}

static inline __attribute__((always_inline)) int is_dma32(struct zone *zone)
{



 return 0;

}

static inline __attribute__((always_inline)) int is_dma(struct zone *zone)
{

 return zone == zone->zone_pgdat->node_zones + ZONE_DMA;



}


struct ctl_table;
struct file;
int min_free_kbytes_sysctl_handler(struct ctl_table *, int, struct file *,
     void *, size_t *, loff_t *);
extern int sysctl_lowmem_reserve_ratio[MAX_NR_ZONES-1];
int lowmem_reserve_ratio_sysctl_handler(struct ctl_table *, int, struct file *,
     void *, size_t *, loff_t *);
int percpu_pagelist_fraction_sysctl_handler(struct ctl_table *, int, struct file *,
     void *, size_t *, loff_t *);
int sysctl_min_unmapped_ratio_sysctl_handler(struct ctl_table *, int,
   struct file *, void *, size_t *, loff_t *);
int sysctl_min_slab_ratio_sysctl_handler(struct ctl_table *, int,
   struct file *, void *, size_t *, loff_t *);

# 1 "include/linux/topology.h" 1
# 34 "include/linux/topology.h"
# 1 "include/asm/topology.h" 1
# 110 "include/asm/topology.h"
# 1 "include/asm-generic/topology.h" 1
# 111 "include/asm/topology.h" 2



extern cpumask_t cpu_coregroup_map(int cpu);
# 35 "include/linux/topology.h" 2
# 570 "include/linux/mmzone.h" 2







extern struct pglist_data contig_page_data;
# 588 "include/linux/mmzone.h"
extern struct pglist_data *first_online_pgdat(void);
extern struct pglist_data *next_online_pgdat(struct pglist_data *pgdat);
extern struct zone *next_zone(struct zone *zone);
# 787 "include/linux/mmzone.h"
void memory_present(int nid, unsigned long start, unsigned long end);
unsigned long __attribute__ ((__section__ (".init.text"))) node_memmap_size_bytes(int, unsigned long, unsigned long);
# 5 "include/linux/gfp.h" 2



struct vm_area_struct;
# 85 "include/linux/gfp.h"
static inline __attribute__((always_inline)) enum zone_type gfp_zone(gfp_t flags)
{

 if (flags & (( gfp_t)0x01u))
  return ZONE_DMA;






 if (flags & (( gfp_t)0x02u))
  return ZONE_HIGHMEM;

 return ZONE_NORMAL;
}
# 118 "include/linux/gfp.h"
static inline __attribute__((always_inline)) void arch_free_page(struct page *page, int order) { }


static inline __attribute__((always_inline)) void arch_alloc_page(struct page *page, int order) { }


extern struct page *
__alloc_pages(gfp_t, unsigned int, struct zonelist *) __attribute__((regparm(3)));

static inline __attribute__((always_inline)) struct page *alloc_pages_node(int nid, gfp_t gfp_mask,
      unsigned int order)
{
 if (__builtin_expect(!!(order >= 11), 0))
  return ((void *)0);


 if (nid < 0)
  nid = ((0));

 return __alloc_pages(gfp_mask, order,
  (&contig_page_data)->node_zonelists + gfp_zone(gfp_mask));
}
# 161 "include/linux/gfp.h"
extern unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order) __attribute__((regparm(3)));
extern unsigned long get_zeroed_page(gfp_t gfp_mask) __attribute__((regparm(3)));







extern void __free_pages(struct page *page, unsigned int order) __attribute__((regparm(3)));
extern void free_pages(unsigned long addr, unsigned int order) __attribute__((regparm(3)));
extern void free_hot_page(struct page *page) __attribute__((regparm(3)));
extern void free_cold_page(struct page *page) __attribute__((regparm(3)));




void page_alloc_init(void);
void drain_zone_pages(struct zone *zone, struct per_cpu_pages *pcp);
# 15 "include/linux/slab.h" 2


typedef struct kmem_cache kmem_cache_t __attribute__((deprecated));
# 38 "include/linux/slab.h"
void __attribute__ ((__section__ (".init.text"))) kmem_cache_init(void);
int slab_is_available(void);

struct kmem_cache *kmem_cache_create(const char *, size_t, size_t,
   unsigned long,
   void (*)(void *, struct kmem_cache *, unsigned long),
   void (*)(void *, struct kmem_cache *, unsigned long));
void kmem_cache_destroy(struct kmem_cache *);
int kmem_cache_shrink(struct kmem_cache *);
void *kmem_cache_alloc(struct kmem_cache *, gfp_t);
void *kmem_cache_zalloc(struct kmem_cache *, gfp_t);
void kmem_cache_free(struct kmem_cache *, void *);
unsigned int kmem_cache_size(struct kmem_cache *);
const char *kmem_cache_name(struct kmem_cache *);
int kmem_ptr_validate(struct kmem_cache *cachep, const void *ptr);
# 69 "include/linux/slab.h"
static inline __attribute__((always_inline)) void *kmem_cache_alloc_node(struct kmem_cache *cachep,
     gfp_t flags, int node)
{
 return kmem_cache_alloc(cachep, flags);
}
# 94 "include/linux/slab.h"
void *__kmalloc(size_t, gfp_t);
void *__kzalloc(size_t, gfp_t);
void * __attribute__((warn_unused_result)) krealloc(const void *, size_t, gfp_t);
void kfree(const void *);
size_t ksize(const void *);







static inline __attribute__((always_inline)) void *kcalloc(size_t n, size_t size, gfp_t flags)
{
 if (n != 0 && size > (~0UL) / n)
  return ((void *)0);
 return __kzalloc(n * size, flags);
}
# 123 "include/linux/slab.h"
# 1 "include/linux/slab_def.h" 1
# 19 "include/linux/slab_def.h"
struct cache_sizes {
 size_t cs_size;
 struct kmem_cache *cs_cachep;

 struct kmem_cache *cs_dmacachep;

};
extern struct cache_sizes malloc_sizes[];

static inline __attribute__((always_inline)) void *kmalloc(size_t size, gfp_t flags)
{
 if (__builtin_constant_p(size)) {
  int i = 0;





# 1 "include/linux/kmalloc_sizes.h" 1

 if (size <= 32) goto found; else i++;

 if (size <= 64) goto found; else i++;



 if (size <= 128) goto found; else i++;



 if (size <= 256) goto found; else i++;
 if (size <= 512) goto found; else i++;
 if (size <= 1024) goto found; else i++;
 if (size <= 2048) goto found; else i++;
 if (size <= 4096) goto found; else i++;
 if (size <= 8192) goto found; else i++;
 if (size <= 16384) goto found; else i++;
 if (size <= 32768) goto found; else i++;
 if (size <= 65536) goto found; else i++;
 if (size <= 131072) goto found; else i++;

 if (size <= 262144) goto found; else i++;


 if (size <= 524288) goto found; else i++;


 if (size <= 1048576) goto found; else i++;


 if (size <= 2097152) goto found; else i++;


 if (size <= 4194304) goto found; else i++;
# 38 "include/linux/slab_def.h" 2

  {
   extern void __you_cannot_kmalloc_that_much(void);
   __you_cannot_kmalloc_that_much();
  }
found:

  if (flags & (( gfp_t)0x01u))
   return kmem_cache_alloc(malloc_sizes[i].cs_dmacachep,
      flags);

  return kmem_cache_alloc(malloc_sizes[i].cs_cachep, flags);
 }
 return __kmalloc(size, flags);
}

static inline __attribute__((always_inline)) void *kzalloc(size_t size, gfp_t flags)
{
 if (__builtin_constant_p(size)) {
  int i = 0;





# 1 "include/linux/kmalloc_sizes.h" 1

 if (size <= 32) goto found; else i++;

 if (size <= 64) goto found; else i++;



 if (size <= 128) goto found; else i++;



 if (size <= 256) goto found; else i++;
 if (size <= 512) goto found; else i++;
 if (size <= 1024) goto found; else i++;
 if (size <= 2048) goto found; else i++;
 if (size <= 4096) goto found; else i++;
 if (size <= 8192) goto found; else i++;
 if (size <= 16384) goto found; else i++;
 if (size <= 32768) goto found; else i++;
 if (size <= 65536) goto found; else i++;
 if (size <= 131072) goto found; else i++;

 if (size <= 262144) goto found; else i++;


 if (size <= 524288) goto found; else i++;


 if (size <= 1048576) goto found; else i++;


 if (size <= 2097152) goto found; else i++;


 if (size <= 4194304) goto found; else i++;
# 64 "include/linux/slab_def.h" 2

  {
   extern void __you_cannot_kzalloc_that_much(void);
   __you_cannot_kzalloc_that_much();
  }
found:

  if (flags & (( gfp_t)0x01u))
   return kmem_cache_zalloc(malloc_sizes[i].cs_dmacachep,
      flags);

  return kmem_cache_zalloc(malloc_sizes[i].cs_cachep, flags);
 }
 return __kzalloc(size, flags);
}
# 112 "include/linux/slab_def.h"
extern const struct seq_operations slabinfo_op;
ssize_t slabinfo_write(struct file *, const char *, size_t, loff_t *);
# 124 "include/linux/slab.h" 2
# 194 "include/linux/slab.h"
static inline __attribute__((always_inline)) void *kmalloc_node(size_t size, gfp_t flags, int node)
{
 return kmalloc(size, flags);
}

static inline __attribute__((always_inline)) void *__kmalloc_node(size_t size, gfp_t flags, int node)
{
 return __kmalloc(size, flags);
}
# 214 "include/linux/slab.h"
extern void *__kmalloc_track_caller(size_t, gfp_t, void*);
# 6 "include/linux/percpu.h" 2
# 36 "include/linux/percpu.h"
struct percpu_data {
 void *ptrs[8];
};
# 52 "include/linux/percpu.h"
extern void *percpu_populate(void *__pdata, size_t size, gfp_t gfp, int cpu);
extern void percpu_depopulate(void *__pdata, int cpu);
extern int __percpu_populate_mask(void *__pdata, size_t size, gfp_t gfp,
      cpumask_t *mask);
extern void __percpu_depopulate_mask(void *__pdata, cpumask_t *mask);
extern void *__percpu_alloc_mask(size_t size, gfp_t gfp, cpumask_t *mask);
extern void percpu_free(void *__pdata);
# 12 "include/asm/desc.h" 2

# 1 "include/asm/mmu.h" 1



# 1 "include/asm/semaphore.h" 1
# 44 "include/asm/semaphore.h"
struct semaphore {
 atomic_t count;
 int sleepers;
 wait_queue_head_t wait;
};
# 64 "include/asm/semaphore.h"
static inline __attribute__((always_inline)) void sema_init (struct semaphore *sem, int val)
{






 (((&sem->count)->counter) = (val));
 sem->sleepers = 0;
 init_waitqueue_head(&sem->wait);
}

static inline __attribute__((always_inline)) void init_MUTEX (struct semaphore *sem)
{
 sema_init(sem, 1);
}

static inline __attribute__((always_inline)) void init_MUTEX_LOCKED (struct semaphore *sem)
{
 sema_init(sem, 0);
}

__attribute__((regparm(3))) void __down_failed(void );
__attribute__((regparm(3))) int __down_failed_interruptible(void );
__attribute__((regparm(3))) int __down_failed_trylock(void );
__attribute__((regparm(3))) void __up_wakeup(void );






static inline __attribute__((always_inline)) void down(struct semaphore * sem)
{
 do { __might_sleep("include/asm/semaphore.h", 99); do { } while (0); } while (0);
 __asm__ __volatile__(
  "# atomic down operation\n\t"
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "decl %0\n\t"
  "jns 2f\n"
  "\tlea %0,%%eax\n\t"
  "call __down_failed\n"
  "2:"
  :"+m" (sem->count)
  :
  :"memory","ax");
}





static inline __attribute__((always_inline)) int down_interruptible(struct semaphore * sem)
{
 int result;

 do { __might_sleep("include/asm/semaphore.h", 120); do { } while (0); } while (0);
 __asm__ __volatile__(
  "# atomic interruptible down operation\n\t"
  "xorl %0,%0\n\t"
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "decl %1\n\t"
  "jns 2f\n\t"
  "lea %1,%%eax\n\t"
  "call __down_failed_interruptible\n"
  "2:"
  :"=&a" (result), "+m" (sem->count)
  :
  :"memory");
 return result;
}





static inline __attribute__((always_inline)) int down_trylock(struct semaphore * sem)
{
 int result;

 __asm__ __volatile__(
  "# atomic interruptible down operation\n\t"
  "xorl %0,%0\n\t"
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "decl %1\n\t"
  "jns 2f\n\t"
  "lea %1,%%eax\n\t"
  "call __down_failed_trylock\n\t"
  "2:\n"
  :"=&a" (result), "+m" (sem->count)
  :
  :"memory");
 return result;
}





static inline __attribute__((always_inline)) void up(struct semaphore * sem)
{
 __asm__ __volatile__(
  "# atomic up operation\n\t"
  ".section .smp_locks,\"a\"\n" "  .align 4\n" "  .long 661f\n" ".previous\n" "661:\n\tlock; " "incl %0\n\t"
  "jg 1f\n\t"
  "lea %0,%%eax\n\t"
  "call __up_wakeup\n"
  "1:"
  :"+m" (sem->count)
  :
  :"memory","ax");
}
# 5 "include/asm/mmu.h" 2






typedef struct {
 int size;
 struct semaphore sem;
 void *ldt;
 void *vdso;
} mm_context_t;
# 14 "include/asm/desc.h" 2

struct Xgt_desc_struct {
 unsigned short size;
 unsigned long address __attribute__((packed));
 unsigned short pad;
} __attribute__ ((packed));

struct gdt_page
{
 struct desc_struct gdt[32];
} __attribute__((aligned((1UL << 12))));
extern __typeof__(struct gdt_page) per_cpu__gdt_page;

static inline __attribute__((always_inline)) struct desc_struct *get_cpu_gdt_table(unsigned int cpu)
{
 return (*({ extern int simple_indentifier_gdt_page(void); ({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__gdt_page)); (typeof(&per_cpu__gdt_page)) (__ptr + (__per_cpu_offset[cpu])); }); })).gdt;
}

extern struct Xgt_desc_struct idt_descr;
extern struct desc_struct idt_table[];
extern void set_intr_gate(unsigned int irq, void * addr);

static inline __attribute__((always_inline)) void pack_descriptor(__u32 *a, __u32 *b,
 unsigned long base, unsigned long limit, unsigned char type, unsigned char flags)
{
 *a = ((base & 0xffff) << 16) | (limit & 0xffff);
 *b = (base & 0xff000000) | ((base & 0xff0000) >> 16) |
  (limit & 0x000f0000) | ((type & 0xff) << 8) | ((flags & 0xf) << 20);
}

static inline __attribute__((always_inline)) void pack_gate(__u32 *a, __u32 *b,
 unsigned long base, unsigned short seg, unsigned char type, unsigned char flags)
{
 *a = (seg << 16) | (base & 0xffff);
 *b = (base & 0xffff0000) | ((type & 0xff) << 8) | (flags & 0xff);
}
# 81 "include/asm/desc.h"
static inline __attribute__((always_inline)) void write_dt_entry(struct desc_struct *dt,
      int entry, u32 entry_low, u32 entry_high)
{
 dt[entry].a = entry_low;
 dt[entry].b = entry_high;
}

static inline __attribute__((always_inline)) void native_set_ldt(const void *addr, unsigned int entries)
{
 if (__builtin_expect(!!(entries == 0), 1))
  __asm__ __volatile__("lldt %w0"::"q" (0));
 else {
  unsigned cpu = (({ typeof(per_cpu__cpu_number) ret__; switch (sizeof(per_cpu__cpu_number)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; default: __bad_percpu_size(); } ret__; }));
  __u32 a, b;

  pack_descriptor(&a, &b, (unsigned long)addr,
    entries * sizeof(struct desc_struct) - 1,
    0x82, 0);
  write_gdt_entry(get_cpu_gdt_table(cpu), (12 + 5), a, b);
  __asm__ __volatile__("lldt %w0"::"q" ((12 + 5)*8));
 }
}


static inline __attribute__((always_inline)) void native_load_tr_desc(void)
{
 asm volatile("ltr %w0"::"q" ((12 + 4)*8));
}

static inline __attribute__((always_inline)) void native_load_gdt(const struct Xgt_desc_struct *dtr)
{
 asm volatile("lgdt %0"::"m" (*dtr));
}

static inline __attribute__((always_inline)) void native_load_idt(const struct Xgt_desc_struct *dtr)
{
 asm volatile("lidt %0"::"m" (*dtr));
}

static inline __attribute__((always_inline)) void native_store_gdt(struct Xgt_desc_struct *dtr)
{
 asm ("sgdt %0":"=m" (*dtr));
}

static inline __attribute__((always_inline)) void native_store_idt(struct Xgt_desc_struct *dtr)
{
 asm ("sidt %0":"=m" (*dtr));
}

static inline __attribute__((always_inline)) unsigned long native_store_tr(void)
{
 unsigned long tr;
 asm ("str %0":"=r" (tr));
 return tr;
}

static inline __attribute__((always_inline)) void native_load_tls(struct thread_struct *t, unsigned int cpu)
{
 unsigned int i;
 struct desc_struct *gdt = get_cpu_gdt_table(cpu);

 for (i = 0; i < 3; i++)
  gdt[6 + i] = t->tls_array[i];
}

static inline __attribute__((always_inline)) void _set_gate(int gate, unsigned int type, void *addr, unsigned short seg)
{
 __u32 a, b;
 pack_gate(&a, &b, (unsigned long)addr, seg, type, 0);
 write_idt_entry(idt_table, gate, a, b);
}

static inline __attribute__((always_inline)) void __set_tss_desc(unsigned int cpu, unsigned int entry, const void *addr)
{
 __u32 a, b;
 pack_descriptor(&a, &b, (unsigned long)addr,
   __builtin_offsetof(struct tss_struct,__cacheline_filler) - 1,
   0x89, 0);
 write_gdt_entry(get_cpu_gdt_table(cpu), entry, a, b);
}
# 190 "include/asm/desc.h"
static inline __attribute__((always_inline)) void clear_LDT(void)
{
 set_ldt(((void *)0), 0);
}




static inline __attribute__((always_inline)) void load_LDT_nolock(mm_context_t *pc)
{
 set_ldt(pc->ldt, pc->size);
}

static inline __attribute__((always_inline)) void load_LDT(mm_context_t *pc)
{
 do { } while (0);
 load_LDT_nolock(pc);
 do { } while (0);
}

static inline __attribute__((always_inline)) unsigned long get_desc_base(unsigned long *desc)
{
 unsigned long base;
 base = ((desc[0] >> 16) & 0x0000ffff) |
  ((desc[1] << 16) & 0x00ff0000) |
  (desc[1] & 0xff000000);
 return base;
}
# 51 "include/asm/elf.h" 2
# 123 "include/asm/elf.h"
struct task_struct;

extern int dump_task_regs (struct task_struct *, elf_gregset_t *);
extern int dump_task_fpu (struct task_struct *, elf_fpregset_t *);
extern int dump_task_extended_fpu (struct task_struct *, struct user_fxsr_struct *);
# 143 "include/asm/elf.h"
extern void __kernel_vsyscall;



struct linux_binprm;


extern int arch_setup_additional_pages(struct linux_binprm *bprm,
                                       int executable_stack);

extern unsigned int vdso_enabled;
# 8 "include/linux/elf.h" 2

struct file;
# 19 "include/linux/elf.h"
typedef __u32 Elf32_Addr;
typedef __u16 Elf32_Half;
typedef __u32 Elf32_Off;
typedef __s32 Elf32_Sword;
typedef __u32 Elf32_Word;


typedef __u64 Elf64_Addr;
typedef __u16 Elf64_Half;
typedef __s16 Elf64_SHalf;
typedef __u64 Elf64_Off;
typedef __s32 Elf64_Sword;
typedef __u32 Elf64_Word;
typedef __u64 Elf64_Xword;
typedef __s64 Elf64_Sxword;
# 126 "include/linux/elf.h"
typedef struct dynamic{
  Elf32_Sword d_tag;
  union{
    Elf32_Sword d_val;
    Elf32_Addr d_ptr;
  } d_un;
} Elf32_Dyn;

typedef struct {
  Elf64_Sxword d_tag;
  union {
    Elf64_Xword d_val;
    Elf64_Addr d_ptr;
  } d_un;
} Elf64_Dyn;
# 149 "include/linux/elf.h"
typedef struct elf32_rel {
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;

typedef struct elf64_rel {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
} Elf64_Rel;

typedef struct elf32_rela{
  Elf32_Addr r_offset;
  Elf32_Word r_info;
  Elf32_Sword r_addend;
} Elf32_Rela;

typedef struct elf64_rela {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
  Elf64_Sxword r_addend;
} Elf64_Rela;

typedef struct elf32_sym{
  Elf32_Word st_name;
  Elf32_Addr st_value;
  Elf32_Word st_size;
  unsigned char st_info;
  unsigned char st_other;
  Elf32_Half st_shndx;
} Elf32_Sym;

typedef struct elf64_sym {
  Elf64_Word st_name;
  unsigned char st_info;
  unsigned char st_other;
  Elf64_Half st_shndx;
  Elf64_Addr st_value;
  Elf64_Xword st_size;
} Elf64_Sym;




typedef struct elf32_hdr{
  unsigned char e_ident[16];
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
} Elf32_Ehdr;

typedef struct elf64_hdr {
  unsigned char e_ident[16];
  Elf64_Half e_type;
  Elf64_Half e_machine;
  Elf64_Word e_version;
  Elf64_Addr e_entry;
  Elf64_Off e_phoff;
  Elf64_Off e_shoff;
  Elf64_Word e_flags;
  Elf64_Half e_ehsize;
  Elf64_Half e_phentsize;
  Elf64_Half e_phnum;
  Elf64_Half e_shentsize;
  Elf64_Half e_shnum;
  Elf64_Half e_shstrndx;
} Elf64_Ehdr;







typedef struct elf32_phdr{
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
} Elf32_Phdr;

typedef struct elf64_phdr {
  Elf64_Word p_type;
  Elf64_Word p_flags;
  Elf64_Off p_offset;
  Elf64_Addr p_vaddr;
  Elf64_Addr p_paddr;
  Elf64_Xword p_filesz;
  Elf64_Xword p_memsz;
  Elf64_Xword p_align;
} Elf64_Phdr;
# 288 "include/linux/elf.h"
typedef struct {
  Elf32_Word sh_name;
  Elf32_Word sh_type;
  Elf32_Word sh_flags;
  Elf32_Addr sh_addr;
  Elf32_Off sh_offset;
  Elf32_Word sh_size;
  Elf32_Word sh_link;
  Elf32_Word sh_info;
  Elf32_Word sh_addralign;
  Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct elf64_shdr {
  Elf64_Word sh_name;
  Elf64_Word sh_type;
  Elf64_Xword sh_flags;
  Elf64_Addr sh_addr;
  Elf64_Off sh_offset;
  Elf64_Xword sh_size;
  Elf64_Word sh_link;
  Elf64_Word sh_info;
  Elf64_Xword sh_addralign;
  Elf64_Xword sh_entsize;
} Elf64_Shdr;
# 361 "include/linux/elf.h"
typedef struct elf32_note {
  Elf32_Word n_namesz;
  Elf32_Word n_descsz;
  Elf32_Word n_type;
} Elf32_Nhdr;


typedef struct elf64_note {
  Elf64_Word n_namesz;
  Elf64_Word n_descsz;
  Elf64_Word n_type;
} Elf64_Nhdr;



extern Elf32_Dyn _DYNAMIC [];
# 393 "include/linux/elf.h"
static inline __attribute__((always_inline)) int arch_notes_size(void) { return 0; }
static inline __attribute__((always_inline)) void arch_write_notes(struct file *file) { }
# 16 "include/linux/module.h" 2

# 1 "include/linux/kobject.h" 1
# 22 "include/linux/kobject.h"
# 1 "include/linux/sysfs.h" 1
# 18 "include/linux/sysfs.h"
struct kobject;
struct module;
struct nameidata;
struct dentry;
struct sysfs_dirent;





struct attribute {
 const char * name;
 struct module * owner;
 mode_t mode;
};

struct attribute_group {
 const char * name;
 struct attribute ** attrs;
};
# 61 "include/linux/sysfs.h"
struct vm_area_struct;

struct bin_attribute {
 struct attribute attr;
 size_t size;
 void *private;
 ssize_t (*read)(struct kobject *, struct bin_attribute *,
   char *, loff_t, size_t);
 ssize_t (*write)(struct kobject *, struct bin_attribute *,
    char *, loff_t, size_t);
 int (*mmap)(struct kobject *, struct bin_attribute *attr,
      struct vm_area_struct *vma);
};

struct sysfs_ops {
 ssize_t (*show)(struct kobject *, struct attribute *,char *);
 ssize_t (*store)(struct kobject *,struct attribute *,const char *, size_t);
};
# 93 "include/linux/sysfs.h"
extern int sysfs_schedule_callback(struct kobject *kobj,
  void (*func)(void *), void *data, struct module *owner);

extern int __attribute__((warn_unused_result))
sysfs_create_dir(struct kobject *kobj, struct sysfs_dirent *shadow_parent_sd);

extern void
sysfs_remove_dir(struct kobject *);

extern int __attribute__((warn_unused_result))
sysfs_rename_dir(struct kobject *kobj, struct sysfs_dirent *new_parent_sd,
   const char *new_name);

extern int __attribute__((warn_unused_result))
sysfs_move_dir(struct kobject *, struct kobject *);

extern int __attribute__((warn_unused_result))
sysfs_create_file(struct kobject *, const struct attribute *);

extern int __attribute__((warn_unused_result))
sysfs_update_file(struct kobject *, const struct attribute *);

extern int __attribute__((warn_unused_result))
sysfs_chmod_file(struct kobject *kobj, struct attribute *attr, mode_t mode);

extern void
sysfs_remove_file(struct kobject *, const struct attribute *);

extern int __attribute__((warn_unused_result))
sysfs_create_link(struct kobject * kobj, struct kobject * target, const char * name);

extern void
sysfs_remove_link(struct kobject *, const char * name);

int __attribute__((warn_unused_result)) sysfs_create_bin_file(struct kobject *kobj,
     struct bin_attribute *attr);
void sysfs_remove_bin_file(struct kobject *kobj, struct bin_attribute *attr);

int __attribute__((warn_unused_result)) sysfs_create_group(struct kobject *,
     const struct attribute_group *);
void sysfs_remove_group(struct kobject *, const struct attribute_group *);
int sysfs_add_file_to_group(struct kobject *kobj,
  const struct attribute *attr, const char *group);
void sysfs_remove_file_from_group(struct kobject *kobj,
  const struct attribute *attr, const char *group);

void sysfs_notify(struct kobject * k, char *dir, char *attr);


extern int sysfs_make_shadowed_dir(struct kobject *kobj,
 void * (*follow_link)(struct dentry *, struct nameidata *));
extern struct sysfs_dirent *sysfs_create_shadow_dir(struct kobject *kobj);
extern void sysfs_remove_shadow_dir(struct sysfs_dirent *shadow_sd);

extern int __attribute__((warn_unused_result)) sysfs_init(void);
# 23 "include/linux/kobject.h" 2


# 1 "include/linux/kref.h" 1
# 23 "include/linux/kref.h"
struct kref {
 atomic_t refcount;
};

void kref_init(struct kref *kref);
void kref_get(struct kref *kref);
int kref_put(struct kref *kref, void (*release) (struct kref *kref));
# 26 "include/linux/kobject.h" 2
# 34 "include/linux/kobject.h"
extern char uevent_helper[];


extern u64 uevent_seqnum;


typedef int kobject_action_t;
enum kobject_action {
 KOBJ_ADD = ( kobject_action_t) 0x01,
 KOBJ_REMOVE = ( kobject_action_t) 0x02,
 KOBJ_CHANGE = ( kobject_action_t) 0x03,
 KOBJ_OFFLINE = ( kobject_action_t) 0x04,
 KOBJ_ONLINE = ( kobject_action_t) 0x05,
 KOBJ_MOVE = ( kobject_action_t) 0x06,
};

struct kobject {
 const char * k_name;
 char name[20];
 struct kref kref;
 struct list_head entry;
 struct kobject * parent;
 struct kset * kset;
 struct kobj_type * ktype;
 struct sysfs_dirent * sd;
 wait_queue_head_t poll;
};

extern int kobject_set_name(struct kobject *, const char *, ...)
 __attribute__((format(printf,2,3)));

static inline __attribute__((always_inline)) const char * kobject_name(const struct kobject * kobj)
{
 return kobj->k_name;
}

extern void kobject_init(struct kobject *);
extern void kobject_cleanup(struct kobject *);

extern int __attribute__((warn_unused_result)) kobject_add(struct kobject *);
extern int __attribute__((warn_unused_result)) kobject_shadow_add(struct kobject *kobj,
        struct sysfs_dirent *shadow_parent);
extern void kobject_del(struct kobject *);

extern int __attribute__((warn_unused_result)) kobject_rename(struct kobject *, const char *new_name);
extern int __attribute__((warn_unused_result)) kobject_shadow_rename(struct kobject *kobj,
           struct sysfs_dirent *new_parent,
           const char *new_name);
extern int __attribute__((warn_unused_result)) kobject_move(struct kobject *, struct kobject *);

extern int __attribute__((warn_unused_result)) kobject_register(struct kobject *);
extern void kobject_unregister(struct kobject *);

extern struct kobject * kobject_get(struct kobject *);
extern void kobject_put(struct kobject *);

extern struct kobject *kobject_kset_add_dir(struct kset *kset,
         struct kobject *, const char *);
extern struct kobject *kobject_add_dir(struct kobject *, const char *);

extern char * kobject_get_path(struct kobject *, gfp_t);

struct kobj_type {
 void (*release)(struct kobject *);
 struct sysfs_ops * sysfs_ops;
 struct attribute ** default_attrs;
};
# 120 "include/linux/kobject.h"
struct kset_uevent_ops {
 int (*filter)(struct kset *kset, struct kobject *kobj);
 const char *(*name)(struct kset *kset, struct kobject *kobj);
 int (*uevent)(struct kset *kset, struct kobject *kobj, char **envp,
   int num_envp, char *buffer, int buffer_size);
};

struct kset {
 struct kobj_type * ktype;
 struct list_head list;
 spinlock_t list_lock;
 struct kobject kobj;
 struct kset_uevent_ops * uevent_ops;
};


extern void kset_init(struct kset * k);
extern int __attribute__((warn_unused_result)) kset_add(struct kset * k);
extern int __attribute__((warn_unused_result)) kset_register(struct kset * k);
extern void kset_unregister(struct kset * k);

static inline __attribute__((always_inline)) struct kset * to_kset(struct kobject * kobj)
{
 return kobj ? ({ const typeof( ((struct kset *)0)->kobj ) *__mptr = (kobj); (struct kset *)( (char *)__mptr - __builtin_offsetof(struct kset,kobj) );}) : ((void *)0);
}

static inline __attribute__((always_inline)) struct kset * kset_get(struct kset * k)
{
 return k ? to_kset(kobject_get(&k->kobj)) : ((void *)0);
}

static inline __attribute__((always_inline)) void kset_put(struct kset * k)
{
 kobject_put(&k->kobj);
}

static inline __attribute__((always_inline)) struct kobj_type * get_ktype(struct kobject * k)
{
 if (k->kset && k->kset->ktype)
  return k->kset->ktype;
 else
  return k->ktype;
}

extern struct kobject * kset_find_obj(struct kset *, const char *);
# 188 "include/linux/kobject.h"
extern struct kset kernel_subsys;

extern struct kset hypervisor_subsys;
# 237 "include/linux/kobject.h"
extern void subsystem_init(struct kset *);
extern int __attribute__((warn_unused_result)) subsystem_register(struct kset *);
extern void subsystem_unregister(struct kset *);

static inline __attribute__((always_inline)) struct kset *subsys_get(struct kset *s)
{
 if (s)
  return kset_get(s);
 return ((void *)0);
}

static inline __attribute__((always_inline)) void subsys_put(struct kset *s)
{
 kset_put(s);
}

struct subsys_attribute {
 struct attribute attr;
 ssize_t (*show)(struct kset *, char *);
 ssize_t (*store)(struct kset *, const char *, size_t);
};

extern int __attribute__((warn_unused_result)) subsys_create_file(struct kset *,
     struct subsys_attribute *);


int kobject_uevent(struct kobject *kobj, enum kobject_action action);
int kobject_uevent_env(struct kobject *kobj, enum kobject_action action,
   char *envp[]);

int add_uevent_var(char **envp, int num_envp, int *cur_index,
   char *buffer, int buffer_size, int *cur_len,
   const char *format, ...)
 __attribute__((format (printf, 7, 8)));
# 18 "include/linux/module.h" 2
# 1 "include/linux/moduleparam.h" 1
# 29 "include/linux/moduleparam.h"
struct kernel_param;


typedef int (*param_set_fn)(const char *val, struct kernel_param *kp);

typedef int (*param_get_fn)(char *buffer, struct kernel_param *kp);

struct kernel_param {
 const char *name;
 unsigned int perm;
 param_set_fn set;
 param_get_fn get;
 void *arg;
};


struct kparam_string {
 unsigned int maxlen;
 char *string;
};


struct kparam_array
{
 unsigned int max;
 unsigned int *num;
 param_set_fn set;
 param_get_fn get;
 unsigned int elemsize;
 void *elem;
};
# 98 "include/linux/moduleparam.h"
extern int parse_args(const char *name,
        char *args,
        struct kernel_param *params,
        unsigned num,
        int (*unknown)(char *param, char *val));







extern int param_set_byte(const char *val, struct kernel_param *kp);
extern int param_get_byte(char *buffer, struct kernel_param *kp);


extern int param_set_short(const char *val, struct kernel_param *kp);
extern int param_get_short(char *buffer, struct kernel_param *kp);


extern int param_set_ushort(const char *val, struct kernel_param *kp);
extern int param_get_ushort(char *buffer, struct kernel_param *kp);


extern int param_set_int(const char *val, struct kernel_param *kp);
extern int param_get_int(char *buffer, struct kernel_param *kp);


extern int param_set_uint(const char *val, struct kernel_param *kp);
extern int param_get_uint(char *buffer, struct kernel_param *kp);


extern int param_set_long(const char *val, struct kernel_param *kp);
extern int param_get_long(char *buffer, struct kernel_param *kp);


extern int param_set_ulong(const char *val, struct kernel_param *kp);
extern int param_get_ulong(char *buffer, struct kernel_param *kp);


extern int param_set_charp(const char *val, struct kernel_param *kp);
extern int param_get_charp(char *buffer, struct kernel_param *kp);


extern int param_set_bool(const char *val, struct kernel_param *kp);
extern int param_get_bool(char *buffer, struct kernel_param *kp);


extern int param_set_invbool(const char *val, struct kernel_param *kp);
extern int param_get_invbool(char *buffer, struct kernel_param *kp);
# 162 "include/linux/moduleparam.h"
extern int param_array_set(const char *val, struct kernel_param *kp);
extern int param_array_get(char *buffer, struct kernel_param *kp);

extern int param_set_copystring(const char *val, struct kernel_param *kp);
extern int param_get_string(char *buffer, struct kernel_param *kp);



struct module;


extern int module_param_sysfs_setup(struct module *mod,
        struct kernel_param *kparam,
        unsigned int num_params);

extern void module_param_sysfs_remove(struct module *mod);
# 19 "include/linux/module.h" 2
# 1 "include/asm/local.h" 1







typedef struct
{
 atomic_long_t a;
} local_t;






static __inline__ __attribute__((always_inline)) void local_inc(local_t *l)
{
 __asm__ __volatile__(
  "incl %0"
  :"+m" (l->a.counter));
}

static __inline__ __attribute__((always_inline)) void local_dec(local_t *l)
{
 __asm__ __volatile__(
  "decl %0"
  :"+m" (l->a.counter));
}

static __inline__ __attribute__((always_inline)) void local_add(long i, local_t *l)
{
 __asm__ __volatile__(
  "addl %1,%0"
  :"+m" (l->a.counter)
  :"ir" (i));
}

static __inline__ __attribute__((always_inline)) void local_sub(long i, local_t *l)
{
 __asm__ __volatile__(
  "subl %1,%0"
  :"+m" (l->a.counter)
  :"ir" (i));
}
# 57 "include/asm/local.h"
static __inline__ __attribute__((always_inline)) int local_sub_and_test(long i, local_t *l)
{
 unsigned char c;

 __asm__ __volatile__(
  "subl %2,%0; sete %1"
  :"+m" (l->a.counter), "=qm" (c)
  :"ir" (i) : "memory");
 return c;
}
# 76 "include/asm/local.h"
static __inline__ __attribute__((always_inline)) int local_dec_and_test(local_t *l)
{
 unsigned char c;

 __asm__ __volatile__(
  "decl %0; sete %1"
  :"+m" (l->a.counter), "=qm" (c)
  : : "memory");
 return c != 0;
}
# 95 "include/asm/local.h"
static __inline__ __attribute__((always_inline)) int local_inc_and_test(local_t *l)
{
 unsigned char c;

 __asm__ __volatile__(
  "incl %0; sete %1"
  :"+m" (l->a.counter), "=qm" (c)
  : : "memory");
 return c != 0;
}
# 115 "include/asm/local.h"
static __inline__ __attribute__((always_inline)) int local_add_negative(long i, local_t *l)
{
 unsigned char c;

 __asm__ __volatile__(
  "addl %2,%0; sets %1"
  :"+m" (l->a.counter), "=qm" (c)
  :"ir" (i) : "memory");
 return c;
}
# 133 "include/asm/local.h"
static __inline__ __attribute__((always_inline)) long local_add_return(long i, local_t *l)
{
 long __i;






 __i = i;
 __asm__ __volatile__(
  "xaddl %0, %1;"
  :"+r" (i), "+m" (l->a.counter)
  : : "memory");
 return i + __i;
# 157 "include/asm/local.h"
}

static __inline__ __attribute__((always_inline)) long local_sub_return(long i, local_t *l)
{
 return local_add_return(-i,l);
}
# 20 "include/linux/module.h" 2

# 1 "include/asm/module.h" 1




struct mod_arch_specific
{
};
# 22 "include/linux/module.h" 2
# 33 "include/linux/module.h"
struct kernel_symbol
{
 unsigned long value;
 const char *name;
};

struct modversion_info
{
 unsigned long crc;
 char name[(64 - sizeof(unsigned long))];
};

struct module;

struct module_attribute {
        struct attribute attr;
        ssize_t (*show)(struct module_attribute *, struct module *, char *);
        ssize_t (*store)(struct module_attribute *, struct module *,
    const char *, size_t count);
 void (*setup)(struct module *, const char *);
 int (*test)(struct module *);
 void (*free)(struct module *);
};

struct module_kobject
{
 struct kobject kobj;
 struct module *mod;
 struct kobject *drivers_dir;
};


extern int init_module(void);
extern void cleanup_module(void);


struct exception_table_entry;

const struct exception_table_entry *
search_extable(const struct exception_table_entry *first,
        const struct exception_table_entry *last,
        unsigned long value);
void sort_extable(struct exception_table_entry *start,
    struct exception_table_entry *finish);
void sort_main_extable(void);






extern struct module __this_module;
# 163 "include/linux/module.h"
const struct exception_table_entry *search_exception_tables(unsigned long add);

struct notifier_block;




void *__symbol_get(const char *symbol);
void *__symbol_get_gpl(const char *symbol);
# 220 "include/linux/module.h"
struct module_ref
{
 local_t count;
} __attribute__((__aligned__((1 << (7)))));

enum module_state
{
 MODULE_STATE_LIVE,
 MODULE_STATE_COMING,
 MODULE_STATE_GOING,
};


struct module_sect_attr
{
 struct module_attribute mattr;
 char *name;
 unsigned long address;
};

struct module_sect_attrs
{
 struct attribute_group grp;
 int nsections;
 struct module_sect_attr attrs[0];
};

struct module_param_attrs;

struct module
{
 enum module_state state;


 struct list_head list;


 char name[(64 - sizeof(unsigned long))];


 struct module_kobject mkobj;
 struct module_param_attrs *param_attrs;
 struct module_attribute *modinfo_attrs;
 const char *version;
 const char *srcversion;
 struct kobject *holders_dir;


 const struct kernel_symbol *syms;
 unsigned int num_syms;
 const unsigned long *crcs;


 const struct kernel_symbol *gpl_syms;
 unsigned int num_gpl_syms;
 const unsigned long *gpl_crcs;


 const struct kernel_symbol *unused_syms;
 unsigned int num_unused_syms;
 const unsigned long *unused_crcs;

 const struct kernel_symbol *unused_gpl_syms;
 unsigned int num_unused_gpl_syms;
 const unsigned long *unused_gpl_crcs;


 const struct kernel_symbol *gpl_future_syms;
 unsigned int num_gpl_future_syms;
 const unsigned long *gpl_future_crcs;


 unsigned int num_exentries;
 const struct exception_table_entry *extable;


 int (*init)(void);


 void *module_init;


 void *module_core;


 unsigned long init_size, core_size;


 unsigned long init_text_size, core_text_size;


 void *unwind_info;


 struct mod_arch_specific arch;


 int unsafe;

 unsigned int taints;



 struct list_head bug_list;
 struct bug_entry *bug_table;
 unsigned num_bugs;




 struct module_ref ref[8];


 struct list_head modules_which_use_me;


 struct task_struct *waiter;


 void (*exit)(void);




 Elf32_Sym *symtab;
 unsigned long num_symtab;
 char *strtab;


 struct module_sect_attrs *sect_attrs;



 void *percpu;



 char *args;
};







static inline __attribute__((always_inline)) int module_is_live(struct module *mod)
{
 return mod->state != MODULE_STATE_GOING;
}


struct module *module_text_address(unsigned long addr);
struct module *__module_text_address(unsigned long addr);
int is_module_address(unsigned long addr);



int module_get_kallsym(unsigned int symnum, unsigned long *value, char *type,
   char *name, char *module_name, int *exported);


unsigned long module_kallsyms_lookup_name(const char *name);

extern void __module_put_and_exit(struct module *mod, long code)
 __attribute__((noreturn));



unsigned int module_refcount(struct module *mod);
void __symbol_put(const char *symbol);

void symbol_put_addr(void *addr);



static inline __attribute__((always_inline)) void __module_get(struct module *module)
{
 if (module) {
  do { if (__builtin_expect(!!((module_refcount(module) == 0)!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/module.h"), "i" (399), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
  local_inc(&module->ref[({ do { } while (0); (({ typeof(per_cpu__cpu_number) ret__; switch (sizeof(per_cpu__cpu_number)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; default: __bad_percpu_size(); } ret__; })); })].count);
  do { } while (0);
 }
}

static inline __attribute__((always_inline)) int try_module_get(struct module *module)
{
 int ret = 1;

 if (module) {
  unsigned int cpu = ({ do { } while (0); (({ typeof(per_cpu__cpu_number) ret__; switch (sizeof(per_cpu__cpu_number)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; default: __bad_percpu_size(); } ret__; })); });
  if (__builtin_expect(!!(module_is_live(module)), 1))
   local_inc(&module->ref[cpu].count);
  else
   ret = 0;
  do { } while (0);
 }
 return ret;
}

extern void module_put(struct module *module);
# 456 "include/linux/module.h"
const char *module_address_lookup(unsigned long addr,
      unsigned long *symbolsize,
      unsigned long *offset,
      char **modname);
int lookup_module_symbol_name(unsigned long addr, char *symname);
int lookup_module_symbol_attrs(unsigned long addr, unsigned long *size, unsigned long *offset, char *modname, char *name);


const struct exception_table_entry *search_module_extables(unsigned long addr);

int register_module_notifier(struct notifier_block * nb);
int unregister_module_notifier(struct notifier_block * nb);

extern void print_modules(void);
# 574 "include/linux/module.h"
struct device_driver;

struct module;

extern struct kset module_subsys;

int mod_sysfs_init(struct module *mod);
int mod_sysfs_setup(struct module *mod,
      struct kernel_param *kparam,
      unsigned int num_params);
int module_add_modinfo_attrs(struct module *mod);
void module_remove_modinfo_attrs(struct module *mod);
# 613 "include/linux/module.h"
void module_add_driver(struct module *mod, struct device_driver *drv);
void module_remove_driver(struct device_driver *drv);
# 157 "drivers/block/floppy.c" 2
# 1 "include/linux/sched.h" 1
# 42 "include/linux/sched.h"
struct sched_param {
 int sched_priority;
};

# 1 "include/asm/param.h" 1
# 47 "include/linux/sched.h" 2

# 1 "include/linux/capability.h" 1
# 19 "include/linux/capability.h"
struct task_struct;
# 34 "include/linux/capability.h"
typedef struct __user_cap_header_struct {
 __u32 version;
 int pid;
} *cap_user_header_t;

typedef struct __user_cap_data_struct {
        __u32 effective;
        __u32 permitted;
        __u32 inheritable;
} *cap_user_data_t;
# 60 "include/linux/capability.h"
typedef __u32 kernel_cap_t;
# 297 "include/linux/capability.h"
extern kernel_cap_t cap_bset;
# 325 "include/linux/capability.h"
static inline __attribute__((always_inline)) kernel_cap_t cap_combine(kernel_cap_t a, kernel_cap_t b)
{
     kernel_cap_t dest;
     (dest) = (a) | (b);
     return dest;
}

static inline __attribute__((always_inline)) kernel_cap_t cap_intersect(kernel_cap_t a, kernel_cap_t b)
{
     kernel_cap_t dest;
     (dest) = (a) & (b);
     return dest;
}

static inline __attribute__((always_inline)) kernel_cap_t cap_drop(kernel_cap_t a, kernel_cap_t drop)
{
     kernel_cap_t dest;
     (dest) = (a) & ~(drop);
     return dest;
}

static inline __attribute__((always_inline)) kernel_cap_t cap_invert(kernel_cap_t c)
{
     kernel_cap_t dest;
     (dest) = ~(c);
     return dest;
}
# 362 "include/linux/capability.h"
int capable(int cap);
int __capable(struct task_struct *t, int cap);
# 49 "include/linux/sched.h" 2



# 1 "include/linux/timex.h" 1
# 100 "include/linux/timex.h"
struct timex {
 unsigned int modes;
 long offset;
 long freq;
 long maxerror;
 long esterror;
 int status;
 long constant;
 long precision;
 long tolerance;


 struct timeval time;
 long tick;

 long ppsfreq;
 long jitter;
 int shift;
 long stabil;
 long jitcnt;
 long calcnt;
 long errcnt;
 long stbcnt;

 int :32; int :32; int :32; int :32;
 int :32; int :32; int :32; int :32;
 int :32; int :32; int :32; int :32;
};
# 187 "include/linux/timex.h"
# 1 "include/asm/timex.h" 1
# 10 "include/asm/timex.h"
# 1 "include/asm/tsc.h" 1
# 14 "include/asm/tsc.h"
typedef unsigned long long cycles_t;

extern unsigned int cpu_khz;
extern unsigned int tsc_khz;

static inline __attribute__((always_inline)) cycles_t get_cycles(void)
{
 unsigned long long ret = 0;







 (ret = paravirt_read_tsc());

 return ret;
}


static inline __attribute__((always_inline)) __attribute__((always_inline)) cycles_t get_cycles_sync(void)
{
 unsigned long long ret;
 unsigned eax, edx;





 asm volatile ("661:\n\t" ".byte 0x8d,0x76,0x00\n" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c[feat]\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" ".byte 0x0f,0x01,0xf9" "\n664:\n" ".previous" : "=a" (eax), "=d" (edx) : [feat] "i" ((1*32+27)), "a" (0U), "d" (0U) : "ecx", "memory");


 ret = (((unsigned long long)edx) << 32) | ((unsigned long long)eax);
 if (ret)
  return ret;





 asm volatile ("661:\n\t" "cpuid" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c[feat]\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" ".byte 0x89,0xf6\n" "\n664:\n" ".previous" : "=a" (eax) : [feat] "i" ((3*32+15)), "0" (1) : "ebx","ecx","edx","memory");

 (ret = paravirt_read_tsc());

 return ret;
}

extern void tsc_init(void);
extern void mark_tsc_unstable(char *reason);
extern int unsynchronized_tsc(void);
extern void init_tsc_clocksource(void);





extern void check_tsc_sync_source(int cpu);
extern void check_tsc_sync_target(void);
# 11 "include/asm/timex.h" 2
# 19 "include/asm/timex.h"
extern int read_current_timer(unsigned long *timer_value);
# 188 "include/linux/timex.h" 2






extern unsigned long tick_usec;
extern unsigned long tick_nsec;
extern int tickadj;




extern int time_status;
extern long time_maxerror;
extern long time_esterror;

extern long time_freq;

extern long time_adjust;

extern void ntp_clear(void);





static inline __attribute__((always_inline)) int ntp_synced(void)
{
 return !(time_status & 0x0040);
}
# 277 "include/linux/timex.h"
static inline __attribute__((always_inline)) void time_interpolator_reset(void)
{
}

static inline __attribute__((always_inline)) void time_interpolator_update(long delta_nsec)
{
}
# 297 "include/linux/timex.h"
extern u64 current_tick_length(void);

extern void second_overflow(void);
extern void update_ntp_one_tick(void);
extern int do_adjtimex(struct timex *);
# 53 "include/linux/sched.h" 2
# 1 "include/linux/jiffies.h" 1



# 1 "include/linux/calc64.h" 1




# 1 "include/asm/div64.h" 1
# 40 "include/asm/div64.h"
static inline __attribute__((always_inline)) long
div_ll_X_l_rem(long long divs, long div, long *rem)
{
 long dum2;
      __asm__("divl %2":"=a"(dum2), "=d"(*rem)
      : "rm"(div), "A"(divs));

 return dum2;

}

extern uint64_t div64_64(uint64_t dividend, uint64_t divisor);
# 6 "include/linux/calc64.h" 2
# 35 "include/linux/calc64.h"
static inline __attribute__((always_inline)) long div_long_long_rem_signed(const long long dividend,
         const long divisor, long *remainder)
{
 long res;

 if (__builtin_expect(!!(dividend < 0), 0)) {
  res = -div_ll_X_l_rem(-dividend,divisor,remainder);
  *remainder = -(*remainder);
 } else
  res = div_ll_X_l_rem(dividend,divisor,remainder);

 return res;
}
# 5 "include/linux/jiffies.h" 2
# 81 "include/linux/jiffies.h"
extern u64 __attribute__((section(".data"))) jiffies_64;
extern unsigned long volatile __attribute__((section(".data"))) jiffies;


u64 get_jiffies_64(void);
# 264 "include/linux/jiffies.h"
extern unsigned int jiffies_to_msecs(const unsigned long j);
extern unsigned int jiffies_to_usecs(const unsigned long j);
extern unsigned long msecs_to_jiffies(const unsigned int m);
extern unsigned long usecs_to_jiffies(const unsigned int u);
extern unsigned long timespec_to_jiffies(const struct timespec *value);
extern void jiffies_to_timespec(const unsigned long jiffies,
    struct timespec *value);
extern unsigned long timeval_to_jiffies(const struct timeval *value);
extern void jiffies_to_timeval(const unsigned long jiffies,
          struct timeval *value);
extern clock_t jiffies_to_clock_t(long x);
extern unsigned long clock_t_to_jiffies(unsigned long x);
extern u64 jiffies_64_to_clock_t(u64 x);
extern u64 nsec_to_clock_t(u64 x);
# 54 "include/linux/sched.h" 2
# 1 "include/linux/rbtree.h" 1
# 100 "include/linux/rbtree.h"
struct rb_node
{
 unsigned long rb_parent_color;


 struct rb_node *rb_right;
 struct rb_node *rb_left;
} __attribute__((aligned(sizeof(long))));


struct rb_root
{
 struct rb_node *rb_node;
};
# 123 "include/linux/rbtree.h"
static inline __attribute__((always_inline)) void rb_set_parent(struct rb_node *rb, struct rb_node *p)
{
 rb->rb_parent_color = (rb->rb_parent_color & 3) | (unsigned long)p;
}
static inline __attribute__((always_inline)) void rb_set_color(struct rb_node *rb, int color)
{
 rb->rb_parent_color = (rb->rb_parent_color & ~1) | color;
}
# 139 "include/linux/rbtree.h"
extern void rb_insert_color(struct rb_node *, struct rb_root *);
extern void rb_erase(struct rb_node *, struct rb_root *);


extern struct rb_node *rb_next(struct rb_node *);
extern struct rb_node *rb_prev(struct rb_node *);
extern struct rb_node *rb_first(struct rb_root *);
extern struct rb_node *rb_last(struct rb_root *);


extern void rb_replace_node(struct rb_node *victim, struct rb_node *new,
       struct rb_root *root);

static inline __attribute__((always_inline)) void rb_link_node(struct rb_node * node, struct rb_node * parent,
    struct rb_node ** rb_link)
{
 node->rb_parent_color = (unsigned long )parent;
 node->rb_left = node->rb_right = ((void *)0);

 *rb_link = node;
}
# 55 "include/linux/sched.h" 2
# 65 "include/linux/sched.h"
# 1 "include/asm/cputime.h" 1



# 1 "include/asm-generic/cputime.h" 1






typedef unsigned long cputime_t;
# 23 "include/asm-generic/cputime.h"
typedef u64 cputime64_t;
# 5 "include/asm/cputime.h" 2
# 66 "include/linux/sched.h" 2


# 1 "include/linux/sem.h" 1



# 1 "include/linux/ipc.h" 1
# 9 "include/linux/ipc.h"
struct ipc_perm
{
 __kernel_key_t key;
 __kernel_uid_t uid;
 __kernel_gid_t gid;
 __kernel_uid_t cuid;
 __kernel_gid_t cgid;
 __kernel_mode_t mode;
 unsigned short seq;
};


# 1 "include/asm/ipcbuf.h" 1
# 14 "include/asm/ipcbuf.h"
struct ipc64_perm
{
 __kernel_key_t key;
 __kernel_uid32_t uid;
 __kernel_gid32_t gid;
 __kernel_uid32_t cuid;
 __kernel_gid32_t cgid;
 __kernel_mode_t mode;
 unsigned short __pad1;
 unsigned short seq;
 unsigned short __pad2;
 unsigned long __unused1;
 unsigned long __unused2;
};
# 22 "include/linux/ipc.h" 2
# 59 "include/linux/ipc.h"
struct kern_ipc_perm
{
 spinlock_t lock;
 int deleted;
 key_t key;
 uid_t uid;
 gid_t gid;
 uid_t cuid;
 gid_t cgid;
 mode_t mode;
 unsigned long seq;
 void *security;
};

struct ipc_ids;
struct ipc_namespace {
 struct kref kref;
 struct ipc_ids *ids[3];

 int sem_ctls[4];
 int used_sems;

 int msg_ctlmax;
 int msg_ctlmnb;
 int msg_ctlmni;

 size_t shm_ctlmax;
 size_t shm_ctlall;
 int shm_ctlmni;
 int shm_tot;
};

extern struct ipc_namespace init_ipc_ns;



extern struct ipc_namespace *copy_ipcs(unsigned long flags,
      struct ipc_namespace *ns);
# 107 "include/linux/ipc.h"
extern void free_ipc_ns(struct kref *kref);


static inline __attribute__((always_inline)) struct ipc_namespace *get_ipc_ns(struct ipc_namespace *ns)
{

 if (ns)
  kref_get(&ns->kref);

 return ns;
}

static inline __attribute__((always_inline)) void put_ipc_ns(struct ipc_namespace *ns)
{

 kref_put(&ns->kref, free_ipc_ns);

}
# 5 "include/linux/sem.h" 2
# 23 "include/linux/sem.h"
struct semid_ds {
 struct ipc_perm sem_perm;
 __kernel_time_t sem_otime;
 __kernel_time_t sem_ctime;
 struct sem *sem_base;
 struct sem_queue *sem_pending;
 struct sem_queue **sem_pending_last;
 struct sem_undo *undo;
 unsigned short sem_nsems;
};


# 1 "include/asm/sembuf.h" 1
# 14 "include/asm/sembuf.h"
struct semid64_ds {
 struct ipc64_perm sem_perm;
 __kernel_time_t sem_otime;
 unsigned long __unused1;
 __kernel_time_t sem_ctime;
 unsigned long __unused2;
 unsigned long sem_nsems;
 unsigned long __unused3;
 unsigned long __unused4;
};
# 36 "include/linux/sem.h" 2


struct sembuf {
 unsigned short sem_num;
 short sem_op;
 short sem_flg;
};


union semun {
 int val;
 struct semid_ds *buf;
 unsigned short *array;
 struct seminfo *__buf;
 void *__pad;
};

struct seminfo {
 int semmap;
 int semmni;
 int semmns;
 int semmnu;
 int semmsl;
 int semopm;
 int semume;
 int semusz;
 int semvmx;
 int semaem;
};
# 82 "include/linux/sem.h"
struct task_struct;


struct sem {
 int semval;
 int sempid;
};


struct sem_array {
 struct kern_ipc_perm sem_perm;
 int sem_id;
 time_t sem_otime;
 time_t sem_ctime;
 struct sem *sem_base;
 struct sem_queue *sem_pending;
 struct sem_queue **sem_pending_last;
 struct sem_undo *undo;
 unsigned long sem_nsems;
};


struct sem_queue {
 struct sem_queue * next;
 struct sem_queue ** prev;
 struct task_struct* sleeper;
 struct sem_undo * undo;
 int pid;
 int status;
 struct sem_array * sma;
 int id;
 struct sembuf * sops;
 int nsops;
 int alter;
};




struct sem_undo {
 struct sem_undo * proc_next;
 struct sem_undo * id_next;
 int semid;
 short * semadj;
};




struct sem_undo_list {
 atomic_t refcnt;
 spinlock_t lock;
 struct sem_undo *proc_list;
};

struct sysv_sem {
 struct sem_undo_list *undo_list;
};



extern int copy_semundo(unsigned long clone_flags, struct task_struct *tsk);
extern void exit_sem(struct task_struct *tsk);
# 69 "include/linux/sched.h" 2
# 1 "include/linux/signal.h" 1



# 1 "include/asm/signal.h" 1
# 9 "include/asm/signal.h"
struct siginfo;
# 22 "include/asm/signal.h"
typedef unsigned long old_sigset_t;

typedef struct {
 unsigned long sig[(64 / 32)];
} sigset_t;
# 113 "include/asm/signal.h"
# 1 "include/asm-generic/signal.h" 1
# 17 "include/asm-generic/signal.h"
typedef void __signalfn_t(int);
typedef __signalfn_t *__sighandler_t;

typedef void __restorefn_t(void);
typedef __restorefn_t *__sigrestore_t;
# 114 "include/asm/signal.h" 2


struct old_sigaction {
 __sighandler_t sa_handler;
 old_sigset_t sa_mask;
 unsigned long sa_flags;
 __sigrestore_t sa_restorer;
};

struct sigaction {
 __sighandler_t sa_handler;
 unsigned long sa_flags;
 __sigrestore_t sa_restorer;
 sigset_t sa_mask;
};

struct k_sigaction {
 struct sigaction sa;
};
# 151 "include/asm/signal.h"
typedef struct sigaltstack {
 void *ss_sp;
 int ss_flags;
 size_t ss_size;
} stack_t;
# 167 "include/asm/signal.h"
static __inline__ __attribute__((always_inline)) void __gen_sigaddset(sigset_t *set, int _sig)
{
 __asm__("btsl %1,%0" : "+m"(*set) : "Ir"(_sig - 1) : "cc");
}

static __inline__ __attribute__((always_inline)) void __const_sigaddset(sigset_t *set, int _sig)
{
 unsigned long sig = _sig - 1;
 set->sig[sig / 32] |= 1 << (sig % 32);
}







static __inline__ __attribute__((always_inline)) void __gen_sigdelset(sigset_t *set, int _sig)
{
 __asm__("btrl %1,%0" : "+m"(*set) : "Ir"(_sig - 1) : "cc");
}

static __inline__ __attribute__((always_inline)) void __const_sigdelset(sigset_t *set, int _sig)
{
 unsigned long sig = _sig - 1;
 set->sig[sig / 32] &= ~(1 << (sig % 32));
}

static __inline__ __attribute__((always_inline)) int __const_sigismember(sigset_t *set, int _sig)
{
 unsigned long sig = _sig - 1;
 return 1 & (set->sig[sig / 32] >> (sig % 32));
}

static __inline__ __attribute__((always_inline)) int __gen_sigismember(sigset_t *set, int _sig)
{
 int ret;
 __asm__("btl %2,%1\n\tsbbl %0,%0"
  : "=r"(ret) : "m"(*set), "Ir"(_sig-1) : "cc");
 return ret;
}






static __inline__ __attribute__((always_inline)) int sigfindinword(unsigned long word)
{
 __asm__("bsfl %1,%0" : "=r"(word) : "rm"(word) : "cc");
 return word;
}

struct pt_regs;
# 5 "include/linux/signal.h" 2
# 1 "include/asm/siginfo.h" 1



# 1 "include/asm-generic/siginfo.h" 1






typedef union sigval {
 int sival_int;
 void *sival_ptr;
} sigval_t;
# 40 "include/asm-generic/siginfo.h"
typedef struct siginfo {
 int si_signo;
 int si_errno;
 int si_code;

 union {
  int _pad[((128 - (3 * sizeof(int))) / sizeof(int))];


  struct {
   pid_t _pid;
   uid_t _uid;
  } _kill;


  struct {
   timer_t _tid;
   int _overrun;
   char _pad[sizeof( uid_t) - sizeof(int)];
   sigval_t _sigval;
   int _sys_private;
  } _timer;


  struct {
   pid_t _pid;
   uid_t _uid;
   sigval_t _sigval;
  } _rt;


  struct {
   pid_t _pid;
   uid_t _uid;
   int _status;
   clock_t _utime;
   clock_t _stime;
  } _sigchld;


  struct {
   void *_addr;



  } _sigfault;


  struct {
   long _band;
   int _fd;
  } _sigpoll;
 } _sifields;
} siginfo_t;
# 251 "include/asm-generic/siginfo.h"
typedef struct sigevent {
 sigval_t sigev_value;
 int sigev_signo;
 int sigev_notify;
 union {
  int _pad[((64 - (sizeof(int) * 2 + sizeof(sigval_t))) / sizeof(int))];
   int _tid;

  struct {
   void (*_function)(sigval_t);
   void *_attribute;
  } _sigev_thread;
 } _sigev_un;
} sigevent_t;







struct siginfo;
void do_schedule_next_timer(struct siginfo *info);





static inline __attribute__((always_inline)) void copy_siginfo(struct siginfo *to, struct siginfo *from)
{
 if (from->si_code < 0)
  (__builtin_constant_p(sizeof(*to)) ? __constant_memcpy((to),(from),(sizeof(*to))) : __memcpy((to),(from),(sizeof(*to))));
 else

  (__builtin_constant_p((3 * sizeof(int)) + sizeof(from->_sifields._sigchld)) ? __constant_memcpy((to),(from),((3 * sizeof(int)) + sizeof(from->_sifields._sigchld))) : __memcpy((to),(from),((3 * sizeof(int)) + sizeof(from->_sifields._sigchld))));
}



extern int copy_siginfo_to_user(struct siginfo *to, struct siginfo *from);
# 5 "include/asm/siginfo.h" 2
# 6 "include/linux/signal.h" 2
# 15 "include/linux/signal.h"
struct sigqueue {
 struct list_head list;
 int flags;
 siginfo_t info;
 struct user_struct *user;
};




struct sigpending {
 struct list_head list;
 sigset_t signal;
};
# 73 "include/linux/signal.h"
static inline __attribute__((always_inline)) int sigisemptyset(sigset_t *set)
{
 extern void _NSIG_WORDS_is_unsupported_size(void);
 switch ((64 / 32)) {
 case 4:
  return (set->sig[3] | set->sig[2] |
   set->sig[1] | set->sig[0]) == 0;
 case 2:
  return (set->sig[1] | set->sig[0]) == 0;
 case 1:
  return set->sig[0] == 0;
 default:
  _NSIG_WORDS_is_unsupported_size();
  return 0;
 }
}
# 120 "include/linux/signal.h"
static inline __attribute__((always_inline)) void sigorsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) | (b3)); r->sig[2] = ((a2) | (b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) | (b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) | (b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }


static inline __attribute__((always_inline)) void sigandsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) & (b3)); r->sig[2] = ((a2) & (b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) & (b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) & (b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }


static inline __attribute__((always_inline)) void signandsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) & ~(b3)); r->sig[2] = ((a2) & ~(b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) & ~(b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) & ~(b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }
# 150 "include/linux/signal.h"
static inline __attribute__((always_inline)) void signotset(sigset_t *set) { extern void _NSIG_WORDS_is_unsupported_size(void); switch ((64 / 32)) { case 4: set->sig[3] = (~(set->sig[3])); set->sig[2] = (~(set->sig[2])); case 2: set->sig[1] = (~(set->sig[1])); case 1: set->sig[0] = (~(set->sig[0])); break; default: _NSIG_WORDS_is_unsupported_size(); } }




static inline __attribute__((always_inline)) void sigemptyset(sigset_t *set)
{
 switch ((64 / 32)) {
 default:
  (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(sigset_t))) ? __constant_c_and_count_memset(((set)),((0x01010101UL*(unsigned char)(0))),((sizeof(sigset_t)))) : __constant_c_memset(((set)),((0x01010101UL*(unsigned char)(0))),((sizeof(sigset_t))))) : (__builtin_constant_p((sizeof(sigset_t))) ? __memset_generic((((set))),(((0))),(((sizeof(sigset_t))))) : __memset_generic(((set)),((0)),((sizeof(sigset_t))))));
  break;
 case 2: set->sig[1] = 0;
 case 1: set->sig[0] = 0;
  break;
 }
}

static inline __attribute__((always_inline)) void sigfillset(sigset_t *set)
{
 switch ((64 / 32)) {
 default:
  (__builtin_constant_p(-1) ? (__builtin_constant_p((sizeof(sigset_t))) ? __constant_c_and_count_memset(((set)),((0x01010101UL*(unsigned char)(-1))),((sizeof(sigset_t)))) : __constant_c_memset(((set)),((0x01010101UL*(unsigned char)(-1))),((sizeof(sigset_t))))) : (__builtin_constant_p((sizeof(sigset_t))) ? __memset_generic((((set))),(((-1))),(((sizeof(sigset_t))))) : __memset_generic(((set)),((-1)),((sizeof(sigset_t))))));
  break;
 case 2: set->sig[1] = -1;
 case 1: set->sig[0] = -1;
  break;
 }
}



static inline __attribute__((always_inline)) void sigaddsetmask(sigset_t *set, unsigned long mask)
{
 set->sig[0] |= mask;
}

static inline __attribute__((always_inline)) void sigdelsetmask(sigset_t *set, unsigned long mask)
{
 set->sig[0] &= ~mask;
}

static inline __attribute__((always_inline)) int sigtestsetmask(sigset_t *set, unsigned long mask)
{
 return (set->sig[0] & mask) != 0;
}

static inline __attribute__((always_inline)) void siginitset(sigset_t *set, unsigned long mask)
{
 set->sig[0] = mask;
 switch ((64 / 32)) {
 default:
  (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __constant_c_and_count_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(0))),((sizeof(long)*((64 / 32)-1)))) : __constant_c_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(0))),((sizeof(long)*((64 / 32)-1))))) : (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __memset_generic((((&set->sig[1]))),(((0))),(((sizeof(long)*((64 / 32)-1))))) : __memset_generic(((&set->sig[1])),((0)),((sizeof(long)*((64 / 32)-1))))));
  break;
 case 2: set->sig[1] = 0;
 case 1: ;
 }
}

static inline __attribute__((always_inline)) void siginitsetinv(sigset_t *set, unsigned long mask)
{
 set->sig[0] = ~mask;
 switch ((64 / 32)) {
 default:
  (__builtin_constant_p(-1) ? (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __constant_c_and_count_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(-1))),((sizeof(long)*((64 / 32)-1)))) : __constant_c_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(-1))),((sizeof(long)*((64 / 32)-1))))) : (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __memset_generic((((&set->sig[1]))),(((-1))),(((sizeof(long)*((64 / 32)-1))))) : __memset_generic(((&set->sig[1])),((-1)),((sizeof(long)*((64 / 32)-1))))));
  break;
 case 2: set->sig[1] = -1;
 case 1: ;
 }
}



static inline __attribute__((always_inline)) void init_sigpending(struct sigpending *sig)
{
 sigemptyset(&sig->signal);
 INIT_LIST_HEAD(&sig->list);
}

extern void flush_sigqueue(struct sigpending *queue);


static inline __attribute__((always_inline)) int valid_signal(unsigned long sig)
{
 return sig <= 64 ? 1 : 0;
}

extern int next_signal(struct sigpending *pending, sigset_t *mask);
extern int group_send_sig_info(int sig, struct siginfo *info, struct task_struct *p);
extern int __group_send_sig_info(int, struct siginfo *, struct task_struct *);
extern long do_sigpending(void *, unsigned long);
extern int sigprocmask(int, sigset_t *, sigset_t *);

struct pt_regs;
extern int get_signal_to_deliver(siginfo_t *info, struct k_sigaction *return_ka, struct pt_regs *regs, void *cookie);

extern struct kmem_cache *sighand_cachep;
# 70 "include/linux/sched.h" 2
# 1 "include/linux/securebits.h" 1





extern unsigned securebits;
# 71 "include/linux/sched.h" 2
# 1 "include/linux/fs_struct.h" 1



struct dentry;
struct vfsmount;

struct fs_struct {
 atomic_t count;
 rwlock_t lock;
 int umask;
 struct dentry * root, * pwd, * altroot;
 struct vfsmount * rootmnt, * pwdmnt, * altrootmnt;
};







extern struct kmem_cache *fs_cachep;

extern void exit_fs(struct task_struct *);
extern void set_fs_altroot(void);
extern void set_fs_root(struct fs_struct *, struct vfsmount *, struct dentry *);
extern void set_fs_pwd(struct fs_struct *, struct vfsmount *, struct dentry *);
extern struct fs_struct *copy_fs_struct(struct fs_struct *);
extern void put_fs_struct(struct fs_struct *);
# 72 "include/linux/sched.h" 2

# 1 "include/linux/completion.h" 1
# 13 "include/linux/completion.h"
struct completion {
 unsigned int done;
 wait_queue_head_t wait;
};
# 39 "include/linux/completion.h"
static inline __attribute__((always_inline)) void init_completion(struct completion *x)
{
 x->done = 0;
 init_waitqueue_head(&x->wait);
}

extern void wait_for_completion(struct completion *) __attribute__((regparm(3)));
extern int wait_for_completion_interruptible(struct completion *x) __attribute__((regparm(3)));
extern unsigned long wait_for_completion_timeout(struct completion *x, unsigned long timeout) __attribute__((regparm(3)));

extern unsigned long wait_for_completion_interruptible_timeout( struct completion *x, unsigned long timeout) __attribute__((regparm(3)));


extern void complete(struct completion *) __attribute__((regparm(3)));
extern void complete_all(struct completion *) __attribute__((regparm(3)));
# 74 "include/linux/sched.h" 2
# 1 "include/linux/pid.h" 1



# 1 "include/linux/rcupdate.h" 1
# 50 "include/linux/rcupdate.h"
struct rcu_head {
 struct rcu_head *next;
 void (*func)(struct rcu_head *head);
};
# 64 "include/linux/rcupdate.h"
struct rcu_ctrlblk {
 long cur;
 long completed;
 int next_pending;

 int signaled;

 spinlock_t lock __attribute__((__aligned__(1 << ((7)))));
 cpumask_t cpumask;

} __attribute__((__aligned__(1 << ((7)))));


static inline __attribute__((always_inline)) int rcu_batch_before(long a, long b)
{
        return (a - b) < 0;
}


static inline __attribute__((always_inline)) int rcu_batch_after(long a, long b)
{
        return (a - b) > 0;
}






struct rcu_data {

 long quiescbatch;
 int passed_quiesc;
 int qs_pending;


 long batch;
 struct rcu_head *nxtlist;
 struct rcu_head **nxttail;
 long qlen;
 struct rcu_head *curlist;
 struct rcu_head **curtail;
 struct rcu_head *donelist;
 struct rcu_head **donetail;
 long blimit;
 int cpu;
 struct rcu_head barrier;
};

extern __typeof__(struct rcu_data) per_cpu__rcu_data;
extern __typeof__(struct rcu_data) per_cpu__rcu_bh_data;







static inline __attribute__((always_inline)) void rcu_qsctr_inc(int cpu)
{
 struct rcu_data *rdp = &(*({ extern int simple_indentifier_rcu_data(void); ({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__rcu_data)); (typeof(&per_cpu__rcu_data)) (__ptr + (__per_cpu_offset[cpu])); }); }));
 rdp->passed_quiesc = 1;
}
static inline __attribute__((always_inline)) void rcu_bh_qsctr_inc(int cpu)
{
 struct rcu_data *rdp = &(*({ extern int simple_indentifier_rcu_bh_data(void); ({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__rcu_bh_data)); (typeof(&per_cpu__rcu_bh_data)) (__ptr + (__per_cpu_offset[cpu])); }); }));
 rdp->passed_quiesc = 1;
}

extern int rcu_pending(int cpu);
extern int rcu_needs_cpu(int cpu);
# 272 "include/linux/rcupdate.h"
extern void rcu_init(void);
extern void rcu_check_callbacks(int cpu, int user);
extern void rcu_restart_cpu(int cpu);
extern long rcu_batches_completed(void);
extern long rcu_batches_completed_bh(void);


extern void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head)) __attribute__((regparm(3)));

extern void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *head)) __attribute__((regparm(3)));

extern void synchronize_rcu(void);
void synchronize_idle(void);
extern void rcu_barrier(void);
# 5 "include/linux/pid.h" 2

enum pid_type
{
 PIDTYPE_PID,
 PIDTYPE_PGID,
 PIDTYPE_SID,
 PIDTYPE_MAX
};
# 43 "include/linux/pid.h"
struct pid
{
 atomic_t count;

 int nr;
 struct hlist_node pid_chain;

 struct hlist_head tasks[PIDTYPE_MAX];
 struct rcu_head rcu;
};

extern struct pid init_struct_pid;

struct pid_link
{
 struct hlist_node node;
 struct pid *pid;
};

static inline __attribute__((always_inline)) struct pid *get_pid(struct pid *pid)
{
 if (pid)
  atomic_inc(&pid->count);
 return pid;
}

extern void put_pid(struct pid *pid) __attribute__((regparm(3)));
extern struct task_struct *pid_task(struct pid *pid, enum pid_type) __attribute__((regparm(3)));
extern struct task_struct *get_pid_task(struct pid *pid, enum pid_type) __attribute__((regparm(3)));


extern struct pid *get_task_pid(struct task_struct *task, enum pid_type type);





extern int attach_pid(struct task_struct *task, enum pid_type type, struct pid *pid) __attribute__((regparm(3)));

extern void detach_pid(struct task_struct *task, enum pid_type) __attribute__((regparm(3)));
extern void transfer_pid(struct task_struct *old, struct task_struct *new, enum pid_type) __attribute__((regparm(3)));






extern struct pid *find_pid(int nr) __attribute__((regparm(3)));




extern struct pid *find_get_pid(int nr);
extern struct pid *find_ge_pid(int nr);

extern struct pid *alloc_pid(void);
extern void free_pid(struct pid *pid) __attribute__((regparm(3)));

static inline __attribute__((always_inline)) pid_t pid_nr(struct pid *pid)
{
 pid_t nr = 0;
 if (pid)
  nr = pid->nr;
 return nr;
}
# 75 "include/linux/sched.h" 2


# 1 "include/linux/seccomp.h" 1
# 10 "include/linux/seccomp.h"
# 1 "include/asm/seccomp.h" 1
# 9 "include/asm/seccomp.h"
# 1 "include/linux/unistd.h" 1






# 1 "include/asm/unistd.h" 1
# 8 "include/linux/unistd.h" 2
# 10 "include/asm/seccomp.h" 2
# 11 "include/linux/seccomp.h" 2

typedef struct { int mode; } seccomp_t;

extern void __secure_computing(int);
static inline __attribute__((always_inline)) void secure_computing(int this_syscall)
{
 if (__builtin_expect(!!(test_ti_thread_flag(current_thread_info(), 8)), 0))
  __secure_computing(this_syscall);
}

static inline __attribute__((always_inline)) int has_secure_computing(struct thread_info *ti)
{
 return __builtin_expect(!!(test_ti_thread_flag(ti, 8)), 0);
}
# 78 "include/linux/sched.h" 2

# 1 "include/linux/futex.h" 1



# 1 "include/linux/sched.h" 1
# 5 "include/linux/futex.h" 2

union ktime;
# 47 "include/linux/futex.h"
struct robust_list {
 struct robust_list *next;
};
# 59 "include/linux/futex.h"
struct robust_list_head {



 struct robust_list list;







 long futex_offset;
# 83 "include/linux/futex.h"
 struct robust_list *list_op_pending;
};
# 111 "include/linux/futex.h"
long do_futex(u32 *uaddr, int op, u32 val, union ktime *timeout,
       u32 *uaddr2, u32 val2, u32 val3);

extern int
handle_futex_death(u32 *uaddr, struct task_struct *curr, int pi);
# 135 "include/linux/futex.h"
union futex_key {
 struct {
  unsigned long pgoff;
  struct inode *inode;
  int offset;
 } shared;
 struct {
  unsigned long address;
  struct mm_struct *mm;
  int offset;
 } private;
 struct {
  unsigned long word;
  void *ptr;
  int offset;
 } both;
};
int get_futex_key(u32 *uaddr, struct rw_semaphore *shared,
    union futex_key *key);
void get_futex_key_refs(union futex_key *key);
void drop_futex_key_refs(union futex_key *key);


extern void exit_robust_list(struct task_struct *curr);
extern void exit_pi_state_list(struct task_struct *curr);
# 80 "include/linux/sched.h" 2
# 1 "include/linux/rtmutex.h" 1
# 16 "include/linux/rtmutex.h"
# 1 "include/linux/plist.h" 1
# 80 "include/linux/plist.h"
struct plist_head {
 struct list_head prio_list;
 struct list_head node_list;

 spinlock_t *lock;

};

struct plist_node {
 int prio;
 struct plist_head plist;
};
# 127 "include/linux/plist.h"
static inline __attribute__((always_inline)) void
plist_head_init(struct plist_head *head, spinlock_t *lock)
{
 INIT_LIST_HEAD(&head->prio_list);
 INIT_LIST_HEAD(&head->node_list);

 head->lock = lock;

}






static inline __attribute__((always_inline)) void plist_node_init(struct plist_node *node, int prio)
{
 node->prio = prio;
 plist_head_init(&node->plist, ((void *)0));
}

extern void plist_add(struct plist_node *node, struct plist_head *head);
extern void plist_del(struct plist_node *node, struct plist_head *head);
# 195 "include/linux/plist.h"
static inline __attribute__((always_inline)) int plist_head_empty(const struct plist_head *head)
{
 return list_empty(&head->node_list);
}





static inline __attribute__((always_inline)) int plist_node_empty(const struct plist_node *node)
{
 return plist_head_empty(&node->plist);
}
# 234 "include/linux/plist.h"
static inline __attribute__((always_inline)) struct plist_node* plist_first(const struct plist_head *head)
{
 return ({ const typeof( ((struct plist_node *)0)->plist.node_list ) *__mptr = (head->node_list.next); (struct plist_node *)( (char *)__mptr - __builtin_offsetof(struct plist_node,plist.node_list) );});

}
# 17 "include/linux/rtmutex.h" 2
# 26 "include/linux/rtmutex.h"
struct rt_mutex {
 spinlock_t wait_lock;
 struct plist_head wait_list;
 struct task_struct *owner;

 int save_state;
 const char *name, *file;
 int line;
 void *magic;

};

struct rt_mutex_waiter;
struct hrtimer_sleeper;


 extern int rt_mutex_debug_check_no_locks_freed(const void *from,
      unsigned long len);
 extern void rt_mutex_debug_check_no_locks_held(struct task_struct *task);
# 58 "include/linux/rtmutex.h"
 extern void rt_mutex_debug_task_free(struct task_struct *tsk);
# 80 "include/linux/rtmutex.h"
static inline __attribute__((always_inline)) int rt_mutex_is_locked(struct rt_mutex *lock)
{
 return lock->owner != ((void *)0);
}

extern void __rt_mutex_init(struct rt_mutex *lock, const char *name);
extern void rt_mutex_destroy(struct rt_mutex *lock);

extern void rt_mutex_lock(struct rt_mutex *lock);
extern int rt_mutex_lock_interruptible(struct rt_mutex *lock,
      int detect_deadlock);
extern int rt_mutex_timed_lock(struct rt_mutex *lock,
     struct hrtimer_sleeper *timeout,
     int detect_deadlock);

extern int rt_mutex_trylock(struct rt_mutex *lock);

extern void rt_mutex_unlock(struct rt_mutex *lock);
# 81 "include/linux/sched.h" 2


# 1 "include/linux/param.h" 1
# 84 "include/linux/sched.h" 2
# 1 "include/linux/resource.h" 1





struct task_struct;
# 23 "include/linux/resource.h"
struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
 long ru_maxrss;
 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;
};

struct rlimit {
 unsigned long rlim_cur;
 unsigned long rlim_max;
};
# 70 "include/linux/resource.h"
# 1 "include/asm/resource.h" 1



# 1 "include/asm-generic/resource.h" 1
# 5 "include/asm/resource.h" 2
# 71 "include/linux/resource.h" 2

int getrusage(struct task_struct *p, int who, struct rusage *ru);
# 85 "include/linux/sched.h" 2
# 1 "include/linux/timer.h" 1




# 1 "include/linux/ktime.h" 1
# 46 "include/linux/ktime.h"
union ktime {
 s64 tv64;
# 57 "include/linux/ktime.h"
};

typedef union ktime ktime_t;
# 81 "include/linux/ktime.h"
static inline __attribute__((always_inline)) ktime_t ktime_set(const long secs, const unsigned long nsecs)
{




 return (ktime_t) { .tv64 = (s64)secs * 1000000000L + (s64)nsecs };
}
# 106 "include/linux/ktime.h"
static inline __attribute__((always_inline)) ktime_t timespec_to_ktime(struct timespec ts)
{
 return ktime_set(ts.tv_sec, ts.tv_nsec);
}


static inline __attribute__((always_inline)) ktime_t timeval_to_ktime(struct timeval tv)
{
 return ktime_set(tv.tv_sec, tv.tv_usec * 1000L);
}
# 271 "include/linux/ktime.h"
static inline __attribute__((always_inline)) int ktime_equal(const ktime_t cmp1, const ktime_t cmp2)
{
 return cmp1.tv64 == cmp2.tv64;
}

static inline __attribute__((always_inline)) s64 ktime_to_us(const ktime_t kt)
{
 struct timeval tv = ns_to_timeval((kt).tv64);
 return (s64) tv.tv_sec * 1000000L + tv.tv_usec;
}

static inline __attribute__((always_inline)) s64 ktime_us_delta(const ktime_t later, const ktime_t earlier)
{
       return ktime_to_us(({ (ktime_t){ .tv64 = (later).tv64 - (earlier).tv64 }; }));
}

static inline __attribute__((always_inline)) ktime_t ktime_add_us(const ktime_t kt, const u64 usec)
{
 return ({ (ktime_t){ .tv64 = (kt).tv64 + (usec * 1000) }; });
}
# 301 "include/linux/ktime.h"
extern void ktime_get_ts(struct timespec *ts);
# 6 "include/linux/timer.h" 2



struct tvec_t_base_s;

struct timer_list {
 struct list_head entry;
 unsigned long expires;

 void (*function)(unsigned long);
 unsigned long data;

 struct tvec_t_base_s *base;

 void *start_site;
 char start_comm[16];
 int start_pid;

};

extern struct tvec_t_base_s boot_tvec_bases;
# 39 "include/linux/timer.h"
void __attribute__((regparm(3))) init_timer(struct timer_list * timer);
void __attribute__((regparm(3))) init_timer_deferrable(struct timer_list *timer);

static inline __attribute__((always_inline)) void setup_timer(struct timer_list * timer,
    void (*function)(unsigned long),
    unsigned long data)
{
 timer->function = function;
 timer->data = data;
 init_timer(timer);
}
# 61 "include/linux/timer.h"
static inline __attribute__((always_inline)) int timer_pending(const struct timer_list * timer)
{
 return timer->entry.next != ((void *)0);
}

extern void add_timer_on(struct timer_list *timer, int cpu);
extern int del_timer(struct timer_list * timer);
extern int __mod_timer(struct timer_list *timer, unsigned long expires);
extern int mod_timer(struct timer_list *timer, unsigned long expires);
# 81 "include/linux/timer.h"
extern unsigned long next_timer_interrupt(void);





extern unsigned long get_next_timer_interrupt(unsigned long now);






extern void init_timer_stats(void);

extern void timer_stats_update_stats(void *timer, pid_t pid, void *startf,
         void *timerf, char * comm);

static inline __attribute__((always_inline)) void timer_stats_account_timer(struct timer_list *timer)
{
 timer_stats_update_stats(timer, timer->start_pid, timer->start_site,
     timer->function, timer->start_comm);
}

extern void __timer_stats_timer_set_start_info(struct timer_list *timer,
            void *addr);

static inline __attribute__((always_inline)) void timer_stats_timer_set_start_info(struct timer_list *timer)
{
 __timer_stats_timer_set_start_info(timer, __builtin_return_address(0));
}

static inline __attribute__((always_inline)) void timer_stats_timer_clear_start_info(struct timer_list *timer)
{
 timer->start_site = ((void *)0);
}
# 135 "include/linux/timer.h"
extern void delayed_work_timer_fn(unsigned long __data);
# 151 "include/linux/timer.h"
static inline __attribute__((always_inline)) void add_timer(struct timer_list *timer)
{
 do { if (__builtin_expect(!!((timer_pending(timer))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/timer.h"), "i" (153), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
 __mod_timer(timer, timer->expires);
}


  extern int try_to_del_timer_sync(struct timer_list *timer);
  extern int del_timer_sync(struct timer_list *timer);







extern void init_timers(void);
extern void run_local_timers(void);
struct hrtimer;
extern enum hrtimer_restart it_real_fn(struct hrtimer *);

unsigned long __round_jiffies(unsigned long j, int cpu);
unsigned long __round_jiffies_relative(unsigned long j, int cpu);
unsigned long round_jiffies(unsigned long j);
unsigned long round_jiffies_relative(unsigned long j);
# 86 "include/linux/sched.h" 2
# 1 "include/linux/hrtimer.h" 1
# 24 "include/linux/hrtimer.h"
struct hrtimer_clock_base;
struct hrtimer_cpu_base;




enum hrtimer_mode {
 HRTIMER_MODE_ABS,
 HRTIMER_MODE_REL,
};




enum hrtimer_restart {
 HRTIMER_NORESTART,
 HRTIMER_RESTART,
};
# 53 "include/linux/hrtimer.h"
enum hrtimer_cb_mode {
 HRTIMER_CB_SOFTIRQ,
 HRTIMER_CB_IRQSAFE,
 HRTIMER_CB_IRQSAFE_NO_RESTART,
 HRTIMER_CB_IRQSAFE_NO_SOFTIRQ,
};
# 112 "include/linux/hrtimer.h"
struct hrtimer {
 struct rb_node node;
 ktime_t expires;
 enum hrtimer_restart (*function)(struct hrtimer *);
 struct hrtimer_clock_base *base;
 unsigned long state;

 enum hrtimer_cb_mode cb_mode;
 struct list_head cb_entry;


 void *start_site;
 char start_comm[16];
 int start_pid;

};
# 136 "include/linux/hrtimer.h"
struct hrtimer_sleeper {
 struct hrtimer timer;
 struct task_struct *task;
};
# 156 "include/linux/hrtimer.h"
struct hrtimer_clock_base {
 struct hrtimer_cpu_base *cpu_base;
 clockid_t index;
 struct rb_root active;
 struct rb_node *first;
 ktime_t resolution;
 ktime_t (*get_time)(void);
 ktime_t (*get_softirq_time)(void);
 ktime_t softirq_time;

 ktime_t offset;
 int (*reprogram)(struct hrtimer *t,
          struct hrtimer_clock_base *b,
          ktime_t n);

};
# 193 "include/linux/hrtimer.h"
struct hrtimer_cpu_base {
 spinlock_t lock;
 struct lock_class_key lock_key;
 struct hrtimer_clock_base clock_base[2];

 ktime_t expires_next;
 int hres_active;
 struct list_head cb_pending;
 unsigned long nr_events;

};


struct clock_event_device;

extern void clock_was_set(void);
extern void hres_timers_resume(void);
extern void hrtimer_interrupt(struct clock_event_device *dev);




static inline __attribute__((always_inline)) ktime_t hrtimer_cb_get_time(struct hrtimer *timer)
{
 return timer->base->get_time();
}
# 253 "include/linux/hrtimer.h"
extern ktime_t ktime_get(void);
extern ktime_t ktime_get_real(void);




extern void hrtimer_init(struct hrtimer *timer, clockid_t which_clock,
    enum hrtimer_mode mode);


extern int hrtimer_start(struct hrtimer *timer, ktime_t tim,
    const enum hrtimer_mode mode);
extern int hrtimer_cancel(struct hrtimer *timer);
extern int hrtimer_try_to_cancel(struct hrtimer *timer);

static inline __attribute__((always_inline)) int hrtimer_restart(struct hrtimer *timer)
{
 return hrtimer_start(timer, timer->expires, HRTIMER_MODE_ABS);
}


extern ktime_t hrtimer_get_remaining(const struct hrtimer *timer);
extern int hrtimer_get_res(const clockid_t which_clock, struct timespec *tp);

extern ktime_t hrtimer_get_next_event(void);





static inline __attribute__((always_inline)) int hrtimer_active(const struct hrtimer *timer)
{
 return timer->state != 0x00;
}




static inline __attribute__((always_inline)) int hrtimer_is_queued(struct hrtimer *timer)
{
 return timer->state &
  (0x01 | 0x04);
}


extern unsigned long
hrtimer_forward(struct hrtimer *timer, ktime_t now, ktime_t interval);


extern long hrtimer_nanosleep(struct timespec *rqtp,
         struct timespec *rmtp,
         const enum hrtimer_mode mode,
         const clockid_t clockid);
extern long hrtimer_nanosleep_restart(struct restart_block *restart_block);

extern void hrtimer_init_sleeper(struct hrtimer_sleeper *sl,
     struct task_struct *tsk);


extern void hrtimer_run_queues(void);


extern void __attribute__ ((__section__ (".init.text"))) hrtimers_init(void);


extern unsigned long ktime_divns(const ktime_t kt, s64 div);





extern void sysrq_timer_list_show(void);






extern void timer_stats_update_stats(void *timer, pid_t pid, void *startf,
         void *timerf, char * comm);

static inline __attribute__((always_inline)) void timer_stats_account_hrtimer(struct hrtimer *timer)
{
 timer_stats_update_stats(timer, timer->start_pid, timer->start_site,
     timer->function, timer->start_comm);
}

extern void __timer_stats_hrtimer_set_start_info(struct hrtimer *timer,
       void *addr);

static inline __attribute__((always_inline)) void timer_stats_hrtimer_set_start_info(struct hrtimer *timer)
{
 __timer_stats_hrtimer_set_start_info(timer, __builtin_return_address(0));
}

static inline __attribute__((always_inline)) void timer_stats_hrtimer_clear_start_info(struct hrtimer *timer)
{
 timer->start_site = ((void *)0);
}
# 87 "include/linux/sched.h" 2
# 1 "include/linux/task_io_accounting.h" 1
# 12 "include/linux/task_io_accounting.h"
struct task_io_accounting {




 u64 read_bytes;





 u64 write_bytes;
# 32 "include/linux/task_io_accounting.h"
 u64 cancelled_write_bytes;
};
# 88 "include/linux/sched.h" 2



struct exec_domain;
struct futex_pi_state;
struct bio;
# 111 "include/linux/sched.h"
extern unsigned long avenrun[];
# 125 "include/linux/sched.h"
extern unsigned long total_forks;
extern int nr_threads;
extern __typeof__(unsigned long) per_cpu__process_counts;
extern int nr_processes(void);
extern unsigned long nr_running(void);
extern unsigned long nr_uninterruptible(void);
extern unsigned long nr_active(void);
extern unsigned long nr_iowait(void);
extern unsigned long weighted_cpuload(const int cpu);

struct seq_file;
struct cfs_rq;

extern void proc_sched_show_task(struct task_struct *p, struct seq_file *m);
extern void proc_sched_set_task(struct task_struct *p);
extern void
print_cfs_rq(struct seq_file *m, int cpu, struct cfs_rq *cfs_rq, u64 now);
# 210 "include/linux/sched.h"
extern rwlock_t tasklist_lock;
extern spinlock_t mmlist_lock;

struct task_struct;

extern void sched_init(void);
extern void sched_init_smp(void);
extern void init_idle(struct task_struct *idle, int cpu);
extern void init_idle_bootup_task(struct task_struct *idle);

extern cpumask_t nohz_cpu_mask;

extern int select_nohz_load_balancer(int cpu);
# 233 "include/linux/sched.h"
extern void show_state_filter(unsigned long state_filter);

static inline __attribute__((always_inline)) void show_state(void)
{
 show_state_filter(0);
}

extern void show_regs(struct pt_regs *);






extern void show_stack(struct task_struct *task, unsigned long *sp);

void io_schedule(void);
long io_schedule_timeout(long timeout);

extern void cpu_init (void);
extern void trap_init(void);
extern void update_process_times(int user);
extern void scheduler_tick(void);


extern void softlockup_tick(void);
extern void spawn_softlockup_task(void);
extern void touch_softlockup_watchdog(void);
extern void touch_all_softlockup_watchdogs(void);
# 281 "include/linux/sched.h"
extern int in_sched_functions(unsigned long addr);


extern signed long schedule_timeout(signed long timeout) __attribute__((regparm(3)));
extern signed long schedule_timeout_interruptible(signed long timeout);
extern signed long schedule_timeout_uninterruptible(signed long timeout);
 __attribute__((regparm(0))) void schedule(void);

struct nsproxy;




extern int sysctl_max_map_count;

# 1 "include/linux/aio.h" 1




# 1 "include/linux/workqueue.h" 1
# 13 "include/linux/workqueue.h"
struct workqueue_struct;

struct work_struct;
typedef void (*work_func_t)(struct work_struct *work);







struct work_struct {
 atomic_long_t data;



 struct list_head entry;
 work_func_t func;
};



struct delayed_work {
 struct work_struct work;
 struct timer_list timer;
};

struct execute_work {
 struct work_struct work;
};
# 121 "include/linux/workqueue.h"
extern struct workqueue_struct *__create_workqueue(const char *name,
          int singlethread,
          int freezeable);




extern void destroy_workqueue(struct workqueue_struct *wq);

extern int queue_work(struct workqueue_struct *wq, struct work_struct *work) __attribute__((regparm(3)));
extern int queue_delayed_work(struct workqueue_struct *wq, struct delayed_work *work, unsigned long delay) __attribute__((regparm(3)));

extern int queue_delayed_work_on(int cpu, struct workqueue_struct *wq,
   struct delayed_work *work, unsigned long delay);

extern void flush_workqueue(struct workqueue_struct *wq) __attribute__((regparm(3)));
extern void flush_scheduled_work(void);

extern int schedule_work(struct work_struct *work) __attribute__((regparm(3)));
extern int schedule_delayed_work(struct delayed_work *work, unsigned long delay) __attribute__((regparm(3)));

extern int schedule_delayed_work_on(int cpu, struct delayed_work *work,
     unsigned long delay);
extern int schedule_on_each_cpu(work_func_t func);
extern int current_is_keventd(void);
extern int keventd_up(void);

extern void init_workqueues(void);
int execute_in_process_context(work_func_t fn, struct execute_work *);

extern void cancel_work_sync(struct work_struct *work);







static inline __attribute__((always_inline)) int cancel_delayed_work(struct delayed_work *work)
{
 int ret;

 ret = del_timer_sync(&work->timer);
 if (ret)
  clear_bit(0, ((unsigned long *)(&(&work->work)->data)));
 return ret;
}

extern void cancel_rearming_delayed_work(struct delayed_work *work);


static inline __attribute__((always_inline))
void cancel_rearming_delayed_workqueue(struct workqueue_struct *wq,
     struct delayed_work *work)
{
 cancel_rearming_delayed_work(work);
}
# 6 "include/linux/aio.h" 2
# 1 "include/linux/aio_abi.h" 1
# 32 "include/linux/aio_abi.h"
typedef unsigned long aio_context_t;

enum {
 IOCB_CMD_PREAD = 0,
 IOCB_CMD_PWRITE = 1,
 IOCB_CMD_FSYNC = 2,
 IOCB_CMD_FDSYNC = 3,




 IOCB_CMD_NOOP = 6,
 IOCB_CMD_PREADV = 7,
 IOCB_CMD_PWRITEV = 8,
};
# 57 "include/linux/aio_abi.h"
struct io_event {
 __u64 data;
 __u64 obj;
 __s64 res;
 __s64 res2;
};
# 78 "include/linux/aio_abi.h"
struct iocb {

 __u64 aio_data;
 __u32 aio_key, aio_reserved1;



 __u16 aio_lio_opcode;
 __s16 aio_reqprio;
 __u32 aio_fildes;

 __u64 aio_buf;
 __u64 aio_nbytes;
 __s64 aio_offset;


 __u64 aio_reserved2;


 __u32 aio_flags;





 __u32 aio_resfd;
};
# 7 "include/linux/aio.h" 2
# 1 "include/linux/uio.h" 1
# 20 "include/linux/uio.h"
struct iovec
{
 void *iov_base;
 __kernel_size_t iov_len;
};



struct kvec {
 void *iov_base;
 size_t iov_len;
};
# 54 "include/linux/uio.h"
static inline __attribute__((always_inline)) size_t iov_length(const struct iovec *iov, unsigned long nr_segs)
{
 unsigned long seg;
 size_t ret = 0;

 for (seg = 0; seg < nr_segs; seg++)
  ret += iov[seg].iov_len;
 return ret;
}

unsigned long iov_shorten(struct iovec *iov, unsigned long nr_segs, size_t to);
# 8 "include/linux/aio.h" 2







struct kioctx;
# 87 "include/linux/aio.h"
struct kiocb {
 struct list_head ki_run_list;
 long ki_flags;
 int ki_users;
 unsigned ki_key;

 struct file *ki_filp;
 struct kioctx *ki_ctx;
 int (*ki_cancel)(struct kiocb *, struct io_event *);
 ssize_t (*ki_retry)(struct kiocb *);
 void (*ki_dtor)(struct kiocb *);

 union {
  void *user;
  struct task_struct *tsk;
 } ki_obj;

 __u64 ki_user_data;
 wait_queue_t ki_wait;
 loff_t ki_pos;

 atomic_t ki_bio_count;
 void *private;

 unsigned short ki_opcode;
 size_t ki_nbytes;
 char *ki_buf;
 size_t ki_left;
 struct iovec ki_inline_vec;
  struct iovec *ki_iovec;
  unsigned long ki_nr_segs;
  unsigned long ki_cur_seg;

 struct list_head ki_list;






 struct file *ki_eventfd;
};
# 150 "include/linux/aio.h"
struct aio_ring {
 unsigned id;
 unsigned nr;
 unsigned head;
 unsigned tail;

 unsigned magic;
 unsigned compat_features;
 unsigned incompat_features;
 unsigned header_length;


 struct io_event io_events[0];
};




struct aio_ring_info {
 unsigned long mmap_base;
 unsigned long mmap_size;

 struct page **ring_pages;
 spinlock_t ring_lock;
 long nr_pages;

 unsigned nr, tail;

 struct page *internal_pages[8];
};

struct kioctx {
 atomic_t users;
 int dead;
 struct mm_struct *mm;


 unsigned long user_id;
 struct kioctx *next;

 wait_queue_head_t wait;

 spinlock_t ctx_lock;

 int reqs_active;
 struct list_head active_reqs;
 struct list_head run_list;


 unsigned max_reqs;

 struct aio_ring_info ring_info;

 struct delayed_work wq;
};


extern unsigned aio_max_size;

extern ssize_t wait_on_sync_kiocb(struct kiocb *iocb) __attribute__((regparm(3)));
extern int aio_put_req(struct kiocb *iocb) __attribute__((regparm(3)));
extern void kick_iocb(struct kiocb *iocb) __attribute__((regparm(3)));
extern int aio_complete(struct kiocb *iocb, long res, long res2) __attribute__((regparm(3)));
extern void __put_ioctx(struct kioctx *ctx) __attribute__((regparm(3)));
struct mm_struct;
extern void exit_aio(struct mm_struct *mm) __attribute__((regparm(3)));
extern struct kioctx *lookup_ioctx(unsigned long ctx_id);
extern int io_submit_one(struct kioctx *ctx, struct iocb *user_iocb, struct iocb *iocb) __attribute__((regparm(3)));



struct kioctx *lookup_ioctx(unsigned long ctx_id);
int io_submit_one(struct kioctx *ctx, struct iocb *user_iocb, struct iocb *iocb) __attribute__((regparm(3)));
# 251 "include/linux/aio.h"
static inline __attribute__((always_inline)) struct kiocb *list_kiocb(struct list_head *h)
{
 return ({ const typeof( ((struct kiocb *)0)->ki_list ) *__mptr = (h); (struct kiocb *)( (char *)__mptr - __builtin_offsetof(struct kiocb,ki_list) );});
}


extern unsigned long aio_nr;
extern unsigned long aio_max_nr;
# 297 "include/linux/sched.h" 2

extern unsigned long
arch_get_unmapped_area(struct file *, unsigned long, unsigned long,
         unsigned long, unsigned long);
extern unsigned long
arch_get_unmapped_area_topdown(struct file *filp, unsigned long addr,
     unsigned long len, unsigned long pgoff,
     unsigned long flags);
extern void arch_unmap_area(struct mm_struct *, unsigned long);
extern void arch_unmap_area_topdown(struct mm_struct *, unsigned long);
# 318 "include/linux/sched.h"
typedef atomic_long_t mm_counter_t;
# 346 "include/linux/sched.h"
struct mm_struct {
 struct vm_area_struct * mmap;
 struct rb_root mm_rb;
 struct vm_area_struct * mmap_cache;
 unsigned long (*get_unmapped_area) (struct file *filp,
    unsigned long addr, unsigned long len,
    unsigned long pgoff, unsigned long flags);
 void (*unmap_area) (struct mm_struct *mm, unsigned long addr);
 unsigned long mmap_base;
 unsigned long task_size;
 unsigned long cached_hole_size;
 unsigned long free_area_cache;
 pgd_t * pgd;
 atomic_t mm_users;
 atomic_t mm_count;
 int map_count;
 struct rw_semaphore mmap_sem;
 spinlock_t page_table_lock;

 struct list_head mmlist;







 mm_counter_t _file_rss;
 mm_counter_t _anon_rss;

 unsigned long hiwater_rss;
 unsigned long hiwater_vm;

 unsigned long total_vm, locked_vm, shared_vm, exec_vm;
 unsigned long stack_vm, reserved_vm, def_flags, nr_ptes;
 unsigned long start_code, end_code, start_data, end_data;
 unsigned long start_brk, brk, start_stack;
 unsigned long arg_start, arg_end, env_start, env_end;

 unsigned long saved_auxv[44];

 cpumask_t cpu_vm_mask;


 mm_context_t context;
# 399 "include/linux/sched.h"
 unsigned int faultstamp;
 unsigned int token_priority;
 unsigned int last_interval;

 unsigned char dumpable:2;


 int core_waiters;
 struct completion *core_startup_done, core_done;


 rwlock_t ioctx_list_lock;
 struct kioctx *ioctx_list;
};

struct sighand_struct {
 atomic_t count;
 struct k_sigaction action[64];
 spinlock_t siglock;
 struct list_head signalfd_list;
};

struct pacct_struct {
 int ac_flag;
 long ac_exitcode;
 unsigned long ac_mem;
 cputime_t ac_utime, ac_stime;
 unsigned long ac_minflt, ac_majflt;
};
# 436 "include/linux/sched.h"
struct signal_struct {
 atomic_t count;
 atomic_t live;

 wait_queue_head_t wait_chldexit;


 struct task_struct *curr_target;


 struct sigpending shared_pending;


 int group_exit_code;





 struct task_struct *group_exit_task;
 int notify_count;


 int group_stop_count;
 unsigned int flags;


 struct list_head posix_timers;


 struct hrtimer real_timer;
 struct task_struct *tsk;
 ktime_t it_real_incr;


 cputime_t it_prof_expires, it_virt_expires;
 cputime_t it_prof_incr, it_virt_incr;


 pid_t pgrp;
 struct pid *tty_old_pgrp;

 union {
  pid_t session __attribute__((deprecated));
  pid_t __session;
 };


 int leader;

 struct tty_struct *tty;







 cputime_t utime, stime, cutime, cstime;
 unsigned long nvcsw, nivcsw, cnvcsw, cnivcsw;
 unsigned long min_flt, maj_flt, cmin_flt, cmaj_flt;
 unsigned long inblock, oublock, cinblock, coublock;







 unsigned long long sum_sched_runtime;
# 516 "include/linux/sched.h"
 struct rlimit rlim[15];

 struct list_head cpu_timers[3];




 struct key *session_keyring;
 struct key *process_keyring;


 struct pacct_struct pacct;


 struct taskstats *stats;

};
# 550 "include/linux/sched.h"
struct user_struct {
 atomic_t __count;
 atomic_t processes;
 atomic_t files;
 atomic_t sigpending;

 atomic_t inotify_watches;
 atomic_t inotify_devs;


 unsigned long mq_bytes;
 unsigned long locked_shm;


 struct key *uid_keyring;
 struct key *session_keyring;



 struct list_head uidhash_list;
 uid_t uid;
};

extern struct user_struct *find_user(uid_t);

extern struct user_struct root_user;


struct backing_dev_info;
struct reclaim_state;


struct sched_info {

 unsigned long pcnt;
 unsigned long long cpu_time,
      run_delay;


 unsigned long long last_arrival,
      last_queued;
};



extern const struct file_operations proc_schedstat_operations;



struct task_delay_info {
 spinlock_t lock;
 unsigned int flags;
# 618 "include/linux/sched.h"
 struct timespec blkio_start, blkio_end;
 u64 blkio_delay;
 u64 swapin_delay;
 u32 blkio_count;

 u32 swapin_count;

};


static inline __attribute__((always_inline)) int sched_info_on(void)
{

 return 1;






}

enum cpu_idle_type {
 CPU_IDLE,
 CPU_NOT_IDLE,
 CPU_NEWLY_IDLE,
 CPU_MAX_IDLE_TYPES
};
# 683 "include/linux/sched.h"
struct sched_group {
 struct sched_group *next;
 cpumask_t cpumask;






 unsigned int __cpu_power;




 u32 reciprocal_cpu_power;
};

struct sched_domain {

 struct sched_domain *parent;
 struct sched_domain *child;
 struct sched_group *groups;
 cpumask_t span;
 unsigned long min_interval;
 unsigned long max_interval;
 unsigned int busy_factor;
 unsigned int imbalance_pct;
 unsigned long long cache_hot_time;
 unsigned int cache_nice_tries;
 unsigned int busy_idx;
 unsigned int idle_idx;
 unsigned int newidle_idx;
 unsigned int wake_idx;
 unsigned int forkexec_idx;
 int flags;


 unsigned long last_balance;
 unsigned int balance_interval;
 unsigned int nr_balance_failed;



 unsigned long lb_cnt[CPU_MAX_IDLE_TYPES];
 unsigned long lb_failed[CPU_MAX_IDLE_TYPES];
 unsigned long lb_balanced[CPU_MAX_IDLE_TYPES];
 unsigned long lb_imbalance[CPU_MAX_IDLE_TYPES];
 unsigned long lb_gained[CPU_MAX_IDLE_TYPES];
 unsigned long lb_hot_gained[CPU_MAX_IDLE_TYPES];
 unsigned long lb_nobusyg[CPU_MAX_IDLE_TYPES];
 unsigned long lb_nobusyq[CPU_MAX_IDLE_TYPES];


 unsigned long alb_cnt;
 unsigned long alb_failed;
 unsigned long alb_pushed;


 unsigned long sbe_cnt;
 unsigned long sbe_balanced;
 unsigned long sbe_pushed;


 unsigned long sbf_cnt;
 unsigned long sbf_balanced;
 unsigned long sbf_pushed;


 unsigned long ttwu_wake_remote;
 unsigned long ttwu_move_affine;
 unsigned long ttwu_move_balance;

};

extern int partition_sched_domains(cpumask_t *partition1,
        cpumask_t *partition2);




struct io_context;
struct cpuset;



struct group_info {
 int ngroups;
 atomic_t usage;
 gid_t small_block[32];
 int nblocks;
 gid_t *blocks[0];
};
# 791 "include/linux/sched.h"
extern struct group_info *groups_alloc(int gidsetsize);
extern void groups_free(struct group_info *group_info);
extern int set_current_groups(struct group_info *group_info);
extern int groups_search(struct group_info *group_info, gid_t grp);







static inline __attribute__((always_inline)) void prefetch_stack(struct task_struct *t) { }


struct audit_context;
struct mempolicy;
struct pipe_inode_info;
struct uts_namespace;

struct rq;
struct sched_domain;

struct sched_class {
 struct sched_class *next;

 void (*enqueue_task) (struct rq *rq, struct task_struct *p,
         int wakeup, u64 now);
 void (*dequeue_task) (struct rq *rq, struct task_struct *p,
         int sleep, u64 now);
 void (*yield_task) (struct rq *rq, struct task_struct *p);

 void (*check_preempt_curr) (struct rq *rq, struct task_struct *p);

 struct task_struct * (*pick_next_task) (struct rq *rq, u64 now);
 void (*put_prev_task) (struct rq *rq, struct task_struct *p, u64 now);

 int (*load_balance) (struct rq *this_rq, int this_cpu,
   struct rq *busiest,
   unsigned long max_nr_move, unsigned long max_load_move,
   struct sched_domain *sd, enum cpu_idle_type idle,
   int *all_pinned, unsigned long *total_load_moved);

 void (*set_curr_task) (struct rq *rq);
 void (*task_tick) (struct rq *rq, struct task_struct *p);
 void (*task_new) (struct rq *rq, struct task_struct *p);
};

struct load_weight {
 unsigned long weight, inv_weight;
};
# 855 "include/linux/sched.h"
struct sched_entity {
 long wait_runtime;
 unsigned long delta_fair_run;
 unsigned long delta_fair_sleep;
 unsigned long delta_exec;
 s64 fair_key;
 struct load_weight load;
 struct rb_node run_node;
 unsigned int on_rq;

 u64 wait_start_fair;
 u64 wait_start;
 u64 exec_start;
 u64 sleep_start;
 u64 sleep_start_fair;
 u64 block_start;
 u64 sleep_max;
 u64 block_max;
 u64 exec_max;
 u64 wait_max;
 u64 last_ran;

 u64 sum_exec_runtime;
 s64 sum_wait_runtime;
 s64 sum_sleep_runtime;
 unsigned long wait_runtime_overruns;
 unsigned long wait_runtime_underruns;







};

struct task_struct {
 volatile long state;
 void *stack;
 atomic_t usage;
 unsigned int flags;
 unsigned int ptrace;

 int lock_depth;







 int prio, static_prio, normal_prio;
 struct list_head run_list;
 struct sched_class *sched_class;
 struct sched_entity se;

 unsigned short ioprio;

 unsigned int btrace_seq;


 unsigned int policy;
 cpumask_t cpus_allowed;
 unsigned int time_slice;


 struct sched_info sched_info;


 struct list_head tasks;




 struct list_head ptrace_children;
 struct list_head ptrace_list;

 struct mm_struct *mm, *active_mm;


 struct linux_binfmt *binfmt;
 int exit_state;
 int exit_code, exit_signal;
 int pdeath_signal;

 unsigned int personality;
 unsigned did_exec:1;
 pid_t pid;
 pid_t tgid;
# 954 "include/linux/sched.h"
 struct task_struct *real_parent;
 struct task_struct *parent;




 struct list_head children;
 struct list_head sibling;
 struct task_struct *group_leader;


 struct pid_link pids[PIDTYPE_MAX];
 struct list_head thread_group;

 struct completion *vfork_done;
 int *set_child_tid;
 int *clear_child_tid;

 unsigned int rt_priority;
 cputime_t utime, stime;
 unsigned long nvcsw, nivcsw;
 struct timespec start_time;

 unsigned long min_flt, maj_flt;

   cputime_t it_prof_expires, it_virt_expires;
 unsigned long long it_sched_expires;
 struct list_head cpu_timers[3];


 uid_t uid,euid,suid,fsuid;
 gid_t gid,egid,sgid,fsgid;
 struct group_info *group_info;
 kernel_cap_t cap_effective, cap_inheritable, cap_permitted;
 unsigned keep_capabilities:1;
 struct user_struct *user;

 struct key *request_key_auth;
 struct key *thread_keyring;
 unsigned char jit_keyring;
# 1003 "include/linux/sched.h"
 unsigned char fpu_counter;
 int oomkilladj;
 char comm[16];




 int link_count, total_link_count;


 struct sysv_sem sysvsem;


 struct thread_struct thread;

 struct fs_struct *fs;

 struct files_struct *files;

 struct nsproxy *nsproxy;

 struct signal_struct *signal;
 struct sighand_struct *sighand;

 sigset_t blocked, real_blocked;
 sigset_t saved_sigmask;
 struct sigpending pending;

 unsigned long sas_ss_sp;
 size_t sas_ss_size;
 int (*notifier)(void *priv);
 void *notifier_data;
 sigset_t *notifier_mask;

 void *security;
 struct audit_context *audit_context;
 seccomp_t seccomp;


    u32 parent_exec_id;
    u32 self_exec_id;

 spinlock_t alloc_lock;


 spinlock_t pi_lock;



 struct plist_head pi_waiters;

 struct rt_mutex_waiter *pi_blocked_on;




 struct mutex_waiter *blocked_on;


 unsigned int irq_events;
 int hardirqs_enabled;
 unsigned long hardirq_enable_ip;
 unsigned int hardirq_enable_event;
 unsigned long hardirq_disable_ip;
 unsigned int hardirq_disable_event;
 int softirqs_enabled;
 unsigned long softirq_disable_ip;
 unsigned int softirq_disable_event;
 unsigned long softirq_enable_ip;
 unsigned int softirq_enable_event;
 int hardirq_context;
 int softirq_context;



 u64 curr_chain_key;
 int lockdep_depth;
 struct held_lock held_locks[30UL];
 unsigned int lockdep_recursion;



 void *journal_info;


 struct bio *bio_list, **bio_tail;


 struct reclaim_state *reclaim_state;

 struct backing_dev_info *backing_dev_info;

 struct io_context *io_context;

 unsigned long ptrace_message;
 siginfo_t *last_siginfo;






 wait_queue_t *io_wait;


 u64 rchar, wchar, syscr, syscw;

 struct task_io_accounting ioac;

 u64 acct_rss_mem1;
 u64 acct_vm_mem1;
 cputime_t acct_stimexpd;






 struct cpuset *cpuset;
 nodemask_t mems_allowed;
 int cpuset_mems_generation;
 int cpuset_mem_spread_rotor;

 struct robust_list_head *robust_list;



 struct list_head pi_state_list;
 struct futex_pi_state *pi_state_cache;

 atomic_t fs_excl;
 struct rcu_head rcu;




 struct pipe_inode_info *splice_pipe;

 struct task_delay_info *delays;


 int make_it_fail;

};
# 1167 "include/linux/sched.h"
static inline __attribute__((always_inline)) int rt_prio(int prio)
{
 if (__builtin_expect(!!(prio < 100), 0))
  return 1;
 return 0;
}

static inline __attribute__((always_inline)) int rt_task(struct task_struct *p)
{
 return rt_prio(p->prio);
}

static inline __attribute__((always_inline)) pid_t process_group(struct task_struct *tsk)
{
 return tsk->signal->pgrp;
}

static inline __attribute__((always_inline)) pid_t signal_session(struct signal_struct *sig)
{
 return sig->__session;
}

static inline __attribute__((always_inline)) pid_t process_session(struct task_struct *tsk)
{
 return signal_session(tsk->signal);
}

static inline __attribute__((always_inline)) void set_signal_session(struct signal_struct *sig, pid_t session)
{
 sig->__session = session;
}

static inline __attribute__((always_inline)) struct pid *task_pid(struct task_struct *task)
{
 return task->pids[PIDTYPE_PID].pid;
}

static inline __attribute__((always_inline)) struct pid *task_tgid(struct task_struct *task)
{
 return task->group_leader->pids[PIDTYPE_PID].pid;
}

static inline __attribute__((always_inline)) struct pid *task_pgrp(struct task_struct *task)
{
 return task->group_leader->pids[PIDTYPE_PGID].pid;
}

static inline __attribute__((always_inline)) struct pid *task_session(struct task_struct *task)
{
 return task->group_leader->pids[PIDTYPE_SID].pid;
}
# 1227 "include/linux/sched.h"
static inline __attribute__((always_inline)) int pid_alive(struct task_struct *p)
{
 return p->pids[PIDTYPE_PID].pid != ((void *)0);
}







static inline __attribute__((always_inline)) int is_init(struct task_struct *tsk)
{
 return tsk->pid == 1;
}

extern struct pid *cad_pid;

extern void free_task(struct task_struct *tsk);


extern void __put_task_struct(struct task_struct *t);

static inline __attribute__((always_inline)) void put_task_struct(struct task_struct *t)
{
 if (atomic_dec_and_test(&t->usage))
  __put_task_struct(t);
}
# 1312 "include/linux/sched.h"
extern int set_cpus_allowed(struct task_struct *p, cpumask_t new_mask);
# 1322 "include/linux/sched.h"
extern unsigned long long sched_clock(void);
extern unsigned long long
task_sched_runtime(struct task_struct *task);



extern void sched_exec(void);




extern void sched_clock_unstable_event(void);


extern void idle_task_exit(void);




extern void sched_idle_next(void);

extern unsigned int sysctl_sched_granularity;
extern unsigned int sysctl_sched_wakeup_granularity;
extern unsigned int sysctl_sched_batch_wakeup_granularity;
extern unsigned int sysctl_sched_stat_granularity;
extern unsigned int sysctl_sched_runtime_limit;
extern unsigned int sysctl_sched_child_runs_first;
extern unsigned int sysctl_sched_features;


extern int rt_mutex_getprio(struct task_struct *p);
extern void rt_mutex_setprio(struct task_struct *p, int prio);
extern void rt_mutex_adjust_pi(struct task_struct *p);
# 1363 "include/linux/sched.h"
extern void set_user_nice(struct task_struct *p, long nice);
extern int task_prio(const struct task_struct *p);
extern int task_nice(const struct task_struct *p);
extern int can_nice(const struct task_struct *p, const int nice);
extern int task_curr(const struct task_struct *p);
extern int idle_cpu(int cpu);
extern int sched_setscheduler(struct task_struct *, int, struct sched_param *);
extern struct task_struct *idle_task(int cpu);
extern struct task_struct *curr_task(int cpu);
extern void set_curr_task(int cpu, struct task_struct *p);

void yield(void);




extern struct exec_domain default_exec_domain;

union thread_union {
 struct thread_info thread_info;
 unsigned long stack[(4096)/sizeof(long)];
};


static inline __attribute__((always_inline)) int kstack_end(void *addr)
{



 return !(((unsigned long)addr+sizeof(void*)-1) & ((4096)-sizeof(void*)));
}


extern union thread_union init_thread_union;
extern struct task_struct init_task;

extern struct mm_struct init_mm;


extern struct task_struct *find_task_by_pid_type(int type, int pid);
extern void __set_special_pids(pid_t session, pid_t pgrp);


extern struct user_struct * alloc_uid(uid_t);
static inline __attribute__((always_inline)) struct user_struct *get_uid(struct user_struct *u)
{
 atomic_inc(&u->__count);
 return u;
}
extern void free_uid(struct user_struct *);
extern void switch_uid(struct user_struct *);



extern void do_timer(unsigned long ticks);

extern int wake_up_state(struct task_struct * tsk, unsigned int state) __attribute__((regparm(3)));
extern int wake_up_process(struct task_struct * tsk) __attribute__((regparm(3)));
extern void wake_up_new_task(struct task_struct * tsk, unsigned long clone_flags) __attribute__((regparm(3)));


 extern void kick_process(struct task_struct *tsk);



extern void sched_fork(struct task_struct *p, int clone_flags);
extern void sched_dead(struct task_struct *p);

extern int in_group_p(gid_t);
extern int in_egroup_p(gid_t);

extern void proc_caches_init(void);
extern void flush_signals(struct task_struct *);
extern void ignore_signals(struct task_struct *);
extern void flush_signal_handlers(struct task_struct *, int force_default);
extern int dequeue_signal(struct task_struct *tsk, sigset_t *mask, siginfo_t *info);

static inline __attribute__((always_inline)) int dequeue_signal_lock(struct task_struct *tsk, sigset_t *mask, siginfo_t *info)
{
 unsigned long flags;
 int ret;

 flags = _spin_lock_irqsave(&tsk->sighand->siglock);
 ret = dequeue_signal(tsk, mask, info);
 _spin_unlock_irqrestore(&tsk->sighand->siglock, flags);

 return ret;
}

extern void block_all_signals(int (*notifier)(void *priv), void *priv,
         sigset_t *mask);
extern void unblock_all_signals(void);
extern void release_task(struct task_struct * p);
extern int send_sig_info(int, struct siginfo *, struct task_struct *);
extern int send_group_sig_info(int, struct siginfo *, struct task_struct *);
extern int force_sigsegv(int, struct task_struct *);
extern int force_sig_info(int, struct siginfo *, struct task_struct *);
extern int __kill_pgrp_info(int sig, struct siginfo *info, struct pid *pgrp);
extern int kill_pgrp_info(int sig, struct siginfo *info, struct pid *pgrp);
extern int kill_pid_info(int sig, struct siginfo *info, struct pid *pid);
extern int kill_pid_info_as_uid(int, struct siginfo *, struct pid *, uid_t, uid_t, u32);
extern int kill_pgrp(struct pid *pid, int sig, int priv);
extern int kill_pid(struct pid *pid, int sig, int priv);
extern int kill_proc_info(int, struct siginfo *, pid_t);
extern void do_notify_parent(struct task_struct *, int);
extern void force_sig(int, struct task_struct *);
extern void force_sig_specific(int, struct task_struct *);
extern int send_sig(int, struct task_struct *, int);
extern void zap_other_threads(struct task_struct *p);
extern int kill_proc(pid_t, int, int);
extern struct sigqueue *sigqueue_alloc(void);
extern void sigqueue_free(struct sigqueue *);
extern int send_sigqueue(int, struct sigqueue *, struct task_struct *);
extern int send_group_sigqueue(int, struct sigqueue *, struct task_struct *);
extern int do_sigaction(int, struct k_sigaction *, struct k_sigaction *);
extern int do_sigaltstack(const stack_t *, stack_t *, unsigned long);

static inline __attribute__((always_inline)) int kill_cad_pid(int sig, int priv)
{
 return kill_pid(cad_pid, sig, priv);
}






static inline __attribute__((always_inline)) int is_si_special(const struct siginfo *info)
{
 return info <= ((struct siginfo *) 2);
}



static inline __attribute__((always_inline)) int on_sig_stack(unsigned long sp)
{
 return (sp - get_current()->sas_ss_sp < get_current()->sas_ss_size);
}

static inline __attribute__((always_inline)) int sas_ss_flags(unsigned long sp)
{
 return (get_current()->sas_ss_size == 0 ? 2
  : on_sig_stack(sp) ? 1 : 0);
}




extern struct mm_struct * mm_alloc(void);


extern void __mmdrop(struct mm_struct *) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) void mmdrop(struct mm_struct * mm)
{
 if (__builtin_expect(!!(atomic_dec_and_test(&mm->mm_count)), 0))
  __mmdrop(mm);
}


extern void mmput(struct mm_struct *);

extern struct mm_struct *get_task_mm(struct task_struct *task);

extern void mm_release(struct task_struct *, struct mm_struct *);

extern int copy_thread(int, unsigned long, unsigned long, unsigned long, struct task_struct *, struct pt_regs *);
extern void flush_thread(void);
extern void exit_thread(void);

extern void exit_files(struct task_struct *);
extern void __cleanup_signal(struct signal_struct *);
extern void __cleanup_sighand(struct sighand_struct *);
extern void exit_itimers(struct signal_struct *);

extern void do_group_exit(int);

extern void daemonize(const char *, ...);
extern int allow_signal(int);
extern int disallow_signal(int);

extern int do_execve(char *, char * *, char * *, struct pt_regs *);
extern long do_fork(unsigned long, unsigned long, struct pt_regs *, unsigned long, int *, int *);
struct task_struct *fork_idle(int);

extern void set_task_comm(struct task_struct *tsk, char *from);
extern void get_task_comm(char *to, struct task_struct *tsk);


extern void wait_task_inactive(struct task_struct * p);
# 1583 "include/linux/sched.h"
static inline __attribute__((always_inline)) int has_group_leader_pid(struct task_struct *p)
{
 return p->pid == p->tgid;
}

static inline __attribute__((always_inline)) struct task_struct *next_thread(const struct task_struct *p)
{
 return ({ const typeof( ((struct task_struct *)0)->thread_group ) *__mptr = (({ typeof(p->thread_group.next) _________p1 = p->thread_group.next; do { } while(0); (_________p1); })); (struct task_struct *)( (char *)__mptr - __builtin_offsetof(struct task_struct,thread_group) );});

}

static inline __attribute__((always_inline)) int thread_group_empty(struct task_struct *p)
{
 return list_empty(&p->thread_group);
}
# 1611 "include/linux/sched.h"
static inline __attribute__((always_inline)) void task_lock(struct task_struct *p)
{
 _spin_lock(&p->alloc_lock);
}

static inline __attribute__((always_inline)) void task_unlock(struct task_struct *p)
{
 _spin_unlock(&p->alloc_lock);
}

extern struct sighand_struct *lock_task_sighand(struct task_struct *tsk,
       unsigned long *flags);

static inline __attribute__((always_inline)) void unlock_task_sighand(struct task_struct *tsk,
      unsigned long *flags)
{
 _spin_unlock_irqrestore(&tsk->sighand->siglock, *flags);
}






static inline __attribute__((always_inline)) void setup_thread_stack(struct task_struct *p, struct task_struct *org)
{
 *((struct thread_info *)(p)->stack) = *((struct thread_info *)(org)->stack);
 ((struct thread_info *)(p)->stack)->task = p;
}

static inline __attribute__((always_inline)) unsigned long *end_of_stack(struct task_struct *p)
{
 return (unsigned long *)(((struct thread_info *)(p)->stack) + 1);
}






static inline __attribute__((always_inline)) void set_tsk_thread_flag(struct task_struct *tsk, int flag)
{
 set_ti_thread_flag(((struct thread_info *)(tsk)->stack), flag);
}

static inline __attribute__((always_inline)) void clear_tsk_thread_flag(struct task_struct *tsk, int flag)
{
 clear_ti_thread_flag(((struct thread_info *)(tsk)->stack), flag);
}

static inline __attribute__((always_inline)) int test_and_set_tsk_thread_flag(struct task_struct *tsk, int flag)
{
 return test_and_set_ti_thread_flag(((struct thread_info *)(tsk)->stack), flag);
}

static inline __attribute__((always_inline)) int test_and_clear_tsk_thread_flag(struct task_struct *tsk, int flag)
{
 return test_and_clear_ti_thread_flag(((struct thread_info *)(tsk)->stack), flag);
}

static inline __attribute__((always_inline)) int test_tsk_thread_flag(struct task_struct *tsk, int flag)
{
 return test_ti_thread_flag(((struct thread_info *)(tsk)->stack), flag);
}

static inline __attribute__((always_inline)) void set_tsk_need_resched(struct task_struct *tsk)
{
 set_tsk_thread_flag(tsk,3);
}

static inline __attribute__((always_inline)) void clear_tsk_need_resched(struct task_struct *tsk)
{
 clear_tsk_thread_flag(tsk,3);
}

static inline __attribute__((always_inline)) int signal_pending(struct task_struct *p)
{
 return __builtin_expect(!!(test_tsk_thread_flag(p,2)), 0);
}

static inline __attribute__((always_inline)) int need_resched(void)
{
 return __builtin_expect(!!(test_ti_thread_flag(current_thread_info(), 3)), 0);
}
# 1703 "include/linux/sched.h"
extern int cond_resched(void);
extern int cond_resched_lock(spinlock_t * lock);
extern int cond_resched_softirq(void);
# 1721 "include/linux/sched.h"
static inline __attribute__((always_inline)) int lock_need_resched(spinlock_t *lock)
{
 if (0 || need_resched())
  return 1;
 return 0;
}







extern void recalc_sigpending_and_wake(struct task_struct *t);
extern void recalc_sigpending(void);

extern void signal_wake_up(struct task_struct *t, int resume_stopped);






static inline __attribute__((always_inline)) unsigned int task_cpu(const struct task_struct *p)
{
 return ((struct thread_info *)(p)->stack)->cpu;
}

extern void set_task_cpu(struct task_struct *p, unsigned int cpu);
# 1765 "include/linux/sched.h"
extern void arch_pick_mmap_layout(struct mm_struct *mm);
# 1775 "include/linux/sched.h"
extern long sched_setaffinity(pid_t pid, cpumask_t new_mask);
extern long sched_getaffinity(pid_t pid, cpumask_t *mask);

extern int sched_mc_power_savings, sched_smt_power_savings;

extern void normalize_rt_tasks(void);


static inline __attribute__((always_inline)) void add_rchar(struct task_struct *tsk, ssize_t amt)
{
 tsk->rchar += amt;
}

static inline __attribute__((always_inline)) void add_wchar(struct task_struct *tsk, ssize_t amt)
{
 tsk->wchar += amt;
}

static inline __attribute__((always_inline)) void inc_syscr(struct task_struct *tsk)
{
 tsk->syscr++;
}

static inline __attribute__((always_inline)) void inc_syscw(struct task_struct *tsk)
{
 tsk->syscw++;
}
# 158 "drivers/block/floppy.c" 2
# 1 "include/linux/fs.h" 1
# 9 "include/linux/fs.h"
# 1 "include/linux/limits.h" 1
# 10 "include/linux/fs.h" 2
# 1 "include/linux/ioctl.h" 1



# 1 "include/asm/ioctl.h" 1
# 1 "include/asm-generic/ioctl.h" 1
# 51 "include/asm-generic/ioctl.h"
extern unsigned int __invalid_size_argument_for_IOC;
# 1 "include/asm/ioctl.h" 2
# 5 "include/linux/ioctl.h" 2
# 11 "include/linux/fs.h" 2
# 36 "include/linux/fs.h"
struct files_stat_struct {
 int nr_files;
 int nr_free_files;
 int max_files;
};
extern struct files_stat_struct files_stat;
extern int get_max_files(void);

struct inodes_stat_t {
 int nr_inodes;
 int nr_unused;
 int dummy[5];
};
extern struct inodes_stat_t inodes_stat;

extern int leases_enable, lease_break_time;


extern int dir_notify_enable;
# 274 "include/linux/fs.h"
# 1 "include/linux/kdev_t.h" 1
# 21 "include/linux/kdev_t.h"
static inline __attribute__((always_inline)) int old_valid_dev(dev_t dev)
{
 return ((unsigned int) ((dev) >> 20)) < 256 && ((unsigned int) ((dev) & ((1U << 20) - 1))) < 256;
}

static inline __attribute__((always_inline)) u16 old_encode_dev(dev_t dev)
{
 return (((unsigned int) ((dev) >> 20)) << 8) | ((unsigned int) ((dev) & ((1U << 20) - 1)));
}

static inline __attribute__((always_inline)) dev_t old_decode_dev(u16 val)
{
 return ((((val >> 8) & 255) << 20) | (val & 255));
}

static inline __attribute__((always_inline)) int new_valid_dev(dev_t dev)
{
 return 1;
}

static inline __attribute__((always_inline)) u32 new_encode_dev(dev_t dev)
{
 unsigned major = ((unsigned int) ((dev) >> 20));
 unsigned minor = ((unsigned int) ((dev) & ((1U << 20) - 1)));
 return (minor & 0xff) | (major << 8) | ((minor & ~0xff) << 12);
}

static inline __attribute__((always_inline)) dev_t new_decode_dev(u32 dev)
{
 unsigned major = (dev & 0xfff00) >> 8;
 unsigned minor = (dev & 0xff) | ((dev >> 12) & 0xfff00);
 return (((major) << 20) | (minor));
}

static inline __attribute__((always_inline)) int huge_valid_dev(dev_t dev)
{
 return 1;
}

static inline __attribute__((always_inline)) u64 huge_encode_dev(dev_t dev)
{
 return new_encode_dev(dev);
}

static inline __attribute__((always_inline)) dev_t huge_decode_dev(u64 dev)
{
 return new_decode_dev(dev);
}

static inline __attribute__((always_inline)) int sysv_valid_dev(dev_t dev)
{
 return ((unsigned int) ((dev) >> 20)) < (1<<14) && ((unsigned int) ((dev) & ((1U << 20) - 1))) < (1<<18);
}

static inline __attribute__((always_inline)) u32 sysv_encode_dev(dev_t dev)
{
 return ((unsigned int) ((dev) & ((1U << 20) - 1))) | (((unsigned int) ((dev) >> 20)) << 18);
}

static inline __attribute__((always_inline)) unsigned sysv_major(u32 dev)
{
 return (dev >> 18) & 0x3fff;
}

static inline __attribute__((always_inline)) unsigned sysv_minor(u32 dev)
{
 return dev & 0x3ffff;
}
# 275 "include/linux/fs.h" 2
# 1 "include/linux/dcache.h" 1
# 12 "include/linux/dcache.h"
struct nameidata;
struct vfsmount;
# 33 "include/linux/dcache.h"
struct qstr {
 unsigned int hash;
 unsigned int len;
 const unsigned char *name;
};

struct dentry_stat_t {
 int nr_dentry;
 int nr_unused;
 int age_limit;
 int want_pages;
 int dummy[2];
};
extern struct dentry_stat_t dentry_stat;






static inline __attribute__((always_inline)) unsigned long
partial_name_hash(unsigned long c, unsigned long prevhash)
{
 return (prevhash + (c << 4) + (c >> 4)) * 11;
}





static inline __attribute__((always_inline)) unsigned long end_name_hash(unsigned long hash)
{
 return (unsigned int) hash;
}


static inline __attribute__((always_inline)) unsigned int
full_name_hash(const unsigned char *name, unsigned int len)
{
 unsigned long hash = 0;
 while (len--)
  hash = partial_name_hash(*name++, hash);
 return end_name_hash(hash);
}

struct dcookie_struct;



struct dentry {
 atomic_t d_count;
 unsigned int d_flags;
 spinlock_t d_lock;
 struct inode *d_inode;





 struct hlist_node d_hash;
 struct dentry *d_parent;
 struct qstr d_name;

 struct list_head d_lru;



 union {
  struct list_head d_child;
   struct rcu_head d_rcu;
 } d_u;
 struct list_head d_subdirs;
 struct list_head d_alias;
 unsigned long d_time;
 struct dentry_operations *d_op;
 struct super_block *d_sb;
 void *d_fsdata;

 struct dcookie_struct *d_cookie;

 int d_mounted;
 unsigned char d_iname[36];
};







enum dentry_d_lock_class
{
 DENTRY_D_LOCK_NORMAL,
 DENTRY_D_LOCK_NESTED
};

struct dentry_operations {
 int (*d_revalidate)(struct dentry *, struct nameidata *);
 int (*d_hash) (struct dentry *, struct qstr *);
 int (*d_compare) (struct dentry *, struct qstr *, struct qstr *);
 int (*d_delete)(struct dentry *);
 void (*d_release)(struct dentry *);
 void (*d_iput)(struct dentry *, struct inode *);
 char *(*d_dname)(struct dentry *, char *, int);
};
# 180 "include/linux/dcache.h"
extern spinlock_t dcache_lock;
# 198 "include/linux/dcache.h"
static inline __attribute__((always_inline)) void __d_drop(struct dentry *dentry)
{
 if (!(dentry->d_flags & 0x0010)) {
  dentry->d_flags |= 0x0010;
  hlist_del_rcu(&dentry->d_hash);
 }
}

static inline __attribute__((always_inline)) void d_drop(struct dentry *dentry)
{
 _spin_lock(&dcache_lock);
 _spin_lock(&dentry->d_lock);
  __d_drop(dentry);
 _spin_unlock(&dentry->d_lock);
 _spin_unlock(&dcache_lock);
}

static inline __attribute__((always_inline)) int dname_external(struct dentry *dentry)
{
 return dentry->d_name.name != dentry->d_iname;
}




extern void d_instantiate(struct dentry *, struct inode *);
extern struct dentry * d_instantiate_unique(struct dentry *, struct inode *);
extern struct dentry * d_materialise_unique(struct dentry *, struct inode *);
extern void d_delete(struct dentry *);


extern struct dentry * d_alloc(struct dentry *, const struct qstr *);
extern struct dentry * d_alloc_anon(struct inode *);
extern struct dentry * d_splice_alias(struct inode *, struct dentry *);
extern void shrink_dcache_sb(struct super_block *);
extern void shrink_dcache_parent(struct dentry *);
extern void shrink_dcache_for_umount(struct super_block *);
extern int d_invalidate(struct dentry *);


extern struct dentry * d_alloc_root(struct inode *);


extern void d_genocide(struct dentry *);

extern struct dentry *d_find_alias(struct inode *);
extern void d_prune_aliases(struct inode *);


extern int have_submounts(struct dentry *);




extern void d_rehash(struct dentry *);
# 263 "include/linux/dcache.h"
static inline __attribute__((always_inline)) void d_add(struct dentry *entry, struct inode *inode)
{
 d_instantiate(entry, inode);
 d_rehash(entry);
}
# 277 "include/linux/dcache.h"
static inline __attribute__((always_inline)) struct dentry *d_add_unique(struct dentry *entry, struct inode *inode)
{
 struct dentry *res;

 res = d_instantiate_unique(entry, inode);
 d_rehash(res != ((void *)0) ? res : entry);
 return res;
}


extern void d_move(struct dentry *, struct dentry *);


extern struct dentry * d_lookup(struct dentry *, struct qstr *);
extern struct dentry * __d_lookup(struct dentry *, struct qstr *);
extern struct dentry * d_hash_and_lookup(struct dentry *, struct qstr *);


extern int d_validate(struct dentry *, struct dentry *);




extern char *dynamic_dname(struct dentry *, char *, int, const char *, ...);

extern char * d_path(struct dentry *, struct vfsmount *, char *, int);
# 319 "include/linux/dcache.h"
static inline __attribute__((always_inline)) struct dentry *dget(struct dentry *dentry)
{
 if (dentry) {
  do { if (__builtin_expect(!!((!((&dentry->d_count)->counter))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/dcache.h"), "i" (322), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
  atomic_inc(&dentry->d_count);
 }
 return dentry;
}

extern struct dentry * dget_locked(struct dentry *);
# 337 "include/linux/dcache.h"
static inline __attribute__((always_inline)) int d_unhashed(struct dentry *dentry)
{
 return (dentry->d_flags & 0x0010);
}

static inline __attribute__((always_inline)) struct dentry *dget_parent(struct dentry *dentry)
{
 struct dentry *ret;

 _spin_lock(&dentry->d_lock);
 ret = dget(dentry->d_parent);
 _spin_unlock(&dentry->d_lock);
 return ret;
}

extern void dput(struct dentry *);

static inline __attribute__((always_inline)) int d_mountpoint(struct dentry *dentry)
{
 return dentry->d_mounted;
}

extern struct vfsmount *lookup_mnt(struct vfsmount *, struct dentry *);
extern struct vfsmount *__lookup_mnt(struct vfsmount *, struct dentry *, int);
extern struct dentry *lookup_create(struct nameidata *nd, int is_dir);

extern int sysctl_vfs_cache_pressure;
# 276 "include/linux/fs.h" 2
# 1 "include/linux/namei.h" 1






struct vfsmount;

struct open_intent {
 int flags;
 int create_mode;
 struct file *file;
};

enum { MAX_NESTED_LINKS = 8 };

struct nameidata {
 struct dentry *dentry;
 struct vfsmount *mnt;
 struct qstr last;
 unsigned int flags;
 int last_type;
 unsigned depth;
 char *saved_names[MAX_NESTED_LINKS + 1];


 union {
  struct open_intent open;
 } intent;
};

struct path {
 struct vfsmount *mnt;
 struct dentry *dentry;
};




enum {LAST_NORM, LAST_ROOT, LAST_DOT, LAST_DOTDOT, LAST_BIND};
# 65 "include/linux/namei.h"
extern int __user_walk(const char *, unsigned, struct nameidata *) __attribute__((regparm(3)));
extern int __user_walk_fd(int dfd, const char *, unsigned, struct nameidata *) __attribute__((regparm(3)));




extern int path_lookup(const char *, unsigned, struct nameidata *) __attribute__((regparm(3)));
extern int path_walk(const char *, struct nameidata *) __attribute__((regparm(3)));
extern int link_path_walk(const char *, struct nameidata *) __attribute__((regparm(3)));
extern void path_release(struct nameidata *);
extern void path_release_on_umount(struct nameidata *);

extern int __user_path_lookup_open(const char *, unsigned lookup_flags, struct nameidata *nd, int open_flags);
extern int path_lookup_open(int dfd, const char *name, unsigned lookup_flags, struct nameidata *, int open_flags);
extern struct file *lookup_instantiate_filp(struct nameidata *nd, struct dentry *dentry,
  int (*open)(struct inode *, struct file *));
extern struct file *nameidata_to_filp(struct nameidata *nd, int flags);
extern void release_open_intent(struct nameidata *);

extern struct dentry * lookup_one_len(const char *, struct dentry *, int);
extern struct dentry *lookup_one_len_kern(const char *, struct dentry *, int);

extern int follow_down(struct vfsmount **, struct dentry **);
extern int follow_up(struct vfsmount **, struct dentry **);

extern struct dentry *lock_rename(struct dentry *, struct dentry *);
extern void unlock_rename(struct dentry *, struct dentry *);

static inline __attribute__((always_inline)) void nd_set_link(struct nameidata *nd, char *path)
{
 nd->saved_names[nd->depth] = path;
}

static inline __attribute__((always_inline)) char *nd_get_link(struct nameidata *nd)
{
 return nd->saved_names[nd->depth];
}
# 277 "include/linux/fs.h" 2




# 1 "include/linux/radix-tree.h" 1
# 38 "include/linux/radix-tree.h"
static inline __attribute__((always_inline)) void *radix_tree_ptr_to_direct(void *ptr)
{
 return (void *)((unsigned long)ptr | 1);
}

static inline __attribute__((always_inline)) void *radix_tree_direct_to_ptr(void *ptr)
{
 return (void *)((unsigned long)ptr & ~1);
}

static inline __attribute__((always_inline)) int radix_tree_is_direct_ptr(void *ptr)
{
 return (int)((unsigned long)ptr & 1);
}






struct radix_tree_root {
 unsigned int height;
 gfp_t gfp_mask;
 struct radix_tree_node *rnode;
};
# 131 "include/linux/radix-tree.h"
static inline __attribute__((always_inline)) void *radix_tree_deref_slot(void **pslot)
{
 return radix_tree_direct_to_ptr(*pslot);
}
# 143 "include/linux/radix-tree.h"
static inline __attribute__((always_inline)) void radix_tree_replace_slot(void **pslot, void *item)
{
 do { if (__builtin_expect(!!((radix_tree_is_direct_ptr(item))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/radix-tree.h"), "i" (145), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
 ({ __asm__ __volatile__ ("": : :"memory"); (*pslot) = ((void *)((unsigned long)item | ((unsigned long)*pslot & 1))); });


}

int radix_tree_insert(struct radix_tree_root *, unsigned long, void *);
void *radix_tree_lookup(struct radix_tree_root *, unsigned long);
void **radix_tree_lookup_slot(struct radix_tree_root *, unsigned long);
void *radix_tree_delete(struct radix_tree_root *, unsigned long);
unsigned int
radix_tree_gang_lookup(struct radix_tree_root *root, void **results,
   unsigned long first_index, unsigned int max_items);
int radix_tree_preload(gfp_t gfp_mask);
void radix_tree_init(void);
void *radix_tree_tag_set(struct radix_tree_root *root,
   unsigned long index, unsigned int tag);
void *radix_tree_tag_clear(struct radix_tree_root *root,
   unsigned long index, unsigned int tag);
int radix_tree_tag_get(struct radix_tree_root *root,
   unsigned long index, unsigned int tag);
unsigned int
radix_tree_gang_lookup_tag(struct radix_tree_root *root, void **results,
  unsigned long first_index, unsigned int max_items,
  unsigned int tag);
int radix_tree_tagged(struct radix_tree_root *root, unsigned int tag);

static inline __attribute__((always_inline)) void radix_tree_preload_end(void)
{
 do { } while (0);
}
# 282 "include/linux/fs.h" 2
# 1 "include/linux/prio_tree.h" 1
# 14 "include/linux/prio_tree.h"
struct raw_prio_tree_node {
 struct prio_tree_node *left;
 struct prio_tree_node *right;
 struct prio_tree_node *parent;
};

struct prio_tree_node {
 struct prio_tree_node *left;
 struct prio_tree_node *right;
 struct prio_tree_node *parent;
 unsigned long start;
 unsigned long last;
};

struct prio_tree_root {
 struct prio_tree_node *prio_tree_node;
 unsigned short index_bits;
 unsigned short raw;




};

struct prio_tree_iter {
 struct prio_tree_node *cur;
 unsigned long mask;
 unsigned long value;
 int size_level;

 struct prio_tree_root *root;
 unsigned long r_index;
 unsigned long h_index;
};

static inline __attribute__((always_inline)) void prio_tree_iter_init(struct prio_tree_iter *iter,
  struct prio_tree_root *root, unsigned long r_index, unsigned long h_index)
{
 iter->root = root;
 iter->r_index = r_index;
 iter->h_index = h_index;
 iter->cur = ((void *)0);
}
# 84 "include/linux/prio_tree.h"
static inline __attribute__((always_inline)) int prio_tree_empty(const struct prio_tree_root *root)
{
 return root->prio_tree_node == ((void *)0);
}

static inline __attribute__((always_inline)) int prio_tree_root(const struct prio_tree_node *node)
{
 return node->parent == node;
}

static inline __attribute__((always_inline)) int prio_tree_left_empty(const struct prio_tree_node *node)
{
 return node->left == node;
}

static inline __attribute__((always_inline)) int prio_tree_right_empty(const struct prio_tree_node *node)
{
 return node->right == node;
}


struct prio_tree_node *prio_tree_replace(struct prio_tree_root *root,
                struct prio_tree_node *old, struct prio_tree_node *node);
struct prio_tree_node *prio_tree_insert(struct prio_tree_root *root,
                struct prio_tree_node *node);
void prio_tree_remove(struct prio_tree_root *root, struct prio_tree_node *node);
struct prio_tree_node *prio_tree_next(struct prio_tree_iter *iter);
# 283 "include/linux/fs.h" 2
# 291 "include/linux/fs.h"
struct hd_geometry;
struct iovec;
struct nameidata;
struct kiocb;
struct pipe_inode_info;
struct poll_table_struct;
struct kstatfs;
struct vm_area_struct;
struct vfsmount;

extern void __attribute__ ((__section__ (".init.text"))) inode_init(unsigned long);
extern void __attribute__ ((__section__ (".init.text"))) inode_init_early(void);
extern void __attribute__ ((__section__ (".init.text"))) mnt_init(unsigned long);
extern void __attribute__ ((__section__ (".init.text"))) files_init(unsigned long);

struct buffer_head;
typedef int (get_block_t)(struct inode *inode, sector_t iblock,
   struct buffer_head *bh_result, int create);
typedef void (dio_iodone_t)(struct kiocb *iocb, loff_t offset,
   ssize_t bytes, void *private);
# 340 "include/linux/fs.h"
struct iattr {
 unsigned int ia_valid;
 umode_t ia_mode;
 uid_t ia_uid;
 gid_t ia_gid;
 loff_t ia_size;
 struct timespec ia_atime;
 struct timespec ia_mtime;
 struct timespec ia_ctime;






 struct file *ia_file;
};




# 1 "include/linux/quota.h" 1
# 44 "include/linux/quota.h"
typedef __kernel_uid32_t qid_t;
typedef __u64 qsize_t;
# 103 "include/linux/quota.h"
struct if_dqblk {
 __u64 dqb_bhardlimit;
 __u64 dqb_bsoftlimit;
 __u64 dqb_curspace;
 __u64 dqb_ihardlimit;
 __u64 dqb_isoftlimit;
 __u64 dqb_curinodes;
 __u64 dqb_btime;
 __u64 dqb_itime;
 __u32 dqb_valid;
};
# 124 "include/linux/quota.h"
struct if_dqinfo {
 __u64 dqi_bgrace;
 __u64 dqi_igrace;
 __u32 dqi_flags;
 __u32 dqi_valid;
};






# 1 "include/linux/dqblk_xfs.h" 1
# 50 "include/linux/dqblk_xfs.h"
typedef struct fs_disk_quota {
 __s8 d_version;
 __s8 d_flags;
 __u16 d_fieldmask;
 __u32 d_id;
 __u64 d_blk_hardlimit;
 __u64 d_blk_softlimit;
 __u64 d_ino_hardlimit;
 __u64 d_ino_softlimit;
 __u64 d_bcount;
 __u64 d_icount;
 __s32 d_itimer;

 __s32 d_btimer;
 __u16 d_iwarns;
 __u16 d_bwarns;
 __s32 d_padding2;
 __u64 d_rtb_hardlimit;
 __u64 d_rtb_softlimit;
 __u64 d_rtbcount;
 __s32 d_rtbtimer;
 __u16 d_rtbwarns;
 __s16 d_padding3;
 char d_padding4[8];
} fs_disk_quota_t;
# 137 "include/linux/dqblk_xfs.h"
typedef struct fs_qfilestat {
 __u64 qfs_ino;
 __u64 qfs_nblks;
 __u32 qfs_nextents;
} fs_qfilestat_t;

typedef struct fs_quota_stat {
 __s8 qs_version;
 __u16 qs_flags;
 __s8 qs_pad;
 fs_qfilestat_t qs_uquota;
 fs_qfilestat_t qs_gquota;
 __u32 qs_incoredqs;
 __s32 qs_btimelimit;
 __s32 qs_itimelimit;
 __s32 qs_rtbtimelimit;
 __u16 qs_bwarnlimit;
 __u16 qs_iwarnlimit;
} fs_quota_stat_t;
# 137 "include/linux/quota.h" 2
# 1 "include/linux/dqblk_v1.h" 1
# 21 "include/linux/dqblk_v1.h"
struct v1_mem_dqinfo {
};
# 138 "include/linux/quota.h" 2
# 1 "include/linux/dqblk_v2.h" 1
# 20 "include/linux/dqblk_v2.h"
struct v2_mem_dqinfo {
 unsigned int dqi_blocks;
 unsigned int dqi_free_blk;
 unsigned int dqi_free_entry;
};
# 139 "include/linux/quota.h" 2

extern spinlock_t dq_data_lock;
# 152 "include/linux/quota.h"
struct mem_dqblk {
 __u32 dqb_bhardlimit;
 __u32 dqb_bsoftlimit;
 qsize_t dqb_curspace;
 __u32 dqb_ihardlimit;
 __u32 dqb_isoftlimit;
 __u32 dqb_curinodes;
 time_t dqb_btime;
 time_t dqb_itime;
};




struct quota_format_type;

struct mem_dqinfo {
 struct quota_format_type *dqi_format;
 struct list_head dqi_dirty_list;
 unsigned long dqi_flags;
 unsigned int dqi_bgrace;
 unsigned int dqi_igrace;
 union {
  struct v1_mem_dqinfo v1_i;
  struct v2_mem_dqinfo v2_i;
 } u;
};

struct super_block;





extern void mark_info_dirty(struct super_block *sb, int type);







struct dqstats {
 int lookups;
 int drops;
 int reads;
 int writes;
 int cache_hits;
 int allocated_dquots;
 int free_dquots;
 int syncs;
};

extern struct dqstats dqstats;
# 214 "include/linux/quota.h"
struct dquot {
 struct hlist_node dq_hash;
 struct list_head dq_inuse;
 struct list_head dq_free;
 struct list_head dq_dirty;
 struct mutex dq_lock;
 atomic_t dq_count;
 wait_queue_head_t dq_wait_unused;
 struct super_block *dq_sb;
 unsigned int dq_id;
 loff_t dq_off;
 unsigned long dq_flags;
 short dq_type;
 struct mem_dqblk dq_dqb;
};







struct quota_format_ops {
 int (*check_quota_file)(struct super_block *sb, int type);
 int (*read_file_info)(struct super_block *sb, int type);
 int (*write_file_info)(struct super_block *sb, int type);
 int (*free_file_info)(struct super_block *sb, int type);
 int (*read_dqblk)(struct dquot *dquot);
 int (*commit_dqblk)(struct dquot *dquot);
 int (*release_dqblk)(struct dquot *dquot);
};


struct dquot_operations {
 int (*initialize) (struct inode *, int);
 int (*drop) (struct inode *);
 int (*alloc_space) (struct inode *, qsize_t, int);
 int (*alloc_inode) (const struct inode *, unsigned long);
 int (*free_space) (struct inode *, qsize_t);
 int (*free_inode) (const struct inode *, unsigned long);
 int (*transfer) (struct inode *, struct iattr *);
 int (*write_dquot) (struct dquot *);
 int (*acquire_dquot) (struct dquot *);
 int (*release_dquot) (struct dquot *);
 int (*mark_dirty) (struct dquot *);
 int (*write_info) (struct super_block *, int);
};


struct quotactl_ops {
 int (*quota_on)(struct super_block *, int, int, char *);
 int (*quota_off)(struct super_block *, int);
 int (*quota_sync)(struct super_block *, int);
 int (*get_info)(struct super_block *, int, struct if_dqinfo *);
 int (*set_info)(struct super_block *, int, struct if_dqinfo *);
 int (*get_dqblk)(struct super_block *, int, qid_t, struct if_dqblk *);
 int (*set_dqblk)(struct super_block *, int, qid_t, struct if_dqblk *);
 int (*get_xstate)(struct super_block *, struct fs_quota_stat *);
 int (*set_xstate)(struct super_block *, unsigned int, int);
 int (*get_xquota)(struct super_block *, int, qid_t, struct fs_disk_quota *);
 int (*set_xquota)(struct super_block *, int, qid_t, struct fs_disk_quota *);
};

struct quota_format_type {
 int qf_fmt_id;
 struct quota_format_ops *qf_ops;
 struct module *qf_owner;
 struct quota_format_type *qf_next;
};




struct quota_info {
 unsigned int flags;
 struct mutex dqio_mutex;
 struct mutex dqonoff_mutex;
 struct rw_semaphore dqptr_sem;
 struct inode *files[2];
 struct mem_dqinfo info[2];
 struct quota_format_ops *ops[2];
};


int mark_dquot_dirty(struct dquot *dquot);
# 308 "include/linux/quota.h"
int register_quota_format(struct quota_format_type *fmt);
void unregister_quota_format(struct quota_format_type *fmt);

struct quota_module_name {
 int qm_fmt_id;
 char *qm_mod_name;
};
# 362 "include/linux/fs.h" 2
# 389 "include/linux/fs.h"
enum positive_aop_returns {
 AOP_WRITEPAGE_ACTIVATE = 0x80000,
 AOP_TRUNCATED_PAGE = 0x80001,
};




struct page;
struct address_space;
struct writeback_control;

struct address_space_operations {
 int (*writepage)(struct page *page, struct writeback_control *wbc);
 int (*readpage)(struct file *, struct page *);
 void (*sync_page)(struct page *);


 int (*writepages)(struct address_space *, struct writeback_control *);


 int (*set_page_dirty)(struct page *page);

 int (*readpages)(struct file *filp, struct address_space *mapping,
   struct list_head *pages, unsigned nr_pages);





 int (*prepare_write)(struct file *, struct page *, unsigned, unsigned);
 int (*commit_write)(struct file *, struct page *, unsigned, unsigned);

 sector_t (*bmap)(struct address_space *, sector_t);
 void (*invalidatepage) (struct page *, unsigned long);
 int (*releasepage) (struct page *, gfp_t);
 ssize_t (*direct_IO)(int, struct kiocb *, const struct iovec *iov,
   loff_t offset, unsigned long nr_segs);
 struct page* (*get_xip_page)(struct address_space *, sector_t,
   int);

 int (*migratepage) (struct address_space *,
   struct page *, struct page *);
 int (*launder_page) (struct page *);
};

struct backing_dev_info;
struct address_space {
 struct inode *host;
 struct radix_tree_root page_tree;
 rwlock_t tree_lock;
 unsigned int i_mmap_writable;
 struct prio_tree_root i_mmap;
 struct list_head i_mmap_nonlinear;
 spinlock_t i_mmap_lock;
 unsigned int truncate_count;
 unsigned long nrpages;
 unsigned long writeback_index;
 const struct address_space_operations *a_ops;
 unsigned long flags;
 struct backing_dev_info *backing_dev_info;
 spinlock_t private_lock;
 struct list_head private_list;
 struct address_space *assoc_mapping;
} __attribute__((aligned(sizeof(long))));






struct block_device {
 dev_t bd_dev;
 struct inode * bd_inode;
 int bd_openers;
 struct mutex bd_mutex;
 struct semaphore bd_mount_sem;
 struct list_head bd_inodes;
 void * bd_holder;
 int bd_holders;

 struct list_head bd_holder_list;

 struct block_device * bd_contains;
 unsigned bd_block_size;
 struct hd_struct * bd_part;

 unsigned bd_part_count;
 int bd_invalidated;
 struct gendisk * bd_disk;
 struct list_head bd_list;
 struct backing_dev_info *bd_inode_backing_dev_info;






 unsigned long bd_private;
};
# 497 "include/linux/fs.h"
int mapping_tagged(struct address_space *mapping, int tag);




static inline __attribute__((always_inline)) int mapping_mapped(struct address_space *mapping)
{
 return !prio_tree_empty(&mapping->i_mmap) ||
  !list_empty(&mapping->i_mmap_nonlinear);
}







static inline __attribute__((always_inline)) int mapping_writably_mapped(struct address_space *mapping)
{
 return mapping->i_mmap_writable != 0;
}
# 530 "include/linux/fs.h"
struct inode {
 struct hlist_node i_hash;
 struct list_head i_list;
 struct list_head i_sb_list;
 struct list_head i_dentry;
 unsigned long i_ino;
 atomic_t i_count;
 unsigned int i_nlink;
 uid_t i_uid;
 gid_t i_gid;
 dev_t i_rdev;
 unsigned long i_version;
 loff_t i_size;

 seqcount_t i_size_seqcount;

 struct timespec i_atime;
 struct timespec i_mtime;
 struct timespec i_ctime;
 unsigned int i_blkbits;
 blkcnt_t i_blocks;
 unsigned short i_bytes;
 umode_t i_mode;
 spinlock_t i_lock;
 struct mutex i_mutex;
 struct rw_semaphore i_alloc_sem;
 const struct inode_operations *i_op;
 const struct file_operations *i_fop;
 struct super_block *i_sb;
 struct file_lock *i_flock;
 struct address_space *i_mapping;
 struct address_space i_data;

 struct dquot *i_dquot[2];

 struct list_head i_devices;
 union {
  struct pipe_inode_info *i_pipe;
  struct block_device *i_bdev;
  struct cdev *i_cdev;
 };
 int i_cindex;

 __u32 i_generation;


 unsigned long i_dnotify_mask;
 struct dnotify_struct *i_dnotify;



 struct list_head inotify_watches;
 struct mutex inotify_mutex;


 unsigned long i_state;
 unsigned long dirtied_when;

 unsigned int i_flags;

 atomic_t i_writecount;

 void *i_security;

 void *i_private;
};
# 608 "include/linux/fs.h"
enum inode_i_mutex_lock_class
{
 I_MUTEX_NORMAL,
 I_MUTEX_PARENT,
 I_MUTEX_CHILD,
 I_MUTEX_XATTR,
 I_MUTEX_QUOTA
};

extern void inode_double_lock(struct inode *inode1, struct inode *inode2);
extern void inode_double_unlock(struct inode *inode1, struct inode *inode2);
# 630 "include/linux/fs.h"
static inline __attribute__((always_inline)) loff_t i_size_read(const struct inode *inode)
{

 loff_t i_size;
 unsigned int seq;

 do {
  seq = read_seqcount_begin(&inode->i_size_seqcount);
  i_size = inode->i_size;
 } while (read_seqcount_retry(&inode->i_size_seqcount, seq));
 return i_size;
# 651 "include/linux/fs.h"
}






static inline __attribute__((always_inline)) void i_size_write(struct inode *inode, loff_t i_size)
{

 write_seqcount_begin(&inode->i_size_seqcount);
 inode->i_size = i_size;
 write_seqcount_end(&inode->i_size_seqcount);







}

static inline __attribute__((always_inline)) unsigned iminor(const struct inode *inode)
{
 return ((unsigned int) ((inode->i_rdev) & ((1U << 20) - 1)));
}

static inline __attribute__((always_inline)) unsigned imajor(const struct inode *inode)
{
 return ((unsigned int) ((inode->i_rdev) >> 20));
}

extern struct block_device *I_BDEV(struct inode *inode);

struct fown_struct {
 rwlock_t lock;
 struct pid *pid;
 enum pid_type pid_type;
 uid_t uid, euid;
 int signum;
};




struct file_ra_state {
 unsigned long start;
 unsigned long size;
 unsigned long flags;
 unsigned long cache_hit;
 unsigned long prev_index;
 unsigned long ahead_start;
 unsigned long ahead_size;
 unsigned long ra_pages;
 unsigned long mmap_hit;
 unsigned long mmap_miss;
 unsigned int prev_offset;
};



struct file {




 union {
  struct list_head fu_list;
  struct rcu_head fu_rcuhead;
 } f_u;
 struct path f_path;


 const struct file_operations *f_op;
 atomic_t f_count;
 unsigned int f_flags;
 mode_t f_mode;
 loff_t f_pos;
 struct fown_struct f_owner;
 unsigned int f_uid, f_gid;
 struct file_ra_state f_ra;

 unsigned long f_version;

 void *f_security;


 void *private_data;



 struct list_head f_ep_links;
 spinlock_t f_ep_lock;

 struct address_space *f_mapping;
};
extern spinlock_t files_lock;
# 779 "include/linux/fs.h"
typedef struct files_struct *fl_owner_t;

struct file_lock_operations {
 void (*fl_insert)(struct file_lock *);
 void (*fl_remove)(struct file_lock *);
 void (*fl_copy_lock)(struct file_lock *, struct file_lock *);
 void (*fl_release_private)(struct file_lock *);
};

struct lock_manager_operations {
 int (*fl_compare_owner)(struct file_lock *, struct file_lock *);
 void (*fl_notify)(struct file_lock *);
 int (*fl_grant)(struct file_lock *, struct file_lock *, int);
 void (*fl_copy_lock)(struct file_lock *, struct file_lock *);
 void (*fl_release_private)(struct file_lock *);
 void (*fl_break)(struct file_lock *);
 int (*fl_mylease)(struct file_lock *, struct file_lock *);
 int (*fl_change)(struct file_lock **, int);
};


# 1 "include/linux/nfs_fs_i.h" 1





# 1 "include/linux/nfs.h" 1
# 39 "include/linux/nfs.h"
 enum nfs_stat {
 NFS_OK = 0,
 NFSERR_PERM = 1,
 NFSERR_NOENT = 2,
 NFSERR_IO = 5,
 NFSERR_NXIO = 6,
 NFSERR_EAGAIN = 11,
 NFSERR_ACCES = 13,
 NFSERR_EXIST = 17,
 NFSERR_XDEV = 18,
 NFSERR_NODEV = 19,
 NFSERR_NOTDIR = 20,
 NFSERR_ISDIR = 21,
 NFSERR_INVAL = 22,
 NFSERR_FBIG = 27,
 NFSERR_NOSPC = 28,
 NFSERR_ROFS = 30,
 NFSERR_MLINK = 31,
 NFSERR_OPNOTSUPP = 45,
 NFSERR_NAMETOOLONG = 63,
 NFSERR_NOTEMPTY = 66,
 NFSERR_DQUOT = 69,
 NFSERR_STALE = 70,
 NFSERR_REMOTE = 71,
 NFSERR_WFLUSH = 99,
 NFSERR_BADHANDLE = 10001,
 NFSERR_NOT_SYNC = 10002,
 NFSERR_BAD_COOKIE = 10003,
 NFSERR_NOTSUPP = 10004,
 NFSERR_TOOSMALL = 10005,
 NFSERR_SERVERFAULT = 10006,
 NFSERR_BADTYPE = 10007,
 NFSERR_JUKEBOX = 10008,
 NFSERR_SAME = 10009,
 NFSERR_DENIED = 10010,
 NFSERR_EXPIRED = 10011,
 NFSERR_LOCKED = 10012,
 NFSERR_GRACE = 10013,
 NFSERR_FHEXPIRED = 10014,
 NFSERR_SHARE_DENIED = 10015,
 NFSERR_WRONGSEC = 10016,
 NFSERR_CLID_INUSE = 10017,
 NFSERR_RESOURCE = 10018,
 NFSERR_MOVED = 10019,
 NFSERR_NOFILEHANDLE = 10020,
 NFSERR_MINOR_VERS_MISMATCH = 10021,
 NFSERR_STALE_CLIENTID = 10022,
 NFSERR_STALE_STATEID = 10023,
 NFSERR_OLD_STATEID = 10024,
 NFSERR_BAD_STATEID = 10025,
 NFSERR_BAD_SEQID = 10026,
 NFSERR_NOT_SAME = 10027,
 NFSERR_LOCK_RANGE = 10028,
 NFSERR_SYMLINK = 10029,
 NFSERR_RESTOREFH = 10030,
 NFSERR_LEASE_MOVED = 10031,
 NFSERR_ATTRNOTSUPP = 10032,
 NFSERR_NO_GRACE = 10033,
 NFSERR_RECLAIM_BAD = 10034,
 NFSERR_RECLAIM_CONFLICT = 10035,
 NFSERR_BAD_XDR = 10036,
 NFSERR_LOCKS_HELD = 10037,
 NFSERR_OPENMODE = 10038,
 NFSERR_BADOWNER = 10039,
 NFSERR_BADCHAR = 10040,
 NFSERR_BADNAME = 10041,
 NFSERR_BAD_RANGE = 10042,
 NFSERR_LOCK_NOTSUPP = 10043,
 NFSERR_OP_ILLEGAL = 10044,
 NFSERR_DEADLOCK = 10045,
 NFSERR_FILE_OPEN = 10046,
 NFSERR_ADMIN_REVOKED = 10047,
 NFSERR_CB_PATH_DOWN = 10048,
 NFSERR_REPLAY_ME = 10049
};



enum nfs_ftype {
 NFNON = 0,
 NFREG = 1,
 NFDIR = 2,
 NFBLK = 3,
 NFCHR = 4,
 NFLNK = 5,
 NFSOCK = 6,
 NFBAD = 7,
 NFFIFO = 8
};


# 1 "include/linux/sunrpc/msg_prot.h" 1
# 18 "include/linux/sunrpc/msg_prot.h"
typedef u32 rpc_authflavor_t;

enum rpc_auth_flavors {
 RPC_AUTH_NULL = 0,
 RPC_AUTH_UNIX = 1,
 RPC_AUTH_SHORT = 2,
 RPC_AUTH_DES = 3,
 RPC_AUTH_KRB = 4,
 RPC_AUTH_GSS = 6,
 RPC_AUTH_MAXFLAVOR = 8,

 RPC_AUTH_GSS_KRB5 = 390003,
 RPC_AUTH_GSS_KRB5I = 390004,
 RPC_AUTH_GSS_KRB5P = 390005,
 RPC_AUTH_GSS_LKEY = 390006,
 RPC_AUTH_GSS_LKEYI = 390007,
 RPC_AUTH_GSS_LKEYP = 390008,
 RPC_AUTH_GSS_SPKM = 390009,
 RPC_AUTH_GSS_SPKMI = 390010,
 RPC_AUTH_GSS_SPKMP = 390011,
};




enum rpc_msg_type {
 RPC_CALL = 0,
 RPC_REPLY = 1
};

enum rpc_reply_stat {
 RPC_MSG_ACCEPTED = 0,
 RPC_MSG_DENIED = 1
};

enum rpc_accept_stat {
 RPC_SUCCESS = 0,
 RPC_PROG_UNAVAIL = 1,
 RPC_PROG_MISMATCH = 2,
 RPC_PROC_UNAVAIL = 3,
 RPC_GARBAGE_ARGS = 4,
 RPC_SYSTEM_ERR = 5,

 RPC_DROP_REPLY = 60000,
};

enum rpc_reject_stat {
 RPC_MISMATCH = 0,
 RPC_AUTH_ERROR = 1
};

enum rpc_auth_stat {
 RPC_AUTH_OK = 0,
 RPC_AUTH_BADCRED = 1,
 RPC_AUTH_REJECTEDCRED = 2,
 RPC_AUTH_BADVERF = 3,
 RPC_AUTH_REJECTEDVERF = 4,
 RPC_AUTH_TOOWEAK = 5,

 RPCSEC_GSS_CREDPROBLEM = 13,
 RPCSEC_GSS_CTXPROBLEM = 14
};
# 102 "include/linux/sunrpc/msg_prot.h"
typedef __be32 rpc_fraghdr;
# 131 "include/linux/nfs.h" 2






struct nfs_fh {
 unsigned short size;
 unsigned char data[128];
};





static inline __attribute__((always_inline)) int nfs_compare_fh(const struct nfs_fh *a, const struct nfs_fh *b)
{
 return a->size != b->size || __builtin_memcmp(a->data, b->data, a->size) != 0;
}

static inline __attribute__((always_inline)) void nfs_copy_fh(struct nfs_fh *target, const struct nfs_fh *source)
{
 target->size = source->size;
 (__builtin_constant_p(source->size) ? __constant_memcpy((target->data),(source->data),(source->size)) : __memcpy((target->data),(source->data),(source->size)));
}
# 165 "include/linux/nfs.h"
enum nfs3_stable_how {
 NFS_UNSTABLE = 0,
 NFS_DATA_SYNC = 1,
 NFS_FILE_SYNC = 2
};
# 7 "include/linux/nfs_fs_i.h" 2

struct nlm_lockowner;




struct nfs_lock_info {
 u32 state;
 struct nlm_lockowner *owner;
 struct list_head list;
};

struct nfs4_lock_state;
struct nfs4_lock_info {
 struct nfs4_lock_state *owner;
};
# 801 "include/linux/fs.h" 2

struct file_lock {
 struct file_lock *fl_next;
 struct list_head fl_link;
 struct list_head fl_block;
 fl_owner_t fl_owner;
 unsigned int fl_pid;
 wait_queue_head_t fl_wait;
 struct file *fl_file;
 unsigned char fl_flags;
 unsigned char fl_type;
 loff_t fl_start;
 loff_t fl_end;

 struct fasync_struct * fl_fasync;
 unsigned long fl_break_time;

 struct file_lock_operations *fl_ops;
 struct lock_manager_operations *fl_lmops;
 union {
  struct nfs_lock_info nfs_fl;
  struct nfs4_lock_info nfs4_fl;
 } fl_u;
};
# 833 "include/linux/fs.h"
# 1 "include/linux/fcntl.h" 1



# 1 "include/asm/fcntl.h" 1
# 1 "include/asm-generic/fcntl.h" 1
# 114 "include/asm-generic/fcntl.h"
struct flock {
 short l_type;
 short l_whence;
 off_t l_start;
 off_t l_len;
 pid_t l_pid;

};
# 137 "include/asm-generic/fcntl.h"
struct flock64 {
 short l_type;
 short l_whence;
 loff_t l_start;
 loff_t l_len;
 pid_t l_pid;

};
# 1 "include/asm/fcntl.h" 2
# 5 "include/linux/fcntl.h" 2
# 834 "include/linux/fs.h" 2

extern int fcntl_getlk(struct file *, struct flock *);
extern int fcntl_setlk(unsigned int, struct file *, unsigned int,
   struct flock *);


extern int fcntl_getlk64(struct file *, struct flock64 *);
extern int fcntl_setlk64(unsigned int, struct file *, unsigned int,
   struct flock64 *);


extern void send_sigio(struct fown_struct *fown, int fd, int band);
extern int fcntl_setlease(unsigned int fd, struct file *filp, long arg);
extern int fcntl_getlease(struct file *filp);


extern int do_sync_mapping_range(struct address_space *mapping, loff_t offset,
   loff_t endbyte, unsigned int flags);


extern void locks_init_lock(struct file_lock *);
extern void locks_copy_lock(struct file_lock *, struct file_lock *);
extern void locks_remove_posix(struct file *, fl_owner_t);
extern void locks_remove_flock(struct file *);
extern int posix_test_lock(struct file *, struct file_lock *);
extern int posix_lock_file(struct file *, struct file_lock *, struct file_lock *);
extern int posix_lock_file_wait(struct file *, struct file_lock *);
extern int posix_unblock_lock(struct file *, struct file_lock *);
extern int vfs_test_lock(struct file *, struct file_lock *);
extern int vfs_lock_file(struct file *, unsigned int, struct file_lock *, struct file_lock *);
extern int vfs_cancel_lock(struct file *filp, struct file_lock *fl);
extern int flock_lock_file_wait(struct file *filp, struct file_lock *fl);
extern int __break_lease(struct inode *inode, unsigned int flags);
extern void lease_get_mtime(struct inode *, struct timespec *time);
extern int setlease(struct file *, long, struct file_lock **);
extern int lease_modify(struct file_lock **, int);
extern int lock_may_read(struct inode *, loff_t start, unsigned long count);
extern int lock_may_write(struct inode *, loff_t start, unsigned long count);

struct fasync_struct {
 int magic;
 int fa_fd;
 struct fasync_struct *fa_next;
 struct file *fa_file;
};




extern int fasync_helper(int, struct file *, int, struct fasync_struct **);

extern void kill_fasync(struct fasync_struct **, int, int);

extern void __kill_fasync(struct fasync_struct *, int, int);

extern int __f_setown(struct file *filp, struct pid *, enum pid_type, int force);
extern int f_setown(struct file *filp, unsigned long arg, int force);
extern void f_delown(struct file *filp);
extern pid_t f_getown(struct file *filp);
extern int send_sigurg(struct fown_struct *fown);
# 903 "include/linux/fs.h"
extern struct list_head super_blocks;
extern spinlock_t sb_lock;



struct super_block {
 struct list_head s_list;
 dev_t s_dev;
 unsigned long s_blocksize;
 unsigned char s_blocksize_bits;
 unsigned char s_dirt;
 unsigned long long s_maxbytes;
 struct file_system_type *s_type;
 const struct super_operations *s_op;
 struct dquot_operations *dq_op;
  struct quotactl_ops *s_qcop;
 struct export_operations *s_export_op;
 unsigned long s_flags;
 unsigned long s_magic;
 struct dentry *s_root;
 struct rw_semaphore s_umount;
 struct mutex s_lock;
 int s_count;
 int s_syncing;
 int s_need_sync_fs;
 atomic_t s_active;

 void *s_security;

 struct xattr_handler **s_xattr;

 struct list_head s_inodes;
 struct list_head s_dirty;
 struct list_head s_io;
 struct hlist_head s_anon;
 struct list_head s_files;

 struct block_device *s_bdev;
 struct mtd_info *s_mtd;
 struct list_head s_instances;
 struct quota_info s_dquot;

 int s_frozen;
 wait_queue_head_t s_wait_unfrozen;

 char s_id[32];

 void *s_fs_info;





 struct mutex s_vfs_rename_mutex;



 u32 s_time_gran;





 char *s_subtype;
};

extern struct timespec current_fs_time(struct super_block *sb);




enum {
 SB_UNFROZEN = 0,
 SB_FREEZE_WRITE = 1,
 SB_FREEZE_TRANS = 2,
};
# 988 "include/linux/fs.h"
extern void lock_super(struct super_block *);
extern void unlock_super(struct super_block *);




extern int vfs_permission(struct nameidata *, int);
extern int vfs_create(struct inode *, struct dentry *, int, struct nameidata *);
extern int vfs_mkdir(struct inode *, struct dentry *, int);
extern int vfs_mknod(struct inode *, struct dentry *, int, dev_t);
extern int vfs_symlink(struct inode *, struct dentry *, const char *, int);
extern int vfs_link(struct dentry *, struct inode *, struct dentry *);
extern int vfs_rmdir(struct inode *, struct dentry *);
extern int vfs_unlink(struct inode *, struct dentry *);
extern int vfs_rename(struct inode *, struct dentry *, struct inode *, struct dentry *);




extern void dentry_unhash(struct dentry *dentry);




extern int file_permission(struct file *, int);
# 1033 "include/linux/fs.h"
int generic_osync_inode(struct inode *, struct address_space *, int);







typedef int (*filldir_t)(void *, const char *, int, loff_t, u64, unsigned);

struct block_device_operations {
 int (*open) (struct inode *, struct file *);
 int (*release) (struct inode *, struct file *);
 int (*ioctl) (struct inode *, struct file *, unsigned, unsigned long);
 long (*unlocked_ioctl) (struct file *, unsigned, unsigned long);
 long (*compat_ioctl) (struct file *, unsigned, unsigned long);
 int (*direct_access) (struct block_device *, sector_t, unsigned long *);
 int (*media_changed) (struct gendisk *);
 int (*revalidate_disk) (struct gendisk *);
 int (*getgeo)(struct block_device *, struct hd_geometry *);
 struct module *owner;
};
# 1065 "include/linux/fs.h"
typedef struct {
 size_t written;
 size_t count;
 union {
  char * buf;
  void *data;
 } arg;
 int error;
} read_descriptor_t;

typedef int (*read_actor_t)(read_descriptor_t *, struct page *, unsigned long, unsigned long);
# 1088 "include/linux/fs.h"
struct file_operations {
 struct module *owner;
 loff_t (*llseek) (struct file *, loff_t, int);
 ssize_t (*read) (struct file *, char *, size_t, loff_t *);
 ssize_t (*write) (struct file *, const char *, size_t, loff_t *);
 ssize_t (*aio_read) (struct kiocb *, const struct iovec *, unsigned long, loff_t);
 ssize_t (*aio_write) (struct kiocb *, const struct iovec *, unsigned long, loff_t);
 int (*readdir) (struct file *, void *, filldir_t);
 unsigned int (*poll) (struct file *, struct poll_table_struct *);
 int (*ioctl) (struct inode *, struct file *, unsigned int, unsigned long);
 long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
 long (*compat_ioctl) (struct file *, unsigned int, unsigned long);
 int (*mmap) (struct file *, struct vm_area_struct *);
 int (*open) (struct inode *, struct file *);
 int (*flush) (struct file *, fl_owner_t id);
 int (*release) (struct inode *, struct file *);
 int (*fsync) (struct file *, struct dentry *, int datasync);
 int (*aio_fsync) (struct kiocb *, int datasync);
 int (*fasync) (int, struct file *, int);
 int (*lock) (struct file *, int, struct file_lock *);
 ssize_t (*sendpage) (struct file *, struct page *, int, size_t, loff_t *, int);
 unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
 int (*check_flags)(int);
 int (*dir_notify)(struct file *filp, unsigned long arg);
 int (*flock) (struct file *, int, struct file_lock *);
 ssize_t (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int);
 ssize_t (*splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
};

struct inode_operations {
 int (*create) (struct inode *,struct dentry *,int, struct nameidata *);
 struct dentry * (*lookup) (struct inode *,struct dentry *, struct nameidata *);
 int (*link) (struct dentry *,struct inode *,struct dentry *);
 int (*unlink) (struct inode *,struct dentry *);
 int (*symlink) (struct inode *,struct dentry *,const char *);
 int (*mkdir) (struct inode *,struct dentry *,int);
 int (*rmdir) (struct inode *,struct dentry *);
 int (*mknod) (struct inode *,struct dentry *,int,dev_t);
 int (*rename) (struct inode *, struct dentry *,
   struct inode *, struct dentry *);
 int (*readlink) (struct dentry *, char *,int);
 void * (*follow_link) (struct dentry *, struct nameidata *);
 void (*put_link) (struct dentry *, struct nameidata *, void *);
 void (*truncate) (struct inode *);
 int (*permission) (struct inode *, int, struct nameidata *);
 int (*setattr) (struct dentry *, struct iattr *);
 int (*getattr) (struct vfsmount *mnt, struct dentry *, struct kstat *);
 int (*setxattr) (struct dentry *, const char *,const void *,size_t,int);
 ssize_t (*getxattr) (struct dentry *, const char *, void *, size_t);
 ssize_t (*listxattr) (struct dentry *, char *, size_t);
 int (*removexattr) (struct dentry *, const char *);
 void (*truncate_range)(struct inode *, loff_t, loff_t);
};

struct seq_file;

ssize_t rw_copy_check_uvector(int type, const struct iovec * uvector,
    unsigned long nr_segs, unsigned long fast_segs,
    struct iovec *fast_pointer,
    struct iovec **ret_pointer);

extern ssize_t vfs_read(struct file *, char *, size_t, loff_t *);
extern ssize_t vfs_write(struct file *, const char *, size_t, loff_t *);
extern ssize_t vfs_readv(struct file *, const struct iovec *,
  unsigned long, loff_t *);
extern ssize_t vfs_writev(struct file *, const struct iovec *,
  unsigned long, loff_t *);





struct super_operations {
    struct inode *(*alloc_inode)(struct super_block *sb);
 void (*destroy_inode)(struct inode *);

 void (*read_inode) (struct inode *);

    void (*dirty_inode) (struct inode *);
 int (*write_inode) (struct inode *, int);
 void (*put_inode) (struct inode *);
 void (*drop_inode) (struct inode *);
 void (*delete_inode) (struct inode *);
 void (*put_super) (struct super_block *);
 void (*write_super) (struct super_block *);
 int (*sync_fs)(struct super_block *sb, int wait);
 void (*write_super_lockfs) (struct super_block *);
 void (*unlockfs) (struct super_block *);
 int (*statfs) (struct dentry *, struct kstatfs *);
 int (*remount_fs) (struct super_block *, int *, char *);
 void (*clear_inode) (struct inode *);
 void (*umount_begin) (struct vfsmount *, int);

 int (*show_options)(struct seq_file *, struct vfsmount *);
 int (*show_stats)(struct seq_file *, struct vfsmount *);

 ssize_t (*quota_read)(struct super_block *, int, char *, size_t, loff_t);
 ssize_t (*quota_write)(struct super_block *, int, const char *, size_t, loff_t);

};
# 1202 "include/linux/fs.h"
extern void __mark_inode_dirty(struct inode *, int);
static inline __attribute__((always_inline)) void mark_inode_dirty(struct inode *inode)
{
 __mark_inode_dirty(inode, (1 | 2 | 4));
}

static inline __attribute__((always_inline)) void mark_inode_dirty_sync(struct inode *inode)
{
 __mark_inode_dirty(inode, 1);
}
# 1221 "include/linux/fs.h"
static inline __attribute__((always_inline)) void inc_nlink(struct inode *inode)
{
 inode->i_nlink++;
}

static inline __attribute__((always_inline)) void inode_inc_link_count(struct inode *inode)
{
 inc_nlink(inode);
 mark_inode_dirty(inode);
}
# 1243 "include/linux/fs.h"
static inline __attribute__((always_inline)) void drop_nlink(struct inode *inode)
{
 inode->i_nlink--;
}
# 1256 "include/linux/fs.h"
static inline __attribute__((always_inline)) void clear_nlink(struct inode *inode)
{
 inode->i_nlink = 0;
}

static inline __attribute__((always_inline)) void inode_dec_link_count(struct inode *inode)
{
 drop_nlink(inode);
 mark_inode_dirty(inode);
}

extern void touch_atime(struct vfsmount *mnt, struct dentry *dentry);
static inline __attribute__((always_inline)) void file_accessed(struct file *file)
{
 if (!(file->f_flags & 01000000))
  touch_atime(file->f_path.mnt, file->f_path.dentry);
}

int sync_inode(struct inode *inode, struct writeback_control *wbc);
# 1362 "include/linux/fs.h"
struct export_operations {
 struct dentry *(*decode_fh)(struct super_block *sb, __u32 *fh, int fh_len, int fh_type,
    int (*acceptable)(void *context, struct dentry *de),
    void *context);
 int (*encode_fh)(struct dentry *de, __u32 *fh, int *max_len,
    int connectable);


 int (*get_name)(struct dentry *parent, char *name,
   struct dentry *child);
 struct dentry * (*get_parent)(struct dentry *child);
 struct dentry * (*get_dentry)(struct super_block *sb, void *inump);


 struct dentry * (*find_exported_dentry)(
  struct super_block *sb, void *obj, void *parent,
  int (*acceptable)(void *context, struct dentry *de),
  void *context);


};

extern struct dentry *
find_exported_dentry(struct super_block *sb, void *obj, void *parent,
       int (*acceptable)(void *context, struct dentry *de),
       void *context);

struct file_system_type {
 const char *name;
 int fs_flags;
 int (*get_sb) (struct file_system_type *, int,
         const char *, void *, struct vfsmount *);
 void (*kill_sb) (struct super_block *);
 struct module *owner;
 struct file_system_type * next;
 struct list_head fs_supers;
 struct lock_class_key s_lock_key;
 struct lock_class_key s_umount_key;
};

extern int get_sb_bdev(struct file_system_type *fs_type,
 int flags, const char *dev_name, void *data,
 int (*fill_super)(struct super_block *, void *, int),
 struct vfsmount *mnt);
extern int get_sb_single(struct file_system_type *fs_type,
 int flags, void *data,
 int (*fill_super)(struct super_block *, void *, int),
 struct vfsmount *mnt);
extern int get_sb_nodev(struct file_system_type *fs_type,
 int flags, void *data,
 int (*fill_super)(struct super_block *, void *, int),
 struct vfsmount *mnt);
void generic_shutdown_super(struct super_block *sb);
void kill_block_super(struct super_block *sb);
void kill_anon_super(struct super_block *sb);
void kill_litter_super(struct super_block *sb);
void deactivate_super(struct super_block *sb);
int set_anon_super(struct super_block *s, void *data);
struct super_block *sget(struct file_system_type *type,
   int (*test)(struct super_block *,void *),
   int (*set)(struct super_block *,void *),
   void *data);
extern int get_sb_pseudo(struct file_system_type *, char *,
 const struct super_operations *ops, unsigned long,
 struct vfsmount *mnt);
extern int simple_set_mnt(struct vfsmount *mnt, struct super_block *sb);
int __put_super(struct super_block *sb);
int __put_super_and_need_restart(struct super_block *sb);
void unnamed_dev_init(void);







extern int register_filesystem(struct file_system_type *);
extern int unregister_filesystem(struct file_system_type *);
extern struct vfsmount *kern_mount(struct file_system_type *);
extern int may_umount_tree(struct vfsmount *);
extern int may_umount(struct vfsmount *);
extern void umount_tree(struct vfsmount *, int, struct list_head *);
extern void release_mounts(struct list_head *);
extern long do_mount(char *, char *, char *, unsigned long, void *);
extern struct vfsmount *copy_tree(struct vfsmount *, struct dentry *, int);
extern void mnt_set_mountpoint(struct vfsmount *, struct dentry *,
      struct vfsmount *);

extern int vfs_statfs(struct dentry *, struct kstatfs *);


extern struct kset fs_subsys;




extern int locks_mandatory_locked(struct inode *);
extern int locks_mandatory_area(int, struct inode *, struct file *, loff_t, size_t);
# 1468 "include/linux/fs.h"
static inline __attribute__((always_inline)) int locks_verify_locked(struct inode *inode)
{
 if ((((inode)->i_sb->s_flags & (64)) && ((inode)->i_mode & (0002000 | 00010)) == 0002000))
  return locks_mandatory_locked(inode);
 return 0;
}

extern int rw_verify_area(int, struct file *, loff_t *, size_t);

static inline __attribute__((always_inline)) int locks_verify_truncate(struct inode *inode,
        struct file *filp,
        loff_t size)
{
 if (inode->i_flock && (((inode)->i_sb->s_flags & (64)) && ((inode)->i_mode & (0002000 | 00010)) == 0002000))
  return locks_mandatory_area(
   2, inode, filp,
   size < inode->i_size ? size : inode->i_size,
   (size < inode->i_size ? inode->i_size - size
    : size - inode->i_size)
  );
 return 0;
}

static inline __attribute__((always_inline)) int break_lease(struct inode *inode, unsigned int mode)
{
 if (inode->i_flock)
  return __break_lease(inode, mode);
 return 0;
}



extern int do_truncate(struct dentry *, loff_t start, unsigned int time_attrs,
         struct file *filp);
extern long do_sys_open(int fdf, const char *filename, int flags,
   int mode);
extern struct file *filp_open(const char *, int, int);
extern struct file * dentry_open(struct dentry *, struct vfsmount *, int);
extern int filp_close(struct file *, fl_owner_t id);
extern char * getname(const char *);


extern void __attribute__ ((__section__ (".init.text"))) vfs_caches_init_early(void);
extern void __attribute__ ((__section__ (".init.text"))) vfs_caches_init(unsigned long);

extern struct kmem_cache *names_cachep;






extern void putname(const char *name);



extern int register_blkdev(unsigned int, const char *);
extern int unregister_blkdev(unsigned int, const char *);
extern struct block_device *bdget(dev_t);
extern void bd_set_size(struct block_device *, loff_t size);
extern void bd_forget(struct inode *inode);
extern void bdput(struct block_device *);
extern struct block_device *open_by_devnum(dev_t, unsigned);
extern const struct address_space_operations def_blk_aops;



extern const struct file_operations def_blk_fops;
extern const struct file_operations def_chr_fops;
extern const struct file_operations bad_sock_fops;
extern const struct file_operations def_fifo_fops;

extern int ioctl_by_bdev(struct block_device *, unsigned, unsigned long);
extern int blkdev_ioctl(struct inode *, struct file *, unsigned, unsigned long);
extern int blkdev_driver_ioctl(struct inode *inode, struct file *file,
          struct gendisk *disk, unsigned cmd,
          unsigned long arg);
extern long compat_blkdev_ioctl(struct file *, unsigned, unsigned long);
extern int blkdev_get(struct block_device *, mode_t, unsigned);
extern int blkdev_put(struct block_device *);
extern int bd_claim(struct block_device *, void *);
extern void bd_release(struct block_device *);

extern int bd_claim_by_disk(struct block_device *, void *, struct gendisk *);
extern void bd_release_from_disk(struct block_device *, struct gendisk *);
# 1561 "include/linux/fs.h"
extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);
extern int register_chrdev_region(dev_t, unsigned, const char *);
extern int register_chrdev(unsigned int, const char *,
      const struct file_operations *);
extern int unregister_chrdev(unsigned int, const char *);
extern void unregister_chrdev_region(dev_t, unsigned);
extern int chrdev_open(struct inode *, struct file *);
extern void chrdev_show(struct seq_file *,off_t);






extern const char *__bdevname(dev_t, char *buffer);
extern const char *bdevname(struct block_device *bdev, char *buffer);
extern struct block_device *lookup_bdev(const char *);
extern struct block_device *open_bdev_excl(const char *, int, void *);
extern void close_bdev_excl(struct block_device *);
extern void blkdev_show(struct seq_file *,off_t);




extern void init_special_inode(struct inode *, umode_t, dev_t);


extern void make_bad_inode(struct inode *);
extern int is_bad_inode(struct inode *);

extern const struct file_operations read_fifo_fops;
extern const struct file_operations write_fifo_fops;
extern const struct file_operations rdwr_fifo_fops;

extern int fs_may_remount_ro(struct super_block *);
# 1608 "include/linux/fs.h"
extern int check_disk_change(struct block_device *);
extern int __invalidate_device(struct block_device *);
extern int invalidate_partition(struct gendisk *, int);

extern int invalidate_inodes(struct super_block *);
unsigned long invalidate_mapping_pages(struct address_space *mapping,
     unsigned long start, unsigned long end);

static inline __attribute__((always_inline)) unsigned long __attribute__((deprecated))
invalidate_inode_pages(struct address_space *mapping)
{
 return invalidate_mapping_pages(mapping, 0, ~0UL);
}

static inline __attribute__((always_inline)) void invalidate_remote_inode(struct inode *inode)
{
 if ((((inode->i_mode) & 00170000) == 0100000) || (((inode->i_mode) & 00170000) == 0040000) ||
     (((inode->i_mode) & 00170000) == 0120000))
  invalidate_mapping_pages(inode->i_mapping, 0, -1);
}
extern int invalidate_inode_pages2(struct address_space *mapping);
extern int invalidate_inode_pages2_range(struct address_space *mapping,
      unsigned long start, unsigned long end);
extern int write_inode_now(struct inode *, int);
extern int filemap_fdatawrite(struct address_space *);
extern int filemap_flush(struct address_space *);
extern int filemap_fdatawait(struct address_space *);
extern int filemap_write_and_wait(struct address_space *mapping);
extern int filemap_write_and_wait_range(struct address_space *mapping,
            loff_t lstart, loff_t lend);
extern int wait_on_page_writeback_range(struct address_space *mapping,
    unsigned long start, unsigned long end);
extern int __filemap_fdatawrite_range(struct address_space *mapping,
    loff_t start, loff_t end, int sync_mode);

extern long do_fsync(struct file *file, int datasync);
extern void sync_supers(void);
extern void sync_filesystems(int wait);
extern void __fsync_super(struct super_block *sb);
extern void emergency_sync(void);
extern void emergency_remount(void);
extern int do_remount_sb(struct super_block *sb, int flags,
    void *data, int force);

extern sector_t bmap(struct inode *, sector_t);

extern int notify_change(struct dentry *, struct iattr *);
extern int permission(struct inode *, int, struct nameidata *);
extern int generic_permission(struct inode *, int,
  int (*check_acl)(struct inode *, int));

extern int get_write_access(struct inode *);
extern int deny_write_access(struct file *);
static inline __attribute__((always_inline)) void put_write_access(struct inode * inode)
{
 atomic_dec(&inode->i_writecount);
}
static inline __attribute__((always_inline)) void allow_write_access(struct file *file)
{
 if (file)
  atomic_inc(&file->f_path.dentry->d_inode->i_writecount);
}
extern int do_pipe(int *);
extern struct file *create_read_pipe(struct file *f);
extern struct file *create_write_pipe(void);
extern void free_write_pipe(struct file *);

extern int open_namei(int dfd, const char *, int, int, struct nameidata *);
extern int may_open(struct nameidata *, int, int);

extern int kernel_read(struct file *, unsigned long, char *, unsigned long);
extern struct file * open_exec(const char *);


extern int is_subdir(struct dentry *, struct dentry *);
extern ino_t find_inode_number(struct dentry *, struct qstr *);

# 1 "include/linux/err.h" 1
# 22 "include/linux/err.h"
static inline __attribute__((always_inline)) void *ERR_PTR(long error)
{
 return (void *) error;
}

static inline __attribute__((always_inline)) long PTR_ERR(const void *ptr)
{
 return (long) ptr;
}

static inline __attribute__((always_inline)) long IS_ERR(const void *ptr)
{
 return __builtin_expect(!!(((unsigned long)ptr) >= (unsigned long)-4095), 0);
}
# 1686 "include/linux/fs.h" 2


extern loff_t default_llseek(struct file *file, loff_t offset, int origin);

extern loff_t vfs_llseek(struct file *file, loff_t offset, int origin);

extern void inode_init_once(struct inode *);
extern void iput(struct inode *);
extern struct inode * igrab(struct inode *);
extern ino_t iunique(struct super_block *, ino_t);
extern int inode_needs_sync(struct inode *inode);
extern void generic_delete_inode(struct inode *inode);
extern void generic_drop_inode(struct inode *inode);

extern struct inode *ilookup5_nowait(struct super_block *sb,
  unsigned long hashval, int (*test)(struct inode *, void *),
  void *data);
extern struct inode *ilookup5(struct super_block *sb, unsigned long hashval,
  int (*test)(struct inode *, void *), void *data);
extern struct inode *ilookup(struct super_block *sb, unsigned long ino);

extern struct inode * iget5_locked(struct super_block *, unsigned long, int (*test)(struct inode *, void *), int (*set)(struct inode *, void *), void *);
extern struct inode * iget_locked(struct super_block *, unsigned long);
extern void unlock_new_inode(struct inode *);

static inline __attribute__((always_inline)) struct inode *iget(struct super_block *sb, unsigned long ino)
{
 struct inode *inode = iget_locked(sb, ino);

 if (inode && (inode->i_state & 64)) {
  sb->s_op->read_inode(inode);
  unlock_new_inode(inode);
 }

 return inode;
}

extern void __iget(struct inode * inode);
extern void clear_inode(struct inode *);
extern void destroy_inode(struct inode *);
extern struct inode *new_inode(struct super_block *);
extern int __remove_suid(struct dentry *, int);
extern int should_remove_suid(struct dentry *);
extern int remove_suid(struct dentry *);

extern void __insert_inode_hash(struct inode *, unsigned long hashval);
extern void remove_inode_hash(struct inode *);
static inline __attribute__((always_inline)) void insert_inode_hash(struct inode *inode) {
 __insert_inode_hash(inode, inode->i_ino);
}

extern struct file * get_empty_filp(void);
extern void file_move(struct file *f, struct list_head *list);
extern void file_kill(struct file *f);

struct bio;
extern void submit_bio(int, struct bio *);
extern int bdev_read_only(struct block_device *);

extern int set_blocksize(struct block_device *, int);
extern int sb_set_blocksize(struct super_block *, int);
extern int sb_min_blocksize(struct super_block *, int);

extern int generic_file_mmap(struct file *, struct vm_area_struct *);
extern int generic_file_readonly_mmap(struct file *, struct vm_area_struct *);
extern int file_read_actor(read_descriptor_t * desc, struct page *page, unsigned long offset, unsigned long size);
extern int file_send_actor(read_descriptor_t * desc, struct page *page, unsigned long offset, unsigned long size);
int generic_write_checks(struct file *file, loff_t *pos, size_t *count, int isblk);
extern ssize_t generic_file_aio_read(struct kiocb *, const struct iovec *, unsigned long, loff_t);
extern ssize_t generic_file_aio_write(struct kiocb *, const struct iovec *, unsigned long, loff_t);
extern ssize_t generic_file_aio_write_nolock(struct kiocb *, const struct iovec *,
  unsigned long, loff_t);
extern ssize_t generic_file_direct_write(struct kiocb *, const struct iovec *,
  unsigned long *, loff_t, loff_t *, size_t, size_t);
extern ssize_t generic_file_buffered_write(struct kiocb *, const struct iovec *,
  unsigned long, loff_t, loff_t *, size_t, ssize_t);
extern ssize_t do_sync_read(struct file *filp, char *buf, size_t len, loff_t *ppos);
extern ssize_t do_sync_write(struct file *filp, const char *buf, size_t len, loff_t *ppos);
extern void do_generic_mapping_read(struct address_space *mapping,
        struct file_ra_state *, struct file *,
        loff_t *, read_descriptor_t *, read_actor_t);
extern int generic_segment_checks(const struct iovec *iov,
  unsigned long *nr_segs, size_t *count, int access_flags);


extern ssize_t generic_file_splice_read(struct file *, loff_t *,
  struct pipe_inode_info *, size_t, unsigned int);
extern ssize_t generic_file_splice_write(struct pipe_inode_info *,
  struct file *, loff_t *, size_t, unsigned int);
extern ssize_t generic_file_splice_write_nolock(struct pipe_inode_info *,
  struct file *, loff_t *, size_t, unsigned int);
extern ssize_t generic_splice_sendpage(struct pipe_inode_info *pipe,
  struct file *out, loff_t *, size_t len, unsigned int flags);
extern long do_splice_direct(struct file *in, loff_t *ppos, struct file *out,
  size_t len, unsigned int flags);

extern void
file_ra_state_init(struct file_ra_state *ra, struct address_space *mapping);
extern loff_t no_llseek(struct file *file, loff_t offset, int origin);
extern loff_t generic_file_llseek(struct file *file, loff_t offset, int origin);
extern loff_t remote_llseek(struct file *file, loff_t offset, int origin);
extern int generic_file_open(struct inode * inode, struct file * filp);
extern int nonseekable_open(struct inode * inode, struct file * filp);


extern ssize_t xip_file_read(struct file *filp, char *buf, size_t len,
        loff_t *ppos);
extern int xip_file_mmap(struct file * file, struct vm_area_struct * vma);
extern ssize_t xip_file_write(struct file *filp, const char *buf,
         size_t len, loff_t *ppos);
extern int xip_truncate_page(struct address_space *mapping, loff_t from);







static inline __attribute__((always_inline)) void do_generic_file_read(struct file * filp, loff_t *ppos,
     read_descriptor_t * desc,
     read_actor_t actor)
{
 do_generic_mapping_read(filp->f_mapping,
    &filp->f_ra,
    filp,
    ppos,
    desc,
    actor);
}


ssize_t __blockdev_direct_IO(int rw, struct kiocb *iocb, struct inode *inode,
 struct block_device *bdev, const struct iovec *iov, loff_t offset,
 unsigned long nr_segs, get_block_t get_block, dio_iodone_t end_io,
 int lock_type);

enum {
 DIO_LOCKING = 1,
 DIO_NO_LOCKING,
 DIO_OWN_LOCKING,
};

static inline __attribute__((always_inline)) ssize_t blockdev_direct_IO(int rw, struct kiocb *iocb,
 struct inode *inode, struct block_device *bdev, const struct iovec *iov,
 loff_t offset, unsigned long nr_segs, get_block_t get_block,
 dio_iodone_t end_io)
{
 return __blockdev_direct_IO(rw, iocb, inode, bdev, iov, offset,
    nr_segs, get_block, end_io, DIO_LOCKING);
}

static inline __attribute__((always_inline)) ssize_t blockdev_direct_IO_no_locking(int rw, struct kiocb *iocb,
 struct inode *inode, struct block_device *bdev, const struct iovec *iov,
 loff_t offset, unsigned long nr_segs, get_block_t get_block,
 dio_iodone_t end_io)
{
 return __blockdev_direct_IO(rw, iocb, inode, bdev, iov, offset,
    nr_segs, get_block, end_io, DIO_NO_LOCKING);
}

static inline __attribute__((always_inline)) ssize_t blockdev_direct_IO_own_locking(int rw, struct kiocb *iocb,
 struct inode *inode, struct block_device *bdev, const struct iovec *iov,
 loff_t offset, unsigned long nr_segs, get_block_t get_block,
 dio_iodone_t end_io)
{
 return __blockdev_direct_IO(rw, iocb, inode, bdev, iov, offset,
    nr_segs, get_block, end_io, DIO_OWN_LOCKING);
}


extern const struct file_operations generic_ro_fops;



extern int vfs_readlink(struct dentry *, char *, int, const char *);
extern int vfs_follow_link(struct nameidata *, const char *);
extern int page_readlink(struct dentry *, char *, int);
extern void *page_follow_link_light(struct dentry *, struct nameidata *);
extern void page_put_link(struct dentry *, struct nameidata *, void *);
extern int __page_symlink(struct inode *inode, const char *symname, int len,
  gfp_t gfp_mask);
extern int page_symlink(struct inode *inode, const char *symname, int len);
extern const struct inode_operations page_symlink_inode_operations;
extern int generic_readlink(struct dentry *, char *, int);
extern void generic_fillattr(struct inode *, struct kstat *);
extern int vfs_getattr(struct vfsmount *, struct dentry *, struct kstat *);
void inode_add_bytes(struct inode *inode, loff_t bytes);
void inode_sub_bytes(struct inode *inode, loff_t bytes);
loff_t inode_get_bytes(struct inode *inode);
void inode_set_bytes(struct inode *inode, loff_t bytes);

extern int vfs_readdir(struct file *, filldir_t, void *);

extern int vfs_stat(char *, struct kstat *);
extern int vfs_lstat(char *, struct kstat *);
extern int vfs_stat_fd(int dfd, char *, struct kstat *);
extern int vfs_lstat_fd(int dfd, char *, struct kstat *);
extern int vfs_fstat(unsigned int, struct kstat *);

extern int vfs_ioctl(struct file *, unsigned int, unsigned int, unsigned long);

extern struct file_system_type *get_fs_type(const char *name);
extern struct super_block *get_super(struct block_device *);
extern struct super_block *user_get_super(dev_t);
extern void drop_super(struct super_block *sb);

extern int dcache_dir_open(struct inode *, struct file *);
extern int dcache_dir_close(struct inode *, struct file *);
extern loff_t dcache_dir_lseek(struct file *, loff_t, int);
extern int dcache_readdir(struct file *, void *, filldir_t);
extern int simple_getattr(struct vfsmount *, struct dentry *, struct kstat *);
extern int simple_statfs(struct dentry *, struct kstatfs *);
extern int simple_link(struct dentry *, struct inode *, struct dentry *);
extern int simple_unlink(struct inode *, struct dentry *);
extern int simple_rmdir(struct inode *, struct dentry *);
extern int simple_rename(struct inode *, struct dentry *, struct inode *, struct dentry *);
extern int simple_sync_file(struct file *, struct dentry *, int);
extern int simple_empty(struct dentry *);
extern int simple_readpage(struct file *file, struct page *page);
extern int simple_prepare_write(struct file *file, struct page *page,
   unsigned offset, unsigned to);
extern int simple_commit_write(struct file *file, struct page *page,
    unsigned offset, unsigned to);

extern struct dentry *simple_lookup(struct inode *, struct dentry *, struct nameidata *);
extern ssize_t generic_read_dir(struct file *, char *, size_t, loff_t *);
extern const struct file_operations simple_dir_operations;
extern const struct inode_operations simple_dir_inode_operations;
struct tree_descr { char *name; const struct file_operations *ops; int mode; };
struct dentry *d_alloc_name(struct dentry *, const char *);
extern int simple_fill_super(struct super_block *, int, struct tree_descr *);
extern int simple_pin_fs(struct file_system_type *, struct vfsmount **mount, int *count);
extern void simple_release_fs(struct vfsmount **mount, int *count);

extern ssize_t simple_read_from_buffer(void *, size_t, loff_t *, const void *, size_t);
# 1929 "include/linux/fs.h"
extern int inode_change_ok(struct inode *, struct iattr *);
extern int __attribute__((warn_unused_result)) inode_setattr(struct inode *, struct iattr *);

extern void file_update_time(struct file *file);

static inline __attribute__((always_inline)) ino_t parent_ino(struct dentry *dentry)
{
 ino_t res;

 _spin_lock(&dentry->d_lock);
 res = dentry->d_parent->d_inode->i_ino;
 _spin_unlock(&dentry->d_lock);
 return res;
}


extern int unshare_files(void);







struct simple_transaction_argresp {
 ssize_t size;
 char data[0];
};



char *simple_transaction_get(struct file *file, const char *buf,
    size_t size);
ssize_t simple_transaction_read(struct file *file, char *buf,
    size_t size, loff_t *pos);
int simple_transaction_release(struct inode *inode, struct file *file);

static inline __attribute__((always_inline)) void simple_transaction_set(struct file *file, size_t n)
{
 struct simple_transaction_argresp *ar = file->private_data;

 do { if (__builtin_expect(!!((n > ((1UL << 12) - sizeof(struct simple_transaction_argresp)))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/fs.h"), "i" (1970), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);





 asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "mfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
 ar->size = n;
}
# 2010 "include/linux/fs.h"
static inline __attribute__((always_inline)) void __attribute__((format(printf, 1, 2)))
__simple_attr_check_format(const char *fmt, ...)
{

}

int simple_attr_open(struct inode *inode, struct file *file,
       u64 (*get)(void *), void (*set)(void *, u64),
       const char *fmt);
int simple_attr_close(struct inode *inode, struct file *file);
ssize_t simple_attr_read(struct file *file, char *buf,
    size_t len, loff_t *ppos);
ssize_t simple_attr_write(struct file *file, const char *buf,
     size_t len, loff_t *ppos);



static inline __attribute__((always_inline)) char *alloc_secdata(void)
{
 return (char *)get_zeroed_page(((( gfp_t)0x10u) | (( gfp_t)0x40u) | (( gfp_t)0x80u)));
}

static inline __attribute__((always_inline)) void free_secdata(void *secdata)
{
 free_pages(((unsigned long)secdata),0);
}
# 159 "drivers/block/floppy.c" 2




# 1 "include/linux/fdreg.h" 1
# 164 "drivers/block/floppy.c" 2

# 1 "include/linux/fd.h" 1
# 13 "include/linux/fd.h"
struct floppy_struct {
 unsigned int size,
   sect,
   head,
   track,
   stretch;




 unsigned char gap,

   rate,







   spec1,
   fmt_gap;
 const char * name;
};
# 66 "include/linux/fd.h"
struct format_descr {
 unsigned int device,head,track;
};
# 81 "include/linux/fd.h"
struct floppy_max_errors {
 unsigned int
   abort,
   read_track,

   reset,
   recal,







   reporting;

};
# 112 "include/linux/fd.h"
typedef char floppy_drive_name[16];







struct floppy_drive_params {
 signed char cmos;




 unsigned long max_dtr;
 unsigned long hlt;
 unsigned long hut;

 unsigned long srt;

 unsigned long spinup;

 unsigned long spindown;
 unsigned char spindown_offset;

 unsigned char select_delay;
 unsigned char rps;
 unsigned char tracks;
 unsigned long timeout;

 unsigned char interleave_sect;


 struct floppy_max_errors max_errors;

 char flags;
# 161 "include/linux/fd.h"
 char read_track;






 short autodetect[8];

 int checkfreq;

 int native_format;
};

enum {
 FD_NEED_TWADDLE_BIT,
 FD_VERIFY_BIT,
 FD_DISK_NEWCHANGE_BIT,

 FD_UNUSED_BIT,
 FD_DISK_CHANGED_BIT,
 FD_DISK_WRITABLE_BIT
};
# 193 "include/linux/fd.h"
struct floppy_drive_struct {
 unsigned long flags;







 unsigned long spinup_date;
 unsigned long select_date;
 unsigned long first_read_date;
 short probed_format;
 short track;
 short maxblock;
 short maxtrack;
 int generation;






 int keep_data;


 int fd_ref;
 int fd_device;
 unsigned long last_checked;


 char *dmabuf;
 int bufblocks;
};
# 236 "include/linux/fd.h"
enum reset_mode {
 FD_RESET_IF_NEEDED,
 FD_RESET_IF_RAWCMD,
 FD_RESET_ALWAYS
};






struct floppy_fdc_state {
 int spec1;
 int spec2;
 int dtr;
 unsigned char version;
 unsigned char dor;
 unsigned long address;
 unsigned int rawcmd:2;
 unsigned int reset:1;
 unsigned int need_configure:1;
 unsigned int perp_mode:2;
 unsigned int has_fifo:1;
 unsigned int driver_version;
# 268 "include/linux/fd.h"
 unsigned char track[4];
# 277 "include/linux/fd.h"
};







struct floppy_write_errors {
# 294 "include/linux/fd.h"
 unsigned int write_errors;



 unsigned long first_error_sector;
 int first_error_generation;
 unsigned long last_error_sector;
 int last_error_generation;

 unsigned int badness;

};
# 319 "include/linux/fd.h"
struct floppy_raw_cmd {
 unsigned int flags;
# 343 "include/linux/fd.h"
 void *data;
 char *kernel_data;
 struct floppy_raw_cmd *next;

 long length;
 long phys_length;
 int buffer_length;

 unsigned char rate;
 unsigned char cmd_count;
 unsigned char cmd[16];
 unsigned char reply_count;
 unsigned char reply[16];
 int track;
 int resultcode;

 int reserved1;
 int reserved2;
};
# 166 "drivers/block/floppy.c" 2
# 1 "include/linux/hdreg.h" 1




# 1 "include/linux/ata.h" 1
# 38 "include/linux/ata.h"
enum {

 ATA_MAX_DEVICES = 2,
 ATA_MAX_PRD = 256,
 ATA_SECT_SIZE = 512,
 ATA_MAX_SECTORS_128 = 128,
 ATA_MAX_SECTORS = 256,
 ATA_MAX_SECTORS_LBA48 = 65535,

 ATA_ID_WORDS = 256,
 ATA_ID_SERNO = 10,
 ATA_ID_FW_REV = 23,
 ATA_ID_PROD = 27,
 ATA_ID_OLD_PIO_MODES = 51,
 ATA_ID_FIELD_VALID = 53,
 ATA_ID_MWDMA_MODES = 63,
 ATA_ID_PIO_MODES = 64,
 ATA_ID_EIDE_DMA_MIN = 65,
 ATA_ID_EIDE_PIO = 67,
 ATA_ID_EIDE_PIO_IORDY = 68,
 ATA_ID_UDMA_MODES = 88,
 ATA_ID_MAJOR_VER = 80,
 ATA_ID_PIO4 = (1 << 1),

 ATA_ID_SERNO_LEN = 20,
 ATA_ID_FW_REV_LEN = 8,
 ATA_ID_PROD_LEN = 40,

 ATA_PCI_CTL_OFS = 2,
 ATA_UDMA0 = (1 << 0),
 ATA_UDMA1 = ATA_UDMA0 | (1 << 1),
 ATA_UDMA2 = ATA_UDMA1 | (1 << 2),
 ATA_UDMA3 = ATA_UDMA2 | (1 << 3),
 ATA_UDMA4 = ATA_UDMA3 | (1 << 4),
 ATA_UDMA5 = ATA_UDMA4 | (1 << 5),
 ATA_UDMA6 = ATA_UDMA5 | (1 << 6),
 ATA_UDMA7 = ATA_UDMA6 | (1 << 7),


 ATA_UDMA_MASK_40C = ATA_UDMA2,


 ATA_PRD_SZ = 8,
 ATA_PRD_TBL_SZ = (ATA_MAX_PRD * ATA_PRD_SZ),
 ATA_PRD_EOT = (1 << 31),

 ATA_DMA_TABLE_OFS = 4,
 ATA_DMA_STATUS = 2,
 ATA_DMA_CMD = 0,
 ATA_DMA_WR = (1 << 3),
 ATA_DMA_START = (1 << 0),
 ATA_DMA_INTR = (1 << 2),
 ATA_DMA_ERR = (1 << 1),
 ATA_DMA_ACTIVE = (1 << 0),


 ATA_HOB = (1 << 7),
 ATA_NIEN = (1 << 1),
 ATA_LBA = (1 << 6),
 ATA_DEV1 = (1 << 4),
 ATA_DEVICE_OBS = (1 << 7) | (1 << 5),
 ATA_DEVCTL_OBS = (1 << 3),
 ATA_BUSY = (1 << 7),
 ATA_DRDY = (1 << 6),
 ATA_DF = (1 << 5),
 ATA_DRQ = (1 << 3),
 ATA_ERR = (1 << 0),
 ATA_SRST = (1 << 2),
 ATA_ICRC = (1 << 7),
 ATA_UNC = (1 << 6),
 ATA_IDNF = (1 << 4),
 ATA_ABORTED = (1 << 2),


 ATA_REG_DATA = 0x00,
 ATA_REG_ERR = 0x01,
 ATA_REG_NSECT = 0x02,
 ATA_REG_LBAL = 0x03,
 ATA_REG_LBAM = 0x04,
 ATA_REG_LBAH = 0x05,
 ATA_REG_DEVICE = 0x06,
 ATA_REG_STATUS = 0x07,

 ATA_REG_FEATURE = ATA_REG_ERR,
 ATA_REG_CMD = ATA_REG_STATUS,
 ATA_REG_BYTEL = ATA_REG_LBAM,
 ATA_REG_BYTEH = ATA_REG_LBAH,
 ATA_REG_DEVSEL = ATA_REG_DEVICE,
 ATA_REG_IRQ = ATA_REG_NSECT,


 ATA_CMD_DEV_RESET = 0x08,
 ATA_CMD_CHK_POWER = 0xE5,
 ATA_CMD_STANDBY = 0xE2,
 ATA_CMD_IDLE = 0xE3,
 ATA_CMD_EDD = 0x90,
 ATA_CMD_FLUSH = 0xE7,
 ATA_CMD_FLUSH_EXT = 0xEA,
 ATA_CMD_ID_ATA = 0xEC,
 ATA_CMD_ID_ATAPI = 0xA1,
 ATA_CMD_READ = 0xC8,
 ATA_CMD_READ_EXT = 0x25,
 ATA_CMD_WRITE = 0xCA,
 ATA_CMD_WRITE_EXT = 0x35,
 ATA_CMD_WRITE_FUA_EXT = 0x3D,
 ATA_CMD_FPDMA_READ = 0x60,
 ATA_CMD_FPDMA_WRITE = 0x61,
 ATA_CMD_PIO_READ = 0x20,
 ATA_CMD_PIO_READ_EXT = 0x24,
 ATA_CMD_PIO_WRITE = 0x30,
 ATA_CMD_PIO_WRITE_EXT = 0x34,
 ATA_CMD_READ_MULTI = 0xC4,
 ATA_CMD_READ_MULTI_EXT = 0x29,
 ATA_CMD_WRITE_MULTI = 0xC5,
 ATA_CMD_WRITE_MULTI_EXT = 0x39,
 ATA_CMD_WRITE_MULTI_FUA_EXT = 0xCE,
 ATA_CMD_SET_FEATURES = 0xEF,
 ATA_CMD_SET_MULTI = 0xC6,
 ATA_CMD_PACKET = 0xA0,
 ATA_CMD_VERIFY = 0x40,
 ATA_CMD_VERIFY_EXT = 0x42,
  ATA_CMD_STANDBYNOW1 = 0xE0,
  ATA_CMD_IDLEIMMEDIATE = 0xE1,
 ATA_CMD_INIT_DEV_PARAMS = 0x91,
 ATA_CMD_READ_NATIVE_MAX = 0xF8,
 ATA_CMD_READ_NATIVE_MAX_EXT = 0x27,
 ATA_CMD_SET_MAX = 0xF9,
 ATA_CMD_SET_MAX_EXT = 0x37,
 ATA_CMD_READ_LOG_EXT = 0x2f,
 ATA_CMD_PMP_READ = 0xE4,
 ATA_CMD_PMP_WRITE = 0xE8,


 ATA_LOG_SATA_NCQ = 0x10,


 ATA_CMD_READ_LONG = 0x22,
 ATA_CMD_READ_LONG_ONCE = 0x23,
 ATA_CMD_WRITE_LONG = 0x32,
 ATA_CMD_WRITE_LONG_ONCE = 0x33,


 SETFEATURES_XFER = 0x03,
 XFER_UDMA_7 = 0x47,
 XFER_UDMA_6 = 0x46,
 XFER_UDMA_5 = 0x45,
 XFER_UDMA_4 = 0x44,
 XFER_UDMA_3 = 0x43,
 XFER_UDMA_2 = 0x42,
 XFER_UDMA_1 = 0x41,
 XFER_UDMA_0 = 0x40,
 XFER_MW_DMA_4 = 0x24,
 XFER_MW_DMA_3 = 0x23,
 XFER_MW_DMA_2 = 0x22,
 XFER_MW_DMA_1 = 0x21,
 XFER_MW_DMA_0 = 0x20,
 XFER_SW_DMA_2 = 0x12,
 XFER_SW_DMA_1 = 0x11,
 XFER_SW_DMA_0 = 0x10,
 XFER_PIO_6 = 0x0E,
 XFER_PIO_5 = 0x0D,
 XFER_PIO_4 = 0x0C,
 XFER_PIO_3 = 0x0B,
 XFER_PIO_2 = 0x0A,
 XFER_PIO_1 = 0x09,
 XFER_PIO_0 = 0x08,
 XFER_PIO_SLOW = 0x00,

 SETFEATURES_WC_ON = 0x02,
 SETFEATURES_WC_OFF = 0x82,

 SETFEATURES_SPINUP = 0x07,


 ATAPI_PKT_DMA = (1 << 0),
 ATAPI_DMADIR = (1 << 2),

 ATAPI_CDB_LEN = 16,


 SATA_PMP_MAX_PORTS = 15,
 SATA_PMP_CTRL_PORT = 15,

 SATA_PMP_GSCR_DWORDS = 128,
 SATA_PMP_GSCR_PROD_ID = 0,
 SATA_PMP_GSCR_REV = 1,
 SATA_PMP_GSCR_PORT_INFO = 2,
 SATA_PMP_GSCR_ERROR = 32,
 SATA_PMP_GSCR_ERROR_EN = 33,
 SATA_PMP_GSCR_FEAT = 64,
 SATA_PMP_GSCR_FEAT_EN = 96,

 SATA_PMP_PSCR_STATUS = 0,
 SATA_PMP_PSCR_ERROR = 1,
 SATA_PMP_PSCR_CONTROL = 2,

 SATA_PMP_FEAT_BIST = (1 << 0),
 SATA_PMP_FEAT_PMREQ = (1 << 1),
 SATA_PMP_FEAT_DYNSSC = (1 << 2),
 SATA_PMP_FEAT_NOTIFY = (1 << 3),


 ATA_CBL_NONE = 0,
 ATA_CBL_PATA40 = 1,
 ATA_CBL_PATA80 = 2,
 ATA_CBL_PATA40_SHORT = 3,
 ATA_CBL_PATA_UNK = 4,
 ATA_CBL_SATA = 5,


 SCR_STATUS = 0,
 SCR_ERROR = 1,
 SCR_CONTROL = 2,
 SCR_ACTIVE = 3,
 SCR_NOTIFICATION = 4,


 SERR_DATA_RECOVERED = (1 << 0),
 SERR_COMM_RECOVERED = (1 << 1),
 SERR_DATA = (1 << 8),
 SERR_PERSISTENT = (1 << 9),
 SERR_PROTOCOL = (1 << 10),
 SERR_INTERNAL = (1 << 11),
 SERR_PHYRDY_CHG = (1 << 16),
 SERR_DEV_XCHG = (1 << 26),


 ATA_TFLAG_LBA48 = (1 << 0),
 ATA_TFLAG_ISADDR = (1 << 1),
 ATA_TFLAG_DEVICE = (1 << 2),
 ATA_TFLAG_WRITE = (1 << 3),
 ATA_TFLAG_LBA = (1 << 4),
 ATA_TFLAG_FUA = (1 << 5),
 ATA_TFLAG_POLLING = (1 << 6),
};

enum ata_tf_protocols {

 ATA_PROT_UNKNOWN,
 ATA_PROT_NODATA,
 ATA_PROT_PIO,
 ATA_PROT_DMA,
 ATA_PROT_NCQ,
 ATA_PROT_ATAPI,
 ATA_PROT_ATAPI_NODATA,
 ATA_PROT_ATAPI_DMA,
};

enum ata_ioctls {
 ATA_IOC_GET_IO32 = 0x309,
 ATA_IOC_SET_IO32 = 0x324,
};



struct ata_prd {
 u32 addr;
 u32 flags_len;
};

struct ata_taskfile {
 unsigned long flags;
 u8 protocol;

 u8 ctl;

 u8 hob_feature;
 u8 hob_nsect;
 u8 hob_lbal;
 u8 hob_lbam;
 u8 hob_lbah;

 u8 feature;
 u8 nsect;
 u8 lbal;
 u8 lbam;
 u8 lbah;

 u8 device;

 u8 command;
};
# 350 "include/linux/ata.h"
static inline __attribute__((always_inline)) unsigned int ata_id_major_version(const u16 *id)
{
 unsigned int mver;

 if (id[ATA_ID_MAJOR_VER] == 0xFFFF)
  return 0;

 for (mver = 14; mver >= 1; mver--)
  if (id[ATA_ID_MAJOR_VER] & (1 << mver))
   break;
 return mver;
}

static inline __attribute__((always_inline)) int ata_id_is_sata(const u16 *id)
{
 return ata_id_major_version(id) >= 5 && id[93] == 0;
}

static inline __attribute__((always_inline)) int ata_id_current_chs_valid(const u16 *id)
{



 return (id[53] & 0x01) &&
  id[54] &&
  id[55] &&
  id[55] <= 16 &&
  id[56];
}

static inline __attribute__((always_inline)) int ata_id_is_cfa(const u16 *id)
{
 u16 v = id[0];
 if (v == 0x848A)
  return 1;

 if (ata_id_major_version(id) >= 3 && id[82] != 0xFFFF &&
   (id[82] & ( 1 << 2)))
  return 1;
 return 0;
}

static inline __attribute__((always_inline)) int ata_drive_40wire(const u16 *dev_id)
{
 if (ata_id_is_sata(dev_id))
  return 0;
 if ((dev_id[93] & 0xE000) == 0x6000)
  return 0;
 return 1;
}

static inline __attribute__((always_inline)) int atapi_cdb_len(const u16 *dev_id)
{
 u16 tmp = dev_id[0] & 0x3;
 switch (tmp) {
 case 0: return 12;
 case 1: return 16;
 default: return -1;
 }
}

static inline __attribute__((always_inline)) int is_atapi_taskfile(const struct ata_taskfile *tf)
{
 return (tf->protocol == ATA_PROT_ATAPI) ||
        (tf->protocol == ATA_PROT_ATAPI_NODATA) ||
        (tf->protocol == ATA_PROT_ATAPI_DMA);
}

static inline __attribute__((always_inline)) int is_multi_taskfile(struct ata_taskfile *tf)
{
 return (tf->command == ATA_CMD_READ_MULTI) ||
        (tf->command == ATA_CMD_WRITE_MULTI) ||
        (tf->command == ATA_CMD_READ_MULTI_EXT) ||
        (tf->command == ATA_CMD_WRITE_MULTI_EXT) ||
        (tf->command == ATA_CMD_WRITE_MULTI_FUA_EXT);
}

static inline __attribute__((always_inline)) int ata_ok(u8 status)
{
 return ((status & (ATA_BUSY | ATA_DRDY | ATA_DF | ATA_DRQ | ATA_ERR))
   == ATA_DRDY);
}

static inline __attribute__((always_inline)) int lba_28_ok(u64 block, u32 n_block)
{

 return ((block + n_block - 1) < ((u64)1 << 28)) && (n_block <= 256);
}

static inline __attribute__((always_inline)) int lba_48_ok(u64 block, u32 n_block)
{

 return ((block + n_block - 1) < ((u64)1 << 48)) && (n_block <= 65536);
}
# 6 "include/linux/hdreg.h" 2
# 92 "include/linux/hdreg.h"
typedef unsigned char task_ioreg_t;
typedef unsigned long sata_ioreg_t;

typedef union ide_reg_valid_s {
 unsigned all : 16;
 struct {
  unsigned data : 1;
  unsigned error_feature : 1;
  unsigned sector : 1;
  unsigned nsector : 1;
  unsigned lcyl : 1;
  unsigned hcyl : 1;
  unsigned select : 1;
  unsigned status_command : 1;

  unsigned data_hob : 1;
  unsigned error_feature_hob : 1;
  unsigned sector_hob : 1;
  unsigned nsector_hob : 1;
  unsigned lcyl_hob : 1;
  unsigned hcyl_hob : 1;
  unsigned select_hob : 1;
  unsigned control_hob : 1;
 } b;
} ide_reg_valid_t;

typedef struct ide_task_request_s {
 task_ioreg_t io_ports[8];
 task_ioreg_t hob_ports[8];
 ide_reg_valid_t out_flags;
 ide_reg_valid_t in_flags;
 int data_phase;
 int req_cmd;
 unsigned long out_size;
 unsigned long in_size;
} ide_task_request_t;

typedef struct ide_ioctl_request_s {
 ide_task_request_t *task_request;
 unsigned char *out_buffer;
 unsigned char *in_buffer;
} ide_ioctl_request_t;

struct hd_drive_cmd_hdr {
 task_ioreg_t command;
 task_ioreg_t sector_number;
 task_ioreg_t feature;
 task_ioreg_t sector_count;
};

typedef struct hd_drive_task_hdr {
 task_ioreg_t data;
 task_ioreg_t feature;
 task_ioreg_t sector_count;
 task_ioreg_t sector_number;
 task_ioreg_t low_cylinder;
 task_ioreg_t high_cylinder;
 task_ioreg_t device_head;
 task_ioreg_t command;
} task_struct_t;

typedef struct hd_drive_hob_hdr {
 task_ioreg_t data;
 task_ioreg_t feature;
 task_ioreg_t sector_count;
 task_ioreg_t sector_number;
 task_ioreg_t low_cylinder;
 task_ioreg_t high_cylinder;
 task_ioreg_t device_head;
 task_ioreg_t control;
} hob_struct_t;
# 377 "include/linux/hdreg.h"
struct hd_geometry {
      unsigned char heads;
      unsigned char sectors;
      unsigned short cylinders;
      unsigned long start;
};
# 429 "include/linux/hdreg.h"
enum {
 BUSSTATE_OFF = 0,
 BUSSTATE_ON,
 BUSSTATE_TRISTATE
};
# 449 "include/linux/hdreg.h"
struct hd_driveid {
 unsigned short config;
 unsigned short cyls;
 unsigned short reserved2;
 unsigned short heads;
 unsigned short track_bytes;
 unsigned short sector_bytes;
 unsigned short sectors;
 unsigned short vendor0;
 unsigned short vendor1;
 unsigned short vendor2;
 unsigned char serial_no[20];
 unsigned short buf_type;
 unsigned short buf_size;


 unsigned short ecc_bytes;
 unsigned char fw_rev[8];
 unsigned char model[40];
 unsigned char max_multsect;
 unsigned char vendor3;
 unsigned short dword_io;
 unsigned char vendor4;
 unsigned char capability;





 unsigned short reserved50;
 unsigned char vendor5;
 unsigned char tPIO;
 unsigned char vendor6;
 unsigned char tDMA;
 unsigned short field_valid;




 unsigned short cur_cyls;
 unsigned short cur_heads;
 unsigned short cur_sectors;
 unsigned short cur_capacity0;
 unsigned short cur_capacity1;
 unsigned char multsect;
 unsigned char multsect_valid;
 unsigned int lba_capacity;
 unsigned short dma_1word;
 unsigned short dma_mword;
 unsigned short eide_pio_modes;
 unsigned short eide_dma_min;
 unsigned short eide_dma_time;
 unsigned short eide_pio;
 unsigned short eide_pio_iordy;
 unsigned short words69_70[2];



 unsigned short words71_74[4];


 unsigned short queue_depth;



 unsigned short words76_79[4];
 unsigned short major_rev_num;
 unsigned short minor_rev_num;
 unsigned short command_set_1;
# 535 "include/linux/hdreg.h"
 unsigned short command_set_2;
# 553 "include/linux/hdreg.h"
 unsigned short cfsse;
# 565 "include/linux/hdreg.h"
 unsigned short cfs_enable_1;
# 584 "include/linux/hdreg.h"
 unsigned short cfs_enable_2;
# 603 "include/linux/hdreg.h"
 unsigned short csf_default;
# 615 "include/linux/hdreg.h"
 unsigned short dma_ultra;
 unsigned short trseuc;
 unsigned short trsEuc;
 unsigned short CurAPMvalues;
 unsigned short mprc;
 unsigned short hw_config;
# 638 "include/linux/hdreg.h"
 unsigned short acoustic;



 unsigned short msrqs;
 unsigned short sxfert;
 unsigned short sal;
 unsigned int spg;
 unsigned long long lba_capacity_2;
 unsigned short words104_125[22];
 unsigned short last_lun;
 unsigned short word127;







 unsigned short dlf;
# 669 "include/linux/hdreg.h"
 unsigned short csfo;







 unsigned short words130_155[26];
 unsigned short word156;
 unsigned short words157_159[3];
 unsigned short cfa_power;






 unsigned short words161_175[15];
 unsigned short words176_205[30];
 unsigned short words206_254[49];
 unsigned short integrity_word;



};
# 167 "drivers/block/floppy.c" 2



# 1 "include/linux/mm.h" 1
# 17 "include/linux/mm.h"
# 1 "include/linux/backing-dev.h" 1
# 13 "include/linux/backing-dev.h"
struct page;




enum bdi_state {
 BDI_pdflush,
 BDI_write_congested,
 BDI_read_congested,
 BDI_unused,
};

typedef int (congested_fn)(void *, int);

struct backing_dev_info {
 unsigned long ra_pages;
 unsigned long state;
 unsigned int capabilities;
 congested_fn *congested_fn;
 void *congested_data;
 void (*unplug_io_fn)(struct backing_dev_info *, struct page *);
 void *unplug_io_data;
};
# 63 "include/linux/backing-dev.h"
extern struct backing_dev_info default_backing_dev_info;
void default_unplug_io_fn(struct backing_dev_info *bdi, struct page *page);

int writeback_acquire(struct backing_dev_info *bdi);
int writeback_in_progress(struct backing_dev_info *bdi);
void writeback_release(struct backing_dev_info *bdi);

static inline __attribute__((always_inline)) int bdi_congested(struct backing_dev_info *bdi, int bdi_bits)
{
 if (bdi->congested_fn)
  return bdi->congested_fn(bdi->congested_data, bdi_bits);
 return (bdi->state & bdi_bits);
}

static inline __attribute__((always_inline)) int bdi_read_congested(struct backing_dev_info *bdi)
{
 return bdi_congested(bdi, 1 << BDI_read_congested);
}

static inline __attribute__((always_inline)) int bdi_write_congested(struct backing_dev_info *bdi)
{
 return bdi_congested(bdi, 1 << BDI_write_congested);
}

static inline __attribute__((always_inline)) int bdi_rw_congested(struct backing_dev_info *bdi)
{
 return bdi_congested(bdi, (1 << BDI_read_congested)|
      (1 << BDI_write_congested));
}

void clear_bdi_congested(struct backing_dev_info *bdi, int rw);
void set_bdi_congested(struct backing_dev_info *bdi, int rw);
long congestion_wait(int rw, long timeout);
long congestion_wait_interruptible(int rw, long timeout);
void congestion_end(int rw);
# 18 "include/linux/mm.h" 2
# 1 "include/linux/mm_types.h" 1
# 9 "include/linux/mm_types.h"
struct address_space;
# 18 "include/linux/mm_types.h"
struct page {
 unsigned long flags;

 atomic_t _count;
 union {
  atomic_t _mapcount;



  struct {
   short unsigned int inuse;
   short unsigned int offset;
  };
 };
 union {
     struct {
  unsigned long private;






  struct address_space *mapping;






     };

     spinlock_t ptl;

     struct {
      void **lockless_freelist;
  struct kmem_cache *slab;
     };
     struct {
  struct page *first_page;
     };
 };
 union {
  unsigned long index;
  void *freelist;
 };
 struct list_head lru;
# 81 "include/linux/mm_types.h"
};
# 19 "include/linux/mm.h" 2

struct mempolicy;
struct anon_vma;
struct user_struct;


extern unsigned long max_mapnr;


extern unsigned long num_physpages;
extern void * high_memory;
extern unsigned long vmalloc_earlyreserve;
extern int page_cluster;


extern int sysctl_legacy_va_layout;





# 1 "include/asm/pgtable.h" 1
# 28 "include/asm/pgtable.h"
struct mm_struct;
struct vm_area_struct;






extern unsigned long empty_zero_page[1024];
extern pgd_t swapper_pg_dir[1024];
extern struct kmem_cache *pmd_cache;
extern spinlock_t pgd_lock;
extern struct page *pgd_list;
void check_pgt_cache(void);

void pmd_ctor(void *, struct kmem_cache *, unsigned long);
void pgtable_cache_init(void);
void paging_init(void);
# 58 "include/asm/pgtable.h"
# 1 "include/asm/pgtable-2level-defs.h" 1
# 59 "include/asm/pgtable.h" 2
# 159 "include/asm/pgtable.h"
extern unsigned long long __PAGE_KERNEL, __PAGE_KERNEL_EXEC;
# 205 "include/asm/pgtable.h"
extern unsigned long pg0[];
# 221 "include/asm/pgtable.h"
static inline __attribute__((always_inline)) int pte_user(pte_t pte) { return (pte).pte_low & 0x004; }
static inline __attribute__((always_inline)) int pte_read(pte_t pte) { return (pte).pte_low & 0x004; }
static inline __attribute__((always_inline)) int pte_dirty(pte_t pte) { return (pte).pte_low & 0x040; }
static inline __attribute__((always_inline)) int pte_young(pte_t pte) { return (pte).pte_low & 0x020; }
static inline __attribute__((always_inline)) int pte_write(pte_t pte) { return (pte).pte_low & 0x002; }
static inline __attribute__((always_inline)) int pte_huge(pte_t pte) { return (pte).pte_low & 0x080; }




static inline __attribute__((always_inline)) int pte_file(pte_t pte) { return (pte).pte_low & 0x040; }

static inline __attribute__((always_inline)) pte_t pte_rdprotect(pte_t pte) { (pte).pte_low &= ~0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_exprotect(pte_t pte) { (pte).pte_low &= ~0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkclean(pte_t pte) { (pte).pte_low &= ~0x040; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkold(pte_t pte) { (pte).pte_low &= ~0x020; return pte; }
static inline __attribute__((always_inline)) pte_t pte_wrprotect(pte_t pte) { (pte).pte_low &= ~0x002; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkread(pte_t pte) { (pte).pte_low |= 0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkexec(pte_t pte) { (pte).pte_low |= 0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkdirty(pte_t pte) { (pte).pte_low |= 0x040; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkyoung(pte_t pte) { (pte).pte_low |= 0x020; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkwrite(pte_t pte) { (pte).pte_low |= 0x002; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkhuge(pte_t pte) { (pte).pte_low |= 0x080; return pte; }




# 1 "include/asm/pgtable-2level.h" 1
# 14 "include/asm/pgtable-2level.h"
static inline __attribute__((always_inline)) void native_set_pte(pte_t *ptep , pte_t pte)
{
 *ptep = pte;
}
static inline __attribute__((always_inline)) void native_set_pte_at(struct mm_struct *mm, unsigned long addr,
         pte_t *ptep , pte_t pte)
{
 native_set_pte(ptep, pte);
}
static inline __attribute__((always_inline)) void native_set_pmd(pmd_t *pmdp, pmd_t pmd)
{
 *pmdp = pmd;
}
# 39 "include/asm/pgtable-2level.h"
static inline __attribute__((always_inline)) void native_pte_clear(struct mm_struct *mm, unsigned long addr, pte_t *xp)
{
 *xp = __pte(0);
}


static inline __attribute__((always_inline)) pte_t native_ptep_get_and_clear(pte_t *xp)
{
 return __pte(((__typeof__(*(&xp->pte_low)))__xchg((unsigned long)(0),(&xp->pte_low),sizeof(*(&xp->pte_low)))));
}
# 62 "include/asm/pgtable-2level.h"
static inline __attribute__((always_inline)) int pte_exec(pte_t pte)
{
 return pte_user(pte);
}




static inline __attribute__((always_inline)) int pte_exec_kernel(pte_t pte)
{
 return 1;
}
# 249 "include/asm/pgtable.h" 2
# 270 "include/asm/pgtable.h"
static inline __attribute__((always_inline)) pte_t native_local_ptep_get_and_clear(pte_t *ptep)
{
 pte_t res = *ptep;


 native_pte_clear(((void *)0), 0, ptep);
 return res;
}
# 352 "include/asm/pgtable.h"
static inline __attribute__((always_inline)) pte_t ptep_get_and_clear(struct mm_struct *mm, unsigned long addr, pte_t *ptep)
{
 pte_t pte = native_ptep_get_and_clear(ptep);
 pte_update(mm, addr, ptep);
 return pte;
}


static inline __attribute__((always_inline)) pte_t ptep_get_and_clear_full(struct mm_struct *mm, unsigned long addr, pte_t *ptep, int full)
{
 pte_t pte;
 if (full) {




  pte = native_local_ptep_get_and_clear(ptep);
 } else {
  pte = ptep_get_and_clear(mm, addr, ptep);
 }
 return pte;
}


static inline __attribute__((always_inline)) void ptep_set_wrprotect(struct mm_struct *mm, unsigned long addr, pte_t *ptep)
{
 clear_bit(1, &ptep->pte_low);
 pte_update(mm, addr, ptep);
}
# 392 "include/asm/pgtable.h"
static inline __attribute__((always_inline)) void clone_pgd_range(pgd_t *dst, pgd_t *src, int count)
{
       (__builtin_constant_p(count * sizeof(pgd_t)) ? __constant_memcpy((dst),(src),(count * sizeof(pgd_t))) : __memcpy((dst),(src),(count * sizeof(pgd_t))));
}
# 411 "include/asm/pgtable.h"
static inline __attribute__((always_inline)) pte_t pte_modify(pte_t pte, pgprot_t newprot)
{
 pte.pte_low &= ((~((1UL << 12)-1)) | 0x020 | 0x040);
 pte.pte_low |= ((newprot).pgprot);
# 424 "include/asm/pgtable.h"
 return pte;
}
# 482 "include/asm/pgtable.h"
extern pte_t *lookup_address(unsigned long address);
# 493 "include/asm/pgtable.h"
 static inline __attribute__((always_inline)) int set_kernel_exec(unsigned long vaddr, int enable) { return 0;}
# 524 "include/asm/pgtable.h"
void native_pagetable_setup_start(pgd_t *base);
void native_pagetable_setup_done(pgd_t *base);
# 548 "include/asm/pgtable.h"
# 1 "include/asm-generic/pgtable.h" 1
# 244 "include/asm-generic/pgtable.h"
void pgd_clear_bad(pgd_t *);
void pud_clear_bad(pud_t *);
void pmd_clear_bad(pmd_t *);

static inline __attribute__((always_inline)) int pgd_none_or_clear_bad(pgd_t *pgd)
{
 if (pgd_none(*pgd))
  return 1;
 if (__builtin_expect(!!(pgd_bad(*pgd)), 0)) {
  pgd_clear_bad(pgd);
  return 1;
 }
 return 0;
}

static inline __attribute__((always_inline)) int pud_none_or_clear_bad(pud_t *pud)
{
 if (pud_none(*pud))
  return 1;
 if (__builtin_expect(!!(pud_bad(*pud)), 0)) {
  pud_clear_bad(pud);
  return 1;
 }
 return 0;
}

static inline __attribute__((always_inline)) int pmd_none_or_clear_bad(pmd_t *pmd)
{
 if ((!(unsigned long)((pgd_val(((*pmd).pud).pgd)))))
  return 1;
 if (__builtin_expect(!!(((((pgd_val(((*pmd).pud).pgd))) & (~(~((1UL << 12)-1)) & ~0x004)) != (0x001 | 0x002 | 0x020 | 0x040))), 0)) {
  pmd_clear_bad(pmd);
  return 1;
 }
 return 0;
}
# 549 "include/asm/pgtable.h" 2
# 41 "include/linux/mm.h" 2
# 60 "include/linux/mm.h"
struct vm_area_struct {
 struct mm_struct * vm_mm;
 unsigned long vm_start;
 unsigned long vm_end;



 struct vm_area_struct *vm_next;

 pgprot_t vm_page_prot;
 unsigned long vm_flags;

 struct rb_node vm_rb;







 union {
  struct {
   struct list_head list;
   void *parent;
   struct vm_area_struct *head;
  } vm_set;

  struct raw_prio_tree_node prio_tree_node;
 } shared;







 struct list_head anon_vma_node;
 struct anon_vma *anon_vma;


 struct vm_operations_struct * vm_ops;


 unsigned long vm_pgoff;

 struct file * vm_file;
 void * vm_private_data;
 unsigned long vm_truncate_count;







};

extern struct kmem_cache *vm_area_cachep;






struct vm_list_struct {
 struct vm_list_struct *next;
 struct vm_area_struct *vma;
};
# 193 "include/linux/mm.h"
extern pgprot_t protection_map[16];







struct vm_operations_struct {
 void (*open)(struct vm_area_struct * area);
 void (*close)(struct vm_area_struct * area);
 struct page * (*nopage)(struct vm_area_struct * area, unsigned long address, int *type);
 unsigned long (*nopfn)(struct vm_area_struct * area, unsigned long address);
 int (*populate)(struct vm_area_struct * area, unsigned long address, unsigned long len, pgprot_t prot, unsigned long pgoff, int nonblock);



 int (*page_mkwrite)(struct vm_area_struct *vma, struct page *page);







};

struct mmu_gather;
struct inode;
# 230 "include/linux/mm.h"
# 1 "include/linux/page-flags.h" 1
# 246 "include/linux/page-flags.h"
static inline __attribute__((always_inline)) void __SetPageTail(struct page *page)
{
 page->flags |= ((1L << 14) | (1L << 17));
}

static inline __attribute__((always_inline)) void __ClearPageTail(struct page *page)
{
 page->flags &= ~((1L << 14) | (1L << 17));
}
# 273 "include/linux/page-flags.h"
struct page;

extern void cancel_dirty_page(struct page *page, unsigned int account_size);

int test_clear_page_writeback(struct page *page);
int test_set_page_writeback(struct page *page);

static inline __attribute__((always_inline)) void set_page_writeback(struct page *page)
{
 test_set_page_writeback(page);
}
# 231 "include/linux/mm.h" 2
# 254 "include/linux/mm.h"
static inline __attribute__((always_inline)) int put_page_testzero(struct page *page)
{
 do { if (__builtin_expect(!!((((&page->_count)->counter) == 0)!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/mm.h"), "i" (256), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
 return atomic_dec_and_test(&page->_count);
}





static inline __attribute__((always_inline)) int get_page_unless_zero(struct page *page)
{
 do { if (__builtin_expect(!!(((__builtin_constant_p(14) ? constant_test_bit((14),(&(page)->flags)) : variable_test_bit((14),(&(page)->flags))))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/mm.h"), "i" (266), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
 return atomic_add_unless((&page->_count), 1, 0);
}

static inline __attribute__((always_inline)) struct page *compound_head(struct page *page)
{
 if (__builtin_expect(!!(((page->flags & ((1L << 14) | (1L << 17))) == ((1L << 14) | (1L << 17)))), 0))
  return page->first_page;
 return page;
}

static inline __attribute__((always_inline)) int page_count(struct page *page)
{
 return ((&compound_head(page)->_count)->counter);
}

static inline __attribute__((always_inline)) void get_page(struct page *page)
{
 page = compound_head(page);
 do { if (__builtin_expect(!!((((&page->_count)->counter) == 0)!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/mm.h"), "i" (285), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);
 atomic_inc(&page->_count);
}

static inline __attribute__((always_inline)) struct page *virt_to_head_page(const void *x)
{
 struct page *page = (mem_map + ((((unsigned long)(x)-((unsigned long)((unsigned long)0xC0000000))) >> 12) - (0UL)));
 return compound_head(page);
}





static inline __attribute__((always_inline)) void init_page_count(struct page *page)
{
 (((&page->_count)->counter) = (1));
}

void put_page(struct page *page);
void put_pages_list(struct list_head *pages);

void split_page(struct page *page, unsigned int order);






typedef void compound_page_dtor(struct page *);

static inline __attribute__((always_inline)) void set_compound_page_dtor(struct page *page,
      compound_page_dtor *dtor)
{
 page[1].lru.next = (void *)dtor;
}

static inline __attribute__((always_inline)) compound_page_dtor *get_compound_page_dtor(struct page *page)
{
 return (compound_page_dtor *)page[1].lru.next;
}

static inline __attribute__((always_inline)) int compound_order(struct page *page)
{
 if (!((page->flags & ((1L << 14) | (1L << 17))) == (1L << 14)))
  return 0;
 return (unsigned long)page[1].lru.prev;
}

static inline __attribute__((always_inline)) void set_compound_order(struct page *page, unsigned long order)
{
 page[1].lru.prev = (void *)order;
}
# 481 "include/linux/mm.h"
static inline __attribute__((always_inline)) enum zone_type page_zonenum(struct page *page)
{
 return (page->flags >> (((((sizeof(unsigned long)*8) - 0) - 0) - 2) * (2 != 0))) & ((1UL << 2) - 1);
}
# 494 "include/linux/mm.h"
static inline __attribute__((always_inline)) int page_zone_id(struct page *page)
{
 return (page->flags >> ((((((sizeof(unsigned long)*8) - 0) - 0) < ((((sizeof(unsigned long)*8) - 0) - 0) - 2))? (((sizeof(unsigned long)*8) - 0) - 0) : ((((sizeof(unsigned long)*8) - 0) - 0) - 2)) * ((0 + 2) != 0))) & ((1UL << (0 + 2)) - 1);
}

static inline __attribute__((always_inline)) int zone_to_nid(struct zone *zone)
{



 return 0;

}




static inline __attribute__((always_inline)) int page_to_nid(struct page *page)
{
 return (page->flags >> ((((sizeof(unsigned long)*8) - 0) - 0) * (0 != 0))) & ((1UL << 0) - 1);
}


static inline __attribute__((always_inline)) struct zone *page_zone(struct page *page)
{
 return &(&contig_page_data)->node_zones[page_zonenum(page)];
}

static inline __attribute__((always_inline)) unsigned long page_to_section(struct page *page)
{
 return (page->flags >> (((sizeof(unsigned long)*8) - 0) * (0 != 0))) & ((1UL << 0) - 1);
}

static inline __attribute__((always_inline)) void set_page_zone(struct page *page, enum zone_type zone)
{
 page->flags &= ~(((1UL << 2) - 1) << (((((sizeof(unsigned long)*8) - 0) - 0) - 2) * (2 != 0)));
 page->flags |= (zone & ((1UL << 2) - 1)) << (((((sizeof(unsigned long)*8) - 0) - 0) - 2) * (2 != 0));
}

static inline __attribute__((always_inline)) void set_page_node(struct page *page, unsigned long node)
{
 page->flags &= ~(((1UL << 0) - 1) << ((((sizeof(unsigned long)*8) - 0) - 0) * (0 != 0)));
 page->flags |= (node & ((1UL << 0) - 1)) << ((((sizeof(unsigned long)*8) - 0) - 0) * (0 != 0));
}

static inline __attribute__((always_inline)) void set_page_section(struct page *page, unsigned long section)
{
 page->flags &= ~(((1UL << 0) - 1) << (((sizeof(unsigned long)*8) - 0) * (0 != 0)));
 page->flags |= (section & ((1UL << 0) - 1)) << (((sizeof(unsigned long)*8) - 0) * (0 != 0));
}

static inline __attribute__((always_inline)) void set_page_links(struct page *page, enum zone_type zone,
 unsigned long node, unsigned long pfn)
{
 set_page_zone(page, zone);
 set_page_node(page, node);
 set_page_section(page, ((pfn) >> 0));
}




# 1 "include/linux/vmstat.h" 1





# 1 "include/linux/mm.h" 1
# 7 "include/linux/vmstat.h" 2
# 30 "include/linux/vmstat.h"
enum vm_event_item { PGPGIN, PGPGOUT, PSWPIN, PSWPOUT,
  PGALLOC_DMA, PGALLOC_NORMAL , PGALLOC_HIGH,
  PGFREE, PGACTIVATE, PGDEACTIVATE,
  PGFAULT, PGMAJFAULT,
  PGREFILL_DMA, PGREFILL_NORMAL , PGREFILL_HIGH,
  PGSTEAL_DMA, PGSTEAL_NORMAL , PGSTEAL_HIGH,
  PGSCAN_KSWAPD_DMA, PGSCAN_KSWAPD_NORMAL , PGSCAN_KSWAPD_HIGH,
  PGSCAN_DIRECT_DMA, PGSCAN_DIRECT_NORMAL , PGSCAN_DIRECT_HIGH,
  PGINODESTEAL, SLABS_SCANNED, KSWAPD_STEAL, KSWAPD_INODESTEAL,
  PAGEOUTRUN, ALLOCSTALL, PGROTATED,
  NR_VM_EVENT_ITEMS
};
# 54 "include/linux/vmstat.h"
struct vm_event_state {
 unsigned long event[NR_VM_EVENT_ITEMS];
};

extern __typeof__(struct vm_event_state) per_cpu__vm_event_states;

static inline __attribute__((always_inline)) void __count_vm_event(enum vm_event_item item)
{
 (*({ extern int simple_indentifier_vm_event_states(void); ({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__vm_event_states)); (typeof(&per_cpu__vm_event_states)) (__ptr + (({ typeof(per_cpu__this_cpu_off) ret__; switch (sizeof(per_cpu__this_cpu_off)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; default: __bad_percpu_size(); } ret__; }))); }); })).event[item]++;
}

static inline __attribute__((always_inline)) void count_vm_event(enum vm_event_item item)
{
 (*({ extern int simple_identifier_vm_event_states(void); do { } while (0); &(*({ extern int simple_indentifier_vm_event_states(void); ({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__vm_event_states)); (typeof(&per_cpu__vm_event_states)) (__ptr + (({ typeof(per_cpu__this_cpu_off) ret__; switch (sizeof(per_cpu__this_cpu_off)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; default: __bad_percpu_size(); } ret__; }))); }); })); })).event[item]++;
 do { } while (0);
}

static inline __attribute__((always_inline)) void __count_vm_events(enum vm_event_item item, long delta)
{
 (*({ extern int simple_indentifier_vm_event_states(void); ({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__vm_event_states)); (typeof(&per_cpu__vm_event_states)) (__ptr + (({ typeof(per_cpu__this_cpu_off) ret__; switch (sizeof(per_cpu__this_cpu_off)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; default: __bad_percpu_size(); } ret__; }))); }); })).event[item] += delta;
}

static inline __attribute__((always_inline)) void count_vm_events(enum vm_event_item item, long delta)
{
 (*({ extern int simple_identifier_vm_event_states(void); do { } while (0); &(*({ extern int simple_indentifier_vm_event_states(void); ({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__vm_event_states)); (typeof(&per_cpu__vm_event_states)) (__ptr + (({ typeof(per_cpu__this_cpu_off) ret__; switch (sizeof(per_cpu__this_cpu_off)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__this_cpu_off)); break; default: __bad_percpu_size(); } ret__; }))); }); })); })).event[item] += delta;
 do { } while (0);
}

extern void all_vm_events(unsigned long *);

extern void vm_events_fold_cpu(int cpu);
# 122 "include/linux/vmstat.h"
extern atomic_long_t vm_stat[NR_VM_ZONE_STAT_ITEMS];

static inline __attribute__((always_inline)) void zone_page_state_add(long x, struct zone *zone,
     enum zone_stat_item item)
{
 atomic_long_add(x, &zone->vm_stat[item]);
 atomic_long_add(x, &vm_stat[item]);
}

static inline __attribute__((always_inline)) unsigned long global_page_state(enum zone_stat_item item)
{
 long x = atomic_long_read(&vm_stat[item]);

 if (x < 0)
  x = 0;

 return x;
}

static inline __attribute__((always_inline)) unsigned long zone_page_state(struct zone *zone,
     enum zone_stat_item item)
{
 long x = atomic_long_read(&zone->vm_stat[item]);

 if (x < 0)
  x = 0;

 return x;
}
# 193 "include/linux/vmstat.h"
static inline __attribute__((always_inline)) void zap_zone_vm_stats(struct zone *zone)
{
 (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(zone->vm_stat))) ? __constant_c_and_count_memset(((zone->vm_stat)),((0x01010101UL*(unsigned char)(0))),((sizeof(zone->vm_stat)))) : __constant_c_memset(((zone->vm_stat)),((0x01010101UL*(unsigned char)(0))),((sizeof(zone->vm_stat))))) : (__builtin_constant_p((sizeof(zone->vm_stat))) ? __memset_generic((((zone->vm_stat))),(((0))),(((sizeof(zone->vm_stat))))) : __memset_generic(((zone->vm_stat)),((0)),((sizeof(zone->vm_stat))))));
}

extern void inc_zone_state(struct zone *, enum zone_stat_item);


void __mod_zone_page_state(struct zone *, enum zone_stat_item item, int);
void __inc_zone_page_state(struct page *, enum zone_stat_item);
void __dec_zone_page_state(struct page *, enum zone_stat_item);

void mod_zone_page_state(struct zone *, enum zone_stat_item, int);
void inc_zone_page_state(struct page *, enum zone_stat_item);
void dec_zone_page_state(struct page *, enum zone_stat_item);

extern void inc_zone_state(struct zone *, enum zone_stat_item);
extern void __inc_zone_state(struct zone *, enum zone_stat_item);
extern void dec_zone_state(struct zone *, enum zone_stat_item);
extern void __dec_zone_state(struct zone *, enum zone_stat_item);

void refresh_cpu_vm_stats(int);
# 557 "include/linux/mm.h" 2

static inline __attribute__((always_inline)) __attribute__((always_inline)) void *lowmem_page_address(struct page *page)
{
 return ((void *)((unsigned long)(((unsigned long)((page) - mem_map) + (0UL)) << 12)+((unsigned long)((unsigned long)0xC0000000))));
}
# 577 "include/linux/mm.h"
void *page_address(struct page *page);
void set_page_address(struct page *page, void *virtual);
void page_address_init(void);
# 599 "include/linux/mm.h"
extern struct address_space swapper_space;
static inline __attribute__((always_inline)) struct address_space *page_mapping(struct page *page)
{
 struct address_space *mapping = page->mapping;

 if (__builtin_expect(!!((__builtin_constant_p(15) ? constant_test_bit((15),(&(page)->flags)) : variable_test_bit((15),(&(page)->flags)))), 0))
  mapping = &swapper_space;




 else if (__builtin_expect(!!((unsigned long)mapping & 1), 0))
  mapping = ((void *)0);
 return mapping;
}

static inline __attribute__((always_inline)) int PageAnon(struct page *page)
{
 return ((unsigned long)page->mapping & 1) != 0;
}





static inline __attribute__((always_inline)) unsigned long page_index(struct page *page)
{
 if (__builtin_expect(!!((__builtin_constant_p(15) ? constant_test_bit((15),(&(page)->flags)) : variable_test_bit((15),(&(page)->flags)))), 0))
  return ((page)->private);
 return page->index;
}






static inline __attribute__((always_inline)) void reset_page_mapcount(struct page *page)
{
 (((&(page)->_mapcount)->counter) = (-1));
}

static inline __attribute__((always_inline)) int page_mapcount(struct page *page)
{
 return ((&(page)->_mapcount)->counter) + 1;
}




static inline __attribute__((always_inline)) int page_mapped(struct page *page)
{
 return ((&(page)->_mapcount)->counter) >= 0;
}
# 686 "include/linux/mm.h"
extern void show_free_areas(void);


int shmem_set_policy(struct vm_area_struct *vma, struct mempolicy *new);
struct mempolicy *shmem_get_policy(struct vm_area_struct *vma,
     unsigned long addr);
int shmem_lock(struct file *file, int lock, struct user_struct *user);
# 712 "include/linux/mm.h"
struct file *shmem_file_setup(char *name, loff_t size, unsigned long flags);

int shmem_zero_setup(struct vm_area_struct *);
# 724 "include/linux/mm.h"
extern int can_do_mlock(void);
extern int user_shm_lock(size_t, struct user_struct *);
extern void user_shm_unlock(size_t, struct user_struct *);




struct zap_details {
 struct vm_area_struct *nonlinear_vma;
 struct address_space *check_mapping;
 unsigned long first_index;
 unsigned long last_index;
 spinlock_t *i_mmap_lock;
 unsigned long truncate_count;
};

struct page *vm_normal_page(struct vm_area_struct *, unsigned long, pte_t);
unsigned long zap_page_range(struct vm_area_struct *vma, unsigned long address,
  unsigned long size, struct zap_details *);
unsigned long unmap_vmas(struct mmu_gather **tlb,
  struct vm_area_struct *start_vma, unsigned long start_addr,
  unsigned long end_addr, unsigned long *nr_accounted,
  struct zap_details *);
void free_pgd_range(struct mmu_gather **tlb, unsigned long addr,
  unsigned long end, unsigned long floor, unsigned long ceiling);
void free_pgtables(struct mmu_gather **tlb, struct vm_area_struct *start_vma,
  unsigned long floor, unsigned long ceiling);
int copy_page_range(struct mm_struct *dst, struct mm_struct *src,
   struct vm_area_struct *vma);
int zeromap_page_range(struct vm_area_struct *vma, unsigned long from,
   unsigned long size, pgprot_t prot);
void unmap_mapping_range(struct address_space *mapping,
  loff_t const holebegin, loff_t const holelen, int even_cows);

static inline __attribute__((always_inline)) void unmap_shared_mapping_range(struct address_space *mapping,
  loff_t const holebegin, loff_t const holelen)
{
 unmap_mapping_range(mapping, holebegin, holelen, 0);
}

extern int vmtruncate(struct inode * inode, loff_t offset);
extern int vmtruncate_range(struct inode * inode, loff_t offset, loff_t end);
extern int install_page(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, struct page *page, pgprot_t prot);
extern int install_file_pte(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, unsigned long pgoff, pgprot_t prot);


extern int __handle_mm_fault(struct mm_struct *mm,struct vm_area_struct *vma,
   unsigned long address, int write_access);

static inline __attribute__((always_inline)) int handle_mm_fault(struct mm_struct *mm,
   struct vm_area_struct *vma, unsigned long address,
   int write_access)
{
 return __handle_mm_fault(mm, vma, address, write_access) &
    (~0x10);
}
# 791 "include/linux/mm.h"
extern int make_pages_present(unsigned long addr, unsigned long end);
extern int access_process_vm(struct task_struct *tsk, unsigned long addr, void *buf, int len, int write);
void install_arg_page(struct vm_area_struct *, struct page *, unsigned long);

int get_user_pages(struct task_struct *tsk, struct mm_struct *mm, unsigned long start,
  int len, int write, int force, struct page **pages, struct vm_area_struct **vmas);
void print_bad_pte(struct vm_area_struct *, pte_t, unsigned long);

extern int try_to_release_page(struct page * page, gfp_t gfp_mask);
extern void do_invalidatepage(struct page *page, unsigned long offset);

int __set_page_dirty_nobuffers(struct page *page);
int __set_page_dirty_no_writeback(struct page *page);
int redirty_page_for_writepage(struct writeback_control *wbc,
    struct page *page);
int set_page_dirty(struct page *page) __attribute__((regparm(3)));
int set_page_dirty_lock(struct page *page);
int clear_page_dirty_for_io(struct page *page);

extern unsigned long do_mremap(unsigned long addr,
          unsigned long old_len, unsigned long new_len,
          unsigned long flags, unsigned long new_addr);
# 825 "include/linux/mm.h"
typedef int (*shrinker_t)(int nr_to_scan, gfp_t gfp_mask);







struct shrinker;
extern struct shrinker *set_shrinker(int, shrinker_t);
extern void remove_shrinker(struct shrinker *shrinker);







static inline __attribute__((always_inline)) int vma_wants_writenotify(struct vm_area_struct *vma)
{
 unsigned int vm_flags = vma->vm_flags;


 if ((vm_flags & (0x00000002|0x00000008)) != ((0x00000002|0x00000008)))
  return 0;


 if (vma->vm_ops && vma->vm_ops->page_mkwrite)
  return 1;


 if (((vma->vm_page_prot).pgprot) !=
     ((protection_map[vm_flags & (0x00000001|0x00000002|0x00000004|0x00000008)]).pgprot))

  return 0;


 if (vm_flags & (0x00000400|0x02000000))
  return 0;


 return vma->vm_file && vma->vm_file->f_mapping &&
  (!(((vma->vm_file->f_mapping)->backing_dev_info)->capabilities & 0x00000001));
}

extern pte_t *get_locked_pte(struct mm_struct *mm, unsigned long addr, spinlock_t **ptl) __attribute__((regparm(3)));


static inline __attribute__((always_inline)) int __pud_alloc(struct mm_struct *mm, pgd_t *pgd,
      unsigned long address)
{
 return 0;
}





static inline __attribute__((always_inline)) int __pmd_alloc(struct mm_struct *mm, pud_t *pud,
      unsigned long address)
{
 return 0;
}




int __pte_alloc(struct mm_struct *mm, pmd_t *pmd, unsigned long address);
int __pte_alloc_kernel(pmd_t *pmd, unsigned long address);






static inline __attribute__((always_inline)) pud_t *pud_alloc(struct mm_struct *mm, pgd_t *pgd, unsigned long address)
{
 return (__builtin_expect(!!(pgd_none(*pgd)), 0) && __pud_alloc(mm, pgd, address))?
  ((void *)0): pud_offset(pgd, address);
}

static inline __attribute__((always_inline)) pmd_t *pmd_alloc(struct mm_struct *mm, pud_t *pud, unsigned long address)
{
 return (__builtin_expect(!!(pud_none(*pud)), 0) && __pmd_alloc(mm, pud, address))?
  ((void *)0): pmd_offset(pud, address);
}
# 961 "include/linux/mm.h"
extern void free_area_init(unsigned long * zones_size);
extern void free_area_init_node(int nid, pg_data_t *pgdat,
 unsigned long * zones_size, unsigned long zone_start_pfn,
 unsigned long *zholes_size);
# 993 "include/linux/mm.h"
extern void free_area_init_nodes(unsigned long *max_zone_pfn);
extern void add_active_range(unsigned int nid, unsigned long start_pfn,
     unsigned long end_pfn);
extern void shrink_active_range(unsigned int nid, unsigned long old_end_pfn,
      unsigned long new_end_pfn);
extern void push_node_boundaries(unsigned int nid, unsigned long start_pfn,
     unsigned long end_pfn);
extern void remove_all_active_ranges(void);
extern unsigned long absent_pages_in_range(unsigned long start_pfn,
      unsigned long end_pfn);
extern void get_pfn_range_for_nid(unsigned int nid,
   unsigned long *start_pfn, unsigned long *end_pfn);
extern unsigned long find_min_pfn_with_active_regions(void);
extern unsigned long find_max_pfn_with_active_regions(void);
extern void free_bootmem_with_active_regions(int nid,
      unsigned long max_low_pfn);
extern void sparse_memory_present_with_active_regions(int nid);

extern int early_pfn_to_nid(unsigned long pfn);


extern void set_dma_reserve(unsigned long new_dma_reserve);
extern void memmap_init_zone(unsigned long, int, unsigned long,
    unsigned long, enum memmap_context);
extern void setup_per_zone_pages_min(void);
extern void mem_init(void);
extern void show_mem(void);
extern void si_meminfo(struct sysinfo * val);
extern void si_meminfo_node(struct sysinfo *val, int nid);




static inline __attribute__((always_inline)) void setup_per_cpu_pageset(void) {}



void vma_prio_tree_add(struct vm_area_struct *, struct vm_area_struct *old);
void vma_prio_tree_insert(struct vm_area_struct *, struct prio_tree_root *);
void vma_prio_tree_remove(struct vm_area_struct *, struct prio_tree_root *);
struct vm_area_struct *vma_prio_tree_next(struct vm_area_struct *vma,
 struct prio_tree_iter *iter);





static inline __attribute__((always_inline)) void vma_nonlinear_insert(struct vm_area_struct *vma,
     struct list_head *list)
{
 vma->shared.vm_set.parent = ((void *)0);
 list_add_tail(&vma->shared.vm_set.list, list);
}


extern int __vm_enough_memory(long pages, int cap_sys_admin);
extern void vma_adjust(struct vm_area_struct *vma, unsigned long start,
 unsigned long end, unsigned long pgoff, struct vm_area_struct *insert);
extern struct vm_area_struct *vma_merge(struct mm_struct *,
 struct vm_area_struct *prev, unsigned long addr, unsigned long end,
 unsigned long vm_flags, struct anon_vma *, struct file *, unsigned long,
 struct mempolicy *);
extern struct anon_vma *find_mergeable_anon_vma(struct vm_area_struct *);
extern int split_vma(struct mm_struct *,
 struct vm_area_struct *, unsigned long addr, int new_below);
extern int insert_vm_struct(struct mm_struct *, struct vm_area_struct *);
extern void __vma_link_rb(struct mm_struct *, struct vm_area_struct *,
 struct rb_node **, struct rb_node *);
extern void unlink_file_vma(struct vm_area_struct *);
extern struct vm_area_struct *copy_vma(struct vm_area_struct **,
 unsigned long addr, unsigned long len, unsigned long pgoff);
extern void exit_mmap(struct mm_struct *);
extern int may_expand_vm(struct mm_struct *mm, unsigned long npages);
extern int install_special_mapping(struct mm_struct *mm,
       unsigned long addr, unsigned long len,
       unsigned long flags, struct page **pages);

extern unsigned long get_unmapped_area(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);

extern unsigned long do_mmap_pgoff(struct file *file, unsigned long addr,
 unsigned long len, unsigned long prot,
 unsigned long flag, unsigned long pgoff);

static inline __attribute__((always_inline)) unsigned long do_mmap(struct file *file, unsigned long addr,
 unsigned long len, unsigned long prot,
 unsigned long flag, unsigned long offset)
{
 unsigned long ret = -22;
 if ((offset + (((len)+(1UL << 12)-1)&(~((1UL << 12)-1)))) < offset)
  goto out;
 if (!(offset & ~(~((1UL << 12)-1))))
  ret = do_mmap_pgoff(file, addr, len, prot, flag, offset >> 12);
out:
 return ret;
}

extern int do_munmap(struct mm_struct *, unsigned long, size_t);

extern unsigned long do_brk(unsigned long, unsigned long);


extern unsigned long page_unuse(struct page *);
extern void truncate_inode_pages(struct address_space *, loff_t);
extern void truncate_inode_pages_range(struct address_space *,
           loff_t lstart, loff_t lend);


extern struct page *filemap_nopage(struct vm_area_struct *, unsigned long, int *);
extern int filemap_populate(struct vm_area_struct *, unsigned long,
  unsigned long, pgprot_t, unsigned long, int);


int write_one_page(struct page *page, int wait);







int do_page_cache_readahead(struct address_space *mapping, struct file *filp,
   unsigned long offset, unsigned long nr_to_read);
int force_page_cache_readahead(struct address_space *mapping, struct file *filp,
   unsigned long offset, unsigned long nr_to_read);
unsigned long page_cache_readahead(struct address_space *mapping,
     struct file_ra_state *ra,
     struct file *filp,
     unsigned long offset,
     unsigned long size);
void handle_ra_miss(struct address_space *mapping,
      struct file_ra_state *ra, unsigned long offset);
unsigned long max_sane_readahead(unsigned long nr);


extern int expand_stack(struct vm_area_struct *vma, unsigned long address);





extern struct vm_area_struct * find_vma(struct mm_struct * mm, unsigned long addr);
extern struct vm_area_struct * find_vma_prev(struct mm_struct * mm, unsigned long addr,
          struct vm_area_struct **pprev);



static inline __attribute__((always_inline)) struct vm_area_struct * find_vma_intersection(struct mm_struct * mm, unsigned long start_addr, unsigned long end_addr)
{
 struct vm_area_struct * vma = find_vma(mm,start_addr);

 if (vma && end_addr <= vma->vm_start)
  vma = ((void *)0);
 return vma;
}

static inline __attribute__((always_inline)) unsigned long vma_pages(struct vm_area_struct *vma)
{
 return (vma->vm_end - vma->vm_start) >> 12;
}

pgprot_t vm_get_page_prot(unsigned long vm_flags);
struct vm_area_struct *find_extend_vma(struct mm_struct *, unsigned long addr);
struct page *vmalloc_to_page(void *addr);
unsigned long vmalloc_to_pfn(void *addr);
int remap_pfn_range(struct vm_area_struct *, unsigned long addr,
   unsigned long pfn, unsigned long size, pgprot_t);
int vm_insert_page(struct vm_area_struct *, unsigned long addr, struct page *);
int vm_insert_pfn(struct vm_area_struct *vma, unsigned long addr,
   unsigned long pfn);

struct page *follow_page(struct vm_area_struct *, unsigned long address,
   unsigned int foll_flags);





typedef int (*pte_fn_t)(pte_t *pte, struct page *pmd_page, unsigned long addr,
   void *data);
extern int apply_to_page_range(struct mm_struct *mm, unsigned long address,
          unsigned long size, pte_fn_t fn, void *data);


void vm_stat_account(struct mm_struct *, unsigned long, struct file *, long);
# 1185 "include/linux/mm.h"
static inline __attribute__((always_inline)) void
kernel_map_pages(struct page *page, int numpages, int enable) {}


extern struct vm_area_struct *get_gate_vma(struct task_struct *tsk);

int in_gate_area_no_task(unsigned long addr);
int in_gate_area(struct task_struct *task, unsigned long addr);





int drop_caches_sysctl_handler(struct ctl_table *, int, struct file *,
     void *, size_t *, loff_t *);
unsigned long shrink_slab(unsigned long scanned, gfp_t gfp_mask,
   unsigned long lru_pages);
void drop_pagecache(void);
void drop_slab(void);




extern int randomize_va_space;


__attribute__((weak)) const char *arch_vma_name(struct vm_area_struct *vma);
# 171 "drivers/block/floppy.c" 2
# 1 "include/linux/bio.h" 1
# 23 "include/linux/bio.h"
# 1 "include/linux/highmem.h" 1





# 1 "include/linux/uaccess.h" 1




# 1 "include/asm/uaccess.h" 1
# 40 "include/asm/uaccess.h"
extern struct movsl_mask {
 int mask;
} __attribute__((__aligned__((1 << (7))))) movsl_mask;
# 98 "include/asm/uaccess.h"
struct exception_table_entry
{
 unsigned long insn, fixup;
};

extern int fixup_exception(struct pt_regs *regs);
# 120 "include/asm/uaccess.h"
extern void __get_user_1(void);
extern void __get_user_2(void);
extern void __get_user_4(void);
# 162 "include/asm/uaccess.h"
extern void __put_user_bad(void);





extern void __put_user_1(void);
extern void __put_user_2(void);
extern void __put_user_4(void);
extern void __put_user_8(void);
# 325 "include/asm/uaccess.h"
struct __large_struct { unsigned long buf[100]; };
# 358 "include/asm/uaccess.h"
extern long __get_user_bad(void);
# 389 "include/asm/uaccess.h"
unsigned long __attribute__((warn_unused_result)) __copy_to_user_ll(void *to,
    const void *from, unsigned long n);
unsigned long __attribute__((warn_unused_result)) __copy_from_user_ll(void *to,
    const void *from, unsigned long n);
unsigned long __attribute__((warn_unused_result)) __copy_from_user_ll_nozero(void *to,
    const void *from, unsigned long n);
unsigned long __attribute__((warn_unused_result)) __copy_from_user_ll_nocache(void *to,
    const void *from, unsigned long n);
unsigned long __attribute__((warn_unused_result)) __copy_from_user_ll_nocache_nozero(void *to,
    const void *from, unsigned long n);
# 419 "include/asm/uaccess.h"
static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long __attribute__((warn_unused_result))
__copy_to_user_inatomic(void *to, const void *from, unsigned long n)
{
 if (__builtin_constant_p(n)) {
  unsigned long ret;

  switch (n) {
  case 1:
   do { ret = 0; (void)0; switch (1) { case 1: __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "iq" (*(u8 *)from), "m"((*(struct __large_struct *)((u8 *)to))), "i"(1), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "ir" (*(u8 *)from), "m"((*(struct __large_struct *)((u8 *)to))), "i"(1), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "ir" (*(u8 *)from), "m"((*(struct __large_struct *)((u8 *)to))), "i"(1), "0"(ret)); break; case 8: __asm__ __volatile__( "1:	movl %%eax,0(%2)\n" "2:	movl %%edx,4(%2)\n" "3:\n" ".section .fixup,\"ax\"\n" "4:	movl %3,%0\n" "	jmp 3b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,4b\n" "	.long 2b,4b\n" ".previous" : "=r"(ret) : "A" ((__typeof__(*(u8 *)to))(*(u8 *)from)), "r" ((u8 *)to), "i"(-14), "0"(ret)); break; default: __put_user_bad(); } } while (0);
   return ret;
  case 2:
   do { ret = 0; (void)0; switch (2) { case 1: __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "iq" (*(u16 *)from), "m"((*(struct __large_struct *)((u16 *)to))), "i"(2), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "ir" (*(u16 *)from), "m"((*(struct __large_struct *)((u16 *)to))), "i"(2), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "ir" (*(u16 *)from), "m"((*(struct __large_struct *)((u16 *)to))), "i"(2), "0"(ret)); break; case 8: __asm__ __volatile__( "1:	movl %%eax,0(%2)\n" "2:	movl %%edx,4(%2)\n" "3:\n" ".section .fixup,\"ax\"\n" "4:	movl %3,%0\n" "	jmp 3b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,4b\n" "	.long 2b,4b\n" ".previous" : "=r"(ret) : "A" ((__typeof__(*(u16 *)to))(*(u16 *)from)), "r" ((u16 *)to), "i"(-14), "0"(ret)); break; default: __put_user_bad(); } } while (0);
   return ret;
  case 4:
   do { ret = 0; (void)0; switch (4) { case 1: __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "iq" (*(u32 *)from), "m"((*(struct __large_struct *)((u32 *)to))), "i"(4), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "ir" (*(u32 *)from), "m"((*(struct __large_struct *)((u32 *)to))), "i"(4), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret) : "ir" (*(u32 *)from), "m"((*(struct __large_struct *)((u32 *)to))), "i"(4), "0"(ret)); break; case 8: __asm__ __volatile__( "1:	movl %%eax,0(%2)\n" "2:	movl %%edx,4(%2)\n" "3:\n" ".section .fixup,\"ax\"\n" "4:	movl %3,%0\n" "	jmp 3b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,4b\n" "	.long 2b,4b\n" ".previous" : "=r"(ret) : "A" ((__typeof__(*(u32 *)to))(*(u32 *)from)), "r" ((u32 *)to), "i"(-14), "0"(ret)); break; default: __put_user_bad(); } } while (0);
   return ret;
  }
 }
 return __copy_to_user_ll(to, from, n);
}
# 454 "include/asm/uaccess.h"
static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long __attribute__((warn_unused_result))
__copy_to_user(void *to, const void *from, unsigned long n)
{
       do { __might_sleep("include/asm/uaccess.h", 457); do { } while (0); } while (0);
       return __copy_to_user_inatomic(to, from, n);
}

static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long
__copy_from_user_inatomic(void *to, const void *from, unsigned long n)
{





 if (__builtin_constant_p(n)) {
  unsigned long ret;

  switch (n) {
  case 1:
   do { ret = 0; (void)0; switch (1) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; default: (*(u8 *)to) = __get_user_bad(); } } while (0);
   return ret;
  case 2:
   do { ret = 0; (void)0; switch (2) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; default: (*(u16 *)to) = __get_user_bad(); } } while (0);
   return ret;
  case 4:
   do { ret = 0; (void)0; switch (4) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; default: (*(u32 *)to) = __get_user_bad(); } } while (0);
   return ret;
  }
 }
 return __copy_from_user_ll_nozero(to, from, n);
}
# 509 "include/asm/uaccess.h"
static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long
__copy_from_user(void *to, const void *from, unsigned long n)
{
 do { __might_sleep("include/asm/uaccess.h", 512); do { } while (0); } while (0);
 if (__builtin_constant_p(n)) {
  unsigned long ret;

  switch (n) {
  case 1:
   do { ret = 0; (void)0; switch (1) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; default: (*(u8 *)to) = __get_user_bad(); } } while (0);
   return ret;
  case 2:
   do { ret = 0; (void)0; switch (2) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; default: (*(u16 *)to) = __get_user_bad(); } } while (0);
   return ret;
  case 4:
   do { ret = 0; (void)0; switch (4) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; default: (*(u32 *)to) = __get_user_bad(); } } while (0);
   return ret;
  }
 }
 return __copy_from_user_ll(to, from, n);
}



static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long __copy_from_user_nocache(void *to,
    const void *from, unsigned long n)
{
 do { __might_sleep("include/asm/uaccess.h", 536); do { } while (0); } while (0);
 if (__builtin_constant_p(n)) {
  unsigned long ret;

  switch (n) {
  case 1:
   do { ret = 0; (void)0; switch (1) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; default: (*(u8 *)to) = __get_user_bad(); } } while (0);
   return ret;
  case 2:
   do { ret = 0; (void)0; switch (2) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; default: (*(u16 *)to) = __get_user_bad(); } } while (0);
   return ret;
  case 4:
   do { ret = 0; (void)0; switch (4) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; default: (*(u32 *)to) = __get_user_bad(); } } while (0);
   return ret;
  }
 }
 return __copy_from_user_ll_nocache(to, from, n);
}

static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long
__copy_from_user_inatomic_nocache(void *to, const void *from, unsigned long n)
{
       return __copy_from_user_ll_nocache_nozero(to, from, n);
}

unsigned long __attribute__((warn_unused_result)) copy_to_user(void *to,
    const void *from, unsigned long n);
unsigned long __attribute__((warn_unused_result)) copy_from_user(void *to,
    const void *from, unsigned long n);
long __attribute__((warn_unused_result)) strncpy_from_user(char *dst, const char *src,
    long count);
long __attribute__((warn_unused_result)) __strncpy_from_user(char *dst,
    const char *src, long count);
# 586 "include/asm/uaccess.h"
long strnlen_user(const char *str, long n);
unsigned long __attribute__((warn_unused_result)) clear_user(void *mem, unsigned long len);
unsigned long __attribute__((warn_unused_result)) __clear_user(void *mem, unsigned long len);
# 6 "include/linux/uaccess.h" 2
# 16 "include/linux/uaccess.h"
static inline __attribute__((always_inline)) void pagefault_disable(void)
{
 do { (current_thread_info()->preempt_count) += (1); } while (0);




 __asm__ __volatile__("": : :"memory");
}

static inline __attribute__((always_inline)) void pagefault_enable(void)
{




 __asm__ __volatile__("": : :"memory");
 do { (current_thread_info()->preempt_count) -= (1); } while (0);



 __asm__ __volatile__("": : :"memory");
 do { } while (0);
}
# 7 "include/linux/highmem.h" 2

# 1 "include/asm/cacheflush.h" 1
# 27 "include/asm/cacheflush.h"
void global_flush_tlb(void);
int change_page_attr(struct page *page, int numpages, pgprot_t prot);







void mark_rodata_ro(void);
# 9 "include/linux/highmem.h" 2


static inline __attribute__((always_inline)) void flush_anon_page(struct vm_area_struct *vma, struct page *page, unsigned long vmaddr)
{
}



static inline __attribute__((always_inline)) void flush_kernel_dcache_page(struct page *page)
{
}




# 1 "include/asm/highmem.h" 1
# 23 "include/asm/highmem.h"
# 1 "include/linux/interrupt.h" 1
# 10 "include/linux/interrupt.h"
# 1 "include/linux/irqreturn.h" 1
# 19 "include/linux/irqreturn.h"
typedef int irqreturn_t;
# 11 "include/linux/interrupt.h" 2
# 1 "include/linux/hardirq.h" 1




# 1 "include/linux/smp_lock.h" 1
# 10 "include/linux/smp_lock.h"
extern int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) __reacquire_kernel_lock(void);
extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) __release_kernel_lock(void);
# 33 "include/linux/smp_lock.h"
static inline __attribute__((always_inline)) int reacquire_kernel_lock(struct task_struct *task)
{
 if (__builtin_expect(!!(task->lock_depth >= 0), 0))
  __reacquire_kernel_lock();
 return 0;
}

extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) lock_kernel(void) ;
extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) unlock_kernel(void) ;
# 6 "include/linux/hardirq.h" 2

# 1 "include/asm/hardirq.h" 1




# 1 "include/linux/irq.h" 1
# 23 "include/linux/irq.h"
# 1 "include/asm/irq.h" 1
# 15 "include/asm/irq.h"
# 1 "include/asm-i386/mach-default/irq_vectors.h" 1
# 87 "include/asm-i386/mach-default/irq_vectors.h"
# 1 "include/asm-i386/mach-default/irq_vectors_limits.h" 1
# 88 "include/asm-i386/mach-default/irq_vectors.h" 2
# 16 "include/asm/irq.h" 2


static __inline__ __attribute__((always_inline)) int irq_canonicalize(int irq)
{
 return ((irq == 2) ? 9 : irq);
}






  extern void irq_ctx_init(int cpu);
  extern void irq_ctx_exit(int cpu);







extern int irqbalance_disable(char *str);



extern void fixup_irqs(cpumask_t map);


void init_IRQ(void);
void __attribute__ ((__section__ (".init.text"))) native_init_IRQ(void);
# 24 "include/linux/irq.h" 2

# 1 "include/asm/irq_regs.h" 1
# 12 "include/asm/irq_regs.h"
extern __typeof__(struct pt_regs *) per_cpu__irq_regs;

static inline __attribute__((always_inline)) struct pt_regs *get_irq_regs(void)
{
 return ({ typeof(per_cpu__irq_regs) ret__; switch (sizeof(per_cpu__irq_regs)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__irq_regs)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__irq_regs)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__irq_regs)); break; default: __bad_percpu_size(); } ret__; });
}

static inline __attribute__((always_inline)) struct pt_regs *set_irq_regs(struct pt_regs *new_regs)
{
 struct pt_regs *old_regs;

 old_regs = get_irq_regs();
 do { typedef typeof(per_cpu__irq_regs) T__; if (0) { T__ tmp__; tmp__ = (new_regs); } switch (sizeof(per_cpu__irq_regs)) { case 1: asm("mov" "b %1,""%%fs:""%0" : "+m" (per_cpu__irq_regs) :"ri" ((T__)new_regs)); break; case 2: asm("mov" "w %1,""%%fs:""%0" : "+m" (per_cpu__irq_regs) :"ri" ((T__)new_regs)); break; case 4: asm("mov" "l %1,""%%fs:""%0" : "+m" (per_cpu__irq_regs) :"ri" ((T__)new_regs)); break; default: __bad_percpu_size(); } } while (0);

 return old_regs;
}
# 26 "include/linux/irq.h" 2

struct irq_desc;
typedef void __attribute__((regparm(3))) (*irq_flow_handler_t)(unsigned int irq,
         struct irq_desc *desc);
# 73 "include/linux/irq.h"
struct proc_dir_entry;
struct msi_desc;
# 98 "include/linux/irq.h"
struct irq_chip {
 const char *name;
 unsigned int (*startup)(unsigned int irq);
 void (*shutdown)(unsigned int irq);
 void (*enable)(unsigned int irq);
 void (*disable)(unsigned int irq);

 void (*ack)(unsigned int irq);
 void (*mask)(unsigned int irq);
 void (*mask_ack)(unsigned int irq);
 void (*unmask)(unsigned int irq);
 void (*eoi)(unsigned int irq);

 void (*end)(unsigned int irq);
 void (*set_affinity)(unsigned int irq, cpumask_t dest);
 int (*retrigger)(unsigned int irq);
 int (*set_type)(unsigned int irq, unsigned int flow_type);
 int (*set_wake)(unsigned int irq, unsigned int on);
# 125 "include/linux/irq.h"
 const char *typename;
};
# 151 "include/linux/irq.h"
struct irq_desc {
 irq_flow_handler_t handle_irq;
 struct irq_chip *chip;
 struct msi_desc *msi_desc;
 void *handler_data;
 void *chip_data;
 struct irqaction *action;
 unsigned int status;

 unsigned int depth;
 unsigned int wake_depth;
 unsigned int irq_count;
 unsigned int irqs_unhandled;
 spinlock_t lock;

 cpumask_t affinity;
 unsigned int cpu;


 cpumask_t pending_mask;


 struct proc_dir_entry *dir;

 const char *name;
} __attribute__((__aligned__(1 << ((7)))));

extern struct irq_desc irq_desc[224];





typedef struct irq_chip hw_irq_controller;

typedef struct irq_desc irq_desc_t;




# 1 "include/asm/hw_irq.h" 1
# 15 "include/asm/hw_irq.h"
# 1 "include/linux/profile.h" 1
# 13 "include/linux/profile.h"
extern int prof_on __attribute__((__section__(".data.read_mostly")));






struct proc_dir_entry;
struct pt_regs;
struct notifier_block;


void __attribute__ ((__section__ (".init.text"))) profile_init(void);
void profile_tick(int);




void profile_hits(int, void *ip, unsigned int nr_hits);




static inline __attribute__((always_inline)) void profile_hit(int type, void *ip)
{



 if (__builtin_expect(!!(prof_on == type), 0))
  profile_hits(type, ip, 1);
}


void create_prof_cpu_mask(struct proc_dir_entry *);




enum profile_type {
 PROFILE_TASK_EXIT,
 PROFILE_MUNMAP
};



struct task_struct;
struct mm_struct;


void profile_task_exit(struct task_struct * task);




int profile_handoff_task(struct task_struct * task);


void profile_munmap(unsigned long addr);

int task_handoff_register(struct notifier_block * n);
int task_handoff_unregister(struct notifier_block * n);

int profile_event_register(enum profile_type, struct notifier_block * n);
int profile_event_unregister(enum profile_type, struct notifier_block * n);

int register_timer_hook(int (*hook)(struct pt_regs *));
void unregister_timer_hook(int (*hook)(struct pt_regs *));


extern int (*timer_hook)(struct pt_regs *);

struct pt_regs;
# 16 "include/asm/hw_irq.h" 2


# 1 "include/asm/sections.h" 1




# 1 "include/asm-generic/sections.h" 1





extern char _text[], _stext[], _etext[];
extern char _data[], _sdata[], _edata[];
extern char __bss_start[], __bss_stop[];
extern char __init_begin[], __init_end[];
extern char _sinittext[], _einittext[];
extern char _sextratext[] __attribute__((weak));
extern char _eextratext[] __attribute__((weak));
extern char _end[];
extern char __per_cpu_start[], __per_cpu_end[];
extern char __kprobes_text_start[], __kprobes_text_end[];
extern char __initdata_begin[], __initdata_end[];
extern char __start_rodata[], __end_rodata[];
# 6 "include/asm/sections.h" 2
# 19 "include/asm/hw_irq.h" 2
# 29 "include/asm/hw_irq.h"
extern void (*interrupt[224])(void);


__attribute__((regparm(3))) void reschedule_interrupt(void);
__attribute__((regparm(3))) void invalidate_interrupt(void);
__attribute__((regparm(3))) void call_function_interrupt(void);



__attribute__((regparm(3))) void apic_timer_interrupt(void);
__attribute__((regparm(3))) void error_interrupt(void);
__attribute__((regparm(3))) void spurious_interrupt(void);
__attribute__((regparm(3))) void thermal_interrupt(void);



void disable_8259A_irq(unsigned int irq);
void enable_8259A_irq(unsigned int irq);
int i8259A_irq_pending(unsigned int irq);
void make_8259A_irq(unsigned int irq);
void init_8259A(int aeoi);
void send_IPI_self(int vector) __attribute__((regparm(3)));
void init_VISWS_APIC_irqs(void);
void setup_IO_APIC(void);
void disable_IO_APIC(void);
void print_IO_APIC(void);
int IO_APIC_get_PCI_irq_vector(int bus, int slot, int fn);
void send_IPI(int dest, int vector);
void setup_ioapic_dest(void);

extern unsigned long io_apic_irqs;

extern atomic_t irq_err_count;
extern atomic_t irq_mis_count;
# 192 "include/linux/irq.h" 2

extern int setup_irq(unsigned int irq, struct irqaction *new);
# 205 "include/linux/irq.h"
void set_pending_irq(unsigned int irq, cpumask_t mask);
void move_native_irq(int irq);
void move_masked_irq(int irq);
# 229 "include/linux/irq.h"
extern int irq_set_affinity(unsigned int irq, cpumask_t cpumask);
extern int irq_can_set_affinity(unsigned int irq);
# 247 "include/linux/irq.h"
extern void set_balance_irq_affinity(unsigned int irq, cpumask_t mask);
# 257 "include/linux/irq.h"
static inline __attribute__((always_inline)) int select_smp_affinity(unsigned int irq)
{
 return 1;
}


extern int no_irq_affinity;

static inline __attribute__((always_inline)) int irq_balancing_disabled(unsigned int irq)
{
 return irq_desc[irq].status & 0x00400000;
}


extern int handle_IRQ_event(unsigned int irq, struct irqaction *action);





extern void __attribute__((regparm(3))) handle_level_irq(unsigned int irq, struct irq_desc *desc);
extern void __attribute__((regparm(3))) handle_fasteoi_irq(unsigned int irq, struct irq_desc *desc);
extern void __attribute__((regparm(3))) handle_edge_irq(unsigned int irq, struct irq_desc *desc);
extern void __attribute__((regparm(3))) handle_simple_irq(unsigned int irq, struct irq_desc *desc);
extern void __attribute__((regparm(3))) handle_percpu_irq(unsigned int irq, struct irq_desc *desc);
extern void __attribute__((regparm(3))) handle_bad_irq(unsigned int irq, struct irq_desc *desc);






extern __attribute__((regparm(3))) unsigned int __do_IRQ(unsigned int irq);
# 298 "include/linux/irq.h"
static inline __attribute__((always_inline)) void generic_handle_irq(unsigned int irq)
{
 struct irq_desc *desc = irq_desc + irq;




 if (__builtin_expect(!!(desc->handle_irq), 1))
  desc->handle_irq(irq, desc);
 else
  __do_IRQ(irq);

}


extern void note_interrupt(unsigned int irq, struct irq_desc *desc,
      int action_ret);


void check_irq_resend(struct irq_desc *desc, unsigned int irq);


extern int noirqdebug_setup(char *str);


extern int can_request_irq(unsigned int irq, unsigned long irqflags);


extern struct irq_chip no_irq_chip;
extern struct irq_chip dummy_irq_chip;

extern void
set_irq_chip_and_handler(unsigned int irq, struct irq_chip *chip,
    irq_flow_handler_t handle);
extern void
set_irq_chip_and_handler_name(unsigned int irq, struct irq_chip *chip,
         irq_flow_handler_t handle, const char *name);

extern void
__set_irq_handler(unsigned int irq, irq_flow_handler_t handle, int is_chained,
    const char *name);




static inline __attribute__((always_inline)) void
set_irq_handler(unsigned int irq, irq_flow_handler_t handle)
{
 __set_irq_handler(irq, handle, 0, ((void *)0));
}






static inline __attribute__((always_inline)) void
set_irq_chained_handler(unsigned int irq,
   irq_flow_handler_t handle)
{
 __set_irq_handler(irq, handle, 1, ((void *)0));
}


extern int create_irq(void);
extern void destroy_irq(unsigned int irq);


static inline __attribute__((always_inline)) int irq_has_action(unsigned int irq)
{
 struct irq_desc *desc = irq_desc + irq;
 return desc->action != ((void *)0);
}


extern void dynamic_irq_init(unsigned int irq);
extern void dynamic_irq_cleanup(unsigned int irq);


extern int set_irq_chip(unsigned int irq, struct irq_chip *chip);
extern int set_irq_data(unsigned int irq, void *data);
extern int set_irq_chip_data(unsigned int irq, void *data);
extern int set_irq_type(unsigned int irq, unsigned int type);
extern int set_irq_msi(unsigned int irq, struct msi_desc *entry);
# 6 "include/asm/hardirq.h" 2

typedef struct {
 unsigned int __softirq_pending;
 unsigned long idle_timestamp;
 unsigned int __nmi_count;
 unsigned int apic_timer_irqs;
} __attribute__((__aligned__((1 << (7))))) irq_cpustat_t;

extern __typeof__(irq_cpustat_t) per_cpu__irq_stat;
extern irq_cpustat_t irq_stat[];




void ack_bad_irq(unsigned int irq);
# 1 "include/linux/irq_cpustat.h" 1
# 22 "include/asm/hardirq.h" 2
# 8 "include/linux/hardirq.h" 2
# 103 "include/linux/hardirq.h"
extern void synchronize_irq(unsigned int irq);




struct task_struct;


static inline __attribute__((always_inline)) void account_system_vtime(struct task_struct *tsk)
{
}
# 132 "include/linux/hardirq.h"
extern void irq_enter(void);
# 147 "include/linux/hardirq.h"
extern void irq_exit(void);
# 12 "include/linux/interrupt.h" 2



# 1 "include/linux/device.h" 1
# 15 "include/linux/device.h"
# 1 "include/linux/ioport.h" 1
# 17 "include/linux/ioport.h"
struct resource {
 resource_size_t start;
 resource_size_t end;
 const char *name;
 unsigned long flags;
 struct resource *parent, *sibling, *child;
};

struct resource_list {
 struct resource_list *next;
 struct resource *res;
 struct pci_dev *dev;
};
# 98 "include/linux/ioport.h"
extern struct resource ioport_resource;
extern struct resource iomem_resource;

extern int request_resource(struct resource *root, struct resource *new);
extern int release_resource(struct resource *new);
extern int insert_resource(struct resource *parent, struct resource *new);
extern int allocate_resource(struct resource *root, struct resource *new,
        resource_size_t size, resource_size_t min,
        resource_size_t max, resource_size_t align,
        void (*alignf)(void *, struct resource *,
         resource_size_t, resource_size_t),
        void *alignf_data);
int adjust_resource(struct resource *res, resource_size_t start,
      resource_size_t size);


extern int find_next_system_ram(struct resource *res);






extern struct resource * __request_region(struct resource *,
     resource_size_t start,
     resource_size_t n, const char *name);






extern int __check_region(struct resource *, resource_size_t, resource_size_t);
extern void __release_region(struct resource *, resource_size_t,
    resource_size_t);

static inline __attribute__((always_inline)) int __attribute__((deprecated)) check_region(resource_size_t s,
      resource_size_t n)
{
 return __check_region(&ioport_resource, s, n);
}


struct device;





extern struct resource * __devm_request_region(struct device *dev,
    struct resource *parent, resource_size_t start,
    resource_size_t n, const char *name);






extern void __devm_release_region(struct device *dev, struct resource *parent,
      resource_size_t start, resource_size_t n);
# 16 "include/linux/device.h" 2

# 1 "include/linux/klist.h" 1
# 20 "include/linux/klist.h"
struct klist_node;
struct klist {
 spinlock_t k_lock;
 struct list_head k_list;
 void (*get)(struct klist_node *);
 void (*put)(struct klist_node *);
};


extern void klist_init(struct klist * k, void (*get)(struct klist_node *),
         void (*put)(struct klist_node *));

struct klist_node {
 struct klist * n_klist;
 struct list_head n_node;
 struct kref n_ref;
 struct completion n_removed;
};

extern void klist_add_tail(struct klist_node * n, struct klist * k);
extern void klist_add_head(struct klist_node * n, struct klist * k);

extern void klist_del(struct klist_node * n);
extern void klist_remove(struct klist_node * n);

extern int klist_node_attached(struct klist_node * n);


struct klist_iter {
 struct klist * i_klist;
 struct list_head * i_head;
 struct klist_node * i_cur;
};


extern void klist_iter_init(struct klist * k, struct klist_iter * i);
extern void klist_iter_init_node(struct klist * k, struct klist_iter * i,
     struct klist_node * n);
extern void klist_iter_exit(struct klist_iter * i);
extern struct klist_node * klist_next(struct klist_iter * i);
# 18 "include/linux/device.h" 2







# 1 "include/asm/device.h" 1
# 9 "include/asm/device.h"
struct dev_archdata {

 void *acpi_handle;

};
# 26 "include/linux/device.h" 2







struct device;
struct device_driver;
struct class;
struct class_device;
struct bus_type;

struct bus_attribute {
 struct attribute attr;
 ssize_t (*show)(struct bus_type *, char * buf);
 ssize_t (*store)(struct bus_type *, const char * buf, size_t count);
};




extern int __attribute__((warn_unused_result)) bus_create_file(struct bus_type *,
     struct bus_attribute *);
extern void bus_remove_file(struct bus_type *, struct bus_attribute *);

struct bus_type {
 const char * name;
 struct module * owner;

 struct kset subsys;
 struct kset drivers;
 struct kset devices;
 struct klist klist_devices;
 struct klist klist_drivers;

 struct blocking_notifier_head bus_notifier;

 struct bus_attribute * bus_attrs;
 struct device_attribute * dev_attrs;
 struct driver_attribute * drv_attrs;
 struct bus_attribute drivers_autoprobe_attr;
 struct bus_attribute drivers_probe_attr;

 int (*match)(struct device * dev, struct device_driver * drv);
 int (*uevent)(struct device *dev, char **envp,
      int num_envp, char *buffer, int buffer_size);
 int (*probe)(struct device * dev);
 int (*remove)(struct device * dev);
 void (*shutdown)(struct device * dev);

 int (*suspend)(struct device * dev, pm_message_t state);
 int (*suspend_late)(struct device * dev, pm_message_t state);
 int (*resume_early)(struct device * dev);
 int (*resume)(struct device * dev);

 unsigned int drivers_autoprobe:1;
};

extern int __attribute__((warn_unused_result)) bus_register(struct bus_type * bus);
extern void bus_unregister(struct bus_type * bus);

extern int __attribute__((warn_unused_result)) bus_rescan_devices(struct bus_type * bus);



int bus_for_each_dev(struct bus_type * bus, struct device * start, void * data,
       int (*fn)(struct device *, void *));
struct device * bus_find_device(struct bus_type *bus, struct device *start,
    void *data, int (*match)(struct device *, void *));

int __attribute__((warn_unused_result)) bus_for_each_drv(struct bus_type *bus,
  struct device_driver *start, void *data,
  int (*fn)(struct device_driver *, void *));







struct notifier_block;

extern int bus_register_notifier(struct bus_type *bus,
     struct notifier_block *nb);
extern int bus_unregister_notifier(struct bus_type *bus,
       struct notifier_block *nb);
# 124 "include/linux/device.h"
struct device_driver {
 const char * name;
 struct bus_type * bus;

 struct kobject kobj;
 struct klist klist_devices;
 struct klist_node knode_bus;

 struct module * owner;
 const char * mod_name;
 struct module_kobject * mkobj;

 int (*probe) (struct device * dev);
 int (*remove) (struct device * dev);
 void (*shutdown) (struct device * dev);
 int (*suspend) (struct device * dev, pm_message_t state);
 int (*resume) (struct device * dev);
};


extern int __attribute__((warn_unused_result)) driver_register(struct device_driver * drv);
extern void driver_unregister(struct device_driver * drv);

extern struct device_driver * get_driver(struct device_driver * drv);
extern void put_driver(struct device_driver * drv);
extern struct device_driver *driver_find(const char *name, struct bus_type *bus);
extern int driver_probe_done(void);



struct driver_attribute {
 struct attribute attr;
 ssize_t (*show)(struct device_driver *, char * buf);
 ssize_t (*store)(struct device_driver *, const char * buf, size_t count);
};




extern int __attribute__((warn_unused_result)) driver_create_file(struct device_driver *,
     struct driver_attribute *);
extern void driver_remove_file(struct device_driver *, struct driver_attribute *);

extern int __attribute__((warn_unused_result)) driver_for_each_device(struct device_driver * drv,
  struct device *start, void *data,
  int (*fn)(struct device *, void *));
struct device * driver_find_device(struct device_driver *drv,
       struct device *start, void *data,
       int (*match)(struct device *, void *));




struct class {
 const char * name;
 struct module * owner;

 struct kset subsys;
 struct list_head children;
 struct list_head devices;
 struct list_head interfaces;
 struct kset class_dirs;
 struct semaphore sem;

 struct class_attribute * class_attrs;
 struct class_device_attribute * class_dev_attrs;
 struct device_attribute * dev_attrs;

 int (*uevent)(struct class_device *dev, char **envp,
      int num_envp, char *buffer, int buffer_size);
 int (*dev_uevent)(struct device *dev, char **envp, int num_envp,
    char *buffer, int buffer_size);

 void (*release)(struct class_device *dev);
 void (*class_release)(struct class *class);
 void (*dev_release)(struct device *dev);

 int (*suspend)(struct device *, pm_message_t state);
 int (*resume)(struct device *);
};

extern int __attribute__((warn_unused_result)) class_register(struct class *);
extern void class_unregister(struct class *);


struct class_attribute {
 struct attribute attr;
 ssize_t (*show)(struct class *, char * buf);
 ssize_t (*store)(struct class *, const char * buf, size_t count);
};




extern int __attribute__((warn_unused_result)) class_create_file(struct class *,
     const struct class_attribute *);
extern void class_remove_file(struct class *, const struct class_attribute *);

struct class_device_attribute {
 struct attribute attr;
 ssize_t (*show)(struct class_device *, char * buf);
 ssize_t (*store)(struct class_device *, const char * buf, size_t count);
};





extern int __attribute__((warn_unused_result)) class_device_create_file(struct class_device *,
        const struct class_device_attribute *);
# 259 "include/linux/device.h"
struct class_device {
 struct list_head node;

 struct kobject kobj;
 struct class * class;
 dev_t devt;
 struct device * dev;
 void * class_data;
 struct class_device *parent;
 struct attribute_group ** groups;

 void (*release)(struct class_device *dev);
 int (*uevent)(struct class_device *dev, char **envp,
      int num_envp, char *buffer, int buffer_size);
 char class_id[20];
};

static inline __attribute__((always_inline)) void *
class_get_devdata (struct class_device *dev)
{
 return dev->class_data;
}

static inline __attribute__((always_inline)) void
class_set_devdata (struct class_device *dev, void *data)
{
 dev->class_data = data;
}


extern int __attribute__((warn_unused_result)) class_device_register(struct class_device *);
extern void class_device_unregister(struct class_device *);
extern void class_device_initialize(struct class_device *);
extern int __attribute__((warn_unused_result)) class_device_add(struct class_device *);
extern void class_device_del(struct class_device *);

extern struct class_device * class_device_get(struct class_device *);
extern void class_device_put(struct class_device *);

extern void class_device_remove_file(struct class_device *,
         const struct class_device_attribute *);
extern int __attribute__((warn_unused_result)) class_device_create_bin_file(struct class_device *,
     struct bin_attribute *);
extern void class_device_remove_bin_file(struct class_device *,
      struct bin_attribute *);

struct class_interface {
 struct list_head node;
 struct class *class;

 int (*add) (struct class_device *, struct class_interface *);
 void (*remove) (struct class_device *, struct class_interface *);
 int (*add_dev) (struct device *, struct class_interface *);
 void (*remove_dev) (struct device *, struct class_interface *);
};

extern int __attribute__((warn_unused_result)) class_interface_register(struct class_interface *);
extern void class_interface_unregister(struct class_interface *);

extern struct class *class_create(struct module *owner, const char *name);
extern void class_destroy(struct class *cls);
extern struct class_device *class_device_create(struct class *cls,
      struct class_device *parent,
      dev_t devt,
      struct device *device,
      const char *fmt, ...)
     __attribute__((format(printf,5,6)));
extern void class_device_destroy(struct class *cls, dev_t devt);
# 337 "include/linux/device.h"
struct device_type {
 const char *name;
 struct attribute_group **groups;
 int (*uevent)(struct device *dev, char **envp, int num_envp,
        char *buffer, int buffer_size);
 void (*release)(struct device *dev);
 int (*suspend)(struct device * dev, pm_message_t state);
 int (*resume)(struct device * dev);
};


struct device_attribute {
 struct attribute attr;
 ssize_t (*show)(struct device *dev, struct device_attribute *attr,
   char *buf);
 ssize_t (*store)(struct device *dev, struct device_attribute *attr,
    const char *buf, size_t count);
};




extern int __attribute__((warn_unused_result)) device_create_file(struct device *device,
     struct device_attribute * entry);
extern void device_remove_file(struct device * dev, struct device_attribute * attr);
extern int __attribute__((warn_unused_result)) device_create_bin_file(struct device *dev,
            struct bin_attribute *attr);
extern void device_remove_bin_file(struct device *dev,
       struct bin_attribute *attr);
extern int device_schedule_callback_owner(struct device *dev,
  void (*func)(struct device *), struct module *owner);






typedef void (*dr_release_t)(struct device *dev, void *res);
typedef int (*dr_match_t)(struct device *dev, void *res, void *match_data);


extern void * __devres_alloc(dr_release_t release, size_t size, gfp_t gfp,
        const char *name);





extern void devres_free(void *res);
extern void devres_add(struct device *dev, void *res);
extern void * devres_find(struct device *dev, dr_release_t release,
     dr_match_t match, void *match_data);
extern void * devres_get(struct device *dev, void *new_res,
    dr_match_t match, void *match_data);
extern void * devres_remove(struct device *dev, dr_release_t release,
       dr_match_t match, void *match_data);
extern int devres_destroy(struct device *dev, dr_release_t release,
     dr_match_t match, void *match_data);


extern void * __attribute__((warn_unused_result)) devres_open_group(struct device *dev, void *id,
          gfp_t gfp);
extern void devres_close_group(struct device *dev, void *id);
extern void devres_remove_group(struct device *dev, void *id);
extern int devres_release_group(struct device *dev, void *id);


extern void *devm_kzalloc(struct device *dev, size_t size, gfp_t gfp);
extern void devm_kfree(struct device *dev, void *p);

struct device {
 struct klist klist_children;
 struct klist_node knode_parent;
 struct klist_node knode_driver;
 struct klist_node knode_bus;
 struct device *parent;

 struct kobject kobj;
 char bus_id[20];
 struct device_type *type;
 unsigned is_registered:1;
 unsigned uevent_suppress:1;

 struct semaphore sem;



 struct bus_type * bus;
 struct device_driver *driver;

 void *driver_data;
 void *platform_data;

 struct dev_pm_info power;




 u64 *dma_mask;
 u64 coherent_dma_mask;





 struct list_head dma_pools;

 struct dma_coherent_mem *dma_mem;


 struct dev_archdata archdata;

 spinlock_t devres_lock;
 struct list_head devres_head;


 struct list_head node;
 struct class *class;
 dev_t devt;
 struct attribute_group **groups;

 void (*release)(struct device * dev);
};
# 471 "include/linux/device.h"
static inline __attribute__((always_inline)) int dev_to_node(struct device *dev)
{
 return -1;
}
static inline __attribute__((always_inline)) void set_dev_node(struct device *dev, int node)
{
}


static inline __attribute__((always_inline)) void *
dev_get_drvdata (struct device *dev)
{
 return dev->driver_data;
}

static inline __attribute__((always_inline)) void
dev_set_drvdata (struct device *dev, void *data)
{
 dev->driver_data = data;
}

static inline __attribute__((always_inline)) int device_is_registered(struct device *dev)
{
 return dev->is_registered;
}

void driver_init(void);




extern int __attribute__((warn_unused_result)) device_register(struct device * dev);
extern void device_unregister(struct device * dev);
extern void device_initialize(struct device * dev);
extern int __attribute__((warn_unused_result)) device_add(struct device * dev);
extern void device_del(struct device * dev);
extern int device_for_each_child(struct device *, void *,
       int (*fn)(struct device *, void *));
extern struct device *device_find_child(struct device *, void *data,
     int (*match)(struct device *, void *));
extern int device_rename(struct device *dev, char *new_name);
extern int device_move(struct device *dev, struct device *new_parent);





extern int __attribute__((warn_unused_result)) device_bind_driver(struct device *dev);
extern void device_release_driver(struct device * dev);
extern int __attribute__((warn_unused_result)) device_attach(struct device * dev);
extern int __attribute__((warn_unused_result)) driver_attach(struct device_driver *drv);
extern int __attribute__((warn_unused_result)) device_reprobe(struct device *dev);




extern struct device *device_create(struct class *cls, struct device *parent,
        dev_t devt, const char *fmt, ...)
        __attribute__((format(printf,4,5)));
extern void device_destroy(struct class *cls, dev_t devt);







extern int (*platform_notify)(struct device * dev);

extern int (*platform_notify_remove)(struct device * dev);






extern struct device * get_device(struct device * dev);
extern void put_device(struct device * dev);



extern void device_shutdown(void);



extern int __attribute__((warn_unused_result)) firmware_register(struct kset *);
extern void firmware_unregister(struct kset *);


extern const char *dev_driver_string(struct device *dev);







static inline __attribute__((always_inline)) int __attribute__ ((format (printf, 2, 3)))
dev_dbg(struct device * dev, const char * fmt, ...)
{
 return 0;
}
# 16 "include/linux/interrupt.h" 2
# 64 "include/linux/interrupt.h"
static inline __attribute__((always_inline))
unsigned long __attribute__((deprecated)) deprecated_irq_flag(unsigned long flag)
{
 return flag;
}
# 82 "include/linux/interrupt.h"
typedef irqreturn_t (*irq_handler_t)(int, void *);

struct irqaction {
 irq_handler_t handler;
 unsigned long flags;
 cpumask_t mask;
 const char *name;
 void *dev_id;
 struct irqaction *next;
 int irq;
 struct proc_dir_entry *dir;
};

extern irqreturn_t no_action(int cpl, void *dev_id);
extern int __attribute__((warn_unused_result)) request_irq(unsigned int, irq_handler_t handler,
         unsigned long, const char *, void *);
extern void free_irq(unsigned int, void *);

extern int __attribute__((warn_unused_result)) devm_request_irq(struct device *dev, unsigned int irq,
       irq_handler_t handler, unsigned long irqflags,
       const char *devname, void *dev_id);
extern void devm_free_irq(struct device *dev, unsigned int irq, void *dev_id);
# 124 "include/linux/interrupt.h"
extern void disable_irq_nosync(unsigned int irq);
extern void disable_irq(unsigned int irq);
extern void enable_irq(unsigned int irq);
# 139 "include/linux/interrupt.h"
static inline __attribute__((always_inline)) void disable_irq_nosync_lockdep(unsigned int irq)
{
 disable_irq_nosync(irq);

 do { raw_local_irq_disable(); trace_hardirqs_off(); } while (0);

}

static inline __attribute__((always_inline)) void disable_irq_nosync_lockdep_irqsave(unsigned int irq, unsigned long *flags)
{
 disable_irq_nosync(irq);

 do { do { (*flags) = __raw_local_irq_save(); } while (0); trace_hardirqs_off(); } while (0);

}

static inline __attribute__((always_inline)) void disable_irq_lockdep(unsigned int irq)
{
 disable_irq(irq);

 do { raw_local_irq_disable(); trace_hardirqs_off(); } while (0);

}

static inline __attribute__((always_inline)) void enable_irq_lockdep(unsigned int irq)
{

 do { trace_hardirqs_on(); raw_local_irq_enable(); } while (0);

 enable_irq(irq);
}

static inline __attribute__((always_inline)) void enable_irq_lockdep_irqrestore(unsigned int irq, unsigned long *flags)
{

 do { if (raw_irqs_disabled_flags(*flags)) { raw_local_irq_restore(*flags); trace_hardirqs_off(); } else { trace_hardirqs_on(); raw_local_irq_restore(*flags); } } while (0);

 enable_irq(irq);
}


extern int set_irq_wake(unsigned int irq, unsigned int on);

static inline __attribute__((always_inline)) int enable_irq_wake(unsigned int irq)
{
 return set_irq_wake(irq, 1);
}

static inline __attribute__((always_inline)) int disable_irq_wake(unsigned int irq)
{
 return set_irq_wake(irq, 0);
}
# 260 "include/linux/interrupt.h"
enum
{
 HI_SOFTIRQ=0,
 TIMER_SOFTIRQ,
 NET_TX_SOFTIRQ,
 NET_RX_SOFTIRQ,
 BLOCK_SOFTIRQ,
 TASKLET_SOFTIRQ,
 SCHED_SOFTIRQ,

 HRTIMER_SOFTIRQ,

};





struct softirq_action
{
 void (*action)(struct softirq_action *);
 void *data;
};

 __attribute__((regparm(0))) void do_softirq(void);
extern void open_softirq(int nr, void (*action)(struct softirq_action*), void *data);
extern void softirq_init(void);

extern void raise_softirq_irqoff(unsigned int nr) __attribute__((regparm(3)));
extern void raise_softirq(unsigned int nr) __attribute__((regparm(3)));
# 312 "include/linux/interrupt.h"
struct tasklet_struct
{
 struct tasklet_struct *next;
 unsigned long state;
 atomic_t count;
 void (*func)(unsigned long);
 unsigned long data;
};
# 328 "include/linux/interrupt.h"
enum
{
 TASKLET_STATE_SCHED,
 TASKLET_STATE_RUN
};


static inline __attribute__((always_inline)) int tasklet_trylock(struct tasklet_struct *t)
{
 return !test_and_set_bit(TASKLET_STATE_RUN, &(t)->state);
}

static inline __attribute__((always_inline)) void tasklet_unlock(struct tasklet_struct *t)
{
 __asm__ __volatile__("": : :"memory");
 clear_bit(TASKLET_STATE_RUN, &(t)->state);
}

static inline __attribute__((always_inline)) void tasklet_unlock_wait(struct tasklet_struct *t)
{
 while ((__builtin_constant_p(TASKLET_STATE_RUN) ? constant_test_bit((TASKLET_STATE_RUN),(&(t)->state)) : variable_test_bit((TASKLET_STATE_RUN),(&(t)->state)))) { __asm__ __volatile__("": : :"memory"); }
}






extern void __tasklet_schedule(struct tasklet_struct *t) __attribute__((regparm(3)));

static inline __attribute__((always_inline)) void tasklet_schedule(struct tasklet_struct *t)
{
 if (!test_and_set_bit(TASKLET_STATE_SCHED, &t->state))
  __tasklet_schedule(t);
}

extern void __tasklet_hi_schedule(struct tasklet_struct *t) __attribute__((regparm(3)));

static inline __attribute__((always_inline)) void tasklet_hi_schedule(struct tasklet_struct *t)
{
 if (!test_and_set_bit(TASKLET_STATE_SCHED, &t->state))
  __tasklet_hi_schedule(t);
}


static inline __attribute__((always_inline)) void tasklet_disable_nosync(struct tasklet_struct *t)
{
 atomic_inc(&t->count);
 __asm__ __volatile__("": : :"memory");
}

static inline __attribute__((always_inline)) void tasklet_disable(struct tasklet_struct *t)
{
 tasklet_disable_nosync(t);
 tasklet_unlock_wait(t);
 asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "mfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
}

static inline __attribute__((always_inline)) void tasklet_enable(struct tasklet_struct *t)
{
 __asm__ __volatile__("": : :"memory");
 atomic_dec(&t->count);
}

static inline __attribute__((always_inline)) void tasklet_hi_enable(struct tasklet_struct *t)
{
 __asm__ __volatile__("": : :"memory");
 atomic_dec(&t->count);
}

extern void tasklet_kill(struct tasklet_struct *t);
extern void tasklet_kill_immediate(struct tasklet_struct *t, unsigned int cpu);
extern void tasklet_init(struct tasklet_struct *t,
    void (*func)(unsigned long), unsigned long data);
# 445 "include/linux/interrupt.h"
extern unsigned long probe_irq_on(void);
extern int probe_irq_off(unsigned long);
extern unsigned int probe_irq_mask(unsigned long);




extern void init_irq_proc(void);
# 24 "include/asm/highmem.h" 2


# 1 "include/asm/tlbflush.h" 1
# 131 "include/asm/tlbflush.h"
extern void flush_tlb_all(void);
extern void flush_tlb_current_task(void);
extern void flush_tlb_mm(struct mm_struct *);
extern void flush_tlb_page(struct vm_area_struct *, unsigned long);



static inline __attribute__((always_inline)) void flush_tlb_range(struct vm_area_struct * vma, unsigned long start, unsigned long end)
{
 flush_tlb_mm(vma->vm_mm);
}

void native_flush_tlb_others(const cpumask_t *cpumask, struct mm_struct *mm,
        unsigned long va);




struct tlb_state
{
 struct mm_struct *active_mm;
 int state;
 char __cacheline_padding[(1 << (7))-8];
};
extern __typeof__(struct tlb_state) per_cpu__cpu_tlbstate;
# 165 "include/asm/tlbflush.h"
static inline __attribute__((always_inline)) void flush_tlb_pgtables(struct mm_struct *mm,
          unsigned long start, unsigned long end)
{

}
# 27 "include/asm/highmem.h" 2



extern unsigned long highstart_pfn, highend_pfn;

extern pte_t *kmap_pte;
extern pgprot_t kmap_prot;
extern pte_t *pkmap_page_table;
# 66 "include/asm/highmem.h"
extern void * kmap_high(struct page *page) __attribute__((regparm(3)));
extern void kunmap_high(struct page *page) __attribute__((regparm(3)));

void *kmap(struct page *page);
void kunmap(struct page *page);
void *kmap_atomic_prot(struct page *page, enum km_type type, pgprot_t prot);
void *kmap_atomic(struct page *page, enum km_type type);
void kunmap_atomic(void *kvaddr, enum km_type type);
void *kmap_atomic_pfn(unsigned long pfn, enum km_type type);
struct page *kmap_atomic_to_page(void *ptr);
# 25 "include/linux/highmem.h" 2


unsigned int nr_free_highpages(void);
extern unsigned long totalhigh_pages;

void kmap_flush_unused(void);
# 66 "include/linux/highmem.h"
static inline __attribute__((always_inline)) void clear_user_highpage(struct page *page, unsigned long vaddr)
{
 void *addr = kmap_atomic(page, KM_USER0);
 (__builtin_constant_p(0) ? (__builtin_constant_p(((1UL << 12))) ? __constant_c_and_count_memset((((void *)(addr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12)))) : __constant_c_memset((((void *)(addr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12))))) : (__builtin_constant_p(((1UL << 12))) ? __memset_generic(((((void *)(addr)))),(((0))),((((1UL << 12))))) : __memset_generic((((void *)(addr))),((0)),(((1UL << 12))))));
 kunmap_atomic(addr, KM_USER0);

 __asm__ __volatile__ ("": : :"memory");
}
# 88 "include/linux/highmem.h"
static inline __attribute__((always_inline)) void clear_highpage(struct page *page)
{
 void *kaddr = kmap_atomic(page, KM_USER0);
 (__builtin_constant_p(0) ? (__builtin_constant_p(((1UL << 12))) ? __constant_c_and_count_memset((((void *)(kaddr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12)))) : __constant_c_memset((((void *)(kaddr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12))))) : (__builtin_constant_p(((1UL << 12))) ? __memset_generic(((((void *)(kaddr)))),(((0))),((((1UL << 12))))) : __memset_generic((((void *)(kaddr))),((0)),(((1UL << 12))))));
 kunmap_atomic(kaddr, KM_USER0);
}
# 113 "include/linux/highmem.h"
static inline __attribute__((always_inline)) void __attribute__((deprecated)) memclear_highpage_flush(struct page *page,
   unsigned int offset, unsigned int size)
{
 do { void *kaddr; do { if (__builtin_expect(!!(((offset) + (size) > (1UL << 12))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/highmem.h"), "i" (116), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0); kaddr = kmap_atomic(page, KM_USER0); (__builtin_constant_p(0) ? (__builtin_constant_p(((size))) ? __constant_c_and_count_memset((((char *)kaddr + (offset))),((0x01010101UL*(unsigned char)(0))),(((size)))) : __constant_c_memset((((char *)kaddr + (offset))),((0x01010101UL*(unsigned char)(0))),(((size))))) : (__builtin_constant_p(((size))) ? __memset_generic(((((char *)kaddr + (offset)))),(((0))),((((size))))) : __memset_generic((((char *)kaddr + (offset))),((0)),(((size)))))); do { } while (0); kunmap_atomic(kaddr, (KM_USER0)); } while (0);
}



static inline __attribute__((always_inline)) void copy_user_highpage(struct page *to, struct page *from,
 unsigned long vaddr, struct vm_area_struct *vma)
{
 char *vfrom, *vto;

 vfrom = kmap_atomic(from, KM_USER0);
 vto = kmap_atomic(to, KM_USER1);
 (__builtin_constant_p((1UL << 12)) ? __constant_memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))) : __memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))));
 kunmap_atomic(vfrom, KM_USER0);
 kunmap_atomic(vto, KM_USER1);

 __asm__ __volatile__ ("": : :"memory");
}



static inline __attribute__((always_inline)) void copy_highpage(struct page *to, struct page *from)
{
 char *vfrom, *vto;

 vfrom = kmap_atomic(from, KM_USER0);
 vto = kmap_atomic(to, KM_USER1);
 (__builtin_constant_p((1UL << 12)) ? __constant_memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))) : __memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))));
 kunmap_atomic(vfrom, KM_USER0);
 kunmap_atomic(vto, KM_USER1);
}
# 24 "include/linux/bio.h" 2
# 1 "include/linux/mempool.h" 1
# 9 "include/linux/mempool.h"
struct kmem_cache;

typedef void * (mempool_alloc_t)(gfp_t gfp_mask, void *pool_data);
typedef void (mempool_free_t)(void *element, void *pool_data);

typedef struct mempool_s {
 spinlock_t lock;
 int min_nr;
 int curr_nr;
 void **elements;

 void *pool_data;
 mempool_alloc_t *alloc;
 mempool_free_t *free;
 wait_queue_head_t wait;
} mempool_t;

extern mempool_t *mempool_create(int min_nr, mempool_alloc_t *alloc_fn,
   mempool_free_t *free_fn, void *pool_data);
extern mempool_t *mempool_create_node(int min_nr, mempool_alloc_t *alloc_fn,
   mempool_free_t *free_fn, void *pool_data, int nid);

extern int mempool_resize(mempool_t *pool, int new_min_nr, gfp_t gfp_mask);
extern void mempool_destroy(mempool_t *pool);
extern void * mempool_alloc(mempool_t *pool, gfp_t gfp_mask);
extern void mempool_free(void *element, mempool_t *pool);





void *mempool_alloc_slab(gfp_t gfp_mask, void *pool_data);
void mempool_free_slab(void *element, void *pool_data);
static inline __attribute__((always_inline)) mempool_t *
mempool_create_slab_pool(int min_nr, struct kmem_cache *kc)
{
 return mempool_create(min_nr, mempool_alloc_slab, mempool_free_slab,
         (void *) kc);
}





void *mempool_kmalloc(gfp_t gfp_mask, void *pool_data);
void *mempool_kzalloc(gfp_t gfp_mask, void *pool_data);
void mempool_kfree(void *element, void *pool_data);
static inline __attribute__((always_inline)) mempool_t *mempool_create_kmalloc_pool(int min_nr, size_t size)
{
 return mempool_create(min_nr, mempool_kmalloc, mempool_kfree,
         (void *) size);
}
static inline __attribute__((always_inline)) mempool_t *mempool_create_kzalloc_pool(int min_nr, size_t size)
{
 return mempool_create(min_nr, mempool_kzalloc, mempool_kfree,
         (void *) size);
}





void *mempool_alloc_pages(gfp_t gfp_mask, void *pool_data);
void mempool_free_pages(void *element, void *pool_data);
static inline __attribute__((always_inline)) mempool_t *mempool_create_page_pool(int min_nr, int order)
{
 return mempool_create(min_nr, mempool_alloc_pages, mempool_free_pages,
         (void *)(long)order);
}
# 25 "include/linux/bio.h" 2
# 1 "include/linux/ioprio.h" 1
# 25 "include/linux/ioprio.h"
enum {
 IOPRIO_CLASS_NONE,
 IOPRIO_CLASS_RT,
 IOPRIO_CLASS_BE,
 IOPRIO_CLASS_IDLE,
};






enum {
 IOPRIO_WHO_PROCESS = 1,
 IOPRIO_WHO_PGRP,
 IOPRIO_WHO_USER,
};






static inline __attribute__((always_inline)) int task_ioprio(struct task_struct *task)
{
 if (((((task->ioprio)) >> (13)) != IOPRIO_CLASS_NONE))
  return ((task->ioprio) & ((1UL << (13)) - 1));

 return (4);
}

static inline __attribute__((always_inline)) int task_nice_ioprio(struct task_struct *task)
{
 return (task_nice(task) + 20) / 5;
}




extern int ioprio_best(unsigned short aprio, unsigned short bprio);
# 26 "include/linux/bio.h" 2


# 1 "include/asm/io.h" 1
# 47 "include/asm/io.h"
# 1 "include/asm-generic/iomap.h" 1
# 28 "include/asm-generic/iomap.h"
extern unsigned int __attribute__((regparm(3))) ioread8(void *);
extern unsigned int __attribute__((regparm(3))) ioread16(void *);
extern unsigned int __attribute__((regparm(3))) ioread16be(void *);
extern unsigned int __attribute__((regparm(3))) ioread32(void *);
extern unsigned int __attribute__((regparm(3))) ioread32be(void *);

extern void __attribute__((regparm(3))) iowrite8(u8, void *);
extern void __attribute__((regparm(3))) iowrite16(u16, void *);
extern void __attribute__((regparm(3))) iowrite16be(u16, void *);
extern void __attribute__((regparm(3))) iowrite32(u32, void *);
extern void __attribute__((regparm(3))) iowrite32be(u32, void *);
# 51 "include/asm-generic/iomap.h"
extern void __attribute__((regparm(3))) ioread8_rep(void *port, void *buf, unsigned long count);
extern void __attribute__((regparm(3))) ioread16_rep(void *port, void *buf, unsigned long count);
extern void __attribute__((regparm(3))) ioread32_rep(void *port, void *buf, unsigned long count);

extern void __attribute__((regparm(3))) iowrite8_rep(void *port, const void *buf, unsigned long count);
extern void __attribute__((regparm(3))) iowrite16_rep(void *port, const void *buf, unsigned long count);
extern void __attribute__((regparm(3))) iowrite32_rep(void *port, const void *buf, unsigned long count);


extern void *ioport_map(unsigned long port, unsigned int nr);
extern void ioport_unmap(void *);


struct pci_dev;
extern void *pci_iomap(struct pci_dev *dev, int bar, unsigned long max);
extern void pci_iounmap(struct pci_dev *dev, void *);
# 48 "include/asm/io.h" 2

# 1 "include/linux/vmalloc.h" 1






struct vm_area_struct;
# 25 "include/linux/vmalloc.h"
struct vm_struct {

 struct vm_struct *next;
 void *addr;
 unsigned long size;
 unsigned long flags;
 struct page **pages;
 unsigned int nr_pages;
 unsigned long phys_addr;
};




extern void *vmalloc(unsigned long size);
extern void *vmalloc_user(unsigned long size);
extern void *vmalloc_node(unsigned long size, int node);
extern void *vmalloc_exec(unsigned long size);
extern void *vmalloc_32(unsigned long size);
extern void *vmalloc_32_user(unsigned long size);
extern void *__vmalloc(unsigned long size, gfp_t gfp_mask, pgprot_t prot);
extern void *__vmalloc_area(struct vm_struct *area, gfp_t gfp_mask,
    pgprot_t prot);
extern void vfree(void *addr);

extern void *vmap(struct page **pages, unsigned int count,
   unsigned long flags, pgprot_t prot);
extern void vunmap(void *addr);

extern int remap_vmalloc_range(struct vm_area_struct *vma, void *addr,
       unsigned long pgoff);
void vmalloc_sync_all(void);




extern struct vm_struct *get_vm_area(unsigned long size, unsigned long flags);
extern struct vm_struct *__get_vm_area(unsigned long size, unsigned long flags,
     unsigned long start, unsigned long end);
extern struct vm_struct *get_vm_area_node(unsigned long size,
       unsigned long flags, int node,
       gfp_t gfp_mask);
extern struct vm_struct *remove_vm_area(void *addr);
extern int map_vm_area(struct vm_struct *area, pgprot_t prot,
   struct page ***pages);
extern void unmap_vm_area(struct vm_struct *area);




extern rwlock_t vmlist_lock;
extern struct vm_struct *vmlist;
# 50 "include/asm/io.h" 2
# 75 "include/asm/io.h"
static inline __attribute__((always_inline)) unsigned long virt_to_phys(volatile void * address)
{
 return ((unsigned long)(address)-((unsigned long)((unsigned long)0xC0000000)));
}
# 93 "include/asm/io.h"
static inline __attribute__((always_inline)) void * phys_to_virt(unsigned long address)
{
 return ((void *)((unsigned long)(address)+((unsigned long)((unsigned long)0xC0000000))));
}






extern void * __ioremap(unsigned long offset, unsigned long size, unsigned long flags);
# 117 "include/asm/io.h"
static inline __attribute__((always_inline)) void * ioremap(unsigned long offset, unsigned long size)
{
 return __ioremap(offset, size, 0);
}

extern void * ioremap_nocache(unsigned long offset, unsigned long size);
extern void iounmap(volatile void *addr);






extern void *bt_ioremap(unsigned long offset, unsigned long size);
extern void bt_iounmap(void *addr, unsigned long size);
# 161 "include/asm/io.h"
static inline __attribute__((always_inline)) unsigned char readb(const volatile void *addr)
{
 return *(volatile unsigned char *) addr;
}
static inline __attribute__((always_inline)) unsigned short readw(const volatile void *addr)
{
 return *(volatile unsigned short *) addr;
}
static inline __attribute__((always_inline)) unsigned int readl(const volatile void *addr)
{
 return *(volatile unsigned int *) addr;
}







static inline __attribute__((always_inline)) void writeb(unsigned char b, volatile void *addr)
{
 *(volatile unsigned char *) addr = b;
}
static inline __attribute__((always_inline)) void writew(unsigned short b, volatile void *addr)
{
 *(volatile unsigned short *) addr = b;
}
static inline __attribute__((always_inline)) void writel(unsigned int b, volatile void *addr)
{
 *(volatile unsigned int *) addr = b;
}






static inline __attribute__((always_inline)) void memset_io(volatile void *addr, unsigned char val, int count)
{
 (__builtin_constant_p(val) ? (__builtin_constant_p((count)) ? __constant_c_and_count_memset((((void *) addr)),((0x01010101UL*(unsigned char)(val))),((count))) : __constant_c_memset((((void *) addr)),((0x01010101UL*(unsigned char)(val))),((count)))) : (__builtin_constant_p((count)) ? __memset_generic(((((void *) addr))),(((val))),(((count)))) : __memset_generic((((void *) addr)),((val)),((count)))));
}
static inline __attribute__((always_inline)) void memcpy_fromio(void *dst, const volatile void *src, int count)
{
 __memcpy(dst, (void *) src, count);
}
static inline __attribute__((always_inline)) void memcpy_toio(volatile void *dst, const void *src, int count)
{
 __memcpy((void *) dst, src, count);
}
# 231 "include/asm/io.h"
static inline __attribute__((always_inline)) void flush_write_buffers(void)
{
 __asm__ __volatile__ ("lock; addl $0,0(%%esp)": : :"memory");
}
# 253 "include/asm/io.h"
static inline __attribute__((always_inline)) void native_io_delay(void)
{
 asm volatile("outb %%al,$0x80" : : : "memory");
}
# 341 "include/asm/io.h"
static inline __attribute__((always_inline)) void outb_local(unsigned char value, int port) { __asm__ __volatile__("out" "b" " %" "b" "0, %w1" : : "a"(value), "Nd"(port)); } static inline __attribute__((always_inline)) unsigned char inb_local(int port) { unsigned char value; __asm__ __volatile__("in" "b" " %w1, %" "b" "0" : "=a"(value) : "Nd"(port)); return value; } static inline __attribute__((always_inline)) void outb_local_p(unsigned char value, int port) { outb_local(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned char inb_local_p(int port) { unsigned char value = inb_local(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outb(unsigned char value, int port) { outb_local(value, port); } static inline __attribute__((always_inline)) unsigned char inb(int port) { return inb_local(port); } static inline __attribute__((always_inline)) void outb_p(unsigned char value, int port) { outb(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned char inb_p(int port) { unsigned char value = inb(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outsb(int port, const void *addr, unsigned long count) { __asm__ __volatile__("rep; outs" "b" : "+S"(addr), "+c"(count) : "d"(port)); } static inline __attribute__((always_inline)) void insb(int port, void *addr, unsigned long count) { __asm__ __volatile__("rep; ins" "b" : "+D"(addr), "+c"(count) : "d"(port)); }
static inline __attribute__((always_inline)) void outw_local(unsigned short value, int port) { __asm__ __volatile__("out" "w" " %" "w" "0, %w1" : : "a"(value), "Nd"(port)); } static inline __attribute__((always_inline)) unsigned short inw_local(int port) { unsigned short value; __asm__ __volatile__("in" "w" " %w1, %" "w" "0" : "=a"(value) : "Nd"(port)); return value; } static inline __attribute__((always_inline)) void outw_local_p(unsigned short value, int port) { outw_local(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned short inw_local_p(int port) { unsigned short value = inw_local(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outw(unsigned short value, int port) { outw_local(value, port); } static inline __attribute__((always_inline)) unsigned short inw(int port) { return inw_local(port); } static inline __attribute__((always_inline)) void outw_p(unsigned short value, int port) { outw(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned short inw_p(int port) { unsigned short value = inw(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outsw(int port, const void *addr, unsigned long count) { __asm__ __volatile__("rep; outs" "w" : "+S"(addr), "+c"(count) : "d"(port)); } static inline __attribute__((always_inline)) void insw(int port, void *addr, unsigned long count) { __asm__ __volatile__("rep; ins" "w" : "+D"(addr), "+c"(count) : "d"(port)); }
static inline __attribute__((always_inline)) void outl_local(unsigned int value, int port) { __asm__ __volatile__("out" "l" " %" "" "0, %w1" : : "a"(value), "Nd"(port)); } static inline __attribute__((always_inline)) unsigned int inl_local(int port) { unsigned int value; __asm__ __volatile__("in" "l" " %w1, %" "" "0" : "=a"(value) : "Nd"(port)); return value; } static inline __attribute__((always_inline)) void outl_local_p(unsigned int value, int port) { outl_local(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned int inl_local_p(int port) { unsigned int value = inl_local(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outl(unsigned int value, int port) { outl_local(value, port); } static inline __attribute__((always_inline)) unsigned int inl(int port) { return inl_local(port); } static inline __attribute__((always_inline)) void outl_p(unsigned int value, int port) { outl(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned int inl_p(int port) { unsigned int value = inl(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outsl(int port, const void *addr, unsigned long count) { __asm__ __volatile__("rep; outs" "l" : "+S"(addr), "+c"(count) : "d"(port)); } static inline __attribute__((always_inline)) void insl(int port, void *addr, unsigned long count) { __asm__ __volatile__("rep; ins" "l" : "+D"(addr), "+c"(count) : "d"(port)); }
# 29 "include/linux/bio.h" 2
# 57 "include/linux/bio.h"
struct bio_vec {
 struct page *bv_page;
 unsigned int bv_len;
 unsigned int bv_offset;
};

struct bio_set;
struct bio;
typedef int (bio_end_io_t) (struct bio *, unsigned int, int);
typedef void (bio_destructor_t) (struct bio *);





struct bio {
 sector_t bi_sector;

 struct bio *bi_next;
 struct block_device *bi_bdev;
 unsigned long bi_flags;
 unsigned long bi_rw;



 unsigned short bi_vcnt;
 unsigned short bi_idx;




 unsigned short bi_phys_segments;




 unsigned short bi_hw_segments;

 unsigned int bi_size;






 unsigned int bi_hw_front_size;
 unsigned int bi_hw_back_size;

 unsigned int bi_max_vecs;

 struct bio_vec *bi_io_vec;

 bio_end_io_t *bi_end_io;
 atomic_t bi_cnt;

 void *bi_private;

 bio_destructor_t *bi_destructor;
};
# 268 "include/linux/bio.h"
struct bio_pair {
 struct bio bio1, bio2;
 struct bio_vec bv1, bv2;
 atomic_t cnt;
 int error;
};
extern struct bio_pair *bio_split(struct bio *bi, mempool_t *pool,
      int first_sectors);
extern mempool_t *bio_split_pool;
extern void bio_pair_release(struct bio_pair *dbio);

extern struct bio_set *bioset_create(int, int);
extern void bioset_free(struct bio_set *);

extern struct bio *bio_alloc(gfp_t, int);
extern struct bio *bio_alloc_bioset(gfp_t, int, struct bio_set *);
extern void bio_put(struct bio *);
extern void bio_free(struct bio *, struct bio_set *);

extern void bio_endio(struct bio *, unsigned int, int);
struct request_queue;
extern int bio_phys_segments(struct request_queue *, struct bio *);
extern int bio_hw_segments(struct request_queue *, struct bio *);

extern void __bio_clone(struct bio *, struct bio *);
extern struct bio *bio_clone(struct bio *, gfp_t);

extern void bio_init(struct bio *);

extern int bio_add_page(struct bio *, struct page *, unsigned int,unsigned int);
extern int bio_add_pc_page(struct request_queue *, struct bio *, struct page *,
      unsigned int, unsigned int);
extern int bio_get_nr_vecs(struct block_device *);
extern struct bio *bio_map_user(struct request_queue *, struct block_device *,
    unsigned long, unsigned int, int);
struct sg_iovec;
extern struct bio *bio_map_user_iov(struct request_queue *,
        struct block_device *,
        struct sg_iovec *, int, int);
extern void bio_unmap_user(struct bio *);
extern struct bio *bio_map_kern(struct request_queue *, void *, unsigned int,
    gfp_t);
extern void bio_set_pages_dirty(struct bio *bio);
extern void bio_check_pages_dirty(struct bio *bio);
extern void bio_release_pages(struct bio *bio);
extern struct bio *bio_copy_user(struct request_queue *, unsigned long, unsigned int, int);
extern int bio_uncopy_user(struct bio *);
void zero_fill_bio(struct bio *bio);
# 324 "include/linux/bio.h"
static inline __attribute__((always_inline)) char *bvec_kmap_irq(struct bio_vec *bvec, unsigned long *flags)
{
 unsigned long addr;





 do { do { (*flags) = __raw_local_irq_save(); } while (0); trace_hardirqs_off(); } while (0);
 addr = (unsigned long) kmap_atomic(bvec->bv_page, KM_BIO_SRC_IRQ);

 do { if (__builtin_expect(!!((addr & ~(~((1UL << 12)-1)))!=0), 0)) do { asm volatile("1:\tud2\n" ".pushsection __bug_table,\"a\"\n" "2:\t.long 1b, %c0\n" "\t.word %c1, 0\n" "\t.org 2b+%c2\n" ".popsection" : : "i" ("include/linux/bio.h"), "i" (335), "i" (sizeof(struct bug_entry))); for(;;) ; } while(0); } while(0);

 return (char *) addr + bvec->bv_offset;
}

static inline __attribute__((always_inline)) void bvec_kunmap_irq(char *buffer, unsigned long *flags)
{
 unsigned long ptr = (unsigned long) buffer & (~((1UL << 12)-1));

 kunmap_atomic((void *) ptr, KM_BIO_SRC_IRQ);
 do { if (raw_irqs_disabled_flags(*flags)) { raw_local_irq_restore(*flags); trace_hardirqs_off(); } else { trace_hardirqs_on(); raw_local_irq_restore(*flags); } } while (0);
}






static inline __attribute__((always_inline)) char *__bio_kmap_irq(struct bio *bio, unsigned short idx,
       unsigned long *flags)
{
 return bvec_kmap_irq((&((bio)->bi_io_vec[(idx)])), flags);
}
# 172 "drivers/block/floppy.c" 2




# 1 "include/linux/mc146818rtc.h" 1
# 15 "include/linux/mc146818rtc.h"
# 1 "include/linux/rtc.h" 1
# 20 "include/linux/rtc.h"
struct rtc_time {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
};





struct rtc_wkalrm {
 unsigned char enabled;
 unsigned char pending;
 struct rtc_time time;
};
# 55 "include/linux/rtc.h"
struct rtc_pll_info {
 int pll_ctrl;
 int pll_value;
 int pll_max;
 int pll_min;
 int pll_posmult;
 int pll_negmult;
 long pll_clock;
};
# 104 "include/linux/rtc.h"
extern int rtc_month_days(unsigned int month, unsigned int year);
extern int rtc_year_days(unsigned int day, unsigned int month, unsigned int year);
extern int rtc_valid_tm(struct rtc_time *tm);
extern int rtc_tm_to_time(struct rtc_time *tm, unsigned long *time);
extern void rtc_time_to_tm(unsigned long time, struct rtc_time *tm);


# 1 "include/linux/seq_file.h" 1
# 9 "include/linux/seq_file.h"
struct seq_operations;
struct file;
struct vfsmount;
struct dentry;
struct inode;

struct seq_file {
 char *buf;
 size_t size;
 size_t from;
 size_t count;
 loff_t index;
 loff_t version;
 struct mutex lock;
 const struct seq_operations *op;
 void *private;
};

struct seq_operations {
 void * (*start) (struct seq_file *m, loff_t *pos);
 void (*stop) (struct seq_file *m, void *v);
 void * (*next) (struct seq_file *m, void *v, loff_t *pos);
 int (*show) (struct seq_file *m, void *v);
};

int seq_open(struct file *, const struct seq_operations *);
ssize_t seq_read(struct file *, char *, size_t, loff_t *);
loff_t seq_lseek(struct file *, loff_t, int);
int seq_release(struct inode *, struct file *);
int seq_escape(struct seq_file *, const char *, const char *);
int seq_putc(struct seq_file *m, char c);
int seq_puts(struct seq_file *m, const char *s);

int seq_printf(struct seq_file *, const char *, ...)
 __attribute__ ((format (printf,2,3)));

int seq_path(struct seq_file *, struct vfsmount *, struct dentry *, char *);

int single_open(struct file *, int (*)(struct seq_file *, void *), void *);
int single_release(struct inode *, struct file *);
int seq_release_private(struct inode *, struct file *);







extern struct list_head *seq_list_start(struct list_head *head,
  loff_t pos);
extern struct list_head *seq_list_start_head(struct list_head *head,
  loff_t pos);
extern struct list_head *seq_list_next(void *v, struct list_head *head,
  loff_t *ppos);
# 112 "include/linux/rtc.h" 2
# 1 "include/linux/cdev.h" 1
# 9 "include/linux/cdev.h"
struct file_operations;
struct inode;
struct module;

struct cdev {
 struct kobject kobj;
 struct module *owner;
 const struct file_operations *ops;
 struct list_head list;
 dev_t dev;
 unsigned int count;
};

void cdev_init(struct cdev *, const struct file_operations *);

struct cdev *cdev_alloc(void);

void cdev_put(struct cdev *p);

int cdev_add(struct cdev *, dev_t, unsigned);

void cdev_del(struct cdev *);

void cd_forget(struct inode *);

extern struct backing_dev_info directly_mappable_cdev_bdi;
# 113 "include/linux/rtc.h" 2
# 1 "include/linux/poll.h" 1



# 1 "include/asm/poll.h" 1
# 1 "include/asm-generic/poll.h" 1
# 31 "include/asm-generic/poll.h"
struct pollfd {
 int fd;
 short events;
 short revents;
};
# 1 "include/asm/poll.h" 2
# 5 "include/linux/poll.h" 2
# 24 "include/linux/poll.h"
struct poll_table_struct;




typedef void (*poll_queue_proc)(struct file *, wait_queue_head_t *, struct poll_table_struct *);

typedef struct poll_table_struct {
 poll_queue_proc qproc;
} poll_table;

static inline __attribute__((always_inline)) void poll_wait(struct file * filp, wait_queue_head_t * wait_address, poll_table *p)
{
 if (p && wait_address)
  p->qproc(filp, wait_address, p);
}

static inline __attribute__((always_inline)) void init_poll_funcptr(poll_table *pt, poll_queue_proc qproc)
{
 pt->qproc = qproc;
}

struct poll_table_entry {
 struct file * filp;
 wait_queue_t wait;
 wait_queue_head_t * wait_address;
};




struct poll_wqueues {
 poll_table pt;
 struct poll_table_page * table;
 int error;
 int inline_index;
 struct poll_table_entry inline_entries[((832 - 256) / sizeof(struct poll_table_entry))];
};

extern void poll_initwait(struct poll_wqueues *pwq);
extern void poll_freewait(struct poll_wqueues *pwq);





typedef struct {
 unsigned long *in, *out, *ex;
 unsigned long *res_in, *res_out, *res_ex;
} fd_set_bits;
# 88 "include/linux/poll.h"
static inline __attribute__((always_inline))
int get_fd_set(unsigned long nr, void *ufdset, unsigned long *fdset)
{
 nr = ((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long));
 if (ufdset)
  return copy_from_user(fdset, ufdset, nr) ? -14 : 0;

 (__builtin_constant_p(0) ? (__builtin_constant_p((nr)) ? __constant_c_and_count_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((nr))) : __constant_c_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((nr)))) : (__builtin_constant_p((nr)) ? __memset_generic((((fdset))),(((0))),(((nr)))) : __memset_generic(((fdset)),((0)),((nr)))));
 return 0;
}

static inline __attribute__((always_inline)) unsigned long __attribute__((warn_unused_result))
set_fd_set(unsigned long nr, void *ufdset, unsigned long *fdset)
{
 if (ufdset)
  return __copy_to_user(ufdset, fdset, ((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)));
 return 0;
}

static inline __attribute__((always_inline))
void zero_fd_set(unsigned long nr, unsigned long *fdset)
{
 (__builtin_constant_p(0) ? (__builtin_constant_p((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))) ? __constant_c_and_count_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long))))) : __constant_c_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))))) : (__builtin_constant_p((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))) ? __memset_generic((((fdset))),(((0))),(((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))))) : __memset_generic(((fdset)),((0)),((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))))));
}



extern int do_select(int n, fd_set_bits *fds, s64 *timeout);
extern int do_sys_poll(struct pollfd * ufds, unsigned int nfds,
         s64 *timeout);
# 114 "include/linux/rtc.h" 2


extern struct class *rtc_class;

struct rtc_class_ops {
 int (*open)(struct device *);
 void (*release)(struct device *);
 int (*ioctl)(struct device *, unsigned int, unsigned long);
 int (*read_time)(struct device *, struct rtc_time *);
 int (*set_time)(struct device *, struct rtc_time *);
 int (*read_alarm)(struct device *, struct rtc_wkalrm *);
 int (*set_alarm)(struct device *, struct rtc_wkalrm *);
 int (*proc)(struct device *, struct seq_file *);
 int (*set_mmss)(struct device *, unsigned long secs);
 int (*irq_set_state)(struct device *, int enabled);
 int (*irq_set_freq)(struct device *, int freq);
 int (*read_callback)(struct device *, int data);
};


struct rtc_task;

struct rtc_device
{
 struct device dev;
 struct module *owner;

 int id;
 char name[20];

 const struct rtc_class_ops *ops;
 struct mutex ops_lock;

 struct cdev char_dev;
 struct mutex char_lock;

 unsigned long irq_data;
 spinlock_t irq_lock;
 wait_queue_head_t irq_queue;
 struct fasync_struct *async_queue;

 struct rtc_task *irq_task;
 spinlock_t irq_task_lock;
 int irq_freq;
 int max_user_freq;

 struct work_struct uie_task;
 struct timer_list uie_timer;

 unsigned int oldsecs;
 unsigned int irq_active:1;
 unsigned int stop_uie_polling:1;
 unsigned int uie_task_active:1;
 unsigned int uie_timer_active:1;

};


extern struct rtc_device *rtc_device_register(const char *name,
     struct device *dev,
     const struct rtc_class_ops *ops,
     struct module *owner);
extern void rtc_device_unregister(struct rtc_device *rtc);

extern int rtc_read_time(struct rtc_device *rtc, struct rtc_time *tm);
extern int rtc_set_time(struct rtc_device *rtc, struct rtc_time *tm);
extern int rtc_set_mmss(struct rtc_device *rtc, unsigned long secs);
extern int rtc_read_alarm(struct rtc_device *rtc,
   struct rtc_wkalrm *alrm);
extern int rtc_set_alarm(struct rtc_device *rtc,
    struct rtc_wkalrm *alrm);
extern void rtc_update_irq(struct rtc_device *rtc,
   unsigned long num, unsigned long events);

extern struct rtc_device *rtc_class_open(char *name);
extern void rtc_class_close(struct rtc_device *rtc);

extern int rtc_irq_register(struct rtc_device *rtc,
    struct rtc_task *task);
extern void rtc_irq_unregister(struct rtc_device *rtc,
    struct rtc_task *task);
extern int rtc_irq_set_state(struct rtc_device *rtc,
    struct rtc_task *task, int enabled);
extern int rtc_irq_set_freq(struct rtc_device *rtc,
    struct rtc_task *task, int freq);

typedef struct rtc_task {
 void (*func)(void *private_data);
 void *private_data;
} rtc_task_t;

int rtc_register(rtc_task_t *task);
int rtc_unregister(rtc_task_t *task);
int rtc_control(rtc_task_t *t, unsigned int cmd, unsigned long arg);
void rtc_get_rtc_time(struct rtc_time *rtc_tm);
irqreturn_t rtc_interrupt(int irq, void *dev_id);
# 16 "include/linux/mc146818rtc.h" 2
# 1 "include/asm/mc146818rtc.h" 1
# 9 "include/asm/mc146818rtc.h"
# 1 "include/linux/mc146818rtc.h" 1
# 10 "include/asm/mc146818rtc.h" 2
# 34 "include/asm/mc146818rtc.h"
extern volatile unsigned long cmos_lock;






static inline __attribute__((always_inline)) void lock_cmos(unsigned char reg)
{
 unsigned long new;
 new = (((({ typeof(per_cpu__cpu_number) ret__; switch (sizeof(per_cpu__cpu_number)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; default: __bad_percpu_size(); } ret__; }))+1) << 8) | reg;
 for (;;) {
  if (cmos_lock)
   continue;
  if (__cmpxchg(&cmos_lock, 0, new, sizeof(cmos_lock)) == 0)
   return;
 }
}

static inline __attribute__((always_inline)) void unlock_cmos(void)
{
 cmos_lock = 0;
}
static inline __attribute__((always_inline)) int do_i_have_lock_cmos(void)
{
 return (cmos_lock >> 8) == ((({ typeof(per_cpu__cpu_number) ret__; switch (sizeof(per_cpu__cpu_number)) { case 1: asm("mov" "b ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 2: asm("mov" "w ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; case 4: asm("mov" "l ""%%fs:""%1,%0" : "=r" (ret__) : "m" (per_cpu__cpu_number)); break; default: __bad_percpu_size(); } ret__; }))+1);
}
static inline __attribute__((always_inline)) unsigned char current_lock_cmos_reg(void)
{
 return cmos_lock & 0xff;
}
# 89 "include/asm/mc146818rtc.h"
unsigned char rtc_cmos_read(unsigned char addr);
void rtc_cmos_write(unsigned char val, unsigned char addr);
# 17 "include/linux/mc146818rtc.h" 2



extern spinlock_t rtc_lock;
# 30 "include/linux/mc146818rtc.h"
struct cmos_rtc_board_info {
 void (*wake_on)(struct device *dev);
 void (*wake_off)(struct device *dev);

 u8 rtc_day_alarm;
 u8 rtc_mon_alarm;
 u8 rtc_century;
};
# 177 "drivers/block/floppy.c" 2



# 1 "include/linux/platform_device.h" 1
# 16 "include/linux/platform_device.h"
struct platform_device {
 const char * name;
 u32 id;
 struct device dev;
 u32 num_resources;
 struct resource * resource;
};



extern int platform_device_register(struct platform_device *);
extern void platform_device_unregister(struct platform_device *);

extern struct bus_type platform_bus_type;
extern struct device platform_bus;

extern struct resource *platform_get_resource(struct platform_device *, unsigned int, unsigned int);
extern int platform_get_irq(struct platform_device *, unsigned int);
extern struct resource *platform_get_resource_byname(struct platform_device *, unsigned int, char *);
extern int platform_get_irq_byname(struct platform_device *, char *);
extern int platform_add_devices(struct platform_device **, int);

extern struct platform_device *platform_device_register_simple(char *, unsigned int, struct resource *, unsigned int);

extern struct platform_device *platform_device_alloc(const char *name, unsigned int id);
extern int platform_device_add_resources(struct platform_device *pdev, struct resource *res, unsigned int num);
extern int platform_device_add_data(struct platform_device *pdev, const void *data, size_t size);
extern int platform_device_add(struct platform_device *pdev);
extern void platform_device_del(struct platform_device *pdev);
extern void platform_device_put(struct platform_device *pdev);

struct platform_driver {
 int (*probe)(struct platform_device *);
 int (*remove)(struct platform_device *);
 void (*shutdown)(struct platform_device *);
 int (*suspend)(struct platform_device *, pm_message_t state);
 int (*suspend_late)(struct platform_device *, pm_message_t state);
 int (*resume_early)(struct platform_device *);
 int (*resume)(struct platform_device *);
 struct device_driver driver;
};

extern int platform_driver_register(struct platform_driver *);
extern void platform_driver_unregister(struct platform_driver *);




extern int platform_driver_probe(struct platform_driver *driver,
  int (*probe)(struct platform_device *));
# 181 "drivers/block/floppy.c" 2
# 1 "include/linux/buffer_head.h" 1
# 13 "include/linux/buffer_head.h"
# 1 "include/linux/pagemap.h" 1
# 23 "include/linux/pagemap.h"
static inline __attribute__((always_inline)) void mapping_set_error(struct address_space *mapping, int error)
{
 if (error) {
  if (error == -28)
   set_bit((20 + 1), &mapping->flags);
  else
   set_bit((20 + 0), &mapping->flags);
 }
}

static inline __attribute__((always_inline)) gfp_t mapping_gfp_mask(struct address_space * mapping)
{
 return ( gfp_t)mapping->flags & (( gfp_t)((1 << 20) - 1));
}





static inline __attribute__((always_inline)) void mapping_set_gfp_mask(struct address_space *m, gfp_t mask)
{
 m->flags = (m->flags & ~( unsigned long)(( gfp_t)((1 << 20) - 1))) |
    ( unsigned long)mask;
}
# 63 "include/linux/pagemap.h"
void release_pages(struct page **pages, int nr, int cold);




static inline __attribute__((always_inline)) struct page *__page_cache_alloc(gfp_t gfp)
{
 return alloc_pages_node(((0)), gfp, 0);
}


static inline __attribute__((always_inline)) struct page *page_cache_alloc(struct address_space *x)
{
 return __page_cache_alloc(mapping_gfp_mask(x));
}

static inline __attribute__((always_inline)) struct page *page_cache_alloc_cold(struct address_space *x)
{
 return __page_cache_alloc(mapping_gfp_mask(x)|(( gfp_t)0x100u));
}

typedef int filler_t(void *, struct page *);

extern struct page * find_get_page(struct address_space *mapping,
    unsigned long index);
extern struct page * find_lock_page(struct address_space *mapping,
    unsigned long index);
extern struct page * find_or_create_page(struct address_space *mapping,
    unsigned long index, gfp_t gfp_mask);
unsigned find_get_pages(struct address_space *mapping, unsigned long start,
   unsigned int nr_pages, struct page **pages);
unsigned find_get_pages_contig(struct address_space *mapping, unsigned long start,
          unsigned int nr_pages, struct page **pages);
unsigned find_get_pages_tag(struct address_space *mapping, unsigned long *index,
   int tag, unsigned int nr_pages, struct page **pages);




static inline __attribute__((always_inline)) struct page *grab_cache_page(struct address_space *mapping, unsigned long index)
{
 return find_or_create_page(mapping, index, mapping_gfp_mask(mapping));
}

extern struct page * grab_cache_page_nowait(struct address_space *mapping,
    unsigned long index);
extern struct page * read_cache_page_async(struct address_space *mapping,
    unsigned long index, filler_t *filler,
    void *data);
extern struct page * read_cache_page(struct address_space *mapping,
    unsigned long index, filler_t *filler,
    void *data);
extern int read_cache_pages(struct address_space *mapping,
  struct list_head *pages, filler_t *filler, void *data);

static inline __attribute__((always_inline)) struct page *read_mapping_page_async(
      struct address_space *mapping,
          unsigned long index, void *data)
{
 filler_t *filler = (filler_t *)mapping->a_ops->readpage;
 return read_cache_page_async(mapping, index, filler, data);
}

static inline __attribute__((always_inline)) struct page *read_mapping_page(struct address_space *mapping,
          unsigned long index, void *data)
{
 filler_t *filler = (filler_t *)mapping->a_ops->readpage;
 return read_cache_page(mapping, index, filler, data);
}

int add_to_page_cache(struct page *page, struct address_space *mapping,
    unsigned long index, gfp_t gfp_mask);
int add_to_page_cache_lru(struct page *page, struct address_space *mapping,
    unsigned long index, gfp_t gfp_mask);
extern void remove_from_page_cache(struct page *page);
extern void __remove_from_page_cache(struct page *page);




static inline __attribute__((always_inline)) loff_t page_offset(struct page *page)
{
 return ((loff_t)page->index) << 12;
}

static inline __attribute__((always_inline)) unsigned long linear_page_index(struct vm_area_struct *vma,
     unsigned long address)
{
 unsigned long pgoff = (address - vma->vm_start) >> 12;
 pgoff += vma->vm_pgoff;
 return pgoff >> (12 - 12);
}

extern void __lock_page(struct page *page) __attribute__((regparm(3)));
extern void __lock_page_nosync(struct page *page) __attribute__((regparm(3)));
extern void unlock_page(struct page *page) __attribute__((regparm(3)));




static inline __attribute__((always_inline)) void lock_page(struct page *page)
{
 do { __might_sleep("include/linux/pagemap.h", 165); do { } while (0); } while (0);
 if (test_and_set_bit(0, &(page)->flags))
  __lock_page(page);
}





static inline __attribute__((always_inline)) void lock_page_nosync(struct page *page)
{
 do { __might_sleep("include/linux/pagemap.h", 176); do { } while (0); } while (0);
 if (test_and_set_bit(0, &(page)->flags))
  __lock_page_nosync(page);
}





extern void wait_on_page_bit(struct page *page, int bit_nr) __attribute__((regparm(3)));
# 194 "include/linux/pagemap.h"
static inline __attribute__((always_inline)) void wait_on_page_locked(struct page *page)
{
 if ((__builtin_constant_p(0) ? constant_test_bit((0),(&(page)->flags)) : variable_test_bit((0),(&(page)->flags))))
  wait_on_page_bit(page, 0);
}




static inline __attribute__((always_inline)) void wait_on_page_writeback(struct page *page)
{
 if ((__builtin_constant_p(12) ? constant_test_bit((12),(&(page)->flags)) : variable_test_bit((12),(&(page)->flags))))
  wait_on_page_bit(page, 12);
}

extern void end_page_writeback(struct page *page);







static inline __attribute__((always_inline)) int fault_in_pages_writeable(char *uaddr, int size)
{
 int ret;





 ret = ({ long __pu_err; do { __pu_err = 0; (void)0; switch ((sizeof(*(uaddr)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__pu_err) : "iq" (((__typeof__(*(uaddr)))(0))), "m"((*(struct __large_struct *)(((uaddr))))), "i"(-14), "0"(__pu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__pu_err) : "ir" (((__typeof__(*(uaddr)))(0))), "m"((*(struct __large_struct *)(((uaddr))))), "i"(-14), "0"(__pu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__pu_err) : "ir" (((__typeof__(*(uaddr)))(0))), "m"((*(struct __large_struct *)(((uaddr))))), "i"(-14), "0"(__pu_err)); break; case 8: __asm__ __volatile__( "1:	movl %%eax,0(%2)\n" "2:	movl %%edx,4(%2)\n" "3:\n" ".section .fixup,\"ax\"\n" "4:	movl %3,%0\n" "	jmp 3b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,4b\n" "	.long 2b,4b\n" ".previous" : "=r"(__pu_err) : "A" ((__typeof__(*((uaddr))))(((__typeof__(*(uaddr)))(0)))), "r" (((uaddr))), "i"(-14), "0"(__pu_err)); break; default: __put_user_bad(); } } while (0); __pu_err; });
 if (ret == 0) {
  char *end = uaddr + size - 1;





  if (((unsigned long)uaddr & (~((1UL << 12)-1))) !=
    ((unsigned long)end & (~((1UL << 12)-1))))
    ret = ({ long __pu_err; do { __pu_err = 0; (void)0; switch ((sizeof(*(end)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__pu_err) : "iq" (((__typeof__(*(end)))(0))), "m"((*(struct __large_struct *)(((end))))), "i"(-14), "0"(__pu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__pu_err) : "ir" (((__typeof__(*(end)))(0))), "m"((*(struct __large_struct *)(((end))))), "i"(-14), "0"(__pu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__pu_err) : "ir" (((__typeof__(*(end)))(0))), "m"((*(struct __large_struct *)(((end))))), "i"(-14), "0"(__pu_err)); break; case 8: __asm__ __volatile__( "1:	movl %%eax,0(%2)\n" "2:	movl %%edx,4(%2)\n" "3:\n" ".section .fixup,\"ax\"\n" "4:	movl %3,%0\n" "	jmp 3b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,4b\n" "	.long 2b,4b\n" ".previous" : "=r"(__pu_err) : "A" ((__typeof__(*((end))))(((__typeof__(*(end)))(0)))), "r" (((end))), "i"(-14), "0"(__pu_err)); break; default: __put_user_bad(); } } while (0); __pu_err; });
 }
 return ret;
}

static inline __attribute__((always_inline)) void fault_in_pages_readable(const char *uaddr, int size)
{
 volatile char c;
 int ret;

 ret = ({ long __gu_err; unsigned long __gu_val; do { __gu_err = 0; (void)0; switch ((sizeof(*(uaddr)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=q" (__gu_val) : "m"((*(struct __large_struct *)(((uaddr))))), "i"(-14), "0"(__gu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((uaddr))))), "i"(-14), "0"(__gu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((uaddr))))), "i"(-14), "0"(__gu_err));break; default: (__gu_val) = __get_user_bad(); } } while (0); ((c)) = (__typeof__(*((uaddr))))__gu_val; __gu_err; });
 if (ret == 0) {
  const char *end = uaddr + size - 1;

  if (((unsigned long)uaddr & (~((1UL << 12)-1))) !=
    ((unsigned long)end & (~((1UL << 12)-1))))
    ({ long __gu_err; unsigned long __gu_val; do { __gu_err = 0; (void)0; switch ((sizeof(*(end)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=q" (__gu_val) : "m"((*(struct __large_struct *)(((end))))), "i"(-14), "0"(__gu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((end))))), "i"(-14), "0"(__gu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((end))))), "i"(-14), "0"(__gu_err));break; default: (__gu_val) = __get_user_bad(); } } while (0); ((c)) = (__typeof__(*((end))))__gu_val; __gu_err; });
 }
}
# 14 "include/linux/buffer_head.h" 2





enum bh_state_bits {
 BH_Uptodate,
 BH_Dirty,
 BH_Lock,
 BH_Req,
 BH_Uptodate_Lock,



 BH_Mapped,
 BH_New,
 BH_Async_Read,
 BH_Async_Write,
 BH_Delay,
 BH_Boundary,
 BH_Write_EIO,
 BH_Ordered,
 BH_Eopnotsupp,
 BH_Unwritten,

 BH_PrivateStart,


};



struct page;
struct buffer_head;
struct address_space;
typedef void (bh_end_io_t)(struct buffer_head *bh, int uptodate);
# 60 "include/linux/buffer_head.h"
struct buffer_head {
 unsigned long b_state;
 struct buffer_head *b_this_page;
 struct page *b_page;

 sector_t b_blocknr;
 size_t b_size;
 char *b_data;

 struct block_device *b_bdev;
 bh_end_io_t *b_end_io;
  void *b_private;
 struct list_head b_assoc_buffers;
 struct address_space *b_assoc_map;

 atomic_t b_count;
};
# 114 "include/linux/buffer_head.h"
static inline __attribute__((always_inline)) void set_buffer_uptodate(struct buffer_head *bh) { set_bit(BH_Uptodate, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_uptodate(struct buffer_head *bh) { clear_bit(BH_Uptodate, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_uptodate(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Uptodate) ? constant_test_bit((BH_Uptodate),(&(bh)->b_state)) : variable_test_bit((BH_Uptodate),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_dirty(struct buffer_head *bh) { set_bit(BH_Dirty, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_dirty(struct buffer_head *bh) { clear_bit(BH_Dirty, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_dirty(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Dirty) ? constant_test_bit((BH_Dirty),(&(bh)->b_state)) : variable_test_bit((BH_Dirty),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) int test_set_buffer_dirty(struct buffer_head *bh) { return test_and_set_bit(BH_Dirty, &(bh)->b_state); } static inline __attribute__((always_inline)) int test_clear_buffer_dirty(struct buffer_head *bh) { return test_and_clear_bit(BH_Dirty, &(bh)->b_state); }
static inline __attribute__((always_inline)) void set_buffer_locked(struct buffer_head *bh) { set_bit(BH_Lock, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_locked(struct buffer_head *bh) { clear_bit(BH_Lock, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_locked(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Lock) ? constant_test_bit((BH_Lock),(&(bh)->b_state)) : variable_test_bit((BH_Lock),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) int test_set_buffer_locked(struct buffer_head *bh) { return test_and_set_bit(BH_Lock, &(bh)->b_state); } static inline __attribute__((always_inline)) int test_clear_buffer_locked(struct buffer_head *bh) { return test_and_clear_bit(BH_Lock, &(bh)->b_state); }
static inline __attribute__((always_inline)) void set_buffer_req(struct buffer_head *bh) { set_bit(BH_Req, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_req(struct buffer_head *bh) { clear_bit(BH_Req, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_req(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Req) ? constant_test_bit((BH_Req),(&(bh)->b_state)) : variable_test_bit((BH_Req),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) int test_set_buffer_req(struct buffer_head *bh) { return test_and_set_bit(BH_Req, &(bh)->b_state); } static inline __attribute__((always_inline)) int test_clear_buffer_req(struct buffer_head *bh) { return test_and_clear_bit(BH_Req, &(bh)->b_state); }
static inline __attribute__((always_inline)) void set_buffer_mapped(struct buffer_head *bh) { set_bit(BH_Mapped, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_mapped(struct buffer_head *bh) { clear_bit(BH_Mapped, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_mapped(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Mapped) ? constant_test_bit((BH_Mapped),(&(bh)->b_state)) : variable_test_bit((BH_Mapped),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_new(struct buffer_head *bh) { set_bit(BH_New, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_new(struct buffer_head *bh) { clear_bit(BH_New, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_new(const struct buffer_head *bh) { return (__builtin_constant_p(BH_New) ? constant_test_bit((BH_New),(&(bh)->b_state)) : variable_test_bit((BH_New),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_async_read(struct buffer_head *bh) { set_bit(BH_Async_Read, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_async_read(struct buffer_head *bh) { clear_bit(BH_Async_Read, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_async_read(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Async_Read) ? constant_test_bit((BH_Async_Read),(&(bh)->b_state)) : variable_test_bit((BH_Async_Read),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_async_write(struct buffer_head *bh) { set_bit(BH_Async_Write, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_async_write(struct buffer_head *bh) { clear_bit(BH_Async_Write, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_async_write(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Async_Write) ? constant_test_bit((BH_Async_Write),(&(bh)->b_state)) : variable_test_bit((BH_Async_Write),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_delay(struct buffer_head *bh) { set_bit(BH_Delay, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_delay(struct buffer_head *bh) { clear_bit(BH_Delay, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_delay(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Delay) ? constant_test_bit((BH_Delay),(&(bh)->b_state)) : variable_test_bit((BH_Delay),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_boundary(struct buffer_head *bh) { set_bit(BH_Boundary, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_boundary(struct buffer_head *bh) { clear_bit(BH_Boundary, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_boundary(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Boundary) ? constant_test_bit((BH_Boundary),(&(bh)->b_state)) : variable_test_bit((BH_Boundary),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_write_io_error(struct buffer_head *bh) { set_bit(BH_Write_EIO, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_write_io_error(struct buffer_head *bh) { clear_bit(BH_Write_EIO, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_write_io_error(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Write_EIO) ? constant_test_bit((BH_Write_EIO),(&(bh)->b_state)) : variable_test_bit((BH_Write_EIO),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_ordered(struct buffer_head *bh) { set_bit(BH_Ordered, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_ordered(struct buffer_head *bh) { clear_bit(BH_Ordered, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_ordered(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Ordered) ? constant_test_bit((BH_Ordered),(&(bh)->b_state)) : variable_test_bit((BH_Ordered),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_eopnotsupp(struct buffer_head *bh) { set_bit(BH_Eopnotsupp, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_eopnotsupp(struct buffer_head *bh) { clear_bit(BH_Eopnotsupp, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_eopnotsupp(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Eopnotsupp) ? constant_test_bit((BH_Eopnotsupp),(&(bh)->b_state)) : variable_test_bit((BH_Eopnotsupp),(&(bh)->b_state))); }
static inline __attribute__((always_inline)) void set_buffer_unwritten(struct buffer_head *bh) { set_bit(BH_Unwritten, &(bh)->b_state); } static inline __attribute__((always_inline)) void clear_buffer_unwritten(struct buffer_head *bh) { clear_bit(BH_Unwritten, &(bh)->b_state); } static inline __attribute__((always_inline)) int buffer_unwritten(const struct buffer_head *bh) { return (__builtin_constant_p(BH_Unwritten) ? constant_test_bit((BH_Unwritten),(&(bh)->b_state)) : variable_test_bit((BH_Unwritten),(&(bh)->b_state))); }
# 147 "include/linux/buffer_head.h"
void mark_buffer_dirty(struct buffer_head *bh) __attribute__((regparm(3)));
void init_buffer(struct buffer_head *, bh_end_io_t *, void *);
void set_bh_page(struct buffer_head *bh,
  struct page *page, unsigned long offset);
int try_to_free_buffers(struct page *);
struct buffer_head *alloc_page_buffers(struct page *page, unsigned long size,
  int retry);
void create_empty_buffers(struct page *, unsigned long,
   unsigned long b_state);
void end_buffer_read_sync(struct buffer_head *bh, int uptodate);
void end_buffer_write_sync(struct buffer_head *bh, int uptodate);


void mark_buffer_dirty_inode(struct buffer_head *bh, struct inode *inode);
int inode_has_buffers(struct inode *);
void invalidate_inode_buffers(struct inode *);
int remove_inode_buffers(struct inode *inode);
int sync_mapping_buffers(struct address_space *mapping);
void unmap_underlying_metadata(struct block_device *bdev, sector_t block);

void mark_buffer_async_write(struct buffer_head *bh);
void invalidate_bdev(struct block_device *);
int sync_blockdev(struct block_device *bdev);
void __wait_on_buffer(struct buffer_head *);
wait_queue_head_t *bh_waitq_head(struct buffer_head *bh);
int fsync_bdev(struct block_device *);
struct super_block *freeze_bdev(struct block_device *);
void thaw_bdev(struct block_device *, struct super_block *);
int fsync_super(struct super_block *);
int fsync_no_super(struct block_device *);
struct buffer_head *__find_get_block(struct block_device *bdev, sector_t block,
   unsigned size);
struct buffer_head *__getblk(struct block_device *bdev, sector_t block,
   unsigned size);
void __brelse(struct buffer_head *);
void __bforget(struct buffer_head *);
void __breadahead(struct block_device *, sector_t block, unsigned int size);
struct buffer_head *__bread(struct block_device *, sector_t block, unsigned size);
void invalidate_bh_lrus(void);
struct buffer_head *alloc_buffer_head(gfp_t gfp_flags);
void free_buffer_head(struct buffer_head * bh);
void unlock_buffer(struct buffer_head *bh) __attribute__((regparm(3)));
void __lock_buffer(struct buffer_head *bh) __attribute__((regparm(3)));
void ll_rw_block(int, int, struct buffer_head * bh[]);
int sync_dirty_buffer(struct buffer_head *bh);
int submit_bh(int, struct buffer_head *);
void write_boundary_block(struct block_device *bdev,
   sector_t bblock, unsigned blocksize);

extern int buffer_heads_over_limit;





void block_invalidatepage(struct page *page, unsigned long offset);
int block_write_full_page(struct page *page, get_block_t *get_block,
    struct writeback_control *wbc);
int block_read_full_page(struct page*, get_block_t*);
int block_prepare_write(struct page*, unsigned, unsigned, get_block_t*);
int cont_prepare_write(struct page*, unsigned, unsigned, get_block_t*,
    loff_t *);
int generic_cont_expand(struct inode *inode, loff_t size);
int generic_cont_expand_simple(struct inode *inode, loff_t size);
int block_commit_write(struct page *page, unsigned from, unsigned to);
void block_sync_page(struct page *);
sector_t generic_block_bmap(struct address_space *, sector_t, get_block_t *);
int generic_commit_write(struct file *, struct page *, unsigned, unsigned);
int block_truncate_page(struct address_space *, loff_t, get_block_t *);
int file_fsync(struct file *, struct dentry *, int);
int nobh_prepare_write(struct page*, unsigned, unsigned, get_block_t*);
int nobh_commit_write(struct file *, struct page *, unsigned, unsigned);
int nobh_truncate_page(struct address_space *, loff_t);
int nobh_writepage(struct page *page, get_block_t *get_block,
                        struct writeback_control *wbc);

void buffer_init(void);





static inline __attribute__((always_inline)) void attach_page_buffers(struct page *page,
  struct buffer_head *head)
{
 get_page(page);
 set_bit(11, &(page)->flags);
 ((page)->private = ((unsigned long)head));
}

static inline __attribute__((always_inline)) void get_bh(struct buffer_head *bh)
{
        atomic_inc(&bh->b_count);
}

static inline __attribute__((always_inline)) void put_bh(struct buffer_head *bh)
{
        __asm__ __volatile__("": : :"memory");
        atomic_dec(&bh->b_count);
}

static inline __attribute__((always_inline)) void brelse(struct buffer_head *bh)
{
 if (bh)
  __brelse(bh);
}

static inline __attribute__((always_inline)) void bforget(struct buffer_head *bh)
{
 if (bh)
  __bforget(bh);
}

static inline __attribute__((always_inline)) struct buffer_head *
sb_bread(struct super_block *sb, sector_t block)
{
 return __bread(sb->s_bdev, block, sb->s_blocksize);
}

static inline __attribute__((always_inline)) void
sb_breadahead(struct super_block *sb, sector_t block)
{
 __breadahead(sb->s_bdev, block, sb->s_blocksize);
}

static inline __attribute__((always_inline)) struct buffer_head *
sb_getblk(struct super_block *sb, sector_t block)
{
 return __getblk(sb->s_bdev, block, sb->s_blocksize);
}

static inline __attribute__((always_inline)) struct buffer_head *
sb_find_get_block(struct super_block *sb, sector_t block)
{
 return __find_get_block(sb->s_bdev, block, sb->s_blocksize);
}

static inline __attribute__((always_inline)) void
map_bh(struct buffer_head *bh, struct super_block *sb, sector_t block)
{
 set_buffer_mapped(bh);
 bh->b_bdev = sb->s_bdev;
 bh->b_blocknr = block;
 bh->b_size = sb->s_blocksize;
}






static inline __attribute__((always_inline)) void wait_on_buffer(struct buffer_head *bh)
{
 do { __might_sleep("include/linux/buffer_head.h", 300); do { } while (0); } while (0);
 if (buffer_locked(bh) || ((&bh->b_count)->counter) == 0)
  __wait_on_buffer(bh);
}

static inline __attribute__((always_inline)) void lock_buffer(struct buffer_head *bh)
{
 do { __might_sleep("include/linux/buffer_head.h", 307); do { } while (0); } while (0);
 if (test_set_buffer_locked(bh))
  __lock_buffer(bh);
}

extern int __set_page_dirty_buffers(struct page *page);
# 182 "drivers/block/floppy.c" 2







static int slow_floppy;

# 1 "include/asm/dma.h" 1
# 137 "include/asm/dma.h"
extern spinlock_t dma_spin_lock;

static __inline__ __attribute__((always_inline)) unsigned long claim_dma_lock(void)
{
 unsigned long flags;
 flags = _spin_lock_irqsave(&dma_spin_lock);
 return flags;
}

static __inline__ __attribute__((always_inline)) void release_dma_lock(unsigned long flags)
{
 _spin_unlock_irqrestore(&dma_spin_lock, flags);
}


static __inline__ __attribute__((always_inline)) void enable_dma(unsigned int dmanr)
{
 if (dmanr<=3)
  outb(dmanr, 0x0A);
 else
  outb(dmanr & 3, 0xD4);
}

static __inline__ __attribute__((always_inline)) void disable_dma(unsigned int dmanr)
{
 if (dmanr<=3)
  outb(dmanr | 4, 0x0A);
 else
  outb((dmanr & 3) | 4, 0xD4);
}
# 175 "include/asm/dma.h"
static __inline__ __attribute__((always_inline)) void clear_dma_ff(unsigned int dmanr)
{
 if (dmanr<=3)
  outb(0, 0x0C);
 else
  outb(0, 0xD8);
}


static __inline__ __attribute__((always_inline)) void set_dma_mode(unsigned int dmanr, char mode)
{
 if (dmanr<=3)
  outb(mode | dmanr, 0x0B);
 else
  outb(mode | (dmanr&3), 0xD6);
}






static __inline__ __attribute__((always_inline)) void set_dma_page(unsigned int dmanr, char pagenr)
{
 switch(dmanr) {
  case 0:
   outb(pagenr, 0x87);
   break;
  case 1:
   outb(pagenr, 0x83);
   break;
  case 2:
   outb(pagenr, 0x81);
   break;
  case 3:
   outb(pagenr, 0x82);
   break;
  case 5:
   outb(pagenr & 0xfe, 0x8B);
   break;
  case 6:
   outb(pagenr & 0xfe, 0x89);
   break;
  case 7:
   outb(pagenr & 0xfe, 0x8A);
   break;
 }
}





static __inline__ __attribute__((always_inline)) void set_dma_addr(unsigned int dmanr, unsigned int a)
{
 set_dma_page(dmanr, a>>16);
 if (dmanr <= 3) {
     outb( a & 0xff, ((dmanr&3)<<1) + 0x00 );
            outb( (a>>8) & 0xff, ((dmanr&3)<<1) + 0x00 );
 } else {
     outb( (a>>1) & 0xff, ((dmanr&3)<<2) + 0xC0 );
     outb( (a>>9) & 0xff, ((dmanr&3)<<2) + 0xC0 );
 }
}
# 249 "include/asm/dma.h"
static __inline__ __attribute__((always_inline)) void set_dma_count(unsigned int dmanr, unsigned int count)
{
        count--;
 if (dmanr <= 3) {
     outb( count & 0xff, ((dmanr&3)<<1) + 1 + 0x00 );
     outb( (count>>8) & 0xff, ((dmanr&3)<<1) + 1 + 0x00 );
        } else {
     outb( (count>>1) & 0xff, ((dmanr&3)<<2) + 2 + 0xC0 );
     outb( (count>>9) & 0xff, ((dmanr&3)<<2) + 2 + 0xC0 );
        }
}
# 270 "include/asm/dma.h"
static __inline__ __attribute__((always_inline)) int get_dma_residue(unsigned int dmanr)
{
 unsigned int io_port = (dmanr<=3)? ((dmanr&3)<<1) + 1 + 0x00
      : ((dmanr&3)<<2) + 2 + 0xC0;


 unsigned short count;

 count = 1 + inb(io_port);
 count += inb(io_port) << 8;

 return (dmanr<=3)? count : (count<<1);
}



extern int request_dma(unsigned int dmanr, const char * device_id);
extern void free_dma(unsigned int dmanr);




extern int isa_dma_bridge_buggy;
# 192 "drivers/block/floppy.c" 2





static int FLOPPY_IRQ = 6;
static int FLOPPY_DMA = 2;
static int can_use_virtual_dma = 2;
# 208 "drivers/block/floppy.c"
static int use_virtual_dma;
# 220 "drivers/block/floppy.c"
static spinlock_t floppy_lock = (spinlock_t) { .raw_lock = { 1 }, .magic = 0xdead4ead, .owner = ((void *)-1L), .owner_cpu = -1, .dep_map = { .name = "floppy_lock" } };
static struct completion device_release;

static unsigned short virtual_dma_port = 0x3f0;
irqreturn_t floppy_interrupt(int irq, void *dev_id);
static int set_dor(int fdc, char mask, char data);
# 239 "drivers/block/floppy.c"
static int allowed_drive_mask = 0x33;

# 1 "include/asm/floppy.h" 1
# 48 "include/asm/floppy.h"
static int virtual_dma_count;
static int virtual_dma_residue;
static char *virtual_dma_addr;
static int virtual_dma_mode;
static int doing_pdma;

static irqreturn_t floppy_hardint(int irq, void *dev_id)
{
 register unsigned char st;
# 65 "include/asm/floppy.h"
 if (!doing_pdma)
  return floppy_interrupt(irq, dev_id);






 {
  register int lcount;
  register char *lptr;

  st = 1;
  for(lcount=virtual_dma_count, lptr=virtual_dma_addr;
      lcount; lcount--, lptr++) {
   st=inb(virtual_dma_port+4) & 0xa0 ;
   if(st != 0xa0)
    break;
   if(virtual_dma_mode)
    outb_p(*lptr, virtual_dma_port+5);
   else
    *lptr = inb_p(virtual_dma_port+5);
  }
  virtual_dma_count = lcount;
  virtual_dma_addr = lptr;
  st = inb(virtual_dma_port+4);
 }




 if(st == 0x20)
  return (1);
 if(!(st & 0x20)) {
  virtual_dma_residue += virtual_dma_count;
  virtual_dma_count=0;







  doing_pdma = 0;
  floppy_interrupt(irq, dev_id);
  return (1);
 }




 return (1);
}

static void fd_disable_dma(void)
{
 if(! (can_use_virtual_dma & 1))
  disable_dma(FLOPPY_DMA);
 doing_pdma = 0;
 virtual_dma_residue += virtual_dma_count;
 virtual_dma_count=0;
}

static int vdma_request_dma(unsigned int dmanr, const char * device_id)
{
 return 0;
}

static void vdma_nop(unsigned int dummy)
{
}


static int vdma_get_dma_residue(unsigned int dummy)
{
 return virtual_dma_count + virtual_dma_residue;
}


static int fd_request_irq(void)
{
 if(can_use_virtual_dma)
  return request_irq(FLOPPY_IRQ, floppy_hardint,
       0x00000020, "floppy", ((void *)0));
 else
  return request_irq(FLOPPY_IRQ, floppy_interrupt,
       0x00000020, "floppy", ((void *)0));

}

static unsigned long dma_mem_alloc(unsigned long size)
{
 return __get_free_pages((((( gfp_t)0x10u) | (( gfp_t)0x40u) | (( gfp_t)0x80u))) | (( gfp_t)0x01u),(get_order(size)));
}


static unsigned long vdma_mem_alloc(unsigned long size)
{
 return (unsigned long) vmalloc(size);

}



static void _fd_dma_mem_free(unsigned long addr, unsigned long size)
{
 if((unsigned int) addr >= (unsigned int) high_memory)
  vfree((void *)addr);
 else
  free_pages(addr, get_order(size));
}



static void _fd_chose_dma_mode(char *addr, unsigned long size)
{
 if(can_use_virtual_dma == 2) {
  if((unsigned int) addr >= (unsigned int) high_memory ||
     virt_to_phys(addr) >= 0x1000000 ||
     (!(0) && ((unsigned long)(addr)/0x10000 != ((unsigned long)(addr) + (size) - 1) / 0x10000)))
   use_virtual_dma = 1;
  else
   use_virtual_dma = 0;
 } else {
  use_virtual_dma = can_use_virtual_dma & 1;
 }
}




static int vdma_dma_setup(char *addr, unsigned long size, int mode, int io)
{
 doing_pdma = 1;
 virtual_dma_port = io;
 virtual_dma_mode = (mode == 0x48);
 virtual_dma_addr = addr;
 virtual_dma_count = size;
 virtual_dma_residue = 0;
 return 0;
}

static int hard_dma_setup(char *addr, unsigned long size, int mode, int io)
{

 if ((!(use_virtual_dma & 1) && ((unsigned long)(addr)/0x10000 != ((unsigned long)(addr) + (size) - 1) / 0x10000))) {
  printk("DMA crossing 64-K boundary %p-%p\n", addr, addr+size);
  return -1;
 }


 doing_pdma = 0;
 clear_dma_ff(FLOPPY_DMA);
 set_dma_mode(FLOPPY_DMA,mode);
 set_dma_addr(FLOPPY_DMA,virt_to_phys(addr));
 set_dma_count(FLOPPY_DMA,size);
 enable_dma(FLOPPY_DMA);
 return 0;
}

static struct fd_routine_l {
 int (*_request_dma)(unsigned int dmanr, const char * device_id);
 void (*_free_dma)(unsigned int dmanr);
 int (*_get_dma_residue)(unsigned int dummy);
 unsigned long (*_dma_mem_alloc) (unsigned long size);
 int (*_dma_setup)(char *addr, unsigned long size, int mode, int io);
} fd_routine[] = {
 {
  request_dma,
  free_dma,
  get_dma_residue,
  dma_mem_alloc,
  hard_dma_setup
 },
 {
  vdma_request_dma,
  vdma_nop,
  vdma_get_dma_residue,
  vdma_mem_alloc,
  vdma_dma_setup
 }
};


static int FDC1 = 0x3f0;
static int FDC2 = -1;
# 242 "drivers/block/floppy.c" 2

static int irqdma_allocated;



# 1 "include/linux/blkdev.h" 1




# 1 "include/linux/major.h" 1
# 6 "include/linux/blkdev.h" 2
# 1 "include/linux/genhd.h" 1
# 16 "include/linux/genhd.h"
enum {


 DOS_EXTENDED_PARTITION = 5,
 LINUX_EXTENDED_PARTITION = 0x85,
 WIN98_EXTENDED_PARTITION = 0x0f,

 SUN_WHOLE_DISK = DOS_EXTENDED_PARTITION,

 LINUX_SWAP_PARTITION = 0x82,
 LINUX_DATA_PARTITION = 0x83,
 LINUX_LVM_PARTITION = 0x8e,
 LINUX_RAID_PARTITION = 0xfd,

 SOLARIS_X86_PARTITION = LINUX_SWAP_PARTITION,
 NEW_SOLARIS_X86_PARTITION = 0xbf,

 DM6_AUX1PARTITION = 0x51,
 DM6_AUX3PARTITION = 0x53,
 DM6_PARTITION = 0x54,
 EZD_PARTITION = 0x55,

 FREEBSD_PARTITION = 0xa5,
 OPENBSD_PARTITION = 0xa6,
 NETBSD_PARTITION = 0xa9,
 BSDI_PARTITION = 0xb7,
 MINIX_PARTITION = 0x81,
 UNIXWARE_PARTITION = 0x63,
};
# 71 "include/linux/genhd.h"
struct partition {
 unsigned char boot_ind;
 unsigned char head;
 unsigned char sector;
 unsigned char cyl;
 unsigned char sys_ind;
 unsigned char end_head;
 unsigned char end_sector;
 unsigned char end_cyl;
 __le32 start_sect;
 __le32 nr_sects;
} __attribute__((packed));

struct hd_struct {
 sector_t start_sect;
 sector_t nr_sects;
 struct kobject kobj;
 struct kobject *holder_dir;
 unsigned ios[2], sectors[2];
 int policy, partno;

 int make_it_fail;

};
# 104 "include/linux/genhd.h"
struct disk_stats {
 unsigned long sectors[2];
 unsigned long ios[2];
 unsigned long merges[2];
 unsigned long ticks[2];
 unsigned long io_ticks;
 unsigned long time_in_queue;
};

struct gendisk {
 int major;
 int first_minor;
 int minors;

 char disk_name[32];
 struct hd_struct **part;
 int part_uevent_suppress;
 struct block_device_operations *fops;
 struct request_queue *queue;
 void *private_data;
 sector_t capacity;

 int flags;
 struct device *driverfs_dev;
 struct kobject kobj;
 struct kobject *holder_dir;
 struct kobject *slave_dir;

 struct timer_rand_state *random;
 int policy;

 atomic_t sync_io;
 unsigned long stamp;
 int in_flight;

 struct disk_stats *dkstats;



 struct work_struct async_notify;
};


struct disk_attribute {
 struct attribute attr;
 ssize_t (*show)(struct gendisk *, char *);
 ssize_t (*store)(struct gendisk *, const char *, size_t);
};
# 172 "include/linux/genhd.h"
static inline __attribute__((always_inline)) void disk_stat_set_all(struct gendisk *gendiskp, int value) {
 int i;
 for (((i)) = __first_cpu(&(cpu_possible_map)); ((i)) < 8; ((i)) = __next_cpu((((i))), &((cpu_possible_map))))
  (__builtin_constant_p(value) ? (__builtin_constant_p((sizeof (struct disk_stats))) ? __constant_c_and_count_memset(((({ struct percpu_data *__p = (struct percpu_data *)~(unsigned long)((gendiskp->dkstats)); (__typeof__((gendiskp->dkstats)))__p->ptrs[((i))]; }))),((0x01010101UL*(unsigned char)(value))),((sizeof (struct disk_stats)))) : __constant_c_memset(((({ struct percpu_data *__p = (struct percpu_data *)~(unsigned long)((gendiskp->dkstats)); (__typeof__((gendiskp->dkstats)))__p->ptrs[((i))]; }))),((0x01010101UL*(unsigned char)(value))),((sizeof (struct disk_stats))))) : (__builtin_constant_p((sizeof (struct disk_stats))) ? __memset_generic((((({ struct percpu_data *__p = (struct percpu_data *)~(unsigned long)((gendiskp->dkstats)); (__typeof__((gendiskp->dkstats)))__p->ptrs[((i))]; })))),(((value))),(((sizeof (struct disk_stats))))) : __memset_generic(((({ struct percpu_data *__p = (struct percpu_data *)~(unsigned long)((gendiskp->dkstats)); (__typeof__((gendiskp->dkstats)))__p->ptrs[((i))]; }))),((value)),((sizeof (struct disk_stats))))));

}
# 210 "include/linux/genhd.h"
static inline __attribute__((always_inline)) int init_disk_stats(struct gendisk *disk)
{
 disk->dkstats = (struct disk_stats *)__percpu_alloc_mask(((sizeof(struct disk_stats))), (((( gfp_t)0x10u) | (( gfp_t)0x40u) | (( gfp_t)0x80u))), &(cpu_possible_map));
 if (!disk->dkstats)
  return 0;
 return 1;
}

static inline __attribute__((always_inline)) void free_disk_stats(struct gendisk *disk)
{
 percpu_free((disk->dkstats));
}
# 234 "include/linux/genhd.h"
extern void disk_round_stats(struct gendisk *disk);


extern int get_blkdev_list(char *, int);
extern void add_disk(struct gendisk *disk);
extern void del_gendisk(struct gendisk *gp);
extern void unlink_gendisk(struct gendisk *gp);
extern struct gendisk *get_gendisk(dev_t dev, int *part);

extern void set_device_ro(struct block_device *bdev, int flag);
extern void set_disk_ro(struct gendisk *disk, int flag);


extern void add_disk_randomness(struct gendisk *disk);
extern void rand_initialize_disk(struct gendisk *disk);

static inline __attribute__((always_inline)) sector_t get_start_sect(struct block_device *bdev)
{
 return bdev->bd_contains == bdev ? 0 : bdev->bd_part->start_sect;
}
static inline __attribute__((always_inline)) sector_t get_capacity(struct gendisk *disk)
{
 return disk->capacity;
}
static inline __attribute__((always_inline)) void set_capacity(struct gendisk *disk, sector_t size)
{
 disk->capacity = size;
}
# 270 "include/linux/genhd.h"
struct solaris_x86_slice {
 __le16 s_tag;
 __le16 s_flag;
 __le32 s_start;
 __le32 s_size;
};

struct solaris_x86_vtoc {
 unsigned int v_bootinfo[3];
 __le32 v_sanity;
 __le32 v_version;
 char v_volume[8];
 __le16 v_sectorsz;
 __le16 v_nparts;
 unsigned int v_reserved[10];
 struct solaris_x86_slice
  v_slice[8];
 unsigned int timestamp[8];
 char v_asciilabel[128];
};
# 305 "include/linux/genhd.h"
struct bsd_disklabel {
 __le32 d_magic;
 __s16 d_type;
 __s16 d_subtype;
 char d_typename[16];
 char d_packname[16];
 __u32 d_secsize;
 __u32 d_nsectors;
 __u32 d_ntracks;
 __u32 d_ncylinders;
 __u32 d_secpercyl;
 __u32 d_secperunit;
 __u16 d_sparespertrack;
 __u16 d_sparespercyl;
 __u32 d_acylinders;
 __u16 d_rpm;
 __u16 d_interleave;
 __u16 d_trackskew;
 __u16 d_cylskew;
 __u32 d_headswitch;
 __u32 d_trkseek;
 __u32 d_flags;

 __u32 d_drivedata[5];

 __u32 d_spare[5];
 __le32 d_magic2;
 __le16 d_checksum;


 __le16 d_npartitions;
 __le32 d_bbsize;
 __le32 d_sbsize;
 struct bsd_partition {
  __le32 p_size;
  __le32 p_offset;
  __le32 p_fsize;
  __u8 p_fstype;
  __u8 p_frag;
  __le16 p_cpg;
 } d_partitions[16];
};
# 361 "include/linux/genhd.h"
struct unixware_slice {
 __le16 s_label;
 __le16 s_flags;
 __le32 start_sect;
 __le32 nr_sects;
};

struct unixware_disklabel {
 __le32 d_type;
 __le32 d_magic;
 __le32 d_version;
 char d_serial[12];
 __le32 d_ncylinders;
 __le32 d_ntracks;
 __le32 d_nsectors;
 __le32 d_secsize;
 __le32 d_part_start;
 __le32 d_unknown1[12];
  __le32 d_alt_tbl;
  __le32 d_alt_len;
  __le32 d_phys_cyl;
  __le32 d_phys_trk;
  __le32 d_phys_sec;
  __le32 d_phys_bytes;
  __le32 d_unknown2;
 __le32 d_unknown3;
 __le32 d_pad[8];

 struct unixware_vtoc {
  __le32 v_magic;
  __le32 v_version;
  char v_name[8];
  __le16 v_nslices;
  __le16 v_unknown1;
  __le32 v_reserved[10];
  struct unixware_slice
   v_slice[16];
 } vtoc;

};
# 414 "include/linux/genhd.h"
char *disk_name (struct gendisk *hd, int part, char *buf);

extern int rescan_partitions(struct gendisk *disk, struct block_device *bdev);
extern void add_partition(struct gendisk *, int, sector_t, sector_t, int);
extern void delete_partition(struct gendisk *, int);
extern void printk_all_partitions(void);

extern struct gendisk *alloc_disk_node(int minors, int node_id);
extern struct gendisk *alloc_disk(int minors);
extern struct kobject *get_disk(struct gendisk *disk);
extern void put_disk(struct gendisk *disk);
extern void genhd_media_change_notify(struct gendisk *disk);
extern void blk_register_region(dev_t dev, unsigned long range,
   struct module *module,
   struct kobject *(*probe)(dev_t, int *, void *),
   int (*lock)(dev_t, void *),
   void *data);
extern void blk_unregister_region(dev_t dev, unsigned long range);

static inline __attribute__((always_inline)) struct block_device *bdget_disk(struct gendisk *disk, int index)
{
 return bdget((((disk->major) << 20) | (disk->first_minor)) + index);
}
# 7 "include/linux/blkdev.h" 2
# 18 "include/linux/blkdev.h"
# 1 "include/asm/scatterlist.h" 1





struct scatterlist {
    struct page *page;
    unsigned int offset;
    dma_addr_t dma_address;
    unsigned int length;
};
# 19 "include/linux/blkdev.h" 2
# 36 "include/linux/blkdev.h"
struct scsi_ioctl_command;

struct request_queue;
typedef struct request_queue request_queue_t;
struct elevator_queue;
typedef struct elevator_queue elevator_t;
struct request_pm_state;
struct blk_trace;







struct as_io_context {
 spinlock_t lock;

 void (*dtor)(struct as_io_context *aic);
 void (*exit)(struct as_io_context *aic);

 unsigned long state;
 atomic_t nr_queued;
 atomic_t nr_dispatched;



 unsigned long last_end_request;
 unsigned long ttime_total;
 unsigned long ttime_samples;
 unsigned long ttime_mean;

 unsigned int seek_samples;
 sector_t last_request_pos;
 u64 seek_total;
 sector_t seek_mean;
};

struct cfq_queue;
struct cfq_io_context {
 struct rb_node rb_node;
 void *key;

 struct cfq_queue *cfqq[2];

 struct io_context *ioc;

 unsigned long last_end_request;
 sector_t last_request_pos;

 unsigned long ttime_total;
 unsigned long ttime_samples;
 unsigned long ttime_mean;

 unsigned int seek_samples;
 u64 seek_total;
 sector_t seek_mean;

 struct list_head queue_list;

 void (*dtor)(struct io_context *);
 void (*exit)(struct io_context *);
};






struct io_context {
 atomic_t refcount;
 struct task_struct *task;

 unsigned int ioprio_changed;




 unsigned long last_waited;
 int nr_batch_requests;

 struct as_io_context *aic;
 struct rb_root cic_root;
 void *ioc_data;
};

void put_io_context(struct io_context *ioc);
void exit_io_context(void);
struct io_context *get_io_context(gfp_t gfp_flags, int node);
void copy_io_context(struct io_context **pdst, struct io_context **psrc);
void swap_io_context(struct io_context **ioc1, struct io_context **ioc2);

struct request;
typedef void (rq_end_io_fn)(struct request *, int);

struct request_list {
 int count[2];
 int starved[2];
 int elvpriv;
 mempool_t *rq_pool;
 wait_queue_head_t wait[2];
};




enum rq_cmd_type_bits {
 REQ_TYPE_FS = 1,
 REQ_TYPE_BLOCK_PC,
 REQ_TYPE_SENSE,
 REQ_TYPE_PM_SUSPEND,
 REQ_TYPE_PM_RESUME,
 REQ_TYPE_PM_SHUTDOWN,
 REQ_TYPE_FLUSH,
 REQ_TYPE_SPECIAL,
 REQ_TYPE_LINUX_BLOCK,





 REQ_TYPE_ATA_CMD,
 REQ_TYPE_ATA_TASK,
 REQ_TYPE_ATA_TASKFILE,
 REQ_TYPE_ATA_PC,
};
# 172 "include/linux/blkdev.h"
enum {



 REQ_LB_OP_EJECT = 0x40,
 REQ_LB_OP_FLUSH = 0x41,
};




enum rq_flag_bits {
 __REQ_RW,
 __REQ_FAILFAST,
 __REQ_SORTED,
 __REQ_SOFTBARRIER,
 __REQ_HARDBARRIER,
 __REQ_FUA,
 __REQ_NOMERGE,
 __REQ_STARTED,
 __REQ_DONTPREP,
 __REQ_QUEUED,
 __REQ_ELVPRIV,
 __REQ_FAILED,
 __REQ_QUIET,
 __REQ_PREEMPT,
 __REQ_ORDERED_COLOR,
 __REQ_RW_SYNC,
 __REQ_ALLOCED,
 __REQ_RW_META,
 __REQ_NR_BITS,
};
# 229 "include/linux/blkdev.h"
struct request {
 struct list_head queuelist;
 struct list_head donelist;

 request_queue_t *q;

 unsigned int cmd_flags;
 enum rq_cmd_type_bits cmd_type;





 sector_t sector;
 sector_t hard_sector;
 unsigned long nr_sectors;
 unsigned long hard_nr_sectors;

 unsigned int current_nr_sectors;


 unsigned int hard_cur_sectors;

 struct bio *bio;
 struct bio *biotail;

 struct hlist_node hash;





 union {
  struct rb_node rb_node;
  void *completion_data;
 };





 void *elevator_private;
 void *elevator_private2;

 struct gendisk *rq_disk;
 unsigned long start_time;




 unsigned short nr_phys_segments;






 unsigned short nr_hw_segments;

 unsigned short ioprio;

 void *special;
 char *buffer;

 int tag;
 int errors;

 int ref_count;




 unsigned int cmd_len;
 unsigned char cmd[16];

 unsigned int data_len;
 unsigned int sense_len;
 void *data;
 void *sense;

 unsigned int timeout;
 int retries;




 rq_end_io_fn *end_io;
 void *end_io_data;
};





struct request_pm_state
{

 int pm_step;

 u32 pm_state;
 void* data;
};

# 1 "include/linux/elevator.h" 1







typedef int (elevator_merge_fn) (request_queue_t *, struct request **,
     struct bio *);

typedef void (elevator_merge_req_fn) (request_queue_t *, struct request *, struct request *);

typedef void (elevator_merged_fn) (request_queue_t *, struct request *, int);

typedef int (elevator_allow_merge_fn) (request_queue_t *, struct request *, struct bio *);

typedef int (elevator_dispatch_fn) (request_queue_t *, int);

typedef void (elevator_add_req_fn) (request_queue_t *, struct request *);
typedef int (elevator_queue_empty_fn) (request_queue_t *);
typedef struct request *(elevator_request_list_fn) (request_queue_t *, struct request *);
typedef void (elevator_completed_req_fn) (request_queue_t *, struct request *);
typedef int (elevator_may_queue_fn) (request_queue_t *, int);

typedef int (elevator_set_req_fn) (request_queue_t *, struct request *, gfp_t);
typedef void (elevator_put_req_fn) (struct request *);
typedef void (elevator_activate_req_fn) (request_queue_t *, struct request *);
typedef void (elevator_deactivate_req_fn) (request_queue_t *, struct request *);

typedef void *(elevator_init_fn) (request_queue_t *);
typedef void (elevator_exit_fn) (elevator_t *);

struct elevator_ops
{
 elevator_merge_fn *elevator_merge_fn;
 elevator_merged_fn *elevator_merged_fn;
 elevator_merge_req_fn *elevator_merge_req_fn;
 elevator_allow_merge_fn *elevator_allow_merge_fn;

 elevator_dispatch_fn *elevator_dispatch_fn;
 elevator_add_req_fn *elevator_add_req_fn;
 elevator_activate_req_fn *elevator_activate_req_fn;
 elevator_deactivate_req_fn *elevator_deactivate_req_fn;

 elevator_queue_empty_fn *elevator_queue_empty_fn;
 elevator_completed_req_fn *elevator_completed_req_fn;

 elevator_request_list_fn *elevator_former_req_fn;
 elevator_request_list_fn *elevator_latter_req_fn;

 elevator_set_req_fn *elevator_set_req_fn;
 elevator_put_req_fn *elevator_put_req_fn;

 elevator_may_queue_fn *elevator_may_queue_fn;

 elevator_init_fn *elevator_init_fn;
 elevator_exit_fn *elevator_exit_fn;
 void (*trim)(struct io_context *);
};



struct elv_fs_entry {
 struct attribute attr;
 ssize_t (*show)(elevator_t *, char *);
 ssize_t (*store)(elevator_t *, const char *, size_t);
};




struct elevator_type
{
 struct list_head list;
 struct elevator_ops ops;
 struct elv_fs_entry *elevator_attrs;
 char elevator_name[(16)];
 struct module *elevator_owner;
};




struct elevator_queue
{
 struct elevator_ops *ops;
 void *elevator_data;
 struct kobject kobj;
 struct elevator_type *elevator_type;
 struct mutex sysfs_lock;
 struct hlist_head *hash;
};




extern void elv_dispatch_sort(request_queue_t *, struct request *);
extern void elv_dispatch_add_tail(request_queue_t *, struct request *);
extern void elv_add_request(request_queue_t *, struct request *, int, int);
extern void __elv_add_request(request_queue_t *, struct request *, int, int);
extern void elv_insert(request_queue_t *, struct request *, int);
extern int elv_merge(request_queue_t *, struct request **, struct bio *);
extern void elv_merge_requests(request_queue_t *, struct request *,
          struct request *);
extern void elv_merged_request(request_queue_t *, struct request *, int);
extern void elv_dequeue_request(request_queue_t *, struct request *);
extern void elv_requeue_request(request_queue_t *, struct request *);
extern int elv_queue_empty(request_queue_t *);
extern struct request *elv_next_request(struct request_queue *q);
extern struct request *elv_former_request(request_queue_t *, struct request *);
extern struct request *elv_latter_request(request_queue_t *, struct request *);
extern int elv_register_queue(request_queue_t *q);
extern void elv_unregister_queue(request_queue_t *q);
extern int elv_may_queue(request_queue_t *, int);
extern void elv_completed_request(request_queue_t *, struct request *);
extern int elv_set_request(request_queue_t *, struct request *, gfp_t);
extern void elv_put_request(request_queue_t *, struct request *);




extern int elv_register(struct elevator_type *);
extern void elv_unregister(struct elevator_type *);




extern ssize_t elv_iosched_show(request_queue_t *, char *);
extern ssize_t elv_iosched_store(request_queue_t *, const char *, size_t);

extern int elevator_init(request_queue_t *, char *);
extern void elevator_exit(elevator_t *);
extern int elv_rq_merge_ok(struct request *, struct bio *);




extern struct request *elv_rb_former_request(request_queue_t *, struct request *);
extern struct request *elv_rb_latter_request(request_queue_t *, struct request *);




extern struct request *elv_rb_add(struct rb_root *, struct request *);
extern void elv_rb_del(struct rb_root *, struct request *);
extern struct request *elv_rb_find(struct rb_root *, sector_t);
# 166 "include/linux/elevator.h"
enum {
 ELV_MQUEUE_MAY,
 ELV_MQUEUE_NO,
 ELV_MQUEUE_MUST,
};
# 333 "include/linux/blkdev.h" 2

typedef void (request_fn_proc) (request_queue_t *q);
typedef int (make_request_fn) (request_queue_t *q, struct bio *bio);
typedef int (prep_rq_fn) (request_queue_t *, struct request *);
typedef void (unplug_fn) (request_queue_t *);

struct bio_vec;
typedef int (merge_bvec_fn) (request_queue_t *, struct bio *, struct bio_vec *);
typedef int (issue_flush_fn) (request_queue_t *, struct gendisk *, sector_t *);
typedef void (prepare_flush_fn) (request_queue_t *, struct request *);
typedef void (softirq_done_fn)(struct request *);

enum blk_queue_state {
 Queue_down,
 Queue_up,
};

struct blk_queue_tag {
 struct request **tag_index;
 unsigned long *tag_map;
 struct list_head busy_list;
 int busy;
 int max_depth;
 int real_max_depth;
 atomic_t refcnt;
};

struct request_queue
{



 struct list_head queue_head;
 struct request *last_merge;
 elevator_t *elevator;




 struct request_list rq;

 request_fn_proc *request_fn;
 make_request_fn *make_request_fn;
 prep_rq_fn *prep_rq_fn;
 unplug_fn *unplug_fn;
 merge_bvec_fn *merge_bvec_fn;
 issue_flush_fn *issue_flush_fn;
 prepare_flush_fn *prepare_flush_fn;
 softirq_done_fn *softirq_done_fn;




 sector_t end_sector;
 struct request *boundary_rq;




 struct timer_list unplug_timer;
 int unplug_thresh;
 unsigned long unplug_delay;
 struct work_struct unplug_work;

 struct backing_dev_info backing_dev_info;





 void *queuedata;




 unsigned long bounce_pfn;
 gfp_t bounce_gfp;




 unsigned long queue_flags;






 spinlock_t __queue_lock;
 spinlock_t *queue_lock;




 struct kobject kobj;




 unsigned long nr_requests;
 unsigned int nr_congestion_on;
 unsigned int nr_congestion_off;
 unsigned int nr_batching;

 unsigned int max_sectors;
 unsigned int max_hw_sectors;
 unsigned short max_phys_segments;
 unsigned short max_hw_segments;
 unsigned short hardsect_size;
 unsigned int max_segment_size;

 unsigned long seg_boundary_mask;
 unsigned int dma_alignment;

 struct blk_queue_tag *queue_tags;

 unsigned int nr_sorted;
 unsigned int in_flight;




 unsigned int sg_timeout;
 unsigned int sg_reserved_size;
 int node;

 struct blk_trace *blk_trace;




 unsigned int ordered, next_ordered, ordseq;
 int orderr, ordcolor;
 struct request pre_flush_rq, bar_rq, post_flush_rq;
 struct request *orig_bar_rq;
 unsigned int bi_size;

 struct mutex sysfs_lock;
};
# 483 "include/linux/blkdev.h"
enum {
# 495 "include/linux/blkdev.h"
 QUEUE_ORDERED_NONE = 0x00,
 QUEUE_ORDERED_DRAIN = 0x01,
 QUEUE_ORDERED_TAG = 0x02,

 QUEUE_ORDERED_PREFLUSH = 0x10,
 QUEUE_ORDERED_POSTFLUSH = 0x20,
 QUEUE_ORDERED_FUA = 0x40,

 QUEUE_ORDERED_DRAIN_FLUSH = QUEUE_ORDERED_DRAIN |
   QUEUE_ORDERED_PREFLUSH | QUEUE_ORDERED_POSTFLUSH,
 QUEUE_ORDERED_DRAIN_FUA = QUEUE_ORDERED_DRAIN |
   QUEUE_ORDERED_PREFLUSH | QUEUE_ORDERED_FUA,
 QUEUE_ORDERED_TAG_FLUSH = QUEUE_ORDERED_TAG |
   QUEUE_ORDERED_PREFLUSH | QUEUE_ORDERED_POSTFLUSH,
 QUEUE_ORDERED_TAG_FUA = QUEUE_ORDERED_TAG |
   QUEUE_ORDERED_PREFLUSH | QUEUE_ORDERED_FUA,




 QUEUE_ORDSEQ_STARTED = 0x01,
 QUEUE_ORDSEQ_DRAIN = 0x02,
 QUEUE_ORDSEQ_PREFLUSH = 0x04,
 QUEUE_ORDSEQ_BAR = 0x08,
 QUEUE_ORDSEQ_POSTFLUSH = 0x10,
 QUEUE_ORDSEQ_DONE = 0x20,
};
# 557 "include/linux/blkdev.h"
static inline __attribute__((always_inline)) int blk_queue_full(struct request_queue *q, int rw)
{
 if (rw == 0)
  return (__builtin_constant_p(3) ? constant_test_bit((3),(&q->queue_flags)) : variable_test_bit((3),(&q->queue_flags)));
 return (__builtin_constant_p(4) ? constant_test_bit((4),(&q->queue_flags)) : variable_test_bit((4),(&q->queue_flags)));
}

static inline __attribute__((always_inline)) void blk_set_queue_full(struct request_queue *q, int rw)
{
 if (rw == 0)
  set_bit(3, &q->queue_flags);
 else
  set_bit(4, &q->queue_flags);
}

static inline __attribute__((always_inline)) void blk_clear_queue_full(struct request_queue *q, int rw)
{
 if (rw == 0)
  clear_bit(3, &q->queue_flags);
 else
  clear_bit(4, &q->queue_flags);
}
# 597 "include/linux/blkdev.h"
extern unsigned long blk_max_low_pfn, blk_max_pfn;
# 611 "include/linux/blkdev.h"
extern int init_emergency_isa_pool(void);
extern void blk_queue_bounce(request_queue_t *q, struct bio **bio);
# 627 "include/linux/blkdev.h"
extern int blk_register_queue(struct gendisk *disk);
extern void blk_unregister_queue(struct gendisk *disk);
extern void register_disk(struct gendisk *dev);
extern void generic_make_request(struct bio *bio);
extern void blk_put_request(struct request *);
extern void __blk_put_request(request_queue_t *, struct request *);
extern void blk_end_sync_rq(struct request *rq, int error);
extern struct request *blk_get_request(request_queue_t *, int, gfp_t);
extern void blk_insert_request(request_queue_t *, struct request *, int, void *);
extern void blk_requeue_request(request_queue_t *, struct request *);
extern void blk_plug_device(request_queue_t *);
extern int blk_remove_plug(request_queue_t *);
extern void blk_recount_segments(request_queue_t *, struct bio *);
extern int scsi_cmd_ioctl(struct file *, struct gendisk *, unsigned int, void *);
extern int sg_scsi_ioctl(struct file *, struct request_queue *,
  struct gendisk *, struct scsi_ioctl_command *);




extern int ll_back_merge_fn(request_queue_t *, struct request *, struct bio *);






static inline __attribute__((always_inline)) void blk_clear_queue_congested(request_queue_t *q, int rw)
{
 clear_bdi_congested(&q->backing_dev_info, rw);
}





static inline __attribute__((always_inline)) void blk_set_queue_congested(request_queue_t *q, int rw)
{
 set_bdi_congested(&q->backing_dev_info, rw);
}

extern void blk_start_queue(request_queue_t *q);
extern void blk_stop_queue(request_queue_t *q);
extern void blk_sync_queue(struct request_queue *q);
extern void __blk_stop_queue(request_queue_t *q);
extern void blk_run_queue(request_queue_t *);
extern void blk_start_queueing(request_queue_t *);
extern int blk_rq_map_user(request_queue_t *, struct request *, void *, unsigned long);
extern int blk_rq_unmap_user(struct bio *);
extern int blk_rq_map_kern(request_queue_t *, struct request *, void *, unsigned int, gfp_t);
extern int blk_rq_map_user_iov(request_queue_t *, struct request *,
          struct sg_iovec *, int, unsigned int);
extern int blk_execute_rq(request_queue_t *, struct gendisk *,
     struct request *, int);
extern void blk_execute_rq_nowait(request_queue_t *, struct gendisk *,
      struct request *, int, rq_end_io_fn *);

static inline __attribute__((always_inline)) request_queue_t *bdev_get_queue(struct block_device *bdev)
{
 return bdev->bd_disk->queue;
}

static inline __attribute__((always_inline)) void blk_run_backing_dev(struct backing_dev_info *bdi,
           struct page *page)
{
 if (bdi && bdi->unplug_io_fn)
  bdi->unplug_io_fn(bdi, page);
}

static inline __attribute__((always_inline)) void blk_run_address_space(struct address_space *mapping)
{
 if (mapping)
  blk_run_backing_dev(mapping->backing_dev_info, ((void *)0));
}
# 711 "include/linux/blkdev.h"
extern int end_that_request_first(struct request *, int, int);
extern int end_that_request_chunk(struct request *, int, int);
extern void end_that_request_last(struct request *, int);
extern void end_request(struct request *req, int uptodate);
extern void blk_complete_request(struct request *);
# 725 "include/linux/blkdev.h"
static inline __attribute__((always_inline)) void blkdev_dequeue_request(struct request *req)
{
 elv_dequeue_request(req->q, req);
}




extern request_queue_t *blk_init_queue_node(request_fn_proc *rfn,
     spinlock_t *lock, int node_id);
extern request_queue_t *blk_init_queue(request_fn_proc *, spinlock_t *);
extern void blk_cleanup_queue(request_queue_t *);
extern void blk_queue_make_request(request_queue_t *, make_request_fn *);
extern void blk_queue_bounce_limit(request_queue_t *, u64);
extern void blk_queue_max_sectors(request_queue_t *, unsigned int);
extern void blk_queue_max_phys_segments(request_queue_t *, unsigned short);
extern void blk_queue_max_hw_segments(request_queue_t *, unsigned short);
extern void blk_queue_max_segment_size(request_queue_t *, unsigned int);
extern void blk_queue_hardsect_size(request_queue_t *, unsigned short);
extern void blk_queue_stack_limits(request_queue_t *t, request_queue_t *b);
extern void blk_queue_segment_boundary(request_queue_t *, unsigned long);
extern void blk_queue_prep_rq(request_queue_t *, prep_rq_fn *pfn);
extern void blk_queue_merge_bvec(request_queue_t *, merge_bvec_fn *);
extern void blk_queue_dma_alignment(request_queue_t *, int);
extern void blk_queue_softirq_done(request_queue_t *, softirq_done_fn *);
extern struct backing_dev_info *blk_get_backing_dev_info(struct block_device *bdev);
extern int blk_queue_ordered(request_queue_t *, unsigned, prepare_flush_fn *);
extern void blk_queue_issue_flush_fn(request_queue_t *, issue_flush_fn *);
extern int blk_do_ordered(request_queue_t *, struct request **);
extern unsigned blk_ordered_cur_seq(request_queue_t *);
extern unsigned blk_ordered_req_seq(struct request *);
extern void blk_ordered_complete_seq(request_queue_t *, unsigned, int);

extern int blk_rq_map_sg(request_queue_t *, struct request *, struct scatterlist *);
extern void blk_dump_rq_flags(struct request *, char *);
extern void generic_unplug_device(request_queue_t *);
extern void __generic_unplug_device(request_queue_t *);
extern long nr_blockdev_pages(void);

int blk_get_queue(request_queue_t *);
request_queue_t *blk_alloc_queue(gfp_t);
request_queue_t *blk_alloc_queue_node(gfp_t, int);
extern void blk_put_queue(request_queue_t *);







extern int blk_queue_start_tag(request_queue_t *, struct request *);
extern struct request *blk_queue_find_tag(request_queue_t *, int);
extern void blk_queue_end_tag(request_queue_t *, struct request *);
extern int blk_queue_init_tags(request_queue_t *, int, struct blk_queue_tag *);
extern void blk_queue_free_tags(request_queue_t *);
extern int blk_queue_resize_tags(request_queue_t *, int);
extern void blk_queue_invalidate_tags(request_queue_t *);
extern struct blk_queue_tag *blk_init_tags(int);
extern void blk_free_tags(struct blk_queue_tag *);

static inline __attribute__((always_inline)) struct request *blk_map_queue_find_tag(struct blk_queue_tag *bqt,
      int tag)
{
 if (__builtin_expect(!!(bqt == ((void *)0) || tag >= bqt->real_max_depth), 0))
  return ((void *)0);
 return bqt->tag_index[tag];
}

extern void blk_rq_bio_prep(request_queue_t *, struct request *, struct bio *);
extern int blkdev_issue_flush(struct block_device *, sector_t *);
# 805 "include/linux/blkdev.h"
static inline __attribute__((always_inline)) int queue_hardsect_size(request_queue_t *q)
{
 int retval = 512;

 if (q && q->hardsect_size)
  retval = q->hardsect_size;

 return retval;
}

static inline __attribute__((always_inline)) int bdev_hardsect_size(struct block_device *bdev)
{
 return queue_hardsect_size(bdev_get_queue(bdev));
}

static inline __attribute__((always_inline)) int queue_dma_alignment(request_queue_t *q)
{
 int retval = 511;

 if (q && q->dma_alignment)
  retval = q->dma_alignment;

 return retval;
}


static inline __attribute__((always_inline)) unsigned int blksize_bits(unsigned int size)
{
 unsigned int bits = 8;
 do {
  bits++;
  size >>= 1;
 } while (size > 256);
 return bits;
}

static inline __attribute__((always_inline)) unsigned int block_size(struct block_device *bdev)
{
 return bdev->bd_block_size;
}

typedef struct {struct page *v;} Sector;

unsigned char *read_dev_sector(struct block_device *, sector_t, Sector *);

static inline __attribute__((always_inline)) void put_dev_sector(Sector p)
{
 put_page(p.v);
}

struct work_struct;
int kblockd_schedule_work(struct work_struct *work);
void kblockd_flush_work(struct work_struct *work);
# 248 "drivers/block/floppy.c" 2
# 1 "include/linux/blkpg.h" 1
# 33 "include/linux/blkpg.h"
struct blkpg_ioctl_arg {
        int op;
        int flags;
        int datalen;
        void *data;
};
# 49 "include/linux/blkpg.h"
struct blkpg_partition {
 long long start;
 long long length;
 int pno;
 char devname[64];

 char volname[64];
};
# 249 "drivers/block/floppy.c" 2
# 1 "include/linux/cdrom.h" 1
# 153 "include/linux/cdrom.h"
struct cdrom_msf0
{
 __u8 minute;
 __u8 second;
 __u8 frame;
};


union cdrom_addr
{
 struct cdrom_msf0 msf;
 int lba;
};


struct cdrom_msf
{
 __u8 cdmsf_min0;
 __u8 cdmsf_sec0;
 __u8 cdmsf_frame0;
 __u8 cdmsf_min1;
 __u8 cdmsf_sec1;
 __u8 cdmsf_frame1;
};


struct cdrom_ti
{
 __u8 cdti_trk0;
 __u8 cdti_ind0;
 __u8 cdti_trk1;
 __u8 cdti_ind1;
};


struct cdrom_tochdr
{
 __u8 cdth_trk0;
 __u8 cdth_trk1;
};


struct cdrom_volctrl
{
 __u8 channel0;
 __u8 channel1;
 __u8 channel2;
 __u8 channel3;
};


struct cdrom_subchnl
{
 __u8 cdsc_format;
 __u8 cdsc_audiostatus;
 __u8 cdsc_adr: 4;
 __u8 cdsc_ctrl: 4;
 __u8 cdsc_trk;
 __u8 cdsc_ind;
 union cdrom_addr cdsc_absaddr;
 union cdrom_addr cdsc_reladdr;
};



struct cdrom_tocentry
{
 __u8 cdte_track;
 __u8 cdte_adr :4;
 __u8 cdte_ctrl :4;
 __u8 cdte_format;
 union cdrom_addr cdte_addr;
 __u8 cdte_datamode;
};


struct cdrom_read
{
 int cdread_lba;
 char *cdread_bufaddr;
 int cdread_buflen;
};


struct cdrom_read_audio
{
 union cdrom_addr addr;
 __u8 addr_format;
 int nframes;
 __u8 *buf;
};


struct cdrom_multisession
{
 union cdrom_addr addr;


 __u8 xa_flag;
 __u8 addr_format;
};






struct cdrom_mcn
{
  __u8 medium_catalog_number[14];
};


struct cdrom_blk
{
 unsigned from;
 unsigned short len;
};
# 280 "include/linux/cdrom.h"
struct cdrom_generic_command
{
 unsigned char cmd[12];
 unsigned char *buffer;
 unsigned int buflen;
 int stat;
 struct request_sense *sense;
 unsigned char data_direction;
 int quiet;
 int timeout;
 void *reserved[1];
};
# 522 "include/linux/cdrom.h"
struct dvd_layer {
 __u8 book_version : 4;
 __u8 book_type : 4;
 __u8 min_rate : 4;
 __u8 disc_size : 4;
 __u8 layer_type : 4;
 __u8 track_path : 1;
 __u8 nlayers : 2;
 __u8 track_density : 4;
 __u8 linear_density : 4;
 __u8 bca : 1;
 __u32 start_sector;
 __u32 end_sector;
 __u32 end_sector_l0;
};



struct dvd_physical {
 __u8 type;
 __u8 layer_num;
 struct dvd_layer layer[4];
};

struct dvd_copyright {
 __u8 type;

 __u8 layer_num;
 __u8 cpst;
 __u8 rmi;
};

struct dvd_disckey {
 __u8 type;

 unsigned agid : 2;
 __u8 value[2048];
};

struct dvd_bca {
 __u8 type;

 int len;
 __u8 value[188];
};

struct dvd_manufact {
 __u8 type;

 __u8 layer_num;
 int len;
 __u8 value[2048];
};

typedef union {
 __u8 type;

 struct dvd_physical physical;
 struct dvd_copyright copyright;
 struct dvd_disckey disckey;
 struct dvd_bca bca;
 struct dvd_manufact manufact;
} dvd_struct;
# 609 "include/linux/cdrom.h"
typedef __u8 dvd_key[5];
typedef __u8 dvd_challenge[10];

struct dvd_lu_send_agid {
 __u8 type;
 unsigned agid : 2;
};

struct dvd_host_send_challenge {
 __u8 type;
 unsigned agid : 2;

 dvd_challenge chal;
};

struct dvd_send_key {
 __u8 type;
 unsigned agid : 2;

 dvd_key key;
};

struct dvd_lu_send_challenge {
 __u8 type;
 unsigned agid : 2;

 dvd_challenge chal;
};
# 648 "include/linux/cdrom.h"
struct dvd_lu_send_title_key {
 __u8 type;
 unsigned agid : 2;

 dvd_key title_key;
 int lba;
 unsigned cpm : 1;
 unsigned cp_sec : 1;
 unsigned cgms : 2;
};

struct dvd_lu_send_asf {
 __u8 type;
 unsigned agid : 2;

 unsigned asf : 1;
};

struct dvd_host_send_rpcstate {
 __u8 type;
 __u8 pdrc;
};

struct dvd_lu_send_rpcstate {
 __u8 type : 2;
 __u8 vra : 3;
 __u8 ucca : 3;
 __u8 region_mask;
 __u8 rpc_scheme;
};

typedef union {
 __u8 type;

 struct dvd_lu_send_agid lsa;
 struct dvd_host_send_challenge hsc;
 struct dvd_send_key lsk;
 struct dvd_lu_send_challenge lsc;
 struct dvd_send_key hsk;
 struct dvd_lu_send_title_key lstk;
 struct dvd_lu_send_asf lsasf;
 struct dvd_host_send_rpcstate hrpcs;
 struct dvd_lu_send_rpcstate lrpcs;
} dvd_authinfo;

struct request_sense {




 __u8 error_code : 7;
 __u8 valid : 1;

 __u8 segment_number;






 __u8 sense_key : 4;
 __u8 reserved2 : 1;
 __u8 ili : 1;
 __u8 reserved1 : 2;

 __u8 information[4];
 __u8 add_sense_len;
 __u8 command_info[4];
 __u8 asc;
 __u8 ascq;
 __u8 fruc;
 __u8 sks[3];
 __u8 asb[46];
};
# 751 "include/linux/cdrom.h"
struct mrw_feature_desc {
 __be16 feature_code;






 __u8 curr : 1;
 __u8 persistent : 1;
 __u8 feature_version : 4;
 __u8 reserved1 : 2;

 __u8 add_len;




 __u8 write : 1;
 __u8 reserved2 : 7;

 __u8 reserved3;
 __u8 reserved4;
 __u8 reserved5;
};


struct rwrt_feature_desc {
 __be16 feature_code;






 __u8 curr : 1;
 __u8 persistent : 1;
 __u8 feature_version : 4;
 __u8 reserved1 : 2;

 __u8 add_len;
 __u32 last_lba;
 __u32 block_size;
 __u16 blocking;




 __u8 page_present : 1;
 __u8 reserved2 : 7;

 __u8 reserved3;
};

typedef struct {
 __be16 disc_information_length;






        __u8 disc_status : 2;
        __u8 border_status : 2;
        __u8 erasable : 1;
 __u8 reserved1 : 3;



 __u8 n_first_track;
 __u8 n_sessions_lsb;
 __u8 first_track_lsb;
 __u8 last_track_lsb;
# 832 "include/linux/cdrom.h"
 __u8 mrw_status : 2;
 __u8 dbit : 1;
        __u8 reserved2 : 2;
        __u8 uru : 1;
        __u8 dbc_v : 1;
 __u8 did_v : 1;

 __u8 disc_type;
 __u8 n_sessions_msb;
 __u8 first_track_msb;
 __u8 last_track_msb;
 __u32 disc_id;
 __u32 lead_in;
 __u32 lead_out;
 __u8 disc_bar_code[8];
 __u8 reserved3;
 __u8 n_opc;
} disc_information;

typedef struct {
 __be16 track_information_length;
 __u8 track_lsb;
 __u8 session_lsb;
 __u8 reserved1;
# 870 "include/linux/cdrom.h"
        __u8 track_mode : 4;
        __u8 copy : 1;
        __u8 damage : 1;
 __u8 reserved2 : 2;
 __u8 data_mode : 4;
 __u8 fp : 1;
 __u8 packet : 1;
 __u8 blank : 1;
 __u8 rt : 1;
 __u8 nwa_v : 1;
 __u8 lra_v : 1;
 __u8 reserved3 : 6;

 __be32 track_start;
 __be32 next_writable;
 __be32 free_blocks;
 __be32 fixed_packet_size;
 __be32 track_size;
 __be32 last_rec_address;
} track_information;

struct feature_header {
 __u32 data_len;
 __u8 reserved1;
 __u8 reserved2;
 __u16 curr_profile;
};

struct mode_page_header {
 __be16 mode_data_length;
 __u8 medium_type;
 __u8 reserved1;
 __u8 reserved2;
 __u8 reserved3;
 __be16 desc_length;
};





struct packet_command
{
 unsigned char cmd[12];
 unsigned char *buffer;
 unsigned int buflen;
 int stat;
 struct request_sense *sense;
 unsigned char data_direction;
 int quiet;
 int timeout;
 void *reserved[1];
};
# 932 "include/linux/cdrom.h"
struct cdrom_device_info {
 struct cdrom_device_ops *ops;
 struct cdrom_device_info *next;
 struct gendisk *disk;
 void *handle;

 int mask;
 int speed;
 int capacity;

 unsigned int options : 30;
 unsigned mc_flags : 2;
     int use_count;
     char name[20];

        __u8 sanyo_slot : 2;
        __u8 reserved : 6;
 int cdda_method;
 __u8 last_sense;
 __u8 media_written;
 unsigned short mmc3_profile;
 int for_data;
 int (*exit)(struct cdrom_device_info *);
 int mrw_mode_page;
};

struct cdrom_device_ops {

 int (*open) (struct cdrom_device_info *, int);
 void (*release) (struct cdrom_device_info *);
 int (*drive_status) (struct cdrom_device_info *, int);
 int (*media_changed) (struct cdrom_device_info *, int);
 int (*tray_move) (struct cdrom_device_info *, int);
 int (*lock_door) (struct cdrom_device_info *, int);
 int (*select_speed) (struct cdrom_device_info *, int);
 int (*select_disc) (struct cdrom_device_info *, int);
 int (*get_last_session) (struct cdrom_device_info *,
     struct cdrom_multisession *);
 int (*get_mcn) (struct cdrom_device_info *,
   struct cdrom_mcn *);

 int (*reset) (struct cdrom_device_info *);

 int (*audio_ioctl) (struct cdrom_device_info *,unsigned int, void *);


 const int capability;
 int n_minors;

 int (*generic_packet) (struct cdrom_device_info *,
          struct packet_command *);
};


extern int cdrom_open(struct cdrom_device_info *cdi, struct inode *ip,
   struct file *fp);
extern int cdrom_release(struct cdrom_device_info *cdi, struct file *fp);
extern int cdrom_ioctl(struct file *file, struct cdrom_device_info *cdi,
  struct inode *ip, unsigned int cmd, unsigned long arg);
extern int cdrom_media_changed(struct cdrom_device_info *);

extern int register_cdrom(struct cdrom_device_info *cdi);
extern int unregister_cdrom(struct cdrom_device_info *cdi);

typedef struct {
    int data;
    int audio;
    int cdi;
    int xa;
    long error;
} tracktype;

extern int cdrom_get_last_written(struct cdrom_device_info *cdi, long *last_written);
extern int cdrom_number_of_slots(struct cdrom_device_info *cdi);
extern int cdrom_mode_select(struct cdrom_device_info *cdi,
        struct packet_command *cgc);
extern int cdrom_mode_sense(struct cdrom_device_info *cdi,
       struct packet_command *cgc,
       int page_code, int page_control);
extern void init_cdrom_command(struct packet_command *cgc,
          void *buffer, int len, int type);




struct cdrom_mechstat_header {
# 1026 "include/linux/cdrom.h"
 __u8 curslot : 5;
 __u8 changer_state : 2;
 __u8 fault : 1;
 __u8 reserved1 : 4;
 __u8 door_open : 1;
 __u8 mech_state : 3;

 __u8 curlba[3];
 __u8 nslots;
 __u16 slot_tablelen;
};

struct cdrom_slot {





 __u8 change : 1;
 __u8 reserved1 : 6;
 __u8 disc_present : 1;

 __u8 reserved2[3];
};

struct cdrom_changer_info {
 struct cdrom_mechstat_header hdr;
 struct cdrom_slot slots[256];
};

typedef enum {
 mechtype_caddy = 0,
 mechtype_tray = 1,
 mechtype_popup = 2,
 mechtype_individual_changer = 4,
 mechtype_cartridge_changer = 5
} mechtype_t;

typedef struct {
# 1082 "include/linux/cdrom.h"
 __u8 page_code : 6;
 __u8 reserved1 : 1;
 __u8 ps : 1;
        __u8 page_length;
        __u8 write_type : 4;
 __u8 test_write : 1;
 __u8 ls_v : 1;
 __u8 bufe : 1;
 __u8 reserved2 : 1;
 __u8 track_mode : 4;
 __u8 copy : 1;
 __u8 fp : 1;
 __u8 multi_session : 2;
 __u8 data_block_type : 4;
 __u8 reserved3 : 4;

 __u8 link_size;
 __u8 reserved4;




 __u8 app_code : 6;
 __u8 reserved5 : 2;

 __u8 session_format;
 __u8 reserved6;
 __be32 packet_size;
 __u16 audio_pause;
 __u8 mcn[16];
 __u8 isrc[16];
 __u8 subhdr0;
 __u8 subhdr1;
 __u8 subhdr2;
 __u8 subhdr3;
} __attribute__((packed)) write_param_page;

struct modesel_head
{
 __u8 reserved1;
 __u8 medium;
 __u8 reserved2;
 __u8 block_desc_length;
 __u8 density;
 __u8 number_of_blocks_hi;
 __u8 number_of_blocks_med;
 __u8 number_of_blocks_lo;
 __u8 reserved3;
 __u8 block_length_hi;
 __u8 block_length_med;
 __u8 block_length_lo;
};

typedef struct {
 __u16 report_key_length;
 __u8 reserved1;
 __u8 reserved2;





 __u8 ucca : 3;
 __u8 vra : 3;
 __u8 type_code : 2;

 __u8 region_mask;
 __u8 rpc_scheme;
 __u8 reserved3;
} rpc_state_t;

struct event_header {
 __be16 data_len;





 __u8 notification_class : 3;
 __u8 reserved1 : 4;
 __u8 nea : 1;

 __u8 supp_event_class;
};

struct media_event_desc {







 __u8 media_event_code : 4;
 __u8 reserved1 : 4;
 __u8 door_open : 1;
 __u8 media_present : 1;
 __u8 reserved2 : 6;

 __u8 start_slot;
 __u8 end_slot;
};

extern int cdrom_get_media_event(struct cdrom_device_info *cdi, struct media_event_desc *med);
# 250 "drivers/block/floppy.c" 2


static struct request *current_req;
static struct request_queue *floppy_queue;
static void do_fd_request(request_queue_t * q);
# 270 "drivers/block/floppy.c"
static inline __attribute__((always_inline)) void fallback_on_nodma_alloc(char **addr, size_t l)
{

 if (*addr)
  return;
 if (can_use_virtual_dma != 2)
  return;
 printk
     ("DMA memory shortage. Temporarily falling back on virtual DMA\n");
 *addr = (char *)vdma_mem_alloc(l);



}



static unsigned long fake_change;
static int initialising = 1;
# 349 "drivers/block/floppy.c"
static unsigned char reply_buffer[16];
static int inr;
# 365 "drivers/block/floppy.c"
static struct {
 struct floppy_drive_params params;
 const char *name;
} default_drive_params[] = {
# 384 "drivers/block/floppy.c"
{{0, 500, 16, 16, 8000, 1*250, 3*250, 0, (2*250/100), 5, 80, 3*250, 20, {3,1,2,0,2}, 0,
      0, { 7, 4, 8, 2, 1, 5, 3,10}, 3*250/2, 0 }, "unknown" },

{{1, 300, 16, 16, 8000, 1*250, 3*250, 0, (2*250/100), 5, 40, 3*250, 17, {3,1,2,0,2}, 0,
      0, { 1, 0, 0, 0, 0, 0, 0, 0}, 3*250/2, 1 }, "360K PC" },

{{2, 500, 16, 16, 6000, 4*250/10, 3*250, 14, (2*250/100), 6, 83, 3*250, 17, {3,1,2,0,2}, 0,
      0, { 2, 5, 6,23,10,20,12, 0}, 3*250/2, 2 }, "1.2M" },

{{3, 250, 16, 16, 3000, 1*250, 3*250, 0, (2*250/100), 5, 83, 3*250, 20, {3,1,2,0,2}, 0,
      0, { 4,22,21,30, 3, 0, 0, 0}, 3*250/2, 4 }, "720k" },

{{4, 500, 16, 16, 4000, 4*250/10, 3*250, 10, (2*250/100), 5, 83, 3*250, 20, {3,1,2,0,2}, 0,
      0, { 7, 4,25,22,31,21,29,11}, 3*250/2, 7 }, "1.44M" },

{{5, 1000, 15, 8, 3000, 4*250/10, 3*250, 10, (2*250/100), 5, 83, 3*250, 40, {3,1,2,0,2}, 0,
      0, { 7, 8, 4,25,28,22,31,21}, 3*250/2, 8 }, "2.88M AMI BIOS" },

{{6, 1000, 15, 8, 3000, 4*250/10, 3*250, 10, (2*250/100), 5, 83, 3*250, 40, {3,1,2,0,2}, 0,
      0, { 7, 8, 4,25,28,22,31,21}, 3*250/2, 8 }, "2.88M" }




};

static struct floppy_drive_params drive_params[8];
static struct floppy_drive_struct drive_state[8];
static struct floppy_write_errors write_errors[8];
static struct timer_list motor_off_timer[8];
static struct gendisk *disks[8];
static struct block_device *opened_bdev[8];
static struct mutex open_lock = { .count = { (1) } , .wait_lock = (spinlock_t) { .raw_lock = { 1 }, .magic = 0xdead4ead, .owner = ((void *)-1L), .owner_cpu = -1, .dep_map = { .name = "open_lock.wait_lock" } } , .wait_list = { &(open_lock.wait_list), &(open_lock.wait_list) } , .magic = &open_lock , .dep_map = { .name = "open_lock" } };
static struct floppy_raw_cmd *raw_cmd, default_raw_cmd;
# 443 "drivers/block/floppy.c"
static struct floppy_struct floppy_type[32] = {
 { 0, 0,0, 0,0,0x00,0x00,0x00,0x00,((void *)0) },
 { 720, 9,2,40,0,0x2A,0x02,0xDF,0x50,"d360" },
 { 2400,15,2,80,0,0x1B,0x00,0xDF,0x54,"h1200" },
 { 720, 9,1,80,0,0x2A,0x02,0xDF,0x50,"D360" },
 { 1440, 9,2,80,0,0x2A,0x02,0xDF,0x50,"D720" },
 { 720, 9,2,40,1,0x23,0x01,0xDF,0x50,"h360" },
 { 1440, 9,2,80,0,0x23,0x01,0xDF,0x50,"h720" },
 { 2880,18,2,80,0,0x1B,0x00,0xCF,0x6C,"H1440" },
 { 5760,36,2,80,0,0x1B,0x43,0xAF,0x54,"E2880" },
 { 6240,39,2,80,0,0x1B,0x43,0xAF,0x28,"E3120" },

 { 2880,18,2,80,0,0x25,0x00,0xDF,0x02,"h1440" },
 { 3360,21,2,80,0,0x1C,0x00,0xCF,0x0C,"H1680" },
 { 820,10,2,41,1,0x25,0x01,0xDF,0x2E,"h410" },
 { 1640,10,2,82,0,0x25,0x02,0xDF,0x2E,"H820" },
 { 2952,18,2,82,0,0x25,0x00,0xDF,0x02,"h1476" },
 { 3444,21,2,82,0,0x25,0x00,0xDF,0x0C,"H1722" },
 { 840,10,2,42,1,0x25,0x01,0xDF,0x2E,"h420" },
 { 1660,10,2,83,0,0x25,0x02,0xDF,0x2E,"H830" },
 { 2988,18,2,83,0,0x25,0x00,0xDF,0x02,"h1494" },
 { 3486,21,2,83,0,0x25,0x00,0xDF,0x0C,"H1743" },

 { 1760,11,2,80,0,0x1C,0x09,0xCF,0x00,"h880" },
 { 2080,13,2,80,0,0x1C,0x01,0xCF,0x00,"D1040" },
 { 2240,14,2,80,0,0x1C,0x19,0xCF,0x00,"D1120" },
 { 3200,20,2,80,0,0x1C,0x20,0xCF,0x2C,"h1600" },
 { 3520,22,2,80,0,0x1C,0x08,0xCF,0x2e,"H1760" },
 { 3840,24,2,80,0,0x1C,0x20,0xCF,0x00,"H1920" },
 { 6400,40,2,80,0,0x25,0x5B,0xCF,0x00,"E3200" },
 { 7040,44,2,80,0,0x25,0x5B,0xCF,0x00,"E3520" },
 { 7680,48,2,80,0,0x25,0x63,0xCF,0x00,"E3840" },

 { 3680,23,2,80,0,0x1C,0x10,0xCF,0x00,"H1840" },
 { 1600,10,2,80,0,0x25,0x02,0xDF,0x2E,"D800" },
 { 3200,20,2,80,0,0x1C,0x00,0xCF,0x2C,"H1600" },
};




static struct floppy_struct *current_type[8];





static struct floppy_struct user_params[8];

static sector_t floppy_sizes[256];

static char floppy_device_name[] = "floppy";






static int probing;






static volatile int command_status = -1;
static unsigned long fdc_busy;
static wait_queue_head_t fdc_wait = { .lock = (spinlock_t) { .raw_lock = { 1 }, .magic = 0xdead4ead, .owner = ((void *)-1L), .owner_cpu = -1, .dep_map = { .name = "fdc_wait.lock" } }, .task_list = { &(fdc_wait).task_list, &(fdc_wait).task_list } };
static wait_queue_head_t command_done = { .lock = (spinlock_t) { .raw_lock = { 1 }, .magic = 0xdead4ead, .owner = ((void *)-1L), .owner_cpu = -1, .dep_map = { .name = "command_done.lock" } }, .task_list = { &(command_done).task_list, &(command_done).task_list } };
# 521 "drivers/block/floppy.c"
static int format_errors;


static struct format_descr format_req;
# 538 "drivers/block/floppy.c"
static char *floppy_track_buffer;
static int max_buffer_sectors;

static int *errors;
typedef void (*done_f) (int);
static struct cont_t {
 void (*interrupt) (void);

 void (*redo) (void);
 void (*error) (void);
 done_f done;

} *cont;

static void floppy_ready(void);
static void floppy_start(void);
static void process_fd_request(void);
static void recalibrate_floppy(void);
static void floppy_shutdown(unsigned long);

static int floppy_grab_irq_and_dma(void);
static void floppy_release_irq_and_dma(void);
# 569 "drivers/block/floppy.c"
static void reset_fdc(void);
# 580 "drivers/block/floppy.c"
static int usage_count;


static int buffer_track = -1;
static int buffer_drive = -1;
static int buffer_min = -1;
static int buffer_max = -1;


static struct floppy_fdc_state fdc_state[2];
static int fdc;

static struct floppy_struct *_floppy = floppy_type;
static unsigned char current_drive;
static long current_count_sectors;
static unsigned char fsector_t;
static unsigned char in_sector_offset;



static inline __attribute__((always_inline)) int fd_eject(int drive)
{
 return -22;
}







static long unsigned debugtimer;

static inline __attribute__((always_inline)) void set_debugt(void)
{
 debugtimer = jiffies;
}

static inline __attribute__((always_inline)) void debugt(const char *message)
{
 if ((&drive_params[current_drive])->flags & 2)
  printk("%s dtime=%lu\n", message, jiffies - debugtimer);
}





typedef void (*timeout_fn) (unsigned long);
static struct timer_list fd_timeout = { .function = (floppy_shutdown), .expires = (0), .data = (0), .base = &boot_tvec_bases, };

static const char *timeout_message;


static void is_alive(const char *message)
{

 if ((__builtin_constant_p(0) ? constant_test_bit((0),(&fdc_busy)) : variable_test_bit((0),(&fdc_busy))) && command_status < 2
     && !timer_pending(&fd_timeout)) {
  printk("floppy" "%d: " "timeout handler died: %s\n", current_drive , message);
 }
}


static void (*do_floppy) (void) = ((void *)0);





static void (*lasthandler) (void);
static unsigned long interruptjiffies;
static unsigned long resultjiffies;
static int resultsize;
static unsigned long lastredo;

static struct output_log {
 unsigned char data;
 unsigned char status;
 unsigned long jiffies;
} output_log[20];

static int output_log_pos;





static void __reschedule_timeout(int drive, const char *message, int marg)
{
 if (drive == -1)
  drive = current_drive;
 del_timer(&fd_timeout);
 if (drive < 0 || drive >= 8) {
  fd_timeout.expires = jiffies + 20UL * 250;
  drive = 0;
 } else
  fd_timeout.expires = jiffies + (&drive_params[drive])->timeout;
 add_timer(&fd_timeout);
 if ((&drive_params[drive])->flags & 0x02) {
  printk("floppy" "%d: " "reschedule timeout ", current_drive);
  printk(message, marg);
  printk("\n");
 }
 timeout_message = message;
}

static void reschedule_timeout(int drive, const char *message, int marg)
{
 unsigned long flags;

 flags = _spin_lock_irqsave(&floppy_lock);
 __reschedule_timeout(drive, message, marg);
 _spin_unlock_irqrestore(&floppy_lock, flags);
}
# 733 "drivers/block/floppy.c"
static int disk_change(int drive)
{
 int fdc = (((drive) & 0x04) >> 2);

 if ((({ unsigned long __dummy; typeof((&drive_state[drive])->select_date + (&drive_params[drive])->select_delay) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ({ unsigned long __dummy; typeof(jiffies) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ((long)(jiffies) - (long)((&drive_state[drive])->select_date + (&drive_params[drive])->select_delay) < 0)))
  printk("floppy" "%d: " "WARNING disk change called early\n", current_drive);
 if (!((&fdc_state[fdc])->dor & (0x10 << ((drive) & 0x03))) ||
     ((&fdc_state[fdc])->dor & 3) != ((drive) & 0x03) || fdc != (((drive) & 0x04) >> 2)) {
  printk("floppy" "%d: " "probing disk change on unselected drive\n", current_drive);
  printk("floppy" "%d: " "drive=%d fdc=%d dor=%x\n", current_drive , drive, (((drive) & 0x04) >> 2), (unsigned int)(&fdc_state[fdc])->dor);

 }



 if ((&drive_params[drive])->flags & 0x02) {
  printk("floppy" "%d: " "checking disk change line for drive %d\n", current_drive , drive);
  printk("floppy" "%d: " "jiffies=%lu\n", current_drive , jiffies);
  printk("floppy" "%d: " "disk change line=%x\n", current_drive , inb_p((7 + fdc_state[fdc].address )) & 0x80);
  printk("floppy" "%d: " "flags=%lx\n", current_drive , (&drive_state[drive])->flags);
 }

 if ((&drive_params[drive])->flags & 0x20)
  return (__builtin_constant_p(FD_DISK_CHANGED_BIT) ? constant_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags)));
 if ((inb_p((7 + fdc_state[fdc].address )) ^ (&drive_params[drive])->flags) & 0x80) {
  set_bit(FD_VERIFY_BIT, &(&drive_state[drive])->flags);
  if ((&drive_state[drive])->maxblock) {

   set_bit(FD_DISK_CHANGED_BIT, &(&drive_state[drive])->flags);
  }


  if ((&drive_state[drive])->keep_data >= 0) {
   if (((&drive_params[drive])->flags & 0x10) &&
       current_type[drive] != ((void *)0))
    printk("floppy" "%d: " "Disk type is undefined after " "disk change\n", current_drive);

   current_type[drive] = ((void *)0);
   floppy_sizes[((drive & 3) | ((drive & 4) << 5))] = 4 << 1;
  }


  return 1;
 } else {
  (&drive_state[drive])->last_checked = jiffies;
  clear_bit(FD_DISK_NEWCHANGE_BIT, &(&drive_state[drive])->flags);
 }
 return 0;
}

static inline __attribute__((always_inline)) int is_selected(int dor, int unit)
{
 return ((dor & (0x10 << unit)) && (dor & 3) == unit);
}

static int set_dor(int fdc, char mask, char data)
{
 register unsigned char drive, unit, newdor, olddor;

 if ((&fdc_state[fdc])->address == -1)
  return -1;

 olddor = (&fdc_state[fdc])->dor;
 newdor = (olddor & mask) | data;
 if (newdor != olddor) {
  unit = olddor & 0x3;
  if (is_selected(olddor, unit) && !is_selected(newdor, unit)) {
   drive = ((unit) + ((fdc) << 2));

   if ((&drive_params[drive])->flags & 0x02) {
    printk("floppy" "%d: " "calling disk change from set_dor\n", current_drive);
   }

   disk_change(drive);
  }
  (&fdc_state[fdc])->dor = newdor;
  outb_p(newdor,(2 + fdc_state[fdc].address ));

  unit = newdor & 0x3;
  if (!is_selected(olddor, unit) && is_selected(newdor, unit)) {
   drive = ((unit) + ((fdc) << 2));
   (&drive_state[drive])->select_date = jiffies;
  }
 }
 return olddor;
}

static void twaddle(void)
{
 if ((&drive_params[current_drive])->select_delay)
  return;
 outb_p((&fdc_state[fdc])->dor & ~(0x10 << ((current_drive) & 0x03)),(2 + fdc_state[fdc].address ));
 outb_p((&fdc_state[fdc])->dor,(2 + fdc_state[fdc].address ));
 (&drive_state[current_drive])->select_date = jiffies;
}



static void reset_fdc_info(int mode)
{
 int drive;

 (&fdc_state[fdc])->spec1 = (&fdc_state[fdc])->spec2 = -1;
 (&fdc_state[fdc])->need_configure = 1;
 (&fdc_state[fdc])->perp_mode = 1;
 (&fdc_state[fdc])->rawcmd = 0;
 for (drive = 0; drive < 8; drive++)
  if ((((drive) & 0x04) >> 2) == fdc && (mode || (&drive_state[drive])->track != -2))
   (&drive_state[drive])->track = -3;
}


static void set_fdc(int drive)
{
 if (drive >= 0 && drive < 8) {
  fdc = (((drive) & 0x04) >> 2);
  current_drive = drive;
 }
 if (fdc != 1 && fdc != 0) {
  printk("bad fdc value\n");
  return;
 }
 set_dor(fdc, ~0, 8);

 set_dor(1 - fdc, ~8, 0);

 if ((&fdc_state[fdc])->rawcmd == 2)
  reset_fdc_info(1);
 if (inb_p((4 + fdc_state[fdc].address )) != 0x80)
  (&fdc_state[fdc])->reset = 1;
}


static int _lock_fdc(int drive, int interruptible, int line)
{
 if (!usage_count) {
  printk("<3>"
         "Trying to lock fdc while usage count=0 at line %d\n",
         line);
  return -1;
 }

 if (test_and_set_bit(0, &fdc_busy)) {
  wait_queue_t wait = { .private = get_current(), .func = default_wake_function, .task_list = { ((void *)0), ((void *)0) } };
  add_wait_queue(&fdc_wait, &wait);

  for (;;) {
   do { (void) ((__typeof__(*(&get_current()->state)))__xchg((unsigned long)((1)),(&get_current()->state),sizeof(*(&get_current()->state)))); } while (0);

   if (!test_and_set_bit(0, &fdc_busy))
    break;

   schedule();

   if (!(!interruptible || !signal_pending(get_current()))) {
    remove_wait_queue(&fdc_wait, &wait);
    return -4;
   }
  }

  do { (void) ((__typeof__(*(&get_current()->state)))__xchg((unsigned long)((0)),(&get_current()->state),sizeof(*(&get_current()->state)))); } while (0);
  remove_wait_queue(&fdc_wait, &wait);

  flush_scheduled_work();
 }
 command_status = -1;

 __reschedule_timeout(drive, "lock fdc", 0);
 set_fdc(drive);
 return 0;
}







static inline __attribute__((always_inline)) void unlock_fdc(void)
{
 unsigned long flags;

 raw_cmd = ((void *)0);
 if (!(__builtin_constant_p(0) ? constant_test_bit((0),(&fdc_busy)) : variable_test_bit((0),(&fdc_busy))))
  printk("floppy" "%d: " "FDC access conflict!\n", current_drive);

 if (do_floppy)
  printk("floppy" "%d: " "device interrupt still active at FDC release: %p!\n", current_drive , do_floppy);

 command_status = -1;
 flags = _spin_lock_irqsave(&floppy_lock);
 del_timer(&fd_timeout);
 cont = ((void *)0);
 clear_bit(0, &fdc_busy);
 if (elv_next_request(floppy_queue))
  do_fd_request(floppy_queue);
 _spin_unlock_irqrestore(&floppy_lock, flags);
 __wake_up(&fdc_wait, 2 | 1, 1, ((void *)0));
}


static void motor_off_callback(unsigned long nr)
{
 unsigned char mask = ~(0x10 << ((nr) & 0x03));

 set_dor((((nr) & 0x04) >> 2), mask, 0);
}


static void floppy_off(unsigned int drive)
{
 unsigned long volatile delta;
 register int fdc = (((drive) & 0x04) >> 2);

 if (!((&fdc_state[fdc])->dor & (0x10 << ((drive) & 0x03))))
  return;

 del_timer(motor_off_timer + drive);



 if ((&drive_params[drive])->rps) {
  delta = jiffies - (&drive_state[drive])->first_read_date + 250 -
      (&drive_params[drive])->spindown_offset;
  delta = ((delta * (&drive_params[drive])->rps) % 250) / (&drive_params[drive])->rps;
  motor_off_timer[drive].expires =
      jiffies + (&drive_params[drive])->spindown - delta;
 }
 add_timer(motor_off_timer + drive);
}






static void scandrives(void)
{
 int i, drive, saved_drive;

 if ((&drive_params[current_drive])->select_delay)
  return;

 saved_drive = current_drive;
 for (i = 0; i < 8; i++) {
  drive = (saved_drive + i + 1) % 8;
  if ((&drive_state[drive])->fd_ref == 0 || (&drive_params[drive])->select_delay != 0)
   continue;
  set_fdc(drive);
  if (!(set_dor(fdc, ~3, ((drive) & 0x03) | (0x10 << ((drive) & 0x03))) &
        (0x10 << ((drive) & 0x03))))


   set_dor(fdc, ~(0x10 << ((drive) & 0x03)), 0);
 }
 set_fdc(saved_drive);
}

static void empty(void)
{
}

static struct work_struct floppy_work = { .data = { (0) }, .entry = { &(floppy_work).entry, &(floppy_work).entry }, .func = (((void *)0)), };

static void schedule_bh(void (*handler) (void))
{
 do { (&floppy_work)->func = ((work_func_t)handler); } while (0);
 schedule_work(&floppy_work);
}

static struct timer_list fd_timer = { .function = (((void *)0)), .expires = (0), .data = (0), .base = &boot_tvec_bases, };

static void cancel_activity(void)
{
 unsigned long flags;

 flags = _spin_lock_irqsave(&floppy_lock);
 do_floppy = ((void *)0);
 do { (&floppy_work)->func = ((work_func_t)empty); } while (0);
 del_timer(&fd_timer);
 _spin_unlock_irqrestore(&floppy_lock, flags);
}



static void fd_watchdog(void)
{

 if ((&drive_params[current_drive])->flags & 0x02) {
  printk("floppy" "%d: " "calling disk change from watchdog\n", current_drive);
 }


 if (disk_change(current_drive)) {
  printk("floppy" "%d: " "disk removed during i/o\n", current_drive);
  cancel_activity();
  cont->done(0);
  reset_fdc();
 } else {
  del_timer(&fd_timer);
  fd_timer.function = (timeout_fn) fd_watchdog;
  fd_timer.expires = jiffies + 250 / 10;
  add_timer(&fd_timer);
 }
}

static void main_command_interrupt(void)
{
 del_timer(&fd_timer);
 cont->interrupt();
}


static int fd_wait_for_completion(unsigned long delay, timeout_fn function)
{
 if ((&fdc_state[fdc])->reset) {
  reset_fdc();


  return 1;
 }

 if ((({ unsigned long __dummy; typeof(delay) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ({ unsigned long __dummy; typeof(jiffies) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ((long)(jiffies) - (long)(delay) < 0))) {
  del_timer(&fd_timer);
  fd_timer.function = function;
  fd_timer.expires = delay;
  add_timer(&fd_timer);
  return 1;
 }
 return 0;
}

static spinlock_t floppy_hlt_lock = (spinlock_t) { .raw_lock = { 1 }, .magic = 0xdead4ead, .owner = ((void *)-1L), .owner_cpu = -1, .dep_map = { .name = "floppy_hlt_lock" } };
static int hlt_disabled;
static void floppy_disable_hlt(void)
{
 unsigned long flags;

 flags = _spin_lock_irqsave(&floppy_hlt_lock);
 if (!hlt_disabled) {
  hlt_disabled = 1;

  disable_hlt();

 }
 _spin_unlock_irqrestore(&floppy_hlt_lock, flags);
}

static void floppy_enable_hlt(void)
{
 unsigned long flags;

 flags = _spin_lock_irqsave(&floppy_hlt_lock);
 if (hlt_disabled) {
  hlt_disabled = 0;

  enable_hlt();

 }
 _spin_unlock_irqrestore(&floppy_hlt_lock, flags);
}

static void setup_DMA(void)
{
 unsigned long f;


 if (raw_cmd->length == 0) {
  int i;

  printk("zero dma transfer size:");
  for (i = 0; i < raw_cmd->cmd_count; i++)
   printk("%x,", raw_cmd->cmd[i]);
  printk("\n");
  cont->done(0);
  (&fdc_state[fdc])->reset = 1;
  return;
 }
 if (((unsigned long)raw_cmd->kernel_data) % 512) {
  printk("non aligned address: %p\n", raw_cmd->kernel_data);
  cont->done(0);
  (&fdc_state[fdc])->reset = 1;
  return;
 }

 f = claim_dma_lock();
 fd_disable_dma();

 if (fd_routine[use_virtual_dma&1]._dma_setup(raw_cmd->kernel_data, raw_cmd->length, (raw_cmd->flags & 1) ? 0x44 : 0x48, (&fdc_state[fdc])->address) < 0) {


  release_dma_lock(f);
  cont->done(0);
  (&fdc_state[fdc])->reset = 1;
  return;
 }
 release_dma_lock(f);
# 1141 "drivers/block/floppy.c"
 floppy_disable_hlt();
}

static void show_floppy(void);


static int wait_til_ready(void)
{
 int counter, status;
 if ((&fdc_state[fdc])->reset)
  return -1;
 for (counter = 0; counter < 10000; counter++) {
  status = inb_p((4 + fdc_state[fdc].address ));
  if (status & 0x80)
   return status;
 }
 if (!initialising) {
  printk("floppy" "%d: " "Getstatus times out (%x) on fdc %d\n", current_drive , status, fdc);
  show_floppy();
 }
 (&fdc_state[fdc])->reset = 1;
 return -1;
}


static int output_byte(char byte)
{
 int status;

 if ((status = wait_til_ready()) < 0)
  return -1;
 if ((status & (0x80 | 0x40 | 0x20)) == 0x80) {
  outb_p(byte,(5 + fdc_state[fdc].address ));

  output_log[output_log_pos].data = byte;
  output_log[output_log_pos].status = status;
  output_log[output_log_pos].jiffies = jiffies;
  output_log_pos = (output_log_pos + 1) % 20;

  return 0;
 }
 (&fdc_state[fdc])->reset = 1;
 if (!initialising) {
  printk("floppy" "%d: " "Unable to send byte %x to FDC. Fdc=%x Status=%x\n", current_drive , byte, fdc, status);

  show_floppy();
 }
 return -1;
}




static int result(void)
{
 int i, status = 0;

 for (i = 0; i < 16; i++) {
  if ((status = wait_til_ready()) < 0)
   break;
  status &= 0x40 | 0x80 | 0x10 | 0x20;
  if ((status & ~0x10) == 0x80) {

   resultjiffies = jiffies;
   resultsize = i;

   return i;
  }
  if (status == (0x40 | 0x80 | 0x10))
   reply_buffer[i] = inb_p((5 + fdc_state[fdc].address ));
  else
   break;
 }
 if (!initialising) {
  printk("floppy" "%d: " "get result error. Fdc=%d Last status=%x Read bytes=%d\n", current_drive , fdc, status, i);


  show_floppy();
 }
 (&fdc_state[fdc])->reset = 1;
 return -1;
}



static int need_more_output(void)
{
 int status;
 if ((status = wait_til_ready()) < 0)
  return -1;
 if ((status & (0x80 | 0x40 | 0x20)) == 0x80)
  return -2;
 return result();
}




static inline __attribute__((always_inline)) void perpendicular_mode(void)
{
 unsigned char perp_mode;

 if (raw_cmd->rate & 0x40) {
  switch (raw_cmd->rate & 3) {
  case 0:
   perp_mode = 2;
   break;
  case 3:
   perp_mode = 3;
   break;
  default:
   printk("floppy" "%d: " "Invalid data rate for perpendicular mode!\n", current_drive);
   cont->done(0);
   (&fdc_state[fdc])->reset = 1;


   return;
  }
 } else
  perp_mode = 0;

 if ((&fdc_state[fdc])->perp_mode == perp_mode)
  return;
 if ((&fdc_state[fdc])->version >= 0x51) {
  output_byte(0x12);
  output_byte(perp_mode);
  (&fdc_state[fdc])->perp_mode = perp_mode;
 } else if (perp_mode) {
  printk("floppy" "%d: " "perpendicular mode not supported by this FDC.\n", current_drive);
 }
}

static int fifo_depth = 0xa;
static int no_fifo;

static int fdc_configure(void)
{

 output_byte(0x13);
 if (need_more_output() != -2)
  return 0;
 output_byte(0);
 output_byte(0x10 | (no_fifo & 0x20) | (fifo_depth & 0xf));
 output_byte(0);

 return 1;
}
# 1310 "drivers/block/floppy.c"
static void fdc_specify(void)
{
 unsigned char spec1, spec2;
 unsigned long srt, hlt, hut;
 unsigned long dtr = 500;
 unsigned long scale_dtr = 500;
 int hlt_max_code = 0x7f;
 int hut_max_code = 0xf;

 if ((&fdc_state[fdc])->need_configure && (&fdc_state[fdc])->version >= 0x45) {
  fdc_configure();
  (&fdc_state[fdc])->need_configure = 0;

 }

 switch (raw_cmd->rate & 0x03) {
 case 3:
  dtr = 1000;
  break;
 case 1:
  dtr = 300;
  if ((&fdc_state[fdc])->version >= 0x60) {


   output_byte(0x8e);
   if (need_more_output() == -2) {
    output_byte(((current_drive) & 0x03));
    output_byte(0xc0);
   }
  }
  break;
 case 2:
  dtr = 250;
  break;
 }

 if ((&fdc_state[fdc])->version >= 0x40) {
  scale_dtr = dtr;
  hlt_max_code = 0x00;
  hut_max_code = 0x0;
 }


 srt = 16 - ((&drive_params[current_drive])->srt * scale_dtr / 1000 + 500 - 1) / 500;
 if (slow_floppy) {
  srt = srt / 4;
 }
 (srt)=({ int __x = (srt); int __y = (0xf); __x < __y ? __x: __y; });
 (srt)=({ int __x = (srt); int __y = (0); __x > __y ? __x: __y; });

 hlt = ((&drive_params[current_drive])->hlt * scale_dtr / 2 + 500 - 1) / 500;
 if (hlt < 0x01)
  hlt = 0x01;
 else if (hlt > 0x7f)
  hlt = hlt_max_code;

 hut = ((&drive_params[current_drive])->hut * scale_dtr / 16 + 500 - 1) / 500;
 if (hut < 0x1)
  hut = 0x1;
 else if (hut > 0xf)
  hut = hut_max_code;

 spec1 = (srt << 4) | hut;
 spec2 = (hlt << 1) | (use_virtual_dma & 1);


 if ((&fdc_state[fdc])->spec1 != spec1 || (&fdc_state[fdc])->spec2 != spec2) {

  output_byte(0x03);
  output_byte((&fdc_state[fdc])->spec1 = spec1);
  output_byte((&fdc_state[fdc])->spec2 = spec2);
 }
}





static int fdc_dtr(void)
{

 if ((raw_cmd->rate & 3) == (&fdc_state[fdc])->dtr)
  return 0;


 outb_p(raw_cmd->rate & 3,(7 + fdc_state[fdc].address ));






 (&fdc_state[fdc])->dtr = raw_cmd->rate & 3;
 return (fd_wait_for_completion(jiffies + 2UL * 250 / 100,
           (timeout_fn) floppy_ready));
}

static void tell_sector(void)
{
 printk(": track %d, head %d, sector %d, size %d",
        (reply_buffer[3]), (reply_buffer[4]), (reply_buffer[5]), (reply_buffer[6]));
}
# 1420 "drivers/block/floppy.c"
static int interpret_errors(void)
{
 char bad;

 if (inr != 7) {
  printk("floppy" "%d: " "-- FDC reply error", current_drive);
  (&fdc_state[fdc])->reset = 1;
  return 1;
 }


 switch ((reply_buffer[0]) & 0xC0) {
 case 0x40:
  if ((reply_buffer[1]) & 0x80)
   return 0;
  bad = 1;
  if ((reply_buffer[1]) & 0x02) {
   printk("floppy" "%d: " "Drive is write protected\n", current_drive);
   clear_bit(FD_DISK_WRITABLE_BIT, &(&drive_state[current_drive])->flags);
   cont->done(0);
   bad = 2;
  } else if ((reply_buffer[1]) & 0x04) {
   set_bit(FD_NEED_TWADDLE_BIT, &(&drive_state[current_drive])->flags);
  } else if ((reply_buffer[1]) & 0x10) {
   if ((&drive_params[current_drive])->flags & 0x10)
    printk("floppy" "%d: " "Over/Underrun - retrying\n", current_drive);
   bad = 0;
  } else if (*errors >= (&drive_params[current_drive])->max_errors.reporting) {
   printk("floppy" "%d: " "", current_drive);
   if ((reply_buffer[0]) & 0x10) {
    printk("Recalibrate failed!");
   } else if ((reply_buffer[2]) & 0x20) {
    printk("data CRC error");
    tell_sector();
   } else if ((reply_buffer[1]) & 0x20) {
    printk("CRC error");
    tell_sector();
   } else if (((reply_buffer[1]) & (0x01 | 0x04))
       || ((reply_buffer[2]) & 0x01)) {
    if (!probing) {
     printk("sector not found");
     tell_sector();
    } else
     printk("probe failed...");
   } else if ((reply_buffer[2]) & 0x10) {
    printk("wrong cylinder");
   } else if ((reply_buffer[2]) & 0x02) {
    printk("bad cylinder");
   } else {
    printk
        ("unknown error. ST[0..2] are: 0x%x 0x%x 0x%x",
         (reply_buffer[0]), (reply_buffer[1]), (reply_buffer[2]));
    tell_sector();
   }
   printk("\n");

  }
  if ((reply_buffer[2]) & 0x10 || (reply_buffer[2]) & 0x02)

   (&drive_state[current_drive])->track = -3;
  return bad;
 case 0x80:
  printk("floppy" "%d: " "Invalid FDC command given!\n", current_drive);
  cont->done(0);
  return 2;
 case 0xc0:
  printk("floppy" "%d: " "Abnormal termination caused by polling\n", current_drive);
  cont->error();
  return 2;
 default:
  return 0;
 }
}






static void setup_rw_floppy(void)
{
 int i, r, flags, dflags;
 unsigned long ready_date;
 timeout_fn function;

 flags = raw_cmd->flags;
 if (flags & (1 | 2))
  flags |= 8;

 if ((flags & 0x10) && !(flags & 4)) {
  ready_date = (&drive_state[current_drive])->spinup_date + (&drive_params[current_drive])->spinup;




  if ((({ unsigned long __dummy; typeof(ready_date) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ({ unsigned long __dummy; typeof(jiffies + (&drive_params[current_drive])->select_delay) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ((long)(jiffies + (&drive_params[current_drive])->select_delay) - (long)(ready_date) < 0))) {
   ready_date -= (&drive_params[current_drive])->select_delay;
   function = (timeout_fn) floppy_start;
  } else
   function = (timeout_fn) setup_rw_floppy;


  if (fd_wait_for_completion(ready_date, function))
   return;
 }
 dflags = (&drive_state[current_drive])->flags;

 if ((flags & 1) || (flags & 2))
  setup_DMA();

 if (flags & 8)
  do_floppy = main_command_interrupt;

 r = 0;
 for (i = 0; i < raw_cmd->cmd_count; i++)
  r |= output_byte(raw_cmd->cmd[i]);

 debugt("rw_command: ");

 if (r) {
  cont->error();
  reset_fdc();
  return;
 }

 if (!(flags & 8)) {
  inr = result();
  cont->interrupt();
 } else if (flags & 0x40)
  fd_watchdog();
}

static int blind_seek;





static void seek_interrupt(void)
{
 debugt("seek interrupt:");
 if (inr != 2 || ((reply_buffer[0]) & 0xF8) != 0x20) {
  printk("floppy" "%d: " "seek failed\n", current_drive);
  (&drive_state[current_drive])->track = -3;
  cont->error();
  cont->redo();
  return;
 }
 if ((&drive_state[current_drive])->track >= 0 && (&drive_state[current_drive])->track != (reply_buffer[1]) && !blind_seek) {

  if ((&drive_params[current_drive])->flags & 0x02) {
   printk("floppy" "%d: " "clearing NEWCHANGE flag because of effective seek\n", current_drive);

   printk("floppy" "%d: " "jiffies=%lu\n", current_drive , jiffies);
  }

  clear_bit(FD_DISK_NEWCHANGE_BIT, &(&drive_state[current_drive])->flags);
  (&drive_state[current_drive])->select_date = jiffies;
 }
 (&drive_state[current_drive])->track = (reply_buffer[1]);
 floppy_ready();
}

static void check_wp(void)
{
 if ((__builtin_constant_p(FD_VERIFY_BIT) ? constant_test_bit((FD_VERIFY_BIT),(&(&drive_state[current_drive])->flags)) : variable_test_bit((FD_VERIFY_BIT),(&(&drive_state[current_drive])->flags)))) {

  output_byte(0x04);
  output_byte(((current_drive) & 0x03));
  if (result() != 1) {
   (&fdc_state[fdc])->reset = 1;
   return;
  }
  clear_bit(FD_VERIFY_BIT, &(&drive_state[current_drive])->flags);
  clear_bit(FD_NEED_TWADDLE_BIT, &(&drive_state[current_drive])->flags);

  if ((&drive_params[current_drive])->flags & 0x02) {
   printk("floppy" "%d: " "checking whether disk is write protected\n", current_drive);
   printk("floppy" "%d: " "wp=%x\n", current_drive , (reply_buffer[0]) & 0x40);
  }

  if (!((reply_buffer[0]) & 0x40))
   set_bit(FD_DISK_WRITABLE_BIT, &(&drive_state[current_drive])->flags);
  else
   clear_bit(FD_DISK_WRITABLE_BIT, &(&drive_state[current_drive])->flags);
 }
}

static void seek_floppy(void)
{
 int track;

 blind_seek = 0;


 if ((&drive_params[current_drive])->flags & 0x02) {
  printk("floppy" "%d: " "calling disk change from seek\n", current_drive);
 }


 if (!(__builtin_constant_p(FD_DISK_NEWCHANGE_BIT) ? constant_test_bit((FD_DISK_NEWCHANGE_BIT),(&(&drive_state[current_drive])->flags)) : variable_test_bit((FD_DISK_NEWCHANGE_BIT),(&(&drive_state[current_drive])->flags))) &&
     disk_change(current_drive) && (raw_cmd->flags & 0x40)) {




  set_bit(FD_DISK_CHANGED_BIT, &(&drive_state[current_drive])->flags);
  cont->done(0);
  cont->redo();
  return;
 }
 if ((&drive_state[current_drive])->track <= -2) {
  recalibrate_floppy();
  return;
 } else if ((__builtin_constant_p(FD_DISK_NEWCHANGE_BIT) ? constant_test_bit((FD_DISK_NEWCHANGE_BIT),(&(&drive_state[current_drive])->flags)) : variable_test_bit((FD_DISK_NEWCHANGE_BIT),(&(&drive_state[current_drive])->flags))) &&
     (raw_cmd->flags & 0x40) &&
     ((&drive_state[current_drive])->track <= -1 || (&drive_state[current_drive])->track == raw_cmd->track)) {


  if (raw_cmd->track)
   track = raw_cmd->track - 1;
  else {
   if ((&drive_params[current_drive])->flags & 0x4) {
    set_dor(fdc, ~(0x10 << ((current_drive) & 0x03)), 0);
    blind_seek = 1;
    raw_cmd->flags |= 0x80;
   }
   track = 1;
  }
 } else {
  check_wp();
  if (raw_cmd->track != (&drive_state[current_drive])->track &&
      (raw_cmd->flags & 0x80))
   track = raw_cmd->track;
  else {
   setup_rw_floppy();
   return;
  }
 }

 do_floppy = seek_interrupt;
 output_byte(0x0F);
 output_byte(((current_drive) & 0x03));
 if (output_byte(track)<0){ reset_fdc();return;};
 debugt("seek command:");
}

static void recal_interrupt(void)
{
 debugt("recal interrupt:");
 if (inr != 2)
  (&fdc_state[fdc])->reset = 1;
 else if ((reply_buffer[0]) & 0x10) {
  switch ((&drive_state[current_drive])->track) {
  case -2:
   debugt("recal interrupt need 1 recal:");




   cont->error();
   cont->redo();
   return;
  case -3:
   debugt("recal interrupt need 2 recal:");







   if ((&drive_params[current_drive])->flags & 0x02) {
    printk("floppy" "%d: " "clearing NEWCHANGE flag because of second recalibrate\n", current_drive);

   }


   clear_bit(FD_DISK_NEWCHANGE_BIT, &(&drive_state[current_drive])->flags);
   (&drive_state[current_drive])->select_date = jiffies;

  default:
   debugt("recal interrupt default:");






   (&drive_state[current_drive])->track = -2;
   break;
  }
 } else
  (&drive_state[current_drive])->track = (reply_buffer[1]);
 floppy_ready();
}

static void print_result(char *message, int inr)
{
 int i;

 printk("floppy" "%d: " "%s ", current_drive , message);
 if (inr >= 0)
  for (i = 0; i < inr; i++)
   printk("repl[%d]=%x ", i, reply_buffer[i]);
 printk("\n");
}


irqreturn_t floppy_interrupt(int irq, void *dev_id)
{
 void (*handler) (void) = do_floppy;
 int do_print;
 unsigned long f;

 lasthandler = handler;
 interruptjiffies = jiffies;

 f = claim_dma_lock();
 fd_disable_dma();
 release_dma_lock(f);

 floppy_enable_hlt();
 do_floppy = ((void *)0);
 if (fdc >= 2 || (&fdc_state[fdc])->address == -1) {

  printk("DOR0=%x\n", fdc_state[0].dor);
  printk("floppy interrupt on bizarre fdc %d\n", fdc);
  printk("handler=%p\n", handler);
  is_alive("bizarre fdc");
  return (0);
 }

 (&fdc_state[fdc])->reset = 0;
# 1763 "drivers/block/floppy.c"
 do_print = !handler && print_unex && !initialising;

 inr = result();
 if (do_print)
  print_result("unexpected interrupt", inr);
 if (inr == 0) {
  int max_sensei = 4;
  do {
   output_byte(0x08);
   inr = result();
   if (do_print)
    print_result("sensei", inr);
   max_sensei--;
  } while (((reply_buffer[0]) & 0x83) != ((current_drive) & 0x03) && inr == 2
    && max_sensei);
 }
 if (!handler) {
  (&fdc_state[fdc])->reset = 1;
  return (0);
 }
 schedule_bh(handler);
 is_alive("normal interrupt end");


 return (1);
}

static void recalibrate_floppy(void)
{
 debugt("recalibrate floppy:");
 do_floppy = recal_interrupt;
 output_byte(0x07);
 if (output_byte(((current_drive) & 0x03))<0){ reset_fdc();return;};
}




static void reset_interrupt(void)
{
 debugt("reset interrupt:");
 result();
 if ((&fdc_state[fdc])->reset) {
  printk("reset set in interrupt, calling %p\n", cont->error);
  cont->error();
 }
 cont->redo();
}





static void reset_fdc(void)
{
 unsigned long flags;

 do_floppy = reset_interrupt;
 (&fdc_state[fdc])->reset = 0;
 reset_fdc_info(0);




 flags = claim_dma_lock();
 fd_disable_dma();
 release_dma_lock(flags);

 if ((&fdc_state[fdc])->version >= 0x45)
  outb_p(0x80 | ((&fdc_state[fdc])->dtr & 3),(4 + fdc_state[fdc].address ));
 else {
  outb_p((&fdc_state[fdc])->dor & ~0x04,(2 + fdc_state[fdc].address ));
  (__builtin_constant_p(20) ? ((20) > 20000 ? __bad_udelay() : __const_udelay((20) * 0x10c7ul)) : __udelay(20));
  outb_p((&fdc_state[fdc])->dor,(2 + fdc_state[fdc].address ));
 }
}

static void show_floppy(void)
{
 int i;

 printk("\n");
 printk("floppy driver state\n");
 printk("-------------------\n");
 printk("now=%lu last interrupt=%lu diff=%lu last called handler=%p\n",
        jiffies, interruptjiffies, jiffies - interruptjiffies,
        lasthandler);


 printk("timeout_message=%s\n", timeout_message);
 printk("last output bytes:\n");
 for (i = 0; i < 20; i++)
  printk("%2x %2x %lu\n",
         output_log[(i + output_log_pos) % 20].data,
         output_log[(i + output_log_pos) % 20].status,
         output_log[(i + output_log_pos) % 20].jiffies);
 printk("last result at %lu\n", resultjiffies);
 printk("last redo_fd_request at %lu\n", lastredo);
 for (i = 0; i < resultsize; i++) {
  printk("%2x ", reply_buffer[i]);
 }
 printk("\n");


 printk("status=%x\n", inb_p((4 + fdc_state[fdc].address )));
 printk("fdc_busy=%lu\n", fdc_busy);
 if (do_floppy)
  printk("do_floppy=%p\n", do_floppy);
 if ((__builtin_constant_p(0) ? constant_test_bit((0),(((unsigned long *)(&(&floppy_work)->data)))) : variable_test_bit((0),(((unsigned long *)(&(&floppy_work)->data))))))
  printk("floppy_work.func=%p\n", floppy_work.func);
 if (timer_pending(&fd_timer))
  printk("fd_timer.function=%p\n", fd_timer.function);
 if (timer_pending(&fd_timeout)) {
  printk("timer_function=%p\n", fd_timeout.function);
  printk("expires=%lu\n", fd_timeout.expires - jiffies);
  printk("now=%lu\n", jiffies);
 }
 printk("cont=%p\n", cont);
 printk("current_req=%p\n", current_req);
 printk("command_status=%d\n", command_status);
 printk("\n");
}

static void floppy_shutdown(unsigned long data)
{
 unsigned long flags;

 if (!initialising)
  show_floppy();
 cancel_activity();

 floppy_enable_hlt();

 flags = claim_dma_lock();
 fd_disable_dma();
 release_dma_lock(flags);



 if (!initialising)
  printk("floppy" "%d: " "floppy timeout called\n", current_drive);
 (&fdc_state[fdc])->reset = 1;
 if (cont) {
  cont->done(0);
  cont->redo();
 } else {
  printk("no cont in shutdown!\n");
  process_fd_request();
 }
 is_alive("floppy shutdown");
}




static int start_motor(void (*function) (void))
{
 int mask, data;

 mask = 0xfc;
 data = ((current_drive) & 0x03);
 if (!(raw_cmd->flags & 4)) {
  if (!((&fdc_state[fdc])->dor & (0x10 << ((current_drive) & 0x03)))) {
   set_debugt();

   (&drive_state[current_drive])->first_read_date = 0;

   (&drive_state[current_drive])->spinup_date = jiffies;
   data |= (0x10 << ((current_drive) & 0x03));
  }
 } else if ((&fdc_state[fdc])->dor & (0x10 << ((current_drive) & 0x03)))
  mask &= ~(0x10 << ((current_drive) & 0x03));


 del_timer(motor_off_timer + current_drive);
 set_dor(fdc, mask, data);


 return (fd_wait_for_completion((&drive_state[current_drive])->select_date + (&drive_params[current_drive])->select_delay,
           (timeout_fn) function));
}

static void floppy_ready(void)
{
 { if ((&fdc_state[fdc])->reset){ reset_fdc(); return; } };
 if (start_motor(floppy_ready))
  return;
 if (fdc_dtr())
  return;


 if ((&drive_params[current_drive])->flags & 0x02) {
  printk("floppy" "%d: " "calling disk change from floppy_ready\n", current_drive);
 }

 if (!(raw_cmd->flags & 4) &&
     disk_change(current_drive) && !(&drive_params[current_drive])->select_delay)
  twaddle();



 if ((raw_cmd->flags & 1) || (raw_cmd->flags & 2)) {
  unsigned long flags = claim_dma_lock();
  _fd_chose_dma_mode(raw_cmd->kernel_data, raw_cmd->length);
  release_dma_lock(flags);
 }


 if (raw_cmd->flags & (0x80 | 0x40)) {
  perpendicular_mode();
  fdc_specify();
  seek_floppy();
 } else {
  if ((raw_cmd->flags & 1) ||
      (raw_cmd->flags & 2))
   fdc_specify();
  setup_rw_floppy();
 }
}

static void floppy_start(void)
{
 reschedule_timeout(-1, "floppy start", 0);

 scandrives();

 if ((&drive_params[current_drive])->flags & 0x02) {
  printk("floppy" "%d: " "setting NEWCHANGE in floppy_start\n", current_drive);
 }

 set_bit(FD_DISK_NEWCHANGE_BIT, &(&drive_state[current_drive])->flags);
 floppy_ready();
}
# 2011 "drivers/block/floppy.c"
static void do_wakeup(void)
{
 reschedule_timeout(-2, "do wakeup", 0);
 cont = ((void *)0);
 command_status += 2;
 __wake_up(&command_done, 2 | 1, 1, ((void *)0));
}

static struct cont_t wakeup_cont = {
 .interrupt = empty,
 .redo = do_wakeup,
 .error = empty,
 .done = (done_f) empty
};

static struct cont_t intr_cont = {
 .interrupt = empty,
 .redo = process_fd_request,
 .error = empty,
 .done = (done_f) empty
};

static int wait_til_done(void (*handler) (void), int interruptible)
{
 int ret;

 schedule_bh(handler);

 if (command_status < 2 && (!interruptible || !signal_pending(get_current()))) {
  wait_queue_t wait = { .private = get_current(), .func = default_wake_function, .task_list = { ((void *)0), ((void *)0) } };

  add_wait_queue(&command_done, &wait);
  for (;;) {
   do { (void) ((__typeof__(*(&get_current()->state)))__xchg((unsigned long)((interruptible ? 1 : 2)),(&get_current()->state),sizeof(*(&get_current()->state)))); } while (0);



   if (command_status >= 2 || !(!interruptible || !signal_pending(get_current())))
    break;

   is_alive("wait_til_done");

   schedule();
  }

  do { (void) ((__typeof__(*(&get_current()->state)))__xchg((unsigned long)((0)),(&get_current()->state),sizeof(*(&get_current()->state)))); } while (0);
  remove_wait_queue(&command_done, &wait);
 }

 if (command_status < 2) {
  cancel_activity();
  cont = &intr_cont;
  reset_fdc();
  return -4;
 }

 if ((&fdc_state[fdc])->reset)
  command_status = 2;
 if (command_status == 3)
  ret = 0;
 else
  ret = -5;
 command_status = -1;
 return ret;
}

static void generic_done(int result)
{
 command_status = result;
 cont = &wakeup_cont;
}

static void generic_success(void)
{
 cont->done(1);
}

static void generic_failure(void)
{
 cont->done(0);
}

static void success_and_wakeup(void)
{
 generic_success();
 cont->redo();
}






static int next_valid_format(void)
{
 int probed_format;

 probed_format = (&drive_state[current_drive])->probed_format;
 while (1) {
  if (probed_format >= 8 || !(&drive_params[current_drive])->autodetect[probed_format]) {
   (&drive_state[current_drive])->probed_format = 0;
   return 1;
  }
  if (floppy_type[(&drive_params[current_drive])->autodetect[probed_format]].sect) {
   (&drive_state[current_drive])->probed_format = probed_format;
   return 0;
  }
  probed_format++;
 }
}

static void bad_flp_intr(void)
{
 int err_count;

 if (probing) {
  (&drive_state[current_drive])->probed_format++;
  if (!next_valid_format())
   return;
 }
 err_count = ++(*errors);
 ((&write_errors[current_drive])->badness)=({ int __x = ((&write_errors[current_drive])->badness); int __y = (err_count); __x > __y ? __x: __y; });
 if (err_count > (&drive_params[current_drive])->max_errors.abort)
  cont->done(0);
 if (err_count > (&drive_params[current_drive])->max_errors.reset)
  (&fdc_state[fdc])->reset = 1;
 else if (err_count > (&drive_params[current_drive])->max_errors.recal)
  (&drive_state[current_drive])->track = -3;
}

static void set_floppy(int drive)
{
 int type = ((((&drive_state[drive])->fd_device)>>2) & 0x1f);
 if (type)
  _floppy = floppy_type + type;
 else
  _floppy = current_type[drive];
}





static void format_interrupt(void)
{
 switch (interpret_errors()) {
 case 1:
  cont->error();
 case 2:
  break;
 case 0:
  cont->done(1);
 }
 cont->redo();
}




static void setup_format_params(int track)
{
 struct fparm {
  unsigned char track, head, sect, size;
 } *here = (struct fparm *)floppy_track_buffer;
 int il, n;
 int count, head_shift, track_shift;

 raw_cmd = &default_raw_cmd;
 raw_cmd->track = track;

 raw_cmd->flags = 2 | 8 | 0x10 |
     0x40 | 0x80;
 raw_cmd->rate = _floppy->rate & 0x43;
 raw_cmd->cmd_count = 6;
 raw_cmd->cmd[0] = ((0x4D) & ~(((_floppy)->rate & 0x80) >>1));
 raw_cmd->cmd[1] = ((current_drive) & 0x03) + (((((_floppy)->stretch & 2) >>1) ^ format_req.head) << 2);
 raw_cmd->cmd[2] = (((((_floppy)->rate&0x38)>> 3)+ 2) %8);
 raw_cmd->cmd[3] = _floppy->sect << 2 >> raw_cmd->cmd[2];
 raw_cmd->cmd[4] = _floppy->fmt_gap;
 raw_cmd->cmd[5] = 0xF6;

 raw_cmd->kernel_data = floppy_track_buffer;
 raw_cmd->length = 4 * raw_cmd->cmd[3];


 head_shift = (raw_cmd->cmd[3] + 5) / 6;


 track_shift = 2 * head_shift + 3;


 n = (track_shift * format_req.track + head_shift * format_req.head)
     % raw_cmd->cmd[3];


 il = 1;
 if (_floppy->fmt_gap < 0x22)
  il++;


 for (count = 0; count < raw_cmd->cmd[3]; ++count) {
  here[count].track = format_req.track;
  here[count].head = format_req.head;
  here[count].sect = 0;
  here[count].size = raw_cmd->cmd[2];
 }

 for (count = 1; count <= raw_cmd->cmd[3]; ++count) {
  here[n].sect = count;
  n = (n + il) % raw_cmd->cmd[3];
  if (here[n].sect) {
   ++n;
   if (n >= raw_cmd->cmd[3]) {
    n -= raw_cmd->cmd[3];
    while (here[n].sect)
     ++n;
   }
  }
 }
 if (_floppy->stretch & 4) {
  for (count = 0; count < raw_cmd->cmd[3]; count++)
   here[count].sect--;
 }
}

static void redo_format(void)
{
 buffer_track = -1;
 setup_format_params(format_req.track << ((_floppy)->stretch & 1));
 floppy_start();
 debugt("queue format request");
}

static struct cont_t format_cont = {
 .interrupt = format_interrupt,
 .redo = redo_format,
 .error = bad_flp_intr,
 .done = generic_done
};

static int do_format(int drive, struct format_descr *tmp_format_req)
{
 int ret;

 if (_lock_fdc(drive,1, 2255)) return -4;;
 set_floppy(drive);
 if (!_floppy ||
     _floppy->track > (&drive_params[current_drive])->tracks ||
     tmp_format_req->track >= _floppy->track ||
     tmp_format_req->head >= _floppy->head ||
     (_floppy->sect << 2) % (1 << (((((_floppy)->rate&0x38)>> 3)+ 2) %8)) ||
     !_floppy->fmt_gap) {
  process_fd_request();
  return -22;
 }
 format_req = *tmp_format_req;
 format_errors = 0;
 cont = &format_cont;
 errors = &format_errors;
 if ((ret=wait_til_done(((redo_format)),1)) == -4) return -4;
 process_fd_request();
 return ret;
}






static void floppy_end_request(struct request *req, int uptodate)
{
 unsigned int nr_sectors = current_count_sectors;


 if (!uptodate)
  nr_sectors = req->current_nr_sectors;
 if (end_that_request_first(req, uptodate, nr_sectors))
  return;
 add_disk_randomness(req->rq_disk);
 floppy_off((long)req->rq_disk->private_data);
 blkdev_dequeue_request(req);
 end_that_request_last(req, uptodate);


 current_req = ((void *)0);
}



static void request_done(int uptodate)
{
 struct request_queue *q = floppy_queue;
 struct request *req = current_req;
 unsigned long flags;
 int block;

 probing = 0;
 reschedule_timeout(-2, "request done %d", uptodate);

 if (!req) {
  printk("floppy.c: no request in request_done\n");
  return;
 }

 if (uptodate) {


  block = current_count_sectors + req->sector;
  ((&drive_state[current_drive])->maxblock)=({ int __x = ((&drive_state[current_drive])->maxblock); int __y = (block); __x > __y ? __x: __y; });
  if (block > _floppy->sect)
   (&drive_state[current_drive])->maxtrack = 1;


  flags = _spin_lock_irqsave(q->queue_lock);
  floppy_end_request(req, 1);
  _spin_unlock_irqrestore(q->queue_lock, flags);
 } else {
  if (((req)->cmd_flags & 1) == 1) {

   (&write_errors[current_drive])->write_errors++;
   if ((&write_errors[current_drive])->write_errors == 1) {
    (&write_errors[current_drive])->first_error_sector = req->sector;
    (&write_errors[current_drive])->first_error_generation = (&drive_state[current_drive])->generation;
   }
   (&write_errors[current_drive])->last_error_sector = req->sector;
   (&write_errors[current_drive])->last_error_generation = (&drive_state[current_drive])->generation;
  }
  flags = _spin_lock_irqsave(q->queue_lock);
  floppy_end_request(req, 0);
  _spin_unlock_irqrestore(q->queue_lock, flags);
 }
}


static void rw_interrupt(void)
{
 int nr_sectors, ssize, eoc, heads;

 if ((reply_buffer[4]) >= 2) {



  return;
 }

 if (!(&drive_state[current_drive])->first_read_date)
  (&drive_state[current_drive])->first_read_date = jiffies;

 nr_sectors = 0;
 (ssize = ((1 << raw_cmd->cmd[5]) + 3) >> 2);

 if ((reply_buffer[1]) & 0x80)
  eoc = 1;
 else
  eoc = 0;

 if (raw_cmd->cmd[0] & 0x80)
  heads = 2;
 else
  heads = 1;

 nr_sectors = ((((reply_buffer[3]) - raw_cmd->cmd[2]) * heads +
         (reply_buffer[4]) - raw_cmd->cmd[3]) * raw_cmd->cmd[6] +
        (reply_buffer[5]) - raw_cmd->cmd[4] + eoc) << raw_cmd->cmd[5] >> 2;


 if (nr_sectors / ssize >
     (in_sector_offset + current_count_sectors + ssize - 1) / ssize) {
  printk("floppy" "%d: " "long rw: %x instead of %lx\n", current_drive , nr_sectors, current_count_sectors);

  printk("rs=%d s=%d\n", (reply_buffer[5]), raw_cmd->cmd[4]);
  printk("rh=%d h=%d\n", (reply_buffer[4]), raw_cmd->cmd[3]);
  printk("rt=%d t=%d\n", (reply_buffer[3]), raw_cmd->cmd[2]);
  printk("heads=%d eoc=%d\n", heads, eoc);
  printk("spt=%d st=%d ss=%d\n", raw_cmd->cmd[6],
         fsector_t, ssize);
  printk("in_sector_offset=%d\n", in_sector_offset);
 }


 nr_sectors -= in_sector_offset;
 (nr_sectors)=({ int __x = (nr_sectors); int __y = (0); __x > __y ? __x: __y; });
 (current_count_sectors)=({ int __x = (current_count_sectors); int __y = (nr_sectors); __x < __y ? __x: __y; });

 switch (interpret_errors()) {
 case 2:
  cont->redo();
  return;
 case 1:
  if (!current_count_sectors) {
   cont->error();
   cont->redo();
   return;
  }
  break;
 case 0:
  if (!current_count_sectors) {
   cont->redo();
   return;
  }
  current_type[current_drive] = _floppy;
  floppy_sizes[((current_drive & 3) | ((current_drive & 4) << 5))] = _floppy->size;
  break;
 }

 if (probing) {
  if ((&drive_params[current_drive])->flags & 0x10)
   printk("floppy" "%d: " "Auto-detected floppy type %s in fd%d\n", current_drive , _floppy->name, current_drive);

  current_type[current_drive] = _floppy;
  floppy_sizes[((current_drive & 3) | ((current_drive & 4) << 5))] = _floppy->size;
  probing = 0;
 }

 if (((raw_cmd->cmd[0]) | 0xc0) != 0xE6 ||
     raw_cmd->kernel_data == current_req->buffer) {

  cont->done(1);
 } else if (((raw_cmd->cmd[0]) | 0xc0) == 0xE6) {
  buffer_track = raw_cmd->track;
  buffer_drive = current_drive;
  (buffer_max)=({ int __x = (buffer_max); int __y = (nr_sectors + fsector_t); __x > __y ? __x: __y; });
 }
 cont->redo();
}


static int buffer_chain_size(void)
{
 struct bio *bio;
 struct bio_vec *bv;
 int size, i;
 char *base;

 base = (page_address((&(((((current_req->bio))))->bi_io_vec[((((current_req->bio)))->bi_idx)]))->bv_page) + (&(((((current_req->bio))))->bi_io_vec[((((current_req->bio)))->bi_idx)]))->bv_offset);
 size = 0;

 if ((current_req->bio)) for (bio = (current_req)->bio; bio; bio = bio->bi_next) {
  for (bv = (&(((bio))->bi_io_vec[(((bio)->bi_idx))])), i = ((bio)->bi_idx); i < (bio)->bi_vcnt; bv++, i++) {
   if (page_address(bv->bv_page) + bv->bv_offset !=
       base + size)
    break;

   size += bv->bv_len;
  }
 }

 return size >> 9;
}


static int transfer_size(int ssize, int max_sector, int max_size)
{
 (max_sector)=({ int __x = (max_sector); int __y = (fsector_t + max_size); __x < __y ? __x: __y; });


 max_sector -= (max_sector % _floppy->sect) % ssize;


 current_count_sectors = max_sector - fsector_t;

 return max_sector;
}




static void copy_buffer(int ssize, int max_sector, int max_sector_2)
{
 int remaining;
 struct bio_vec *bv;
 struct bio *bio;
 char *buffer, *dma_buffer;
 int size, i;

 max_sector = transfer_size(ssize,
       ({ typeof(max_sector) _x = (max_sector); typeof(max_sector_2) _y = (max_sector_2); (void) (&_x == &_y); _x < _y ? _x : _y; }),
       current_req->nr_sectors);

 if (current_count_sectors <= 0 && ((raw_cmd->cmd[0]) | 0xc0) == 0xC5 &&
     buffer_max > fsector_t + current_req->nr_sectors)
  current_count_sectors = ({ int __x = (buffer_max - fsector_t); int __y = (current_req->nr_sectors); __x < __y ? __x: __y; });


 remaining = current_count_sectors << 9;

 if ((remaining >> 9) > current_req->nr_sectors &&
     ((raw_cmd->cmd[0]) | 0xc0) == 0xC5) {
  printk("floppy" "%d: " "in copy buffer\n", current_drive);
  printk("current_count_sectors=%ld\n", current_count_sectors);
  printk("remaining=%d\n", remaining >> 9);
  printk("current_req->nr_sectors=%ld\n",
         current_req->nr_sectors);
  printk("current_req->current_nr_sectors=%u\n",
         current_req->current_nr_sectors);
  printk("max_sector=%d\n", max_sector);
  printk("ssize=%d\n", ssize);
 }


 buffer_max = ({ typeof(max_sector) _x = (max_sector); typeof(buffer_max) _y = (buffer_max); (void) (&_x == &_y); _x > _y ? _x : _y; });

 dma_buffer = floppy_track_buffer + ((fsector_t - buffer_min) << 9);

 size = current_req->current_nr_sectors << 9;

 if ((current_req->bio)) for (bio = (current_req)->bio; bio; bio = bio->bi_next) {
  for (bv = (&(((bio))->bi_io_vec[(((bio)->bi_idx))])), i = ((bio)->bi_idx); i < (bio)->bi_vcnt; bv++, i++) {
   if (!remaining)
    break;

   size = bv->bv_len;
   (size)=({ int __x = (size); int __y = (remaining); __x < __y ? __x: __y; });

   buffer = page_address(bv->bv_page) + bv->bv_offset;

   if (dma_buffer + size >
       floppy_track_buffer + (max_buffer_sectors << 10) ||
       dma_buffer < floppy_track_buffer) {
    printk("floppy" "%d: " "buffer overrun in copy buffer %d\n", current_drive , (int)((floppy_track_buffer - dma_buffer) >> 9));


    printk("fsector_t=%d buffer_min=%d\n",
           fsector_t, buffer_min);
    printk("current_count_sectors=%ld\n",
           current_count_sectors);
    if (((raw_cmd->cmd[0]) | 0xc0) == 0xE6)
     printk("read\n");
    if (((raw_cmd->cmd[0]) | 0xc0) == 0xC5)
     printk("write\n");
    break;
   }
   if (((unsigned long)buffer) % 512)
    printk("floppy" "%d: " "%p buffer not aligned\n", current_drive , buffer);

   if (((raw_cmd->cmd[0]) | 0xc0) == 0xE6)
    (__builtin_constant_p(size) ? __constant_memcpy((buffer),(dma_buffer),(size)) : __memcpy((buffer),(dma_buffer),(size)));
   else
    (__builtin_constant_p(size) ? __constant_memcpy((dma_buffer),(buffer),(size)) : __memcpy((dma_buffer),(buffer),(size)));

   remaining -= size;
   dma_buffer += size;
  }
 }

 if (remaining) {
  if (remaining > 0)
   max_sector -= remaining >> 9;
  printk("floppy" "%d: " "weirdness: remaining %d\n", current_drive , remaining >> 9);
 }

}
# 2584 "drivers/block/floppy.c"
static void virtualdmabug_workaround(void)
{
 int hard_sectors, end_sector;

 if (((raw_cmd->cmd[0]) | 0xc0) == 0xC5) {
  raw_cmd->cmd[0] &= ~0x80;

  hard_sectors = raw_cmd->length >> (7 + raw_cmd->cmd[5]);
  end_sector = raw_cmd->cmd[4] + hard_sectors - 1;

  if (end_sector > raw_cmd->cmd[6]) {
   printk("too many sectors %d > %d\n",
          end_sector, raw_cmd->cmd[6]);
   return;
  }

  raw_cmd->cmd[6] = end_sector;

 }
}
# 2615 "drivers/block/floppy.c"
static int make_raw_rw_request(void)
{
 int aligned_sector_t;
 int max_sector, max_size, tracksize, ssize;

 if (max_buffer_sectors == 0) {
  printk("VFS: Block I/O scheduled on unopened device\n");
  return 0;
 }

 set_fdc((long)current_req->rq_disk->private_data);

 raw_cmd = &default_raw_cmd;
 raw_cmd->flags = 0x10 | 0x40 | 0x40 |
     0x80;
 raw_cmd->cmd_count = 9;
 if (((current_req)->cmd_flags & 1) == 0) {
  raw_cmd->flags |= 1;
  raw_cmd->cmd[0] = ((0xE6) & ~(((_floppy)->rate & 0x80) >>1));
 } else if (((current_req)->cmd_flags & 1) == 1) {
  raw_cmd->flags |= 2;
  raw_cmd->cmd[0] = ((0xC5) & ~(((_floppy)->rate & 0x80) >>1));
 } else {
  printk("floppy" "%d: " "make_raw_rw_request: unknown command\n", current_drive);
  return 0;
 }

 max_sector = _floppy->sect * _floppy->head;

 raw_cmd->cmd[2] = (int)current_req->sector / max_sector;
 fsector_t = (int)current_req->sector % max_sector;
 if (_floppy->track && raw_cmd->cmd[2] >= _floppy->track) {
  if (current_req->current_nr_sectors & 1) {
   current_count_sectors = 1;
   return 1;
  } else
   return 0;
 }
 raw_cmd->cmd[3] = fsector_t / _floppy->sect;

 if (((_floppy->stretch & (2 | 4)) ||
      (__builtin_constant_p(FD_NEED_TWADDLE_BIT) ? constant_test_bit((FD_NEED_TWADDLE_BIT),(&(&drive_state[current_drive])->flags)) : variable_test_bit((FD_NEED_TWADDLE_BIT),(&(&drive_state[current_drive])->flags)))) && fsector_t < _floppy->sect)
  max_sector = _floppy->sect;


 if ((_floppy->rate & 0x4) && (!raw_cmd->cmd[2]) && (!raw_cmd->cmd[3])) {
  max_sector = 2 * _floppy->sect / 3;
  if (fsector_t >= max_sector) {
   current_count_sectors =
       ({ int __x = (_floppy->sect - fsector_t); int __y = (current_req->nr_sectors); __x < __y ? __x: __y; });

   return 1;
  }
  raw_cmd->cmd[5] = 2;
 } else
  raw_cmd->cmd[5] = (((((_floppy)->rate&0x38)>> 3)+ 2) %8);
 raw_cmd->rate = _floppy->rate & 0x43;
 if ((_floppy->rate & 0x4) && (raw_cmd->cmd[2] || raw_cmd->cmd[3]) && raw_cmd->rate == 2)
  raw_cmd->rate = 1;

 if (raw_cmd->cmd[5])
  raw_cmd->cmd[8] = 0xff;
 else
  raw_cmd->cmd[8] = 0x80;
 raw_cmd->track = raw_cmd->cmd[2] << ((_floppy)->stretch & 1);
 raw_cmd->cmd[1] = ((current_drive) & 0x03) + (((((_floppy)->stretch & 2) >>1) ^ raw_cmd->cmd[3]) << 2);
 raw_cmd->cmd[7] = _floppy->gap;
 (ssize = ((1 << raw_cmd->cmd[5]) + 3) >> 2);
 raw_cmd->cmd[6] = _floppy->sect << 2 >> raw_cmd->cmd[5];
 raw_cmd->cmd[4] = ((fsector_t % _floppy->sect) << 2 >> raw_cmd->cmd[5]) +
     ((_floppy->stretch & 4) ? 0 : 1);




 tracksize = _floppy->sect - _floppy->sect % ssize;
 if (tracksize < _floppy->sect) {
  raw_cmd->cmd[6]++;
  if (tracksize <= fsector_t % _floppy->sect)
   raw_cmd->cmd[4]--;


  while (tracksize <= fsector_t % _floppy->sect) {
   while (tracksize + ssize > _floppy->sect) {
    raw_cmd->cmd[5]--;
    ssize >>= 1;
   }
   raw_cmd->cmd[4]++;
   raw_cmd->cmd[6]++;
   tracksize += ssize;
  }
  max_sector = raw_cmd->cmd[3] * _floppy->sect + tracksize;
 } else if (!raw_cmd->cmd[2] && !raw_cmd->cmd[3] && !(_floppy->rate & 0x4) && probing) {
  max_sector = _floppy->sect;
 } else if (!raw_cmd->cmd[3] && ((raw_cmd->cmd[0]) | 0xc0) == 0xC5) {

  max_sector = _floppy->sect;
 }

 in_sector_offset = (fsector_t % _floppy->sect) % ssize;
 aligned_sector_t = fsector_t - in_sector_offset;
 max_size = current_req->nr_sectors;
 if ((raw_cmd->track == buffer_track) &&
     (current_drive == buffer_drive) &&
     (fsector_t >= buffer_min) && (fsector_t < buffer_max)) {

  if (((raw_cmd->cmd[0]) | 0xc0) == 0xE6) {
   copy_buffer(1, max_sector, buffer_max);
   return 1;
  }
 } else if (in_sector_offset || current_req->nr_sectors < ssize) {
  if (((raw_cmd->cmd[0]) | 0xc0) == 0xC5) {
   if (fsector_t + current_req->nr_sectors > ssize &&
       fsector_t + current_req->nr_sectors < ssize + ssize)
    max_size = ssize + ssize;
   else
    max_size = ssize;
  }
  raw_cmd->flags &= ~2;
  raw_cmd->flags |= 1;
  raw_cmd->cmd[0] = ((0xE6) & ~(((_floppy)->rate & 0x80) >>1));
 } else if ((unsigned long)current_req->buffer < (((unsigned long)((unsigned long)0xC0000000))+0x1000000)) {
  unsigned long dma_limit;
  int direct, indirect;

  indirect =
      transfer_size(ssize, max_sector,
      max_buffer_sectors * 2) - fsector_t;





  max_size = buffer_chain_size();
  dma_limit =
      ((((unsigned long)((unsigned long)0xC0000000))+0x1000000) -
       ((unsigned long)current_req->buffer)) >> 9;
  if ((unsigned long)max_size > dma_limit) {
   max_size = dma_limit;
  }

  if ((!(use_virtual_dma & 1) && ((unsigned long)(current_req->buffer)/0x10000 != ((unsigned long)(current_req->buffer) + (max_size << 9) - 1) / 0x10000)))
   max_size = (0x10000 -
        ((unsigned long)current_req->buffer) %
        0x10000) >> 9;
  direct = transfer_size(ssize, max_sector, max_size) - fsector_t;







  if (!direct ||
      (indirect * 2 > direct * 3 &&
       *errors < (&drive_params[current_drive])->max_errors.read_track &&

       ((!probing
         || ((&drive_params[current_drive])->read_track & (1 << (&drive_state[current_drive])->probed_format)))))) {
   max_size = current_req->nr_sectors;
  } else {
   raw_cmd->kernel_data = current_req->buffer;
   raw_cmd->length = current_count_sectors << 9;
   if (raw_cmd->length == 0) {
    printk("floppy" "%d: " "zero dma transfer attempted from make_raw_request\n", current_drive);

    printk("floppy" "%d: " "indirect=%d direct=%d fsector_t=%d", current_drive , indirect, direct, fsector_t);

    return 0;
   }




   virtualdmabug_workaround();
   return 2;
  }
 }

 if (((raw_cmd->cmd[0]) | 0xc0) == 0xE6)
  max_size = max_sector;


 if (buffer_track != raw_cmd->track ||
     buffer_drive != current_drive ||
     fsector_t > buffer_max ||
     fsector_t < buffer_min ||
     ((((raw_cmd->cmd[0]) | 0xc0) == 0xE6 ||
       (!in_sector_offset && current_req->nr_sectors >= ssize)) &&
      max_sector > 2 * max_buffer_sectors + buffer_min &&
      max_size + fsector_t > 2 * max_buffer_sectors + buffer_min)

     ) {
  buffer_track = -1;
  buffer_drive = current_drive;
  buffer_max = buffer_min = aligned_sector_t;
 }
 raw_cmd->kernel_data = floppy_track_buffer +
     ((aligned_sector_t - buffer_min) << 9);

 if (((raw_cmd->cmd[0]) | 0xc0) == 0xC5) {





  if (in_sector_offset && buffer_track == -1)
   printk("floppy" "%d: " "internal error offset !=0 on write\n", current_drive);

  buffer_track = raw_cmd->track;
  buffer_drive = current_drive;
  copy_buffer(ssize, max_sector,
       2 * max_buffer_sectors + buffer_min);
 } else
  transfer_size(ssize, max_sector,
         2 * max_buffer_sectors + buffer_min -
         aligned_sector_t);


 raw_cmd->length = in_sector_offset + current_count_sectors;
 raw_cmd->length = ((raw_cmd->length - 1) | (ssize - 1)) + 1;
 raw_cmd->length <<= 9;



 if ((raw_cmd->length < current_count_sectors << 9) ||
     (raw_cmd->kernel_data != current_req->buffer &&
      ((raw_cmd->cmd[0]) | 0xc0) == 0xC5 &&
      (aligned_sector_t + (raw_cmd->length >> 9) > buffer_max ||
       aligned_sector_t < buffer_min)) ||
     raw_cmd->length % (128 << raw_cmd->cmd[5]) ||
     raw_cmd->length <= 0 || current_count_sectors <= 0) {
  printk("floppy" "%d: " "fractionary current count b=%lx s=%lx\n", current_drive , raw_cmd->length, current_count_sectors);

  if (raw_cmd->kernel_data != current_req->buffer)
   printk("addr=%d, length=%ld\n",
          (int)((raw_cmd->kernel_data -
          floppy_track_buffer) >> 9),
          current_count_sectors);
  printk("st=%d ast=%d mse=%d msi=%d\n",
         fsector_t, aligned_sector_t, max_sector, max_size);
  printk("ssize=%x SIZECODE=%d\n", ssize, raw_cmd->cmd[5]);
  printk("command=%x SECTOR=%d HEAD=%d, TRACK=%d\n",
         raw_cmd->cmd[0], raw_cmd->cmd[4], raw_cmd->cmd[3], raw_cmd->cmd[2]);
  printk("buffer drive=%d\n", buffer_drive);
  printk("buffer track=%d\n", buffer_track);
  printk("buffer_min=%d\n", buffer_min);
  printk("buffer_max=%d\n", buffer_max);
  return 0;
 }

 if (raw_cmd->kernel_data != current_req->buffer) {
  if (raw_cmd->kernel_data < floppy_track_buffer ||
      current_count_sectors < 0 ||
      raw_cmd->length < 0 ||
      raw_cmd->kernel_data + raw_cmd->length >
      floppy_track_buffer + (max_buffer_sectors << 10)) {
   printk("floppy" "%d: " "buffer overrun in schedule dma\n", current_drive);
   printk("fsector_t=%d buffer_min=%d current_count=%ld\n",
          fsector_t, buffer_min, raw_cmd->length >> 9);
   printk("current_count_sectors=%ld\n",
          current_count_sectors);
   if (((raw_cmd->cmd[0]) | 0xc0) == 0xE6)
    printk("read\n");
   if (((raw_cmd->cmd[0]) | 0xc0) == 0xC5)
    printk("write\n");
   return 0;
  }
 } else if (raw_cmd->length > current_req->nr_sectors << 9 ||
     current_count_sectors > current_req->nr_sectors) {
  printk("floppy" "%d: " "buffer overrun in direct transfer\n", current_drive);
  return 0;
 } else if (raw_cmd->length < current_count_sectors << 9) {
  printk("floppy" "%d: " "more sectors than bytes\n", current_drive);
  printk("bytes=%ld\n", raw_cmd->length >> 9);
  printk("sectors=%ld\n", current_count_sectors);
 }
 if (raw_cmd->length == 0) {
  printk("floppy" "%d: " "zero dma transfer attempted from make_raw_request\n", current_drive);
  return 0;
 }


 virtualdmabug_workaround();
 return 2;
}

static void redo_fd_request(void)
{

 int drive;
 int tmp;

 lastredo = jiffies;
 if (current_drive < 8)
  floppy_off(current_drive);

 for (;;) {
  if (!current_req) {
   struct request *req;

   _spin_lock_irq(floppy_queue->queue_lock);
   req = elv_next_request(floppy_queue);
   _spin_unlock_irq(floppy_queue->queue_lock);
   if (!req) {
    do_floppy = ((void *)0);
    unlock_fdc();
    return;
   }
   current_req = req;
  }
  drive = (long)current_req->rq_disk->private_data;
  set_fdc(drive);
  reschedule_timeout(-1, "redo fd request", 0);

  set_floppy(drive);
  raw_cmd = &default_raw_cmd;
  raw_cmd->flags = 0;
  if (start_motor(redo_fd_request))
   return;
  disk_change(current_drive);
  if ((__builtin_constant_p(current_drive) ? constant_test_bit((current_drive),(&fake_change)) : variable_test_bit((current_drive),(&fake_change))) ||
      (__builtin_constant_p(FD_DISK_CHANGED_BIT) ? constant_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[current_drive])->flags)) : variable_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[current_drive])->flags)))) {
   printk("floppy" "%d: " "disk absent or changed during operation\n", current_drive);
   {request_done(0); continue; };
  }
  if (!_floppy) {
   if (!probing) {
    (&drive_state[current_drive])->probed_format = 0;
    if (next_valid_format()) {
     printk("floppy" "%d: " "no autodetectable formats\n", current_drive);
     _floppy = ((void *)0);
     {request_done(0); continue; };
    }
   }
   probing = 1;
   _floppy =
       floppy_type + (&drive_params[current_drive])->autodetect[(&drive_state[current_drive])->probed_format];
  } else
   probing = 0;
  errors = &(current_req->errors);
  tmp = make_raw_rw_request();
  if (tmp < 2) {
   request_done(tmp);
   continue;
  }

  if ((__builtin_constant_p(FD_NEED_TWADDLE_BIT) ? constant_test_bit((FD_NEED_TWADDLE_BIT),(&(&drive_state[current_drive])->flags)) : variable_test_bit((FD_NEED_TWADDLE_BIT),(&(&drive_state[current_drive])->flags))))
   twaddle();
  schedule_bh(floppy_start);
  debugt("queue fd request");
  return;
 }

}

static struct cont_t rw_cont = {
 .interrupt = rw_interrupt,
 .redo = redo_fd_request,
 .error = bad_flp_intr,
 .done = request_done
};

static void process_fd_request(void)
{
 cont = &rw_cont;
 schedule_bh(redo_fd_request);
}

static void do_fd_request(request_queue_t * q)
{
 if (max_buffer_sectors == 0) {
  printk("VFS: do_fd_request called on non-open device\n");
  return;
 }

 if (usage_count == 0) {
  printk("warning: usage count=0, current_req=%p exiting\n",
         current_req);
  printk("sect=%ld type=%x flags=%x\n", (long)current_req->sector,
         current_req->cmd_type, current_req->cmd_flags);
  return;
 }
 if ((__builtin_constant_p(0) ? constant_test_bit((0),(&fdc_busy)) : variable_test_bit((0),(&fdc_busy)))) {


  is_alive("do fd request, old request running");
  return;
 }
 _lock_fdc(-2,0, 3004);
 process_fd_request();
 is_alive("do fd request");
}

static struct cont_t poll_cont = {
 .interrupt = success_and_wakeup,
 .redo = floppy_ready,
 .error = generic_failure,
 .done = generic_done
};

static int poll_drive(int interruptible, int flag)
{
 int ret;

 raw_cmd = &default_raw_cmd;
 raw_cmd->flags = flag;
 raw_cmd->track = 0;
 raw_cmd->cmd_count = 0;
 cont = &poll_cont;

 if ((&drive_params[current_drive])->flags & 0x02) {
  printk("floppy" "%d: " "setting NEWCHANGE in poll_drive\n", current_drive);
 }

 set_bit(FD_DISK_NEWCHANGE_BIT, &(&drive_state[current_drive])->flags);
 if ((ret=wait_til_done(((floppy_ready)),interruptible)) == -4) return -4;
 return ret;
}






static void reset_intr(void)
{
 printk("weird, reset interrupt called\n");
}

static struct cont_t reset_cont = {
 .interrupt = reset_intr,
 .redo = success_and_wakeup,
 .error = generic_failure,
 .done = generic_done
};

static int user_reset_fdc(int drive, int arg, int interruptible)
{
 int ret;

 ret = 0;
 if (_lock_fdc(drive,interruptible, 3057)) return -4;;
 if (arg == FD_RESET_ALWAYS)
  (&fdc_state[fdc])->reset = 1;
 if ((&fdc_state[fdc])->reset) {
  cont = &reset_cont;
  if ((ret=wait_til_done(((reset_fdc)),interruptible)) == -4) return -4;
 }
 process_fd_request();
 return ret;
}





static inline __attribute__((always_inline)) int fd_copyout(void *param, const void *address,
        unsigned long size)
{
 return copy_to_user(param, address, size) ? -14 : 0;
}

static inline __attribute__((always_inline)) int fd_copyin(void *param, void *address, unsigned long size)
{
 return copy_from_user(address, param, size) ? -14 : 0;
}







static inline __attribute__((always_inline)) const char *drive_name(int type, int drive)
{
 struct floppy_struct *floppy;

 if (type)
  floppy = floppy_type + type;
 else {
  if ((&drive_params[drive])->native_format)
   floppy = floppy_type + (&drive_params[drive])->native_format;
  else
   return "(null)";
 }
 if (floppy->name)
  return floppy->name;
 else
  return "(null)";
}


static void raw_cmd_done(int flag)
{
 int i;

 if (!flag) {
  raw_cmd->flags |= 0x10000;
  raw_cmd->flags |= 0x20000;
 } else {
  raw_cmd->reply_count = inr;
  if (raw_cmd->reply_count > 16)
   raw_cmd->reply_count = 0;
  for (i = 0; i < raw_cmd->reply_count; i++)
   raw_cmd->reply[i] = reply_buffer[i];

  if (raw_cmd->flags & (1 | 2)) {
   unsigned long flags;
   flags = claim_dma_lock();
   raw_cmd->length = fd_routine[use_virtual_dma&1]._get_dma_residue(FLOPPY_DMA);
   release_dma_lock(flags);
  }

  if ((raw_cmd->flags & 0x800) &&
      (!raw_cmd->reply_count || (raw_cmd->reply[0] & 0xc0)))
   raw_cmd->flags |= 0x10000;

  if (disk_change(current_drive))
   raw_cmd->flags |= 4;
  else
   raw_cmd->flags &= ~4;
  if (raw_cmd->flags & 0x20)
   motor_off_callback(current_drive);

  if (raw_cmd->next &&
      (!(raw_cmd->flags & 0x10000) ||
       !(raw_cmd->flags & 0x200)) &&
      ((raw_cmd->flags & 0x10000) ||
       !(raw_cmd->flags & 0x400))) {
   raw_cmd = raw_cmd->next;
   return;
  }
 }
 generic_done(flag);
}

static struct cont_t raw_cmd_cont = {
 .interrupt = success_and_wakeup,
 .redo = floppy_start,
 .error = generic_failure,
 .done = raw_cmd_done
};

static inline __attribute__((always_inline)) int raw_cmd_copyout(int cmd, char *param,
      struct floppy_raw_cmd *ptr)
{
 int ret;

 while (ptr) {
  if ((ret = ((copy_to_user((void *)param, &(*ptr), sizeof(*ptr)) ? -14 : 0)))) return ret;;
  param += sizeof(struct floppy_raw_cmd);
  if ((ptr->flags & 1) && ptr->buffer_length) {
   if (ptr->length >= 0
       && ptr->length <= ptr->buffer_length)
    if ((ret = (fd_copyout (ptr->data, ptr->kernel_data, ptr->buffer_length - ptr->length)))) return ret;;


  }
  ptr = ptr->next;
 }
 return 0;
}

static void raw_cmd_free(struct floppy_raw_cmd **ptr)
{
 struct floppy_raw_cmd *next, *this;

 this = *ptr;
 *ptr = ((void *)0);
 while (this) {
  if (this->buffer_length) {
   _fd_dma_mem_free((unsigned long)this->kernel_data, this->buffer_length);

   this->buffer_length = 0;
  }
  next = this->next;
  kfree(this);
  this = next;
 }
}

static inline __attribute__((always_inline)) int raw_cmd_copyin(int cmd, char *param,
     struct floppy_raw_cmd **rcmd)
{
 struct floppy_raw_cmd *ptr;
 int ret;
 int i;

 *rcmd = ((void *)0);
 while (1) {
  ptr = (struct floppy_raw_cmd *)
      kmalloc(sizeof(struct floppy_raw_cmd), ((( gfp_t)0x10u) | (( gfp_t)0x40u) | (( gfp_t)0x80u) | (( gfp_t)0x20000u)));
  if (!ptr)
   return -12;
  *rcmd = ptr;
  if ((ret = ((copy_from_user(&(*ptr), (void *)param, sizeof(*ptr)) ? -14 : 0)))) return ret;;
  ptr->next = ((void *)0);
  ptr->buffer_length = 0;
  param += sizeof(struct floppy_raw_cmd);
  if (ptr->cmd_count > 33)
# 3224 "drivers/block/floppy.c"
   return -22;

  for (i = 0; i < 16; i++)
   ptr->reply[i] = 0;
  ptr->resultcode = 0;
  ptr->kernel_data = ((void *)0);

  if (ptr->flags & (1 | 2)) {
   if (ptr->length <= 0)
    return -22;
   ptr->kernel_data =
       (char *)fd_routine[use_virtual_dma&1]._dma_mem_alloc(ptr->length);
   fallback_on_nodma_alloc(&ptr->kernel_data, ptr->length);
   if (!ptr->kernel_data)
    return -12;
   ptr->buffer_length = ptr->length;
  }
  if (ptr->flags & 2)
   if ((ret = (fd_copyin(ptr->data, ptr->kernel_data, ptr->length)))) return ret;;

  rcmd = &(ptr->next);
  if (!(ptr->flags & 0x100))
   return 0;
  ptr->rate &= 0x43;
 }
}

static int raw_cmd_ioctl(int cmd, void *param)
{
 int drive, ret, ret2;
 struct floppy_raw_cmd *my_raw_cmd;

 if ((&fdc_state[fdc])->rawcmd <= 1)
  (&fdc_state[fdc])->rawcmd = 1;
 for (drive = 0; drive < 8; drive++) {
  if ((((drive) & 0x04) >> 2) != fdc)
   continue;
  if (drive == current_drive) {
   if ((&drive_state[drive])->fd_ref > 1) {
    (&fdc_state[fdc])->rawcmd = 2;
    break;
   }
  } else if ((&drive_state[drive])->fd_ref) {
   (&fdc_state[fdc])->rawcmd = 2;
   break;
  }
 }

 if ((&fdc_state[fdc])->reset)
  return -5;

 ret = raw_cmd_copyin(cmd, param, &my_raw_cmd);
 if (ret) {
  raw_cmd_free(&my_raw_cmd);
  return ret;
 }

 raw_cmd = my_raw_cmd;
 cont = &raw_cmd_cont;
 ret = wait_til_done(floppy_start, 1);

 if ((&drive_params[current_drive])->flags & 0x02) {
  printk("floppy" "%d: " "calling disk change from raw_cmd ioctl\n", current_drive);
 }


 if (ret != -4 && (&fdc_state[fdc])->reset)
  ret = -5;

 (&drive_state[current_drive])->track = -1;

 ret2 = raw_cmd_copyout(cmd, param, my_raw_cmd);
 if (!ret)
  ret = ret2;
 raw_cmd_free(&my_raw_cmd);
 return ret;
}

static int invalidate_drive(struct block_device *bdev)
{

 set_bit((long)bdev->bd_disk->private_data, &fake_change);
 process_fd_request();
 check_disk_change(bdev);
 return 0;
}

static inline __attribute__((always_inline)) int set_geometry(unsigned int cmd, struct floppy_struct *g,
          int drive, int type, struct block_device *bdev)
{
 int cnt;


 if (g->sect <= 0 ||
     g->head <= 0 ||
     g->track <= 0 || g->track > (&drive_params[drive])->tracks >> ((g)->stretch & 1) ||

     (g->stretch & ~(1 | 2 | 4)) != 0)
  return -22;
 if (type) {
  if (!capable(21))
   return -1;
  mutex_lock(&open_lock);
  if (_lock_fdc(drive,1, 3327)) return -4;;
  floppy_type[type] = *g;
  floppy_type[type].name = "user format";
  for (cnt = type << 2; cnt < (type << 2) + 4; cnt++)
   floppy_sizes[cnt] = floppy_sizes[cnt + 0x80] =
       floppy_type[type].size + 1;
  process_fd_request();
  for (cnt = 0; cnt < 8; cnt++) {
   struct block_device *bdev = opened_bdev[cnt];
   if (!bdev || (((drive_state[cnt].fd_device)>>2) & 0x1f) != type)
    continue;
   __invalidate_device(bdev);
  }
  mutex_unlock(&open_lock);
 } else {
  int oldStretch;
  if (_lock_fdc(drive,1, 3343)) return -4;;
  if (cmd != (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x43)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))))


   if ((poll_drive(1, 0x40)) == -4) return -4;
  oldStretch = g->stretch;
  user_params[drive] = *g;
  if (buffer_drive == drive)
   (buffer_max)=({ int __x = (buffer_max); int __y = (user_params[drive].sect); __x < __y ? __x: __y; });
  current_type[drive] = &user_params[drive];
  floppy_sizes[drive] = user_params[drive].size;
  if (cmd == (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x43)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))))
   (&drive_state[current_drive])->keep_data = -1;
  else
   (&drive_state[current_drive])->keep_data = 1;





  if ((&drive_state[current_drive])->maxblock > user_params[drive].sect ||
      (&drive_state[current_drive])->maxtrack ||
      ((user_params[drive].sect ^ oldStretch) &
       (2 | 4)))
   invalidate_drive(bdev);
  else
   process_fd_request();
 }
 return 0;
}


static int ioctl_table[] = {
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x41)) << 0) | ((0) << ((0 +8)+8))),
 (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x42)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x43)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x04)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x45)) << 0) | ((0) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x46)) << 0) | ((0) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x47)) << 0) | ((0) << ((0 +8)+8))),
 (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x48)) << 0) | (((((sizeof(struct format_descr) == sizeof(struct format_descr[1]) && sizeof(struct format_descr) < (1 << 14)) ? sizeof(struct format_descr) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x49)) << 0) | ((0) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x4a)) << 0) | ((0) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x4b)) << 0) | ((0) << ((0 +8)+8))),
 (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x4c)) << 0) | (((((sizeof(struct floppy_max_errors) == sizeof(struct floppy_max_errors[1]) && sizeof(struct floppy_max_errors) < (1 << 14)) ? sizeof(struct floppy_max_errors) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x0e)) << 0) | (((((sizeof(struct floppy_max_errors) == sizeof(struct floppy_max_errors[1]) && sizeof(struct floppy_max_errors) < (1 << 14)) ? sizeof(struct floppy_max_errors) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x0f)) << 0) | (((((sizeof(floppy_drive_name) == sizeof(floppy_drive_name[1]) && sizeof(floppy_drive_name) < (1 << 14)) ? sizeof(floppy_drive_name) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x90)) << 0) | (((((sizeof(struct floppy_drive_params) == sizeof(struct floppy_drive_params[1]) && sizeof(struct floppy_drive_params) < (1 << 14)) ? sizeof(struct floppy_drive_params) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x11)) << 0) | (((((sizeof(struct floppy_drive_params) == sizeof(struct floppy_drive_params[1]) && sizeof(struct floppy_drive_params) < (1 << 14)) ? sizeof(struct floppy_drive_params) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x12)) << 0) | (((((sizeof(struct floppy_drive_struct) == sizeof(struct floppy_drive_struct[1]) && sizeof(struct floppy_drive_struct) < (1 << 14)) ? sizeof(struct floppy_drive_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x13)) << 0) | (((((sizeof(struct floppy_drive_struct) == sizeof(struct floppy_drive_struct[1]) && sizeof(struct floppy_drive_struct) < (1 << 14)) ? sizeof(struct floppy_drive_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x54)) << 0) | ((0) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x15)) << 0) | (((((sizeof(struct floppy_fdc_state) == sizeof(struct floppy_fdc_state[1]) && sizeof(struct floppy_fdc_state) < (1 << 14)) ? sizeof(struct floppy_fdc_state) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x56)) << 0) | ((0) << ((0 +8)+8))),
 (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x17)) << 0) | (((((sizeof(struct floppy_write_errors) == sizeof(struct floppy_write_errors[1]) && sizeof(struct floppy_write_errors) < (1 << 14)) ? sizeof(struct floppy_write_errors) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x58)) << 0) | ((0) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x5a)) << 0) | ((0) << ((0 +8)+8))),
 (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x59)) << 0) | ((0) << ((0 +8)+8)))
};

static inline __attribute__((always_inline)) int normalize_ioctl(int *cmd, int *size)
{
 int i;

 for (i = 0; i < (sizeof(ioctl_table) / sizeof((ioctl_table)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(ioctl_table), typeof(&ioctl_table[0])))]) - 1)); i++) {
  if ((*cmd & 0xffff) == (ioctl_table[i] & 0xffff)) {
   *size = (((*cmd) >> ((0 +8)+8)) & ((1 << 14)-1));
   *cmd = ioctl_table[i];
   if (*size > (((*cmd) >> ((0 +8)+8)) & ((1 << 14)-1))) {
    printk("ioctl not yet supported\n");
    return -14;
   }
   return 0;
  }
 }
 return -22;
}

static int get_floppy_geometry(int drive, int type, struct floppy_struct **g)
{
 if (type)
  *g = &floppy_type[type];
 else {
  if (_lock_fdc(drive,0, 3426)) return -4;;
  if ((poll_drive(0, 0)) == -4) return -4;
  process_fd_request();
  *g = current_type[drive];
 }
 if (!*g)
  return -19;
 return 0;
}

static int fd_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
 int drive = (long)bdev->bd_disk->private_data;
 int type = (((drive_state[drive].fd_device)>>2) & 0x1f);
 struct floppy_struct *g;
 int ret;

 ret = get_floppy_geometry(drive, type, &g);
 if (ret)
  return ret;

 geo->heads = g->head;
 geo->sectors = g->sect;
 geo->cylinders = g->track;
 return 0;
}

static int fd_ioctl(struct inode *inode, struct file *filp, unsigned int cmd,
      unsigned long param)
{




 int drive = (long)inode->i_bdev->bd_disk->private_data;
 int i, type = ((((&drive_state[drive])->fd_device)>>2) & 0x1f);
 int ret;
 int size;
 union inparam {
  struct floppy_struct g;
  struct format_descr f;
  struct floppy_max_errors max_errors;
  struct floppy_drive_params dp;
 } inparam;
 const char *outparam;




 if (cmd == 0x5309 ||
     cmd == 0x6470 ) {
  printk("floppy" "%d: " "obsolete eject ioctl\n", current_drive);
  printk("floppy" "%d: " "please use floppycontrol --eject\n", current_drive);
  cmd = (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x5a)) << 0) | ((0) << ((0 +8)+8)));
 }


 if ((cmd & 0xff00) == 0x0200) {
  if ((ret = (normalize_ioctl(&cmd, &size)))) return ret;;
 } else
  return -22;


 if (((cmd & 0x40) && !((filp) && (filp)->private_data)) ||
     ((cmd & 0x80) && !capable(21)))
  return -1;


 (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(*(&inparam)))) ? __constant_c_and_count_memset((((&inparam))),((0x01010101UL*(unsigned char)(0))),((sizeof(*(&inparam))))) : __constant_c_memset((((&inparam))),((0x01010101UL*(unsigned char)(0))),((sizeof(*(&inparam)))))) : (__builtin_constant_p((sizeof(*(&inparam)))) ? __memset_generic(((((&inparam)))),(((0))),(((sizeof(*(&inparam)))))) : __memset_generic((((&inparam))),((0)),((sizeof(*(&inparam)))))));
 if ((((cmd) >> (((0 +8)+8)+14)) & ((1 << 2)-1)) & 1U)
     if ((ret = (fd_copyin((void *)param, &inparam, size)))) return ret;;

 switch (cmd) {
  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x5a)) << 0) | ((0) << ((0 +8)+8))):
   if ((&drive_state[drive])->fd_ref != 1)

    return -16;
   if (_lock_fdc(drive,1, 3503)) return -4;;



   ret = fd_eject(((drive) & 0x03));

   set_bit(FD_DISK_CHANGED_BIT, &(&drive_state[drive])->flags);
   set_bit(FD_VERIFY_BIT, &(&drive_state[drive])->flags);
   process_fd_request();
   return ret;
  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x41)) << 0) | ((0) << ((0 +8)+8))):
   if (_lock_fdc(drive,1, 3514)) return -4;;
   current_type[drive] = ((void *)0);
   floppy_sizes[drive] = 4 << 1;
   (&drive_state[drive])->keep_data = 0;
   return invalidate_drive(inode->i_bdev);
  case (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x42)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))):
  case (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x43)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))):
   return set_geometry(cmd, &inparam.g,
         drive, type, inode->i_bdev);
  case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x04)) << 0) | (((((sizeof(struct floppy_struct) == sizeof(struct floppy_struct[1]) && sizeof(struct floppy_struct) < (1 << 14)) ? sizeof(struct floppy_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))):
   if ((ret = (get_floppy_geometry(drive, type, (struct floppy_struct **) &outparam)))) return ret;;


   break;

  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x45)) << 0) | ((0) << ((0 +8)+8))):
   (&drive_params[drive])->flags |= 0x10;
   return 0;
  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x46)) << 0) | ((0) << ((0 +8)+8))):
   (&drive_params[drive])->flags &= ~0x10;
   return 0;

  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x47)) << 0) | ((0) << ((0 +8)+8))):
   if (_lock_fdc(drive,1, 3537)) return -4;;
   if ((poll_drive(1, 0x40)) == -4) return -4;
   ret = (&drive_state[drive])->flags;
   process_fd_request();
   if (ret & (1 << FD_VERIFY_BIT))
    return -19;
   if (!(ret & (1 << FD_DISK_WRITABLE_BIT)))
    return -30;
   return 0;
  case (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x48)) << 0) | (((((sizeof(struct format_descr) == sizeof(struct format_descr[1]) && sizeof(struct format_descr) < (1 << 14)) ? sizeof(struct format_descr) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))):
   if ((&drive_state[drive])->fd_ref != 1)
    return -16;
   return do_format(drive, &inparam.f);
  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x49)) << 0) | ((0) << ((0 +8)+8))):
  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x4b)) << 0) | ((0) << ((0 +8)+8))):
   if (_lock_fdc(drive,1, 3552)) return -4;;
   return invalidate_drive(inode->i_bdev);

  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x4a)) << 0) | ((0) << ((0 +8)+8))):
   (&drive_params[drive])->max_errors.reporting =
       (unsigned short)(param & 0x0f);
   return 0;
   case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x0e)) << 0) | (((((sizeof(struct floppy_max_errors) == sizeof(struct floppy_max_errors[1]) && sizeof(struct floppy_max_errors) < (1 << 14)) ? sizeof(struct floppy_max_errors) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))): outparam = (const char *) (&(&drive_params[drive])->max_errors); break;
   case (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x4c)) << 0) | (((((sizeof(struct floppy_max_errors) == sizeof(struct floppy_max_errors[1]) && sizeof(struct floppy_max_errors) < (1 << 14)) ? sizeof(struct floppy_max_errors) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))): *(&(&drive_params[drive])->max_errors) = inparam. max_errors ; return 0;

  case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x0f)) << 0) | (((((sizeof(floppy_drive_name) == sizeof(floppy_drive_name[1]) && sizeof(floppy_drive_name) < (1 << 14)) ? sizeof(floppy_drive_name) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))):
   outparam = drive_name(type, drive);
   (size)=({ int __x = (size); int __y = (strlen(outparam) + 1); __x < __y ? __x: __y; });
   break;

   case (((1U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x90)) << 0) | (((((sizeof(struct floppy_drive_params) == sizeof(struct floppy_drive_params[1]) && sizeof(struct floppy_drive_params) < (1 << 14)) ? sizeof(struct floppy_drive_params) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))): *((&drive_params[drive])) = inparam. dp ; return 0;
   case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x11)) << 0) | (((((sizeof(struct floppy_drive_params) == sizeof(struct floppy_drive_params[1]) && sizeof(struct floppy_drive_params) < (1 << 14)) ? sizeof(struct floppy_drive_params) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))): outparam = (const char *) ((&drive_params[drive])); break;

  case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x13)) << 0) | (((((sizeof(struct floppy_drive_struct) == sizeof(struct floppy_drive_struct[1]) && sizeof(struct floppy_drive_struct) < (1 << 14)) ? sizeof(struct floppy_drive_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))):
   if (_lock_fdc(drive,1, 3571)) return -4;;
   if ((poll_drive(1, 0x40)) == -4) return -4;
   process_fd_request();

   case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x12)) << 0) | (((((sizeof(struct floppy_drive_struct) == sizeof(struct floppy_drive_struct[1]) && sizeof(struct floppy_drive_struct) < (1 << 14)) ? sizeof(struct floppy_drive_struct) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))): outparam = (const char *) ((&drive_state[drive])); break;

  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x54)) << 0) | ((0) << ((0 +8)+8))):
   return user_reset_fdc(drive, (int)param, 1);

   case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x15)) << 0) | (((((sizeof(struct floppy_fdc_state) == sizeof(struct floppy_fdc_state[1]) && sizeof(struct floppy_fdc_state) < (1 << 14)) ? sizeof(struct floppy_fdc_state) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))): outparam = (const char *) ((&fdc_state[(((drive) & 0x04) >> 2)])); break;

  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x56)) << 0) | ((0) << ((0 +8)+8))):
   (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(*((&write_errors[drive]))))) ? __constant_c_and_count_memset(((((&write_errors[drive])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&write_errors[drive])))))) : __constant_c_memset(((((&write_errors[drive])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&write_errors[drive]))))))) : (__builtin_constant_p((sizeof(*((&write_errors[drive]))))) ? __memset_generic((((((&write_errors[drive]))))),(((0))),(((sizeof(*((&write_errors[drive]))))))) : __memset_generic(((((&write_errors[drive])))),((0)),((sizeof(*((&write_errors[drive]))))))));
   return 0;
   case (((2U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x17)) << 0) | (((((sizeof(struct floppy_write_errors) == sizeof(struct floppy_write_errors[1]) && sizeof(struct floppy_write_errors) < (1 << 14)) ? sizeof(struct floppy_write_errors) : __invalid_size_argument_for_IOC))) << ((0 +8)+8))): outparam = (const char *) ((&write_errors[drive])); break;

  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x58)) << 0) | ((0) << ((0 +8)+8))):
   if (type)
    return -22;
   if (_lock_fdc(drive,1, 3590)) return -4;;
   set_floppy(drive);
   if ((i = raw_cmd_ioctl(cmd, (void *)param)) == -4) return -4;
   process_fd_request();
   return i;

  case (((0U) << (((0 +8)+8)+14)) | (((2)) << (0 +8)) | (((0x59)) << 0) | ((0) << ((0 +8)+8))):
   if (_lock_fdc(drive,1, 3597)) return -4;;
   twaddle();
   process_fd_request();
   return 0;

  default:
   return -22;
 }

 if ((((cmd) >> (((0 +8)+8)+14)) & ((1 << 2)-1)) & 2U)
  return fd_copyout((void *)param, outparam, size);
 else
  return 0;


}

static void __attribute__ ((__section__ (".init.text"))) config_types(void)
{
 int first = 1;
 int drive;


 drive = 0;
 if (!(&drive_params[drive])->cmos)
  (&drive_params[drive])->cmos = ({ unsigned long flags; unsigned char val; flags = _spin_lock_irqsave(&rtc_lock); val = (rtc_cmos_read(0x10) >> 4) & 15; _spin_unlock_irqrestore(&rtc_lock, flags); val; });
 drive = 1;
 if (!(&drive_params[drive])->cmos && ({ unsigned long flags; unsigned char val; flags = _spin_lock_irqsave(&rtc_lock); val = rtc_cmos_read(0x10) & 15; _spin_unlock_irqrestore(&rtc_lock, flags); val; }))
  (&drive_params[drive])->cmos = ({ unsigned long flags; unsigned char val; flags = _spin_lock_irqsave(&rtc_lock); val = rtc_cmos_read(0x10) & 15; _spin_unlock_irqrestore(&rtc_lock, flags); val; });




 for (drive = 0; drive < 8; drive++) {
  unsigned int type = (&drive_params[drive])->cmos;
  struct floppy_drive_params *params;
  const char *name = ((void *)0);
  static char temparea[32];

  if (type < (sizeof(default_drive_params) / sizeof((default_drive_params)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(default_drive_params), typeof(&default_drive_params[0])))]) - 1))) {
   params = &default_drive_params[type].params;
   if (type) {
    name = default_drive_params[type].name;
    allowed_drive_mask |= 1 << drive;
   } else
    allowed_drive_mask &= ~(1 << drive);
  } else {
   params = &default_drive_params[0].params;
   sprintf(temparea, "unknown type %d (usb?)", type);
   name = temparea;
  }
  if (name) {
   const char *prepend = ",";
   if (first) {
    prepend = "<6>" "Floppy drive(s):";
    first = 0;
   }
   printk("%s fd%d is %s", prepend, drive, name);
  }
  *(&drive_params[drive]) = *params;
 }
 if (!first)
  printk("\n");
}

static int floppy_release(struct inode *inode, struct file *filp)
{
 int drive = (long)inode->i_bdev->bd_disk->private_data;

 mutex_lock(&open_lock);
 if ((&drive_state[drive])->fd_ref < 0)
  (&drive_state[drive])->fd_ref = 0;
 else if (!(&drive_state[drive])->fd_ref--) {
  printk("floppy" "%d: " "floppy_release with fd_ref == 0", current_drive);
  (&drive_state[drive])->fd_ref = 0;
 }
 if (!(&drive_state[drive])->fd_ref)
  opened_bdev[drive] = ((void *)0);
 mutex_unlock(&open_lock);

 return 0;
}






static int floppy_open(struct inode *inode, struct file *filp)
{
 int drive = (long)inode->i_bdev->bd_disk->private_data;
 int old_dev;
 int try;
 int res = -16;
 char *tmp;

 filp->private_data = (void *)0;
 mutex_lock(&open_lock);
 old_dev = (&drive_state[drive])->fd_device;
 if (opened_bdev[drive] && opened_bdev[drive] != inode->i_bdev)
  goto out2;

 if (!(&drive_state[drive])->fd_ref && ((&drive_params[drive])->flags & 0x20)) {
  set_bit(FD_DISK_CHANGED_BIT, &(&drive_state[drive])->flags);
  set_bit(FD_VERIFY_BIT, &(&drive_state[drive])->flags);
 }

 if ((&drive_state[drive])->fd_ref == -1 || ((&drive_state[drive])->fd_ref && (filp->f_flags & 00000200)))
  goto out2;

 if (filp->f_flags & 00000200)
  (&drive_state[drive])->fd_ref = -1;
 else
  (&drive_state[drive])->fd_ref++;

 opened_bdev[drive] = inode->i_bdev;

 res = -6;

 if (!floppy_track_buffer) {


  if (((&drive_params[drive])->cmos == 6) || ((&drive_params[drive])->cmos == 5))
   try = 64;
  else
   try = 32;

  tmp = (char *)fd_routine[use_virtual_dma&1]._dma_mem_alloc(1024 * try);
  if (!tmp && !floppy_track_buffer) {
   try >>= 1;
   (try)=({ int __x = (try); int __y = (16); __x > __y ? __x: __y; });
   tmp = (char *)fd_routine[use_virtual_dma&1]._dma_mem_alloc(1024 * try);
  }
  if (!tmp && !floppy_track_buffer) {
   fallback_on_nodma_alloc(&tmp, 2048 * try);
  }
  if (!tmp && !floppy_track_buffer) {
   printk("floppy" "%d: " "Unable to allocate DMA memory\n", current_drive);
   goto out;
  }
  if (floppy_track_buffer) {
   if (tmp)
    _fd_dma_mem_free((unsigned long)tmp, try * 1024);
  } else {
   buffer_min = buffer_max = -1;
   floppy_track_buffer = tmp;
   max_buffer_sectors = try;
  }
 }

 (&drive_state[drive])->fd_device = iminor(inode);
 set_capacity(disks[drive], floppy_sizes[iminor(inode)]);
 if (old_dev != -1 && old_dev != iminor(inode)) {
  if (buffer_drive == drive)
   buffer_track = -1;
 }




 if ((filp->f_mode & 2) || !file_permission(filp, 2))
  filp->private_data = (void *)8;

 if ((&fdc_state[(((drive) & 0x04) >> 2)])->rawcmd == 1)
  (&fdc_state[(((drive) & 0x04) >> 2)])->rawcmd = 2;

 if (!(filp->f_flags & 00004000)) {
  if (filp->f_mode & 3) {
   (&drive_state[drive])->last_checked = 0;
   check_disk_change(inode->i_bdev);
   if ((__builtin_constant_p(FD_DISK_CHANGED_BIT) ? constant_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags))))
    goto out;
  }
  res = -30;
  if ((filp->f_mode & 2) && !((__builtin_constant_p(FD_DISK_WRITABLE_BIT) ? constant_test_bit((FD_DISK_WRITABLE_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_DISK_WRITABLE_BIT),(&(&drive_state[drive])->flags)))))
   goto out;
 }
 mutex_unlock(&open_lock);
 return 0;
out:
 if ((&drive_state[drive])->fd_ref < 0)
  (&drive_state[drive])->fd_ref = 0;
 else
  (&drive_state[drive])->fd_ref--;
 if (!(&drive_state[drive])->fd_ref)
  opened_bdev[drive] = ((void *)0);
out2:
 mutex_unlock(&open_lock);
 return res;
}




static int check_floppy_change(struct gendisk *disk)
{
 int drive = (long)disk->private_data;

 if ((__builtin_constant_p(FD_DISK_CHANGED_BIT) ? constant_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags))) || (__builtin_constant_p(FD_VERIFY_BIT) ? constant_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags))))
  return 1;

 if ((({ unsigned long __dummy; typeof(jiffies) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ({ unsigned long __dummy; typeof((&drive_state[drive])->last_checked + (&drive_params[drive])->checkfreq) __dummy2; (void)(&__dummy == &__dummy2); 1; }) && ((long)((&drive_state[drive])->last_checked + (&drive_params[drive])->checkfreq) - (long)(jiffies) < 0))) {
  _lock_fdc(drive,0, 3799);
  poll_drive(0, 0);
  process_fd_request();
 }

 if ((__builtin_constant_p(FD_DISK_CHANGED_BIT) ? constant_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags))) ||
     (__builtin_constant_p(FD_VERIFY_BIT) ? constant_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags))) ||
     (__builtin_constant_p(drive) ? constant_test_bit((drive),(&fake_change)) : variable_test_bit((drive),(&fake_change))) ||
     (!((((&drive_state[drive])->fd_device)>>2) & 0x1f) && !current_type[drive]))
  return 1;
 return 0;
}







static int floppy_rb0_complete(struct bio *bio, unsigned int bytes_done,
          int err)
{
 if (bio->bi_size)
  return 1;

 complete((struct completion *)bio->bi_private);
 return 0;
}

static int __floppy_read_block_0(struct block_device *bdev)
{
 struct bio bio;
 struct bio_vec bio_vec;
 struct completion complete;
 struct page *page;
 size_t size;

 page = alloc_pages_node(((0)), ((( gfp_t)0x10u)), 0);
 if (!page) {
  process_fd_request();
  return -12;
 }

 size = bdev->bd_block_size;
 if (!size)
  size = 1024;

 bio_init(&bio);
 bio.bi_io_vec = &bio_vec;
 bio_vec.bv_page = page;
 bio_vec.bv_len = size;
 bio_vec.bv_offset = 0;
 bio.bi_vcnt = 1;
 bio.bi_idx = 0;
 bio.bi_size = size;
 bio.bi_bdev = bdev;
 bio.bi_sector = 0;
 init_completion(&complete);
 bio.bi_private = &complete;
 bio.bi_end_io = floppy_rb0_complete;

 submit_bio(0, &bio);
 generic_unplug_device(bdev_get_queue(bdev));
 process_fd_request();
 wait_for_completion(&complete);

 __free_pages((page), 0);

 return 0;
}





static int floppy_revalidate(struct gendisk *disk)
{
 int drive = (long)disk->private_data;

 int cf;
 int res = 0;

 if ((__builtin_constant_p(FD_DISK_CHANGED_BIT) ? constant_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags))) ||
     (__builtin_constant_p(FD_VERIFY_BIT) ? constant_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags))) || (__builtin_constant_p(drive) ? constant_test_bit((drive),(&fake_change)) : variable_test_bit((drive),(&fake_change))) || (!current_type[drive] && !((((&drive_state[drive])->fd_device)>>2) & 0x1f))) {
  if (usage_count == 0) {
   printk("VFS: revalidate called on non-open device.\n");
   return -14;
  }
  _lock_fdc(drive,0, 3887);
  cf = (__builtin_constant_p(FD_DISK_CHANGED_BIT) ? constant_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_DISK_CHANGED_BIT),(&(&drive_state[drive])->flags))) || (__builtin_constant_p(FD_VERIFY_BIT) ? constant_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags)) : variable_test_bit((FD_VERIFY_BIT),(&(&drive_state[drive])->flags)));
  if (!(cf || (__builtin_constant_p(drive) ? constant_test_bit((drive),(&fake_change)) : variable_test_bit((drive),(&fake_change))) || (!current_type[drive] && !((((&drive_state[drive])->fd_device)>>2) & 0x1f)))) {
   process_fd_request();
   return 0;
  }
  (&drive_state[drive])->maxblock = 0;
  (&drive_state[drive])->maxtrack = 0;
  if (buffer_drive == drive)
   buffer_track = -1;
  clear_bit(drive, &fake_change);
  clear_bit(FD_DISK_CHANGED_BIT, &(&drive_state[drive])->flags);
  if (cf)
   (&drive_state[drive])->generation++;
  if ((!current_type[drive] && !((((&drive_state[drive])->fd_device)>>2) & 0x1f))) {

   res = __floppy_read_block_0(opened_bdev[drive]);
  } else {
   if (cf)
    poll_drive(0, 0x40);
   process_fd_request();
  }
 }
 set_capacity(disk, floppy_sizes[(&drive_state[drive])->fd_device]);
 return res;
}

static struct block_device_operations floppy_fops = {
 .owner = (&__this_module),
 .open = floppy_open,
 .release = floppy_release,
 .ioctl = fd_ioctl,
 .getgeo = fd_getgeo,
 .media_changed = check_floppy_change,
 .revalidate_disk = floppy_revalidate,
};
# 3931 "drivers/block/floppy.c"
static char __attribute__ ((__section__ (".init.text"))) get_fdc_version(void)
{
 int r;

 output_byte(0x0E);
 if ((&fdc_state[fdc])->reset)
  return 0x00;
 if ((r = result()) <= 0x00)
  return 0x00;
 if ((r == 1) && (reply_buffer[0] == 0x80)) {
  printk("<6>" "FDC %d is an 8272A\n", fdc);
  return 0x20;
 }
 if (r != 10) {
  printk
      ("FDC %d init: DUMPREGS: unexpected return of %d bytes.\n",
       fdc, r);
  return 0x10;
 }

 if (!fdc_configure()) {
  printk("<6>" "FDC %d is an 82072\n", fdc);
  return 0x40;
 }

 output_byte(0x12);
 if (need_more_output() == -2) {
  output_byte(0);
 } else {
  printk("<6>" "FDC %d is an 82072A\n", fdc);
  return 0x45;
 }

 output_byte(0x14);
 r = result();
 if ((r == 1) && (reply_buffer[0] == 0x80)) {
  printk("<6>" "FDC %d is a pre-1991 82077\n", fdc);
  return 0x51;

 }
 if ((r != 1) || (reply_buffer[0] != 0x00)) {
  printk("FDC %d init: UNLOCK: unexpected return of %d bytes.\n",
         fdc, r);
  return 0x10;
 }
 output_byte(0x18);
 r = result();
 if (r != 1) {
  printk("FDC %d init: PARTID: unexpected return of %d bytes.\n",
         fdc, r);
  return 0x10;
 }
 if (reply_buffer[0] == 0x80) {
  printk("<6>" "FDC %d is a post-1991 82077\n", fdc);
  return 0x52;
 }
 switch (reply_buffer[0] >> 5) {
 case 0x0:

  printk("<6>" "FDC %d is an 82078.\n", fdc);
  return 0x60;
 case 0x1:
  printk("<6>" "FDC %d is a 44pin 82078\n", fdc);
  return 0x60;
 case 0x2:
  printk("<6>" "FDC %d is a S82078B\n", fdc);
  return 0x62;
 case 0x3:
  printk("<6>" "FDC %d is a National Semiconductor PC87306\n",
         fdc);
  return 0x63;
 default:
  printk("<6>"
         "FDC %d init: 82078 variant with unknown PARTID=%d.\n",
         fdc, reply_buffer[0] >> 5);
  return 0x5f;
 }
}



static void __attribute__ ((__section__ (".init.text"))) floppy_set_flags(int *ints, int param, int param2)
{
 int i;

 for (i = 0; i < (sizeof(default_drive_params) / sizeof((default_drive_params)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(default_drive_params), typeof(&default_drive_params[0])))]) - 1)); i++) {
  if (param)
   default_drive_params[i].params.flags |= param2;
  else
   default_drive_params[i].params.flags &= ~param2;
 }
 printk("floppy" "%d: " "%s flag 0x%x\n", current_drive , param2 ? "Setting" : "Clearing", param);
}

static void __attribute__ ((__section__ (".init.text"))) daring(int *ints, int param, int param2)
{
 int i;

 for (i = 0; i < (sizeof(default_drive_params) / sizeof((default_drive_params)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(default_drive_params), typeof(&default_drive_params[0])))]) - 1)); i++) {
  if (param) {
   default_drive_params[i].params.select_delay = 0;
   default_drive_params[i].params.flags |=
       0x4;
  } else {
   default_drive_params[i].params.select_delay =
       2 * 250 / 100;
   default_drive_params[i].params.flags &=
       ~0x4;
  }
 }
 printk("floppy" "%d: " "Assuming %s floppy hardware\n", current_drive , param ? "standard" : "broken");
}

static void __attribute__ ((__section__ (".init.text"))) set_cmos(int *ints, int dummy, int dummy2)
{
 int current_drive = 0;

 if (ints[0] != 2) {
  printk("floppy" "%d: " "wrong number of parameters for CMOS\n", current_drive);
  return;
 }
 current_drive = ints[1];
 if (current_drive < 0 || current_drive >= 8) {
  printk("floppy" "%d: " "bad drive for set_cmos\n", current_drive);
  return;
 }

 if (current_drive >= 4 && !FDC2)
  FDC2 = 0x370;

 (&drive_params[current_drive])->cmos = ints[2];
 printk("floppy" "%d: " "setting CMOS code to %d\n", current_drive , ints[2]);
}

static struct param_table {
 const char *name;
 void (*fn) (int *ints, int param, int param2);
 int *var;
 int def_param;
 int param2;
} config_params[] __attribute__ ((__section__ (".init.data"))) = {
 {"allowed_drive_mask", ((void *)0), &allowed_drive_mask, 0xff, 0},
 {"all_drives", ((void *)0), &allowed_drive_mask, 0xff, 0},
 {"asus_pci", ((void *)0), &allowed_drive_mask, 0x33, 0},
 {"irq", ((void *)0), &FLOPPY_IRQ, 6, 0},
 {"dma", ((void *)0), &FLOPPY_DMA, 2, 0},
 {"daring", daring, ((void *)0), 1, 0},

 {"two_fdc", ((void *)0), &FDC2, 0x370, 0},
 {"one_fdc", ((void *)0), &FDC2, 0, 0},

 {"thinkpad", floppy_set_flags, ((void *)0), 1, 0x80},
 {"broken_dcl", floppy_set_flags, ((void *)0), 1, 0x20},
 {"messages", floppy_set_flags, ((void *)0), 1, 0x10},
 {"silent_dcl_clear", floppy_set_flags, ((void *)0), 1, 0x4},
 {"debug", floppy_set_flags, ((void *)0), 1, 0x02},
 {"nodma", ((void *)0), &can_use_virtual_dma, 1, 0},
 {"omnibook", ((void *)0), &can_use_virtual_dma, 1, 0},
 {"yesdma", ((void *)0), &can_use_virtual_dma, 0, 0},
 {"fifo_depth", ((void *)0), &fifo_depth, 0xa, 0},
 {"nofifo", ((void *)0), &no_fifo, 0x20, 0},
 {"usefifo", ((void *)0), &no_fifo, 0, 0},
 {"cmos", set_cmos, ((void *)0), 0, 0},
 {"slow", ((void *)0), &slow_floppy, 1, 0},
 {"unexpected_interrupts", ((void *)0), &print_unex, 1, 0},
 {"no_unexpected_interrupts", ((void *)0), &print_unex, 0, 0},
 {"L40SX", ((void *)0), &print_unex, 0, 0}


};

static int __attribute__ ((__section__ (".init.text"))) floppy_setup(char *str)
{
 int i;
 int param;
 int ints[11];

 str = get_options(str, (sizeof(ints) / sizeof((ints)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(ints), typeof(&ints[0])))]) - 1)), ints);
 if (str) {
  for (i = 0; i < (sizeof(config_params) / sizeof((config_params)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(config_params), typeof(&config_params[0])))]) - 1)); i++) {
   if (strcmp(str, config_params[i].name) == 0) {
    if (ints[0])
     param = ints[1];
    else
     param = config_params[i].def_param;
    if (config_params[i].fn)
     config_params[i].
         fn(ints, param,
            config_params[i].param2);
    if (config_params[i].var) {
     printk("floppy" "%d: " "%s=%d\n", current_drive , str, param);
     *config_params[i].var = param;
    }
    return 1;
   }
  }
 }
 if (str) {
  printk("floppy" "%d: " "unknown floppy option [%s]\n", current_drive , str);

  printk("floppy" "%d: " "allowed options are:", current_drive);
  for (i = 0; i < (sizeof(config_params) / sizeof((config_params)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(config_params), typeof(&config_params[0])))]) - 1)); i++)
   printk(" %s", config_params[i].name);
  printk("\n");
 } else
  printk("floppy" "%d: " "botched floppy option\n", current_drive);
 printk("floppy" "%d: " "Read Documentation/floppy.txt\n", current_drive);
 return 0;
}

static int have_no_fdc = -19;

static ssize_t floppy_cmos_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
 struct platform_device *p;
 int drive;

 p = ({ const typeof( ((struct platform_device *)0)->dev ) *__mptr = (dev); (struct platform_device *)( (char *)__mptr - __builtin_offsetof(struct platform_device,dev) );});
 drive = p->id;
 return sprintf(buf, "%X\n", (&drive_params[drive])->cmos);
}
struct device_attribute dev_attr_cmos = { .attr = {.name = "cmos", .mode = (00400|00040|00004) }, .show = floppy_cmos_show, .store = ((void *)0), };

static void floppy_device_release(struct device *dev)
{
 complete(&device_release);
}

static struct platform_device floppy_device[8];

static struct kobject *floppy_find(dev_t dev, int *part, void *data)
{
 int drive = (*part & 3) | ((*part & 0x80) >> 5);
 if (drive >= 8 ||
     !(allowed_drive_mask & (1 << drive)) ||
     fdc_state[(((drive) & 0x04) >> 2)].version == 0x00)
  return ((void *)0);
 if (((*part >> 2) & 0x1f) >= (sizeof(floppy_type) / sizeof((floppy_type)[0]) + (sizeof(char[1 - 2 * !!(__builtin_types_compatible_p(typeof(floppy_type), typeof(&floppy_type[0])))]) - 1)))
  return ((void *)0);
 *part = 0;
 return get_disk(disks[drive]);
}

static int __attribute__ ((__section__ (".init.text"))) floppy_init(void)
{
 int i, unit, drive;
 int err, dr;






 raw_cmd = ((void *)0);

 for (dr = 0; dr < 8; dr++) {
  disks[dr] = alloc_disk(1);
  if (!disks[dr]) {
   err = -12;
   goto out_put_disk;
  }

  disks[dr]->major = 2;
  disks[dr]->first_minor = ((dr & 3) | ((dr & 4) << 5));
  disks[dr]->fops = &floppy_fops;
  sprintf(disks[dr]->disk_name, "fd%d", dr);

  init_timer(&motor_off_timer[dr]);
  motor_off_timer[dr].data = dr;
  motor_off_timer[dr].function = motor_off_callback;
 }

 err = register_blkdev(2, "fd");
 if (err)
  goto out_put_disk;

 floppy_queue = blk_init_queue(do_fd_request, &floppy_lock);
 if (!floppy_queue) {
  err = -12;
  goto out_unreg_blkdev;
 }
 blk_queue_max_sectors(floppy_queue, 64);

 blk_register_region((((2) << 20) | (0)), 256, (&__this_module),
       floppy_find, ((void *)0), ((void *)0));

 for (i = 0; i < 256; i++)
  if ((((i)>>2) & 0x1f))
   floppy_sizes[i] = floppy_type[(((i)>>2) & 0x1f)].size;
  else
   floppy_sizes[i] = 4 << 1;

 reschedule_timeout(-2, "floppy init", -2);
 config_types();

 for (i = 0; i < 2; i++) {
  fdc = i;
  (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(*((&fdc_state[fdc]))))) ? __constant_c_and_count_memset(((((&fdc_state[fdc])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&fdc_state[fdc])))))) : __constant_c_memset(((((&fdc_state[fdc])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&fdc_state[fdc]))))))) : (__builtin_constant_p((sizeof(*((&fdc_state[fdc]))))) ? __memset_generic((((((&fdc_state[fdc]))))),(((0))),(((sizeof(*((&fdc_state[fdc]))))))) : __memset_generic(((((&fdc_state[fdc])))),((0)),((sizeof(*((&fdc_state[fdc]))))))));
  (&fdc_state[fdc])->dtr = -1;
  (&fdc_state[fdc])->dor = 0x4;







 }

 use_virtual_dma = can_use_virtual_dma & 1;
 fdc_state[0].address = FDC1;
 if (fdc_state[0].address == -1) {
  del_timer(&fd_timeout);
  err = -19;
  goto out_unreg_region;
 }

 fdc_state[1].address = FDC2;


 fdc = 0;
 err = floppy_grab_irq_and_dma();
 if (err) {
  del_timer(&fd_timeout);
  err = -16;
  goto out_unreg_region;
 }


 for (drive = 0; drive < 8; drive++) {
  (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(*((&drive_state[drive]))))) ? __constant_c_and_count_memset(((((&drive_state[drive])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&drive_state[drive])))))) : __constant_c_memset(((((&drive_state[drive])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&drive_state[drive]))))))) : (__builtin_constant_p((sizeof(*((&drive_state[drive]))))) ? __memset_generic((((((&drive_state[drive]))))),(((0))),(((sizeof(*((&drive_state[drive]))))))) : __memset_generic(((((&drive_state[drive])))),((0)),((sizeof(*((&drive_state[drive]))))))));
  (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(*((&write_errors[drive]))))) ? __constant_c_and_count_memset(((((&write_errors[drive])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&write_errors[drive])))))) : __constant_c_memset(((((&write_errors[drive])))),((0x01010101UL*(unsigned char)(0))),((sizeof(*((&write_errors[drive]))))))) : (__builtin_constant_p((sizeof(*((&write_errors[drive]))))) ? __memset_generic((((((&write_errors[drive]))))),(((0))),(((sizeof(*((&write_errors[drive]))))))) : __memset_generic(((((&write_errors[drive])))),((0)),((sizeof(*((&write_errors[drive]))))))));
  set_bit(FD_DISK_NEWCHANGE_BIT, &(&drive_state[drive])->flags);
  set_bit(FD_DISK_CHANGED_BIT, &(&drive_state[drive])->flags);
  set_bit(FD_VERIFY_BIT, &(&drive_state[drive])->flags);
  (&drive_state[drive])->fd_device = -1;
  floppy_track_buffer = ((void *)0);
  max_buffer_sectors = 0;
 }





 msleep(10);

 for (i = 0; i < 2; i++) {
  fdc = i;
  (&fdc_state[fdc])->driver_version = 0x100;
  for (unit = 0; unit < 4; unit++)
   (&fdc_state[fdc])->track[unit] = 0;
  if ((&fdc_state[fdc])->address == -1)
   continue;
  (&fdc_state[fdc])->rawcmd = 2;
  if (user_reset_fdc(-1, FD_RESET_ALWAYS, 0)) {

   __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 2), (4));
   __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 7), (1));
   (&fdc_state[fdc])->address = -1;
   (&fdc_state[fdc])->version = 0x00;
   continue;
  }

  (&fdc_state[fdc])->version = get_fdc_version();
  if ((&fdc_state[fdc])->version == 0x00) {

   __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 2), (4));
   __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 7), (1));
   (&fdc_state[fdc])->address = -1;
   continue;
  }
  if (can_use_virtual_dma == 2 && (&fdc_state[fdc])->version < 0x45)
   can_use_virtual_dma = 0;

  have_no_fdc = 0;




  user_reset_fdc(-1, FD_RESET_ALWAYS, 0);
 }
 fdc = 0;
 del_timer(&fd_timeout);
 current_drive = 0;
 initialising = 0;
 if (have_no_fdc) {
  printk("floppy" "%d: " "no floppy controllers found\n", current_drive);
  err = have_no_fdc;
  goto out_flush_work;
 }

 for (drive = 0; drive < 8; drive++) {
  if (!(allowed_drive_mask & (1 << drive)))
   continue;
  if (fdc_state[(((drive) & 0x04) >> 2)].version == 0x00)
   continue;

  floppy_device[drive].name = floppy_device_name;
  floppy_device[drive].id = drive;
  floppy_device[drive].dev.release = floppy_device_release;

  err = platform_device_register(&floppy_device[drive]);
  if (err)
   goto out_flush_work;

  err = device_create_file(&floppy_device[drive].dev,&dev_attr_cmos);
  if (err)
   goto out_unreg_platform_dev;


  disks[drive]->private_data = (void *)(long)drive;
  disks[drive]->queue = floppy_queue;
  disks[drive]->flags |= 1;
  disks[drive]->driverfs_dev = &floppy_device[drive].dev;
  add_disk(disks[drive]);
 }

 return 0;

out_unreg_platform_dev:
 platform_device_unregister(&floppy_device[drive]);
out_flush_work:
 flush_scheduled_work();
 if (usage_count)
  floppy_release_irq_and_dma();
out_unreg_region:
 blk_unregister_region((((2) << 20) | (0)), 256);
 blk_cleanup_queue(floppy_queue);
out_unreg_blkdev:
 unregister_blkdev(2, "fd");
out_put_disk:
 while (dr--) {
  del_timer(&motor_off_timer[dr]);
  put_disk(disks[dr]);
 }
 return err;
}

static spinlock_t floppy_usage_lock = (spinlock_t) { .raw_lock = { 1 }, .magic = 0xdead4ead, .owner = ((void *)-1L), .owner_cpu = -1, .dep_map = { .name = "floppy_usage_lock" } };

static int floppy_grab_irq_and_dma(void)
{
 unsigned long flags;

 flags = _spin_lock_irqsave(&floppy_usage_lock);
 if (usage_count++) {
  _spin_unlock_irqrestore(&floppy_usage_lock, flags);
  return 0;
 }
 _spin_unlock_irqrestore(&floppy_usage_lock, flags);





 flush_scheduled_work();

 if (fd_request_irq()) {
  printk("floppy" "%d: " "Unable to grab IRQ%d for the floppy driver\n", current_drive , FLOPPY_IRQ);

  flags = _spin_lock_irqsave(&floppy_usage_lock);
  usage_count--;
  _spin_unlock_irqrestore(&floppy_usage_lock, flags);
  return -1;
 }
 if (fd_routine[can_use_virtual_dma & 1]._request_dma(FLOPPY_DMA,"floppy")) {
  printk("floppy" "%d: " "Unable to grab DMA%d for the floppy driver\n", current_drive , FLOPPY_DMA);

  free_irq(FLOPPY_IRQ, ((void *)0));
  flags = _spin_lock_irqsave(&floppy_usage_lock);
  usage_count--;
  _spin_unlock_irqrestore(&floppy_usage_lock, flags);
  return -1;
 }

 for (fdc = 0; fdc < 2; fdc++) {
  if ((&fdc_state[fdc])->address != -1) {
   if (!__request_region(&ioport_resource, ((&fdc_state[fdc])->address + 2), (4), ("floppy"))) {
    printk("floppy" "%d: " "Floppy io-port 0x%04lx in use\n", current_drive , (&fdc_state[fdc])->address + 2);

    goto cleanup1;
   }
   if (!__request_region(&ioport_resource, ((&fdc_state[fdc])->address + 7), (1), ("floppy DIR"))) {
    printk("floppy" "%d: " "Floppy io-port 0x%04lx in use\n", current_drive , (&fdc_state[fdc])->address + 7);

    goto cleanup2;
   }


  }
 }
 for (fdc = 0; fdc < 2; fdc++) {
  if ((&fdc_state[fdc])->address != -1) {
   reset_fdc_info(1);
   outb_p((&fdc_state[fdc])->dor,(2 + fdc_state[fdc].address ));
  }
 }
 fdc = 0;
 set_dor(0, ~0, 8);

 for (fdc = 0; fdc < 2; fdc++)
  if ((&fdc_state[fdc])->address != -1)
   outb_p((&fdc_state[fdc])->dor,(2 + fdc_state[fdc].address ));




 fdc = 0;
 irqdma_allocated = 1;
 return 0;
cleanup2:
 __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 2), (4));
cleanup1:
 free_irq(FLOPPY_IRQ, ((void *)0));
 fd_routine[can_use_virtual_dma & 1]._free_dma(FLOPPY_DMA);
 while (--fdc >= 0) {
  __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 2), (4));
  __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 7), (1));
 }
 flags = _spin_lock_irqsave(&floppy_usage_lock);
 usage_count--;
 _spin_unlock_irqrestore(&floppy_usage_lock, flags);
 return -1;
}

static void floppy_release_irq_and_dma(void)
{
 int old_fdc;


 int drive;


 long tmpsize;
 unsigned long tmpaddr;
 unsigned long flags;

 flags = _spin_lock_irqsave(&floppy_usage_lock);
 if (--usage_count) {
  _spin_unlock_irqrestore(&floppy_usage_lock, flags);
  return;
 }
 _spin_unlock_irqrestore(&floppy_usage_lock, flags);
 if (irqdma_allocated) {
  fd_disable_dma();
  fd_routine[can_use_virtual_dma & 1]._free_dma(FLOPPY_DMA);
  free_irq(FLOPPY_IRQ, ((void *)0));
  irqdma_allocated = 0;
 }
 set_dor(0, ~0, 8);

 set_dor(1, ~8, 0);

 floppy_enable_hlt();

 if (floppy_track_buffer && max_buffer_sectors) {
  tmpsize = max_buffer_sectors * 1024;
  tmpaddr = (unsigned long)floppy_track_buffer;
  floppy_track_buffer = ((void *)0);
  max_buffer_sectors = 0;
  buffer_min = buffer_max = -1;
  _fd_dma_mem_free(tmpaddr, tmpsize);
 }


 for (drive = 0; drive < 2 * 4; drive++)
  if (timer_pending(motor_off_timer + drive))
   printk("motor off timer %d still active\n", drive);


 if (timer_pending(&fd_timeout))
  printk("floppy timer still active:%s\n", timeout_message);
 if (timer_pending(&fd_timer))
  printk("auxiliary floppy timer still active\n");
 if ((__builtin_constant_p(0) ? constant_test_bit((0),(((unsigned long *)(&(&floppy_work)->data)))) : variable_test_bit((0),(((unsigned long *)(&(&floppy_work)->data))))))
  printk("work still pending\n");

 old_fdc = fdc;
 for (fdc = 0; fdc < 2; fdc++)
  if ((&fdc_state[fdc])->address != -1) {
   __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 2), (4));
   __release_region(&ioport_resource, ((&fdc_state[fdc])->address + 7), (1));
  }
 fdc = old_fdc;
}



static char *floppy;

static void __attribute__ ((__section__ (".init.text"))) parse_floppy_cfg_string(char *cfg)
{
 char *ptr;

 while (*cfg) {
  for (ptr = cfg; *cfg && *cfg != ' ' && *cfg != '\t'; cfg++) ;
  if (*cfg) {
   *cfg = '\0';
   cfg++;
  }
  if (*ptr)
   floppy_setup(ptr);
 }
}

int __attribute__ ((__section__ (".init.text"))) init_module(void)
{
 if (floppy)
  parse_floppy_cfg_string(floppy);
 return floppy_init();
}

void cleanup_module(void)
{
 int drive;

 init_completion(&device_release);
 blk_unregister_region((((2) << 20) | (0)), 256);
 unregister_blkdev(2, "fd");

 for (drive = 0; drive < 8; drive++) {
  del_timer_sync(&motor_off_timer[drive]);

  if ((allowed_drive_mask & (1 << drive)) &&
      fdc_state[(((drive) & 0x04) >> 2)].version != 0x00) {
   del_gendisk(disks[drive]);
   device_remove_file(&floppy_device[drive].dev, &dev_attr_cmos);
   platform_device_unregister(&floppy_device[drive]);
  }
  put_disk(disks[drive]);
 }

 del_timer_sync(&fd_timeout);
 del_timer_sync(&fd_timer);
 blk_cleanup_queue(floppy_queue);

 if (usage_count)
  floppy_release_irq_and_dma();


 fd_eject(0);

 wait_for_completion(&device_release);
}

static inline __attribute__((always_inline)) char * *__check_floppy(void) { return(&(floppy)); }; static int __param_perm_check_floppy __attribute__((unused)) = (sizeof(char[1 - 2 * !!((0) < 0 || (0) > 0777 || ((0) & 2))]) - 1); static char __param_str_floppy[] = "floppy"; static struct kernel_param const __param_floppy __attribute__((__used__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_floppy, 0, param_set_charp, param_get_charp, &floppy }; static const char __mod_floppytype4577[] __attribute__((__used__)) __attribute__((section(".modinfo"),unused)) = "parmtype" "=" "floppy" ":" "charp";
static inline __attribute__((always_inline)) int *__check_FLOPPY_IRQ(void) { return(&(FLOPPY_IRQ)); }; static int __param_perm_check_FLOPPY_IRQ __attribute__((unused)) = (sizeof(char[1 - 2 * !!((0) < 0 || (0) > 0777 || ((0) & 2))]) - 1); static char __param_str_FLOPPY_IRQ[] = "FLOPPY_IRQ"; static struct kernel_param const __param_FLOPPY_IRQ __attribute__((__used__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_FLOPPY_IRQ, 0, param_set_int, param_get_int, &FLOPPY_IRQ }; static const char __mod_FLOPPY_IRQtype4578[] __attribute__((__used__)) __attribute__((section(".modinfo"),unused)) = "parmtype" "=" "FLOPPY_IRQ" ":" "int";
static inline __attribute__((always_inline)) int *__check_FLOPPY_DMA(void) { return(&(FLOPPY_DMA)); }; static int __param_perm_check_FLOPPY_DMA __attribute__((unused)) = (sizeof(char[1 - 2 * !!((0) < 0 || (0) > 0777 || ((0) & 2))]) - 1); static char __param_str_FLOPPY_DMA[] = "FLOPPY_DMA"; static struct kernel_param const __param_FLOPPY_DMA __attribute__((__used__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_FLOPPY_DMA, 0, param_set_int, param_get_int, &FLOPPY_DMA }; static const char __mod_FLOPPY_DMAtype4579[] __attribute__((__used__)) __attribute__((section(".modinfo"),unused)) = "parmtype" "=" "FLOPPY_DMA" ":" "int";
static const char __mod_author4580[] __attribute__((__used__)) __attribute__((section(".modinfo"),unused)) = "author" "=" "Alain L. Knaff";
;
static const char __mod_license4582[] __attribute__((__used__)) __attribute__((section(".modinfo"),unused)) = "license" "=" "GPL";







static const char __mod_alias4590[] __attribute__((__used__)) __attribute__((section(".modinfo"),unused)) = "alias" "=" "block-major-" "2" "-*";
