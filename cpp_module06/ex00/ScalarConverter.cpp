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
    if (strlen(value) == 1) {
        return value[0];
    }
    
    std::string strValue(value);
    if (strValue == "nan" || strValue == "inf" || strValue == "-inf") {
        return (-1);
    }

    int num;
    std::istringstream iss(value);
    iss >> num;

    if (!iss.fail() && iss.eof()) {
        return static_cast<char>(num);
    } else {
        std::cout << "Error: Invalid conversion to char" << std::endl;
        return (-1);
    }
}

template <>
int ScalarConverter::preconvert<int>(char *value) {
    int intValue;

    std::istringstream iss(value);
    iss >> intValue;

    if (!iss.fail() && iss.eof()) {
        return intValue;
    } else {
        throw std::runtime_error("Invalid conversion to int");
    }
}

template <>
float ScalarConverter::preconvert<float>(char *value) {
    float floatValue;
    std::istringstream iss(value);
    iss >> floatValue;

    if (!iss.fail() && iss.eof()) {
        return floatValue;
    } else {
        throw std::runtime_error("Invalid conversion to float");
    }
}

template <>
double ScalarConverter::preconvert<double>(char *value) {
    double doubleValue;
    std::istringstream iss(value);
    iss >> doubleValue;

    if (!iss.fail() && iss.eof()) {
        return doubleValue;
    } else {
        throw std::runtime_error("Invalid conversion to double");
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