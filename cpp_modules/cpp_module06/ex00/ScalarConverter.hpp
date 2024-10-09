#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <limits.h>
#include <float.h>

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
    static void preconvert(char *value, std::string &detectedType);
    static void printChar(char *value, std::string &detectedType);
    static void printInt(char *value, std::string &detectedType);
    static void printFloat(char *value, std::string &detectedType);
    static void printDouble(char *value, std::string &detectedType);
    static void printImpossible(std::string &detectedType);
};

#endif