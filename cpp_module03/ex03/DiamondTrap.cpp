#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ScavTrap(), FragTrap(), _name("DiamondTrap_defualt_name")
{
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        _name = other._name;
    }
    return *this;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : _name(name)
{
    std::cout << "DiamondTrap " << _name << " created!" << std::endl;
    ClapTrap::_name = name + "_clap_name";
    _energyPoints = ScavTrap::save_energy;
    std::cout << "FragTrap hit points is " << FragTrap::_hitPoints << std::endl;
    std::cout << "DiamondTrap hit points is " << _hitPoints << std::endl;
    std::cout << "ScavTrap energy points is " << ScavTrap::_energyPoints << std::endl;
    std::cout << "DiamondTrap energy points is " << _energyPoints << std::endl;
    std::cout << "FragTrap attack damage is " << FragTrap::_attackDamage << std::endl;
    std::cout << "DiamondTrap attack damage is " << _attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << _name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}