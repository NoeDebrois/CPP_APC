#include "inverse_power_iteration.h"

#ifndef ASSIGNMENT1_2024_SHIFT_INVERSE_POWER_ITERATION_H
#define ASSIGNMENT1_2024_SHIFT_INVERSE_POWER_ITERATION_H

namespace eigenvalue {

    class shift_inverse_power_iteration: public inverse_power_iteration
    {
    public:
        shift_inverse_power_iteration(const std::size_t& m_it = 1000, const double& tol = 1e-6, const checkT& term = BOTH): inverse_power_iteration(m_it, tol, term) {};

        //compute the nearest to mu eigenvalue of A
        double solve(const linear_algebra::square_matrix& A, const double& mu, const std::vector<double>& x0) const;
    };

} // eigenvalue

#endif //ASSIGNMENT1_2024_SHIFT_INVERSE_POWER_ITERATION_H
