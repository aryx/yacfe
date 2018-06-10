(* Joust: a Java lexer, parser, and pretty-printer written in OCaml
   Copyright (C) 2001  Eric C. Cooper <ecc@cmu.edu>
   Released under the GNU General Public License *)

open Format
open Syntax

(* Print a generic separated list.
   [pf] is a formatter for elements of the list.
   [sep] is a function to print the separator between elements. *)

let rec print_sep_list pf sep f list =
  match list with
  | [] -> ()
  | [x] -> pf f x
  | x :: rest -> fprintf f "%a%t%a" pf x sep (print_sep_list pf sep) rest

(* Print a generic option value.
   [pf] is a formatter for the value, if present.
   Prints a space before the value when present. *)

let print_option pf f opt =
  match opt with
  | Some x -> fprintf f " %a" pf x
  | None -> ()

(* Print a list of items with no additional separators.
   [pf] is a formatter for elements of the list. *)

let print_list pf =
  print_sep_list pf (fun f -> ())

(* Print a comma-separated list.
   [pf] is a formatter for elements of the list. *)

let print_comma_list pf =
  print_sep_list pf (fun f -> fprintf f ", ")

(* Print a space-separated list.
   [pf] is a formatter for elements of the list. *)

let print_space_list pf =
  print_sep_list pf (fun f -> fprintf f " ")

(* Print a newline-separated list.
   [pf] is a formatter for elements of the list. *)

let print_newline_list pf =
  print_sep_list pf (fun f -> fprintf f "@\n")

let print_ident f id =
  pp_print_string f (id_string id)

let print_name f =
  print_sep_list print_ident (fun f -> fprintf f ".") f

let rec print_type f t =
  match t with
  | TypeName n -> print_name f n
  | ArrayType t' -> fprintf f "%a[]" print_type t'

let modifier_to_string m =
  match m with
  | Public -> "public"
  | Protected -> "protected"
  | Private -> "private"
  | Abstract -> "abstract"
  | Static -> "static"
  | Final -> "final"
  | StrictFP -> "strictfp"
  | Transient -> "transient"
  | Volatile -> "volatile"
  | Synchronized -> "synchronized"
  | Native -> "native"

let rec print f comp =
  pp_set_margin f 0;
  pp_open_box f 0;
  begin
    match comp.package with
    | Some pkg -> fprintf f "package %a;@\n@\n" print_name pkg
    | None -> ()
  end;
  if comp.imports <> [] then
    begin
      print_newline_list (fun f -> fprintf f "import %a;" print_name)
	f comp.imports;
      fprintf f "@\n@\n";
    end;
  print_decl_list f comp.decls;
  pp_print_newline f ()

and print_decl_list f =
  print_sep_list print_decl (fun f -> fprintf f "@\n@\n") f

and print_decl f d =
  match d with
  | Class c -> print_class f c
  | Interface i -> print_interface f i
  | Field fld -> fprintf f "%a;" print_field fld
  | Method m -> print_method f m
  | InstanceInit st -> fprintf f "%a" print_stmt st
  | StaticInit st -> fprintf f "static %a" print_stmt st
  | Constructor m -> print_method f m

and print_class f c =
  fprintf f "%aclass %a%a"
    print_modifiers c.cl_mods print_ident c.cl_name
    (print_option (fun f -> fprintf f "extends %a" print_name)) c.cl_super;
  if c.cl_impls <> [] then
    fprintf f " implements %a" (print_comma_list print_name) c.cl_impls;
  fprintf f " %a" print_class_body c.cl_body

and print_modifiers f mods =
  print_space_list (fun f m -> fprintf f "%s" (modifier_to_string m)) f mods;
  if mods <> [] then
    fprintf f " "

and print_class_body f body =
  fprintf f "{@\n@[<2>  %a@]@\n}" print_decl_list body

and print_interface f i =
  fprintf f "%ainterface %a" print_modifiers i.if_mods print_ident i.if_name;
  if i.if_exts <> [] then
    fprintf f " extends %a" (print_comma_list print_name) i.if_exts;
  fprintf f " %a" print_class_body i.if_body

and print_field f fld =
  fprintf f "%a%a" print_var fld.f_var
    (print_option (fun f -> fprintf f "= %a" print_init)) fld.f_init

and print_init f init =
  match init with
  | ExprInit e -> print_expr f e
  | ArrayInit inits ->
      fprintf f "{ %a }" print_init_list inits

and print_bare_expr f e =
  match e with
  | Postfix (e, op) ->
      fprintf f "%a%s" print_expr e op
  | Prefix (op, e) ->
      fprintf f "%s%a" op print_expr e
  | Assignment (e1, op, e2) ->
      fprintf f "%a %s %a" print_expr e1 op print_expr e2
  | _ -> print_expr f e

and print_expr f e =
  match e with
  | Literal s ->
      fprintf f "%s" s
  | ClassLiteral t ->
      fprintf f "%a.class" print_type t
  | NewClass (t, args, opt) ->
      fprintf f "new %a(%a)%a"
	print_type t print_expr_list args (print_option print_class_body) opt
  | NewQualifiedClass (e, id, args, opt) ->
      fprintf f "%a.new %a(%a)%a"
	print_expr e print_ident id print_expr_list args
	(print_option print_class_body) opt
  | NewArray (t, dims, n, opt) ->
      fprintf f "new %a%a%a%a"
	print_type t print_dimensions dims print_extra_dimensions n
	(print_option print_init) opt
  | Dot (e, id) ->
      fprintf f "%a.%a" print_expr e print_ident id
  | Call (e, args) ->
      fprintf f "%a(%a)" print_expr e print_expr_list args
  | ArrayAccess (e1, e2) ->
      fprintf f "%a[%a]" print_expr e1 print_expr e2
  | Postfix (e, op) ->
      fprintf f "(%a%s)" print_expr e op
  | Prefix (op, e) ->
      fprintf f "(%s%a)" op print_expr e
  | Cast (t, e) ->
      fprintf f "((%a)%a)" print_type t print_expr e
  | Infix (e1, op, e2) ->
      fprintf f "(%a %s %a)" print_expr e1 op print_expr e2
  | InstanceOf (e, t) ->
      fprintf f "(%a instanceof %a)" print_expr e print_type t
  | Conditional (e1, e2, e3) ->
      fprintf f "(%a ? %a : %a)" print_expr e1 print_expr e2 print_expr e3
  | Assignment (e1, op, e2) ->
      fprintf f "(%a %s %a)" print_expr e1 op print_expr e2
  | Name n ->
      print_name f n

and print_expr_list f =
  print_comma_list print_expr f

and print_dimensions f =
  print_list (fun f -> fprintf f "[%a]" print_expr) f

and print_extra_dimensions f n =
  if n > 0 then
    fprintf f "[]%a" print_extra_dimensions (n-1)

and print_init_list f =
  print_comma_list print_init f

and print_method f m =
  fprintf f "%a(%a)"
    print_var m.m_var (print_comma_list print_var) m.m_formals;
  if m.m_throws <> [] then
    fprintf f " throws %a" (print_comma_list print_name) m.m_throws;
  fprintf f " %a" print_stmt m.m_body

and print_var f v =
  print_modifiers f v.v_mods;
  if v.v_type <> no_type then (* special case for constructor *)
    fprintf f "%a " print_type v.v_type;
  print_ident f v.v_name

and print_stmt f stmt =
  match stmt with
  | Block [] ->
      fprintf f "{@\n}"
  | Block list ->
      fprintf f "{@\n@[<2>  %a@]@\n}" print_stmt_list list
  | LocalVar fld ->
      fprintf f "%a;" print_field fld
  | LocalClass c ->
      print_class f c
  | Empty ->
      fprintf f ";"
  | Label (lbl, st) ->
      fprintf f "%a: %a" print_ident lbl print_stmt st
  | Expr e ->
      fprintf f "%a;" print_bare_expr e
  | If (e, s1, None) ->
      fprintf f "if (%a) %a" print_expr e print_stmt s1
  | If (e, s1, Some s2) ->
      fprintf f "if (%a) %a@\nelse %a"
	print_expr e print_stmt s1 print_stmt s2
  | Switch (e, sw) ->
      fprintf f "switch (%a) %a" print_expr e print_switch sw
  | While (e, st) ->
      fprintf f "while (%a) %a" print_expr e print_stmt st
  | Do (st, e) ->
      fprintf f "do %a while (%a);" print_stmt st print_expr e
  | For (init, test, update, st) ->
      fprintf f "for (%a;%a;%t%a) %a"
	print_for_clause init
	(print_option print_expr) test
	(fun f -> if update <> [] then fprintf f " ")
	print_for_clause update
	print_stmt st
  | Break opt ->
      fprintf f "break%a;" (print_option print_ident) opt
  | Continue opt ->
      fprintf f "continue%a;" (print_option print_ident) opt
  | Return opt ->
      fprintf f "return%a;" (print_option print_expr) opt
  | Throw e ->
      fprintf f "throw %a;" print_expr e
  | Sync (e, st) ->
      fprintf f "synchronized (%a) %a" print_expr e print_stmt st
  | Try (st, catches, finally) ->
      begin
	fprintf f "try %a" print_stmt st;
	if catches <> [] then
	  fprintf f " %a" print_catches catches;
	print_option (fun f -> fprintf f "finally %a" print_stmt)
	  f finally;
      end

and print_stmt_list f =
  print_newline_list print_stmt f

and print_switch f sw =
  fprintf f "{@\n@[<2>  %a@]@\n}" (print_newline_list print_sw) sw

and print_sw f (cases, stmts) =
  fprintf f "%a@\n@[<2>  %a@]"
    (print_newline_list print_case) cases print_stmt_list stmts

and print_case f c =
  match c with
  | Case e -> fprintf f "case %a:" print_expr e
  | Default -> fprintf f "default:"

and print_for_clause f list =
  match list with
  | Expr _ :: _ -> print_comma_list print_expr_stmt f list
  | [LocalVar fld] -> print_field f fld
  | LocalVar fld :: rest ->
      fprintf f "%a, %a" print_field fld
	(print_comma_list (print_for_local_var fld.f_var.v_type)) rest
  | [] -> ()
  | _ -> invalid_arg "print_for_clause"

and print_expr_stmt f stmt =
  match stmt with
  | Expr e -> print_bare_expr f e
  | _ -> invalid_arg "print_expr_stmt"

and print_for_local_var t f st =
  let rec convert typ id =
    if typ = t then id
    else match typ with
    | ArrayType typ' -> convert typ' (synth_id (id_string id ^ "[]"))
    | TypeName _ -> failwith "print_for_local_var: convert"
  in
  match st with
  | LocalVar fld ->
      fprintf f "%a%a"
	print_ident (convert fld.f_var.v_type fld.f_var.v_name)
	(print_option (fun f -> fprintf f "= %a" print_init)) fld.f_init
  | _ -> failwith "print_for_local_var"

and print_catches f  =
  print_space_list print_catch f

and print_catch f (v, st) =
  fprintf f "catch (%a) %a" print_var v print_stmt st
