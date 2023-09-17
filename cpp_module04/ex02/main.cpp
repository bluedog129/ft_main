#include "AAnimal.hpp"

void leaks()
{
    std::cout << std::system("leaks ex02") << std::endl;
}

int main()
{
    AAnimal aanimal;

    aanimal.makeSound();
    aanimal.getBrain();
    atexit(leaks);
}