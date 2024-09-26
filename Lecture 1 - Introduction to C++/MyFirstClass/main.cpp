#include <iostream>
#include "X.h"
int main() {
    X x;		// variable x of type X
    //x.data = 4; // error: data is private (i.e., inaccessible)
    //int y = x.mf1();//  error: mf1 is private
    int z = x.mf2(); //  ok: mf2 is public
    std::cout << z << std::endl;

    return 0;
}
