#include "callcenter.h"

int main()
{
    CallCenter callcenter;

    callcenter.RegisterTaxi("00001");
    callcenter.RegisterTaxi("00002");
    callcenter.RegisterTaxi("00003");

    // print
    std::cout << "------------- Callcenter status -------------" << std::endl;
    callcenter.printTaxis();
    std::cout << "---------------------------------------------" << std::endl;

    Place first_source(1.0, 1.0);
    Place first_destination(2.0, 2.0);

    auto first_taxi = callcenter.Call(
        first_source,
        first_destination
        );
    first_taxi.print();

    Place second_destination(3.0, 3.0);

    auto second_taxi = callcenter.CallAtRailStation(second_destination);
    second_taxi.print();

    callcenter.Arrived(first_taxi.CGetLicenseId());
    callcenter.Arrived(second_taxi.CGetLicenseId());

    // print
    std::cout << "------------- Callcenter status -------------" << std::endl;
    callcenter.printTaxis();
    std::cout << "---------------------------------------------" << std::endl;

    return 0;
}