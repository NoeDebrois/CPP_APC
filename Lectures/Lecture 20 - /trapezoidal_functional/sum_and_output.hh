#ifndef SUM_AND_OUTPUT
#define SUM_AND_OUTPUT

#include <ostream>
#include <vector>

namespace mpi
{
  void sum_and_print (std::vector<double> integral, std::ostream &,
                      double a, double b, unsigned n);
}

#endif // SUM_AND_OUTPUT
