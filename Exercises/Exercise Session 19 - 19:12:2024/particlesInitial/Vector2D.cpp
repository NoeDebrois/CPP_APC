//
// Created by Federica Filippini on 18/01/23.
//

#include "Vector2D.h"

#include <iostream>

double Vector2D::get_x (void) const
{
  return x;
}

double Vector2D::get_y (void) const
{
  return y;
}

void Vector2D::set_x (double _x)
{
  x = _x;
}

void Vector2D::set_y (double _y)
{
  y = _y;
}

void Vector2D::print (void) const
{
  std::cout << "(" << x << "," << y << ")" << std::endl;
}
