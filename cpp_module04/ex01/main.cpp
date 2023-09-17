#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void leaks()
{
    std::cout << std::system("leaks ex01") << std::endl;
}

int main()
{
    atexit(leaks);
    std::cout << "========== animal copy test ==========" << std::endl;
    Cat *catOne = new Cat();
    Dog *dogOne = new Dog();
    Cat *catTwo = new Cat(*catOne);
    Dog *dogTwo = new Dog();
    *dogTwo = *dogOne;

    std::cout << "=== reference address ===" << std::endl;
    std::cout << "catOne's address : " << catOne << std::endl;
    std::cout << "catOne's brain address : " << catOne->getBrain() << std::endl;
    std::cout << "catTwo's address : " << catTwo << std::endl;
    std::cout << "catTwo's brain address : " << catTwo->getBrain() << std::endl;
    std::cout << "dogOne's address : " << dogOne << std::endl;
    std::cout << "dogOne's brain address : " << dogOne->getBrain() << std::endl;
    std::cout << "dogTwo's address : " << dogTwo << std::endl;
    std::cout << "dogTwo's brain address : " << dogTwo->getBrain() << std::endl;

    catOne->getBrain()->setIdeas(CAT_IDEA_STRING, 0);
    dogOne->getBrain()->setIdeas(DOG_IDEA_STRING, 0);
    std::cout << "catOne's idea : " << catOne->getBrain()->getIdeas(0) << std::endl;
    std::cout << "catTwo's idea : " << catTwo->getBrain()->getIdeas(0) << std::endl;
    std::cout << "catOne's brain address : " << catOne->getBrain() << std::endl;
    std::cout << "catTwo's brain address : " << catTwo->getBrain() << std::endl;
    std::cout << "dogOne's idea : " << dogOne->getBrain()->getIdeas(0) << std::endl;
    std::cout << "dogTwo's idea : " << dogTwo->getBrain()->getIdeas(0) << std::endl;
    std::cout << "dogOne's brain address : " << dogOne->getBrain() << std::endl;
    std::cout << "dogTwo's brain address : " << dogTwo->getBrain() << std::endl;

    delete catOne;
    delete catTwo;
    delete dogOne;
    delete dogTwo;

    std::cout << "========== animalArray test ==========" << std::endl;
    Animal *animalArray[4];

    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            Dog *dog = new Dog();
            dog->getBrain()->setIdeas(DOG_IDEA_STRING, i);
            std::cout << "dog's idea : " << dog->getBrain()->getIdeas(i) << std::endl;  
            animalArray[i] = dog;
        } else {
            Cat *cat = new Cat();
            cat->getBrain()->setIdeas(CAT_IDEA_STRING, i);
            std::cout << "cat's idea : " << cat->getBrain()->getIdeas(i) << std::endl;
            animalArray[i] = cat;
        }
    }

    for (int i = 0; i < 4; i++) {
        animalArray[i]->makeSound();
    }

    for (int i = 0; i < 4; i++) {
        delete animalArray[i];
    }

    atexit(leaks);
    
    return 0;
}