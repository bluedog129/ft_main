#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "default Ice constructer is created" << std::endl;
}

Ice::Ice(std::string const &type) : AMateria(type)
{
    // std::cout << "Ice constructer is created" << std::endl;
}

Ice::Ice(Ice const &others)
{
    // std::cout << "Ice copy constructer is created" << std::endl;
    *this = others;
}

Ice& Ice::operator=(Ice const &others)
{
    // std::cout << "Ice copy assignment operator is called" << std::endl;
    if (this != &others)
        _type = others._type;
    
    return *this;
}

Ice::~Ice()
{
    // std::cout << "Ice destructer is created" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}