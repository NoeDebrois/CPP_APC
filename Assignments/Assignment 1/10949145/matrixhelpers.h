#ifndef MATRIX_HELPERS_H
#define MATRIX_HELPERS_H

#include "squarematrix.h"

#include <vector>
#include <utility>

namespace linear_algebra
{
    //method to compute the LU factorization of A (supposing it is invertible)
    void lu(const square_matrix& A, square_matrix& L, square_matrix& U);

    //method to solve the sistem Ux = b, with U upper triangular
    std::vector<double> backsolve(const square_matrix& U, const std::vector<double>& b);

    //method to solve the sistem Lx = b, with L lower triangular
    std::vector<double> forwardsolve(const square_matrix& L, const std::vector<double>& b);
}

#endif
