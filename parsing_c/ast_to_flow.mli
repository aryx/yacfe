
val ast_to_control_flow : Ast_c.toplevel -> Control_flow_c.cflow option

val deadcode_detection : Control_flow_c.cflow -> unit
val check_control_flow : Control_flow_c.cflow -> unit

val annotate_loop_nodes : Control_flow_c.cflow -> Control_flow_c.cflow

type error = 
  | DeadCode          of Parse_info.t option
  | CaseNoSwitch      of Parse_info.t
  | OnlyBreakInSwitch of Parse_info.t
  | NoEnclosingLoop   of Parse_info.t
  | GotoCantFindLabel of string * Parse_info.t
  | NoExit of Parse_info.t
  | DuplicatedLabel of string
  | NestedFunc
  | ComputedGoto
  | Define of Parse_info.t

exception Error of error

val report_error : error -> unit
