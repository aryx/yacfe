(defun pad-ocaml-project-Yacfe ()
  (interactive)

  (setq 
   pad-ocaml-project-path "/home/pad/mobile/project-yacfe/code"
   pad-ocaml-project-subdirs 
   (split-string 
    "commons globals extra 
     parsing_c parsing_cplusplus parsing_java
     analyze_c
     matcher_c
     smpl
    ")

   pad-ocaml-project-toplevel "yacfe.top"
   )

  ; --------------------------------------------------------------------------
  ; command line
  ; --------------------------------------------------------------------------
  (setq
   pad-ocaml-project-prog     "yacfe"
   pad-ocaml-project-args 
   (join-string 
    (list 
     "-debugger"
     (case 9
       (0 "")

       (1 "/home/pad/comments/tests/basic.c")

       (5 "-parse_c /home/pad/software-src/kernel/opensolaris-usr-src-uts/common/io/gld.c")
       (6 "-parse_c /home/pad/software-os-src/linux/fs/afs/inode.c")
       (7 "-parse_c /home/pad/comments/tests/macro_expansion.c")
       (8 "-parse_c /home/pad/software-os-src/linux/arch/powerpc/platforms/pseries/setup.c")
       ;(9 "-parse_c /home/pad/comments/tests/macro_expansion2.c")
       (9 "-macro_file /home/pad/c-yacfe/config/macros/empty.h -env_file /home/pad/c-yacfe/config/envos/empty.h
             -parse_c /home/pad/c-yacfe/tests_c/typedef/function_pointer_jesper.c")


       (10 "/home/pad/software-src/kernels/git/linux-2.6/init")
       (11 "/home/pad/kernels/git/linux-2.6/sound/arm/sa11xx-uda1341.c")
       (12 "/home/pad/software-src/kernels/git/linux-2.6/fs")

       (20 "-parse_c -D /home/pad/c-yacfe/data/test.h /home/pad/c-yacfe/tests_cpp/hints_required.c")

       (21 "-macro_file /home/pad/c-yacfe/macros/macros_linux.h -parse_c /home/pad/linux/arch/arm/mach-davinci/gpio.c")

       (52 "/home/pad/software-src/devel/sparse-git/")
       (53 "/home/pad/software-os-src/freebsd/vm/")
       (54 "-nocheck_stack /home/pad/software-os-src/opensolaris/")
       (55 "-nocheck_stack /home/pad/software-os-src/freebsd/")

       (70 "-parse_c /home/pad/c-yacfe/tests_c/error-recovery/misc2.c")

       (90 "-parse_c++ /home/pad/c-yacfe/tests2/reference.cpp")
       (91 "-parse_c++ /home/pad/c-yacfe/tests2/misc_macro.cpp")
       (92 "-parse_c++ /home/pad/c-yacfe/tests2/destructor.cpp")
       (93 "-parse_c++ /home/pad/c-yacfe/tests2/typedef_false_interference_constructor1.cpp")
       (94 "-parse_c++ /home/pad/c-yacfe/tests2/decl_object.cpp")
       (95 "-parse_c++ /home/pad/c-yacfe/tests2/typedef_constructor_func_param.cpp")
       (96 "-parse_c++ /home/pad/c-yacfe/tests2/qualified_typedef.cpp")
       (97 "-parse_c++ /home/pad/c-yacfe/tests2/error_recov_test1.cpp")
       (98 "-parse_c++ /home/pad/c-yacfe/tests2/define_initializer_optvirg.cpp")
       ;operator_eq.cpp 
       ;constructor_multi.cpp 
       ;constructed_template2.cpp
       ;false_positif_cast_is_constructor.cpp
       ;(100 "-parse_c++ /home/pad/c-yacfe/tests_c++/attribute_passing.cpp")
       (100 "-parse_c++ /home/pad/c-yacfe/tests_c++/ex_tara.cpp")
       ;constructed_bool1
       
       (201 "-parse_java /home/pad/c-yacfe/tests-ex/java/objet-4eme-annee/tp7/Reference.java")
       (202 "-parse_java /home/pad/c-yacfe/tests_java/simple.java")

       (210 "-visitor_java /home/pad/c-yacfe/tests_java/simple.java")


       (300 "-xxx /home/pad/c-yacfe/parsing_java/parser_java.mly")

       (400 "-cc09_null_transfo /home/pad/paper-cc09/simple.c")

       (600 "-test_cpp /home/pad/linux/block/blk-core.c")

       (700 "-test_build_db /home/pad/linux/block")
       (701 "-test_build_db /home/pad/software-src/devel/sparse-git/")

       (800 "-test_cfg_ifdef /home/pad/c-yacfe/tests-components/cfg/flow_ifdef.c")


       (900 "-test_query_smpl /home/pad/c-yacfe/data/sgrep/blk_plug_device.sgrep /home/pad/linux/YACFEDB/")
       (901 "-test_query_smpl /home/pad/c-yacfe/data/sgrep/field_suspend.sgrep /home/pad/c-yacfe/tests-components/database/YACFEDB")

       (1000 "-test_function_pointer_call_in_ast /home/pad/c-yacfe/tests-components/database/pointer_function.c")
       (1001 "-parse_c /home/pad/c-yacfe/tests-components/database/pointer_function_typedef.c")

       (1100 "-type_c /home/pad/software-os-src2/freebsd/contrib/ipfilter/netinet/ip_fil_freebsd.c")
       (1101 "-type_c /home/pad/c-yacfe/tests-components/typeur/function.c")
       (1102 "-type_c /home/pad/c-yacfe/tests-components/typeur/enum.c")


       (1200 "-tweak_reindex2 /home/pad/c-yacfe/tests-components/database2/YACFEDB")
       (1201 "-index_db4 /home/pad/c-yacfe/tests-components/database2/YACFEDB")
       (1203 "-batch_mode -build_db_src database2")

       (1300 "-batch_mode -stat_src sparse")
       (1301 "-batch_mode -build_db_src sparse")

       (1400 "-check_db /home/pad/linux/YACFEDB")
       (1401 "-check_db /home/pad/c-yacfe/tests-components/database/YACFEDB")

       )
     )
    )
   )


  ; --------------------------------------------------------------------------
  ; browser
  ; --------------------------------------------------------------------------
  (setq
   pad-ocaml-project-prog     "yacfe_browser"
   pad-ocaml-project-args 
   (join-string 
    (list 
     "-debugger"
     (case 1
       (0 "/home/pad/c-yacfe/tests-components/database/YACFEDB/")
       (1 "/home/pad/c-yacfe/tests-components/database2/YACFEDB/")
       (2 "-verbose_level 4 -test caller:foo_open /home/yyzhou/pad/mobile/project-yacfe/code/tests-components/database/YACFEDB/")
       )
     ))
   )

; time ~/c-yacfe/yacfe_browser.opt  -verbose_level 4 -profile  -test file:/home/pad/linux/drivers/input/mouse/pc110pad.c    /home/pad/linux/YACFEDB/



  ; for the help system, for C-c C-h to find where to look for
  (mapcar (lambda (p) 
            (ocaml-add-path (concat pad-ocaml-project-path "/" p))
            (ocaml-add-path "/home/pad/packages/lib/ocaml/std-lib")
            (ocaml-add-path "/usr/lib/ocaml/3.09.2/lablgtk2")
            (ocaml-add-path "/usr/lib/ocaml/3.09.2/lablgtksourceview")
            (ocaml-add-path "/home/pad/packages/lib/ocaml/std-lib")
            (ocaml-add-path "/home/pad/packages/lib/ocaml/pkg-lib/lablgtk2")
            (ocaml-add-path "/home/pad/packages/lib/ocaml/pkg-lib/lablgtksourceview")
            )
          pad-ocaml-project-subdirs)
  )

; specific emacs macros: 
(fset 'yacfe-goto-place
   [?\C-  ?\C-s ?: left ?\M-w ?\C-x ?\C-f ?/ S-insert return ?\C-\M-l right ?\C-  C-right ?\M-w ?\C-\M-l ?\M-g S-insert return])

(fset 'yacfe-parse-error-goto
   [?\C-s ?\" right left ?\C-  ?\C-s ?\" left ?\M-w ?\C-x ?\C-f S-insert return ?\C-\M-l C-right C-right C-left ?\C-  C-right ?\M-w ?\C-\M-l ?\M-g S-insert return])
