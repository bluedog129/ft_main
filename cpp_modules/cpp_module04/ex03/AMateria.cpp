#include "AMateria.hpp"

AMateria::AMateria() : _type("default amateria")
{
    // std::cout << "default AMateria constructer is created" << std::endl;
}

AMateria::AMateria(AMateria &others)
{
    // std::cout << "AMateria copy constructer is created" << std::endl;
    *this = others;
}

AMateria& AMateria::operator=(AMateria &others)
{
    // std::cout << "AMateria copy assignment operator is called" << std::endl;
    if (this != &others)
    {
        _type = others._type;
    }
    return *this;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    // std::cout << "AMateria constructer is created" << std::endl;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructer is created" << std::endl;
}

std::string const &AMateria::getType() const
{
    return _type;
}
