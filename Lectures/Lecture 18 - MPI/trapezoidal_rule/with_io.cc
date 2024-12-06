#include <iostream>
#include <mpi.h>

#include "input.hh"
#include "quadrature.hh"
#include "sum_and_output.hh"

int
main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);

  int rank, size;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  double a, b;
  unsigned n;

  mpi::get_input (a, b, n);

  const double h = (b - a) / n;
  const unsigned local_n = n / size;

  const double local_a = a + rank * local_n * h;
  const double local_b = local_a + local_n * h;

  const double local_int =
    quadrature::trapezoidal (local_a, local_b, local_n);

  mpi::sum_and_print (local_int, std::cout, a, b, n);

  MPI_Finalize ();
  return 0;
}
