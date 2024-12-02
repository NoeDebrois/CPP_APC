#include "NearestNeighborInterpolation.h"

/* TO BE COMPLETED */

NearestNeighborInterpolation::NearestNeighborInterpolation (const std::vector<Point> & points_):
Interpolation(points_) {}

double NearestNeighborInterpolation::interpolate (double x) const
{
    // If point no in domain return NaN
    // Else
    //      find the proper subinterval
    //      return the y of the closest point
    double result = err_value;

    // Compute result :
    std::vector<Point>::const_iterator prev = points.begin(); // You can write "auto" instead of
    std::vector<Point>::const_iterator curr = prev + 1;       // std::vector<Point>::const_iterator

    if (in_domain((x))) // Protected method from the base class
    {
        ++curr;
        ++prev;
    }

    if (curr != points.cend())
    {
        // We know (because everything is sorted) that : prev->get_x() <= x <= curr->get_x()
        double distance1 = x - prev->get_x();
        double distance2 = curr->get_x() - x;

        const bool first_is_closest = (distance1 < distance2);

        // If the first is closest we use its y to interpolate, otherwise we use the other y :
        result = first_is_closest ? prev->get_y() : curr->get_y();
    }

    return result;
}
