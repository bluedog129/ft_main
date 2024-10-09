#include "Base.hpp"

int main() {
    srand(time(NULL));

    Base *base = Base::generate();
    Base::identify(base);
    Base::identify(*base);

    delete base;
    return 0;
}