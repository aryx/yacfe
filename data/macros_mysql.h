// time start 22h18: 88.1%
// +20min + 15min
//  19h + 10min + 10min  91.94% (after also grammar extension)


//BAD:!!!!!   return new (thd->mem_root) Item_func_ln(arg1);


#define LINT_SET_PTR

#define TESTCASE(a,b) void test_foo()

#define TAOCRYPT_CDECL
#define TAOCRYPT_NAKED
#define TAOCRYPT_FASTCALL


#define UNIV_INLINE

//   STATIC_CONST( SignalLength = 2 );
//BAD:!!!!!   STATIC_CONST( InvalidId = ~(Uint32)0 );
//#define STATIC_CONST(a) a
#define STATIC_CONST(xassign) static const int xassign

#define CONST

#define __stdcall

#define IMPORT



#define ATTRIBUTE_FORMAT(a,b,c)


#define UT_LIST_BASE_NODE_T(a) a
#define UT_LIST_NODE_T(a) a

#define NEAR_F
#define STDCALL

//BAD:!!!!! bool __fastcall TForm1::connect_server()
#define __fastcall


//BAD:!!!!!     THREAD_RETURN YASSL_API echoserver_test(void*);
#define YASSL_API

//bad: C_MODE_START
//bad: C_MODE_END
#define C_MODE_START
#define C_MODE_END


#define WINAPI
#define CALLBACK
#define NEAR
#define FAR

//BAD:!!!!!   GCC_BUG_WORKAROUND int32 x,y;
#define GCC_BUG_WORKAROUND


//BAD:!!!!! extern int rl_backward_char PARAMS((int, int));
#define PARAMS(a) a

//BAD:!!!!! int ZEXPORT deflateInit2_(strm, level, method, windowBits, memLevel, strategy,
#define ZEXPORT

//BAD:!!!!! STATIC_INLINE uint my_count_bits(ulonglong v)
#define STATIC_INLINE

//BAD:!!!!! void __CDECL hfree(void *ptr)
#define __CDECL

//BAD:!!!!! static yyconst flex_int32_t yy_ec[256] =
#define yyconst const

//bad: 	YY_BREAK
//BAD:!!!!! case 83:
#define YY_BREAK break;


//BAD:!!!!!    "built-in default (" STRINGIFY_ARG(MYSQL_PORT) ").",
#define STRINGIFY_ARG(a) "stringified" 

//BAD:!!!!!   SECTION( ATTRIBUTE_LIST_SECTION = 0 );
#define SECTION(a) a


#define reg1 register
#define reg2 register
#define reg3 register
#define reg4 register
#define reg5 register

//BAD:!!!!!     buffer_ = NEW_YS byte[s];
//bad:     #define NEW_YS new (yaSSL::ys)
//#define NEW_YS
#define NEW_YS new

//bad:     return init_dynamic_array(&file_names, sizeof(File_name_record),
//BAD:!!!!! 			      100,100 CALLER_INFO);
#define CALLER_INFO

//BAD:!!!!! int sk_GENERAL_NAME_num(STACK_OF(GENERAL_NAME) *x)
#define STACK_OF(a) a

//pad: need constructed object at toplevel, so constant detection maybe
//  can help
//bad: MY_LOCALE my_locale_ru_UA
//bad: (
//BAD:!!!!!   44,
//#define MY_LOCALE 

//BAD:!!!!!       RT_D_MBR_KORR(int8, mi_sint1korr, 1, (double));
#define RT_D_MBR_KORR(a,b,c,d) int foo


//BAD:!!!!! void mi_check_print_info _VARARGS((MI_CHECK *param, const char *fmt,...));
//BAD:!!!!! extern int my_printf_error _VARARGS((uint my_err, const char *format,
#define _VARARGS(a) a

//BAD:!!!!! extern int ax_unreg __P((int, long));
#define __P(a) a 

//BAD:!!!!!   my_bool SV::*offset;
//
//BAD:!!!!!   String *val_str(String *) ZLIB_DEPENDED_FUNCTION
#define ZLIB_DEPENDED_FUNCTION 

//BAD:!!!!! STATIC int      regtry();
#define STATIC

//BAD:!!!!! extern void __cdecl _dosmaperr(unsigned long);
#define __cdecl 


//bad: static void MD5Transform PROTO_LIST ((UINT4 [4], unsigned char [64]));
//BAD:!!!!!        void my_MD5Init PROTO_LIST ((my_MD5_CTX *));
#define PROTO_LIST(a) a 


//BAD:!!!!! 	   void (*free_element)(void*),uint flags CALLER_INFO_PROTO)
#define CALLER_INFO_PROTO

//BAD:!!!!! int _export FAR PASCAL libmain(HANDLE hModule,short cbHeapSize,
#define _export
#define FAR
#define PASCAL 
//
//BAD:!!!!! BOOL APIENTRY LibMain(HANDLE hInst,DWORD ul_reason_being_called,
#define APIENTRY
//
//BAD:!!!!! SSL_STATIC my_bool opt_use_ssl  = 0;
#define SSL_STATIC 

//BAD:!!!!!   REGISTER struct link *old;
#define REGISTER
//
//BAD:!!!!! ZEXTERN const char * ZEXPORT zlibVersion OF((void));
#define ZEXTERN extern
#define ZEXTERN 

#define OF(a) a

//
//BAD:!!!!! local void bi_flush(s)
#define local 

//BAD:!!!!! int ZEXPORTVA gzprintf (file, format, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,
//bad:                        a11, a12, a13, a14, a15, a16, a17, a18, a19, a20)
#define ZEXPORTVA 


//bad: NDB_COMMAND(DbAsyncGenerator, "DbAsyncGenerator",
//bad: 	    "DbAsyncGenerator", "DbAsyncGenerator", 65535)
//BAD:!!!!! {
//bad:   ndb_init();
#define NDB_COMMAND(a, str, str2, str3, i1) int a(void) 



//
//BAD:!!!!! MgmApiSession::setTrace(Parser<MgmApiSession>::Context &,
//bad: 			Properties const &args) {
//
//BAD:!!!!!   SECTION( DICT_OBJ_INFO = 0 );
#define SECTION(a) a

//BAD:!!!!! {
//bad:   MYSQL_STORAGE_ENGINE_PLUGIN,
#define mysql_storage_engine_plugin(q) int a = 
//mysql_declare_plugin_end;

//bad: mysql_declare_plugin(blackhole)
#define mysql_declare_plugin(q) int a = 
#define mysql_declare_plugin_end


//bad: #ifdef _MSC_VER
//bad:     __declspec(naked) 
//bad: #endif
#define __declspec(a)

//BAD:!!!!!   IF_DBUG(uint tmp=) my_strnxfrm(field_charset,
//bad:                                  to, length,
//bad:                                  ptr, field_length);
//BAD:!!!!!     IF_DBUG(int error=)
#define IF_DBUG(a) a

/*

//pad: old C decl
static states
step(g, start, stop, bef, ch, aft)
register struct re_guts *g;
bad: register char *cp;
BAD:!!!!! {
bad: 	register char *p;
bad: 
bad: 	if (cs->multis == NULL)
bad: 		return(NULL);
bad: 	for (p = cs->multis; *p != '\0'; p += strlen(p) + 1)
bad: 		if (strcmp(cp, p) == 0)
bad: 			return(p);
bad: 	return(NULL);
bad: }

// = File "/home/pad/software-os-src/mysql/cmd-line-utils/libedit/history.c", line 125, column 8,  charpos = 4852
//BAD:!!!!! private int history_def_first(ptr_t, HistEvent *);
/



BAD:!!!!!         IF_DBUG(int res=) trans->restart();

*/
