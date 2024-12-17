#include "quadrature.hh"
#include <functional>

namespace quadrature
{

  double trapezoidal (const std::function<double (double)> & f, double a, double b, unsigned n)
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
