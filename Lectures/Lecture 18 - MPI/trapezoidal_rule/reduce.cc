#include <mpi.h>

#include "sum_and_output.hh"

namespace mpi
{
  void sum_and_print (double local_integral, std::ostream & out,
                      double a, double b, unsigned n)
  {
    int rank;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);

    double total (0.);
    MPI_Reduce (&local_integral, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
      {
        out << "n = " << n << ", a = " << a << ", b = " << b
            << ", integral = " << total << std::endl;
      }
  }
}
