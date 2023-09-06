#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
    _type = "Dog";
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        *_brain = *other._brain;
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "mung mung" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}