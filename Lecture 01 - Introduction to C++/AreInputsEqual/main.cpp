#include<iostream>
int main(){
    std::cout<<"Hi! This program will tell you if your two input integers are equal or not."<<std::endl;
    int a=0;
    int b=0;
    std::cout << "Enter a = ";
    std::cin >> a;
    std::cout << "Enter b = ";
    std::cin >> b;
    if (a==b)
        std::cout << "They are equal!"<< std::endl;
    else
        std::cout << "They aren't equal!"<< std::endl;

}
