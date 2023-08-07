/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:55:58 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/07 18:42:33 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(0) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _value(0) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return (*this);
}

int Fixed::getRawBits() const {
	return (_value);
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}