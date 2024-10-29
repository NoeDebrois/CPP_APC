/*
 * Robust.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#ifndef ROBUST_H_
#define ROBUST_H_

// You need those include :
#include "Newton.hpp"
#include "Bisection.hpp"

class Robust : public RootFinder {
protected:
    real cratio;
    real inf_limit;
    real sup_limit;

public:
  Robust(const Function &f, real inf_l, real sup_l, real tol, real cr,
         const checkT &term_c, int max_i) :
      RootFinder(f, tol, term_c, max_i), cratio(cr), inf_limit(inf_l), sup_limit(sup_l) {}

  real find_root(int &nit_bis, int &nit_newt) const;

};

#endif /* ROBUST_H_ */
