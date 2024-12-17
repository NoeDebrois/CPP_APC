//
// Created by Federica Filippini on 09/12/2020.
//

#include "callcenter.h"

void CallCenter::RegisterTaxi (const std::string& license_id) {
    Taxi new_taxi(license_id);
    taxis.insert(std::pair<std::string, Taxi>(license_id, new_taxi));

    if(new_taxi.CGetPosition() == station)
        station_available_taxis.insert(new_taxi);
    else
        available_taxis.insert(license_id);
}

Taxi CallCenter::Call(const Place &source, const Place &destination) {

    if (available_taxis.empty() and station_available_taxis.empty()) {
        std::cerr << "CallCenter::Call(): No available taxi found" << std::endl;
        return Taxi("nonexistent");
    }

    std::string closest_taxi_id = *(available_taxis.begin());
    float closest_distance = ComputeDistance(
        taxis.at(closest_taxi_id).CGetPosition(),
        source
    );

    for (const std::string& taxi : available_taxis) {
        float distance = ComputeDistance(
            taxis.at(taxi).CGetPosition(),
            source
            );
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_taxi_id = taxi;
        }
    }

    if (not station_available_taxis.empty()) {
        float station_distance = ComputeDistance(
            station, source
            );
        if (station_distance < closest_distance) {
            auto first_taxi_it = station_available_taxis.begin();
            std::string first_taxi_id = first_taxi_it->CGetLicenseId();

            station_available_taxis.erase(first_taxi_it);

            taxis.at(
                first_taxi_id
                ).SetRide(source, destination);
            return taxis.at(first_taxi_id);
        }
    }

    available_taxis.erase(closest_taxi_id);
    taxis.at(closest_taxi_id).SetRide(source, destination);
    return taxis.at(closest_taxi_id);
}


