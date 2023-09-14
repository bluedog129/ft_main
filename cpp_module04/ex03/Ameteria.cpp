#include "Amateria.hpp"

AMateria::AMateria() : _type("default amateria")
{
    std::cout << "default AMateria constructer is created" << std::endl;
}

AMateria::AMateria(AMateria &others)
{
    std::cout << "AMateria copy constructer is created" << std::endl;
    *this = others;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructer is created" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMateria constructer is created" << std::endl;
}