#include <iostream>
#include <mpi.h>

#include "input.hh"
#include "quadrature.hh"
#include "sum_and_output.hh"

int
main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);

  int rk, sz;
  MPI_Comm_rank (MPI_COMM_WORLD, &rk);
  MPI_Comm_size (MPI_COMM_WORLD, &sz);
  const unsigned rank (rk), size (sz);

  double a, b;
  unsigned n;

  mpi::get_input (a, b, n);

  const double h = (b - a) / n;

  const unsigned short_n = n / size, long_n = short_n + 1;
  const unsigned remainder = n % size;
  const unsigned local_n = rank < remainder ? long_n : short_n;

  const unsigned long_pred = rank < remainder ? rank : remainder;
  const unsigned short_pred = rank < remainder ? 0 : rank - remainder;

  const double local_a = a + (long_pred * long_n + short_pred * short_n) * h;
  const double local_b = local_a + local_n * h;

  const double local_int = quadrature::trapezoidal (local_a, local_b, local_n);

  mpi::sum_and_print (local_int, std::cout, a, b, n);

  MPI_Finalize ();
  return 0;
}
