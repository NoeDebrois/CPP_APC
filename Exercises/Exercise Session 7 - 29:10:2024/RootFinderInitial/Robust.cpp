/*
 * Robust.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include "Robust.hpp"

real Robust::find_root(int &nit_bis, int &nit_newt) const {
    Bisection bs(
        func,
        inf_limit,
        sup_limit,
        cratio * tolerance,
        termination_criteria,
        max_iteration);

    real x_bis = bs.find_root(nit_bis); // Initial guess for Newton, found by bisection

    Newton nw(
        func,
        x_bis,
        tolerance,
        termination_criteria,
        max_iteration);

    return nw.find_root(nit_newt);
}


