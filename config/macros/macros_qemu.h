// time: 
//  start 11h32: 89% 
//        11h41: 95%
//        12h10: 96.60%

// QEMU_LIST_HEAD
// QEMU_LIST_ENTRY


//BAD:!!!!! void OPPROTO op_movl_imm_T0(void)
//bad: {
#define OPPROTO


//hmmm
//#define SFR_RW_MM_TLB_SEL  env->pregs[PR_SRS]][4



//BAD:!!!!! static always_inline int vaxf_is_valid (float ff)
//bad: {
#define always_inline 

//bad: DISAS_INSN(move_to_ccr)
//BAD:!!!!! {
#define DISAS_INSN(a) void a(void)

//BAD:!!!!! static int __thread mmap_lock_count;
#define __thread YACFE_ATTRIBUTE


//bad: GEN_HANDLER(fmr, 0x3F, 0x08, 0x02, 0x001F0000, PPC_FLOAT)
//BAD:!!!!! {
#define GEN_HANDLER(a, b, c, d, e, f) void a(void) 

//bad: GEN_HANDLER2(addic_, "addic.", 0x0D, 0xFF, 0xFF, 0x00000000, PPC_INTEGER)
//BAD:!!!!! {
#define GEN_HANDLER2(a, b, c, d, e, f, g, h) void a(void) 

//bad: void HELPER(cpsr_write)(uint32_t val, uint32_t mask)
//bad: {
#define HELPER(a) a



//BAD:!!!!! static void GCC_ATTR ldebug (const char *fmt, ...)
#define GCC_ATTR YACFE_ATTRIBUTE

//BAD:!!!!! static void GCC_FMT_ATTR (2, 3) oss_logerr (int err, const char *fmt, ...)
#define GCC_FMT_ATTR(a,b) 








//BAD:!!!!! int show_x _P((char *, struct socket *));
#define _P(a) a

//BAD:!!!!! float32 int64_to_float32( int64 a STATUS_PARAM )
//bad: {
#define STATUS_PARAM

//bad: IO_WRITE_PROTO (gus_writeb)
//BAD:!!!!! {
#define IO_WRITE_PROTO(a) void a(void)

//bad: static IO_READ_PROTO (dsp_read)
//BAD:!!!!! {
#define IO_READ_PROTO(a) void a(void)


//bad: F_HELPER(neg, q)
//BAD:!!!!! {
#define F_HELPER(a, b) void a(void)



//BAD:!!!!! extern int print_insn_d10v		PARAMS ((bfd_vma, disassemble_info*));
#define PARAMS(a) a

//BAD:!!!!! static inline int hppa_rebuild_insn (int, int, int) ATTRIBUTE_UNUSED;
#define ATTRIBUTE_UNUSED



//bad: void TCG_HELPER_PROTO helper_evaluate_flags_mulu(void);
//BAD:!!!!! void TCG_HELPER_PROTO helper_evaluate_flags_mcp(void);
#define TCG_HELPER_PROTO

//bad: void OPPROTO glue(op_store_T1_ir, REG) (void)
#define glue(a,b) a



//BAD:!!!!! void *glue(_test_, OP) __init_call = glue(test_, OP);
#define __init_call


//bad: void HELPER(divu)(CPUState *env, uint32_t word)
//bad: {




//BAD:!!!!!                               void *__unbounded msgp;
#define __unbounded

//BAD:!!!!! void __hidden cpu_loop_exit(void);
#define __hidden YACFE_ATTRIBUTE



//BAD:!!!!! static LIST_HEAD (capture_list_head, CaptureState) capture_head;

//BAD:!!!!! DEF_HELPER(void, do_raise_exception_err, (int excp, int err))
#define DEF_HELPER(a, b, c) a b c



//bad:     target_ulong tls_value; /* For usermode emulation */
//bad: 
//BAD:!!!!!     CPU_COMMON
//bad: 
#define CPU_COMMON

//bad: typedef struct CirrusVGAState {
//BAD:!!!!!     VGA_STATE_COMMON
//bad: 
//bad:     int cirrus_linear_io_addr;
#define VGA_STATE_COMMON


//bad: struct audio_driver alsa_audio_driver = {
//bad:     INIT_FIELD (name           = ) "alsa",
//bad:     INIT_FIELD (descr          = ) "ALSA http://www.alsa-project.org",
//BAD:!!!!!     INIT_FIELD (options        = ) alsa_options,
#define INIT_FIELD(a) . a

//-----------------------------------------------------------------------------
//BAD:!!!!!     LIST_ENTRY (CaptureState) entries;
#define LIST_ENTRY(a) a

//BAD:!!!!!     LIST_HEAD (sw_in_listhead, SWVoiceIn) sw_head;
#define LIST_HEAD(a,b) a

//bad: struct rndis_response {
//BAD:!!!!!     TAILQ_ENTRY(rndis_response) entries;
#define TAILQ_ENTRY(a) a

//BAD:!!!!!     TAILQ_HEAD(rndis_resp_head, rndis_response) rndis_resp;
#define TAILQ_HEAD(a,b) a



//-----------------------------------------------------------------------------

//BAD:!!!!!     return normalizeRoundAndPackFloat64( zSign, 0x43C, zSign ? - a : a STATUS_VAR );
#define STATUS_VAR






//BAD:!!!!! 	D(CPUState *env = opaque);
#define D(a) a


//BAD:!!!!! void CALLBACK host_alarm_handler(UINT uTimerID, UINT uMsg,
#define CALLBACK

#define WINAPI

