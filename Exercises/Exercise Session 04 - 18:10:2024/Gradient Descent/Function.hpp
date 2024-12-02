/*
 * Function.h
 *
 *  Created on: Oct 18, 2024
 *      Author: Noé Debrois
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <iostream>
#include <vector>

class Function
{
private:
  std::vector<double> coefficients;

public:
  Function (const std::vector<double> & coeff): coefficients (coeff) {};
  double eval (double x) const;
  Function derivative (void) const;
  void print (void) const;
};

#endif /* FUNCTION_H_ */
