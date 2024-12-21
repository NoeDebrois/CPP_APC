#include "evaluate_by_column.hpp"

using la::dense_matrix;

// 1st method: cycling partitioning -> NO gather/scatter but no necessity of local_[...].
dense_matrix evaluate_by_column(const dense_matrix& A, const function_t& f)
{
  int rank(0), size(0);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  unsigned nrows = A.rows();
  unsigned ncols = A.columns();

  // result is a row vector
  dense_matrix result(1,ncols);
  for (unsigned j = rank; j < ncols; j+=size)
  {
    // extract column
    dense_matrix column(nrows,1);
    for (unsigned i = 0; i < nrows; ++i)
      column(i,0) = A(i,j);

    // compute result
    result(0,j) = f(column);
  }

  // loop over all elements
  for (unsigned j = 0; j < ncols; ++j)
  {
    // broadcast each element from the proper root
    int root = j % size;
    MPI_Bcast(&(result(0,j)), 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
  }

  return result;
}

// 2nd method: block partitioning, we can't use scatter because of the way the matrix is stored, but we need to have
// two indexes: a local one (j) and a global one (j + rank*n_local_cols). At the end we can use AllGather.
dense_matrix evaluate_by_column2(const dense_matrix& A, const function_t& f)
{
  int rank(0), size(0);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  unsigned nrows = A.rows();
  unsigned ncols = A.columns();
  unsigned n_local_cols = ncols / size;

  // result is a row vector
  dense_matrix local_result(1,n_local_cols);
  for (unsigned j = 0; j < n_local_cols; ++j)
  {
    // extract column
    dense_matrix column(nrows,1);
    for (unsigned i = 0; i < nrows; ++i)
      column(i,0) = A(i, j + rank * n_local_cols); // WARNING: A is the global matrix so you can't use index "j", which
      // is the local index: you have to add rank * n_local_cols.

    // compute result (apply f to the column)
    local_result(0,j) = f(column);
  }

  // collect result
  dense_matrix result(1,ncols);
  MPI_Allgather(local_result.data(), n_local_cols, MPI_DOUBLE, result.data(),
                n_local_cols, MPI_DOUBLE, MPI_COMM_WORLD);

  return result;
}
