#define INLINE extern __inline__


/* For use as a GCC soft-float library we need some special function names. */

#ifdef __LIBFLOAT__

/* Some 32-bit ops can be mapped straight across by just changing the name. */
#define float32_add			__addsf3
#define float32_sub			__subsf3
#define float32_mul			__mulsf3
#define float32_div			__divsf3
#define int32_to_float32		__floatsisf

#endif

void main(int i)
{
}
