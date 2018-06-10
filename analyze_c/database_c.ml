open Common

open Oassoc

open Ast_c

(*****************************************************************************)
(* C info, kind of CIA (C Information Abstractor)  *)
(*****************************************************************************)


(*****************************************************************************)
(* Types *)
(*****************************************************************************)
(* this directory will the contain a later a yacfe_special_dirname directory *)
type project = 
  Project of Common.dirname * string option (* name of project *)

(* ---------------------------------------------------------------------- *)

type id = filepos
 (* primary key, enough ? normally yes, no ambiguity. What if the 
  * entity is coming from an expansion as for __P() macros ? then can not
  * add it ?  TODO!! for the moment I generate a few fake filepos.
  *)
 and filepos = {
  file: filename;
  line: int;
  column: int;
}

(* todo? add a  is_fake_id() ? for expanded macro ast elements ? *)

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


(*****************************************************************************)
(* Database *)
(*****************************************************************************)


type database = {
  project: project; 
  metapath : Common.dirname;

  objects:      (id, Ast_c.toplevel) Oassoc.oassoc;
  rest_objects: (id, Parse_c.info_item) Oassoc.oassoc;

  file_to_ids: (filename, id list) Oassoc.oassoc;

  (* defs *)
  function_def: (string, id list) Oassoc.oassoc;

  (* use *)
  callees_of_f: (id_func_pos, string list) Oassoc.oassoc;
  callers_of_f: (string, id_func_pos list) Oassoc.oassoc; (* reverse idx *)

  close_hook: unit -> unit;
}

let yacfe_special_dirname = "YACFEDB" 

let use_disk = ref true 
let use_transact = ref false


let is_database_dir ~metapath = 
  Sys.file_exists (metapath ^ "/prj.raw")



type error = 
  | ErrorDb of string

exception Error of error
  

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

let (path_of_project: project -> Common.dirname) = function
  (Project (path,_)) -> path

let (normalize_project: project -> project) = function
  (Project (path, nameopt)) -> 
    Project (Common.chop_dirsymbol path, nameopt)


let (metapath_of_database: database -> Common.dirname) = fun db -> 
  db.metapath
let (metapath_of_project: project -> Common.dirname) = function
  (Project (path,_)) -> 
    Filename.concat path yacfe_special_dirname


let (filepos_of_parse_info: Common.parse_info -> filepos) = fun pi -> 
  { 
    file = pi.Common.file;
    line = pi.Common.line;
    column = pi.Common.column;
  }

(*****************************************************************************)
(* Helpers ast *)
(*****************************************************************************)


exception NoII


let rec first_filepos_origin ii = 
  match ii with
  | [] -> raise NoII
  | x::xs -> 
      if Ast_c.is_origintok x 
      then x +> Ast_c.parse_info_of_info +> filepos_of_parse_info
      else 
        first_filepos_origin xs

let rec first_filepos_origin_token toks =
  match toks with
  | [] -> raise NoII
  | x::xs -> 
      (match Token_helpers.pinfo_of_tok x with
      | Ast_c.OriginTok pi -> 
          filepos_of_parse_info  pi
      | _ -> 
          (* /home/pad/linux/arch/powerpc/platforms/40x/ep405.c (2350/24639) *)
          (* old: failwith "token not origin" *)
          first_filepos_origin_token xs
      )


let (id_of_toplevel: Ast_c.toplevel -> filepos) = fun top -> 
  match top with
  | Declaration decl -> 
      (match decl with
      | MacroDecl (s_and_args, ii) -> 
          first_filepos_origin ii 
      | DeclList (vars, ii) ->  
          first_filepos_origin ii 
      )
          
  | Definition (defbis, ii) -> 
      (try 
        first_filepos_origin ii
      with 
       NoII -> 
         let allii = Lib_parsing_c.ii_of_toplevel top in
         first_filepos_origin allii
      )

  | MacroTop (s, xs, ii) -> 
      first_filepos_origin ii 

  | CppTop top -> 
      (match top with
      | Include {i_include = (inc, ii)}  -> 
          first_filepos_origin ii
      | Define ((s,ii), body)  -> 
          first_filepos_origin ii
      | Undef (string,ii) -> 
          first_filepos_origin ii
      | PragmaAndCo (ii) -> 
          first_filepos_origin ii
      )
 
  | IfdefTop (IfdefDirective (kind, ii)) -> 
      first_filepos_origin ii

  | EmptyDef ii -> 
      first_filepos_origin ii 
  | NotParsedCorrectly ii -> 
      first_filepos_origin ii 

  | FinalDef info -> 
      first_filepos_origin [info] 


(*****************************************************************************)
(* Helpers persistency *)
(*****************************************************************************)

let create_dbm metapath dbname = 
  Oassocdbm.create_dbm metapath dbname 

(*****************************************************************************)
(* Locking wrappers *)
(*****************************************************************************)

(* Berkeley DB and especially GDBM don't like when there is a concurrent
 * access to the same database. 
 *)
exception DatabaseAlreadyLocked

let lockfile metapath = Filename.concat metapath "lockfile.lock" 

let acquire_lock metapath = 
  try Common.acquire_file_lock (lockfile metapath)
  with Common.FileAlreadyLocked -> raise DatabaseAlreadyLocked

let release_lock metapath = 
  Common.release_file_lock (lockfile metapath)

(*****************************************************************************)
(* Create/Open/Close *)
(*****************************************************************************)


let open_db ~metapath = 
  let metapath = Common.chop_dirsymbol metapath in

  assert(is_database_dir metapath);
  acquire_lock metapath;
  let prj = Common.read_value (metapath ^ "/prj.raw") in
  (*
    pr2_gen (metapath_of_project prj);
    pr2_gen (metapath);
  *)
  assert (metapath_of_project prj = metapath);

  if !use_disk then begin

    let objects_db, objects_info         = create_dbm metapath "/objects" in
    let rest_objects_db, rest_objects_info  = create_dbm metapath "/rest_objects" in
    let file_to_ids_db, file_to_ids_info  = create_dbm metapath "/file_to_ids" in

    let fdef_db, fdef_info = create_dbm metapath "/function_defs" in
    let callers_db, callers_info = create_dbm metapath "/callers" in
    let callees_db, callees_info = create_dbm metapath "/callees" in

    { 
      metapath = metapath;
      project = prj;
    
      objects = objects_info;
      rest_objects = rest_objects_info;
      file_to_ids = file_to_ids_info;

      function_def = fdef_info;
      callers_of_f = callers_info;
      callees_of_f = callees_info;
      
      close_hook = (fun () -> 

        Dbm.close objects_db;
        Dbm.close rest_objects_db;
        Dbm.close file_to_ids_db;
        Dbm.close fdef_db;
        Dbm.close callers_db;
        Dbm.close callees_db;
      );
    }

  end else 
    { 
      metapath = metapath;
      project = prj;
    
      objects = new Oassoch.oassoch [];
      rest_objects = new Oassoch.oassoch [];
      file_to_ids = new Oassoch.oassoch [];
      
      function_def = new Oassoch.oassoch [];
      callers_of_f = new Oassoch.oassoch [];
      callees_of_f = new Oassoch.oassoch [];
      
      close_hook = Common.id;
    }


(*---------------------------------------------------------------------------*)
let close_db db = 
  db.close_hook ();
  release_lock db.metapath;
  ()


(*---------------------------------------------------------------------------*)
let with_db ~metapath f = 
  let db = open_db metapath in
  Common.unwind_protect (fun () -> 
    f db;
    close_db db;
  ) 
  (fun e -> close_db db)



(*---------------------------------------------------------------------------*)
let create_db prj  = 
  let prj = normalize_project prj in 

  let metapath = metapath_of_project prj in

  if (Sys.file_exists (Filename.concat metapath "notes.txt"))
  then failwith "there is a notes.txt file";

  if not (Common.command2_y_or_no("rm -rf " ^ metapath))
  then failwith "ok we stop";

  Common.command2("mkdir -p " ^ metapath);

  (* create prj file opened later by open_db *)
  Common.write_value prj (metapath ^ "/prj.raw");

  let db = open_db metapath in
  begin
    (* perform some initialization on db ? populate with a few facts ? *)

    db
  end


(*****************************************************************************)
(* Query database *)
(*****************************************************************************)


(*****************************************************************************)
(* Add to database *)
(*****************************************************************************)

let cnt = ref 0 

let add_toplevel2 file (top,(str,toks)) db = 

  let newid = 
    try 
      id_of_toplevel top 
    with NoII -> 
      pr2 ("pb NoII with:");
      pr2 str;
      pr2 ("using info from token then:");
      (try 
          first_filepos_origin_token toks
      with NoII -> 
        pr2 ("pb NoII with tokens too:");
        pr2 (
          toks +> List.map Token_helpers.str_of_tok
               +> Common.join " "
        );
          
        (* if a macro expands to multiple declaration, then have a serie
         * of elements in the ast without connection to the original file.
         * but must still try to generate some fake id for them ?
         *)
        incr cnt;
        { file = file;
          line = -(!cnt);
          column = 0;
        }
      )
  in

  if db.objects#haskey newid
  then begin
    let elem = db.rest_objects#assoc newid in
    pr2_gen (newid, (str, elem));
    failwith "id already in database"
  end;

  db.objects#add2 (newid, top);
  (* TODO add also tokens? *)
  db.rest_objects#add2 (newid, (str,[](*TODO*)));

  newid



let (add_filename_and_ids: (filename * id list) -> database -> unit) = 
 fun (file, ids) db -> 

   db.file_to_ids#add2 (file, ids);
   ()
  

let (add_function_def: (string * id) -> database -> unit) =  
  fun (fstr, fid) db -> 
    db.function_def#apply_with_default fstr 
      (fun old -> fid::old) (fun() -> []) +> ignore

(* also add in reverse index *)
let (add_callees_of_f: (id_func_pos * string list) -> database -> unit) =
 fun (idfpos, fs) db -> 
   let caller = idfpos in 

   db.callees_of_f#add2 (idfpos, fs);

   fs +> List.iter (fun callee -> 
     db.callers_of_f#apply_with_default callee
       (fun old -> Common.insert_set caller old) (fun() -> []) +> ignore;
   );
   ()


(*****************************************************************************)
(* Misc operations *)
(*****************************************************************************)

(*---------------------------------------------------------------------------*)
(* Pruning *)
(*---------------------------------------------------------------------------*)

(*---------------------------------------------------------------------------*)
(* Misc, upgrage database *)
(*---------------------------------------------------------------------------*)

(*****************************************************************************)
(* Error *)
(*****************************************************************************)

let (report_error: error -> string) = fun error -> 
  match error with 
  | ErrorDb s -> "ErrorDb:" ^ s

