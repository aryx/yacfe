open Common 

module Flag = Flag_parsing_c

let config_path = "/home/pad/c-yacfe"
let score_path = "/home/pad/c-yacfe/tmp"

let no_macro_file = ref false

let parse_all = ref (fun x -> failwith "no parse_all")


(* ------------------------------------------------------------------------- *)
let parse_software_src str = 
  let (dir, stdh, fbefore) = 
    Software_src.all_cfgs_assoc +> List.assoc str in
  
  let xfile = Flag.mk_macro_path ~cocci_path:config_path stdh in
  
  fbefore ();
  if stdh <> "" && not (!no_macro_file)
  then begin 
    Parse_c.init_defs xfile;
    Parse_cplusplus.init_defs xfile;
    (*Parse_c.add_defs (Filename.concat config_path commonh);*)
  end;
  
  let (_stat, _score) = !parse_all [dir] in
  ()
 


(* ------------------------------------------------------------------------- *)
let cc09 soft_str = 
  let softs = Software_src.soft_of_str soft_str in
  softs +> List.map fst3 +> List.iter (fun x -> 
    if Common.is_directory x then ()
    else failwith ("no directory: " ^ x)
  );
  softs +> List.map snd3 +> List.iter (fun stdh -> 
    let xfile = Flag.mk_macro_path ~cocci_path:config_path stdh in
    if stdh = "" || Sys.file_exists xfile then ()
    else failwith ("no macro file: " ^ xfile)
  );
(* TOREPUT but force to have more dependencies
  if Features.Distribution.under_mpirun ()
  then 
    !parse_all (softs +> List.map fst3) +> ignore
  else 
*)
   begin

    let stats = 
      softs +> List.map (fun (dir, stdh, fbefore) -> 
        let xfile = Flag.mk_macro_path ~cocci_path:config_path stdh in

        fbefore ();
        if stdh <> "" && not (!no_macro_file)
        then begin 
          Parse_c.init_defs xfile;
          Parse_cplusplus.init_defs xfile;
          (*Parse_c.add_defs (Filename.concat config_path commonh);*)
        end;
        
        let (stat, score) = !parse_all [dir] in
        Parsing_stat.print_stat_numbers ();

        stat, score, dir
      ) 
    in
    let total_parsing_stat = 
      stats +> List.map fst3 +> List.flatten in
    let newscore = 
      stats +> List.map snd3 +> List.map Common.hash_to_list +> List.flatten +> 
        Common.hash_of_list
    in

    let dirname = "cc09" in
    (
      pr2 "--------------------------------";
      pr2 "regression testing  information";
      pr2 "--------------------------------";
      let str = Str.global_replace (Str.regexp "/") "__" dirname in
      let def = if !Flag_parsing_c.filter_define_error then "_def_" else "" in
      let ext = "_all_" ^ soft_str ^ (if !no_macro_file then "_noD_" else "") in
      Common.regression_testing newscore 
        (Filename.concat score_path
            ("score_parsing__" ^str ^ def ^ ext ^ ".marshalled"))
    );
    Parsing_stat.print_stat_numbers ();


    stats +> List.iter (fun (stat, score, dir) -> 
      pr2_xxxxxxxxxxxxxxxxx();
      pr2 dir;
      Statistics_parsing.print_parsing_stat_list stat;
    );
    
    pr2_xxxxxxxxxxxxxxxxx();
    Statistics_parsing.print_parsing_stat_list total_parsing_stat;
    
    ()
  end


(* ------------------------------------------------------------------------- *)


let cc09_stat_stdh soft_str  = 
  let softs = Software_src.soft_of_str soft_str in
  softs +> List.map snd3 +> List.map (fun stdh -> 
    let xfile = Flag.mk_macro_path ~cocci_path:config_path stdh in
    if stdh = "" || Sys.file_exists xfile then ()
    else failwith ("no macro file: " ^ xfile);

    let defines = Common.cat xfile +> List.filter (fun s -> 
      s =~ "^#define.*"
    ) in
    let n = List.length defines in
    pr (spf "%s: %d" xfile n);
    n
  ) +> Common.avg_list 
    +> (fun f -> pr (spf "avg: %f" f))


let cc09_stat_gcc_compiled dir = 
  let xs = Common.files_of_dir_or_files "c" [dir] in
  let xs' = xs +> List.filter (fun f -> 
    if Sys.file_exists (Common.replace_ext f "c" "o")
    then true
    else begin 
      pr2 (spf "not compiled?: %s" f);
      false 
    end
  ) in
  let nxs = (List.length xs) in
  let nxs' = (List.length xs') in
  pr (spf "total=%d, with .o=%d, percent compiled= %f%%" nxs nxs' 
         (Common.pourcent_float nxs' nxs));
  ()

let cc09_gcc_count_file_processed dir = 
  raise Todo



let cc09_stat_mly file = 
  let xs = Common.cat file in
  let xs' = xs +> List.filter (fun s -> 
    let does_match = (s =~ "^[a-z_]*:.*[a-zA-Z_].*" || s =~ "[ \t]*|.*") in
    if does_match
    then pr2 (spf "yes: %s" s)
    else pr2 (spf "nop: %s" s);
    does_match
  ) in
  pr (spf "total = %d" (List.length xs'));
  ()


open Ast_c
let cc09_null_transfo file = 
(* X == 0  -->  X == NULL when X is a pointer *)
(*let main = *)
  let (ast2, _stat) = Parse_c.parse_c_and_cpp file (* Sys.argv(1) *) in
  let ast = Parse_c.program_of_program2 ast2 in

  Type_annoter_c.annotate_program 
    !Type_annoter_c.initial_env ast
    +> ignore;

  (* done first via ocamldebug ./spatch -parse_cocci ~/paper-cc09/simple.cocci
   * and later strimmed.
   *)
  let null_addon = 
    Ast_cocci.ExpressionTag
      (Ast_cocci.make_term 
          (Ast_cocci.Ident
            (Ast_cocci.make_term 
                (Ast_cocci.Id
                  ("MYNULL", Ast_cocci.no_info,
                  Ast_cocci.PLUS, Ast_cocci.NoMetaPos)))))
  in

  Visitor_c.vk_program { Visitor_c.default_visitor_c with
    Visitor_c.kexpr = (fun (k, bigf) exp -> 
      match Ast_c.unwrap_expr exp with
      | Binary(e1, Logical (Eq), (((Constant(Int("0")) as _e2),_t),ii)) -> 
          (match Ast_c.get_type_expr e1 with 
          | (Some ((qu, (Pointer _,_ii)), _), _test) -> 
              let idzero = Common.tuple_of_list1 ii in
              idzero.cocci_tag := Some (
                Ast_cocci.MINUS (Ast_cocci.NoPos, [[null_addon]]), []);
              (*Ast_c.modify_token (fun s -> "NULL") idzero;*)
          | _ -> ()
          )
      | _ -> k exp
    );
  } ast;
  let tmpfile = "/tmp/modified.c" in
  Unparse_c.pp_program_default ast2 tmpfile;
  Common.cat tmpfile +> List.iter pr2;
  ()

(* ------------------------------------------------------------------------- *)

let misc_xxx file = 
  Common.cat file +> List.iter (fun s -> 
    let ident = "\\([A-Z][A-Za-z]*\\)" in
    let maj = "[A-Z]" in
    let newstr = 
      Common.global_replace_regexp ident (fun s -> 

       if String.uppercase s = s (* all maj, so do nothing *)
       then s
       else 
        let is_first = ref true in
        Common.global_replace_regexp maj (fun m -> 
          if !is_first 
          then begin 
            is_first := false;
            String.lowercase m
          end
          else 
            "_" ^ String.lowercase m
        ) s 
      ) s 
    in
    pr newstr;
  )


(* ------------------------------------------------------------------------- *)
let extra_actions () = [
  "-parse_software_src", " ",
  Common.mk_action_1_arg (fun x -> ignore(parse_software_src (x)));
  "-cc09", "  <soft_set> ",
  Common.mk_action_1_arg cc09;
  "-cc09_gcc", "   ",
  Common.mk_action_1_arg cc09_gcc_count_file_processed;
  "-cc09_stat_stdh", "  <soft_set> ",
  Common.mk_action_1_arg cc09_stat_stdh;
  "-cc09_stat_gcc_compiled", "   ",
  Common.mk_action_1_arg cc09_stat_gcc_compiled;
  "-cc09_stat_mly", "   ",
  Common.mk_action_1_arg cc09_stat_mly;
  "-cc09_null_transfo", "   ",
  Common.mk_action_1_arg cc09_null_transfo;
  "-xxx", "   ",
  Common.mk_action_1_arg misc_xxx;
]

let extra_options () = [
    "-no_macro_file", Arg.Set no_macro_file,
    " ";
]
