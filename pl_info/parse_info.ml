open Common

type t = {
    str: string;
    charpos: int;

    line: int;
    column: int;
    file: filename;
  } 
  (* with sexp *)

let fake_parse_info = { 
  charpos = -1; str = "";
  line = -1; column = -1; file = "";
}

let string_of_parse_info x = 
  spf "%s at %s:%d:%d" x.str x.file x.line x.column
let string_of_parse_info_bis x = 
  spf "%s:%d:%d" x.file x.line x.column

let (info_from_charpos2: int -> filename -> (int * int * string)) = 
 fun charpos filename ->

  (* Currently lexing.ml does not handle the line number position.
   * Even if there is some fields in the lexing structure, they are not 
   * maintained by the lexing engine :( So the following code does not work:
   *   let pos = Lexing.lexeme_end_p lexbuf in 
   *   sprintf "at file %s, line %d, char %d" pos.pos_fname pos.pos_lnum  
   *      (pos.pos_cnum - pos.pos_bol) in 
   * Hence this function to overcome the previous limitation.
   *)
  let chan = open_in filename in
  let linen  = ref 0 in
  let posl   = ref 0 in
  let rec charpos_to_pos_aux last_valid =
    let s =
      try Some (input_line chan)
      with End_of_file when charpos =|= last_valid -> None in
    incr linen;
    match s with
      Some s ->
	let s = s ^ "\n" in
	if (!posl + String.length s > charpos)
	then begin
	  close_in chan;
	  (!linen, charpos - !posl, s)
	end
	else begin
	  posl := !posl + String.length s;
	  charpos_to_pos_aux !posl;
	end
    | None -> (!linen, charpos - !posl, "\n")
  in 
  let res = charpos_to_pos_aux 0 in
  close_in chan;
  res

let info_from_charpos a b = 
  profile_code "Common.info_from_charpos" (fun () -> info_from_charpos2 a b)



let full_charpos_to_pos2 = fun filename ->

  let size = (Common2.filesize filename + 2) in

    let arr = Array.create size  (0,0) in

    let chan = open_in filename in

    let charpos   = ref 0 in
    let line  = ref 0 in

    let rec full_charpos_to_pos_aux () =
     try
       let s = (input_line chan) in
       incr line;

       (* '... +1 do'  cos input_line dont return the trailing \n *)
       for i = 0 to (String.length s - 1) + 1 do 
         arr.(!charpos + i) <- (!line, i);
       done;
       charpos := !charpos + String.length s + 1;
       full_charpos_to_pos_aux();
       
     with End_of_file -> 
       for i = !charpos to Array.length arr - 1 do
         arr.(i) <- (!line, 0);
       done;
       ();
    in 
    begin 
      full_charpos_to_pos_aux ();
      close_in chan;
      arr
    end
let full_charpos_to_pos a =
  profile_code "Common.full_charpos_to_pos" (fun () -> full_charpos_to_pos2 a)
    
let test_charpos file = 
  full_charpos_to_pos file +> dump +> pr2



let complete_parse_info filename table x = 
  { x with 
    file = filename;
    line   = fst (table.(x.charpos));
    column = snd (table.(x.charpos));
  }



let full_charpos_to_pos_large2 = fun filename ->

  let size = (Common2.filesize filename + 2) in

    (* old: let arr = Array.create size  (0,0) in *)
    let arr1 = Bigarray.Array1.create 
      Bigarray.int Bigarray.c_layout size in
    let arr2 = Bigarray.Array1.create 
      Bigarray.int Bigarray.c_layout size in
    Bigarray.Array1.fill arr1 0;
    Bigarray.Array1.fill arr2 0;

    let chan = open_in filename in

    let charpos   = ref 0 in
    let line  = ref 0 in

    let rec full_charpos_to_pos_aux () =
     try
       let s = (input_line chan) in
       incr line;

       (* '... +1 do'  cos input_line dont return the trailing \n *)
       for i = 0 to (String.length s - 1) + 1 do 
         (* old: arr.(!charpos + i) <- (!line, i); *)
         arr1.{!charpos + i} <- (!line);
         arr2.{!charpos + i} <- i;
       done;
       charpos := !charpos + String.length s + 1;
       full_charpos_to_pos_aux();
       
     with End_of_file -> 
       for i = !charpos to (* old: Array.length arr *) 
         Bigarray.Array1.dim arr1 - 1 do
         (* old: arr.(i) <- (!line, 0); *)
         arr1.{i} <- !line;
         arr2.{i} <- 0;
       done;
       ();
    in 
    begin 
      full_charpos_to_pos_aux ();
      close_in chan;
      (fun i -> arr1.{i}, arr2.{i})
    end
let full_charpos_to_pos_large a =
  profile_code "Common.full_charpos_to_pos_large" 
    (fun () -> full_charpos_to_pos_large2 a)


let complete_parse_info_large filename table x = 
  { x with 
    file = filename;
    line   = fst (table (x.charpos));
    column = snd (table (x.charpos));
  }

(*---------------------------------------------------------------------------*)
(* Decalage is here to handle stuff such as cpp which include file and who 
 * can make shift.
 *)
let (error_messagebis: filename -> (string * int) -> int -> string)=
 fun filename (lexeme, lexstart) decalage ->

  let charpos = lexstart      + decalage in
  let tok = lexeme in 
  let (line, pos, linecontent) =  info_from_charpos charpos filename in
  spf "File \"%s\", line %d, column %d,  charpos = %d
    around = '%s', whole content = %s"
    filename line pos charpos tok (Common2.chop linecontent)

let error_message = fun filename (lexeme, lexstart) -> 
  try error_messagebis filename (lexeme, lexstart) 0    
  with
    End_of_file ->
      ("PB in Common.error_message, position " ^ i_to_s lexstart ^
       " given out of file:" ^ filename)



let error_message_short = fun filename (lexeme, lexstart) -> 
  try 
  let charpos = lexstart in
  let (line, pos, linecontent) =  info_from_charpos charpos filename in
  spf "File \"%s\", line %d"  filename line

  with End_of_file -> 
    begin
      ("PB in Common.error_message, position " ^ i_to_s lexstart ^
          " given out of file:" ^ filename);
    end
    

