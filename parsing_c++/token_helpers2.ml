open Common

open Parser_cplusplus
module Ast_c = Ast_cplusplus

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

let is_just_comment = function
  | TComment _ -> true
  | _ -> false





let is_comment = function
  | TComment _    | TCommentSpace _ 
  | TCommentCpp _ 
  | TCommentMisc _ -> true
  | _ -> false


let is_real_comment = function
  | TComment _    | TCommentSpace _ 
      -> true
  | _ -> false

let is_fake_comment = function
  | TCommentCpp _    | TCommentMisc _ 
      -> true
  | _ -> false

let is_not_comment x = 
  not (is_comment x)


let is_cpp_instruction = function
  | TInclude _ | TDefine _
  | TIfdef _   | TIfdefelse _ | TIfdefelif _
  | TEndif _ 
  | TIfdefBool _ | TIfdefMisc _ | TIfdefVersion _
      -> true
  | _ -> false




let is_opar = function
  | TOPar _ | TOParDefine _ | TOParCplusplusInit _ -> true
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
  (* c++ext: *)
  | Tclass _
  | Tbool _
  | Twchar_t _ 
    -> true
  | _ -> false



let is_binary_operator = function
  | TOrLog _ | TAndLog _ |  TOr _ |  TXor _ |  TAnd _ 
  | TEqEq _ |  TNotEq _  | TInf _ |  TSup _ |  TInfEq _ |  TSupEq _ 
  | TShl _ | TShr _  
  | TPlus _ |  TMinus _ |  TMul _ |  TDiv _ |  TMod _ 
        -> true
  | _ -> false 

let is_binary_operator_except_star = function
  | TOrLog _ | TAndLog _ |  TOr _ |  TXor _   (* | TAnd _ *)
  | TEqEq _ |  TNotEq _  | TInf _ |  TSup _ |  TInfEq _ |  TSupEq _ 
  | TShl _ | TShr _  
  | TPlus _ |  TMinus _ (*|  TMul _*) |  TDiv _ |  TMod _ 
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

let is_static_cast_like = function
  | Tconst_cast _ | Tdynamic_cast _ | Tstatic_cast _ | Treinterpret_cast _ -> 
      true
  | _ -> false

let is_basic_type = function
  | Tchar _  | Tshort _ | Tint _ | Tdouble _ |  Tfloat _ | Tlong _ 
  | Tbool _ | Twchar_t _
        -> true
  (*| Tunsigned _ | Tsigned _ | Tvoid _  *)
  | _ -> false



let is_struct_like_keyword = function
  | (Tstruct _ | Tunion _ | Tenum _) -> true
  (* c++ext: *)
  | (Tclass _) -> true
  | _ -> false

let is_classkey_keyword = function
  | (Tstruct _ | Tunion _ | Tclass _) -> true
  | _ -> false


let is_cplusplus_keyword = function
  | Tclass _
  | Tthis _
 
  | Tnew _
  | Tdelete _
 
  | Ttemplate _
  | Ttypeid _
  | Ttypename _
 
  | Tcatch _
  | Ttry _
  | Tthrow _
 
  | Toperator _
  | Tpublic _
  | Tprivate _
  | Tprotected _

  | Tfriend _
 
  | Tvirtual _
 
  | Tnamespace _
  | Tusing _
 
  | Tbool _
  | Tfalse _
  | Ttrue _
 
  | Twchar_t _
  | Tconst_cast _
  | Tdynamic_cast _
  | Tstatic_cast _
  | Treinterpret_cast  _
  | Texplicit _
  | Tmutable _
 
  | Texport _

  | TColCol  _
      -> true

  | _ -> false


let is_really_cplusplus_keyword = function
  | Tconst_cast _
  | Tdynamic_cast _
  | Tstatic_cast _
  | Treinterpret_cast  _

  | TColCol  _
      -> true

  | _ -> false

(* some false positive on some C file like sqlite3.c *)
let is_maybenot_cplusplus_keyword = function
  | Tpublic _
  | Tprivate _
  | Tprotected _
  | Ttemplate _
  | Tnew _
  | Ttypename _
  | Tnamespace _
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

  (*cppext:*) 
  | TDefine (ii) -> ii 
  | TInclude (includes, filename, inifdef, i1) ->     i1

  | TIncludeStart (i1, inifdef) ->     i1
  | TIncludeFilename (s, i1) ->     i1

  | TDefEOL (i1) ->     i1
  | TOParDefine (i1) ->     i1
  | TIdentDefine  (s, i) -> i
  | TCppEscapedNewline (ii) -> ii
  | TDefParamVariadic (s, i1) ->     i1

  | TOBraceDefineInit (i1) ->     i1

  | TUnknown             (i) -> i

  | TMacroStmt             (i) -> i
  | TMacroString             (i) -> i
  | TMacroDecl             (s, i) -> i
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
  | TOParCplusplusInit                (i) -> i
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
  | TCol              (i) -> i
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

  | Trestrict (i) -> i

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

  (* gccext: *)
  | Tasm                 (i) -> i
  | Tattribute           (i) -> i
  | Tinline              (i) -> i
  | Ttypeof              (i) -> i

  (* c++ext: *)
  | Tclass (i) -> i
  | Tthis (i) -> i

  | Tnew (i) -> i
  | Tdelete (i) -> i

  | Ttemplate (i) -> i
  | Ttypeid (i) -> i
  | Ttypename (i) -> i

  | Tcatch (i) -> i
  | Ttry (i) -> i
  | Tthrow (i) -> i

  | Toperator (i) -> i

  | Tpublic (i) -> i
  | Tprivate (i) -> i
  | Tprotected (i) -> i
  | Tfriend (i) -> i

  | Tvirtual (i) -> i

  | Tnamespace (i) -> i
  | Tusing (i) -> i

  | Tbool (i) -> i
  | Ttrue (i) -> i
  | Tfalse (i) -> i

  | Twchar_t (i) -> i

  | Tconst_cast (i) -> i
  | Tdynamic_cast (i) -> i
  | Tstatic_cast (i) -> i
  | Treinterpret_cast (i) -> i

  | Texplicit (i) -> i
  | Tmutable (i) -> i
  | Texport (i) -> i

  | TColCol (i) -> i
  | TColCol2 (i) -> i

  | TPtrOpStar (i) -> i
  | TDotStar(i) -> i

  | Tclassname  (s, i) -> i
  | Tclassname2  (s, i) -> i
  | Ttemplatename  (s, i) -> i
  | Tconstructorname  (s, i) -> i
  | TypedefIdent2  (s, i) -> i
  | TtemplatenameQ  (s, i) -> i
  | TtemplatenameQ2  (s, i) -> i

  | TInf2                 (i) -> i
  | TSup2                 (i) -> i

  | TOCro2                 (i) -> i
  | TCCro2                 (i) -> i

  | TIntZeroVirtual        (i) -> i

  | Tchar2 (i) -> i
  | Tint2  (i) -> i
  | Tfloat2 (i) -> i
  | Tdouble2  (i) -> i
  | Twchar_t2 (i) -> i

  | Tshort2  (i) -> i
  | Tlong2   (i) -> i
  | Tbool2  (i) -> i
      
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

  (* cppext: *)
  | TDefine (i1) -> TDefine(f i1) 

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

  | TMacroStmt           (i)   -> TMacroStmt            (f i)
  | TMacroString         (i)   -> TMacroString          (f i)
  | TMacroDecl           (s,i) -> TMacroDecl            (s, f i)
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
  | TOParCplusplusInit                (i) -> TOParCplusplusInit     (f i) 
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
  | TCol              (i) -> TCol              (f i) 
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


  | Tclass (i) -> Tclass (f i)
  | Tthis (i) -> Tthis (f i)

  | Tnew (i) -> Tnew (f i)
  | Tdelete (i) -> Tdelete (f i)

  | Ttemplate (i) -> Ttemplate (f i)
  | Ttypeid (i) -> Ttypeid (f i)
  | Ttypename (i) -> Ttypename (f i)

  | Tcatch (i) -> Tcatch (f i)
  | Ttry (i) -> Ttry (f i)
  | Tthrow (i) -> Tthrow (f i)

  | Toperator (i) -> Toperator (f i)

  | Tpublic (i) -> Tpublic (f i)
  | Tprivate (i) -> Tprivate (f i)
  | Tprotected (i) -> Tprotected (f i)
  | Tfriend (i) -> Tfriend (f i)

  | Tvirtual (i) -> Tvirtual (f i)

  | Tnamespace (i) -> Tnamespace (f i)
  | Tusing (i) -> Tusing (f i)

  | Tbool (i) -> Tbool (f i)
  | Ttrue (i) -> Ttrue (f i)
  | Tfalse (i) -> Tfalse (f i)

  | Twchar_t (i) -> Twchar_t (f i)

  | Tconst_cast (i) -> Tconst_cast (f i)
  | Tdynamic_cast (i) -> Tdynamic_cast (f i)
  | Tstatic_cast (i) -> Tstatic_cast (f i)
  | Treinterpret_cast (i) -> Treinterpret_cast (f i)

  | Texplicit (i) -> Texplicit (f i)
  | Tmutable (i) -> Tmutable (f i)

  | Texport (i) -> Texport (f i)



  | TColCol (i) -> TColCol (f i)
  | TColCol2 (i) -> TColCol2 (f i)

  | TPtrOpStar (i) -> TPtrOpStar (f i)
  | TDotStar(i) -> TDotStar (f i)


  | Tclassname  (s, i) -> Tclassname  (s, f i) 
  | Tclassname2  (s, i) -> Tclassname2  (s, f i) 
  | Ttemplatename  (s, i) -> Ttemplatename  (s, f i) 
  | Tconstructorname  (s, i) -> Tconstructorname  (s, f i) 
  | TypedefIdent2  (s, i) -> TypedefIdent2  (s, f i) 

  | TtemplatenameQ  (s, i) -> TtemplatenameQ  (s, f i) 
  | TtemplatenameQ2  (s, i) -> TtemplatenameQ2  (s, f i) 

  | TInf2                 (i) -> TInf2                 (f i) 
  | TSup2                 (i) -> TSup2                 (f i) 

  | TOCro2                 (i) -> TOCro2                 (f i) 
  | TCCro2                 (i) -> TCCro2                 (f i) 


  | TIntZeroVirtual (i) -> TIntZeroVirtual (f i)

  | Tchar2                 (i) -> Tchar2                 (f i) 
  | Tint2                 (i) -> Tint2                 (f i) 
  | Tfloat2                 (i) -> Tfloat2                 (f i) 
  | Tdouble2                 (i) -> Tdouble2                 (f i) 
  | Twchar_t2                 (i) -> Twchar_t2                 (f i) 

  | Tshort2  (i) -> Tshort2 (f i)
  | Tlong2   (i) -> Tlong2 (f i)
  | Tbool2  (i) -> Tbool2 (f i)


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
