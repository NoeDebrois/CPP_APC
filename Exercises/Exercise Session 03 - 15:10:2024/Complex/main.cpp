#include <iostream>
#include "Complex.h"

int main() {
    Complex c1(5, 2);
    std::cout << "c1 = ";
    c1.print();

    Complex c2(6, 3);
    std::cout << "c2 = ";
    c2.print();

    Complex c3 = c1;
    std::cout << "c3 = ";
    c3.print();

    Complex c4(2, 0);
    std::cout << "c4 = ";
    c4.print();
    std::cout << "c4 (polar coordinates) = ";
    c4.print_polar();

    Complex c5 = c1 + c2;
    std::cout << "ADDITION : " << std::endl;
    std::cout << "c5 = c1 + c2 = ";
    c5.print();

    c5 = c2 - c4;
    std::cout << "SUBTRACTION : " << std::endl;
    std::cout << "c5 = c2 - c4 = ";
    c5.print();

    c5 = c2 * c4;
    std::cout << "MULTIPLICATION : " << std::endl;
    std::cout << "c2 (polar coordinates) = ";
    c2.print_polar();
    std::cout << "c5 = c2 * c4 (polar coordinates) = ";
    c5.print_polar();

    c5 = c2 / c4;
    std::cout << "DIVISION : " << std::endl;
    std::cout << "c2 (polar coordinates) = ";
    c2.print_polar();
    std::cout << "c5 = c2 / c4 (polar coordinates) = ";
    c5.print_polar();

    return 0;
}