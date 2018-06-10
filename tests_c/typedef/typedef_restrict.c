intmax_t
wcstoimax (const wchar_t *__restrict nptr, wchar_t **__restrict endptr,
	   int base)
{
  return __wcstol_internal (nptr, endptr, base, 0);
}

extern int __vfwprintf_chk (FILE *__restrict __s, int __flag,
			    const wchar_t *__restrict __format,
							__gnuc_va_list __arg);

extern double __wcstod_internal (__const wchar_t *__restrict __nptr,
								 wchar_t **__restrict __endptr, int __group);

