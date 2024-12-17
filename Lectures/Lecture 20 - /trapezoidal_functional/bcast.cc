#include <iostream>
#include <mpi.h>

#include "input.hh" // WARNING: header file and source file don't have same name.
// It's not mandatory but it's better to use the same name.

namespace mpi
{
  void get_input (double & a, double & b, unsigned & n)
  {
    int rank;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);

    if (rank == 0) std::cin >> a >> b >> n;

    MPI_Bcast (&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast (&b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast (&n, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
  }
}
