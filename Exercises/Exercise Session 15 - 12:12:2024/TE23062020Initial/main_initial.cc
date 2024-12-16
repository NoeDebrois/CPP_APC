//#include <cmath>
#include <iostream>
#include <mpi.h>
#include <fstream>
#include <string>
#include <cmath>

#include "nd_vector.hh"



double
cosine_similarity (const numeric::nd_vector & v1, const numeric::nd_vector & v2);



int
main (int argc, char *argv[])
{

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


double
cosine_similarity (const numeric::nd_vector & v1, const numeric::nd_vector & v2){

  

  double local_dot_term = 0;
  double local_v1_norm_term = 0;
  double local_v2_norm_term = 0;

  int rank;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  int size;
  MPI_Comm_size (MPI_COMM_WORLD, &size);


  // your code goes here
  

}
