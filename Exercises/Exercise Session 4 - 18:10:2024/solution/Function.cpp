/*
 * Function.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include <cmath>

#include "Function.hpp"

double Function::eval (double x) const
{
  double val = 0;
  for (size_t i = 0; i < coefficients.size(); i++)
      val += coefficients[i] * pow (x, i);
  return val;
}

Function Function::derivative() const
{
  std::vector<double> dcoefficients;
  for (size_t i = 0; i < coefficients.size() - 1; i++)
      dcoefficients.push_back ((i + 1) * coefficients[i + 1]);
  return Function (dcoefficients);
}

void Function::print() const
{
  for (size_t i = 0; i < coefficients.size(); i++)
      std::cout << coefficients[i] << "  ";
  std::cout << std::endl;
}
