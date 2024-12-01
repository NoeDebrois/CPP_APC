#ifndef POINT_H_
#define POINT_H_

#include <vector>

class Point
{
protected:
  std::vector<double> x;

public:
  Point (std::vector<double> const &  coords) : x(coords) {};

  //compute distance to Point p
  double
  distance (const Point& p) const;
  void
  print (void) const;
  double
  get_coord(int i) const;
};

#endif /* POINT_H_ */
