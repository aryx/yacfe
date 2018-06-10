open Common

(*****************************************************************************)
(* Flags *)
(*****************************************************************************)
let path_xpm = ref (Filename.concat Config.path "gui/xpms")

(*
let db_path = ref (Database_c.database_dir "/home/pad/linux")
*)

(*****************************************************************************)
(* The options *)
(*****************************************************************************)
let options = [ 

  "-path_xpm_pixmaps" , Arg.Set_string path_xpm, 
  " path to pixmaps icons files";
] 

(*****************************************************************************)
(* The actions *)
(*****************************************************************************)

(* update: try put ocamlgtk related test in widgets/test_widgets.ml, not
 * here. Here it's for ... well it's for nothing I think as it's not really
 * easy to test gui.
 *)

(*****************************************************************************)
(* The main entry point *)
(*****************************************************************************)
let main () = 
  let usage_msg = 
    ("Usage: " ^ basename Sys.argv.(0) ^ " [options] <path> \nOptions are:") 
  in
  let args = Common.parse_options options usage_msg Sys.argv in

  (* must be done after Arg.parse, because Common.profile is set by it *)
  Common.profile_code "Main total" (fun () -> 

    (match args with
    | [dir] -> 
        let model = Model.init_model dir (None) in

        GtkMain.Main.init() +> ignore;
        View.mk_gui model !path_xpm

    (* --------------------------------------------------------- *)
    (* empty entry *)
    (* --------------------------------------------------------- *)
    | _ -> Arg.usage (Arg.align options) usage_msg; 
    );
  )

(*****************************************************************************)
let _ = 
  if Sys.argv +> Array.to_list +> List.exists (fun x -> x ="-debugger")
  then Common.debugger := true;

  Common.finalize          
    (fun ()-> 
      main ()
    )
    (fun()-> 
      pr2 (Common.profile_diagnostic ());
    )
