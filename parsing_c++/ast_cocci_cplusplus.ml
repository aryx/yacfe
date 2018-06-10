type mcodekind = 
 CONTEXT of pos * unit befaft
 and pos = NoPos | DontCarePos | FixPos of (int * int)

and meta_name = ()

and 'a befaft =
    BEFORE      of 'a list list
  | AFTER       of 'a list list
  | BEFOREAFTER of 'a list list * 'a list list
  | NOTHING



 and fixpos =
    Real of int (* charpos *) | Virt of int * int (* charpos + offset *)
