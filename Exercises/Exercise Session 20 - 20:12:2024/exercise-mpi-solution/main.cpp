#include <iostream>
#include <fstream>

#include "evaluate_by_column.hpp"

using la::dense_matrix;

double column_mean (const dense_matrix& column);

int main (int argc, char* argv[])
{
  MPI_Init(&argc, &argv);

  int rank(0), size(0);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  std::string filename = argv[1];
  std::ifstream ifs(filename);
  dense_matrix matrix(ifs);

  if (rank == 0)
    matrix.print(std::cout);

  dense_matrix result = evaluate_by_column(matrix, column_mean);

  if (rank == 0)
  {
    std::cout << "\nresult:" << std::endl;
    result.print(std::cout);
  }

  MPI_Finalize();
  return 0;
}

double column_mean (const dense_matrix& column)
{
  double result = 0.0;

  unsigned nrows = column.rows();
  for (unsigned i = 0; i < nrows; ++i)
      result += column(i,0);

  result /= nrows;

  return result;
}
