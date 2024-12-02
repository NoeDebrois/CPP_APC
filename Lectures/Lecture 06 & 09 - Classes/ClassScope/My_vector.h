//
// Created by Danilo Ardagna on 14/10/21.
//

#ifndef CLASSSCOPE_MY_VECTOR_H
#define CLASSSCOPE_MY_VECTOR_H

#include <vector>
#include <cmath>
#include <algorithm> // std::max
#include <iostream>

class My_vector {
    std::vector<int> v;				// v is in class scope
public:

    My_vector(const std::vector<int> & values):v(values){};
    int largest_buggy();			// largest is in class scope

};
// no v here





#endif //CLASSSCOPE_MY_VECTOR_H
