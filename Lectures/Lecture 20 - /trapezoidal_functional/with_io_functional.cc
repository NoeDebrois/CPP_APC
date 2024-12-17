#include <iostream>
#include <mpi.h>

#include "input.hh"
#include "quadrature.hh"
#include "sum_and_output.hh"
#include <cmath>
#include <vector>

double
f_poly (double x)
{
  return x * x + 3 * x + 1;
}


double
f_trig (double x)
{
  return sin(x)*sin(x) + cos(x) + 1;
}


double
f_exp (double x)
{
  return exp(x) + x*x*x + 1;
}


int main (int argc, char *argv[])
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

  std::vector<double> local_int(3);
  local_int[0]  =  quadrature::trapezoidal (f_poly, local_a, local_b, local_n);
  local_int[1]  =  quadrature::trapezoidal (f_trig, local_a, local_b, local_n);
  local_int[2]  =  quadrature::trapezoidal (f_exp, local_a, local_b, local_n);

  mpi::sum_and_print (local_int, std::cout, a, b, n);

  MPI_Finalize ();
  return 0;
}
