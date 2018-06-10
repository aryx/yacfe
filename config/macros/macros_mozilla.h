// time 
//  start 




// ****************************************************************************
// firefox battery
// ****************************************************************************

//#include <macros_sqlite.h>
#define SQLITE_EXTERN extern
#define SQLITE_PRIVATE
#define SQLITE_API

//#include <macros_jpeg.h>
#define jpeg_common_fields
// conflict with minix 
#define EXTERN(a) a
#define JPP(x) x

//#include <macros_hacc.h> 
#define YY_PROTO(x) x 
#define yyconst const 


//#include <macros_windows.h>

//BAD:!!!!! MOZCE_SHUNT_API int WINAPI SetMapMode(HDC, int)
#define WINAPI
#define CALLBACK
#define FAR
#define NEAR

//BAD:!!!!! PVOID APIENTRY WinQueryProperty(HWND hwnd, PCSZ  pszNameOrAtom);
//BAD:!!!!! BOOL APIENTRY DllMain(  HINSTANCE hModule, 
#define APIENTRY




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

//BAD:!!!!! local int do_flush (file, flush)
#define local static
#define vector

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
//bad: NS_METHOD_(void*)
#define NS_METHOD_(a) a 

// cast function syntax
//#define PRUnichar(x) (char)(x)
//#define PRInt32(x) (char)(x)


#define NS_IF_ADDREF(e) e


#define DECL_DHASH_WRAPPER(a,b,c)

//BAD:!!!!!     NS_STDCALL_FUNCPROTO(nsresult,
//bad:                          getter,
//bad:                          nsIWindowsHooksSettings, GetShowDialog, 
//bad:                          (PRBool*));
#define NS_STDCALL_FUNCPROTO(a,b,c,d,e) a b

#define NS_HTML_CONTENT_INTERFACE_MAP_BEGIN(a,b)
#define NS_HTML_CONTENT_INTERFACE_MAP_END

//#define MOZCE_SHUNT_API static
#define MOZCE_SHUNT_API


//but normally should be detected by the heuristic on macro noptvirg
#define MOZCE_PRECHECK

#define CONST const

//BAD:!!!!! typedef void    (LDAP_C LDAP_CALLBACK LDAP_TF_SET_LDERRNO_CALLBACK)( int err,
#define LDAP_CALLBACK
#define LDAP_C
#define LDAP_API(a) a
#define LDAP_CALL


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
#define __stdcall
#define __declspec(x) 



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

//BAD:!!!!!     IMPLEMENT_METHOD_FAMILY(CallObjectMethod, jobject, l)


//BAD:!!!!! extern "C" NS_VISIBILITY_DEFAULT nsresult JSJ_RegisterLiveConnectFactory(void);
#define NS_VISIBILITY_DEFAULT


//bad: JNI_OJIAPITest(JNIEnv_GetMethodID_5)
//bad: {
//bad:   GET_JNI_FOR_TEST
#define GET_JNI_FOR_TEST


//BAD:!!!!! CPluginManager::Alloc(PRUint32 size)

//BAD:!!!!! DEFINE_API_C(int) main(NPNetscapeFuncs* nsTable, NPPluginFuncs* pluginFuncs, NPP_ShutdownUPP* unloadUpp)
#define DEFINE_API_C(a) a 

//BAD:!!!!!     extern NS_IMPORT_(char **) environ; 
#define NS_IMPORT_(a) a 


//BAD:!!!!!   NS_ADDREF(*aResult = lf);
#define NS_ADDREF(a) a 

//bad: #ifdef NEVER_ENABLE_THIS_JAVASCRIPT
//
//bad: class PyG_nsIComponentLoader : public PyG_Base, public nsIComponentLoader
//bad: {
//bad: public:
//bad: 	PyG_nsIComponentLoader(PyObject *instance) : PyG_Base(instance, NS_GET_IID(nsIComponentLoader)) {;}
//BAD:!!!!! 	PYGATEWAY_BASE_SUPPORT(nsIComponentLoader, PyG_Base);
//bad: 
//bad: 	NS_DECL_NSICOMPONENTLOADER
//bad: };


//BAD:!!!!! 	PyObject_HEAD_INIT(&PyType_Type)
//bad: 	0,
#define PyObject_HEAD_INIT(a) a, 

//bad: 			if ((val_use=PyNumber_Int(val))==NULL) BREAK_FALSE
#define BREAK_FALSE

//BAD:!!!!! DHASH_WRAPPER(txKeyValueHash, txKeyValueHashEntry, txKeyValueHashKey&)
//bad: DHASH_WRAPPER(txIndexedKeyHash, txIndexedKeyHashEntry, txIndexedKeyHashKey&)

//BAD:!!!!! DHASH_SET(nsStringHashSet, PLDHashStringEntry, nsAString&)

//
//
//BAD:!!!!!     NS_XTF_ELEMENT_FACTORY_CONTRACTID_PREFIX NS_NAMESPACE_XFORMS,
//
//BAD:!!!!!     TRACE_METHOD(CControlSite::CControlSite);
#define TRACE_METHOD(a) a()

//BAD:!!!!! lineto(nsFT_CONST FT_Vector *aEndPt, void *aClosure)
#define nsFT_CONST const 

//BAD:!!!!! pascal void CursorSpinner::SpinCursor(EventLoopTimerRef inTimer, void *inUserData)
#define pascal 

//BAD:!!!!! PRIVATE int binhex_encode_finishing(
//bad: 	binhex_encode_object *p_bh_encode_obj)
//bad: {
#define PRIVATE 

//BAD:!!!!! static int yy_flex_strlen YY_PROTO(( yyconst char * ));
//and co

//BAD:!!!!! extern gzFile EXPORT gzdopen  OF((int fd, const char *mode));
#define EXPORT


//BAD:!!!!! extern "C" XULAPI int
#define XULAPI 

//BAD:!!!!! extern "C" NS_EXPORT jboolean JNICALL
//bad: JAVAPROXY_NATIVE(isSameXPCOMObject) (JNIEnv *env, jclass that, jobject aProxy1,
#define JAVAPROXY_NATIVE(a) a

/*

*/
