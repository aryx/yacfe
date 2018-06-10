open Common.BasicType 

val cprogram_of_file : filename -> Parse_c.program2
val cstatement_of_string  : string -> Ast_c.statement
val cexpression_of_string : string -> Ast_c.expression

val actions: unit -> Common.cmdline_actions
