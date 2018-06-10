/* lib/deputy/include/deputy/annots.h */

#ifndef ANNOT_H
#define ANNOT_H

#define DEPUTY          1

#define BOUND(lo, hi)   __attribute__((bounds((lo),(hi))))
#define COUNT(n)        BND(__this, __this + (n))
#define SIZE(n)         COUNT(n)
#define SAFE            COUNT(1)
#define SNT             COUNT(0) __attribute__((sentinel))

#define BND(lo, hi)     BOUND(lo, hi)
#define CT(n)           COUNT(n)
#define SZ(n)           SIZE(n)

#define EFAT            BND(__this, __auto)
#define FAT             BND(__auto, __auto)

#define NULLTERM        __attribute__((nullterm))
#define NT              NULLTERM
#define NTS             NULLTERM COUNT(0)
#define NTC(n)          NULLTERM COUNT(n-1)

#define NTDROPATTR      __attribute__((ntdrop))
#define NTEXPANDATTR    __attribute__((ntexpand))

#define NULLABLE
#define OPT             NULLABLE
#define NONNULL         __attribute__((nonnull))

#define TRUSTED         __attribute__((trusted))
#define TRUSTEDBLOCK    __blockattribute__((trusted))

#define POLY            TRUSTED

#define COPYTYPE        __attribute__((copytype))

//specifies that Deputy's typechecker (but not optimizer) should assume
//that this lvalue is constant. (unsound)
#define ASSUMECONST     __attribute__((assumeconst))

#define WHEN(e)         __attribute__((when(e)))

#define DMEMCPY(x, y, z) __attribute__((dmemcpy((x),(y),(z))))
#define DMEMSET(x, y, z) __attribute__((dmemset((x),(y),(z))))
#define DMEMCMP(x, y, z) __attribute__((dmemcmp((x),(y),(z))))

#define DALLOC(x)       __attribute__((dalloc(x)))
#define DREALLOC(x, y)  __attribute__((drealloc((x), (y))))
#define DFREE(x)        __attribute__((dfree(x)))

#define DVARARG(x)      __attribute__((dvararg(x)))
#define DPRINTF(x)      DVARARG(printf(x))

#define NTDROP(x)       ((void * COUNT(0) NTDROPATTR COPYTYPE)(x))
#define NTEXPAND(x)     ((void * COUNT(0) NTEXPANDATTR COPYTYPE)(x))

#define TC(x)           ((void * TRUSTED COPYTYPE)(x))

#define TVATTR(x)       __attribute__((tyvar(x)))
#define TPATTR(x)       __attribute__((typaram(sizeof(x))))

#define TV(x)           void * TVATTR(x)
#define TP(x)           TPATTR(x)

//Deputy will replace this with the number of checks that were inserted into
//the file.  Small regression tests use this to ensure that all checks that
//that should be optimized away actually are.  Since we regularly change the
//way checks are implemented, this is really only useful for small tests with
//few or no checks added.
extern const int DEPUTY_NUM_CHECKS_ADDED;

#endif // ANNOT_H
