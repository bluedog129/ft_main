#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _inputValue(""), _charValue(0), _intValue(0), _floatValue(0), _doubleValue(0), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false)
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string const &value) 
: _inputValue(value), _charValue(0), _intValue(0), _floatValue(0), _doubleValue(0), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false)
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

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    if (this != &other)
    {
        this->_inputValue = other._inputValue;
        this->_charValue = other._charValue;
        this->_intValue = other._intValue;
        this->_floatValue = other._floatValue;
        this->_doubleValue = other._doubleValue;
        this->_isChar = other._isChar;
        this->_isInt = other._isInt;
        this->_isFloat = other._isFloat;
        this->_isDouble = other._isDouble;
    }
    return *this;
}

void ScalarConverter::convert()
{
    std::cout << "Convert called" << std::endl;

    if (isprint(_inputValue[0]))
    {
        
    }
    else if (iscntrl(_inputValue[0]))
    {
        _charValue = _inputValue[0];
        _isChar = true;
    }
    else 
    {
        std::cout << "impossible" << std::endl;
    }
    try {
        _intValue = std::stoi(_inputValue);
        _isInt = true;
    } catch (std::exception &e) {
        std::cout << "stoi failed" << std::endl;
    }
    try {
        _floatValue = std::stof(_inputValue);
        _isFloat = true;
    } catch (std::exception &e) {
        std::cout << "stof failed" << std::endl;
    }
    try {
        _doubleValue = std::stod(_inputValue);
        _isDouble = true;
    } catch (std::exception &e) {
        std::cout << "stod failed" << std::endl;
    }
}

void ScalarConverter::printChar()
{
    if (_isChar) {
        std::cout << "char: '" << _charValue << "'" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
}

void ScalarConverter::printInt()
{
    if (_isInt) {
        std::cout << "int: " << _intValue << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::printFloat()
{
    if (_isFloat) {
        std::cout << "float: " << std::fixed << std::setprecision(1) << _floatValue << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::printDouble()
{
    if (_isDouble) {
        std::cout << "double: " << std::fixed << std::setprecision(1) << _doubleValue << std::endl;
    } else {
        std::cout << "double: impossible" << std::endl;
    }
}

