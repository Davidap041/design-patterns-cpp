#include <string>
#include <iostream>
using namespace std;

/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target
{
public:
    virtual ~Target() = default;
    virtual std::string Request() const
    {
        return "Target: The default target's behavior.";
    }
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee
{
public:
    std::string SpecificRequest() const;
};

std::string Adaptee::SpecificRequest() const
{

    return ".eetpadA eht fo roivaheb laicepS";
}
/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface using multiple inheritance.
 */
class Adapter : public Target, public Adaptee
{
public:
    // constuctor
    Adapter(){};
    std::string Request() const override;
};

std::string Adapter::Request() const
{
    std::string to_reverse = SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (Translated) " + to_reverse;
}

void ClientCode(const Target *target)
{
    std::cout << target->Request();
}
int main()
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target();
    ClientCode(target);
    std::cout << "\n\n";

    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I'dont undestand it \n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "Client: But I can work with it via the ";

    Adapter *adapter = new Adapter();
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;
}