open Common

open Ast_c

(*
 * transformation:
 *    X == 0  -->  X == NULL when X is a pointer (copy paste of cc09.ml)
 * to compile:
 *   $ ocamlc -I ../commons/ -I ../parsing_c/ unix.cma str.cma bigarray.cma ../commons/commons.cma ../parsing_c/parsing_c.cma simple_zero_to_null.ml -o zero_to_null
 * to test:
 *   $ ./zero_to_null foo.c
 *   $ cat /tmp/modified.c
 *)


let null_transfo file =
  let (ast2, _stat) = Parse_c.parse_c_and_cpp file in
  let ast = Parse_c.program_of_program2 ast2 in

  ignore (Type_annoter_c.annotate_program !Type_annoter_c.initial_env ast);

  let null_addon =
    Ast_cocci.ExpressionTag
      (Ast_cocci.make_term
          (Ast_cocci.Ident
            (Ast_cocci.make_term
                (Ast_cocci.Id
                  ("NULL", Ast_cocci.no_info,
                  Ast_cocci.PLUS, Ast_cocci.NoMetaPos)))))
  in

  Visitor_c.vk_program { Visitor_c.default_visitor_c with
    Visitor_c.kexpr = (fun (k, bigf) exp ->
      match Ast_c.unwrap_expr exp with
      | Binary(e1, Logical (Eq), (((Constant(Int("0")) as _e2),_t),ii)) ->

          (match Ast_c.get_onlytype_expr e1 with
          | Some (qu, (Pointer _,_ii)) ->

              let idzero = Common2.tuple_of_list1 ii in
              idzero.cocci_tag :=
                Some (Ast_cocci.MINUS (Ast_cocci.NoPos, [[null_addon]]), []);

          | _ -> k exp
          )
      | _ -> k exp
    );
  } ast;
  let tmpfile = "/tmp/modified.c" in
  Unparse_c.pp_program_default ast2 tmpfile;
  Common.cat tmpfile +> List.iter pr2;
  ()

let main =
  null_transfo Sys.argv.(1)
