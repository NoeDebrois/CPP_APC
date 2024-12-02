#include "FunctionRn.h"

double FunctionRn::eval (const Point & P) const
{
    /* Your code goes here */
}

void FunctionRn::addMonomial (const Monomial & m)
{
  monoms.push_back (m);
}

//evaluate derivative wrt dim j in P
double FunctionRn::eval_deriv (std::size_t j,
                               const Point & P) const
{
    /* Your code goes here */
}
