#include "Character.hpp"

Character::Character() : name("default")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(Character const &other)
{
    this->name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
        this->inventory[i] = other.inventory[i]->clone();
    }
}

Character &Character::operator=(Character const &other)
{
    if (this == &other)
        return (*this);
    this->name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
        this->inventory[i] = other.inventory[i]->clone();
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

std::string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "Materia is NULL" << std::endl;
        return ;
    }
    if (inventory[3] != NULL)
    {
        std::cout << "Inventory is full" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
        return ;
    if (this->inventory[idx])
        this->inventory[idx]->use(target);
}