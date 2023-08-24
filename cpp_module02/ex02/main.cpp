#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    // ++a example
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    // a++ example
    std::cout << a++ << std::endl;
    // // + example
    std::cout << a + b << std::endl;
    // - example
    std::cout << a - b << std::endl;
    std::cout << b - a << std::endl;
    // * example
    std::cout << a * b << std::endl;
    // / example
    std::cout << a / b << std::endl;
    std::cout << b / a << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    // // min example
    // std::cout << Fixed::min(a, b) << std::endl;
    // max example
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}