open Common

type ppmethod = PPnormal | PPviastr

(* program -> output filename (often "/tmp/output.c") -> unit *) 
val pp_program : 
  (Parse_cplusplus.toplevel2 * ppmethod) list -> filename -> unit

