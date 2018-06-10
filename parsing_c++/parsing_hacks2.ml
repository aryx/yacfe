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

module TH = Token_helpers2 
module LP = Lexer_parser2

module Stat = Parsing_stat2

open Parser_cplusplus

module Flag_parsing_c = Flag_parsing_cplusplus
module Parser_c = Parser_cplusplus
module Ast_c = Ast_cplusplus

(*****************************************************************************)
(* Some debugging functions  *)
(*****************************************************************************)

let pr2 s = 
  if !Flag_parsing_c.verbose_parsing 
  then Common.pr2 s

let pr2_cpp s = 
  if !Flag_parsing_c.debug_cpp
  then Common.pr2_once ("CPP-" ^ s)

let pr2_cplusplus s = 
  if !Flag_parsing_c.debug_cplusplus
  then Common.pr2_once ("C++-" ^ s)


(* In the following, there are some harcoded names of types or macros
 * but they are not used by our heuristics! They are just here to
 * enable to detect false positive by printing only the typedef/macros
 * that we don't know yet. If we print everything, then we can easily
 * get lost with too much verbose tracing information. So those
 * functions "filter" some messages. So our heuristics are still good,
 * there is no more (or not that much) hardcoded linux stuff.
 *)

let msg_gen cond is_known printer s = 
  if cond
  then
    if not (!Flag_parsing_c.filter_msg)
    then printer s
    else
      if not (is_known s)
      then printer s
        




(* note: cant use partial application with let msg_typedef = 
 * because it would compute msg_typedef at compile time when 
 * the flag debug_typedef is always false
 *)
let msg_typedef (s,ii) = 
  msg_gen (!Flag_parsing_c.debug_typedef)
    (fun s -> 
      (match s with
      | "u_char"   | "u_short"  | "u_int"  | "u_long"
      | "u8" | "u16" | "u32" | "u64" 
      | "s8"  | "s16" | "s32" | "s64" 
      | "__u8" | "__u16" | "__u32"  | "__u64"  
          -> true
          
      | "acpi_handle" 
      | "acpi_status" 
        -> true

      | "FILE" 
      | "DIR" 
        -> true
          
      | s when s =~ ".*_t$" -> true
      | _ -> false 
      )
    )
    (fun s -> 
      pr2_cpp ("TYPEDEF: promoting: " ^ s);
      if !Flag_parsing_c.debug_typedef_location
      then 
        pr2_cpp ("loc: " ^
                 Common.string_of_parse_info (Ast_c.parse_info_of_info ii))
    )
    s




let msg_declare_macro s = 
  msg_gen (!Flag_parsing_c.debug_cpp)
    (fun s -> 
      (match s with 
      | "DECLARE_MUTEX" | "DECLARE_COMPLETION"  | "DECLARE_RWSEM"
      | "DECLARE_WAITQUEUE" | "DECLARE_WAIT_QUEUE_HEAD" 
      | "DEFINE_SPINLOCK" | "DEFINE_TIMER"
      | "DEVICE_ATTR" | "CLASS_DEVICE_ATTR" | "DRIVER_ATTR"
      | "SENSOR_DEVICE_ATTR"
      | "LIST_HEAD"
      | "DECLARE_WORK"  | "DECLARE_TASKLET"
      | "PORT_ATTR_RO" | "PORT_PMA_ATTR"
      | "DECLARE_BITMAP"

          -> true
 (*
      | s when s =~ "^DECLARE_.*" -> true
      | s when s =~ ".*_ATTR$" -> true
      | s when s =~ "^DEFINE_.*" -> true
      | s when s =~ "NS_DECL.*" -> true
 *)

      | _ -> false
      )
    )
    (fun s -> pr2_cpp ("MACRO: found declare-macro: " ^ s))
    s
      

let msg_foreach s = 
  pr2_cpp ("MACRO: found foreach: " ^ s)


let msg_debug_macro s = 
  pr2_cpp ("MACRO: found debug-macro: " ^ s)


let msg_macro_noptvirg s = 
  pr2_cpp ("MACRO: found macro with param noptvirg: " ^ s)

let msg_macro_toplevel_noptvirg s = 
  pr2_cpp ("MACRO: found toplevel macro noptvirg: " ^ s)


let msg_macro_noptvirg_single s = 
  pr2_cpp ("MACRO: found single-macro noptvirg: " ^ s)


let msg_macro_higher_order s = 
  msg_gen (!Flag_parsing_c.debug_cpp)
    (fun s -> 
      (match s with 
      | "DBGINFO"
      | "DBGPX"
      | "DFLOW"
        -> true
      | _ -> false
      )
    )
    (fun s -> pr2_cpp ("MACRO: found higher ordre macro : " ^ s))
    s


let msg_stringification s = 
  msg_gen (!Flag_parsing_c.debug_cpp)
    (fun s -> 
      (match s with 
      | "REVISION"
      | "UTS_RELEASE"
      | "SIZE_STR"
      | "DMA_STR"
          -> true
      (* s when s =~ ".*STR.*" -> true  *) 
      | _ -> false
      )
    )
    (fun s -> pr2_cpp ("MACRO: found string-macro " ^ s))
    s

let msg_classname s = 
  pr2_cplusplus ("CLASSNAME: found " ^ s)

let msg_templatename s = 
  pr2_cplusplus ("TEMPLATENAME: found " ^ s)

let msg_constructorname s = 
  pr2_cplusplus ("CONSTRUCTORNAME: found " ^ s)
  

(*****************************************************************************)
(* The regexp and basic view definitions *)
(*****************************************************************************)

(* opti: better to built then once and for all, especially regexp_foreach *)

let regexp_macro =  Str.regexp
  "^[A-Z_][A-Z_0-9]*$"

(* linuxext: *)
let regexp_annot =  Str.regexp
  "^__.*$"

(* linuxext: *)
let regexp_declare =  Str.regexp
  ".*DECLARE.*"

(* linuxext: *)
let regexp_foreach = Str.regexp_case_fold 
  ".*\\(for_?each\\|for_?all\\|iterate\\|loop\\|walk\\|scan\\|each\\|for\\)"

(* firefoxext: *)
let regexp_ns_decl_like = Str.regexp
  ("\\(" ^
   "NS_DECL_\\|NS_DECLARE_\\|NS_IMPL_\\|" ^ 
   "NS_IMPLEMENT_\\|NS_INTERFACE_\\|NS_FORWARD_\\|NS_HTML_\\|" ^
   "NS_DISPLAY_\\|NS_IMPL_\\|" ^
   "TX_DECL_\\|DOM_CLASSINFO_\\|NS_CLASSINFO_\\|IMPL_INTERNAL_\\|" ^
   "ON_\\|EVT_\\|NS_UCONV_\\|NS_GENERIC_\\|NS_COM_" ^
   "\\).*")



let regexp_typedef = Str.regexp
  ".*_t$"


let false_typedef = [
  "printk";
  ]

let ok_typedef s = not (List.mem s false_typedef)

let not_annot s = 
  not (s ==~ regexp_annot)

type define_body = (unit,string list) either * Parser_c.token list

let (_defs : (string, define_body) Hashtbl.t ref)  = 
  ref (Hashtbl.create 101)


(* ------------------------------------------------------------------------- *)
(* fuzzy parsing, different "views" over the same program *)
(* ------------------------------------------------------------------------- *)


(* Normally I should not use ref/mutable in the token_extended type
 * and I should have a set of functions taking a list of tokens and
 * returning a list of tokens. The problem is that to make easier some
 * functions, it is better to work on better representation, on "views"
 * over this list of tokens. But then modifying those views and get
 * back from those views to the original simple list of tokens is
 * tedious. One way is to maintain next to the view a list of "actions"
 * (I was using a hash storing the charpos of the token and associating
 * the action) but it is tedious too. Simpler to use mutable/ref. We
 * use the same idea that we use when working on the Ast_c. *)

(* old: when I was using the list of "actions" next to the views, the hash
 * indexed by the charpos, there could have been some problems:
 * how my fake_pos interact with the way I tag and adjust token ?
 * because I base my tagging on the position of the token ! so sometimes
 * could tag another fakeInfo that should not be tagged ? 
 * fortunately I don't use anymore this technique.
 *)

(* update: quite close to the Place_c.Inxxx.
 * update: now that can have complex nesting of class/func in c++,
 *  this type is also present in duplicated form in lexer_parser2.ml
 * 
 * The strategy to set the tag is simply to look at the token 
 * before the '{'.
 *)
type context = 
  InFunction | InEnum | InStruct | InInitializer | NoContext

type token_extended = { 
  mutable tok: Parser_c.token;
  mutable where: context;

  (* less: need also a after ? *)
  mutable new_tokens_before : Parser_c.token list;

  (* line x col  cache, more easily accessible, of the info in the token *)
  line: int; 
  col : int;
}

let set_as_comment cppkind x = 
  (* normally the caller have first filtered the set of tokens to have
   * a clearer "view" to work on
   *)
  assert(not (TH.is_real_comment x.tok));

  if TH.is_eof x.tok 
  then () (* otherwise parse_c will be lost if don't find a EOF token *)
  else 
    x.tok <- TCommentCpp (cppkind, TH.info_of_tok x.tok)


let set_as_opar_cplusplus xs = 
  match xs with
  | ({tok = TOPar ii} as tok1)::xs -> 
      pr2_cplusplus "TOParCplusplusInit";
      tok1.tok <- TOParCplusplusInit ii;
      
  | _ -> raise  Impossible

let mk_token_extended x = 
  let (line, col) = TH.linecol_of_tok x in
  { tok = x; 
    line = line; col = col; 
    where = NoContext; 
    new_tokens_before = [];
  }




(* x list list, because x list separated by ',' *) 
type paren_grouped = 
  | Parenthised   of paren_grouped list list * token_extended list
  | PToken of token_extended

type brace_grouped = 
  | Braceised   of 
      brace_grouped list list * token_extended * token_extended option
  | BToken of token_extended

(* Far better data structure than doing hacks in the lexer or parser
 * because in lexer we don't know to which ifdef a endif is related
 * and so when we want to comment a ifdef, we don't know which endif
 * we must also comment. Especially true for the #if 0 which sometimes
 * have a #else part.
 * 
 * x list list, because x list separated by #else or #elif 
 *) 
type ifdef_grouped = 
  | Ifdef     of ifdef_grouped list list * token_extended list
  | Ifdefbool of bool * ifdef_grouped list list * token_extended list
  | NotIfdefLine of token_extended list


type 'a line_grouped = 
  Line of 'a list


type body_function_grouped = 
  | BodyFunction of token_extended list
  | NotBodyLine  of token_extended list


(* ------------------------------------------------------------------------- *)
(* view builders  *)
(* ------------------------------------------------------------------------- *)

(* todo: synchro ! use more indentation 
 * if paren not closed and same indentation level, certainly because
 * part of a mid-ifdef-expression.
*)
let rec mk_parenthised xs = 
  match xs with
  | [] -> []
  | x::xs -> 
      (match x.tok with 
      | xx when TH.is_opar xx -> 
          let body, extras, xs = mk_parameters [x] [] xs in
          Parenthised (body,extras)::mk_parenthised xs
      | _ -> 
          PToken x::mk_parenthised xs
      )

(* return the body of the parenthised expression and the rest of the tokens *)
and mk_parameters extras acc_before_sep  xs = 
  match xs with
  | [] -> 
      (* maybe because of #ifdef which "opens" '(' in 2 branches *)
      pr2 "PB: not found closing paren in fuzzy parsing";
      [List.rev acc_before_sep], List.rev extras, []
  | x::xs -> 
      (match x.tok with 
      (* synchro *)
      | xx when TH.is_obrace xx && x.col = 0 -> 
          pr2 "PB: found synchro point } in paren";
          [List.rev acc_before_sep], List.rev (extras), (x::xs)

      | xx when TH.is_cpar xx  -> 
          [List.rev acc_before_sep], List.rev (x::extras), xs
      | xx when TH.is_opar xx -> 
          let body, extrasnest, xs = mk_parameters [x] [] xs in
          mk_parameters extras 
            (Parenthised (body,extrasnest)::acc_before_sep) 
            xs
      | TComma _ -> 
          let body, extras, xs = mk_parameters (x::extras) [] xs in
          (List.rev acc_before_sep)::body, extras, xs 
      | _ -> 
          mk_parameters extras (PToken x::acc_before_sep) xs
      )




let rec mk_braceised xs = 
  match xs with
  | [] -> []
  | x::xs -> 
      (match x.tok with 
      | xx when TH.is_obrace xx -> 
          let body, endbrace, xs = mk_braceised_aux [] xs in
          Braceised (body, x, endbrace)::mk_braceised xs
      | xx when TH.is_cbrace xx -> 
          pr2 "PB: found closing brace alone in fuzzy parsing";
          BToken x::mk_braceised xs
      | _ -> 
          BToken x::mk_braceised xs
      )

(* return the body of the parenthised expression and the rest of the tokens *)
and mk_braceised_aux acc xs = 
  match xs with
  | [] -> 
      (* maybe because of #ifdef which "opens" '(' in 2 branches *)
      pr2 "PB: not found closing brace in fuzzy parsing";
      [List.rev acc], None, []
  | x::xs -> 
      (match x.tok with 
      | xx when TH.is_cbrace xx -> [List.rev acc], Some x, xs
      | xx when TH.is_obrace xx -> 
          let body, endbrace, xs = mk_braceised_aux [] xs in
          mk_braceised_aux  (Braceised (body,x, endbrace)::acc) xs
      | _ -> 
          mk_braceised_aux (BToken x::acc) xs
      )

          


let rec mk_ifdef xs = 
  match xs with
  | [] -> []
  | x::xs -> 
      (match x.tok with 
      | TIfdef _ -> 
          let body, extra, xs = mk_ifdef_parameters [x] [] xs in
          Ifdef (body, extra)::mk_ifdef xs
      | TIfdefBool (b,_) -> 
          let body, extra, xs = mk_ifdef_parameters [x] [] xs in
          
          (* if not passing, then consider a #if 0 as an ordinary #ifdef *)
          if !Flag_parsing_c.if0_passing
          then Ifdefbool (b, body, extra)::mk_ifdef xs
          else Ifdef(body, extra)::mk_ifdef xs

      | TIfdefMisc (b,_) | TIfdefVersion (b,_) -> 
          let body, extra, xs = mk_ifdef_parameters [x] [] xs in
          Ifdefbool (b, body, extra)::mk_ifdef xs

          
      | _ -> 
          (* todo? can have some Ifdef in the line ? *)
          let line, xs = Common.span (fun y -> y.line = x.line) (x::xs) in
          NotIfdefLine line::mk_ifdef xs 
      )

and mk_ifdef_parameters extras acc_before_sep xs = 
  match xs with
  | [] -> 
      (* Note that mk_ifdef is assuming that CPP instruction are alone
       * on their line. Because I do a span (fun x -> is_same_line ...)
       * I might take with me a #endif if this one is mixed on a line
       * with some "normal" tokens.
       *)
      pr2 "PB: not found closing ifdef in fuzzy parsing";
      [List.rev acc_before_sep], List.rev extras, []
  | x::xs -> 
      (match x.tok with 
      | TEndif _ -> 
          [List.rev acc_before_sep], List.rev (x::extras), xs
      | TIfdef _ -> 
          let body, extrasnest, xs = mk_ifdef_parameters [x] [] xs in
          mk_ifdef_parameters 
            extras (Ifdef (body, extrasnest)::acc_before_sep) xs

      | TIfdefBool (b,_) -> 
          let body, extrasnest, xs = mk_ifdef_parameters [x] [] xs in

          if !Flag_parsing_c.if0_passing
          then
            mk_ifdef_parameters 
              extras (Ifdefbool (b, body, extrasnest)::acc_before_sep) xs
          else 
            mk_ifdef_parameters 
              extras (Ifdef (body, extrasnest)::acc_before_sep) xs


      | TIfdefMisc (b,_) | TIfdefVersion (b,_) -> 
          let body, extrasnest, xs = mk_ifdef_parameters [x] [] xs in
          mk_ifdef_parameters 
            extras (Ifdefbool (b, body, extrasnest)::acc_before_sep) xs

      | TIfdefelse _ 
      | TIfdefelif _ -> 
          let body, extras, xs = mk_ifdef_parameters (x::extras) [] xs in
          (List.rev acc_before_sep)::body, extras, xs 
      | _ -> 
          let line, xs = Common.span (fun y -> y.line = x.line) (x::xs) in
          mk_ifdef_parameters extras (NotIfdefLine line::acc_before_sep) xs
      )

(* --------------------------------------- *)

let line_of_paren = function
  | PToken x -> x.line
  | Parenthised (xxs, info_parens) -> 
      (match info_parens with
      | [] -> raise Impossible
      | x::xs -> x.line
      )

let rec span_line_paren line = function
  | [] -> [],[]
  | x::xs -> 
      (match x with
      | PToken tok when TH.is_eof tok.tok -> 
          [], x::xs
      | _ -> 
        if line_of_paren x = line 
        then
          let (l1, l2) = span_line_paren line xs in
          (x::l1, l2)
        else ([], x::xs)
      )

(* old        
let rec mk_line_parenthised xs = 
  match xs with
  | [] -> []
  | x::xs -> 
      let line_no = line_of_paren x in
      let line, xs = span_line_paren line_no xs in
      Line (x::line)::mk_line_parenthised xs
*)





(* --------------------------------------- *)

let line_range_of_paren = function
  | PToken x -> x.line, x.line
  | Parenthised (xxs, info_parens) -> 
      (match info_parens with
      | [] -> raise Impossible
      | x::xs -> 
          let lines_no = (x::xs) +> List.map (fun x -> x.line) in
          Common.minimum lines_no, Common.maximum lines_no
      )

let rec span_line_paren_range (imin, imax) = function
  | [] -> [],[]
  | x::xs -> 
      (match x with
      | PToken tok when TH.is_eof tok.tok -> 
          [], x::xs
      | _ -> 
        if line_of_paren x >= imin && line_of_paren x <= imax
        then
          (* may need to extend *)
          let (imin', imax') = line_range_of_paren x in
          let (l1, l2) = span_line_paren_range (imin, max imax imax') xs in
          (x::l1, l2)
        else ([], x::xs)
      )


let rec mk_line_parenthised xs = 
  match xs with
  | [] -> []
  | x::xs -> 
      let line_range = line_range_of_paren x in
      let line, xs = span_line_paren_range line_range xs in
      Line (x::line)::mk_line_parenthised xs





(* --------------------------------------- *)
let rec mk_body_function_grouped xs = 
  match xs with 
  | [] -> []
  | x::xs -> 
      (match x with
      | {tok = TOBrace _; col = 0} -> 
          let is_closing_brace = function 
            | {tok = TCBrace _; col = 0 } -> true 
            | _ -> false 
          in
          let body, xs = Common.span (fun x -> not (is_closing_brace x)) xs in
          (match xs with
          | ({tok = TCBrace _; col = 0 })::xs -> 
              BodyFunction body::mk_body_function_grouped xs
          | [] -> 
              pr2 "PB:not found closing brace in fuzzy parsing";
              [NotBodyLine body]
          | _ -> raise Impossible
          )
          
      | _ -> 
          let line, xs = Common.span (fun y -> y.line = x.line) (x::xs) in
          NotBodyLine line::mk_body_function_grouped xs 
      )

(* --------------------------------------- *)
let is_braceised = function
  | Braceised   _ -> true
  | BToken _ -> false


(* ------------------------------------------------------------------------- *)
(* view iterators  *)
(* ------------------------------------------------------------------------- *)

let rec iter_token_paren f xs = 
  xs +> List.iter (function
  | PToken tok -> f tok;
  | Parenthised (xxs, info_parens) -> 
      info_parens +> List.iter f;
      xxs +> List.iter (fun xs -> iter_token_paren f xs)
  )

let rec iter_token_brace f xs = 
  xs +> List.iter (function
  | BToken tok -> f tok;
  | Braceised (xxs, tok1, tok2opt) -> 
      f tok1; do_option f tok2opt;
      xxs +> List.iter (fun xs -> iter_token_brace f xs)
  )

let rec iter_token_ifdef f xs = 
  xs +> List.iter (function
  | NotIfdefLine xs -> xs +> List.iter f;
  | Ifdefbool (_, xxs, info_ifdef) 
  | Ifdef (xxs, info_ifdef) -> 
      info_ifdef +> List.iter f;
      xxs +> List.iter (iter_token_ifdef f)
  )




let tokens_of_paren xs = 
  let g = ref [] in
  xs +> iter_token_paren (fun tok -> push2 tok g);
  List.rev !g


let tokens_of_paren_ordered xs = 
  let g = ref [] in

  let rec aux_tokens_ordered = function
    | PToken tok -> push2 tok g;
    | Parenthised (xxs, info_parens) -> 
        let (opar, cpar, commas) = 
          match info_parens with
          | opar::xs -> 
              (match List.rev xs with
              | cpar::xs -> 
                  opar, cpar, List.rev xs
              | _ -> raise Impossible
              )
          | _ -> raise Impossible
        in
        push2 opar g;
        aux_args (xxs,commas);
        push2 cpar g;

  and aux_args (xxs, commas) =
    match xxs, commas with
    | [], [] -> ()
    | [xs], [] -> xs +> List.iter aux_tokens_ordered
    | xs::ys::xxs, comma::commas -> 
        xs +> List.iter aux_tokens_ordered;
        push2 comma g;
        aux_args (ys::xxs, commas)
    | _ -> raise Impossible

  in

  xs +> List.iter aux_tokens_ordered;
  List.rev !g



(* ------------------------------------------------------------------------- *)
(* set the context info in token *)
(* ------------------------------------------------------------------------- *)
(* All important context are introduced via some '{' '}'. To make the 
 * difference is it often enough to just look at the few tokens before the
 * '{'.
 * 
 * TODO harder now that have c++, can have function inside struct so need
 * handle all together. 
 * 
 * TODO So change token but do not recurse in
 * nested Braceised. maybe do via accumulator, don't use iter_token_brace.
 * 
 * TODO Also need remove the qualifier as they make
 * the sequence pattern matching more difficult.
 *)

let rec set_in_function_tag xs = 
 (* could try: ) { } but it can be the ) of a if or while, so 
  * better to base the heuristic on the position in column zero.
  * Note that some struct or enum or init put also their { in first column
  * but set_in_other will overwrite the previous InFunction tag.
  *)
 let rec aux xs = 
  match xs with
  | [] -> ()
(*TODOC++ext: now can have some const or throw between 
  => do a view that filter them first ?
*)

  (* ) { and the closing } is in column zero, then certainly a function *)
(*TODO1 col 0 not valid anymore with c++ nestedness of method *)
  | BToken ({tok = TCPar _ })::(Braceised (body, tok1, Some tok2))::xs 
      when tok1.col <> 0 && tok2.col = 0 -> 
      body +> List.iter (iter_token_brace (fun tok -> 
        tok.where <- InFunction
      ));
      aux xs

  | (BToken x)::xs -> aux xs

(*TODO1 not valid anymore with c++ nestedness of method *)
  | (Braceised (body, tok1, Some tok2))::xs 
      when tok1.col = 0 && tok2.col = 0 -> 
      body +> List.iter (iter_token_brace (fun tok -> 
        tok.where <- InFunction
      ));
      aux xs
  | Braceised (body, tok1, tok2)::xs -> 
      aux xs
 in
 aux xs



  

let rec set_in_other xs = 
  match xs with 
  | [] -> ()
  (* enum x { } *)
  | BToken ({tok = Tenum _})::BToken ({tok = TIdent _})
    ::Braceised(body, tok1, tok2)::xs 
  | BToken ({tok = Tenum _})
    ::Braceised(body, tok1, tok2)::xs 
    -> 
      body +> List.iter (iter_token_brace (fun tok -> 
        tok.where <- InEnum;
      ));
      set_in_other xs
  (* struct/union/class x { } *)
  | BToken ({tok = tokstruct})::BToken ({tok = TIdent _})
    ::Braceised(body, tok1, tok2)::xs when TH.is_classkey_keyword tokstruct -> 
      body +> List.iter (iter_token_brace (fun tok -> 
        tok.where <- InStruct;
      ));
      set_in_other xs

  (* struct/union/class x : ... { } *)
  | BToken ({tok = tokstruct})::BToken ({tok = TIdent _})
    ::BToken ({tok = TCol _})::xs when TH.is_classkey_keyword tokstruct -> 
      
      let (before, elem, after) = Common.split_when is_braceised xs in
      (match elem with 
      | Braceised(body, tok1, tok2) -> 
          body +> List.iter (iter_token_brace (fun tok -> 
            tok.where <- InInitializer;
          ));
          set_in_other after
      | _ -> raise Impossible
      )
          

  (* = { } *)
  | BToken ({tok = TEq _})
    ::Braceised(body, tok1, tok2)::xs -> 
      body +> List.iter (iter_token_brace (fun tok -> 
        tok.where <- InInitializer;
      ));
      set_in_other xs


  (* recurse *)
  | BToken _::xs -> set_in_other xs
  | Braceised(body, tok1, tok2)::xs -> 
      body +> List.iter set_in_other;
      set_in_other xs

      
      

let set_context_tag xs = 
  begin
    (* order is important *)
    set_in_function_tag xs;
    set_in_other xs;
  end
  




(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

(* Thanks to this function many stuff are not anymore hardcoded in ocaml code
 * (but they are now hardcoded in standard.h ...)
 *)
let rec (cpp_engine: (string , Parser_c.token list) assoc -> 
          Parser_c.token list -> Parser_c.token list) = fun env xs ->
  xs +> List.map (fun tok -> 
    match tok with
    | TIdent (s,i1) when List.mem_assoc s env -> Common.assoc s env
    | x -> [x]
  )
  +> List.flatten
  

(* ------------------------------------------------------------------------- *)
(* the pair is the status of '()' and '{}', ex: (-1,0) 
 * if too much ')' and good '{}' 
 * could do for [] too ? 
 * could do for ','   if encounter ',' at "toplevel", not inside () or {}
 * then if have ifdef, then certainly can lead to a problem.
 *)
let (count_open_close_stuff_ifdef_clause: ifdef_grouped list -> (int * int)) = 
 fun xs -> 
   let cnt_paren, cnt_brace = ref 0, ref 0 in
   xs +> iter_token_ifdef (fun x -> 
     (match x.tok with
     | x when TH.is_opar x  -> incr cnt_paren
     | x when TH.is_obrace x -> incr cnt_brace
     | x when TH.is_cpar x  -> decr cnt_paren
     | x when TH.is_obrace x -> decr cnt_brace
     | _ -> ()
     )
   );
   !cnt_paren, !cnt_brace



(* ------------------------------------------------------------------------- *)

(* c++ext: *)
let templateLOOKAHEAD = 30
  
(* note: no need to check for TCPar to stop for instance the search, 
 * this is will be done automatically because we would be inside a 
 * Parenthised expression.
 *)
let rec have_a_tsup_quite_close xs =
  match xs with
  | [] -> false
  | (PToken x)::xs -> 
      (match x with
      | {tok = TSup i} -> true

      (* false positive *)
      | {tok = tok} when TH.is_static_cast_like tok -> false

      (* bugfix: but want allow some binary operator :) like '*' *)
      | {tok = tok} when TH.is_binary_operator_except_star tok -> false
      

      | x -> have_a_tsup_quite_close xs
      )
  | (Parenthised (xxs, info_parens))::xs -> 
      have_a_tsup_quite_close xs




(* precondition: there is a tsup *)
let rec find_tsup_quite_close xs = 
  let rec aux acc xs =
    match xs with
    | [] -> failwith "find_tsup_quite_close, no tsup"
    | (PToken x)::xs -> 
        (match x with
        | {tok = TSup ii} -> 
            acc, (x,ii), xs
              
        | {tok = TInf ii} -> 
            (* recurse *)
            let (before, (tsuptok,_), after) = 
              find_tsup_quite_close xs in
            (* we don't care about this one, it will be eventually be 
             * transformed by the caller *)
            aux ((PToken x)::(before++[PToken tsuptok])) xs
              
              
        | x -> aux ((PToken x)::acc) xs
        )
    | (Parenthised (xxs, info_parens))::xs -> 
        aux ((Parenthised (xxs, info_parens))::acc) xs
  in
  let (before, tsup, after) = aux [] xs in
  List.rev before, tsup, after

(* ------------------------------------------------------------------------- *)

(* cppext: *)

let forLOOKAHEAD = 30
  
(* look if there is a '{' just after the closing ')', and handling the
 * possibility to have nested expressions inside nested parenthesis 
 *)
let rec is_really_foreach xs = 
  let rec is_foreach_aux = function
    | [] -> false, []
    | TCPar _::TOBrace _::xs -> true, xs
      (* the following attempts to handle the cases where there is a
	 single statement in the body of the loop.  undoubtedly more
	 cases are needed. 
         todo: premier(statement) - suivant(funcall)
      *)
    | TCPar _::TIdent _::xs -> true, xs
    | TCPar _::Tif _::xs -> true, xs
    | TCPar _::Twhile _::xs -> true, xs
    | TCPar _::Tfor _::xs -> true, xs
    | TCPar _::Tswitch _::xs -> true, xs

    | TCPar _::xs -> false, xs
    | TOPar _::xs -> 
        let (_, xs') = is_foreach_aux xs in
        is_foreach_aux xs'
    | x::xs -> is_foreach_aux xs
  in
  is_foreach_aux xs +> fst


(*****************************************************************************)
(* CPP handling: macros, ifdefs, macros defs  *)
(*****************************************************************************)

(* ------------------------------------------------------------------------- *)
(* ifdef keeping/passing *)
(* ------------------------------------------------------------------------- *)

(* #if 0, #if 1,  #if LINUX_VERSION handling *)
let rec find_ifdef_bool xs = 
  xs +> List.iter (function 
  | NotIfdefLine _ -> ()
  | Ifdefbool (is_ifdef_positif, xxs, info_ifdef_stmt) -> 
      
      if is_ifdef_positif
      then pr2_cpp "commenting parts of a #if 1 or #if LINUX_VERSION"
      else pr2_cpp "commenting a #if 0 or #if LINUX_VERSION or __cplusplus";

      (match xxs with
      | [] -> raise Impossible
      | firstclause::xxs -> 
          info_ifdef_stmt +> List.iter (set_as_comment Ast_c.CppDirective);
            
          if is_ifdef_positif
          then xxs +> List.iter 
            (iter_token_ifdef (set_as_comment Ast_c.CppOther))
          else begin
            firstclause +> iter_token_ifdef (set_as_comment Ast_c.CppOther);
            (match List.rev xxs with
            (* keep only last *)
            | last::startxs -> 
                startxs +> List.iter 
                  (iter_token_ifdef (set_as_comment Ast_c.CppOther))
            | [] -> (* not #else *) ()
            );
          end
      );
      
  | Ifdef (xxs, info_ifdef_stmt) -> xxs +> List.iter find_ifdef_bool
  )



let thresholdIfdefSizeMid = 6

(* infer ifdef involving not-closed expressions/statements *)
let rec find_ifdef_mid xs = 
  xs +> List.iter (function 
  | NotIfdefLine _ -> ()
  | Ifdef (xxs, info_ifdef_stmt) -> 
      (match xxs with 
      | [] -> raise Impossible
      | [first] -> ()
      | first::second::rest -> 
          (* don't analyse big ifdef *)
          if xxs +> List.for_all 
            (fun xs -> List.length xs <= thresholdIfdefSizeMid) && 
            (* don't want nested ifdef *)
            xxs +> List.for_all (fun xs -> 
              xs +> List.for_all 
                (function NotIfdefLine _ -> true | _ -> false)
            )
            
          then 
            let counts = xxs +> List.map count_open_close_stuff_ifdef_clause in
            let cnt1, cnt2 = List.hd counts in 
            if cnt1 <> 0 || cnt2 <> 0 && 
               counts +> List.for_all (fun x -> x = (cnt1, cnt2))
              (*
                if counts +> List.exists (fun (cnt1, cnt2) -> 
                cnt1 <> 0 || cnt2 <> 0 
                ) 
              *)
            then begin
              pr2_cpp "found ifdef-mid-something";
              (* keep only first, treat the rest as comment *)
              info_ifdef_stmt +> List.iter (set_as_comment Ast_c.CppDirective);
              (second::rest) +> List.iter 
                (iter_token_ifdef (set_as_comment Ast_c.CppOther));
            end
              
      );
      List.iter find_ifdef_mid xxs
        
  (* no need complex analysis for ifdefbool *)
  | Ifdefbool (_, xxs, info_ifdef_stmt) -> 
      List.iter find_ifdef_mid xxs
          
        
  )


let thresholdFunheaderLimit = 4

(* ifdef defining alternate function header, type *)
let rec find_ifdef_funheaders = function
  | [] -> ()
  | NotIfdefLine _::xs -> find_ifdef_funheaders xs 

  (* ifdef-funheader if ifdef with 2 lines and a '{' in next line *)
  | Ifdef 
      ([(NotIfdefLine (({col = 0} as _xline1)::line1))::ifdefblock1;
        (NotIfdefLine (({col = 0} as xline2)::line2))::ifdefblock2
      ], info_ifdef_stmt 
      )
    ::NotIfdefLine (({tok = TOBrace i; col = 0})::line3)
    ::xs  
   when List.length ifdefblock1 <= thresholdFunheaderLimit &&
        List.length ifdefblock2 <= thresholdFunheaderLimit
    -> 
      find_ifdef_funheaders xs;
      info_ifdef_stmt +> List.iter (set_as_comment Ast_c.CppDirective);
      let all_toks = [xline2] @ line2 in
      all_toks +> List.iter (set_as_comment Ast_c.CppOther) ;
      ifdefblock2 +> iter_token_ifdef (set_as_comment Ast_c.CppOther);

  (* ifdef with nested ifdef *)
  | Ifdef 
      ([[NotIfdefLine (({col = 0} as _xline1)::line1)];
        [Ifdef 
            ([[NotIfdefLine (({col = 0} as xline2)::line2)];
              [NotIfdefLine (({col = 0} as xline3)::line3)];
            ], info_ifdef_stmt2
            )
        ]
      ], info_ifdef_stmt 
      )
    ::NotIfdefLine (({tok = TOBrace i; col = 0})::line4)
    ::xs  
    -> 
      find_ifdef_funheaders xs;
      info_ifdef_stmt  +> List.iter (set_as_comment Ast_c.CppDirective);
      info_ifdef_stmt2 +> List.iter (set_as_comment Ast_c.CppDirective);
      let all_toks = [xline2;xline3] @ line2 @ line3 in
      all_toks +> List.iter (set_as_comment Ast_c.CppOther);

 (* ifdef with elseif *)
  | Ifdef 
      ([[NotIfdefLine (({col = 0} as _xline1)::line1)];
        [NotIfdefLine (({col = 0} as xline2)::line2)];
        [NotIfdefLine (({col = 0} as xline3)::line3)];
      ], info_ifdef_stmt 
      )
    ::NotIfdefLine (({tok = TOBrace i; col = 0})::line4)
    ::xs 
    -> 
      find_ifdef_funheaders xs;
      info_ifdef_stmt +> List.iter (set_as_comment Ast_c.CppDirective);
      let all_toks = [xline2;xline3] @ line2 @ line3 in
      all_toks +> List.iter (set_as_comment Ast_c.CppOther)
        

  | Ifdef (xxs,info_ifdef_stmt)::xs 
  | Ifdefbool (_, xxs,info_ifdef_stmt)::xs -> 
      List.iter find_ifdef_funheaders xxs; 
      find_ifdef_funheaders xs
        



let rec adjust_inifdef_include xs = 
  xs +> List.iter (function 
  | NotIfdefLine _ -> ()
  | Ifdef (xxs, info_ifdef_stmt) | Ifdefbool (_, xxs, info_ifdef_stmt) -> 
      xxs +> List.iter (iter_token_ifdef (fun tokext -> 
        match tokext.tok with
        | Parser_c.TInclude (s1, s2, inifdef_ref, ii) -> 
            inifdef_ref := true;
        | _ -> ()
      ));
  )



(* ------------------------------------------------------------------------- *)
(* cpp-builtin part1, macro, using standard.h or other defs *)
(* ------------------------------------------------------------------------- *)

(* no need to take care to not substitute the macro name itself
 * that occurs in the macro definition because the macro name is
 * after fix_token_define a TDefineIdent, no more a TIdent.
 *)
let rec apply_macro_defs xs = 
  match xs with
  | [] -> ()

  (* recognized macro of standard.h (or other) *)
  | PToken ({tok = TIdent (s,i1)} as id)::Parenthised (xxs,info_parens)::xs 
      when Hashtbl.mem !_defs s -> 
      pr2_cpp ("MACRO: found known macro = " ^ s);
      (match Hashtbl.find !_defs s with
      | Left (), bodymacro -> 
          pr2 ("macro without param used before parenthize, wierd: " ^ s);
          (* ex: PRINTP("NCR53C400 card%s detected\n" ANDP(((struct ... *)
          set_as_comment (Ast_c.CppMacro) id;
          id.new_tokens_before <- bodymacro;
      | Right params, bodymacro -> 
          if List.length params = List.length xxs
          then
            let xxs' = xxs +> List.map (fun x -> 
              (tokens_of_paren_ordered x) +> List.map (fun x -> 
                TH.visitor_info_of_tok Ast_c.make_expanded x.tok
              )
            ) in
            id.new_tokens_before <-
              cpp_engine (Common.zip params xxs') bodymacro

          else begin
            pr2 ("macro with wrong number of arguments, wierd: " ^ s);
            id.new_tokens_before <- bodymacro;
          end;
          (* important to do that after have apply the macro, otherwise
           * will pass as argument to the macro some tokens that
           * are all TCommentCpp
           *)
          [Parenthised (xxs, info_parens)] +> 
            iter_token_paren (set_as_comment Ast_c.CppMacro);
          set_as_comment Ast_c.CppMacro id;

           

      );
      apply_macro_defs xs

  | PToken ({tok = TIdent (s,i1)} as id)::xs 
      when Hashtbl.mem !_defs s -> 
      pr2_cpp ("MACRO: found known macro = " ^ s);
      (match Hashtbl.find !_defs s with
      | Right params, bodymacro -> 
          pr2 ("macro with params but no parens found, wierd: " ^ s);
          (* dont apply the macro, perhaps a redefinition *)
          ()
      | Left (), bodymacro -> 
          (* special case when 1-1 substitution, we reuse the token *)
          (match bodymacro with
          | [newtok] -> 
              id.tok <- (newtok +> TH.visitor_info_of_tok (fun _ -> 
                TH.info_of_tok id.tok))

          | _ -> 
              set_as_comment Ast_c.CppMacro id;
              id.new_tokens_before <- bodymacro;
          )
      );
      apply_macro_defs xs




  (* recurse *)
  | (PToken x)::xs -> apply_macro_defs xs 
  | (Parenthised (xxs, info_parens))::xs -> 
      xxs +> List.iter apply_macro_defs;
      apply_macro_defs xs





(* ------------------------------------------------------------------------- *)
(* stringification *)
(* ------------------------------------------------------------------------- *)

let rec find_string_macro_paren xs = 
  match xs with
  | [] -> ()
  | Parenthised(xxs, info_parens)::xs -> 
      xxs +> List.iter (fun xs -> 
        if xs +> List.exists 
          (function PToken({tok = TString _}) -> true | _ -> false) &&
          xs +> List.for_all 
          (function PToken({tok = TString _}) | PToken({tok = TIdent _}) -> 
            true | _ -> false)
        then
          xs +> List.iter (fun tok -> 
            match tok with
            | PToken({tok = TIdent (s,_)} as id) -> 
                msg_stringification s;
                id.tok <- TMacroString (TH.info_of_tok id.tok);
            | _ -> ()
          )
        else 
          find_string_macro_paren xs
      );
      find_string_macro_paren xs
  | PToken(tok)::xs -> 
      find_string_macro_paren xs
      

(* ------------------------------------------------------------------------- *)
(* macro2 *)
(* ------------------------------------------------------------------------- *)

(* don't forget to recurse in each case.
 * note that the code below is called after the ifdef phase simplification, 
 * so if this previous phase is buggy, then it may pass some code that
 * could be matched by the following rules but will not. 
 **)
let rec find_macro_paren xs = 
  match xs with
  | [] -> ()
      
  (* attribute *)
  | PToken ({tok = Tattribute _} as id)
    ::Parenthised (xxs,info_parens)
    ::xs
     -> 
      pr2_cpp ("MACRO: __attribute detected ");
      [Parenthised (xxs, info_parens)] +> 
        iter_token_paren (set_as_comment Ast_c.CppAttr);
      set_as_comment Ast_c.CppAttr id;
      find_macro_paren xs

  (* stringification
   * 
   * the order of the matching clause is important
   * 
   *)

  (* string macro with params, before case *)
  | PToken ({tok = TString _})::PToken ({tok = TIdent (s,_)} as id)
    ::Parenthised (xxs, info_parens)
    ::xs -> 
      pr2_cpp ("MACRO: string-macro with params : " ^ s);
      id.tok <- TMacroString (TH.info_of_tok id.tok);
      [Parenthised (xxs, info_parens)] +> 
        iter_token_paren (set_as_comment Ast_c.CppMacro);
      find_macro_paren xs

  (* after case *)
  | PToken ({tok = TIdent (s,_)} as id)
    ::Parenthised (xxs, info_parens)
    ::PToken ({tok = TString _})
    ::xs -> 
      pr2_cpp ("MACRO: string-macro with params : " ^ s);
      id.tok <- TMacroString (TH.info_of_tok id.tok);
      [Parenthised (xxs, info_parens)] +> 
        iter_token_paren (set_as_comment Ast_c.CppMacro);
      find_macro_paren xs


  (* for the case where the string is not inside a funcall, but
   * for instance in an initializer.
   *)
        
  (* string macro variable, before case *)
  | PToken ({tok = TString ((str,_),_)})::PToken ({tok = TIdent (s,_)} as id)
      ::xs -> 

      (* c++ext: *)
      if str <> "C" then begin

      msg_stringification s;
      id.tok <- TMacroString (TH.info_of_tok id.tok);
      find_macro_paren xs
      end
      (* bugfix, forgot to recurse in else case too ... *)
      else 
        find_macro_paren xs

  (* after case *)
  | PToken ({tok = TIdent (s,_)} as id)::PToken ({tok = TString _})
      ::xs -> 
      msg_stringification s;
      id.tok <- TMacroString (TH.info_of_tok id.tok);
      find_macro_paren xs



  (* cooperating with standard.h *)
  | PToken ({tok = TIdent (s,i1)} as id)::xs 
      when s = "MACROSTATEMENT" -> 
      id.tok <- TMacroStmt(TH.info_of_tok id.tok);
      find_macro_paren xs
        


  (* recurse *)
  | (PToken x)::xs -> find_macro_paren xs 
  | (Parenthised (xxs, info_parens))::xs -> 
      xxs +> List.iter find_macro_paren;
      find_macro_paren xs





(* don't forget to recurse in each case *)
let rec find_macro_lineparen xs = 
  match xs with
  | [] -> ()

  (* firefoxext: ex: NS_DECL_NSIDOMNODELIST *)
  | (Line ([PToken ({tok = TIdent (s,_)} as macro);]))::xs 
      when s ==~ regexp_ns_decl_like -> 
      
      msg_declare_macro s;
      set_as_comment Ast_c.CppMacro macro;
      
      find_macro_lineparen (xs)

  (* firefoxext: ex: NS_DECL_NSIDOMNODELIST; *)
  | (Line ([PToken ({tok = TIdent (s,_)} as macro);
            PToken ({tok = TPtVirg _})]))::xs 
      when s ==~ regexp_ns_decl_like -> 
      
      msg_declare_macro s;
      set_as_comment Ast_c.CppMacro macro;
      
      find_macro_lineparen (xs)

  (* firefoxext: ex: NS_IMPL_XXX(a) *)
  | (Line ([PToken ({tok = TIdent (s,_)} as macro);
           Parenthised (xxs,info_parens);
          ]))
    ::xs 
      when s ==~ regexp_ns_decl_like -> 
     
      msg_declare_macro s;

      [Parenthised (xxs, info_parens)] +> 
        iter_token_paren (set_as_comment Ast_c.CppMacro);
      set_as_comment Ast_c.CppMacro macro;
      
      find_macro_lineparen (xs)


  (* linuxext: ex: static [const] DEVICE_ATTR(); *)
  | (Line 
        (
          [PToken ({tok = Tstatic _});
           PToken ({tok = TIdent (s,_)} as macro);
           Parenthised (xxs,info_parens);
           PToken ({tok = TPtVirg _});
          ] 
        ))
    ::xs 
    when (s ==~ regexp_macro) -> 
      msg_declare_macro s;
      let info = TH.info_of_tok macro.tok in
      macro.tok <- TMacroDecl (Ast_c.str_of_info info, info);

      find_macro_lineparen (xs)

  (* the static const case *)
  | (Line 
        (
          [PToken ({tok = Tstatic _});
           PToken ({tok = Tconst _} as const);
           PToken ({tok = TIdent (s,_)} as macro);
           Parenthised (xxs,info_parens);
           PToken ({tok = TPtVirg _});
          ] 
            (*as line1*)

        ))
    ::xs 
    when (s ==~ regexp_macro) -> 
      msg_declare_macro s;
      let info = TH.info_of_tok macro.tok in
      macro.tok <- TMacroDecl (Ast_c.str_of_info info, info);
      
      (* need retag this const, otherwise ambiguity in grammar 
         21: shift/reduce conflict (shift 121, reduce 137) on Tconst
  	 decl2 : Tstatic . TMacroDecl TOPar argument_list TCPar ...
	 decl2 : Tstatic . Tconst TMacroDecl TOPar argument_list TCPar ...
	 storage_class_spec : Tstatic .  (137)
      *)
      const.tok <- TMacroDeclConst (TH.info_of_tok const.tok);

      find_macro_lineparen (xs)


  (* same but without trailing ';'
   * 
   * I do not put the final ';' because it can be on a multiline and
   * because of the way mk_line is coded, we will not have access to
   * this ';' on the next line, even if next to the ')' *)
  | (Line 
        ([PToken ({tok = Tstatic _});
          PToken ({tok = TIdent (s,_)} as macro);
          Parenthised (xxs,info_parens);
        ] 
        ))
    ::xs 
    when s ==~ regexp_macro -> 

      msg_declare_macro s;
      let info = TH.info_of_tok macro.tok in
      macro.tok <- TMacroDecl (Ast_c.str_of_info info, info);

      find_macro_lineparen (xs)




  (* on multiple lines *)
  | (Line 
        (
          (PToken ({tok = Tstatic _})::[]
          )))
    ::(Line 
          (
            [PToken ({tok = TIdent (s,_)} as macro);
             Parenthised (xxs,info_parens);
             PToken ({tok = TPtVirg _});
            ]
          ) 
        )
    ::xs 
    when (s ==~ regexp_macro) -> 
      msg_declare_macro s;
      let info = TH.info_of_tok macro.tok in
      macro.tok <- TMacroDecl (Ast_c.str_of_info info, info);

      find_macro_lineparen (xs)


  (* linuxext: ex: DECLARE_BITMAP(); 
   * 
   * Here I use regexp_declare and not regexp_macro because
   * Sometimes it can be a FunCallMacro such as DEBUG(foo());
   * Here we don't have the preceding 'static' so only way to
   * not have positive is to restrict to .*DECLARE.* macros.
   *
   * but there is a grammar rule for that, so don't need this case anymore
   * unless the parameter of the DECLARE_xxx are wierd and can not be mapped
   * on a argument_list
   *)
        
  | (Line 
        ([PToken ({tok = TIdent (s,_)} as macro);
          Parenthised (xxs,info_parens);
          PToken ({tok = TPtVirg _});
        ]
        ))
    ::xs 
    when (s ==~ regexp_declare) -> 

      msg_declare_macro s;
      let info = TH.info_of_tok macro.tok in
      macro.tok <- TMacroDecl (Ast_c.str_of_info info, info);

      find_macro_lineparen (xs)

        
  (* toplevel macros.
   * module_init(xxx)
   * 
   * Could also transform the TIdent in a TMacroTop but can have false
   * positive, so easier to just change the TCPar and so just solve
   * the end-of-stream pb of ocamlyacc
   *)
  | (Line 
        ([PToken ({tok = TIdent (s,ii); col = col1; where = ctx} as _macro);
          Parenthised (xxs,info_parens);
        ] as _line1
        ))
    ::xs when col1 = 0
    -> 
      let condition = 
        (* to reduce number of false positive *)
        (match xs with
        | (Line (PToken ({col = col2 } as other)::restline2))::_ -> 
            TH.is_eof other.tok || (col2 = 0 &&
             (match other.tok with
             | TOBrace _ -> false (* otherwise would match funcdecl *)
             | TCBrace _ when ctx <> InFunction -> false
             | TPtVirg _ 
             | TCol _
               -> false
             | tok when TH.is_binary_operator tok -> false
                 
             | _ -> true
             )
            )
        | _ -> false
        )
      in
      if condition
      then begin
          msg_macro_toplevel_noptvirg s;
          (* just to avoid the end-of-stream pb of ocamlyacc  *)
          let tcpar = Common.last info_parens in
          tcpar.tok <- TCParEOL (TH.info_of_tok tcpar.tok);
          
          (*macro.tok <- TMacroTop (s, TH.info_of_tok macro.tok);*)
          
        end;

       find_macro_lineparen (xs)



  (* macro with parameters 
   * ex: DEBUG()
   *     return x;
   *)
  | (Line 
        ([PToken ({tok = TIdent (s,ii); col = col1; where = ctx} as macro);
          Parenthised (xxs,info_parens);
        ] as _line1
        ))
    ::(Line 
          (PToken ({col = col2 } as other)::restline2
          ) as line2)
    ::xs 
    (* when s ==~ regexp_macro *)
    -> 
      let condition = 
        (col1 = col2 && 
            (match other.tok with
            | TOBrace _ -> false (* otherwise would match funcdecl *)
            | TCBrace _ when ctx <> InFunction -> false
            | TPtVirg _ 
            | TCol _
                -> false
            | tok when TH.is_binary_operator tok -> false

            | _ -> true
            )
        ) 
        || 
        (col2 <= col1 &&
              (match other.tok with
              | TCBrace _ when ctx = InFunction -> true
              | Treturn _ -> true
              | Tif _ -> true
              | Telse _ -> true

              | _ -> false
              )
          )

      in
      
      if condition
      then 
        if col1 = 0 then ()
        else begin
          msg_macro_noptvirg s;
          macro.tok <- TMacroStmt (TH.info_of_tok macro.tok);
          [Parenthised (xxs, info_parens)] +> 
            iter_token_paren (set_as_comment Ast_c.CppMacro);
        end;

      find_macro_lineparen (line2::xs)
        
  (* linuxext:? single macro 
   * ex: LOCK
   *     foo();
   *     UNLOCK
   *)
  | (Line 
        ([PToken ({tok = TIdent (s,ii); col = col1; where = ctx} as macro);
        ] as _line1
        ))
    ::(Line 
          (PToken ({col = col2 } as other)::restline2
          ) as line2)
    ::xs -> 
    (* when s ==~ regexp_macro *)
      
      let condition = 
        (col1 = col2 && 
            col1 <> 0 && (* otherwise can match typedef of fundecl*)
            (match other.tok with
            | TPtVirg _ -> false 
            | TOr _ -> false 
            | TCBrace _ when ctx <> InFunction -> false
            | tok when TH.is_binary_operator tok -> false

            | _ -> true
            )) ||
          (col2 <= col1 &&
              (match other.tok with
              | TCBrace _ when ctx = InFunction -> true
              | Treturn _ -> true
              | Tif _ -> true
              | Telse _ -> true
              | _ -> false
              ))
      in
      
      if condition
      then begin
        msg_macro_noptvirg_single s;
        macro.tok <- TMacroStmt (TH.info_of_tok macro.tok);
      end;
      find_macro_lineparen (line2::xs)
        
  | x::xs -> 
      find_macro_lineparen xs


(* ------------------------------------------------------------------------- *)
(* define tobrace init *)
(* ------------------------------------------------------------------------- *)

let rec find_define_init_brace_paren xs = 
 let rec aux xs = 
  match xs with
  | [] -> ()

  (* mainly for firefox *)
  | (PToken {tok = TDefine _})
    ::(PToken {tok = TIdentDefine (s,_)})
    ::(PToken ({tok = TOBrace i1} as tokbrace))
    ::(PToken tok2)
    ::(PToken tok3)
    ::xs -> 
      let is_init =
        match tok2.tok, tok3.tok with
        | TInt _, TComma _ -> true
        | TString _, TComma _ -> true
        | TIdent _, TComma _ -> true
        | _ -> false
            
      in
      if is_init
      then begin 
        pr2_cpp("found define initializer: " ^s);
        tokbrace.tok <- TOBraceDefineInit i1;
      end;

      aux xs

  (* mainly for linux, especially in sound/ *)
  | (PToken {tok = TDefine _})
    ::(PToken {tok = TIdentDefine (s,_)})
    ::(Parenthised(xxx, info_parens))
    ::(PToken ({tok = TOBrace i1} as tokbrace))
    ::(PToken tok2)
    ::(PToken tok3)
    ::xs -> 
      let is_init =
        match tok2.tok, tok3.tok with
        | TInt _, TComma _ -> true
        | TDot _, TIdent _ -> true
        | TIdent _, TComma _ -> true
        | _ -> false
            
      in
      if is_init
      then begin 
        pr2_cpp("found define initializer with param: " ^ s);
        tokbrace.tok <- TOBraceDefineInit i1;
      end;

      aux xs

    

  (* recurse *)
  | (PToken x)::xs -> aux xs 
  | (Parenthised (xxs, info_parens))::xs -> 
      (* not need for tobrace init:
       *  xxs +> List.iter aux; 
       *)
      aux xs
 in
 aux xs



(* ------------------------------------------------------------------------- *)
(* action *)
(* ------------------------------------------------------------------------- *)

let rec find_actions = function
  | [] -> ()

  | PToken ({tok = TIdent (s,ii)})
    ::Parenthised (xxs,info_parens)
    ::xs -> 
      find_actions xs;
      xxs +> List.iter find_actions;
      let modified = find_actions_params xxs in
      if modified 
      then msg_macro_higher_order s
        
  | x::xs -> 
      find_actions xs

and find_actions_params xxs = 
  xxs +> List.fold_left (fun acc xs -> 
    let toks = tokens_of_paren xs in
    if toks +> List.exists (fun x -> TH.is_statement x.tok)
    then begin
      xs +> iter_token_paren (fun x -> 
        if TH.is_eof x.tok
        then 
          (* certainly because paren detection had a pb because of
           * some ifdef-exp
           *)
          pr2 "PB: wierd, I try to tag an EOF token as action"
        else 
          x.tok <- TAction (TH.info_of_tok x.tok);
      );
      true (* modified *)
    end
    else acc
  ) false



(* ------------------------------------------------------------------------- *)
(* c++ext: *)
(* ------------------------------------------------------------------------- *)

let find_cplusplus_view_all_tokens xs = 
 let rec aux xs =

  match xs with
  | [] -> ()
  | x::xs -> aux xs
 in
 aux xs



(* ------------------------------------------------------------------------- *)

let find_cplusplus_view_filtered_tokens xs = 
 let rec aux xs =

  match xs with
  | [] -> ()

  (* classname *)
  | ({tok = TIdent(s,i1)} as tok1)
    ::{tok = TColCol _}
    ::({tok = TIdent(s2,i2)} as tok2)
    ::xs -> 
      msg_classname s;
      tok1.tok <- Tclassname(s,i1);

      if s = s2 
      then begin
        msg_constructorname s2;
        tok2.tok <- Tconstructorname (s2, i2);
      end;

      aux (tok2::xs)

  | ({tok = TIdent(s,i1)} as tok1)
    ::{tok = TColCol _}
    ::({tok = Toperator(i2)} as tok2)
    ::xs -> 
      msg_classname s;
      tok1.tok <- Tclassname(s,i1);

      aux (tok2::xs)

   (* destructor special case *)
  | ({tok = TIdent(s,i1)} as tok1)
    ::{tok = TColCol _}
    ::{tok = TTilde _}
    ::({tok = TIdent(s2,i2)} as _tok2)
    ::xs -> 

      msg_classname s;
      tok1.tok <- Tclassname(s,i1);

      aux xs

  (* operator special case to avoid ambiguity when have 
   * x.operator new[3], which apparently is possible with 
   * the grammar, so to know diff between new[] operator and 
   * new [3] array access need see 2 tokens ahead, so again,
   * introduce an extra token to help.
   *)
  | ({tok = Tnew i1} | {tok = Tdelete i1})
      ::({tok = TOCro i2} as tok2)
      ::({tok = TCCro i3} as tok3)
      ::xs -> 
      
      tok2.tok <- TOCro2 i2;
      tok3.tok <- TCCro2 i3;

      aux xs


  (* recurse *)
  | x::xs -> aux xs
 in
 aux xs


(* assume have done TInf -> TInf2, Tclassname, Ttemplatename *)
(* pass 2 *)
let find_cplusplus_view_filtered_tokens_bis xs = 
 let rec aux xs =
  match xs with
  | [] -> ()

  (* xx::yy<zz> ww *)
  | ({tok = Tclassname (s1,i1)} as tok1)
    ::({tok = TColCol i2} as tok2)
    ::({tok = (*TypedefIdent*) _})
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TSup2 _})
    ::(({tok = TIdent (s2,_)})| ({tok = Tclassname (s2,_)}))
    ::xs

  (* xx::yy<zz>& ww *)
  | ({tok = Tclassname (s1,i1)} as tok1)
    ::({tok = TColCol i2} as tok2)
    ::({tok = (*TypedefIdent*) _})
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TSup2 _})
    ::({tok = TAnd _})
    ::(({tok = TIdent (s2,_)})| ({tok = Tclassname (s2,_)}))
    ::xs

  (* xx::yy<zz*> ww *)
  | ({tok = Tclassname (s1,i1)} as tok1)
    ::({tok = TColCol i2} as tok2)
    ::({tok = (*TypedefIdent*) _})
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TMul _})
    ::({tok = TSup2 _})
    ::(({tok = TIdent (s2,_)})| ({tok = Tclassname (s2,_)}))
    ::xs
  (* xx::yy<zz*>& ww *)
  | ({tok = Tclassname (s1,i1)} as tok1)
    ::({tok = TColCol i2} as tok2)
    ::({tok = (*TypedefIdent*) _})
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TMul _})
    ::({tok = TSup2 _})
    ::({tok = TAnd _})
    ::(({tok = TIdent (s2,_)})| ({tok = Tclassname (s2,_)}))
    ::xs

    -> 
      pr2 "RECLASSIF class and col to class2 col2";
      tok1.tok <- Tclassname2 (s1, i1);
      tok2.tok <- TColCol2 i2;
      
      aux xs


  (* xx<zz>::yy ww *)
  | ({tok = Ttemplatename (s1,i1)} as tok1)
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TSup2 _})
    ::({tok = TColCol i2} as tok2)
    ::({tok = TIdent (s2,_)})
    ::xs

  (* xx<zz,zzz>::yy ww *)
  | ({tok = Ttemplatename (s1,i1)} as tok1)
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TSup2 _})
    ::({tok = TColCol i2} as tok2)
    ::({tok = TIdent (s2,_)})
    ::xs

  (* xx<zz*>::yy ww *)
  | ({tok = Ttemplatename (s1,i1)} as tok1)
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*)_})
    ::({tok = TMul _})
    ::({tok = TSup2 _})
    ::({tok = TColCol i2} as tok2)
    ::({tok = TIdent (s2,_)})
    ::xs

    -> 
      pr2 "RECLASSIF2 template and col to templateQ2 col2";
      tok1.tok <- TtemplatenameQ2 (s1, i1);
      tok2.tok <- TColCol2 i2;
      
      aux xs


  (* aa::xx<zz>::yy ww *)
  | ({tok = Tclassname (s1,i1)} as tok1)
    ::({tok = TColCol i2} as tok2)
    ::({tok = Ttemplatename (s3,i3)} as tok3)
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TSup2 _})
    ::({tok = TColCol i4} as tok4)
    ::({tok = TIdent (s2,_)})
    ::xs 
  | ({tok = Tclassname (s1,i1)} as tok1)
    ::({tok = TColCol i2} as tok2)
    ::({tok = Ttemplatename (s3,i3)} as tok3)
    ::({tok = TInf2 _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = (*TIdent (s,_)*) _})
    ::({tok = TSup2 _})
    ::({tok = TColCol i4} as tok4)
    ::({tok = TIdent (s2,_)})
    ::xs 
    -> 
      pr2 "RECLASSIF3 classname template and col to templateQ2 col2";
      tok1.tok <- Tclassname2 (s1, i1);
      tok2.tok <- TColCol2 i2;
      tok3.tok <- TtemplatenameQ2 (s3, i3);
      tok4.tok <- TColCol2 i4;
      
      aux xs




  (* recurse *)
  | x::xs -> aux xs
 in
 aux xs




let find_cplusplus_view_parenthized xs = 
 let rec aux xs =
  match xs with
  | [] -> ()
      
  (* static_cast *)
  | (PToken {tok = tok1})::(PToken ({tok = TInf i2} as tok2))::xs 
      when TH.is_static_cast_like tok1
    -> 
      tok2.tok <- TInf2 i2;

      let (before_inf, (toksup, toksupi), rest) = 
        find_tsup_quite_close xs in
      toksup.tok <- TSup2 toksupi;
      
      (* recurse *)
      aux before_inf;
      aux rest

  (* templatename *)

  (* note: some macros in standard.h may expand to static_cast, so perhaps
   * better to do template detection after macro expansion ?
   *)
 
  (* Template, maybe. Rely on fact that even if C++ allow expression like
   * a<b>c, parsed as (a < b) > c, most people don't use that, so we
   * can use this fact for our heuristic. Also people usually don't
   * nest < for expressions as in a < b < c.
   *)
  | (PToken ({tok = TIdent(s,i1)} as tok1))
    ::(PToken ({tok = TInf i2} as tok2))::xs 
    when have_a_tsup_quite_close (Common.take_safe templateLOOKAHEAD xs)
    -> 
      msg_templatename s;
      tok1.tok <- Ttemplatename(s,i1);

      tok2.tok <- TInf2 i2;
      
      let (before_inf, (toksup, toksupi), rest) = find_tsup_quite_close xs in
      toksup.tok <- TSup2 toksupi;
      
      (* recurse *)
      aux before_inf;
      aux rest

  | (PToken ({tok = Ttemplate(i1)}))
    ::(PToken ({tok = TInf i2} as tok2))::xs 
    when have_a_tsup_quite_close (Common.take_safe templateLOOKAHEAD xs)
    -> 
      tok2.tok <- TInf2 i2;
      
      let (before_inf, (toksup, toksupi), rest) = find_tsup_quite_close xs in
      toksup.tok <- TSup2 toksupi;
      
      (* recurse *)
      aux before_inf;
      aux rest

        
  (* new (...) type(arg) *)
  | (PToken ({tok = Tnew(i1)}))
    ::Parenthised _
    ::PToken ({tok = TIdent(s,i2)} as tok1)
    ::Parenthised _
    ::xs 
    -> 
      pr2 "new placement and later typedef";
      tok1.tok <- TypedefIdent(s,i2);
      aux xs


  (* recurse *)
  | (PToken x)::xs -> aux xs 
  | (Parenthised (xxs, info_parens))::xs -> 
      xxs +> List.iter aux;
      aux xs
 in
 aux xs





(* ------------------------------------------------------------------------- *)

let find_cplusplus_view_parenthized2 xs = 
 let rec aux xs =
  match xs with
  | [] -> ()

  (* recurse *)
  | (PToken x)::xs -> aux xs 
  | (Parenthised (xxs, info_parens))::xs -> 
      xxs +> List.iter aux;
      aux xs
 in
 aux xs
      

(* ------------------------------------------------------------------------- *)
(* pre: have done the templatenameize and TInf/TSup -> TInf2/TSup2 *)
let rec find_cplusplus_view_line_paren xs = 

 let rec aux xs =
  match xs with 
  | [] -> ()

  (* c++ext: constructed objects part1 *)

  (* xx yy(...);    when in body of function/method, otherwise can
   * perfectly be a declaration of a prototype or of a method.
   *)
  | (Line 
        [PToken ({tok = TIdent (s1,i1)} as tok);
         PToken ({tok = TIdent (s,_); where = ctx} as _constructor);
         Parenthised (xxs,info_parens);
         PToken ({tok = TPtVirg _});
        ]
    )
    ::xs 
    when ctx = InFunction
      -> 
      ignore(info_parens);
      (* todo? check that in info_parens have what looks like expressions *)

      msg_typedef (s1,i1);
      tok.tok <- TypedefIdent (s1,i1);

      set_as_opar_cplusplus info_parens;

      aux xs




  (* xx<zz> yy(...); when in function *)
  | (Line 
        [PToken ({tok = Ttemplatename (s1,i1)} as _tok);
         PToken ({tok = TInf2 _});
         PToken ({tok = (*TypedefIdent*) _ident});
         PToken ({tok = TSup2 _});
         PToken ({tok = TIdent (s,_); where = ctx} as _constructor);
         Parenthised (xxs,info_parens);
         PToken ({tok = TPtVirg _});
        ]
    )
    ::xs 
    when ctx = InFunction
      -> 
      ignore(info_parens);
      (* todo? check that in info_parens have what looks like expressions *)

      set_as_opar_cplusplus info_parens;

      aux xs


  (* xx<zz> yy \n(...); when in function *)
  | (Line 
        [PToken ({tok = Ttemplatename (s1,i1)} as _tok);
         PToken ({tok = TInf2 _});
         PToken ({tok = (*TypedefIdent*) _});
         PToken ({tok = TSup2 _});
         PToken ({tok = TIdent (s,_); where = ctx} as _constructor);
        ]
    )
    ::(Line 
         [
         Parenthised (xxs,info_parens);
         PToken ({tok = TPtVirg _});
        ]
    )
    ::xs 
    when ctx = InFunction
      -> 
      ignore(info_parens);
      (* todo? check that in info_parens have what looks like expressions *)

      set_as_opar_cplusplus info_parens;

      aux xs






  | x::xs -> 
      aux xs
 in
 aux xs

(* ------------------------------------------------------------------------- *)
(* main fix cpp function *)
(* ------------------------------------------------------------------------- *)

let rebuild_tokens_extented toks_ext = 
  let _tokens = ref [] in
  toks_ext +> List.iter (fun tok -> 
    tok.new_tokens_before +> List.iter (fun x -> push2 x _tokens);
    push2 tok.tok _tokens 
  );
  let tokens = List.rev !_tokens in
  (tokens +> acc_map mk_token_extended)

let filter_cpp_stuff xs = 
  let rec aux xs = 
    match xs with
    | [] -> []
    | x::xs -> 
        (match x.tok with
        | tok when TH.is_comment tok -> aux xs
        (* don't want drop the define, or if drop, have to drop
         * also its body otherwise the line heuristics may be lost
         * by not finding the TDefine in column 0 but by finding
         * a TDefineIdent in a column > 0
         *)
        | Parser_c.TDefine _ -> 
            x::aux xs
        | tok when TH.is_cpp_instruction tok -> aux xs
        | _ -> x::aux xs
        )
  in
  aux xs
          

let insert_virtual_positions l =
  let strlen x = String.length (Ast_c.str_of_info x) in
  let rec loop prev offset = function
      [] -> []
    | x::xs ->
	let ii = TH.info_of_tok x in
	let inject pi =
	  TH.visitor_info_of_tok (function ii -> Ast_c.rewrap_pinfo pi ii) x in
	match Ast_c.pinfo_of_info ii with
	  Ast_c.OriginTok pi ->
	    let prev = Ast_c.parse_info_of_info ii in
	    x::(loop prev (strlen ii) xs)
	| Ast_c.ExpandedTok (pi,_) ->
	    inject (Ast_c.ExpandedTok (pi,(prev,offset))) ::
	    (loop prev (offset + (strlen ii)) xs)
	| Ast_c.FakeTok (s,_) ->
	    inject (Ast_c.FakeTok (s,(prev,offset))) ::
	    (loop prev (offset + (strlen ii)) xs)
	| Ast_c.AbstractLineTok _ -> failwith "abstract not expected" in
  let rec skip_fake = function
      [] -> []
    | x::xs ->
	let ii = TH.info_of_tok x in
	match Ast_c.pinfo_of_info ii with
	  Ast_c.OriginTok pi ->
	    let prev = Ast_c.parse_info_of_info ii in
	    x::(loop prev (strlen ii) xs)
	| _ -> x::skip_fake xs in
  skip_fake l








(* ------------------------------------------------------------------------- *)
let fix_tokens_cpp2 tokens = 
  let tokens2 = ref (tokens +> acc_map mk_token_extended) in
  
  begin 
    (* the order is important, if you put the action heuristic first,
     * then because of ifdef, can have not closed paren
     * and so may believe that higher order macro 
     * and it will eat too much tokens. So important to do 
     * first the ifdef.
     * 
     * I recompute multiple times cleaner cos the mutable
     * can have be changed and so may have more comments
     * in the token original list.
     * 
     *)

    (* before filtering space and comments, want closed tokens *)
    find_cplusplus_view_all_tokens !tokens2;

    (* ifdef *)
    let cleaner = !tokens2 +> List.filter (fun x -> 
      not (TH.is_comment x.tok) (* could filter also #define/#include *)
    ) in
    let ifdef_grouped = mk_ifdef cleaner in
    find_ifdef_funheaders ifdef_grouped;
    find_ifdef_bool       ifdef_grouped;
    find_ifdef_mid        ifdef_grouped;


    (* macro 1 *)
    let cleaner = !tokens2 +> filter_cpp_stuff in

    let paren_grouped = mk_parenthised  cleaner in
    apply_macro_defs paren_grouped;
    (* because the before field is used by apply_macro_defs *)
    tokens2 := rebuild_tokens_extented !tokens2; 

    (* tagging contextual info (InFunc, InStruct, etc). Better to do
     * that after the "ifdef-simplification" phase.
     *)
    let cleaner = !tokens2 +> List.filter (fun x -> 
      not (TH.is_comment x.tok) (* could filter also #define/#include *)
    ) in

    (* done on brace_grouped but actually modifies tokens2 *)
    let brace_grouped = mk_braceised cleaner in
    set_context_tag   brace_grouped;



    (* macro *)
    let cleaner = !tokens2 +> filter_cpp_stuff in

    let paren_grouped      = mk_parenthised  cleaner in
    let line_paren_grouped = mk_line_parenthised paren_grouped in
    find_define_init_brace_paren paren_grouped;
    find_string_macro_paren paren_grouped;
    find_macro_lineparen    line_paren_grouped;
    find_macro_paren        paren_grouped;

    find_cplusplus_view_filtered_tokens cleaner;
    find_cplusplus_view_parenthized paren_grouped;
    find_cplusplus_view_parenthized2 paren_grouped;
    find_cplusplus_view_line_paren line_paren_grouped;
    find_cplusplus_view_filtered_tokens_bis cleaner;

    (* actions *)
    let cleaner = !tokens2 +> filter_cpp_stuff in
    let paren_grouped = mk_parenthised  cleaner in
    find_actions  paren_grouped;


    insert_virtual_positions (!tokens2 +> acc_map (fun x -> x.tok))
  end

let fix_tokens_cpp a = 
  Common.profile_code "C parsing.fix_cpp" (fun () -> fix_tokens_cpp2 a)




(*****************************************************************************)
(* The #define tricks *)
(*****************************************************************************)

(* ugly hack, a better solution perhaps would be to erase TDefEOL 
 * from the Ast and list of tokens in parse_c. 
 * 
 * note: I do a +1 somewhere, it's for the unparsing to correctly sync.
 * 
 * note: can't replace mark_end_define by simply a fakeInfo(). The reason
 * is where is the \n TCommentSpace. Normally there is always a last token
 * to synchronize on, either EOF or the token of the next toplevel.
 * In the case of the #define we got in list of token 
 * [TCommentSpace "\n"; TDefEOL] but if TDefEOL is a fakeinfo then we will
 * not synchronize on it and so we will not print the "\n".
 * A solution would be to put the TDefEOL before the "\n".
 * 
 * todo?: could put a ExpandedTok for that ? 
 *)
let mark_end_define ii = 
  let ii' = 
    { Ast_c.pinfo = Ast_c.OriginTok { (Ast_c.parse_info_of_info ii) with 
        Common.str = ""; 
        Common.charpos = Ast_c.pos_of_info ii + 1
      };
      cocci_tag = ref Ast_c.emptyAnnot;
      comments_tag = ref Ast_c.emptyComments;
    } 
  in
  TDefEOL (ii')


(* put the TDefEOL at the good place *)
let rec define_line_1 xs = 
  match xs with
  | [] -> []
  | TDefine ii::xs -> 
      let line = Ast_c.line_of_info ii in
      TDefine ii::define_line_2 line ii xs
  | TCppEscapedNewline ii::xs -> 
      pr2 "WIERD: a \\ outside a #define";
      TCommentSpace ii::define_line_1 xs
  | x::xs -> 
      x::define_line_1 xs

and define_line_2 line lastinfo xs = 
  match xs with 
  | [] -> 
      (* should not happened, should meet EOF before *)
      pr2 "PB: WIERD";   
      mark_end_define lastinfo::[]
  | x::xs -> 
      let line' = TH.line_of_tok x in
      let info = TH.info_of_tok x in

      (match x with
      | EOF ii -> 
          mark_end_define lastinfo::EOF ii::define_line_1 xs
      | TCppEscapedNewline ii -> 
          if (line' <> line) then pr2 "PB: WIERD: not same line number";
          TCommentSpace ii::define_line_2 (line+1) info xs
      | x -> 
          if line' = line
          then x::define_line_2 line info xs 
          else 
            mark_end_define lastinfo::define_line_1 (x::xs)
      )

let rec define_ident xs = 
  match xs with
  | [] -> []
  | TDefine ii::xs -> 
      TDefine ii::
      (match xs with
      | TCommentSpace i1::TIdent (s,i2)::TOPar (i3)::xs -> 
          (* Change also the kind of TIdent to avoid bad interaction
           * with other parsing_hack tricks. For instant if keep TIdent then
           * the stringication algo can believe the TIdent is a string-macro.
           * So simpler to change the kind of the ident too.
           *)
          (* if TOParDefine sticked to the ident, then 
           * it's a macro-function. Change token to avoid ambiguity
           * between #define foo(x)  and   #define foo   (x)
           *)
          TCommentSpace i1::TIdentDefine (s,i2)::TOParDefine i3
          ::define_ident xs
      | TCommentSpace i1::TIdent (s,i2)::xs -> 
          TCommentSpace i1::TIdentDefine (s,i2)::define_ident xs
      | _ -> 
          pr2 "wierd #define body"; 
          define_ident xs
      )
  | x::xs -> 
      x::define_ident xs
  


let fix_tokens_define2 xs = 
  define_ident (define_line_1 xs)

let fix_tokens_define a = 
  Common.profile_code "C parsing.fix_define" (fun () -> fix_tokens_define2 a)
      

(*****************************************************************************)
(* for the cpp-builtin *)
(*****************************************************************************)

let rec define_parse xs = 
  match xs with
  | [] -> []
  | TDefine i1::TIdentDefine (s,i2)::TOParDefine i3::xs -> 
      let (tokparams, _, xs) = 
        xs +> Common.split_when (function TCPar _ -> true | _ -> false) in
      let (body, _, xs) = 
        xs +> Common.split_when (function TDefEOL _ -> true | _ -> false) in
      let params = 
        tokparams +> Common.map_filter (function
        | TComma _ -> None
        | TIdent (s, _) -> Some s
        | x -> error_cant_have x
        ) in
      let body = body +> List.map 
        (TH.visitor_info_of_tok Ast_c.make_expanded) in
      let def = (s, (Right params, body)) in
      def::define_parse xs

  | TDefine i1::TIdentDefine (s,i2)::xs -> 
      let (body, _, xs) = 
        xs +> Common.split_when (function TDefEOL _ -> true | _ -> false) in
      let body = body +> List.map 
        (TH.visitor_info_of_tok Ast_c.make_expanded) in
      let def = (s, (Left (), body)) in
      def::define_parse xs

  | TDefine i1::_ -> 
      raise Impossible
  | x::xs -> define_parse xs 
      

let extract_cpp_define xs = 
  let cleaner = xs +> List.filter (fun x -> 
    not (TH.is_comment x)
  ) in
  define_parse cleaner
  

      

(*****************************************************************************)
(* Lexing with lookahead *)
(*****************************************************************************)

(* Why using yet another parsing_hack technique ? The fix_xxx where do
 * some pre-processing on the full list of tokens is not enough ? 
 * No cos sometimes we need more contextual info, and even if
 * set_context() tries to give some contextual info, it's not completely
 * accurate so the following code give yet another alternative, yet another
 * chance to transform some tokens.
 * 
 * todo?: maybe could try to get rid of this technique. Maybe a better
 * set_context() would make possible to move this code using a fix_xx
 * technique.
 * 
 * This function work on a "cleaned" set of tokens, no space, no comment, 
 * no cpp.
 * c++ext: also no classname::
 *
 * 
 * LALR(k) trick. We can do stuff by adding cases in lexer_c.mll, but
 * it is more general to do it via my LALR(k) tech. Because here we can
 * transform some token give some context information. So sometimes it
 * makes sense to transform a token in one context, sometimes not, and
 * lex can not provide us this context information. Note that the order
 * in the pattern matching in lookahead is important. Do not cut/paste. 
 * 
 * Note that in next there is only "clean" tokens, there is no comment
 * or space tokens. This is done by the caller.
 * 
 * 
 * c++ext: 
 *  - add a |TAnd _ where had a TMul _
 *)

open Lexer_parser2 (* for the fields of lexer_hint type *)

let not_struct_enum = function
  | x::xs when TH.is_struct_like_keyword x -> false
  | [] -> true
  | x::xs -> true




let lookahead2 next before = 

  match (next, before) with

  (* c++ext: constructed objects part2 *)
  (* > xx(   and in function *)
  | TOPar i1::_,           TIdent(s,i2)::TSup2 _::_ 
      when (LP.current_context () = (LP.InFunction)) -> 
        pr2_cplusplus("constructed_object: "  ^s);
        TOParCplusplusInit i1    

  (* yy xx(   and in function *)
  | TOPar i1::_,              TIdent(s,i2)::TypedefIdent _::_ 
      when (LP.current_context () = (LP.InFunction)) -> 
        pr2_cplusplus("constructed_object: "  ^s);
        TOParCplusplusInit i1    

  (* int xx( and in function, problably not a internal declaration *)
  | TOPar i1::_,   TIdent(s,i2)::t1::_ 
      when (LP.current_context () = (LP.InFunction)) &&
        TH.is_basic_type t1
        -> 
        pr2_cplusplus("constructed_object: "  ^s);
        TOParCplusplusInit i1    
        



  (* c++ext: for cast_function_expression and constructed expression.
   * Can only match cast_function_expression ? can also match destructor ...
   * 
   * note: the order is important
   * 
   * false positif of cast_function_typedef
   *  
   * typedef xxx ( *yyy) ...
   * new xxx(...)
   * new (placement_opt) xxx(...)
   *)
  | (TypedefIdent(s,i1))::TOPar _::_ , ((Ttypedef _|Tnew _ |TCPar _)::_) 
      ->
      TypedefIdent(s,i1)

  | tok::TOPar _::_ , ((Ttypedef _|Tnew _ |TCPar _)::_) 
     when TH.is_basic_type tok  ->
      tok

  (* addon: inline XXX() *)
  | ((TIdent(s,i1)|TypedefIdent(s,i1))::TOPar _::_, 
    (((TOBrace _| TCBrace _|TPtVirg _ | Texplicit _  |Tinline _)::_)
     (* for    public:   xx * y; *)
      | TCol _::(Tpublic _ |Tprotected _|Tprivate _)::_
    )) when (LP.current_context () = (LP.InClassStruct s))
        -> 
      msg_constructorname s;
      Tconstructorname(s,i1)


  | (TypedefIdent(s,i1))::TOPar _::_ , _ 
    -> 
      pr2_cplusplus("cast_function_typedef: "  ^s);
      TypedefIdent2(s,i1)


  (* basic type can now also be used as "cast_function/constructor" *)
  | (Tchar(i1))::TOPar _::_ , _  
      when (LP.current_context() <> LP.InParameter)
        ->
      pr2_cplusplus("cast_function_typedef: "  ^"char");
      Tchar2(i1)
  | (Tint(i1))::TOPar _::_ , _   
      when (LP.current_context() <> LP.InParameter)
        -> 
      pr2_cplusplus("cast_function_typedef: "  ^"int");
      Tint2(i1)
  | (Tfloat(i1))::TOPar _::_ , _   
      when (LP.current_context() <> LP.InParameter)
        -> 
      pr2_cplusplus("cast_function_typedef: "  ^"float");
      Tfloat2(i1)
  | (Tdouble(i1))::TOPar _::_ , _   
      when (LP.current_context() <> LP.InParameter)
        -> 
      pr2_cplusplus("cast_function_typedef: "  ^"double");
      Tdouble2(i1)
  | (Tshort(i1))::TOPar _::_ , _   
      when (LP.current_context() <> LP.InParameter)
        -> 
      pr2_cplusplus("cast_function_typedef: "  ^"short");
      Tshort2(i1)
  | (Tlong(i1))::TOPar _::_ , _   
      when (LP.current_context() <> LP.InParameter)
        -> 
      pr2_cplusplus("cast_function_typedef: "  ^"long");
      Tlong2(i1)

  | (Tbool(i1))::TOPar _::_ , _   
      when (LP.current_context() <> LP.InParameter)
        -> 
      pr2_cplusplus("cast_function_typedef: "  ^"bool");
      Tbool2(i1)




  (* new foo() *)
  | TIdent(s,i1)::_, Tnew _::_ -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* template<xxx  on xxx *)
  | TIdent(s,i1)::_,      TInf2 _::_ -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* template<xxx, yyy  on yyy *)
  | TIdent(s,i1)::_,      TComma _::TypedefIdent(_)::TInf2 _::_ -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

      

  (*-------------------------------------------------------------*)
  (* typedef inference, parse_typedef_fix3 *)
  (*-------------------------------------------------------------*)
  (* xx xx *)
  | (TIdent(s,i1)::TIdent(s2,i2)::_ , _) when not_struct_enum before && s = s2
      && ok_typedef s
      (* (take_safe 1 !passed_tok <> [TOPar]) ->  *)
    -> 
      (* parse_typedef_fix3:
       *    acpi_object		acpi_object;
       * etait mal pars'e, car pas le temps d'appeler dt()  dans le type_spec. 
       * Le parser en interne a deja appel'e le prochain token pour pouvoir
       * decider des choses.
       *  => special case in lexer_heuristic, again
       *)
      if !Flag_parsing_c.debug_typedef 
      then pr2 ("TYPEDEF: disable typedef cos special case: " ^ s); 

      LP.disable_typedef();

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* xx yy *)
  | (TIdent (s, i1)::TIdent (s2, i2)::_  , _) 
      when not_struct_enum before 
      && ok_typedef s
        ->
         (* && not_annot s2 BUT lead to false positive*)

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (* xx inline *)
  | (TIdent (s, i1)::Tinline i2::_  , _) when not_struct_enum before 
      && ok_typedef s
      -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (* [,(] xx [,)] AND param decl *)
  | (TIdent (s, i1)::(TComma _|TCPar _)::_ , (TComma _ |TOPar _)::_ )
    when not_struct_enum before && (LP.current_context() = LP.InParameter)
      && ok_typedef s
      -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (* [,(] xx =  AND param decl  for c++ext:  *)
  | (TIdent (s, i1)::TEq _ ::_ , (TComma _|TOPar _)::_ )
    when not_struct_enum before && (LP.current_context() = LP.InParameter)
      && ok_typedef s
      -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

(*TODO can add static_cast<> case here too, look for TSup not just TCPar *)
  (* xx* [,)]    '*' or '&' *)
  (* specialcase:  [,(] xx* [,)] *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::(TComma _|TCPar _)::_ , (*(TComma _|TOPar _)::*)_ )
    when not_struct_enum before
        (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      && ok_typedef s
    -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


(*TODO can add static_cast<> case here too, look for TSup not just TCPar *)
  (* xx** [,)] *)
  (* specialcase:  [,(] xx** [,)] *)
  | (TIdent (s, i1)::TMul _::TMul _::(TComma _|TCPar _)::_ , (*(TComma _|TOPar _)::*)_ )
    when not_struct_enum before
      (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      && ok_typedef s
    -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* specialcase:  xx*& [,)] *)
  | (TIdent (s, i1)::TMul _::TAnd _::(TComma _|TCPar _)::_ , (*(TComma _|TOPar _)::*)_ )
    when not_struct_enum before
      (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      && ok_typedef s
    -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)



  (* just look for const xx ? no!! cos can have char const xx; *)

  (* const xx *)
  | (TIdent (s, i1))::xs,  Tconst _::_ 
     when (LP.current_context() = LP.InTemplateParam) 
       && ok_typedef s  ->

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* xx const *   USELESS because of next rule ? *)
  | (TIdent (s, i1)::(Tconst _|Tvolatile _|Trestrict _)::TMul _::_ , _ ) 
      when not_struct_enum before 
      (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      && ok_typedef s
      ->

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)
  
  (* xx const *)
  | (TIdent (s, i1)::(Tconst _|Tvolatile _|Trestrict _)::_ , _ ) 
      when not_struct_enum before 
      && ok_typedef s
      (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      ->

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (* xx * const *)
  | (TIdent (s, i1)::TMul _::(Tconst _ | Tvolatile _|Trestrict _)::_ , _ ) 
      when not_struct_enum before 
      && ok_typedef s
      ->
      (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

(*TODO can add static_cast<> case here too, look for TSup not just TCPar *)

  (* ( const xx)  *)
  | (TIdent (s, i1)::TCPar _::_,  (Tconst _ | Tvolatile _|Trestrict _)::TOPar _::_) when
      ok_typedef s ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)
      


  (* ( xx ) [sizeof, ~]  c++ext: TString *)
  | (TIdent (s, i1)::TCPar _::(Tsizeof _|TTilde _ | TString _)::_ , TOPar _::_ )
    when not_struct_enum before
      && ok_typedef s
    -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* [(,] xx [   AND parameterdeclaration *)
  | (TIdent (s, i1)::TOCro _::_, (TComma _ |TOPar _)::_)
      when (LP.current_context() = LP.InParameter) 
      && ok_typedef s
     -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)
        
  (*------------------------------------------------------------*)
  (* if 'x*y' maybe an expr, maybe just a classic multiplication *)
  (* but if have a '=', or ','   I think not *)
  (*------------------------------------------------------------*)

  (* static|const|... xx * yy    '*' or '&'  *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::_ , 
     (Tregister _|Tstatic _ |Tvolatile _|Tconst _|Trestrict _|Tvirtual _)::_) when
      ok_typedef s 
        ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

        
  (*  TODO  xx * yy ; AND in start of compound element  *)


  (*  xx * yy,      AND  in paramdecl   '*' or '&' *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::TComma _::_ , _)
    when not_struct_enum before && (LP.current_context() = LP.InParameter)
      && ok_typedef s 
      -> 

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (*  xx * &yy,      AND  in paramdecl *)
  | (TIdent (s, i1)::TMul _::TAnd _::TIdent (s2, i2)::TComma _::_ , _)
    when not_struct_enum before && (LP.current_context() = LP.InParameter)
      && ok_typedef s 
      -> 

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (*  xx * yy ;     AND in Toplevel, except when have = before  *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::TPtVirg _::_ , TEq _::_) ->
      TIdent (s, i1)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::TPtVirg _::_ , _)
    when not_struct_enum before && 
      (LP.is_top_or_struct (LP.current_context ()))
      -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (*  xx * yy ,     AND in Toplevel  *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::TComma _::_ , _)
    when not_struct_enum before 
      && (LP.is_top_or_struct (LP.current_context ()))
      (*(LP.current_context () = LP.InTopLevel)*)
      && ok_typedef s 
      -> 

      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (*  xx * yy (     AND in Toplevel  '*' or '&'  *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::(TIdent (_, i2))::TOPar _::_ , _)
    when not_struct_enum before  
      && (LP.is_top_or_struct (LP.current_context ()))
      && ok_typedef s 
      ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (*  xx * operator      AND in Toplevel  '*' or '&'  *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::(Toperator (i2))::_ , _)
    when not_struct_enum before  
      && (LP.is_top_or_struct (LP.current_context ()))
      && ok_typedef s 
      ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (*  xx *& yy (     AND in Toplevel *)
  | (TIdent (s, i1)::TMul _::TAnd _::(TIdent (s2, i2))::TOPar _::_ , _)
    when not_struct_enum before  
      && (LP.is_top_or_struct (LP.current_context ()))
      && ok_typedef s 
      ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

        
  (* xx * yy [ *)
  (* todo? enough ? cos in struct def we can have some expression ! *)
  | (TIdent (s, i1)::TMul _::TIdent (s2, i2)::TOCro _::_ , _)
    when not_struct_enum before && 
      (LP.is_top_or_struct (LP.current_context ()))
      && ok_typedef s 
      -> 
      msg_typedef (s,i1);  LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* u16: 10; in struct *)
  | (TIdent (s, i1)::TCol _::_ , (TOBrace _ | TPtVirg _)::_)
    when 
      (LP.is_top_or_struct (LP.current_context ()))
      && ok_typedef s 
      -> 
      msg_typedef (s,i1);  LP.add_typedef_root s;
      TypedefIdent (s, i1)
        

    (*  why need TOPar condition as stated in preceding rule ? really needed ? *)
    (*   YES cos at toplevel can have some expression !! for instance when *)
    (*   enter in the dimension of an array *)
    (*
      | (TIdent s::TMul::TIdent s2::_ , _)
      when (take_safe 1 !passed_tok <> [Tstruct] &&
      (take_safe 1 !passed_tok <> [Tenum]))
      &&
      !LP._lexer_hint = Some LP.Toplevel -> 
      msg_typedef (s,i1); 
      LP.add_typedef_root s;
      TypedefIdent s
     *)

  (*  xx * yy =  *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::TEq _::_ , _)
    when not_struct_enum before 
      && ok_typedef s 
      ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)




  (*  xx * yy)      AND in paramdecl    '*' or '&' *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::TCPar _::_ , _)
      when not_struct_enum before && (LP.current_context () = LP.InParameter)
        && ok_typedef s 
        ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (*  xx * &yy)      AND in paramdecl *)
  | (TIdent (s, i1)::TMul _::TAnd _::TIdent (s2, i2)::TCPar _::_ , _)
      when not_struct_enum before && (LP.current_context () = LP.InParameter)
      && ok_typedef s 
        ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)
          
  (*  xx * yy; *) (* wrong ? *)
  | (TIdent (s, i1)::TMul _::TIdent (s2, i2)::TPtVirg _::_ , 
     (((TOBrace _| TPtVirg _)::_)
     (*c++ext: public: xx * y; *)
      | TCol _::(Tpublic _ |Tprotected _|Tprivate _)::_
    ))
       when not_struct_enum before 
      && ok_typedef s 
        ->
      msg_typedef (s,i1);  LP.add_typedef_root s;
      pr2 ("PB MAYBE: dangerous typedef inference, maybe not a typedef: " ^ s);
      TypedefIdent (s, i1)

  (* : public y *)
  | (TIdent (s, i1))::_ , (Tpublic _ |Tprotected _|Tprivate _)::TCol _::_
      when ok_typedef s 
      ->
      msg_typedef (s,i1);  LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (*  xx * yy,  and ';' before xx *) (* wrong ? *)
  | (TIdent (s, i1)::TMul _::TIdent (s2, i2)::TComma _::_ , 
     (TOBrace _| TPtVirg _)::_) when
      ok_typedef s 
    ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (* xx_t * yy *)
  | (TIdent (s, i1)::(TMul _|TAnd _)::TIdent (s2, i2)::_ , _)  
      when s ==~ regexp_typedef && not_struct_enum before 
        (* struct user_info_t sometimes *) 
      && ok_typedef s 
        -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (*  xx ** yy *)  (* wrong ? maybe look at position, if space then 
   * don't do it *)
  | (TIdent (s, i1)::TMul _::TMul _::TIdent (s2, i2)::_ , _)
    when not_struct_enum before
        (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      && ok_typedef s 
      ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (* xx *** yy *)
  | (TIdent (s, i1)::TMul _::TMul _::TMul _::TIdent (s2, i2)::_ , _)
    when not_struct_enum before 
      && ok_typedef s 
        (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

  (*  xx ** ) *)
  | (TIdent (s, i1)::TMul _::TMul _::TCPar _::_ , _)
    when not_struct_enum before  
        (* && !LP._lexer_hint = Some LP.ParameterDeclaration *)
      && ok_typedef s 
      ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)



  (* ----------------------------------- *)

  (*  (xx) yy    yy or int or char (and string??) *)
  | (TOPar info::TIdent (s, i1)::TCPar i2::
        (TIdent (_,i3)|TInt (_,i3)|TFloat(_,i3)|TChar(_,i3))::_ , 
    x::_)  
    when not (TH.is_stuff_taking_parenthized x) &&
      Ast_c.line_of_info i2 = Ast_c.line_of_info i3
      && ok_typedef s 
      -> 

      msg_typedef (s,i1); LP.add_typedef_root s;
      TOPar info

(*TODO can add static_cast<> case here too, look for TSup not just TCPar *)

  (*  (xx) (    yy) *)
  | (TOPar info::TIdent (s, i1)::TCPar _::TOPar _::_ , x::_)  
    when not (TH.is_stuff_taking_parenthized x)  
      && ok_typedef s 
        ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TOPar info

  (*  (xx * ) yy *)
  | (TOPar info::TIdent (s, i1)::TMul _::TCPar _::TIdent (s2, i2)::_ , _) when 
      ok_typedef s 
        -> 
      msg_typedef (s,i1); LP.add_typedef_root s;
      TOPar info

(* c++ext: interference with constructor recursive call,
   cf tests2/typedef_false_interference_constructor1.cpp
   could also add LP.lexer_hint.ctor_mem_initializer and
   no trigger following rule if in this region

  (* (xx){ ... }  constructor *)
  | (TIdent (s, i1)::TCPar _::TOBrace _::_ , TOPar _::x::_)  
      when (*s ==~ regexp_typedef && *) not (TH.is_stuff_taking_parenthized x) 
      && ok_typedef s 
        ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)

*)


        (* can have sizeof on expression
           | (Tsizeof::TOPar::TIdent s::TCPar::_,   _) -> 
           msg_typedef (s,i1); 
           LP.add_typedef_root s;
           Tsizeof
         *)
   (* x ( *y )(params),  function pointer *)
  | (TIdent (s, i1)::TOPar _::TMul _::TIdent _::TCPar _::TOPar _::_,  _) 
      when not_struct_enum before
      && ok_typedef s 
        ->
      msg_typedef (s,i1); LP.add_typedef_root s;
      TypedefIdent (s, i1)


  (*-------------------------------------------------------------*)
  (* CPP *)
  (*-------------------------------------------------------------*)
  | ((TIfdef ii |TIfdefelse ii |TIfdefelif ii |TEndif ii |
      TIfdefBool (_,ii)|TIfdefMisc(_,ii)|TIfdefVersion(_,ii))
        as x)
    ::_, _ 
      -> 
      if not !Flag_parsing_c.ifdef_to_if 
      then TCommentCpp (Ast_c.CppDirective, ii)
      else 
        if not (LP.current_context () = LP.InTopLevel)
        then x
        else begin
          pr2_cpp("IFDEF: or related outside function. I treat it as comment");
          TCommentCpp (Ast_c.CppDirective, ii)
        end


   (* If ident contain a for_each, then certainly a macro. But to be
    * sure should look if there is a '{' after the ')', but it requires
    * to count the '('. Because this can be expensive, we do that only
    * when the token contains "for_each". 
    *)
(*c++ext: some false positif so for now commented 
soluce will be to check that InFunction, the not toplevel is not good
enough anymore with nested stuff.
  | (TIdent (s, i1)::TOPar _::rest, _) when not (LP.current_context () = LP.InTopLevel)  
      (* otherwise a function such as static void loopback_enable(int i) { 
       * will be considered as a loop 
       *)
        ->

 
      if s ==~ regexp_foreach && 
        is_really_foreach (Common.take_safe forLOOKAHEAD rest)
   
      then begin
        msg_foreach s;
        TMacroIterator (s, i1)
      end
      else TIdent (s, i1)
*)


                    
 (*-------------------------------------------------------------*)
 | v::xs, _ -> v
 | _ -> raise Impossible

let lookahead a b = 
  Common.profile_code "C parsing.lookahead" (fun () -> lookahead2 a b)


