open Common

(*****************************************************************************)
(* The model *)
(*****************************************************************************)
type model = { 

  (* --------- *)
  (* the data  *)
  (* --------- *)
  db_path: Common.dirname;

  (* --------- *)
  (* the query *)
  (* --------- *)
  mutable basic_query: string;

  (* easier to use ref than mutable when want write generic code *)
  col1_name: string ref;
  col1: string list ref;

  col2_name: string ref;
  col2: string list ref;

  col3_name: string ref;
  col3: string list ref;

  col4_name: string ref;
  col4: string list ref;

  (* --------- *)
  (* the rest *)
  (* --------- *)
  mutable current_file : Common.filename option;

}


let default_model db_path file = {

  db_path = db_path;

  basic_query = "";

  col1_name = ref "";
  col1 = ref [];
  col2_name = ref "";
  col2 = ref [];
  col3_name = ref "";
  col3 = ref [];
  col4_name = ref "";
  col4 = ref [];

  current_file = file;

}

let init_model dir file = 
  default_model dir file

let close_model model = 
  ()

(*****************************************************************************)
(* Accessors *)
(*****************************************************************************)

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)
