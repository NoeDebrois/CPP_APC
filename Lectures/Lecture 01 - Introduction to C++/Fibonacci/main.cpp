#include <iostream>
using std::cin;
using std::cout; using std::endl;

int fib(int);

int main() {
    int max_idx = 0;
    cout << "Hi, please enter you maximum index for the computation of Fibonaci terms:" << endl;
    cin >> max_idx;
    for (int i = 0; i<=max_idx; ++i)
        printf("Fib %d is %d\n", i, fib(i));
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
