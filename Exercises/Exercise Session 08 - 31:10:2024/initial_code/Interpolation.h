#ifndef INTERPOLATION_HH
#define INTERPOLATION_HH

#include <vector>

#include "Point.h"

// This class has to be abstract since we don't want to be able to construct it if we don't precise
// which type of interpolation we want ! cf the virtual method in the bottom.

class Interpolation
{
protected:
  std::vector<Point> points; // sorted_vector
  static constexpr double err_value = std::numeric_limits<double>::quiet_NaN();
  bool in_domain(double x) const;

public:
  explicit Interpolation (const std::vector<Point> &); // Arg : vector of points.

  // Virtual method = 0 (cf explanation related to the abstract class, above).
  virtual double interpolate (double) const = 0;

  // We must provide the destructor : the default one is fine but we need to specify it as virtual.
  // If it's not 'virtual', only the base class destructor will be called, even if your object has
  // inherited from derived class : and then memory will be lost (cf lecture on dynamic binding).
  virtual ~Interpolation() = default;
  // Anytime you have a virtual method, you should provide a virtual destructor.
};

#endif // INTERPOLATION_HH
