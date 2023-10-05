#include "AAnimal.hpp"

void leaks()
{
    std::cout << std::system("leaks ex02") << std::endl;
}

int main()
{
    AAnimal animal;

    animal.makeSound();
    animal.getBrain();
    atexit(leaks);
}