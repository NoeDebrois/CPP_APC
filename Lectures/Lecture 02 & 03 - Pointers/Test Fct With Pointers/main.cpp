#include <iostream>

// Illustration of the difference between "pass by value" and "pass by reference" for function calls.
// The first is the usual way (for me), and the second uses pointers.
// Check the two void functions.

void swap_two_ints(int, int);
void swap_two_ints_with_pointers(int *, int *);

int main() {
    int a = 1;
    int b = 2;
    swap_two_ints(a, b);
    std::cout << a << std::endl; // You can see that a and b haven't been swapped...
    std::cout << b << std::endl; // it was only inside the function that p and q were swapped.

    swap_two_ints_with_pointers(&a, &b);
    std::cout << a << std::endl; // You can see that a and b are swapped here...
    std::cout << b << std::endl; // it's because the actual & formal parameters share the same
    // memory location !
    return 0;
}

void swap_two_ints(int p, int q) {
    int temp;
    temp = p; // temporary variable
    p = q;
    q = temp;
    // no return : that's why it's a void
}

void swap_two_ints_with_pointers(int *p, int *q) {
    int temp;
    temp = *p; // temporary variable
    *p = *q;
    *q = temp;
    // no return : that's why it's a void
}