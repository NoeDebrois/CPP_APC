#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

typedef std::vector<double> nd_vector;

static constexpr double pi = M_PI;

double ff (const nd_vector&);
double gg (const nd_vector&);
double compute_laplacian (const std::function<double (const nd_vector&)> & f, const nd_vector& x, double h = 0.01);
// Generic function f that returns a double and take as input a vector.

int main()
{
    nd_vector x{1., 1., 1., 1.};
    std::cout << "ff(x) = " << ff(x) << std::endl;
    std::cout << "Df(x) = " << compute_laplacian(ff, x) << std::endl;

    x = {pi/2, 0.};
    std::cout << "gg(x) = " << gg(x) << std::endl;
    std::cout << "Dg(x) = " << compute_laplacian(gg, x) << std::endl;

    return 0;
}

double ff (const nd_vector& x)
{
  double val{0.};
  // val = 1 + x1 + x2^2 + x3^3 + x4^4....
  for (nd_vector::size_type i = 0; i < x.size(); ++i)
    val += std::pow(x[i], i);
  return val;
}

double gg (const nd_vector& x)
{
  double val{0.};
  // val = sin(x0) + sin(x1) + sin(x2) + ...
  for (nd_vector::size_type i = 0; i < x.size(); ++i)
    val += std::sin(x[i]);
  return val;
}

// It's just the implementation of the classical Laplacian approximation:
double compute_laplacian (const std::function<double (const nd_vector&)> & f,
                          const nd_vector& x, double h)
{
    double laplacian {0.};
    const double h2 = h * h;
    for (nd_vector::size_type i = 0; i < x.size (); ++i)
    {
        nd_vector x_plus_h (x), x_minus_h (x);
        x_plus_h[i] += h;
        x_minus_h[i] -= h;
        laplacian += (f (x_plus_h) - 2 * f (x) + f (x_minus_h)) / h2;
    }
    return laplacian;
}

