//
// Created by Noé Debrois on 28/10/2024.
//

#ifndef MANAGER_H
#define MANAGER_H
#include "Developer.h"

class Manager : public Developer {
private: // private because there will be no derived class so no need to make this information available !
    const double wsh_rate = 8.5;
    const double m_rate = 9.5;
    unsigned int m_hours = 0;
public:
    Manager(std::string n, std::string s, unsigned ID): Developer(n, s, ID) {}; // Idem as for Developer.
    void set_m_hours(unsigned hours) { m_hours = hours; } // Another similar setter as in developer, for wsh hours.
    double salary_cal() const override {
        double wsh_pay = wsh_hours * wsh_rate;
        double wrk_pay = (work_hours - wsh_hours - m_hours) * pay_rate;
        double m_pay = m_rate * m_hours;
        return wsh_pay + wrk_pay + m_pay;
    }
};

#endif //MANAGER_H