#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    Animal *animalArray[4];
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            animalArray[i] = new Dog();
        } else {
            animalArray[i] = new Cat();
        }
    }

    for (int i = 0; i < 4; i++) {
        delete animalArray[i];
    }
    
    return 0;
}