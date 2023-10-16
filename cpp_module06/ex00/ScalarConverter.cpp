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
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

template <>
char ScalarConverter::preconvert<char>(char *value) {
    // Check if it's a single character
    if (strlen(value) == 1) {
        int num = std::stoi(value);
        return static_cast<char>(num);
    }
    // check for special inputs like "nan" or "inf"
    std::string strValue(value);
    if (strValue == "nan" || strValue == "inf" || strValue == "-inf") {
        return (-1);
    }
    // Try to convert the input string to an integer, then to a char
    try {
        int num = std::stoi(strValue);
        return static_cast<char>(num);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (-1);
    }
}

template <>
int ScalarConverter::preconvert<int>(char *value) {
    try {
        int intValue = std::stoi(value);
        return intValue;

    } catch (const std::out_of_range&) {
        throw;
    } catch (const std::exception&) {
        throw;
    }
}

template <>
float ScalarConverter::preconvert<float>(char *value) {
    try {
        float floatValue = std::stof(value);
        return floatValue;

    } catch (const std::out_of_range&) {
        throw;
    } catch (const std::exception&) {
        throw;
    }
}

template <>
double ScalarConverter::preconvert<double>(char *value) {
    try {
        double doubleValue = std::stod(value);
        return doubleValue;

    } catch (const std::out_of_range&) {
        throw;
    } catch (const std::exception&) {
        throw;
    }
}

void ScalarConverter::printChar(char *value) {
    char c = preconvert<char>(value);

    if (c != 0 && (32 <= c && c <= 126)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else if (c == -1) {
        std::cout << "char: impossible" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(char *value) {
    try {
        int intValue = preconvert<int>(value);
        std::cout << "int: " << intValue << std::endl;
    } catch (const std::exception&) {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::printFloat(char *value) {
    try {
        float floatValue = preconvert<float>(value);
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    } catch (const std::exception&) {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::printDouble(char *value) {
    try {
        double doubleValue = preconvert<double>(value);
        std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
    } catch (const std::exception&) {
        std::cout << "double: impossible" << std::endl;
    }
}