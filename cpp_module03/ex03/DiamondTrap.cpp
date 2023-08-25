#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _diamondName(name + "_diamond_name")
{
    std::cout << "DiamondTrap " << _diamondName << " created!" << std::endl;
}