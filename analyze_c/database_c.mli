open Common 

(* this directory will the contain a later a yacfe_special_dirname directory *)
type project = 
  Project of Common.dirname * string option (* name of project *)


(* ---------------------------------------------------------------------- *)
type id = filepos
 (* primary key, enough ? normally yes, no ambiguity. What if the 
  * entity is coming from an expansion as for __P() macros ? then can not
  * add it ?  TODO!!
  *)
 and filepos = {
  file: filename;
  line: int;
  column: int;
}

type id_elem = 
  | Function of string
  | Variable of string
  | Prototype of string (* special case of Variable *)
  | Macro of string

  (* tags *)
  | Struct of string (* of structUnion *)
  | Enum of string

  | Typedef of string

  | Field of string
  | EnumConstant of string
  | Label of string

type id_elem_file = 
  IdElemFile of id_elem * filename

type id_elem_pos = 
  IdElemPos of id_elem * filepos

type id_string = 
  IdString of string

(* special cases *)
type id_func_file = 
  IdFuncFile of string * filename
type id_func_pos = 
  IdFuncPos of string * filepos


(* ---------------------------------------------------------------------- *)
type database = {
  project: project;
  metapath: Common.dirname;


  objects:      (id, Ast_c.toplevel) Oassoc.oassoc;
  rest_objects: (id, Parse_c.info_item) Oassoc.oassoc;

  file_to_ids: (filename, id list) Oassoc.oassoc;

  (* defs *)
  function_def: (string, id list) Oassoc.oassoc;


  (* uses *)

  (* simple version. 
   * todo: string list should be   id_func_pos * nodei 
   * 
   *)
  callees_of_f: (id_func_pos, string list) Oassoc.oassoc;
  callers_of_f: (string, id_func_pos list) Oassoc.oassoc; (* reverse idx *)

  close_hook: unit -> unit;
}
val yacfe_special_dirname: string


type error = 
  | ErrorDb of string

exception Error of error

val report_error: error -> string

(* ---------------------------------------------------------------------- *)
val path_of_project: project -> Common.dirname
val metapath_of_project: project -> Common.dirname
val metapath_of_database: database -> Common.dirname

exception DatabaseAlreadyLocked


(* @Effect: acquire and release file lock *)
val open_db : metapath:dirname -> database
val close_db: database -> unit
val with_db:  metapath:dirname -> (database -> unit) -> unit

val create_db : project -> database


(* ---------------------------------------------------------------------- *)

(* the filename should not be needed normally, but for some expanded 
 * tokens, I have not enough info so must at least know the original 
 * filename in which the elements should be associated with 
 *)
val add_toplevel2: filename -> Parse_c.toplevel2 -> database -> id

val add_filename_and_ids: (filename * id list) -> database -> unit 

val add_function_def: (string * id) -> database -> unit

(* also add in reverse index *)
val add_callees_of_f: (id_func_pos * string list) -> database -> unit


(* ---------------------------------------------------------------------- *)
(*
type function_id = (Common.filename * string)
type macro_id = (Common.filename * string)

val ast_of_function: unit
val ast_of_macro: unit

val prototypes_of_function: unit
*)

(* ------------------------------------- *)
