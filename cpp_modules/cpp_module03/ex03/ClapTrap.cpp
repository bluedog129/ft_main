#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : _name("clapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    _name = "ClapTrap_defualt_name";
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints < 1) {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
        return;
    }
    if (_energyPoints < 1) {
        std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", casuing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints < 1) {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
        return;
    }
    if (_energyPoints < 1) {
        std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
        return;
    }
    if (amount >= static_cast<unsigned int>(_hitPoints)) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and died" << std::endl;
    }
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and now has " << _hitPoints << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    unsigned int gap = std::numeric_limits<unsigned int>::max() - _hitPoints;
    if (gap > amount)
        _hitPoints = std::numeric_limits<unsigned int>::max();
    if (_hitPoints < 1) {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
        return;
    }
    if (_energyPoints < 1) {
        std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
        return;
    }
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " was repaired by " << amount << " points and now has " << _hitPoints << " hit points" << std::endl;
    _energyPoints--;
}