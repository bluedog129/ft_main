#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>

class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();

public:
    ScalarConverter(std::string const &);
    ScalarConverter(ScalarConverter const &other);
    
    ScalarConverter &operator=(ScalarConverter const &);

    static void convert(char *value);
    template <typename T>
    static T preconvert(char *value);
    static void printChar(char *value);
    static void printInt(char *value);
    static void printFloat(char *value);
    static void printDouble(char *value);
};

#endif