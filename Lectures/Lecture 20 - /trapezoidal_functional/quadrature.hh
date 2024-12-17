#ifndef QUADRATURE
#define QUADRATURE
#include <functional>


namespace quadrature
{
  double
  trapezoidal (const std::function<double (double)> & f, double a, double b, unsigned n);
}

#endif // QUADRATURE
