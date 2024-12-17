//
// Created by Federica Filippini on 09/12/2020.
//

#include "callcenter.h"

void CallCenter::RegisterTaxi (const std::string& license_id)
{
    Taxi new_taxi(license_id);
    taxis.insert(std::pair<std::string, Taxi>(license_id, new_taxi));

    available_taxis.insert(license_id);

    if(new_taxi.CGetPosition() == station)
        station_available_taxis.insert(new_taxi);
}

Taxi CallCenter::Call (const Place& source, const Place& destination)
{
    if (available_taxis.empty())
    {
        std::cerr << "There is not any available taxi" << std::endl;
        return Taxi("nonexistent");
    }

    auto closest_taxi_id = *(available_taxis.begin());
    float closest_distance = ComputeDistance(taxis.at(closest_taxi_id).CGetPosition(), source);

    for(const std::string& taxi_id : available_taxis)
    {
        const auto current_distance = ComputeDistance(taxis.at(taxi_id).CGetPosition(), source);
        if(current_distance < closest_distance)
        {
            closest_distance = current_distance;
            closest_taxi_id = taxi_id;
        }
    }

    available_taxis.erase(closest_taxi_id);
    Taxi& return_taxi = taxis.at(closest_taxi_id);

    if(return_taxi.CGetPosition() == station)
        station_available_taxis.erase(return_taxi);

    return_taxi.SetRide(source, destination);

    return return_taxi;
}

Taxi CallCenter::CallAtRailStation (const Place& destination)
{
    if(not station_available_taxis.empty())
    {
        auto first_taxi = *(station_available_taxis.begin());
        taxis.at(first_taxi.CGetLicenseId()).SetRide(station, destination);
        station_available_taxis.erase(first_taxi);
        available_taxis.erase(first_taxi.CGetLicenseId());
        return taxis.at(first_taxi.CGetLicenseId());
    }
    else
    {
        return Call(station, destination);
    }
}

Taxi CallCenter::CallToRailStation (const Place& source)
{
    return Call(source, station);
}

void CallCenter::Arrived (const std::string& license_id)
{
    Taxi& taxi = taxis.at(license_id);
    const auto last_ride = taxi.CGetLastRide();

    taxi.AddDistance(ComputeDistance(last_ride.first, last_ride.second));

    if(taxi.CGetPosition() == station)
        station_available_taxis.insert(taxi);

    available_taxis.insert(license_id);
}

void CallCenter::printTaxis () const {

  std::cout << "All taxis:" << std::endl;
  for (const auto &pair: taxis)
    pair.second.print();

  std::cout << "Available taxis: [";
  for (const std::string& taxi_id : available_taxis)
    std::cout << taxi_id << " ";
  std::cout << "]" << std::endl;

  std::cout << "Available taxis at the station: [";
  for (const Taxi& taxi : station_available_taxis)
    std::cout << taxi.CGetLicenseId() << " ";
  std::cout << "]" << std::endl;
}