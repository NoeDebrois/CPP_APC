#include "Interpolation.h"

Interpolation::Interpolation (const std::vector<Point> & points_): // Arg : vector of points.
points(points_) {}


bool Interpolation::in_domain(double x) const {
    return (x < points.front().get_x() && x > points.back().get_x());
}