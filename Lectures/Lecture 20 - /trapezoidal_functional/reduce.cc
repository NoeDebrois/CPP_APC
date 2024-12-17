#include <mpi.h>
#include <vector>
#include "sum_and_output.hh"

namespace mpi
{
  void sum_and_print (std::vector<double> local_integral, std::ostream & out,
                      double a, double b, unsigned n)
  {
    int rank;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);

    std::vector<double> total(local_integral.size());
    MPI_Reduce (local_integral.data(), total.data(), 3, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
      {
          out << "n = " << n << ", a = " << a << ", b = " << b << std::endl;
          for ( double v: total )
              out << "integral = " << v << std::endl;
      }
  }
}
