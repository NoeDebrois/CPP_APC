#include "inverse_power_iteration.h"

#include "power_iteration.h"

namespace eigenvalue {

    using linear_algebra::operator*;
    using linear_algebra::operator-;

    double inverse_power_iteration::solve(const linear_algebra::square_matrix& A, const std::vector<double>& x0) const
    {
        // MY CODE :
        // Check that x0 is of norm 1 :
        std::vector<double>x = x0;
        linear_algebra::normalize(x);

        // Inversion of A using LU factorization :
        // 1) Find L lower-triangular, U upper-triangular such that A = LU :
        linear_algebra::square_matrix L = linear_algebra::square_matrix(A.size());
        linear_algebra::square_matrix U = linear_algebra::square_matrix(A.size());
        linear_algebra::lu(A, L, U); // L and U are modified here.
        // 2) solve for all i, LUai = ei [ai : col vectors of A^-1 ; ei : idem with Id] :
        //      2.1) solve Ly = ei with forwardsolve ;
        //      2.2) solve Uai = y with backsolve.
        linear_algebra::square_matrix Ainv = linear_algebra::square_matrix(A.size()); // A^-1
        for (int i = 0; i < A.size(); i++) {
            // Create ei :
            std::vector<double> e(A.size());
            e[i] = 1; // I don't know how to create directly a const std::vector<double> with 0s and a 1 at ith idx
            const std::vector<double> ei = e;
            // 2.1)
            std::vector<double> y = linear_algebra::forwardsolve(L, ei);
            // 2.2)
            std::vector<double> ai = linear_algebra::backsolve(U, y); // col vectors of A^-1
            for (int j = 0; j < ai.size(); j++) {
                Ainv(i, j) = ai[j];
            }
        }

        // Computation of the dominant eigenvalue of A^-1 using the Power Iteration method :
        power_iteration PI (this->max_it, this->tolerance, this->termination);
        const double max_obtained = PI.solve(Ainv, x);
        // OBVIOUSLY we don't want to recode the Power Iteration method so we call it from here.

        // Computation of the minimum modulus eigenvalue :
        const double lambdan = 1 / max_obtained;
        return lambdan;
    }

    bool inverse_power_iteration::converged(const double& residual, const double& increment) const
    {
        bool conv;

        switch(termination) {
            case(RESIDUAL):
                conv = residual < tolerance;
                break;
            case(INCREMENT):
                conv = increment < tolerance;
                break;
            case(BOTH):
                conv = residual < tolerance && increment < tolerance;
                break;
            default:
                conv = false;
        }
        return conv;
    }

} // eigenvalue