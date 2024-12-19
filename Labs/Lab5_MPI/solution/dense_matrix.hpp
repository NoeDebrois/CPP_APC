#ifndef DENSE_MATRIX_H_
#define DENSE_MATRIX_H_

#include <istream>
#include <vector>
#include <cmath>

#include "matrix.hpp"

class DenseMatrix : public Matrix
{
  public:
   typedef std::vector<double> container_type;

  private:
    container_type m_data;

    std::size_t sub2ind (std::size_t i, std::size_t j) const;

  public:
    DenseMatrix (std::size_t rows = 0, std::size_t columns = 0, 
                  double value = 0.0);
  DenseMatrix (std::size_t rows, std::size_t columns, 
               const container_type& values);

  void read (std::istream &);

  void swap (DenseMatrix &);

  double & operator () (std::size_t i, std::size_t j) override;
  double operator () (std::size_t i, std::size_t j) const override;

  DenseMatrix transposed (void) const;

  double * data (void);
  const double * data (void) const;
  container_type get_data (void) const;
};

DenseMatrix operator * (const DenseMatrix &, const DenseMatrix &);

void swap (DenseMatrix &, DenseMatrix &);

//double norm (const DenseMatrix&);

#endif // DENSE_MATRIX_HH
