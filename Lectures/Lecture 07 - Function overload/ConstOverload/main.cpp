#include <iostream>

// LECTURE 7 - slide 16 :
// We can overload a member function based on whether it is const :
// class C{
// public:
//    f() const;
//    f();
//    }
// The non-const version will not be viable for const objects; we can only call const member functions on a const object.
// We can call either version on a non-const object, but the non-const version will be a better match.

#include "C.h"
int main() {

    C c;
    const C const_c;

    c.f();
    const_c.f();

    return 0;
}