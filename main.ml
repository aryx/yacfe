open Common

(*****************************************************************************)
(* Purpose *)
(*****************************************************************************)

(* This module handle the IO, the special name of info files. 
 * the pure algorithmic stuff is in parsing_c/
 *)

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

let detect_pl_of_file_with_cplusplus_header_addon file = 
    let (d,b,e) = Common.dbe_of_filename file in
    if e = "h" && Parse_cplusplus.is_problably_cplusplus_file file
    then begin
      pr2 ("MISC: c++ .h file, using c++ parser not c parser:" ^ file);
      Programming_language.Cplusplus
    end
    else Programming_language.detect_pl_of_file file


let parse_and_comments_of_file file = 
  match detect_pl_of_file_with_cplusplus_header_addon file with
  | Programming_language.C -> 
      let (program2, parsing_stat) = 
        Parse_c.parse_c_and_cpp file in

      let program = Parse_c.program_of_program2 program2 in

      let _estat = Statistics_c.statistics_of_program program in

      program2 +> List.iter (fun (ast, (s, toks)) -> 
        Parse_c.print_commentized toks
      );
      
      let parsing_stat = 
        Language_helper.conv_c_parsing_stat parsing_stat in

(*      
      let (comments_packed, unpacked_info_comments, 
        (comment_stat, entities_stat)) = 
        Comments_c_extraction.comments_of_program 
          ~do_packing:(!use_c_comment_packing)
          program in
      comments_packed, unpacked_info_comments,
      (parsing_stat, comment_stat, entities_stat)
*)
      parsing_stat
  | Programming_language.Cplusplus -> 
      
      let (program, parsing_stat) = 
        Parse_cplusplus.parse_c_and_cpp file in
      
      let parsing_stat = 
        Language_helper.conv_cplusplus_parsing_stat parsing_stat in
(*      
      let (comments_packed, unpacked_info_comments, 
          (comment_stat, entities_stat)) = 
        Comments_cplusplus_extraction.comments_of_program 
          ~do_packing:true
          program in
      comments_packed, unpacked_info_comments, 
      (parsing_stat, comment_stat, entities_stat)
*)
      parsing_stat

  | Programming_language.Java -> 
      let (program, parsing_stat) = 
        Parse_java.parse_java file in
      
      let parsing_stat = 
        Language_helper.conv_java_parsing_stat parsing_stat in
(*      
      let (comments_packed, unpacked_info_comments, 
          (comment_stat, entities_stat)) = 
        Comments_java_extraction.comments_of_program program in
      comments_packed, unpacked_info_comments,
      (parsing_stat, comment_stat, entities_stat)
*)
      parsing_stat

(*****************************************************************************)
(* Extra actions *)
(*****************************************************************************)

let score_path = "/home/pad/c-yacfe/tmp"

let parse_one_file (file, i, nbfiles) = 
  pr2 (spf "PARSING: %s (%d/%d)" file i nbfiles);

  let (stat) = 
    parse_and_comments_of_file file
  in
  file, stat


let parse_all xs =

  let dirname_opt = 
    match xs with
    | [x] when is_directory x -> Some x
    | xs -> 
        Some (xs +> Common.join "" +> md5sum_of_string)
  in

  (*
  Flag_parsing_c.debug_typedef := true;
  *)
  Flag_parsing_c.debug_cpp := true;


  Flag_parsing_c.verbose_parsing := true;

  (*
  Flag_parsing_c.filter_classic_passed := true;

  Flag_parsing_c.filter_msg := false;
  Flag_parsing_cplusplus.filter_msg := false;
  *)

  (* sure ? *)
  Flag_parsing_c.filter_define_error := false;
  Flag_parsing_cplusplus.filter_define_error := false;


  let newscore  = Common.empty_score () in
  let parsing_stat_list = ref [] in


  let biglist = (fun () -> 

    let files = 
      if (xs +> List.for_all Common.is_directory)
      then
        let ext = "[ch]" in
        let ext2 = "java" in
        let ext3 = ".*\\.\\(cpp\\|cc\\|C\\|cxx\\|hpp\\|hxx\\)$" in
        
        let files1 = Common.files_of_dir_or_files ext (xs) in
        let files2 = Common.files_of_dir_or_files ext2 (xs) in
        let files3 = Common.files_of_dir_or_files_no_vcs_post_filter ext3 xs in
        let files = files3 ++ files2 ++ files1 in
        files
      else xs
    in
    let nbfiles = List.length files in
    Common.check_stack_nbfiles nbfiles; 

    files +> Common.index_list +> List.map (fun (i,j) -> (i,j,nbfiles))
  )
  in
  let map_ex = parse_one_file in

  let reduce_ex = (fun xxs -> 
    let stats_parse = xxs in

    stats_parse +> List.iter (fun (file, stat) -> 
      let s = 
        sprintf "bad = %d, timeout = %B" 
          stat.Statistics_parsing.bad stat.Statistics_parsing.have_timeout
      in
      
      Common.push2 stat  parsing_stat_list;

      if stat.Statistics_parsing.bad = 0 && 
        not stat.Statistics_parsing.have_timeout
      then Hashtbl.add newscore file (Common.Ok)
      else Hashtbl.add newscore file (Common.Pb s)
    );

 
    dirname_opt +> Common.do_option (fun dirname -> 
      pr2 "--------------------------------";
      pr2 "regression testing  information";
      pr2 "--------------------------------";
      let str = Str.global_replace (Str.regexp "/") "__" dirname in
      let def = if !Flag_parsing_c.filter_define_error then "_def_" else "" in
      let ext = "_all_" in
      Common.regression_testing newscore 
        (Filename.concat score_path
            ("score_parsing__" ^str ^ def ^ ext ^ ".marshalled"))
    );
    
    pr2_xxxxxxxxxxxxxxxxx();
    Parsing_stat.print_stat_numbers ();
    Statistics_parsing.print_parsing_stat_list !parsing_stat_list;
    

    !parsing_stat_list, newscore
  ) in
  (* will call either map_ex for worker or reduce_ex for server *)
  biglist +> Features.Distribution.mpi_main2 ~debug_mpi:true map_ex reduce_ex


let _ = Cc09.parse_all := parse_all


(* ------------------------------------------------------------------------- *)
let yacfe_extra_actions () = [
  "-parse_all", " ",
  Common.mk_action_n_arg (fun x -> ignore(parse_all x));
]

(*****************************************************************************)
(* The options *)
(*****************************************************************************)

let all_actions () = 
   yacfe_extra_actions() ++
   Cc09.extra_actions() ++
   Test.actions() ++
   Test_parsing_c.actions() ++
   Test_parsing_cplusplus.actions() ++
   Test_parsing_java.actions() ++
   []

let options () = 
  Flag_parsing_c.cmdline_flags_macrofile () ++
  Flag_parsing_c.cmdline_flags_verbose () ++
  Flag_parsing_c.cmdline_flags_debugging () ++
  Flag_parsing_c.cmdline_flags_parsing_algos () ++

  Flag_parsing_cplusplus.cmdline_flags_macrofile () ++
  Flag_parsing_cplusplus.cmdline_flags_verbose () ++
  Flag_parsing_cplusplus.cmdline_flags_debugging () ++

  Cc09.extra_options() ++

  [
  ] ++
  Common.options_of_actions action (all_actions()) ++
  Common.cmdline_flags_devel () ++
  Common.cmdline_flags_verbose () ++
  [
  "-version",   Arg.Unit (fun () -> 
    pr2 (spf "yacfe version: %s" Config.version);
    exit 0;
  ), 
    "  guess what";

  (* this can not be factorized in Common *)
  "-date",   Arg.Unit (fun () -> 
    pr2 "version: $Date: 2008/10/26 00:44:57 $";
    raise (Common.UnixExit 0)
    ), 
  "   guess what";
  ]

 
(*****************************************************************************)
(* Main entry point *)
(*****************************************************************************)

let main () = 

  Flag_parsing_c.std_h := "/home/pad/c-yacfe/data/standard.h";
  Flag_parsing_cplusplus.std_h := "/home/pad/c-yacfe/data/standard.h";

  let argv = Features.Distribution.mpi_adjust_argv Sys.argv in


  let usage_msg = 
    "Usage: " ^ basename Sys.argv.(0) ^ 
      " [options] <file or dir> " ^ "\n" ^ "Options are:"
  in
  (* does side effect on many global flags *)
  let args = Common.parse_options (options()) usage_msg argv in

  (* must be done after Arg.parse, because -macro_file can set it *)
  Parse_c.init_defs !Flag_parsing_c.std_h;
  Parse_cplusplus.init_defs !Flag_parsing_cplusplus.std_h;
    
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
    | x::xs -> 
        (* CQL *)

        let ext = "[ch]" in

        let files = Common.files_of_dir_or_files ext (x::xs) in
        let nbfiles = List.length files in

        let parsing_stat_list = ref [] in
        (* let comment_stat_list = ref [] in *)
        (* let entities_stat_list = ref [] in *)

        Common.check_stack_nbfiles nbfiles; 

        files +> Common.index_list +> List.iter (fun (file, i) -> 

          pr2 (spf "PARSING: %s (%d/%d)" file i nbfiles);

          (* toc:
           * - parsing c and cpp and comments (well basic comments parsing)
           * - comments_extraction
           * - comments_extraction check
           *)

          let (program, parsing_stat) = 
            Parse_c.parse_c_and_cpp file in

          let (_comments_packed, _allx, _pinfo_mapping, _entities_stat) = 
            (* TOREPUT Comment_annotater.comments_of_program program *)
            (), (), (), ()
          in

          (*
          let _info_comments = comments +> List.map fst in
          Parse_c_comments_only.check_extraction file info_comments;
          *)

          Common.push2 parsing_stat  parsing_stat_list;
          (*
            Common.push2 comment_stat  comment_stat_list;
            Common.push2 entities_stat entities_stat_list;
          *)
        );
        (* -------------------------- *)
        (* end iter *)
        (* -------------------------- *)

        Parsing_stat.print_stat_numbers ();
        Parsing_stat.print_parsing_stat_list              !parsing_stat_list;

        (*
        pr2_xxxxxxxxxxxxxxxxx ();
        Comments_statistics.print_comments_stat_list !comment_stat_list;
        Statistics_c.print_entities_stat_list !entities_stat_list;
        *)


    (* --------------------------------------------------------- *)
    (* empty entry *)
    (* --------------------------------------------------------- *)
    | [] -> 
        Common.usage usage_msg (options()); 
        failwith "too few arguments"
          
    )
  )

(*****************************************************************************)
let _ =
  Common.main_boilerplate (fun () -> 
    main ();
  )
