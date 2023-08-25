#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    ScavTrap scavTrap("ScavTrap");

    clapTrap.attack("target");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);

    scavTrap.attack("target");
    scavTrap.guardGate();

    return 0;
}