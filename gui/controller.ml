open Common

(*****************************************************************************)
(* Basic *)
(*****************************************************************************)

let (_refresh_all_func : (Model.model -> unit) list ref) = 
  ref []
let refresh_all model = 
  begin
    pr2 "refresh";
    !_refresh_all_func +> List.iter (fun f -> f model);
  end

let (_before_quit_all_func : (Model.model -> unit) list ref) = 
  ref []
let before_quit_all model = 
  begin 
    pr2 "quitting";
    !_before_quit_all_func +> List.iter (fun f ->  f model);
  end



(*****************************************************************************)
(* Specific *)
(*****************************************************************************)


let (_refresh_source : (Common.filename option -> Model.model -> unit) ref) = 
  ref (fun m id -> failwith "refresh source controller not set")
let refresh_source optid model =
  model.Model.current_file <- optid;
  !_refresh_source optid model
