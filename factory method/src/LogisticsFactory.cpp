#include "LogisticsFactory.hpp"
/**
 *
 */
Transport::~Transport()
{
}
/**
 *
 */
Logistics::~Logistics()
{
}

std::string Logistics::planDelivery() const
{
    Transport *t = this->createTransport();
    std::string msg = t->deliver();
    delete t;
    return msg;
}
/**
 *
 */
RoadLogistics::RoadLogistics()
{
}
RoadLogistics::~RoadLogistics()
{
}
Transport *RoadLogistics::createTransport() const
{
    Transport *r = new Truck();
    return r;
}

/**
 *
 */
SeaLogistics::SeaLogistics()
{
}
SeaLogistics::~SeaLogistics()
{
}
Transport *SeaLogistics::createTransport() const
{
    Transport *s = new Ship();
    return s;
}

/**
 * Ship class implementation
 */
Ship::Ship()
{
}

Ship::~Ship()
{
}

std::string Ship::deliver() const
{
    std::string msg = "Deliver by a sea in a container";
    return msg;
}

/**
 * Truck class implementation
 */
Truck::Truck()
{
}
Truck::~Truck()
{
}
std::string Truck::deliver() const
{
    std::string msg = "Deliver by land in  a box";
    return msg;
}
