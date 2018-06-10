(*
remove the old ansi way to declarete parameters, 

remove the alternative for order of stuff in type.
let int const (even if in spirit it's more consistent than const int when
deal with pointer).

order of storage, type, qualifier, attribute, inline.
cf parser_c.mly parse helper function


function_def: start_fun compound      { LP.del_scope(); ($1, $2) }
 | start_fun decl_list compound      { 
     pr2 "OLD STYLE DECL NOT WELL SUPPORTED";
     LP.del_scope(); ($1, $3) 
   }


 /*(* in ~/kernels/src/linux-2.5.2/drivers/isdn/hisax/isdnl3.c sometimes
  * the function ends with }; instead of just } 
  * can also remove this rule and report "parse error" pb to morton
  *)*/
 | TPtVirg    { EmptyDef [$1] } 



cpp macro without trailing ptvirg




*)
