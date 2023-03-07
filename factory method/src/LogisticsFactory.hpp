#pragma once
#include <string>
/**
 * Interface class that implements the default methods
 * to the children classes
 */
class Transport
{
private:
    /* data */
public:
    virtual ~Transport();
    virtual std::string deliver() const = 0;
};

class Ship : public Transport
{
private:
    /* data */
public:
    Ship();
    ~Ship();
    std::string deliver() const override;
};

class Truck : public Transport
{
private:
    /* data */
public:
    Truck();
    ~Truck();
    std::string deliver() const override;
};

class Logistics
{
public:
    virtual ~Logistics();
    virtual Transport *createTransport() const = 0;
    std::string planDelivery() const;
};

class RoadLogistics : public Logistics
{
public:
    RoadLogistics();
    ~RoadLogistics();
    Transport *createTransport() const override;
};

class SeaLogistics : public Logistics
{
public:
    SeaLogistics();
    ~SeaLogistics();
    Transport *createTransport() const override;
};
