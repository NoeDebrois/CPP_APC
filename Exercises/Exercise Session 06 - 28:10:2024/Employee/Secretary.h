//
// Created by Noé Debrois on 28/10/2024.
//

#ifndef SECRETARY_H
#define SECRETARY_H
#include "Employee.h"

// Secretary class is inheriting from Employee class.
class Secretary : public Employee {
public:
    Secretary(std::string n, std::string s, unsigned ID): Employee(n, s, ID) {}; // We will only have to change the
    // Base Class if we want to make some change later because we called the Employee constructor.

    double salary_cal() const override {
        // We override here because this function computes the salary in a way that is
        // ONLY VALID FOR Secretary. So we need to have a specific salary_cal() method for Secretary, one for Dev, etc.
        return work_hours * pay_rate;
    };
};

#endif //SECRETARY_H
