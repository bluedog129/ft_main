#include "Amateria.hpp"

class Ice : public AMateria
{
private:
    std::string _name;
public:
    Ice();
    Ice(std::string const & type);
    Ice(Ice const & others);
    Ice &operator=(Ice const &others);
    ~Ice();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target); 
};