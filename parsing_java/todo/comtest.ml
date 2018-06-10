let usage () =
  Printf.eprintf "Usage: %s [-c] file ...\n" Sys.argv.(0);
  Printf.eprintf "Options:\n  -c    print comments only\n";
  exit 1

let errors = ref 0

let error msg =
  incr errors;
  Printf.eprintf "%s: %s\n" (Source.location ()) msg

let print_comment comment =
  let s, n = comment.Source.buffer, comment.Source.pos in
  Printf.printf "[%d]\n%s\n" n s;
  flush stdout

let parse comments_only =
  try
    Source.with_lexbuf
      (fun lexbuf ->
	let result = Parser.goal Lexer.token lexbuf in
	List.iter print_comment result.Syntax.comments;
	if not comments_only then
	  Pretty.print Format.std_formatter result)
  with e -> error (Printexc.to_string e)

let _ =
  let argc = Array.length Sys.argv in
  let cflag, start =
    if argc > 1 && Sys.argv.(1) = "-c" then (true, 2)
    else (false, 1)
  in
  if start = argc then
    usage ();
  for i = start to argc-1 do
    Source.set_file_name Sys.argv.(i);
    parse cflag
  done;
  exit !errors
