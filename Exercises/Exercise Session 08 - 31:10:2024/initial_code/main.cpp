#include <iostream>

#include "LinearInterpolation.h"
#include "StepwiseInterpolation.h"
#include "NearestNeighborInterpolation.h"

int
main (void)
{
    std::vector<Point> points {
    Point (1.0, 0.0),
      Point (2.0, 3.0),
      Point (3.0, 1.0),
      Point (4.0, 2.0),
      Point (5.0, 4.0)
      };

    double x = 1.5;

    // Interpolation general_method(points) // We can do this because Interpolation is an abstract class.
    // What we have to do is to precise which type of interpolation we want to use :
    const LinearInterpolation Method1(points);
    std::cout << Method1.interpolate(x) << std::endl;
    const StepwiseInterpolation Method2(points);
    std::cout << Method2.interpolate(x) << std::endl;
    const NearestNeighborInterpolation Method3(points);
    std::cout << Method3.interpolate(x) << std::endl;

    return 0;
}
