//
// Created by Federica Filippini on 18/10/22.
//

#ifndef COPYCONTROL_MYCLASS_H
#define COPYCONTROL_MYCLASS_H

#include <string>

class MyClass {

private:
    std::string string_elem = "";
    int int_elem = 0;

public:
    // constructor
    MyClass(const std::string& s, int i);
    MyClass(void);

    // copy constructor
    MyClass(const MyClass& rhs);

    // assignment operator
    MyClass& operator=(const MyClass& rhs);

    void print(void) const;

};


#endif //COPYCONTROL_MYCLASS_H
