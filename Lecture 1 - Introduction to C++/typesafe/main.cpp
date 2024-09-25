#include <iostream>
using std::cout;

// This code shows how the choice of type for your variable is important.
// If you make some computations with badly chosen variable types, you
// will make some mistakes. Please take a look :

int main()
{
    int a = 20000; // A short int goes from -32768 to +32767... you have long int also.
    char c = a; // WARNING : a char goes from -128 to +127 !
    int b = c; // WARNING : the variable has been cut since c is between -128 and +127 !
    if (a != b)	//  != means “not equal”
        cout << "WARNING : a = " << a << " != b = " << b << '\n';
    else
        cout << "Wow! We have large characters\n";
    return 0;
}

