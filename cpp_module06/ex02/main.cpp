#include "Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main() {
    srand(time(NULL));

    Base *base = generate();
    identify(base);
    identify(*base);

    delete base;
    return 0;
}