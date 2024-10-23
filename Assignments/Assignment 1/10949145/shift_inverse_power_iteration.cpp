#include "shift_inverse_power_iteration.h"

#include "power_iteration.h"

namespace eigenvalue {

    using linear_algebra::operator*;
    using linear_algebra::operator-;

    double shift_inverse_power_iteration::solve(const linear_algebra::square_matrix& A, const double& mu, const std::vector<double>& x0) const
    {
        // MY CODE :
        // Check that x0 is of norm 1 :
        std::vector<double>x = x0;
        linear_algebra::normalize(x);

        // Build the identity matrix :
        linear_algebra::square_matrix mu_I = linear_algebra::square_matrix(A.size());
        for (int i = 0; i < A.size(); ++i) {
            mu_I(i, i) = mu;
        }

        // Build our input matrix on which we will call the Inverse Power Iteration method :
        linear_algebra::square_matrix input_matrix = linear_algebra::square_matrix(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                input_matrix(i, j) = A(i, j) - mu_I(i, j); // A - mu * I
            }
        }

        // Computation of the minimum modulus eigenvalue lambda_tilde_mu of A - mu * I using the Inverse Power Iteration
        // method :
        inverse_power_iteration IPI; // I cannot this->max_it since IT IS PRIVATE in the base class inverse_power_iteration and here I am in a class which derives from inverse_power_iteration.
        const double lambda_tilde_mu = IPI.solve(input_matrix, x);

        // Computation of the eigenvalue of A closest ti mu as lambda_mu = lambda_tilde + mu :
        const double lambda_mu = lambda_tilde_mu + mu;
        return lambda_mu;
    }

} // eigenvalue