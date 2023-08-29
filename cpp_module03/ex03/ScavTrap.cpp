#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _name = "ScavTrap_defualt_name";
    _hitPoints = 100;
    _energyPoints = 50;
    save_energy = _energyPoints;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    save_energy = _energyPoints;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints < 1) {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
        return;
    }
    if (_energyPoints < 1) {
        std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << " with style, causing "<< _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}