/*
 * Function.h
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

#include <vector>
#include <iostream>
#include "rootfinding.hpp"

class Function {
private:
  std::vector<real> coefficients;

public:
  Function(const std::vector<real> &coeff) : coefficients(coeff) {};
  real eval(real x) const;
  Function derivative() const;
  void print() const;
};

#endif /* FUNCTION_HPP_ */
