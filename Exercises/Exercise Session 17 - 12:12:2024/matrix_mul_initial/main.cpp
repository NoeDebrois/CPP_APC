#include <fstream>
#include <iostream>

#include <mpi.h>

#include "dense_matrix.hh"

int
main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);

  int rank (0), size (0);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  la::dense_matrix full_A(0, 0);
  la::dense_matrix full_B(0, 0);

  if (rank == 0)
    {
      std::ifstream first (argv[1]), second (argv[2]);
      full_A.read (first);
      full_B.read (second);
    }

  unsigned m = full_A.rows(), n = full_A.columns(), p = full_B.columns();
  
  // MY CODE:
  // 0) Broadcast matrices size to prepare local buffers / matrices !
  MPI_Bcast(&m, 1, MPI_UNSIGNED, M_COMM_WORLD);
  MPI_Bcast(&n, 1, MPI_UNSIGNED, M_COMM_WORLD);
  MPI_Bcast(&p, 1, MPI_UNSIGNED, M_COMM_WORLD);

  const unsigned stripe = m/size; // Nb of rows that we have to scatter.

  // 1) Scatter full_A from rank 0
  la::dense_matrix local_A (stripe, n); // Across all ranks, we create local_A
  MPI_Scatter(full_A.data(), stripe*n, MPI_DOUBLE, local_A.data(), stripe*n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  // 2) Broadcast full_B to all ranks
  la::dense_matrix local_B (n, p);
  if (rank == 0) {
    local_B = full_B;
  }
  MPI_Bcast(local_B.data(), n*p, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  // 3) Compute local_C = local_A * local_B
  la::dense_matrix local_C = local_A * local_B;

  la::dense_matrix full_C (m, p);

  // MY CODE:
  // 4) Gather full_C from local_C
  MPI_Allgather(local_C.data(), stripe*p, MPI_DOUBLE, full_C.data(), stripe*p, MPI_DOUBLE, MPI_COMM_WORLD);
  
  if (rank == 0)
    {
      std::cout << full_C.rows() << " " << full_C.columns() << "\n";

      for (std::size_t i = 0; i < full_C.rows(); ++i)
        for (std::size_t j = 0; j < full_C.columns(); ++j)
          {
            std::cout << full_C(i, j);
            std::cout << (full_C.columns() - j == 1 ? "\n" : " ");
          }
    }

  MPI_Finalize ();
  return 0;
}
