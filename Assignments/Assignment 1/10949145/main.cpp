#include <iostream>
#include <string>

#include "squarematrix.h"
#include "vectorhelpers.h"
#include "power_iteration.h"
#include "inverse_power_iteration.h"
#include "shift_inverse_power_iteration.h"

int main() {

    std::string filename = "../inputs/input_50.txt";

    linear_algebra::square_matrix A(filename);
    std::vector<double> x0(A.size());
    x0[0] = 1.; //starting point

    eigenvalue::power_iteration pi(10000, 1e-6, BOTH);
    eigenvalue::inverse_power_iteration inv_pi(10000, 1e-6, BOTH);
    eigenvalue::shift_inverse_power_iteration s_inv_pi(10000, 1e-6, BOTH);

    double max_expected, min_expected, closest_expected;

    if (filename == "../inputs/input_10.txt"){
        max_expected = 5.10274;
        min_expected = -0.0817798;
        closest_expected = 0.946734;
    }
    else if (filename == "../inputs/input_20.txt"){
        max_expected = 10.1993;
        min_expected = 0.0591506;
        closest_expected = 1.70976;
    }
    else if (filename == "../inputs/input_50.txt"){
        max_expected = 25.0613;
        min_expected = 0.0171826;
        closest_expected = 2.04765;
    }

    double max_obtained = pi.solve(A, x0);
    std::string result;
    if (std::abs(max_obtained - max_expected) < 1e-3)
        result = "CONVERGED";
    else
        result = "NOT CONVERGED";
    std::cout << "Maximum modulus eigenvalue: " << max_obtained << " --> " << result << std::endl;

    double min_obtained = inv_pi.solve(A, x0);
    if (std::abs(min_obtained - min_expected) < 1e-3)
        result = "CONVERGED";
    else
        result = "NOT CONVERGED";
    std::cout << "Minimum modulus eigenvalue: " << min_obtained << " --> " << result << std::endl;

    double mu = 2.0;
    double closest_obtained = s_inv_pi.solve(A, mu, x0);
    if (std::abs(closest_obtained - closest_expected) < 1e-3)
        result = "CONVERGED";
    else
        result = "NOT CONVERGED";
    std::cout << "Eigenvalue closest to " << mu << ": " << closest_obtained << " --> " << result << std::endl;

    return 0;
}
