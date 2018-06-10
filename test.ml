open Common

(* try put stuff in parsing_c/test_parsing_c.ml instead of in this file *)

open Ast_c

module Db = Database_c

(*****************************************************************************)
(* to be called by ocaml toplevel, to test. *)
(*****************************************************************************)

let cprogram_of_file file = 
  (* useful only when called from toplevel *)
  Flag_parsing_c.std_h := "/home/pad/c-yacfe/data/standard.h";
  Parse_c.init_defs !Flag_parsing_c.std_h;

  let (program2, _stat) = Parse_c.parse_c_and_cpp file in
  program2 




let (cstatement_of_string: string -> Ast_c.statement) = fun s ->
  Common.write_file ("/tmp/__cocci.c") ("void main() { \n" ^ s ^ "\n}");
  let program = cprogram_of_file ("/tmp/__cocci.c") in
  program +> Common.find_some (fun (e,_) -> 
    match e with
    | Ast_c.Definition ({Ast_c.f_body = [Ast_c.StmtElem st]},_) -> Some st
    | _ -> None
  )

let (cexpression_of_string: string -> Ast_c.expression) = fun s ->
  Common.write_file ("/tmp/__cocci.c") ("void main() { \n" ^ s ^ ";\n}");
  let program = cprogram_of_file ("/tmp/__cocci.c") in
  program +> Common.find_some (fun (e,_) -> 
    match e with
    | Ast_c.Definition ({Ast_c.f_body = compound},_) -> 
        (match compound with
        | [Ast_c.StmtElem (Ast_c.ExprStatement (Some e),ii)] -> Some e
        | _ -> None
        )
    | _ -> None
  )
  

(*****************************************************************************)
(* Misc *)
(*****************************************************************************)

let test_attributes file = 
  let (ast2, _stat) = Parse_c.parse_c_and_cpp file in
  let ast = Parse_c.program_of_program2 ast2 in

  let s_of_attr attr = 
    attr
    +> List.map (fun (Attribute s, ii) -> s)
    +> Common.join ","
  in
  Visitor_c.vk_program { Visitor_c.default_visitor_c with
    Visitor_c.kdef = (fun (k, bigf) (defbis, ii) -> 
      let sattr  = s_of_attr defbis.f_attr in
      pr2 (spf "%-30s: %s" defbis.f_name sattr);
    );
    Visitor_c.kdecl = (fun (k, bigf) decl -> 
      match decl with
      | DeclList (xs, ii) -> 
          xs +> List.iter (fun (onedecl, iicomma) -> 
            
            let sattr  = s_of_attr onedecl.v_attr in
            let idname = 
              match onedecl.v_namei with
              | Some ((s,ini), _) -> s
              | None -> "novar"
            in
            pr2 (spf "%-30s: %s" idname sattr);
          );
      | _ -> ()
          
    );
  } ast;
  ()


let cpp_options () = [
  Cpp_ast_c.I "/home/yyzhou/pad/linux/include";
] ++ 
  Cpp_ast_c.cpp_option_of_cmdline 
  (!Flag_parsing_c.cpp_i_opts,!Flag_parsing_c.cpp_d_opts)

let test_cpp file = 
  let (ast2, _stat) = Parse_c.parse_c_and_cpp file in
  let dirname = Filename.dirname file in
  let ast = Parse_c.program_of_program2 ast2 in
  let _ast' = Cpp_ast_c.cpp_expand_include (cpp_options()) dirname ast in
  
  ()


(*****************************************************************************)
(* Query *)
(*****************************************************************************)

(* done first via ocamldebug ./spatch -parse_cocci ~/paper-cc09/simple.cocci
 * and later strimmed.
 * 
 * todo? use my generic_print trick so that easier ?
 *)

let gen_pattern_func s = 
     {Ast_cocci.node =
                 Ast_cocci.Exp
                  {Ast_cocci.node =
                    Ast_cocci.FunCall
                     ({Ast_cocci.node =
                        Ast_cocci.Ident
                         {Ast_cocci.node =
                           Ast_cocci.Id
                            (s, (* HERE !!! *)
                             {Ast_cocci.line = 4; Ast_cocci.column = 2;
                              Ast_cocci.strbef = []; Ast_cocci.straft = []},
                             Ast_cocci.MINUS (Ast_cocci.NoPos, []),
                             Ast_cocci.NoMetaPos);
                          Ast_cocci.node_line = 4; Ast_cocci.free_vars = [];
                          Ast_cocci.minus_free_vars = [];
                          Ast_cocci.fresh_vars = [];
                          Ast_cocci.inherited = [];
                          Ast_cocci.saved_witness = [];
                          Ast_cocci.bef_aft = Ast_cocci.NoDots;
                          Ast_cocci.pos_info = None;
                          Ast_cocci.true_if_test_exp = false;
                          Ast_cocci.iso_info = []};
                       Ast_cocci.node_line = 4; Ast_cocci.free_vars = [];
                       Ast_cocci.minus_free_vars = [];
                       Ast_cocci.fresh_vars = []; Ast_cocci.inherited = [];
                       Ast_cocci.saved_witness = [];
                       Ast_cocci.bef_aft = Ast_cocci.NoDots;
                       Ast_cocci.pos_info = None;
                       Ast_cocci.true_if_test_exp = false;
                       Ast_cocci.iso_info = []},
                     ("(",
                      {Ast_cocci.line = 4; Ast_cocci.column = 0;
                       Ast_cocci.strbef = []; Ast_cocci.straft = []},
                      Ast_cocci.MINUS (Ast_cocci.NoPos, []),
                      Ast_cocci.NoMetaPos),
                     {Ast_cocci.node =
                       Ast_cocci.DOTS
                        [{Ast_cocci.node =
                           Ast_cocci.Edots
                            (("...",
                              {Ast_cocci.line = 4; Ast_cocci.column = 0;
                               Ast_cocci.strbef = []; Ast_cocci.straft = []},
                              Ast_cocci.MINUS (Ast_cocci.NoPos, []),
                              Ast_cocci.NoMetaPos),
                            None);
                          Ast_cocci.node_line = 4; Ast_cocci.free_vars = [];
                          Ast_cocci.minus_free_vars = [];
                          Ast_cocci.fresh_vars = [];
                          Ast_cocci.inherited = [];
                          Ast_cocci.saved_witness = [];
                          Ast_cocci.bef_aft = Ast_cocci.NoDots;
                          Ast_cocci.pos_info = None;
                          Ast_cocci.true_if_test_exp = false;
                          Ast_cocci.iso_info = []}];
                      Ast_cocci.node_line = 4; Ast_cocci.free_vars = [];
                      Ast_cocci.minus_free_vars = [];
                      Ast_cocci.fresh_vars = []; Ast_cocci.inherited = [];
                      Ast_cocci.saved_witness = [];
                      Ast_cocci.bef_aft = Ast_cocci.NoDots;
                      Ast_cocci.pos_info = None;
                      Ast_cocci.true_if_test_exp = false;
                      Ast_cocci.iso_info = []},
                     (")",
                      {Ast_cocci.line = 4; Ast_cocci.column = 0;
                       Ast_cocci.strbef = []; Ast_cocci.straft = []},
                      Ast_cocci.MINUS (Ast_cocci.NoPos, []),
                      Ast_cocci.NoMetaPos));
                   Ast_cocci.node_line = 4; Ast_cocci.free_vars = [];
                   Ast_cocci.minus_free_vars = []; Ast_cocci.fresh_vars = [];
                   Ast_cocci.inherited = []; Ast_cocci.saved_witness = [];
                   Ast_cocci.bef_aft = Ast_cocci.NoDots;
                   Ast_cocci.pos_info = None;
                   Ast_cocci.true_if_test_exp = false;
                   Ast_cocci.iso_info = []};
                Ast_cocci.node_line = 4; Ast_cocci.free_vars = [];
                Ast_cocci.minus_free_vars = []; Ast_cocci.fresh_vars = [];
                Ast_cocci.inherited = []; Ast_cocci.saved_witness = [];
                Ast_cocci.bef_aft = Ast_cocci.NoDots;
                Ast_cocci.pos_info = None;
                Ast_cocci.true_if_test_exp = false; Ast_cocci.iso_info = []}
    



let func1_pattern = 
  gen_pattern_func "blk_plug_device"

let func2_pattern = 
  gen_pattern_func "spin_lock_irq" (* TODO disjunction *)

let func_intermediate s = gen_pattern_func s



(* algo: start with list of func and return a list of func that 
 * must still be analyzed further.
 *)

let (find_nodes_satisfying_pattern: 
      Control_flow_c.cflow -> Ast_cocci.rule_elem -> Ograph_extended.nodei list)= 
 fun flow pattern -> 

  let nodes = flow#nodes in
  let nodes = nodes#tolist in
  nodes +> Common.map_filter (fun (nodei, node) -> 
    let res = 
      Pattern_c.match_re_node [] 
        pattern node 
        [] 
    in
    if List.length res > 0
    then Some nodei
    else None
  )

let (check_upward: 
  Ograph_extended.nodei -> Control_flow_c.cflow -> Ast_cocci.rule_elem -> 
  Ograph_extended.nodei option) = 
 fun nodei flow pattern ->

   let already_done = ref [nodei] in
   let found = ref [] in

   let rec aux nodei = 
     let pred = 
       List.map fst ((flow#predecessors nodei)#tolist)
     in
     pred +> List.iter (fun nodei2 -> 
       if List.mem nodei2 !already_done
       then ()
       else begin
         Common.push2 nodei2 already_done;

         let node2 = flow#nodes#assoc nodei2 in

         let res = 
           Pattern_c.match_re_node [] 
             pattern node2
             [] 
         in
         if List.length res > 0
         then Common.push2 nodei2 found
         else 
           aux nodei2
       end
     );
   in
   aux nodei;
   (match !found with
   | [] -> None
   | [x] -> Some x
   | x::y::ys -> 
       pr2 "multiple found";
       Some x
   )
     




let min_pinfo_of_node node = 
  let ii = Lib_parsing_c.ii_of_node node in
  let (maxii, minii) = Lib_parsing_c.max_min_ii_by_pos ii in
  Ast_c.parse_info_of_info minii


let (string_of_node: Ograph_extended.nodei -> Control_flow_c.cflow -> string) = 
 fun nodei flow -> 
  let node = flow#nodes#assoc nodei in
  let s = Common.format_to_string (fun () ->
    Pretty_print_c.pp_flow_simple node
  ) in
  let pos = min_pinfo_of_node node in
  (spf "%s(n%d)--> %s" (Common.string_of_parse_info_bis pos) nodei s)
  

let test_query_db dirdb = 
  Database_c.with_db ~metapath:dirdb (fun db -> 

    (* breath first search *)
    let remaining = ref [] in
    let round = ref 2 in

    remaining := 
      db.Db.callers_of_f#assoc "blk_plug_device"
        +> List.map (fun idfpos -> "blk_plug_device", idfpos);

    while !round > 0 do

      pr2 (spf "round: %d, remaining to check = %d" 
              !round (List.length !remaining));

      let callers = List.rev !remaining in
      remaining := [];
      decr round;

      callers +> List.iter (fun (func_callee, idfpos) -> 
        
        let (Db.IdFuncPos (func_caller,_)) = idfpos in
        pr2 ("caller: " ^ func_caller);
        let id_defs = db.Db.function_def#assoc func_caller in
        
        if List.length id_defs <> 1 
        then pr2 ("MULTIDEF: " ^ func_caller);
        
        id_defs +> List.iter (fun id -> 
          
          let ast = db.Db.objects#assoc id in
          let (_str, _toks) = db.Db.rest_objects#assoc id in
          
          let flowopt = Ast_to_flow.ast_to_control_flow ast in
          
          match flowopt with
          | None -> pr2 ("NO FLOW:" ^ (Common.dump id));
          | Some flow -> 
              let nodes = find_nodes_satisfying_pattern flow 
                (gen_pattern_func func_callee) in
              
              nodes +> List.iter (fun node -> 
                
                pr2 ("starting at: " ^ string_of_node node flow);
                let found_node_opt = check_upward node flow func2_pattern in
                (match found_node_opt with
                | None -> 
                    pr2 "not found at this depth";
                    let new_callers = 
                      try 
                        (db.Db.callers_of_f#assoc func_caller
                          +> List.map (fun idfpos -> func_caller, idfpos))
                      with  Not_found -> 
                        pr2 ("could not get callers of:" ^ func_caller);
                        []
                    in
                    remaining := new_callers @ !remaining;
                   
                    
                | Some node2 -> 
                    pr2 ("YES at: " ^ string_of_node node2 flow);
                )
              );
        )
      );
    done
  )
(*****************************************************************************)
(* Database  *)
(*****************************************************************************)

(* time: 191min on linux source tree *)
let test_build_db0 dir = 
  let prj = (Database_c.Project (Common.chop_dirsymbol dir, None)) in
  let db = Database_c.create_db prj in
  Database_c.close_db db;
  Database_c.with_db ~metapath:(Database_c.metapath_of_project prj) (fun db -> 

    let ext = "[ch]" in
    
    let files = Common.files_of_dir_or_files ext [dir] in
    let nbfiles = List.length files in
    
    Common.check_stack_nbfiles nbfiles; 
    
    files +> Common.index_list +> List.iter (fun (file, i) -> 
      pr2 (spf "PARSING: %s (%d/%d)" file i nbfiles);

      let all_ids = ref [] in

      let (ast2, _stat) = Parse_c.parse_c_and_cpp file in
      ast2 +> List.iter (fun (topelem, info_item) -> 
        match topelem with
        (* bugfix: the finaldef have the same id as the previous item so
         * do not add it otherwise id will not be a primary key.
         *)
        | Ast_c.FinalDef _ -> ()
        | _ -> 
            let id = db +> Database_c.add_toplevel2 file (topelem, info_item) 
            in
            Common.push2 id all_ids;

      );
      db +> Database_c.add_filename_and_ids (file,(List.rev !all_ids));
    );
  )
  


(* pb ps3av_cmd.c *)
let test_update_db1 dir = 
  Database_c.with_db ~metapath:dir (fun db -> 
    db.Db.file_to_ids#iter (fun (file, ids) -> 
      pr2 ("ANALYZING: " ^ file);
      ids +> List.iter (fun id -> 
        let ast = db.Db.objects#assoc id in
        let (_str, _toks) = db.Db.rest_objects#assoc id in

        match ast with
        | Ast_c.Definition (def,ii) -> 
            db +> Database_c.add_function_def (def.Ast_c.f_name, id);
            let callees = 
              Relation_c.callees_of_ast ast 
            in
            db +> Database_c.add_callees_of_f 
              (Db.IdFuncPos (def.Ast_c.f_name, id),  callees)

        | Ast_c.Declaration decl -> 
            ()
        | Ast_c.MacroTop (s, xs, ii) -> 
            ()
        | Ast_c.CppTop top -> 
            (match top with
            | Ast_c.Include {i_include = (inc, ii)}  -> 
                ()
            | Ast_c.Define ((s,ii), body)  -> 
                ()
            | Ast_c.Undef (string,ii) -> 
                ()
            | Ast_c.PragmaAndCo (ii) -> 
                ()
            )
              
        | Ast_c.IfdefTop (Ast_c.IfdefDirective (kind, ii)) -> 
            ()

        | Ast_c.EmptyDef ii -> 
            ()
        | Ast_c.NotParsedCorrectly ii -> 
            ()
        | Ast_c.FinalDef info -> 
            ()
      )
    )
  )


let test_build_db dir = 
  let prj = (Database_c.Project (Common.chop_dirsymbol dir, None)) in
  test_build_db0 dir;
  test_update_db1 (Database_c.metapath_of_project prj);
  ()



(* ---------------------------------------------------------------------- *)
let test_open_db dir file = 
  Database_c.with_db ~metapath:dir (fun db -> 
    let ids = db.Db.file_to_ids#assoc file in
    ids +> List.iter (fun id -> 
      let (str, _toks) = db.Db.rest_objects#assoc id in
      pr str;
    );
  )


(* time: 28min on linux source database *)
let test_open_db2 dir = 
  Database_c.with_db ~metapath:dir (fun db -> 
    db.Db.file_to_ids#tolist +> Common.index_list_and_total +> List.iter 
     (fun ((file, ids), i, total) -> 
      pr2 (spf "ANALYZING: %s %d/%d " file i total);
      ids +> List.iter (fun id -> 
        (*
        let _ast = db.Db.objects#assoc id in
        let (_str, _toks) = db.Db.rest_objects#assoc id in
        (* pr str; *)
        *)
        ()
      )
    )
  )




(*****************************************************************************)
(* Main entry for Arg *)
(*****************************************************************************)

let actions () = [
  "-test_attributes", " <file>",
  Common.mk_action_1_arg test_attributes;
  "-test_cpp", " <file>",
  Common.mk_action_1_arg test_cpp;
  "-test_query_db", " <db>",
  Common.mk_action_1_arg test_query_db;
  "-test_build_db", "",
  Common.mk_action_1_arg test_build_db;
  "-test_open_db", " <db> <file>",
  Common.mk_action_2_arg test_open_db;
  "-test_open_db2", " <db>",
  Common.mk_action_1_arg test_open_db2;

  "-test_update_db1", " <db>",
  Common.mk_action_1_arg test_update_db1;

]
