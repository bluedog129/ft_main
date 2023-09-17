#ifndef MATTERIASOURCE_HPP
#define MATTERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *learnedMaterias[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource &others);
    MateriaSource &operator=(MateriaSource &others);
    ~MateriaSource();

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif