let version = "0.2"

let path = 
  try (Sys.getenv "YACFE_HOME") 
  with Not_found->"/usr/local/share/yacfe"

