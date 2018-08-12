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
 * program also depends on the external file
 * - macro files in macros/standard.h,
 * - and typing environment in environment_unix.h
 * Then can be set via -macro_file, -envir_file.
 *)

(* action mode *)
let action = ref ""

let macro_file = ref ""

(*****************************************************************************)
(* Some  debugging functions *)
(*****************************************************************************)

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

let parse_and_comments_of_file file =
  let (program2, parsing_stat) =
    Parse_c.parse_c_and_cpp file in

  (* let program = Parse_c.program_of_program2 program2 in *)

      (* let _estat = Statistics_c.statistics_of_program program in *)

  program2 +> List.iter (fun (ast, (s, toks)) ->
    Parse_c.print_commentized toks
  )


(*****************************************************************************)
(* Main action *)
(*****************************************************************************)

let main_action xs =
  match xs with
  | x::xs ->
        (* CQL *)

        let ext = "[ch]" in

        let files = Common2.files_of_dir_or_files ext (x::xs) in
        let nbfiles = List.length files in

        let parsing_stat_list = ref [] in
        (* let comment_stat_list = ref [] in *)
        (* let entities_stat_list = ref [] in *)

        Common2.check_stack_nbfiles nbfiles;

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

          Common.push parsing_stat  parsing_stat_list;
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
  | _ -> raise Impossible


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

(*
  let dirname_opt =
    match xs with
    | [x] when Common2.is_directory x -> Some x
    | xs ->
        Some (xs +> Common.join "" +> Common2.md5sum_of_string)
  in
*)

  (*
  Flag_parsing_c.debug_typedef := true;
  *)
  Flag_parsing_c.debug_cpp := true;

  Flag_parsing_c.verbose_parsing := true;

  (*
  Flag_parsing_c.filter_classic_passed := true;
  Flag_parsing_c.filter_msg := false;
  *)

  (* sure ? *)
  Flag_parsing_c.filter_define_error := false;
(*
  let newscore  = Common2.empty_score () in
  let parsing_stat_list = ref [] in

  let biglist = (fun () ->

    let files =
      if (xs +> List.for_all Common2.is_directory)
      then
        let ext = "[ch]" in
        let ext2 = "java" in
        let ext3 = ".*\\.\\(cpp\\|cc\\|C\\|cxx\\|hpp\\|hxx\\)$" in

        let files1 = Common2.files_of_dir_or_files ext (xs) in
        let files2 = Common2.files_of_dir_or_files ext2 (xs) in
        let files3 = Common2.files_of_dir_or_files_no_vcs_post_filter ext3 xs in
        let files = files3 @ files2 @ files1 in
        files
      else xs
    in
    let nbfiles = List.length files in
    Common2.check_stack_nbfiles nbfiles;

    files +> Common.index_list +> List.map (fun (i,j) -> (i,j,nbfiles))
  )
  in
  let map_ex = parse_one_file in

  let reduce_ex = (fun xxs ->
    let stats_parse = xxs in

    stats_parse +> List.iter (fun (file, stat) ->
      let s =
        spf "bad = %d, timeout = %B"
          stat.Statistics_parsing.bad stat.Statistics_parsing.have_timeout
      in

      Common.push stat  parsing_stat_list;

      if stat.Statistics_parsing.bad = 0 &&
        not stat.Statistics_parsing.have_timeout
      then Hashtbl.add newscore file (Common2.Ok)
      else Hashtbl.add newscore file (Common2.Pb s)
    );


    dirname_opt +> Common.do_option (fun dirname ->
      pr2 "--------------------------------";
      pr2 "regression testing  information";
      pr2 "--------------------------------";
      let str = Str.global_replace (Str.regexp "/") "__" dirname in
      let def = if !Flag_parsing_c.filter_define_error then "_def_" else "" in
      let ext = "_all_" in
      Common2.regression_testing newscore
        (Filename.concat score_path
            ("score_parsing__" ^str ^ def ^ ext ^ ".marshalled"))
    );

    Common2.pr2_xxxxxxxxxxxxxxxxx();
    Parsing_stat.print_stat_numbers ();
    Statistics_parsing.print_parsing_stat_list !parsing_stat_list;


    !parsing_stat_list, newscore
  ) in
  (* will call either map_ex for worker or reduce_ex for server *)
  (* TODO biglist map_ex reduce_ex *)
*)
  ()


(* ------------------------------------------------------------------------- *)
let yacfe_extra_actions () = [
  "-parse_all", " ",
  Common.mk_action_n_arg (fun x -> ignore(parse_all x));
]

(*****************************************************************************)
(* The options *)
(*****************************************************************************)
let (++) = (@)

let all_actions () =
   yacfe_extra_actions() ++
   Test.actions() ++
   Test_parsing_c.actions() ++

   []

let options () =
  Flag_parsing_c.cmdline_flags_macrofile () ++
  Flag_parsing_c.cmdline_flags_envfile () ++
  Flag_parsing_c.cmdline_flags_cpp () ++
  Flag_parsing_c.cmdline_flags_parsing_algos () ++

  Flag_parsing_c.cmdline_flags_verbose () ++
  Flag_parsing_c.cmdline_flags_debugging () ++
  Flag_parsing_c.cmdline_flags_checks () ++

  [
    "-macro_file", Arg.Set_string macro_file,
    " <file>";
  ] ++
  Common.options_of_actions action (all_actions()) ++
  Common2.cmdline_flags_devel () ++
  Common2.cmdline_flags_verbose () ++
  Common2.cmdline_flags_other () ++
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
  (*Common_extra.set_link(); *)
  (*let argv = Features.Distribution.mpi_adjust_argv Sys.argv in *)
  let argv = Sys.argv in


  let usage_msg =
    "Usage: " ^ Filename.basename Sys.argv.(0) ^
      " [options] <file or dir> " ^ "\n" ^ "Options are:"
  in
  (* does side effect on many global flags *)
  let args = Common.parse_options (options()) usage_msg argv in

  (* must be done after Arg.parse, because -macro_file can set it *)
  Parse_c.init_defs_builtins !Flag_parsing_c.std_h;

  if !macro_file <> ""
  then Parse_c.init_defs !macro_file;

  Type_annoter_c.init_env !Flag_parsing_c.std_envir;

  Cpp_ast_c.show_cpp_i_opts !Flag_parsing_c.cpp_i_opts;
  Cpp_ast_c.show_cpp_d_opts !Flag_parsing_c.cpp_d_opts;

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
        main_action (x::xs)

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
