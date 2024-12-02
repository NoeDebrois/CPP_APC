//
// Created by Federica Filippini on 23/10/2020.
//

#ifndef BOXESINITIAL_BOX_H
#define BOXESINITIAL_BOX_H

#include <iostream>

class Box {

public:
    // constructor
    Box (double l, double b, double h);

    // copy constructor
    Box (const Box& b);

    // member functions
    double volume (void) const;
    unsigned getid (void) const {return id;}

    // assignment operator
    Box& operator= (const Box &);

private:
    double length;          // Length of a box
    double breadth;         // Breadth of a box
    double height;          // Height of a box
    unsigned id;            // Identification Number of the box
};


#endif //BOXESINITIAL_BOX_H
