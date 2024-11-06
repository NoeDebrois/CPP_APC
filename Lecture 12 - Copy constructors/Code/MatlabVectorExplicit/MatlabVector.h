//
// Created by Federica Filippini on 09/10/2020.
//

#ifndef MATLABVECTOR_MATLABLIKEVECTOR_H
#define MATLABVECTOR_MATLABLIKEVECTOR_H

#include <vector>
#include <iostream>
#include <limits>

class MatlabVector {

    std::vector<double> elem;

public:
    // constructors
    MatlabVector (void) = default;
    explicit MatlabVector (unsigned n): elem(n,0.) {}

    double & operator[] (unsigned n);
    size_t size (void) const; // return number of elements

    void print (void) const;

    MatlabVector operator+ (const MatlabVector& other) const;
    MatlabVector operator+ (double d) const;
    MatlabVector operator* (double scalar) const;
};

#endif //MATLABVECTOR_MATLABLIKEVECTOR_H
