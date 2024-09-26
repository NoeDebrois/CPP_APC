#include "X.h"

// Here we can access to everything : public or private !

int X::mf1() {
    data = 0;
    return 0;
}

int X::mf2() {
    data = 1;
    int var1 = data;

    return var1 + mf1(); // See, we can access even to mf1 which is private !
}
