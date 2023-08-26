#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap " << _name << " created!" << std::endl;
}
