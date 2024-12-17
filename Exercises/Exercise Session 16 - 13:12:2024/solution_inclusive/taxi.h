//
// Created by Federica Filippini on 09/12/2020.
//

#ifndef TAXICALLCENTER_INCLUSIVE_TAXI_H
#define TAXICALLCENTER_INCLUSIVE_TAXI_H

#include <iostream>
#include <string>

#include "place.h"

class Taxi
{
private:
    std::string license_id;

    float total_distance = 0.0;

    Place last_ride_source = Place();

    Place last_ride_destination = Place();

public:
    explicit Taxi (const std::string& _license_id) :
            license_id(_license_id)
    {}

    float CGetOverallDistance () const
    {
        return total_distance;
    }

    std::string CGetLicenseId () const
    {
        return license_id;
    }

    void print () const
    {
        std::cout << "License ID: " << license_id << " - Overall Km. "  << total_distance << std::endl;
    }

    Place CGetPosition () const
    {
        return last_ride_destination;
    }

    void SetRide (const Place& source, const Place& destination)
    {
        last_ride_source = source;
        last_ride_destination = destination;
    }

    std::pair<Place, Place> CGetLastRide () const
    {
        return {last_ride_source, last_ride_destination};
    }

    void AddDistance (float distance)
    {
        total_distance += distance;
    }

    friend bool operator< (const Taxi&, const Taxi&);
};

bool operator< (const Taxi& first_taxi, const Taxi& second_taxi);

#endif //TAXICALLCENTER_INCLUSIVE_TAXI_H
