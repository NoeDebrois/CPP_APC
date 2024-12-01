#ifndef CENTROID_H_
#define CENTROID_H_

#include <iostream>
#include <vector>

#include "Point.h"

class Centroid : public Point // Derived class
{
public:
  // Constructor : calls the constructor of Point class
  Centroid (std::vector<double> const & coords)
    : Point (coords) {};
  
  void update_coords (std::vector<Point *> const &); // We pass a const-reference.
};

#endif /* CENTROID_H_ */
