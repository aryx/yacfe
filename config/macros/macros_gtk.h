// time: start 
//   22h03  95%? 
//   22h17  98%
//   -
//   22h28

//BAD:!!!!!   g_assert_cmpint (normal, ==, 1);
#define g_assert_cmpint(a, op, b) assert(a op b)
//
//
//BAD:!!!!! G_CONST_RETURN gchar*
//bad: gtk_progress_bar_get_text (GtkProgressBar *pbar)
//bad: {
#define G_CONST_RETURN const 
//
//bad: G_BEGIN_DECLS
#define G_BEGIN_DECLS

//bad: G_END_DECLS
#define G_END_DECLS

//
//BAD:!!!!! GType              _gtk_file_chooser_entry_get_type (void) G_GNUC_CONST;
//#define G_GNUC_CONST const
//pad: only c++ extension
#define G_GNUC_CONST 

//bad: static HRESULT STDMETHODCALLTYPE
//BAD:!!!!! iprintdialogcallback_queryinterface (IPrintDialogCallback *This,
#define STDMETHODCALLTYPE

//
//BAD:!!!!! MODULE_ENTRY (fill_info) (GdkPixbufFormat *info)
//bad: {
#define MODULE_ENTRY(a) int a

//BAD:!!!!! #define MODULE_ENTRY(function) G_MODULE_EXPORT void function
//BAD:!!!!! G_MODULE_EXPORT GtkRcStyle *
//bad: theme_create_rc_style (void)
//bad: {
//bad:   return g_object_new (MSW_TYPE_RC_STYLE, NULL);
//bad: }
#define G_MODULE_EXPORT 

//
//BAD:!!!!! G_GNUC_INTERNAL ThemePixbuf *theme_pixbuf_new          (void);
#define G_GNUC_INTERNAL

//BAD:!!!!!   if (!API_CALL (EmptyClipboard, ()))
//
//BAD:!!!!!       API_CALL (CloseClipboard, ());
#define API_CALL(a,b) a b


//BAD:!!!!! 						     ...) G_GNUC_NULL_TERMINATED;
#define G_GNUC_NULL_TERMINATED
//
//
//BAD:!!!!!                                         ...) G_GNUC_PRINTF (5, 6);
#define G_GNUC_PRINTF(a,b)
//
//bad: static LRESULT CALLBACK
//BAD:!!!!! gtk_win32_embed_widget_window_process (HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
#define CALLBACK
//
//bad: UINT_PTR CALLBACK
//BAD:!!!!! run_mainloop_hook (HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam)

//BAD:!!!!! WINUSERAPI HWND WINAPI GetAncestor(HWND,UINT);
//bad: BOOL WINAPI
//BAD:!!!!! DllMain (HINSTANCE hinstDLL,
#define WINUSERAPI 
#define WINAPI




//bad: #define CHECK_IN_BUFFER_RETURN(anchor, val)                             \
//BAD:!!!!!   G_STMT_START {                                                        \
//bad:     if ((anchor)->segment == NULL)                                      \
//bad:       {                                                                 \
//bad:         g_warning ("%s: GtkTextChildAnchor hasn't been in a buffer yet",\
//bad:                    G_STRFUNC);                                          \
//bad:         return (val);                                                   \
//bad:       }                                                                 \
//bad:   } G_STMT_END
#define G_STMT_START do
#define G_STMT_END while(0)


//BAD:!!!!! GTKMAIN_C_VAR const guint gtk_major_version;
#define GTKMAIN_C_VAR 

//
//bad:   gint             GSEAL (num_children);
//BAD:!!!!!   GList           *GSEAL (children);
#define GSEAL(a) a 

//BAD:!!!!! uncompress (unsigned size, INOUT guchar ** source, OUT guchar * target, INOUT gsize * _remaining)
#define IN
#define OUT
#define INOUT


////pad: objective C
//bad:   GDK_QUARTZ_ALLOC_POOL;
//BAD:!!!!!   array = [NSScreen screens];
//

//bad: G_DEFINE_TYPE_WITH_CODE (GtkTreeModelFilter, gtk_tree_model_filter, G_TYPE_OBJECT,
//bad: 			 G_IMPLEMENT_INTERFACE (GTK_TYPE_TREE_MODEL,
//bad: 						gtk_tree_model_filter_tree_model_init)
//BAD:!!!!! 			 G_IMPLEMENT_INTERFACE (GTK_TYPE_TREE_DRAG_SOURCE,
//bad: 						gtk_tree_model_filter_drag_source_init))
//
//
//
//bad: DECLARE_INTERFACE_ (IPrintDialogCallback, IUnknown)
//BAD:!!!!! {
//bad:     STDMETHOD (QueryInterface)(THIS_ REFIID,LPVOID*) PURE;

//
//bad:   COMPARE_DIRECTORIES;
//BAD:!!!!!   else
//
//BAD:!!!!! G_DEFINE_TYPE_WITH_CODE (GtkFileChooserButton, gtk_file_chooser_button, GTK_TYPE_HBOX, { \
//bad:     G_IMPLEMENT_INTERFACE (GTK_TYPE_FILE_CHOOSER, gtk_file_chooser_button_file_chooser_iface_init) \
//


/*


*/

