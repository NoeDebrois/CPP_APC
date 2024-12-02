#ifndef MONOMIAL_H_
#define MONOMIAL_H_

#include <vector>

#include "Point.h"

class Monomial
{
  double coeff;
  std::vector<double> powers;

public:
  Monomial (double c, std::vector<double> const & pows)
    : coeff (c), powers (pows) {};
  double eval (Point const & P) const;
};

#endif /* MONOMIAL_H_ */
