open Common


type pl =
  | C
  | Cplusplus
  | Java

(* todo detect false C file, look for "Mode: Objective-C++" string in file ?*)
let detect_pl_of_file file =
  let (d,b,e) = Common2.dbe_of_filename file in
  match e with
  | "c" -> C
  (* can also be a c++, use Parser_cplusplus.is_problably_cplusplus_file *)
  | "h" -> C

  | "hpp" -> Cplusplus
  | "hxx" -> Cplusplus

  | "cpp" -> Cplusplus
  | "C" -> Cplusplus
  | "cc" -> Cplusplus
  | "cxx" -> Cplusplus


  | "java" -> Java

  | _ -> failwith ("unrecognize programming language suffix: " ^ e)


let string_of_pl = function
  | C -> "c"
  | Cplusplus -> "c++"
  | Java -> "java"
