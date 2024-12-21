#include <iostream>
#include <fstream>

#include "evaluate_by_column.hpp"

using la::dense_matrix;

double column_mean (const dense_matrix& column);

int main (int argc, char* argv[])
{
  /* Your code goes here */
  /* ... Initialize matrix from argument string ... */

  dense_matrix result = evaluate_by_column(matrix, column_mean);

  /* Your code goes here */
  /* ... Print result ... */

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
