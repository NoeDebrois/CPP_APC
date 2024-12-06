#include <mpi.h>

#include "sum_and_output.hh"

namespace mpi
{
  void sum_and_print (double local_integral, std::ostream & out,
                      double a, double b, unsigned n)
  {
    int rank, size;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);

    if (rank > 0)
      {
        MPI_Send (&local_integral, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
      }
    else
      {
        double total (local_integral);

        for (int source = 1; source < size; ++source)
          {
            MPI_Recv (&local_integral, 1, MPI_DOUBLE, source, 0,
                      MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total += local_integral;
          }

        out << "n = " << n << ", a = " << a << ", b = " << b
            << ", integral = " << total << std::endl;
      }
  }
}
