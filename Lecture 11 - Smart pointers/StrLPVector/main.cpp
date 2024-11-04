#include <iostream>

#include "StrLPVector.h"

// We want to define a class LPVector that will hold a collection elements. Unlike the vector,
// we want that LPVector objects which are copies of one another to share the same elements.

int main()
{
    StrLPVector sv1({"a", "list", "of", "words"});
    StrLPVector sv2(sv1);

    std::cout << "sv1.front() is: " << sv1.front() << std::endl;
    std::cout << "sv2.front() is: " << sv2.front() << std::endl;

    StrLPVector sv3 = sv2;
    sv3.push_back("new element");

    std::cout << "sv1.back() is: " << sv1.back() << std::endl;
    std::cout << "sv2.back() is: " << sv2.back() << std::endl;
    std::cout << "sv3.back() is: " << sv3.back() << std::endl;
    // We get three times "new element" : sv3 is a copy of sv2 (& sv1) but they share the SAME elts.
}
