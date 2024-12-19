#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstddef>
#include <iostream>

class Matrix
{
protected:
  std::size_t n_rows;
  std::size_t n_cols;

public:
  Matrix (std::size_t rows = 0, std::size_t cols = 0);

  virtual double & operator () (std::size_t i, std::size_t j) = 0;

  virtual double operator () (std::size_t i, std::size_t j) const = 0;

  std::size_t get_n_rows() const;
  std::size_t get_n_cols() const;

  virtual ~Matrix (void) = default;
};

void
print (const Matrix & matrix);

#endif /* MATRIX_H_ */
