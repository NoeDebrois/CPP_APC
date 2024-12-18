//#include <cmath>
#include <iostream>
#include <mpi.h>
#include <fstream>
#include <string>
#include <cmath>

#include "nd_vector.hh"



double
cosine_similarity (const numeric::nd_vector & v1, const numeric::nd_vector & v2);



int main (int argc, char *argv[]){
  MPI_Init (&argc, &argv);
  int rank;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);

  numeric::nd_vector v1{1., 2., 3., 4., 3.};
  numeric::nd_vector v2{1., 2., 3., 4., 3.};

  //numeric::nd_vector v2{5., 6., 7., 8., 5.};

  double similarity = cosine_similarity ( v1, v2);

  if (rank == 0){
      std::cout << "v1, v2 similarity: "<< similarity <<std::endl;
  }

  MPI_Finalize ();
  return 0;
}


double cosine_similarity (const numeric::nd_vector & v1, const numeric::nd_vector & v2){
  double local_dot_term = 0;
  double local_v1_norm_term = 0;
  double local_v2_norm_term = 0;

  int rank, int size;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  // MY CODE:
  // Partition data
  // - Cyclic partitioning because v1 available everywhere (across all cores)
  // - Cyclic partitioning then since v1, v2 are passed as const &
  for (numeric::nd_vector::size_type i = 0; i < v1.size(); i+=size) {
      // Compute local_dot_term, local_v1_norm_term & local_v2_norm_term:
      local_dot_term += v1[i]*v2[i];
      local_v1_norm_term += v1[i]*v1[i];
      local_v2_norm_term += v2[i]*v2[i];
  }

  double global_dot_term = 0;
  double global_v1_norm_term = 0;
  double global_v2_norm_term = 0;

  // MPI_Allreduce and return:
  MPI_Allreduce(&local_dot_term, &global_dot_term, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  MPI_Allreduce(&local_v1_norm_term, &global_v1_norm_term, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  MPI_Allreduce(&local_v2_norm_term, &global_v2_norm_term, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

  // Now we can properly construct the square-root (don't do this with the local terms!):
  global_v1_norm_term = sqrt(global_v1_norm_term);
  global_v2_norm_term = sqrt(global_v2_norm_term);

  return global_v1_norm_term/(global_v1_norm_term * global_v2_norm_term);
}
