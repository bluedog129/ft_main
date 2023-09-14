#include "Amateria.hpp"

class Ice : public AMateria
{
private:
    std::string _name;
public:
    Ice();
    Ice(Ice &others);
    ~Ice();

    Ice(std::string const & type);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target); 
};