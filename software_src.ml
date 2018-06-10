open Common 

(* ------------------------------------------------------------------------- *)
(* pair of directory and standard.h file and before advice *) 

(* if add a new soft, then parse it, get its percentage, and then 
 * add its cfg in one of the good_xxx or bad_xxx list below.
 *)
let all_cfgs = [
  "template", "/home/pad/software-src/???", "", 
  (fun () -> ());

  "linux", "/home/pad/software-os-src/linux", "macros_linux.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 200;);
  "firefox", "/home/pad/software-os-src/firefox", "macros_mozilla.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 2;);
  "firefox2",  "/home/pad/software-src/web/mozilla", "macros_mozilla.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 1;);
  "mysql", "/home/pad/software-os-src/mysql", "macros_mysql.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 1;);
  "qemu", "/home/pad/software-src/hardware/qemu-svn", "macros_qemu.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 100;);
  "emacs", "/home/pad/software-src/devel/emacs-22.0.97", "macros_emacs.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 100;);
  "git", "/home/pad/software-src/devel/git-git", "macros_git.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 100;);
  "sparse", "/home/pad/software-src/devel/sparse-git", "macros_sparse.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 100;);

  (* only gcc part ? not libgcc, libada, libcpp, etc ? *)
  "gcc", "/home/pad/software-src/devel/gcc-svn/gcc", "macros_gcc.h", (* only compiler part *)
  (fun () -> ());
  "pidgin", "/home/pad/software-src/desktop/communication/pidgin-2.5.1", "macros_pidgin.h", 
  (fun () -> ());
  "quake3", "/home/pad/software-src/games/ioquake3-svn", "macros_quake3.h", 
  (fun () -> ());
  "openssh", "/home/pad/software-src/security/openssh-4.7p1", "macros_openssh.h", 
  (fun () -> ());
  "kdeedu", "/home/pad/software-src/edu/kdeedu-3.5.5", "macros_kdeedu.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 1;);
  "glibc", "/home/pad/software-src/libs/glibc-2.7", "macros_glibc.h", 
  (fun () -> Parse_cplusplus.threshold_cplusplus := 250;);
  (* comes from gcc-svn/libstdc++-v3 *)
  "libstdcplusplus", "/home/pad/software-src/libs/libstdc++-v3", "macros_libstl.h", 
  (fun () -> ());
  "sdl", "/home/pad/software-src/libs/sdl-svn", "macros_libsdl.h", 
  (fun () -> ());

  (* ---------------------------------------- *)
  "linux001", "/home/pad/software-src/kernel/linux-0.01", "", 
  (fun () -> ());
  "gnuchess", "/home/pad/software-src/games/gnuchess-5.07", "", 
  (fun () -> ());

  "gnugo", "/home/pad/software-src/games/gnugo-3.0.0", "", 
  (fun () -> ());
  "doom", "/home/pad/software-src/games/linuxdoom-1.10", "", 
  (fun () -> ());
  "sqlite", "/home/pad/software-src/database/sqlite-cvs", "", 
  (fun () -> ());
  "postfix", "/home/pad/software-src/server/postfix-2.5.5", "", 
  (fun () -> ());
  "samba", "/home/pad/software-src/server/samba-3.2.4", "", 
  (fun () -> ());

  "apache", "/home/pad/software-src/system/httpd-2.2.6", "macros_apache.h", 
  (fun () -> ());

  "qemacs", "/home/pad/software-src/devel/qemacs-0.3.1", "", 
  (fun () -> ());

  "dbus", "/home/pad/software-src/libs/dbus-git", "", 
  (fun () -> ());
 
  "cairo", "/home/pad/software-src/libs/cairo-1.8.0", "", 
  (fun () -> ());
 
  "gtk", "/home/pad/software-src/libs/gtk-svn", "macros_gtk.h", 
  (fun () -> ());

  "utils_linux", "/home/pad/software-src/utils/util-linux-2.12r", "", 
  (fun () -> ());
  "utils_linux_ng", "/home/pad/software-src/utils/util-linux-ng-2.14", "", 
  (fun () -> ());

  "gimp", "/home/pad/software-src/graphical/gimp-2.4.7", "", 
  (fun () -> ());

  "grub", "/home/pad/software-src/hardware/grub-1.96", "", 
  (fun () -> ());

  "d1x", "/home/pad/software-src/games/d1x-rebirth", "", 
  (fun () -> ());
  "d2x", "/home/pad/software-src/games/d2x-rebirth", "", 
  (fun () -> ());

  "dvdcss", "/home/pad/software-src/multimedia/libdvdcss-1.2.8", "", 
  (fun () -> ());

  "xpdf", "/home/pad/software-src/publish/xpdf-3.02", "", 
  (fun () -> ());
  "xfig", "/home/pad/software-src/graphical/xfig.3.2.5", "", 
  (fun () -> ());

  (* only kernel *)
  "freebsd", "/home/pad/software-os-src/freebsd", "", 
  (fun () -> ());
  (* only kernel *)
  "opensolaris", "/home/pad/software-os-src/opensolaris", "", 
  (fun () -> ());
  "coyotos", "/home/pad/software-src/kernel/coyotos-hg", "", 
  (fun () -> ());

  "postgres", "/home/pad/software-src/database/postgresql-8.3.4", "", 
  (fun () -> ());

  "spim", "/home/pad/software-src/hardware/spim-7.3", "", 
  (fun () -> ());

  "zsnes", "/home/pad/software-src/hardware/zsnes_1_51", "", 
  (fun () -> ());

  (* only the server. X11 is huge, with lots of git modules (modular X) *)
  "x11_server", "/home/pad/software-src/graphicalx11-git", "", 
  (fun () -> ());

  "fvwm", "/home/pad/software-src/graphical/fvwm-2.4.20", "", 
  (fun () -> ());

  "valgrind", "/home/pad/software-src/deve/valgrind-3.2.3", "", 
  (fun () -> ());

  "glib", "/home/pad/software-src/libs/glib-svn", "", 
  (fun () -> ());

  "mesa", "/home/pad/software-src/libs/mesa-git", "", 
  (fun () -> ());

  "gnumeric", "/home/pad/software-src/desktop/office/gnumeric-1.8.3", "", 
  (fun () -> ());
  "abiword", "/home/pad/software-src/desktop/office/abiword-2.6.4", "", 
  (fun () -> ());

  "ffmpeg", "/home/pad/software-src/multimedia/ffmpeg-svn", "", 
  (fun () -> ());

  "mplayer", "/home/pad/software-src/multimedia/MPlayer-1.0rc2", "", 
  (fun () -> ());

  "wget", "/home/pad/software-src/network/wget-1.11.4", "", 
  (fun () -> ());

  "jgraph", "/home/pad/software-src/publish/jgraph", "", 
  (fun () -> ());
  "xterm", "/home/pad/software-src/window/xterm-222", "", 
  (fun () -> ());

  "vim", "/home/pad/software-src/devel/vim72", "", 
  (fun () -> ());

  "llvm", "/home/pad/software-src/devel/llvm-2.3", "", 
  (fun () -> ());

  "doxygen", "/home/pad/software-src/devel/doxygen-1.5.7", "", 
  (fun () -> ());

  "R", "/home/pad/software-src/misc/R-2.6.2", "", 
  (fun () -> ());

  "xmame", "/home/pad/software-src/hardware/xmame-0.106", "", 
  (fun () -> ());
]
let all_cfgs_assoc = all_cfgs +> List.map (fun (s, path, macro, hook) -> 
  s, (path, macro, hook)
)

let cfg s = Common.assoc_with_err_msg s all_cfgs_assoc

(* ------------------------------------------------------------------------- *)
(* 99.22 (5s) 352files *)
let soft1 = [ 
  cfg "sparse"; cfg "git";
]

(* 88.44% (1m47) 82.46% (2m) 3342files *)
let soft2 = soft1 ++ [
  cfg "qemu"; cfg "openssh";    cfg "quake3";      cfg "sdl"; 
  cfg "pidgin"; cfg "gtk";
]

(* 82.45% (2m36) 3842files *)
let soft3 = soft2 ++ [
  cfg "emacs";
  cfg "kdeedu"; 
    (* TOREPUT: PB in file ~/software-src/edu/kdeedu-3.5.5/kmplot/kmplot/kmplotio.h *)
    (* @author Klaus-Dieter Möller & Matthias Meßmer *)
]

(* *)
let soft4 = soft3 ++ [
  cfg "linux"; 
  cfg "firefox2"; 
  cfg "mysql";
  cfg "glibc"; (* TOREPUT: PB in iconvdate/ temperarily moved in a ___2/ *)
  cfg "libstdcplusplus";
  cfg "gcc";
]

let soft5 = soft4 ++ [

]



(* ---------------------------------------- *)
let soft_alt1 = [
  cfg "sqlite"; 
]

(* ---------------------------------------- *)
(* > 99%  = 99.22 (1s) *)
let soft_good1 = [
  cfg "sparse"; cfg "git";
]

(* = 99.32 (10s) *)
let soft_good2 = soft_good1 ++ [

  cfg "gnuchess"; cfg "gnugo";
  cfg "linux001"; cfg "doom";
]


(* > 95% = 95.39 (2m7)  *)
let soft_good3 = soft_good2 ++ [
  cfg "openssh"; 

  cfg "qemacs";

  cfg "dbus"; cfg "cairo"; cfg "gtk";
  cfg "pidgin";
  cfg "utils_linux"; cfg "utils_linux_ng";
  cfg "gimp";
]

(* > 90% = 94.27 (??m)  *)
let soft_good4 = soft_good3 ++ [

  cfg "postfix"; cfg "samba"; 
  cfg "grub";
  (* cfg_d1x; cfg_d2x; *)
  cfg "dvdcss";
  cfg "xpdf";
  cfg "xfig";
]


(* > 80% = ?? *)
let soft_good5 = soft_good4 ++ [
  cfg "linux";
  cfg "quake3";
  cfg "sdl";

  cfg "freebsd"; (* cfg "opensolaris" *)
  cfg "coyotos";

  cfg "sqlite";

  cfg "postgres";
  cfg "spim";
  cfg "zsnes";
  cfg "x11_server";
  cfg "fvwm";
  cfg "valgrind";
  cfg "glib";
  cfg "mesa";
  cfg "gnumeric";
  cfg "abiword";
  cfg "ffmpeg";
  cfg "wget";
]

(* = ?? *)
let soft_ok1 = [
  cfg "mysql";
  cfg "qemu";

  cfg "glibc";
  cfg "kdeedu";

]

(* = ?? *)
let soft_bad1 = [
  cfg "emacs";


  cfg "jgraph";
  cfg "xterm";
  cfg "vim";
  
  cfg "llvm";
  cfg "doxygen";
  cfg "R";
]

(* = ?? *)
let soft_bad2 = soft_bad1 ++ [
  cfg "firefox";

  cfg "xmame"; 
  cfg "libstdcplusplus";
]


let soft_pb1 = [
  cfg "gcc";

]


(* ---------------------------------------- *)
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




