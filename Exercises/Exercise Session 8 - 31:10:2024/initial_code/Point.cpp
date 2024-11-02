#include "Point.h"

Point::Point (double f1, double f2)
  : x (f1), y (f2) {}

double
Point::get_x (void) const
{
  return x;
}

double
Point::get_y (void) const
{
  return y;
}
