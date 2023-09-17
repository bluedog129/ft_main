#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leaks()
{
    std::cout << std::system("leaks ex00") << std::endl;
}

int main() {
    const AAnimal* animal = new AAnimal();
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();
    delete animal;
    delete dog;
    delete cat;

    std::cout << "------ Additional Tests ------" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    delete wrongAnimal;
    delete wrongCat;
    
    atexit(leaks);

    return 0;
}