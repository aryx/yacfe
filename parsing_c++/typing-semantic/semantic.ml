open Common
open Commonop
open AbstractSyntax

exception Semantic of string

(*****************************************************************************)
(* 
 the different namespaces stdC: 

 You introduce two new name spaces with every block that you write.
 One name space includes all functions, objects, type definitions, and
 enumeration constants that you declare or define within the block.
 The other name space includes all enumeration, structure, and union
 tags that you define within the block.

 You introduce a new member name space with every structure or union
 whose content you define. You identify a member name space by the
 type of left operand that you write for a member selection operator,
 as in x.y or p->y. A member name space ends with the end of the block
 in which you declare it.

 You introduce a new goto label name space with every function
 definition you write. Each goto label name space ends with its
 function definition.

 object can have only one storage => I made an or-type and not a
 record for linkage. 

 stdC : do not declare the same name with both
 internal linkage and external linkage in the same translation unit.

 scope can allow it ? no cos when inner, the only form allowed is
 extern and it takes previous, so the bug will be detected
  
 Inv: 

  - cant have NoLinkage at top, 
  
  - never same name in string (assoc is a function) TODO? put big and
    tags as a function ?)

  - type in symbolTable are "finalised" (= type finalType) to simplify PM, ...

      - dont contain typename

      - contain only constant (process constExpression)

      - better bitfieldType

      - no struct with name (but structname), the structdef is in tags

      - no enum (replace by its corresponding int) (but enumname)

 label: ... in fact special TODO ? cos when enter block, you have not
 another namespace for label same for Internal et External, ils sont
 uniquement at file_level (sure ? en fait non car kan inner redeclare,
 on take previous !!)
 
*)
type finalType = fullType

type symbolTable = {big:     (string * bigNameSpace)   list
		   ;tags:    (string * tags)           list
		   ;label:     string list 
		   ;fieldname: string list
		   } 
     and bigNameSpace   = TypedefN     of finalType
                        | EnumConstant of string (* name of his type *)
                        | Object       of linkage * finalType
	 and linkage = Internal | External | NoLinkage

     and tags = | TagStruct of structType    | TagStructName of structUnion
		| TagEnum   of intType       | TagEnumName

type scopedTable = symbolTable list
type fullTable   = scopedTable * symbolTable

let emptyTable = {big = []; tags = []; label = []; fieldname = []}

(* 
estet: better have global for scopedTable ? cool cos avoid passing
parameters, bad for scope cos recursion make the scoped mechanism
implicit, so ? I pass scopedTable, I dont flatten it cos i can have
same name in different namespace !!

  check_context : scoped, current scope   -> new current scope

I dont return a fullTable cos only the current scope can be altered,
we never modify up

  type 'a check_context  = fullTable  -> 'a -> symbolTable

estet: in the same time, thread symboltable sucks, we can easily forget to
thread by using not good names, it burden the code (up,cur) everwhere
and let destructurant

 ex: let check_type ... = 
    | (q, Pointer f)  -> let (cur, f') = check_type (up,cur) f in (cur, (q, Pointer f'))

  in place of prettier

    | (q, Pointer f)  -> (q, Pointer (check_type f))

estet: it burden type too. and after all, the fact that all the func take
(up,cur) and return cur, make the use of global lucid, we dont need
old value of cur,...

*)

let cur = ref emptyTable
let up  = ref []





(* TODO, not first class field name sucks *)
let (lookup_big:   string -> bigNameSpace option) = (fun s -> optionise 
  (fun () -> (!cur::!up) +> List.fold_left (fun acc {big =  xs} -> acc ++ [xs]) [] +> lookup_list s))

(* int correspond to the depth of this tags, so will help to tag *)
let (lookup_tags:  string -> (tags * int) option) = (fun s -> optionise 
  (fun ()  -> 
    (* if lookup_list2 in list of length 3 found elem at 2 ( = end of list <=> toplevel decl)
       we must return a tag = 0 ===> len - i *)
    let lookup_list2_fix s xxs = let (res, i) = lookup_list2 s xxs in (res, List.length xxs - i)
    in 
    (!cur::!up) +> List.fold_left (fun acc {tags = xs} -> acc ++ [xs]) [] +> lookup_list2_fix s)
    )

let optionise2 f = fun a b -> optionise (fun () -> f a b)

let lookhere_big  s = (optionise2 List.assoc) s !cur.big
let lookhere_tags s = (optionise2 List.assoc) s !cur.tags

let add_tags (s,v) = cur := {!cur with tags = (s,v)::!cur.tags}
let add_big  (s,v) = cur := {!cur with big  = (s,v)::!cur.big}

let add_field s = cur := {!cur with fieldname = s::!cur.fieldname}

let tag_it() = List.length !up



let (look_tags_at: (string * int) -> tags option) = fun (s,i) -> 
  let {tags = l}  = (try (!cur::!up) +> List.rev +> (flip List.nth) i with _ -> internal_error "not good index") in
  optionise (fun () -> List.assoc s l)
  
let (fix_enum_struct: finalType -> fullType) = fun (q, t) -> 
  (q, 
   match t with
   | EnumName (s,i) -> 
      (match look_tags_at (s,i) with
      |	(None | (Some TagEnumName)) -> t
      |	Some (TagEnum e) -> BaseType (IntType e)
      |	_ -> internal_error "semantic check not correctly done"
      )
   | StructUnionName ((s,i),su) -> 
       (match look_tags_at (s,i) with
       | (None | Some (TagStructName _)) -> t
       | Some (TagStruct (su2, fields)) when su = su2 -> StructUnion (None, (su, fields))
       | _ -> internal_error "same"
       )
   | e -> e
  )


(*****************************************************************************)

(* 
Do the check on inferSize here. Just kind of invariant on AST and
possibly the compute the actual value (=> need change AST type with
(int64 option), ...).

Fill in check_enum (can be many type, if there is an unsigned, long,
...). If negative and overflow signed long ? Does ansi C allow long
enum ? cos conflict with promote to int. Can make reference to
preceding label !!! thread check_struct, ... Do link between all the
ckeck.

know_storage : dont care extern, incomplete if pointer, ... Must do
know_storage after each variable, not wait until all have been
declared. Pour array, pour verifier que elem sont pas incomplete type
(genre struct) c'est a la fin !! Pas au moment ou on declare, si on
complete la struct apres la def de l'array, gcc dit ok. num t not
defined en local, know size ?

When outer, then can have temporally incomplete, but at the end of the
file, all must be complete.


Do fulltype2. Will see what is related to codegen (internal) and what
is typechecking (external, ...). Pb: need keep structname, kan turn a
struct pointer in void pointer, cos when do p->m, need to know what m
(to know what decalage to do) => need keep structname, ... => in decl,
must return the var AND the structDef, perhaps could do that by
parsing symbolTable at then end of a bloc of decl ? enumDef dont care,

You write a void type as the keyword void, with an optional (but
meaningless) type qualifier. You can declare but you cannot define an
object of void type. You cannot complete a void type. Facto code
check_proto and check_funcdef. Expr and ini. Deffunc, must do do
check_compatible.

expr2, no need enumconstant (subst by value)

other way to check if incomplete ? only when use it, that is why when
do struct t; and dont define it gcc does not warn, cos it does not
forbid to generate code perhaps i should put this in warning. Same for
check_compatible, if different enum, he say nothing (perhaps i could
tag enum to have good warning on this) ex: enum t { RED = 1} i {{{
extern enum t { RED = 2} i; here gcc say nothing

incomplete type need reparse symbol table ? stdC say nothing
incomplete array of struct, incomplete struct, type2.c:5: warning:
parameter has incomplete type must call has_static_size when locals
(ex, if enum not defined) (<=> is_complete) when recursive struct ?
must say error
*)

(*XXXX USE emptyDecl, fill in check_type call, finish one_step *)
	   
(*****************************************************************************)
type initialiserType = StaticIni | DynamicIni

let constant i = Constant (Int (i, (Si (Signed, CInt))))



(* stdC: Thus, for signed char, short, and any signed bitfield type,
   the promoted type is int. For each of the remaining integer types
   (char, unsigned char, unsigned short, any plain bitfield type, or
   any unsigned bitfield type), the effect of these rules is to favor
   promoting to int wherever possible, but to promote to unsigned int
   if necessary to
*)
let change_when_promoted = function
  | CChar | Si (_, (CChar2|CShort)) -> true
  | _ -> false


let default_enum_type = BaseType (IntType (Si (UnSigned, CInt)))

(*****************************************************************************)
(* 

this check compatible, and give in the same time the composite, if not
compatible then exception.

stdC: type section, the end 

  * Both types are the same.

   pad: mean also same tag in struct, compatible enum (same size),
   enum and int of same type,

  * Both are pointer types, with the same type qualifiers, that point
    to compatible types.

  * Both are array types whose elements have compatible types. If both
    specify repetition counts, the repetition counts are equal.

  * Both are function types whose return types are compatible. If both
    specify types for their parameters, both declare the same number
    of parameters (including ellipses) and the types of corresponding
    parameters are compatible. Otherwise, at least one does not
    specify types for its parameters. If the other specifies types for
    its parameters, it specifies only a fixed number of parameters and
    does not specify parameters of type float or of any integer types
    that change when promoted.

  * Both are structure, union, or enumeration types that are declared
    in different translation units with the same member names.
    Structure members are declared in the same order. Structure and
    union members whose names match are declared with compatible
    types. Enumeration constants whose names match have the same
    values.

  pad: useless sentence, only relevant for linker
  take care of enum (is unsigned, enumnotDef, then composite is unsigned, ...

*)

(* first argument is newer, order of rule is important too, i rely on
   first Pattern yield gcc do strange things, on a func return type he
   raise, on argument he dont even warn, on var he warn, TODO?
*)
let rec addQualif2 = function
  | (({const=true} as x),    ({const=false} as y)) -> 
      warning "const declaration for `i' follows non-const" (addQualif2 ({x with const = false}, {y with const = true}))
  | (({const=true} as x),    ({const=true} as y)) -> addQualif2 ({x with const = false}, y)
  | (({volatile=true} as x), y) -> addQualif2 ({x with volatile=false}, {y with volatile=true})
  | ({const=false; volatile=false},y) -> y

(* the second is newer than the first *)
let rec (check_compatible: finalType * finalType -> finalType)     = function
  | ((q1, BaseType x),         (q2, BaseType y))        when  x = y  -> (addQualif2 (q2,q1), BaseType x)
  | ((q1, Pointer x),          (q2, Pointer y))         when q1 = q2 -> (q1, Pointer (check_compatible (x,y)))
  | ((_,  Array (Some i, x)),  (_,  Array (Some j, y))) when  i = j  -> (nQ, Array (Some i,check_compatible (x,y)))
  | ((_,  Array (c1, x)),       (_, Array (c2, y)))                  -> 
      (nQ, Array ((match (c1,c2) with (Some i,_) -> Some i | (_, Some i) -> Some i | _ -> None)
	         ,check_compatible (x,y)
		 )
      )
  | ((_,  FunctionType(r1, x)),(_,  FunctionType(r2, y))) -> 
      let t      = check_compatible (r1,r2) in
      let params = 
       (match (x,y) with
         (* both specify *)
       | (Classic (x::xs,ell1), Classic (y::ys,ell2)) when ell1 = ell2 && List.length (x::xs) = List.length (y::ys) -> 
           (* i do reg or reg2 but stdC does not specify anything, neither the semantic of addQualif2 *)
	   Classic (zip (x::xs) (y::ys) +> 
		    List.map (fun ((reg, s, x),(reg2,s2, y)) -> (reg or reg2, None,check_compatible (x,y)))
		    , ell1)
       | ((Classic ([], true),_) | (_, Classic ([], true))) -> internal_error "parsing cant allow this"
       | ((Classic ([], false), Classic (xs,el)) | ((Classic (xs,el), Classic ([], false)))) -> 
	   (match xs,el with
	   | ([], false) -> (Classic ([], false))
	   | (x::xs, true) -> 
	       raise (Semantic "A parameter list with an ellipsis can't match an empty parameter name list declaration.")
	   | (x::xs, false) -> 
	       (Classic (((x::xs) +> List.map 
		 (function 
		   | (reg, s, ((_, (BaseType (FloatType CFloat))))) -> 
    raise (Semantic "An argument type that has a default promotion can't match an empty parameter name list declaration.")
		   | (reg, s, (_, (BaseType (IntType i)))) when change_when_promoted i -> 
    raise (Semantic "An argument type that has a default promotion can't match an empty parameter name list declaration.")
		   | x -> x
		 )), false))
	   | _ -> internal_error "PM below catch"
	   )
       | ((Old _,_)|(_,Old _)) -> internal_error "impossible in fullt" 
       | _ -> raise (Semantic "conflicting types for i")
       ) in
      (nQ, FunctionType (t, params))
  | ((q1, StructUnionName (s1, su1)), (q2, StructUnionName (s2,su2))) when s1 = s2 && su1 = su2 -> 
      (addQualif2 (q2,q1), StructUnionName (s1, su1))
  | (x,y) -> 
      (match (fix_enum_struct x, fix_enum_struct y) with
      | ((q1, BaseType x),  (q2, BaseType y))  when  x  = y  -> (addQualif2 (q2,q1), BaseType x)
      |	((q1, EnumName s1), (q2, EnumName s2)) when s1  = s2 -> (addQualif2 (q2,q1), EnumName s2)
       (* very strange, but gcc do that perhaps cos gcc dont know which one to choose to be the composite
	  if make a bad choice, and complete the other ?
       *)
      |	((q1, EnumName s1), (q2, EnumName s2)) when s1 <> s2 -> (addQualif2 (q2,q1), default_enum_type)

       (* i dont know why he accept only this when enum not yet def, cos you can have signed enum, ... *)
      |	(((q1, EnumName s1), (q2, BaseType (IntType (Si ((UnSigned, CInt)))))) 
        |((q1, BaseType (IntType (Si ((UnSigned, CInt))))), (q2, EnumName s1))) -> 
	  (addQualif2 (q2, q2), BaseType (IntType (Si ((UnSigned, CInt)))))
      | _ -> raise (Semantic "conflicting types for i") 
      )


(* not really important, just for accurate error message *)
let equal_modulo_struct t1 t2 = (t1 = t2)

(* TODO warning: width of `i' exceeds its type, use maxSize int 

stdC: You cannot portably specify more bits than are used to represent
type int.

*)
let check_size_bitfield = fun t i -> ()
(*
  | CInt))         -> (q,BitFieldInt)
  | CUnsignedInt)) -> (q,BitFieldUnsigned)
  | (IntType _)) -> (q,BitFieldInt) 
  | (q,Enum _) -> (q, BitFieldInt) 
  | (q,EnumName _) -> raise (Semantic "incomplete type")
  | _ -> raise (Semantic "bit-field TODO has invalid type") 
*)

(* convert enum into inttype and call below *)
let check_enum_size_bitfield = fun t i -> ()

(* stdC: An incomplete type can be a structure type whose members you
   have not yet specified, a union type whose members you have not yet
   specified, an array type whose repetition count you have not yet
   specified, or a void type. You complete an incomplete type by
   specifying the missing information. Once completed, an incomplete
   type becomes an object type.
*)

let is_incomplete = function 
  | (_, (StructUnionName _ | Array (None,_) | BaseType (Void))) -> true
  | _ -> false


(*******************************************************************************)

let (check: program -> unit) = fun p -> 

  let rec (check_decl: declaration -> unit) = fun x -> 
    let is_outer = List.length !up = 0 in
    match x with
    | (Decl (None, _,               StoTypedef)) -> raise (Semantic "useless typedef") (* gccw *)
    | (Decl (Some (_, Some _), _,   StoTypedef)) -> raise (Semantic "typedef is initialised")
    | (Decl (Some (s, None), fullt, StoTypedef)) -> 
	let fullt1 = check_type fullt in
	(* take care of order of cos when do  typedef enum { RED } RED; => want an error 
	   what order ? cos can have too typedef int RED[sizeof(enum { RED })]; 
	    so here the enum must launch an error
	   in fact i dont care for the order, what is important is detect all error
	*)
	(match lookhere_big s    with
	 | None ->  add_big (s, TypedefN fullt1)
	 | Some (TypedefN fullt2) -> 
	       if equal_modulo_struct fullt1 fullt2
		(* redefinition: do we do = or =modulo ? seems gcc do =
		   but need kind of =modulo (not saying int* = unsigned*, but with struct 
		    complet et incomplet)
		   = modulostruct, work only if same name !! if 2 struct compatible, does not matter 
		   but it a bit gcc specific, tout ca pour un mesg d'erreur ? yes
		*)
	       then raise (Semantic "redefinition of TODO, previously declared TODO")
	       else raise (Semantic "conflicting types for TODO, previously declared TODO")
	 | Some (_) -> raise (Semantic "redeclared as different kind of symbol")
	)

   (* stdC:You can omit the declarator only for a structure, union, or
      enumeration declaration that declares a tag. You must write a
      name within the declarator of any other outer declarator. 
  
      pad: seems gcc does not do that (interet de gcc de faire ca ? you can
      do int;) TODO?

      if empty declarator then must declare a tag, how can i have
      empty declarator and a struct ? either directly with struct, but
      pointer to struct too ? NO cos pointer to imply have a
      declarator, function prototype ? the same => the check have not
      to go in depth

      I dont check for enum, cos cant have enum that dont define a tag
      (either the name of the enum or enumeration constant tag (the
      list of the enum is never empty))
   *)
    | Decl (None, _, Sto _) -> 
	raise (Semantic "useless keyword or type name in empty declaration") (* gccw *)
    | Decl (None, (nQ, StructUnion (None, _)),     NoSto) -> 
	raise (Semantic "unnamed struct/union that defines no instances") (* gccw *)
    | Decl (None, (nQ, StructUnionName ((s,_),t)), NoSto) -> 
	(* obscure empty struct t; to handle inner mutually recursive struct def *)
	((if not is_outer &&
	  (match lookup_tags s with 
	  | Some ((TagStruct (t2,_)|(TagStructName t2)),_) when t2 = t -> true 
	  | _ -> false)
	then ()
	else warning "cant really see why you use the obscure construct empty struct t in this context, not needed" ())
	;ignore (check_type (nQ, StructUnionName ((s, -2),t))) (* != -1 => we will be able to make diff in check_type *)
	)
    | Decl (None, (nQ, (StructUnion (Some _,_) | Enum _  ) as t),NoSto) -> ignore (check_type t)
    | Decl (None, (nQ, EnumName (s,_) as t),NoSto) -> 
	(* same kind of empty struct t; if do   enum t i; int f1() { enum t; extern enum t i; }, we want error *)
	((if not is_outer &&
	  (match lookup_tags s with 
	  | Some ((TagEnumName | TagEnum _),_) -> true
	  | _ -> false)
	then ()
	else warning "cant really see why you need the obscure empty enum t in this context, not needed" ())
	;ignore (check_type (nQ, EnumName (s,-2)))
	)
    | Decl (None, _, _)                             -> 
	raise (Semantic "empty declaration") (*gccw*)
    | Decl (_,_, Sto (Auto|Register)) when is_outer -> 
	raise (Semantic "auto/register not appropriate here")
	  
    | Decl (Some (s, ini), fullt, sto) -> 
	let fullt1 = check_type fullt in
	(match fullt1, sto, is_outer with
        (* this case means that obj will have either internal or external => we must do 
	   some complicated things *)
	| (((_,FunctionType _),_,_)|(_,Sto Extern,_)|(_,_,true)) -> 
	    (check_up (s, fullt1, sto, is_outer);
	     (match ini, sto, is_outer, fullt1 with
	     | (None,   _,_,_)               -> ()
	     | (Some i, Sto Extern, false,_)      -> 
		 raise (Semantic "TODO inner decl has both extern and initialiser")
	     | (Some i, _,_, (_, FunctionType _)) -> 
		 raise (Semantic "function TODO is initialized like a variable")
	     | (Some i, _, false,_) -> 
		 internal_error "not outer => must be func or extern, and catched before"
	     | (Some i, _, true,_) -> check_ini (StaticIni, fullt1, i)
	     )
	    )
	(* when no linkage, it is simpler just look locally *)
	| _ -> (* TODO, must be able to allocate => must be complet, missing array size *)
	    let _ = check_know_storage_size fullt1 in
	    (match lookhere_big s with
	    | None -> 
		(match ini with 
		| None -> add_big (s, Object (NoLinkage, fullt1))
		| Some i -> 
		    (* order is important, can do int t = sizeof(t) *)
		    (add_big (s, Object (NoLinkage, fullt1));
		     check_ini ((if sto=Sto Static then StaticIni else DynamicIni),fullt1,i)
		    )
		
		)
	    | Some _ -> 
		raise (Semantic "TODO already used as a var or a typedef or enum or extern or TODO")
	    )
	)
  (* when  (((_,FunctionType _),_,_)|(_,Sto Extern,_)|(_,_,true)) *)
  and (check_up: (string * finalType * storage * bool) -> unit) = 
    fun (s,fullt,sto,is_outer) -> 
      let current_found = lookhere_big s in

      (* seems i dont look just up, i go directly at the top ? if intermediare ? dont care ? *)
      let up_found      = (optionise2 List.assoc) s 
	  (try !up +>List.rev +> List.hd with Not_found -> emptyTable).big in

      let stoAndTypeAndSameNS = match (current_found, up_found) with
      | (None, None) -> None
      (* we can ask that if there is Some in up_found, we must take
	 linkage of the top one, cos previous linkage mean at the top.

	 stdC:"previous linkage of a declaration that is visible at
	 file level for the same name" but in fact, our check must
	 have check that the previous in current must be compatible
	 too => it has the same linkage as the outer one => look at
	 previous in current give the same result TODO refman p55,
	 4.2.5
      *)
      | (Some (Object ((Internal|External) as i, varfunc)), _)   -> Some (i, varfunc, true)
      |	(Some (Object (NoLinkage,_)), _) -> 
	  raise (Semantic "redeclaration of TODO")
      |	(Some _,_)                       -> 
	  raise (Semantic "TODO redeclared as different kind of symbol")
      | (None, Some (Object ((Internal|External) as i,varfunc))) -> Some (i, varfunc, false)
      |	(None, Some (Object (NoLinkage,_))) -> 
	  internal_error "outer cant be NoLink" 
      |	(None, Some _) -> 
	  raise (Semantic "TODO redeclared as different kind of symbol")
      in
      let previous_linkage = (match stoAndTypeAndSameNS with None -> External | Some (i,_,_) -> i) in
      let storage = (* stdC: cf bad table in section declaration *)
	(match (sto, fullt, is_outer) with
	| (NoSto, (_,(FunctionType _)),_) -> previous_linkage
	| (NoSto, notfunc, true) -> External
	| (NoSto, notfunc, false) -> 
	    internal_error "so the obj must be NoLink and so we cant get called"
	| (Sto Static,_,true) -> Internal
	| (Sto Static,(_,(FunctionType _)),false) -> 
	    raise (Semantic "inner decl of func cant be static")(* nogcc ?*)
	| (Sto Static,_,false) -> internal_error "obj must be NoLink"
	| (Sto (Auto|Register),(_,(FunctionType _)),_) -> 
	    raise (Semantic "not allowed keyword") (* nogcc ? gcc accepe top auto ? *)
	| (Sto (Auto|Register),notfunc,_) -> 
	    internal_error "not allowed outer,or if inner then must be NoLink"
	| (StoTypedef,_,_) -> internal_error "must be filtered by check_decl"
	| (Sto Extern,_,_) -> previous_linkage
	)
      in
      (match (storage, stoAndTypeAndSameNS) with
	  | (i, None) -> add_big (s, Object (i, fullt))
	  | (i, Some (j, fullt2, sameNs)) when i = j -> 
	      (let t = check_compatible (fullt,fullt2) in
	       add_big (s, Object (i, if sameNs then t else fullt))
	      )
	  | (i, Some (j, _, _)) -> raise (Semantic "not same linkage, conflicting declaration")
      )


	  
  (* stdC: type section, deriving types *)
  and (check_type: fullType -> finalType) = fun f -> 
    (match f with 
    | (_, BaseType _) -> f
    | (q, Pointer f)  -> (q, Pointer (check_type f))

    (* stdC: type section, cant have nor incomplete nor function type in array *)
    | (nQ, Array (expr,f) ) -> 
	(* order is important, struct t { int i,j;} a[sizeof(struct t)]; must be valid *)
	(match check_type f with
	| (_, FunctionType _) ->    raise (Semantic "declaration of `f' as array of functions") (* ex: int f[10](int) *)
	| (_, BaseType Void) -> raise (Semantic "declaeration of a as array of voids")
	| f -> (nQ, Array (expr +> fmap (fun e -> constant (evalInt e)), f)) 
          (* check for incomplete struct is done as end of block *)
	)
    | (nQ, FunctionType (return, params)) -> 
	(match check_type return with
	| (_, FunctionType _) -> raise (Semantic "f declared as function returning a function") (* ex: int f(int)(int) *)
	| (_, Array _) ->        raise (Semantic "`f' declared as function returning an array") (* ex: int f(int)[10] *)
	| ret -> (nQ, FunctionType (ret, check_prototype params))
	)
    | (q, TypeName s) -> 
	(match lookup_big s with
	| Some (TypedefN (q2,t)) -> (addQualif (q,q2), t)
	| Some _ -> internal_error "if we see a typename, then cant have enum or var declared"
	| None   -> internal_error "if typename then must have been declared"
	)
    | (q, (StructUnion (None, t))) -> check_struct (q, (None, t))
    | (q, (Enum        (None, t))) -> check_enum   (q, (None, t))


    (* when there is a tag involved, there is complicated things to do *)
    | (q, ((StructUnionName ((s,_),_) | EnumName (s,_) | StructUnion (Some s,_) | Enum (Some s,_)) as t)) -> 
	(match lookhere_tags s with
	| None -> 
	    (match t with
	     (* here it is the where the case of obscure empty struct
		t strike, when -1 => i must have a look up and if
		exist, then it take the up one, when empty struct t, i
		dont lookup up it means that it is a new struct *)
	    | StructUnionName ((s,-1),su) -> 
		(match lookup_tags s with
		(* i think this case must be an error in C programs,
		   perhaps if pointer to C allow it TODO ? or at
		   least, the programmer cant do many things with it
		   (cos it cant be defined) cos this is not the good
		   scope to complete it *)
		| Some (TagStructName su2,j) when su = su2 -> (q, StructUnionName ((s,j),su))
		| Some (TagStruct (su2,_),j) when su = su2 -> (q, StructUnionName ((s,j),su))
		| Some _ -> raise (Semantic "t defined as wrong kind of tag")
		| None -> (add_tags (s, TagStructName su);
			   (q, StructUnionName ((s,tag_it()),su)))
		)

	    (* obscure empty *)
	    | StructUnionName ((s,-2),su) -> (add_tags (s, TagStructName su); 
					     (q, StructUnionName ((s, tag_it()), su)))

	    | StructUnion (Some s, t) -> check_struct (q, (Some s, t))
	    | Enum (Some s,t) -> check_enum (q, (Some s,t))
	    | EnumName (s,-1) -> 
		(match lookup_tags s with
		| Some (TagEnumName,j) -> (q, EnumName (s,j)) (* strange (cos dont know if unsigned or not) but valid *)
		| Some (TagEnum t,j) ->   (q, BaseType (IntType t))
		| Some _ -> raise (Semantic "t defined as wrong kind of tag")
                 (* interet ? perhaps if enum used in a struct, and after enum do sizeof struct .. ? perhaps ADT ?*)
		| None -> (add_tags (s, TagEnumName); (q, EnumName (s, tag_it()))) 
		)
	    | EnumName (s,-2) -> (add_tags (s, TagEnumName);
				  (q, EnumName (s, tag_it ())))
	    | _ -> internal_error "cf PM below"
	    )
	| Some v -> 
	    (* gcc do very strange things, when we declare only name, then he dont even warn,  why TODO *)
	    (match v with
	    | TagStruct (su, fields) -> 
		(match t with
		| StructUnionName ((s,-1), su2) when su = su2 -> (q, StructUnionName ((s, tag_it()),su))
		| (StructUnionName ((s,_), su2)|(StructUnion (Some s,(su2,_)))) when su = su2 -> 
		    raise (Semantic "redefinition of struct") (* nogcc for structname *) 
		(* gcc dont do that for unionName or enumName, morover
		i should perhaps have better error mesg here *)
		| _ -> raise (Semantic "t defined as wrong kind of tag")
		)
	    | TagStructName su -> 
		(match t with
		(* definition of an incomplete type, i could update
		   cur to suppr this structname but useless *)
		| StructUnion (Some s, ((su2,_) as t)) when su = su2 -> check_struct (q, (Some s, t))
		| StructUnionName ((s,-1),su2) when su = su2 ->  (q, StructUnionName ((s,tag_it()),su))
		| StructUnionName ((s,-2),su2) when su = su2 -> raise (Semantic "redefinition of struct") (*nogcc*)
		| _ -> raise (Semantic "t defined as wrong kind of tag") (* same as before, not for ..Name *)
		)
	    | TagEnum e -> 
		(match t with
		| Enum _ -> raise (Semantic "redeclaration of enum t")
		| EnumName (s,-1) -> (q, BaseType (IntType e))
		| EnumName (s,-2) -> raise (Semantic "redefinition of enum") (* nogcc *)
		| _ -> raise (Semantic "t defined as wrong kind of tag") (* same *)
		)
	    | TagEnumName -> 
		(match t with
		(* definition of an incomplete type, TODO ? *)
		| Enum (Some s, e) -> check_enum (q, (Some s, e))
		| EnumName (s,-1) -> (q, EnumName (s, tag_it ())) (* interest ? *)
		| EnumName (s,-2) -> raise (Semantic "redefinition of enum") (* nogcc *)
		| _ -> raise (Semantic "t defined as wrong kind of tag") (* same *)
		)
	    )
	)
    )

  (* stdC: cf type section, deriving types: struct cant contain
  function type nor incomplete type *)

  (* todo: call check_complete (dont pass tgrough pointer, ... *)

  (* when we have a string, we must return a structunionname *)
  and (check_struct: (typeQualifier * (string option * structType)) -> fullType) = 
    fun f -> raise Todo
  (* return BaseType IntType ... *)
  and (check_enum:   (typeQualifier * (string option * enumType)) -> fullType) = 
    fun  f -> raise Todo

  and (check_complete:     symbolTable -> unit) = fun cur -> ()

      (* when name, must look in cur ? no, cos check_know_storage_size
	 is done just after check_type BUT perhaps check_type have not
	 updated if struct t j[sizeof(struct t {int d;})] !! *)
  and (check_know_storage_size: fullType    -> unit) = fun cur -> ()
(*  call fix_enum_struct *)

		


	



      
	


(* stdC: A parameter-level declaration is in scope from the point
   where it is declared in the function definition to the end of the
   outermost block of the function definition. (If there is no
   function definition, the scope of a parameter-level declaration
   ends with the declaration.)
*)

(* 
 (StructUnion (_, Some _, _) | Enum _  | StructUnionName (_,_) | EnumName _)

 look if already in or struct now enum, ... (now i have same namespace
 for all tags (enum and struct) even if gcc dont, it make my like
 simpler. But with struct/enum/union, we can have k in already if was
 before an incomplete type
*)



(* must have in param linkage, and level of decl A static initializer
   for an object with scalar type consists of a single expression
   (possibly enclosed in braces) that the translator can evaluate
   prior to program startup. A static initializer for an object with
   array, structure, or union type consists of a list of one or more
   initializers separated by commas and enclosed in braces.

   For other than array types, any rvalue expression that is
   assignment compatible with the type of the object can serve as a
   dynamic initializer. You can also write a dynamic initializer in
   the same form as a static initializer.

   The initializers that you write within a list separated by commas
   are inner initializers. You write an inner initializer the same way
   you write a static initializer, except that you can omit the
   outermost braces:
                                                                                                                          
     * For an object of structure type, the list of inner initializers
       you write initializes each member of the structure in turn,
       beginning with the first. The translator skips unnamed
       bitfields, which you cannot initialize.

     * For an object of union type, you can initialize only the first
       member of the union.

     * For an object of array type, the list of inner initializers you
       write initializes each element of the array in turn, beginning
       with element number zero. The last array subscript varies most
       rapidly.
 
If you do not provide as many initializers as there are members or
elements to initialize, the translator initializes any remaining
members or elements to the value zero. Do not provide excess
initializers. You can initialize an object of incomplete array type,
in which case the number of element initializers you write determines
the repetition count and completes the array type.

You can initialize an array of any character type by writing a string
literal, or an array of wchar_t by writing a wide character string
literal, as shorthand for a sequence of character constants. The
translator retains the terminating null character only when you
initialize an object of incomplete array type. (An object of complete
array type is padded as needed with trailing zero initializers.)

cf table


do a call to check_expr
 *)
  and (check_ini: (initialiserType * fullType * initialiser) -> unit) = 
    fun (iniType, f,ini) ->
      ()
(*---------------------------------------------------------------------------*)

  (* return field list, cos can have a structDef that return nothing
     we could think that in case of structdef we should return something
     but when structDef, we know that just below come an ident with a structname that
     will catch with him the strutDef, so no need
  *)
  and (check_member: field -> field list) = fun x -> 
   (* stdC: A bitfield can be unnamed. If the declarator is for a
      bitfield that has zero size, do not write a name within the
      declarator. If the declarator is for a bitfield that has nonzero
      size, then you can optionally write a name; otherwise, you must
      write a name.

     last sentence is enforced by parsing but gcc does not do that,
     but ansi C grammar say impossible so i follow grammar, perhaps
     gcc do that cos when mapping hardware,there can be some hole
     TODO?

     interet bitfield 0 ? c'est pour les regles de padding se
     bitfield, cf ritchie,
    *)
    match x with
    | (Simple (s, fullt)) -> 
	if List.mem s !cur.fieldname then raise (Semantic "duplicate member TODO")
	else (add_field s; [Simple (s, check_type fullt)])
    | (BitField (name, fullt, expr)) -> 
	(* here order not so important, i could do check_type after evalInt,
           cos I cant have 

	     struct t {...} i:(sizeof(struct t))

	   cos bitfield type can only be simple, so v must be as cur
	   when good decl, if bad it will be detected anyway after
	*)
	let fullt1  = check_type fullt in
	let i       = evalInt   expr  in
	(
	 (match name with 
	 | None -> ()
	 | Some s when List.mem s !cur.fieldname -> raise (Semantic "duplicate member TODO")
	 | Some s -> add_field s
	 );
	 (match (name, fullt1, i) with
	 | (Some _, _, "0")            -> raise (Semantic "zero width for bit-field TODO")
	 | (_,(_, BaseType Void), _) -> raise (Semantic "field declared void")
	 | (_,(_, BaseType (IntType t)), i) -> check_size_bitfield t i
	      (* could modify symbolTable if declare enum !! but what is his scope ? seems gcc say nothing *)
	 | (_,(_, (Enum _ | EnumName _) as enum), i) -> check_enum_size_bitfield enum i 
	 | _ -> raise (Semantic "bit-field TODO has invalid type")
	 );
	 [BitField (name, fullt1, constant i)]
	)
    | (DefStruct (s, e)) -> (ignore (check_type (nQ, (StructUnion (Some s, e))));[])
    | (DefEnum (s,e)) ->    (ignore (check_type (nQ, (Enum (Some s, e)))); [])
   

  and (check_funcdef: definition -> unit) = fun f -> 
     (*
        stdC: You cannot write a function definition within another
        declaration or function definition.

	pad: nested func def not allowed by construction i assure
        this, my abstactSyntax dont allowed it, and the parsing too.
        but i must check that i dont have declaration of function ? no
        cos i can give inner prototype of function inside function

	stdC: This is the only context where you can omit both the
        storage class and any type part. You must write a name within
        the declarator.

        pad: assured by parsing (cf function_definition, we allow
        declarator ... without a leading decl_spec

	stdC: The outermost block of a function definition includes in
	its name space all the parameters for the function, as object
	declarations.
      *)
    ()

  and (check_parameter: parameterTypeDef -> parameterTypeDef) = fun f -> f
    (* 
       stdC: You must write a parameter name within the declarator.
       
        pad: assured by parsing ? NO we allow parameter_decl: decl_spec 
        
        => can do it either in type-checking or in fixFunc, 
        
        the fact to have a name when in definition is now inforced by
        using a more precise abstactSyntax type for funcdef, that make
        the diff between a prototype and a function definition, where
        the rule are different we could also have done a
        parameter_decl_when_indef: grammar rule that force to put a
        declartor (a name) and so we would have less work in fixFunc
        
        => now done in parsing auxillary code
    *)
  and (check_block: declaration -> unit) = fun  f -> 
    (* stdC: same as for outer *)
    check_decl f
  and (check_prototype: parameterTypeDecl -> parameterTypeDecl) = fun f -> f
    (* 
       stdC: If the prototype declaration declares a parameter for a
       function that you are defining (it is part of a function
       definition), then you must write a name within the declarator.

        pad: done in fixFunc
        Otherwise, you can omit the name.

       stdC: The translator alters any declaration you write at
       parameter level with type function returning T to type pointer
       to function returning T, which is an object type.

       do check for Old
    *)
  and (check_typename: fullType -> fullType) = fun f -> f
    (* 
       stdC: Do not write a name within the declarator. 

       TODO call check_type, et apres juste traverser et voir kan on a
       une func decl, seul cas (avec parameter_type_list) otherwise
       the abstract_declarator force to not have names
    *)

(* check_expr, ...
 pergaps put check_ini here too 
 range of constant
*)

  and (evalInt: constExpression -> string) = fun  x -> "0"
  (* must return too a sumbolTable cos with sizeof(struct t { ..... } ) 
     we must add t in the scope  *)
in
  ()
  

(*******************************************************************************)

(* resolve overloading of operator

let sizeTypeC _ = 1

let checkEnumName 

let fixEnum xs = xs 
    +> List.fold_left (fun (acc,xs) (s,io) -> 
      if io = None then (acc+1, xs @ [s, acc]) 
      else (some io + 1, xs @ [s, some io])) (0,[])
    +> snd

let check program = 
  program +> List.fold_left 
    (fun env -> function
      |	Declaration 
      |	Definition
    ) [[]]

*)

