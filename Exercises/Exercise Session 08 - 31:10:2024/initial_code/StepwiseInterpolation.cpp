#include "StepwiseInterpolation.h"

/* TO BE COMPLETED */

StepwiseInterpolation::StepwiseInterpolation (const std::vector<Point> & points_):
Interpolation(points_) {}

double
StepwiseInterpolation::interpolate (double x) const {
    // If point no in domain return NaN
    // Else
    //      find the proper subinterval
    //      return the y of the left bound
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
        result = prev->get_y();
    }

    return result;
}
