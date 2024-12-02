#ifndef LINEAR_INTERPOLATION_HH
#define LINEAR_INTERPOLATION_HH

#include <vector>

#include "Interpolation.h"

class LinearInterpolation: public Interpolation // This class is a derived class from Interpolation.
{

public:
  explicit LinearInterpolation (const std::vector<Point> &); // Arg : vector of points.

  double interpolate (double) const override; // We override the analogous method from the base class.
};

#endif // LINEAR_INTERPOLATION_HH
