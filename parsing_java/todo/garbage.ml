let ident s n = { id = s; pos = n }

let id_string ident = ident.id

let id_pos ident = ident.pos




(* Find the position of a syntactic structure, or -1 if undefined. *)





let opt_id_pos opt =
  match opt with
  | Some id -> id_pos id
  | None -> -1

let var_pos var = id_pos var.v_name



(*****************************************************************************)
(* position *)
(*****************************************************************************)

let rec type_pos t =
  match t with
  | TypeName name -> id_pos (List.hd name)
  | ArrayType t' -> type_pos t'

let rec stmt_pos stmt =
  match stmt with
  | Block [] -> -1
  | Block stmts -> stmts_pos stmts
  | LocalVar fld -> var_pos fld.f_var
  | LocalClass c -> id_pos c.cl_name
  | Empty -> -1
  | Label (lbl, _) -> id_pos lbl
  | Expr e -> expr_pos e
  | If (e, s1, opt) ->
      let n = expr_pos e in
      if n <> -1 then n
      else
	let n = stmt_pos s1 in
	if n <> -1 then n
	else
	  (match opt with
	  | Some s2 -> stmt_pos s2
	  | None -> -1)
  | Switch (e, sw) ->
      let n = expr_pos e in
      if n <> -1 then n
      else switch_pos sw
  | While (e, st) ->
      let n = expr_pos e in
      if n <> -1 then n
      else stmt_pos st
  | Do (st, e) ->
      let n = stmt_pos st in
      if n <> -1 then n
      else expr_pos e
  | For (init, test, update, st) ->
      let n = stmts_pos init in
      if n <> -1 then n
      else
	let n = (match test with Some e -> expr_pos e | None -> -1) in
	if n <> -1 then n
	else stmts_pos (update @ [st])
  | Break opt -> opt_id_pos opt
  | Continue opt -> opt_id_pos opt
  | Return opt ->
      (match opt with Some e -> expr_pos e | None -> -1)
  | Throw e -> expr_pos e
  | Sync (e, st) ->
      let n = expr_pos e in
      if n <> -1 then n
      else stmt_pos st
  | Try (st, catches, Some f) ->
      let n = stmt_pos st in
      if n <> -1 then n
      else
	let n = catches_pos catches in
	if n <> -1 then n
	else stmt_pos f
  | Try (st, catches, None) ->
      let n = stmt_pos st in
      if n <> -1 then n
      else catches_pos catches

and stmts_pos list =
  match list with
  | s :: rest ->
      let n = stmt_pos s in
      if n <> -1 then n
      else stmts_pos rest
  | [] -> -1

and expr_stmt_pos e s =
  let n = expr_pos e in
  if n <> -1 then n
  else stmt_pos s

and switch_pos list =
  match list with
  | (cases, stmts) :: rest ->
      let n = cases_pos cases in
      if n <> -1 then n
      else
	let n = stmts_pos stmts in
	if n <> -1 then n
	else switch_pos rest
  | [] -> -1

and cases_pos list =
  match list with
  | Case e :: rest ->
      let n = expr_pos e in
      if n <> -1 then n
      else cases_pos rest
  | Default :: rest -> cases_pos rest
  | [] -> -1

and expr_pos e =
  match e with
  | Literal _ -> -1
  | ClassLiteral t -> type_pos t
  | NewClass (t, _, _) -> type_pos t
  | NewQualifiedClass (e, id, _, _) ->
      let n = expr_pos e in
      if n <> -1 then n
      else id_pos id
  | NewArray (t, dims, _, opt) ->
      let n = type_pos t in
      if n <> -1 then n
      else
	let n = exprs_pos dims in
	if n <> -1 then n
	else
	  (match opt with
	  | Some init -> init_pos init
	  | None -> -1)
  | Dot (e, id) ->
      let n = expr_pos e in
      if n <> -1 then n
      else id_pos id
  | Call (e, args) ->
      let n = expr_pos e in
      if n <> -1 then n
      else exprs_pos args
  | ArrayAccess (e1, e2) ->
      let n = expr_pos e1 in
      if n <> -1 then n
      else expr_pos e2
  | Postfix (e, _) -> expr_pos e
  | Prefix (_, e) -> expr_pos e
  | Cast (t, e) ->
      let n = type_pos t in
      if n <> -1 then n
      else expr_pos e
  | Infix (e1, op, e2) ->
      let n = expr_pos e1 in
      if n <> -1 then n
      else expr_pos e2
  | InstanceOf (e, t) ->
      let n = expr_pos e in
      if n <> -1 then n
      else type_pos t
  | Conditional (e1, e2, e3) ->
      let n = expr_pos e1 in
      if n <> -1 then n
      else
	let n = expr_pos e2 in
	if n <> -1 then n
	else expr_pos e3
  | Assignment (e1, _, e2) ->
      let n = expr_pos e1 in
      if n <> -1 then n
      else expr_pos e2
  | Name name ->
      id_pos (List.hd name)

and exprs_pos list =
  match list with
  | e :: rest ->
      let n = expr_pos e in
      if n <> -1 then n
      else exprs_pos rest
  | [] -> -1

and init_pos init =
  match init with
  | ExprInit e -> expr_pos e
  | ArrayInit inits -> inits_pos inits

and inits_pos list =
  match list with
  | init :: rest ->
      let n = init_pos init in
      if n <> -1 then n
      else inits_pos rest
  | [] -> -1

and catches_pos list =
  match list with
  | (var, stmt) :: rest ->
      let n = var_pos var in
      if n <> -1 then n
      else
	let n = stmt_pos stmt in
	if n <> -1 then n
	else catches_pos rest
  | [] -> -1
