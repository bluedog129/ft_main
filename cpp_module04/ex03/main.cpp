#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void leaks()
{
    std::cout << std::system("leaks ex03") << std::endl;
}

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    
    AMateria* ice;
    AMateria* cure;

    ice = src->createMateria("ice");
    me->equip(ice);
    cure = src->createMateria("cure");
    me->equip(cure);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    me->unequip(1);

    delete ice;
    delete cure;
    delete bob;
    delete me;
    delete src;

    atexit(leaks);
    return 0;
}