#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
public:
    AMateria();
    AMateria(AMateria &others);
    AMateria &operator=(AMateria &others);
    AMateria(std::string const & type);
    ~AMateria();

    std::string const & getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};

#endif