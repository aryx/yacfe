open Common

open Parser_c

(*****************************************************************************)
(* Is_xxx, categories *)
(*****************************************************************************)

let is_space = function
  | TCommentSpace _ -> true
  | _ -> false

let is_comment_or_space = function
  | TComment _ -> true
  | TCommentSpace _ -> true

  | _ -> false
let is_real_comment = is_comment_or_space

let is_just_comment = function
  | TComment _ -> true
  | _ -> false

let is_comment = function
  | TComment _    | TCommentSpace _ 
  | TCommentCpp _ 
  | TCommentMisc _ -> true
  | _ -> false

let is_fake_comment = function
  | TCommentCpp _    | TCommentMisc _ 
      -> true
  | _ -> false

let is_not_comment x = 
  not (is_comment x)





let is_cpp_instruction = function
  | TInclude _ 
  | TDefine _
  | TIfdef _   | TIfdefelse _ | TIfdefelif _ | TEndif _ 
  | TIfdefBool _ | TIfdefMisc _ | TIfdefVersion _
  | TUndef _ 
  | TCppDirectiveOther _
      -> true
  | _ -> false


let is_gcc_token = function
  | Tasm _ 
  | Tinline _ 
  | Tattribute _ 
  | Ttypeof _ 
      -> true
  | _ -> false




let is_opar = function
  | TOPar _ | TOParDefine _ -> true
  | _ -> false

let is_cpar = function
  | TCPar _ | TCParEOL _ -> true
  | _ -> false


let is_obrace = function
  | TOBrace _ | TOBraceDefineInit _ -> true
  | _ -> false

let is_cbrace = function
  | TCBrace _ -> true
  | _ -> false 




let is_eof = function
  | EOF x -> true
  | _ -> false



let is_statement = function
  | Tfor _ | Tdo _ | Tif _ | Twhile _ | Treturn _ 
  | Tbreak _ | Telse _ | Tswitch _ | Tcase _ | Tcontinue _
  | Tgoto _ 
  | TPtVirg _
  | TMacroIterator _
      -> true
  | _ -> false

(* is_start_of_something is used in parse_c for error recovery, to find
 * a synchronisation token.
 * 
 * Would like to put TIdent or TDefine, TIfdef but they can be in the
 * middle of a function, for instance with label:.
 * 
 * Could put Typedefident but fired ? it would work in error recovery
 * on the already_passed tokens, which has been already gone in the
 * Parsing_hacks.lookahead machinery, but it will not work on the
 * "next" tokens. But because the namespace for labels is different
 * from namespace for ident/typedef, we can use the name for a typedef
 * for a label and so dangerous to put Typedefident at true here. 
 * 
 * Can look in parser_c.output to know what can be at toplevel
 * at the very beginning.
 *)

let is_start_of_something = function
  | Tchar _  | Tshort _ | Tint _ | Tdouble _ |  Tfloat _ | Tlong _ 
  | Tunsigned _ | Tsigned _ | Tvoid _ 
  | Tauto _ | Tregister _ | Textern _ | Tstatic _
  | Tconst _ | Tvolatile _
  | Ttypedef _
  | Tstruct _ | Tunion _ | Tenum _ 
    -> true
  | _ -> false



let is_binary_operator = function
  | TOrLog _ | TAndLog _ |  TOr _ |  TXor _ |  TAnd _ 
  | TEqEq _ |  TNotEq _  | TInf _ |  TSup _ |  TInfEq _ |  TSupEq _ 
  | TShl _ | TShr _  
  | TPlus _ |  TMinus _ |  TMul _ |  TDiv _ |  TMod _ 
        -> true
  | _ -> false 

let is_stuff_taking_parenthized = function
  | Tif _ 
  | Twhile _ 
  | Tswitch _
  | Ttypeof _
  | TMacroIterator _
    -> true 
  | _ -> false

(*****************************************************************************)
(* Visitors *)
(*****************************************************************************)

(* Because ocamlyacc force us to do it that way. The ocamlyacc token 
 * cant be a pair of a sum type, it must be directly a sum type.
 *)
let info_of_tok = function
  | TString ((string, isWchar), i) -> i
  | TChar  ((string, isWchar), i) -> i
  | TFloat ((string, floatType), i) -> i

  | TAssign  (assignOp, i) -> i

  | TIdent  (s, i) -> i
  | TypedefIdent  (s, i) -> i

  | TInt  (s, i) -> i

  | TDefine (ii) -> ii 
  | TInclude (includes, filename, inifdef, i1) ->     i1

  | TUndef (s, ii) -> ii
  | TCppDirectiveOther (ii) -> ii

  | TIncludeStart (i1, inifdef) ->     i1
  | TIncludeFilename (s, i1) ->     i1

  | TDefEOL (i1) ->     i1
  | TOParDefine (i1) ->     i1
  | TIdentDefine  (s, i) -> i
  | TCppEscapedNewline (ii) -> ii
  | TDefParamVariadic (s, i1) ->     i1

  | TOBraceDefineInit (i1) ->     i1

  | TUnknown             (i) -> i

  | TMacroAttr             (i) -> i
  | TMacroStmt             (i) -> i
  | TMacroString             (i) -> i
  | TMacroDecl             (s, i) -> i
  | TMacroStructDecl             (s, i) -> i
  | TMacroDeclConst             (i) -> i
  | TMacroIterator             (s,i) -> i
(*  | TMacroTop             (s,i) -> i *)
  | TCParEOL (i1) ->     i1

  | TAction             (i) -> i

  | TComment             (i) -> i
  | TCommentSpace        (i) -> i
  | TCommentCpp          (cppkind, i) -> i
  | TCommentMisc         (i) -> i

  | TIfdef               (i) -> i
  | TIfdefelse           (i) -> i
  | TIfdefelif           (i) -> i
  | TEndif               (i) -> i
  | TIfdefBool           (b, i) -> i
  | TIfdefMisc           (b, i) -> i
  | TIfdefVersion           (b, i) -> i

  | TOPar                (i) -> i
  | TCPar                (i) -> i
  | TOBrace              (i) -> i
  | TCBrace              (i) -> i
  | TOCro                (i) -> i
  | TCCro                (i) -> i
  | TDot                 (i) -> i
  | TComma               (i) -> i
  | TPtrOp               (i) -> i
  | TInc                 (i) -> i
  | TDec                 (i) -> i
  | TEq                  (i) -> i
  | TWhy                 (i) -> i
  | TTilde               (i) -> i
  | TBang                (i) -> i
  | TEllipsis            (i) -> i
  | TDotDot              (i) -> i
  | TPtVirg              (i) -> i
  | TOrLog               (i) -> i
  | TAndLog              (i) -> i
  | TOr                  (i) -> i
  | TXor                 (i) -> i
  | TAnd                 (i) -> i
  | TEqEq                (i) -> i
  | TNotEq               (i) -> i
  | TInf                 (i) -> i
  | TSup                 (i) -> i
  | TInfEq               (i) -> i
  | TSupEq               (i) -> i
  | TShl                 (i) -> i
  | TShr                 (i) -> i
  | TPlus                (i) -> i
  | TMinus               (i) -> i
  | TMul                 (i) -> i
  | TDiv                 (i) -> i
  | TMod                 (i) -> i

  | Tchar                (i) -> i
  | Tshort               (i) -> i
  | Tint                 (i) -> i
  | Tdouble              (i) -> i
  | Tfloat               (i) -> i
  | Tlong                (i) -> i
  | Tunsigned            (i) -> i
  | Tsigned              (i) -> i
  | Tvoid                (i) -> i
  | Tauto                (i) -> i
  | Tregister            (i) -> i
  | Textern              (i) -> i
  | Tstatic              (i) -> i
  | Tconst               (i) -> i
  | Tvolatile            (i) -> i

  | Trestrict            (i) -> i

  | Tstruct              (i) -> i
  | Tenum                (i) -> i
  | Ttypedef             (i) -> i
  | Tunion               (i) -> i
  | Tbreak               (i) -> i
  | Telse                (i) -> i
  | Tswitch              (i) -> i
  | Tcase                (i) -> i
  | Tcontinue            (i) -> i
  | Tfor                 (i) -> i
  | Tdo                  (i) -> i
  | Tif                  (i) -> i
  | Twhile               (i) -> i
  | Treturn              (i) -> i
  | Tgoto                (i) -> i
  | Tdefault             (i) -> i
  | Tsizeof              (i) -> i
  | Tasm                 (i) -> i
  | Tattribute           (i) -> i
  | Tinline              (i) -> i
  | Ttypeof              (i) -> i

  | EOF                  (i) -> i
  



(* used by tokens to complete the parse_info with filename, line, col infos *)
let visitor_info_of_tok f = function
  | TString ((s, isWchar), i)  -> TString ((s, isWchar), f i) 
  | TChar  ((s, isWchar), i)   -> TChar  ((s, isWchar), f i) 
  | TFloat ((s, floatType), i) -> TFloat ((s, floatType), f i) 
  | TAssign  (assignOp, i)     -> TAssign  (assignOp, f i) 

  | TIdent  (s, i)       -> TIdent  (s, f i) 
  | TypedefIdent  (s, i) -> TypedefIdent  (s, f i) 
  | TInt  (s, i)         -> TInt  (s, f i) 

  | TDefine (i1) -> TDefine(f i1) 

  | TUndef (s,i1) -> TUndef(s, f i1) 
  | TCppDirectiveOther (i1) -> TCppDirectiveOther(f i1) 

  | TInclude (includes, filename, inifdef, i1) -> 
      TInclude (includes, filename, inifdef, f i1)

  | TIncludeStart (i1, inifdef) -> TIncludeStart (f i1, inifdef)
  | TIncludeFilename (s, i1) -> TIncludeFilename (s, f i1)

  | TCppEscapedNewline (i1) -> TCppEscapedNewline (f i1)
  | TDefEOL (i1) -> TDefEOL (f i1)
  | TOParDefine (i1) -> TOParDefine (f i1)
  | TIdentDefine  (s, i) -> TIdentDefine (s, f i)

  | TDefParamVariadic (s, i1) -> TDefParamVariadic (s, f i1)

  | TOBraceDefineInit (i1) -> TOBraceDefineInit (f i1)


  | TUnknown             (i) -> TUnknown                (f i)

  | TMacroAttr           (i)   -> TMacroAttr            (f i)
  | TMacroStmt           (i)   -> TMacroStmt            (f i)
  | TMacroString         (i)   -> TMacroString          (f i)
  | TMacroDecl           (s,i) -> TMacroDecl            (s, f i)
  | TMacroStructDecl     (s,i) -> TMacroStructDecl      (s, f i)
  | TMacroDeclConst      (i)   -> TMacroDeclConst       (f i)
  | TMacroIterator       (s,i) -> TMacroIterator        (s,f i)
(*  | TMacroTop          (s,i) -> TMacroTop             (s,f i) *)
  | TCParEOL (i) ->     TCParEOL (f i)


  | TAction               (i) -> TAction             (f i)

  | TComment             (i) -> TComment             (f i) 
  | TCommentSpace        (i) -> TCommentSpace        (f i) 
  | TCommentCpp          (cppkind, i) -> TCommentCpp          (cppkind, f i) 
  | TCommentMisc         (i) -> TCommentMisc         (f i) 
  | TIfdef               (i) -> TIfdef               (f i) 
  | TIfdefelse           (i) -> TIfdefelse           (f i) 
  | TIfdefelif           (i) -> TIfdefelif           (f i) 
  | TEndif               (i) -> TEndif               (f i) 
  | TIfdefBool           (b, i) -> TIfdefBool        (b, f i) 
  | TIfdefMisc           (b, i) -> TIfdefMisc        (b, f i) 
  | TIfdefVersion        (b, i) -> TIfdefVersion     (b, f i) 

  | TOPar                (i) -> TOPar                (f i) 
  | TCPar                (i) -> TCPar                (f i) 
  | TOBrace              (i) -> TOBrace              (f i) 
  | TCBrace              (i) -> TCBrace              (f i) 
  | TOCro                (i) -> TOCro                (f i) 
  | TCCro                (i) -> TCCro                (f i) 
  | TDot                 (i) -> TDot                 (f i) 
  | TComma               (i) -> TComma               (f i) 
  | TPtrOp               (i) -> TPtrOp               (f i) 
  | TInc                 (i) -> TInc                 (f i) 
  | TDec                 (i) -> TDec                 (f i) 
  | TEq                  (i) -> TEq                  (f i) 
  | TWhy                 (i) -> TWhy                 (f i) 
  | TTilde               (i) -> TTilde               (f i) 
  | TBang                (i) -> TBang                (f i) 
  | TEllipsis            (i) -> TEllipsis            (f i) 
  | TDotDot              (i) -> TDotDot              (f i) 
  | TPtVirg              (i) -> TPtVirg              (f i) 
  | TOrLog               (i) -> TOrLog               (f i) 
  | TAndLog              (i) -> TAndLog              (f i) 
  | TOr                  (i) -> TOr                  (f i) 
  | TXor                 (i) -> TXor                 (f i) 
  | TAnd                 (i) -> TAnd                 (f i) 
  | TEqEq                (i) -> TEqEq                (f i) 
  | TNotEq               (i) -> TNotEq               (f i) 
  | TInf                 (i) -> TInf                 (f i) 
  | TSup                 (i) -> TSup                 (f i) 
  | TInfEq               (i) -> TInfEq               (f i) 
  | TSupEq               (i) -> TSupEq               (f i) 
  | TShl                 (i) -> TShl                 (f i) 
  | TShr                 (i) -> TShr                 (f i) 
  | TPlus                (i) -> TPlus                (f i) 
  | TMinus               (i) -> TMinus               (f i) 
  | TMul                 (i) -> TMul                 (f i) 
  | TDiv                 (i) -> TDiv                 (f i) 
  | TMod                 (i) -> TMod                 (f i) 
  | Tchar                (i) -> Tchar                (f i) 
  | Tshort               (i) -> Tshort               (f i) 
  | Tint                 (i) -> Tint                 (f i) 
  | Tdouble              (i) -> Tdouble              (f i) 
  | Tfloat               (i) -> Tfloat               (f i) 
  | Tlong                (i) -> Tlong                (f i) 
  | Tunsigned            (i) -> Tunsigned            (f i) 
  | Tsigned              (i) -> Tsigned              (f i) 
  | Tvoid                (i) -> Tvoid                (f i) 
  | Tauto                (i) -> Tauto                (f i) 
  | Tregister            (i) -> Tregister            (f i) 
  | Textern              (i) -> Textern              (f i) 
  | Tstatic              (i) -> Tstatic              (f i) 
  | Tconst               (i) -> Tconst               (f i) 
  | Tvolatile            (i) -> Tvolatile            (f i) 

  | Trestrict            (i) -> Trestrict            (f i) 

  | Tstruct              (i) -> Tstruct              (f i) 
  | Tenum                (i) -> Tenum                (f i) 
  | Ttypedef             (i) -> Ttypedef             (f i) 
  | Tunion               (i) -> Tunion               (f i) 
  | Tbreak               (i) -> Tbreak               (f i) 
  | Telse                (i) -> Telse                (f i) 
  | Tswitch              (i) -> Tswitch              (f i) 
  | Tcase                (i) -> Tcase                (f i) 
  | Tcontinue            (i) -> Tcontinue            (f i) 
  | Tfor                 (i) -> Tfor                 (f i) 
  | Tdo                  (i) -> Tdo                  (f i) 
  | Tif                  (i) -> Tif                  (f i) 
  | Twhile               (i) -> Twhile               (f i) 
  | Treturn              (i) -> Treturn              (f i) 
  | Tgoto                (i) -> Tgoto                (f i) 
  | Tdefault             (i) -> Tdefault             (f i) 
  | Tsizeof              (i) -> Tsizeof              (f i) 
  | Tasm                 (i) -> Tasm                 (f i) 
  | Tattribute           (i) -> Tattribute           (f i) 
  | Tinline              (i) -> Tinline              (f i) 
  | Ttypeof              (i) -> Ttypeof              (f i) 
  | EOF                  (i) -> EOF                  (f i) 
  

(*****************************************************************************)
(* Accessors *)
(*****************************************************************************)

let linecol_of_tok tok =
  let info = info_of_tok tok in
  Ast_c.line_of_info info, Ast_c.col_of_info info

let col_of_tok x = snd (linecol_of_tok x)
let line_of_tok x = fst (linecol_of_tok x)
let pos_of_tok x =  Ast_c.opos_of_info (info_of_tok x)
let str_of_tok x =  Ast_c.str_of_info (info_of_tok x)
let file_of_tok x = Ast_c.file_of_info (info_of_tok x)
let pinfo_of_tok x = Ast_c.pinfo_of_info (info_of_tok x)

let is_origin x =
  match pinfo_of_tok x with Ast_c.OriginTok _ -> true | _ -> false
let is_expanded x =
  match pinfo_of_tok x with Ast_c.ExpandedTok _ -> true | _ -> false
let is_fake x =
  match pinfo_of_tok x with Ast_c.FakeTok _ -> true | _ -> false
let is_abstract x =
  match pinfo_of_tok x with Ast_c.AbstractLineTok _ -> true | _ -> false
