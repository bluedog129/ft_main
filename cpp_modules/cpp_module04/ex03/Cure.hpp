#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
    std::string _name;
public:
    Cure();
    Cure(std::string const & type);
    Cure(Cure const & others);
    Cure &operator=(Cure const &others);
    ~Cure();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif