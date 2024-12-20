//
// Created by Federica Filippini on 18/01/23.
//

#ifndef MOLECULES_VECTOR2D_H
#define MOLECULES_VECTOR2D_H

class Vector2D {

private:
  double x = 0;
  double y = 0;

public:
  Vector2D (void) = default;
  Vector2D (double _x, double _y): x(_x), y(_y) {}

  double get_x (void) const;
  double get_y (void) const;

  void set_x (double _x);
  void set_y (double _x);

  void print (void) const;

};

#endif //MOLECULES_VECTOR2D_H
