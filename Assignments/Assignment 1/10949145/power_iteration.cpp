#include "power_iteration.h"

namespace eigenvalue {

    using linear_algebra::operator*;
    using linear_algebra::operator-;

    double power_iteration::solve(const linear_algebra::square_matrix& A, const std::vector<double>& x0) const
    {
        // MY CODE :
        // Check that x0 is of norm 1 :
        std::vector<double>x = x0;

        double nu_new = 0; // what we will return
        double nu_old = 0;  // stores the old value of the eigenvalue

        // Initialize :
        // tolerance <- 1e-6 (this->tolerance);
        // Tmax <- 10000 (this->max_it);
        double res = this->tolerance + 1;
        double inc = this->tolerance + 1;
        int t = 0;

        // while not converged and t < Tmax do :
        while(!this->converged(res, inc) && t < this->max_it) {
            // z(k+1) = Ax(k) (2)
            std::vector<double> z(A.size());
            z = A * x; // operator * has been redefined !

            // x(k+1) = z(k+1) / ||z(k+1)|| (3), i.e,
            // Normalize z : z(k+1) -> z(k+1) // ||z(k+1)||...
            linear_algebra::normalize(z);
            // ... and update x : x(k+1) = z(k+1) / ||z(k+1)|| :
            x = z;

            // nu(k+1) = (x(k+1), Ax(k+1)) (4), i.e,
            // Compute the current eigenvalue nu(k+1) :
            nu_new = linear_algebra::scalar(z, A * z); // operator * has been redefined !

            // Recompute residual : ||Ax(k+1) - nu(k+1)x(k+1)||
            res = linear_algebra::norm(A * z - nu_new * z);
            // Recompute increment : |nu(k+1) - nu(k)| / |nu(k+1)|
            inc = std::abs(nu_new - nu_old) / std::abs(nu_new);

            // Update the old eigenvalue for the next iteration :
            nu_old = nu_new;

            // Increment the counter :
            t++;

            if (t == this->max_it) {
                std::cerr << "max iterations exceeded" << std::endl;
            }
        }
        return nu_new;
    }

    bool power_iteration::converged(const double& residual, const double& increment) const
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