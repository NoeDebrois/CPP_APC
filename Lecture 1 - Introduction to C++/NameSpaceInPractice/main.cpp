#include <iostream>
#include "MyFriendLibrary.h"

// Imagine you have an initial code and you need to extend your program
// relying on MyFriendLibrary where the function "bar" is available and
// you also have a function "bar" in your code, and the two functions
// therefore need to coexist. It is related to the "linking" part.
// The idea is to use namespace and header files. See below.
// PS : cf slide 117 of CPP introduction.

namespace foo {
    void bar(); // declaration
}
int main() {
    foo::bar(); // here I would like to use my bar version
    bar(); // here I would like to use the library version
    return 0;
}

void foo::bar(){ // definition
    std::cout << "Running main bar" << std::endl;
}