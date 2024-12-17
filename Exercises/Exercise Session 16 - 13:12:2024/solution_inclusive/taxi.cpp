//
// Created by Federica Filippini on 09/12/2020.
//

#include "taxi.h"

bool operator< (const Taxi & first_taxi, const Taxi & second_taxi)
{
    const auto distance1 = first_taxi.CGetOverallDistance();
    const auto distance2 = second_taxi.CGetOverallDistance();

    if (distance1 < distance2)
    {
        return true;
    }
    else if (distance1 > distance2)
    {
        return false;
    }
    else
    {
        return first_taxi.CGetLicenseId() < second_taxi.CGetLicenseId();
    }
}