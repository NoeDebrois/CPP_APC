#ifndef NEAREST_NEIGHBOR_INTERPOLATION_HH
#define NEAREST_NEIGHBOR_INTERPOLATION_HH

#include <vector>

#include "Interpolation.h"

/* TO BE COMPLETED */

class NearestNeighborInterpolation: public Interpolation
{
public:
  explicit NearestNeighborInterpolation (const std::vector<Point> &);

  double interpolate (double) const override; // We override the base class method
};

#endif // NEAREST_NEIGHBOR_INTERPOLATION_HH
