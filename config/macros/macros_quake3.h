//bad: typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC) (const GLdouble *v);
#define APIENTRYP

//BAD:!!!!! static int QDECL ArenaServers_Compare( const void *arg1, const void *arg2 ) {
#define QDECL


//PB: FALSE positive:


//BAD:!!!!! GLOBAL void
//bad: jpeg_make_c_derived_tbl (j_compress_ptr cinfo, JHUFF_TBL * htbl,
//bad: 			 c_derived_tbl ** pdtbl)
//bad: {
#define GLOBAL

//bad: LOCAL boolean
//BAD:!!!!! dump_buffer (working_state * state)
//bad: /* Empty the output buffer; return TRUE if successful, FALSE if must suspend */
#define LOCAL
//but FP in lcc:
//BAD:!!!!! 	assert(level >= LOCAL);

//bad: METHODDEF boolean
//BAD:!!!!! encode_mcu_huff (j_compress_ptr cinfo, JBLOCKROW *MCU_data)
//bad: {
#define METHODDEF




//BAD:!!!!! static ID_INLINE void WRITE_2BYTES( int x )
#define ID_INLINE

//bad: INLINE
//bad: LOCAL boolean
//BAD:!!!!! emit_bits (working_state * state, unsigned int code, int size)
//#define INLINE

//BAD:!!!!! extern DECLSPEC void SDLCALL SDL_SetError(const char *fmt, ...);
#define DECLSPEC
#define SDLCALL

//BAD:!!!!! typedef unsigned long (__cdecl *pfnSDL_CurrentBeginThread) (void *, unsigned,
#define __cdecl



#define GLAPI

#define APIENTRY





//BAD:!!!!! extern C_LINKAGE int SDL_main(int argc, char *argv[]);
#define C_LINKAGE


//jpeg
//BAD:!!!!! extern void * malloc JPP((size_t size));

#define JPP(a) a

//BAD:!!!!! GLOBAL void FAR *
//bad: jpeg_get_large (j_common_ptr cinfo, size_t sizeofobject)
#define FAR

#define far


//BAD:!!!!! METHODDEF boolean encode_mcu_huff JPP((j_compress_ptr cinfo,
//bad: 				       JBLOCKROW *MCU_data));
//#define JBLOCKROW


//BAD:!!!!! EXTERN void jpeg_make_c_derived_tbl JPP((j_compress_ptr cinfo,
//bad: 				JHUFF_TBL * htbl, c_derived_tbl ** pdtbl));
#define EXTERN


//BAD:!!!!! typedef JMETHOD(void, float_DCT_method_ptr, (FAST_FLOAT * data));
//BAD:!!!!!   JMETHOD(void, start_pass, (j_compress_ptr cinfo));
#define JMETHOD(a, b, args) a (* b) args

//#define JMETHOD(type,methodname,arglist)  type (*methodname) arglist



//bad: struct jpeg_decompress_struct {
//BAD:!!!!!   jpeg_common_fields;		/* Fields shared with jpeg_compress_struct */
#define jpeg_common_fields


//unzip
//BAD:!!!!! static int huft_build OF((
//bad:     uInt *,				/* code lengths in bits */
#define OF(a) a

//BAD:!!!!! typedef void           (ALAPIENTRY *LPALGETBUFFERIV)( ALuint bid, ALenum param, ALint* values );
#define ALAPIENTRY

//bad: typedef void           (ALCAPIENTRY *LPALCCAPTURESTART)( ALCdevice *device );
#define ALCAPIENTRY

//BAD:!!!!! ALUTAPI void ALUTAPIENTRY alutInit(int *argc, char *argv[]);
#define ALUTAPI


//BAD:!!!!! ALCAPI ALCcontext *    ALCAPIENTRY alcCreateContext( ALCdevice *device, const ALCint* attrlist );
#define ALCAPI

//BAD:!!!!! ALAPI void ALAPIENTRY alEnable( ALenum capability );
#define ALAPI

//BAD:!!!!! CURL_EXTERN CURLM *curl_multi_init(void);
//BAD:!!!!! CURL_EXTERN CURL *curl_easy_init(void);
#define CURL_EXTERN


//bad: typedef enum {
//bad:   /* This is the socket callback function pointer */
//BAD:!!!!!   CINIT(SOCKETFUNCTION, FUNCTIONPOINT, 1),
//bad:
//bad:   /* This is the argument passed to the socket callback */
//bad:   CINIT(SOCKETDATA, OBJECTPOINT, 2),
//bad:
//bad:   CURLMOPT_LASTENTRY /* the last unused */
//bad: } CURLMoption;
