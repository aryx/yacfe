
type pr_elem_func = Ast_cplusplus.info -> unit
type pr_space_func = unit -> unit

val pp_expression_gen :
    pr_elem_func -> pr_space_func -> Ast_cplusplus.expression -> unit
val pp_statement_gen : pr_elem_func -> pr_space_func -> Ast_cplusplus.statement -> unit
val pp_decl_gen : pr_elem_func -> pr_space_func -> Ast_cplusplus.declaration -> unit
val pp_init_gen : pr_elem_func -> pr_space_func -> Ast_cplusplus.initialiser -> unit

val pp_type_gen : pr_elem_func -> pr_space_func -> Ast_cplusplus.fullType -> unit
val pp_type_with_ident_gen :
  pr_elem_func -> pr_space_func ->
  (string * Ast_cplusplus.info) option ->
  (Ast_cplusplus.storage * Ast_cplusplus.il) option -> Ast_cplusplus.fullType -> unit


val pp_program_gen : pr_elem_func -> pr_space_func -> Ast_cplusplus.toplevel -> unit

val pp_expression_simple : Ast_cplusplus.expression -> unit
val pp_statement_simple : Ast_cplusplus.statement -> unit
val pp_type_simple : Ast_cplusplus.fullType -> unit
