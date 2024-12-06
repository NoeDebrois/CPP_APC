#include <iostream>
#include <mpi.h>

#include "input.hh"

namespace mpi
{
  void
  get_input (double & a, double & b, unsigned & n)
  {
    int rank, size;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);

    if (rank == 0)
      {
        std::cin >> a >> b >> n;

        for (int dest = 1; dest < size; ++dest)
          {
            MPI_Send (&a, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
            MPI_Send (&b, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
            MPI_Send (&n, 1, MPI_UNSIGNED, dest, 0, MPI_COMM_WORLD);
          }
      }
    else
      {
        MPI_Recv (&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv (&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv (&n, 1, MPI_UNSIGNED, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      }
  }
}
