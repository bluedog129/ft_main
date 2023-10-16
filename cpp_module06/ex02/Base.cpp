#include "Base.hpp"

Base *Base::generate(void)
{
    int random = rand() % 3;
    
    switch(random) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }

    return nullptr;
}

void identify(Base *p) 
{
    if (p) {
        std::cout << p->getType() << std::endl;
    }
}

void identify(Base &p) 
{
    std::cout << p.getType() << std::endl;
}