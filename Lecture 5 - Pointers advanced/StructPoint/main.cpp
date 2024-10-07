#include <iostream>
#include <string>
#include <vector>

struct Student{
   std::string name;
   unsigned age;
};


int main() {
    std::vector <Student> vs;
    Student s1;

    s1.name = "Danilo";
    s1.age = 48;
    Student s2;

    s2.name = "Luca";
    s2.age = 27;

    vs.push_back(s1);
    vs.push_back(s2);

    /*
    for (size_t i = 0; i < vs.size(); ++i){
        std::cout << vs[i].name << " ";
        std::cout << vs[i].age << std::endl;

    }
*/
    // Nice way to print the info of all the students in vs :
    for (auto it =vs.begin(); it  != vs.end(); ++it){
        std::cout << it ->name << " ";
        std::cout << it -> age << std::endl;

    }
    return 0;
}
