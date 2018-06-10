
type pinfo_place_mapping = 
  (Common.parse_info, Place_code.place) Hashtbl.t

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

val comments_of_program : 
  Parse_java.program2 -> 
    (Common.parse_info * Place_code.place list) list * 
    Parser_java.token list *
    pinfo_place_mapping *
    Statistics_code.entities_stat
