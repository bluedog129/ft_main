#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor is created" << std::endl;
    for (int i = 0; i < 4; i++)
        learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &others) {
    for (int i = 0; i < 4; i++)
    {
        if (others.learnedMaterias[i])
            learnedMaterias[i] = others.learnedMaterias[i]->clone();
        else
            learnedMaterias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource &others) {
    if (this == &others)
    {
        return *this;
    }
    for (int i = 0; i < 4; i++)
    {
        if (others.learnedMaterias[i])
            learnedMaterias[i] = others.learnedMaterias[i]->clone();
        else
            learnedMaterias[i] = NULL;
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        if (learnedMaterias[i])
            delete learnedMaterias[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        std::cout << "Materia is NULL" << std::endl;
        return ;
    }
    if (learnedMaterias[3] != NULL)
    {
        std::cout << "MateriaSource is full" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!learnedMaterias[i])
        {
            learnedMaterias[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (learnedMaterias[i] && learnedMaterias[i]->getType() == type)
            return learnedMaterias[i]->clone();
    }
    return NULL;
}