#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clapTrap("CL4P-TP");
    ScavTrap scavTrap("SC4V-TP");
    FragTrap fragTrap("FR4G-TP");

    clapTrap.attack("Bandit");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);

    scavTrap.attack("Thief");
    scavTrap.guardGate();

    fragTrap.attack("Enemy");
    fragTrap.highFivesGuys();

    return 0;
}