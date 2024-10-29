/*
 * Newton.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#ifndef NEWTON_H_
#define NEWTON_H_

#include <cstdlib>
#include <cmath>
#include "rootfinding.hpp"
#include "Function.hpp"
#include "RootFinder.hpp"

class Newton : public RootFinder {
protected:
    Function der;
    real x_init;

public:
  Newton(const Function &f, real xp, real tol, const checkT &term_c, int max_i) :
      RootFinder(f, tol, term_c, max_i), der(f.derivative()), x_init(xp) {}

  real find_root(int &nit) const;
};

#endif /* NEWTON_H_ */
