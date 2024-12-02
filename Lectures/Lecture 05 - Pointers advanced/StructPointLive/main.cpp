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

    Student *ps = &s1;

    ps->age = 50;

/*
    for (size_t i = 0; i < vs.size(); ++i){
        std::cout << vs[i].name << " ";
        std::cout << vs[i].age << std::endl;

    }*/

    // The two same things (because of pointers : cf line 25) :
    std::cout << (*ps).name << " " << ps->age << " // " ;
    std::cout << s1.name << " " << s1.age << std::endl ;
    std::cout << " " << std::endl ;

    // Print the info from students in vs : it didn't change the students in vs :
    //
    // IMPORTANT : when we pushed s1 into the vector, the vector created a copy of s1
    // and stored it in the vector. This means that the object in vs[0] is a different
    // object than s1, even though it initially has the same values. That's why :
    for (auto it = vs.begin(); it  != vs.end(); ++it){
        std::cout << it -> name << " ";
        std::cout << it -> age << std::endl;
    }

    return 0;
}
