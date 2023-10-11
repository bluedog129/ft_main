#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    std::string value = argv[1];
    // check double vs float
    double num = std::stod(value);

    if (num < 0 || num > 127) {
        std::cout << "char: " << "impossible" << std::endl;
    } else if (num >= 32 && num <= 126) {
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    } else {
        std::cout << "char : Non displayable" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;

    // ScalarConverter sc(argv[1]);
    // sc.convert();
    // sc.printChar();
    // sc.printInt();
    // sc.printFloat();
    // sc.printDouble();
    // return 0;
}