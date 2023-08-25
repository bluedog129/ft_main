#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints < 1) {
        std::cout << "FragTrap " << _name << " has no energy points left" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << ", casuing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " wants to high five!" << std::endl;
}