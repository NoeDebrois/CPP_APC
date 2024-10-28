//
// Created by Noé Debrois on 28/10/2024.
//

#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "Employee.h"

class Developer : public Employee {
protected: // From Manager class, we will want to be able to access workshop hours ! So it has to be in "protected".
    unsigned wsh_hours = 0;
    const double wsh_rate = 8.0;

public:
    Developer(std::string n, std::string s, unsigned ID): Employee(n, s, ID) {}; // Idem as for Secretary.
    void set_wsh_hours(unsigned hours) { wsh_hours = hours; } // Setter for wsh hours.
    double salary_cal() const override {
        double wsh_pay = wsh_hours * wsh_rate;
        double wrk_pay = (work_hours - wsh_hours) * pay_rate;
        return wsh_pay + wrk_pay;
    }
};

#endif //DEVELOPER_H