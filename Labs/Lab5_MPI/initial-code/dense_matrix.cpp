#include <sstream>
#include <string>
#include <iostream>

#include "dense_matrix.hpp"

DenseMatrix::DenseMatrix (size_t rows, size_t columns, double value) :
  Matrix(rows, columns),
  m_data (n_rows * n_cols, value)
{}

DenseMatrix::DenseMatrix(size_t rows, size_t columns, const container_type& values) :
  Matrix(rows, columns),
  m_data(values)
{}

size_t
DenseMatrix::sub2ind (size_t i, size_t j) const
{
  return i * n_cols + j;
}

void
DenseMatrix::read (std::istream & in)
{
  std::string line;
  std::getline (in, line);

  std::istringstream first_line (line);
  first_line >> n_rows >> n_cols;
  m_data.resize (n_rows * n_cols);

  for (size_t i = 0; i < n_rows; ++i)
  {
    std::getline (in, line);
    std::istringstream current_line (line);

    for (size_t j = 0; j < n_cols; ++j)
    {
      /* alternative syntax: current_line >> operator () (i, j);
       * or: current_line >> m_data[sub2ind (i, j)];
       */
      current_line >> (*this)(i, j);
    }
  }
}

void
DenseMatrix::swap (DenseMatrix & rhs)
{
  using std::swap;
  swap (n_rows, rhs.n_rows);
  swap (n_cols, rhs.n_cols);
  swap (m_data, rhs.m_data);
}

DenseMatrix
DenseMatrix::transposed (void) const
{
  DenseMatrix At (n_cols, n_rows);

  for (size_t i = 0; i < n_cols; ++i)
    for (size_t j = 0; j < n_rows; ++j)
      At(i, j) = operator () (j, i);

  return At;
}

double *
DenseMatrix::data (void)
{
  return m_data.data ();
}

const double *
DenseMatrix::data (void) const
{
  return m_data.data ();
}

DenseMatrix::container_type
DenseMatrix::get_data (void) const
{
  return m_data;
}

DenseMatrix
operator * (const DenseMatrix & A, const DenseMatrix & B)
{
  DenseMatrix C (A.get_n_rows (), B.get_n_cols ());

  for (size_t i = 0; i < A.get_n_rows (); ++i)
    for (size_t j = 0; j < B.get_n_cols (); ++j)
      for (size_t k = 0; k < A.get_n_cols (); ++k)
        C(i, j) += A(i, k) * B(k, j);

  return C;
}

void
swap (DenseMatrix & A, DenseMatrix & B)
{
  A.swap (B);
}


double &
DenseMatrix::operator()(size_t i, size_t j)
{
  return m_data.at(sub2ind(i, j));
}

double
DenseMatrix::operator()(size_t i, size_t j) const
{
  return m_data.at(sub2ind(i, j));
}
