//
// Created by Federica Filippini on 23/10/2020.
//

#include "Box.h"

// initialization of the static variable
unsigned Box::count = 0;

// member functions:
double Box::volume() const
{
    return length * breadth * height;
}

// assignment operator
Box& Box::operator= (const Box &b)
{
    std::cout << "Using assignment operator" << std::endl;
    length = b.length;
    breadth = b.breadth;
    height = b.height;

    return *this;
}