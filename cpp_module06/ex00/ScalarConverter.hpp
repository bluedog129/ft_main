#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
private:
    std::string _inputValue;
    char _charValue;
    int _intValue;
    float _floatValue;
    double _doubleValue;
    bool _isChar;
    bool _isInt;
    bool _isFloat;
    bool _isDouble;

    ScalarConverter(std::string const &value, char c, int i, float f, double d, bool isChar, bool isInt, bool isFloat, bool isDouble);

public:
    ScalarConverter();
    ScalarConverter(std::string const &value);
    ScalarConverter(ScalarConverter const &other);
    ~ScalarConverter();

    ScalarConverter &operator=(ScalarConverter const &other);

    void convert();
    void printChar();
    void printInt();
    void printFloat();
    void printDouble();
};

#endif