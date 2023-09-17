#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
    _type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
    _type = "Cat";
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        delete _brain;
        _brain = new Brain(*other._brain);
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}