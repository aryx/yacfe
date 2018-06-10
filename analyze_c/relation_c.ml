open Common

open Ast_c 

(*****************************************************************************)
(*  *)
(*****************************************************************************)

(* 
 * history: 
 *  - started doing stuff for eurosys'06 in patchparse/. 
 *  - extended it for eurosys'08 for coccinelle/ in coccinelle/extra/ 
 *    and use it to discover some .c .h mapping and generate some crazy graphs.
 *  - extended it for aComment, to feed information to some 
 *    inter-procedural analysis.
 * 
 * todo: add info on scope in ast itself ? next to each ident then can 
 *  say to what this ident refers too. As in DrScheme GUI, can see 
 *  arrows between def and use. To be accurate it means that we must
 *  handle well the scope, and also .h files by using cpp_ast_c.ml.
 *
 *)
 

let regexp_macro =  Str.regexp
    "^[A-Z_][A-Z_0-9]*$" 

let callees_of_ast top =
  let res = ref [] in

  let bigf = { Visitor_c.default_visitor_c with

    (* --------- and now looking for use --------- *)
    Visitor_c.kexpr = (fun (k,bigf) x -> 
      match Ast_c.unwrap_expr x with
      
      | FunCall (((Ident f, typ), ii), args) -> 
          if f ==~ regexp_macro
          then ()
          else 
            Common.push2 f res
          ;
          args +> List.iter (fun (x,ii) -> 
            Visitor_c.vk_argument bigf x
          );
      | Ident s -> 
          (*
            if s ==~ regexp_macro
            then add e.macros s
            else add e.variables s
          *)
          ()

      | _ -> k x
    );
  } in
  Visitor_c.vk_toplevel bigf top;
  !res


