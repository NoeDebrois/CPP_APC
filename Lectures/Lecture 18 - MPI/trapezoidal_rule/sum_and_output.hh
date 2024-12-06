#ifndef SUM_AND_OUTPUT
#define SUM_AND_OUTPUT

#include <ostream>

namespace mpi
{
  void sum_and_print (double integral, std::ostream &,
                      double a, double b, unsigned n);
}

#endif // SUM_AND_OUTPUT
