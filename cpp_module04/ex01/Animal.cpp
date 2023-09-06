#include "Animal.hpp"

AAnimal::AAnimal() : _type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return _type;
}

void AAnimal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}