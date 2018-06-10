open Common

(* because Str of ocaml sux with word boundary, newline, etc.
 * ex: \\bcia_pci_tbi_try2\\b
 *)

let find_offset_all_matches ~regexp str = 

  let substrings = Pcre.exec ~rex:regexp str in
  let res = ref [] in

  let rec loop substrings = 
    let n = Pcre.num_of_subs substrings in
    for i = 1 to n -1 do
      let (pos1, pos2) = Pcre.get_substring_ofs substrings i in
      Common.push2 (pos1,pos2) res;
    done;
    (try 
        let subs2 = Pcre.next_match ~rex:regexp substrings in
        loop subs2
      with  Not_found -> ()
    );
  in
  loop substrings;
  List.rev !res

