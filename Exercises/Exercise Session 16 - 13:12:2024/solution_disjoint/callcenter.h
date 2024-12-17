//
// Created by Federica Filippini on 09/12/2020.
//

#ifndef TAXICALLCENTER_DISJOINT_CALLCENTER_H
#define TAXICALLCENTER_DISJOINT_CALLCENTER_H

#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "date.h"
#include "place.h"
#include "taxi.h"

class CallCenter
{
private:
    /*
     * NOTE: a taxi available at the rail station is included only in
     * station_available_taxis
     *
     * */

    std::unordered_set<std::string> available_taxis;

    std::set<Taxi> station_available_taxis;

    std::unordered_map<std::string, Taxi> taxis;

    const Place station = Place(0.0, 0.0);

public:
    Taxi Call (const Place& source, const Place& destination);

    Taxi CallAtRailStation (const Place& Destination);

    Taxi CallToRailStation (const Place& Source);

    void Arrived (const std::string& license_id);

    void RegisterTaxi (const std::string& license_id);

    void printTaxis () const;
};

#endif //TAXICALLCENTER_DISJOINT_CALLCENTER_H
