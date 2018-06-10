let usage () =
  Printf.eprintf "Usage: %s file ...\n" Sys.argv.(0);
  exit 1

let errors = ref 0

let error msg =
  incr errors;
  Printf.eprintf "%s: %s\n" (Source.location ()) msg

let parse () =
  try
    Source.with_lexbuf
      (fun lexbuf ->
	Pretty.print Format.std_formatter (Parser.goal Lexer.token lexbuf))
  with e -> error (Printexc.to_string e)

let _ =
  let argc = Array.length Sys.argv in
  if argc <= 1 then
    usage ();
  for i = 1 to argc-1 do
    Source.set_file_name Sys.argv.(i);
    parse ()
  done;
  exit !errors
