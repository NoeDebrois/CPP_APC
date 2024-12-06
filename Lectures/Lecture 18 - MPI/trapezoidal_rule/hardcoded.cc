#include <iostream>
#include <mpi.h>

#include "quadrature.hh"

int
main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);

  int rank, size;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  double a (0.0), b (3.0);
  unsigned n (1024);

  const double h = (b - a) / n;
  const unsigned local_n = n / size;

  const double local_a = a + rank * local_n * h;
  const double local_b = local_a + local_n * h;

  double local_int =
    quadrature::trapezoidal (local_a, local_b, local_n);

  if (rank > 0)
    {
      MPI_Send (&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
  else
    { // rank 0
      double total (local_int);

      for (int source = 1; source < size; ++source)
        {
          MPI_Recv (&local_int, 1, MPI_DOUBLE, source, 0,
                    MPI_COMM_WORLD, MPI_STATUS_IGNORE);
          total += local_int;
        }

      std::cout << "n = " << n << ", a = " << a << ", b = " << b
                << ", integral = " << total << std::endl;
    }

  MPI_Finalize ();
  return 0;
}
