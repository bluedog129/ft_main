#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value) : _value(value << fractional_bits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << fractional_bits))) {}

Fixed::~Fixed() {}

int Fixed::getRawValue() const {
    return _value;
}

float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << fractional_bits);
}

bool Fixed::operator>(const Fixed &other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed fixed;

    std::cout << "operator + called" << std::endl;
    fixed._value = _value + other._value;
    fixed._value = fixed._value >> fractional_bits;
    return fixed;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed fixed;

    std::cout << "operator - called" << std::endl;
    fixed._value = _value - other._value;
    fixed._value = fixed._value >> fractional_bits;
    return fixed;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed fixed;

    std::cout << "operator * called" << std::endl;
    fixed._value = (_value * other.getRawValue()) >> fractional_bits;
    return fixed;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed fixed;

    std::cout << "operator / called" << std::endl;
    fixed._value = (_value << fractional_bits) / other.getRawValue();
    return fixed;
}

// Increment and decrement operators
Fixed &Fixed::operator++(void) {
    _value += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--(void) {
    _value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    std::cout << "min called" << std::endl;
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    std::cout << "max called" << std::endl;
    return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}