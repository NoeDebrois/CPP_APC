#include <cmath>
#include <iostream>
#include <random>

#include "FunctionMinRn.h"
#include "FunctionRn.h"
#include "Monomial.h"

Point FunctionMinRn::solve (const Point & P) const
{
    Point P0(P.get_coords());
    /*
    Function df = f.derivative();
    double x0 = x_init;
    double f0 = f.eval (x0);
    bool converged = ((sup_limit - inf_limit) < tolerance
                      || std::abs (df.eval (x0)) < tolerance);
    unsigned int i;

    for (i = 0; i < max_iterations && ! converged; ++i)
    {
        const double deriv = df.eval (x0);
        double x1 = x0 - deriv * step;

        if (deriv > 0)
            x1 = std::max (inf_limit, x1);
        else
            x1 = std::min (sup_limit, x1);

        const double f1 = f.eval (x1);
        converged = (std::abs (f1 - f0) < tolerance
                     || std::abs (df.eval (x1)) < tolerance);

        x0 = x1;
        f0 = f1;
    }

    return x0;
     */
  return P0;
}

Point FunctionMinRn::solve (void) const
{
  std::vector<double> initial_coords;

  //compute domain mid point
  for (std::size_t i = 0; i < sup_limits.size (); ++i)
    initial_coords.push_back ((sup_limits[i] + inf_limits[i]) / 2);
  const Point P (initial_coords);

  return solve (P);
}

// gradient descent with multi-start
Point FunctionMinRn::solve_multistart (unsigned int n_trials) const
{
  /* Your code goes here */
}

// gradient descent with multi-start and domain decomposition
Point FunctionMinRn::solve_domain_decomposition (unsigned int n_intervals,
                                                 unsigned int n_trials) const
{
    /* Your code goes here */
}

void FunctionMinRn::next_inf_limit (std::vector<double> & cur_inf_limit,
                                    const std::vector<double> & internal_steps) const
{
    /* Your code goes here */
}


Point FunctionMinRn::compute_gradient (const Point & P0) const
{
    /* Your code goes here */
}

void FunctionMinRn::debug_info (const std::string& s) const
{
  if (debug)
    std::cout << s << " " << std::endl;
}

void FunctionMinRn::debug_info (const std::string& s, double val) const
{
  if (debug)
    std::cout << s << " " << val << std::endl;
}
