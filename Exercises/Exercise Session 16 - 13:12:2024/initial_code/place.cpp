//
// Created by Federica Filippini on 09/12/2020.
//

#include "place.h"

float ComputeDistance (const Place& first_place, const Place& second_place)
{
    float x_distance = first_place.CGetXCoordinates() - second_place.CGetXCoordinates();
    float y_distance = first_place.CGetYCoordinates() - second_place.CGetYCoordinates();

    // f stands for float; the usual sqrt returns a double
    return sqrtf (x_distance*x_distance + y_distance*y_distance);
}