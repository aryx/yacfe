(*
maybe when fixed those code, can simplify lexer_c.mll or ast_c.ml or
parser_c.mly or parsing_hack.ml ? Or maybe just add comment in those
file saying that those ugly code is also detected by cpp-lint or k-lint
*)

  (* linuxext: different possible variations (we not manage all of them):
    #if LINUX_VERSION_CODE < ASC_LINUX_VERSION(2,2,0) || \
    (LINUX_VERSION_CODE > ASC_LINUX_VERSION(2,3,0) && \
    LINUX_VERSION_CODE < ASC_LINUX_VERSION(2,4,0))

=> normalize




  *)
