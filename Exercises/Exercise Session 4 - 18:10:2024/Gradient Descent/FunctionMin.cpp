#include <algorithm>
#include <cmath> // For std::abs() : absolute value.
#include <random> // For randomly picking an initial point in [inf, sup] at each iteration.

#include "FunctionMin.hpp"

// Gradient descent with x_init as initial point : it solves the minimum of f in [inf, sup].
double FunctionMin::solve (double x_init) const
{
  Function df = f.derivative();

  // To save the previous point and the previous function value :
  double x0 = x_init;
  double f0 = f.eval(x0);

  // Check convergence
  bool converged = false;

  // Until we converge, or we reach max iterations....
  for (size_t i = 0; i < max_iterations && ! converged; ++i)
  {
      // Evaluates derivative of the previous point :
      const double eval = df.eval(x0);
      // Computes new point :
      double x1 = x0 - step * eval;
      // Make sure that we don't go outside the interval :
      if (eval > 0)
          x1 = std::max(inf_limit, x1);
      else
          x1 = std::min(sup_limit, x1);
      // Computes new function value :
      const double f1 = f.eval(x1);
      // Checks convergence :
      if ((std::abs(x1 - x0) < tolerance) || (std::abs(f1 - f0) < tolerance) || (std::abs(df.eval(x1)) < tolerance)) {
          // |x1 - x0| < tol & f(x1) - f(x0)| < tol & |df(x1)| < tol
          converged = true;
      }

      // Saves the current values x1 & f1 in x0 & f0.
      // Those two (x0 and f0) become the previous values in the POV of the next iteration :
      x0 = x1;
      f0 = f1;
  }
  return x0;
}

// Gradient descent with x_init being the middle point in the interval [inf, sup] if no initial point argument is given.
double FunctionMin::solve (void) const
{
    return solve((inf_limit + sup_limit) / 2);
}

// Gradient descent with multi-start : it randomly picks an initial point in [inf, sup] at each iteration.
double FunctionMin::solve_multistart (unsigned n_trials) const
{
    std::default_random_engine generator(4850);
    std::uniform_real_distribution<double> distribution (inf_limit, sup_limit);

    double x_min = solve();
    double fmin = f.eval(x_min);

    for (unsigned n = 1; n < n_trials; ++n)
    {
        const double x_guess = distribution(generator);  // That's a callable object
        // Let's try with a new randomly picked initial point (x_guess) :
        const double x_current = solve(x_guess);
        const double f_current = f.eval(x_current);
        // Let's check if we obtained a better minimum :
        if (f_current < fmin) {
            x_min = x_current; // Update the x of the minimum
            fmin = f_current; // Update the function value of the minimum
        }
    }
    return x_min;
}

// Gradient descent with multi-start and domain decomposition (splitting of [inf, sup] in a given nb of sub-intervals).
double FunctionMin::solve_domain_decomposition (unsigned n_intervals, unsigned n_trials) const {
    // Domain decomposition, i.e, splitting of [inf, sup] in a given nb of sub-intervals :
    std::vector<std::pair<double, double>> intervals;
    double interval_width = (sup_limit - inf_limit) / n_intervals;

    // Build all subintervals :
    for (int i = 0; i < n_intervals; ++i) {
        double lower_bound = inf_limit + i * interval_width;
        double upper_bound = lower_bound + interval_width;
        intervals.push_back({lower_bound, upper_bound});
    } // intervals contain all the n_intervals sub-intervals of [inf, sup].

    // Let's perform multistart on all the subintervals of [inf, sup] :
    double x_min = solve(); // Benchmark x_min
    double f_min = f.eval(x_min); // Benchmark f_min

    // Loop over all subintervals :
    for (int i = 0; i < intervals.size(); ++i) {
        // Access the lower and upper bounds for each sub-interval :
        double const inf = intervals[i].first;
        double const sup = intervals[i].second;

        // Create a new FunctionMin object with the right bounds (that's inefficient : think how to improve this!) :
        FunctionMin f_subinterval(f, inf, sup, tolerance, step, max_iterations);

        // Call MultiStart(n_trials) on this subinterval :
        const double x_current = f_subinterval.solve_multistart(n_trials);

        // Compute the value of f at this x_current :
        const double f_current = f.eval(x_current);

        // If the value of f at x_current is < f_min : update f_min and x_min :
        if (f_current < f_min) {
            x_min = x_current;
            f_min = f_current;
        }
    }
    // At the end, we return the best x, i.e the best in both the POV of the multistart and the domain decomposition :
    return x_min;
}
