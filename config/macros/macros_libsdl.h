// time: 
//  start 13h08: 86%
//        13h28: 95.19%
//        13h36: 95.23%
/* main pbs: CARD16 
 *    vector extension
 */


//bad: typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC) (const GLshort *v);
//BAD:!!!!! typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
#define APIENTRYP *



//bad: static int SDLCALL
//BAD:!!!!! win32_file_open(SDL_RWops * context, const char *filename, const char *mode)
#define SDLCALL

//BAD:!!!!! __declspec(naked)
#define __declspec(a) 

//BAD:!!!!!     static void *SDL_OSX_dlsym(void *dl_restrict handle,
#define dl_restrict



//bad: int WINAPI
//BAD:!!!!! WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR szCmdLine, int sw)
#define WINAPI

#define CALLBACK

#define FAR
#define NEAR


//bad: DECLSPEC Uint32 SDLCALL
//BAD:!!!!! SDL_GetTicks(void)
#define DECLSPEC

//BAD:!!!!!     SDL_logical_joydecl(SDL_Joystick * logicaljoy = NULL);
#define SDL_logical_joydecl(x) x



#define _AuConst const

//bad: /* for quicksort */
//BAD:!!!!! static int compare(_Xconst void *, _Xconst void *);
#define _Xconst const 


#define __BEGIN_DECLS
#define __END_DECLS

//bad: static LONG APIENTRY
//BAD:!!!!! DARTEventFunc(ULONG ulStatus, PMCI_MIX_BUFFER pBuffer, ULONG ulFlags)
#define APIENTRY


//BAD:!!!!! SDL_NAME(XF86VidModeModeInfo) * modeline;
#define SDL_NAME(a) a



//bad: typedef struct BMPINFO
//bad: {
//BAD:!!!!!     BITMAPINFO;
//bad:     RGB clr;
//bad: } BMPINFO, *PBMPINFO;
#define BITMAPINFO

//bad: static MRESULT EXPENTRY
//BAD:!!!!! WndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
#define EXPENTRY

//BAD:!!!!! typedef void (__cdecl * pfnSDL_CurrentEndThread) (unsigned code);
#define __cdecl


//bad: static unsigned __stdcall
//bad: RunThread(void *data)
//BAD:!!!!! {
#define __stdcall

//bad: unsigned _System
//bad: LibMain(unsigned hmod, unsigned termination)
#define _System


//BAD:!!!!! GL_API void GL_APIENTRY glAlphaFunc (GLenum func, GLclampf ref);
#define GL_API 
#define GL_APIENTRY

//bad: GLAPI void APIENTRY glBlendEquation (GLenum);
#define GLAPI


//BAD:!!!!! extern C_LINKAGE int SDL_main(int argc, char *argv[]);
#define C_LINKAGE

//BAD:!!!!! SDL_COMPILE_TIME_ASSERT(enum, sizeof(SDL_DUMMY_ENUM) == sizeof(int));

//BAD:!!!!! SDL_PROC_UNUSED(void, glAlphaFunc, (GLenum func, GLclampf ref))


//BAD:!!!!! _XFUNCPROTOBEGIN Bool SDL_NAME(XF86VidModeQueryVersion) (Display * /* dpy */ ,

//BAD:!!!!! SDL_X11_SYM(XClassHint*,XAllocClassHint,(void),(),return)


/*
bad: extern "C"
bad: {
bad: 
BAD:!!!!! #include "SDL_joystick.h"


BAD:!!!!!     _asm {
bad:         push edx
bad:         push eax

bad: typedef struct IOHIDDeviceInterface121
bad: {
BAD:!!!!!     IUNKNOWN_C_GUTS;
bad:     IOHIDDEVICEINTERFACE_FUNCS_100;
bad:     IOHIDDEVICEINTERFACE_FUNCS_121;
bad: } IOHIDDeviceInterface121;

BAD:!!!!! @interface Cocoa_WindowListener:NSResponder {
bad:     SDL_WindowData *_data;
bad: }

bad: typedef struct _XDGAOpenFramebuffer
bad: {
bad:     CARD8 reqType;
bad:     CARD8 dgaReqType;
BAD:!!!!!     CARD16 length B16;
bad:     CARD32 screen B32;
bad: } xXDGAOpenFramebufferReq;


BAD:!!!!! static vector unsigned char
bad: calc_swizzle32(const SDL_PixelFormat * srcfmt, const SDL_PixelFormat * dstfmt)
bad: {


BAD:!!!!!     vector unsigned char valpha = vec_splat_u8(0);
bad:     vector unsigned char vpermute = calc_swizzle32(srcfmt, NULL);

BAD:!!!!! SDL_PROC_UNUSED(void, glAlphaFunc, (GLenum func, GLclampf ref))
bad: SDL_PROC(void, glClearColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha))

bad: SDL_PROC_UNUSED(GLboolean, glAreTexturesResident,
BAD:!!!!!                 (GLsizei, const GLuint *, GLboolean *))

BAD:!!!!!     __try {
bad:         if (lInitialCount > lMaximumCount || lMaximumCount < 0
bad:             || lInitialCount < 0) {

BAD:!!!!! typedef unsigned long (__watcall * pfnSDL_CurrentBeginThread) (void *,
bad:                                                                unsigned,


BAD:!!!!! #import <Cocoa/Cocoa.h>
bad: #import "SDL.h"

bad:     case (SDL_INIT_VIDEO | SDL_INIT_AUDIO):
BAD:!!!!!         return VIDEO_USAGE " " AUDIO_USAGE;
bad:     default:

BAD:!!!!! typedef signed __int8 int8_t;
ERROR-RECOV: found sync col 0 at line 35


*/
