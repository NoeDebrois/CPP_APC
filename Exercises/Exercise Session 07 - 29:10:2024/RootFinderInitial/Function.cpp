/*
 * Function.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include <cmath>

#include "Function.hpp"

real Function::eval(real x) const {

  real val = 0;

  for (int i = 0; i < coefficients.size(); i++) {
    val += coefficients[i] * pow(x, i);
  }

  return val;

}

Function Function::derivative() const {
  std::vector<real> dcoefficients;
  for (int i = 0; i < coefficients.size() - 1; i++)
    dcoefficients.push_back((i + 1) * coefficients[i + 1]);
  return Function(dcoefficients);

}

void Function::print() const {
  std::cout << "Function" << std::endl;
  for (int i = 0; i < coefficients.size(); i++) {
    std::cout << coefficients[i] << "x^" << i;
    if (i < coefficients.size() -1)
      std::cout << " + ";
  }
  std::cout << std::endl;
}


