#include "LinearInterpolation.h"

LinearInterpolation::LinearInterpolation (const std::vector<Point> & points_):
Interpolation(points_) {} // We call the base class constructor.

double LinearInterpolation::interpolate (double x) const {
    double result = err_value;

    // If point no in domain return NaN
    // Else
    //      find the proper subinterval
    //      use the straight line equation to compute y

    std::vector<Point>::const_iterator prev = points.begin();
    std::vector<Point>::const_iterator curr = prev + 1;

    // for a vector v, v.front() is equivalent as v[0], analog with back().
    if (in_domain(x)) // Protected method from the base class !
    {
        // Compute result :
        while (curr != points.end() && curr->get_x() < x) {
            ++curr;
            ++prev;
        }
    }

    if (curr != points.cend())
    {
        // It means that we exited because we found the proper subinterval.
        const double x1 (prev->get_x()), x2 (curr->get_x());
        const double y1 (prev->get_y()), y2 (curr->get_y());
        result = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
    };

    // Else, we return NaN (it means that x is outside the domain).
    return result;
}
