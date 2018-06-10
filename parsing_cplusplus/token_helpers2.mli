val is_space               : Parser_cplusplus.token -> bool
val is_comment_or_space    : Parser_cplusplus.token -> bool
val is_just_comment        : Parser_cplusplus.token -> bool
val is_comment             : Parser_cplusplus.token -> bool
val is_real_comment        : Parser_cplusplus.token -> bool
val is_fake_comment        : Parser_cplusplus.token -> bool
val is_not_comment         : Parser_cplusplus.token -> bool

val is_cpp_instruction     : Parser_cplusplus.token -> bool
val is_eof                 : Parser_cplusplus.token -> bool
val is_statement           : Parser_cplusplus.token -> bool
val is_start_of_something  : Parser_cplusplus.token -> bool
val is_binary_operator     : Parser_cplusplus.token -> bool
val is_stuff_taking_parenthized : Parser_cplusplus.token -> bool
val is_static_cast_like    : Parser_cplusplus.token -> bool
val is_basic_type          : Parser_cplusplus.token -> bool
val is_binary_operator_except_star     : Parser_cplusplus.token -> bool
val is_struct_like_keyword : Parser_cplusplus.token -> bool
val is_classkey_keyword : Parser_cplusplus.token -> bool

val is_cplusplus_keyword : Parser_cplusplus.token -> bool
val is_really_cplusplus_keyword : Parser_cplusplus.token -> bool
val is_maybenot_cplusplus_keyword : Parser_cplusplus.token -> bool

val is_opar : Parser_cplusplus.token -> bool
val is_cpar : Parser_cplusplus.token -> bool
val is_obrace : Parser_cplusplus.token -> bool
val is_cbrace : Parser_cplusplus.token -> bool

val info_of_tok : Parser_cplusplus.token -> Ast_cplusplus.info

val visitor_info_of_tok : 
  (Ast_cplusplus.info -> Ast_cplusplus.info) -> Parser_cplusplus.token -> Parser_cplusplus.token

val linecol_of_tok : Parser_cplusplus.token -> int * int
val col_of_tok     : Parser_cplusplus.token -> int
val line_of_tok    : Parser_cplusplus.token -> int
val pos_of_tok     : Parser_cplusplus.token -> int
val str_of_tok     : Parser_cplusplus.token -> string
val file_of_tok    : Parser_cplusplus.token -> Common.filename
val pinfo_of_tok   : Parser_cplusplus.token -> Ast_cplusplus.parse_info

(* val mark_of_tok    : Parser_cplusplus.token -> Ast_c.mark_token *)
val is_origin : Parser_cplusplus.token -> bool
val is_expanded : Parser_cplusplus.token -> bool
val is_fake : Parser_cplusplus.token -> bool
val is_abstract : Parser_cplusplus.token -> bool
