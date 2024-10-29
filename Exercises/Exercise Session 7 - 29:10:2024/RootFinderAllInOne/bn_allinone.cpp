/*!
 * \file bn-allinone.cpp
 * \brief all the exercise code in a single file. Original version by Luca Formaggia
 * \date Oct 14, 2016
 * Modified by Noé Debrois, 29/10/2024.
 */

// Exercise session 7 - 29/10/2024.
// - For each of the three root-finding technics, the last argument is "int &nit" :
//      -- nit is passed by reference ;
//      -- so we can see at the end how many iterations we needed before reaching the right tolerance ;
//      -- the fact that it's passed by reference allows us to only return the approximation of the root, but the nit
//         variable will still be accessible outside the method implementation.
// - About the argument before the last : const checkT &check (in the 3 root-finding technics)
//      -- "enum" (see below just after "typedef double real") : defines keywords : increment == 0, residual == 1,
//         both = 2. So it's an easy way to check conditions based on numbers without having to remember which number ;
//      -- see the "converged" method : the same as : "if (check == INCREMENT) return(increment < tol)" etc. So if we
//         are in the check regarding INCREMENT, we check INCREMENT, same with RESIDUAL and BOTH ;
// We want to restructure this program in different files like in the OOP framework.

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>

//! Type for real numbers
typedef double real;

//! Type for convergence check
enum checkT {
  INCREMENT, //! Check the difference between subsequent iterates
  RESIDUAL,  //! Check the residual
  BOTH       //! Check both conditions
};

//! Function f(x)
real f(real x) {
  return pow(x, 2) - 0.5;
}

//! First derivative of function f(x) 
real df(real x) {
  return 2. * x;
}

bool converged(real increment, real residual,
               real tol, const checkT &check) {
  /*
    Compares a parameter value against desired tolerance.
    The parameter is chosen upon the value of check.
  */
  switch (check) {
  case INCREMENT:return (increment < tol);
  case RESIDUAL:return (residual < tol);
  case BOTH:return ((increment < tol) && (residual < tol));
  default:return false;
  }
  // It is the same as :
  /*
   if (check == INCREMENT)
      return (increment < tol);
   else if (check == RESIDUAL)
      return (residual < tol);
   else if (check == BOTH)
      return ((increment < tol) && (residual < tol));
   */
}

// BISECTION METHOD
real bisection(real a, real b,
               real tol, int maxit,
               const checkT &check, int &nit) {
  real u = f(a);          // Evaluate f on boundary a
  real l = b - a;         // Interval length
  real r;                 // Residual
  real c = a + l * 0.5;   // Middle point

  nit = 0;
  r = f(c);

  if (u * f(b) >= 0.0) { // It's an assumption : obviously this test doesn't always work.
    std::cout << "Error Function has same sign at both endpoints" << std::endl;
    return -std::numeric_limits<double>::infinity();
    // If instead we want to return NaN : std::numeric_limits<double>::quiet_NaN();
  }

  while (!(converged(fabs(l), fabs(r), tol, check))
      && (nit <= maxit)) {
    /*
      If f(c)f(a) < 0 then the new "right" boundary is c;
      otherwise move the "left" boundary

      The expression
         test ? stat1 : stat2
      means
         if(test)
            stat1
         else
            stat2
    */
    (u * r < 0.) ? (b = c) : (a = c, u = r);

    /* Exactly the same as :
    if (u * r < 0.0) {
      b = c; // the new right boundary becomes the old middle point (zero is on the left of the mid point)
    }
    else {
      a = c; // the new left boundary becomes the old middle point (zero is on the right of the mid point)
      u = r; // update f(a) = f(old midpoint)
    }
    */

    l *= 0.5;  // Now interval is twice smaller (b-a) * 0.5 here
    c = a + l; // Now we move to the mid point of this new interval, i.e we move + half of the length
    r = f(c);  // Update the image of the mid point
    ++nit;
  }
  return c;
}

// NEWTON METHOD
real newton(real xp, real tol, int maxit,
            const checkT &check, int &nit) {
  real v = f(xp);
  real xnew;

  nit = 0;
  bool conv = false;

  for (int k = 1; k <= maxit && !conv; ++k, ++nit) {
    double derv = df(xp);
    if (!derv) {
      std::cerr << "ERROR: Division by 0 occurred in Newton algorithm"
                << std::endl;
      exit(1);
    }

    xnew = xp - v / derv; // The x where the tangent intercepts the x-axis
    v = f(xnew);          // Computes the image of this new point : it should shrink to zero...
    conv = converged(fabs(xnew - xp), fabs(v), tol, check);
    if (!conv)
      xp = xnew;
  }
  return xnew;

}

// ROBUST METHOD
real robust(real a, real b,
            real tol, real cfratio,
            int maxit, const checkT &check,
            int &nit_coarse, int &nit_fine) {
  // Call bisection method (with a greater desired tolerance)
  real tol_bis = cfratio * tol;
  real x_bis = bisection(a, b, tol_bis, maxit, check, nit_coarse);

  /*
    Call a Newton algorithm which uses as an initial value
    the solution given by bisection method
  */
  return newton(x_bis, tol, maxit, check, nit_fine);
}

// MAIN FUNCTION
int main() {

  int nit_bis;
  int nit_newt;
  std::cout << std::numeric_limits<double>::infinity() << std::endl;
  std::cout << "Bisection" << std::endl;
  std::cout << bisection(0., 1., 1e-8, 100, INCREMENT, nit_bis);
  std::cout << '\t' << nit_bis << std::endl;

  std::cout << "Newton" << std::endl;
  std::cout << newton(.1, 1e-8, 100, INCREMENT, nit_newt);
  std::cout << '\t' << nit_newt << std::endl;

  std::cout << "Robust" << std::endl;
  std::cout << robust(0., 1., 1e-8, 1e4, 100, INCREMENT, nit_bis, nit_newt);
  std::cout << '\t' << nit_bis << " " << nit_newt << std::endl;

  return 0;
}
