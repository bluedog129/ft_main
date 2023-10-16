#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(std::string const &) {
    std::cout << "Parametric constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Serializer::~Serializer() {
    std::cout << "Destructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &) {
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}