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
    std::string detectedType;

    preconvert(value, detectedType);

    printChar(value, detectedType);
    printInt(value, detectedType);
    printFloat(value, detectedType);
    printDouble(value, detectedType);
    printImpossible(detectedType);
}

void ScalarConverter::preconvert(char *value, std::string &detectedType)
{
    double inputForDouble = atof(value);

    //check if it's a char
    if (strlen(value) == 1 && !isdigit(value[0]))
        detectedType = "char";
    //check if it's an int
    else if (inputForDouble == static_cast<int>(inputForDouble) && \
            (INT_MAX >= inputForDouble && INT_MIN <= inputForDouble) && \
            !strchr(value, '.'))
    {
        detectedType = "int";
        if (inputForDouble == 0 && value[0] != '0')
            detectedType = "impossible";
    }
    //check if it's a float
    else if ((inputForDouble >= std::numeric_limits<float>::lowest() && inputForDouble <= std::numeric_limits<float>::max() && strchr(value, 'f')) || \
            (strcmp(value, "-inff") == 0 || strcmp(value, "+inff") == 0 || strcmp(value, "nanf") == 0))
        detectedType = "float";
    //check if it's a double
    else if ((inputForDouble >= std::numeric_limits<double>::lowest() && inputForDouble <= std::numeric_limits<double>::max()) || \
            (strcmp(value, "-inf") == 0 || strcmp(value, "+inf") == 0 || strcmp(value, "nan") == 0))
        detectedType = "double";
    else
        detectedType = "impossible";
}

void ScalarConverter::printChar(char *value, std::string &detectedType)
{
    if (detectedType == "char")
    {
        std::cout << "char: '" << value << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(*value) << std::endl;
        std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(*value) << "f" << std::endl;
        std::cout << "double: " << std::setprecision(1) << static_cast<double>(*value) << std::endl;
    }
}

void ScalarConverter::printInt(char *value, std::string &detectedType)
{
    if (detectedType == "int")
    {
        if (isprint(atoi(value))) {
            std::cout << "char: '" << static_cast<char>(atoi(value)) << "'" << std::endl;
        } else if (0 <= atoi(value) && atoi(value) <= 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(atoi(value)) << std::endl;
        std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(atoi(value)) << "f" << std::endl;
        std::cout << "double: " << std::setprecision(1) << static_cast<double>(atoi(value)) << std::endl;
    }
}

void ScalarConverter::printFloat(char *value, std::string &detectedType)
{
    if (detectedType == "float")
    {
        if (isprint(static_cast<int>(atof(value)))) {
            std::cout << "char: '" << static_cast<char>(atof(value)) << "'" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        if (atof(value) <= INT_MAX && atof(value) >= INT_MIN) {
            std::cout << "int: " << static_cast<int>(atof(value)) << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }
        std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(atof(value)) << "f" << std::endl;
        std::cout << "double: " << std::setprecision(1) << static_cast<double>(atof(value)) << std::endl;
    }
}

void ScalarConverter::printDouble(char *value, std::string &detectedType)
{
    if (detectedType == "double")
    {
        if (isprint(static_cast<int>(atof(value)))) {
            std::cout << "char: '" << static_cast<char>(atof(value)) << "'" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        if (atof(value) <= INT_MAX && atof(value) >= INT_MIN) {
            std::cout << "int: " << static_cast<int>(atof(value)) << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }
        std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(atof(value)) << "f" << std::endl;
        std::cout << "double: " << std::setprecision(1) << static_cast<double>(atof(value)) << std::endl;
    }
}

void ScalarConverter::printImpossible(std::string &detectedType)
{
    if (detectedType == "impossible")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}