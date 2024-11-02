#ifndef POINT_HH
#define POINT_HH

class Point
{
  double x;
  double y;

public:
  Point (double f1, double f2);

  double get_x (void) const;
  double get_y (void) const;
};

#endif // POINT_HH
