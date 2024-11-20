#include <iostream>

int main()
{
    // 1.1.1 POINTERS :
    // A pointer is a variable whose value is the address of another variable.
    // Declaration of a pointer : "base_type * pointer_name".
    int a = 3;
    // Two ways to initialize a pointer :
    // - by the adress of a variable :
    int * I_am_a_pointer = &a;
    // - by the value of another pointer :
    int * I_am_another_pointer = I_am_a_pointer;
    // Otherwise, the pointer should be defined "nullptr" :
    int * Null_ptr = nullptr;
    //
    std::cout << "The value pointed by I_am_a_pointer is : " << *I_am_a_pointer << std::endl;
    std::cout << "The value pointed by I_am_another_pointer is : " << *I_am_another_pointer << std::endl;
    // We can change the value from 3 to e.g 5 through pointer :
    *I_am_a_pointer = 5;
    // Both the pointers will have the new value :
    std::cout << "The value pointed by I_am_a_pointer is : " << *I_am_a_pointer << std::endl;
    std::cout << "The value pointed by I_am_another_pointer is : " << *I_am_another_pointer << std::endl;
    // Also a itself has a new value :
    std::cout << "The value pointed by a is : " << a << std::endl;
    std::cout << std::endl;
    //
    // EXAMPLE : with array, we can initialize elements from the array using pointers.
    int numbers[5];
    int * p;
    p = numbers; // THE NAME OF AN ARRAY ALWAYS REPRESENTS THE ADDRESS OF ITS FIRST ELEMENT.
    // SO ABOVE WHAT WE DO IS : we assign to p the address of numbers[0].
    *p = 10;
    p++; // Address of numbers[1].
    *p = 20; // We change numbers[1]
    p = &numbers[2]; // We assign to p the address of the 3rd element of numbers.
    *p = 30;
    p = numbers + 3; // We assign to p the address of 3 elts on the right of the first elt of numbers,
    // i.e, the address of the fourth element of numbers.
    *p = 40;
    //p = numbers;
    //*(p + 4) = 50;
    for(int i = 0; i < 5; i++) {
        std::cout << numbers[i] << std::endl;
    }
    std::cout << std::endl;
    // ANOTHER EXAMPLE : use of a pointer to go through an array.
    int var[3] = {10, 100, 200};
    int *ptr;
    ptr = var;
    for (int i = 0; i < 3; i++) {
        std::cout << "var[" << i << "]" << std::endl;
        std::cout << *ptr << std::endl;
        ptr++;
    }
    std::cout << std::endl;
    //
}

