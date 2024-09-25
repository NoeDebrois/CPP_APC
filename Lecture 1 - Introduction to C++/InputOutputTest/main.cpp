#include <iostream>
using std::cin;
using std::cout; using std::endl;
using std::string;

int fib(int);
int sum(int, int);

int main() {
    cout << "Please enter your first name (followed by 'enter'):" << endl;
    string first_name; // declare first_name's type
    // Read first name :
    cin >> first_name;
    // Take into account the entered *first_name* :
    cout << "Hello, " << first_name << "! Please enter your first nb and second nb." << endl;
    cout << "After each nb, press 'enter' :" << endl;
    int a_in; // declare a_in's type
    int b_in; // declare b_in's type
    // Read a_in and b_in :
    cin >> a_in >> b_in;
    printf("Sum of your two numbers is %d\n\n", sum(a_in, b_in));

    cout << "Do you want to print the 10 first nb of the Fibonacci sequence ? (y/n):" << endl;
    string answer;
    cin >> answer;
    if (answer == "y") {
        for (int i = 0; i<10; ++i)
            printf("Fib%d = %d\n", i, fib(i));
    }
    return 0;
}

int fib(int n){
    int first = 0, second = 1;
    for (int i=0; i<n; ++i)  {
        int sum = first+second;
        first = second;
        second = sum;
    }
    return first;
}

int sum(int a, int b) {
    return a + b;
}
