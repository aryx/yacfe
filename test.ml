open Common

(* try put stuff in parsing_c/test_parsing_c.ml or analyze_c/test_analyze_c.ml
 * instead of in this file.
 *)

open Ast_c

(*****************************************************************************)
(* to be called by ocaml toplevel, to test. *)
(*****************************************************************************)

let cprogram_of_file file =
  (* useful only when called from toplevel *)
  Flag_parsing_c.std_h := "/home/pad/c-yacfe/config/macros/standard.h";
  Parse_c.init_defs !Flag_parsing_c.std_h;

  let (program2, _stat) = Parse_c.parse_c_and_cpp file in
  program2


(*****************************************************************************)
(* Misc *)
(*****************************************************************************)


(*****************************************************************************)
(* Main entry for Arg *)
(*****************************************************************************)

let actions () = [

]
