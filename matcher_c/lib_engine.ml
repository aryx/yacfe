open Ograph_extended

(*****************************************************************************)
(* the different ctl formula related types *)
(*****************************************************************************)
type mvar = Ast_cocci.meta_name

type predicate =
    InLoop | TrueBranch | FalseBranch
  | After (* pointer to the code after an if or while *)
  | FallThrough
  | Return (* any exit from the current function *)
  | FunHeader | Top | Exit | ErrorExit | Goto
  | Paren of Ast_cocci.meta_name
  | Match of Ast_cocci.rule_elem
  | Label of Ast_cocci.meta_name
  | BCLabel of Ast_cocci.meta_name (* parent of break or continue *)
  | PrefixLabel of Ast_cocci.meta_name
  | BindGood of Ast_cocci.meta_name (* used to implement \+ *)
  | BindBad  of Ast_cocci.meta_name
  | FakeBrace

(* coccionly: 
type ctlcocci = (predicate, Ast_cocci.meta_name) Wrapper_ctl.wrapped_ctl
*)


(*****************************************************************************)
(* the different binding types *)
(*****************************************************************************)
type metavars_binding = Ast_c.metavars_binding

(* used in ctlcocci_integration *)
type metavar_binding_kind2 = 
  | NormalMetaVal of Ast_c.metavar_binding_kind
  | ParenVal of Ast_cocci.meta_name
  | LabelVal of int list
  | GoodVal | BadVal (* used to implement \+ *)

and metavars_binding2 = (mvar, metavar_binding_kind2) Common.assoc



(*****************************************************************************)
(* the CTL model related types *)
(*****************************************************************************)
(* coccionly: 
type label_ctlcocci = 
 predicate -> 
 (nodei * 
 (predicate * (mvar, metavar_binding_kind2) Ast_ctl.generic_substitution)) 
 list
 
type model = Control_flow_c.cflow * label_ctlcocci * nodei list
*)

type transformation_info = 
 (nodei * metavars_binding * Ast_cocci.rule_elem) list


(*****************************************************************************)
(* comparing binding *)
(*****************************************************************************)

let equal_binding xs ys = 
  List.sort compare xs = List.sort compare ys
