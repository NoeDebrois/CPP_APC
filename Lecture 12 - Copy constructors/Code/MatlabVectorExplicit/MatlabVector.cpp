//
// Created by Federica Filippini on 09/10/2020.
//

#include "MatlabVector.h"

using std::cout;
using std::endl;

void MatlabVector::print (void) const
{
    for (size_t i =0; i< elem.size(); ++i)
        cout << elem[i] << " ";

    cout << endl;
}

size_t MatlabVector::size (void) const
{
    return elem.size();
}

MatlabVector MatlabVector::operator* (double scalar) const
{
    MatlabVector result;
    for (unsigned i=0; i<elem.size(); ++i)
        result[i] =scalar * elem[i];

    return result;
}

MatlabVector MatlabVector::operator+ (const MatlabVector &other) const
{
    MatlabVector result;
    if (elem.size() == other.size()) {
        for (unsigned i = 0; i < elem.size(); ++i)
            result[i] = elem[i] + other.elem[i];
    }
    else
        result[0] = std::numeric_limits<double>::quiet_NaN();

    return result;
}

MatlabVector MatlabVector::operator+ (double d) const 
{
    MatlabVector result(elem.size());
    for (unsigned i = 0; i < elem.size(); ++i)
        result.elem[i] = elem[i] + d;
    return result;
}

double & MatlabVector::operator[] (unsigned n)
{
    while (elem.size() < n+1)
        elem.push_back(0.);
    return elem[n];
}