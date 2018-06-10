open Common 

let config_path = "/home/pad/c-yacfe"

(*
time ./yacfe.opt -profile -env_file config/envos/empty.h -macro_file config/macros/macros_linux.h -I /home/pad/linux/include   -test_build_db /home/pad/linux/
time ./yacfe.opt -profile -macro_file config/macros/macros_freebsd.h -I /home/pad/software-os-src2/freebsd  -test_build_db /home/pad/software-os-src2/freebsd/
time ./yacfe.opt -profile -macro_file config/macros/macros_opensolaris.h -I /home/pad/software-os-src2/opensolaris/common/  -test_build_db /home/pad/software-os-src2/opensolaris/ 
time ./yacfe.opt -profile -macro_file config/macros/macros_freebsd.h -I /home/pad/software-os-src2/netbsd/  -test_build_db /home/pad/software-os-src2/netbsd/
*)

let default_hook = (fun (files: filename list) -> files)
let filter_files_hook = ref default_hook

let default_depth_limit_cpp = ref 3

let max_phase = ref Database_c_build.max_phase

let cmdline_flags_options () =
  [
    "-max_phase",  Arg.Set_int max_phase, 
    " <int> guess what";
  ]

(* ------------------------------------------------------------------------- *)
let all_cfgs = [
  "template", "/home/pad/software-src/???", "", 
  (fun () -> ());

  "database", "/home/pad/c-yacfe/tests-components/database", "standard.h", 
  (fun () -> 
    ()
  );

  "database2", "/home/pad/c-yacfe/tests-components/database2", "standard.h", 
  (fun () -> 
    ()
  );


  "linux", "/home/pad/linux/", "macros_linux.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 200;
    Common.push2 "/home/pad/linux/include" Flag_parsing_c.cpp_i_opts;

    Cpp_ast_c.threshold_cache_nb_files := 400;
    default_depth_limit_cpp := 2;

    filter_files_hook := (fun files -> 
      files +> List.filter (fun s -> 
        (* pb of Stack_overflow in linux/scripts/mod/file2alias.c *)
        (*s =~ ".*mod/.*"*)
        (*s =~ ".*pc110pad.*"*)
        true
      )
    );
  );

  "linuxsmall", "/home/pad/linux/", "macros_linux.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 200;
    Common.push2 "/home/pad/linux/include" Flag_parsing_c.cpp_i_opts;

    Cpp_ast_c.threshold_cache_nb_files := 400;
    default_depth_limit_cpp := 2;

    filter_files_hook := (fun files -> 
      files +> List.filter (fun s -> 
        not (s =~ ".*/linux/arch/.*" || s =~ ".*/linux/drivers/.*")
        (*s =~ ".*pc110pad.*"*)
      )
    );
  );

  "linuxbis", "/home/pad/software-os-src/linux/", "macros_linux.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 200;
    Common.push2 "/home/pad/software-os-src/linux/include" Flag_parsing_c.cpp_i_opts;

    filter_files_hook := (fun files -> 
      files +> List.filter (fun s -> 
        (* pb of Stack_overflow in linux/scripts/mod/file2alias.c *)
        s =~ ".*mod/.*"
      )
    );
  );

  "linux-next", "/home/pad/linux-next/", "macros_linux.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 200;
    Common.push2 "/home/pad/linux-next/linux/include" Flag_parsing_c.cpp_i_opts;

    filter_files_hook := (fun files -> 
      files +> List.filter (fun s -> 
        (* pb of Stack_overflow in linux/scripts/mod/file2alias.c *)
        s =~ ".*mod/.*"
      )
    );
  );


  (* only kernel *)
  "freebsd", "/home/pad/software-os-src2/freebsd", "macros_freebsd.h", 
  (fun () -> 
    Cpp_ast_c.threshold_cache_nb_files := 200;
    Common.push2 "/home/pad/software-os-src2/freebsd" Flag_parsing_c.cpp_i_opts;
    ()
  );

  (* only kernel *)
  "opensolaris", "/home/pad/software-os-src2/opensolaris", "macros_opensolaris.h", 
  (fun () -> 
    Cpp_ast_c.threshold_cache_nb_files := 200;
    Common.push2 "/home/pad/software-os-src2/opensolaris/common" Flag_parsing_c.cpp_i_opts;
    ()
  );
  (* only kernel *)
  "netbsd", "/home/pad/software-os-src2/netbsd", "macros_freebsd.h", 
  (fun () -> 

    Cpp_ast_c.threshold_cache_nb_files := 200;
    Common.push2 "/home/pad/software-os-src2/netbsd" Flag_parsing_c.cpp_i_opts;
    ()
  );


  "sparse", "/home/pad/software-src/devel/sparse-git", "macros_sparse.h", 
  (fun () -> 
    default_depth_limit_cpp := 3;
    Parse_cplusplus.threshold_cplusplus := 100;
  );
  "git", "/home/pad/software-src/devel/git-git", "macros_git.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 100;
  );

  (* good parsing score: *)
  "pidgin", "/home/pad/software-src/desktop/communication/pidgin-2.5.1", "macros_pidgin.h", 
  (fun () -> 
    default_depth_limit_cpp := 5;
    ()
  );
  "openssh", "/home/pad/software-src/security/openssh-4.7p1", "macros_openssh.h",
  (fun () -> 
    default_depth_limit_cpp := 5;

    (* need /usr/include/openssl/ *)
    Common.push2 "/usr/include" Flag_parsing_c.cpp_i_opts;
    Common.push2 "/usr/include/gtk-2.0" Flag_parsing_c.cpp_i_opts;

    ()
  );
  "doom", "/home/pad/software-src/games/linuxdoom-1.10", "", 
  (fun () -> 
    (* go from 62% to 98% good field typing with 5 *)
    default_depth_limit_cpp := 2;
    ()
  );


  "gnuchess", "/home/pad/software-src/games/gnuchess-5.07", "", 
  (fun () -> 
    ()
  );
  "gnugo", "/home/pad/software-src/games/gnugo-3.0.0", "", 
  (fun () -> 
    ()
  );
  "apache", "/home/pad/software-src/system/httpd-2.2.6", "macros_apache.h", 
  (fun () -> ());


]

let all_cfgs_assoc = all_cfgs +> List.map (fun (s, path, macro, hook) -> 
  s, (path, macro, hook)
)

let cfg s = Common.assoc_with_err_msg s all_cfgs_assoc


(* ------------------------------------------------------------------------- *)
let soft_of_str soft_str = 
  match soft_str with
  | "all" -> 
      [cfg "linux"; cfg "freebsd"; cfg "opensolaris"; cfg "netbsd"]
  | "easy" -> [cfg "sparse"; cfg "git"; 
               cfg "doom"; cfg "gnuchess"; cfg "gnugo";
               ]
  | "medium" -> [cfg "openssh"; cfg "pidgin";]

  | "test" -> [cfg "sparse"]

  | s -> failwith ("unrecognized softset: " ^ s)

(* ------------------------------------------------------------------------- *)
let stat_cfg cfg = 
  let (path, macro, hook) = cfg in
  let dbpath = Filename.concat path Database_c.yacfe_special_dirname in
  
  Database_c.with_db ~metapath:dbpath (fun db -> 
    Database_c_statistics.typing_stat_db db;
    Database_c_statistics.parsing_stat_db db;
    Database_c_statistics.callgraph_stat_db db;
(*   
*)
  );
  ()

let build_cfg cfg = 
  let (dir, macro, hook) = cfg in

  filter_files_hook := default_hook;

  Parse_c.init_defs 
    (Filename.concat !Flag_parsing_c.path ("config/macros/" ^ macro));

  hook();

  Cpp_ast_c.show_cpp_i_opts !Flag_parsing_c.cpp_i_opts;
  Cpp_ast_c.show_cpp_d_opts !Flag_parsing_c.cpp_d_opts;

  Flag_parsing_c.check_annotater := false;

  let dir = Common.relative_to_absolute dir in
  let prj = Database_c.Project (dir, None) in
  let prj = Database_c.normalize_project prj in 

  let db = 
    Database_c_build.create_db
      ~default_depth_limit_cpp:!default_depth_limit_cpp
      ~phase:!max_phase
      ~filter_files_hook:!filter_files_hook
      prj 
  in
  Database_c.close_db db;
  ()


(* ------------------------------------------------------------------------- *)
let stat_os_src os =
  stat_cfg (cfg os)

let build_db_os_src os = 
  build_cfg (cfg os)



(* ------------------------------------------------------------------------- *)
(* 73 min in total for "all" 4 os. cf tests_score.org *)
let stat_soft_src soft = 
  let cfgs = soft_of_str soft in
  cfgs +> List.iter stat_cfg

let build_db_soft_src soft = 
  Common._batch_mode := true;
  let cfgs = soft_of_str soft in
  cfgs +> List.iter build_cfg

(* ------------------------------------------------------------------------- *)
let extra_actions () = [

    "-build_db_src", " <project>",
  Common.mk_action_1_arg build_db_os_src;
    "-build_db_soft", " <soft>",
  Common.mk_action_1_arg build_db_soft_src;

    "-stat_db_src", " <project>",
  Common.mk_action_1_arg stat_os_src;
    "-stat_db_soft", " <soft>",
  Common.mk_action_1_arg stat_soft_src;

]

