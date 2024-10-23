#ifndef ASSIGNMENT1_2024_INVERSE_POWER_ITERATION_H
#define ASSIGNMENT1_2024_INVERSE_POWER_ITERATION_H

#include <iostream>
#include "squarematrix.h"
#include "vectorhelpers.h"
#include "matrixhelpers.h"
#include "eig_finder_helpers.h"

namespace eigenvalue {

    //class to implement the inverse power iteration
    class inverse_power_iteration
    {
    public:
        inverse_power_iteration(const std::size_t& m_it = 1000, const double& tol = 1e-6, const checkT& term = BOTH): max_it(m_it), tolerance(tol), termination(term) {};

        double solve(const linear_algebra::square_matrix& A, const std::vector<double>& x0) const;

    private:
        const std::size_t max_it = 1000;
        const double tolerance = 1e-6;
        const checkT termination = BOTH;
        bool converged(const double& residual, const double& increment) const;

    };

} // eigenvalue

#endif //ASSIGNMENT1_2024_INVERSE_POWER_ITERATION_H
