(*
maybe when fixed those code, can simplify lexer_c.mll or ast_c.ml or
parser_c.mly or parsing_hack.ml ? Or maybe just add comment in those
file saying that those ugly code is also detected by cpp-lint or k-lint

check that no '\' in normal code

*)

(*
  (* only in cpp directives normally *)
  | "\\" '\n' { TCppEscapedNewline (tokinfo lexbuf) }
*)


(*
  (* '0'+ because sometimes it is a #if 000 *)
  | "#" [' ' '\t']* "if" [' ' '\t']* '0'+           (* [^'\n']*  '\n' *)
*)

(*
  (* can have some ifdef 0  hence the letter|digit even at beginning of word *)
  | "#" [' ''\t']* "ifdef"  [' ''\t']+ (letter|digit) ((letter|digit)* ) [' ''\t']*  
*)


(*
  (* bugfix: can have #endif LINUX  but at the same time if I eat everything
   * until next line, I may miss some TComment which for some tools
   * are important such as aComment 
   *)
  | "#" [' ' '\t']* "endif" (*[^'\n']* '\n'*) { 
      TEndif     (tokinfo lexbuf) 
*)

(*
  (* there is a file in 2.6 that have this *)
  | "##" [' ' '\t']* "else" [' ' '\t' '\n']  { TIfdefelse (tokinfo lexbuf) }
*)


(*
 | Tdo statement Twhile TOPar TInt TCPar 
     {
       if fst $5 <> "0" 
       then pr2 "WIERD: in macro and have not a while(0)";
       DefineDoWhileZero ($2,  [$1;$3;$4;snd $5;$6])
     }

*)

(*
 param_define:
 ...
 /*(* they reuse keywords :(  *)*/
 | Tregister            { "register", [$1] }
*)
 


(*
make ArgAction better, easier to parse. Make the idiom
a standard.

ifdef not closed



ugly ifdef


not standard macro idiom
(kind of repeat what astec did)



detect bad indentation :)
(can also detect some bad indentation for comment via comment_annotater if
look for place:function_misc, place:unknown, etc)

*)
