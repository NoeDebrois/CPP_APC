#include <stdio.h>
using std::cin;
using std::cout; using std::endl;

int fib(int);
int sum(int, int);

int main() {
    cout << "please enter your first nb and second nb\n" << endl;
    int a_in =0;
    int b_in =0;
    cin >> a_in >> b_in;
    printf("Cumulative Fib is %d\n", sum(a_in, b_in));

    for (int i = 0; i<10; ++i)
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

int sum(int a, int b) {
    return a + b;
}