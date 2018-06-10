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

(* Operator precedence.
   Used by print_prec to eliminate unnecessary parentheses. *)

type precedence = Left of int | Right of int

let operator_precedence e =
  match e with
  | Literal _
  | ClassLiteral _
  | NewClass _
  | NewQualifiedClass _
  | NewArray _
  | Dot _
  | Call _
  | ArrayAccess _
  | Name _
    -> Left 16

  | Postfix _
    -> Left 15

  | Prefix ("++", _)
  | Prefix ("--", _)
  | Prefix ("+", _)
  | Prefix ("-", _)
    -> Right 14

  | Prefix ("~", _)
  | Prefix ("!", _)
  | Cast _
    -> Right 13

  | Infix (_, "*", _)
  | Infix (_, "/", _)
  | Infix (_, "%", _)
    -> Left 12

  | Infix (_, "+", _)
  | Infix (_, "-", _)
    -> Left 11

  | Infix (_, "<<", _)
  | Infix (_, ">>", _)
  | Infix (_, ">>>", _)
    -> Left 10

  | Infix (_, "<", _)
  | Infix (_, ">", _)
  | Infix (_, "<=", _)
  | Infix (_, ">=", _)
  | InstanceOf _
    -> Left 9

  | Infix (_, "==", _)
  | Infix (_, "!=", _)
    -> Left 8

  | Infix (_, "&", _) -> Left 7
  | Infix (_, "^", _) -> Left 6
  | Infix (_, "|", _) -> Left 5
  | Infix (_, "&&", _) -> Left 4
  | Infix (_, "||", _) -> Left 3

  | Conditional _ -> Left 2

  | Assignment _ -> Right 1

  | _ -> invalid_arg "precedence"

let precedence e =
  match operator_precedence e with
  | Left n -> (2*n, 2*n+1)
  | Right n -> (2*n+1, 2*n)

let comments = ref []

(* Print all comments that occur before position [n] in the source file.
   The global variable [comments] contains a list of comments
   in order of position.  [print] sets this to the entire list initially;
   [print_comments] removes the ones it prints, for efficiency. *)

let print_comments f n =
  let rec loop list =
    match list with
    | { Source.buffer = comment; Source.pos = m } :: rest ->
	if m < n then
	  begin
	    fprintf f "%s@\n" comment;
	    loop rest
	  end
	else
	  comments := list
    | [] ->
	comments := []
  in
  loop !comments

let print_id_comments f id = print_comments f (id_pos id)

let print_stmt_comments f stmt = print_comments f (stmt_pos stmt)

let print_remaining_comments f =
  List.iter (fun c -> fprintf f "%s@\n" c.Source.buffer) !comments;
  comments := []

let rec print f comp =
  pp_set_margin f 0;
  pp_open_box f 0;
  comments := comp.comments;
  begin
    match comp.package with
    | Some pkg ->
	print_id_comments f (List.hd pkg);
	fprintf f "package %a;@\n@\n" print_name pkg
    | None -> ()
  end;
  if comp.imports <> [] then
    begin
      print_newline_list (fun f -> fprintf f "import %a;" print_name)
	f comp.imports;
      fprintf f "@\n@\n";
    end;
  print_decls f comp.decls;
  pp_print_newline f ();
  print_remaining_comments f;

and print_decls f =
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
  print_id_comments f c.cl_name;
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
  fprintf f "{@\n@[<2>  %a@]@\n}" print_decls body

and print_interface f i =
  print_id_comments f i.if_name;
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
      fprintf f "{ %a }" print_inits inits

and print_prec prec f e =
  let (left, right) = precedence e in
  if prec > min left right then
    fprintf f "(%a)" print_expr e
  else
    match e with
    | Literal s ->
	fprintf f "%s" s
    | ClassLiteral t ->
	fprintf f "%a.class" print_type t
    | NewClass (t, args, opt) ->
	fprintf f "new %a(%a)%a"
	  print_type t print_exprs args (print_option print_class_body) opt
    | NewQualifiedClass (e, id, args, opt) ->
	fprintf f "%a.new %a(%a)%a"
	  (print_prec left) e print_ident id print_exprs args
	  (print_option print_class_body) opt
    | NewArray (t, dims, n, opt) ->
	fprintf f "new %a%a%a%a"
	  print_type t print_dimensions dims print_extra_dimensions n
	  (print_option print_init) opt
    | Dot (e, id) ->
	fprintf f "%a.%a" (print_prec left) e print_ident id
    | Call (e, args) ->
	fprintf f "%a(%a)" (print_prec left) e print_exprs args
    | ArrayAccess (e1, e2) ->
	fprintf f "%a[%a]" (print_prec left) e1 print_expr e2
    | Postfix (e, op) ->
	fprintf f "%a%s" (print_prec left) e op
    | Prefix (op, e) ->
	fprintf f "%s%a" op (print_prec right) e
    | Cast (t, e) ->
	fprintf f "(%a)%a" print_type t (print_prec right) e
    | Infix (e1, op, e2) ->
	fprintf f "%a %s %a" (print_prec left) e1 op (print_prec right) e2
    | InstanceOf (e, t) ->
	fprintf f "%a instanceof %a" (print_prec left) e print_type t
    | Conditional (e1, e2, e3) ->
	fprintf f "%a ? %a : %a"
	  (print_prec left) e1 (print_prec left) e2 (print_prec right) e3
    | Assignment (e1, op, e2) ->
	fprintf f "%a %s %a" (print_prec left) e1 op (print_prec right) e2
    | Name n ->
	print_name f n

and print_expr f = print_prec 0 f

and print_exprs f =
  print_comma_list print_expr f

and print_dimensions f =
  print_list (fun f -> fprintf f "[%a]" print_expr) f

and print_extra_dimensions f n =
  if n > 0 then
    fprintf f "[]%a" print_extra_dimensions (n-1)

and print_inits f =
  print_comma_list print_init f

and print_method f m =
  fprintf f "%a(%a)"
    print_var m.m_var (print_comma_list print_var) m.m_formals;
  if m.m_throws <> [] then
    fprintf f " throws %a" (print_comma_list print_name) m.m_throws;
  fprintf f " %a" print_stmt m.m_body

and print_var f v =
  print_id_comments f v.v_name;
  print_modifiers f v.v_mods;
  if v.v_type <> no_type then (* special case for constructor *)
    fprintf f "%a " print_type v.v_type;
  print_ident f v.v_name

and print_stmt f stmt =
  match stmt with
  | Block [] ->
      fprintf f "{@\n}"
  | Block stmts ->
      fprintf f "{@\n@[<2>  %a@]@\n}" print_stmts stmts
  | LocalVar fld ->
      fprintf f "%a;" print_field fld
  | LocalClass c ->
      print_class f c
  | Empty ->
      fprintf f ";"
  | Label (lbl, st) ->
      fprintf f "%a: %a" print_ident lbl print_stmt st
  | Expr e ->
      fprintf f "%a;" print_expr e
  | If (e, st, None) ->
      fprintf f "if (%a)%a" print_expr e print_body st
  | If (e, s1, Some s2) ->
      begin
	fprintf f "if (%a)%a" print_expr e print_body s1;
	(match s1 with
	| Block (_ :: _) -> fprintf f " "
	| _ -> fprintf f "@\n");
	fprintf f "else";
	(match s2 with
	| If _ -> fprintf f " %a" print_stmt s2
	| _ -> print_body f s2)
      end
  | Switch (e, sw) ->
      fprintf f "switch (%a) %a" print_expr e print_switch sw
  | While (e, st) ->
      fprintf f "while (%a)%a" print_expr e print_body st
  | Do (st, e) ->
      fprintf f "do%a while (%a);" print_body st print_expr e
  | For (init, test, update, st) ->
      fprintf f "for (%a;%a;%t%a)%a"
	print_for_clause init
	(print_option print_expr) test
	(fun f -> if update <> [] then fprintf f " ")
	print_for_clause update
	print_body st
  | Break opt ->
      fprintf f "break%a;" (print_option print_ident) opt
  | Continue opt ->
      fprintf f "continue%a;" (print_option print_ident) opt
  | Return opt ->
      fprintf f "return%a;" (print_option print_expr) opt
  | Throw e ->
      fprintf f "throw %a;" print_expr e
  | Sync (e, st) ->
      fprintf f "synchronized (%a)%a" print_expr e print_body st
  | Try (st, catches, finally) ->
      begin
	fprintf f "try %a" print_stmt st;
	if catches <> [] then
	  fprintf f " %a" print_catches catches;
	print_option (fun f -> fprintf f "finally %a" print_stmt)
	  f finally;
      end

and print_stmts f =
  print_newline_list (fun f s -> print_stmt_comments f s; print_stmt f s) f

and print_body f st =
  match st with
  | Block (_ :: _) -> fprintf f " %a" print_stmt st
  | _ -> fprintf f "@\n@[<2>  %a@]" print_stmt st

and print_switch f sw =
  fprintf f "{@\n@[<2>  %a@]@\n}" (print_newline_list print_sw) sw

and print_sw f (cases, stmts) =
  fprintf f "%a@\n@[<2>  %a@]"
    (print_newline_list print_case) cases print_stmts stmts

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
  | Expr e -> print_expr f e
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
