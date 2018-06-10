(* Copyright (C) 2006, 2007 Julia Lawall
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License (GPL)
 * version 2 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * file license.txt for more details.
 * 
 * This file was part of Coccinelle.
 *)

(* for metavariables in general, but here because needed for metatypes *)
type inherited = bool (* true if inherited *)
type keep_binding = Unitary (* need no info *)
  | Nonunitary (* need an env entry *) | Saved (* need a witness *)

type typeC =
    ConstVol        of const_vol * typeC
  | BaseType        of baseType
  | SignedT         of sign * typeC option
  | Pointer         of typeC
  | FunctionPointer of typeC (* only return type *)
  | Array           of typeC (* drop size info *)
  | EnumName        of bool (* true if a metaId *) * string
  | StructUnionName of structUnion * bool (* true if a metaId *) * string
  | TypeName        of string
  | MetaType        of (string * string) * keep_binding * inherited
  | Unknown (* for metavariables of type expression *^* *)

and tagged_string = string

and baseType = VoidType | CharType | ShortType | IntType | DoubleType
| FloatType | LongType | LongLongType | BoolType

and structUnion = Struct | Union

and sign = Signed | Unsigned

and const_vol = Const | Volatile

(* --------------------------------------------------------------------- *)
(* Printer *)
open Format

let rec type2c = function
    ConstVol(cv,ty) -> (const_vol cv) ^ (type2c ty)
  | BaseType(ty) -> baseType ty
  | SignedT(sgn,None) -> sign sgn
  | SignedT(sgn,Some ty) -> (sign sgn) ^ (type2c ty)
  | Pointer(ty) -> (type2c ty) ^ "*"
  | FunctionPointer(ty) -> (type2c ty) ^ "(*)(...)"
  | Array(ty) -> (type2c ty) ^ "[] "
  | EnumName(mv,name) -> "enum " ^ name ^ " "
  | StructUnionName(kind,mv,name) -> (structUnion kind) ^ name ^ " "
  | TypeName(name) -> name ^ " "
  | MetaType((rule,name),keep,inherited) -> name ^ " "
      (*
      let print_unitary = function
	  Unitary -> print_string "unitary"
	| Nonunitary -> print_string "nonunitary"
	| Saved -> print_string "saved" in
      print_string "/* ";
      print_string "keep:"; print_unitary keep;
      print_string " inherited:"; print_bool inherited;
      print_string " */"
      *)
  | Unknown -> "unknown "

and baseType = function
    VoidType -> "void "
  | CharType -> "char "
  | ShortType -> "short "
  | IntType -> "int "
  | DoubleType -> "double "
  | FloatType -> "float "
  | LongType -> "long "
  | LongLongType -> "long long "
  | BoolType -> "bool "

and structUnion = function
    Struct -> "struct "
  | Union -> "union "

and sign = function
    Signed -> "signed "
  | Unsigned -> "unsigned "

and const_vol = function
    Const -> "const "
  | Volatile -> "volatile "

let typeC t = print_string (type2c t)

(* t1 should be less informative than t1, eg t1 = Pointer(Unknown) and t2 =
Pointer(int) *)
(* only used in iso *)
(* needs to do something for MetaType *)
let compatible t1 = function
    None -> t1 = Unknown
  | Some t2 ->
      let rec loop = function
	  (Unknown,_) -> true
	| (ConstVol(cv1,ty1),ConstVol(cv2,ty2)) when cv1 = cv2 ->
	    loop(ty1,ty2)
	| (Pointer(ty1),Pointer(ty2)) -> loop(ty1,ty2)
	| (FunctionPointer(ty1),_) -> false (* not enough info *)
	| (_,FunctionPointer(ty2)) -> false (* not enough info *)
	| (Array(ty1),Array(ty2)) -> loop(ty1,ty2)
	| (_,_) -> t1=t2 in
      loop (t1,t2)
