(defun pad-ocaml-project-Yacfe ()
  (interactive)

  (setq 
   pad-ocaml-project-path "/home/pad/mobile/project-yacfe/code"
   pad-ocaml-project-subdirs 
   (split-string 
    "commons globals extra 
     parsing_c parsing_c++ parsing_java
     analyze_c
     matcher
    ")

   pad-ocaml-project-toplevel "yacfe.top"
   pad-ocaml-project-prog     "yacfe"
   pad-ocaml-project-args 
   (join-string 
    (list 
     "-debugger"
     (case 700
       (0 "")

       (1 "/home/pad/comments/tests/basic.c")

       (5 "-parse_c /home/pad/software-src/kernel/opensolaris-usr-src-uts/common/io/gld.c")
       (6 "-parse_c /home/pad/software-os-src/linux/fs/afs/inode.c")
       (7 "-parse_c /home/pad/comments/tests/macro_expansion.c")
       (8 "-parse_c /home/pad/software-os-src/linux/arch/powerpc/platforms/pseries/setup.c")
       (9 "-parse_c /home/pad/comments/tests/macro_expansion2.c")


       (10 "/home/pad/software-src/kernels/git/linux-2.6/init")
       (11 "/home/pad/kernels/git/linux-2.6/sound/arm/sa11xx-uda1341.c")
       (12 "/home/pad/software-src/kernels/git/linux-2.6/fs")

       (20 "-parse_c -D /home/pad/c-yacfe/data/test.h /home/pad/c-yacfe/tests_cpp/hints_required.c")

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
       (100 "-parse_c++ /home/pad/c-yacfe/tests_c++/attribute_passing.cpp")
       ;constructed_bool1
       
       (201 "-parse_java /home/pad/c-yacfe/tests-ex/java/objet-4eme-annee/tp7/Reference.java")
       (202 "-parse_java /home/pad/c-yacfe/tests_java/simple.java")

       (210 "-visitor_java /home/pad/c-yacfe/tests_java/simple.java")


       (300 "-xxx /home/pad/c-yacfe/parsing_java/parser_java.mly")

       (400 "-cc09_null_transfo /home/pad/paper-cc09/simple.c")

       (600 "-test_cpp /home/pad/linux/block/blk-core.c")

       (700 "-test_build_db /home/pad/linux/block")

       )
     )
    )
   )

  ; for the help system, for C-c C-h to find where to look for
  (mapcar (lambda (p) 
            (ocaml-add-path (concat pad-ocaml-project-path "/" p))
            (ocaml-add-path "/home/pad/packages/lib/ocaml/std-lib")
            (ocaml-add-path "/usr/lib/ocaml/3.09.2/lablgtk2")
            (ocaml-add-path "/usr/lib/ocaml/3.09.2/lablgtksourceview")
            )
          pad-ocaml-project-subdirs)
  )

; specific emacs macros: 
(fset 'yacfe-goto-place
   [?\C-  ?\C-s ?: left ?\M-w ?\C-x ?\C-f ?/ S-insert return ?\C-\M-l right ?\C-  C-right ?\M-w ?\C-\M-l ?\M-g S-insert return])

(fset 'yacfe-parse-error-goto
   [?\C-s ?\" right left ?\C-  ?\C-s ?\" left ?\M-w ?\C-x ?\C-f S-insert return ?\C-\M-l C-right C-right C-left ?\C-  C-right ?\M-w ?\C-\M-l ?\M-g S-insert return])
