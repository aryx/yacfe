open Common 


module C = Ast_cplusplus
module Lib = Lib_parsing_cplusplus
module Ast_c = Ast_cplusplus
module Visitor_c = Visitor_cplusplus

(* was first done for CComment *)

open Statistics_code

module Stat = Parsing_stat2

(*****************************************************************************)
(* Compute stat, clone code with comment_annotater *)
(*****************************************************************************)

(* update: also do some side effect on Parsing_stat.nXXX variables 
 * could do it in parser_c.mly but then pollute the grammar file so
 * better do it here.
*)

let (statistics_of_program : Ast_c.program -> entities_stat) =
 fun asts -> 

  let z = default_entities_stat () in

  let bigf_phase1 = { Visitor_c.default_visitor_c with

    Visitor_c.ktoplevel = (fun (k, bigf) top -> 
      k top;
      match top with
      | C.TopDecl decl -> ()

      | C.CppTop _ -> ()
      | C.IfdefTop _ -> 
          incr Stat.nIfdefTop;

      (* todo? for DEFINE_SPINLOCK maybe we would like to extract the name
       *  of the lock, that is insides 'args'
       *)
      | C.MacroTop (s, args, ii) -> 
          z.nb_variable <- z.nb_variable + 1;

          incr Stat.nMacroTopDecl; 
          
      | C.EmptyDef ii -> 
          incr Stat.nMacroTopDecl; 
          ()

      | C.NotParsedCorrectly ii -> 
          incr Stat.nNotParsedCorrectly;
          ()
      | C.FinalDef info -> ()
    );


    Visitor_c.kcppdirective = (fun (k,bigf) top -> 
      k top;

      match top with
      | C.Include ((s, ii),pos) -> 
          z.nb_include <- z.nb_include + 1;

          incr Stat.nIncludeGrammar;


      | C.Define ((s,ii), (defkind, defval)) -> 
          let (_idefine,_iident,_ieol) = Common.tuple_of_list3 ii in
          
          (match defkind with
          | C.DefineVar -> 
              z.nb_define_var <- z.nb_define_var + 1;

          | C.DefineFunc _ -> 
              z.nb_define_func <- z.nb_define_func + 1;
          );

          (match defval with
          | C.DefineExpr e -> incr Stat.nDefineExpr; 
          | C.DefineStmt s -> incr Stat.nDefineStmt; 
          | C.DefineType t -> incr Stat.nDefineOther; 
          | C.DefineDoWhileZero swrap -> incr Stat.nDefineOther; 
          | C.DefineFunction def -> incr Stat.nDefineOther; 
          | C.DefineText swrap -> incr Stat.nDefineOther; 
          | C.DefineEmpty -> incr Stat.nDefineOther; 
          | C.DefineTodo -> incr Stat.nDefineOther; 
          | C.DefineInit _ -> incr Stat.nDefineInit;
          )
      | C.Undef (s, ii) -> incr Stat.nUndef;
      | C.PragmaAndCo (ii) -> incr Stat.nPragmaAndCo;
    );


    Visitor_c.kfdef = (fun (k, bigf) def -> 
      z.nb_function <- z.nb_function + 1;
      let (s, (returnt, (paramst, (b, iib))), sto, statxs), ii = def in

      paramst +> List.iter (fun (param, iicomma) -> 
        z.nb_parameter <- z.nb_parameter + 1;
      );
    );

    Visitor_c.kvdecl = (fun (k,bigf) decl -> 
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
                    let _ii = Lib.ii_of_vdecl decl in
                    if null xs 
                    then 
                      (match Ast_c.unwrap_typeC returnType with
                      | C.FunctionType(_) -> 
                          z.nb_prototype <- z.nb_prototype + 1;

                      | _ -> 
                          z.nb_variable <- z.nb_variable + 1;

                      )
                    else begin 
                      z.nb_variable <- z.nb_variable + 1 + List.length xs;

                    end
                  else 
                    ()
              | None -> ()
              )
          )

      | C.MacroDecl ((s, args),_ii) -> 
          z.nb_variable <- z.nb_variable + 1;

    );

    Visitor_c.ktype = (fun (k, bigf) ft -> 
      k ft;
      let (q, t) = ft in
      let (_unwrap_q, _iiq) = q in
      let (unwrap_t, iit) = t in
      match unwrap_t with

      | C.StructUnion class_def -> 
          let (_su, _sopt, _bopt, _members),_ii = class_def in

            z.nb_struct <- z.nb_struct + 1;

(* TODO
  -          fields +> List.iter (fun (xfield, iipttvirg) -> 
  -
  -            (match xfield with 
  -            | C.FieldDeclList onefield_multivars -> 
  -                z.nb_field <- z.nb_field + List.length onefield_multivars;
  -
  -                (match onefield_multivars with
  -                | [] -> pr2 "possible?"
  -                | [(x, ii)] -> 
  -                    ()
  -                | xs -> (* TODO?*)
  -                    ()
  -                )
  -            | C.EmptyField -> ()
  -            );
  -          );
*)



      | C.Enum (sopt, fields) -> 
          z.nb_enum <- z.nb_enum + 1;

          fields +> List.iter (fun (((s, eopt),ii_s_eq), iicomma) -> 
            z.nb_enum_value <- z.nb_enum_value + 1;

          );

      | _ -> ()
    );

    Visitor_c.kini = (fun (k, bigf) ini -> 
      k ini;
      
    );

    Visitor_c.kstatement = (fun (k, bigf) st -> 
      k st;
      match st with 

      | C.Compound (xs), ii -> 
          ()
      | C.Iteration  (C.While (e, st)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

      | C.Iteration  (C.DoWhile (st, e)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

      | C.Iteration  (C.For ((e1opt,i1), (e2opt,i2), (e3opt,i3), st)), ii -> 
          z.nb_loop <- z.nb_loop + 1;

      | C.Iteration  (C.MacroIteration (s,es,st)), ii ->
          z.nb_loop <- z.nb_loop + 1;

          incr Stat.nIteratorGrammar;

      | C.Selection  (C.If (e, st1, st2)), ii -> 
          z.nb_if <- z.nb_if + 1;

          (match ii with 
          | i1::i2::i3::is -> 

              (match (is) with
              | []  -> ()
              | [iifakend] -> ()
              | [i4;iifakend] -> 
                  z.nb_else <- z.nb_else + 1;

              | x -> raise Impossible
              )
          | x -> raise Impossible
          )
      | C.Selection  (C.Switch (e, st)), ii -> 
          z.nb_if <- z.nb_if + 1;



      | C.Jump (C.Goto s), ii  -> 
          z.nb_goto <- z.nb_goto + 1;

      | C.Jump (C.Continue), ii  -> 
          z.nb_continue <- z.nb_continue + 1;

      | C.Jump (C.Break), ii  -> 
          z.nb_break <- z.nb_break + 1;


      | C.Jump (C.Return), ii  
      | C.Jump (C.ReturnExpr _), ii -> 
          z.nb_return <- z.nb_return + 1;
          

      | C.Labeled (C.Label  (s, st)), ii -> 
          z.nb_label <- z.nb_label + 1;

      | C.Labeled (C.Case  (e, st)), ii -> 
          z.nb_case <- z.nb_case + 1;

      | C.Labeled (C.CaseRange  (e, _, st)), ii -> 
          z.nb_case <- z.nb_case + 1;
          incr Stat.nGccCaseRange;

      | C.Labeled (C.Default  (st)), ii -> 
          z.nb_case <- z.nb_case + 1;



      | C.ExprStatement opte, ii -> 
          let _allii = Lib.ii_of_stmt st in

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

                  | (C.RecordPtAccess (e, s), _typ), _ii 
                  | (C.RecordAccess (e, s), _typ), _ii 
                      ->
                      z.nb_method_call <- z.nb_method_call + 1;

                  | _ -> ()
                  )

              (* todo *)

              | C.Postfix (e, op)
              | C.Infix (e, op) -> 
                  ()

              | C.Assignment (e1, C.OpAssign op, e2) ->
                  z.nb_simple_assign <- z.nb_simple_assign + 1;

              
              | C.Assignment (((C.Ident var, _typ), _ii), C.SimpleAssign, e) ->
                  (* var ^ " = ... ;" *)

                  let ((unwrap_e, typ), ii) = e in
                  (match unwrap_e with
                  | C.FunCall (((C.Ident f, _typ), _ii), _args) -> 
                      z.nb_simple_funcall <- z.nb_simple_funcall + 1;

                  | _ -> 
                      ()
                  )
                  

              | C.Assignment 
                  (((C.RecordAccess (((C.Ident var, _typ), _ii), field),_typ2),
                   _ii2),
                  C.SimpleAssign, 
                  e) -> 
                  z.nb_simple_field_assign <- z.nb_simple_field_assign + 1;

                  (* var ^ "." ^ field ^ " = ... ;" *)


              | C.Assignment 
                  (((C.RecordPtAccess (((C.Ident var, _typ), _ii), field),_typ2),
                   _ii2),
                  C.SimpleAssign, 
                  e) -> 
                  z.nb_simple_field_assign <- z.nb_simple_field_assign + 1;

                   
              | _ -> ()
              )
          )
      | _ -> ()
    );
(*
      | C.Asm _,ii -> 
          incr Stat.nGccAsm;
      | C.NestedFunc _,ii -> 
          incr Stat.nGccNestedFunc;
*)


    Visitor_c.kexpr = (fun (k,bigf) e -> 
      let ((exp, typ), ii) = e in
      k e;
      match exp with
      | C.Binary (e1, op, e2) -> 
          ()

(*
      | C.StatementExpr _ -> 
          incr Stat.nGccStmtExpr;
      | C.Constructor _ -> 
          incr Stat.nGccConstructor;
*)

      | _ -> ()
    );

  }
  in
  asts +> List.iter (Visitor_c.vk_toplevel bigf_phase1);
  z

