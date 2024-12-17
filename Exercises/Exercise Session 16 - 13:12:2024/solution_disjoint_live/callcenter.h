//
// Created by Federica Filippini on 09/12/2020.
//

#ifndef TAXICALLCENTER_INITIAL_CALLCENTER_H
#define TAXICALLCENTER_INITIAL_CALLCENTER_H

#include <unordered_map>
#include <unordered_set>
#include <set>

#include "date.h"
#include "place.h"
#include "taxi.h"

class CallCenter
{
private:
    std::unordered_set<std::string> available_taxis;

    std::set<Taxi> station_available_taxis;     // operator<(const Taxi&, const Taxi&)

    std::unordered_map<std::string, Taxi> taxis;

    const Place station = Place(0.0, 0.0);

public:
    void RegisterTaxi (const std::string& license_id);

    Taxi Call (const Place& source, const Place& destination);

    Taxi CallAtRailStation (const Place& Destination);

    Taxi CallToRailStation (const Place& Source);

    void Arrived (const std::string& license_id);
};

#endif //TAXICALLCENTER_INITIAL_CALLCENTER_H
