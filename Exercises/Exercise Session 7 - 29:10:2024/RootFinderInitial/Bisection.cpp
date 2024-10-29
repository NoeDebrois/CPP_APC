/*
 * Bisection.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include "Bisection.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>

// WARNING : we need a and b because the method in a const one !
real Bisection::find_root(int &nit) const {

  real a = inf_limit;
  real b = sup_limit;
  real u = func.eval(a);
  real l = b - a;
  real r;
  real c = a + l * 0.5;

  nit = 0;
  r = func.eval(c);

  if (u * func.eval(b) >= 0.0) {
      std::cout << "Error function has same sign at both endpoints" << std::endl;
      return -inf;
  }

  bool conv = converged(fabs(l), fabs(r));
  while (!conv && nit <= max_iteration) {
      (u * r < 0.) ? (b = c) : (a = c, u = r);
      l *= 0.5;
      c = a + l * 0.5;
      r = func.eval(c);
      conv = converged(fabs(l), fabs(r));
      ++nit;
  }
    return 0;
}
