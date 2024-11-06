#ifndef DENSE_MATRIX_HPP
#define DENSE_MATRIX_HPP

#include <istream>
#include <vector>

#include "matrix.hpp"

class DenseMatrix : public Matrix // Child class of Matrix !
{
   private:
       std::vector<double> m_data; // stores its elements in a vector of data
       unsigned sub2ind (unsigned i, unsigned j) const; // returns a single idx to find the corresponding element
       // in the vector of data (above). It converts from the idx system of the matrix to the idx system of the vector of
       // data.

   public:
       // You can't create a DenseMatrix as "DenseMatrix A" (look at the constructors below). Why is that ? Because you
       // cannot resize a matrix.
       DenseMatrix (unsigned rows, unsigned columns,
             double value = 0.0);
       // First constructor to create a DenseMatrix :
       // - First way : DenseMatrix(4, 4) : a 4x4 matrix with all zeros.
       // - Second way : DenseMatrix(4, 4, 5.1) : a 4x4 matrix with all 5.1's.

       DenseMatrix (unsigned rows, unsigned columns,
             const std::vector<double> & values);

       void read (std::istream &);

       void swap (DenseMatrix &);

       double & operator () (unsigned i, unsigned j) override;     // setter-like operator. Returns a ref.
       double operator () (unsigned i, unsigned j) const override; // getter-like operator. Returns a copy.

       DenseMatrix transposed (void) const;
       // We cannot call : "A.transposed()" since it returns a copy.
       // We have to write : "DenseMatrix At = A.transposed()".


       // These will be very useful for MPI (parallel computing) :
       double * data (void);
       const double * data (void) const;
};

DenseMatrix operator * (const DenseMatrix &, const DenseMatrix &);

void swap (DenseMatrix &, DenseMatrix &);

#endif // DENSE_MATRIX_HH
