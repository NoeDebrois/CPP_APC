#include <iostream>
#include <memory>

using std::shared_ptr;
using std::make_shared;

// Basic implementation with smart pointers, to understand what we call the "reference count",
// i.e, the associated counter to the shared_ptr.

int main()
{
    shared_ptr<int> p1 = make_shared<int>(2);
    std::cout << p1.use_count() << std::endl;
    // p1 is the only pointer pointing to "make_shared<int>(2)", so it will print 1.

    shared_ptr<int> p2(p1); // Now p2 is a pointer pointing to the same memory area as p1.
    std::cout << p1.use_count() << "; " << p2.use_count() << std::endl;
    // p1 and p2 are pointing to the same memory area : so both will print 2.

    shared_ptr<int> p3 = make_shared<int>(10);
    std::cout << p3.use_count() << std::endl;
    // p3 points to "make_shared<int>(10)", it is the only pointer pointing here : so 1.

    p1 = p3;
    // Now we changed our mind : p1 = p3. So the reference count of (previous) p1 and p2 is decremented
    // , i.e, only one pointer now points to "make_shared<int>(2)", and it is p2.
    // In parallel the reference count from p3 and (new) p1 is incremented.
    // As a conclusion the following code will print 2 ; 1 ; 2.
    std::cout << p1.use_count() << "; " 
              << p2.use_count() << "; " 
              << p3.use_count() << std::endl;

    return 0;
}
// Outside the scope of "main", the smart pointers are deleted automatically and the memory is freed up.