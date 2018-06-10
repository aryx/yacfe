open Common

module C = Ast_c

(*****************************************************************************)
(* Purpose *)
(*****************************************************************************)

(*****************************************************************************)
(* Flags *)
(*****************************************************************************)
(* In addition to flags that can be tweaked via -xxx options (cf the
 * full list of options in the "the options" section below), this 
 * program also depends on the external file data/standard.h.
 *)

(* action mode *)
let action = ref ""

(*****************************************************************************)
(* Some  debugging functions *)
(*****************************************************************************)

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

(*****************************************************************************)
(* Main action *)
(*****************************************************************************)

let visit asts2 = 
  let asts = Parse_c.program_of_program2 asts2 in
  let props = ref [] in 

  let bigf = { Visitor_c.default_visitor_c with
    Visitor_c.ktoplevel = (fun (k, bigf) top -> 
      k top;
      match top with

      (* handled by kdecl *)
      | C.Declaration decl -> 
          ()
      | C.Definition (defbis,_ii) -> 
          let s = defbis.C.f_name in
          Common.push2 ("function:" ^s) props;
      | C.MacroTop (s,_,_ii) -> 
          Common.push2 ("macrotop:" ^s) props;

      | _ -> 
          ()
    );
  } in
  asts +> List.iter (Visitor_c.vk_toplevel bigf);

  let stats = Statistics_c.statistics_of_program asts in
  stats +> Statistics_code.assoc_of_entities_stat +> List.iter (fun (s,v) -> 
    Common.push2 (spf "nb_%s:%d" s v) props
  );

  List.rev !props




let transduce  file = 
  Flag_parsing_c.verbose_lexing := false;
  Flag_parsing_c.verbose_parsing := false;

  Flag_parsing_c.debug_lexer := false; 
  Flag_parsing_c.debug_typedef := false;
  Flag_parsing_c.debug_cpp := false;
  Flag_parsing_c.debug_etdt := false;

  let (program,_stat) = Parse_c.parse_c_and_cpp file in
  let props = visit program in
  pr (Common.join "/" props);
  ()

(*****************************************************************************)
(* The options *)
(*****************************************************************************)

let all_actions () = 
  []

let options () = 
  Flag_parsing_c.cmdline_flags_macrofile () ++
  Flag_parsing_c.cmdline_flags_verbose () ++
  Flag_parsing_c.cmdline_flags_debugging () ++
  [
  ] ++
  Common.options_of_actions action (all_actions()) ++
  [
  (* this can not be factorized in Common *)
  "-version",   Arg.Unit (fun () -> 
    pr2 "version: $Date: 2008/06/08 12:32:06 $";
    raise (Common.UnixExit 0)
  ), 
  "   guess what";
  ]

(*****************************************************************************)
(* Main entry point *)
(*****************************************************************************)


let main () = 
  let usage_msg = 
    "Usage: " ^ basename Sys.argv.(0) ^ 
      " [options] <file> " ^ "\n" ^ "Options are:"
  in
  (* does side effect on many global flags *)
  let args = Common.parse_options (options()) usage_msg Sys.argv in

  (* must be done after Arg.parse, because -macro_file can set it *)
  Parse_c.init_defs !Flag_parsing_c.std_h;
    
  (* must be done after Arg.parse, because Common.profile is set by it *)
  Common.profile_code "Main total" (fun () -> 

    (match args with
    
    (* --------------------------------------------------------- *)
    (* actions, useful to debug subpart *)
    (* --------------------------------------------------------- *)
    | xs when List.mem !action (Common.action_list (all_actions())) -> 
        Common.do_action !action xs (all_actions())

    | _ when not (Common.null_string !action) -> 
        failwith ("unrecognized action or wrong params: " ^ !action)

    (* --------------------------------------------------------- *)
    (* main entry *)
    (* --------------------------------------------------------- *)
    | [x] -> 
        transduce x

    (* --------------------------------------------------------- *)
    (* empty entry *)
    (* --------------------------------------------------------- *)
    | _  -> 
        Common.usage usage_msg (options()); 
        failwith "too few arguments"
          
    )
  )

(*****************************************************************************)
let _ =
  Common.main_boilerplate (fun () -> 
    main ();
  )
    

      
