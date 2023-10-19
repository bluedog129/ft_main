#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
    return NULL;
}

void Base::identify(Base *p) 
{
    if (p) {
        if (dynamic_cast<A*>(p)) {
            std::cout << "A" << std::endl;
        } else if (dynamic_cast<B*>(p)) {
            std::cout << "B" << std::endl;
        } else if (dynamic_cast<C*>(p)) {
            std::cout << "C" << std::endl;
        } else {
            std::cout << "Unknown type" << std::endl;
        }
    }
}

void Base::identify(Base &p) 
{
    int jdx = 0;
    for (int idx = 0; idx < 3; idx++) {
        try {
            switch(idx) {
                case 0:
                    (void)dynamic_cast<A&>(p);
                    std::cout << "A" << std::endl;
                    break;
                case 1:
                    (void)dynamic_cast<B&>(p);
                    std::cout << "B" << std::endl;
                    break;
                case 2:
                    (void)dynamic_cast<C&>(p);
                    std::cout << "C" << std::endl;
            }
        }
        catch (std::exception &) {
            jdx++;
        }
    }
    if (jdx == 3)
        std::cout << "Unknown type" << std::endl;
}