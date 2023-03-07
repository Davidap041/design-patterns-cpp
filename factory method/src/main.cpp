#include <iostream>
#include <string>
#include "LogisticsFactory.hpp"
void ClientCode(const Logistics &logistics)
{
    std::cout << "Client: I'm not aware of the Logistic's class, but it still works.\n"
              << logistics.planDelivery() << std::endl;
}

int main()
{
    std::cout << "App: Launched with the RoadTransport.\n";
    Logistics *roadVehicle = new RoadLogistics();
    ClientCode(*roadVehicle);
    std::cout << std::endl;
    std::cout << "App: Launched with the SeaTransport.\n";
    Logistics *seaVehicle = new SeaLogistics();
    ClientCode(*seaVehicle);
    delete roadVehicle;
    delete seaVehicle;
    return 0;
}
