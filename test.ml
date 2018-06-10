open Common

(* try put stuff in parsing_c/test_parsing_c.ml instead of in this file *)


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
  begin
    Common.write_file ("/tmp/__cocci.c") ("void main() { \n" ^ s ^ "\n}");
    let program = cprogram_of_file ("/tmp/__cocci.c") in
    program +> Common.find_some (fun (e,_) -> 
      match e with
      | Ast_c.Definition ((funcs, _, _, [Ast_c.StmtElem st]),_) -> Some st
      | _ -> None
      )
  end

let (cexpression_of_string: string -> Ast_c.expression) = fun s ->
  begin
    Common.write_file ("/tmp/__cocci.c") ("void main() { \n" ^ s ^ ";\n}");
    let program = cprogram_of_file ("/tmp/__cocci.c") in
    program +> Common.find_some (fun (e,_) -> 
      match e with
      | Ast_c.Definition ((funcs, _, _, compound),_) -> 
          (match compound with
          | [Ast_c.StmtElem (Ast_c.ExprStatement (Some e),ii)] -> Some e
          | _ -> None
          )
      | _ -> None
      )
  end
  

