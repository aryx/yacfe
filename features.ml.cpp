(* yes sometimes cpp is useful *)

#if FEATURE_MPI==1
let x = 1 
#else 
let x = 2

module Distribution = struct
  let under_mpirun () = 
    false
      
  let mpi_main2 ?debug_mpi map_ex reduce_ex fxs = 
    let res = List.map map_ex (fxs()) in
    reduce_ex res

  let mpi_adjust_argv argv = 
    argv
end


#endif

