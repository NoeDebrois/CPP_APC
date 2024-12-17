//
// Created by Federica Filippini on 09/12/2020.
//

#ifndef TAXICALLCENTER_DISJOINT_DATE_H
#define TAXICALLCENTER_DISJOINT_DATE_H

#include <string>

class Date
{
private:
    int day = 1, month = 1, year = 1972;

public:
    //format (year-month-day) needs to be checked
    explicit Date (const std::string& str);

    std::string print () const;

    friend bool operator< (const Date&, const Date&);

    friend bool operator!= (const Date&, const Date&);
};

bool operator< (const Date&, const Date&);

bool operator!= (const Date&, const Date&);

#endif //TAXICALLCENTER_DISJOINT_DATE_H
