//-->/home/pad/software-os-src/freebsd/contrib/opensolaris/uts/common/sys/feature_tests.h:362:

#error "Compiler or options invalid; UNIX 03 and POSIX.1-2001 applications \
	require the use of c99"
#endif

/*
 * The following macro defines a value for the ISO C99 restrict
 * keyword so that _RESTRICT_KYWD resolves to "restrict" if
 * an ISO C99 compiler is used and "" (null string) if any other
 * compiler is used. This allows for the use of single prototype
 * declarations regardless of compiler version.
 */
