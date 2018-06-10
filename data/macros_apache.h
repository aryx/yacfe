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
