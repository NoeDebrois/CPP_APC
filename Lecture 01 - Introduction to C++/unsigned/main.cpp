#include <iostream>

// This code shows an expression involving unsigned types.
// It shows an infinite loop. Indeed, since u is unsigned, it can never be negative
// so the condition will always succeed !

int main() {
    int a = 0;
    for (unsigned u = 10; u >= 0; u--)
        std::cout << u << std::endl;
}

// Here we show a way to solve this problem :

//int main() {
//    unsigned u = 11; // Start the loop one past the first element we want to print.
//    while (u > 0) {
//        --u; // Decrement first, so that the last iteration will print 0.
//        std::cout << u << std::endl;
//    }
//}