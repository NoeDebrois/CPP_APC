#include <iostream>

// This code shows how the position of "++" (when you want to increment a variable)
// is important ; especially when you use it to assign a new variable.
// Please take a look :

int main() {
    int i =0;
    ++i;
    std::cout << "i: " << i << std::endl;
    i++;
    std::cout << "i: " << i << std::endl;

    int a = ++i;
    std::cout << "a: " << a << std::endl;
    std::cout << "i: " << i << std::endl;

    int b = i++;
    std::cout << "b: " << b << std::endl;
    std::cout << "i: " << i << std::endl;

    return 0;
}
