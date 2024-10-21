#include <iostream>
#include "X.h"

// This notebook shows the usage of this-> in classes ; or the need to use different names.
// It's important to be able to use this-> framework, because sometimes you have no other way.

int main() {
    X obj(3);
    std::cout << obj.getMember() << std::endl;
    obj.setMember(10);
    std::cout << obj.getMember() << std::endl;

    // It doesn't work because in X::X(int member) (cf X.cpp file) we have member = member so :
    // - either we change the code in X::X(int member) (cf X.cpp file) to X_member = member (for example)
    // and we also change in X.h in class X {int X_member ... ;
    // - or we use this->member = member in X::X(int member) (cf X.cpp file).
    // Do the same in void X::setMember(int member) (i.e put this->member = member).

    return 0;
}
