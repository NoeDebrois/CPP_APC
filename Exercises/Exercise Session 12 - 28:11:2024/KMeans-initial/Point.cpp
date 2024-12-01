#include <cmath>
#include <iostream>

#include "Point.h"

double
Point::distance (const Point& p) const
{
  double dist = 0.0;

  for (std::size_t i = 0; i < x.size(); ++i)
    {
      const double delta = x[i] - p.x[i];
      dist += delta * delta;
    }

  return sqrt(dist);

}

void
Point::print (void) const
{
  for (auto it = x.cbegin (); it != x.cend (); ++it)
    {
      std::cout << *it;
      std::cout << " ";
    }
  std::cout << std::endl;
}

double
Point::get_coord (int i) const
{
  return x[i];
}
