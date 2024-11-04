#include <iostream>

// A reference is an automatically dereferenced pointer, i.e
// an "alternative name" for an object.

int main() {
    int x = 9;

    int &ref = x; // a reference has to be initialized ! And you cannot re-reference a reference
    // i.e you cannot make a reference refer to another object after initalisation.

    std::cout << ref << std::endl;
    std::cout << x << std::endl; // ref and x have the same value.

    ref = 11;
    std::cout << ref << std::endl;
    std::cout << x << std::endl; // ref and x are "linked".

    x = 12;
    std::cout << ref << std::endl;
    std::cout << x << std::endl; // ref and x point to the same location in the memory.
    return 0;
}
