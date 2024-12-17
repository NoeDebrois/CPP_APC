//
// Created by Federica Filippini on 09/12/2020.
//

#ifndef TAXICALLCENTER_INCLUSIVE_PLACE_H
#define TAXICALLCENTER_INCLUSIVE_PLACE_H

#include <cmath>

class Place
{
private:
    float x_coordinates;
    float y_coordinates;

public:
    Place (float _x_coordinates = 0.0, float _y_coordinates = 0.0) :
            x_coordinates(_x_coordinates),
            y_coordinates(_y_coordinates)
    {}

    float CGetXCoordinates () const
    {
        return x_coordinates;
    }

    float CGetYCoordinates () const
    {
        return y_coordinates;
    }

    bool operator== (const Place& other) const
    {
        return x_coordinates == other.x_coordinates and y_coordinates == other.y_coordinates;
    }
};

float ComputeDistance (const Place& first_place, const Place& second_place);

#endif //TAXICALLCENTER_INCLUSIVE_PLACE_H
