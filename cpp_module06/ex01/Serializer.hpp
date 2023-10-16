#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
private:
    Serializer();
    ~Serializer();

public:
    Serializer(Serializer const &other);
    Serializer(std::string const &);
    Serializer &operator=(Serializer const &other);

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif