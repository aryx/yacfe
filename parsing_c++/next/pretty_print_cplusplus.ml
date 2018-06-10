(* Copyright (C) 2002-2008 Yoann Padioleau
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License (GPL)
 * version 2 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * file license.txt for more details.
 *)
open Common

open Ast_cplusplus
module Ast_c = Ast_cplusplus
module Flag_parsing_c = Flag_parsing_cplusplus

type pr_elem_func = Ast_c.info -> unit
type pr_space_func = unit -> unit

(*****************************************************************************)

(* This module is used by unparse_c, but because unparse_c have also
 * the list of tokens, pretty_print_c could be useless in the futur
 * (except that the ast_c have some fake tokens not present in the list
 * of tokens so it's still useful). But this module is also useful to
 * unparse C when you don't have the ordered list of tokens separately,
 * or tokens without position information, for instance when you want
 * to pretty print some piece of C that was generated, or some
 * abstract-lined piece of code, etc. *)

let rec pp_expression_gen pr_elem pr_space = 
  (* subtil: dont try to shorten the def of pp_statement by omitting e,
     otherwise get infinite funcall and huge memory consumption *)
  let pp_statement e = pp_statement_gen pr_elem pr_space e in
  let rec pp_expression = fun ((exp, typ), ii) -> 
    (match exp, ii with
    | Ident (c),         [i]     -> pr_elem i
    (* only a MultiString can have multiple ii *)
    | Constant (MultiString), is     -> is +> List.iter pr_elem
    | Constant (c),         [i]     -> pr_elem i 
    | FunCall  (e, es),     [i1;i2] -> 
        pp_expression e; pr_elem i1; 
        es +> List.iter (fun (e, opt) -> 
          assert (List.length opt <= 1); (* opt must be a comma? *)
          opt +> List.iter (function x -> pr_elem x; pr_space());
          pp_argument_gen pr_elem pr_space e;
        );
        pr_elem i2;
        
    | CondExpr (e1, e2, e3),    [i1;i2]    -> 
        pp_expression e1; pr_space(); pr_elem i1; pr_space();
	do_option (function x -> pp_expression x; pr_space()) e2; pr_elem i2; 
        pp_expression e3
    | Sequence (e1, e2),          [i]  -> 
        pp_expression e1; pr_elem i; pr_space(); pp_expression e2
    | Assignment (e1, op, e2),    [i]  -> 
        pp_expression e1; pr_space(); pr_elem i; pr_space(); pp_expression e2
          
    | Postfix  (e, op),    [i] -> pp_expression e; pr_elem i;
    | Infix    (e, op),    [i] -> pr_elem i; pp_expression e;
    | Unary    (e, op),    [i] -> pr_elem i; pp_expression e
    | Binary   (e1, op, e2),    [i] -> 
        pp_expression e1; pr_space(); pr_elem i; pr_space(); pp_expression e2
          
    | ArrayAccess    (e1, e2),   [i1;i2] -> 
        pp_expression e1; pr_elem i1; pp_expression e2; pr_elem i2
    | RecordAccess   (e, s),     [i1;i2] -> 
        pp_expression e; pr_elem i1; pr_elem i2
    | RecordPtAccess (e, s),     [i1;i2] -> 
        pp_expression e; pr_elem i1; pr_elem i2

    | SizeOfExpr  (e),     [i] -> pr_elem i; pp_expression e
    | SizeOfType  (t),     [i1;i2;i3] -> 
        pr_elem i1; pr_elem i2; pp_type_gen pr_elem pr_space t; 
        pr_elem i3
    | Cast    (t, e),      [i1;i2] -> 
        pr_elem i1; pp_type_gen pr_elem pr_space t; pr_elem i2; 
        pp_expression e

    | StatementExpr (statxs, [ii1;ii2]),  [i1;i2] -> 
        pr_elem i1;
        pr_elem ii1;
        statxs +> List.iter pp_statement;
        pr_elem ii2;
        pr_elem i2;
    | Constructor (t, xs), lp::rp::i1::i2::iicommaopt -> 
        pr_elem lp;
        pp_type_gen pr_elem pr_space t;
        pr_elem rp;
        pr_elem i1;
        xs +> List.iter (fun (x, ii) -> 
          assert (List.length ii <= 1);
          ii +> List.iter (function x -> pr_elem x; pr_space());
          pp_init_gen pr_elem pr_space x
        );
        iicommaopt +> List.iter pr_elem;
        pr_elem i2;

        

    | ParenExpr (e), [i1;i2] -> pr_elem i1; pp_expression e; pr_elem i2;

    | (Ident (_) | Constant _ | FunCall (_,_) | CondExpr (_,_,_) 
        | Sequence (_,_)
        | Assignment (_,_,_) 
        | Postfix (_,_) | Infix (_,_) | Unary (_,_) | Binary (_,_,_)
        | ArrayAccess (_,_) | RecordAccess (_,_) | RecordPtAccess (_,_)
        | SizeOfExpr (_) | SizeOfType (_) | Cast (_,_) 
        | StatementExpr (_) | Constructor _
        | ParenExpr (_)
      ),_ -> raise Impossible
    );
    if !Flag_parsing_c.pretty_print_type_info
    then begin
      pr_elem (Ast_c.fakeInfo() +> Ast_c.rewrap_str "/*");
      !typ +> Common.do_option (fun x -> pp_type_gen pr_elem pr_space x);
      pr_elem (Ast_c.fakeInfo() +> Ast_c.rewrap_str "*/");
    end

  in
  pp_expression


and pp_argument_gen pr_elem pr_space argument = 
  let rec pp_action = function 
    | (ActMisc ii) -> ii +> List.iter pr_elem
  in
  match argument with
  | Left e -> pp_expression_gen pr_elem pr_space e
  | Right wierd -> 
      (match wierd with
      | ArgType param -> pp_param_gen pr_elem pr_space param
      | ArgAction action -> pp_action action
      )





(* ---------------------- *)
and pp_statement_gen pr_elem pr_space = 
  let pp_expression e = pp_expression_gen pr_elem pr_space e in
  let rec pp_statement = function
    | Labeled (Label (s, st)), [i1;i2] -> 
        pr_elem i1; pr_elem i2; pp_statement st
    | Labeled (Case  (e, st)), [i1;i2] -> 
        pr_elem i1; pp_expression e; pr_elem i2; pp_statement st
    | Labeled (CaseRange  (e, e2, st)), [i1;i2;i3] -> 
        pr_elem i1; pp_expression e; pr_elem i2; pp_expression e2; pr_elem i3;
        pp_statement st
    | Labeled (Default st), [i1;i2] -> pr_elem i1; pr_elem i2; pp_statement st
    | Compound statxs, [i1;i2] -> 
        pr_elem i1; statxs +> List.iter pp_statement; pr_elem i2;
        
    | ExprStatement (None), [i] -> pr_elem i;
    | ExprStatement (None), [] -> ()
    | ExprStatement (Some e), [i] -> pp_expression e; pr_elem i
        (* the last ExprStatement of a for does not have a trailing
           ';' hence the [] for ii *)
    | ExprStatement (Some e), [] -> pp_expression e; 
    | Selection  (If (e, st1, st2)), i1::i2::i3::is -> 
        pr_elem i1; pr_elem i2; pp_expression e; pr_elem i3; pp_statement st1; 
        (match (st2, is) with
        | ((ExprStatement None, []), [])  -> ()
        | ((ExprStatement None, []), [iifakend])  -> pr_elem iifakend
        | st2, [i4;iifakend] -> pr_elem i4; pp_statement st2; pr_elem iifakend
        | x -> raise Impossible
        )
    | Selection  (Switch (e, st)), [i1;i2;i3;iifakend] -> 
        pr_elem i1; pr_elem i2; pp_expression e; pr_elem i3; pp_statement st;
        pr_elem iifakend
    | Iteration  (While (e, st)), [i1;i2;i3;iifakend] -> 
        pr_elem i1; pr_elem i2; pp_expression e; pr_elem i3; pp_statement st;
        pr_elem iifakend
    | Iteration  (DoWhile (st, e)), [i1;i2;i3;i4;i5;iifakend] -> 
        pr_elem i1; pp_statement st; pr_elem i2; pr_elem i3; pp_expression e; 
        pr_elem i4; pr_elem i5;
        pr_elem iifakend
          
          
    | Iteration  (For ((e1opt,il1),(e2opt,il2),(e3opt, il3),st)),
        [i1;i2;i3;iifakend] ->

        pr_elem i1;
        pr_elem i2;
        pp_statement (ExprStatement e1opt, il1);
        pp_statement (ExprStatement e2opt, il2);
        assert (null il3);
        pp_statement (ExprStatement e3opt, il3);
        pr_elem i3;
        pp_statement st;
        pr_elem iifakend

    | Iteration  (MacroIteration (s,es,st)), [i1;i2;i3;iifakend] ->
        pr_elem i1;
        pr_elem i2;

        es +> List.iter (fun (e, opt) -> 
          assert (List.length opt <= 1);
          opt +> List.iter pr_elem;
          pp_argument_gen pr_elem pr_space e;
        );

        pr_elem i3;
        pp_statement st;
        pr_elem iifakend
          
    | Jump (Goto s), [i1;i2;i3]               -> 
        pr_elem i1; pr_space(); pr_elem i2; pr_elem i3;
    | Jump ((Continue|Break|Return)), [i1;i2] -> pr_elem i1; pr_elem i2;
    | Jump (ReturnExpr e), [i1;i2] ->
	pr_elem i1; pr_space(); pp_expression e; pr_elem i2
    | Jump (GotoComputed e), [i1;i2;i3] -> 
        pr_elem i1; pr_elem i2; pp_expression e; pr_elem i3

    | Decl decl, [] -> pp_decl_gen pr_elem pr_space decl 
    | Asm asmbody, ii -> 
        (match ii with
        | [iasm;iopar;icpar;iptvirg] -> 
            pr_elem iasm; pr_elem iopar;
            pp_asmbody_gen pr_elem pr_space asmbody;
            pr_elem icpar; pr_elem iptvirg
        | [iasm;ivolatile;iopar;icpar;iptvirg] -> 
            pr_elem iasm; pr_elem ivolatile; pr_elem iopar; 
            pp_asmbody_gen pr_elem pr_space asmbody;
            pr_elem icpar; pr_elem iptvirg
        | _ -> raise Impossible
        )

    | NestedFunc def, ii -> 
        assert (null ii);
        pp_def_gen pr_elem pr_space def
    | MacroStmt, ii -> 
        ii +> List.iter pr_elem ;

    | Selection  (Ifdef (st1s, st2s)), i1::i2::is -> 
        pr_elem i1; 
        st1s +> List.iter pp_statement; 
        (match (st2s, is) with
        | [], [iifakend] -> pr_elem i2; pr_elem iifakend
        | x::xs, [i3;iifakend] -> 
            pr_elem i2;
            st2s +> List.iter pp_statement; 
            pr_elem i3;
            pr_elem iifakend
              
        | _ -> raise Impossible
        )
    | ( Labeled (Label (_,_)) | Labeled (Case  (_,_)) 
        | Labeled (CaseRange  (_,_,_)) | Labeled (Default _)
        | Compound _ | ExprStatement _ 
        | Selection  (If (_, _, _)) | Selection  (Switch (_, _))
        | Iteration  (While (_, _)) | Iteration  (DoWhile (_, _)) 
        | Iteration  (For ((_,_), (_,_), (_, _), _))
        | Iteration  (MacroIteration (_,_,_))
        | Jump (Goto _) | Jump ((Continue|Break|Return)) | Jump (ReturnExpr _)
        | Jump (GotoComputed _)
        | Decl _ | Selection (Ifdef (_,_))
      ), _ -> raise Impossible

  in
  pp_statement


and pp_asmbody_gen pr_elem pr_space (string_list, colon_list) = 
  string_list +> List.iter pr_elem ;
  colon_list +> List.iter (fun (Colon xs, ii) -> 
    ii +> List.iter pr_elem;
    xs +> List.iter (fun (x,iicomma) -> 
      assert ((List.length iicomma) <= 1);
      iicomma +> List.iter (function x -> pr_elem x; pr_space());
      (match x with 
      | ColonMisc, ii -> ii +> List.iter pr_elem;
      | ColonExpr e, [istring;iopar;icpar] -> 
          pr_elem istring;
          pr_elem iopar;
          pp_expression_gen pr_elem pr_space e;
          pr_elem icpar
      | _ -> raise Impossible
      )
    ))
  

(* ---------------------- *)
and (pp_type_with_ident_gen: 
        pr_elem_func -> pr_space_func -> 
      (string * info) option -> (storage * il) option -> fullType -> unit) = 
  fun pr_elem pr_space ->
    fun ident sto ((qu, iiqu), (ty, iity)) -> 
      pp_base_type_gen pr_elem pr_space ((qu, iiqu), (ty, iity))  sto;
      pp_type_with_ident_rest_gen pr_elem pr_space ident
	((qu, iiqu), (ty, iity))


and (pp_base_type_gen: 
       pr_elem_func -> pr_space_func -> fullType ->
	 (storage * il) option -> unit) = 
  fun pr_elem pr_space -> 
    let pp_expression e = pp_expression_gen pr_elem pr_space e in

    let rec pp_base_type = 
      fun (qu, (ty, iity)) sto -> 
        let get_sto sto = 
          match sto with 
          | None -> [] | Some (s, iis) -> (*assert (List.length iis = 1);*) iis
        in
        let print_sto_qu (sto, (qu, iiqu)) = 
          let all_ii = get_sto sto ++ iiqu in
          all_ii 
          +> List.sort Ast_c.compare_pos
          +> List.iter pr_elem;
          
        in
        let print_sto_qu_ty (sto, (qu, iiqu), iity) = 
          let all_ii = get_sto sto ++ iiqu ++ iity in
          let all_ii2 = all_ii +> List.sort Ast_c.compare_pos in

          if all_ii <> all_ii2 
          then begin 
            (* TODO in fact for pointer, the qualifier is after the type 
             * cf -test strangeorder
             *)
            pr2 "STRANGEORDER"; 
            all_ii2 +> List.iter pr_elem 
          end
          else all_ii2 +> List.iter pr_elem
        in

        match ty, iity with
        | (Pointer t, [i])                           -> pp_base_type t sto
        | (ParenType t, _)                           -> pp_base_type t sto
        | (Array (eopt, t), [i1;i2])                 -> pp_base_type t sto
        | (FunctionType (returnt, paramst), [i1;i2]) -> 
            pp_base_type returnt sto


        | (StructUnion (su, sopt, fields),iis) -> 
            print_sto_qu (sto, qu);

            (match sopt,iis with
            | Some s , [i1;i2;i3;i4] -> 
                pr_elem i1; pr_elem i2; pr_elem i3; 
            | None, [i1;i2;i3] -> 
                pr_elem i1; pr_elem i2; 
            | x -> raise Impossible
            );

            fields +> List.iter 
              (fun (xfield, iipttvirg) -> 

                match xfield with 
                | FieldDeclList onefield_multivars -> 
                 (match onefield_multivars with
                 | x::xs -> 
                  (* handling the first var. Special case, with the
                     first var, we print the whole type *)

                  (match x with
                  | (Simple (sopt, typ), iis), iivirg -> 
                      (* first var cant have a preceding ',' *)
                      assert (List.length iivirg = 0); 
                      let identinfo = 
                        (match sopt, iis with 
                        None,_ -> None 
                        | (Some s, [iis]) -> Some (s, iis) 
                        | x -> raise Impossible) 
                      in
                      pp_type_with_ident_gen pr_elem pr_space
			identinfo None typ;

                  | (BitField (sopt, typ, expr), ii), iivirg -> 
                      (* first var cant have a preceding ',' *)
                      assert (List.length iivirg = 0); 
                      (match sopt, ii with
                      | (None , [idot]) -> 
                          pp_type_gen pr_elem pr_space typ;
                          pr_elem idot;
                          pp_expression expr
                      | (Some s, [is;idot]) -> 
                          pp_type_with_ident_gen 
                            pr_elem pr_space (Some (s, is)) None typ;
                          pr_elem idot;
                          pp_expression expr
                      | x -> raise Impossible
                      )
                        
                  );
                  
                  (* for other vars *)
                  xs +> List.iter (function
                  | (Simple (sopt, typ), iis), iivirg -> 
                      iivirg +> List.iter pr_elem;
                      let identinfo = 
                        (match sopt, iis with 
                        | None,_ -> None 
                        | (Some s, [iis]) -> Some (s, iis) 
                        | x -> raise Impossible) 
                      in
                      pp_type_with_ident_rest_gen pr_elem pr_space
			identinfo typ;

                  | (BitField (sopt, typ, expr), ii), iivirg -> 
                      iivirg +> List.iter pr_elem;
                      (match sopt, ii with
                      | (Some s, [is;idot]) -> 
                          pp_type_with_ident_rest_gen 
                            pr_elem pr_space (Some (s, is)) typ;
                          pr_elem idot;
                          pp_expression expr
                      | x -> raise Impossible
                      );
                      
                  );

                  assert (List.length iipttvirg = 1);
                  iipttvirg +> List.iter pr_elem;
              | x -> raise Impossible
              ) 
            | EmptyField -> ()
            );

            (match sopt,iis with
            | Some s , [i1;i2;i3;i4] -> pr_elem i4
            | None, [i1;i2;i3] ->       pr_elem i3; 
            | x -> raise Impossible
            );



        | (Enum  (sopt, enumt), iis) -> 
            print_sto_qu (sto, qu);

            (match sopt, iis with
            | (Some s, ([i1;i2;i3;i4]|[i1;i2;i3;i4;_])) -> 
                pr_elem i1; pr_elem i2; pr_elem i3;
            | (None, ([i1;i2;i3]|[i1;i2;i3;_])) -> 
                pr_elem i1; pr_elem i2
            | x -> raise Impossible
            );

            enumt +> List.iter (fun (((s, eopt),ii_s_eq), iicomma) -> 
              assert (List.length iicomma <= 1);
              iicomma +> List.iter (function x -> pr_elem x; pr_space());
              (match eopt, ii_s_eq with
              | None, [is] -> pr_elem is;
              | Some e, [is;ieq] -> pr_elem is; pr_elem ieq; pp_expression e
              | _ -> raise Impossible
              )
                
            );

            (match sopt, iis with
            | (Some s, [i1;i2;i3;i4]) ->    pr_elem i4
            | (Some s, [i1;i2;i3;i4;i5]) -> 
                pr_elem i5; pr_elem i4 (* trailing comma *)
            | (None, [i1;i2;i3]) ->         pr_elem i3
            | (None, [i1;i2;i3;i4]) ->      
                pr_elem i4; pr_elem i3 (* trailing comma *)


            | x -> raise Impossible
            );


        | (BaseType _, iis) -> 
            print_sto_qu_ty (sto, qu, iis);

        | (StructUnionName (s, structunion), iis) -> 
            assert (List.length iis = 2);
            print_sto_qu_ty (sto, qu, iis);

        | (EnumName  s, iis) -> 
            assert (List.length iis = 2);
            print_sto_qu_ty (sto, qu, iis);

        | (TypeName (s,_typ), iis) -> 
            assert (List.length iis = 1);  
            print_sto_qu_ty (sto, qu, iis);

        | (TypeOfExpr (e), iis) -> 
            print_sto_qu (sto, qu);
            (match iis with
            | [itypeof;iopar;icpar] -> 
                pr_elem itypeof; pr_elem iopar;
                pp_expression_gen pr_elem pr_space e;
                pr_elem icpar;
            | _ -> raise Impossible
            )

        | (TypeOfType (t), iis) -> 
            print_sto_qu (sto, qu);
            (match iis with
            | [itypeof;iopar;icpar] -> 
                pr_elem itypeof; pr_elem iopar;
                pp_type_gen pr_elem pr_space t; 
                pr_elem icpar;
            | _ -> raise Impossible
            )


        | x -> raise Impossible
    in
    pp_base_type


(* used because of DeclList, in    int i,*j[23];  we dont print anymore the 
   int before *j *) 
and (pp_type_with_ident_rest_gen: 
        pr_elem_func -> pr_space_func ->
	  (string * info) option -> fullType -> unit) = 
  fun pr_elem pr_space -> 
    fun ident (((qu, iiqu), (ty, iity)) as fullt) -> 
      let print_ident ident = do_option (fun (s, iis) -> pr_elem iis) ident
      in

      match ty, iity with
      (* the work is to do in base_type !! *)
      | (BaseType _, iis)                       -> print_ident ident
      | (Enum  (sopt, enumt), iis)              -> print_ident ident
      | (StructUnion (_, sopt, fields),iis)     -> print_ident ident
      | (StructUnionName (s, structunion), iis) -> print_ident ident
      | (EnumName  s, iis)                      -> print_ident ident
      | (TypeName (s,_typ), iis)                -> print_ident ident
      | (TypeOfExpr (e), iis)                   -> print_ident ident
      | (TypeOfType (e), iis)                   -> print_ident ident



      | (Pointer t, [i]) ->  
          (* subtil:  void ( *done)(int i)   is a Pointer 
             (FunctionType (return=void, params=int i) *)
          (*WRONG I THINK, use left & right function *)
          (* bug: pp_type_with_ident_rest None t;      print_ident ident *)
          pr_elem i; 
          iiqu +> List.iter pr_elem; (* le const est forcement apres le '*' *)
          pp_type_with_ident_rest_gen pr_elem pr_space ident t;

      (* ugly special case ... todo? maybe sufficient in practice *)       
      | (ParenType (q1, (Pointer (q2, (FunctionType t, ii3))   , 
                        [ipointer])  ), [i1;i2]) ->  
          pp_type_left_gen pr_elem pr_space (q2, (FunctionType t, ii3));
          pr_elem i1;
          pr_elem ipointer;
          print_ident ident;
          pr_elem i2;
          pp_type_right_gen pr_elem pr_space (q2, (FunctionType t, ii3));

      (* another ugly special case *)
      | (ParenType 
          (q1, (Array (eopt,
            (q2, (Pointer 
              (q3, (FunctionType t, iifunc)), 
                 [ipointer]))),
               [iarray1;iarray2])), [i1;i2]) -> 
          pp_type_left_gen pr_elem pr_space (q3, (FunctionType t, iifunc));
          pr_elem i1;
          pr_elem ipointer;
          print_ident ident;
          pr_elem iarray1;
          do_option (pp_expression_gen pr_elem pr_space) eopt;
          pr_elem iarray2;
          pr_elem i2;
          pp_type_right_gen pr_elem pr_space (q3, (FunctionType t, iifunc))
            


      | (ParenType t, [i1;i2]) ->  
          pr2 "PB PARENTYPE ZARB, I forget about the ()";
          pp_type_with_ident_rest_gen pr_elem pr_space ident t;
          

      | (Array (eopt, t), [i1;i2]) -> 
          pp_type_left_gen pr_elem pr_space fullt;

          iiqu +> List.iter pr_elem;
          print_ident ident;

          pp_type_right_gen pr_elem pr_space fullt;


      | (FunctionType (returnt, paramst), [i1;i2]) -> 
          pp_type_left_gen pr_elem pr_space fullt;

          iiqu +> List.iter pr_elem;
          print_ident ident;

          pp_type_right_gen pr_elem pr_space fullt;

      | x -> raise Impossible
          

and (pp_type_left_gen: pr_elem_func -> pr_space_func -> fullType -> unit) = 
  fun pr_elem pr_space ->
    let rec pp_type_left = fun ((qu, iiqu), (ty, iity)) -> 
      match ty, iity with
      | (Pointer t, [i]) ->  
          pr_elem i; 
          iiqu +> List.iter pr_elem; (* le const est forcement apres le '*' *)
          pp_type_left t

      | (Array (eopt, t), [i1;i2]) -> pp_type_left t
      | (FunctionType (returnt, paramst), [i1;i2]) -> pp_type_left returnt

      | (ParenType t, _) ->  failwith "parenType"


      | (BaseType _, iis)    -> ()    
      | (Enum  (sopt, enumt), iis) -> ()    
      | (StructUnion (_, sopt, fields),iis)  -> ()    
      | (StructUnionName (s, structunion), iis) -> ()    
      | (EnumName  s, iis) -> ()    
      | (TypeName (s,_typ), iis) -> ()
      | x -> raise Impossible
    in
    pp_type_left


and pp_param_gen pr_elem pr_space = fun ((b, sopt, t), ii_b_s) -> 
  match b, sopt, ii_b_s with
  | false, None, [] -> 
      pp_type_gen pr_elem pr_space t
  | true, None, [i1] -> 
      pr_elem i1;
      pp_type_gen pr_elem pr_space t

  | false, Some s, [i1] -> 
      pp_type_with_ident_gen pr_elem pr_space (Some (s, i1)) None t;
  | true, Some s, [i1;i2] -> 
      pr_elem i1;
      pp_type_with_ident_gen pr_elem pr_space (Some (s, i2)) None t;
  | _ -> raise Impossible                


and (pp_type_right_gen: pr_elem_func -> pr_space_func -> fullType -> unit) = 
  fun pr_elem pr_space -> 
    let rec pp_type_right = fun ((qu, iiqu), (ty, iity)) -> 
      match ty, iity with
      | (Pointer t, [i]) ->  pp_type_right t

      | (Array (eopt, t), [i1;i2]) -> 
          pr_elem i1;
          eopt +> do_option (fun e -> pp_expression_gen pr_elem pr_space e);
          pr_elem i2;
          pp_type_right t

      | (ParenType t, _) ->  failwith "parenType"
      | (FunctionType (returnt, paramst), [i1;i2]) -> 
          pr_elem i1;
          (match paramst with
          | (ts, (b, iib)) -> 
              ts +> List.iter (fun (param,iicomma) -> 
                assert ((List.length iicomma) <= 1);
                iicomma +> List.iter (function x -> pr_elem x; pr_space());
                
                pp_param_gen pr_elem pr_space param;
              );
              iib +> List.iter pr_elem;
          );
          pr_elem i2;
          



      | (BaseType _, iis)        -> ()    
      | (Enum  (sopt, enumt), iis) -> ()    
      | (StructUnion (_, sopt, fields),iis)-> ()      
      | (StructUnionName (s, structunion), iis) -> ()    
      | (EnumName  s, iis) -> ()    
      | (TypeName (s,_typ), iis) -> ()
      | x -> raise Impossible
    in 
    pp_type_right

and pp_type_gen pr_elem pr_space t =
  pp_type_with_ident_gen pr_elem pr_space None None t

(* ---------------------- *)
and pp_decl_gen pr_elem pr_space = function
  | DeclList ((((var, returnType, storage),[])::xs), 
             iivirg::ifakestart::iisto) -> 

      pr_elem ifakestart;

      (* old: iisto +> List.iter pr_elem; *)
      

      (* handling the first var. Special case, we print the whole type *)
      (match var with
      | Some ((s, ini),  iis::iini) -> 
          pp_type_with_ident_gen pr_elem pr_space
	    (Some (s, iis)) (Some (storage, iisto))
            returnType;
          ini +> do_option (fun init -> 
            List.iter pr_elem iini; pp_init_gen pr_elem pr_space init);
      | None -> pp_type_gen pr_elem pr_space returnType
      | _ -> raise Impossible
      );

      (* for other vars, we just call pp_type_with_ident_rest. *)
      xs +> List.iter (function
      | ((Some ((s, ini), iis::iini), returnType, storage2), iivirg) -> 
          assert (storage2 = storage);
          iivirg +> List.iter pr_elem;
          pp_type_with_ident_rest_gen pr_elem pr_space
	    (Some (s, iis)) returnType;
          ini +> do_option (fun (init) -> 
            List.iter pr_elem iini; pp_init_gen pr_elem pr_space init);


      | x -> raise Impossible
      );

      pr_elem iivirg;

  | MacroDecl ((s, es), iis::lp::rp::iiend::ifakestart::iisto) -> 
      pr_elem ifakestart;
      iisto +> List.iter pr_elem; (* static and const *)
      pr_elem iis;
      pr_elem lp;
      es +> List.iter (fun (e, opt) -> 
        assert (List.length opt <= 1);
        opt +> List.iter pr_elem;
        pp_argument_gen pr_elem pr_space e;
      );

      pr_elem rp;
      pr_elem iiend;

  | x -> raise Impossible
      

(* ---------------------- *)
and pp_init_gen = fun pr_elem pr_space -> 
  let pp_expression e = pp_expression_gen pr_elem pr_space e in
  let rec pp_init = fun (init, iinit) -> 
    match init, iinit with
    | InitExpr e, [] -> pp_expression e;
    | InitList xs, i1::i2::iicommaopt -> 
        pr_elem i1;
        xs +> List.iter (fun (x, ii) -> 
          assert (List.length ii <= 1);
          ii +> List.iter pr_elem;
          pp_init x
        );
        iicommaopt +> List.iter pr_elem;
        pr_elem i2;

    | InitDesignators (xs, initialiser), [i1] -> (* : *)
        xs +> List.iter (pp_designator pr_elem pr_space);
        pr_elem i1;
        pp_init initialiser

    (* no use of '=' in the "Old" style *)
    | InitFieldOld (string, initialiser), [i1;i2] -> (* label:   in oldgcc *)
        pr_elem i1; pr_elem i2; pp_init initialiser
    | InitIndexOld (expression, initialiser), [i1;i2] -> (* [1] in oldgcc *)
        pr_elem i1; pp_expression expression; pr_elem i2; 
        pp_init initialiser
    | x -> raise Impossible
  in
  pp_init



and pp_designator pr_elem pr_space design = 
  let pp_expression e = pp_expression_gen pr_elem pr_space e in
  match design with 
  | DesignatorField (s), [i1; i2] -> 
      pr_elem i1; pr_elem i2; 
  | DesignatorIndex (expression), [i1;i2] -> 
      pr_elem i1; pp_expression expression; pr_elem i2; 

  | DesignatorRange (e1, e2), [iocro;iellipsis;iccro] -> 
      pr_elem iocro; pp_expression e1; pr_elem iellipsis;
      pp_expression e2; pr_elem iccro; 
  | x -> raise Impossible
     



(* ---------------------- *)
and pp_def_gen pr_elem pr_space def = 
  match def with 
  | ((s, (returnt, (paramst, (b, iib))), sto, statxs), 
                     is::iifunc1::iifunc2::i1::i2::ifakestart::isto) -> 

         pr_elem ifakestart;
                       
         pp_type_with_ident_gen pr_elem pr_space None (Some (sto, isto)) 
                         returnt;
         pr_elem is;
         pr_elem iifunc1;

        (* not anymore, cf tests/optional_name_parameter and 
           macro_parameter_shortcut.c
         (match paramst with
         | [(((bool, None, t), ii_b_s), iicomma)] -> 
             assert 
               (match t with 
               | qu, (BaseType Void, ii) -> true
               | _ -> true 
               );
             assert (null iicomma);
             assert (null ii_b_s);
             pp_type_with_ident_gen pr_elem pr_space  None None t
             
         | paramst -> 
           paramst +> List.iter (fun (((bool, s, t), ii_b_s), iicomma) ->
            iicomma +> List.iter pr_elem;
           
            (match b, s, ii_b_s with
            | false, Some s, [i1] -> 
                pp_type_with_ident_gen 
                  pr_elem pr_space (Some (s, i1)) None t;
            | true, Some s, [i1;i2] -> 
                pr_elem i1;
                pp_type_with_ident_gen 
                  pr_elem pr_space (Some (s, i2)) None t;

            (* in definition we have name for params, except when f(void) *)
             | _, None, _ -> raise Impossible 
            | false, None, [] -> 
                
            | _ -> raise Impossible
            )
         );
           );

         (* normally ii represent the ",..." but it is also abused
            with the f(void) case *)
         (* assert (List.length iib <= 2);*)
         iib +> List.iter pr_elem;

        *)
         paramst +> List.iter (fun (param,iicomma) -> 
           assert ((List.length iicomma) <= 1);
           iicomma +> List.iter (function x -> pr_elem x; pr_space());
           
           pp_param_gen pr_elem pr_space param;
         );
         iib +> List.iter pr_elem;
            

         pr_elem iifunc2;
         pr_elem i1; 
         statxs +> List.iter (pp_statement_gen pr_elem pr_space);
         pr_elem i2;
     | _ -> raise Impossible




let pp_program_gen pr_elem pr_space progelem =
  match progelem with
  | Declaration decl -> pp_decl_gen pr_elem pr_space decl
  | Definition def -> pp_def_gen pr_elem pr_space def

  | Include ((s, [i1;i2]),h_rel_pos) -> 
      pr_elem i1; pr_elem i2
  | Define ((s,[idefine;iident;ieol]), (defkind, defval)) -> 
      pr_elem idefine;
      pr_elem iident;
        
      let define_val = function
        | DefineExpr e -> pp_expression_gen pr_elem pr_space e
        | DefineStmt st -> pp_statement_gen pr_elem pr_space st
        | DefineDoWhileZero (st, ii) -> 
            (match ii with
            | [ido;iwhile;iopar;iint;icpar] -> 
                pr_elem ido;
                pp_statement_gen pr_elem pr_space st;
                pr_elem iwhile; pr_elem iopar; pr_elem iint; pr_elem icpar
            | _ -> raise Impossible
            )
        | DefineFunction def -> pp_def_gen pr_elem pr_space def
            
        | DefineType ty -> pp_type_gen pr_elem pr_space ty
        | DefineText (s, ii) -> List.iter pr_elem ii
        | DefineEmpty -> ()
      in
      (match defkind with
      | DefineVar -> ()
      | DefineFunc (params, ii) -> 
          let (i1,i2) = tuple_of_list2 ii in
          pr_elem i1; 
          params +> List.iter (fun ((s,iis), iicomma) -> 
            assert (List.length iicomma <= 1);
            iicomma +> List.iter pr_elem;
            iis +> List.iter pr_elem;
          );
          pr_elem i2;
      );
      define_val defval;
      pr_elem ieol
          

  | MacroTop (s, es,   [i1;i2;i3;i4]) -> 
      pr_elem i1;
      pr_elem i2;
      es +> List.iter (fun (e, opt) -> 
        assert (List.length opt <= 1);
        opt +> List.iter pr_elem;
        pp_argument_gen pr_elem pr_space e;
      );
      pr_elem i3;
      pr_elem i4;
      

  | EmptyDef ii -> ii +> List.iter pr_elem
  | NotParsedCorrectly ii -> 
      assert (List.length ii >= 1);
      ii +> List.iter pr_elem 
  | FinalDef info -> pr_elem (Ast_c.rewrap_str "" info)
      
  | _ -> raise Impossible
     



(*****************************************************************************)

(* Here we do not use (mcode, env). It is a simple C pretty printer. *)
let pr_elem info = 
  let s = Ast_c.str_of_info info in
  pp s

let pr_space _ = Format.print_space()

let pp_expression_simple = pp_expression_gen pr_elem pr_space
let pp_statement_simple  = pp_statement_gen pr_elem pr_space
let pp_type_simple  = pp_type_gen pr_elem pr_space
