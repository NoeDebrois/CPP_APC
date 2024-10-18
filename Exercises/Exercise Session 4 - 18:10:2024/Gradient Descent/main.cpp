//============================================================================
// Author      : Noé Debrois
// Version     : 1
//============================================================================

// EXERCISE SESSION 4 :
// Goal : to provide the implementation of gradient descent algorithm for polynomial functions
// f(x) = a_0 + a_1*x + a_2*x^2 + ... + a_n*x^n.
//
// Gradient descent algorithm :
// - Find the minimum of f in a given interval [inf, sup] ;
// - Start from a given initial point x_0 ;
// - Next candidate : x_i = x_{i-1} - delta * f'(x_{i-1}), where delta is a given constant.
//
// Required methods :
// "solve", that finds the minimum of f in [inf, sup] ;
// "solve_multistart", that randomly picks an initial point in [inf, sup] at each iteration ;
// "solve_domain_decomposition", that performs multistart after having split [inf, sup] in a given number of subintervals.
//

#include <iostream>

#include "Function.hpp"
#include "FunctionMin.hpp"

using std::cout;
using std::endl;

int main()
{
  std::cout << "**----**----**----**----**----**----**----**----**" << std::endl;
  std::cout << "TEST :" << std::endl;
  Function f ({1., 1., 2., -10., 2.});
  std::cout << "Function f, printed with method print() : ";
  f.print();
  std::cout << "Function f, evaluated in 1 with method eval(1) : " << f.eval (1) << std::endl;

  // Try to compute the derivative of f :
  Function fderiv({1., 1., 2., -10., 2.});
  fderiv = f.derivative();
  std::cout << "Derivative function of f, printed with method print() : ";
  fderiv.print();

  std::cout << "**----**----**----**----**----**----**----**----**" << std::endl;

  // Gradient descent :
  std::cout << "GRADIENT DESCENT :" << std::endl;
  FunctionMin minF (f, -1, 4, 1e-3, 1e-3, 1e6);
  std::cout << "Function minimum at: " << minF.solve() << std::endl;
  std::cout << "----" << std::endl;
  std::cout << "Function minimum (multi-start) at: "
            << minF.solve_multistart (100000) << std::endl;
  std::cout << "----" << std::endl;
  std::cout << "Function minimum (multi-start domain decomp) at: "
            << minF.solve_domain_decomposition (10, 100000) << std::endl;
  return 0;
}
