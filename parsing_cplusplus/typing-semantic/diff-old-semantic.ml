(*
--- semantic-orig.ml	2006-07-25 20:03:17.000000000 +0200
+++ semantic.ml	2006-07-25 20:03:17.000000000 +0200
 
-let (lookup_big:   string -> fullTable -> bigNameSpace) = fun s (up,cur) -> 
-  (cur::up) +> List.fold_left (fun acc {big =  xs} -> acc @ [xs]) [] +> lookup_list s

-let (lookup_tags:  string -> fullTable -> tags) = fun s (up,cur) ->    
-  (cur::up) +> List.fold_left (fun acc {tags = xs} -> acc @ [xs]) [] +> lookup_list s 

+let add_tags (s,v) = cur := {!cur with tags = (s,v)::!cur.tags}
+let add_big  (s,v) = cur := {!cur with big  = (s,v)::!cur.big}
   
+let add_field s = cur := {!cur with fieldname = s::!cur.fieldname}
+
+let tag_it() = List.length !up
+
+
+
+let (look_tags_at: (string * int) -> tags option) = fun (s,i) -> 
+  let {tags = l}  = (try (!cur::!up) +> List.rev +> (flip List.nth) i with _ -> internal_error "not good index") in
+  optionise (fun () -> List.assoc s l)
+  
   
-type emptyDecl = EmptyDecl | NotEmpty (* for obscure struct t *)
 
-let (check_compatible: fullTable -> fullType -> fullType -> unit)     = fun (up,cur) fullt1 fullt2 -> ()
-let (composite:        fullTable -> fullType -> fullType -> fullType) = fun (up,cur) fullt1 fullt2 -> fullt1
-let equal_modulo_struct tab typ1 typ2 = true
+let constant i = Constant (Int (i, (Si (Signed, CInt))))
 
 
-let constant i = Constant (Int (0, CInt))
 
-let addQualif = function
-  | ({const=true},    ({const=true} as x)) -> warning "duplicate 'const'" x
-  | ({volatile=true}, ({volatile=true} as x)) -> warning "duplicate 'volatile'" x
-  | ({const=true},    v) -> {v with const=true}
-  | ({volatile=true}, v) -> {v with volatile=true}
-  | _ -> failwith "internal error: there is no noconst or novolatile keyword"
 
 
-type 'a check_context  = fullTable  -> 'a -> symbolTable
 
 let (check: program -> unit) = fun p -> 
 
-  let rec (check_decl: declaration check_context) = fun (up,cur) x -> 
-    let is_outer = List.length up = 0 in
+  let rec (check_decl: declaration -> unit) = fun x -> 
+    let is_outer = List.length !up = 0 in
     match x with
     | (Decl (None, _,               StoTypedef)) -> raise (Semantic "useless typedef") (* gccw *)
     | (Decl (Some (_, Some _), _,   StoTypedef)) -> raise (Semantic "typedef is initialised")
     | (Decl (Some (s, None), fullt, StoTypedef)) -> 
-	let (cur, fullt1) = check_type (up,cur) NotEmpty fullt in
+	let fullt1 = check_type fullt in
-	(match (optionise2 List.assoc) s cur.big   with
-	 | None ->  {cur with big = (s, TypedefN fullt1)::cur.big }
+	(match lookhere_big s    with
+	 | None ->  add_big (s, TypedefN fullt1)
 	 | Some (TypedefN fullt2) -> 
-	       if equal_modulo_struct (up,cur) fullt1 fullt2
+	       if equal_modulo_struct fullt1 fullt2

-		   but need kind of =modulo (not saying int* = unsigned*, but with struct complet et incomplet)
+		   but need kind of =modulo (not saying int* = unsigned*, but with struct 
+		    complet et incomplet)
 		   = modulostruct, work only if same name !! if 2 struct compatible, does not matter 
 		   but it a bit gcc specific, tout ca pour un mesg d'erreur ? yes
 		
@@ -133,37 +360,69 @@ let (check: program -> unit) = fun p -> 

-    | Decl (None, _, Sto _) -> raise (Semantic "useless keyword or type name in empty declaration") (* gccw *)
-    | Decl (None, (nullQualif, StructUnion (_,(None, _))),NoSto) -> 
-	raise (Semantic "unnamed struct/union that defines no instances, pad: you must declare a tag") (* gccw *)
-    | Decl (None, (nullQualif, (StructUnion (_, (Some _, _)) | Enum _  | StructUnionName (_,_) | EnumName _) as t),NoSto) 
-      -> let (cur, _) = check_type (up,cur) t in cur
-    | Decl (None, _, _)                             -> raise (Semantic "empty declaration") (* gccw *)
-    | Decl (_,_, Sto (Auto|Register)) when is_outer -> raise (Semantic "auto/register not appropriate here")
+    | Decl (None, _, Sto _) -> 
+	raise (Semantic "useless keyword or type name in empty declaration") (* gccw *)
+    | Decl (None, (nQ, StructUnion (None, _)),     NoSto) -> 
+	raise (Semantic "unnamed struct/union that defines no instances") (* gccw *)
+    | Decl (None, (nQ, StructUnionName ((s,_),t)), NoSto) -> 
+	(* obscure empty struct t; to handle inner mutually recursive struct def *)
+	((if not is_outer &&
+	  (match lookup_tags s with 
+	  | Some ((TagStruct (t2,_)|(TagStructName t2)),_) when t2 = t -> true 
+	  | _ -> false)
+	then ()
+	else warning "cant really see why you use the obscure construct empty struct t in this context, not needed" ())
+	;ignore (check_type (nQ, StructUnionName ((s, -2),t))) (* != -1 => we will be able to make diff in check_type *)
+	)
+    | Decl (None, (nQ, (StructUnion (Some _,_) | Enum _  ) as t),NoSto) -> ignore (check_type t)
+    | Decl (None, (nQ, EnumName (s,_) as t),NoSto) -> 
+	(* same kind of empty struct t; if do   enum t i; int f1() { enum t; extern enum t i; }, we want error *)
+	((if not is_outer &&
+	  (match lookup_tags s with 
+	  | Some ((TagEnumName | TagEnum _),_) -> true
+	  | _ -> false)
+	then ()
+	else warning "cant really see why you need the obscure empty enum t in this context, not needed" ())
+	;ignore (check_type (nQ, EnumName (s,-2)))
+	)
+    | Decl (None, _, _)                             -> 
+	raise (Semantic "empty declaration") (*gccw*)
+    | Decl (_,_, Sto (Auto|Register)) when is_outer -> 
+	raise (Semantic "auto/register not appropriate here")
 	  
     | Decl (Some (s, ini), fullt, sto) -> 
-	let (cur, fullt1) = check_type (up,cur) fullt in
+	let fullt1 = check_type fullt in
 	(match fullt1, sto, is_outer with
 	| (((_,FunctionType _),_,_)|(_,Sto Extern,_)|(_,_,true)) -> 
-	    let cur = check_up (up,cur) (s, fullt1, sto, is_outer) in
+	    (check_up (s, fullt1, sto, is_outer);
 	    (match ini, sto, is_outer, fullt1 with
-	    | (None,   _,_,_)               -> cur
-	    | (Some i, Sto Extern, false,_)      -> raise (Semantic "TODO inner decl has both extern and initialiser")
-	    | (Some i, _,_, (_, FunctionType _)) -> raise (Semantic "function TODO is initialized like a variable")
-	    | (Some i, _, false,_) -> failwith "internal error: not outer => must be func or extern, and catched before"
-	    | (Some i, _, true,_) -> check_ini (up,cur) (StaticIni, s, fullt1, i)
+	     | (None,   _,_,_)               -> ()
+	     | (Some i, Sto Extern, false,_)      -> 
+		 raise (Semantic "TODO inner decl has both extern and initialiser")
+	     | (Some i, _,_, (_, FunctionType _)) -> 
+		 raise (Semantic "function TODO is initialized like a variable")
+	     | (Some i, _, false,_) -> 
+		 internal_error "not outer => must be func or extern, and catched before"
+	     | (Some i, _, true,_) -> check_ini (StaticIni, fullt1, i)
+	     )
 	    )
-	    (match (optionise2 List.assoc) s cur.big with
+	    let _ = check_know_storage_size fullt1 in
+	    (match lookhere_big s with
 	    | None -> 
 		(match ini with 
-		| None ->      {cur with big = (s, Object (NoLinkage, fullt1))::cur.big }
-		| Some i -> let cur = check_ini (up,cur) ((if sto=Sto Static then StaticIni else DynamicIni), s, fullt,i) 
-		            in {cur with big = (s, Object (NoLinkage, fullt1))::cur.big }
+		| None -> add_big (s, Object (NoLinkage, fullt1))
+		| Some i -> 
 		)
-	    | Some _ -> raise (Semantic "TODO already used as a var or a typedef or enum or extern or ...TODO")
+		
 	    )
+	    | Some _ -> 
+		raise (Semantic "TODO already used as a var or a typedef or enum or extern or TODO")
 	)
+	)
+  (* when  (((_,FunctionType _),_,_)|(_,Sto Extern,_)|(_,_,true)) *)
+  and (check_up: (string * finalType * storage * bool) -> unit) = 
+    fun (s,fullt,sto,is_outer) -> 
+      let current_found = lookhere_big s in
 
-  and (check_up: fullTable -> (string * fullType * storage * bool) -> symbolTable) = 
-    fun (up,cur)  (s,fullt,sto,is_outer) -> 
-      let current_found = (optionise2 List.assoc) s cur.big in
-      let up_found      = (optionise2 List.assoc) s (try up +>List.rev +> List.hd with Not_found -> emptyTable).big in

+      let up_found      = (optionise2 List.assoc) s 
+	  (try !up +>List.rev +> List.hd with Not_found -> emptyTable).big in
+

       | (Some (Object ((Internal|External) as i, varfunc)), _)   -> Some (i, varfunc, true)
-      |	(Some (Object (NoLinkage,_)), _) -> raise (Semantic "redeclaration of TODO")
-      |	(Some _,_)                       -> raise (Semantic "TODO redeclared as different kind of symbol")
+      |	(Some (Object (NoLinkage,_)), _) -> 
+	  raise (Semantic "redeclaration of TODO")
+      |	(Some _,_)                       -> 
+	  raise (Semantic "TODO redeclared as different kind of symbol")
       | (None, Some (Object ((Internal|External) as i,varfunc))) -> Some (i, varfunc, false)
-      |	(None, Some (Object (NoLinkage,_))) -> failwith "internal error: outer cant be NoLink" 
-      |	(None, Some _) -> raise (Semantic "TODO redeclared as different kind of symbol")
+      |	(None, Some (Object (NoLinkage,_))) -> 
+	  internal_error "outer cant be NoLink" 
+      |	(None, Some _) -> 
+	  raise (Semantic "TODO redeclared as different kind of symbol")
       in
       let previous_linkage = (match stoAndTypeAndSameNS with None -> External | Some (i,_,_) -> i) in
 	(match (sto, fullt, is_outer) with
 	| (NoSto, (_,(FunctionType _)),_) -> previous_linkage
 	| (NoSto, notfunc, true) -> External
-	| (NoSto, notfunc, false) -> failwith "internal error: so the obj must be NoLink and so we cant get called"
+	| (NoSto, notfunc, false) -> 
+	    internal_error "so the obj must be NoLink and so we cant get called"
 	| (Sto Static,_,true) -> Internal
-	| (Sto Static,(_,(FunctionType _)),false) -> raise (Semantic "inner decl of func cant be static")(* nogcc ?*)
-	| (Sto Static,_,false) -> failwith "internal error: obj must be NoLink"
-	| (Sto (Auto|Register),(_,(FunctionType _)),_) -> raise (Semantic "not allowed keyword") (* nogcc ? gcc accepe top auto ? *)
-	| (Sto (Auto|Register),notfunc,_) -> failwith "internal error: not allowed outer,or if inner then must be NoLink"
-	| (StoTypedef,_,_) -> failwith "internal error: must be filtered by check_decl"
+	| (Sto Static,(_,(FunctionType _)),false) -> 
+	    raise (Semantic "inner decl of func cant be static")(* nogcc ?*)
+	| (Sto Static,_,false) -> internal_error "obj must be NoLink"
+	| (Sto (Auto|Register),(_,(FunctionType _)),_) -> 
+	    raise (Semantic "not allowed keyword") (* nogcc ? gcc accepe top auto ? *)
+	| (Sto (Auto|Register),notfunc,_) -> 
+	    internal_error "not allowed outer,or if inner then must be NoLink"
+	| (StoTypedef,_,_) -> internal_error "must be filtered by check_decl"
 	| (Sto Extern,_,_) -> previous_linkage
 	)
       in
       (match (storage, stoAndTypeAndSameNS) with
-	  | (i, None) -> {cur with big = (s, Object (i, fullt))::cur.big}
+	  | (i, None) -> add_big (s, Object (i, fullt))
 	  | (i, Some (j, fullt2, sameNs)) when i = j -> 
-	      (check_compatible (up, cur) fullt fullt2; 
-	       {cur with big = (s, Object (i, if sameNs then composite (up,cur) fullt fullt2 else fullt))::cur.big}
+	      (let t = check_compatible (fullt,fullt2) in
+	       add_big (s, Object (i, if sameNs then t else fullt))
 	      )
 	  | (i, Some (j, _, _)) -> raise (Semantic "not same linkage, conflicting declaration")
       )
@@ -219,88 +493,53 @@ let (check: program -> unit) = fun p -> 
 
 	  

-  and (check_type: fullTable -> fullType -> (symbolTable * fullType)) = fun (up,cur) f -> 
-    (match one_step (up,cur) f with 
-    | (_, BaseType _) -> (cur, f)
-    | (q, Pointer f)  -> let (cur', f') = check_type (up,cur) f in (cur', (q, Pointer f'))
-    )
- *
-    | (_, Enum x) ->  evalInt,
-    
-CHECK valid POINTER
-    | (q, Array (expr, f)) -> 
-	order is important, struct t { int i,j;} a[sizeof(struct t)]; must be valid
-	let (cur, f') = check_type (up,cur) f in
-	let (cur, i)  = evalInt (up,cur) expr in
-have a finaltype (that handle mutuel recursive struct and obscure struct t; declaration)
- and handle mark
-have a make_final_type (perhaps it is the role of check_type to do that too)
-better bitfield type, better type (no typename ?)
-CHECK valid array
-CHECK if use tab and misuse v, must thread the cur !!
-mark struct !!
-  when struct, if already present ?
-stdC: 
-The translator alters any              
-   declaration you write at parameter level with type function returning T to type pointer to function returning T,       
-   which is an object type.                                                         
-
-TODO obscure empty struct t which mean allocate new !! => need know when check_type
- is called with an empty decl or not
-	
-  and (one_step: fullTable -> fullType -> fullType) = fun (up,cur) f -> 
+  and (check_type: fullType -> finalType) = fun f -> 
     (match f with
-    | (q,TypeName s) -> 
-	(try (match lookup_big s (up,cur) with
-	     | (TypedefN (q2,t)) -> (addQualif (q,q2), t)
-	     | _ -> failwith "internal error: if we see a typename, then cant have enum or var declared"
+    | (_, BaseType _) -> f
+    | (q, Pointer f)  -> (q, Pointer (check_type f))
+
 	     )
-	with Not_found -> failwith "internal error: if typename then must have been declared"
 	)
- * XXX
-    | (q, StructUnionName (su, (s,_))) -> 
-	(try (match lookup_tags s (up,cur) with
-	     | 
 	     )
-	with Not_found -> 
- *
-    | f -> f
     )
 	

-  faudra l'adder a current aussi
+
+do a call to check_expr
  
-  and (check_ini: (scopedTable * symbolTable) -> (initialiserType * string * fullType * initialiser) -> symbolTable) = 
-    fun (up,cur) (iniType, s, f,ini) ->
-      cur
+  and (check_ini: (initialiserType * fullType * initialiser) -> unit) = 
+    fun (iniType, f,ini) ->
+      ()
 
-  and (check_member: fullTable -> field -> (symbolTable * field)) = fun (up,cur) x -> 
+  and (check_member: field -> field list) = fun x -> 
     | (Simple (s, fullt)) -> 
-	if List.mem s cur.fieldname then raise (Semantic "duplicate member TODO")
-	else let (cur,fullt1) = check_type (up,cur) fullt in ({cur with fieldname = s::cur.fieldname}, Simple (s, fullt1))
+	if List.mem s !cur.fieldname then raise (Semantic "duplicate member TODO")
+	else (add_field s; [Simple (s, check_type fullt)])
     | (BitField (name, fullt, expr)) -> 
-	let (cur,fullt1)  = check_type (up,cur) fullt in
-	let (cur,i)       = evalInt    (up,cur) expr  in
-	let cur = 
+	let fullt1  = check_type fullt in
+	let i       = evalInt   expr  in
+	(
 	  (match name with 
-	  | None -> cur
-	  | Some s when List.mem s cur.fieldname -> raise (Semantic "duplicate member TODO")
-	  | Some s -> {cur with fieldname = s::cur.fieldname}
-	  ) in
-	let _ = 
+	 | None -> ()
+	 | Some s when List.mem s !cur.fieldname -> raise (Semantic "duplicate member TODO")
+	 | Some s -> add_field s
+	 );
 	(match (name, fullt1, i) with
-	| (Some _, _, 0)            -> raise (Semantic "zero width for bit-field TODO")
+	 | (Some _, _, "0")            -> raise (Semantic "zero width for bit-field TODO")
 	| (_,(_, BaseType Void), _) -> raise (Semantic "field declared void")
 	| (_,(_, BaseType (IntType t)), i) -> check_size_bitfield t i

-	| (_,(_, (Enum _ | EnumName _) as enum), i) -> check_enum_size_bitfield tab enum i 
+	 | (_,(_, (Enum _ | EnumName _) as enum), i) -> check_enum_size_bitfield enum i 
 	| _ -> raise (Semantic "bit-field TODO has invalid type")
+	 );
+	 [BitField (name, fullt1, constant i)]
 	      ) 
-	in (cur, BitField (name, fullt1, constant i))
+    | (DefStruct (s, e)) -> (ignore (check_type (nQ, (StructUnion (Some s, e))));[])
+    | (DefEnum (s,e)) ->    (ignore (check_type (nQ, (Enum (Some s, e)))); [])
    
 
-  and (check_funcdef: definition check_context) = fun ((up,cur) as tab) f -> 
+  and (check_funcdef: definition -> unit) = fun f -> 
-    cur
+    ()
 
-  and (check_parameter: parameterTypeDef check_context) = fun ((up,cur) as tab) f -> 
+  and (check_parameter: parameterTypeDef -> parameterTypeDef) = fun f -> f


-    cur
-  and (check_block: declaration check_context) = fun ((up,cur) as tab) f -> 
+  and (check_block: declaration -> unit) = fun  f -> 

-    check_decl tab f
-  and (check_prototype: parameterTypeDecl check_context) = fun ((up,cur) as tab) f -> 
+    check_decl f
+  and (check_prototype: parameterTypeDecl -> parameterTypeDecl) = fun f -> f
     *
-    cur
-  and (check_typename: fullType check_context) = fun ((up,cur) as tab) f -> 
+  and (check_typename: fullType -> fullType) = fun f -> f

-    cur
 
 
-  and (evalInt: (scopedTable * symbolTable) -> constExpression -> (symbolTable * int)) = fun ((up,cur) as tab) x -> 
-    (cur,0)
+  and (evalInt: constExpression -> string) = fun  x -> "0"
   
 
-let maxValueNum _ = 1
 
-let rec containOld = function
-  | (_, FunctionType (_, Old _)) -> true
-  | (_, FunctionType (_, Classic _)) -> false
-  | (_, Pointer f) -> containOld f
-  | (_, Array (_,f)) -> containOld f
-  | (_, StructUnion (_,_, fields)) -> or_list (fields +> List.map (function (Simple (s,f)) -> containOld f
-                                                                          | (BitField (s,f,_)) -> containOld f))
-	    | (_,_, typ)  when containOld typ ->raise(Semantic "parameter names (without types) in function declaration")

  *)
