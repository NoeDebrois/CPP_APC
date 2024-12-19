#include "power_method.hpp"

DenseMatrix power_method(const DenseMatrix & local_A, std::size_t iterations)
{
  const unsigned n = local_A.get_n_cols ();

  const unsigned stripe = local_A.get_n_rows ();

  DenseMatrix full_eigen_vector(n, 1, 1.0);

  for (std::size_t it_n = 0; it_n < iterations; ++it_n)
  {

    DenseMatrix local_X = local_A * full_eigen_vector;

    MPI_Allgather (local_X.data (), stripe , MPI_DOUBLE,
              full_eigen_vector.data (), stripe , MPI_DOUBLE,
              MPI_COMM_WORLD);
    // normalization step
  }

  return full_eigen_vector;
}
