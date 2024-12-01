#ifndef POINT_H_
#define POINT_H_

#include <vector>

class Point
{
protected:
  std::vector<double> x; // A point is a vector of double.

public:
  // Constructor :
  Point(std::vector<double> const &  coords) : x(coords) {};

  // Compute distance to Point p :
  double distance (const Point& p) const;

  // Print function :
  void print (void) const;

  // Getter :
  double get_coord(int i) const;
};

#endif /* POINT_H_ */
