/* was in include/linux/compiler.h */

//note: xos asplos paper explains a little bit sparse

//#ifdef __CHECKER__
# define __user		__attribute__((noderef, address_space(1)))
# define __kernel	/* default address space */
# define __iomem	__attribute__((noderef, address_space(2)))

# define __safe		__attribute__((safe))
# define __force	__attribute__((force))
# define __nocast	__attribute__((nocast))

# define __acquires(x)	__attribute__((context(x,0,1)))
# define __releases(x)	__attribute__((context(x,1,0)))
# define __acquire(x)	__context__(x,1)
# define __release(x)	__context__(x,-1)
# define __cond_lock(x,c)	((c) ? ({ __acquire(x); 1; }) : 0)
extern void __chk_user_ptr(const volatile void __user *);
extern void __chk_io_ptr(const volatile void __iomem *);

//pad: bitwise ??

//#else
//# define __user
//# define __kernel
//# define __safe
//# define __force
//# define __nocast
//# define __iomem
//# define __chk_user_ptr(x) (void)0
//# define __chk_io_ptr(x) (void)0
//# define __builtin_warning(x, y...) (1)
//# define __acquires(x)
//# define __releases(x)
//# define __acquire(x) (void)0
//# define __release(x) (void)0
//# define __cond_lock(x,c) (c)
//#endif


/* was in sparse/ident-list.h */


// #define IDENT(n) __IDENT(n## _ident, #n, 0)
// #define IDENT_RESERVED(n) __IDENT(n## _ident, #n, 1)
// 
// /* Basic C reserved words.. */
// IDENT_RESERVED(sizeof);
// IDENT_RESERVED(if);
// IDENT_RESERVED(else);
// IDENT_RESERVED(return);
// IDENT_RESERVED(switch);
// IDENT_RESERVED(case);
// IDENT_RESERVED(default);
// IDENT_RESERVED(break);
// IDENT_RESERVED(continue);
// IDENT_RESERVED(for);
// IDENT_RESERVED(while);
// IDENT_RESERVED(do);
// IDENT_RESERVED(goto);





// /* C typenames. They get marked as reserved when initialized */
// IDENT(struct);
// IDENT(union);
// IDENT(enum);

//!!!!!
// IDENT(__attribute); IDENT(__attribute__);


// IDENT(volatile); IDENT(__volatile); IDENT(__volatile__);
// 
// /* Extended gcc identifiers */
// IDENT(asm); IDENT_RESERVED(__asm); IDENT_RESERVED(__asm__);
// IDENT(alignof); IDENT_RESERVED(__alignof); IDENT_RESERVED(__alignof__); 
// IDENT_RESERVED(__sizeof_ptr__);
// IDENT_RESERVED(__builtin_types_compatible_p);
// IDENT_RESERVED(__builtin_offsetof);
// 


//!!!!!!
// /* Attribute names */
// IDENT(packed); IDENT(__packed__);
// IDENT(aligned); IDENT(__aligned__);
// IDENT(nocast);
// IDENT(noderef);
// IDENT(safe);
// IDENT(force);


// IDENT(address_space);


//!!!!!!
// IDENT(context);


// IDENT(mode); IDENT(__mode__);
// IDENT(QI); IDENT(__QI__);
// IDENT(HI); IDENT(__HI__);
// IDENT(SI); IDENT(__SI__);
// IDENT(DI); IDENT(__DI__);
// IDENT(word); IDENT(__word__);
// IDENT(format); IDENT(__format__);
// IDENT(section); IDENT(__section__);
//!!!!!!
// IDENT(unused); IDENT(__unused__);
// IDENT(const); IDENT(__const); IDENT(__const__);
// IDENT(used); IDENT(__used__);
// IDENT(warn_unused_result); IDENT(__warn_unused_result__);
// IDENT(noinline); IDENT(__noinline__);
// IDENT(deprecated); IDENT(__deprecated__);
// IDENT(noreturn); IDENT(__noreturn__);
// IDENT(regparm); IDENT(__regparm__);
// IDENT(weak); IDENT(__weak__);
// IDENT(no_instrument_function); IDENT(__no_instrument_function__);
// IDENT(sentinel); IDENT(__sentinel__);
// IDENT(alias); IDENT(__alias__);
// IDENT(pure); IDENT(__pure__);
// IDENT(always_inline); IDENT(__always_inline__);
// IDENT(syscall_linkage); IDENT(__syscall_linkage__);
// IDENT(visibility); IDENT(__visibility__);
// IDENT(bitwise); IDENT(__bitwise__);
// IDENT(model); IDENT(__model__);
// IDENT(format_arg); IDENT(__format_arg__);
// IDENT(nothrow); IDENT(__nothrow); IDENT(__nothrow__);
// IDENT(__transparent_union__);
// IDENT(malloc);
// IDENT(__malloc__);
// IDENT(nonnull); IDENT(__nonnull); IDENT(__nonnull__);

// IDENT(constructor); IDENT(__constructor__);
// IDENT(destructor); IDENT(__destructor__);
// IDENT(cdecl); IDENT(__cdecl__);
// IDENT(stdcall); IDENT(__stdcall__);
// IDENT(fastcall); IDENT(__fastcall__);
// IDENT(dllimport); IDENT(__dllimport__);
// IDENT(dllexport); IDENT(__dllexport__);




// 
// /* Preprocessor idents.  Direct use of __IDENT avoids mentioning the keyword
//  * itself by name, preventing these tokens from expanding when compiling
//  * sparse. */
// IDENT(defined);
// __IDENT(pragma_ident, "__pragma__", 0);
// __IDENT(__VA_ARGS___ident, "__VA_ARGS__", 0);
// __IDENT(__LINE___ident, "__LINE__", 0);
// __IDENT(__FILE___ident, "__FILE__", 0);
// __IDENT(__DATE___ident, "__DATE__", 0);
// __IDENT(__TIME___ident, "__TIME__", 0);
// __IDENT(__func___ident, "__func__", 0);
// __IDENT(__FUNCTION___ident, "__FUNCTION__", 0);
// __IDENT(__PRETTY_FUNCTION___ident, "__PRETTY_FUNCTION__", 0);
// 




//!!!!!!
//!!!!!!
//!!!!!!
//!!!!!!
// /* Sparse commands */
// IDENT_RESERVED(__context__);
// IDENT_RESERVED(__range__);
// 
//!!!!!!
//!!!!!!
// /* Magic function names we recognize */
// IDENT(memset); IDENT(memcpy);
// IDENT(copy_to_user); IDENT(copy_from_user);
// IDENT(main);




// 
// #undef __IDENT
// #undef IDENT
// #undef IDENT_RESERVED
