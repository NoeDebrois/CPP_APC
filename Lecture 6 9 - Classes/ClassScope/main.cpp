#include <iostream>

#include "My_vector.h"


// no r, i, or v here

int main() {
    My_vector vec({1, -3, 2});

    std::cout << "Max: " << vec.largest_buggy() << std::endl;
    return 0;
}