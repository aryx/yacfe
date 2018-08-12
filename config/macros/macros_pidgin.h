//time: 1h I think

//bad: G_BEGIN_DECLS
//bad:
//bad: /**
//bad:  * @return The GType for GntWS.
//bad:  *
//bad:  * @since 2.0.0 (gnt), 2.1.0 (pidgin)
//bad:  */
//BAD:!!!!! GType gnt_ws_get_gtype(void);
//bad: G_END_DECLS

#define G_BEGIN_DECLS
#define G_END_DECLS


//bad: STATIC_PROTO_INIT
//bad:
//bad: gboolean
//BAD:!!!!! purple_core_init(const char *ui)
#define STATIC_PROTO_INIT


//BAD:!!!!! gboolean msim_send(struct _MsimSession *session, ...) SENTINEL_ATTR;
#define SENTINEL_ATTR

//bad: struct gg_session {
//BAD:!!!!! 	gg_common_head(struct gg_session)
//bad:
#define gg_common_head(a)

//BAD:!!!!! static void (DNSSD_API* _DNSServiceRefDeallocate)(DNSServiceRef sdRef);
#define DNSSD_API


//BAD:!!!!! Zconst char * ZGetRealm () { return __Zephyr_realm; }
#define Zconst const


//bad: START_TEST(test_md5_empty_string) {
//bad: 	MD5_TEST("", "d41d8cd98f00b204e9800998ecf8427e");
//bad: }
//bad: }
//bad: END_TEST
#define START_TEST(a) void a(void)

#define END_TEST


//-----------------------------------------------------------------------------

//BAD:!!!!! G_CONST_RETURN gchar *purple_gai_strerror(gint errnum);
#define G_CONST_RETURN

//BAD:!!!!! G_GNUC_NORETURN static void
//bad: resolve(int in, int out)
#define G_GNUC_NORETURN

//BAD:!!!!! static void lose(const char *fmt, ...) G_GNUC_NORETURN G_GNUC_PRINTF (1, 2);
#define G_GNUC_PRINTF(a,b)

//BAD:!!!!!                                            GValue       *return_value G_GNUC_UNUSED,
#define G_GNUC_UNUSED

//bad: void purple_account_set_status(PurpleAccount *account, const char *status_id,
//BAD:!!!!! 	gboolean active, ...) G_GNUC_NULL_TERMINATED;
#define G_GNUC_NULL_TERMINATED


//bad: static gboolean G_GNUC_CONST
//BAD:!!!!! standard_is_boolean (const char * key)
#define G_GNUC_CONST


//BAD:!!!!! int tcl_cmd_send_im(ClientData unused, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
#define CONST

//-----------------------------------------------------------------------------
//BAD:!!!!! BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
#define WINAPI

//bad: static unsigned __stdcall
//bad: select_thread (void *parameter)
#define __stdcall



//-----------------------------------------------------------------------------
//BAD:!!!!!     register int (*predicate) __P((ZNotice_t *, void *));
#define __P(a) a

//BAD:!!!!! int ZCompareALDPred ZP((ZNotice_t *notice, void *zald));
#define ZP(a) a

//BAD:!!!!! void com_err ETP((ETCONST char *, long, ETCONST char *, ...));
#define ETCONST const
#define ETP(a) a




//BAD:!!!!! DBUS_EXPORT void music_messaging_change_request (const int session, const char *command, const char *parameters);
#define DBUS_EXPORT

