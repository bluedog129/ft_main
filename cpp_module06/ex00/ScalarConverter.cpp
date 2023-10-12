#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string const &)
{
    std::cout << "Parametric constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
    std::cout << "Assignation operator called" << std::endl;

    return *this;
}

void ScalarConverter::convert(char *value)
{
    std::cout << "Convert called" << std::endl;

    preconvert(value);

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printChar(char *value)
{
    std::string stringValue = value;
    double num = std::stod(stringValue);

    if (num >= 32 && num <= 126) {
        std::cout << "char: '" << static_cast<char>(num) << "'"<< std::endl;
    } else if (num >= 0 && num <= 127) {
        std::cout << "char : Non displayable" << std::endl;
    } else {
        std::cout << "char: " << "impossible" << std::endl;
    }
}

void ScalarConverter::printInt(char *value)
{
    std::string stringValue = value;

    if (int num = std::stoi(stringValue)) {
        std::cout << "int: " << num << std::endl;
    } else {
        std::cout << "int: " << "impossible" << std::endl;
    }
}

void ScalarConverter::printFloat(char *value)
{
    std::string stringValue = value;

    if (float num = std::stof(stringValue)) {
        std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
    } else {
        std::cout << "float: " << "impossible" << std::endl;
    }
}

void ScalarConverter::printDouble(char *value)
{
    std::string stringValue = value;

    if (double num = std::stod(stringValue)) {
        std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
    } else {
        std::cout << "double: " << "impossible" << std::endl;
    }
}