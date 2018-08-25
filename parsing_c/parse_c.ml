(* Yoann Padioleau
 *
 * Copyright (C) 2006, 2007, 2008 Ecole des Mines de Nantes
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
open Common2

module TH = Token_helpers
module LP = Lexer_parser

module Stat = Parsing_stat

(*****************************************************************************)
(* Wrappers *)
(*****************************************************************************)
let pr2_err s =
  if !Flag_parsing_c.verbose_parsing
  then Common.pr2 s

let pr2_once s =
  if !Flag_parsing_c.verbose_parsing
  then Common.pr2_once s

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

let lexbuf_to_strpos lexbuf     =
  (Lexing.lexeme lexbuf, Lexing.lexeme_start lexbuf)

let token_to_strpos tok =
  (TH.str_of_tok tok, TH.pos_of_tok tok)


let error_msg_tok tok =
  let file = TH.file_of_tok tok in
  if !Flag_parsing_c.verbose_parsing
  then Parse_info.error_message file (token_to_strpos tok)
  else ("error in " ^ file  ^ "; set verbose_parsing for more info")


let print_bad line_error (start_line, end_line) filelines  =
  begin
    pr2 ("badcount: " ^ i_to_s (end_line - start_line));

    for i = start_line to end_line do
      let line = filelines.(i) in

      if i =|= line_error
      then  pr2 ("BAD:!!!!!" ^ " " ^ line)
      else  pr2 ("bad:" ^ " " ^      line)
    done
  end



let mk_info_item2 filename toks =
  let buf = Buffer.create 100 in
  let s =
    (* old: get_slice_file filename (line1, line2) *)
    begin
      toks |> List.iter (fun tok ->
        match TH.pinfo_of_tok tok with
        | Ast_c.OriginTok _ ->
            Buffer.add_string buf (TH.str_of_tok tok)
        | Ast_c.AbstractLineTok _ ->
            raise Impossible
        | _ -> ()
      );
      Buffer.contents buf
    end
  in
  (s, toks)

let mk_info_item a b =
  Common.profile_code "C parsing.mk_info_item"
    (fun () -> mk_info_item2 a b)


let info_same_line line xs =
  xs |> List.filter (fun info -> Ast_c.line_of_info info =|= line)


(*****************************************************************************)
(* Stats on what was passed/commentized  *)
(*****************************************************************************)

let commentized xs = xs |> Common.map_filter (function
  | Parser_c.TCommentCpp (cppkind, ii) ->
      let s = Ast_c.str_of_info ii in
      let legal_passing =
        match !Flag_parsing_c.filter_passed_level with
        | 0 -> false
        | 1 ->
            List.mem cppkind [Token_c.CppAttr]
            ||
            (s =~ "__.*")
        | 2 ->
            List.mem cppkind [Token_c.CppAttr;Token_c.CppPassingNormal]
            ||
            (s =~ "__.*")
        | 3 ->
            List.mem cppkind [Token_c.CppAttr;Token_c.CppPassingNormal;Token_c.CppDirective]
            ||
            (s =~ "__.*")
        | 4 ->
            List.mem cppkind [Token_c.CppAttr;Token_c.CppPassingNormal;Token_c.CppMacro]
            ||
            (s =~ "__.*")


        | 5 ->
            List.mem cppkind [Token_c.CppAttr;Token_c.CppPassingNormal;Token_c.CppDirective;Token_c.CppMacro]
            ||
            (s =~ "__.*")




        | _ -> failwith "not valid level passing number"
      in
      if legal_passing then None else Some (ii.Ast_c.pinfo)

        (*
        | Ast_c.CppOther ->
            (match s with
            | s when s =~ "KERN_.*" -> None
            | s when s =~ "__.*" -> None
            | _ ->
                Some (ii.Ast_c.pinfo)
            )
        *)


  | Parser_c.TCommentMisc ii
  | Parser_c.TAction ii
    ->
      Some (ii.Ast_c.pinfo)
  | _ ->
      None
 )

let count_lines_commentized xs =
  let line = ref (-1) in
  let count = ref 0 in
  begin
    commentized xs |>
    List.iter
      (function
	  Ast_c.OriginTok pinfo | Ast_c.ExpandedTok (_,(pinfo,_)) ->
	    let newline = pinfo.Parse_info.line in
	    if newline <> !line
	    then begin
              line := newline;
              incr count
	    end
	| _ -> ());
    !count
  end



let print_commentized xs =
  let line = ref (-1) in
  begin
    let ys = commentized xs in
    ys |>
    List.iter
      (function
	  Ast_c.OriginTok pinfo | Ast_c.ExpandedTok (_,(pinfo,_)) ->
	    let newline = pinfo.Parse_info.line in
	    let s = pinfo.Parse_info.str in
	    let s = Str.global_substitute
		(Str.regexp "\n") (fun s -> "") s
	    in
	    if newline =|= !line
	    then prerr_string (s ^ " ")
	    else begin
              if !line =|= -1
              then Common2.pr2_no_nl "passed:"
              else Common2.pr2_no_nl "\npassed:";
              line := newline;
              Common2.pr2_no_nl (s ^ " ");
	    end
	| _ -> ());
    if not (null ys) then pr2 "";
  end




(*****************************************************************************)
(* Lexing only *)
(*****************************************************************************)

(* called by parse_print_error_heuristic *)
let tokens2 file =
 let table     = Parse_info.full_charpos_to_pos_large file in

 Common.with_open_infile file (fun chan ->
  let lexbuf = Lexing.from_channel chan in
  try
    let rec tokens_aux acc =
      let tok = Lexer_c.token lexbuf in
      (* fill in the line and col information *)
      let tok = tok |> TH.visitor_info_of_tok (fun ii ->
        { ii with Ast_c.pinfo=
          (* could assert pinfo.filename = file ? *)
	  match Ast_c.pinfo_of_info ii with
	    Ast_c.OriginTok pi ->
              Ast_c.OriginTok (Parse_info.complete_parse_info_large file table pi)
	  | Ast_c.ExpandedTok (pi,vpi) ->
              Ast_c.ExpandedTok((Parse_info.complete_parse_info_large file table pi),vpi)
	  | Ast_c.FakeTok (s,vpi) -> Ast_c.FakeTok (s,vpi)
	  | Ast_c.AbstractLineTok pi -> failwith "should not occur"
      })
      in

      if TH.is_eof tok
      then List.rev (tok::acc)
      else tokens_aux (tok::acc)
    in
    tokens_aux []
  with
    | Lexer_c.Lexical s ->
        failwith ("lexical error " ^ s ^ "\n =" ^
                  (Parse_info.error_message file (lexbuf_to_strpos lexbuf)))
    | e -> raise e
 )

let time_lexing ?(profile=true) a =
  if profile
  then Common.profile_code_exclusif "LEXING" (fun () -> tokens2 a)
  else tokens2 a
let tokens ?profile a =
  Common.profile_code "C parsing.tokens" (fun () -> time_lexing ?profile a)


let tokens_of_string string =
  let lexbuf = Lexing.from_string string in
  try
    let rec tokens_s_aux () =
      let tok = Lexer_c.token lexbuf in
      if TH.is_eof tok
      then [tok]
      else tok::(tokens_s_aux ())
    in
    tokens_s_aux ()
  with
    | Lexer_c.Lexical s -> failwith ("lexical error " ^ s ^ "\n =" )
    | e -> raise e


(*****************************************************************************)
(* Parsing, but very basic, no more used *)
(*****************************************************************************)

(*
 * !!!Those function use refs, and are not reentrant !!! so take care.
 * It use globals defined in Lexer_parser.
 *
 * update: because now lexer return comments tokens, those functions
 * may not work anymore.
 *)

let parse file =
  let lexbuf = Lexing.from_channel (open_in file) in
  let result = Parser_c.main Lexer_c.token lexbuf in
  result


let parse_print_error file =
  let chan = (open_in file) in
  let lexbuf = Lexing.from_channel chan in

  let error_msg () = Parse_info.error_message file (lexbuf_to_strpos lexbuf) in
  try
    lexbuf |> Parser_c.main Lexer_c.token
  with
  | Lexer_c.Lexical s ->
      failwith ("lexical error " ^s^ "\n =" ^  error_msg ())
  | Parsing.Parse_error ->
      failwith ("parse error \n = " ^ error_msg ())
  | Semantic_c.Semantic (s, i) ->
      failwith ("semantic error " ^ s ^ "\n =" ^ error_msg ())
  | e -> raise e




(*****************************************************************************)
(* Parsing subelements, useful to debug parser *)
(*****************************************************************************)

(*
 * !!!Those function use refs, and are not reentrant !!! so take care.
 * It use globals defined in Lexer_parser.
 *)


(* old:
 *   let parse_gen parsefunc s =
 *     let lexbuf = Lexing.from_string s in
 *     let result = parsefunc Lexer_c.token lexbuf in
 *     result
 *)

let parse_gen parsefunc s =
  let toks = tokens_of_string s |> List.filter TH.is_not_comment in


  (* Why use this lexing scheme ? Why not classically give lexer func
   * to parser ? Because I now keep comments in lexer. Could
   * just do a simple wrapper that when comment ask again for a token,
   * but maybe simpler to use cur_tok technique.
   *)
  let all_tokens = ref toks in
  let cur_tok    = ref (List.hd !all_tokens) in

  let lexer_function =
    (fun _ ->
      if TH.is_eof !cur_tok
      then (pr2_err "LEXER: ALREADY AT END"; !cur_tok)
      else
        let v = Common2.pop2 all_tokens in
        cur_tok := v;
        !cur_tok
    )
  in
  let lexbuf_fake = Lexing.from_function (fun buf n -> raise Impossible) in
  let result = parsefunc lexer_function lexbuf_fake in
  result


let type_of_string       = parse_gen Parser_c.type_name
let statement_of_string  = parse_gen Parser_c.statement
let expression_of_string = parse_gen Parser_c.expr

(* ex: statement_of_string "(struct us_data* )psh->hostdata = NULL;" *)





(*****************************************************************************)
(* Consistency checking *)
(*****************************************************************************)

(* todo:
 *  could check that an ident has always the same class, be it a typedef
 *  (but sometimes do 'acpi_val acpi_val;'), an ident, a TMacroStatement,
 *  etc.
 *)

type class_ident =
  | CIdent (* can be var, func, field, tag, enum constant *)
  | CTypedef

let str_of_class_ident = function
  | CIdent -> "Ident"
  | CTypedef -> "Typedef"

(*
  | CMacro
  | CMacroString
  | CMacroStmt
  | CMacroDecl
  | CMacroIterator
  | CAttr

(* but take care that must still be able to use '=' *)
type context = InFunction | InEnum | InStruct | InInitializer | InParams
type class_token =
  | CIdent of class_ident

  | CComment
  | CSpace
  | CCommentCpp of cppkind
  | CCommentMisc
  | CCppDirective

  | COPar
  | CCPar
  | COBrace
  | CCBrace

  | CSymbol
  | CReservedKwd (type | decl | qualif | flow | misc | attr)
*)

let ident_to_typename ident =
  (Ast_c.nQ, (Ast_c.TypeName  (ident, Ast_c.noTypedefDef()), Ast_c.noii))


(* parse_typedef_fix4 *)
let consistency_checking2 xs =

  (* first phase, gather data *)
  let stat = Hashtbl.create 101 in

  (* default value for hash *)
  let v1 () = Hashtbl.create 101 in
  let v2 () = ref 0 in

  let bigf = { Visitor_c.default_visitor_c with

    Visitor_c.kexpr = (fun (k,bigf) x ->
      match Ast_c.unwrap_expr x with
      | Ast_c.Ident (id) ->
          let s = Ast_c.str_of_name id in
          stat |>
            Common2.hfind_default s v1 |> Common2.hfind_default CIdent v2 |>
            (fun aref -> incr aref)

      | _ -> k x
    );
    Visitor_c.ktype = (fun (k,bigf) t ->
      match Ast_c.unwrap_typeC t with
      | Ast_c.TypeName (name,_typ) ->
          let s = Ast_c.str_of_name name in
          stat |>
            Common2.hfind_default s v1 |> Common2.hfind_default CTypedef v2 |>
            (fun aref -> incr aref)

      | _ -> k t
    );
  }
  in
  xs |> List.iter (fun (p, info_item) -> Visitor_c.vk_toplevel bigf p);


  let ident_to_type = ref [] in


  (* second phase, analyze data *)
  stat |> Hashtbl.iter (fun k v ->
    let xs = Common.hash_to_list v in
    if List.length xs >= 2
    then begin
      pr2_err ("CONFLICT:" ^ k);
      let sorted = xs |> List.sort (fun (ka,va) (kb,vb) ->
        if !va =|= !vb then
          (match ka, kb with
          | CTypedef, _ -> 1 (* first is smaller *)
          | _, CTypedef -> -1
          | _ -> 0
          )
        else compare !va !vb
      ) in
      let sorted = List.rev sorted in
      match sorted with
      | [CTypedef, i1;CIdent, i2] ->
          pr2_err ("transforming some ident in typedef");
          Common.push k ident_to_type;
      | _ ->
          pr2_err ("TODO:other transforming?");

    end
  );

  (* third phase, update ast.
   * todo? but normally should try to handle correctly scope ? maybe sometime
   * sizeof(id) and even if id was for a long time an identifier, maybe
   * a few time, because of the scope it's actually really a type.
   *)
  if (null !ident_to_type)
  then xs
  else
    let bigf = { Visitor_c.default_visitor_c_s with
      Visitor_c.kdefineval_s = (fun (k,bigf) x ->
        match x with
        | Ast_c.DefineExpr e ->
            (match e with
            | (Ast_c.Ident (ident), _), _ii  ->
                let s = Ast_c.str_of_name ident in
                if List.mem s !ident_to_type
                then
                  let t = ident_to_typename ident in
                  Ast_c.DefineType t
                else k x
            | _ -> k x
            )
        | _ -> k x
      );
      Visitor_c.kexpr_s = (fun (k, bigf) x ->
        match x with
        | (Ast_c.SizeOfExpr e, tref), isizeof ->
            let i1 = Common2.tuple_of_list1 isizeof in
            (match e with
            | (Ast_c.ParenExpr e, _), iiparen ->
                (match e with
                | (Ast_c.Ident (ident), _), _ii  ->

                    let s = Ast_c.str_of_name ident in
                    if List.mem s !ident_to_type
                    then
                      let t = ident_to_typename ident in
                      let (i2, i3) = Common2.tuple_of_list2 iiparen in
                      (Ast_c.SizeOfType t, tref), [i1;i2;i3]
                    else  k x
                | _ -> k x
                )
            | _ -> k x
            )
        | _ -> k x
      );
    } in
    xs |> List.map (fun (p, info_item) ->
      Visitor_c.vk_toplevel_s bigf p, info_item
    )


let consistency_checking a  =
  Common.profile_code "C consistencycheck" (fun () -> consistency_checking2 a)



(*****************************************************************************)
(* Error recovery *)
(*****************************************************************************)

let is_define_passed passed =
  let xs = passed |> List.rev |> List.filter TH.is_not_comment in
  if List.length xs >= 2
  then
    (match Common2.head_middle_tail xs with
    | Parser_c.TDefine _, _, Parser_c.TDefEOL _ ->
        true
    | _ -> false
    )
  else begin
    pr2_err "WEIRD: length list of error recovery tokens < 2 ";
    false
  end

let is_defined_passed_bis last_round =
  let xs = last_round |> List.filter TH.is_not_comment in
  match xs with
  | Parser_c.TDefine _::_ -> true
  | _ -> false

(* ---------------------------------------------------------------------- *)


(* todo: do something if find Parser_c.Eof ? *)
let rec find_next_synchro next already_passed =

  (* Maybe because not enough }, because for example an ifdef contains
   * in both branch some opening {, we later eat too much, "on deborde
   * sur la fonction d'apres". So already_passed may be too big and
   * looking for next synchro point starting from next may not be the
   * best. So maybe we can find synchro point inside already_passed
   * instead of looking in next.
   *
   * But take care! must progress. We must not stay in infinite loop!
   * For instance now I have as a error recovery to look for
   * a "start of something", corresponding to start of function,
   * but must go beyond this start otherwise will loop.
   * So look at premier(external_declaration2) in parser.output and
   * pass at least those first tokens.
   *
   * I have chosen to start search for next synchro point after the
   * first { I found, so quite sure we will not loop. *)

  let last_round = List.rev already_passed in
  if is_defined_passed_bis last_round
  then find_next_synchro_define (last_round @ next) []
  else

  let (before, after) =
    last_round |> Common.span (fun tok ->
      match tok with
      (* by looking at TOBrace we are sure that the "start of something"
       * will not arrive too early
       *)
      | Parser_c.TOBrace _ -> false
      | Parser_c.TDefine _ -> false
      | _ -> true
    )
  in
  find_next_synchro_orig (after @ next)  (List.rev before)



and find_next_synchro_define next already_passed =
  match next with
  | [] ->
      pr2_err "ERROR-RECOV: end of file while in recovery mode";
      already_passed, []
  | (Parser_c.TDefEOL i as v)::xs  ->
      pr2_err ("ERROR-RECOV: found sync end of #define, line "^i_to_s(TH.line_of_tok v));
      v::already_passed, xs
  | v::xs ->
      find_next_synchro_define xs (v::already_passed)




and find_next_synchro_orig next already_passed =
  match next with
  | [] ->
      pr2_err "ERROR-RECOV: end of file while in recovery mode";
      already_passed, []

  | (Parser_c.TCBrace i as v)::xs when TH.col_of_tok v =|= 0 ->
      pr2_err ("ERROR-RECOV: found sync '}' at line "^i_to_s (TH.line_of_tok v));

      (match xs with
      | [] -> raise Impossible (* there is a EOF token normally *)

      (* still useful: now parser.mly allow empty ';' so normally no pb *)
      | Parser_c.TPtVirg iptvirg::xs ->
          pr2_err "ERROR-RECOV: found sync bis, eating } and ;";
          (Parser_c.TPtVirg iptvirg)::v::already_passed, xs

      | Parser_c.TIdent x::Parser_c.TPtVirg iptvirg::xs ->
          pr2_err "ERROR-RECOV: found sync bis, eating ident, }, and ;";
          (Parser_c.TPtVirg iptvirg)::(Parser_c.TIdent x)::v::already_passed,
          xs

      | Parser_c.TCommentSpace sp::Parser_c.TIdent x::Parser_c.TPtVirg iptvirg
        ::xs ->
          pr2_err "ERROR-RECOV: found sync bis, eating ident, }, and ;";
          (Parser_c.TCommentSpace sp)::
            (Parser_c.TPtVirg iptvirg)::
            (Parser_c.TIdent x)::
            v::
            already_passed,
          xs

      | Parser_c.TCommentNewline sp::Parser_c.TIdent x::Parser_c.TPtVirg iptvirg
        ::xs ->
          pr2_err "ERROR-RECOV: found sync bis, eating ident, }, and ;";
          (Parser_c.TCommentNewline sp)::
            (Parser_c.TPtVirg iptvirg)::
            (Parser_c.TIdent x)::
            v::
            already_passed,
          xs

      | _ ->
          v::already_passed, xs
      )
  | v::xs when TH.col_of_tok v =|= 0 && TH.is_start_of_something v  ->
      pr2_err ("ERROR-RECOV: found sync col 0 at line "^ i_to_s(TH.line_of_tok v));
      already_passed, v::xs

  | v::xs ->
      find_next_synchro_orig xs (v::already_passed)


(*****************************************************************************)
(* Macro problem recovery *)
(*****************************************************************************)
module TV = Token_views_c

let candidate_macros_in_passed2 passed defs_optional =
  let res = ref [] in
  let res2 = ref [] in

  passed |> List.iter (function
  | Parser_c.TIdent (s,_)
   (* bugfix: may have to undo some infered things *)
  | Parser_c.TMacroIterator (s,_)
  | Parser_c.TypedefIdent (s,_)
    ->
      (match Common2.hfind_option s defs_optional with
      | Some def ->
          if s ==~ Parsing_hacks.regexp_macro
          then
            (* pr2 (spf "candidate: %s" s); *)
            Common.push (s, def) res
          else
            Common.push (s, def) res2
        | None -> ()
        )

  | _ -> ()
  );
  if null !res
  then !res2
  else !res

let candidate_macros_in_passed a b =
  Common.profile_code "MACRO managment" (fun () ->
    candidate_macros_in_passed2 a b)



let find_optional_macro_to_expand2 ~defs toks =

  let defs = Common.hash_of_list defs in

  let toks = toks |> List.map (function

    (* special cases to undo *)
    | Parser_c.TMacroIterator (s, ii) ->
        if Hashtbl.mem defs s
        then Parser_c.TIdent (s, ii)
        else Parser_c.TMacroIterator (s, ii)

    | Parser_c.TypedefIdent (s, ii) ->
        if Hashtbl.mem defs s
        then Parser_c.TIdent (s, ii)
        else Parser_c.TypedefIdent (s, ii)

    | x -> x
  ) in

  let tokens = toks in
  Parsing_hacks.fix_tokens_cpp ~macro_defs:defs tokens

  (* just calling apply_macro_defs and having a specialized version
   * of the code in fix_tokens_cpp is not enough as some work such
   * as the passing of the body of attribute in Parsing_hacks.find_macro_paren
   * will not get the chance to be run on the new expanded tokens.
   * Hence even if it's expensive, it's currently better to
   * just call directly fix_tokens_cpp again here.

  let tokens2 = ref (tokens |> Common.acc_map TV.mk_token_extended) in
  let cleaner = !tokens2 |> Parsing_hacks.filter_cpp_stuff in
  let paren_grouped = TV.mk_parenthised  cleaner in
  Cpp_token_c.apply_macro_defs
    ~msg_apply_known_macro:(fun s -> pr2 (spf "APPLYING: %s" s))
    ~msg_apply_known_macro_hint:(fun s -> pr2 "hint")
    defs paren_grouped;
  (* because the before field is used by apply_macro_defs *)
  tokens2 := TV.rebuild_tokens_extented !tokens2;
  Parsing_hacks.insert_virtual_positions
    (!tokens2 |> Common.acc_map (fun x -> x.TV.tok))
  *)
let find_optional_macro_to_expand ~defs a =
    Common.profile_code "MACRO managment" (fun () ->
      find_optional_macro_to_expand2 ~defs a)



(*****************************************************************************)
(* Include/Define hacks *)
(*****************************************************************************)

(* Sometimes I prefer to generate a single token for a list of things in the
 * lexer so that if I have to passed them, like for passing TInclude then
 * it's easy. Also if I don't do a single token, then I need to
 * parse the rest which may not need special stuff, like detecting
 * end of line which the parser is not really ready for. So for instance
 * could I parse a #include <a/b/c/xxx.h> as 2 or more tokens ? just
 * lex #include ? so then need recognize <a/b/c/xxx.h> as one token ?
 * but this kind of token is valid only after a #include and the
 * lexing and parsing rules are different for such tokens so not that
 * easy to parse such things in parser_c.mly. Hence the following hacks.
 *
 * less?: maybe could get rid of this like I get rid of some of fix_define.
 *)

(* ------------------------------------------------------------------------- *)
(* helpers *)
(* ------------------------------------------------------------------------- *)

(* used to generate new token from existing one *)
let new_info posadd str ii =
  { Ast_c.pinfo =
      Ast_c.OriginTok { (Ast_c.parse_info_of_info ii) with
        Parse_info.charpos = Ast_c.pos_of_info ii + posadd;
        str     = str;
        column = Ast_c.col_of_info ii + posadd;
      };
    (* must generate a new ref each time, otherwise share *)
    cocci_tag = ref Ast_c.emptyAnnot;
    comments_tag = ref Ast_c.emptyComments;
   }


let rec comment_until_defeol xs =
  match xs with
  | [] -> failwith "cant find end of define token TDefEOL"
  | x::xs ->
      (match x with
      | Parser_c.TDefEOL i ->
          Parser_c.TCommentCpp (Token_c.CppDirective, TH.info_of_tok x)
          ::xs
      | _ ->
          let x' =
            (* bugfix: otherwise may lose a TComment token *)
            if TH.is_real_comment x
            then x
            else Parser_c.TCommentCpp (Token_c.CppPassingNormal (*good?*), TH.info_of_tok x)
          in
          x'::comment_until_defeol xs
      )

let drop_until_defeol xs =
  List.tl
    (Common2.drop_until (function Parser_c.TDefEOL _ -> true | _ -> false) xs)



(* ------------------------------------------------------------------------- *)
(* returns a pair (replaced token, list of next tokens) *)
(* ------------------------------------------------------------------------- *)

let tokens_include (info, includes, filename, inifdef) =
  Parser_c.TIncludeStart (Ast_c.rewrap_str includes info, inifdef),
  [Parser_c.TIncludeFilename
      (filename, (new_info (String.length includes) filename info))
  ]

(*****************************************************************************)
(* Parsing default define macros, usually in a standard.h file *)
(*****************************************************************************)

let save_excursion reference f =
  let old = !reference in
  let res = f() in
  reference := old;
  res

let parse_cpp_define_file2 file =
  save_excursion Flag_parsing_c.verbose_lexing (fun () ->
    Flag_parsing_c.verbose_lexing := false;
    let toks = tokens ~profile:false file in
    let toks = Cpp_token_c.fix_tokens_define toks in
    Cpp_token_c.extract_cpp_define toks
  )

let parse_cpp_define_file a =
  Common.profile_code_exclusif "HACK" (fun () -> parse_cpp_define_file2 a)



let (_defs : (string, Cpp_token_c.define_def) Hashtbl.t ref)  =
  ref (Hashtbl.create 101)

let (_defs_builtins : (string, Cpp_token_c.define_def) Hashtbl.t ref)  =
  ref (Hashtbl.create 101)


(* can not be put in parsing_hack, cos then mutually recursive problem as
 * we also want to parse the standard.h file.
 *)
let init_defs std_h =
  if not (Common2.lfile_exists std_h)
  then pr2 ("warning: Can't find default macro file: " ^ std_h)
  else begin
    pr2 ("init_defs: " ^ std_h);
    _defs := Common.hash_of_list (parse_cpp_define_file std_h);
  end

let init_defs_builtins file_h =
  if not (Common2.lfile_exists file_h)
  then pr2 ("warning: Can't find macro file: " ^ file_h)
  else begin
    pr2 ("init_defs_builtins: " ^ file_h);
    _defs_builtins :=
      Common.hash_of_list (parse_cpp_define_file file_h);
  end


(*****************************************************************************)
(* Main entry point *)
(*****************************************************************************)

type info_item =  string * Parser_c.token list

type program2 = toplevel2 list
     and toplevel2 = Ast_c.toplevel * info_item

let program_of_program2 xs =
  xs |> List.map fst

let with_program2 f program2 =
  program2
  |> Common2.unzip
  |> (fun (program, infos) ->
    f program, infos
  )
  |> Common2.uncurry Common2.zip



(* The use of local refs (remaining_tokens, passed_tokens, ...) makes
 * possible error recovery. Indeed, they allow to skip some tokens and
 * still be able to call again the ocamlyacc parser. It is ugly code
 * because we cant modify ocamllex and ocamlyacc. As we want some
 * extended lexing tricks, we have to use such refs.
 *
 * Those refs are now also used for my lalr(k) technique. Indeed They
 * store the futur and previous tokens that were parsed, and so
 * provide enough context information for powerful lex trick.
 *
 * - passed_tokens_last_ckp stores the passed tokens since last
 *   checkpoint. Used for NotParsedCorrectly and also to build the
 *   info_item attached to each program_element.
 * - passed_tokens_clean is used for lookahead, in fact for lookback.
 * - remaining_tokens_clean is used for lookahead. Now remaining_tokens
 *   contain some comments and so would make pattern matching difficult
 *   in lookahead. Hence this variable. We would like also to get rid
 *   of cpp instruction because sometimes a cpp instruction is between
 *   two tokens and makes a pattern matching fail. But lookahead also
 *   transform some cpp instruction (in comment) so can't remove them.
 *
 * So remaining_tokens, passed_tokens_last_ckp contain comment-tokens,
 * whereas passed_tokens_clean and remaining_tokens_clean does not contain
 * comment-tokens.
 *
 * Normally we have:
 * toks = (reverse passed_tok) ++ cur_tok ++ remaining_tokens
 *    after the call to pop2.
 * toks = (reverse passed_tok) ++ remaining_tokens
 *     at the and of the lexer_function call.
 * At the very beginning, cur_tok and remaining_tokens overlap, but not after.
 * At the end of lexer_function call,  cur_tok  overlap  with passed_tok.
 *
 * convention: I use "tr"  for "tokens refs"
 *
 * I now also need this lexing trick because the lexer return comment
 * tokens.
 *)

type tokens_state = {
  mutable rest :         Parser_c.token list;
  mutable rest_clean :   Parser_c.token list;
  mutable current :      Parser_c.token;
  (* it's passed since last "checkpoint", not passed from the beginning *)
  mutable passed :       Parser_c.token list;
  mutable passed_clean : Parser_c.token list;
}

let mk_tokens_state toks =
  {
    rest       = toks;
    rest_clean = (toks |> List.filter TH.is_not_comment);
    current    = (List.hd toks);
    passed = [];
    passed_clean = [];
  }



let clone_tokens_state tr =
  { rest = tr.rest;
    rest_clean = tr.rest_clean;
    current = tr.current;
    passed = tr.passed;
    passed_clean = tr.passed_clean;
  }
let copy_tokens_state ~src ~dst =
  dst.rest <- src.rest;
  dst.rest_clean <- src.rest_clean;
  dst.current <- src.current;
  dst.passed <- src.passed;
  dst.passed_clean <-  src.passed_clean;
  ()

(* todo? agglomerate the x##b ? *)
let rec filter_noise n xs =
  match n, xs with
  | _, [] -> []
  | 0, xs -> xs
  | n, x::xs ->
      (match x with
      | Parser_c.TMacroAttr _ ->
          filter_noise (n-1) xs
      | _ ->
          x::filter_noise (n-1) xs
      )

let clean_for_lookahead xs =
  match xs with
  | [] -> []
  | [x] -> [x]
  | x::xs ->
      x::filter_noise 10 xs



(* Hacked lex. This function use refs passed by parse_print_error_heuristic
 * tr means token refs.
 *)
let rec lexer_function ~pass tr = fun lexbuf ->
  match tr.rest with
  | [] -> pr2_err "ALREADY AT END"; tr.current
  | v::xs ->
    tr.rest <- xs;
    tr.current <- v;

    if !Flag_parsing_c.debug_lexer then Common.pr2_gen v;

    if TH.is_comment v
    then begin
      tr.passed <- v::tr.passed;
      lexer_function ~pass tr lexbuf
    end
    else begin
      let x = List.hd tr.rest_clean  in
      tr.rest_clean <- List.tl tr.rest_clean;
      assert (x =*= v);

      (match v with

      (* fix_define1.
       *
       * Why not in parsing_hacks lookahead and do passing like
       * I do for some ifdef directives ? Because here I also need to
       * generate some tokens sometimes and so I need access to the
       * tr.passed, tr.rest, etc.
       *)
      | Parser_c.TDefine (tok) ->
          if not (LP.current_context () =*= LP.InTopLevel) &&
            (!Flag_parsing_c.cpp_directive_passing || (pass >= 2))
          then begin
            incr Stat.nDefinePassing;
            pr2_once ("CPP-DEFINE: inside function, I treat it as comment");
            let v' = Parser_c.TCommentCpp (Token_c.CppDirective,TH.info_of_tok v)
            in
            tr.passed <- v'::tr.passed;
            tr.rest       <- comment_until_defeol tr.rest;
            tr.rest_clean <- drop_until_defeol tr.rest_clean;
            lexer_function ~pass tr lexbuf
          end
          else begin
            tr.passed <- v::tr.passed;
            tr.passed_clean <- v::tr.passed_clean;
            v
          end

      | Parser_c.TInclude (includes, filename, inifdef, info) ->
          if not (LP.current_context () =*= LP.InTopLevel)  &&
            (!Flag_parsing_c.cpp_directive_passing || (pass >= 2))
          then begin
            incr Stat.nIncludePassing;
            pr2_once ("CPP-INCLUDE: inside function, I treat it as comment");
            let v = Parser_c.TCommentCpp(Token_c.CppDirective, info) in
            tr.passed <- v::tr.passed;
            lexer_function ~pass tr lexbuf
          end
          else begin
            let (v,new_tokens) =
              tokens_include (info, includes, filename, inifdef) in
            let new_tokens_clean =
              new_tokens |> List.filter TH.is_not_comment  in

            tr.passed <- v::tr.passed;
            tr.passed_clean <- v::tr.passed_clean;
            tr.rest <- new_tokens ++ tr.rest;
            tr.rest_clean <- new_tokens_clean ++ tr.rest_clean;
            v
          end

      | _ ->

          (* typedef_fix1 *)
          let v = match v with
            | Parser_c.TIdent (s, ii) ->
                if
                  LP.is_typedef s &&
                    not (!Flag_parsing_c.disable_add_typedef) &&
                    pass =|= 1
                then Parser_c.TypedefIdent (s, ii)
                else Parser_c.TIdent (s, ii)
            | x -> x
          in

          let v = Parsing_hacks.lookahead ~pass
            (clean_for_lookahead (v::tr.rest_clean))
            tr.passed_clean in

          tr.passed <- v::tr.passed;

          (* the lookahead may have changed the status of the token and
           * consider it as a comment, for instance some #include are
           * turned into comments, hence this code. *)
          match v with
          | Parser_c.TCommentCpp _ -> lexer_function ~pass tr lexbuf
          | v ->
              tr.passed_clean <- v::tr.passed_clean;
              v
      )
    end


let max_pass = 4


let get_one_elem ~pass tr (file, filelines) =

  if not (LP.is_enabled_typedef()) && !Flag_parsing_c.debug_typedef
  then pr2_err "TYPEDEF:_handle_typedef=false. Not normal if dont come from exn";

  (* normally have to do that only when come from an exception in which
   * case the dt() may not have been done
   * TODO but if was in scoped scope ? have to let only the last scope
   * so need do a LP.lexer_reset_typedef ();
   *)
  LP.enable_typedef();
  LP._lexer_hint := (LP.default_hint ());
  LP.save_typedef_state();

  tr.passed <- [];

  let lexbuf_fake = Lexing.from_function (fun buf n -> raise Impossible) in

  (try
      (* -------------------------------------------------- *)
      (* Call parser *)
      (* -------------------------------------------------- *)
      Common.profile_code_exclusif "YACC" (fun () ->
        Left (Parser_c.celem (lexer_function ~pass tr) lexbuf_fake)
      )
    with e ->
      LP.restore_typedef_state();

      (* must keep here, before the code that adjusts the tr fields *)
      let line_error = TH.line_of_tok tr.current in

      let passed_before_error = tr.passed in
      let current = tr.current in

      (*  error recovery, go to next synchro point *)
      let (passed', rest') = find_next_synchro tr.rest tr.passed in
      tr.rest <- rest';
      tr.passed <- passed';

      tr.current <- List.hd passed';
      tr.passed_clean <- [];           (* enough ? *)
      (* with error recovery, rest and rest_clean may not be in sync *)
      tr.rest_clean <- (tr.rest |> List.filter TH.is_not_comment);


      let info_of_bads = Common2.map_eff_rev TH.info_of_tok tr.passed in
      Right (info_of_bads,  line_error,
            tr.passed, passed_before_error,
            current, e)
  )




(* note: as now we go in 2 passes, there is first all the error message of
 * the lexer, and then the error of the parser. It is not anymore
 * interwinded.
 *
 * !!!This function use refs, and is not reentrant !!! so take care.
 * It use globals defined in Lexer_parser and also the _defs global
 * in parsing_hack.ml.
 *
 * This function uses internally some semi globals in the
 * tokens_stat record and parsing_stat record.
 *)

let parse_print_error_heuristic2 file =

  let filelines = Common2.cat_array file in
  let stat = Parsing_stat.default_stat file in

  (* -------------------------------------------------- *)
  (* call lexer and get all the tokens *)
  (* -------------------------------------------------- *)
  LP.lexer_reset_typedef();
  Parsing_hacks.ifdef_paren_cnt := 0;

  let toks_orig = tokens file in

  let toks = Cpp_token_c.fix_tokens_define toks_orig in

  let toks = Parsing_hacks.fix_tokens_cpp ~macro_defs:!_defs_builtins toks in

  (* expand macros on demand trick, preparation phase *)
  let macros =
    Common.profile_code "MACRO mgmt prep 1" (fun () ->
      let macros = Hashtbl.copy !_defs in
      (* include also builtins as some macros may generate some builtins too
       * like __decl_spec or __stdcall
       *)
      !_defs_builtins |> Hashtbl.iter (fun s def ->
        Hashtbl.replace macros   s def;
      );
      macros
    )
  in
  Common.profile_code "MACRO mgmt prep 2" (fun () ->
    let local_macros = parse_cpp_define_file file in
    local_macros |> List.iter (fun (s, def) ->
      Hashtbl.replace macros   s def;
    );
  );

  let tr = mk_tokens_state toks in

  let rec loop tr =

    (* todo?: I am not sure that it represents current_line, cos maybe
     * tr.current partipated in the previous parsing phase, so maybe tr.current
     * is not the first token of the next parsing phase. Same with checkpoint2.
     * It would be better to record when we have a } or ; in parser.mly,
     *  cos we know that they are the last symbols of external_declaration2.
     *
     * bugfix: may not be equal to 'file' as after macro expansions we can
     * start to parse a new entity from the body of a macro, for instance
     * when parsing a define_machine() body, cf standard.h
     *)
    let checkpoint = TH.line_of_tok tr.current in
    let checkpoint_file = TH.file_of_tok tr.current in

    (* call the parser *)
    let elem =
      let pass1 =
        Common.profile_code "Parsing: 1st pass" (fun () ->
          get_one_elem ~pass:1 tr (file, filelines)
        ) in
      match pass1 with
      | Left e -> Left e
      | Right (info,line_err, passed, passed_before_error, cur, exn) ->
          if !Flag_parsing_c.disable_multi_pass
          then pass1
          else begin
            Common.profile_code "Parsing: multi pass" (fun () ->

            pr2_err "parsing pass2: try again";
            let toks = List.rev passed ++ tr.rest in
            let new_tr = mk_tokens_state toks in
            copy_tokens_state ~src:new_tr ~dst:tr;
            let passx = get_one_elem ~pass:2 tr (file, filelines) in

            (match passx with
            | Left e -> passx
            | Right (info,line_err,passed,passed_before_error,cur,exn) ->
                let candidates =
                  candidate_macros_in_passed passed macros
                in
                if is_define_passed passed || null candidates
                then passx
                else begin
                  (* todo factorize code *)

                  pr2_err "parsing pass3: try again";
                  let toks = List.rev passed ++ tr.rest in
                  let toks' =
                    find_optional_macro_to_expand ~defs:candidates toks in
                  let new_tr = mk_tokens_state toks' in
                  copy_tokens_state ~src:new_tr ~dst:tr;
                  let passx = get_one_elem ~pass:3 tr (file, filelines) in

                  (match passx with
                  | Left e -> passx
                  | Right (info,line_err,passed,passed_before_error,cur,exn) ->
                      pr2_err "parsing pass4: try again";

                      let candidates =
                        candidate_macros_in_passed passed macros in

                      let toks = List.rev passed ++ tr.rest in
                      let toks' =
                      find_optional_macro_to_expand ~defs:candidates toks in
                      let new_tr = mk_tokens_state toks' in
                      copy_tokens_state ~src:new_tr ~dst:tr;
                      let passx = get_one_elem ~pass:4 tr (file, filelines) in
                      passx
                  )
                 end
            )
            )
          end
    in


    (* again not sure if checkpoint2 corresponds to end of bad region *)
    let checkpoint2 = TH.line_of_tok tr.current in (* <> line_error *)
    let checkpoint2_file = TH.file_of_tok tr.current in

    let diffline =
      if (checkpoint_file =$= checkpoint2_file) && (checkpoint_file =$= file)
      then (checkpoint2 - checkpoint)
      else 0
        (* TODO? so if error come in middle of something ? where the
         * start token was from original file but synchro found in body
         * of macro ? then can have wrong number of lines stat.
         * Maybe simpler just to look at tr.passed and count
         * the lines in the token from the correct file ?
         *)
    in
    let info = mk_info_item file (List.rev tr.passed) in

    (* some stat updates *)
    stat.Stat.commentized <-
      stat.Stat.commentized + count_lines_commentized (snd info);

    let elem =
      match elem with
      | Left e ->
          stat.Stat.correct <- stat.Stat.correct + diffline;
          e
      | Right (info_of_bads, line_error, toks_of_bads,
              _passed_before_error, cur, exn) ->

          let was_define = is_define_passed tr.passed in

          if was_define && !Flag_parsing_c.filter_msg_define_error
          then ()
          else begin
            (match exn with
            (* Lexical is not anymore launched I think *)
            | Lexer_c.Lexical s ->
                pr2 ("lexical error " ^s^ "\n =" ^ error_msg_tok cur)
            | Parsing.Parse_error ->
                pr2 ("parse error \n = " ^ error_msg_tok cur)
            | Semantic_c.Semantic (s, i) ->
                pr2 ("semantic error " ^s^ "\n ="^ error_msg_tok cur)
            | e -> raise e
            );

            let pbline =
              toks_of_bads
              |> Common2.filter (TH.is_same_line_or_close line_error)
              |> Common2.filter TH.is_ident_like
            in
            let error_info =
              (pbline |> List.map TH.str_of_tok), line_error
            in
            stat.Stat.problematic_lines <-
              error_info::stat.Stat.problematic_lines;

            (* bugfix: *)
            if (checkpoint_file =$= checkpoint2_file) &&
                checkpoint_file =$= file
            then print_bad line_error (checkpoint, checkpoint2) filelines
            else pr2 "PB: bad: but on tokens not from original file"
          end;

          if was_define && !Flag_parsing_c.filter_define_error
          then stat.Stat.correct <- stat.Stat.correct + diffline
          else stat.Stat.bad     <- stat.Stat.bad     + diffline;

          Ast_c.NotParsedCorrectly info_of_bads
    in

    (match elem with
    | Ast_c.FinalDef x -> [(Ast_c.FinalDef x, info)]
    | xs -> (xs, info):: loop tr (* recurse *)
    )
  in
  let v = loop tr in
  let v = consistency_checking v in
  (v, stat)


let time_total_parsing a  =
  Common.profile_code "TOTAL" (fun () -> parse_print_error_heuristic2 a)

let parse_print_error_heuristic a  =
  Common.profile_code "C parsing" (fun () -> time_total_parsing a)


(* alias *)
let parse_c_and_cpp a = parse_print_error_heuristic a

(*****************************************************************************)
(* Same but faster cos memoize stuff *)
(*****************************************************************************)
let parse_cache file =
  if not !Flag_parsing_c.use_cache then parse_print_error_heuristic file
  else
  let _ = pr2 "TOFIX" in
  let need_no_changed_files =
    (* should use Sys.argv.(0), would be safer. *)

    [
      (* TOFIX
      Config.path ^ "/parsing_c/c_parser.cma";
      (* we may also depend now on the semantic patch because
         the SP may use macro and so we will disable some of the
         macro expansions from standard.h.
      *)
      !Config.std_h;
      *)
    ]
  in
  let need_no_changed_variables =
    (* could add some of the flags of flag_parsing_c.ml *)
    []
  in
  Common2.cache_computation_robust
    file ".ast_raw"
    (need_no_changed_files, need_no_changed_variables) ".depend_raw"
    (fun () -> parse_print_error_heuristic file)



(*****************************************************************************)
(* Some special cases *)
(*****************************************************************************)

let (cstatement_of_string: string -> Ast_c.statement) = fun s ->
  Common.write_file ("/tmp/__cocci.c") ("void main() { \n" ^ s ^ "\n}");
  let program = parse_c_and_cpp ("/tmp/__cocci.c") |> fst in
  program |> Common.find_some (fun (e,_) ->
    match e with
    | Ast_c.Definition ({Ast_c.f_body = [Ast_c.StmtElem st]},_) -> Some st
    | _ -> None
  )

let (cexpression_of_string: string -> Ast_c.expression) = fun s ->
  Common.write_file ("/tmp/__cocci.c") ("void main() { \n" ^ s ^ ";\n}");
  let program = parse_c_and_cpp ("/tmp/__cocci.c") |> fst in
  program |> Common.find_some (fun (e,_) ->
    match e with
    | Ast_c.Definition ({Ast_c.f_body = compound},_) ->
        (match compound with
        | [Ast_c.StmtElem (Ast_c.ExprStatement (Some e),ii)] -> Some e
        | _ -> None
        )
    | _ -> None
  )
