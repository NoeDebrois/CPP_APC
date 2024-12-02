//
// Created by Federica Filippini on 23/10/2020.
//

#ifndef BOXESV1_BOX_H
#define BOXESV1_BOX_H

#include <iostream>

class Box {

public:
    // constructor
    Box (double l, double b, double h): length(l), breadth(b), height(h)
    {
        std::cout << "Constructing a box" << std::endl;
        count++;
        id = count;
    }

    // copy constructor
    Box (const Box& b): length(b.length), breadth(b.breadth), height(b.height)
    {
        std::cout << "Using copy constructor" << std::endl;
        count ++;
        id = count;
    }

    // member functions
    double volume (void) const;
    static unsigned getcount (void) {return count;}
    unsigned getid (void) const {return id;}

    // assignment operator
    Box& operator= (const Box &);

private:
    double length;          // Length of a box
    double breadth;         // Breadth of a box
    double height;          // Height of a box
    unsigned id;            // Identification Number of the box
    static unsigned count;  // Number of boxes

};


#endif //BOXESV1_BOX_H
