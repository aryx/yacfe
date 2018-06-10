open Common

module C = Ast_java
module G = Ast_generic

module TH = Token_helpers_java
module TC = Parser_java

module Lib = Lib_parsing_java

open Statistics_code (* for the fields *)

module M = Place_code

module Ast_c = Ast_java
module Visitor_c = Visitor_java

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

(*****************************************************************************)
(* Helpers packing *)
(*****************************************************************************)

(* copy paste with other langage annotater *)
let pack_comments toks = 
  let rec aux xs = 
    match xs with
    | [] -> []
    | TC.TComment i1::TC.TCommentSpace i2::TC.TComment i3::xs -> 


        (* Simple heuristic, same col, just line after, and just space
         * between. Suppose that i1 is just one line long, but I think
         * it's better to not agglomerate otherwise.
         * 
         * Note that must first call recursively and compared on already
         * built from bottom comment, otherwise if build from top then
         * the line number will not be good.
         *)
        if C.col_of_info i1 = C.col_of_info i3 && 
           C.line_of_info i1 = (C.line_of_info i3 - 1)
           
        then
          (match aux (TC.TComment i3::xs) with
          | TC.TComment i3'::xs' -> 
              
              let total_str = 
                C.str_of_info i1 ^ C.str_of_info i2 ^ C.str_of_info i3' in
              let i1' = C.rewrap_str total_str i1 in
              (TC.TComment i1'::xs')
          | _ -> raise Impossible
          )
        else 
          TC.TComment i1::TC.TCommentSpace i2::
          aux (TC.TComment i3::xs)
    | x::xs -> 
        x::aux xs
  in
  aux toks
        


(*****************************************************************************)
(* Helpers first pass *)
(*****************************************************************************)

let same_line xs = 
  xs +> List.filter (fun x -> x.Ast_c.mpos = 0)
let line_before ?(nblines=1)  xs = 
  xs +> List.filter (fun x -> 
    x.Ast_c.mpos < 0 && x.Ast_c.mpos >= -nblines
  )

let line_before_same_col ?(nblines=1) ?(checkcol=true) info xs = 
  let col1 = Ast_c.col_of_info info in
  xs +> List.filter (fun x -> 
    let col2 = x.Ast_c.minfo.Common.column in
    x.Ast_c.mpos < 0 && x.Ast_c.mpos >= -nblines && 
      (if checkcol then col1 = col2 else true)
  )


let is_comment_or_space = function
  | TC.TComment _ -> true
  | TC.TCommentSpace _ -> true
  | _ -> false



let is_origin_token ii = true


let pinfo_of_comment = function
  | TC.TComment ii -> Ast_c.parse_info_of_info ii
  | _ -> failwith "not a comment token !!!"

let pinfo_of_ii x = Ast_c.parse_info_of_info x


(*****************************************************************************)
(* First pass, compute comments around *)
(*****************************************************************************)

(* The pinfo corresponds to a C token. *)
type pinfo_around_mapping = 
  (Common.parse_info, Ast_java.comments_around) Hashtbl.t


let (compute_comments_around : Parser_java.token list -> pinfo_around_mapping)= 
 fun toks ->

   (* Common.exclude_but_keep_attached gather all comments before a
    * token and then associates to this token those comments. Note that
    * if reverse the list of tokens then this function can also be used
    * to gather all the comments after a token :) 
    * 
    *)

   (* before phase *)
   let toks_with_before = 
     Common.exclude_but_keep_attached is_comment_or_space
       toks 
   in

  (* after phase. trick: reverse the tokens and reuse previous func *)
   let toks_with_after = List.rev 
     (Common.exclude_but_keep_attached is_comment_or_space
         (List.rev toks)) 
   in
  
  (* merge *)

   assert(List.length toks_with_after = List.length toks_with_before);
   let h = Hashtbl.create 1001 in

   Common.zip toks_with_before toks_with_after 
   +> List.iter (fun ((t1, before), (t2, after)) -> 
       assert(t1 = t2);

       (* now dont want the space, or other stuff, just the comment *)
       let before = List.filter TH.is_just_comment before in
       let after  = List.filter TH.is_just_comment after in
       
       let line1 = TH.line_of_tok t1 in

       let before' = before +> List.map (fun t2 -> 
         let line2 = 
           TH.line_of_tok t2 + 
             (Common.nblines (TH.str_of_tok t2) - 1)
         in
         {C.mpos = line2 - line1; 
          minfo = pinfo_of_comment t2;
          (*cppbetween = false;*)
         }
       ) in
       let after' = after +> List.rev +> List.map (fun t2 -> 
         let line2 = TH.line_of_tok t2 in
         {C.mpos = line2 - line1; 
          minfo = pinfo_of_comment t2;
          (*cppbetween = false;*)
         }
       ) in
       let infot1 = Ast_c.parse_info_of_info (TH.info_of_tok t1) in

       Hashtbl.add h  infot1 
         ({C.mbefore = before'; C.mafter = after'});
     );
  h


(* ---------------------------------------------------------------------- *)
(* a comment is attached to something often because it is either placed
 * before the something, or on the same line after the something, hence
 * those functions which should serve most uses.
 * 
 * effects: the following functions modifies the h passed in parameter.
 *)
let verbose_annotater_error = ref false
let min_ii_line_before ?nblines ?checkcol (haround, h) kind_place ii =
  let ii = ii +> List.filter is_origin_token in
  if null ii 
  then 
    if !verbose_annotater_error
    then pr2 "PB: null ii"
    else ()
  else 
       

  let (_max,min) = Lib.max_min_ii_by_pos ii in

  let around = Hashtbl.find haround (pinfo_of_ii min) in
  around.C.mbefore
  +> line_before_same_col ?nblines ?checkcol min
  +> List.iter (fun x -> 
    Hashtbl.add h x.C.minfo kind_place
  )

let max_ii_same_line_after (haround, h) kind_place ii =
  let ii = ii +> List.filter is_origin_token in

  if null ii 
  then 
    if !verbose_annotater_error
    then pr2 "PB: null ii"
    else ()
  else 

  let (max,_min) = Lib.max_min_ii_by_pos ii in
  let around = Hashtbl.find haround (pinfo_of_ii max) in
  around.C.mafter
  +> same_line
  +> List.iter (fun x -> 
    Hashtbl.add h x.C.minfo kind_place
  )

(* to use only for small stuff, for one line entity such as
 * variable declaration *)
let minmax_ii_attached ?nblines ?checkcol hboth kind_place ii =
  begin
    min_ii_line_before     ?nblines ?checkcol hboth kind_place ii;
    max_ii_same_line_after                    hboth kind_place ii;
  end



(* for the InStructUnknown, InFuncUnknown, etc, just set to the tag if the
 * ii has no place yet attached to it *)
let unassigned_place ?(try_not_found=false) (haround, hplaces) kind_place ii = 
  let ii = ii +> List.filter is_origin_token in

  if null ii 
  then 
    if !verbose_annotater_error
    then pr2 "PB: null ii"
    else ()
  else 

    ii +> List.iter (fun info -> 
      let do_x () = 
      let around = Hashtbl.find haround (pinfo_of_ii info) in
      (* opti? lots of redundant work here because the after here is 
       * the before of next token *)
      (around.C.mbefore ++ around.C.mafter)+> List.iter (fun comment_and_pos -> 
        let minfo = comment_and_pos.C.minfo in
        if null (Hashtbl.find_all hplaces minfo)
        then Hashtbl.add hplaces minfo kind_place
      )
      in
      if try_not_found 
      then (try do_x () with Not_found -> ())
      else do_x ()
    )


(*****************************************************************************)
(* Second pass  *)
(*****************************************************************************)

(*****************************************************************************)
(* Place computation *)
(*****************************************************************************)

(* for the first one the pinfo corresponds to a C token, for the second one
 * the pinfo corresponds to a comment token
 *)
(*type pinfo_around_mapping = (Common.parse_info, C.comments_around) Hashtbl.t*)
type pinfo_place_mapping = 
  (Common.parse_info, Place_code.place) Hashtbl.t

(* ---------------------------------------------------------------------- *)
(* now comment_place contains also some info on the entities the comments
 * is attached to, such as the name of the variable, function, macro. *)

type xinfo_places = {
  false_positive_header: Ast_c.info list;
}


let (compute_places : xinfo_places -> Ast_java.program -> pinfo_around_mapping -> 
                      pinfo_place_mapping * Statistics_code.entities_stat)
 = fun xinfo asts haround -> 

  let (h: pinfo_place_mapping) = Hashtbl.create 1001 in
  let hboth = (haround, h) in (* shortcut *)

  let z = Statistics_code.default_entities_stat () in

  let bigf_phase1 = { Visitor_c.default_visitor_s with

    Visitor_c.kprogram_s = (fun (k, bigf) cu -> 
      let res = k cu in

      cu.C.package +> Common.do_option (fun (name, ii) -> 
        ii +> min_ii_line_before ~nblines:2 hboth 
          (M.Header);
      );
      res

    );

    Visitor_c.kdecl_s = (fun (k, bigf) decl -> 

      let decl' = k decl in

      (match decl with
      | C.Class cd -> 
          let ii = Lib.ii_of_modifiers cd.C.cl_mods in
          ii +> min_ii_line_before ~nblines:2 hboth
            (M.Class "class_todo");

          decl'

      | C.Interface inter -> 
          let ii = Lib.ii_of_modifiers inter.C.if_mods in
          ii +> min_ii_line_before ~nblines:2 hboth
            (M.Class "interface_todo");

          decl'

      | C.Field fld -> 
          let ii = Lib.ii_of_modifiers fld.C.f_var.C.v_mods in
          ii +> min_ii_line_before ~nblines:2 hboth
            (M.Field "field_todo");

          decl'

      | C.Method md -> 
          let ii = Lib.ii_of_modifiers md.C.m_var.C.v_mods in
          ii +> min_ii_line_before ~nblines:2 hboth
            (M.Method "method_todo");

          decl'


      | C.InstanceInit ist -> 
          decl'
      | C.StaticInit sti -> 
          decl'

      | C.Constructor md -> 
          let ii = Lib.ii_of_modifiers md.C.m_var.C.v_mods in
          ii +> min_ii_line_before ~nblines:2 hboth
            (M.Constructor "ctor_todo");

          decl'
      )
    );

    Visitor_c.ktype_s = (fun (k, bigf) ft -> 
      k ft
    );
    Visitor_c.kstatement_s = (fun (k, bigf) stm -> 
      match stm with

      | C.Empty, ii -> 
          k stm

      | C.Block (xs), ii -> 
          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Compound);
          ii +> max_ii_same_line_after hboth (M.EndCompound);
 
          k stm

      | (C.While (e, st)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Loop);
          k stm

      | (C.Do (st, e)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

          (*let (i1,i2,i3,i4,i5,iifakend) = tuple_of_list6 ii in*)
          (* certainement le commentaire est apres le ');' *)
          ii +> max_ii_same_line_after hboth (M.Statement M.Loop);
          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Loop);

          k stm

      | (C.For (smts, eopt, stmts, st)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Loop);
          
          k stm

      | (C.If (e, st1, st2)), ii -> 
          z.nb_if <- z.nb_if + 1;

          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.If);
          k stm
(*
          (match ii with 
          | i1::i2::i3::is -> 
              (* accrocher a ')' *)
              [i3] +> max_ii_same_line_after hboth (M.Statement M.If);

              (match st1 with 
              | C.Compound st, ii -> 
                  let (i1, i2) = Common.tuple_of_list2 ii in
                  [i1] +> max_ii_same_line_after hboth (M.Statement M.If);
              | _ -> ()
              );

              (match (is) with
              | []  -> ()
              | [iifakend] -> ()
              | [i4;iifakend] -> 
                  z.nb_else <- z.nb_else + 1;

                  (* accrocher au else *)
                  [i4] +> max_ii_same_line_after hboth (M.Else);

                  (match st2 with
                  | C.Compound st, ii -> 
                      let (i1, i2) = Common.tuple_of_list2 ii in
                      [i1] +> max_ii_same_line_after hboth (M.Else);
                  | _ -> ()
                  )

              | x -> raise Impossible
              )
          | x -> raise Impossible
          )

*)

      | (C.Switch (e, st)), ii -> 
          z.nb_if <- z.nb_if + 1;

          ii +> min_ii_line_before hboth (M.Statement M.If);
          k stm


      | (C.Continue idopt), ii  -> 
          z.nb_continue <- z.nb_continue + 1;

          ii +> minmax_ii_attached hboth (M.Statement (M.Continue));
          k stm

      | (C.Break idopt), ii  -> 
          z.nb_break <- z.nb_break + 1;

          ii +> minmax_ii_attached hboth (M.Statement (M.Break));
          k stm
          

      | (C.Return eopt), ii -> 
          z.nb_return <- z.nb_return + 1;
          
          ii +> minmax_ii_attached hboth (M.Statement M.Return);
          k stm

      | (C.Label  (s, st)), ii -> 
          z.nb_label <- z.nb_label + 1;

          ii +> minmax_ii_attached ~nblines:2 ~checkcol:false
            hboth (M.Statement (M.Label "label_todo"));
          k stm

(*
      | C.Labeled (C.Case  (e, st)), ii 
      | C.Labeled (C.CaseRange  (e, _, st)), ii -> 
          z.nb_case <- z.nb_case + 1;

          (* todo? look in e and check if find ident ? *)
          let entity = None in
          ii +> min_ii_line_before hboth (M.Statement (M.Case entity));
          ii +> max_ii_same_line_after hboth (M.Statement (M.Case entity));

      | C.Labeled (C.Default  (st)), ii -> 
          z.nb_case <- z.nb_case + 1;

          let entity = Some "default" in 
          ii +> min_ii_line_before hboth (M.Statement (M.Case entity));
*)


      | (C.Expr _), ii -> 
          k stm

(*
      | C.ExprStatement opte, ii -> 
          let allii = Lib.ii_of_stmt st in

          (match opte with
          | None -> ()
          | Some e -> 
              (* TODO factorize *)

              let ((unwrap_e, typ), ii) = e in
              (match unwrap_e with

              | C.FunCall (e, _args) -> 
                  (match e with
                  | ((C.Ident f, _typ), _ii) -> 
                      z.nb_simple_funcall <- z.nb_simple_funcall + 1;

                      allii +> minmax_ii_attached hboth 
                        (M.Statement (M.SimpleFunCall f))

                  | (C.RecordPtAccess (e, s), _typ), _ii 
                  | (C.RecordAccess (e, s), _typ), _ii 
                      ->
                      z.nb_method_call <- z.nb_method_call + 1;

                      allii +> minmax_ii_attached hboth 
                        (M.Statement (M.MethodCall s))
                  | _ -> ()
                  )

              (* todo *)

              | C.Postfix (e, op)
              | C.Infix (e, op) -> 
                  allii +> minmax_ii_attached hboth
                    (M.Statement (M.SimpleIncDec (gen_fixop_conv op)))


              | C.Assignment (e1, C.OpAssign op, e2) ->
                  z.nb_simple_assign <- z.nb_simple_assign + 1;

                  allii +> minmax_ii_attached ~nblines:2 hboth
                    (M.Statement (M.SimpleAssignOp (gen_arithop_conv op)))
               
              | C.Assignment (((C.Ident var, _typ), _ii), C.SimpleAssign, e) ->
                  (* var ^ " = ... ;" *)

                  let ((unwrap_e, typ), ii) = e in
                  (match unwrap_e with
                  | C.FunCall (((C.Ident f, _typ), _ii), _args) -> 
                      z.nb_simple_funcall <- z.nb_simple_funcall + 1;

                      allii +> minmax_ii_attached hboth 
                        (M.Statement (M.SimpleFunCall f))
                  | _ -> 
                      allii +> minmax_ii_attached hboth 
                        (M.Statement (M.SimpleAssign var))
                      
                  )
                  

              | C.Assignment 
                  (((C.RecordAccess (((C.Ident var, _typ), _ii), field),_typ2),
                   _ii2),
                  C.SimpleAssign, 
                  e) -> 
                  z.nb_simple_field_assign <- z.nb_simple_field_assign + 1;

                  (* var ^ "." ^ field ^ " = ... ;" *)

                  allii +> minmax_ii_attached hboth 
                        (M.Statement (M.SimpleFieldAssign field))

              | C.Assignment 
                  (((C.RecordPtAccess (((C.Ident var, _typ), _ii), field),_typ2),
                   _ii2),
                  C.SimpleAssign, 
                  e) -> 
                  z.nb_simple_field_assign <- z.nb_simple_field_assign + 1;

                  allii +> minmax_ii_attached hboth 
                        (M.Statement (M.SimpleFieldAssign field))

                   
              | _ -> ()
              )
          )

      | _ -> ()
    );
*)

      | (C.Sync (_, _)), ii -> 
          ii +> minmax_ii_attached hboth (M.Statement M.Sync);
          k stm

      | (C.Throw _), ii -> 
          ii +> minmax_ii_attached hboth (M.Statement M.Throw);

          k stm
      | (C.Try (_, _, _)), ii -> 
          ii +> minmax_ii_attached hboth (M.Statement M.Try);

          k stm
          

      | (C.LocalClass lc), ii -> 
          k stm

      | (C.LocalVar fld), ii -> 

          let ii = Lib.ii_of_modifiers fld.C.f_var.C.v_mods in
          ii +> min_ii_line_before ~nblines:2 hboth
            (M.Variable "localvar_todo");
          k stm

      | (C.Assert (e1, e2opt)), ii -> 
          k stm


    );

  }
  in

  (* try to better categorize the Unknown by at least detecting if 
   * the comment is inside a complex C entity such as a structure, enum,
   * initializer or function. So we have at least less Unknown *)
  let bigf_phase2 = { Visitor_c.default_visitor_s with
    Visitor_c.kstatement_s = (fun (k, bigf) st -> 
      k st
    );

    Visitor_c.kdecl_s = (fun (k, bigf) decl -> 
      let decl' = k decl in

      (match decl with
      | C.Class cd -> 
          let allii = Lib.ii_of_decls cd.C.cl_body in
          allii +> unassigned_place hboth (M.InClassUnknown);

          decl'

      | C.Interface inter -> 
          let allii = Lib.ii_of_decls inter.C.if_body in
          allii +> unassigned_place hboth (M.InInterfaceUnknown);

          decl'


      | C.Field fld -> 
          decl' 

      | C.Method md -> 
          let allii = Lib.ii_of_stmt md.C.m_body in
          allii +> unassigned_place hboth (M.InFuncUnknown);

          decl'

      | C.InstanceInit ist -> 
          decl'
      | C.StaticInit sti -> 
          decl'

      | C.Constructor md -> 
          let allii = Lib.ii_of_stmt md.C.m_body in
          allii +> unassigned_place hboth (M.InCtorDtorUnknown);

          decl'
      )
    );

    Visitor_c.kini_s = (fun (k, bigf) ini -> 
      let ini' = k ini in
      (match C.unwrap ini with
      | C.ArrayInit xs -> 
          z.nb_initializer <- z.nb_initializer + 1;

          let allii = Lib.ii_of_ini (C.ArrayInit xs, []) in
          allii +> unassigned_place hboth (M.InInitializerUnknown);
          
          ini'
      | _ -> ini'
      )
    );

  }
  in

  (match asts with
  | Left asts -> 
      (* phase 1 *)
      asts +> Visitor_c.compilation_unit bigf_phase1 +> ignore;

      (* phase 2, the remaining comments to put in InXxxUnknown *)
      asts +> Visitor_c.compilation_unit bigf_phase2 +> ignore;
  | Right ii -> 
          ii +> unassigned_place ~try_not_found:true hboth (M.UnknownParsePB);
  );

  h, z


(*****************************************************************************)
(* Main entry *)
(*****************************************************************************)

let (comments_of_program2: 
      Parse_java.program2 -> 
      (Common.parse_info * Place_code.place list) list * 
      Parser_java.token list *
      pinfo_place_mapping *
      Statistics_code.entities_stat
     ) =
 fun xs -> 

  let alltoks = xs +> (fun (ast, (toks)) -> toks) in
  let allasts = xs +> (fun (ast, (toks)) -> ast) in

  let packed_toks = pack_comments alltoks in

  let false_positive_header = [] (* Todo *) in
  let aux = { 
    false_positive_header = false_positive_header;
  } in


  let haround = compute_comments_around packed_toks in
  let (hplaces, entities_stat) = compute_places aux allasts haround  in

(*  
  header_comments +> List.iter (fun tinfo -> 
    Hashtbl.add hplaces (Ast_c.parse_info_of_info tinfo) (M.Header)
  );
*)

  packed_toks +> Common.map_filter (fun tok -> 
      match tok with
      | TC.TComment ii -> 

          let places = 
            match Hashtbl.find_all hplaces (Ast_java.parse_info_of_info ii) with
            | [] -> [M.Unknown]
            | places -> places
          in
          Some (Ast_java.parse_info_of_info ii, places)
      | _ -> None
    )
   , 
   packed_toks, 
   hplaces,
   entities_stat



let comments_of_program a =
  Common.profile_code "Comments java extract" (fun () -> comments_of_program2 a)
