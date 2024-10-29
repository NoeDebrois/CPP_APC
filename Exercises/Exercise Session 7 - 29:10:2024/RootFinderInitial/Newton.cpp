/*
 * Newton.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include "Newton.hpp"

// WARNING : we need xp because the method in a const one !
real Newton::find_root(int &nit) const {
    real xp = x_init;
    real v = func.eval(xp);
    real xnew;

    nit = 0;
    bool conv = false;

    for (int k = 1; k <= max_iteration && !conv; ++k, ++nit) {
        double derv = der.eval(xp);
        if (!derv) {
            std::cerr << "ERROR: Division by 0 occurred in Newton algorithm"
                      << std::endl;
            return -inf;
        }

        xnew = xp - v / derv; // The x where the tangent intercepts the x-axis
        v = func.eval(xnew);  // Computes the image of this new point : it should shrink to zero...

        conv = converged(fabs(xnew - xp), fabs(v));

        if (!conv)
            xp = xnew;
    }
    return xnew;
  return 0;
}
