#ifndef VECTORHELPERS_H
#define VECTORHELPERS_H

#include <vector>
#include <iostream>
#include <cmath>

namespace linear_algebra
{
    //method to compute the eucledian norm of x
    double norm(const std::vector<double>& x);

    //receives a vector x and normalizes it (divides each component by the eucledian norm of x)
    void normalize(std::vector<double>& x);

    //method to compute the scalar product of x and y
    double scalar(const std::vector<double>& x, const std::vector<double>& y);

    //method to compute the multiplication of a vector times a scalar
    std::vector<double> operator*(const double& a, const std::vector<double>& x);

    //method to subtract two vectors
    std::vector<double> operator-(const std::vector<double>& x1, const std::vector<double>& x2);
}


#endif
