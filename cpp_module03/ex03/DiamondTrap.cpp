#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : _diamondName(_name)
{
    std::cout << "DiamondTrap " << _name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap " << _name << " created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}
