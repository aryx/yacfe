open Common

module C = Ast_c
module G = Ast_generic

module TH = Token_helpers
module TC = Parser_c

module Lib = Lib_parsing_c

open Statistics_code (* for the fields *)

module M = Place_code

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)
let gen_fixop_conv = function
  | C.Dec  -> G.Dec
  | C.Inc  -> G.Dec

let gen_arithop_conv = function
  | C.Plus -> G.Plus 
  | C.Minus -> G.Minus 
  | C.Mul -> G.Mul 
  | C.Div -> G.Div 
  | C.Mod-> G.Mod
  
  | C.DecLeft -> G.DecLeft 
  | C.DecRight -> G.DecRight 
  
  | C.And -> G.And 
  | C.Or -> G.Or 
  | C.Xor-> G.Xor

let gen_logicalop_conv = function
  | C.Inf -> G.Inf 
  | C.Sup -> G.Sup 
  | C.InfEq -> G.InfEq 
  | C.SupEq -> G.SupEq 
  
  | C.Eq -> G.Eq 
  | C.NotEq -> G.NotEq 
  
  | C.AndLog -> G.AndLog 
  | C.OrLog-> G.OrLog

let gen_binaryop_conv = function
  | C.Arith arithOp  -> G.Arith (gen_arithop_conv arithOp)
  | C.Logical logicalOp -> G.Logical (gen_logicalop_conv logicalOp)


(*****************************************************************************)
(* Helper packing *)
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

(* works on Ast_c.comment_and_relative_pos type *)

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
    

(* The "stuff" part is to deal with cpp expansions. In 
 *      /* comment */
 *      AP_DECLARE(void) ap_show_modules(void);
 * the comment is attached to AP_DECLARE but AP_DECLARE then disappears,
 * and we will not get the chance to make the connexion between the comment
 * and void (or ap_show_modules). So to try to attach the comment 
 * to something "real", we do not attach it to an expanded Macro,
 * and so here we must filter those tokens. That means later the comment
 * may be wrongly attached to for instance ap_show_modules, but 
 * our comment_place() extract function later is aware of this and so will look
 * for a comment not only attached to its return type but also attached
 * to the function name (and will not check if same column).
 *)
let is_comment_or_space_or_stuff = function
  | TC.TComment _ -> true
  | TC.TCommentSpace _ -> true

  | TC.TCommentCpp (Ast_c.CppMacro,_)  -> true
  | TC.TCommentCpp (Ast_c.CppOther,_)  -> true

  | tok -> 
      (match TH.pinfo_of_tok tok with
      | Ast_c.ExpandedTok _ -> true

      | Ast_c.OriginTok _ -> false
      | Ast_c.FakeTok _ -> false

      | Ast_c.AbstractLineTok _ -> raise Impossible
      )




let is_origin_token ii = 
  match Ast_c.pinfo_of_info ii with
  | Ast_c.OriginTok _ -> true
  | _ -> false



let pinfo_of_comment = function
  | TC.TComment ii -> Ast_c.parse_info_of_info ii
  | _ -> failwith "not a comment token !!!"

let pinfo_of_ii x = Ast_c.parse_info_of_info x

(*****************************************************************************)
(* First pass, compute comments around *)
(*****************************************************************************)

(* The pinfo corresponds to a C token. *)
type pinfo_around_mapping = 
  (Common.parse_info, Ast_c.comments_around) Hashtbl.t


let (compute_comments_around : Parser_c.token list -> pinfo_around_mapping) = 
 fun toks ->

   (* Common.exclude_but_keep_attached gather all comments before a
    * token and then associates to this token those comments. Note that
    * if reverse the list of tokens then this function can also be used
    * to gather all the comments after a token :) 
    * 
    * todo? attach comments both to the "stuff" and the cleaned_stuff, both
    * to the expanded_token and the function ?
    *)

   (* before phase *)
   let toks_with_before = 
     Common.exclude_but_keep_attached is_comment_or_space_or_stuff 
       toks 
   in

  (* after phase. trick: reverse the tokens and reuse previous func *)
   let toks_with_after = List.rev 
     (Common.exclude_but_keep_attached is_comment_or_space_or_stuff 
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

(* was in of ccomment/comments/comments_extraction.ml *)


(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

let s_of_inc_file inc_file = 
  match inc_file with
  | C.Local xs -> xs +> Common.join "/"
  | C.NonLocal xs -> xs +> Common.join "/"
  | C.Wierd s -> s

let fieldname_of_fieldkind fieldkind = 
  match C.unwrap fieldkind with
  | C.Simple (sopt, ft) -> sopt
  | C.BitField (sopt, ft, expr) -> sopt



(*****************************************************************************)
(* Place computation *)
(*****************************************************************************)

(* for the first one the pinfo corresponds to a C token, for the second one
 * the pinfo corresponds to a comment token
 *)
(*type pinfo_around_mapping = (Common.parse_info, C.comments_around) Hashtbl.t*)
type pinfo_place_mapping = (Common.parse_info, Place_code.place) Hashtbl.t

(* ---------------------------------------------------------------------- *)
(* now comment_place contains also some info on the entities the comments
 * is attached to, such as the name of the variable, function, macro. *)

type xinfo_places = {
  false_positive_header: Ast_c.info list;
}

let (compute_places : xinfo_places -> Ast_c.program -> pinfo_around_mapping -> 
                      pinfo_place_mapping * Statistics_code.entities_stat)
 = fun xinfo asts haround -> 

  let (h: pinfo_place_mapping) = Hashtbl.create 1001 in
  let hboth = (haround, h) in (* shortcut *)

  let z = Statistics_code.default_entities_stat () in

  let bigf_phase1 = { Visitor_c.default_visitor_c with

    Visitor_c.ktoplevel = (fun (k, bigf) top -> 
      k top;
      match top with

      (* handled by kdecl *)
      | C.Declaration decl -> 
          ()

      | C.Definition def -> 
          z.nb_function <- z.nb_function + 1;

          let (s, (returnt, (paramst, (b, iib))), sto, statxs), ii = def in
          let iit = Lib.ii_of_type returnt in
          (iit ++ ii) +> min_ii_line_before ~nblines:2 ~checkcol:false
            hboth (M.Function s);


          paramst +> List.iter (fun (param, iicomma) -> 
            z.nb_parameter <- z.nb_parameter + 1;

            if not (null iicomma)
            then iicomma +> max_ii_same_line_after hboth M.Parameter;

            let ii = Lib.ii_of_param param in
            ii +> max_ii_same_line_after hboth M.Parameter;
          );

      | C.Include ((s, ii),pos) -> 
          z.nb_include <- z.nb_include + 1;

          let (iinclude, iipath) = Common.tuple_of_list2 ii in
          if not (List.mem iinclude xinfo.false_positive_header)
          then 
            [iinclude;iipath] +> minmax_ii_attached hboth 
              (M.Include (s_of_inc_file s))

      | C.Define ((s,ii), (defkind, defval)) -> 
          let (idefine,iident,ieol) = Common.tuple_of_list3 ii in
          
          (match defkind with
          | C.DefineVar -> 
              z.nb_define_var <- z.nb_define_var + 1;

              if not (List.mem idefine xinfo.false_positive_header)
              then
              ii +> min_ii_line_before ~nblines:2 hboth (M.MacroVariable s)
          | C.DefineFunc _ -> 
              z.nb_define_func <- z.nb_define_func + 1;

              if not (List.mem idefine xinfo.false_positive_header)
              then
              ii +> min_ii_line_before ~nblines:2 hboth (M.MacroFunction s)
          );
          (match defkind, defval with
          | C.DefineVar, C.DefineExpr e -> 
              (Lib.ii_of_expr e) +> max_ii_same_line_after hboth 
                (M.MacroVariable s)
          | C.DefineFunc _, C.DefineExpr e -> 
              (Lib.ii_of_expr e) +> max_ii_same_line_after hboth 
                (M.MacroFunction s)
          | _ -> ()
          );

      (* todo? for DEFINE_SPINLOCK maybe we would like to extract the name
       *  of the lock, that is insides 'args'
       *)
      | C.MacroTop (s, args, ii) -> 
          z.nb_variable <- z.nb_variable + 1;
          
          ii +> min_ii_line_before hboth (M.Variable s)

      | C.EmptyDef ii -> 
          ()
      (* for those ii I set the try_not_found cos in ii there as space info,
       * comments_info which are not in hboth as they were filterd in the
       * first phase by a is_comment_or_space_or_stuff.
       * 
       *)
      | C.NotParsedCorrectly ii -> 
          ii +> unassigned_place ~try_not_found:true hboth (M.UnknownParsePB);
          

      | C.FinalDef info -> ()
    );

    Visitor_c.kdecl = (fun (k,bigf) decl -> 
      k decl;
      match decl with
      | C.DeclList (xs,ii1) -> 
          (match xs with
          | [] -> raise Impossible
          | (x,ii2)::xs -> 
              let (var, returnType, (storage,inline)) = x in
              (match var with
              | Some ((s, optini),_ii) -> 
                  if storage <> C.StoTypedef
                  then 
                    let ii = Lib.ii_of_decl decl in
                    if null xs 
                    then 
                      (match Ast_c.unwrap_typeC returnType with
                      | C.FunctionType(_) -> 
                          z.nb_prototype <- z.nb_prototype + 1;

                          ii +> minmax_ii_attached hboth (M.Prototype s)
                      | _ -> 
                          z.nb_variable <- z.nb_variable + 1;

                          ii +> minmax_ii_attached hboth (M.Variable s)
                      )
                    else begin 
                      z.nb_variable <- z.nb_variable + 1 + List.length xs;

                      ii +> minmax_ii_attached hboth (M.Variable "multidecl");
                    end
                  else 
                    let ii = Lib.ii_of_decl decl in
                    ii +> minmax_ii_attached hboth (M.Type)

              | None -> ()
              )
          )

      | C.MacroDecl ((s, args),_ii) -> 
          z.nb_variable <- z.nb_variable + 1;

          let ii = Lib.ii_of_decl decl in
          ii +> minmax_ii_attached hboth (M.Variable s)
    );

    Visitor_c.ktype = (fun (k, bigf) ft -> 
      k ft;
      let (q, t) = ft in
      let (_unwrap_q, _iiq) = q in
      let (unwrap_t, iit) = t in
      match unwrap_t with
      | C.StructUnion (su, sopt, fields) -> 
          z.nb_struct <- z.nb_struct + 1;

          (match sopt, iit with
          | Some s, iit -> 
              iit +> min_ii_line_before ~nblines:2 hboth (M.Struct s);
          | None, [i1;i2;i3] -> 
              iit +> min_ii_line_before hboth (M.Struct "anonymous");
              [i1] +> max_ii_same_line_after hboth (M.StructIdent);
          | _ -> ()
          );

          fields +> List.iter (fun (xfield, iipttvirg) -> 

            (match xfield with 
            | C.FieldDeclList onefield_multivars -> 
                z.nb_field <- z.nb_field + List.length onefield_multivars;

                (match onefield_multivars with
                | [] -> pr2 "possible?"
                | [(x, ii)] -> 

                    fieldname_of_fieldkind x +> Common.do_option (fun s -> 
                      iipttvirg +> max_ii_same_line_after hboth (M.Field s);
                      let ii = Lib.ii_of_struct_field onefield_multivars in
                      ii +> min_ii_line_before hboth (M.Field s);
                    )
                | xs -> (* TODO?*)
                    ()
                )
            | C.EmptyField -> ()
            );
          );

      | C.Enum (sopt, fields) -> 
          z.nb_enum <- z.nb_enum + 1;

          sopt +> Common.do_option (fun s -> 
            iit +> min_ii_line_before hboth (M.Enum s);
          );
          fields +> List.iter (fun (((s, eopt),ii_s_eq), iicomma) -> 
            z.nb_enum_value <- z.nb_enum_value + 1;

            if not (null iicomma)
            then iicomma +> max_ii_same_line_after hboth (M.EnumValue s);
            ii_s_eq +> minmax_ii_attached hboth (M.EnumValue s)
          );

      | _ -> ()
    );

    Visitor_c.kstatement = (fun (k, bigf) st -> 
      k st;
      match st with 

      | C.Compound (xs), ii -> 
          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Compound);
          ii +> max_ii_same_line_after hboth (M.EndCompound);
 
      | C.Iteration  (C.While (e, st)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Loop);
      | C.Iteration  (C.DoWhile (st, e)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

          let (i1,i2,i3,i4,i5,iifakend) = tuple_of_list6 ii in
          (* certainement le commentaire est apres le ');' *)
          [i5] +> max_ii_same_line_after hboth (M.Statement M.Loop);
          [i1] +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Loop);

      | C.Iteration  (C.For ((e1opt,i1), (e2opt,i2), (e3opt,i3), st)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Loop);
      | C.Iteration  (C.MacroIteration (s,es,st)), ii ->
          z.nb_loop <- z.nb_loop + 1;

          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.Loop);

      | C.Selection  (C.If (e, st1, st2)), ii -> 
          z.nb_if <- z.nb_if + 1;

          ii +> min_ii_line_before ~nblines:2 hboth (M.Statement M.If);
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
      | C.Selection  (C.Switch (e, st)), ii -> 
          z.nb_if <- z.nb_if + 1;

          ii +> min_ii_line_before hboth (M.Statement M.If);


      | C.Jump (C.Goto s), ii  -> 
          z.nb_goto <- z.nb_goto + 1;

          ii +> minmax_ii_attached hboth (M.Statement (M.Goto s))
      | C.Jump (C.Continue), ii  -> 
          z.nb_continue <- z.nb_continue + 1;

          ii +> minmax_ii_attached hboth (M.Statement (M.Continue))
      | C.Jump (C.Break), ii  -> 
          z.nb_break <- z.nb_break + 1;

          ii +> minmax_ii_attached hboth (M.Statement (M.Break))
          

      | C.Jump (C.Return), ii  
      | C.Jump (C.ReturnExpr _), ii -> 
          z.nb_return <- z.nb_return + 1;
          
          ii +> minmax_ii_attached hboth (M.Statement M.Return)


      | C.Labeled (C.Label  (s, st)), ii -> 
          z.nb_label <- z.nb_label + 1;

          ii +> minmax_ii_attached ~nblines:2 ~checkcol:false
            hboth (M.Statement (M.Label s))

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
    Visitor_c.kexpr = (fun (k,bigf) e -> 
      let ((exp, typ), ii) = e in
      k e;
      match exp with
      | C.Binary (e1, op, e2) -> 
          ii +> max_ii_same_line_after hboth 
            (M.Expression (M.Binary (gen_binaryop_conv op)))

      | _ -> ()
    );


  }
  in

  (* try to better categorize the Unknown by at least detecting if 
   * the comment is inside a complex C entity such as a structure, enum,
   * initializer or function. So we have at least less Unknown *)

  let bigf_phase2 = { Visitor_c.default_visitor_c with

    Visitor_c.ktoplevel = (fun (k, bigf) top -> 
      k top;
      match top with
      | C.Definition def -> 
          let ((s, (returnt, (paramst, (b, iib))), sto, statxs), ii) = def in
              (* is::iifunc1::iifunc2::i1::i2::ifakestart::isto *)
          let allii = Lib.ii_of_stmt (C.Compound statxs, []) in
          allii +> unassigned_place hboth (M.InFuncUnknown);
          
      | _ -> ()
    );

    Visitor_c.ktype = (fun (k, bigf) ft -> 
      k ft;
      let (q, t) = ft in
      let (_unwrap_q, _iiq) = q in
      let (unwrap_t, iit) = t in
      match unwrap_t with
      | C.StructUnion (su, sopt, fields) -> 
          let allii = Lib.ii_of_struct_fields fields in
          allii +> unassigned_place hboth (M.InStructUnknown);

      | C.Enum (sopt, fields) -> 
          
          let iicommaopt = 
            (match sopt, iit with
            | (Some s, i1::i2::i3::i4::iicommaopt) -> 
                iicommaopt
            | (None, i1::i2::i3::iicommaopt) -> 
                iicommaopt
            | x -> raise Impossible
            ) 
          in
          let fake = C.nQ, (C.Enum (sopt, fields), iicommaopt) in
          let allii = Lib.ii_of_type fake in
          allii +> unassigned_place hboth (M.InEnumUnknown);
          
      | _ -> ()
    );

    Visitor_c.kdecl = (fun (k,bigf) decl -> 
      k decl;
      match decl with
      | C.DeclList (xs,ii1) -> 
          xs +> List.iter (fun (x, ii2) -> 
            let (var, returnType, (storage,inline)) = x in
            (match var with
            | Some ((s, optini),_ii) -> 
                optini +> Common.do_option (fun ini -> 
                  match ini with
                  | C.InitList xs, i1::i2::iicommaopt -> 
                      z.nb_initializer <- z.nb_initializer + 1;

                      let allii = Lib.ii_of_ini (C.InitList xs, iicommaopt) in
                      allii +> unassigned_place hboth (M.InInitializerUnknown);
                  | _ -> ()
                );
            | None -> ()
            )
          );
      | _ -> ()
    );

  }
  in


  (* phase 1 *)
  asts +> List.iter (Visitor_c.vk_toplevel bigf_phase1);

  (* phase 2, the remaining comments to put in InXxxUnknown *)
  asts +> List.iter (Visitor_c.vk_toplevel bigf_phase2);

  h, z
   

(*****************************************************************************)
(* Main entry *)
(*****************************************************************************)

let (comments_of_program2: ?do_packing:bool ->
      Parse_c.program2 -> 
      (Common.parse_info * Place_code.place list) list * 
      Parser_c.token list *
      pinfo_place_mapping *
      Statistics_code.entities_stat
     ) =
 fun ?(do_packing = false) xs -> 

  let alltoks = xs +> List.map (fun (ast, (s, toks)) -> toks) +> List.concat in
  let allasts = xs +> List.map (fun (ast, (s, toks)) -> ast) in

  let packed_toks = 
    if do_packing 
    then pack_comments alltoks 
    else alltoks
  in

  let first_toks = Common.take_safe 30 packed_toks in
  let first_toks = Common.exclude TH.is_space first_toks in

  let false_positive_header, header_comments = 
    match first_toks with
    (* /* comment */ #include *)
    | TC.TComment ii_comment::xs

    (* ifndef XX_H #define XX_H /* comment */ #include *)
    | TC.TCommentCpp (Ast_c.CppDirective, _)::
      TC.TDefine(_)::TC.TIdentDefine (_)::TC.TDefEOL (_)::
      TC.TComment ii_comment::xs
      ->
        (* todo? check if header .h file ? 
         * check if big comment ? if nblines > 4 ?
         *)

        (match xs with
        (* TC.TInclude exist only at lex time, then parse_c transforms it *)
        | TC.TIncludeStart (ii,_)::_ 
        | TC.TDefine (ii)::_
            ->
            [ii], [ii_comment]
        | _ -> [], [ii_comment]
        )
    | _ -> [], []
  in
  let aux = { 
    false_positive_header = false_positive_header;
  } in

  let haround = compute_comments_around packed_toks in
  let (hplaces, entities_stat) = compute_places aux allasts haround  in

  header_comments +> List.iter (fun tinfo -> 
    Hashtbl.add hplaces (Ast_c.parse_info_of_info tinfo) (M.Header)
  );
  
  packed_toks +> Common.map_filter (fun tok -> 
      match tok with
      | TC.TComment ii -> 

          let places = 
            match Hashtbl.find_all hplaces (Ast_c.parse_info_of_info ii) with
            | [] -> [M.Unknown]
            | places -> places
          in
          Some (pinfo_of_ii ii, places)
      | _ -> None
    
  ), 
   packed_toks, 
   hplaces,
   entities_stat


let comments_of_program ?do_packing a =
  Common.profile_code "Comments extract" (fun () -> 
    comments_of_program2 ?do_packing a)




(*****************************************************************************)
(*****************************************************************************)

(* Do via side effects. Fill in the comment information that was put
 * to [] during parsing.
 *)
let annotate_program xs =
  raise Todo
