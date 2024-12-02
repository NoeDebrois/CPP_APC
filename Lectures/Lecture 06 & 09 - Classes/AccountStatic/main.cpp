// Modified by Noé Debrois on 22/10/24.

#include <iostream>
#include "Account.h"
#include <iostream>

int main() {
    double r;
    r = Account::rate();
    std::cout << r <<std::endl;
    Account ac1;
    Account *ac2 = &ac1;

    // Equivalent ways to call the static member rate function
    r = ac1.rate(); // through an Account object or reference
    std::cout << r <<std::endl;
    r = ac2->rate(); // through a pointer to an Account object
    std::cout << r <<std::endl;

    return 0;
}
