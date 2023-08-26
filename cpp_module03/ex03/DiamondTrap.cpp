#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : _diamondName(_name)
{
    std::cout << "DiamondTrap " << _name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ScavTrap(other), FragTrap(other), _diamondName(other._diamondName)
{
    std::cout << "DiamondTrap " << _name << " created!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        _diamondName = other._diamondName;
    }
    return *this;
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

void DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << _diamondName << " and my ClapTrap name is " << _name << std::endl;
}