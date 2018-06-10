%{
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
module Semantic_c = Semantic_cplusplus
module Flag_parsing_c = Flag_parsing_cplusplus

module LP = Lexer_parser2
open Lexer_parser2 (* for the fields *)

open Semantic_c (* Semantic exn *)

module Stat = Parsing_stat2

(*****************************************************************************)
(* Wrappers *)
(*****************************************************************************)
let warning s v = 
  if !Flag_parsing_c.verbose_parsing 
  then Common.warning ("PARSING: " ^ s) v
  else v


let pr2 s = 
  if !Flag_parsing_c.verbose_parsing 
  then Common.pr2 s

(*****************************************************************************)
(* Parse helpers functions *)
(*****************************************************************************)

(*-------------------------------------------------------------------------- *)
(* Type related *)
(*-------------------------------------------------------------------------- *)

type shortLong      = Short  | Long | LongLong

type decl = { 
  storageD: storagebis wrap;
  typeD: ((sign option) * (shortLong option) * (typeCbis option)) wrap;
  qualifD: typeQualifierbis wrap;
  inlineD: bool             wrap;
  (* note: have a full_info: parse_info list; to remember ordering
   * between storage, qualifier, type ? well this info is already in
   * the Ast_c.info, just have to sort them to get good order *)
} 

let nullDecl = {
  storageD = NoSto, [];
  typeD = (None, None, None), [];
  qualifD = nullQualif;
  inlineD = false, [];
}
let fake_pi = Common.fake_parse_info

let addStorageD  = function 
  | ((x,ii), ({storageD = (NoSto,[])} as v)) -> { v with storageD = (x, [ii]) }
  | ((x,ii), ({storageD = (y, ii2)} as v)) ->  
      if x = y then warning "duplicate storage classes" v
      else raise (Semantic ("multiple storage classes", fake_pi))

let addInlineD  = function 
  | ((true,ii), ({inlineD = (false,[])} as v)) -> { v with inlineD=(true,[ii])}
  | ((true,ii), ({inlineD = (true, ii2)} as v)) -> warning "duplicate inline" v
  | _ -> raise Impossible


let addTypeD     = function 
  | ((Left3 Signed,ii)   ,({typeD = ((Some Signed,  b,c),ii2)} as v)) -> 
      warning "duplicate 'signed'"   v
  | ((Left3 UnSigned,ii) ,({typeD = ((Some UnSigned,b,c),ii2)} as v)) -> 
      warning "duplicate 'unsigned'" v
  | ((Left3 _,ii),        ({typeD = ((Some _,b,c),ii2)} as _v)) -> 
      raise (Semantic ("both signed and unsigned specified", fake_pi))
  | ((Left3 x,ii),        ({typeD = ((None,b,c),ii2)} as v))   -> 
      {v with typeD = (Some x,b,c),ii ++ ii2}

  | ((Middle3 Short,ii),  ({typeD = ((a,Some Short,c),ii2)} as v)) -> 
      warning "duplicate 'short'" v

      
  (* gccext: long long allowed *)
  | ((Middle3 Long,ii),   ({typeD = ((a,Some Long ,c),ii2)} as v)) -> 
      { v with typeD = (a, Some LongLong, c),ii++ii2 }
  | ((Middle3 Long,ii),   ({typeD = ((a,Some LongLong ,c),ii2)} as v)) -> 
      warning "triplicate 'long'" v

  | ((Middle3 _,ii),      ({typeD = ((a,Some _,c),ii2)} as _v)) -> 
      raise (Semantic ("both long and short specified", fake_pi))
  | ((Middle3 x,ii),      ({typeD = ((a,None,c),ii2)} as v))  -> 
      {v with typeD = (a, Some x,c),ii++ii2}

  | ((Right3 t,ii),       ({typeD = ((a,b,Some _),ii2)} as _v)) -> 
      raise (Semantic ("two or more data types", fake_pi))
  | ((Right3 t,ii),       ({typeD = ((a,b,None),ii2)} as v))   -> 
      {v with typeD = (a,b, Some t),ii++ii2}


let addQualif = function
  | ({const=true},   ({const=true} as x)) ->   warning "duplicate 'const'" x
  | ({volatile=true},({volatile=true} as x))-> warning "duplicate 'volatile'" x
  | ({const=true},    v) -> {v with const=true}
  | ({volatile=true}, v) -> {v with volatile=true}
  | _ -> internal_error "there is no noconst or novolatile keyword"

let addQualifD ((qu,ii), ({qualifD = (v,ii2)} as x)) =
  { x with qualifD = (addQualif (qu, v),ii::ii2) }


(*-------------------------------------------------------------------------- *)
(* Declaration/Function related *)
(*-------------------------------------------------------------------------- *)


(* stdC: type section, basic integer types (and ritchie)
 * To understand the code, just look at the result (right part of the PM) 
 * and go back.
 *)
let (fixDeclSpecForDecl: decl -> (fullType * (storage wrap)))  = function
 {storageD = (st,iist); 
  qualifD = (qu,iiq); 
  typeD = (ty,iit); 
  inlineD = (inline,iinl);
  } -> 
  (
   ((qu, iiq),
   (match ty with 
 | (None,None,None)       -> warning "type defaults to 'int'" (defaultInt, [])
 | (None, None, Some t)   -> (t, iit)
	 
 | (Some sign,   None, (None| Some (BaseType (IntType (Si (_,CInt))))))  -> 
     BaseType(IntType (Si (sign, CInt))), iit
 | ((None|Some Signed),Some x,(None|Some(BaseType(IntType (Si (_,CInt)))))) -> 
     BaseType(IntType (Si (Signed, [Short,CShort; Long, CLong; LongLong, CLongLong] +> List.assoc x))), iit
 | (Some UnSigned, Some x, (None| Some (BaseType (IntType (Si (_,CInt))))))-> 
     BaseType(IntType (Si (UnSigned, [Short,CShort; Long, CLong; LongLong, CLongLong] +> List.assoc x))), iit
 | (Some sign,   None, (Some (BaseType (IntType CChar))))   -> BaseType(IntType (Si (sign, CChar2))), iit
 | (None, Some Long,(Some(BaseType(FloatType CDouble))))    -> BaseType (FloatType (CLongDouble)), iit

 | (Some _,_, Some _) ->  
     (*mine*)
     raise (Semantic ("signed, unsigned valid only for char and int", fake_pi))
 | (_,Some _,(Some(BaseType(FloatType (CFloat|CLongDouble))))) -> 
     raise (Semantic ("long or short specified with floatint type", fake_pi))
 | (_,Some Short,(Some(BaseType(FloatType CDouble)))) ->
     raise (Semantic ("the only valid combination is long double", fake_pi))
       
 | (_, Some _, Some _) -> 
     (* mine *)
     raise (Semantic ("long, short valid only for int or float", fake_pi)) 

     (* if do short uint i, then gcc say parse error, strange ? it is
      * not a parse error, it is just that we dont allow with typedef
      * either short/long or signed/unsigned. In fact, with
      * parse_typedef_fix2 (with et() and dt()) now I say too parse
      * error so this code is executed only when do short struct
      * {....} and never with a typedef cos now we parse short uint i
      * as short ident ident => parse error (cos after first short i
      * pass in dt() mode) *)
   ))
     ,((st, inline),iist++iinl)
  )

let fixDeclSpecForParam = function ({storageD = (st,iist)} as r) -> 
  let ((qu,ty) as v,_st) = fixDeclSpecForDecl r in
  match st with
  | (Sto Register) -> (v, true), iist
  | NoSto -> (v, false), iist
  | _ -> 
      raise 
        (Semantic ("storage class specified for parameter of function", 
                  fake_pi))

let fixDeclSpecForFuncDef x =
  let (returnType,storage) = fixDeclSpecForDecl x in
  (match fst (unwrap storage) with
  | StoTypedef -> 
      raise (Semantic ("function definition declared 'typedef'", fake_pi))
  | x -> (returnType, storage)
  )

(* parameter: (this is the context where we give parameter only when
 * in func DEFINITION not in funct DECLARATION) We must have a name.
 * This function ensure that we give only parameterTypeDecl with well
 * formed Classic constructor todo?: do we accept other declaration
 * in ? so I must add them to the compound of the deffunc. I dont
 * have to handle typedef pb here cos C forbid to do VF f { ... }
 * with VF a typedef of func cos here we dont see the name of the
 * argument (in the typedef)
 *)
let (fixOldCDecl: fullType -> fullType) = fun ty ->
  match snd ty with
  | ((FunctionType (fullt, (params, (b, iib)))),iifunc) -> 

      (* stdC: If the prototype declaration declares a parameter for a
       * function that you are defining (it is part of a function
       * definition), then you must write a name within the declarator.
       * Otherwise, you can omit the name. *)
      (match params with
      | [((reg, None, ((_qua, (BaseType Void,_)))),_), _] ->  
          ty
      | params -> 
          (params +> List.iter (function 
          | (((b, None, _),  ii1),ii2) -> 
              (* if majuscule, then certainly macro-parameter *)
              pr2 ("SEMANTIC:parameter name omitted, but I continue"); 
	  | _ -> ()
          );
           ty)
      )
        (* todo? can we declare prototype in the decl or structdef,
           ... => length <> but good kan meme *)
  | _ -> 
      (* gcc say parse error but dont see why *)
      raise (Semantic ("seems this is not a function", fake_pi)) 


let fixFunc = function
  | ((
      (s,iis), 
      (nQ, (FunctionType (fullt, (params,bool)),iifunc)), 
      (st,iist)
    ), 
    (cp,iicp)) -> 
      let iistart = Ast_c.fakeInfo () in
      assert (nQ =*= nullQualif);
      (match params with
      | [((reg, None, ((_qua, (BaseType Void,_)))),_), _] ->  ()
      | params -> 
          params +> List.iter (function 
          | (((bool, Some s, fullt), _), _) -> ()
	  | _ -> ()
                (* failwith "internal errror: fixOldCDecl not good" *)
          ));
      (* it must be nullQualif,cos parser construct only this*)
      (s, (fullt, (params, bool)), st, cp), 
      ([iis]++iifunc++iicp++[iistart]++iist) 
  | _ -> 
      raise 
        (Semantic 
            ("you are trying to do a function definition but you dont give " ^
             "any parameter", fake_pi))


(*-------------------------------------------------------------------------- *)
(* parse_typedef_fix2 *)
(*-------------------------------------------------------------------------- *)

let dt s () = 
  if !Flag_parsing_c.debug_etdt then pr2 ("<" ^ s); 
  LP.disable_typedef ()

let et s () = 
  if !Flag_parsing_c.debug_etdt then pr2 (">" ^ s);  
  LP.enable_typedef ()


let fix_add_params_ident = function
  | ((s, (nQ, (FunctionType (fullt, (params, bool)),_)), st)) ->  

      (match params with
      | [((reg, None, ((_qua, (BaseType Void,_)))),_), _] ->  ()
      | params -> 
        params +> List.iter (function 
         | (((bool, Some s, fullt), _), _) -> 
            LP.add_ident s
	 | _ -> 
             ()
             (* failwith "internal errror: fixOldCDecl not good" *)
      )) 
  | _ -> ()

(*-------------------------------------------------------------------------- *)
(* shortcuts *)
(*-------------------------------------------------------------------------- *)

let mk_e e ii = ((e, Ast_c.noType()), ii)
    
%}

/*(*************************************************************************)*/
/*(* Tokens *)*/
/*(*************************************************************************)*/

/*
(* 
 * Some tokens are not even used in this file because they are filtered
 * in some intermediate phases. But they still must be declared because
 * ocamllex may generate them, or some intermediate phase may also
 * generate them (like some functions in parsing_hacks.ml)
 *)
*/

/*(* unrecognized token *)*/
%token <Ast_cplusplus.info> TUnknown

/*(* coupling: Token_helpers.is_real_comment *)*/
%token <Ast_cplusplus.info> TComment TCommentSpace 

/*(*-----------------------------------------*)*/
/*(* the normal tokens *)*/
/*(*-----------------------------------------*)*/

%token <string * Ast_cplusplus.info>                     TInt
%token <(string * Ast_cplusplus.floatType) * Ast_cplusplus.info> TFloat
%token <(string * Ast_cplusplus.isWchar) * Ast_cplusplus.info>   TChar
%token <(string * Ast_cplusplus.isWchar) * Ast_cplusplus.info>   TString



%token <string * Ast_cplusplus.info> TIdent 
/*(* appears mostly after some fix_xxx in parsing_hack *)*/
%token <string * Ast_cplusplus.info> TypedefIdent 

/*
(* Some tokens like TOPar and TCPar are used as synchronisation stuff, 
 * in parsing_hack.ml. So if define special tokens like TOParDefine and
 * TCParEOL, then take care to also modify token_helpers.
 *)
*/

%token <Ast_cplusplus.info> TOPar TCPar TOBrace TCBrace TOCro TCCro 
%token <Ast_cplusplus.info> TDot TComma TPtrOp 
%token <Ast_cplusplus.info> TInc TDec
%token <Ast_cplusplus.assignOp * Ast_cplusplus.info> TAssign 
%token <Ast_cplusplus.info> TEq
%token <Ast_cplusplus.info> TWhy  TTilde TBang
%token <Ast_cplusplus.info> TEllipsis
%token <Ast_cplusplus.info> TCol

%token <Ast_cplusplus.info> TPtVirg
%token <Ast_cplusplus.info> 
       TOrLog TAndLog TOr TXor TAnd  TEqEq TNotEq TInf TSup TInfEq TSupEq
       TShl TShr 
       TPlus TMinus TMul TDiv TMod 

%token <Ast_cplusplus.info>
       Tchar Tshort Tint Tdouble Tfloat Tlong Tunsigned Tsigned Tvoid
       Tauto Tregister Textern Tstatic 
       Ttypedef 
       Tconst Tvolatile
       Tstruct Tunion Tenum 
       Tbreak Telse Tswitch Tcase Tcontinue Tfor Tdo Tif  Twhile Treturn
       Tgoto Tdefault
       Tsizeof  
/*(* C99 *)*/
%token <Ast_cplusplus.info>
       Trestrict

/*(*-----------------------------------------*)*/
/*(* gccext: extra tokens *)*/
/*(*-----------------------------------------*)*/
%token <Ast_cplusplus.info> Tasm
%token <Ast_cplusplus.info> Tattribute
%token <Ast_cplusplus.info> Tinline /*(* also c++ext: *)*/
%token <Ast_cplusplus.info> Ttypeof


/*(*-----------------------------------------*)*/
/*(* cppext: extra tokens *)*/
/*(*-----------------------------------------*)*/

%token <Ast_cplusplus.info> TDefine
%token <(string * Ast_cplusplus.info)> TDefParamVariadic

/*(* disappear after fix_tokens_define *)*/
%token <Ast_cplusplus.info> TCppEscapedNewline 

/*(* appear    after fix_tokens_define *)*/
%token <Ast_cplusplus.info> TOParDefine        
%token <Ast_cplusplus.info> TOBraceDefineInit

%token <(string * Ast_cplusplus.info)> TIdentDefine
%token <Ast_cplusplus.info>            TDefEOL


/*(* used only in lexer_c, then transformed in comment or splitted in tokens *)*/
%token <(string * string * bool ref * Ast_cplusplus.info)> TInclude

/*(* tokens coming from above, generated in parse_c from TInclude, etc *)*/
%token <(Ast_cplusplus.info * bool ref)> TIncludeStart
%token <(string * Ast_cplusplus.info)> TIncludeFilename





/*(* coupling: Token_helpers.is_cpp_instruction *)*/
%token <Ast_cplusplus.info>          TIfdef TIfdefelse TIfdefelif TEndif
%token <(bool * Ast_cplusplus.info)> TIfdefBool TIfdefMisc TIfdefVersion



%token <Ast_cplusplus.info> TCommentMisc
%token <(Ast_cplusplus.cppcommentkind * Ast_cplusplus.info)> TCommentCpp



/*(* appear  after fix_tokens_cpp *)*/

%token <Ast_cplusplus.info>            TMacroStmt
/*(* no need for the value for the moment *)*/
%token <Ast_cplusplus.info>            TMacroString 
%token <(string * Ast_cplusplus.info)> TMacroDecl
%token <Ast_cplusplus.info>            TMacroDeclConst 
%token <(string * Ast_cplusplus.info)> TMacroIterator

/*(* %token <(string * Ast_cplusplus.info)> TMacroTop *)*/
/*(* appear after parsing_hack *)*/
%token <Ast_cplusplus.info> TCParEOL   


%token <Ast_cplusplus.info> TAction


/*(*-----------------------------------------*)*/
/*(* c++ext: extra tokens *)*/
/*(*-----------------------------------------*)*/
%token <Ast_cplusplus.info>
 Tclass Tthis 
 Tnew Tdelete 
 Ttemplate Ttypeid Ttypename 
 Tcatch Ttry Tthrow 
 Toperator 
 Tpublic Tprivate Tprotected    Tfriend 
 Tvirtual 
 Tnamespace Tusing 
 Tbool    Tfalse Ttrue 
 Twchar_t 
 Tconst_cast Tdynamic_cast Tstatic_cast Treinterpret_cast 
 Texplicit Tmutable 
 Texport
%token <Ast_cplusplus.info> TPtrOpStar TDotStar

%token <Ast_cplusplus.info> TColCol 
/*(* for typedef, appear after solved if next token is a typedef *)*/
%token <Ast_cplusplus.info> TColCol2

/*(* for constructed object *)*/
%token <Ast_cplusplus.info> TOParCplusplusInit

/*(* for template *)*/
%token <Ast_cplusplus.info> TInf2 TSup2

/*(* for new[] delete[] *)*/
%token <Ast_cplusplus.info> TOCro2 TCCro2

/*(* for pure virtual method *)*/
%token <Ast_cplusplus.info> TIntZeroVirtual


/*(* TTilde2? *)*/


%token <string * Ast_cplusplus.info> Tclassname 
/*(* for typedef, appear after solved if next token is a typedef *)*/
%token <string * Ast_cplusplus.info> Tclassname2
%token <string * Ast_cplusplus.info> Ttemplatename
%token <string * Ast_cplusplus.info> Tconstructorname
/*(* for cast_constructor, before a '(' *)*/
%token <string * Ast_cplusplus.info> TypedefIdent2
/*(* for templatename as qualifier, before a '::' TODO write heuristic *)*/
%token <string * Ast_cplusplus.info> TtemplatenameQ
%token <string * Ast_cplusplus.info> TtemplatenameQ2

/*(* for constructed (basic) objects, cf heuristic in parsing_hack *)*/
%token <Ast_cplusplus.info> Tchar2 Tint2 Tfloat2 Tdouble2 Twchar_t2 Tshort2 Tlong2 Tbool2
/*(*  Tunsigned Tsigned Tvoid *)*/


/*(*-----------------------------------------*)*/
%token <Ast_cplusplus.info> EOF



/*(*-----------------------------------------*)*/
/*(* must be at the top so that it has the lowest priority *)*/
%nonassoc BOTTOM
%nonassoc SHIFTHERE

%nonassoc Telse

%left TOrLog
%left TAndLog
%left TOr
%left TXor
%left TAnd 
%left TEqEq TNotEq
%left TInf TSup TInfEq TSupEq 
%left TShl TShr
%left TPlus TMinus
%left TMul TDiv TMod 

/*%left TColCol*/

%nonassoc TOP


/*(*************************************************************************)*/
/*(* Rules type declaration *)*/
/*(*************************************************************************)*/
%start main celem statement expr type_id
%type <Ast_cplusplus.program> main

%type <Ast_cplusplus.toplevel> celem

%type <Ast_cplusplus.statement> statement
%type <Ast_cplusplus.expression> expr
%type <Ast_cplusplus.fullType> type_id

%%
/*(*************************************************************************)*/
/*
(* TOC:
 * toplevel (obsolete)
 * 
 * ident
 * expression
 * statement
 * types with 
 *   - left part (type_spec, qualif, template and its arguments), 
 *   - right part (declarator, abstract declarator)
 *   - aux part (parameters)
 * declaration, storage, initializers
 * class/struct
 * enum
 * block_declaration
 * cpp directives
 * celem (=~ main)
 * 
 * generic workarounds (obrace, cbrace for context setting)
 * xxx_list, xxx_opt
 *)
*/
/*(*************************************************************************)*/



/*(*************************************************************************)*/
/*(* toplevel *)*/
/*(*************************************************************************)*/
/*(* no more used; now that use error recovery *)*/

main:  
 | translation_unit EOF     { $1 }

translation_unit: 
 | external_declaration                  
     { !LP._lexer_hint.context_stack <- [LP.InTopLevel];   [$1] }
 | translation_unit external_declaration
     { !LP._lexer_hint.context_stack <- [LP.InTopLevel]; $1 ++ [$2] }

external_declaration: 
 | function_definition            { TopDecl (Definition $1, noii) }
 | block_declaration              { TopDecl (Declaration $1, noii) }



/*(*************************************************************************)*/
/*(* ident, scope *)*/
/*(*************************************************************************)*/

/*
(* todo
 * ~id class_name,  conflict
 * template-id,   conflict
 *)
*/
unqualified_id:
 | TIdent               { IdIdent (fst $1), [snd $1] }
 | operator_function_id { $1 }
 | conversion_function_id { $1 }


qualified_id: 
 | nested_name_specifier /*(*templateopt*)*/ unqualified_id 
   { $1, $2 }



nested_name_specifier: 
 | class_or_namespace_name_for_qualifier TColCol nested_name_specifier_opt 
   { (fst $1, snd $1++[$2])::$3 }

class_or_namespace_name_for_qualifier:
 | Tclassname   { QClassname (fst $1), [snd $1] }
 | template_idq { $1 }

template_idq:
 | TtemplatenameQ tinf_template template_argument_list tsup_template 
  { QTemplateId (fst $1, $3), [snd $1;$2;$4] }





nested_name_specifier2: 
 | class_or_namespace_name_for_qualifier2 TColCol2 nested_name_specifier_opt2 
  { (fst $1, snd $1++[$2])::$3 }

class_or_namespace_name_for_qualifier2:
 | Tclassname2   { QClassname (fst $1), [snd $1]  }
 | template_idq2 { $1 }

template_idq2:
 | TtemplatenameQ2 tinf_template template_argument_list tsup_template
  { QTemplateId (fst $1, $3), [snd $1;$2;$4] }






operator_function_id: 
 | Toperator operator_kind
    { IdOperator (fst $2), $1::(snd $2) }

conversion_function_id:
 | Toperator conversion_type_id
    { IdConverter $2, [$1] }





/*(* no deref getref operator (cos ambiguity with Mul and And), 
   * no unaryplus/minus op either *)*/
operator_kind:
 /*(* != == *)*/
 | TEqEq  { BinaryOp (Logical Eq),    [$1] }
 | TNotEq { BinaryOp (Logical NotEq), [$1] }
 /*(* =    +=   -=   *=   /=   %=       ^=   &=   |=   >>=  <<=   *)*/
 | TEq     { AssignOp SimpleAssign, [$1] }     
 | TAssign { AssignOp (fst $1), [snd $1] } 
 /*(* ! ~ *)*/
 | TTilde { UnaryTildeOp, [$1] }
 | TBang  { UnaryNotOp,   [$1] }
 /*(* , *)*/
 | TComma { CommaOp,  [$1] }
 /*(* +    -    *    /    %  *)*/
 | TPlus  { BinaryOp (Arith Plus),  [$1] }  
 | TMinus { BinaryOp (Arith Minus), [$1] }
 | TMul   { BinaryOp (Arith Mul),   [$1] }  
 | TDiv   { BinaryOp (Arith Div),   [$1] }
 | TMod   { BinaryOp (Arith Mod),   [$1] }
 /*(* ^ & |     <<   >>  *)*/
 | TOr   { BinaryOp (Arith Or),  [$1] }  
 | TXor  { BinaryOp (Arith Xor), [$1] } 
 | TAnd  { BinaryOp (Arith And), [$1]  } 
 | TShl   { BinaryOp (Arith DecLeft), [$1] }  
 | TShr   { BinaryOp (Arith DecRight), [$1] }
 /*(* &&   || *)*/
 | TOrLog  { BinaryOp (Logical OrLog), [$1] } 
 | TAndLog { BinaryOp (Logical AndLog), [$1] }
 /*(* < >  <=   >=  *)*/
 | TInf   { BinaryOp (Logical Inf), [$1] }  
 | TSup   { BinaryOp (Logical Sup), [$1] }
 | TInfEq { BinaryOp (Logical InfEq), [$1] }   
 | TSupEq { BinaryOp (Logical SupEq), [$1] }
 /*(* ++   -- *)*/
 | TInc   { FixOp Inc, [$1] }  
 | TDec   { FixOp Dec, [$1] }
 /*(* ->*  -> *) */
 | TPtrOpStar { PtrOpOp PtrStarOp, [$1] }  
 | TPtrOp     { PtrOpOp PtrOp,     [$1] }
 /*(* () [] (double tokens) *)*/
 | TOPar TCPar { AccessOp ParenOp, [$1;$2] }
 | TOCro TCCro { AccessOp ArrayOp, [$1;$2] }
 /*(* new delete *)*/
 | Tnew    { AllocOp NewOp,    [$1] } 
 | Tdelete { AllocOp DeleteOp, [$1] }
 /*(*new[] delete[] (tripple tokens) *)*/
 | Tnew TOCro2 TCCro2    { AllocOp NewArrayOp,    [$1;$2;$3] }
 | Tdelete TOCro2 TCCro2 { AllocOp DeleteArrayOp, [$1;$2;$3] }





tcolcol_opt:
 | TColCol         { Some (QTop, [$1]) }
 | /*(* empty *)*/ { None }





id_expression:
 | unqualified_id { noQscope, $1 }
 | qualified_id { $1 }





typedef_name: 
 | TypedefIdent { $1 }

template_name:
 | Ttemplatename { $1 }

namespace_name:
 | TIdent { $1 }

enum_name_or_typedef_name_or_simple_class_name:
 | TypedefIdent { $1 }




/*(* Why this ? Why not s/ident/TIdent ? cos there is multiple namespaces in C, 
   * so a label can have the same name that a typedef, same for field and tags
   * hence sometimes the use of ident  instead of TIdent.
   *)*/
ident: 
 | TIdent       { $1 }
 | typedef_name { $1 }

/*(*c++ext:*)*/
ident3:
 | ident { $1 }
 | TypedefIdent2 { $1 }


/*(*************************************************************************)*/
/*(* expr *)*/
/*(*************************************************************************)*/


expr: 
 | assign_expr             { $1 }
 | expr TComma assign_expr { mk_e (Sequence ($1,$3)) [$2] }


/*(* bugfix: in C grammar they put 'unary_expr', but in fact it must be 
   * 'cast_expr', otherwise (int * ) xxx = &yy; is not allowed
   *)*/
assign_expr: 
 | cond_expr                     { $1 }
 | cast_expr TAssign assign_expr { mk_e(Assignment ($1,fst $2,$3)) [snd $2]}
 | cast_expr TEq     assign_expr { mk_e(Assignment ($1,SimpleAssign,$3)) [$2]}
 /*(*c++ext: *)*/
 | Tthrow assign_expr_opt        { mk_e (Throw $2) [$1] }

/*(* gccext: allow optional then part hence gcc_opt_expr 
   * bugfix: in C grammar they put 'TCol cond_expr', but in fact it must be
   * 'assign_expr', otherwise   pnp ? x : x = 0x388  is not allowed
   *)*/
cond_expr: 
 | arith_expr   { $1 }
 | arith_expr TWhy gcc_opt_expr TCol assign_expr 
     { mk_e (CondExpr ($1,$3,$5)) [$2;$4] } 


arith_expr: 
 | pm_expr                     { $1 }
 | arith_expr TMul    arith_expr { mk_e(Binary ($1, Arith Mul,      $3)) [$2] }
 | arith_expr TDiv    arith_expr { mk_e(Binary ($1, Arith Div,      $3)) [$2] }
 | arith_expr TMod    arith_expr { mk_e(Binary ($1, Arith Mod,      $3)) [$2] }

 | arith_expr TPlus   arith_expr { mk_e(Binary ($1, Arith Plus,     $3)) [$2] }
 | arith_expr TMinus  arith_expr { mk_e(Binary ($1, Arith Minus,    $3)) [$2] }
 | arith_expr TShl    arith_expr { mk_e(Binary ($1, Arith DecLeft,  $3)) [$2] }
 | arith_expr TShr    arith_expr { mk_e(Binary ($1, Arith DecRight, $3)) [$2] }
 | arith_expr TInf    arith_expr { mk_e(Binary ($1, Logical Inf,    $3)) [$2] }
 | arith_expr TSup    arith_expr { mk_e(Binary ($1, Logical Sup,    $3)) [$2] }
 | arith_expr TInfEq  arith_expr { mk_e(Binary ($1, Logical InfEq,  $3)) [$2] }
 | arith_expr TSupEq  arith_expr { mk_e(Binary ($1, Logical SupEq,  $3)) [$2] }
 | arith_expr TEqEq   arith_expr { mk_e(Binary ($1, Logical Eq,     $3)) [$2] }
 | arith_expr TNotEq  arith_expr { mk_e(Binary ($1, Logical NotEq,  $3)) [$2] }
 | arith_expr TAnd    arith_expr { mk_e(Binary ($1, Arith And,      $3)) [$2] }
 | arith_expr TOr     arith_expr { mk_e(Binary ($1, Arith Or,       $3)) [$2] }
 | arith_expr TXor    arith_expr { mk_e(Binary ($1, Arith Xor,      $3)) [$2] }
 | arith_expr TAndLog arith_expr { mk_e(Binary ($1, Logical AndLog, $3)) [$2] }
 | arith_expr TOrLog  arith_expr { mk_e(Binary ($1, Logical OrLog,  $3)) [$2] }

pm_expr: 
 | cast_expr { $1 }
 /*(*c++ext: .* and ->*, note that not next to . and -> and take expr *)*/
 | pm_expr TDotStar   cast_expr
     { mk_e(RecordStarAccess   ($1,$3)) [$2]}
 | pm_expr TPtrOpStar cast_expr
     { mk_e(RecordPtStarAccess ($1,$3)) [$2]}

cast_expr: 
 | unary_expr                        { $1 }
 | topar2 type_id tcpar2 cast_expr { mk_e(Cast ($2, $4)) [$1;$3] }

unary_expr: 
 | postfix_expr                    { $1 }
 | TInc unary_expr                 { mk_e(Infix ($2, Inc))    [$1] }
 | TDec unary_expr                 { mk_e(Infix ($2, Dec))    [$1] }
 | unary_op cast_expr              { mk_e(Unary ($2, fst $1)) [snd $1] }
 | Tsizeof unary_expr              { mk_e(SizeOfExpr ($2))    [$1] }
 | Tsizeof topar2 type_id tcpar2 { mk_e(SizeOfType ($3))    [$1;$2;$4] }
 /*(*c++ext: *)*/
 | new_expr      { $1 }
 | delete_expr   { $1 }

unary_op: 
 | TAnd   { GetRef,     $1 }
 | TMul   { DeRef,      $1 }
 | TPlus  { UnPlus,     $1 }
 | TMinus { UnMinus,    $1 }
 | TTilde { Tilde,      $1 }
 | TBang  { Not,        $1 }
 /*(* gccext: have that a lot in old kernel to get address of local label.
    * cf gcc manual "local labels as values".
    *)*/
 | TAndLog { GetRefLabel, $1 }




postfix_expr: 
 | primary_expr               { $1 }
 | postfix_expr TOCro expr TCCro                
     { mk_e(ArrayAccess ($1, $3)) [$2;$4] }
 | postfix_expr TOPar argument_list_opt TCPar  
     { mk_e(FunCall ($1, $3)) [$2;$4] }


 /*(*c++ext: ident is now a id_expression *)*/
 | postfix_expr TDot   template_opt tcolcol_opt  id_expression
     { let name = ($4, fst $5, snd $5) in mk_e(RecordAccess ($1,name)) [$2] }
 | postfix_expr TPtrOp template_opt tcolcol_opt id_expression  
     { let name = ($4, fst $5, snd $5) in mk_e(RecordPtAccess($1,name)) [$2] }

 | postfix_expr TInc          { mk_e(Postfix ($1, Inc)) [$2] }
 | postfix_expr TDec          { mk_e(Postfix ($1, Dec)) [$2] }

 /*(* gccext: also called compound literals *)*/
 | compound_literal_expr { $1 }

 /*(* c++ext: *)*/
 | cast_operator_expr { $1 }
 | Ttypeid topar2 unary_expr tcpar2 { mk_e(TypeIdOfExpr ($3))    [$1;$2;$4] }
 | Ttypeid topar2 type_id    tcpar2 { mk_e(TypeIdOfType ($3))    [$1;$2;$4] }
 | cast_constructor_expr { $1 }




primary_expr: 
 /*(*c++ext: cf below now. old: TIdent { mk_e(Ident  (fst $1)) [snd $1] }  *)*/

 /*(* constants a.k.a literal *)*/
 | TInt    { mk_e(Constant (Int    (fst $1))) [snd $1] }
 | TFloat  { mk_e(Constant (Float  (fst $1))) [snd $1] }
 | TString { mk_e(Constant (String (fst $1))) [snd $1] }
 | TChar   { mk_e(Constant (Char   (fst $1))) [snd $1] }
 /*(*c++ext: *)*/
 | Ttrue   { mk_e(Constant (Bool false)) [$1] }
 | Tfalse  { mk_e(Constant (Bool false)) [$1] }

  /*(* forunparser: *)*/
 | TOPar expr TCPar { mk_e(ParenExpr ($2)) [$1;$3] }  

 /*(* gccext: cppext: *)*/
 | string_elem string_list { mk_e(Constant (MultiString)) ($1 ++ $2) }
 /*(* gccext: allow statement as expressions via ({ statement }) *)*/
 | TOPar compound TCPar    { mk_e(StatementExpr ($2)) [$1;$3] }

 /*(* c++ext: *)*/
 | Tthis { mk_e(This) [$1] }
 | primary_cplusplus_id { $1 }


/*(*----------------------------*)*/
/*(* c++ext: *)*/
/*(*----------------------------*)*/

/*(* can't factorize with following rule :(
   * | tcolcol_opt nested_name_specifier_opt TIdent  *)*/
primary_cplusplus_id:
 | TColCol TIdent  
     { let qtop = Some (QTop, [$1]) in
       let qid = IdIdent (fst $2), [snd $2] in 
       let name = (qtop, noQscope, qid) in mk_e(Ident name) [] }
 | TColCol operator_function_id 
     { let qtop = Some (QTop, [$1]) in
       let qop = $2 in
       let name = (qtop, noQscope, qop) in mk_e(Ident name) [] }
 | TColCol qualified_id 
     { let qtop = Some (QTop, [$1]) in
       let name = (qtop, fst $2, snd $2) in mk_e(Ident name) [] }
 | id_expression 
     { let qtop = None in 
       let name = (qtop, fst $1, snd $1) in mk_e(Ident name) [] }



/*(*could use TInf here *)*/
cast_operator_expr: 
 | cpp_cast_operator tinf_template type_id  tsup_template TOPar expr TCPar 
     { mk_e (CplusplusCast (fst $1, $3, $6)) [snd $1;$2;$4;$5;$7] }


/*(*c++ext:*)*/
cpp_cast_operator:
 | Tstatic_cast      { Static_cast, $1 }
 | Tdynamic_cast     { Dynamic_cast, $1 }
 | Tconst_cast       { Const_cast, $1 }
 | Treinterpret_cast { Reinterpret_cast, $1 }




/*
(* c++ext: cast with function syntax, and also constructor, but conflict.
 * constructed object or cast. Have a few conflicts.
 * todo can have nested specifier before the typedefident2 ... so 
 * need a classname3 ?
*)*/
cast_constructor_expr:
 | TypedefIdent2 TOPar argument_list_opt TCPar 
     { let ft = nQ, (TypeName (fst $1, Ast_c.noTypedefDef()), [snd $1]) in
       mk_e(ConstructedObject (ft, $3)) [$2;$4]  
     }
 | basic_type_2 TOPar argument_list_opt TCPar 
     { let ft = nQ, $1 in
       mk_e(ConstructedObject (ft, $3)) [$2;$4] 
     }


basic_type_2: 
 | Tchar2                { (BaseType (IntType CChar)), [$1]}
 | Tint2                 { (BaseType (IntType (Si (Signed,CInt)))), [$1]}
 | Tfloat2               { (BaseType (FloatType CFloat)),  [$1]}
 | Tdouble2              { (BaseType (FloatType CDouble)), [$1] }

 | Twchar_t2             { (BaseType (IntType WChar_t)),         [$1] }

 | Tshort2               { (BaseType (IntType (Si (Signed, CShort)))),  [$1] }
 | Tlong2                { (BaseType (IntType (Si (Signed, CLong)))),   [$1] }
 | Tbool2                { (BaseType (IntType CBool)),         [$1] }






/*(* c++ext: * simple case: new A(x1, x2); *)*/
new_expr:
 | tcolcol_opt Tnew new_placement_opt   new_type_id  new_initializer_opt
     { mk_e (This) [] (*TODO*)  }
/*(* ambiguity then on the TOPar
 tcolcol_opt Tnew new_placement_opt TOPar type_id TCPar new_initializer_opt
  *)*/

delete_expr:
 | tcolcol_opt Tdelete cast_expr 
     { mk_e (Delete ($3, $1)) [$2] }
 | tcolcol_opt Tdelete TOCro2 TCCro2 cast_expr 
     { mk_e (DeleteArray ($5, $1)) [$2;$3;$4] }


new_placement: 
 | TOPar argument_list TCPar { () }

new_initializer: 
 | TOPar argument_list_opt TCPar { () }







/*(*----------------------------*)*/
/*(* gccext: *)*/
/*(*----------------------------*)*/

compound_literal_expr:
 | topar2 type_id tcpar2 TOBrace TCBrace 
     { mk_e(GccConstructor ($2, [])) [$1;$3;$4;$5] }
 | topar2 type_id tcpar2 tobrace_ini initialize_list gcc_comma_opt tcbrace_ini
     { mk_e(GccConstructor ($2, List.rev $5)) ([$1;$3;$4;$7] ++ $6) }


 

string_elem:
 | TString { [snd $1] }
 /*(* cppext:  ex= printk (KERN_INFO "xxx" UTS_RELEASE)  *)*/
 | TMacroString { [$1] }


/*(*----------------------------*)*/
/*(* cppext: *)*/
/*(*----------------------------*)*/

/*(* cppext: *)*/
argument: 
 | assign_expr { Left $1 }
 | parameter_decl { Right (ArgType $1)  }
 | action_higherordermacro { Right (ArgAction $1) }

action_higherordermacro: 
 | taction_list 
     { if null $1
       then ActMisc [Ast_c.fakeInfo()]
       else ActMisc $1
     }

/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/

/*(* would like evalInt $1 but require too much info *)*/
const_expr: cond_expr { $1  }


topar2: TOPar { et "topar2" (); $1  }
tcpar2: TCPar { et "tcpar2" (); $1 (*TODO? et ? sure ? c pas dt plutot ? *) } 


/*(*************************************************************************)*/
/*(* statement *)*/
/*(*************************************************************************)*/

statement: 
 | compound        { Compound     (fst $1), snd $1 }
 | expr_statement  { ExprStatement(fst $1), snd $1 }
 | labeled         { Labeled      (fst $1), snd $1 }
 | selection       { Selection    (fst $1), snd $1 ++ [fakeInfo()] }
 | iteration       { Iteration    (fst $1), snd $1 ++ [fakeInfo()] }
 | jump TPtVirg    { Jump         (fst $1), snd $1 ++ [$2] }

 /*(* cppext: *)*/
 | TMacroStmt { MacroStmt, [$1] }

 /*
 (* cppext: c++ext: because of cpp, some stuff looks like declaration but are in
  * fact statement but too hard to figure out, and if parse them as
  * expression, then we force to have first decls and then exprs, then
  * will have a parse error. So easier to let mix decl/statement.
  * Moreover it helps to not make such a difference between decl and
  * statement for further coccinelle phases to factorize code.
  * 
  * update: now a c++ext and handle slightly differently. It's inlined
  * in statement instead of going through a stat_or_decl.
  *)*/
 | declaration_statement { $1 }

 /*(* gccext: if move in statement then can have r/r conflict with define *)*/
 | function_definition { NestedFunc $1, noii }

 /*(* c++ext: *)*/
 | try_block { $1 }

 /*(* c++ext: TODO put at good place later *)*/
 | Tswitch TOPar decl_spec init_declarator_list TCPar statement
     { (* TODO AST *) MacroStmt, [] }

 | Tif TOPar decl_spec init_declarator_list TCPar statement              %prec SHIFTHERE
     { MacroStmt, [] }
 | Tif TOPar decl_spec init_declarator_list TCPar statement Telse statement 
     { MacroStmt, [] }




compound: 
 | tobrace statement_list_opt tcbrace { $2, [$1; $3]  }


statement_list:
 | statement_seq { [$1] }
 | statement_list statement_seq { $1 ++ [$2] }

statement_list_opt:
 | /*(*empty*)*/ { [] }
 | statement_list { $1 }


statement_seq:
 | statement { StmtElem $1 }
 /* (* cppext: *)*/
 | cpp_directive 
     { CppDirectiveStmt $1 }
 | cpp_ifdef_directive/*(* stat_or_decl_list ...*)*/  
     { IfdefStmt $1 }




expr_statement: 
 | expr_opt TPtVirg { $1, [$2] }




/*(* note that case 1: case 2: i++;    would be correctly parsed, but with 
   * a Case  (1, (Case (2, i++)))  :(  
   *)*/
labeled: 
 | ident            TCol statement   { Label (fst $1, $3),  [snd $1; $2] }
 | Tcase const_expr TCol statement   { Case ($2, $4),       [$1; $3] }
 | Tcase const_expr TEllipsis const_expr TCol statement 
     { CaseRange ($2, $4, $6), [$1;$3;$5] } /*(* gccext: allow range *)*/
 | Tdefault         TCol statement   { Default $3,             [$1; $2] } 





/*(* classic else ambiguity resolved by a %prec *)*/
selection: 
 | Tif TOPar expr TCPar statement              %prec SHIFTHERE
     { If ($3, $5, (ExprStatement None, [])),   [$1;$2;$4] }
 | Tif TOPar expr TCPar statement Telse statement 
     { If ($3, $5, $7),  [$1;$2;$4;$6] }
 | Tswitch TOPar expr TCPar statement             
     { Switch ($3,$5),   [$1;$2;$4]  }



iteration: 
 | Twhile TOPar expr TCPar statement                             
     { While ($3,$5),                [$1;$2;$4] }
 | Tdo statement Twhile TOPar expr TCPar TPtVirg                 
     { DoWhile ($2,$5),              [$1;$3;$4;$6;$7] }

 | Tfor TOPar expr_statement expr_statement expr_opt TCPar statement
     { For ($3,$4,($5, []),$7), [$1;$2;$6] }
 /*(* c++ext: for(int i = 0; i < n; i++)*)*/
 | Tfor TOPar simple_declaration expr_statement expr_opt TCPar statement
     { 
       MacroIteration ("toto", [], $7),[] (* TODOfake ast, TODO need decl2 ? *)
     }
 /*(* cppext: *)*/
 | TMacroIterator TOPar argument_list_opt TCPar statement
     { MacroIteration (fst $1, $3, $5), [snd $1;$2;$4] }



/*(* the ';' in the caller grammar rule will be appended to the infos *)*/
jump: 
 | Tgoto ident  { Goto (fst $2),  [$1;snd $2] } 
 | Tcontinue    { Continue,       [$1] }
 | Tbreak       { Break,          [$1] }
 | Treturn      { Return,         [$1] } 
 | Treturn expr { ReturnExpr $2,  [$1] }
 | Tgoto TMul expr { GotoComputed $3, [$1;$2] }





       
/*(*----------------------------*)*/
/*(* c++ext: *)*/
/*(*----------------------------*)*/

declaration_statement:
 | block_declaration { DeclStmt $1, noii }



try_block: 
 | Ttry compound handler_list { Try ($2, $3), [$1] }

handler: 
 | Tcatch topar exception_decl tcpar compound { ($3, [$1;$2;$4]), $5 }

exception_decl:
 | parameter_decl { ExnDecl $1 }
 | TEllipsis      { ExnDeclEllipsis $1 }


/*(*************************************************************************)*/
/*(* types *)*/
/*(*************************************************************************)*/


/*(*-----------------------------------------------------------------------*)*/
/*(* Type spec, left part of a type *)*/
/*(*-----------------------------------------------------------------------*)*/

/*(* in c++ grammar they put 'cv_qualifier' here but I prefer keep as before *)*/
type_spec2:
 | simple_type_specifier { $1 }
 | elaborated_type_specifier { $1 }
 | enum_specifier  { Right3 (fst $1), snd $1 }
 | class_specifier { Right3 (StructUnion $1),            [] }


simple_type_specifier:
 | Tvoid                { Right3 (BaseType Void),            [$1] }
 | Tchar                { Right3 (BaseType (IntType CChar)), [$1]}
 | Tint                 { Right3 (BaseType (IntType (Si (Signed,CInt)))), [$1]}
 | Tfloat               { Right3 (BaseType (FloatType CFloat)),  [$1]}
 | Tdouble              { Right3 (BaseType (FloatType CDouble)), [$1] }
 | Tshort               { Middle3 Short,  [$1]}
 | Tlong                { Middle3 Long,   [$1]}
 | Tsigned              { Left3 Signed,   [$1]}
 | Tunsigned            { Left3 UnSigned, [$1]}
 /*(*c++ext: *)*/
 | Tbool                { Right3 (BaseType (IntType CBool)),            [$1] }
 | Twchar_t             { Right3 (BaseType (IntType WChar_t)),         [$1] }

 /*(* gccext: *)*/
 | Ttypeof TOPar assign_expr TCPar { Right3 (TypeOfExpr ($3)), [$1;$2;$4] }
 | Ttypeof TOPar type_id   TCPar { Right3 (TypeOfType ($3)), [$1;$2;$4] }

 /*
 (* parse_typedef_fix1: cant put: TIdent {} cos it make the grammar 
  * ambiguous, generates lots of conflicts => we must 
  * use some tricks: we make the lexer and parser cooperate, cf lexerParser.ml.
  * 
  * parse_typedef_fix2: this is not enough, and you must use 
  * parse_typedef_fix2 to fully manage typedef problems in grammar.
  * 
  * parse_typedef_fix3:
  * 
  * parse_typedef_fix4: try also to do now some consistency checking in
  * Parse_c
  *)*/
 | type_cplusplus_id { Right3 (fst $1), snd $1 }




/*(*todo: can have a ::opt nested_name_specifier_opt before ident*)*/
elaborated_type_specifier: 
 | Tenum ident 
     { Right3 (EnumName (fst $2)),       [$1; snd $2] }
 | class_key ident
     { Right3 (StructUnionName (fst $1, fst $2)), [snd $1;snd $2] }
 /*(* c++ext: *)*/
 | Ttypename ident 
     { let typedef = (TypeName (fst $2,Ast_c.noTypedefDef())), [snd $2] in
       Right3 (TypenameKwd (Ast_c.nQ,typedef)), [$1]
     }
 | Ttypename template_id 
     { let template = $2 in
       Right3 (TypenameKwd (Ast_c.nQ,template)), [$1]
     }




/*(*----------------------------*)*/
/*(* c++ext:  *)*/
/*(*----------------------------*)*/

/*(* cant factorize with a tcolcol_opt2 *)*/
type_cplusplus_id:
 | type_name { $1 }
 | TColCol2 type_name { $2 }
 | nested_name_specifier2 type_name { $2 }
 | TColCol2 nested_name_specifier2 type_name { $3 }


/*
(* in c++ grammar they put 
 *  typename: enum-name | typedef-name | class-name 
 *   class-name:  identifier | template-id
 *    template-id: template-name < template-argument-list > 
 * But in my case I don't have the contextual info so when I see an ident
 * it can be a typedef-name, enum-name, class-name (not template-name
 * cos I detect them as they have a '<' just after),
 * so here type_name is simplified in consequence.
 *)
*/
type_name:
 | enum_name_or_typedef_name_or_simple_class_name
     { (TypeName (fst $1,Ast_c.noTypedefDef())), [snd $1] }
 | template_id { $1 }




template_id:
 | template_name tinf_template template_argument_list tsup_template 
    { (TypeTemplate (fst $1,$3)), [snd $1;$2;$4] }

/*
(*c++ext: in the c++ grammar they have also 'template-name' but this is catched 
 * in my case by type_id and its generic TypedefIdent, or will be parsed
 * as an Ident and so assign_expr. In this later case may need a ast post 
 * disambiguation analysis for some false positive.
 *)*/
template_argument:
 | type_id     { Left $1 }
 | assign_expr { Right $1 }



/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/

type_spec: type_spec2    { dt "type" (); $1   }

/*(*-----------------------------------------------------------------------*)*/
/*(* Qualifiers *)*/
/*(*-----------------------------------------------------------------------*)*/

/*(* was called type_qualif before *)*/
cv_qualif: 
 | Tconst    { {const=true  ; volatile=false}, $1 }
 | Tvolatile { {const=false ; volatile=true},  $1 }
 /*(* C99 *)*/
 | Trestrict { (* TODO *) {const=false ; volatile=false},  $1 }




/*(*-----------------------------------------------------------------------*)*/
/*(* Declarator, right part of a type + second part of decl (the ident)  *)*/
/*(*-----------------------------------------------------------------------*)*/

/*
(* declarator return a couple: 
 *  (name, partial type (a function to be applied to return type)) 
 *
 * when int* f(int) we must return Func(Pointer int,int) and not
 * Pointer (Func(int,int) 
 *)*/

declarator: 
 | pointer direct_d { (fst $2, fun x -> x +> $1 +> (snd $2)  ) }
 | direct_d         { $1  }

/*(* so must do  int * const p; if the pointer is constant, not the pointee *)*/
pointer: 
 | TMul                          { fun x ->(nQ,         (Pointer x,     [$1]))}
 | TMul cv_qualif_list         { fun x ->($2.qualifD, (Pointer x,     [$1]))}
 | TMul pointer                  { fun x ->(nQ,         (Pointer ($2 x),[$1]))}
 | TMul cv_qualif_list pointer { fun x ->($2.qualifD, (Pointer ($3 x),[$1]))}
 /*(*c++ext: no qualif for ref *)*/
 | TAnd                          { fun x ->(nQ,    (Reference x,    [$1]))}
 | TAnd pointer                  { fun x ->(nQ,    (Reference ($2 x),[$1]))}

direct_d: 
 | declarator_id
     { ($1, fun x -> x) }
 | TOPar declarator TCPar      /*(* forunparser: old: $2 *)*/ 
     { (fst $2, fun x -> (nQ, (ParenType ((snd $2) x), [$1;$3]))) }
 | direct_d tocro            tccro         
     { (fst $1,fun x->(snd $1) (nQ,(Array (None,x),         [$2;$3]))) }
 | direct_d tocro const_expr tccro
     { (fst $1,fun x->(snd $1) (nQ,(Array (Some $3,x),      [$2;$4])))}
 | direct_d topar            tcpar const_opt exception_specification_opt
     { (fst $1,
       fun x->(snd $1) 
         (nQ,(FunctionType (x,(([],(false, [])))),[$2;$3])))
     }
 | direct_d topar parameter_type_list tcpar const_opt exception_specification_opt
     { (fst $1,fun x->(snd $1) (nQ,(FunctionType (x, $3),   [$2;$4]))) }



/*(*----------------------------*)*/
/*(*c++ext: TODOAST *)*/
/*(*----------------------------*)*/
declarator_id:
 | tcolcol_opt id_expression 
     { let _name = ($1, fst $2, snd $2) in "todo",fakeInfo()   (*TODO*) }
/*(* TODO ::opt nested-name-specifieropt type-name*) */


/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/

tocro: TOCro { et "tocro" ();$1 }
tccro: TCCro { dt "tccro" ();$1 }


/*(*-----------------------------------------------------------------------*)*/
abstract_declarator: 
 | pointer                            { $1 }
 |         direct_abstract_declarator { $1 }
 | pointer direct_abstract_declarator { fun x -> x +> $2 +> $1 }

direct_abstract_declarator: 
 | TOPar abstract_declarator TCPar /*(* forunparser: old: $2 *)*/
     { (fun x -> (nQ, (ParenType ($2 x), [$1;$3]))) }

 | TOCro            TCCro                            
     { fun x ->   (nQ, (Array (None, x),      [$1;$2]))}
 | TOCro const_expr TCCro                            
     { fun x ->   (nQ, (Array (Some $2, x),   [$1;$3]))}
 | direct_abstract_declarator TOCro            TCCro 
     { fun x ->$1 (nQ, (Array (None, x),      [$2;$3])) }
 | direct_abstract_declarator TOCro const_expr TCCro
     { fun x ->$1 (nQ, (Array (Some $3,x),    [$2;$4])) }
 | TOPar TCPar                                       
     { fun x ->   (nQ, (FunctionType (x, ([], (false,  []))),   [$1;$2])) }
 | TOPar parameter_type_list TCPar
     { fun x ->   (nQ, (FunctionType (x, $2),           [$1;$3]))}
 | direct_abstract_declarator TOPar TCPar const_opt exception_specification_opt
     { fun x ->$1 (nQ, (FunctionType (x, (([], (false, [])))),[$2;$3])) }
 | direct_abstract_declarator TOPar parameter_type_list TCPar const_opt exception_specification_opt
     { fun x -> $1 (nQ, (FunctionType (x, $3), [$2;$4])) }




/*(*-----------------------------------------------------------------------*)*/
/*(* Parameters (use decl_spec not type_spec just for 'register') *)*/
/*(*-----------------------------------------------------------------------*)*/
parameter_type_list: 
 | parameter_list                  { ($1, (false, []))}
 | parameter_list TComma TEllipsis { ($1, (true,  [$2;$3])) }


parameter_decl2: 
 | decl_spec declaratorp
     { let ((returnType,hasreg),iihasreg) = fixDeclSpecForParam $1 in 
       (hasreg, Some (fst (fst $2)), ((snd $2) returnType)),    
        (iihasreg ++ [snd (fst $2)])      }
 | decl_spec abstract_declarator
     { let ((returnType,hasreg), iihasreg) = fixDeclSpecForParam $1 
       in (hasreg, None, ($2 returnType)),      (iihasreg ++ [])  }
 | decl_spec
     { let ((returnType,hasreg), iihasreg) = fixDeclSpecForParam $1 
       in (hasreg, None, returnType),           (iihasreg ++ []) }

/*(*c++ext: default parameter value, copy paste, TODOAST *)*/
 | decl_spec declaratorp TEq assign_expr
     { let ((returnType,hasreg),iihasreg) = fixDeclSpecForParam $1 
       in 
       (hasreg, Some (fst (fst $2)), ((snd $2) returnType)),    
        (iihasreg ++ [snd (fst $2)]) }
 | decl_spec abstract_declarator TEq assign_expr
     { let ((returnType,hasreg), iihasreg) = fixDeclSpecForParam $1 
       in (hasreg, None, ($2 returnType)),      (iihasreg ++ []) }
 | decl_spec TEq assign_expr
     { let ((returnType,hasreg), iihasreg) = fixDeclSpecForParam $1 
       in (hasreg, None, returnType),           (iihasreg ++ []) }

/*(*----------------------------*)*/
/*(* c++ext: *)*/
/*(*----------------------------*)*/
/*(*c++ext: specialisation TODO *)*/
exception_specification: 
 | Tthrow TOPar TCPar { () }

/*(*c++ext: in orig they put cv-qualifier-seqopt but there is never some 
   * volatile so ...
   *)
   */
const_opt:
 | Tconst        { Some $1 }
 | /*(*empty*)*/ { None }




/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/

parameter_decl: parameter_decl2 { et "param" ();  $1 }

declaratorp: declarator      { LP.add_ident (fst (fst $1)); $1 }




/*(*-----------------------------------------------------------------------*)*/
/*(* helper type rules *)*/
/*(*-----------------------------------------------------------------------*)*/

/*(* For type_id. No storage here. Was used before for field but 
   * now structure fields can have storage so fields now use decl_spec. *)*/
spec_qualif_list2: 
 | type_spec                    { addTypeD ($1, nullDecl) }
 | cv_qualif                    { {nullDecl with qualifD = (fst $1,[snd $1])}}
 | type_spec   spec_qualif_list { addTypeD ($1,$2)   }
 | cv_qualif   spec_qualif_list { addQualifD ($1,$2) }

spec_qualif_list: spec_qualif_list2            {  dt "spec_qualif" (); $1 }
 	     
/*(* for pointers in direct_declarator and abstract_declarator *)*/
cv_qualif_list: 
 | cv_qualif                  { {nullDecl with qualifD = (fst $1,[snd $1])} }
 | cv_qualif_list cv_qualif   { addQualifD ($2,$1) }




/*(*-----------------------------------------------------------------------*)*/
/*(* xxx_type_id *)*/
/*(*-----------------------------------------------------------------------*)*/

/*(* for case and sizeof. was called type_name in old c grammar *)*/
type_id: 
 | spec_qualif_list
     { let (returnType, _) = fixDeclSpecForDecl $1 in  returnType }
 | spec_qualif_list abstract_declarator
     { let (returnType, _) = fixDeclSpecForDecl $1 in $2 returnType }



ptr_operator:
 | TMul { () }
 | TAnd { () }
/*(*TODO ::opt nested-name-specifier * cv-qualifier-seqopt 
   and some cv_qualifier_opt on TMul *)
*/

/*(* ambiguity with '*' and '&' cos when have new int *2, it can
   * be parsed as (new int) * 2 or (new int * ) 2.
   * cf p62 of Ellis. So when see a TMul or TAnd don't reduce here,
   * sift, hence the prec when are to decice wethere or not to enter
   * in new_declarator and its leading ptr_operator
   *)*/
new_type_id: 
 | spec_qualif_list new_declarator  { }
 | spec_qualif_list %prec SHIFTHERE   { }

new_declarator: 
 | ptr_operator new_declarator 
     { () }
 | ptr_operator %prec SHIFTHERE
     { () }
 | direct_new_declarator 
     { () }



direct_new_declarator:
 | TOCro expr TCCro { () }
 | direct_new_declarator TOCro expr TCCro { () }



/*
(* in c++ grammar they do 'type_spec_seq conversion_declaratoropt'. We
 * can not replace with a simple 'type_id' cos here we must not allow
 * functionType otherwise there is conflicts on TOPar.
 * TODO: right now do simple_type_specifier because conflict 
 * when do full type_spec.
 *   type_spec conversion_declaratoropt
 * 
 *)*/
conversion_type_id: 
 | simple_type_specifier conversion_declarator 
     { let tx = addTypeD ($1, nullDecl) in
       let (returnType, _) = fixDeclSpecForDecl tx in returnType 
     }
 | simple_type_specifier %prec SHIFTHERE 
     { let tx = addTypeD ($1, nullDecl) in
       let (returnType, _) = fixDeclSpecForDecl tx in returnType 
     }

conversion_declarator: 
 | ptr_operator conversion_declarator 
     { () }
 | ptr_operator %prec SHIFTHERE
     { () }






/*(*************************************************************************)*/
/*(* declaration, types, initializers *)*/
/*(*************************************************************************)*/

block_declaration:
 | simple_declaration { SimpleDecl $1, noii }
 | asm_definition     { $1 }

 /*(*c++ext: *)*/
 | namespace_alias_definition { $1 }
 | using_declaration { UsingDecl (fst $1), snd $1 }
 | using_directive   { $1 }


/*(*----------------------------*)*/
/*(* c++ext: *)*/
/*(*----------------------------*)*/


namespace_alias_definition:
 | Tnamespace TIdent TEq tcolcol_opt nested_name_specifier_opt namespace_name
     { let name = ($4, $5, (IdIdent (fst $6), [snd $6])) in
       NameSpaceAlias (fst $2, name), [$1;snd $2;$3] 
     }

using_directive:
 | Tusing Tnamespace tcolcol_opt nested_name_specifier_opt namespace_name TPtVirg
     { let name = ($3, $4, (IdIdent (fst $5), [snd $5])) in
       UsingDirective name, [$1;$2;$6] 
     }

/*(* conflict on TColCol in 'Tusing TColCol unqualified_id TPtVirg'
   * need LALR(2) to see if after tcol have a nested_name_specifier
   * or put opt on nested_name_specifier too
  *)*/
using_declaration:
 | Tusing typename_opt tcolcol_opt nested_name_specifier unqualified_id TPtVirg
     { let name = ($3, $4, $5) in
       name, [$1;$6]++$2
     }



/*(*----------------------------*)*/
/*(* gccext: c++ext: *)*/
/*(*----------------------------*)*/

asm_definition:
 /*(* gccext: c++ext: also apparently *)*/
 | Tasm TOPar asmbody TCPar TPtVirg             { Asm $3, [$1;$2;$4;$5] }
 | Tasm Tvolatile TOPar asmbody TCPar TPtVirg   { Asm $4, [$1;$2;$3;$5;$6] }




asmbody: 
 | string_list colon_asm_list  { $1, $2 }
 | string_list { $1, [] } /*(* in old kernel *)*/


colon_asm: 
 | TCol colon_option_list { Colon $2, [$1]   }

colon_option: 
 | TString                      { ColonMisc, [snd $1] }
 | TString TOPar asm_expr TCPar { ColonExpr $3, [snd $1; $2;$4] } 
 /*(* cppext: certainly a macro *)*/
 | TOCro TIdent TCCro TString TOPar asm_expr TCPar
     { ColonExpr $6, [$1;snd $2;$3;snd $4; $5; $7 ] }
 | TIdent                           { ColonMisc, [snd $1] }
 | /*(* empty *)*/                  { ColonMisc, [] }

asm_expr: assign_expr { $1 }




/*(*************************************************************************)*/
/*(* simple declaration, initializers *)*/
/*(*************************************************************************)*/

simple_declaration2:
 | decl_spec TPtVirg
     { let (returnType,storage) = fixDeclSpecForDecl $1 in 
       let iistart = Ast_c.fakeInfo () in
       DeclList ([(None, returnType, unwrap storage),noii],  
                ($2::iistart::snd storage))
     } 
 | decl_spec init_declarator_list TPtVirg 
     { let (returnType,storage) = fixDeclSpecForDecl $1 in
       let iistart = Ast_c.fakeInfo () in
       DeclList (
         ($2 +> List.map (fun ((((s,iis),f), ini), iivirg) -> 
           let ini, iini = 
             match ini with
             | None -> None, []
             | Some (ini, iini) -> Some ini, [iini]
           in
	   if fst (unwrap storage) = StoTypedef 
	   then LP.add_typedef s;
           (Some ((s, ini), iis::iini), f returnType, unwrap storage),
           iivirg 
         )
         ),  ($3::iistart::snd storage))
     } 
 /*(* cppext: *)*/
 | TMacroDecl TOPar argument_list TCPar TPtVirg 
     { MacroDecl ((fst $1, $3), [snd $1;$2;$4;$5;fakeInfo()]) }
 | Tstatic TMacroDecl TOPar argument_list TCPar TPtVirg 
     { MacroDecl ((fst $2, $4), [snd $2;$3;$5;$6;fakeInfo();$1]) }
 | Tstatic TMacroDeclConst TMacroDecl TOPar argument_list TCPar TPtVirg 
     { MacroDecl ((fst $3, $5), [snd $3;$4;$6;$7;fakeInfo();$1;$2])}







/*(*-----------------------------------------------------------------------*)*/
/*
(* In c++ grammar they put 'explicit' in function_spec, 'typedef' and 'friend' 
 * in decl_spec. But it's just estethic as no other rules directly
 * mention function_spec or storage_spec. They just want to say that 
 * 'virtual' applies only to functions, but they have no way to check that 
 * syntaxically. I could keep as before, as in the C grammar. 
 * For 'explicit' I prefer to put it directly
 * with the ctor as I already have a special heuristic for constructor.
 * They also don't put the cv_qualif here but instead inline it in
 * type_spec. I prefer to keep as before but I take care when
 * they speak about type_spec to translate instead in type+qualif_spec
 * (which is spec_qualif_list)
 * 
 * todo? can simplify by putting all in _opt ? must have at least one otherwise
 * decl_list is ambiguous ? (no cos have ';' between decl) 
 * 
 *)*/
decl_spec2: 
 | storage_class_spec      { {nullDecl with storageD = (fst $1, [snd $1]) } }
 | type_spec               { addTypeD ($1,nullDecl) }
 | cv_qualif               { {nullDecl with qualifD  = (fst $1, [snd $1]) } }
 | function_spec           { {nullDecl with inlineD = (true, [snd $1]) } (*TODO*) }
 | Ttypedef     { {nullDecl with storageD = (StoTypedef,  [$1]) } }
 | Tfriend      { {nullDecl with inlineD = (true, [$1]) } (*TODO*) }

 | storage_class_spec decl_spec2 { addStorageD ($1, $2) }
 | type_spec          decl_spec2 { addTypeD    ($1, $2) }
 | cv_qualif          decl_spec2 { addQualifD  ($1, $2) }
 | function_spec      decl_spec2 { addInlineD ((true, snd $1), $2) (*TODO*) }
 | Ttypedef           decl_spec2 { addStorageD ((StoTypedef,$1),$2) }
 | Tfriend            decl_spec2 { addInlineD ((true, $1),$2) (*TODO*)}




function_spec:
 /*(*gccext: and c++ext: *)*/
 | Tinline { Inline, $1 }
 /*(*c++ext: *)*/
 | Tvirtual { Virtual, $1 }


storage_class_spec: 
 | Tstatic      { Sto Static,  $1 }
 | Textern      { Sto Extern,  $1 }
 | Tauto        { Sto Auto,    $1 }
 | Tregister    { Sto Register,$1 }
 /*(* c++ext: *)*/
 | Tmutable     { Sto Register,$1 (*TODO*) }


/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/

decl_spec: decl_spec2    { dt "declspec" (); $1  }
simple_declaration: simple_declaration2 { et "simple_decl" (); $1 }




/*(*-----------------------------------------------------------------------*)*/
/*(* declarators (right part of type and variable) *)*/
/*(*-----------------------------------------------------------------------*)*/
init_declarator2:  
 | declaratori                  { ($1, None) }
 | declaratori teq initialize   { ($1, Some ($3, $2)) }

 /*(* c++ext: c++ initializer via call to constructor. note that this
    * is different from TypedefIdent2, here the declaratori is an ident,
    * not the constructorname hence the need for a TOParCplusplusInit
    * TODOAST
    *)*/
 | declaratori TOParCplusplusInit argument_list_opt TCPar { ($1, None) }


/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/
teq: TEq  { et "teq" (); $1 }

init_declarator: init_declarator2  { dt "init" (); $1 }



/*(*----------------------------*)*/
/*(* gccext: *)*/
/*(*----------------------------*)*/
declaratori: 
 | declarator                { LP.add_ident (fst (fst $1)); $1 }
 /*(* gccext: *)*/ 
 | declarator gcc_asm_decl   { LP.add_ident (fst (fst $1)); $1 }

gcc_asm_decl: 
 | Tasm TOPar asmbody TCPar              {  }
 | Tasm Tvolatile TOPar asmbody TCPar   {  }






			  
/*(*-----------------------------------------------------------------------*)*/
initialize: 
 | assign_expr                                    
     { InitExpr $1,                [] }
 | tobrace_ini initialize_list gcc_comma_opt_struct  tcbrace_ini
     { InitList (List.rev $2),     [$1;$4]++$3 }
 | tobrace_ini tcbrace_ini
     { InitList [],       [$1;$2] } /*(* gccext: *)*/


/*
(* opti: This time we use the weird order of non-terminal which requires in 
 * the "caller" to do a List.rev cos quite critical. With this wierd order it
 * allows yacc to use a constant stack space instead of exploding if we would
 * do a  'initialize2 Tcomma initialize_list'.
 *)
*/
initialize_list: 
 | initialize2                        { [$1,   []] }
 | initialize_list TComma initialize2 { ($3,  [$2])::$1 }


/*(* gccext: condexpr and no assign_expr cos can have ambiguity with comma *)*/
initialize2: 
 | cond_expr 
     { InitExpr $1,   [] } 
 | tobrace_ini initialize_list gcc_comma_opt_struct tcbrace_ini
     { InitList (List.rev $2),   [$1;$4]++$3 }
 | tobrace_ini tcbrace_ini
     { InitList [],  [$1;$2]  }

 /*(* gccext: labeled elements, a.k.a designators *)*/
 | designator_list TEq initialize2 
     { InitDesignators ($1, $3), [$2] }

 /*(* gccext: old format *)*/
 | ident TCol initialize2
     { InitFieldOld (fst $1, $3),     [snd $1; $2] } /*(* in old kernel *)*/
/*(*c++ext: remove conflict, but I think could be remove anyway
 | TOCro const_expr TCCro initialize2 
     { InitIndexOld ($2, $4),    [$1;$3] }
  *)*/




/*(* they can be nested, can have a .x.[3].y *)*/
designator: 
 | TDot ident 
     { DesignatorField (fst $2), [$1;snd $2] } 
 | TOCro const_expr TCCro     %prec SHIFTHERE
     { DesignatorIndex ($2),  [$1;$3] }
 | TOCro const_expr TEllipsis const_expr TCCro 
     { DesignatorRange ($2, $4),  [$1;$3;$5] }


/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/

gcc_comma_opt_struct: 
 | TComma {  [$1] } 
 | /*(* empty *)*/  {  [Ast_c.fakeInfo() +> Ast_c.rewrap_str ","]  }







/*(*************************************************************************)*/
/*(* struct/class *)*/
/*(*************************************************************************)*/

class_specifier: 
 | class_head TOBrace member_specification_opt tcbrace_struct 
     { let ((su, iisu), nameopt, baseopt) = $1 in
       let (baseopt, iibopt) = 
         match baseopt with 
         | None -> None, []
         | Some (ii, base) -> Some base, [ii]
       in
       (su, nameopt, baseopt, $3), [iisu;$2;$4]++iibopt
     }



/*
(* todo in grammar they allow anon class with base_clause, wierd. 
 * bugfixc++: in c++ grammar they put identifier but when we do template 
 * specialization then we can get some template_id. Note that can
 * not introduce a class_key_name intermediate cos they get a 
 * r/r conflict as there is another place with a 'class_key ident'
 * in elaborated specifier. So need to duplicate the rule for
 * the template_id case.
 * TODO
*)*/
class_head: 
 | class_key 
     { LP.push_context LP.InStructAnon;
       $1, None, None
     }
 | class_key ident base_clause_opt
     { LP.push_context (LP.InClassStruct (fst $2)); 
       let qid = IdIdent (fst $2), [snd $2] in
       let name = (None, noQscope, qid) in
       $1, Some name, $3
     }
 | class_key nested_name_specifier ident base_clause_opt
     { LP.push_context (LP.InClassStruct (fst $3)); 
       let qid = IdIdent (fst $3), [snd $3] in
       let name = (None, $2, qid) in
       $1, Some name, $4
     }



/*(* was called struct_union before *)*/
class_key2: 
 | Tstruct   { Struct, $1 }
 | Tunion    { Union, $1 }
 /*(*c++ext: *)*/
 | Tclass    { Class, $1 }


/*(* TODO add cpp_directive possibility here too *)*/
member_specification:
 | member_declaration member_specification_opt    
     { ClassElem $1::$2 }
 | access_specifier TCol member_specification_opt 
     { let access = Access (fst $1), [snd $1;$2] in
       ClassElem access::$3
     }

access_specifier:
 | Tpublic    { Public, $1 }
 | Tprivate   { Private, $1 }
 | Tprotected { Protected, $1 }



/*(* in c++ grammar there is a ;opt after function_definition but 
   * there is a conflict as it can also be an EmptyField *)*/
member_declaration:
 | field_declaration      { DeclarationField $1, noii }
 | function_definition    { Method $1, noii }
 | qualified_id TPtVirg   
     { let name = (None, fst $1, snd $1) in
       QualifiedIdInClass name, [$2]
     }
 | using_declaration      { UsingDeclInClass (fst $1), snd $1 }
 | template_declaration   { TemplateDeclInClass (fst $1), snd $1 }

 /*(* not in c++ grammar as merged with function_definition, but I can't *)*/
 | ctor_dtor_member       { $1 }

 /*(* cppext: as some macro sometimes have a trailing ';' we must allow
    * them here. Generates conflicts if keep the opt_ptvirg mentionned 
    * before.
    * c++ext: in c++ grammar they put a double optional but I prefer
    * to force the presence of a decl_spec. I don't know what means
    * 'x;' in a structure, maybe default to int but not practical for my way of
    * parsing
    *)*/
 | TPtVirg    { EmptyField, [$1] }







field_declaration:
 | decl_spec member_declarator_list TPtVirg 
     {  
       let (returnType,storage) = fixDeclSpecForDecl $1 in

       FieldDeclList ($2 +> (List.map (fun (f, iivirg) ->     
         f returnType (unwrap storage), iivirg
       )), $3::(snd storage)
       )
     }
 | decl_spec TPtVirg 
     { 
       (* gccext: allow empty elements if it is a structdef or enumdef *)
       let (returnType,storage) = fixDeclSpecForDecl $1 in
       let onedecl = (None, returnType, unwrap storage) in
       
       FieldDeclList (
         [(FieldDecl onedecl , noii),noii], 
         $2::(snd storage)) 
     }





/*(* was called struct_declarator before *)*/
member_declarator:
 | declaratorsd                    
     { let (name, partialt) = $1 in
       (fun returnType unwrap_storage -> 
         let var = Some ((fst name, None), [snd name]) in
         let onedecl = (var, partialt returnType, unwrap_storage) in
         (FieldDecl onedecl, noii)
       )
     }
 | declaratorsd pure_specifier
     { let (name, partialt) = $1 in
       (fun returnType unwrap_storage -> 
         (*TODO detect methodDecl *)
         let onedecl = (None, partialt returnType, unwrap_storage) in
         (FieldDecl onedecl, $2)
       )
     }
 | declaratorsd constant_initializer
     { let (name, partialt) = $1 in
       (fun returnType unwrap_storage -> 
         let ini = InitExpr (snd $2), noii in
         let var = Some ((fst name, Some ini), [snd name;fst $2]) in
         let onedecl = (var, partialt returnType, unwrap_storage) in
         (FieldDecl onedecl, noii)
       )
     }

 /*(* normally just ident, but ambiguity so solve by inspetcing declarator *)*/
 | declaratorsd col const_expr2 
     { let (name, partialt) = $1 in
       (fun returnType unwrap_storage -> 
         let var = Some (fst name) in
         BitField (var, returnType, $3), [snd name; $2]
       )
     }
 | col const_expr2            
     { (fun returnType unwrap_storage -> 
         BitField (None, returnType, $2), [$1]
       )
     }




/*(* could also solve ambiguity without the special-token technique by
   * merging pure_specifier and constant_initializer and disambiguating
   * by looking at the form of the declaratorsd.
   * TODO do the heuristic in parsing_hack for TIntZeroVirtual
   *)*/
pure_specifier:
 | TEq TIntZeroVirtual { [$1;$2] }

constant_initializer:
 | TEq const_expr2 { $1, $2 }




/*(* special case for ctor/dtor cos they don't have a return type *)*/
ctor_dtor_member:
 | explicit_opt Tconstructorname topar parameter_type_list_opt tcpar
     ctor_mem_initializer_list_opt
     compound
     {  EmptyField, [](*TODO*) }

 | explicit_opt Tconstructorname topar parameter_type_list_opt tcpar
     ctor_mem_initializer_list_opt
     TPtVirg 
     { EmptyField, [](*TODO*) }

 | Tinline Tconstructorname topar parameter_type_list_opt tcpar
     ctor_mem_initializer_list_opt
     TPtVirg 
     { EmptyField, [](*TODO*) }

 | Tinline Tconstructorname topar parameter_type_list_opt tcpar
     ctor_mem_initializer_list_opt
     compound
     {  EmptyField, [](*TODO*) }


 | virtual_opt TTilde ident3 TOPar void_opt TCPar compound
     { EmptyField, [](*TODO*) }
 | virtual_opt TTilde ident3 TOPar void_opt TCPar  TPtVirg
     { EmptyField, [](*TODO*) }

 | Tinline TTilde ident3 TOPar void_opt TCPar compound
     { EmptyField, [](*TODO*) }
 | Tinline TTilde ident3 TOPar void_opt TCPar  TPtVirg
     { EmptyField, [](*TODO*) }


/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/

/*(*TODO? need more workaround ? cf old struct code *)*/

declaratorsd: declarator 
  { (*also ? LP.add_ident (fst (fst $1)); *) $1 }

class_key: class_key2 { et "su" (); $1 }

const_expr2: const_expr { dt "const_expr2" (); $1 }

col: TCol  { et "dotdot" (); $1 }


/*(*************************************************************************)*/
/*(* enum *)*/
/*(*************************************************************************)*/

enum_specifier: 
 | Tenum        tobrace_enum enumerator_list gcc_comma_opt tcbrace_enum
     { Enum (None,    $3),           [$1;$2;$5] ++ $4 }
 | Tenum ident  tobrace_enum enumerator_list gcc_comma_opt tcbrace_enum
     { Enum (Some (fst $2), $4),     [$1; snd $2; $3;$6] ++ $5 }

enumerator: 
 | idente                 { (fst $1, None),      [snd $1]    }
 | idente  TEq const_expr { (fst $1, Some $3),   [snd $1; $2] }



/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/
idente: ident { LP.add_ident (fst $1); $1 }




/*(*************************************************************************)*/
/*(* OO aux *)*/
/*(*************************************************************************)*/

/*(*----------------------------*)*/
/*(* c++ext: inheritance rules *)*/
/*(*----------------------------*)*/

base_clause: 
 | TCol base_specifier_list { $1, $2 }

/*(* base-specifier:
   *  ::opt nested-name-specifieropt class-name
   *  virtual access-specifieropt ::opt nested-name-specifieropt class-name
   *  access-specifier virtualopt ::opt nested-name-specifieropt class-name
   * specialisation
   *)*/
base_specifier:
 | access_specifier class_name 
     { 
       let qid = IdIdent (fst $2), [snd $2] in 
       let name = (None, noQscope, qid) in
       (name, false, Some (fst $1)), [snd $1]
     }
 | class_name 
     { 
       let qid = IdIdent (fst $1), [snd $1] in 
       let name = (None, noQscope, qid) in
       (name, false, None), noii
     }
 | Tvirtual access_specifier class_name 
     { 
       let qid = IdIdent (fst $3), [snd $3] in 
       let name = (None, noQscope, qid) in
       (name, true, Some (fst $2)), [$1;snd $2]
     }



/*(* todo? can be template_id  *)*/
class_name:
/* specialisation | ident3 { $1 } */
 | type_cplusplus_id { "todo", Ast_c.fakeInfo() (* TODOAST *) }
 | TIdent { $1 }


/*(*----------------------------*)*/
/*(* c++ext: ctor rules *)*/
/*(*----------------------------*)*/

ctor_mem_initializer_list_opt: 
 | TCol mem_initializer_list { () }
 | /*(* empty *)*/ { () }

mem_initializer: 
 | mem_initializer_id TOPar argument_list_opt TCPar { () }

/*(* factorize with declarator_id ? specialisation *)*/
mem_initializer_id:
/* specialsiation | TIdent { () } */
 | primary_cplusplus_id { () }


/*(*************************************************************************)*/
/*(* function *)*/
/*(*************************************************************************)*/

function_definition: start_fun compound                { fixFunc ($1, $2) }

start_fun: decl_spec declaratorfd  
     { let (returnType,storage) = fixDeclSpecForFuncDef $1 in
       let res = 
        (fst $2, fixOldCDecl ((snd $2) returnType) , storage)  in
       fix_add_params_ident res; 
       res
     }

/*(*----------------------------*)*/
/*(* workarounds *)*/
/*(*----------------------------*)*/
declaratorfd: declarator { et "declaratorfd" (); $1 }


/*(*************************************************************************)*/
/*(* declaration, in c++ sense *)*/
/*(*************************************************************************)*/

/*
(* in grammar they have 'explicit_instantiation' but it is equal to 
 * to template_declaration and so is ambiguous.
 *)*)*/
declaration:
 | block_declaration                 { Declaration $1, noii }
 | function_definition               { Definition $1, noii }
 | template_declaration              { TemplateDecl (fst $1), snd $1 }
 | explicit_specialization           { $1 }
 | linkage_specification             { $1 }         
 | namespace_definition              { $1 }
 /*(* not in c++ grammar as merged with function_definition, but I can't *)*/
 | ctor_dtor { $1 }




declaration_list: 
 | declaration_seq                  { [$1]   }
 | declaration_list declaration_seq { $1 ++ [$2] }

declaration_list_opt: 
 | /*(*empty*)*/ { [] }
 | declaration_list { $1 }

declaration_seq:
 | declaration { DeclElem $1 }
 /* (* cppext: *)*/
 | cpp_directive 
     { CppDirectiveDecl $1 }
 | cpp_ifdef_directive/*(* stat_or_decl_list ...*)*/  
     { IfdefDecl $1 }






/*(*todo: export_opt, but generates lots of conflicts *)*/ 
template_declaration:
 | Ttemplate tinf_template template_parameter_list tsup_template declaration
   { ($3, $5), [$1;$2;$4] (* todo ++ some_to_list $1*) }

explicit_specialization:
 | Ttemplate TInf2 TSup2 declaration 
     { TemplateSpecialization $4,[$1;$2;$3]}

/*(*todo: '| type_paramter' 
   * ambiguity with parameter_decl cos a type can also be 'class X'
 | Tclass ident { raise Todo }
   *)*/
template_parameter: 
 | parameter_decl { $1 }





/*(* c++ext: could also do a extern_string_opt to factorize stuff *)*/
linkage_specification:
 | Textern TString declaration 
     { ExternC $3, [$1;snd $2] }
 | Textern TString TOBrace declaration_list_opt TCBrace 
     { ExternCList $4, [$1;snd $2;$3;$5] }




namespace_definition:
 | named_namespace_definition   { $1 }
 | unnamed_namespace_definition { $1 }

/*
(* in c++ grammar they make diff between 'original' and 'extension' namespace
 * definition but they require some contextual information to know if
 * an identifier was already a namespace. So here I have just a single rule.
 *)*/
named_namespace_definition: 
 | Tnamespace TIdent TOBrace declaration_list_opt TCBrace 
     { NameSpace (fst $2, $4), [$1; snd $2; $3; $5] }

unnamed_namespace_definition:
 | Tnamespace TOBrace declaration_list_opt TCBrace 
     { NameSpaceAnon $3, [$1;$2;$4] }



/*
(* Special case cos ctor/dtor do not have return type. 
 * TODO scope ? do a start_constructor ? 
 *)*/
ctor_dtor:
 | nested_name_specifier Tconstructorname topar parameter_type_list_opt tcpar
     ctor_mem_initializer_list_opt
     compound
     { NameSpaceAnon [],[] }
 /*(* new_type_id, could also introduce a Tdestructorname or forbidy the
      TypedefIdent2 transfo by putting a guard in the lalr(k) rule by
      checking if have a ~ before
   *)*/
 | nested_name_specifier TTilde ident3 TOPar void_opt TCPar
     compound
     { NameSpaceAnon [],[] }



/*(*************************************************************************)*/
/*(* cpp directives *)*/
/*(*************************************************************************)*/

/*(* cppext: *)*/
cpp_directive: 
 | TIncludeStart TIncludeFilename 
     { 
       let (i1, in_ifdef) = $1 in
       let (s, i2) = $2 in

       (* redo some lexing work :( *)
       let inc_file = 
         match () with
         | _ when s =~ "^\"\\(.*\\)\"$" -> 
             Local (Common.split "/" (matched1 s))
         | _ when s =~ "^\\<\\(.*\\)\\>$" -> 
             NonLocal (Common.split "/" (matched1 s))
         | _ -> 
             Wierd s 
       in
       Include ((inc_file, [i1;i2]), (Ast_c.noRelPos(), !in_ifdef)) 
     }

 | TDefine TIdentDefine define_val TDefEOL 
     { Define ((fst $2, [$1; snd $2;$4]), (DefineVar, $3)) }

 /*
 (* The TOParDefine is introduced to avoid ambiguity with previous rules.
  * A TOParDefine is a TOPar that was just next to the ident.
  *)*/
 | TDefine TIdentDefine TOParDefine param_define_list_opt TCPar define_val TDefEOL
     { Define 
         ((fst $2, [$1; snd $2;$7]), 
           (DefineFunc ($4, [$3;$5]), $6)) 
     }






/*(* perhaps better to use assign_expr ? but in that case need 
   * do a assign_expr_of_string in parse_c.
   * c++ext: update, now statement include simple declarations
   * todo? maybe can parse $1 and generate the previous DefineDecl
   * and DefineFunction ? cos nested_func is also now inside statement.
   *)*/
define_val: 
 | expr      { DefineExpr $1 }
 | statement { DefineStmt $1 }
 /*(*c++ext: remove a conflict on TCPar
 | Tdo statement Twhile TOPar TInt TCPar 
     {
       if fst $5 <> "0" 
       then pr2 "WIERD: in macro and have not a while(0)";
       DefineDoWhileZero ($2,  [$1;$3;$4;snd $5;$6])
     }
  *)*/
 | TOBraceDefineInit initialize_list TCBrace comma_opt 
    { DefineInit (InitList (List.rev $2), [$1;$3]++$4)  }
 /*(* but quite stupid cos better to use typedef than define for that *)*/
 | TypedefIdent 
    { DefineType (nQ,(TypeName(fst $1,noTypedefDef()),[snd $1]))}
 | /*(* empty *)*/ { DefineEmpty }




param_define:
 | TIdent               { fst $1, [snd $1] } 
 | TypedefIdent         { fst $1, [snd $1] } 
 | TDefParamVariadic    { fst $1, [snd $1] } 
 | TEllipsis            { "...", [$1] }
 /*(* they reuse keywords :(  *)*/
 | Tregister            { "register", [$1] }
 | Tnew                 { "new", [$1] }


cpp_ifdef_directive: 
 | TIfdef     { IfdefDirective [$1] }
 | TIfdefelse { IfdefDirective [$1] }
 | TIfdefelif { IfdefDirective [$1] }
 | TEndif     { IfdefDirective [$1] }

 | TIfdefBool  { IfdefDirective [snd $1] }
 | TIfdefMisc  { IfdefDirective [snd $1] }
 | TIfdefVersion { IfdefDirective [snd $1] }



cpp_other:
/*(* cppext: *)*/
 | TIdent TOPar argument_list TCPar TPtVirg
     { MacroTop (fst $1, $3,    [snd $1;$2;$4;$5]) } 

 /*(* TCParEOL to fix the end-of-stream bug of ocamlyacc *)*/
 | TIdent TOPar argument_list TCParEOL
     { MacroTop (fst $1, $3,    [snd $1;$2;$4;fakeInfo()]) } 

  /*(* ex: EXPORT_NO_SYMBOLS; *)*/
 | TIdent TPtVirg { EmptyDef [snd $1;$2] }



/*(*************************************************************************)*/
/*(* celem *)*/
/*(*************************************************************************)*/

celem: 
 | declaration       { TopDecl $1 }


 | cpp_directive     { CppTop $1 }

 | cpp_ifdef_directive /* (*external_declaration_list ...*)*/
     { IfdefTop $1 }

 | cpp_other     { $1 }

 /*
 (* in ~/kernels/src/linux-2.5.2/drivers/isdn/hisax/isdnl3.c sometimes
  * the function ends with }; instead of just } 
  * can also remove this rule and report "parse error" pb to morton
  *)*/
 | TPtVirg    { EmptyDef [$1] } 

 | EOF        { FinalDef $1 } 






/*(*************************************************************************)*/
/*(* some generic workarounds *)*/
/*(*************************************************************************)*/

tobrace: TOBrace  { LP.push_context LP.InFunction; LP.new_scope (); $1 }
tcbrace: TCBrace  { LP.pop_context();              LP.del_scope (); $1 }

tobrace_enum: TOBrace { LP.push_context LP.InEnum; $1 }
tcbrace_enum: TCBrace { LP.pop_context (); $1 }

tobrace_ini: TOBrace { LP.push_context LP.InInitializer; $1 }
tcbrace_ini: TCBrace { LP.pop_context (); $1 }

/*(*tobrace_struct: TOBrace { LP.push_context LP.InStructAnon; $1 }*)*/
tcbrace_struct: TCBrace { LP.pop_context (); $1 }

/*(*todo? put some et() dt() ? *)*/
tinf_template: TInf2 { LP.push_context LP.InTemplateParam; $1 }
tsup_template: TSup2 { LP.pop_context(); $1 }


topar: TOPar 
     { LP.new_scope ();et "topar" (); 
       LP.push_context LP.InParameter;
       $1  
     }
tcpar: TCPar 
     { LP.del_scope ();dt "tcpar" (); 
       LP.pop_context (); 
       $1  
     }

/*(*************************************************************************)*/
/*(* xxx_list, xxx_opt *)*/
/*(*************************************************************************)*/






string_list: 
 | string_elem { $1 }
 | string_list string_elem { $1 ++ $2 } 

colon_asm_list: 
 | colon_asm { [$1] }
 | colon_asm_list colon_asm  { $1 ++ [$2] }

colon_option_list: 
 | colon_option { [$1, []] } 
 | colon_option_list TComma colon_option { $1 ++ [$3, [$2]] }





argument_list: 
 | argument                           { [$1, []] }
 | argument_list TComma argument { $1 ++ [$3,    [$2]] }



enumerator_list: 
 | enumerator                        { [$1,          []]   }
 | enumerator_list TComma enumerator { $1 ++ [$3,    [$2]] }


init_declarator_list: 
 | init_declarator                             { [$1,   []] }
 | init_declarator_list TComma init_declarator { $1 ++ [$3,     [$2]] }

member_declarator_list: 
 | member_declarator                             { [$1,   []] }
 | member_declarator_list TComma member_declarator { $1 ++ [$3,     [$2]] }


parameter_list: 
 | parameter_decl                       { [$1, []] }
 | parameter_list TComma parameter_decl { $1 ++ [$3,  [$2]] }

taction_list: 
/*(* c++ext: to remove some conflicts (from 13 to 4)
   * | (* empty *) { [] } 
   *)*/
 | TAction { [$1] }
 | taction_list TAction { $1 ++ [$2] }

param_define_list_opt: 
 | /*(* empty *)*/ { [] }
 | param_define                           { [$1, []] }
 | param_define_list_opt TComma param_define  { $1 ++ [$3, [$2]] }

designator_list: 
 | designator { [$1] }
 | designator_list designator { $1 ++ [$2] }









handler_list:
 | handler { [$1] }
 | handler_list handler { $1 ++ [$2] }


mem_initializer_list: 
 | mem_initializer                           { [$1, []] }
 | mem_initializer_list TComma mem_initializer  { $1 ++ [$3, [$2]] }

template_argument_list:
 | template_argument { [$1, []] }
 | template_argument_list TComma template_argument { $1 ++ [$3, [$2]] }

template_parameter_list: 
 | template_parameter { [$1, []] }
 | template_parameter_list TComma template_parameter { $1 ++ [$3, [$2]] }


base_specifier_list: 
 | base_specifier                               { [$1,           []] }
 | base_specifier_list TComma base_specifier    { $1 ++ [$3,     [$2]] }






/*(*-----------------------------------------------------------------------*)*/

/*(* gccext:  which allow a trailing ',' in enum, as in perl *)*/
gcc_comma_opt: 
 | TComma {  [$1] } 
 | /*(* empty *)*/  {  []  }

comma_opt:
 | TComma { [$1] }
 | { [] }




gcc_opt_expr: 
 | expr        { Some $1 }
 | /*(* empty *)*/ { None  }

assign_expr_opt: 
 | assign_expr     { Some $1 }
 | /*(* empty *)*/ { None }

expr_opt: 
 | expr            { Some $1 }
 | /*(* empty *)*/ { None }





argument_list_opt:
 | argument_list { $1 }
 | /*(*empty*)*/ { [] }

parameter_type_list_opt:
 | parameter_type_list { Some $1 }
 | /*(*empty*)*/       { None }




member_specification_opt:
 | member_specification { $1 }
 | /*(*empty*)*/        { [] }





nested_name_specifier_opt:
 | nested_name_specifier { $1 }
 | /*(* empty *)*/       { [] }

nested_name_specifier_opt2:
 | nested_name_specifier2 { $1 }
 | /*(* empty *)*/        { [] }



exception_specification_opt: 
 | exception_specification { Some $1 }
 | /*(*empty*)*/           { None }


/*(*c++ext: ??? *)*/
new_placement_opt:
 | new_placement { () }
 | /*(*empty*)*/ { () }

new_initializer_opt:
 | new_initializer { () }
 | /*(*empty*)*/ { () }



virtual_opt:
 | Tvirtual      { Some $1 }
 | /*(*empty*)*/ { None }

explicit_opt:
 | Texplicit     { Some $1 }
 | /*(*empty*)*/ { None }

base_clause_opt: 
 | base_clause   { Some $1 }
 | /*(*empty*)*/ { None }

typename_opt:
 | Ttypename     { [$1] }
 | /*(*empty*)*/ { [] }

template_opt:
 | Ttemplate     { [$1] }
 | /*(*empty*)*/ { [] }

/*
export_opt:
 | Texport   { Some $1 }
 | (*empty*) { None }

ptvirg_opt:
 | TPtVirg { [$1] }
 | { [] }
*/


void_opt:
 | Tvoid         { Some $1 }
 | /*(*empty*)*/ { None }

