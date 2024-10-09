#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "----- DiamondTrap tests -----" << std::endl;
    DiamondTrap diamondTrap("diamond");
    diamondTrap.attack("enemy");
    diamondTrap.whoAmI();
}