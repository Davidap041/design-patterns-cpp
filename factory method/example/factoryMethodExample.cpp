#include <iostream>
#include <string>

using namespace std;

/**
 * The Product interface declares the operations tha all concrete products must implement
 */

class Product
{
public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};
/**
 * Concrete Products various implementantions of the Produtct Interface
 */
class ConcreteProduct1 : public Product
{
private:
    /* data */
public:
    ConcreteProduct1(/* args */){};
    ~ConcreteProduct1(){};
    std::string Operation() const override
    {
        return "{Result of the Concrete Product1}";
    }
};
class ConcreteProduct2 : public Product
{
private:
    /* data */
public:
    ConcreteProduct2(/* args */){};
    ~ConcreteProduct2(){};
    std::string Operation() const override
    {
        return "{Result of the Concrete Product2}";
    }
};

class Creator
{
private:
    /* data */
public:
    virtual ~Creator(){};
    virtual Product *FactoryMethod() const = 0;
    std::string SomeOperation() const
    {
        Product *product = this->FactoryMethod();
        std::string result = "Creator: The same creator's code has just worked with" + product->Operation();
        delete product;
        return result;
    }
};
/**
 * Concrete Creators overrid the factory method in order to change the
 * resulting product's type
 */
class ConcreteCreator1 : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator &creator)
{
    // ...
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.SomeOperation() << std::endl;
    // ...
}

int main()
{
    std::cout << "App:Launched with the ConcreteCreator1.\n";
    Creator *creator = new ConcreteCreator1();
    ClientCode(*creator);
    std::cout << std::endl;
    std::cout << "App: launched with the Concrete Creator2.\n";
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);
    delete creator, creator2;
    return 0;
}