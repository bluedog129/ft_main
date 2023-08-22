#include "Fixed.hpp"

// Fixed::Fixed() : _value(0) {}

// Fixed::Fixed(const int value) : _value(value << fractional_bits) {}

// Fixed::Fixed(const float value) : _value(roundf(value * (1 << fractional_bits))) {}

// int Fixed::getRawValue() const {
//     return _value;
// }

// float Fixed::toFloat() const {
//     return static_cast<float>(_value) / (1 << fractional_bits);
// }

// bool Fixed::operator>(const Fixed &other) const {
//     return _value > other._value;
// }

// bool Fixed::operator<(const Fixed &other) const {
//     return _value < other._value;
// }

// bool Fixed::operator>=(const Fixed &other) const {
//     return _value >= other._value;
// }

// bool Fixed::operator<=(const Fixed &other) const {
//     return _value <= other._value;
// }

// bool Fixed::operator==(const Fixed &other) const {
//     return _value == other._value;
// }

// bool Fixed::operator!=(const Fixed &other) const {
//     return _value != other._value;
// }

// // Arithmetic operators
// Fixed Fixed::operator+(const Fixed &other) const {
//     return Fixed(toFloat() + other.toFloat());
// }

// Fixed Fixed::operator-(const Fixed &other) const {
//     return Fixed(toFloat() - other.toFloat());
// }

// Fixed Fixed::operator*(const Fixed &other) const {
//     return Fixed(toFloat() * other.toFloat());
// }

// Fixed Fixed::operator/(const Fixed &other) const {
//     return Fixed(toFloat() / other.toFloat());
// }

// // Increment and decrement operators
// Fixed &Fixed::operator++(void) {
//     _value += (1 << fractional_bits);
//     return *this;
// }

// Fixed Fixed::operator++(int) {
//     Fixed temp = *this;
//     ++(*this);
//     return temp;
// }

// Fixed &Fixed::operator--(void) {
//     _value -= (1 << fractional_bits);
//     return *this;
// }

// Fixed Fixed::operator--(int) {
//     Fixed temp = *this;
//     --(*this);
//     return temp;
// }

// const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
//     return a < b ? a : b;
// }

// const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
//     return a > b ? a : b;
// }

// std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
// 	os << fixed.toFloat();
// 	return (os);
// }

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value) : _value(value << fractional_bits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << fractional_bits))) {}

int Fixed::getRawValue() const {
    return _value;
}

float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << fractional_bits);
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(toFloat() / other.toFloat());
}

// Increment and decrement operators
Fixed& Fixed::operator++() {
    _value += (1 << fractional_bits);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    _value -= (1 << fractional_bits);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

// Static member functions
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}