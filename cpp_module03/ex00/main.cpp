#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("CL4P-TP");

    clapTrap.attack("Jack");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.attack("Jack");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(10);

    return 0;
}