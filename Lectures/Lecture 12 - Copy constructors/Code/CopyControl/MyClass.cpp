//
// Created by Federica Filippini on 18/10/22.
//

#include "MyClass.h"

#include <iostream>


MyClass::MyClass(const std::string& s, int i): string_elem(s), int_elem(i)
{
    std::cout << "Using constructor" << std::endl;
}

MyClass::MyClass(void): MyClass("", 0)
{
    std::cout << "Using default constructor" << std::endl;
}

MyClass::MyClass(const MyClass& rhs): string_elem(rhs.string_elem), int_elem(rhs.int_elem)
{
    std::cout << "Using copy constructor" << std::endl;
}

MyClass& MyClass::operator=(const MyClass& rhs)
{
    std::cout << "Using assignment operator" << std::endl;

    string_elem = rhs.string_elem;
    int_elem = rhs.int_elem;

    return *this;
}

void MyClass::print(void) const
{
    std::cout << "(" << string_elem << ", " << int_elem << ")" << std::endl;
}
