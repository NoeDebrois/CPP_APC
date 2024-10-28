//
// Created by Noé Debrois on 28/10/2024.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <ostream>
#include <string>

class Employee {
protected: // Those will be inherited by all the derived classes. Those are the "common ground" between employees :
    std::string name, surname;            // No default value.
    unsigned employee_ID, work_hours = 0; // No default value for employee_ID, but for work_hours : 0 hour.
    const double pay_rate = 7.5; // We will never going to change the pay rate for the work hours. So it's a const
                                 // attribute : IMPORTANT to understand when members (methods or arguments) are const.
public:
    // CONSTRUCTOR of Employee :
    Employee(std::string n, std::string s, unsigned ID) : name(n), surname(s), employee_ID(ID) {};

    // SETTER of Employee for working hours :
    void set_work_hours(unsigned hours) { work_hours = hours; }; // No return value : so type is void. We don't set it
    // as "const" because we modify the class (work_hours). So usually, a SETTER is not a const member.

    // print() will be the SAME for ALL TYPES of EMPLOYEES. So we can write it here in the base (abstract) class :
    void print() const { // It can be const because we are just printing things, not modifying anything.
        std::cout << name << " " << surname << " " << employee_ID << std::endl;
    }

    // Computation of the salary :
    virtual double salary_cal() const = 0; // Each time we call salary_cal() method, we want that the computation depends on the
    // type of employee that we are calling it on. That's why we declare it as "virtual".
};

#endif //EMPLOYEE_H
