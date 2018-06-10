open Lexing

let usage () =
  Printf.eprintf "Usage: %s file ...\n" Sys.argv.(0);
  exit 1

let _ =
  let argc = Array.length Sys.argv in
  if argc <= 1 then
    usage ();
  for i = 1 to argc-1 do
    Source.set_file_name Sys.argv.(i);
    parse ()
  done
