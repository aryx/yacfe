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

module F = Control_flow_cplusplus

(*****************************************************************************)
(* Functions to visit the Ast, and now also the CFG nodes *)
(*****************************************************************************)


(* Visitor based on continuation. Cleaner than the one based on mutable 
 * pointer functions. src: based on a (vague) idea from Remy Douence.
 * 
 * 
 * 
 * Diff with Julia's visitor ? She does:
 * 
 * let ident r k i =
 *  ...
 * let expression r k e =
 *  ... 
 *   ... (List.map r.V0.combiner_expression expr_list) ...
 *  ...
 * let res = V0.combiner bind option_default 
 *   mcode mcode mcode mcode mcode mcode mcode mcode mcode mcode mcode
 *   donothing donothing donothing donothing
 *   ident expression typeC donothing parameter declaration statement
 *   donothing in
 * ...
 * collect_unitary_nonunitary
 *   (List.concat (List.map res.V0.combiner_top_level t))
 * 
 * 
 * 
 * So she has to remember at which position you must put the 'expression'
 * function. I use record which is easier. 
 * 
 * When she calls recursively, her res.V0.combiner_xxx does not take bigf
 * in param whereas I do 
 *   | F.Decl decl -> Visitor_c.vk_decl bigf decl 
 * And with the record she gets, she does not have to do my
 * multiple defs of function such as 'let al_type = V0.vk_type_s bigf'
 * 
 * The code of visitor.ml is cleaner with julia because mutual recursive calls
 * are clean such as ... 'expression e' ... and not  'f (k, bigf) e'
 * or 'vk_expr bigf e'.
 * 
 * So it is very dual:
 * - I give a record but then I must handle bigf.
 * - She gets a record, and gives a list of function
 * 
 *) 

 
(* old: first version (only visiting expr) 

let (iter_expr:((expression -> unit) -> expression -> unit) -> expression -> unit)
 = fun f expr ->
  let rec k e = 
    match e with
    | Constant c -> ()
    | FunCall  (e, es)         ->  f k e; List.iter (f k) es
    | CondExpr (e1, e2, e3)    -> f k e1; f k e2; f k e3
    | Sequence (e1, e2)        -> f k e1; f k e2;
    | Assignment (e1, op, e2)  -> f k e1; f k e2;
        
    | Postfix  (e, op) -> f k e
    | Infix    (e, op) -> f k e
    | Unary    (e, op) -> f k e
    | Binary   (e1, op, e2) -> f k e1; f k  e2;
        
    | ArrayAccess    (e1, e2) -> f k e1; f k e2;
    | RecordAccess   (e, s) -> f k e
    | RecordPtAccess (e, s) -> f k e

    | SizeOfExpr  e -> f k e
    | SizeOfType  t -> ()
    | _ -> failwith "to complete"

  in f k expr

let ex1 = Sequence (Sequence (Constant (Ident "1"), Constant (Ident "2")), 
                             Constant (Ident "4"))
let test = 
  iter_expr (fun k e ->  match e with
  | Constant (Ident x) -> Common.pr2 x
  | rest -> k rest
  ) ex1 
==> 
1
2
4

*)

(*****************************************************************************)
(* Side effect style visitor *)
(*****************************************************************************)

(* Visitors for all langage concept,  not just for expression.
 * 
 * Note that I don't visit necesserally in the order of the token
 * found in the original file. So don't assume such hypothesis!
 * 
 * todo? parameter ? onedecl ?
 *)
type visitor_c = 
 { 
   kexpr:      (expression  -> unit) * visitor_c -> expression  -> unit;
   kstatement: (statement   -> unit) * visitor_c -> statement   -> unit;
   ktype:      (fullType    -> unit) * visitor_c -> fullType    -> unit;

   kvdecl: (var_declaration -> unit) * visitor_c -> var_declaration -> unit;
   kbdecl: (block_declaration -> unit) * visitor_c -> block_declaration -> unit;
   kclassdecl: (class_member -> unit) * visitor_c -> class_member -> unit;

   kfdef:   (definition  -> unit) * visitor_c -> definition  -> unit; 

   kini:       (initialiser  -> unit) * visitor_c -> initialiser  -> unit; 

   kcppdirective: (cpp_directive -> unit) * visitor_c -> cpp_directive -> unit;
   kdefineval : (define_val -> unit) * visitor_c -> define_val -> unit;
   kstatementseq: (statement_sequencable   -> unit) * visitor_c -> statement_sequencable   -> unit;
   kdeclarationseq: (declaration_sequencable   -> unit) * visitor_c -> declaration_sequencable   -> unit;
   kclassmemberseq: (class_member_sequencable   -> unit) * visitor_c -> class_member_sequencable   -> unit;

   kname: (name -> unit) * visitor_c -> name -> unit;
   kinfo: (info -> unit) * visitor_c -> info -> unit;

   (* CFG *)
   knode: (F.node -> unit) * visitor_c -> F.node -> unit;
   (* AST *)
   ktopdecl: (declaration -> unit) * visitor_c -> declaration -> unit;
   ktoplevel: (toplevel -> unit) * visitor_c -> toplevel -> unit;
 } 

let default_visitor_c = 
  { kexpr =      (fun (k,_) e  -> k e);
    kstatement = (fun (k,_) st -> k st);
    ktype      = (fun (k,_) t  -> k t);
    kvdecl      = (fun (k,_) d  -> k d);
    kbdecl      = (fun (k,_) d  -> k d);
    kclassdecl      = (fun (k,_) d  -> k d);
    kfdef       = (fun (k,_) d  -> k d);
    kini       = (fun (k,_) ie  -> k ie);
    kname      = (fun (k,_) ii  -> k ii);
    kinfo      = (fun (k,_) ii  -> k ii);
    knode      = (fun (k,_) n  -> k n);
    ktopdecl  = (fun (k,_) p  -> k p);
    ktoplevel  = (fun (k,_) p  -> k p);
    kcppdirective = (fun (k,_) p  -> k p);
    kdefineval = (fun (k,_) p  -> k p);

    kstatementseq    = (fun (k,_) p  -> k p);
    kdeclarationseq    = (fun (k,_) p  -> k p);
    kclassmemberseq    = (fun (k,_) p  -> k p);
  } 


(* ------------------------------------------------------------------------ *)


let rec vk_expr = fun bigf expr ->
  let iif ii = vk_ii bigf ii in

  let rec exprf e = bigf.kexpr (k,bigf) e
  (* dont go in _typ *)
  and k ((e,_typ), ii) = 
    iif ii;
    match e with
    | Ident (s) -> vk_name bigf s
    | Constant (c) -> ()
    | FunCall  (e, es)         -> 
        exprf e;  
        vk_argument_list bigf es;
    | CondExpr (e1, e2, e3)    -> 
        exprf e1; do_option (exprf) e2; exprf e3
    | Sequence (e1, e2)        -> exprf e1; exprf e2;
    | Assignment (e1, op, e2)  -> exprf e1; exprf e2;
        
    | Postfix  (e, op) -> exprf e
    | Infix    (e, op) -> exprf e
    | Unary    (e, op) -> exprf e
    | Binary   (e1, op, e2) -> exprf e1; exprf  e2;
        
    | ArrayAccess    (e1, e2) -> exprf e1; exprf e2;
    | RecordAccess   (e, s) -> exprf e; vk_name bigf s
    | RecordPtAccess (e, s) -> exprf e; vk_name bigf s

    | SizeOfExpr  (e) -> exprf e
    | SizeOfType  (t) -> vk_type bigf t
    | Cast    (t, e) -> vk_type bigf t; exprf e

    (* old: | StatementExpr (((declxs, statxs), is)), is2 -> 
     *          List.iter (vk_decl bigf) declxs; 
     *          List.iter (vk_statement bigf) statxs 
     *)
    | StatementExpr ((statxs, is)) -> 
        iif is;
        statxs +> List.iter (vk_statement_sequencable bigf);

    (* TODO, we will certainly have to then do a special visitor for 
     * initializer 
     *)
    | GccConstructor (t, initxs) -> 
        vk_type bigf t;
        initxs +> List.iter (fun (ini, ii) -> 
          vk_ini bigf ini;
          vk_ii bigf ii;
        ) 
          
    | ParenExpr (e) -> exprf e


    | This -> () 
    | RecordStarAccess (e1, e2) -> exprf e1; exprf e2
    | RecordPtStarAccess (e1, e2) -> exprf e1; exprf e2
    | CplusplusCast (_castop, ft, e) -> 
        vk_type bigf ft;
        exprf e
    | ConstructedObject (ft, args) -> 
        vk_type bigf ft;
        vk_argument_list bigf args
    | TypeIdOfExpr e -> exprf e
    | TypeIdOfType ft -> vk_type bigf ft


    | New -> ()
    | Delete (e, qtopopt) -> 
        exprf e;
        qtopopt +> Common.do_option (vk_qtop bigf)
    | DeleteArray (e, qtopopt) -> 
        exprf e;
        qtopopt +> Common.do_option (vk_qtop bigf)


    | Throw eopt -> 
        eopt +> Common.do_option exprf
        

  in exprf expr





and vk_statement = fun bigf st -> 
  let iif ii = vk_ii bigf ii in

  let rec statf x = bigf.kstatement (k,bigf) x 
  and k st = 
    let (unwrap_st, ii) = st in
    iif ii;
    match unwrap_st with
    | Labeled (Label (s, st)) -> statf  st;
    | Labeled (Case  (e, st)) -> vk_expr bigf e; statf st;
    | Labeled (CaseRange  (e, e2, st)) -> 
        vk_expr bigf e; vk_expr bigf e2; statf st;
    | Labeled (Default st) -> statf st;

    | Compound statxs -> 
        statxs +> List.iter (vk_statement_sequencable bigf)
    | ExprStatement (eopt) -> do_option (vk_expr bigf) eopt;

    | Selection  (If (e, st1, st2)) -> 
        vk_expr bigf e; statf st1; statf st2;
    | Selection  (Switch (e, st)) -> 
        vk_expr bigf e; statf st;
    | Iteration  (While (e, st)) -> 
        vk_expr bigf e; statf st;
    | Iteration  (DoWhile (st, e)) -> statf st; vk_expr bigf e; 
    | Iteration  (For ((e1opt,i1), (e2opt,i2), (e3opt,i3), st)) -> 
        statf (ExprStatement (e1opt),i1); 
        statf (ExprStatement (e2opt),i2); 
        statf (ExprStatement (e3opt),i3); 
        statf st;

    | Iteration  (MacroIteration (s, es, st)) -> 
        vk_argument_list bigf es;
        statf st;
          
    | Jump (Goto s) -> ()
    | Jump ((Continue|Break|Return)) -> ()
    | Jump (ReturnExpr e) -> vk_expr bigf e;
    | Jump (GotoComputed e) -> vk_expr bigf e;

    | MacroStmt -> ()

    | DeclStmt d -> vk_bdecl bigf d
    | NestedFunc f -> vk_def bigf f
    | Try (((compound),ii), handlers) -> 
        iif ii;
        compound +> List.iter (vk_statement_sequencable bigf);
        handlers +> List.iter (vk_handler bigf);

  in statf st

and vk_statement_sequencable = fun bigf stseq -> 
  let f = bigf.kstatementseq in 

  let rec k stseq = 
    match stseq with
    | StmtElem st -> vk_statement bigf st
    | CppDirectiveStmt directive -> 
        vk_cpp_directive bigf directive
    | IfdefStmt ifdef -> 
        vk_ifdef_directive bigf ifdef
  in f (k, bigf) stseq



and vk_type = fun bigf t -> 
  let iif ii = vk_ii bigf ii in

  let rec typef x = bigf.ktype (k, bigf) x 
  and k t = 
    let (q, t) = t in
    let (unwrap_q, iiq) = q in
    let (unwrap_t, iit) = t in
    iif iiq;
    iif iit;
    match unwrap_t with
    | BaseType _ -> ()
    | Pointer t -> typef t
    | Array (eopt, t) -> 
        do_option (vk_expr bigf) eopt;
        typef t 
    | FunctionType (returnt, paramst) -> 
        typef returnt;
        (match paramst with
        | (ts, (b,iihas3dots)) -> 
            iif iihas3dots;
            vk_param_list bigf ts
        )

    | Enum  (sopt, enumt) -> 
        enumt +> List.iter (fun (((s, eopt),ii_s_eq), iicomma) -> 
          iif ii_s_eq; iif iicomma;
          eopt +> do_option (vk_expr bigf)
          );    
        

    | StructUnionName (s, structunion) -> ()
    | EnumName  s -> ()

    (* dont go in _typ *)
    | TypeName (s, _typ) -> ()

    | TypeOfExpr e -> vk_expr bigf e
    | TypeOfType t -> typef t

    | ParenType t -> typef t

    | Reference t -> typef t
    | TypeTemplate (s, targs) -> 
        vk_template_argument_list bigf targs
    | TypenameKwd t -> typef t
    | StructUnion cd -> vk_class_definition bigf cd

  in typef t




(* ------------------------------------------------------------------------ *)

and vk_vdecl = fun bigf d -> 
  let iif ii = vk_ii bigf ii in

  let f = bigf.kvdecl in 
  let rec k decl = 
    match decl with 
    | DeclList (xs,ii) -> 
        iif ii; 
        xs +> List.iter (fun (adecl, iicomma) -> 
          vk_onedecl bigf adecl;
          iif iicomma;
        );
    | MacroDecl ((s, args),ii) -> 
        iif ii;
        vk_argument_list bigf args;

  in f (k, bigf) d 

and vk_ini = fun bigf ini -> 
  let iif ii = vk_ii bigf ii in

  let rec inif x = bigf.kini (k, bigf) x 
  and k (ini, iini) = 
    iif iini;
    match ini with
    | InitExpr e -> vk_expr bigf e
    | InitList initxs -> 
        initxs +> List.iter (fun (ini, ii) -> 
          inif ini;
          iif ii;
        ) 
    | InitDesignators (xs, e) -> 
        xs +> List.iter (vk_designator bigf);
        inif e

    | InitFieldOld (s, e) -> inif e
    | InitIndexOld (e1, e) ->
        vk_expr bigf e1; inif e

  in inif ini


and vk_designator = fun bigf design -> 
  let iif ii = vk_ii bigf ii in
  let (designator, ii) = design in
  iif ii;
  match designator with
  | DesignatorField s -> ()
  | DesignatorIndex e -> vk_expr bigf e
  | DesignatorRange (e1, e2) -> vk_expr bigf e1; vk_expr bigf e2

(* ------------------------------------------------------------------------ *)
and vk_bdecl = fun bigf d -> 
  let iif ii =  vk_ii bigf ii in
  let f = bigf.kbdecl in
  let rec k d = 
    let (unwrap_d, ii) = d in
    iif ii;
    match unwrap_d with
    | SimpleDecl vdecl -> vk_vdecl bigf vdecl

    | UsingDecl name -> vk_name bigf name
    | UsingDirective name -> vk_name bigf name
    | NameSpaceAlias (s, name) -> vk_name bigf name

    | Asm asmbody -> vk_asmbody bigf asmbody
  in
  f (k, bigf) d

(* ------------------------------------------------------------------------ *)
and vk_classdecl = fun bigf d -> 
  let iif ii =  vk_ii bigf ii in
  let f = bigf.kclassdecl in
  let rec k d = 
    let (unwrap_d, ii) = d in
    iif ii;
    match unwrap_d with
    | Access access_spec -> ()
    | DeclarationField field_decl -> vk_field_decl bigf field_decl
    
    | Method def -> vk_def bigf def

    | Constructor (def, _bool) ->  vk_def bigf def
    | Destructor def -> vk_def bigf def
    | ConstructorDecl (params, _bool) -> vk_param_list bigf params

    | DestructorDecl (name, bool) -> 
        vk_name bigf name
         
    | QualifiedIdInClass name -> vk_name bigf name
        
    | TemplateDeclInClass (tpl_params, declaration) -> 
        vk_template_parameter_list bigf tpl_params;
        vk_topdecl bigf declaration

    | UsingDeclInClass name -> vk_name bigf name

    | EmptyField -> ()
  in
  f (k, bigf) d


and vk_classdecl_sequencable = fun bigf stseq -> 
  let f = bigf.kclassmemberseq in 

  let rec k stseq = 
    match stseq with
    | ClassElem st -> vk_classdecl bigf st
    | CppDirectiveStruct directive -> 
        vk_cpp_directive bigf directive
    | IfdefStruct ifdef -> 
        vk_ifdef_directive bigf ifdef
  in f (k, bigf) stseq



and vk_class_member = fun bigf d -> 
  vk_classdecl bigf d


and vk_field_decl = fun bigf xfield -> 
  let iif ii = vk_ii bigf ii in
  match xfield with 
  | FieldDeclList (onefield_multivars, iiptvirg) -> 
      iif iiptvirg;
      onefield_multivars +> List.iter (fun (afield, iicomma) -> 
        iif iicomma;
        vk_field_kind bigf afield
      )

and vk_field_kind = fun bigf fld -> 
  let iif ii =  vk_ii bigf ii in

  let (unwrap_fld, ii) = fld in
  iif ii;
  match unwrap_fld with
  | FieldDecl onedecl -> 
      vk_onedecl bigf onedecl
  | MethodDecl (onedecl, is_virtual) -> 
      vk_onedecl bigf onedecl
  | BitField (sopt, ft, e) -> 
      vk_type bigf ft;
      vk_expr bigf e


and vk_onedecl = fun bigf adecl -> 
  let iif ii =  vk_ii bigf ii in

  let (var, t, sto) = adecl in

  vk_type bigf t;
  var +> Common.do_option (fun ((s, ini), ii_s_ini) -> 
    iif ii_s_ini;
    ini +> Common.do_option (vk_ini bigf)
  );
  ()



(* ------------------------------------------------------------------------ *)


and vk_def = fun bigf d -> 
  let iif ii = vk_ii bigf ii in

  let f = bigf.kfdef in
  let rec k d = 
    match d with
    | (s, (returnt, (paramst, (b, iib))), sto, statxs), ii -> 
        iif ii;
        iif iib;
        vk_type bigf returnt;
        paramst +> List.iter (fun (param,iicomma) -> 
          vk_param bigf param;
          iif iicomma;
        );
        statxs +> List.iter (vk_statement_sequencable bigf)
  in f (k, bigf) d 


and vk_class_definition = fun bigf cd -> 
  let iif ii = vk_ii bigf ii in

  let (su, nameopt, baseopt, cd), ii = cd in

  nameopt +> Common.do_option (vk_name bigf);
  baseopt +> Common.do_option (vk_base_clause_list bigf);
  cd +> List.iter (vk_classdecl_sequencable bigf);
  iif ii


(* ------------------------------------------------------------------------ *)
and vk_topdecl = fun bigf d -> 
  let iif ii =  vk_ii bigf ii in
  let f = bigf.ktopdecl in
  let rec k d = 
    let (unwrap_d, ii) = d in
    iif ii;
    match unwrap_d with
    | Declaration bd -> vk_bdecl bigf bd

    | Definition def -> vk_def bigf def
    | ConstructorTop (def, b) -> vk_def bigf def
    | DestructorTop (def) -> vk_def bigf def

    | TemplateDecl (tpl_params, decl) -> 
        vk_template_parameter_list bigf tpl_params;
        vk_topdecl bigf decl
    | TemplateSpecialization decl -> vk_topdecl bigf decl

    | ExternC decl ->       vk_topdecl bigf decl
    | ExternCList decls ->  decls +> List.iter (vk_declaration_sequencable bigf)
    | NameSpace       (s, decls) -> decls +> List.iter (vk_declaration_sequencable bigf)
    | NameSpaceExtend (s, decls) -> decls +> List.iter (vk_declaration_sequencable bigf)
    | NameSpaceAnon   (decls) -> decls +> List.iter (vk_declaration_sequencable bigf)
  in
  f (k, bigf) d


and vk_declaration_sequencable = fun bigf stseq -> 
  let f = bigf.kdeclarationseq in 

  let rec k stseq = 
    match stseq with
    | DeclElem st -> vk_topdecl bigf st
    | CppDirectiveDecl directive -> 
        vk_cpp_directive bigf directive
    | IfdefDecl ifdef -> 
        vk_ifdef_directive bigf ifdef
  in f (k, bigf) stseq


    


and vk_toplevel = fun bigf p -> 
  let f = bigf.ktoplevel in
  let iif ii =  vk_ii bigf ii in
  let rec k p = 
    match p with
    | TopDecl decl -> vk_topdecl bigf decl

    | EmptyDef ii -> iif ii
    | MacroTop (s, xs, ii) -> 
        vk_argument_list bigf xs;
        iif ii

    | CppTop top -> vk_cpp_directive bigf top
    | IfdefTop ifdefdir -> vk_ifdef_directive bigf ifdefdir
          
    | NotParsedCorrectly ii -> iif ii
    | FinalDef info -> vk_info bigf info
  in f (k, bigf) p



and vk_ifdef_directive bigf directive = 
  let iif ii =  vk_ii bigf ii in
  match directive with
  | IfdefDirective ii -> iif ii


and vk_cpp_directive bigf directive =
  let iif ii =  vk_ii bigf ii in
  let f = bigf.kcppdirective in
  let rec k directive = 
    match directive with
    | Include ((s, ii), h_rel_pos) -> iif ii;
    | Define ((s,ii), (defkind, defval)) -> 
        iif ii;
        vk_define_kind bigf defkind;
        vk_define_val bigf defval
    | Undef (s, ii) -> 
        iif ii
    | PragmaAndCo (ii) -> 
        iif ii
  in f (k, bigf) directive


and vk_define_kind bigf defkind = 
  match defkind with
  | DefineVar -> ()
  | DefineFunc (params, ii) -> 
      vk_ii bigf ii;
      params +> List.iter (fun ((s,iis), iicomma) -> 
        vk_ii bigf iis;
        vk_ii bigf iicomma;
      )

and vk_define_val bigf defval = 
  let f = bigf.kdefineval in 

  let rec k defval = 
  match defval with
  | DefineExpr e -> 
      vk_expr bigf e
  | DefineStmt stmt -> vk_statement bigf stmt
  | DefineDoWhileZero (stmt, ii) -> 
      vk_statement bigf stmt;
      vk_ii bigf ii
  | DefineFunction def -> vk_def bigf def
  | DefineType ty -> vk_type bigf ty
  | DefineText (s, ii) -> vk_ii bigf ii
  | DefineEmpty -> ()
  | DefineInit ini -> vk_ini bigf ini

  | DefineTodo -> 
      pr2 "DefineTodo";
      ()
  in f (k, bigf) defval
  

        

(* ------------------------------------------------------------------------ *)
(* Now keep fullstatement inside the control flow node, 
 * so that can then get in a MetaStmtVar the fullstatement to later
 * pp back when the S is in a +. But that means that 
 * Exp will match an Ifnode even if there is no such exp
 * inside the condition of the Ifnode (because the exp may
 * be deeper, in the then branch). So have to not visit
 * all inside a node anymore.
 * 
 * update: j'ai choisi d'accrocher au noeud du CFG a la
 * fois le fullstatement et le partialstatement et appeler le 
 * visiteur que sur le partialstatement.
 *)

and vk_node = fun bigf node -> 
  let iif ii = vk_ii bigf ii in
  let infof info = vk_info bigf info in

  let f = bigf.knode in
  let rec k n = 
    match F.unwrap n with

    | F.FunHeader ((idb, (rett, (paramst,(isvaargs,iidotsb))), stob),ii) ->
        vk_type bigf rett;
        paramst +> List.iter (fun (param, iicomma) ->
          vk_param bigf param;
          iif iicomma;
        );


    | F.Decl decl -> vk_vdecl bigf decl 
    | F.ExprStatement (st, (eopt, ii)) ->  
        iif ii;
        eopt +> do_option (vk_expr bigf)

    | F.IfHeader (_, (e,ii)) 
    | F.SwitchHeader (_, (e,ii))
    | F.WhileHeader (_, (e,ii))
    | F.DoWhileTail (e,ii) -> 
        iif ii;
        vk_expr bigf e

    | F.ForHeader (_st, (((e1opt,i1), (e2opt,i2), (e3opt,i3)), ii)) -> 
        iif i1; iif i2; iif i3;
        iif ii;
        e1opt +> do_option (vk_expr bigf);
        e2opt +> do_option (vk_expr bigf);
        e3opt +> do_option (vk_expr bigf);
    | F.MacroIterHeader (_s, ((s,es), ii)) -> 
        iif ii;
        vk_argument_list bigf es;
        
    | F.ReturnExpr (_st, (e,ii)) -> iif ii; vk_expr bigf e
        
    | F.Case  (_st, (e,ii)) -> iif ii; vk_expr bigf e
    | F.CaseRange (_st, ((e1, e2),ii)) -> 
        iif ii; vk_expr bigf e1; vk_expr bigf e2


    | F.CaseNode i -> ()

    | F.DefineExpr e  -> vk_expr bigf e
    | F.DefineType ft  -> vk_type bigf ft
    | F.DefineHeader ((s,ii), (defkind))  -> 
        iif ii;
        vk_define_kind bigf defkind;

    | F.DefineDoWhileZeroHeader (((),ii)) -> iif ii

    | F.Include ((s, ii),h_rel_pos) -> iif ii

    | F.MacroTop (s, args, ii) -> 
        iif ii;
        vk_argument_list bigf args

    | F.Ifdef (st, ((),ii)) -> iif ii

    | F.Break    (st,((),ii)) -> iif ii
    | F.Continue (st,((),ii)) -> iif ii
    | F.Default  (st,((),ii)) -> iif ii
    | F.Return   (st,((),ii)) -> iif ii
    | F.Goto  (st, (s,ii)) -> iif ii
    | F.Label (st, (s,ii)) -> iif ii
    | F.EndStatement iopt -> do_option infof iopt
    | F.DoHeader (st, info) -> infof info
    | F.Else info -> infof info
    | F.SeqEnd (i, info) -> infof info
    | F.SeqStart (st, i, info) -> infof info

    | F.MacroStmt (st, ((),ii)) -> iif ii
    | F.Asm (st, (asmbody,ii)) -> 
        iif ii;
        vk_asmbody bigf asmbody

    | (
        F.TopNode|F.EndNode|
        F.ErrorExit|F.Exit|F.Enter|
        F.FallThroughNode|F.AfterNode|F.FalseNode|F.TrueNode|F.InLoopNode|
        F.Fake
      ) -> ()



  in
  f (k, bigf) node
(* ------------------------------------------------------------------------ *)
and vk_name = fun bigf name -> 
  let (qtopopt, qscope, qid) = name in

  qtopopt +> Common.do_option (vk_qtop bigf);
  qscope +> List.iter (vk_qualifier_scope bigf);
  vk_ident bigf qid;
    



and vk_qualifier_scope = fun bigf (qualif: qualifier) -> 
  let iif ii = vk_ii bigf ii in
  let (unwrap_qualif, ii) = qualif in
  iif ii;
  match unwrap_qualif with
  | QClassname s -> ()
  | QTemplateId (s, targs) -> vk_template_argument_list bigf targs

and vk_qtop = fun bigf x ->    
  let iif ii = vk_ii bigf ii in
  let (QTop,ii) = x in
  iif ii

and vk_ident = fun bigf id -> 
  let iif ii = vk_ii bigf ii in

  let (unwrap_id, ii) = id in
  iif ii;
  match unwrap_id with
  | IdIdent s -> ()
  | IdOperator op -> ()
  | IdConverter ft -> vk_type bigf ft
  | IdDestructor id -> ()
  | IdTemplateId (s, targs) -> vk_template_argument_list bigf targs
  


(* ------------------------------------------------------------------------ *)
and vk_info = fun bigf info -> 
  let rec infof ii = bigf.kinfo (k, bigf) ii
  and k i = ()
  in
  infof info

and vk_ii = fun bigf ii -> 
  List.iter (vk_info bigf) ii


(* ------------------------------------------------------------------------ *)
and vk_argument = fun bigf arg -> 
  let rec do_action = function 
    | (ActMisc ii) -> vk_ii bigf ii
  in
  match arg with
  | Left e -> (vk_expr bigf) e
  | Right (ArgType param) -> vk_param bigf param
  | Right (ArgAction action) -> do_action action

and vk_argument_list = fun bigf es -> 
  let iif ii = vk_ii bigf ii in
  es +> List.iter (fun (e, ii) -> 
    iif ii;
    vk_argument bigf e
  )



and vk_param = fun bigf (((b, s, t), ii_b_s)) ->  
  let iif ii = vk_ii bigf ii in
  iif ii_b_s;
  vk_type bigf t

and vk_param_list = fun bigf ts -> 
  let iif ii = vk_ii bigf ii in
  ts +> List.iter (fun (param,iicomma) -> 
    vk_param bigf param;
    iif iicomma;
  )


and vk_template_argument = fun bigf arg -> 
  match arg with
  | Left ft -> vk_type bigf ft
  | Right e -> vk_expr bigf e

and vk_template_argument_list = fun bigf es -> 
  let iif ii = vk_ii bigf ii in
  es +> List.iter (fun (e, ii) -> 
    iif ii;
    vk_template_argument bigf e
  )


and vk_template_parameter = fun bigf arg -> 
 vk_param bigf arg

and vk_template_parameter_list = fun bigf es -> 
  let iif ii = vk_ii bigf ii in
  es +> List.iter (fun (e, ii) -> 
    iif ii;
    vk_template_parameter bigf e
  )







(* ------------------------------------------------------------------------ *)
and vk_asmbody = fun bigf (string_list, colon_list) -> 
  let iif ii = vk_ii bigf ii in

  iif string_list;
  colon_list +> List.iter (fun (Colon xs, ii)  -> 
    iif ii;
    xs +> List.iter (fun (x,iicomma) -> 
      iif iicomma;
      (match x with
      | ColonMisc, ii -> iif ii 
      | ColonExpr e, ii -> 
          vk_expr bigf e;
          iif ii
      )
    ))


and vk_handler = fun bigf handler -> 
  pr2 "Todo: vk_handler";
  ()


and vk_base_clause = fun bigf base ->
  let iif ii = vk_ii bigf ii in

  let (unwrap_x, ii) = base in
  iif ii;
  match unwrap_x with
  | name, is_virtual, access_opt -> 
      vk_name bigf name



and vk_base_clause_list = fun bigf es -> 
  let iif ii = vk_ii bigf ii in
  es +> List.iter (fun (e, ii) -> 
    iif ii;
    vk_base_clause bigf e
  )



(* ------------------------------------------------------------------------ *)

let vk_args_splitted = fun bigf args_splitted -> 
  let iif ii = vk_ii bigf ii in
  args_splitted +> List.iter (function  
  | Left arg -> vk_argument bigf arg
  | Right ii -> iif ii
  )


let vk_define_params_splitted = fun bigf args_splitted -> 
  let iif ii = vk_ii bigf ii in
  args_splitted +> List.iter (function  
  | Left (s, iis) -> vk_ii bigf iis
  | Right ii -> iif ii
  )



let vk_params_splitted = fun bigf args_splitted -> 
  let iif ii = vk_ii bigf ii in
  args_splitted +> List.iter (function  
  | Left arg -> vk_param bigf arg
  | Right ii -> iif ii
  )






(* ------------------------------------------------------------------------ *)
let vk_class_members = fun bigf cd ->
  cd +> List.iter (vk_classdecl_sequencable bigf)


(* ------------------------------------------------------------------------ *)
let vk_cst = fun bigf (cst, ii) -> 
  let iif ii = vk_ii bigf ii in
  iif ii;
  (match cst with
  | Left cst -> ()
  | Right s -> ()
  )


  

(*****************************************************************************)
(* "syntetisized attributes" style *)
(*****************************************************************************)

(* TODO port the xxs_s to new cpp construct too *)

type 'a inout = 'a -> 'a 

(* _s for synthetizized attributes 
 *
 * Note that I don't visit necesserally in the order of the token
 * found in the original file. So don't assume such hypothesis!
 *)
type visitor_c_s = { 
  kexpr_s:      (expression inout * visitor_c_s) -> expression inout;
  kstatement_s: (statement  inout * visitor_c_s) -> statement  inout;
  ktype_s:      (fullType   inout * visitor_c_s) -> fullType   inout;
  kini_s:  (initialiser  inout * visitor_c_s) -> initialiser inout; 

  kvdecl_s: (var_declaration  inout * visitor_c_s) -> var_declaration inout;
  kdef_s:  (definition   inout * visitor_c_s) -> definition  inout; 

  ktoplevel_s: (toplevel inout * visitor_c_s) -> toplevel inout;
  knode_s: (F.node inout * visitor_c_s) -> F.node inout;

  kcppdirective_s: (cpp_directive inout * visitor_c_s) -> cpp_directive inout;
  kdefineval_s: (define_val inout * visitor_c_s) -> define_val inout;

  kinfo_s: (info inout * visitor_c_s) -> info inout;
 } 

let default_visitor_c_s = 
  { kexpr_s =      (fun (k,_) e  -> k e);
    kstatement_s = (fun (k,_) st -> k st);
    ktype_s      = (fun (k,_) t  -> k t);
    kvdecl_s      = (fun (k,_) d  -> k d);
    kdef_s       = (fun (k,_) d  -> k d);
    kini_s       = (fun (k,_) d  -> k d);
    ktoplevel_s  = (fun (k,_) p  -> k p);
    knode_s      = (fun (k,_) n  -> k n);
    kinfo_s      = (fun (k,_) i  -> k i);
    kdefineval_s = (fun (k,_) x  -> k x);
    kcppdirective_s = (fun (k,_) x  -> k x);
  } 

let rec vk_expr_s = fun bigf expr ->
  let iif ii = vk_ii_s bigf ii in
  let rec exprf e = bigf.kexpr_s  (k, bigf) e
  and k e = 
    let ((unwrap_e, typ), ii) = e in
    (* don't analyse optional type
     * old:  typ +> map_option (vk_type_s bigf) in 
     *)
    let typ' = typ in 
    let e' = 
      match unwrap_e with
      | Ident (s) -> Ident (s)
      | Constant (c) -> Constant (c)
      | FunCall  (e, es)         -> 
          FunCall (exprf e,
                  es +> List.map (fun (e,ii) -> 
                    vk_argument_s bigf e, iif ii
                  ))
            
      | CondExpr (e1, e2, e3)    -> CondExpr (exprf e1, fmap exprf e2, exprf e3)
      | Sequence (e1, e2)        -> Sequence (exprf e1, exprf e2)
      | Assignment (e1, op, e2)  -> Assignment (exprf e1, op, exprf e2)
          
      | Postfix  (e, op) -> Postfix (exprf e, op)
      | Infix    (e, op) -> Infix   (exprf e, op)
      | Unary    (e, op) -> Unary   (exprf e, op)
      | Binary   (e1, op, e2) -> Binary (exprf e1, op, exprf e2)
          
      | ArrayAccess    (e1, e2) -> ArrayAccess (exprf e1, exprf e2)
      | RecordAccess   (e, s) -> RecordAccess     (exprf e, s) 
      | RecordPtAccess (e, s) -> RecordPtAccess   (exprf e, s) 

      | SizeOfExpr  (e) -> SizeOfExpr   (exprf e)
      | SizeOfType  (t) -> SizeOfType (vk_type_s bigf t)
      | Cast    (t, e) ->  Cast   (vk_type_s bigf t, exprf e)

      | StatementExpr (statxs, is) -> 
          StatementExpr (
            statxs +> List.map (vk_statement_sequencable_s bigf),
            iif is)
      | GccConstructor (t, initxs) -> 
          GccConstructor 
            (vk_type_s bigf t, 
            (initxs +> List.map (fun (ini, ii) -> 
              vk_ini_s bigf ini, vk_ii_s bigf ii) 
            ))
                      
      | ParenExpr (e) -> ParenExpr (exprf e)

      | (Throw _|DeleteArray (_, _)|Delete (_, _)|TypeIdOfType _|TypeIdOfExpr _|
ConstructedObject (_, _)|CplusplusCast (_, _, _)|RecordPtStarAccess (_, _)|
RecordStarAccess (_, _)|New|This)
          -> raise Todo

    in
    (e', typ'), (iif ii)
  in exprf expr

and vk_argument_s bigf argument = 
  let iif ii = vk_ii_s bigf ii in
  let rec do_action = function 
    | (ActMisc ii) -> ActMisc (iif ii)
  in
  (match argument with
  | Left e -> Left (vk_expr_s bigf e)
  | Right (ArgType param) ->    Right (ArgType (vk_param_s bigf param))
  | Right (ArgAction action) -> Right (ArgAction (do_action action))
  )






and vk_statement_s = fun bigf (st: statement) -> 
  let rec statf st = bigf.kstatement_s (k, bigf) st 
  and k st = 
    let (unwrap_st, ii) = st in
    let st' = 
      match unwrap_st with
      | Labeled (Label (s, st)) -> 
          Labeled (Label (s, statf st))
      | Labeled (Case  (e, st)) -> 
          Labeled (Case  ((vk_expr_s bigf) e , statf st))
      | Labeled (CaseRange  (e, e2, st)) -> 
          Labeled (CaseRange  ((vk_expr_s bigf) e, 
                              (vk_expr_s bigf) e2, 
                              statf st))
      | Labeled (Default st) -> Labeled (Default (statf st))
      | Compound statxs -> 
          Compound (statxs +> List.map (vk_statement_sequencable_s bigf))
      | ExprStatement (None) ->  ExprStatement (None)
      | ExprStatement (Some e) -> ExprStatement (Some ((vk_expr_s bigf) e))
      | Selection (If (e, st1, st2)) -> 
          Selection  (If ((vk_expr_s bigf) e, statf st1, statf st2))
      | Selection (Switch (e, st))   -> 
          Selection  (Switch ((vk_expr_s bigf) e, statf st))
      | Iteration (While (e, st))    -> 
          Iteration  (While ((vk_expr_s bigf) e, statf st))
      | Iteration (DoWhile (st, e))  -> 
          Iteration  (DoWhile (statf st, (vk_expr_s bigf) e))
      | Iteration (For ((e1opt,i1), (e2opt,i2), (e3opt,i3), st)) -> 
          let e1opt' = statf (ExprStatement (e1opt),i1) in
          let e2opt' = statf (ExprStatement (e2opt),i2) in
          let e3opt' = statf (ExprStatement (e3opt),i3) in
          (match (e1opt', e2opt', e3opt') with
          | ((ExprStatement x1,i1), (ExprStatement x2,i2), ((ExprStatement x3,i3))) -> 
              Iteration (For ((x1,i1), (x2,i2), (x3,i3), statf st))
          | x -> failwith "cant be here if iterator keep ExprStatement as is"
         )

      | Iteration  (MacroIteration (s, es, st)) -> 
          Iteration 
            (MacroIteration
                (s,
                es +> List.map (fun (e, ii) -> 
                  vk_argument_s bigf e, vk_ii_s bigf ii
                ), 
                statf st
                ))

            
      | Jump (Goto s) -> Jump (Goto s)
      | Jump (((Continue|Break|Return) as x)) -> Jump (x)
      | Jump (ReturnExpr e) -> Jump (ReturnExpr ((vk_expr_s bigf) e))
      | Jump (GotoComputed e) -> Jump (GotoComputed (vk_expr_s bigf e));

      | MacroStmt -> MacroStmt

      | (Try (_, _)|NestedFunc _|DeclStmt _)
          -> raise Todo
    in
    st', vk_ii_s bigf ii
  in statf st


and vk_statement_sequencable_s = fun bigf stseq -> 
  match stseq with
  | StmtElem st -> 
      StmtElem (vk_statement_s bigf st)
  | CppDirectiveStmt directive -> 
      CppDirectiveStmt (vk_cpp_directive_s bigf directive)
  | IfdefStmt ifdef -> 
      IfdefStmt (vk_ifdef_directive_s bigf ifdef)

and vk_asmbody_s = fun bigf (string_list, colon_list) -> 
  let  iif ii = vk_ii_s bigf ii in

  iif string_list,
  colon_list +> List.map (fun (Colon xs, ii) -> 
    Colon 
      (xs +> List.map (fun (x, iicomma) -> 
        (match x with
        | ColonMisc, ii -> ColonMisc, iif ii 
        | ColonExpr e, ii -> ColonExpr (vk_expr_s bigf e), iif ii
        ), iif iicomma
      )), 
    iif ii 
  )
    
  


and vk_type_s = fun bigf t -> 
  let rec typef t = bigf.ktype_s (k,bigf) t
  and iif ii = vk_ii_s bigf ii
  and k t = 
    let (q, t) = t in
    let (unwrap_q, iiq) = q in
    let q' = unwrap_q in     (* todo? a visitor for qualifier *)
    let (unwrap_t, iit) = t in
    let t' = 
      match unwrap_t with
      | BaseType x -> BaseType x
      | Pointer t  -> Pointer (typef t)
      | Array (eopt, t) -> Array (fmap (vk_expr_s bigf) eopt, typef t) 
      | FunctionType (returnt, paramst) -> 
          FunctionType 
            (typef returnt, 
            (match paramst with
            | (ts, (b, iihas3dots)) -> 
                (ts +> List.map (fun (param,iicomma) -> 
                  (vk_param_s bigf param, iif iicomma)),
                (b, iif iihas3dots))
            ))

      | Enum  (sopt, enumt) -> 
          Enum (sopt,
               enumt +> List.map (fun (((s, eopt),ii_s_eq), iicomma) -> 
                 ((s, fmap (vk_expr_s bigf) eopt), iif ii_s_eq),
                 iif iicomma
               )
          )

      | StructUnionName (s, structunion) -> StructUnionName (s, structunion)
      | EnumName  s -> EnumName  s
      | TypeName (s, typ) -> TypeName (s, typ)

      | ParenType t -> ParenType (typef t)
      | TypeOfExpr e -> TypeOfExpr (vk_expr_s bigf e)
      | TypeOfType t -> TypeOfType (typef t)

      | (TypenameKwd _|TypeTemplate (_, _)|StructUnion _|Reference _) -> 
          raise Todo
    in
    (q', iif iiq), 
  (t', iif iit)


  in typef t

and vk_vdecl_s = fun bigf d -> 
  let f = bigf.kvdecl_s in 
  let iif ii = vk_ii_s bigf ii in
  let rec k decl = 
    match decl with
    | DeclList (xs, ii) -> 
        DeclList (List.map aux xs,   iif ii)
    | MacroDecl ((s, args),ii) -> 
        MacroDecl 
          ((s, 
           args +> List.map (fun (e,ii) -> vk_argument_s bigf e, iif ii)
           ),
          iif ii)


  and aux ((var, t, sto), iicomma) = 
    ((var +> map_option (fun ((s, ini), ii_s_ini) -> 
      (s, ini +> map_option (fun init -> vk_ini_s bigf init)),
      iif ii_s_ini
    )
    ),
    vk_type_s bigf t, 
    sto),
  iif iicomma

  in f (k, bigf) d 

and vk_ini_s = fun bigf ini -> 
  let rec inif ini = bigf.kini_s (k,bigf) ini
  and k ini = 
    let (unwrap_ini, ii) = ini in
    let ini' = 
      match unwrap_ini with
      | InitExpr e -> InitExpr (vk_expr_s bigf e)
      | InitList initxs -> 
          InitList (initxs +> List.map (fun (ini, ii) -> 
            inif ini, vk_ii_s bigf ii) 
          )


      | InitDesignators (xs, e) -> 
          InitDesignators 
            (xs +> List.map (vk_designator_s bigf),
            inif e 
            )

    | InitFieldOld (s, e) -> InitFieldOld (s, inif e)
    | InitIndexOld (e1, e) -> InitIndexOld (vk_expr_s bigf e1, inif e)

    in ini', vk_ii_s bigf ii
  in inif ini


and vk_designator_s = fun bigf design -> 
  let iif ii = vk_ii_s bigf ii in
  let (designator, ii) = design in
  (match designator with
  | DesignatorField s -> DesignatorField s
  | DesignatorIndex e -> DesignatorIndex (vk_expr_s bigf e)
  | DesignatorRange (e1, e2) -> 
      DesignatorRange (vk_expr_s bigf e1, vk_expr_s bigf e2)
  ), iif ii




and vk_def_s = fun bigf d -> 
  let f = bigf.kdef_s in
  let iif ii = vk_ii_s bigf ii in
  let rec k d = 
    match d with
    | (s, (returnt, (paramst, (b, iib))), sto, statxs), ii  -> 
        (s, 
        (vk_type_s bigf returnt, 
        (paramst +> List.map (fun (param, iicomma) ->
          (vk_param_s bigf param, iif iicomma)
        ), 
        (b, iif iib))), 
        sto, 
        statxs +> List.map (vk_statement_sequencable_s bigf) 
        ),
        iif ii

  in f (k, bigf) d 

and vk_toplevel_s = fun bigf p -> 
  let f = bigf.ktoplevel_s in
  let iif ii = vk_ii_s bigf ii in
  let rec k p = 
    match p with
    | TopDecl d -> raise Todo 

    | EmptyDef ii -> EmptyDef (iif ii)
    | MacroTop (s, xs, ii) -> 
        MacroTop
          (s, 
          xs +> List.map (fun (elem, iicomma) -> 
            vk_argument_s bigf elem, iif iicomma
          ),
          iif ii
          )
    | CppTop top -> CppTop (vk_cpp_directive_s bigf top)
    | IfdefTop ifdefdir -> IfdefTop (vk_ifdef_directive_s bigf ifdefdir)

    | NotParsedCorrectly ii -> NotParsedCorrectly (iif ii)
    | FinalDef info -> FinalDef (vk_info_s bigf info)
  in f (k, bigf) p


and vk_cpp_directive_s = fun bigf top ->
  let iif ii = vk_ii_s bigf ii in
  let f = bigf.kcppdirective_s in
  let rec k top = 
  match top with 
    | Include ((s, ii), h_rel_pos) -> Include ((s, iif ii), h_rel_pos)
    | Define ((s,ii), (defkind, defval)) -> 
        Define ((s, iif ii), 
               (vk_define_kind_s bigf defkind, vk_define_val_s bigf defval))
    | Undef (s, ii) -> Undef (s, iif ii)
    | PragmaAndCo (ii) -> PragmaAndCo (iif ii)

  in f (k, bigf) top

and vk_ifdef_directive_s = fun bigf ifdef -> 
  let iif ii = vk_ii_s bigf ii in
  match ifdef with
  | IfdefDirective ii -> IfdefDirective (iif ii)



and vk_define_kind_s  = fun bigf defkind -> 
  match defkind with
  | DefineVar -> DefineVar 
  | DefineFunc (params, ii) -> 
      DefineFunc 
        (params +> List.map (fun ((s,iis),iicomma) -> 
          ((s, vk_ii_s bigf iis), vk_ii_s bigf iicomma)
        ),
        vk_ii_s bigf ii
        )


and vk_define_val_s = fun bigf x -> 
  let f = bigf.kdefineval_s in
  let iif ii = vk_ii_s bigf ii in
  let rec k x = 
    match x with
    | DefineExpr e  -> DefineExpr (vk_expr_s bigf e)
    | DefineStmt st -> DefineStmt (vk_statement_s bigf st)
    | DefineDoWhileZero (st,ii) -> 
        DefineDoWhileZero (vk_statement_s bigf st, iif ii)
    | DefineFunction def -> DefineFunction (vk_def_s bigf def)
    | DefineType ty -> DefineType (vk_type_s bigf ty)
    | DefineText (s, ii) -> DefineText (s, iif ii)
    | DefineEmpty -> DefineEmpty
    | DefineInit ini -> DefineInit (vk_ini_s bigf ini)

    | DefineTodo -> 
        pr2 "DefineTodo";
        DefineTodo
  in
  f (k, bigf) x
  

and vk_info_s = fun bigf info -> 
  let rec infof ii = bigf.kinfo_s (k, bigf) ii
  and k i = i
  in
  infof info

and vk_ii_s = fun bigf ii -> 
  List.map (vk_info_s bigf) ii

(* ------------------------------------------------------------------------ *)
and vk_node_s = fun bigf node -> 
  let iif ii = vk_ii_s bigf ii in
  let infof info = vk_info_s bigf info  in

  let rec nodef n = bigf.knode_s (k, bigf) n
  and k node = 
    F.rewrap node (
    match F.unwrap node with
    | F.FunHeader ((idb, (rett, (paramst,(isvaargs,iidotsb))), stob),ii) ->
        F.FunHeader 
          ((idb,
           (vk_type_s bigf rett,
           (paramst +> List.map (fun (param, iicomma) ->
             (vk_param_s bigf param, iif iicomma)
           ), (isvaargs,iif iidotsb))), stob),iif ii)
          
          
    | F.Decl declb -> F.Decl (vk_vdecl_s bigf declb)
    | F.ExprStatement (st, (eopt, ii)) ->  
        F.ExprStatement (st, (eopt +> map_option (vk_expr_s bigf), iif ii))
          
    | F.IfHeader (st, (e,ii))     -> 
        F.IfHeader    (st, (vk_expr_s bigf e, iif ii))
    | F.SwitchHeader (st, (e,ii)) -> 
        F.SwitchHeader(st, (vk_expr_s bigf e, iif ii))
    | F.WhileHeader (st, (e,ii))  -> 
        F.WhileHeader (st, (vk_expr_s bigf e, iif ii))
    | F.DoWhileTail (e,ii)  -> 
        F.DoWhileTail (vk_expr_s bigf e, iif ii)

    | F.ForHeader (st, (((e1opt,i1), (e2opt,i2), (e3opt,i3)), ii)) -> 
        F.ForHeader (st,
                    (((e1opt +> Common.map_option (vk_expr_s bigf), iif i1),
                     (e2opt +> Common.map_option (vk_expr_s bigf), iif i2),
                     (e3opt +> Common.map_option (vk_expr_s bigf), iif i3)),
                    iif ii))

    | F.MacroIterHeader (st, ((s,es), ii)) -> 
        F.MacroIterHeader
          (st,
          ((s, es +> List.map (fun (e, ii) -> vk_argument_s bigf e, iif ii)),
          iif ii))

          
    | F.ReturnExpr (st, (e,ii)) -> 
        F.ReturnExpr (st, (vk_expr_s bigf e, iif ii))
        
    | F.Case  (st, (e,ii)) -> F.Case (st, (vk_expr_s bigf e, iif ii))
    | F.CaseRange (st, ((e1, e2),ii)) -> 
        F.CaseRange (st, ((vk_expr_s bigf e1, vk_expr_s bigf e2), iif ii))

    | F.CaseNode i -> F.CaseNode i

    | F.DefineHeader((s,ii), (defkind)) -> 
        F.DefineHeader ((s, iif ii), (vk_define_kind_s bigf defkind))

    | F.DefineExpr e -> F.DefineExpr (vk_expr_s bigf e)
    | F.DefineType ft -> F.DefineType (vk_type_s bigf ft)
    | F.DefineDoWhileZeroHeader ((),ii) -> 
        F.DefineDoWhileZeroHeader ((),iif ii)

    | F.Include ((s, ii), h_rel_pos) -> F.Include ((s, iif ii), h_rel_pos)
    | F.Ifdef (st, ((),ii)) -> F.Ifdef (st, ((),iif ii))
    | F.MacroTop (s, args, ii) -> 
        F.MacroTop 
          (s,
          args +> List.map (fun (e, ii) -> vk_argument_s bigf e, iif ii),
          iif ii)


    | F.MacroStmt (st, ((),ii)) -> F.MacroStmt (st, ((),iif ii))
    | F.Asm (st, (body,ii)) -> F.Asm (st, (vk_asmbody_s bigf body,iif ii))

    | F.Break    (st,((),ii)) -> F.Break    (st,((),iif ii))
    | F.Continue (st,((),ii)) -> F.Continue (st,((),iif ii))
    | F.Default  (st,((),ii)) -> F.Default  (st,((),iif ii))
    | F.Return   (st,((),ii)) -> F.Return   (st,((),iif ii))
    | F.Goto  (st, (s,ii)) -> F.Goto  (st, (s,iif ii))
    | F.Label (st, (s,ii)) -> F.Label (st, (s,iif ii))
    | F.EndStatement iopt -> F.EndStatement (map_option infof iopt)
    | F.DoHeader (st, info) -> F.DoHeader (st, infof info)
    | F.Else info -> F.Else (infof info)
    | F.SeqEnd (i, info) -> F.SeqEnd (i, infof info)
    | F.SeqStart (st, i, info) -> F.SeqStart (st, i, infof info)

    | (
        (
          F.TopNode|F.EndNode|
          F.ErrorExit|F.Exit|F.Enter|
          F.FallThroughNode|F.AfterNode|F.FalseNode|F.TrueNode|F.InLoopNode|
          F.Fake
        ) as x) -> x


    )
  in
  nodef node
  
(* ------------------------------------------------------------------------ *)
and vk_param_s = fun bigf ((b, s, t), ii_b_s) -> 
  let iif ii = vk_ii_s bigf ii in
  ((b, s, vk_type_s bigf t), iif ii_b_s)
        
let vk_args_splitted_s = fun bigf args_splitted -> 
  let iif ii = vk_ii_s bigf ii in
  args_splitted +> List.map (function  
  | Left arg -> Left (vk_argument_s bigf arg)
  | Right ii -> Right (iif ii)
  )

let vk_arguments_s = fun bigf args -> 
  let iif ii = vk_ii_s bigf ii in
  args +> List.map (fun (e, ii) -> vk_argument_s bigf e, iif ii)


let vk_params_splitted_s = fun bigf args_splitted -> 
  let iif ii = vk_ii_s bigf ii in
  args_splitted +> List.map (function  
  | Left arg -> Left (vk_param_s bigf arg)
  | Right ii -> Right (iif ii)
  )

let vk_params_s = fun bigf args -> 
  let iif ii = vk_ii_s bigf ii in
  args +> List.map (fun (p,ii) -> vk_param_s bigf p, iif ii)

let vk_define_params_splitted_s = fun bigf args_splitted -> 
  let iif ii = vk_ii_s bigf ii in
  args_splitted +> List.map (function  
  | Left (s, iis) -> Left (s, vk_ii_s bigf iis)
  | Right ii -> Right (iif ii)
  )

let vk_cst_s = fun bigf (cst, ii) -> 
  let iif ii = vk_ii_s bigf ii in
  (match cst with
  | Left cst -> Left cst 
  | Right s -> Right s
  ), iif ii
