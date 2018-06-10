
(* For the first one the pinfo corresponds to a C token, for the second one
 * the pinfo corresponds to the comment token.
 *)
type pinfo_around_mapping = 
  (Common.parse_info, Ast_cplusplus.comments_around) Hashtbl.t
type pinfo_place_mapping = 
  (Common.parse_info, Place_code.place) Hashtbl.t


val compute_comments_around : Parser_cplusplus.token list -> pinfo_around_mapping




val min_ii_line_before:
  ?nblines:int -> ?checkcol:bool -> 
  pinfo_around_mapping * (Common.parse_info, 'a) Hashtbl.t -> 
  'a -> Ast_cplusplus.info list -> unit

val max_ii_same_line_after:
  pinfo_around_mapping * (Common.parse_info, 'a) Hashtbl.t -> 
  'a -> Ast_cplusplus.info list -> unit

val minmax_ii_attached:
  ?nblines:int -> ?checkcol:bool -> 
  pinfo_around_mapping * (Common.parse_info, 'a) Hashtbl.t -> 
  'a -> Ast_cplusplus.info list -> unit

val unassigned_place:
  ?try_not_found:bool -> 
  pinfo_around_mapping * (Common.parse_info, 'a) Hashtbl.t -> 
  'a -> Ast_cplusplus.info list -> unit





(* Do via side effects. Fill in the comment information that was put
 * to [] during parsing.
 *)
val annotate_program : 
  Parse_cplusplus.program2 -> unit


(* Return a place list because comments can be attached to different entities:
 *
 * - we may say that a comment both refer to a function call, or
 *   to an affectaction as in x = foobar(); /* a comment on x or foobar ? */
 * 
 * - our algorithm sometimes cant disambiguate. Usually a comment is placed
 *   before an entity, so because we can have only one entity, there should
 *   be only one possible place, but sometimes a comment is placed after in
 *   which case we may have ambiguities. really ?
 *)

val comments_of_program : ?do_packing:bool -> 
  Parse_cplusplus.program2 -> 
    (Common.parse_info * Place_code.place list) list * 
    Parser_cplusplus.token list * (* packed tokens *)
    pinfo_place_mapping *
    Statistics_code.entities_stat
