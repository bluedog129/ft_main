#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "default Cure constructer is created" << std::endl;
}

Cure::Cure(std::string const &type) : AMateria(type)
{
    std::cout << "Cure constructer is created" << std::endl;
}

Cure::Cure(Cure const &others)
{
    std::cout << "Cure copy constructer is created" << std::endl;
    *this = others;
}

Cure& Cure::operator=(Cure const &others)
{
    std::cout << "Cure copy assignment operator is called" << std::endl;
    if (this != &others)
        _type = others._type;
    
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructer is created" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
