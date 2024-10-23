#include "matrixhelpers.h"

namespace linear_algebra
{
    //LU factorization of a square matrix A
    void lu(const square_matrix& A, square_matrix& L, square_matrix& U)
    {
        const std::size_t n = A.size();

        L = square_matrix(n);
        U = A;

        for (std::size_t i = 0; i < n; i++) {
            L(i,i) = 1.;
        }

        //building L and U via gauss elimination
        for (std::size_t k = 0; k < n; k++) {
            for (std::size_t i = k+1; i < n; i++) {
                double multiplier = U(i,k)/U(k,k);
                L(i,k) = multiplier;
                U(i,k) = 0.;
                for (std::size_t j = k+1; j < n; j++) {
                    U(i,j) -= multiplier*U(k,j);
                }
            }
        }
    }

    //backward substitutions (U upper triangular not singular)
    std::vector<double> backsolve(const square_matrix& U, const std::vector<double>& b)
    {
        std::size_t n = b.size();
        std::vector<double> x(n);

        if (U.size() != n) {
            std::cerr << "Error: dimensions don't agree!" << std::endl;
        }

        for (std::size_t i = 1; i <= n; i++) {
            double s = 0.;
            for (std::size_t j = 1; j < i; j++)
                s += U(n-i,n-j)*x[n-j];
            x[n-i] = (b[n-i] - s)/U(n-i,n-i);
        }
        return x;
    }

    //forward substitutions (L lower triangular)
    std::vector<double> forwardsolve(const square_matrix& L, const std::vector<double>& b)
    {
        std::size_t n = b.size();
        std::vector<double> x(n);

        if (L.size() != n) {
            std::cerr << "Error: dimensions don't agree!" << std::endl;
        }

        for (std::size_t i = 0; i < n; i++) {
            double s = 0.;
            for (std::size_t j = 0; j < i; j++)
                s += L(i,j)*x[j];
            x[i] = (b[i] - s)/L(i,i);
        }
        return x;
    }
}
