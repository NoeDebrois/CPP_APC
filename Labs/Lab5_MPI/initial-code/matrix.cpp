#include "matrix.hpp"

Matrix::Matrix (std::size_t rows, std::size_t cols)
  : n_rows (rows), n_cols (cols) {}

std::size_t
Matrix::get_n_cols (void) const
{
  return n_cols;
}

std::size_t
Matrix::get_n_rows (void) const
{
  return n_rows;
}

void
print (const Matrix & matrix)
{
  for (std::size_t i = 0; i < matrix.get_n_rows (); ++i)
  {
   for (std::size_t j = 0; j < matrix.get_n_cols (); ++j)
    {
      std::cout << matrix (i, j) << "\t";
    }
    std::cout << std::endl;
  }
}
