//
// Created by Danilo Ardagna on 14/10/21.
// Modified by Noé Debrois on 22/10/24.
//

#include "Account.h"
void Account::rate(double new_rate)
{
    interest_rate = new_rate;
}

double Account::init_rate(){
    return .05;
}

double Account::interest_rate = init_rate();