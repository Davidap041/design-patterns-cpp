#include <string>
#include <iostream>

using namespace std;

/**
 * The target defines the domain-specific interface used by the client code.
 */
class Target
{
public:
    Target(){};
    virtual ~Target(){};

    virtual std::string Request() const;
};

std::string Target::Request() const
{
    return "Target: The default target's behavior.";
}

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adatpee needs some adapatation before the
 * client code can use it.
 */
class Adaptee
{
public:
    Adaptee(/* args */){};
    ~Adaptee(){};
    std::string SpecificRequest() const;
};

std::string Adaptee::SpecificRequest() const
{
    return ".eetpadA eht fo roivaheb laicepS";
}

/**
 * The Adapter makes the Adatee's interface compatible with the Target's
 * interface
 */
class Adapter : public Target
{
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee){};
    std::string Request() const override;
};

std::string Adapter::Request() const
{
    std::string to_reverse = this->adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (translated) " + to_reverse;
}

/**
 * The client code supports all classes that follow the Targe interface.
 */
void ClientCode(const Target *target)
{
    std::cout << target->Request();
}

int main()
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target;
    ClientCode(target);
    std::cout << "\n\n";

    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I'dont undestand it: \n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter: \n";
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);
    std::cout << "\n";
    
    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}