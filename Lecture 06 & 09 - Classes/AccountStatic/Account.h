//
// Created by Danilo Ardagna on 14/10/21.
// Modified by Noé Debrois on 22/10/24.
//

#ifndef ACCOUNTSTATIC_ACCOUNT_H
#define ACCOUNTSTATIC_ACCOUNT_H
#include <string>

class Account {

public:
    void calculate() { amount += amount * interest_rate; }
    static double rate() { return interest_rate; }
    static void rate(double);
    // add getters and setters for non-static data members
    // as an exercise
private:
    std::string owner;
    double amount;
    static double interest_rate;
    static double init_rate();
};

#endif //ACCOUNTSTATIC_ACCOUNT_H