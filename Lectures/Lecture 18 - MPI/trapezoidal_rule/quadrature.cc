#include "quadrature.hh"

namespace quadrature
{
  double
  f (double x)
  {
    return x * x + 3 * x + 1;
  }

  double
  trapezoidal (double a, double b, unsigned n)
  {
    const double h = (b - a) / n;
    double sum = (f (a) + f (b)) / 2;
    for (unsigned i = 1; i < n; ++i)
      {
        const double x = a + h * i;
        sum += f (x);
      }
    return sum * h;
  }
}
