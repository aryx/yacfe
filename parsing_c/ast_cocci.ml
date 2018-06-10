(* Copyright (C) 2006, 2007 Julia Lawall
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License (GPL)
 * version 2 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * file license.txt for more details.
 * 
 * This file was part of Coccinelle.
 *)

(* old: simplified
 *
 * type mcodekind = 
 * CONTEXT of pos * unit befaft
 * and pos = NoPos | DontCarePos | FixPos of (int * int)
 * 
 * and meta_name = ()
 * 
 * and 'a befaft =
 * BEFORE      of 'a list list
 * | AFTER       of 'a list list
 * | BEFOREAFTER of 'a list list * 'a list list
 * | NOTHING
 * 
 * 
 * 
 * and fixpos =
 * Real of int (* charpos *) | Virt of int * int (* charpos + offset *)
 *)


(* --------------------------------------------------------------------- *)
(* Modified code *)

type info = { line : int; column : int;
	      strbef : (string * int (* line *) * int (* col *)) list;
	      straft : (string * int (* line *) * int (* col *)) list }
type line = int
type meta_name = string * string
(* need to be careful about rewrapping, to avoid duplicating pos info
currently, the pos info is always None until asttoctl2. *)
type 'a wrap =
    {node : 'a;
      node_line : line;
      free_vars : meta_name list; (*free vars*)
      minus_free_vars : meta_name list; (*minus free vars*)
      fresh_vars : (meta_name * string (*seed*) option) list; (*fresh vars*)
      inherited : meta_name list; (*inherited vars*)
      saved_witness : meta_name list; (*witness vars*)
      bef_aft : dots_bef_aft;
      (* the following is for or expressions *)
      pos_info : meta_name mcode option; (* pos info, try not to duplicate *)
      true_if_test_exp : bool;(* true if "test_exp from iso", only for exprs *)
      (* isos relevant to the term; ultimately only used for rule_elems *)
      iso_info : (string*anything) list }

and 'a befaft =
    BEFORE      of 'a list list
  | AFTER       of 'a list list
  | BEFOREAFTER of 'a list list * 'a list list
  | NOTHING

and 'a mcode = 'a * info * mcodekind * meta_pos (* pos variable *)
 (* pos is an offset indicating where in the C code the mcodekind has an
 effect *)
 and mcodekind =
    MINUS       of pos * anything list list
  | CONTEXT     of pos * anything befaft
  | PLUS
 and fixpos =
    Real of int (* charpos *) | Virt of int * int (* charpos + offset *)
 and pos = NoPos | DontCarePos | FixPos of (fixpos * fixpos)

and dots_bef_aft =
    NoDots
  | AddingBetweenDots of statement * int (*index of let var*)
  | DroppingBetweenDots of statement * int (*index of let var*)

and inherited = Type_cocci.inherited
and keep_binding = Type_cocci.keep_binding
and multi = bool (*true if a nest is one or more, false if it is zero or more*)

and end_info =
    meta_name list (*free vars*) * (meta_name * string option) list (*fresh*) *
      meta_name list (*inherited vars*) * mcodekind

(* --------------------------------------------------------------------- *)
(* Metavariables *)

and arity = UNIQUE | OPT | MULTI | NONE

and metavar =
    MetaIdDecl of arity * meta_name (* name *)
  | MetaFreshIdDecl of meta_name (* name *) * string option (* seed *)
  | MetaTypeDecl of arity * meta_name (* name *)
  | MetaInitDecl of arity * meta_name (* name *)
  | MetaListlenDecl of meta_name (* name *)
  | MetaParamDecl of arity * meta_name (* name *)
  | MetaParamListDecl of arity * meta_name (*name*) * meta_name option (*len*)
  | MetaConstDecl of
      arity * meta_name (* name *) * Type_cocci.typeC list option
  | MetaErrDecl of arity * meta_name (* name *)
  | MetaExpDecl of
      arity * meta_name (* name *) * Type_cocci.typeC list option
  | MetaIdExpDecl of
      arity * meta_name (* name *) * Type_cocci.typeC list option
  | MetaLocalIdExpDecl of
      arity * meta_name (* name *) * Type_cocci.typeC list option
  | MetaExpListDecl of arity * meta_name (*name*) * meta_name option (*len*)
  | MetaStmDecl of arity * meta_name (* name *)
  | MetaStmListDecl of arity * meta_name (* name *)
  | MetaFuncDecl of arity * meta_name (* name *)
  | MetaLocalFuncDecl of arity * meta_name (* name *)
  | MetaPosDecl of arity * meta_name (* name *)
  | MetaDeclarerDecl of arity * meta_name (* name *)
  | MetaIteratorDecl of arity * meta_name (* name *)

(* --------------------------------------------------------------------- *)
(* --------------------------------------------------------------------- *)
(* Dots *)

and 'a base_dots =
    DOTS of 'a list
  | CIRCLES of 'a list
  | STARS of 'a list

and 'a dots = 'a base_dots wrap

(* --------------------------------------------------------------------- *)
(* Identifier *)

and base_ident =
    Id of string mcode

  | MetaId        of meta_name mcode * ident list * keep_binding * inherited
  | MetaFunc      of meta_name mcode * ident list * keep_binding * inherited
  | MetaLocalFunc of meta_name mcode * ident list * keep_binding * inherited

  | OptIdent      of ident
  | UniqueIdent   of ident

and ident = base_ident wrap

(* --------------------------------------------------------------------- *)
(* Expression *)

and base_expression =
    Ident          of ident
  | Constant       of constant mcode
  | FunCall        of expression * string mcode (* ( *) *
                      expression dots * string mcode (* ) *)
  | Assignment     of expression * assignOp mcode * expression *
	              bool (* true if it can match an initialization *)
  | CondExpr       of expression * string mcode (* ? *) * expression option *
	              string mcode (* : *) * expression
  | Postfix        of expression * fixOp mcode
  | Infix          of expression * fixOp mcode
  | Unary          of expression * unaryOp mcode
  | Binary         of expression * binaryOp mcode * expression
  | Nested         of expression * binaryOp mcode * expression
  | ArrayAccess    of expression * string mcode (* [ *) * expression *
	              string mcode (* ] *)
  | RecordAccess   of expression * string mcode (* . *) * ident
  | RecordPtAccess of expression * string mcode (* -> *) * ident
  | Cast           of string mcode (* ( *) * fullType * string mcode (* ) *) *
                      expression
  | SizeOfExpr     of string mcode (* sizeof *) * expression
  | SizeOfType     of string mcode (* sizeof *) * string mcode (* ( *) *
                      fullType * string mcode (* ) *)
  | TypeExp        of fullType (*type name used as an expression, only in
				  arg or #define*)

  | Paren          of string mcode (* ( *) * expression *
                      string mcode (* ) *)

  | MetaErr        of meta_name mcode * expression list * keep_binding *
	              inherited
  | MetaExpr       of meta_name mcode * expression list * keep_binding *
	              Type_cocci.typeC list option * form * inherited
  | MetaExprList   of meta_name mcode * listlen option * keep_binding *
                      inherited (* only in arg lists *)

  | EComma         of string mcode (* only in arg lists *)

  | DisjExpr       of expression list
  | NestExpr       of expression dots * expression option * multi

  (* can appear in arg lists, and also inside Nest, as in:
   if(< ... X ... Y ...>)
   In the following, the expression option is the WHEN  *)
  | Edots          of string mcode (* ... *) * expression option
  | Ecircles       of string mcode (* ooo *) * expression option
  | Estars         of string mcode (* *** *) * expression option

  | OptExp         of expression
  | UniqueExp      of expression

(* ANY = int E; ID = idexpression int X; CONST = constant int X; *)
and form = ANY | ID | LocalID | CONST (* form for MetaExp *)

and expression = base_expression wrap

and listlen = meta_name mcode * keep_binding * inherited

and  unaryOp = GetRef | DeRef | UnPlus |  UnMinus | Tilde | Not
and  assignOp = SimpleAssign | OpAssign of arithOp
and  fixOp = Dec | Inc

and  binaryOp = Arith of arithOp | Logical of logicalOp
and  arithOp =
    Plus | Minus | Mul | Div | Mod | DecLeft | DecRight | And | Or | Xor
and  logicalOp = Inf | Sup | InfEq | SupEq | Eq | NotEq | AndLog | OrLog

and constant =
    String of string
  | Char   of string
  | Int    of string
  | Float  of string

(* --------------------------------------------------------------------- *)
(* Types *)

and base_fullType =
    Type            of const_vol mcode option * typeC
  | DisjType        of fullType list (* only after iso *)
  | OptType         of fullType
  | UniqueType      of fullType

and base_typeC =
    BaseType        of baseType * string mcode list (* Yoann style *)
  | SignedT         of sign mcode * typeC option
  | Pointer         of fullType * string mcode (* * *)
  | FunctionPointer of fullType *
	          string mcode(* ( *)*string mcode(* * *)*string mcode(* ) *)*
                  string mcode (* ( *)*parameter_list*string mcode(* ) *)

  (* used for the automatic managment of prototypes *)
  | FunctionType     of bool (* true if all minus for dropping return type *) *
                   fullType option *
	           string mcode (* ( *) * parameter_list *
                   string mcode (* ) *)

  | Array           of fullType * string mcode (* [ *) *
	               expression option * string mcode (* ] *)
  | EnumName        of string mcode (*enum*) * ident (* name *)
  | StructUnionName of structUnion mcode * ident option (* name *)
  | StructUnionDef  of fullType (* either StructUnionName or metavar *) *
	string mcode (* { *) * declaration dots * string mcode (* } *)
  | TypeName        of string mcode (* pad: should be 'of ident' ? *)

  | MetaType        of meta_name mcode * keep_binding * inherited

and fullType = base_fullType wrap
and typeC = base_typeC wrap

and baseType = VoidType | CharType | ShortType | IntType | DoubleType
  | FloatType | LongType | LongLongType

and structUnion = Struct | Union

and sign = Signed | Unsigned

and const_vol = Const | Volatile

(* --------------------------------------------------------------------- *)
(* Variable declaration *)
(* Even if the Cocci program specifies a list of declarations, they are
   split out into multiple declarations of a single variable each. *)

and base_declaration =
    Init of storage mcode option * fullType * ident * string mcode (*=*) *
	initialiser * string mcode (*;*)
  | UnInit of storage mcode option * fullType * ident * string mcode (* ; *)
  | TyDecl of fullType * string mcode (* ; *)
  | MacroDecl of ident (* name *) * string mcode (* ( *) *
        expression dots * string mcode (* ) *) * string mcode (* ; *)
  | Typedef of string mcode (*typedef*) * fullType *
               typeC (* either TypeName or metavar *) * string mcode (*;*)
  | DisjDecl of declaration list
  (* Ddots is for a structure declaration *)
  | Ddots    of string mcode (* ... *) * declaration option (* whencode *)

  | MetaDecl of meta_name mcode * keep_binding * inherited

  | OptDecl    of declaration
  | UniqueDecl of declaration

and declaration = base_declaration wrap

(* --------------------------------------------------------------------- *)
(* Initializers *)

and base_initialiser =
    MetaInit of meta_name mcode * keep_binding * inherited
  | InitExpr of expression
  | InitList of string mcode (*{*) * initialiser list * string mcode (*}*) *
	initialiser list (* whencode: elements that shouldn't appear in init *)
  | InitGccExt of
      designator list (* name *) * string mcode (*=*) *
	initialiser (* gccext: *)
  | InitGccName of ident (* name *) * string mcode (*:*) *
	initialiser
  | IComma of string mcode (* , *)

  | OptIni    of initialiser
  | UniqueIni of initialiser

and designator =
    DesignatorField of string mcode (* . *) * ident
  | DesignatorIndex of string mcode (* [ *) * expression * string mcode (* ] *)
  | DesignatorRange of
      string mcode (* [ *) * expression * string mcode (* ... *) *
      expression * string mcode (* ] *)

and initialiser = base_initialiser wrap

(* --------------------------------------------------------------------- *)
(* Parameter *)

and base_parameterTypeDef =
    VoidParam     of fullType
  | Param         of fullType * ident option

  | MetaParam     of meta_name mcode * keep_binding * inherited
  | MetaParamList of meta_name mcode * listlen option * keep_binding *
	             inherited

  | PComma        of string mcode

  | Pdots         of string mcode (* ... *)
  | Pcircles      of string mcode (* ooo *)

  | OptParam      of parameterTypeDef
  | UniqueParam   of parameterTypeDef

and parameterTypeDef = base_parameterTypeDef wrap

and parameter_list = parameterTypeDef dots

(* --------------------------------------------------------------------- *)
(* #define Parameters *)

and base_define_param =
    DParam        of ident
  | DPComma       of string mcode
  | DPdots        of string mcode (* ... *)
  | DPcircles     of string mcode (* ooo *)
  | OptDParam     of define_param
  | UniqueDParam  of define_param

and define_param = base_define_param wrap

and base_define_parameters =
    NoParams     (* not parameter list, not an empty one *)
  | DParams      of string mcode(*( *) * define_param dots * string mcode(* )*)

and define_parameters = base_define_parameters wrap

(* --------------------------------------------------------------------- *)
(* positions *)

(* PER = keep bindings separate, ALL = collect them *)
and meta_collect = PER | ALL

and meta_pos =
    MetaPos of meta_name mcode * meta_name list *
	meta_collect * keep_binding * inherited
  | NoMetaPos

(* --------------------------------------------------------------------- *)
(* Function declaration *)

and storage = Static | Auto | Register | Extern

(* --------------------------------------------------------------------- *)
(* Top-level code *)

and base_rule_elem =
    FunHeader     of mcodekind (* before the function header *) *
	             bool (* true if all minus, for dropping static, etc *) *
	             fninfo list * ident (* name *) *
	             string mcode (* ( *) * parameter_list *
                     string mcode (* ) *)
  | Decl          of mcodekind (* before the decl *) *
                     bool (* true if all minus *) * declaration

  | SeqStart      of string mcode (* { *)
  | SeqEnd        of string mcode (* } *)

  | ExprStatement of expression * string mcode (*;*)
  | IfHeader      of string mcode (* if *) * string mcode (* ( *) *
	             expression * string mcode (* ) *)
  | Else          of string mcode (* else *)
  | WhileHeader   of string mcode (* while *) * string mcode (* ( *) *
	             expression * string mcode (* ) *)
  | DoHeader      of string mcode (* do *)
  | WhileTail     of string mcode (* while *) * string mcode (* ( *) *
	             expression * string mcode (* ) *) *
                     string mcode (* ; *)
  | ForHeader     of string mcode (* for *) * string mcode (* ( *) *
                     expression option * string mcode (*;*) *
	             expression option * string mcode (*;*) *
                     expression option * string mcode (* ) *)
  | IteratorHeader of ident (* name *) * string mcode (* ( *) *
	             expression dots * string mcode (* ) *)
  | SwitchHeader  of string mcode (* switch *) * string mcode (* ( *) *
	             expression * string mcode (* ) *)
  | Break         of string mcode (* break *) * string mcode (* ; *)
  | Continue      of string mcode (* continue *) * string mcode (* ; *)
  | Label         of ident * string mcode (* : *)
  | Goto          of string mcode (* goto *) * ident * string mcode (* ; *)
  | Return        of string mcode (* return *) * string mcode (* ; *)
  | ReturnExpr    of string mcode (* return *) * expression *
	             string mcode (* ; *)

  | MetaRuleElem  of meta_name mcode * keep_binding * inherited
  | MetaStmt      of meta_name mcode * keep_binding * metaStmtInfo *
	             inherited
  | MetaStmtList  of meta_name mcode * keep_binding * inherited

  | Exp           of expression (* matches a subterm *)
  | TopExp        of expression (* for macros body, exp at top level,
				   not subexp *)
  | Ty            of fullType (* only at SP top level, matches a subterm *)
  | TopInit       of initialiser (* only at top level *)
  | Include       of string mcode (*#include*) * inc_file mcode (*file *)
  | DefineHeader  of string mcode (* #define *) * ident (* name *) *
	             define_parameters (*params*)
  | Case          of string mcode (* case *) * expression * string mcode (*:*)
  | Default       of string mcode (* default *) * string mcode (*:*)
  | DisjRuleElem  of rule_elem list

and fninfo =
    FStorage of storage mcode
  | FType of fullType
  | FInline of string mcode
  | FAttr of string mcode

and metaStmtInfo =
    NotSequencible | SequencibleAfterDots of dots_whencode list | Sequencible

and rule_elem = base_rule_elem wrap

and base_statement =
    Seq           of rule_elem (* { *) * statement dots *
	             statement dots * rule_elem (* } *)
  | IfThen        of rule_elem (* header *) * statement * end_info (* endif *)
  | IfThenElse    of rule_elem (* header *) * statement *
	             rule_elem (* else *) * statement * end_info (* endif *)
  | While         of rule_elem (* header *) * statement * end_info (*endwhile*)
  | Do            of rule_elem (* do *) * statement * rule_elem (* tail *)
  | For           of rule_elem (* header *) * statement * end_info (*endfor*)
  | Iterator      of rule_elem (* header *) * statement * end_info (*enditer*)
  | Switch        of rule_elem (* header *) * rule_elem (* { *) *
	             case_line list * rule_elem (* } *)
  | Atomic        of rule_elem
  | Disj          of statement dots list
  | Nest          of statement dots *
	             (statement dots,statement) whencode list * multi *
	             dots_whencode list * dots_whencode list
  | FunDecl       of rule_elem (* header *) * rule_elem (* { *) *
     	             statement dots * statement dots * rule_elem (* } *)
  | Define        of rule_elem (* header *) * statement dots
  | Dots          of string mcode (* ... *) *
	             (statement dots,statement) whencode list *
	             dots_whencode list * dots_whencode list
  | Circles       of string mcode (* ooo *) *
	             (statement dots,statement) whencode list *
	             dots_whencode list * dots_whencode list
  | Stars         of string mcode (* *** *) *
	             (statement dots,statement) whencode list *
	             dots_whencode list * dots_whencode list
  | OptStm        of statement
  | UniqueStm     of statement

and ('a,'b) whencode =
    WhenNot of 'a
  | WhenAlways of 'b
  | WhenModifier of when_modifier
  | WhenNotTrue of rule_elem (* useful for fvs *)
  | WhenNotFalse of rule_elem

and when_modifier =
  (* The following removes the shortest path constraint.  It can be used
     with other when modifiers *)
    WhenAny
  (* The following removes the special consideration of error paths.  It
     can be used with other when modifiers *)
  | WhenStrict
  | WhenForall
  | WhenExists

(* only used with asttoctl *)
and dots_whencode =
    WParen of rule_elem * meta_name (*pren_var*)
  | Other of statement
  | Other_dots of statement dots

and statement = base_statement wrap

and base_case_line =
    CaseLine of rule_elem (* case/default header *) * statement dots
  | OptCase of case_line

and case_line = base_case_line wrap

and inc_file =
    Local of inc_elem list
  | NonLocal of inc_elem list

and inc_elem =
    IncPath of string
  | IncDots

and base_top_level =
    DECL of statement
  | CODE of statement dots
  | FILEINFO of string mcode (* old file *) * string mcode (* new file *)
  | ERRORWORDS of expression list

and top_level = base_top_level wrap

and rulename =
    CocciRulename of string option * dependency *
	string list * string list * exists * bool
  | GeneratedRulename of string option * dependency *
	string list * string list * exists * bool
  | ScriptRulename of string * dependency
  | InitialScriptRulename of string
  | FinalScriptRulename of string

and ruletype = Normal | Generated

and rule =
    CocciRule of string (* name *) *
	(dependency * string list (* dropped isos *) * exists) * top_level list
	* bool list * ruletype
  | ScriptRule of string * dependency * (string * meta_name) list * string
  | InitialScriptRule of string (*language*) * string (*code*)
  | FinalScriptRule of string (*language*) * string (*code*)

and dependency =
    Dep of string (* rule applies for the current binding *)
  | AntiDep of string (* rule doesn't apply for the current binding *)
  | EverDep of string (* rule applies for some binding *)
  | NeverDep of string (* rule never applies for any binding *)
  | AndDep of dependency * dependency
  | OrDep of dependency * dependency
  | NoDep

and rule_with_metavars = metavar list * rule

and anything =
    FullTypeTag         of fullType
  | BaseTypeTag         of baseType
  | StructUnionTag      of structUnion
  | SignTag             of sign
  | IdentTag            of ident
  | ExpressionTag       of expression
  | ConstantTag         of constant
  | UnaryOpTag          of unaryOp
  | AssignOpTag         of assignOp
  | FixOpTag            of fixOp
  | BinaryOpTag         of binaryOp
  | ArithOpTag          of arithOp
  | LogicalOpTag        of logicalOp
  | DeclarationTag      of declaration
  | InitTag             of initialiser
  | StorageTag          of storage
  | IncFileTag          of inc_file
  | Rule_elemTag        of rule_elem
  | StatementTag        of statement
  | CaseLineTag         of case_line
  | ConstVolTag         of const_vol
  | Token               of string * info option
  | Pragma              of string list
  | Code                of top_level
  | ExprDotsTag         of expression dots
  | ParamDotsTag        of parameterTypeDef dots
  | StmtDotsTag         of statement dots
  | DeclDotsTag         of declaration dots
  | TypeCTag            of typeC
  | ParamTag            of parameterTypeDef
  | SgrepStartTag       of string
  | SgrepEndTag         of string

(* --------------------------------------------------------------------- *)

and exists = Exists | Forall | ReverseForall | Undetermined

(* --------------------------------------------------------------------- *)

let mkToken x = Token (x,None)

(* --------------------------------------------------------------------- *)

let rewrap model x         = {model with node = x}
let rewrap_mcode (_,a,b,c) x = (x,a,b,c)
let unwrap x               = x.node
let unwrap_mcode (x,_,_,_)  = x
let get_mcodekind (_,_,x,_) = x
let get_line x             = x.node_line
let get_mcode_line (_,l,_,_) = l.line
let get_fvs x              = x.free_vars
let set_fvs fvs x          = {x with free_vars = fvs}
let get_mfvs x             = x.minus_free_vars
let set_mfvs mfvs x        = {x with minus_free_vars = mfvs}
let get_fresh x            = x.fresh_vars
let get_inherited x        = x.inherited
let get_saved x            = x.saved_witness
let get_dots_bef_aft x     = x.bef_aft
let set_dots_bef_aft d x   = {x with bef_aft = d}
let get_pos x              = x.pos_info
let set_pos x pos          = {x with pos_info = pos}
let get_test_exp x      = x.true_if_test_exp
let set_test_exp x      = {x with true_if_test_exp = true}
let get_isos x             = x.iso_info
let set_isos x isos        = {x with iso_info = isos}
let get_pos_var (_,_,_,p)  = p
let set_pos_var vr (a,b,c,_) = (a,b,c,vr)
let drop_pos (a,b,c,_)     = (a,b,c,NoMetaPos)

let get_wcfvs (whencode : ('a wrap, 'b wrap) whencode list) =
  Common.union_all
    (List.map
       (function
	   WhenNot(a) -> get_fvs a
	 | WhenAlways(a) -> get_fvs a
	 | WhenModifier(_) -> []
	 | WhenNotTrue(e) -> get_fvs e
	 | WhenNotFalse(e) -> get_fvs e)
       whencode)

(* --------------------------------------------------------------------- *)

let get_meta_name = function
    MetaIdDecl(ar,nm) -> nm
  | MetaFreshIdDecl(nm,seed) -> nm
  | MetaTypeDecl(ar,nm) -> nm
  | MetaInitDecl(ar,nm) -> nm
  | MetaListlenDecl(nm) -> nm
  | MetaParamDecl(ar,nm) -> nm
  | MetaParamListDecl(ar,nm,nm1) -> nm
  | MetaConstDecl(ar,nm,ty) -> nm
  | MetaErrDecl(ar,nm) -> nm
  | MetaExpDecl(ar,nm,ty) -> nm
  | MetaIdExpDecl(ar,nm,ty) -> nm
  | MetaLocalIdExpDecl(ar,nm,ty) -> nm
  | MetaExpListDecl(ar,nm,nm1) -> nm
  | MetaStmDecl(ar,nm) -> nm
  | MetaStmListDecl(ar,nm) -> nm
  | MetaFuncDecl(ar,nm) -> nm
  | MetaLocalFuncDecl(ar,nm) -> nm
  | MetaPosDecl(ar,nm) -> nm
  | MetaDeclarerDecl(ar,nm) -> nm
  | MetaIteratorDecl(ar,nm) -> nm

(* --------------------------------------------------------------------- *)

let no_info = { line = 0; column = 0; strbef = []; straft = [] }

let make_term x =
  {node = x;
    node_line = 0;
    free_vars = [];
    minus_free_vars = [];
    fresh_vars = [];
    inherited = [];
    saved_witness = [];
    bef_aft = NoDots;
    pos_info = None;
    true_if_test_exp = false;
    iso_info = [] }

let make_meta_rule_elem s d (fvs,fresh,inh) =
  {(make_term
      (MetaRuleElem((("",s),no_info,d,NoMetaPos),Type_cocci.Unitary,false)))
  with free_vars = fvs; fresh_vars = fresh; inherited = inh}

let make_meta_decl s d (fvs,fresh,inh) =
  {(make_term
      (MetaDecl((("",s),no_info,d,NoMetaPos),Type_cocci.Unitary,false))) with
    free_vars = fvs; fresh_vars = fresh; inherited = inh}

let make_mcode x = (x,no_info,CONTEXT(NoPos,NOTHING),NoMetaPos)

(* --------------------------------------------------------------------- *)

let equal_pos x y = x = y

(* --------------------------------------------------------------------- *)

let undots x =
  match unwrap x with
    DOTS    e -> e
  | CIRCLES e -> e
  | STARS   e -> e
