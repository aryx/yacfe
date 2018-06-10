open Common

(*****************************************************************************)
(* Purpose *)
(*****************************************************************************)

(* This module handle the IO, the special name of info files. 
 * the pure algorithmic stuff is in parsing_c/
 *)

(*****************************************************************************)
(* Flags *)
(*****************************************************************************)

(* In addition to flags that can be tweaked via -xxx options (cf the
 * full list of options in the "the options" section below), this 
 * program also depends on the external file data/standard.h.
 *)

(* action mode *)
let action = ref ""

let config_path = "/home/pad/c-yacfe"

let no_macro_file = ref false

(*****************************************************************************)
(* Some  debugging functions *)
(*****************************************************************************)

(*****************************************************************************)
(* Helpers *)
(*****************************************************************************)

let detect_pl_of_file_with_cplusplus_header_addon file = 
    let (d,b,e) = Common.dbe_of_filename file in
    if e = "h" && Parse_cplusplus.is_problably_cplusplus_file file
    then begin
      pr2 ("MISC: c++ .h file, using c++ parser not c parser:" ^ file);
      Programming_language.Cplusplus
    end
    else Programming_language.detect_pl_of_file file


let parse_and_comments_of_file file = 
  match detect_pl_of_file_with_cplusplus_header_addon file with
  | Programming_language.C -> 
      let (program2, parsing_stat) = 
        Parse_c.parse_c_and_cpp file in

      let program = Parse_c.program_of_program2 program2 in

      let _estat = Statistics_c.statistics_of_program program in

      program2 +> List.iter (fun (ast, (s, toks)) -> 
        Parse_c.print_commentized toks
      );
      
      let parsing_stat = 
        Language_helper.conv_c_parsing_stat parsing_stat in

(*      
      let (comments_packed, unpacked_info_comments, 
        (comment_stat, entities_stat)) = 
        Comments_c_extraction.comments_of_program 
          ~do_packing:(!use_c_comment_packing)
          program in
      comments_packed, unpacked_info_comments,
      (parsing_stat, comment_stat, entities_stat)
*)
      parsing_stat
  | Programming_language.Cplusplus -> 
      
      let (program, parsing_stat) = 
        Parse_cplusplus.parse_c_and_cpp file in
      
      let parsing_stat = 
        Language_helper.conv_cplusplus_parsing_stat parsing_stat in
(*      
      let (comments_packed, unpacked_info_comments, 
          (comment_stat, entities_stat)) = 
        Comments_cplusplus_extraction.comments_of_program 
          ~do_packing:true
          program in
      comments_packed, unpacked_info_comments, 
      (parsing_stat, comment_stat, entities_stat)
*)
      parsing_stat

  | Programming_language.Java -> 
      let (program, parsing_stat) = 
        Parse_java.parse_java file in
      
      let parsing_stat = 
        Language_helper.conv_java_parsing_stat parsing_stat in
(*      
      let (comments_packed, unpacked_info_comments, 
          (comment_stat, entities_stat)) = 
        Comments_java_extraction.comments_of_program program in
      comments_packed, unpacked_info_comments,
      (parsing_stat, comment_stat, entities_stat)
*)
      parsing_stat


(*****************************************************************************)
(* Extra actions *)
(*****************************************************************************)

let score_path = "/home/pad/c-yacfe/tmp"

let parse_one_file (file, i, nbfiles) = 
  pr2 (spf "PARSING: %s (%d/%d)" file i nbfiles);

  let (stat) = 
    parse_and_comments_of_file file
  in
  file, stat


let parse_all xs =

  let dirname_opt = 
    match xs with
    | [x] when is_directory x -> Some x
    | xs -> 
        Some (xs +> Common.join "" +> md5sum_of_string)
  in

  (*
  Flag_parsing_c.debug_typedef := true;
  *)
  Flag_parsing_c.debug_cpp := true;


  Flag_parsing_c.verbose_parsing := true;

  (*
  Flag_parsing_c.filter_classic_passed := true;

  Flag_parsing_c.filter_msg := false;
  Flag_parsing_cplusplus.filter_msg := false;
  *)

  (* sure ? *)
  Flag_parsing_c.filter_define_error := false;
  Flag_parsing_cplusplus.filter_define_error := false;


  let newscore  = Common.empty_score () in
  let parsing_stat_list = ref [] in


  let biglist = (fun () -> 

    let files = 
      if (xs +> List.for_all Common.is_directory)
      then
        let ext = "[ch]" in
        let ext2 = "java" in
        let ext3 = ".*\\.\\(cpp\\|cc\\|C\\|cxx\\|hpp\\|hxx\\)$" in
        
        let files1 = Common.files_of_dir_or_files ext (xs) in
        let files2 = Common.files_of_dir_or_files ext2 (xs) in
        let files3 = Common.files_of_dir_or_files_no_vcs_post_filter ext3 xs in
        let files = files3 ++ files2 ++ files1 in
        files
      else xs
    in
    let nbfiles = List.length files in
    Common.check_stack_nbfiles nbfiles; 

    files +> Common.index_list +> List.map (fun (i,j) -> (i,j,nbfiles))
  )
  in
  let map_ex = parse_one_file in

  let reduce_ex = (fun xxs -> 
    let stats_parse = xxs in

    stats_parse +> List.iter (fun (file, stat) -> 
      let s = 
        sprintf "bad = %d, timeout = %B" 
          stat.Statistics_parsing.bad stat.Statistics_parsing.have_timeout
      in
      
      Common.push2 stat  parsing_stat_list;

      if stat.Statistics_parsing.bad = 0 && 
        not stat.Statistics_parsing.have_timeout
      then Hashtbl.add newscore file (Common.Ok)
      else Hashtbl.add newscore file (Common.Pb s)
    );

 
    dirname_opt +> Common.do_option (fun dirname -> 
      pr2 "--------------------------------";
      pr2 "regression testing  information";
      pr2 "--------------------------------";
      let str = Str.global_replace (Str.regexp "/") "__" dirname in
      let def = if !Flag_parsing_c.filter_define_error then "_def_" else "" in
      let ext = "_all_" in
      Common.regression_testing newscore 
        (Filename.concat score_path
            ("score_parsing__" ^str ^ def ^ ext ^ ".marshalled"))
    );
    
    pr2_xxxxxxxxxxxxxxxxx();
    Parsing_stat.print_stat_numbers ();
    Statistics_parsing.print_parsing_stat_list !parsing_stat_list;
    

    !parsing_stat_list, newscore
  ) in
  (* will call either map_ex for worker or reduce_ex for server *)
  biglist +> Distribution.mpi_main2 ~debug_mpi:true map_ex reduce_ex



(* ------------------------------------------------------------------------- *)
(* pair of directory and standard.h file and before advice *) 

let all_cfgs = ref []

let cfg_template = 
  "/home/pad/software-src/???", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_template", cfg_template) all_cfgs 

(* if add a new soft, then parse it, get its percentage, and then 
 * add its cfg in one of the good_xxx or bad_xxx list below.
 *)


let cfg_linux = 
  "/home/pad/software-os-src/linux", "macros_linux.h", 
  (fun () -> 
     Parse_cplusplus.threshold_cplusplus := 100;
  )
let _ = Common.push2 ("cfg_linux", cfg_linux) all_cfgs
let cfg_mozilla = 
  "/home/pad/software-os-src/firefox", "macros_mozilla.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 2;
    )
let _ = Common.push2 ("cfg_firefox", cfg_mozilla) all_cfgs
let cfg_mozilla2 = 
  "/home/pad/software-src/web/mozilla", "macros_mozilla.h", 
  (fun () -> 
         Parse_cplusplus.threshold_cplusplus := 1;
  )
let _ = Common.push2 ("cfg_firefox2", cfg_mozilla2) all_cfgs
let cfg_mysql = 
  "/home/pad/software-os-src/mysql", "macros_mysql.h", 
  (fun () -> 
         Parse_cplusplus.threshold_cplusplus := 1;
  )
let _ = Common.push2 ("cfg_mysql", cfg_mysql) all_cfgs

let cfg_qemu =
  "/home/pad/software-src/hardware/qemu-svn", "macros_qemu.h", 
  (fun () -> 
         Parse_cplusplus.threshold_cplusplus := 100;

  )
let _ = Common.push2 ("cfg_qemu", cfg_qemu) all_cfgs
let cfg_emacs = 
  "/home/pad/software-src/devel/emacs-22.0.97", "macros_emacs.h", 
  (fun () -> 
         Parse_cplusplus.threshold_cplusplus := 100;
  )
let _ = Common.push2 ("cfg_emacs", cfg_emacs) all_cfgs

let cfg_git =
  "/home/pad/software-src/devel/git-git", "macros_git.h", 
  (fun () -> 
         Parse_cplusplus.threshold_cplusplus := 100;
  )
let _ = Common.push2 ("cfg_git", cfg_git) all_cfgs
let cfg_sparse = 
  "/home/pad/software-src/devel/sparse-git", "macros_sparse.h", 
  (fun () -> 
         Parse_cplusplus.threshold_cplusplus := 100;
  )
let _ = Common.push2 ("cfg_sparse", cfg_sparse) all_cfgs


(* only gcc part ? not libgcc, libada, libcpp, etc ? *)
let cfg_gcc =
  "/home/pad/software-src/devel/gcc-svn/gcc", "macros_gcc.h", (* only compiler part *)
  (fun () -> ())
let _ = Common.push2 ("cfg_gcc", cfg_gcc) all_cfgs


let cfg_pidgin = 
  "/home/pad/software-src/desktop/communication/pidgin-2.5.1", "macros_pidgin.h", 
  (fun () -> ()
  )
let _ = Common.push2 ("cfg_pidgin", cfg_pidgin) all_cfgs

let cfg_quake3 = 
  "/home/pad/software-src/games/ioquake3-svn", "macros_quake3.h", 
  (fun () -> ()
  )
let _ = Common.push2 ("cfg_quake3", cfg_quake3) all_cfgs
let cfg_openssh = 
  "/home/pad/software-src/security/openssh-4.7p1", "macros_openssh.h", 
  (fun () -> ()
  )
let _ = Common.push2 ("cfg_openssh", cfg_openssh) all_cfgs


let cfg_kdeedu = 
  "/home/pad/software-src/edu/kdeedu-3.5.5", "macros_kdeedu.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 1;
  )
let _ = Common.push2 ("cfg_kdeedu", cfg_kdeedu) all_cfgs

let cfg_glibc = 
  "/home/pad/software-src/libs/glibc-2.7", "macros_glibc.h", 
  (fun () -> 
    Parse_cplusplus.threshold_cplusplus := 250;
  )
let _ = Common.push2 ("cfg_glibc", cfg_glibc) all_cfgs
(* comes from gcc-svn/libstdc++-v3 *)
let cfg_libstdcplusplus = 
  "/home/pad/software-src/libs/libstdc++-v3", "macros_libstl.h", 
  (fun () -> ())
let _ = Common.push2 ("cfg_libstdcplusplus", cfg_libstdcplusplus) all_cfgs


let cfg_sdl = 
  "/home/pad/software-src/libs/sdl-svn", "macros_libsdl.h", 
  (fun () -> ()
  )
let _ = Common.push2 ("cfg_sdl", cfg_sdl) all_cfgs


(* ---------------------------------------- *)



let cfg_linux001 = 
  "/home/pad/software-src/kernel/linux-0.01", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_linux001", cfg_linux001) all_cfgs

let cfg_gnuchess = 
  "/home/pad/software-src/games/gnuchess-5.07", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_gnuchess", cfg_gnuchess) all_cfgs
let cfg_gnugo = 
  "/home/pad/software-src/games/gnugo-3.0.0", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_gnugo", cfg_gnugo) all_cfgs

let cfg_doom =
  "/home/pad/software-src/games/linuxdoom-1.10", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_doom", cfg_doom) all_cfgs

let cfg_sqlite = 
  "/home/pad/software-src/database/sqlite-cvs", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_sqlite", cfg_sqlite) all_cfgs


let cfg_postfix = 
  "/home/pad/software-src/server/postfix-2.5.5", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_postfix", cfg_postfix) all_cfgs
let cfg_samba = 
  "/home/pad/software-src/server/samba-3.2.4", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_samba", cfg_samba) all_cfgs


let cfg_apache = 
  "/home/pad/software-src/system/httpd-2.2.6", "macros_apache.h", 
  (fun () -> ())
let _ = Common.push2 ("cfg_apache", cfg_apache) all_cfgs


let cfg_qemacs = 
  "/home/pad/software-src/devel/qemacs-0.3.1", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_qemacs", cfg_qemacs) all_cfgs



let cfg_dbus = 
  "/home/pad/software-src/libs/dbus-git", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_dbus", cfg_dbus) all_cfgs
 
let cfg_cairo = 
  "/home/pad/software-src/libs/cairo-1.8.0", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_cairo", cfg_cairo) all_cfgs
 
let cfg_gtk = 
  "/home/pad/software-src/libs/gtk-svn", "macros_gtk.h", 
  (fun () -> ())
let _ = Common.push2 ("cfg_gtk", cfg_gtk) all_cfgs


let cfg_utils_linux = 
  "/home/pad/software-src/utils/util-linux-2.12r", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_utils_linux", cfg_utils_linux) all_cfgs

let cfg_utils_linux_ng = 
  "/home/pad/software-src/utils/util-linux-ng-2.14", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_utils_linux_ng", cfg_utils_linux_ng) all_cfgs

let cfg_gimp = 
  "/home/pad/software-src/graphical/gimp-2.4.7", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_gimp", cfg_gimp) all_cfgs


let cfg_grub = 
  "/home/pad/software-src/hardware/grub-1.96", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_grub", cfg_grub) all_cfgs

let cfg_d1x = 
  "/home/pad/software-src/games/d1x-rebirth", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_d1x", cfg_d1x) all_cfgs

let cfg_d2x = 
  "/home/pad/software-src/games/d2x-rebirth", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_d2x", cfg_d2x) all_cfgs

let cfg_dvdcss = 
  "/home/pad/software-src/multimedia/libdvdcss-1.2.8", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_dvdcss", cfg_dvdcss) all_cfgs

let cfg_xpdf = 
  "/home/pad/software-src/publish/xpdf-3.02", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_xpdf", cfg_xpdf) all_cfgs

let cfg_xfig = 
  "/home/pad/software-src/graphical/xfig.3.2.5", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_xfig", cfg_xfig) all_cfgs


(* only kernel *)
let cfg_freebsd = 
  "/home/pad/software-os-src/freebsd", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_freebsd", cfg_freebsd) all_cfgs
(* only kernel *)
let cfg_opensolaris = 
  "/home/pad/software-os-src/opensolaris", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_opensolaris", cfg_opensolaris) all_cfgs

let cfg_coyotos = 
  "/home/pad/software-src/kernel/coyotos-hg", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_coyotos", cfg_coyotos) all_cfgs


let cfg_postgres = 
  "/home/pad/software-src/database/postgresql-8.3.4", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_postgres", cfg_postgres) all_cfgs

let cfg_spim = 
  "/home/pad/software-src/hardware/spim-7.3", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_spim", cfg_spim) all_cfgs

let cfg_zsnes = 
  "/home/pad/software-src/hardware/zsnes_1_51", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_zsnes", cfg_zsnes) all_cfgs

(* only the server. X11 is huge, with lots of git modules (modular X) *)
let cfg_x11_server = 
  "/home/pad/software-src/graphicalx11-git", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_x11_server", cfg_x11_server) all_cfgs

let cfg_fvwm = 
  "/home/pad/software-src/graphical/fvwm-2.4.20", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_fvwm", cfg_fvwm) all_cfgs

let cfg_valgrind = 
  "/home/pad/software-src/deve/valgrind-3.2.3", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_valgrind", cfg_valgrind) all_cfgs

let cfg_glib = 
  "/home/pad/software-src/libs/glib-svn", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_glib", cfg_glib) all_cfgs

let cfg_mesa = 
  "/home/pad/software-src/libs/mesa-git", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_mesa", cfg_mesa) all_cfgs

let cfg_gnumeric = 
  "/home/pad/software-src/desktop/office/gnumeric-1.8.3", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_gnumeric", cfg_gnumeric) all_cfgs

let cfg_abiword = 
  "/home/pad/software-src/desktop/office/abiword-2.6.4", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_abiword", cfg_abiword) all_cfgs

let cfg_ffmpeg = 
  "/home/pad/software-src/multimedia/ffmpeg-svn", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_ffmpeg", cfg_ffmpeg) all_cfgs

let cfg_mplayer = 
  "/home/pad/software-src/multimedia/MPlayer-1.0rc2", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_mplayer", cfg_mplayer) all_cfgs

let cfg_wget = 
  "/home/pad/software-src/network/wget-1.11.4", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_wget", cfg_wget) all_cfgs


let cfg_jgraph = 
  "/home/pad/software-src/publish/jgraph", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_jgraph", cfg_jgraph) all_cfgs

let cfg_xterm = 
  "/home/pad/software-src/window/xterm-222", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_xterm", cfg_xterm) all_cfgs

let cfg_vim = 
  "/home/pad/software-src/devel/vim72", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_vim", cfg_vim) all_cfgs


let cfg_llvm = 
  "/home/pad/software-src/devel/llvm-2.3", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_llvm", cfg_llvm) all_cfgs

let cfg_doxygen = 
  "/home/pad/software-src/devel/doxygen-1.5.7", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_doxygen", cfg_doxygen) all_cfgs

let cfg_R = 
  "/home/pad/software-src/misc/R-2.6.2", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_R", cfg_R) all_cfgs


let cfg_xmame = 
  "/home/pad/software-src/hardware/xmame-0.106", "", 
  (fun () -> ())
let _ = Common.push2 ("cfg_xmame", cfg_xmame) all_cfgs



(* ---------------------------------------- *)
(* 99.22 (5s) 352files *)
let soft1 = [ 
  cfg_sparse; cfg_git
]

(* 88.44% (1m47) 82.46% (2m) 3342files *)
let soft2 = soft1 ++ [
  cfg_qemu; cfg_openssh;    cfg_quake3;      cfg_sdl; 
  cfg_pidgin; cfg_gtk;
]

(* 82.45% (2m36) 3842files *)
let soft3 = soft2 ++ [
  cfg_emacs;
  cfg_kdeedu; 
    (* TOREPUT: PB in file ~/software-src/edu/kdeedu-3.5.5/kmplot/kmplot/kmplotio.h *)
    (* @author Klaus-Dieter Möller & Matthias Meßmer *)
]

(* *)
let soft4 = soft3 ++ [
  cfg_linux; 
  cfg_mozilla2; 
  cfg_mysql;
  cfg_glibc; (* TOREPUT: PB in iconvdate/ temperarily moved in a ___2/ *)
  cfg_libstdcplusplus;
  cfg_gcc;
]

let soft5 = soft4 ++ [

]



(* ---------------------------------------- *)
let soft_alt1 = [
  cfg_sqlite; 
]

(* ---------------------------------------- *)
(* > 99%  = 99.22 (1s) *)
let soft_good1 = [
  cfg_sparse; cfg_git;
]

(* = 99.32 (10s) *)
let soft_good2 = soft_good1 ++ [

  cfg_gnuchess; cfg_gnugo;
  cfg_linux001; cfg_doom;
]


(* > 95% = 95.39 (2m7)  *)
let soft_good3 = soft_good2 ++ [
  cfg_openssh; 

  cfg_qemacs;

  cfg_dbus; cfg_cairo; cfg_gtk;
  cfg_pidgin;
  cfg_utils_linux; cfg_utils_linux_ng;
  cfg_gimp;
]

(* > 90% = 94.27 (??m)  *)
let soft_good4 = soft_good3 ++ [

  cfg_postfix; cfg_samba; 
  cfg_grub;
  (* cfg_d1x; cfg_d2x; *)
  cfg_dvdcss;
  cfg_xpdf;
  cfg_xfig;
]


(* > 80% = ?? *)
let soft_good5 = soft_good4 ++ [
  cfg_linux;
  cfg_quake3;
  cfg_sdl;

  cfg_freebsd; (* cfg_opensolaris *)
  cfg_coyotos;

  cfg_sqlite;

  cfg_postgres;
  cfg_spim;
  cfg_zsnes;
  cfg_x11_server;
  cfg_fvwm;
  cfg_valgrind;
  cfg_glib;
  cfg_mesa;
  cfg_gnumeric;
  cfg_abiword;
  cfg_ffmpeg;
  cfg_wget;
]

(* = ?? *)
let soft_ok1 = [
  cfg_mysql;
  cfg_qemu;

  cfg_glibc;
  cfg_kdeedu;

]

(* = ?? *)
let soft_bad1 = [
  cfg_emacs;


  cfg_jgraph;
  cfg_xterm;
  cfg_vim;
  
  cfg_llvm;
  cfg_doxygen;
  cfg_R;
]

(* = ?? *)
let soft_bad2 = soft_bad1 ++ [
  cfg_mozilla;

  cfg_xmame; 
  cfg_libstdcplusplus;
]


let soft_pb1 = [
  cfg_gcc;

]
(* ---------------------------------------- *)
(*
X big: Linux          82% !! 96% (-D) 98.5 (twopass ifdef) 98.97%+1.32% (rules with conflicts back)

X qemu           76% !! 89% (twopass ifdef) 96.60% (macros)     97.00%+3.3
X emacs          58% !! 62% (twopass ifdef) 84.42% (macros) 95% (pb old c decl and bad typedef) 96.15% (macros2) 96.15%+4.3
X git            99.4% !! 99.89% (macros) 99.92%+0.03
X sparse         98.5% !! 99.32% (macros) 98.80%+0.71 :( (pb was c++ .h bad inference) 99.33%
X big: gcc       85% !! (compiler only)  (include cpp :) ) 96%(macros) 97.30%+1.52 (two pass, and extensions)
X Quake III      84% !! 97.25%          96.09%+2.15 :( 
X openssh        94% !! 99.07% (macros) 99.16%+0.69
X pidgin         96% !! 99.30% (macros) 99.35%+1.48
X big: glibc     70% !! (bug PB in iconvdata/) 77%(twopass ifdefs) 84%(macros) 92.13%(macros and extensions, STD_C ifdef passing, cplusplus passing) 92.37%+3.9
X sdl            82% !! 86% (twopass ifdef) 95.23% 93% :( (pb APIENTRYp) 95.22%+3.06
X gtk            94% 96% XX% (macros)

~ big: Mozilla(c++)   66% !! 83% -D 86% -D++ 90% (twopass ifdef)
~ big: Mysql(c++)     75% !! 84% -D ?? 88.1% (twopass ifdef)
~ kdeedu (c++)   78% !! (PB in file, I think unicode related) 87.2% (macros)
big: libstdc++ 49% !! 50%

*)

(*
% - OS: freebsd 87%!!, opensolaris ??%,     xen ??%    linux0.01 (97%)!! 95.99%+0.22 :( 
% - OS: coyotos 81%!!  plan9 (include: 95%)  unix-lions 25% xinu 56%
% - Browser: google chrome (c++) ??% (+ lots of libs, like glags, gtest)
% - Browser: WebKit ??% v8??
% - Database: berkeleyDB 77%, gdbm,  sqlite 84%!!, postgres 89%!!, 
% - Server: apache 68% 96.44%+1.96,  postfix 93%!!, samba 91%!!
% - Hardware: spim 85%!!,   wine, xmame 52%!!, zsnes 81%!!
% - System: grub 91%!!
% - Windows: X11-xorg-server 84%!!, fvmwm 88%!!  xterm 45%!!
% - Editor: qemacs 95%!! 97.77%+2.52     vim 47%!!
% - Devel: llvm(c++) 34%!!  elsa(c++)    doxygen(c++) 66%!!
% - Devel: subversion RCS CVS 
% - Devel: binutils  flex 75%  bison  gmake  
% - Devel: valgrind 79%!!  gdb  
% - Devel: perl, python, ruby, php,  mono,   gawk
% - Devel: v8 (c++) 62%
% - Games: doom 99.6%!! 100%+0.88    d1x 92% 96.43%+0.91    d2x 91%  96.60%+1.0
% - Games: gnuchess 99.3%!! 99.97%+0.1  gnugo 99.4%!! 99.92%+1.0
% - Libs: boost CRASH (c++) (hmmm) glib 87%!!
% - Libs: dbus 94%!!
% - Libs Graphics: cairo 94%!!,  mesa 84%!!
% - GUI: gtk 94%!!  wxwidgets qt(c++)
% - Desktop: ooffice, koffice (c++),     gnumeric 82%!! , abiword(c++) 78%!!
% - Desktop: pidgin 96%!!  
% - Desktop: kdepim (c++) 96%  
% - Multimedia: mplayer 86.32%+2.29   ffmpeg 84%!!,  xmms  xine      cdparanioa  dvdcss 91%!! 97.11%+0.87
% - Multimedia: blender 
% - Scientific:  R 67% (also categ: langage)  
% - Utils: diffutils 66% findutils 68% corutils 79%
% - Utils: utils-linux 94%!! utils-linux-ng 95%!!
% - Utils: gzip tar 72%
% - Utils: bash 71% zsh 59%
% - Utils: bc 57%
% - Graphic: gimp 95%!!
% - Publis: latex? gv 53%, xpdf(c++) 90%!! , xfig 93%!!, jgraph 35%!! gnuplot 
% - Business:
% - Network: wget 88%!!

gnome: 
 glib, dbus
 bluez, evolution, telapath, avahi, gstreamer, sqlite, gconf, matchbox, gio
 gtk, pango, atk, cairo


astec list: gzip, RCS, openssh, linux

cpp ernst list: 
 bison
 cvs
 flex
 fvwm!!
 gawk
 genscript
 ghostview
 gnuchess!!
 gnuplot
 gs
 gzip
 m4
 mosaic
 plan? rasmol?
 rcs
 remind ?
 workman
 xfig!!
 zephyr?
 zsh
pad: no mozilla (cos C++), no linux (cos gccext?)

stroustrup list hopl3:
 
*)


let soft_of_str soft_str = 
  match soft_str with
  | "soft1" -> soft1
  | "soft2" -> soft2
  | "soft3" -> soft3
  | "soft4" -> soft4
  | "soft5" -> soft5
      
  | "soft_alt1" -> soft_alt1
      
  | "soft_good1" -> soft_good1
  | "soft_good2" -> soft_good2
  | "soft_good3" -> soft_good3
  | "soft_good4" -> soft_good4
  | "soft_good5" -> soft_good5
      
  | "soft_ok1" -> soft_ok1
      
  | "soft_bad1" -> soft_bad1
  | s -> failwith ("unrecognized softset: " ^ s)


let cc09 soft_str = 
  let softs = soft_of_str soft_str in
  softs +> List.map fst3 +> List.iter (fun x -> 
    if Common.is_directory x then ()
    else failwith ("no directory: " ^ x)
  );
  softs +> List.map snd3 +> List.iter (fun stdh -> 
    let xfile = (Filename.concat config_path ("data/" ^ stdh)) in
    if stdh = "" || Sys.file_exists xfile then ()
    else failwith ("no macro file: " ^ xfile)
  );

  if Distribution.under_mpirun ()
  then 
    parse_all (softs +> List.map fst3) +> ignore
  else begin

    let stats = 
      softs +> List.map (fun (dir, stdh, fbefore) -> 
        let xfile = (Filename.concat config_path ("data/" ^ stdh)) in

        fbefore ();
        if stdh <> "" && not (!no_macro_file)
        then begin 
          Parse_c.init_defs xfile;
          Parse_cplusplus.init_defs xfile;
          (*Parse_c.add_defs (Filename.concat config_path commonh);*)
        end;
        
        let (stat, score) = parse_all [dir] in
        Parsing_stat.print_stat_numbers ();

        stat, score, dir
      ) 
    in
    let total_parsing_stat = 
      stats +> List.map fst3 +> List.flatten in
    let newscore = 
      stats +> List.map snd3 +> List.map Common.hash_to_list +> List.flatten +> 
        Common.hash_of_list
    in

    let dirname = "cc09" in
    (
      pr2 "--------------------------------";
      pr2 "regression testing  information";
      pr2 "--------------------------------";
      let str = Str.global_replace (Str.regexp "/") "__" dirname in
      let def = if !Flag_parsing_c.filter_define_error then "_def_" else "" in
      let ext = "_all_" ^ soft_str ^ (if !no_macro_file then "_noD_" else "") in
      Common.regression_testing newscore 
        (Filename.concat score_path
            ("score_parsing__" ^str ^ def ^ ext ^ ".marshalled"))
    );
    Parsing_stat.print_stat_numbers ();


    stats +> List.iter (fun (stat, score, dir) -> 
      pr2_xxxxxxxxxxxxxxxxx();
      pr2 dir;
      Statistics_parsing.print_parsing_stat_list stat;
    );
    
    pr2_xxxxxxxxxxxxxxxxx();
    Statistics_parsing.print_parsing_stat_list total_parsing_stat;
    
    ()
  end


(* ------------------------------------------------------------------------- *)

let parse_software_src str = 
  let (dir, stdh, fbefore) = !all_cfgs +> List.assoc str in
  
  
  let xfile = (Filename.concat config_path ("data/" ^ stdh)) in
  
  fbefore ();
  if stdh <> "" && not (!no_macro_file)
  then begin 
    Parse_c.init_defs xfile;
    Parse_cplusplus.init_defs xfile;
    (*Parse_c.add_defs (Filename.concat config_path commonh);*)
  end;
  
  let (_stat, _score) = parse_all [dir] in
  ()
 


let cc09_gcc_count_file_processed dir = 
  raise Todo

let cc09_stat_stdh soft_str  = 
  let softs = soft_of_str soft_str in
  softs +> List.map snd3 +> List.map (fun stdh -> 
    let xfile = (Filename.concat config_path ("data/" ^ stdh)) in
    if stdh = "" || Sys.file_exists xfile then ()
    else failwith ("no macro file: " ^ xfile);

    let defines = Common.cat xfile +> List.filter (fun s -> 
      s =~ "^#define.*"
    ) in
    let n = List.length defines in
    pr (spf "%s: %d" xfile n);
    n
  ) +> Common.avg_list 
    +> (fun f -> pr (spf "avg: %f" f))

let cc09_stat_gcc_compiled dir = 
  let xs = Common.files_of_dir_or_files "c" [dir] in
  let xs' = xs +> List.filter (fun f -> 
    if Sys.file_exists (Common.replace_ext f "c" "o")
    then true
    else begin 
      pr2 (spf "not compiled?: %s" f);
      false 
    end
  ) in
  let nxs = (List.length xs) in
  let nxs' = (List.length xs') in
  pr (spf "total=%d, with .o=%d, percent compiled= %f%%" nxs nxs' 
         (Common.pourcent_float nxs' nxs));

  

  ()

let cc09_stat_mly file = 
  let xs = Common.cat file in
  let xs' = xs +> List.filter (fun s -> 
    let does_match = (s =~ "^[a-z_]*:.*[a-zA-Z_].*" || s =~ "[ \t]*|.*") in
    if does_match
    then pr2 (spf "yes: %s" s)
    else pr2 (spf "nop: %s" s);
    does_match
  ) in
  pr (spf "total = %d" (List.length xs'));
  ()


open Ast_c
let cc09_null_transfo () = 
(*
(* X == 0  -->  X == NULL when X is a pointer *)
(*let main = *)
  let (ast, _stat) = Parse_c.parse_c_and_cpp Sys.argv.(1) in
  let ast2 = List.map fst ast in
  Type_annoter_c.annotate_program Type_annoter_c.initial_env ast2;
  Visitor_c.vk_program {
    Visitor_c.kexpr = (fun k exp -> 
      match Ast_c.unwrap_expr exp with
      | Binary(e1, Logical (Eq), (((Constant(Int("0")) as e2),_),_)) -> 
          (match Ast_c.get_type_expr e1 with 
          | Some (qu, (Pointer _)) -> 
              let idzero = Ast_c.get_tokens_ref1 e2 in
              Ast_c.modify_token (fun s -> "NULL") idzero;
          | _ -> ()
          )
      | _ -> k st
    );
  } ast;
  let tmpfile = "/tmp/modified.c" in
  Unparse_c.unparse ast tmpfile
*)
  ()

(*
  let (program2, _stat) =  Parse_c.parse_print_error_heuristic infile in
  let _program2 =
    program2 
    +> Common.unzip 
    +> (fun (program, infos) -> 
      Type_annoter_c.annotate_program Type_annoter_c.initial_env
        program +> List.map fst,
      infos
    )
    +> Common.uncurry Common.zip
  in
  let program2_with_ppmethod = 
    program2 +> List.map (fun x -> x, Unparse_c.PPnormal)
  in
  Unparse_c.pp_program program2_with_ppmethod tmpfile;
*)




(* ------------------------------------------------------------------------- *)

let misc_xxx file = 
  Common.cat file +> List.iter (fun s -> 
    let ident = "\\([A-Z][A-Za-z]*\\)" in
    let maj = "[A-Z]" in
    let newstr = 
      Common.global_replace_regexp ident (fun s -> 

       if String.uppercase s = s (* all maj, so do nothing *)
       then s
       else 
        let is_first = ref true in
        Common.global_replace_regexp maj (fun m -> 
          if !is_first 
          then begin 
            is_first := false;
            String.lowercase m
          end
          else 
            "_" ^ String.lowercase m
        ) s 
      ) s 
    in
    pr newstr;
  )


(* ------------------------------------------------------------------------- *)
let yacfe_extra_actions () = [
  "-parse_all", " ",
  Common.mk_action_n_arg (fun x -> ignore(parse_all x));
  "-parse_software_src", " ",
  Common.mk_action_1_arg (fun x -> ignore(parse_software_src ("cfg_" ^ x)));
  "-cc09", "  <soft_set> ",
  Common.mk_action_1_arg cc09;
  "-cc09_gcc", "   ",
  Common.mk_action_1_arg cc09_gcc_count_file_processed;
  "-cc09_stat_stdh", "  <soft_set> ",
  Common.mk_action_1_arg cc09_stat_stdh;
  "-cc09_stat_gcc_compiled", "   ",
  Common.mk_action_1_arg cc09_stat_gcc_compiled;
  "-cc09_stat_mly", "   ",
  Common.mk_action_1_arg cc09_stat_mly;
  "-xxx", "   ",
  Common.mk_action_1_arg misc_xxx;
]

(*****************************************************************************)
(* The options *)
(*****************************************************************************)

let all_actions () = 
   yacfe_extra_actions() ++
   Test_parsing_c.actions() ++
   Test_parsing_cplusplus.actions() ++
   Test_parsing_java.actions() ++
   []

let options () = 
  Flag_parsing_c.cmdline_flags_macrofile () ++
  Flag_parsing_c.cmdline_flags_verbose () ++
  Flag_parsing_c.cmdline_flags_debugging () ++
  Flag_parsing_c.cmdline_flags_parsing_algos () ++

  Flag_parsing_cplusplus.cmdline_flags_macrofile () ++
  Flag_parsing_cplusplus.cmdline_flags_verbose () ++
  Flag_parsing_cplusplus.cmdline_flags_debugging () ++


  [
    "-no_macro_file", Arg.Set no_macro_file,
    " ";
  ] ++
  Common.options_of_actions action (all_actions()) ++
  Common.cmdline_flags_devel () ++
  Common.cmdline_flags_verbose () ++
  [
  (* this can not be factorized in Common *)
  "-version",   Arg.Unit (fun () -> 
    pr2 "version: $Date: 2008/06/08 12:32:06 $";
    raise (Common.UnixExit 0)
  ), 
  "   guess what";
  ]

 
(*****************************************************************************)
(* Main entry point *)
(*****************************************************************************)

let main () = 

  Flag_parsing_c.std_h := "/home/pad/c-yacfe/data/standard.h";
  Flag_parsing_cplusplus.std_h := "/home/pad/c-yacfe/data/standard.h";

  let argv = Distribution.mpi_adjust_argv Sys.argv in


  let usage_msg = 
    "Usage: " ^ basename Sys.argv.(0) ^ 
      " [options] <file or dir> " ^ "\n" ^ "Options are:"
  in
  (* does side effect on many global flags *)
  let args = Common.parse_options (options()) usage_msg argv in

  (* must be done after Arg.parse, because -macro_file can set it *)
  Parse_c.init_defs !Flag_parsing_c.std_h;
  Parse_cplusplus.init_defs !Flag_parsing_cplusplus.std_h;
    
  (* must be done after Arg.parse, because Common.profile is set by it *)
  Common.profile_code "Main total" (fun () -> 

    (match args with
    
    (* --------------------------------------------------------- *)
    (* actions, useful to debug subpart *)
    (* --------------------------------------------------------- *)
    | xs when List.mem !action (Common.action_list (all_actions())) -> 
        Common.do_action !action xs (all_actions())

    | _ when not (Common.null_string !action) -> 
        failwith ("unrecognized action or wrong params: " ^ !action)

    (* --------------------------------------------------------- *)
    (* main entry *)
    (* --------------------------------------------------------- *)
    | x::xs -> 
        (* CQL *)

        let ext = "[ch]" in

        let files = Common.files_of_dir_or_files ext (x::xs) in
        let nbfiles = List.length files in

        let parsing_stat_list = ref [] in
        (* let comment_stat_list = ref [] in *)
        (* let entities_stat_list = ref [] in *)

        Common.check_stack_nbfiles nbfiles; 

        files +> Common.index_list +> List.iter (fun (file, i) -> 

          pr2 (spf "PARSING: %s (%d/%d)" file i nbfiles);

          (* toc:
           * - parsing c and cpp and comments (well basic comments parsing)
           * - comments_extraction
           * - comments_extraction check
           *)

          let (program, parsing_stat) = 
            Parse_c.parse_c_and_cpp file in

          let (_comments_packed, _allx, _pinfo_mapping, _entities_stat) = 
            (* TOREPUT Comment_annotater.comments_of_program program *)
            (), (), (), ()
          in

          (*
          let _info_comments = comments +> List.map fst in
          Parse_c_comments_only.check_extraction file info_comments;
          *)

          Common.push2 parsing_stat  parsing_stat_list;
          (*
            Common.push2 comment_stat  comment_stat_list;
            Common.push2 entities_stat entities_stat_list;
          *)
        );
        (* -------------------------- *)
        (* end iter *)
        (* -------------------------- *)

        Parsing_stat.print_stat_numbers ();
        Parsing_stat.print_parsing_stat_list              !parsing_stat_list;

        (*
        pr2_xxxxxxxxxxxxxxxxx ();
        Comments_statistics.print_comments_stat_list !comment_stat_list;
        Statistics_c.print_entities_stat_list !entities_stat_list;
        *)


    (* --------------------------------------------------------- *)
    (* empty entry *)
    (* --------------------------------------------------------- *)
    | [] -> 
        Common.usage usage_msg (options()); 
        failwith "too few arguments"
          
    )
  )

(*****************************************************************************)
let _ =
  Common.main_boilerplate (fun () -> 
    main ();
  )
