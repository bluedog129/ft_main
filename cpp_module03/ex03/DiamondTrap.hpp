#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap, public ClapTrap {
private:
    std::string _diamondName;
public:
    DiamondTrap(const std::string &name);
    ~DiamondTrap();

    using ClapTrap::attack;
    void whoAmI(void);
};

#endif