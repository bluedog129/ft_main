#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#define CAT_IDEA_STRING "Give me some food human!"

class Cat : public AAnimal {
private:
    Brain* _brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
    Brain* getBrain() const;
};

#endif