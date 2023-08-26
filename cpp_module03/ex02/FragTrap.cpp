#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
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